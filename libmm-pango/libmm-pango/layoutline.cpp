


#include <libmm-glib/mm-glib.hpp>

#include <libmm-pango/layoutline.hpp>
#include <libmm-pango/layoutline_p.hpp>


// -*- c++ -*-
/* $Id: layoutline.ccg,v 1.3 2006/05/30 17:14:21 murrayc Exp $ */

/*
 *
 * Copyright 1998-2002 The gtkmm Development Team
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
 * License along with this library; if not, write to the Free
 * Software Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 */

#include <libmm-pango/layout.hpp>
#include <pango/pangocairo.h>

namespace Pango {

auto LayoutLine::get_ink_extents() const -> Rectangle
{
  Rectangle ink_rect;
  pango_layout_line_get_extents(const_cast<PangoLayoutLine*>(gobj()), ink_rect.gobj(), 0);
  return ink_rect;
}

auto LayoutLine::get_logical_extents() const -> Rectangle
{
  Rectangle logical_rect;
  pango_layout_line_get_extents(const_cast<PangoLayoutLine*>(gobj()), 0, logical_rect.gobj());
  return logical_rect;
}

auto LayoutLine::get_pixel_ink_extents() const -> Rectangle
{
  Rectangle ink_rect;
  pango_layout_line_get_pixel_extents(const_cast<PangoLayoutLine*>(gobj()), ink_rect.gobj(), 0);
  return ink_rect;
}

auto LayoutLine::get_pixel_logical_extents() const -> Rectangle
{
  Rectangle logical_rect;
  pango_layout_line_get_pixel_extents(const_cast<PangoLayoutLine*>(gobj()), 0, logical_rect.gobj());
  return logical_rect;
}

auto LayoutLine::index_to_x(
  const int index, const bool trailing) const -> int
{
  int x_pos;
  pango_layout_line_index_to_x(const_cast<PangoLayoutLine*>(gobj()), index, trailing, &x_pos);
  return x_pos;
}

auto LayoutLine::get_x_ranges(
  const int start_index, const int end_index) const -> std::vector<std::pair<int,int> >
{
  //TODO: This reinterpret_cast<> is scary. There should at least be a comment explaining it.
  int* ranges = nullptr;
  int n_ranges = 0;
  pango_layout_line_get_x_ranges(const_cast<PangoLayoutLine*>(gobj()), start_index, end_index, &ranges, &n_ranges);
  return Glib::ArrayHandler<std::pair<int,int>>::array_to_vector(reinterpret_cast<std::pair<int,int>*>(ranges), n_ranges, Glib::OWNERSHIP_SHALLOW);
}

auto LayoutLine::show_in_cairo_context (const Cairo::RefPtr <Cairo::Context> &context) -> void
{
  pango_cairo_show_layout_line(context->cobj(), gobj());
}

auto LayoutLine::add_to_cairo_context (const Cairo::RefPtr <Cairo::Context> &context) -> void
{
  pango_cairo_layout_line_path(context->cobj(), gobj());
}

} /* namespace Pango */

namespace
{
} // anonymous namespace


/* Why reinterpret_cast<LayoutLine*>(gobject) is needed:
 *
 * A LayoutLine instance is in fact always a PangoLayoutLine instance.
 * Unfortunately, PangoLayoutLine cannot be a member of LayoutLine,
 * because it is an opaque struct.  Also, the C interface does not provide
 * any hooks to install a destroy notification handler, thus we cannot
 * wrap it dynamically either.
 *
 * The cast works because LayoutLine does not have any member data, and
 * it is impossible to derive from it.  This is ensured by using final on the
 * class and by using = delete on the default constructor.
 */

namespace Glib
{

auto wrap(PangoLayoutLine* object, const bool take_copy) -> RefPtr<Pango::LayoutLine>
{
  if(take_copy && object)
    pango_layout_line_ref(object);

  // See the comment at the top of this file, if you want to know why the cast works.
  return Glib::make_refptr_for_instance<Pango::LayoutLine>(reinterpret_cast<Pango::LayoutLine*>(object));
}

} // namespace Glib


namespace Pango
{

auto LayoutLine::reference () const -> void
{
  // See the comment at the top of this file, if you want to know why the cast works.
  pango_layout_line_ref(reinterpret_cast<PangoLayoutLine*>(const_cast<LayoutLine*>(this)));
}

auto LayoutLine::unreference () const -> void
{
  // See the comment at the top of this file, if you want to know why the cast works.
  pango_layout_line_unref(reinterpret_cast<PangoLayoutLine*>(const_cast<LayoutLine*>(this)));
}

auto LayoutLine::gobj() -> PangoLayoutLine*
{
  // See the comment at the top of this file, if you want to know why the cast works.
  return reinterpret_cast<PangoLayoutLine*>(this);
}

auto LayoutLine::gobj() const -> const PangoLayoutLine*
{
  // See the comment at the top of this file, if you want to know why the cast works.
  return reinterpret_cast<const PangoLayoutLine*>(this);
}

auto LayoutLine::gobj_copy() const -> PangoLayoutLine*
{
  // See the comment at the top of this file, if you want to know why the cast works.
  const auto gobject = reinterpret_cast<PangoLayoutLine*>(const_cast<LayoutLine*>(this));
  pango_layout_line_ref(gobject);
  return gobject;
}


auto LayoutLine::x_to_index(
  const int x_pos, int& index, int& trailing) const -> bool
{
  return pango_layout_line_x_to_index(const_cast<PangoLayoutLine*>(gobj()), x_pos, &index, &trailing);
}

auto LayoutLine::get_extents (Rectangle &ink_rect, Rectangle &logical_rect) const -> void
{
  pango_layout_line_get_extents(const_cast<PangoLayoutLine*>(gobj()), ink_rect.gobj(), logical_rect.gobj());
}

auto LayoutLine::get_pixel_extents (Rectangle &ink_rect, Rectangle &logical_rect) const -> void
{
  pango_layout_line_get_pixel_extents(const_cast<PangoLayoutLine*>(gobj()), ink_rect.gobj(), logical_rect.gobj());
}

auto LayoutLine::get_layout() -> Glib::RefPtr<Layout>
{
  Glib::RefPtr<Layout> ref_ptr(Glib::wrap(gobj()->layout));

  if(ref_ptr)
    ref_ptr->reference();

  return ref_ptr;
}

auto LayoutLine::get_layout() const -> Glib::RefPtr<const Layout>
{
  Glib::RefPtr<const Layout> ref_ptr(Glib::wrap(gobj()->layout));

  if(ref_ptr)
    ref_ptr->reference();

  return ref_ptr;
}

auto LayoutLine::get_length() const -> int
{
  return gobj()->length;
}

auto LayoutLine::get_start_index() const -> int
{
  return gobj()->start_index;
}


} // namespace Pango


