// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_WINDOW_H
#define _GTKMM_WINDOW_H

#include <libmm/glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <vector>

#include <libmm/gdk/surface.hxx>
#include <libmm/gdk/texture.hxx>
#include <libmm/glib/object.hxx>
#include <libmm/gtk/native.hxx>
#include <libmm/gtk/root.hxx>
#include <libmm/gtk/shortcutmanager.hxx>
#include <libmm/gtk/widget.hxx>
#include <libmm/gtk/windowgroup.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkWindow = struct _GtkWindow;
using GtkWindowClass = struct _GtkWindowClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace gtk
{
  class LIBMM_GTK_SYMEXPORT Window_Class;
}
#endif

namespace gio
{
  class LIBMM_GTK_SYMEXPORT ListModel;
}

namespace gtk
{

  class LIBMM_GTK_SYMEXPORT Application;
  class LIBMM_GTK_SYMEXPORT WindowGroup;

  class LIBMM_GTK_SYMEXPORT Window : public Widget,
                           public Native,
                           public ShortcutManager,
                           public Root
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    typedef Window CppObjectType;
    typedef Window_Class CppClassType;
    typedef GtkWindow BaseObjectType;
    typedef GtkWindowClass BaseClassType;
#endif

    Window (const Window&) = delete;
    auto
    operator= (const Window&) -> Window& = delete;

    ~Window () noexcept override;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

  private:
    friend LIBMM_GTK_SYMEXPORT class Window_Class;
    static CppClassType window_class_;

  protected:
    explicit Window (const glib::ConstructParams& construct_params);
    explicit Window (GtkWindow* castitem);

#endif

  public:
    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GtkWindow*
    {
      return reinterpret_cast<GtkWindow*> (gobject_);
    }

    auto
    gobj () const -> const GtkWindow*
    {
      return reinterpret_cast<GtkWindow*> (gobject_);
    }

  private:
  public:
    using Root::get_display;

    Window (Window&& src) noexcept;
    auto
    operator= (Window&& src) noexcept -> Window&;

    explicit Window ();

    auto
    property_title () -> glib::PropertyProxy<glib::ustring>;

    auto
    property_title () const -> glib::PropertyProxy_ReadOnly<glib::ustring>;

    auto
    property_startup_id () -> glib::PropertyProxy_WriteOnly<glib::ustring>;

    auto
    property_resizable () -> glib::PropertyProxy<bool>;

    auto
    property_resizable () const -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_modal () -> glib::PropertyProxy<bool>;

    auto
    property_modal () const -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_default_width () -> glib::PropertyProxy<int>;

    auto
    property_default_width () const -> glib::PropertyProxy_ReadOnly<int>;

    auto
    property_default_height () -> glib::PropertyProxy<int>;

    auto
    property_default_height () const -> glib::PropertyProxy_ReadOnly<int>;

    auto
    property_destroy_with_parent () -> glib::PropertyProxy<bool>;

    auto
    property_destroy_with_parent () const -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_hide_on_close () -> glib::PropertyProxy<bool>;

    auto
    property_hide_on_close () const -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_mnemonics_visible () -> glib::PropertyProxy<bool>;

    auto
    property_mnemonics_visible () const -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_icon_name () -> glib::PropertyProxy<glib::ustring>;

    auto
    property_icon_name () const -> glib::PropertyProxy_ReadOnly<glib::ustring>;

    auto
    property_display () -> glib::PropertyProxy<glib::RefPtr<gdk::Display>>;

    auto
    property_display () const
        -> glib::PropertyProxy_ReadOnly<glib::RefPtr<gdk::Display>>;

    auto
    property_is_active () const -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_decorated () -> glib::PropertyProxy<bool>;

    auto
    property_decorated () const -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_transient_for () -> glib::PropertyProxy<Window*>;

    auto
    property_transient_for () const -> glib::PropertyProxy_ReadOnly<Window*>;

    auto
    property_deletable () -> glib::PropertyProxy<bool>;

    auto
    property_deletable () const -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_application () -> glib::PropertyProxy<glib::RefPtr<Application>>;

    auto
    property_application () const
        -> glib::PropertyProxy_ReadOnly<glib::RefPtr<Application>>;

    auto
    property_focus_visible () -> glib::PropertyProxy<bool>;

    auto
    property_focus_visible () const -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_maximized () -> glib::PropertyProxy<bool>;

    auto
    property_maximized () const -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_fullscreened () -> glib::PropertyProxy<bool>;

    auto
    property_fullscreened () const -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_default_widget () -> glib::PropertyProxy<Widget*>;

    auto
    property_default_widget () const -> glib::PropertyProxy_ReadOnly<Widget*>;

    auto
    property_focus_widget () -> glib::PropertyProxy<Widget*>;

    auto
    property_focus_widget () const -> glib::PropertyProxy_ReadOnly<Widget*>;

    auto
    property_child () -> glib::PropertyProxy<Widget*>;

    auto
    property_child () const -> glib::PropertyProxy_ReadOnly<Widget*>;

    auto
    property_titlebar () -> glib::PropertyProxy<Widget*>;

    auto
    property_titlebar () const -> glib::PropertyProxy_ReadOnly<Widget*>;

    auto
    property_handle_menubar_accel () -> glib::PropertyProxy<bool>;

    auto
    property_handle_menubar_accel () const
        -> glib::PropertyProxy_ReadOnly<bool>;

#ifndef GTKMM_DISABLE_DEPRECATED

    auto
    signal_keys_changed () -> glib::SignalProxy<void ()>;
#endif

    auto
    signal_close_request () -> glib::SignalProxy<bool ()>;

    auto
    set_title (const glib::ustring& title) -> void;

    auto
    get_title () const -> glib::ustring;

    auto
    set_startup_id (const glib::ustring& startup_id) -> void;

    auto
    set_focus (gtk::Widget& focus) -> void;
    auto
    unset_focus () -> void;

    auto
    get_focus () -> Widget*;

    auto
    get_focus () const -> const Widget*;

    auto
    set_default_widget (gtk::Widget& default_widget) -> void;
    auto
    unset_default_widget () -> void;

    auto
    get_default_widget () -> Widget*;

    auto
    get_default_widget () const -> const Widget*;

    auto
    set_transient_for (Window& parent) -> void;

    auto
    unset_transient_for () -> void;

    auto
    get_transient_for () -> Window*;

    auto
    get_transient_for () const -> const Window*;

    auto
    set_destroy_with_parent (bool setting = true) -> void;

    auto
    get_destroy_with_parent () const -> bool;

    auto
    destroy () -> void;

    auto
    set_hide_on_close (bool setting = true) -> void;

    auto
    get_hide_on_close () const -> bool;

    auto
    set_mnemonics_visible (bool setting = true) -> void;

    auto
    get_mnemonics_visible () const -> bool;

    auto
    set_focus_visible (bool setting = true) -> void;

    auto
    get_focus_visible () const -> bool;

    auto
    set_resizable (bool resizable = true) -> void;

    auto
    get_resizable () const -> bool;

    auto
    set_display (const glib::RefPtr<gdk::Display>& display) -> void;

    auto
    is_active () const -> bool;

    auto
    set_decorated (bool setting = true) -> void;

    auto
    get_decorated () const -> bool;

    auto
    set_deletable (bool setting = true) -> void;

    auto
    get_deletable () const -> bool;

    auto
    set_icon_name (const glib::ustring& name) -> void;

    auto
    get_icon_name () const -> glib::ustring;

    static auto
    set_default_icon_name (const glib::ustring& name) -> void;

    static auto
    get_default_icon_name () -> glib::ustring;

    static auto
    set_auto_startup_notification (bool setting = true) -> void;

    auto
    set_modal (bool modal = true) -> void;

    auto
    get_modal () const -> bool;

    static auto
    get_toplevels () -> glib::RefPtr<gio::ListModel>;

    static auto
    list_toplevels () -> std::vector<Window*>;

    auto
    present () -> void;

    auto
    present (guint32 timestamp) -> void;

    auto
    minimize () -> void;

    auto
    unminimize () -> void;

    auto
    maximize () -> void;

    auto
    unmaximize () -> void;

    auto
    fullscreen () -> void;

    auto
    unfullscreen () -> void;

    auto
    fullscreen_on_monitor (const glib::RefPtr<gdk::Monitor>& monitor) -> void;

    auto
    close () -> void;

    auto
    set_default_size (int width, int height) -> void;

    auto
    get_default_size (int& width, int& height) const -> void;

    auto
    get_group () -> glib::RefPtr<WindowGroup>;

    auto
    get_group () const -> glib::RefPtr<const WindowGroup>;

    auto
    has_group () const -> bool;

    auto
    get_application () -> glib::RefPtr<Application>;

    auto
    get_application () const -> glib::RefPtr<const Application>;

    auto
    set_application (const glib::RefPtr<Application>& application) -> void;

    auto
    unset_application () -> void;

    auto
    set_child (Widget& child) -> void;
    auto
    unset_child () -> void;

    auto
    get_child () -> Widget*;

    auto
    get_child () const -> const Widget*;

    auto
    set_titlebar (Widget& titlebar) -> void;

    auto
    unset_titlebar () -> void;

    auto
    get_titlebar () -> Widget*;

    auto
    get_titlebar () const -> const Widget*;

    auto
    is_maximized () const -> bool;

    auto
    is_fullscreen () const -> bool;

    auto
    set_handle_menubar_accel (bool handle_menubar_accel) -> void;

    auto
    get_handle_menubar_accel () const -> bool;

    auto
    set_manage () -> void override;

  protected:
    auto
    on_window_hide () -> void;

    auto
    destroy_ () -> void;
    auto
    _release_c_instance () -> void;

  public:
  public:
  protected:
    virtual auto
    on_keys_changed () -> void;

    virtual auto
    on_close_request () -> bool;
  };

} // namespace gtk

namespace glib
{
  LIBMM_GTK_SYMEXPORT auto
  wrap (GtkWindow* object, bool take_copy = false) -> gtk::Window*;
} // namespace glib

#endif
