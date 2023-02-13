


#include <mm/glib/mm-glib.hpp>

#include <mm/glib/optiongroup.hpp>
#include <mm/glib/private/optiongroup_p.hpp>


/* Copyright (C) 2002 The gtkmm Development Team
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <mm/glib/optionentry.hpp>
#include <mm/glib/optioncontext.hpp>
#include <mm/glib/utility.hpp>
#include <mm/glib/exceptionhandler.hpp>
#include <glib.h> // g_malloc
#include <cstring> // std::memset()

namespace Glib
{

namespace // anonymous
{

// A pointer to an OptionArgCallback instance is stored in CppOptionEntry::cpparg_
// when a callback function shall parse the command option's value.
class OptionArgCallback
{
public:
  explicit OptionArgCallback(const OptionGroup::SlotOptionArgString& slot)
  : slot_string_(new OptionGroup::SlotOptionArgString(slot)), slot_filename_(nullptr)
  {
  }

  explicit OptionArgCallback(const OptionGroup::SlotOptionArgFilename& slot)
  : slot_string_(nullptr), slot_filename_(new OptionGroup::SlotOptionArgFilename(slot))
  {
  }

  auto is_filename_option() const -> bool { return slot_filename_ != nullptr; }

  auto get_slot_string() const -> const OptionGroup::SlotOptionArgString* { return slot_string_; }

  auto get_slot_filename() const -> const OptionGroup::SlotOptionArgFilename* { return slot_filename_; }

  ~OptionArgCallback()
  {
    delete slot_string_;
    delete slot_filename_;
  }

private:
  // One of these slot pointers is 0 and the other one points to a slot.
  OptionGroup::SlotOptionArgString* slot_string_;
  OptionGroup::SlotOptionArgFilename* slot_filename_;

  // Not copyable
  OptionArgCallback(const OptionArgCallback&);
  auto operator=(const OptionArgCallback&) -> OptionArgCallback&;
};

extern "C" {

static auto
g_callback_pre_parse(
  GOptionContext* context, GOptionGroup* /* group */, const gpointer data, GError** error) -> gboolean
{
  OptionContext cppContext(context, false /* take_ownership */);

  const auto option_group = static_cast<OptionGroup*>(data);
  if (!option_group)
  {
    OptionError(OptionError::FAILED, "Glib::OptionGroup: g_callback_pre_parse(): "
                                     "No OptionGroup pointer available")
      .propagate(error);
    return false;
  }

  try
  {
    return option_group->on_pre_parse(cppContext);
  }
  catch (Error & err)
  {
    err.propagate(error);
  }
  catch (...)
  {
    exception_handlers_invoke();
  }
  return false;
}

static auto g_callback_error (
  GOptionContext *context, GOptionGroup * /* group */, const gpointer data, GError **error) -> void
{
  // GError** error is input data containing information on an error that
  // has occurred before this function is called.

  OptionContext cppContext(context, false /* take_ownership */);

  const auto option_group = static_cast<OptionGroup*>(data);
  if (option_group && error && *error)
  {
    try
    {
      Error::throw_exception(g_error_copy(*error));
    }
    catch (const Error& err)
    {
      return option_group->on_error(cppContext, err);
    }
  }
}

auto
OptionGroup_Translate_glibmm_callback(const gchar* string, const gpointer data) -> const gchar*
{
  const OptionGroup::SlotTranslate* the_slot = static_cast<OptionGroup::SlotTranslate*>(data);

  try
  {
    // The C docs says that the char* belongs to Glib.
    return g_strdup((*the_slot)(ustring(string)).c_str());
  }
  catch (...)
  {
    exception_handlers_invoke();
  }

  return nullptr;
}

static auto OptionGroup_Translate_glibmm_callback_destroy (void *data) -> void
{
  delete static_cast<OptionGroup::SlotTranslate*>(data);
}

} /* extern "C" */

} // anonymous namespace

// static
auto
OptionGroup::post_parse_callback(
  GOptionContext* context, GOptionGroup* /* group */, const gpointer data, GError** error) -> gboolean
{
  OptionContext cppContext(context, false /* take_ownership */);

  OptionGroup* option_group = static_cast<OptionGroup*>(data);
  if (!option_group)
  {
    OptionError(OptionError::FAILED, "Glib::OptionGroup::post_parse_callback(): "
                                     "No OptionGroup pointer available")
      .propagate(error);
    return false;
  }

  // The C args have now been given values by g_option_context_parse().
  // Convert C values to C++ values:
  for (auto& the_pair : option_group->map_entries_)
  {
    auto& cpp_entry = the_pair.second;
    cpp_entry.convert_c_to_cpp();
  }

  try
  {
    return option_group->on_post_parse(cppContext);
  }
  catch (Error & err)
  {
    err.propagate(error);
  }
  catch (...)
  {
    exception_handlers_invoke();
  }
  return false;
}

// static
auto
OptionGroup::option_arg_callback(
  const gchar* option_name, const gchar* value, const gpointer data, GError** error) -> gboolean
{
  const ustring cpp_option_name(option_name);
  const OptionGroup* const option_group = static_cast<const OptionGroup*>(data);
  if (!option_group)
  {
    OptionError(OptionError::FAILED, "Glib::OptionGroup::option_arg_callback(): "
                                     "No OptionGroup pointer available for option " +
                                       cpp_option_name)
      .propagate(error);
    return false;
  }

  // option_name is either a single dash followed by a single letter (for a
  // short name) or two dashes followed by a long option name.
  type_map_entries::const_iterator iterFind = option_group->map_entries_.end();
  if (option_name[1] == '-')
  {
    // Long option name.
    const auto long_option_name = ustring(option_name + 2);
    iterFind = option_group->map_entries_.find(long_option_name);
  }
  else
  {
    // Short option name.
    const auto short_option_name = option_name[1];
    for (iterFind = option_group->map_entries_.begin();
         iterFind != option_group->map_entries_.end(); ++iterFind)
    {
      const auto& cppOptionEntry = iterFind->second;
      if (cppOptionEntry.entry_ && cppOptionEntry.entry_->get_short_name() == short_option_name)
        break;
    }
  }

  if (iterFind == option_group->map_entries_.end())
  {
    OptionError(OptionError::UNKNOWN_OPTION, "Glib::OptionGroup::option_arg_callback(): "
                                             "Unknown option " +
                                               cpp_option_name)
      .propagate(error);
    return false;
  }

  const auto& cppOptionEntry = iterFind->second;
  if (cppOptionEntry.carg_type_ != G_OPTION_ARG_CALLBACK)
  {
    OptionError(OptionError::FAILED, "Glib::OptionGroup::option_arg_callback() "
                                     "called for non-callback option " +
                                       cpp_option_name)
      .propagate(error);
    return false;
  }

  const bool has_value = value != nullptr;
  const OptionArgCallback* const option_arg =
    static_cast<const OptionArgCallback*>(cppOptionEntry.cpparg_);
  try
  {
    if (option_arg->is_filename_option())
    {
      const auto the_slot = option_arg->get_slot_filename();
      const std::string cpp_value(value ? value : "");
      return (*the_slot)(cpp_option_name, cpp_value, has_value);
    }
    else
    {
      const auto the_slot = option_arg->get_slot_string();
      const ustring cpp_value(value ? value : "");
      return (*the_slot)(cpp_option_name, cpp_value, has_value);
    }
  }
  catch (Error & err)
  {
    err.propagate(error);
  }
  catch (...)
  {
    exception_handlers_invoke();
  }
  return false;
}

OptionGroup::OptionGroup(const ustring & name, const ustring & description,
  const ustring & help_description)
: gobject_(g_option_group_new(name.c_str(), description.c_str(), help_description.c_str(),
    this /* user_data */, nullptr /* destroy_func */))
{
  // g_callback_pre_parse(), post_parse_callback(), g_callback_error(), and
  // option_arg_callback() depend on user_data being this. The first three
  // functions get a GOptionGroup*, but it would not be correct to use it for
  // creating a new OptionGroup. They must call their virtual functions in the
  // original OptionGroup instance.

  // Connect callbacks, so that derived classes can override the virtual methods:
  g_option_group_set_parse_hooks(gobj(), &g_callback_pre_parse, &post_parse_callback);
  g_option_group_set_error_hook(gobj(), &g_callback_error);
}

OptionGroup::OptionGroup(GOptionGroup* castitem) : gobject_(castitem)
{
  // Always takes ownership - never takes copy.
}

auto OptionGroup::release_gobject () noexcept -> void
{
  // Free any C types that were allocated during add_entry():
  for (auto& the_pair : map_entries_)
  {
    auto& cpp_entry = the_pair.second;
    cpp_entry.release_c_arg();
  }

  if (gobject_)
  {
    g_option_group_unref(gobj());
    gobject_ = nullptr;
  }
}

OptionGroup::~OptionGroup()
{
  release_gobject();
}

auto OptionGroup::add_entry (const OptionEntry &entry) -> void
{
  // It does not copy the entry, so it needs to live as long as the group.

  // g_option_group_add_entries takes an array, with the last item in the array having a null
  // long_name.
  // Hopefully this will be properly documented eventually - see bug #

  // Create a temporary array, just so we can give the correct thing to g_option_group_add_entries:
  GOptionEntry array[2];
  array[0] = *entry.gobj(); // Copy contents.
  std::memset(&array[1], 0, sizeof(GOptionEntry));

  g_option_group_add_entries(gobj(), array);
}

auto OptionGroup::add_entry (const OptionEntry &entry, bool &arg) -> void
{
  add_entry_with_wrapper(entry,
    G_OPTION_ARG_NONE /* Actually a boolean on/off, depending on whether the argument name was given, without argument parameters. */,
    &arg);
}

auto OptionGroup::add_entry (const OptionEntry &entry, int &arg) -> void
{
  add_entry_with_wrapper(entry, G_OPTION_ARG_INT, &arg);
}

auto OptionGroup::add_entry (const OptionEntry &entry, double &arg) -> void
{
  add_entry_with_wrapper(entry, G_OPTION_ARG_DOUBLE, &arg);
}

auto OptionGroup::add_entry (const OptionEntry &entry, ustring &arg) -> void
{
  add_entry_with_wrapper(entry, G_OPTION_ARG_STRING, &arg);
}

auto OptionGroup::add_entry (const OptionEntry &entry, vecustrings &arg) -> void
{
  add_entry_with_wrapper(entry, G_OPTION_ARG_STRING_ARRAY, &arg);
}

auto OptionGroup::add_entry_filename (const OptionEntry &entry, std::string &arg) -> void
{
  add_entry_with_wrapper(entry, G_OPTION_ARG_FILENAME, &arg);
}

auto OptionGroup::add_entry_filename (const OptionEntry &entry, vecstrings &arg) -> void
{
  add_entry_with_wrapper(entry, G_OPTION_ARG_FILENAME_ARRAY, &arg);
}

// When the command argument value is to be parsed by a user-supplied function
// (indicated by G_OPTION_ARG_CALLBACK), the OptionEntry::Flags::FILENAME in 'entry' is ignored.
// set_c_arg_default() clears or sets it as required in a copy of 'entry'.
//
// The glib API is inconsistent here. The choice between UTF-8 and filename
// encoding is done with G_OPTION_ARG_STRING, G_OPTION_ARG_FILENAME,
// G_OPTION_ARG_STRING_ARRAY, and G_OPTION_ARG_FILENAME_ARRAY, which in glibmm
// are set by OptionGroup::add_entry[_filename]. But when a callback function
// is chosen, there is only G_OPTION_ARG_CALLBACK, and the encoding is chosen
// with OptionEntry::Flags::FILENAME. We do this automatiically in set_c_arg_default().
// Other option flags are set by OptionEntry::set_flags().

auto OptionGroup::add_entry (const OptionEntry &entry, const SlotOptionArgString &slot) -> void
{
  // The OptionArgCallback is deleted in release_c_arg().
  add_entry_with_wrapper(entry, G_OPTION_ARG_CALLBACK, new OptionArgCallback(slot));
}

auto OptionGroup::add_entry_filename (
  const OptionEntry &entry, const SlotOptionArgFilename &slot) -> void
{
  // The OptionArgCallback is deleted in release_c_arg().
  add_entry_with_wrapper(entry, G_OPTION_ARG_CALLBACK, new OptionArgCallback(slot));
}

auto OptionGroup::add_entry_with_wrapper (
  const OptionEntry &entry, const GOptionArg arg_type, void *cpp_arg) -> void
{
  const auto name = entry.get_long_name();
  const type_map_entries::iterator iterFind = map_entries_.find(name);
  if (iterFind == map_entries_.end()) // If we have not added this entry already
  {
    CppOptionEntry cppEntry;
    // g_option_group_add_entry() does not take its own copy, so we must keep the instance alive.
    cppEntry.entry_ = new OptionEntry(entry);
    // cppEntry.entry_ is deleted in release_c_arg(), via the destructor.

    // Several options can refer to the same C++ variable,
    // typically a pair of --enable-x / --disable-x options.
    // Only one C variable shall be allocated for them.
    // See https://bugzilla.gnome.org/show_bug.cgi?id=744854.
    bool is_duplicate = false;
    void* carg = nullptr;
    if (arg_type != G_OPTION_ARG_CALLBACK)
    {
      for (type_map_entries::iterator iter = map_entries_.begin(); iter != map_entries_.end();
           ++iter)
      {
        const auto& cpp_entry = iter->second;
        if (cpp_entry.cpparg_ == cpp_arg && cpp_entry.carg_type_ == arg_type && cpp_entry.carg_)
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
      cppEntry.allocate_c_arg();
      cppEntry.set_c_arg_default(cpp_arg);
      carg = cppEntry.carg_;
    }
    cppEntry.cpparg_ = cpp_arg;

    // Give the information to the C API:
    cppEntry.entry_->gobj()->arg = arg_type;
    cppEntry.entry_->gobj()->arg_data = carg;

    // Remember the C++/C mapping so that we can use it later:
    map_entries_[name] = cppEntry;

    add_entry(*cppEntry.entry_);
  }
  else if (arg_type == G_OPTION_ARG_CALLBACK)
  {
    // Delete the OptionArgCallback instance that was allocated by add_entry()
    // or add_entry_filename().
    const auto option_arg = static_cast<OptionArgCallback*>(cpp_arg);
    delete option_arg;
  }
}

auto
OptionGroup::on_pre_parse(OptionContext& /* context */) -> bool
{
  return true;
}

auto
OptionGroup::on_post_parse(OptionContext& /* context */) -> bool
{
  return true;
}

auto OptionGroup::on_error (OptionContext & /* context */, const Error & /* error */) -> void
{
}

auto OptionGroup::set_translate_func (const SlotTranslate &slot) -> void
{
  // Create a copy of the slot. A pointer to this will be passed through the
  // callback's data parameter.  It will be deleted when
  // OptionGroup_Translate_glibmm_callback_destroy() is called.
  const auto slot_copy = new SlotTranslate(slot);
  g_option_group_set_translate_func(gobj(), &OptionGroup_Translate_glibmm_callback, slot_copy,
    &OptionGroup_Translate_glibmm_callback_destroy);
}

OptionGroup::CppOptionEntry::CppOptionEntry()
: carg_type_(G_OPTION_ARG_NONE), carg_(nullptr), cpparg_(nullptr), entry_(nullptr)
{
}

auto OptionGroup::CppOptionEntry::allocate_c_arg () -> void
{
  // Create an instance of the appropriate C type.
  // This will be destroyed in the OptionGroup destructor.
  //
  // We must also call set_c_arg_default() to give these C types the specified
  // defaults based on the C++-typed arguments.
  switch (carg_type_)
  {
  case G_OPTION_ARG_STRING: // The char* will be for UTF8 a string.
  case G_OPTION_ARG_FILENAME: // The char* will be for a string in the current locale's encoding.
  {
    char** typed_arg = new char*;
    // The C code will allocate a char* and put it here, for us to g_free() later.
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
    // The C code will allocate a char** and put it here, for us to g_strfreev() later.
    *typed_arg = nullptr;
    carg_ = typed_arg;

    break;
  }
  case G_OPTION_ARG_NONE: // Actually a boolean.
  {
    gboolean* typed_arg = new gboolean;
    *typed_arg = false;
    carg_ = typed_arg;

    break;
  }
  case G_OPTION_ARG_CALLBACK:
  {
    // The C arg pointer is a function pointer, cast to void*.
    //
    //   carg_ = reinterpret_cast<void*>(&OptionGroup::option_arg_callback);
    // or
    //   union {
    //     void* dp;
    //     GOptionArgFunc fp;
    //   } u;
    //   u.fp = &OptionGroup::option_arg_callback;
    //   carg_ = u.dp;
    // ? See
    // https://bugzilla.gnome.org/show_bug.cgi?id=589197
    // https://github.com/libsigcplusplus/libsigcplusplus/issues/1
    // https://github.com/libsigcplusplus/libsigcplusplus/issues/8
    carg_ = reinterpret_cast<void*>(&OptionGroup::option_arg_callback);

    break;
  }
  default:
  {
    break;
  }
  }
}

auto OptionGroup::CppOptionEntry::set_c_arg_default (void *cpp_arg) -> void
{
  switch (carg_type_)
  {
  case G_OPTION_ARG_INT:
  {
    *static_cast<int*>(carg_) = *static_cast<int*>(cpp_arg);
    break;
  }
  case G_OPTION_ARG_DOUBLE:
  {
    *static_cast<double*>(carg_) = *static_cast<double*>(cpp_arg);
    break;
  }
  case G_OPTION_ARG_NONE:
  {
    *static_cast<gboolean*>(carg_) = *static_cast<bool*>(cpp_arg);
    break;
  }
  case G_OPTION_ARG_STRING:
  case G_OPTION_ARG_FILENAME:
  case G_OPTION_ARG_STRING_ARRAY:
  case G_OPTION_ARG_FILENAME_ARRAY:
  {
    // No need to set default values for string-valued options.
    // If *carg_ is still 0, when convert_c_to_cpp() is called, just don't
    // touch *cpparg_. Besides, setting default values in *carg_ can result
    // in memory leaks, because glib would not free the strings before
    // the char*'s are overwritten with pointers to newly allocated copies
    // of the command option arguments.
    break;
  }
  case G_OPTION_ARG_CALLBACK:
  {
    // No value to set here. The arg pointer is a function pointer.

    // Set or clear OptionEntry::Flags::FILENAME in *entry_.
    const OptionArgCallback* const option_arg = static_cast<const OptionArgCallback*>(cpp_arg);
    if (option_arg->is_filename_option())
    {
      entry_->set_flags(entry_->get_flags() | OptionEntry::Flags::FILENAME);
    }
    else
    {
      entry_->set_flags(entry_->get_flags() & ~OptionEntry::Flags::FILENAME);
    }
    break;
  }
  default:
  {
    break;
  }
  }
}

auto OptionGroup::CppOptionEntry::release_c_arg () -> void
{
  // Delete the instances that we created in allocate_c_arg().
  // Notice that we delete the type that we created, but not the value to which it points.
  if (carg_)
  {
    switch (carg_type_)
    {
    case G_OPTION_ARG_STRING:
    case G_OPTION_ARG_FILENAME:
    {
      char** typed_arg = static_cast<char**>(carg_);
      g_free(*typed_arg); // Free the char* string at typed_arg, if allocated by the C code.
      delete typed_arg; // Delete the char** that we allocated in allocate_c_arg().

      break;
    }
    case G_OPTION_ARG_INT:
    {
      const int* typed_arg = static_cast<int*>(carg_);
      delete typed_arg;

      break;
    }
    case G_OPTION_ARG_DOUBLE:
    {
      const double* typed_arg = static_cast<double*>(carg_);
      delete typed_arg;

      break;
    }
    case G_OPTION_ARG_STRING_ARRAY:
    case G_OPTION_ARG_FILENAME_ARRAY:
    {
      char*** typed_arg = static_cast<char***>(carg_);
      g_strfreev(*typed_arg); // Free the array of strings and the array at typed_arg, if allocated
                              // by the C code.
      delete typed_arg; // Delete the char*** that we allocated in allocate_c_arg().

      break;
    }
    case G_OPTION_ARG_NONE: // Actually a boolean.
    {
      const gboolean* typed_arg = static_cast<gboolean*>(carg_);
      delete typed_arg;

      break;
    }
    case G_OPTION_ARG_CALLBACK:
    {
      // Delete the OptionArgCallback instance that was allocated by add_entry()
      // or add_entry_filename().
      const auto option_arg = static_cast<OptionArgCallback*>(cpparg_);
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

auto OptionGroup::CppOptionEntry::convert_c_to_cpp () -> void
{
  if (!carg_)
    return;

  switch (carg_type_)
  {
  case G_OPTION_ARG_STRING:
  {
    char** typed_arg = static_cast<char**>(carg_);
    const auto typed_cpp_arg = static_cast<ustring *>(cpparg_);
    if (typed_arg && *typed_arg && typed_cpp_arg)
    {
      *typed_cpp_arg = *typed_arg;
    }
    break;
  }
  case G_OPTION_ARG_FILENAME:
  {
    char** typed_arg = static_cast<char**>(carg_);
    const auto typed_cpp_arg = static_cast<std::string*>(cpparg_);
    if (typed_arg && *typed_arg && typed_cpp_arg)
    {
      *typed_cpp_arg = *typed_arg;
    }
    break;
  }
  case G_OPTION_ARG_INT:
  {
    *(int*)cpparg_ = *static_cast<int*>(carg_);
    break;
  }
  case G_OPTION_ARG_DOUBLE:
  {
    *(double*)cpparg_ = *static_cast<double*>(carg_);
    break;
  }
  case G_OPTION_ARG_STRING_ARRAY:
  {
    char*** typed_arg = static_cast<char***>(carg_);
    const auto typed_cpp_arg = static_cast<vecustrings*>(cpparg_);
    if (typed_arg && *typed_arg && typed_cpp_arg)
    {
      typed_cpp_arg->clear();

      // The C array is null-terminated.
      // std::vector<Glib::ustring> array_handle(*typed_arg,  Glib::OWNERSHIP_NONE);

      // The SUN Forte compiler complains about this:
      // "optiongroup.cc", line 354: Error: Cannot assign Glib::ArrayHandle<Glib::ustring,
      // Glib::Container_Helpers::TypeTraits<Glib::ustring>> to std::vector<Glib::ustring> without
      // "std::vector<Glib::ustring>::operator=(const std::vector<Glib::ustring>&)";.
      //
      //(*typed_cpp_arg) = array_handle;
      //
      // And the Tru64 compiler does not even like us to instantiate the StringArrayHandle:
      //
      // cxx: Error: ../../glib/glibmm/containerhandle_shared.h, line 149: the operand
      //     of a pointer dynamic_cast must be a pointer to a complete class type
      //   return dynamic_cast<CppType>(Glib::wrap_auto(cobj, false /* take_copy */));

      // for(auto iter = array_handle.begin(); iter !=
      // array_handle.end(); ++iter)
      //{
      //  typed_cpp_arg->emplace_back(*iter);
      //}

      // So we do this:

      char** char_array_next = *typed_arg;
      while (*char_array_next)
      {
        typed_cpp_arg->emplace_back(*char_array_next);
        ++char_array_next;
      }
    }
    break;
  }
  case G_OPTION_ARG_FILENAME_ARRAY:
  {
    char*** typed_arg = static_cast<char***>(carg_);
    const auto typed_cpp_arg = static_cast<vecstrings*>(cpparg_);
    if (typed_arg && *typed_arg && typed_cpp_arg)
    {
      typed_cpp_arg->clear();

      // See comments above about the SUN Forte and Tru64 compilers.

      char** char_array_next = *typed_arg;
      while (*char_array_next)
      {
        typed_cpp_arg->emplace_back(*char_array_next);
        ++char_array_next;
      }
    }
    break;
  }
  case G_OPTION_ARG_NONE: // Actually a boolean.
  {
    *static_cast<bool*>(cpparg_) = *static_cast<gboolean*>(carg_);
    break;
  }
  case G_OPTION_ARG_CALLBACK:
  {
    // Nothing to convert here. That's a task for the callback function
    //(the SlotOptionArgString or SlotOptionArgFilename).
    break;
  }
  default:
  {
    break;
  }
  }
}

auto
OptionGroup::gobj_copy() const -> GOptionGroup*
{
  return g_option_group_ref(gobject_);
}

} // namespace Glib

namespace
{
} // anonymous namespace


namespace Glib
{


auto OptionGroup::set_translation_domain (const ustring &domain) -> void
{
  g_option_group_set_translation_domain(gobj(), domain.c_str());
}


} // namespace Glib


