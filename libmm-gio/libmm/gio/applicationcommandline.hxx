// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GIOMM_APPLICATIONCOMMANDLINE_H
#define _GIOMM_APPLICATIONCOMMANDLINE_H

#include <libmm/glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm/gio/file.hxx>
#include <libmm/gio/inputstream.hxx>
#include <libmm/glib/object.hxx>
#include <libmm/glib/variant.hxx>
#include <libmm/glib/variantdict.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GApplicationCommandLine = struct _GApplicationCommandLine;
using GApplicationCommandLineClass = struct _GApplicationCommandLineClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace gio
{
  class LIBMM_GIO_SYMEXPORT ApplicationCommandLine_Class;
}
#endif

namespace gio
{

  class LIBMM_GIO_SYMEXPORT ApplicationCommandLine : public glib::Object
  {
#ifndef DOXYGEN_SHOULD_SKIP_THIS

  public:
    using CppObjectType = ApplicationCommandLine;
    using CppClassType = ApplicationCommandLine_Class;
    using BaseObjectType = GApplicationCommandLine;
    using BaseClassType = GApplicationCommandLineClass;

    ApplicationCommandLine (const ApplicationCommandLine&) = delete;
    auto
    operator= (const ApplicationCommandLine&)
        -> ApplicationCommandLine& = delete;

  private:
    friend class ApplicationCommandLine_Class;
    static CppClassType applicationcommandline_class_;

  protected:
    explicit ApplicationCommandLine (
        const glib::ConstructParams& construct_params);
    explicit ApplicationCommandLine (GApplicationCommandLine* castitem);

#endif

  public:
    ApplicationCommandLine (ApplicationCommandLine&& src) noexcept;
    auto
    operator= (ApplicationCommandLine&& src) noexcept
        -> ApplicationCommandLine&;

    ~ApplicationCommandLine () noexcept override;

    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GApplicationCommandLine*
    {
      return reinterpret_cast<GApplicationCommandLine*> (gobject_);
    }

    auto
    gobj () const -> const GApplicationCommandLine*
    {
      return reinterpret_cast<GApplicationCommandLine*> (gobject_);
    }

    auto
    gobj_copy () -> GApplicationCommandLine*;

  private:
  protected:
    ApplicationCommandLine ();

  public:
    auto
    get_arguments (int& argc) const -> char**;

    auto
    get_options_dict () -> glib::RefPtr<glib::VariantDict>;

    auto
    get_options_dict () const -> glib::RefPtr<const glib::VariantDict>;

    auto
    get_stdin () -> glib::RefPtr<InputStream>;

    auto
    get_stdin () const -> glib::RefPtr<const InputStream>;

    auto
    get_cwd () const -> std::string;

    auto
    get_environ () const -> std::vector<std::string>;

    auto
    getenv (const glib::ustring& name) const -> std::string;

    auto
    is_remote () const -> bool;

    auto
    get_platform_data () const
        -> glib::Variant<std::map<glib::ustring, glib::VariantBase>>;

    auto
    set_exit_status (int exit_status) -> void;

    auto
    get_exit_status () const -> int;

    auto
    print (const glib::ustring& message) -> void;

    auto
    printerr (const glib::ustring& message) -> void;

    auto
    create_file_for_arg (const glib::ustring& arg) const -> glib::RefPtr<File>;

  public:
  public:
  protected:
  };

} // namespace gio

namespace glib
{

  LIBMM_GIO_SYMEXPORT
  auto
  wrap (GApplicationCommandLine* object, bool take_copy = false) -> glib::RefPtr<gio::ApplicationCommandLine>;
} // namespace glib

#endif
