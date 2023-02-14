// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GLIBMM_OPTIONCONTEXT_H
#define _GLIBMM_OPTIONCONTEXT_H

#include <libmm-glib/error.hxx>
#include <libmm-glib/optionentry.hxx>
#include <libmm-glib/optiongroup.hxx>
#include <sigc++/signal.h>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
extern "C"
{
  typedef struct _GOptionContext GOptionContext;
}
#endif

namespace Glib
{

  class OptionError : public Glib::Error
  {
  public:
    enum Code
    {
      UNKNOWN_OPTION,
      BAD_VALUE,
      FAILED
    };

    GLIBMM_API
    OptionError (Code error_code, const Glib::ustring& error_message);
    GLIBMM_API explicit OptionError (GError* gobject);
    GLIBMM_API auto
    code () const -> Code;

#ifndef DOXYGEN_SHOULD_SKIP_THIS
  private:
    GLIBMM_API static void
    throw_func (GError* gobject);

    friend GLIBMM_API void
    wrap_init ();

#endif
  };

  class GLIBMM_API OptionContext
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    using CppObjectType = OptionContext;
    using BaseObjectType = GOptionContext;
#endif

  private:
  public:
    explicit OptionContext (const Glib::ustring& parameter_string = {});

    explicit OptionContext (GOptionContext* castitem,
                            bool take_ownership = false);

    OptionContext (const OptionContext& other) = delete;
    auto
    operator= (const OptionContext& other) -> OptionContext& = delete;

    OptionContext (OptionContext&& other) noexcept;
    auto
    operator= (OptionContext&& other) noexcept -> OptionContext&;

    virtual ~OptionContext ();

    void
    set_help_enabled (bool help_enabled = true);

    auto
    get_help_enabled () const -> bool;

    void
    set_ignore_unknown_options (bool ignore_unknown = true);

    auto
    get_ignore_unknown_options () const -> bool;

    void
    set_strict_posix (bool strict_posix = true);

    auto
    get_strict_posix () const -> bool;

    auto
    parse (int& argc, char**& argv) -> bool;

    auto
    parse (char**& argv) -> bool;

    void
    add_group (OptionGroup& group);

    void
    set_main_group (OptionGroup& group);

    auto
    get_help (bool main_help, const OptionGroup& group) const -> Glib::ustring;

    auto
    get_help (bool main_help = true) const -> Glib::ustring;

    auto
    gobj () -> GOptionContext*
    {
      return gobject_;
    }

    auto
    gobj () const -> const GOptionContext*
    {
      return gobject_;
    }

    void
    set_summary (const Glib::ustring& summary);

    auto
    get_summary () const -> Glib::ustring;

    void
    set_description (const Glib::ustring& description);

    auto
    get_description () const -> Glib::ustring;

    void
    set_translation_domain (const Glib::ustring& domain);

    using SlotTranslate = sigc::slot<Glib::ustring (const Glib::ustring&)>;

    void
    set_translate_func (const SlotTranslate& slot);

  protected:
    GOptionContext* gobject_;
    bool has_ownership_;
  };

} // namespace Glib

#endif
