// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_CSSPROVIDER_H
#define _GTKMM_CSSPROVIDER_H

#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm-gio/file.hxx>
#include <libmm-glib/object.hxx>
#include <libmm-gtk/csssection.hxx>
#include <libmm-gtk/styleprovider.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkCssProvider = struct _GtkCssProvider;
using GtkCssProviderClass = struct _GtkCssProviderClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{
  class GTKMM_API CssProvider_Class;
}
#endif

namespace Gtk
{

  class CssParserError : public Glib::Error
  {
  public:
    enum Code
    {
      FAILED,
      SYNTAX,
      IMPORT,
      NAME,
      UNKNOWN_VALUE
    };

    GTKMM_API
    CssParserError (Code error_code, const Glib::ustring& error_message);
    GTKMM_API explicit CssParserError (GError* gobject);
    GTKMM_API auto
    code () const -> Code;

#ifndef DOXYGEN_SHOULD_SKIP_THIS
  private:
    GTKMM_API static auto
    throw_func (GError* gobject) -> void;

    friend GTKMM_API auto
    wrap_init () -> void;

#endif
  };

} // namespace Gtk

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

  template <>
  class GTKMM_API Value<Gtk::CssParserError::Code>
    : public Glib::Value_Enum<Gtk::CssParserError::Code>
  {
  public:
    static auto
    value_type () -> GType G_GNUC_CONST;
  };

} // namespace Glib
#endif

namespace Gtk
{

  class CssParserWarning : public Glib::Error
  {
  public:
    enum Code
    {
      DEPRECATED,
      SYNTAX,
      UNIMPLEMENTED
    };

    GTKMM_API
    CssParserWarning (Code error_code, const Glib::ustring& error_message);
    GTKMM_API explicit CssParserWarning (GError* gobject);
    GTKMM_API auto
    code () const -> Code;

#ifndef DOXYGEN_SHOULD_SKIP_THIS
  private:
    GTKMM_API static auto
    throw_func (GError* gobject) -> void;

    friend GTKMM_API auto
    wrap_init () -> void;

#endif
  };

} // namespace Gtk

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

  template <>
  class GTKMM_API Value<Gtk::CssParserWarning::Code>
    : public Glib::Value_Enum<Gtk::CssParserWarning::Code>
  {
  public:
    static auto
    value_type () -> GType G_GNUC_CONST;
  };

} // namespace Glib
#endif

namespace Gtk
{

  class GTKMM_API CssProvider : public Glib::Object,
                                public StyleProvider
  {
#ifndef DOXYGEN_SHOULD_SKIP_THIS

  public:
    using CppObjectType = CssProvider;
    using CppClassType = CssProvider_Class;
    using BaseObjectType = GtkCssProvider;
    using BaseClassType = GtkCssProviderClass;

    CssProvider (const CssProvider&) = delete;
    auto
    operator= (const CssProvider&) -> CssProvider& = delete;

  private:
    friend class CssProvider_Class;
    static CppClassType cssprovider_class_;

  protected:
    explicit CssProvider (const Glib::ConstructParams& construct_params);
    explicit CssProvider (GtkCssProvider* castitem);

#endif

  public:
    CssProvider (CssProvider&& src) noexcept;
    auto
    operator= (CssProvider&& src) noexcept -> CssProvider&;

    ~CssProvider () noexcept override;

    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GtkCssProvider*
    {
      return reinterpret_cast<GtkCssProvider*> (gobject_);
    }

    auto
    gobj () const -> const GtkCssProvider*
    {
      return reinterpret_cast<GtkCssProvider*> (gobject_);
    }

    auto
    gobj_copy () -> GtkCssProvider*;

  private:
  protected:
    CssProvider ();

  public:
    static auto
    create () -> Glib::RefPtr<CssProvider>;

    auto
    to_string () const -> Glib::ustring;

    auto
    load_from_data (const std::string& data) -> void;

    auto
    load_from_file (const Glib::RefPtr<const Gio::File>& file) -> void;

    auto
    load_from_path (const std::string& path) -> void;

    auto
    load_from_resource (const std::string& resource_path) -> void;

    auto
    load_named (const Glib::ustring& name, const Glib::ustring& variant)
        -> void;

    auto
    signal_parsing_error ()
        -> Glib::SignalProxy<void (const Glib::RefPtr<const CssSection>&,
                                   const Glib::Error&)>;

  public:
  public:
  protected:
  };

} // namespace Gtk

namespace Glib
{
  GTKMM_API auto
  wrap (GtkCssProvider* object, bool take_copy = false) -> Glib::RefPtr<Gtk::CssProvider>;
} // namespace Glib

#endif
