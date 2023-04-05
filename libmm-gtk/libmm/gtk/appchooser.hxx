// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_APPCHOOSER_H
#define _GTKMM_APPCHOOSER_H

#include <libmm/gtk/mm-gtkconfig.hxx>

#ifndef GTKMM_DISABLE_DEPRECATED

  #include <libmm/glib/ustring.hxx>
  #include <sigc++/sigc++.h>

  #include <libmm/gio/appinfo.hxx>
  #include <libmm/glib/interface.hxx>

  #ifndef DOXYGEN_SHOULD_SKIP_THIS
extern "C"
{
  typedef struct _GtkAppChooserIface GtkAppChooserIface;
}
  #endif

  #ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkAppChooser = struct _GtkAppChooser;
using GtkAppChooserClass = struct _GtkAppChooserClass;
  #endif

  #ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace gtk
{
  class LIBMM_GTK_SYMEXPORT AppChooser_Class;
}
  #endif

namespace gtk
{

  class LIBMM_GTK_SYMEXPORT AppChooser : public glib::Interface
  {
  #ifndef DOXYGEN_SHOULD_SKIP_THIS

  public:
    using CppObjectType = AppChooser;
    using CppClassType = AppChooser_Class;
    using BaseObjectType = GtkAppChooser;
    using BaseClassType = GtkAppChooserIface;

    AppChooser (const AppChooser&) = delete;
    auto
    operator= (const AppChooser&) -> AppChooser& = delete;

  private:
    friend class AppChooser_Class;
    static CppClassType appchooser_class_;

  #endif
  protected:
    AppChooser ();

  #ifndef DOXYGEN_SHOULD_SKIP_THIS

    explicit AppChooser (const glib::Interface_Class& interface_class);

  public:
    explicit AppChooser (GtkAppChooser* castitem);

  protected:
  #endif

  public:
    AppChooser (AppChooser&& src) noexcept;
    auto
    operator= (AppChooser&& src) noexcept -> AppChooser&;

    ~AppChooser () noexcept override;

    static auto
    add_interface (GType gtype_implementer) -> void;

    static auto
    get_type () -> GType G_GNUC_CONST;

  #ifndef DOXYGEN_SHOULD_SKIP_THIS
    static auto
    get_base_type () -> GType G_GNUC_CONST;
  #endif

    auto
    gobj () -> GtkAppChooser*
    {
      return reinterpret_cast<GtkAppChooser*> (gobject_);
    }

    auto
    gobj () const -> const GtkAppChooser*
    {
      return reinterpret_cast<GtkAppChooser*> (gobject_);
    }

  private:
  public:
    auto
    get_app_info () -> glib::RefPtr<gio::AppInfo>;

    auto
    get_app_info () const -> glib::RefPtr<const gio::AppInfo>;

    auto
    get_content_type () const -> glib::ustring;

    auto
    refresh () -> void;

    auto
    property_content_type () const
        -> glib::PropertyProxy_ReadOnly<glib::ustring>;

  public:
  public:
  protected:
  };

} // namespace gtk

namespace glib
{
  LIBMM_GTK_SYMEXPORT auto
  wrap (GtkAppChooser* object, bool take_copy = false) -> glib::RefPtr<gtk::AppChooser>;

} // namespace glib

#endif

#endif
