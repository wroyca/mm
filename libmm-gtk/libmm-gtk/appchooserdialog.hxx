
#ifndef _GTKMM_APPCHOOSERDIALOG_H
#define _GTKMM_APPCHOOSERDIALOG_H

#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm-gio/file.hxx>
#include <libmm-gtk/appchooser.hxx>
#include <libmm-gtk/dialog.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkAppChooserDialog = struct _GtkAppChooserDialog;
using GtkAppChooserDialogClass = struct _GtkAppChooserDialogClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{
  class GTKMM_API AppChooserDialog_Class;
}
#endif

namespace Gtk
{

  class GTKMM_API AppChooserDialog : public Dialog,
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
    friend GTKMM_API class AppChooserDialog_Class;
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

    void
    set_heading (const Glib::ustring& heading);

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

  GTKMM_API
  auto
  wrap (GtkAppChooserDialog* object, bool take_copy = false) -> Gtk::AppChooserDialog*;
} // namespace Glib

#endif
