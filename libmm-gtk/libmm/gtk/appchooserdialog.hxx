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
namespace gtk
{
  class LIBMM_GTK_SYMEXPORT AppChooserDialog_Class;
}
  #endif

namespace gtk
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
    explicit AppChooserDialog (const glib::ConstructParams& construct_params);
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
    explicit AppChooserDialog (const glib::ustring& content_type);

    AppChooserDialog (const glib::ustring& content_type, gtk::Window& parent);

    explicit AppChooserDialog (const glib::RefPtr<gio::File>& file);

    AppChooserDialog (const glib::RefPtr<gio::File>& file, gtk::Window& parent);

    auto
    get_widget () -> Widget*;

    auto
    get_widget () const -> const Widget*;

    auto
    set_heading (const glib::ustring& heading) -> void;

    auto
    get_heading () const -> glib::ustring;

    auto
    property_gfile () const
        -> glib::PropertyProxy_ReadOnly<glib::RefPtr<gio::File>>;

    auto
    property_heading () -> glib::PropertyProxy<glib::ustring>;

    auto
    property_heading () const -> glib::PropertyProxy_ReadOnly<glib::ustring>;

  public:
  public:
  protected:
  };

} // namespace gtk

namespace glib
{
  LIBMM_GTK_SYMEXPORT auto
  wrap (GtkAppChooserDialog* object, bool take_copy = false) -> gtk::AppChooserDialog*;
} // namespace glib

#endif

#endif
