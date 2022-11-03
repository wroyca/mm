/* Copyright 2002      The gtkmm Development Team
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
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 */

#include <mm/gdk/cairoutils.hpp>
#include <mm/gdk/general.hpp>
#include <gdk/gdk.h>


namespace Gdk::Cairo
{

auto set_source_rgba (
  const ::Cairo::RefPtr <::Cairo::Context> &context, const RGBA &color) -> void
{
  gdk_cairo_set_source_rgba(context->cobj(), color.gobj());
}

auto set_source_pixbuf (
  const ::Cairo::RefPtr <::Cairo::Context> &context, const Glib::RefPtr <const Pixbuf> &pixbuf, const double pixbuf_x, const double pixbuf_y) -> void
{
  gdk_cairo_set_source_pixbuf(context->cobj(), pixbuf->gobj(), pixbuf_x, pixbuf_y);
}


auto add_rectangle_to_path (
  const ::Cairo::RefPtr <::Cairo::Context> &context, const Rectangle &rectangle) -> void
{
  gdk_cairo_rectangle(context->cobj(), rectangle.gobj());
}

auto add_region_to_path (
  const ::Cairo::RefPtr <::Cairo::Context> &context,
  const ::Cairo::RefPtr <::Cairo::Region> &region) -> void
{
  gdk_cairo_region(context->cobj(), region ? region->cobj() : nullptr);
}

auto create_region_from_surface(const ::Cairo::RefPtr< ::Cairo::Surface>& surface) -> ::Cairo::RefPtr< ::Cairo::Region>
{
  return wrap(gdk_cairo_region_create_from_surface(surface->cobj()), true);
}

#ifndef GDKMM_DISABLE_DEPRECATED
G_GNUC_BEGIN_IGNORE_DEPRECATIONS
auto draw_from_gl (
  const ::Cairo::RefPtr <::Cairo::Context> &context,
  const Glib::RefPtr <Surface> &surface, const int source, const int source_type, const int buffer_scale, const int x, const int y, const int width, const int height) -> void
{
  gdk_cairo_draw_from_gl(context->cobj(), surface->gobj(), source, source_type,
    buffer_scale, x, y, width, height);
}
G_GNUC_END_IGNORE_DEPRECATIONS
#endif // GDKMM_DISABLE_DEPRECATED

} //namespace Gdk
