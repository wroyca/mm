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
namespace gtk
{
  class LIBMM_GTK_SYMEXPORT AppChooserWidget_Class;
}
  #endif

namespace gtk
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
    explicit AppChooserWidget (const glib::ConstructParams& construct_params);
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
    explicit AppChooserWidget (const glib::ustring& content_type);

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
    set_default_text (const glib::ustring& text) -> void;

    auto
    get_default_text () -> glib::ustring;

    auto
    signal_application_selected ()
        -> glib::SignalProxy<void (const glib::RefPtr<gio::AppInfo>&)>;

    auto
    signal_application_activated ()
        -> glib::SignalProxy<void (const glib::RefPtr<gio::AppInfo>&)>;

    auto
    property_show_default () -> glib::PropertyProxy<bool>;

    auto
    property_show_default () const -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_show_recommended () -> glib::PropertyProxy<bool>;

    auto
    property_show_recommended () const -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_show_fallback () -> glib::PropertyProxy<bool>;

    auto
    property_show_fallback () const -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_show_other () -> glib::PropertyProxy<bool>;

    auto
    property_show_other () const -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_show_all () -> glib::PropertyProxy<bool>;

    auto
    property_show_all () const -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_default_text () -> glib::PropertyProxy<glib::ustring>;

    auto
    property_default_text () const
        -> glib::PropertyProxy_ReadOnly<glib::ustring>;

  public:
  public:
  protected:
  };

} // namespace gtk

namespace glib
{
  LIBMM_GTK_SYMEXPORT auto
  wrap (GtkAppChooserWidget* object, bool take_copy = false) -> gtk::AppChooserWidget*;
} // namespace glib

#endif

#endif
