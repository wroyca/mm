// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_SHORTCUTSWINDOW_H
#define _GTKMM_SHORTCUTSWINDOW_H

#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm-gtk/window.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkShortcutsWindow = struct _GtkShortcutsWindow;
using GtkShortcutsWindowClass = struct _GtkShortcutsWindowClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{
  class LIBMM_GTK_SYMEXPORT ShortcutsWindow_Class;
}
#endif

namespace Gtk
{

  class LIBMM_GTK_SYMEXPORT ShortcutsWindow : public Window
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    typedef ShortcutsWindow CppObjectType;
    typedef ShortcutsWindow_Class CppClassType;
    typedef GtkShortcutsWindow BaseObjectType;
    typedef GtkShortcutsWindowClass BaseClassType;
#endif

    ShortcutsWindow (ShortcutsWindow&& src) noexcept;
    auto
    operator= (ShortcutsWindow&& src) noexcept -> ShortcutsWindow&;

    ShortcutsWindow (const ShortcutsWindow&) = delete;
    auto
    operator= (const ShortcutsWindow&) -> ShortcutsWindow& = delete;

    ~ShortcutsWindow () noexcept override;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

  private:
    friend LIBMM_GTK_SYMEXPORT class ShortcutsWindow_Class;
    static CppClassType shortcutswindow_class_;

  protected:
    explicit ShortcutsWindow (const Glib::ConstructParams& construct_params);
    explicit ShortcutsWindow (GtkShortcutsWindow* castitem);

#endif

  public:
    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GtkShortcutsWindow*
    {
      return reinterpret_cast<GtkShortcutsWindow*> (gobject_);
    }

    auto
    gobj () const -> const GtkShortcutsWindow*
    {
      return reinterpret_cast<GtkShortcutsWindow*> (gobject_);
    }

  private:
  public:
    ShortcutsWindow ();

    auto
    unset_view_name () -> void;

    auto
    property_section_name () -> Glib::PropertyProxy<Glib::ustring>;

    auto
    property_section_name () const
        -> Glib::PropertyProxy_ReadOnly<Glib::ustring>;

    auto
    property_view_name () -> Glib::PropertyProxy<Glib::ustring>;

    auto
    property_view_name () const -> Glib::PropertyProxy_ReadOnly<Glib::ustring>;

  public:
  public:
  protected:
  };

} // namespace Gtk

namespace Glib
{
  LIBMM_GTK_SYMEXPORT auto
  wrap (GtkShortcutsWindow* object, bool take_copy = false) -> Gtk::ShortcutsWindow*;
} // namespace Glib

#endif
