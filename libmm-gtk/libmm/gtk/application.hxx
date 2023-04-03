// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_APPLICATION_H
#define _GTKMM_APPLICATION_H

#include <libmm/gtk/mm-gtkconfig.hxx>

#include <libmm/glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm/gio/application.hxx>
#include <libmm/gio/menu.hxx>
#include <libmm/gio/menumodel.hxx>
#include <libmm/gtk/window.hxx>
#include <type_traits>
#include <utility>
#include <vector>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkApplication = struct _GtkApplication;
using GtkApplicationClass = struct _GtkApplicationClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{
  class LIBMM_GTK_SYMEXPORT Application_Class;
}
#endif

namespace Gtk
{

  class LIBMM_GTK_SYMEXPORT Application : public Gio::Application
  {
  protected:
#ifndef DOXYGEN_SHOULD_SKIP_THIS

  public:
    using CppObjectType = Application;
    using CppClassType = Application_Class;
    using BaseObjectType = GtkApplication;
    using BaseClassType = GtkApplicationClass;

    Application (const Application&) = delete;
    auto
    operator= (const Application&) -> Application& = delete;

  private:
    friend class Application_Class;
    static CppClassType application_class_;

  protected:
    explicit Application (const Glib::ConstructParams& construct_params);
    explicit Application (GtkApplication* castitem);

#endif

  public:
    Application (Application&& src) noexcept;
    auto
    operator= (Application&& src) noexcept -> Application&;

    ~Application () noexcept override;

    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GtkApplication*
    {
      return reinterpret_cast<GtkApplication*> (gobject_);
    }

    auto
    gobj () const -> const GtkApplication*
    {
      return reinterpret_cast<GtkApplication*> (gobject_);
    }

    auto
    gobj_copy () -> GtkApplication*;

  private:
  protected:
    explicit Application (
        const Glib::ustring& application_id = {},
        Gio::Application::Flags flags = Gio::Application::Flags::NONE);

  public:
    enum class InhibitFlags
    {
      LOGOUT = (1 << 0),
      SWITCH = (1 << 1),
      SUSPEND = (1 << 2),
      IDLE = (1 << 3)
    };

    static auto
    create (const Glib::ustring& application_id = {},
            Gio::Application::Flags flags = Gio::Application::Flags::NONE)
        -> Glib::RefPtr<Application>;

    auto
    get_windows () -> std::vector<Window*>;

    auto
    get_windows () const -> std::vector<const Window*>;

    auto
    add_window (Window& window) -> void;

    auto
    remove_window (Window& window) -> void;

    auto
    run (int argc, char** argv) -> int;

    auto
    run () -> int;

    template <typename T_Window, typename... T_Args>
    auto
    make_window_and_run (int argc, char** argv, T_Args&&... args) -> int;

    auto
    get_run_window () -> Window*
    {
      return m_run_window;
    }

    auto
    get_run_window () const -> const Window*
    {
      return m_run_window;
    }

    auto
    get_menubar () -> Glib::RefPtr<Gio::MenuModel>;

    auto
    get_menubar () const -> Glib::RefPtr<const Gio::MenuModel>;

    auto
    set_menubar (const Glib::RefPtr<Gio::MenuModel>& menubar) -> void;

    auto
    inhibit (Window& window, InhibitFlags flags, const Glib::ustring& reason)
        -> guint;

    auto
    uninhibit (guint cookie) -> void;

    auto
    get_window_by_id (guint id) -> Window*;

    auto
    get_window_by_id (guint id) const -> const Window*;

    auto
    get_active_window () -> Window*;

    auto
    get_active_window () const -> const Window*;

    auto
    list_action_descriptions () const -> std::vector<Glib::ustring>;

    auto
    get_accels_for_action (const Glib::ustring& detailed_action_name) const
        -> std::vector<Glib::ustring>;

    auto
    get_actions_for_accel (const Glib::ustring& accel) const
        -> std::vector<Glib::ustring>;

    auto
    set_accels_for_action (const Glib::ustring& detailed_action_name,
                           const std::vector<Glib::ustring>& accels) -> void;

    auto
    set_accel_for_action (const Glib::ustring& detailed_action_name,
                          const Glib::ustring& accel) -> void;

    auto
    unset_accels_for_action (const Glib::ustring& detailed_action_name) -> void;

    auto
    get_menu_by_id (const Glib::ustring& id) -> Glib::RefPtr<Gio::Menu>;

    auto
    get_menu_by_id (const Glib::ustring& id) const
        -> Glib::RefPtr<const Gio::Menu>;

    auto
    property_menubar () -> Glib::PropertyProxy<Glib::RefPtr<Gio::MenuModel>>;

    auto
    property_menubar () const
        -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<Gio::MenuModel>>;

    auto
    property_register_session () -> Glib::PropertyProxy<bool>;

    auto
    property_register_session () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_screensaver_active () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_active_window () const -> Glib::PropertyProxy_ReadOnly<Window*>;

    auto
    signal_window_added () -> Glib::SignalProxy<void (Window*)>;

    auto
    signal_window_removed () -> Glib::SignalProxy<void (Window*)>;

    auto
    signal_query_end () -> Glib::SignalProxy<void ()>;

  private:
    auto
    custom_class_init () -> const Glib::Class&;

    Window* m_run_window = nullptr;

  public:
  public:
  protected:
    virtual auto
    on_window_added (Window* window) -> void;

    virtual auto
    on_window_removed (Window* window) -> void;
  };

  template <typename T_Window, typename... T_Args>
  auto
  Application::make_window_and_run (int argc, char** argv, T_Args&&... args) -> int
  {
    static_assert (std::is_base_of<Window, T_Window>::value);

    signal_activate ().connect (
        [this, &args...] ()
        {
          if (!m_run_window)
          {
            auto window =
                make_managed<T_Window> (std::forward<T_Args> (args)...);
            m_run_window = window;
            add_window (*window);
            window->present ();
          }
          else
          {
            m_run_window->present ();
          }
        });

    signal_window_removed ().connect (
        [this] (Window* window)
        {
          if (window == m_run_window)
          {
            if (window)
              window->destroy ();
            m_run_window = nullptr;
          }
        });

    return Gio::Application::run (argc, argv);
  }

} // namespace Gtk

namespace Gtk
{

  inline auto
  operator| (Application::InhibitFlags lhs, Application::InhibitFlags rhs) -> Application::InhibitFlags
  {
    return static_cast<Application::InhibitFlags> (static_cast<unsigned> (lhs) |
                                                   static_cast<unsigned> (rhs));
  }

  inline auto
  operator& (Application::InhibitFlags lhs, Application::InhibitFlags rhs) -> Application::InhibitFlags
  {
    return static_cast<Application::InhibitFlags> (static_cast<unsigned> (lhs) &
                                                   static_cast<unsigned> (rhs));
  }

  inline auto
  operator^ (Application::InhibitFlags lhs, Application::InhibitFlags rhs) -> Application::InhibitFlags
  {
    return static_cast<Application::InhibitFlags> (static_cast<unsigned> (lhs) ^
                                                   static_cast<unsigned> (rhs));
  }

  inline auto
  operator~(Application::InhibitFlags flags) -> Application::InhibitFlags
  {
    return static_cast<Application::InhibitFlags> (
        ~static_cast<unsigned> (flags));
  }

  inline auto
  operator|= (Application::InhibitFlags& lhs, Application::InhibitFlags rhs) -> Application::InhibitFlags&
  {
    return (lhs = static_cast<Application::InhibitFlags> (
                static_cast<unsigned> (lhs) | static_cast<unsigned> (rhs)));
  }

  inline auto
  operator&= (Application::InhibitFlags& lhs, Application::InhibitFlags rhs) -> Application::InhibitFlags&
  {
    return (lhs = static_cast<Application::InhibitFlags> (
                static_cast<unsigned> (lhs) & static_cast<unsigned> (rhs)));
  }

  inline auto
  operator^= (Application::InhibitFlags& lhs, Application::InhibitFlags rhs) -> Application::InhibitFlags&
  {
    return (lhs = static_cast<Application::InhibitFlags> (
                static_cast<unsigned> (lhs) ^ static_cast<unsigned> (rhs)));
  }
} // namespace Gtk

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

  template <>
  class LIBMM_GTK_SYMEXPORT Value<Gtk::Application::InhibitFlags>
    : public Glib::Value_Flags<Gtk::Application::InhibitFlags>
  {
  public:
    static auto
    value_type () -> GType G_GNUC_CONST;
  };

} // namespace Glib
#endif

namespace Glib
{
  LIBMM_GTK_SYMEXPORT auto
  wrap (GtkApplication* object, bool take_copy = false) -> Glib::RefPtr<Gtk::Application>;
} // namespace Glib

#endif
