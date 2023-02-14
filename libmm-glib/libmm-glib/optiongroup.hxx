
#ifndef _GLIBMM_OPTIONGROUP_H
#define _GLIBMM_OPTIONGROUP_H

#include <glib.h>
#include <libmm-glib/error.hxx>
#include <libmm-glib/ustring.hxx>
#include <map>
#include <sigc++/slot.h>
#include <vector>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
extern "C"
{
  typedef struct _GOptionGroup GOptionGroup;
}
#endif

namespace Glib
{

#ifndef DOXYGEN_SHOULD_SKIP_THIS
  class OptionEntry;
  class OptionContext;
#endif

  class GLIBMM_API OptionGroup
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    using CppObjectType = OptionGroup;
    using BaseObjectType = GOptionGroup;
#endif

  private:
  public:
    using SlotTranslate = sigc::slot<Glib::ustring (const Glib::ustring&)>;

    using SlotOptionArgString =
        sigc::slot<bool (const Glib::ustring&, const Glib::ustring&, bool)>;

    using SlotOptionArgFilename =
        sigc::slot<bool (const Glib::ustring&, const std::string&, bool)>;

    OptionGroup (const Glib::ustring& name,
                 const Glib::ustring& description,
                 const Glib::ustring& help_description = {});

    explicit OptionGroup (GOptionGroup* castitem);

    OptionGroup (const OptionGroup& other) = delete;
    auto
    operator= (const OptionGroup& other) -> OptionGroup& = delete;
    OptionGroup (OptionGroup&& other) = delete;
    auto
    operator= (OptionGroup&& other) -> OptionGroup& = delete;

    virtual ~OptionGroup ();

    virtual auto
    on_pre_parse (OptionContext& context) -> bool;
    virtual auto
    on_post_parse (OptionContext& context) -> bool;
    virtual void
    on_error (OptionContext& context, const Error& error);

    void
    add_entry (const OptionEntry& entry);

    using vecustrings = std::vector<Glib::ustring>;
    using vecstrings = std::vector<std::string>;

    void
    add_entry (const OptionEntry& entry, bool& arg);

    void
    add_entry (const OptionEntry& entry, int& arg);

    void
    add_entry (const OptionEntry& entry, double& arg);

    void
    add_entry (const OptionEntry& entry, Glib::ustring& arg);

    void
    add_entry_filename (const OptionEntry& entry, std::string& arg);

    void
    add_entry (const OptionEntry& entry, vecustrings& arg);

    void
    add_entry_filename (const OptionEntry& entry, vecstrings& arg);

    void
    add_entry (const OptionEntry& entry, const SlotOptionArgString& slot);

    void
    add_entry_filename (const OptionEntry& entry,
                        const SlotOptionArgFilename& slot);

    void
    set_translate_func (const SlotTranslate& slot);

    void
    set_translation_domain (const Glib::ustring& domain);

    auto
    gobj () -> GOptionGroup*
    {
      return gobject_;
    }

    auto
    gobj () const -> const GOptionGroup*
    {
      return gobject_;
    }

    auto
    gobj_copy () const -> GOptionGroup*;

  protected:
#ifndef DOXYGEN_SHOULD_SKIP_THIS

    class CppOptionEntry
    {
    public:
      CppOptionEntry ();

      void
      allocate_c_arg ();
      void
      set_c_arg_default (void* cpp_arg);
      void
      convert_c_to_cpp ();
      void
      release_c_arg ();

      GOptionArg carg_type_;
      void* carg_;
      void* cpparg_;
      OptionEntry* entry_;
    };

    void
    add_entry_with_wrapper (const OptionEntry& entry,
                            GOptionArg arg_type,
                            void* cpp_arg);

    static auto
    post_parse_callback (GOptionContext* context,
                         GOptionGroup* group,
                         gpointer data,
                         GError** error) -> gboolean;

    static auto
    option_arg_callback (const gchar* option_name,
                         const gchar* value,
                         gpointer data,
                         GError** error) -> gboolean;

    using type_map_entries = std::map<Glib::ustring, CppOptionEntry>;
    type_map_entries map_entries_;

    GOptionGroup* gobject_;
#endif

  private:
    void
    release_gobject () noexcept;
  };

} // namespace Glib

#endif
