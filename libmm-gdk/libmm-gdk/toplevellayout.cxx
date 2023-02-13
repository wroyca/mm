


#include <libmm-glib/mm-glib.hxx>

#include <libmm-gdk/toplevellayout.hxx>
#include <libmm-gdk/toplevellayout_p.hxx>

#include <gdk/gdk.h>

/* Copyright (C) 2020 The gtkmm Development Team
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library. If not, see <http://www.gnu.org/licenses/>.
 */


namespace
{
} // anonymous namespace


/* Why reinterpret_cast<ToplevelLayout*>(gobject) is needed:
 *
 * A ToplevelLayout instance is in fact always a GdkToplevelLayout instance.
 * Unfortunately, GdkToplevelLayout cannot be a member of ToplevelLayout,
 * because it is an opaque struct.  Also, the C interface does not provide
 * any hooks to install a destroy notification handler, thus we cannot
 * wrap it dynamically either.
 *
 * The cast works because ToplevelLayout does not have any member data, and
 * it is impossible to derive from it.  This is ensured by using final on the
 * class and by using = delete on the default constructor.
 */

namespace Glib
{

auto wrap(GdkToplevelLayout* object, const bool take_copy) -> RefPtr<Gdk::ToplevelLayout>
{
  if(take_copy && object)
    gdk_toplevel_layout_ref(object);

  // See the comment at the top of this file, if you want to know why the cast works.
  return Glib::make_refptr_for_instance<Gdk::ToplevelLayout>(reinterpret_cast<Gdk::ToplevelLayout*>(object));
}

} // namespace Glib


namespace Gdk
{

auto ToplevelLayout::reference () const -> void
{
  // See the comment at the top of this file, if you want to know why the cast works.
  gdk_toplevel_layout_ref(reinterpret_cast<GdkToplevelLayout*>(const_cast<ToplevelLayout*>(this)));
}

auto ToplevelLayout::unreference () const -> void
{
  // See the comment at the top of this file, if you want to know why the cast works.
  gdk_toplevel_layout_unref(reinterpret_cast<GdkToplevelLayout*>(const_cast<ToplevelLayout*>(this)));
}

auto ToplevelLayout::gobj() -> GdkToplevelLayout*
{
  // See the comment at the top of this file, if you want to know why the cast works.
  return reinterpret_cast<GdkToplevelLayout*>(this);
}

auto ToplevelLayout::gobj() const -> const GdkToplevelLayout*
{
  // See the comment at the top of this file, if you want to know why the cast works.
  return reinterpret_cast<const GdkToplevelLayout*>(this);
}

auto ToplevelLayout::gobj_copy() const -> GdkToplevelLayout*
{
  // See the comment at the top of this file, if you want to know why the cast works.
  const auto gobject = reinterpret_cast<GdkToplevelLayout*>(const_cast<ToplevelLayout*>(this));
  gdk_toplevel_layout_ref(gobject);
  return gobject;
}


auto ToplevelLayout::create() -> Glib::RefPtr<ToplevelLayout>
{
  return Glib::wrap(gdk_toplevel_layout_new());
}

auto ToplevelLayout::copy() const -> Glib::RefPtr<ToplevelLayout>
{
  return Glib::wrap(gdk_toplevel_layout_copy(const_cast<GdkToplevelLayout*>(gobj())));
}

auto ToplevelLayout::equal(const Glib::RefPtr<const ToplevelLayout>& other) const -> bool
{
  return gdk_toplevel_layout_equal(const_cast<GdkToplevelLayout*>(gobj()), const_cast<GdkToplevelLayout*>(Glib::unwrap(other)));
}

auto ToplevelLayout::set_maximized (
  const bool maximized) -> void
{
  gdk_toplevel_layout_set_maximized(gobj(), maximized);
}

auto ToplevelLayout::set_fullscreen (
  const bool fullscreen, const Glib::RefPtr <Monitor> &monitor) -> void
{
  gdk_toplevel_layout_set_fullscreen(gobj(), fullscreen, Glib::unwrap(monitor));
}

auto ToplevelLayout::get_maximized(bool& maximized) const -> bool
{
  return gdk_toplevel_layout_get_maximized(const_cast<GdkToplevelLayout*>(gobj()), (gboolean*) &maximized);
}

auto ToplevelLayout::get_fullscreen(bool& fullscreen) const -> bool
{
  return gdk_toplevel_layout_get_fullscreen(const_cast<GdkToplevelLayout*>(gobj()), (gboolean*) &fullscreen);
}

auto ToplevelLayout::get_fullscreen_monitor() -> Glib::RefPtr<Monitor>
{
  auto retvalue = Glib::wrap(gdk_toplevel_layout_get_fullscreen_monitor(gobj()));
  if(retvalue)
    retvalue->reference(); //The function does not do a ref for us.
  return retvalue;
}

auto ToplevelLayout::get_fullscreen_monitor() const -> Glib::RefPtr<const Monitor>
{
  return const_cast<ToplevelLayout*>(this)->get_fullscreen_monitor();
}

auto ToplevelLayout::set_resizable (
  const bool resizable) -> void
{
  gdk_toplevel_layout_set_resizable(gobj(), resizable);
}

auto ToplevelLayout::get_resizable() const -> bool
{
  return gdk_toplevel_layout_get_resizable(const_cast<GdkToplevelLayout*>(gobj()));
}


} // namespace Gdk


