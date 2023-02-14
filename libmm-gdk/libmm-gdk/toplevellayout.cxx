// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm-glib/mm-glib.hxx>

#include <libmm-gdk/toplevellayout.hxx>
#include <libmm-gdk/toplevellayout_p.hxx>

#include <gdk/gdk.h>

namespace
{
}

namespace Glib
{

  auto
  wrap (GdkToplevelLayout* object, const bool take_copy) -> RefPtr<Gdk::ToplevelLayout>
  {
    if (take_copy && object)
      gdk_toplevel_layout_ref (object);

    return Glib::make_refptr_for_instance<Gdk::ToplevelLayout> (
        reinterpret_cast<Gdk::ToplevelLayout*> (object));
  }

} // namespace Glib

namespace Gdk
{

  auto
  ToplevelLayout::reference () const -> void
  {
    gdk_toplevel_layout_ref (reinterpret_cast<GdkToplevelLayout*> (
        const_cast<ToplevelLayout*> (this)));
  }

  auto
  ToplevelLayout::unreference () const -> void
  {
    gdk_toplevel_layout_unref (reinterpret_cast<GdkToplevelLayout*> (
        const_cast<ToplevelLayout*> (this)));
  }

  auto
  ToplevelLayout::gobj () -> GdkToplevelLayout*
  {
    return reinterpret_cast<GdkToplevelLayout*> (this);
  }

  auto
  ToplevelLayout::gobj () const -> const GdkToplevelLayout*
  {
    return reinterpret_cast<const GdkToplevelLayout*> (this);
  }

  auto
  ToplevelLayout::gobj_copy () const -> GdkToplevelLayout*
  {
    const auto gobject = reinterpret_cast<GdkToplevelLayout*> (
        const_cast<ToplevelLayout*> (this));
    gdk_toplevel_layout_ref (gobject);
    return gobject;
  }

  auto
  ToplevelLayout::create () -> Glib::RefPtr<ToplevelLayout>
  {
    return Glib::wrap (gdk_toplevel_layout_new ());
  }

  auto
  ToplevelLayout::copy () const -> Glib::RefPtr<ToplevelLayout>
  {
    return Glib::wrap (
        gdk_toplevel_layout_copy (const_cast<GdkToplevelLayout*> (gobj ())));
  }

  auto
  ToplevelLayout::equal (const Glib::RefPtr<const ToplevelLayout>& other) const -> bool
  {
    return gdk_toplevel_layout_equal (
        const_cast<GdkToplevelLayout*> (gobj ()),
        const_cast<GdkToplevelLayout*> (Glib::unwrap (other)));
  }

  auto
  ToplevelLayout::set_maximized (const bool maximized) -> void
  {
    gdk_toplevel_layout_set_maximized (gobj (), maximized);
  }

  auto
  ToplevelLayout::set_fullscreen (const bool fullscreen,
                                  const Glib::RefPtr<Monitor>& monitor) -> void
  {
    gdk_toplevel_layout_set_fullscreen (gobj (),
                                        fullscreen,
                                        Glib::unwrap (monitor));
  }

  auto
  ToplevelLayout::get_maximized (bool& maximized) const -> bool
  {
    return gdk_toplevel_layout_get_maximized (
        const_cast<GdkToplevelLayout*> (gobj ()),
        (gboolean*) &maximized);
  }

  auto
  ToplevelLayout::get_fullscreen (bool& fullscreen) const -> bool
  {
    return gdk_toplevel_layout_get_fullscreen (
        const_cast<GdkToplevelLayout*> (gobj ()),
        (gboolean*) &fullscreen);
  }

  auto
  ToplevelLayout::get_fullscreen_monitor () -> Glib::RefPtr<Monitor>
  {
    auto retvalue =
        Glib::wrap (gdk_toplevel_layout_get_fullscreen_monitor (gobj ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  ToplevelLayout::get_fullscreen_monitor () const -> Glib::RefPtr<const Monitor>
  {
    return const_cast<ToplevelLayout*> (this)->get_fullscreen_monitor ();
  }

  auto
  ToplevelLayout::set_resizable (const bool resizable) -> void
  {
    gdk_toplevel_layout_set_resizable (gobj (), resizable);
  }

  auto
  ToplevelLayout::get_resizable () const -> bool
  {
    return gdk_toplevel_layout_get_resizable (
        const_cast<GdkToplevelLayout*> (gobj ()));
  }

} // namespace Gdk
