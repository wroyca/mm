// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_APPLICATIONWINDOW_H
#define _GTKMM_APPLICATIONWINDOW_H

#include <libmm-gtk/mm-gtkconfig.hxx>

#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm-gio/actiongroup.hxx>
#include <libmm-gio/actionmap.hxx>
#include <libmm-gtk/application.hxx>
#include <libmm-gtk/window.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkApplicationWindow = struct _GtkApplicationWindow;
using GtkApplicationWindowClass = struct _GtkApplicationWindowClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{
  class GTKMM_API ApplicationWindow_Class;
}
#endif

namespace Gtk
{
  class GTKMM_API ShortcutsWindow;

  class GTKMM_API ApplicationWindow : public Gtk::Window,
                                      public Gio::ActionGroup,
                                      public Gio::ActionMap
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    typedef ApplicationWindow CppObjectType;
    typedef ApplicationWindow_Class CppClassType;
    typedef GtkApplicationWindow BaseObjectType;
    typedef GtkApplicationWindowClass BaseClassType;
#endif

    ApplicationWindow (ApplicationWindow&& src) noexcept;
    auto
    operator= (ApplicationWindow&& src) noexcept -> ApplicationWindow&;

    ApplicationWindow (const ApplicationWindow&) = delete;
    auto
    operator= (const ApplicationWindow&) -> ApplicationWindow& = delete;

    ~ApplicationWindow () noexcept override;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

  private:
    friend GTKMM_API class ApplicationWindow_Class;
    static CppClassType applicationwindow_class_;

  protected:
    explicit ApplicationWindow (const Glib::ConstructParams& construct_params);
    explicit ApplicationWindow (GtkApplicationWindow* castitem);

#endif

  public:
    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GtkApplicationWindow*
    {
      return reinterpret_cast<GtkApplicationWindow*> (gobject_);
    }

    auto
    gobj () const -> const GtkApplicationWindow*
    {
      return reinterpret_cast<GtkApplicationWindow*> (gobject_);
    }

  private:
  public:
    using Widget::activate_action;

    ApplicationWindow ();
    explicit ApplicationWindow (const Glib::RefPtr<Application>& application);

    void
    set_show_menubar (bool show_menubar = true);

    auto
    get_show_menubar () const -> bool;

    auto
    get_id () const -> guint;

    void
    set_help_overlay (ShortcutsWindow& help_overlay);

    void
    unset_help_overlay ();

    auto
    get_help_overlay () -> ShortcutsWindow*;

    auto
    get_help_overlay () const -> const ShortcutsWindow*;

    auto
    property_show_menubar () -> Glib::PropertyProxy<bool>;

    auto
    property_show_menubar () const -> Glib::PropertyProxy_ReadOnly<bool>;

  public:
  public:
  protected:
  };

} // namespace Gtk

namespace Glib
{

  GTKMM_API
  auto
  wrap (GtkApplicationWindow* object, bool take_copy = false) -> Gtk::ApplicationWindow*;
} // namespace Glib

#endif
