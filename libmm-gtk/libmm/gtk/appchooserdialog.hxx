// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_APPCHOOSERDIALOG_H
#define _GTKMM_APPCHOOSERDIALOG_H

#ifndef GTKMM_DISABLE_DEPRECATED

  #include <libmm/glib/ustring.hxx>
  #include <sigc++/sigc++.h>

  #include <libmm/gio/file.hxx>
  #include <libmm/gtk/appchooser.hxx>
  #include <libmm/gtk/dialog.hxx>

  #ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkAppChooserDialog = struct _GtkAppChooserDialog;
using GtkAppChooserDialogClass = struct _GtkAppChooserDialogClass;
  #endif

  #ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{
  class LIBMM_GTK_SYMEXPORT AppChooserDialog_Class;
}
  #endif

namespace Gtk
{

  class LIBMM_GTK_SYMEXPORT AppChooserDialog : public Dialog,
                                     public AppChooser
  {
  public:
  #ifndef DOXYGEN_SHOULD_SKIP_THIS
    typedef AppChooserDialog CppObjectType;
    typedef AppChooserDialog_Class CppClassType;
    typedef GtkAppChooserDialog BaseObjectType;
    typedef GtkAppChooserDialogClass BaseClassType;
  #endif

    AppChooserDialog (AppChooserDialog&& src) noexcept;
    auto
    operator= (AppChooserDialog&& src) noexcept -> AppChooserDialog&;

    AppChooserDialog (const AppChooserDialog&) = delete;
    auto
    operator= (const AppChooserDialog&) -> AppChooserDialog& = delete;

    ~AppChooserDialog () noexcept override;

  #ifndef DOXYGEN_SHOULD_SKIP_THIS

  private:
    friend LIBMM_GTK_SYMEXPORT class AppChooserDialog_Class;
    static CppClassType appchooserdialog_class_;

  protected:
    explicit AppChooserDialog (const Glib::ConstructParams& construct_params);
    explicit AppChooserDialog (GtkAppChooserDialog* castitem);

  #endif

  public:
    static auto
    get_type () -> GType G_GNUC_CONST;

  #ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
  #endif

    auto
    gobj () -> GtkAppChooserDialog*
    {
      return reinterpret_cast<GtkAppChooserDialog*> (gobject_);
    }

    auto
    gobj () const -> const GtkAppChooserDialog*
    {
      return reinterpret_cast<GtkAppChooserDialog*> (gobject_);
    }

  private:
  public:
    explicit AppChooserDialog (const Glib::ustring& content_type);

    AppChooserDialog (const Glib::ustring& content_type, Gtk::Window& parent);

    explicit AppChooserDialog (const Glib::RefPtr<Gio::File>& file);

    AppChooserDialog (const Glib::RefPtr<Gio::File>& file, Gtk::Window& parent);

    auto
    get_widget () -> Widget*;

    auto
    get_widget () const -> const Widget*;

    auto
    set_heading (const Glib::ustring& heading) -> void;

    auto
    get_heading () const -> Glib::ustring;

    auto
    property_gfile () const
        -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<Gio::File>>;

    auto
    property_heading () -> Glib::PropertyProxy<Glib::ustring>;

    auto
    property_heading () const -> Glib::PropertyProxy_ReadOnly<Glib::ustring>;

  public:
  public:
  protected:
  };

} // namespace Gtk

namespace Glib
{
  LIBMM_GTK_SYMEXPORT auto
  wrap (GtkAppChooserDialog* object, bool take_copy = false) -> Gtk::AppChooserDialog*;
} // namespace Glib

#endif

#endif
