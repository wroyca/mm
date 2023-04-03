// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_APPCHOOSERBUTTON_H
#define _GTKMM_APPCHOOSERBUTTON_H

#ifndef GTKMM_DISABLE_DEPRECATED

  #include <libmm/glib/ustring.hxx>
  #include <sigc++/sigc++.h>

  #include <libmm/gtk/appchooser.hxx>
  #include <libmm/gtk/widget.hxx>

  #ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkAppChooserButton = struct _GtkAppChooserButton;
using GtkAppChooserButtonClass = struct _GtkAppChooserButtonClass;
  #endif

  #ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{
  class LIBMM_GTK_SYMEXPORT AppChooserButton_Class;
}
  #endif

namespace Gtk
{

  class LIBMM_GTK_SYMEXPORT AppChooserButton : public Widget,
                                     public AppChooser
  {
  public:
  #ifndef DOXYGEN_SHOULD_SKIP_THIS
    typedef AppChooserButton CppObjectType;
    typedef AppChooserButton_Class CppClassType;
    typedef GtkAppChooserButton BaseObjectType;
    typedef GtkAppChooserButtonClass BaseClassType;
  #endif

    AppChooserButton (AppChooserButton&& src) noexcept;
    auto
    operator= (AppChooserButton&& src) noexcept -> AppChooserButton&;

    AppChooserButton (const AppChooserButton&) = delete;
    auto
    operator= (const AppChooserButton&) -> AppChooserButton& = delete;

    ~AppChooserButton () noexcept override;

  #ifndef DOXYGEN_SHOULD_SKIP_THIS

  private:
    friend LIBMM_GTK_SYMEXPORT class AppChooserButton_Class;
    static CppClassType appchooserbutton_class_;

  protected:
    explicit AppChooserButton (const Glib::ConstructParams& construct_params);
    explicit AppChooserButton (GtkAppChooserButton* castitem);

  #endif

  public:
    static auto
    get_type () -> GType G_GNUC_CONST;

  #ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
  #endif

    auto
    gobj () -> GtkAppChooserButton*
    {
      return reinterpret_cast<GtkAppChooserButton*> (gobject_);
    }

    auto
    gobj () const -> const GtkAppChooserButton*
    {
      return reinterpret_cast<GtkAppChooserButton*> (gobject_);
    }

  private:
  public:
    explicit AppChooserButton (const Glib::ustring& content_type);

    auto
    append_separator () -> void;

    auto
    append_custom_item (const Glib::ustring& name,
                        const Glib::ustring& label,
                        const Glib::RefPtr<Gio::Icon>& icon) -> void;

    auto
    set_active_custom_item (const Glib::ustring& name) -> void;

    auto
    set_show_dialog_item (bool setting = true) -> void;

    auto
    get_show_dialog_item () const -> bool;

    auto
    set_heading (const Glib::ustring& heading) -> void;

    auto
    get_heading () const -> Glib::ustring;

    auto
    set_show_default_item (bool setting = true) -> void;

    auto
    get_show_default_item () const -> bool;

    auto
    set_modal (bool modal = true) -> void;

    auto
    get_modal () const -> bool;

    auto
    signal_changed () -> Glib::SignalProxy<void ()>;

    auto
    signal_custom_item_activated (const Glib::ustring& custom_item_name = {})
        -> Glib::SignalProxyDetailed<void (const Glib::ustring&)>;

    auto
    property_show_dialog_item () -> Glib::PropertyProxy<bool>;

    auto
    property_show_dialog_item () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_heading () -> Glib::PropertyProxy<Glib::ustring>;

    auto
    property_heading () const -> Glib::PropertyProxy_ReadOnly<Glib::ustring>;

    auto
    property_show_default_item () -> Glib::PropertyProxy<bool>;

    auto
    property_show_default_item () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_modal () -> Glib::PropertyProxy<bool>;

    auto
    property_modal () const -> Glib::PropertyProxy_ReadOnly<bool>;

  public:
  public:
  protected:
  };

} // namespace Gtk

namespace Glib
{
  LIBMM_GTK_SYMEXPORT auto
  wrap (GtkAppChooserButton* object, bool take_copy = false) -> Gtk::AppChooserButton*;
} // namespace Glib

#endif

#endif
