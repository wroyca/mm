// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GLIBMM_OPTIONCONTEXT_H
#define _GLIBMM_OPTIONCONTEXT_H

#include <libmm/glib/error.hxx>
#include <libmm/glib/optionentry.hxx>
#include <libmm/glib/optiongroup.hxx>
#include <sigc++/signal.h>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
extern "C"
{
  typedef struct _GOptionContext GOptionContext;
}
#endif

namespace glib
{

  class OptionError : public glib::Error
  {
  public:
    enum Code
    {
      UNKNOWN_OPTION,
      BAD_VALUE,
      FAILED
    };

    LIBMM_GLIB_SYMEXPORT
    OptionError (Code error_code, const glib::ustring& error_message);
    LIBMM_GLIB_SYMEXPORT explicit OptionError (GError* gobject);
    LIBMM_GLIB_SYMEXPORT auto
    code () const -> Code;

#ifndef DOXYGEN_SHOULD_SKIP_THIS
  private:
    LIBMM_GLIB_SYMEXPORT static auto
    throw_func (GError* gobject) -> void;

    friend LIBMM_GLIB_SYMEXPORT auto
    wrap_init () -> void;

#endif
  };

  class LIBMM_GLIB_SYMEXPORT OptionContext
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    using CppObjectType = OptionContext;
    using BaseObjectType = GOptionContext;
#endif

  private:
  public:
    explicit OptionContext (const glib::ustring& parameter_string = {});

    explicit OptionContext (GOptionContext* castitem,
                            bool take_ownership = false);

    OptionContext (const OptionContext& other) = delete;
    auto
    operator= (const OptionContext& other) -> OptionContext& = delete;

    OptionContext (OptionContext&& other) noexcept;
    auto
    operator= (OptionContext&& other) noexcept -> OptionContext&;

    virtual ~OptionContext ();

    auto
    set_help_enabled (bool help_enabled = true) -> void;

    auto
    get_help_enabled () const -> bool;

    auto
    set_ignore_unknown_options (bool ignore_unknown = true) -> void;

    auto
    get_ignore_unknown_options () const -> bool;

    auto
    set_strict_posix (bool strict_posix = true) -> void;

    auto
    get_strict_posix () const -> bool;

    auto
    parse (int& argc, char**& argv) -> bool;

    auto
    parse (char**& argv) -> bool;

    auto
    add_group (OptionGroup& group) -> void;

    auto
    set_main_group (OptionGroup& group) -> void;

    auto
    get_help (bool main_help, const OptionGroup& group) const -> glib::ustring;

    auto
    get_help (bool main_help = true) const -> glib::ustring;

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

    auto
    set_summary (const glib::ustring& summary) -> void;

    auto
    get_summary () const -> glib::ustring;

    auto
    set_description (const glib::ustring& description) -> void;

    auto
    get_description () const -> glib::ustring;

    auto
    set_translation_domain (const glib::ustring& domain) -> void;

    using SlotTranslate = sigc::slot<glib::ustring (const glib::ustring&)>;

    auto
    set_translate_func (const SlotTranslate& slot) -> void;

  protected:
    GOptionContext* gobject_;
    bool has_ownership_;
  };

} // namespace glib

#endif
