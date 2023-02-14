

#include <libmm-glib/mm-glib.hxx>

#include <libmm-glib/optiongroup.hxx>
#include <libmm-glib/optiongroup_p.hxx>

#include <cstring>
#include <glib.h>
#include <libmm-glib/exceptionhandler.hxx>
#include <libmm-glib/optioncontext.hxx>
#include <libmm-glib/optionentry.hxx>
#include <libmm-glib/utility.hxx>

namespace Glib
{

  namespace
  {

    class OptionArgCallback
    {
    public:
      explicit OptionArgCallback (const OptionGroup::SlotOptionArgString& slot)
        : slot_string_ (new OptionGroup::SlotOptionArgString (slot)),
          slot_filename_ (nullptr)
      {
      }

      explicit OptionArgCallback (
          const OptionGroup::SlotOptionArgFilename& slot)
        : slot_string_ (nullptr),
          slot_filename_ (new OptionGroup::SlotOptionArgFilename (slot))
      {
      }

      auto
      is_filename_option () const -> bool
      {
        return slot_filename_ != nullptr;
      }

      auto
      get_slot_string () const -> const OptionGroup::SlotOptionArgString*
      {
        return slot_string_;
      }

      auto
      get_slot_filename () const -> const OptionGroup::SlotOptionArgFilename*
      {
        return slot_filename_;
      }

      ~OptionArgCallback ()
      {
        delete slot_string_;
        delete slot_filename_;
      }

    private:
      OptionGroup::SlotOptionArgString* slot_string_;
      OptionGroup::SlotOptionArgFilename* slot_filename_;

      OptionArgCallback (const OptionArgCallback&);
      auto
      operator= (const OptionArgCallback&) -> OptionArgCallback&;
    };

    extern "C"
    {
      static auto
      g_callback_pre_parse (GOptionContext* context,
                            GOptionGroup*,
                            const gpointer data,
                            GError** error) -> gboolean
      {
        OptionContext cppContext (context, false);

        const auto option_group = static_cast<OptionGroup*> (data);
        if (!option_group)
        {
          OptionError (OptionError::FAILED,
                       "Glib::OptionGroup: g_callback_pre_parse(): "
                       "No OptionGroup pointer available")
              .propagate (error);
          return false;
        }

        try
        {
          return option_group->on_pre_parse (cppContext);
        }
        catch (Error& err)
        {
          err.propagate (error);
        }
        catch (...)
        {
          exception_handlers_invoke ();
        }
        return false;
      }

      static auto
      g_callback_error (GOptionContext* context,
                        GOptionGroup*,
                        const gpointer data,
                        GError** error) -> void
      {
        OptionContext cppContext (context, false);

        const auto option_group = static_cast<OptionGroup*> (data);
        if (option_group && error && *error)
        {
          try
          {
            Error::throw_exception (g_error_copy (*error));
          }
          catch (const Error& err)
          {
            return option_group->on_error (cppContext, err);
          }
        }
      }

      auto
      OptionGroup_Translate_glibmm_callback (const gchar* string,
                                             const gpointer data)
          -> const gchar*
      {
        const OptionGroup::SlotTranslate* the_slot =
            static_cast<OptionGroup::SlotTranslate*> (data);

        try
        {
          return g_strdup ((*the_slot) (ustring (string)).c_str ());
        }
        catch (...)
        {
          exception_handlers_invoke ();
        }

        return nullptr;
      }

      static auto
      OptionGroup_Translate_glibmm_callback_destroy (void* data) -> void
      {
        delete static_cast<OptionGroup::SlotTranslate*> (data);
      }
    }

  } // namespace

  auto
  OptionGroup::post_parse_callback (GOptionContext* context,
                                    GOptionGroup*,
                                    const gpointer data,
                                    GError** error) -> gboolean
  {
    OptionContext cppContext (context, false);

    OptionGroup* option_group = static_cast<OptionGroup*> (data);
    if (!option_group)
    {
      OptionError (OptionError::FAILED,
                   "Glib::OptionGroup::post_parse_callback(): "
                   "No OptionGroup pointer available")
          .propagate (error);
      return false;
    }

    for (auto& the_pair : option_group->map_entries_)
    {
      auto& cpp_entry = the_pair.second;
      cpp_entry.convert_c_to_cpp ();
    }

    try
    {
      return option_group->on_post_parse (cppContext);
    }
    catch (Error& err)
    {
      err.propagate (error);
    }
    catch (...)
    {
      exception_handlers_invoke ();
    }
    return false;
  }

  auto
  OptionGroup::option_arg_callback (const gchar* option_name,
                                    const gchar* value,
                                    const gpointer data,
                                    GError** error) -> gboolean
  {
    const ustring cpp_option_name (option_name);
    const OptionGroup* const option_group =
        static_cast<const OptionGroup*> (data);
    if (!option_group)
    {
      OptionError (OptionError::FAILED,
                   "Glib::OptionGroup::option_arg_callback(): "
                   "No OptionGroup pointer available for option " +
                       cpp_option_name)
          .propagate (error);
      return false;
    }

    type_map_entries::const_iterator iterFind =
        option_group->map_entries_.end ();
    if (option_name[1] == '-')
    {
      const auto long_option_name = ustring (option_name + 2);
      iterFind = option_group->map_entries_.find (long_option_name);
    }
    else
    {
      const auto short_option_name = option_name[1];
      for (iterFind = option_group->map_entries_.begin ();
           iterFind != option_group->map_entries_.end ();
           ++iterFind)
      {
        const auto& cppOptionEntry = iterFind->second;
        if (cppOptionEntry.entry_ &&
            cppOptionEntry.entry_->get_short_name () == short_option_name)
          break;
      }
    }

    if (iterFind == option_group->map_entries_.end ())
    {
      OptionError (OptionError::UNKNOWN_OPTION,
                   "Glib::OptionGroup::option_arg_callback(): "
                   "Unknown option " +
                       cpp_option_name)
          .propagate (error);
      return false;
    }

    const auto& cppOptionEntry = iterFind->second;
    if (cppOptionEntry.carg_type_ != G_OPTION_ARG_CALLBACK)
    {
      OptionError (OptionError::FAILED,
                   "Glib::OptionGroup::option_arg_callback() "
                   "called for non-callback option " +
                       cpp_option_name)
          .propagate (error);
      return false;
    }

    const bool has_value = value != nullptr;
    const OptionArgCallback* const option_arg =
        static_cast<const OptionArgCallback*> (cppOptionEntry.cpparg_);
    try
    {
      if (option_arg->is_filename_option ())
      {
        const auto the_slot = option_arg->get_slot_filename ();
        const std::string cpp_value (value ? value : "");
        return (*the_slot) (cpp_option_name, cpp_value, has_value);
      }
      else
      {
        const auto the_slot = option_arg->get_slot_string ();
        const ustring cpp_value (value ? value : "");
        return (*the_slot) (cpp_option_name, cpp_value, has_value);
      }
    }
    catch (Error& err)
    {
      err.propagate (error);
    }
    catch (...)
    {
      exception_handlers_invoke ();
    }
    return false;
  }

  OptionGroup::OptionGroup (const ustring& name,
                            const ustring& description,
                            const ustring& help_description)
    : gobject_ (g_option_group_new (name.c_str (),
                                    description.c_str (),
                                    help_description.c_str (),
                                    this,
                                    nullptr))
  {
    g_option_group_set_parse_hooks (gobj (),
                                    &g_callback_pre_parse,
                                    &post_parse_callback);
    g_option_group_set_error_hook (gobj (), &g_callback_error);
  }

  OptionGroup::OptionGroup (GOptionGroup* castitem)
    : gobject_ (castitem)
  {
  }

  auto
  OptionGroup::release_gobject () noexcept -> void
  {
    for (auto& the_pair : map_entries_)
    {
      auto& cpp_entry = the_pair.second;
      cpp_entry.release_c_arg ();
    }

    if (gobject_)
    {
      g_option_group_unref (gobj ());
      gobject_ = nullptr;
    }
  }

  OptionGroup::~OptionGroup ()
  {
    release_gobject ();
  }

  auto
  OptionGroup::add_entry (const OptionEntry& entry) -> void
  {
    GOptionEntry array[2];
    array[0] = *entry.gobj ();
    std::memset (&array[1], 0, sizeof (GOptionEntry));

    g_option_group_add_entries (gobj (), array);
  }

  auto
  OptionGroup::add_entry (const OptionEntry& entry, bool& arg) -> void
  {
    add_entry_with_wrapper (entry, G_OPTION_ARG_NONE, &arg);
  }

  auto
  OptionGroup::add_entry (const OptionEntry& entry, int& arg) -> void
  {
    add_entry_with_wrapper (entry, G_OPTION_ARG_INT, &arg);
  }

  auto
  OptionGroup::add_entry (const OptionEntry& entry, double& arg) -> void
  {
    add_entry_with_wrapper (entry, G_OPTION_ARG_DOUBLE, &arg);
  }

  auto
  OptionGroup::add_entry (const OptionEntry& entry, ustring& arg) -> void
  {
    add_entry_with_wrapper (entry, G_OPTION_ARG_STRING, &arg);
  }

  auto
  OptionGroup::add_entry (const OptionEntry& entry, vecustrings& arg) -> void
  {
    add_entry_with_wrapper (entry, G_OPTION_ARG_STRING_ARRAY, &arg);
  }

  auto
  OptionGroup::add_entry_filename (const OptionEntry& entry, std::string& arg) -> void
  {
    add_entry_with_wrapper (entry, G_OPTION_ARG_FILENAME, &arg);
  }

  auto
  OptionGroup::add_entry_filename (const OptionEntry& entry, vecstrings& arg) -> void
  {
    add_entry_with_wrapper (entry, G_OPTION_ARG_FILENAME_ARRAY, &arg);
  }

  auto
  OptionGroup::add_entry (const OptionEntry& entry,
                          const SlotOptionArgString& slot) -> void
  {
    add_entry_with_wrapper (entry,
                            G_OPTION_ARG_CALLBACK,
                            new OptionArgCallback (slot));
  }

  auto
  OptionGroup::add_entry_filename (const OptionEntry& entry,
                                   const SlotOptionArgFilename& slot) -> void
  {
    add_entry_with_wrapper (entry,
                            G_OPTION_ARG_CALLBACK,
                            new OptionArgCallback (slot));
  }

  auto
  OptionGroup::add_entry_with_wrapper (const OptionEntry& entry,
                                       const GOptionArg arg_type,
                                       void* cpp_arg) -> void
  {
    const auto name = entry.get_long_name ();
    const type_map_entries::iterator iterFind = map_entries_.find (name);
    if (iterFind == map_entries_.end ())
    {
      CppOptionEntry cppEntry;

      cppEntry.entry_ = new OptionEntry (entry);

      bool is_duplicate = false;
      void* carg = nullptr;
      if (arg_type != G_OPTION_ARG_CALLBACK)
      {
        for (type_map_entries::iterator iter = map_entries_.begin ();
             iter != map_entries_.end ();
             ++iter)
        {
          const auto& cpp_entry = iter->second;
          if (cpp_entry.cpparg_ == cpp_arg &&
              cpp_entry.carg_type_ == arg_type && cpp_entry.carg_)
          {
            is_duplicate = true;
            carg = cpp_entry.carg_;
            break;
          }
        }
      }

      cppEntry.carg_type_ = arg_type;
      if (!is_duplicate)
      {
        cppEntry.allocate_c_arg ();
        cppEntry.set_c_arg_default (cpp_arg);
        carg = cppEntry.carg_;
      }
      cppEntry.cpparg_ = cpp_arg;

      cppEntry.entry_->gobj ()->arg = arg_type;
      cppEntry.entry_->gobj ()->arg_data = carg;

      map_entries_[name] = cppEntry;

      add_entry (*cppEntry.entry_);
    }
    else if (arg_type == G_OPTION_ARG_CALLBACK)
    {
      const auto option_arg = static_cast<OptionArgCallback*> (cpp_arg);
      delete option_arg;
    }
  }

  auto
  OptionGroup::on_pre_parse (OptionContext&) -> bool
  {
    return true;
  }

  auto
  OptionGroup::on_post_parse (OptionContext&) -> bool
  {
    return true;
  }

  auto
  OptionGroup::on_error (OptionContext&, const Error&) -> void
  {
  }

  auto
  OptionGroup::set_translate_func (const SlotTranslate& slot) -> void
  {
    const auto slot_copy = new SlotTranslate (slot);
    g_option_group_set_translate_func (
        gobj (),
        &OptionGroup_Translate_glibmm_callback,
        slot_copy,
        &OptionGroup_Translate_glibmm_callback_destroy);
  }

  OptionGroup::CppOptionEntry::CppOptionEntry ()
    : carg_type_ (G_OPTION_ARG_NONE),
      carg_ (nullptr),
      cpparg_ (nullptr),
      entry_ (nullptr)
  {
  }

  auto
  OptionGroup::CppOptionEntry::allocate_c_arg () -> void
  {
    switch (carg_type_)
    {
      case G_OPTION_ARG_STRING:
      case G_OPTION_ARG_FILENAME:
      {
        char** typed_arg = new char*;

        *typed_arg = nullptr;
        carg_ = typed_arg;

        break;
      }
      case G_OPTION_ARG_INT:
      {
        int* typed_arg = new int;
        *typed_arg = 0;
        carg_ = typed_arg;

        break;
      }
      case G_OPTION_ARG_DOUBLE:
      {
        double* typed_arg = new double;
        *typed_arg = 0.0;
        carg_ = typed_arg;

        break;
      }
      case G_OPTION_ARG_STRING_ARRAY:
      case G_OPTION_ARG_FILENAME_ARRAY:
      {
        char*** typed_arg = new char**;

        *typed_arg = nullptr;
        carg_ = typed_arg;

        break;
      }
      case G_OPTION_ARG_NONE:
      {
        gboolean* typed_arg = new gboolean;
        *typed_arg = false;
        carg_ = typed_arg;

        break;
      }
      case G_OPTION_ARG_CALLBACK:
      {
        carg_ = reinterpret_cast<void*> (&OptionGroup::option_arg_callback);

        break;
      }
      default:
      {
        break;
      }
    }
  }

  auto
  OptionGroup::CppOptionEntry::set_c_arg_default (void* cpp_arg) -> void
  {
    switch (carg_type_)
    {
      case G_OPTION_ARG_INT:
      {
        *static_cast<int*> (carg_) = *static_cast<int*> (cpp_arg);
        break;
      }
      case G_OPTION_ARG_DOUBLE:
      {
        *static_cast<double*> (carg_) = *static_cast<double*> (cpp_arg);
        break;
      }
      case G_OPTION_ARG_NONE:
      {
        *static_cast<gboolean*> (carg_) = *static_cast<bool*> (cpp_arg);
        break;
      }
      case G_OPTION_ARG_STRING:
      case G_OPTION_ARG_FILENAME:
      case G_OPTION_ARG_STRING_ARRAY:
      case G_OPTION_ARG_FILENAME_ARRAY:
      {
        break;
      }
      case G_OPTION_ARG_CALLBACK:
      {
        const OptionArgCallback* const option_arg =
            static_cast<const OptionArgCallback*> (cpp_arg);
        if (option_arg->is_filename_option ())
        {
          entry_->set_flags (entry_->get_flags () |
                             OptionEntry::Flags::FILENAME);
        }
        else
        {
          entry_->set_flags (entry_->get_flags () &
                             ~OptionEntry::Flags::FILENAME);
        }
        break;
      }
      default:
      {
        break;
      }
    }
  }

  auto
  OptionGroup::CppOptionEntry::release_c_arg () -> void
  {
    if (carg_)
    {
      switch (carg_type_)
      {
        case G_OPTION_ARG_STRING:
        case G_OPTION_ARG_FILENAME:
        {
          char** typed_arg = static_cast<char**> (carg_);
          g_free (*typed_arg);
          delete typed_arg;

          break;
        }
        case G_OPTION_ARG_INT:
        {
          const int* typed_arg = static_cast<int*> (carg_);
          delete typed_arg;

          break;
        }
        case G_OPTION_ARG_DOUBLE:
        {
          const double* typed_arg = static_cast<double*> (carg_);
          delete typed_arg;

          break;
        }
        case G_OPTION_ARG_STRING_ARRAY:
        case G_OPTION_ARG_FILENAME_ARRAY:
        {
          char*** typed_arg = static_cast<char***> (carg_);
          g_strfreev (*typed_arg);

          delete typed_arg;

          break;
        }
        case G_OPTION_ARG_NONE:
        {
          const gboolean* typed_arg = static_cast<gboolean*> (carg_);
          delete typed_arg;

          break;
        }
        case G_OPTION_ARG_CALLBACK:
        {
          const auto option_arg = static_cast<OptionArgCallback*> (cpparg_);
          delete option_arg;
          cpparg_ = nullptr;

          break;
        }
        default:
        {
          break;
        }
      }

      carg_ = nullptr;
    }

    if (entry_)
      delete entry_;
  }

  auto
  OptionGroup::CppOptionEntry::convert_c_to_cpp () -> void
  {
    if (!carg_)
      return;

    switch (carg_type_)
    {
      case G_OPTION_ARG_STRING:
      {
        char** typed_arg = static_cast<char**> (carg_);
        const auto typed_cpp_arg = static_cast<ustring*> (cpparg_);
        if (typed_arg && *typed_arg && typed_cpp_arg)
        {
          *typed_cpp_arg = *typed_arg;
        }
        break;
      }
      case G_OPTION_ARG_FILENAME:
      {
        char** typed_arg = static_cast<char**> (carg_);
        const auto typed_cpp_arg = static_cast<std::string*> (cpparg_);
        if (typed_arg && *typed_arg && typed_cpp_arg)
        {
          *typed_cpp_arg = *typed_arg;
        }
        break;
      }
      case G_OPTION_ARG_INT:
      {
        *(int*) cpparg_ = *static_cast<int*> (carg_);
        break;
      }
      case G_OPTION_ARG_DOUBLE:
      {
        *(double*) cpparg_ = *static_cast<double*> (carg_);
        break;
      }
      case G_OPTION_ARG_STRING_ARRAY:
      {
        char*** typed_arg = static_cast<char***> (carg_);
        const auto typed_cpp_arg = static_cast<vecustrings*> (cpparg_);
        if (typed_arg && *typed_arg && typed_cpp_arg)
        {
          typed_cpp_arg->clear ();

          char** char_array_next = *typed_arg;
          while (*char_array_next)
          {
            typed_cpp_arg->emplace_back (*char_array_next);
            ++char_array_next;
          }
        }
        break;
      }
      case G_OPTION_ARG_FILENAME_ARRAY:
      {
        char*** typed_arg = static_cast<char***> (carg_);
        const auto typed_cpp_arg = static_cast<vecstrings*> (cpparg_);
        if (typed_arg && *typed_arg && typed_cpp_arg)
        {
          typed_cpp_arg->clear ();

          char** char_array_next = *typed_arg;
          while (*char_array_next)
          {
            typed_cpp_arg->emplace_back (*char_array_next);
            ++char_array_next;
          }
        }
        break;
      }
      case G_OPTION_ARG_NONE:
      {
        *static_cast<bool*> (cpparg_) = *static_cast<gboolean*> (carg_);
        break;
      }
      case G_OPTION_ARG_CALLBACK:
      {
        break;
      }
      default:
      {
        break;
      }
    }
  }

  auto
  OptionGroup::gobj_copy () const -> GOptionGroup*
  {
    return g_option_group_ref (gobject_);
  }

} // namespace Glib

namespace
{
}

namespace Glib
{

  auto
  OptionGroup::set_translation_domain (const ustring& domain) -> void
  {
    g_option_group_set_translation_domain (gobj (), domain.c_str ());
  }

} // namespace Glib
