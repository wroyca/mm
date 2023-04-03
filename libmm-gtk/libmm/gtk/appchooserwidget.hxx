// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_APPCHOOSERWIDGET_H
#define _GTKMM_APPCHOOSERWIDGET_H

#ifndef GTKMM_DISABLE_DEPRECATED

  #include <libmm/glib/ustring.hxx>
  #include <sigc++/sigc++.h>

  #include <libmm/gtk/appchooser.hxx>
  #include <libmm/gtk/widget.hxx>

  #ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkAppChooserWidget = struct _GtkAppChooserWidget;
using GtkAppChooserWidgetClass = struct _GtkAppChooserWidgetClass;
  #endif

  #ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{
  class LIBMM_GTK_SYMEXPORT AppChooserWidget_Class;
}
  #endif

namespace Gtk
{

  class LIBMM_GTK_SYMEXPORT AppChooserWidget : public Widget,
                                     public AppChooser
  {
  public:
  #ifndef DOXYGEN_SHOULD_SKIP_THIS
    typedef AppChooserWidget CppObjectType;
    typedef AppChooserWidget_Class CppClassType;
    typedef GtkAppChooserWidget BaseObjectType;
    typedef GtkAppChooserWidgetClass BaseClassType;
  #endif

    AppChooserWidget (AppChooserWidget&& src) noexcept;
    auto
    operator= (AppChooserWidget&& src) noexcept -> AppChooserWidget&;

    AppChooserWidget (const AppChooserWidget&) = delete;
    auto
    operator= (const AppChooserWidget&) -> AppChooserWidget& = delete;

    ~AppChooserWidget () noexcept override;

  #ifndef DOXYGEN_SHOULD_SKIP_THIS

  private:
    friend LIBMM_GTK_SYMEXPORT class AppChooserWidget_Class;
    static CppClassType appchooserwidget_class_;

  protected:
    explicit AppChooserWidget (const Glib::ConstructParams& construct_params);
    explicit AppChooserWidget (GtkAppChooserWidget* castitem);

  #endif

  public:
    static auto
    get_type () -> GType G_GNUC_CONST;

  #ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
  #endif

    auto
    gobj () -> GtkAppChooserWidget*
    {
      return reinterpret_cast<GtkAppChooserWidget*> (gobject_);
    }

    auto
    gobj () const -> const GtkAppChooserWidget*
    {
      return reinterpret_cast<GtkAppChooserWidget*> (gobject_);
    }

  private:
  public:
    explicit AppChooserWidget (const Glib::ustring& content_type);

    auto
    set_show_default (bool setting = true) -> void;

    auto
    get_show_default () -> bool;

    auto
    set_show_recommended (bool setting = true) -> void;

    auto
    get_show_recommended () const -> bool;

    auto
    set_show_fallback (bool setting = true) -> void;

    auto
    get_show_fallback () const -> bool;

    auto
    set_show_other (bool setting = true) -> void;

    auto
    get_show_other () const -> bool;

    auto
    set_show_all (bool setting = true) -> void;

    auto
    get_show_all () const -> bool;

    auto
    set_default_text (const Glib::ustring& text) -> void;

    auto
    get_default_text () -> Glib::ustring;

    auto
    signal_application_selected ()
        -> Glib::SignalProxy<void (const Glib::RefPtr<Gio::AppInfo>&)>;

    auto
    signal_application_activated ()
        -> Glib::SignalProxy<void (const Glib::RefPtr<Gio::AppInfo>&)>;

    auto
    property_show_default () -> Glib::PropertyProxy<bool>;

    auto
    property_show_default () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_show_recommended () -> Glib::PropertyProxy<bool>;

    auto
    property_show_recommended () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_show_fallback () -> Glib::PropertyProxy<bool>;

    auto
    property_show_fallback () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_show_other () -> Glib::PropertyProxy<bool>;

    auto
    property_show_other () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_show_all () -> Glib::PropertyProxy<bool>;

    auto
    property_show_all () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_default_text () -> Glib::PropertyProxy<Glib::ustring>;

    auto
    property_default_text () const
        -> Glib::PropertyProxy_ReadOnly<Glib::ustring>;

  public:
  public:
  protected:
  };

} // namespace Gtk

namespace Glib
{
  LIBMM_GTK_SYMEXPORT auto
  wrap (GtkAppChooserWidget* object, bool take_copy = false) -> Gtk::AppChooserWidget*;
} // namespace Glib

#endif

#endif