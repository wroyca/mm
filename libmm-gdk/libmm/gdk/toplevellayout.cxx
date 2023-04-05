// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/gdk/toplevellayout.hxx>
#include <libmm/gdk/toplevellayout_p.hxx>

#include <gdk/gdk.h>

namespace
{
}

namespace glib
{

  auto
  wrap (GdkToplevelLayout* object, bool take_copy) -> glib::RefPtr<gdk::ToplevelLayout>
  {
    if (take_copy && object)
      gdk_toplevel_layout_ref (object);

    return glib::make_refptr_for_instance<gdk::ToplevelLayout> (
        reinterpret_cast<gdk::ToplevelLayout*> (object));
  }

} // namespace glib

namespace gdk
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
  ToplevelLayout::create () -> glib::RefPtr<ToplevelLayout>
  {
    return glib::wrap (gdk_toplevel_layout_new ());
  }

  auto
  ToplevelLayout::copy () const -> glib::RefPtr<ToplevelLayout>
  {
    return glib::wrap (
        gdk_toplevel_layout_copy (const_cast<GdkToplevelLayout*> (gobj ())));
  }

  auto
  ToplevelLayout::equal (const glib::RefPtr<const ToplevelLayout>& other) const -> bool
  {
    return gdk_toplevel_layout_equal (
        const_cast<GdkToplevelLayout*> (gobj ()),
        const_cast<GdkToplevelLayout*> (glib::unwrap (other)));
  }

  auto
  ToplevelLayout::set_maximized (bool maximized) -> void
  {
    gdk_toplevel_layout_set_maximized (gobj (), static_cast<int> (maximized));
  }

  auto
  ToplevelLayout::set_fullscreen (bool fullscreen,
                                  const glib::RefPtr<Monitor>& monitor) -> void
  {
    gdk_toplevel_layout_set_fullscreen (gobj (),
                                        static_cast<int> (fullscreen),
                                        glib::unwrap (monitor));
  }

  auto
  ToplevelLayout::get_maximized (bool& maximized) const -> bool
  {
    return gdk_toplevel_layout_get_maximized (
        const_cast<GdkToplevelLayout*> (gobj ()),
        ((gboolean*) &(maximized)));
  }

  auto
  ToplevelLayout::get_fullscreen (bool& fullscreen) const -> bool
  {
    return gdk_toplevel_layout_get_fullscreen (
        const_cast<GdkToplevelLayout*> (gobj ()),
        ((gboolean*) &(fullscreen)));
  }

  auto
  ToplevelLayout::get_fullscreen_monitor () -> glib::RefPtr<Monitor>
  {
    auto retvalue =
        glib::wrap (gdk_toplevel_layout_get_fullscreen_monitor (gobj ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  ToplevelLayout::get_fullscreen_monitor () const -> glib::RefPtr<const Monitor>
  {
    return const_cast<ToplevelLayout*> (this)->get_fullscreen_monitor ();
  }

  auto
  ToplevelLayout::set_resizable (bool resizable) -> void
  {
    gdk_toplevel_layout_set_resizable (gobj (), static_cast<int> (resizable));
  }

  auto
  ToplevelLayout::get_resizable () const -> bool
  {
    return gdk_toplevel_layout_get_resizable (
        const_cast<GdkToplevelLayout*> (gobj ()));
  }

} // namespace gdk
