
#ifndef _GTKMM_WINDOW_H
#define _GTKMM_WINDOW_H

#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <vector>

#include <libmm-gdk/surface.hxx>
#include <libmm-gdk/texture.hxx>
#include <libmm-glib/object.hxx>
#include <libmm-gtk/native.hxx>
#include <libmm-gtk/root.hxx>
#include <libmm-gtk/shortcutmanager.hxx>
#include <libmm-gtk/widget.hxx>
#include <libmm-gtk/windowgroup.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkWindow = struct _GtkWindow;
using GtkWindowClass = struct _GtkWindowClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{
  class GTKMM_API Window_Class;
}
#endif

namespace Gio
{
  class GTKMM_API ListModel;
}

namespace Gtk
{

  class GTKMM_API Application;
  class GTKMM_API WindowGroup;

  class GTKMM_API Window : public Widget,
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
    friend GTKMM_API class Window_Class;
    static CppClassType window_class_;

  protected:
    explicit Window (const Glib::ConstructParams& construct_params);
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
    property_title () -> Glib::PropertyProxy<Glib::ustring>;

    auto
    property_title () const -> Glib::PropertyProxy_ReadOnly<Glib::ustring>;

    auto
    property_startup_id () -> Glib::PropertyProxy_WriteOnly<Glib::ustring>;

    auto
    property_resizable () -> Glib::PropertyProxy<bool>;

    auto
    property_resizable () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_modal () -> Glib::PropertyProxy<bool>;

    auto
    property_modal () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_default_width () -> Glib::PropertyProxy<int>;

    auto
    property_default_width () const -> Glib::PropertyProxy_ReadOnly<int>;

    auto
    property_default_height () -> Glib::PropertyProxy<int>;

    auto
    property_default_height () const -> Glib::PropertyProxy_ReadOnly<int>;

    auto
    property_destroy_with_parent () -> Glib::PropertyProxy<bool>;

    auto
    property_destroy_with_parent () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_hide_on_close () -> Glib::PropertyProxy<bool>;

    auto
    property_hide_on_close () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_mnemonics_visible () -> Glib::PropertyProxy<bool>;

    auto
    property_mnemonics_visible () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_icon_name () -> Glib::PropertyProxy<Glib::ustring>;

    auto
    property_icon_name () const -> Glib::PropertyProxy_ReadOnly<Glib::ustring>;

    auto
    property_display () -> Glib::PropertyProxy<Glib::RefPtr<Gdk::Display>>;

    auto
    property_display () const
        -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<Gdk::Display>>;

    auto
    property_is_active () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_decorated () -> Glib::PropertyProxy<bool>;

    auto
    property_decorated () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_transient_for () -> Glib::PropertyProxy<Window*>;

    auto
    property_transient_for () const -> Glib::PropertyProxy_ReadOnly<Window*>;

    auto
    property_deletable () -> Glib::PropertyProxy<bool>;

    auto
    property_deletable () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_application () -> Glib::PropertyProxy<Glib::RefPtr<Application>>;

    auto
    property_application () const
        -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<Application>>;

    auto
    property_focus_visible () -> Glib::PropertyProxy<bool>;

    auto
    property_focus_visible () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_maximized () -> Glib::PropertyProxy<bool>;

    auto
    property_maximized () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_fullscreened () -> Glib::PropertyProxy<bool>;

    auto
    property_fullscreened () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_default_widget () -> Glib::PropertyProxy<Widget*>;

    auto
    property_default_widget () const -> Glib::PropertyProxy_ReadOnly<Widget*>;

    auto
    property_focus_widget () -> Glib::PropertyProxy<Widget*>;

    auto
    property_focus_widget () const -> Glib::PropertyProxy_ReadOnly<Widget*>;

    auto
    property_child () -> Glib::PropertyProxy<Widget*>;

    auto
    property_child () const -> Glib::PropertyProxy_ReadOnly<Widget*>;

    auto
    property_titlebar () -> Glib::PropertyProxy<Widget*>;

    auto
    property_titlebar () const -> Glib::PropertyProxy_ReadOnly<Widget*>;

    auto
    property_handle_menubar_accel () -> Glib::PropertyProxy<bool>;

    auto
    property_handle_menubar_accel () const
        -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    signal_keys_changed () -> Glib::SignalProxy<void ()>;

    auto
    signal_close_request () -> Glib::SignalProxy<bool ()>;

    void
    set_title (const Glib::ustring& title);

    auto
    get_title () const -> Glib::ustring;

    void
    set_startup_id (const Glib::ustring& startup_id);

    void
    set_focus (Gtk::Widget& focus);
    void
    unset_focus ();

    auto
    get_focus () -> Widget*;

    auto
    get_focus () const -> const Widget*;

    void
    set_default_widget (Gtk::Widget& default_widget);
    void
    unset_default_widget ();

    auto
    get_default_widget () -> Widget*;

    auto
    get_default_widget () const -> const Widget*;

    void
    set_transient_for (Window& parent);

    void
    unset_transient_for ();

    auto
    get_transient_for () -> Window*;

    auto
    get_transient_for () const -> const Window*;

    void
    set_destroy_with_parent (bool setting = true);

    auto
    get_destroy_with_parent () const -> bool;

    void
    destroy ();

    void
    set_hide_on_close (bool setting = true);

    auto
    get_hide_on_close () const -> bool;

    void
    set_mnemonics_visible (bool setting = true);

    auto
    get_mnemonics_visible () const -> bool;

    void
    set_focus_visible (bool setting = true);

    auto
    get_focus_visible () const -> bool;

    void
    set_resizable (bool resizable = true);

    auto
    get_resizable () const -> bool;

    void
    set_display (const Glib::RefPtr<Gdk::Display>& display);

    auto
    is_active () const -> bool;

    void
    set_decorated (bool setting = true);

    auto
    get_decorated () const -> bool;

    void
    set_deletable (bool setting = true);

    auto
    get_deletable () const -> bool;

    void
    set_icon_name (const Glib::ustring& name);

    auto
    get_icon_name () const -> Glib::ustring;

    static void
    set_default_icon_name (const Glib::ustring& name);

    static auto
    get_default_icon_name () -> Glib::ustring;

    static void
    set_auto_startup_notification (bool setting = true);

    void
    set_modal (bool modal = true);

    auto
    get_modal () const -> bool;

    static auto
    get_toplevels () -> Glib::RefPtr<Gio::ListModel>;

    static auto
    list_toplevels () -> std::vector<Window*>;

    void
    present ();

    void
    present (guint32 timestamp);

    void
    minimize ();

    void
    unminimize ();

    void
    maximize ();

    void
    unmaximize ();

    void
    fullscreen ();

    void
    unfullscreen ();

    void
    fullscreen_on_monitor (const Glib::RefPtr<Gdk::Monitor>& monitor);

    void
    close ();

    void
    set_default_size (int width, int height);

    void
    get_default_size (int& width, int& height) const;

    auto
    get_group () -> Glib::RefPtr<WindowGroup>;

    auto
    get_group () const -> Glib::RefPtr<const WindowGroup>;

    auto
    has_group () const -> bool;

    auto
    get_application () -> Glib::RefPtr<Application>;

    auto
    get_application () const -> Glib::RefPtr<const Application>;

    void
    set_application (const Glib::RefPtr<Application>& application);

    void
    unset_application ();

    void
    set_child (Widget& child);
    void
    unset_child ();

    auto
    get_child () -> Widget*;

    auto
    get_child () const -> const Widget*;

    void
    set_titlebar (Widget& titlebar);

    void
    unset_titlebar ();

    auto
    get_titlebar () -> Widget*;

    auto
    get_titlebar () const -> const Widget*;

    auto
    is_maximized () const -> bool;

    auto
    is_fullscreen () const -> bool;

    void
    set_handle_menubar_accel (bool handle_menubar_accel);

    auto
    get_handle_menubar_accel () const -> bool;

    void
    set_manage () override;

  protected:
    void
    on_window_hide ();

    void
    destroy_ ();
    void
    _release_c_instance ();

  public:
  public:
  protected:
    virtual void
    on_keys_changed ();

    virtual auto
    on_close_request () -> bool;
  };

} // namespace Gtk

namespace Glib
{

  GTKMM_API
  auto
  wrap (GtkWindow* object, bool take_copy = false) -> Gtk::Window*;
} // namespace Glib

#endif
