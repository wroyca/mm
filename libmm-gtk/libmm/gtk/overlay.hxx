// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_OVERLAY_H
#define _GTKMM_OVERLAY_H

#include <libmm/glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm/gtk/widget.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkOverlay = struct _GtkOverlay;
using GtkOverlayClass = struct _GtkOverlayClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{
  class LIBMM_GTK_SYMEXPORT Overlay_Class;
}
#endif

namespace Gtk
{

  class LIBMM_GTK_SYMEXPORT Overlay : public Widget
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    typedef Overlay CppObjectType;
    typedef Overlay_Class CppClassType;
    typedef GtkOverlay BaseObjectType;
    typedef GtkOverlayClass BaseClassType;
#endif

    Overlay (Overlay&& src) noexcept;
    auto
    operator= (Overlay&& src) noexcept -> Overlay&;

    Overlay (const Overlay&) = delete;
    auto
    operator= (const Overlay&) -> Overlay& = delete;

    ~Overlay () noexcept override;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

  private:
    friend LIBMM_GTK_SYMEXPORT class Overlay_Class;
    static CppClassType overlay_class_;

  protected:
    explicit Overlay (const Glib::ConstructParams& construct_params);
    explicit Overlay (GtkOverlay* castitem);

#endif

  public:
    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GtkOverlay*
    {
      return reinterpret_cast<GtkOverlay*> (gobject_);
    }

    auto
    gobj () const -> const GtkOverlay*
    {
      return reinterpret_cast<GtkOverlay*> (gobject_);
    }

  private:
  public:
    Overlay ();

    auto
    add_overlay (Gtk::Widget& widget) -> void;

    auto
    remove_overlay (Gtk::Widget& widget) -> void;

    auto
    set_child (Widget& child) -> void;
    auto
    unset_child () -> void;

    auto
    get_child () -> Widget*;

    auto
    get_child () const -> const Widget*;

    auto
    get_measure_overlay (Widget& widget) const -> bool;

    auto
    set_measure_overlay (Widget& widget, bool measure = true) -> void;

    auto
    get_clip_overlay (const Widget& widget) const -> bool;

    auto
    set_clip_overlay (const Widget& widget, bool clip_overlay = true) -> void;

    auto
    signal_get_child_position ()
        -> Glib::SignalProxy<bool (Gtk::Widget*, Gdk::Rectangle&)>;

    auto
    property_child () -> Glib::PropertyProxy<Widget*>;

    auto
    property_child () const -> Glib::PropertyProxy_ReadOnly<Widget*>;

  public:
  public:
  protected:
  };

} // namespace Gtk

namespace Glib
{
  LIBMM_GTK_SYMEXPORT auto
  wrap (GtkOverlay* object, bool take_copy = false) -> Gtk::Overlay*;
} // namespace Glib

#endif
