


#include <libmm-glib/mm-glib.hpp>

#include <libmm-pango/layoutiter.hpp>
#include <libmm-pango/layoutiter_p.hpp>


/*
 * Copyright 2001-2002 The gtkmm Development Team
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

namespace Pango
{

auto LayoutIter::get_char_extents() const -> Rectangle
{
  Rectangle logical_rect;
  pango_layout_iter_get_char_extents(const_cast<PangoLayoutIter*>(gobj()), logical_rect.gobj());
  return logical_rect;
}

auto LayoutIter::get_cluster_ink_extents() const -> Rectangle
{
  Rectangle ink_rect;
  pango_layout_iter_get_cluster_extents(const_cast<PangoLayoutIter*>(gobj()), ink_rect.gobj(), 0);
  return ink_rect;
}

auto LayoutIter::get_cluster_logical_extents() const -> Rectangle
{
  Rectangle logical_rect;
  pango_layout_iter_get_cluster_extents(const_cast<PangoLayoutIter*>(gobj()), 0, logical_rect.gobj());
  return logical_rect;
}

auto LayoutIter::get_run_ink_extents() const -> Rectangle
{
  Rectangle ink_rect;
  pango_layout_iter_get_run_extents(const_cast<PangoLayoutIter*>(gobj()), ink_rect.gobj(), 0);
  return ink_rect;
}

auto LayoutIter::get_run_logical_extents() const -> Rectangle
{
  Rectangle logical_rect;
  pango_layout_iter_get_run_extents(const_cast<PangoLayoutIter*>(gobj()), 0, logical_rect.gobj());
  return logical_rect;
}

auto LayoutIter::get_line_ink_extents() const -> Rectangle
{
  Rectangle ink_rect;
  pango_layout_iter_get_line_extents(const_cast<PangoLayoutIter*>(gobj()), ink_rect.gobj(), 0);
  return ink_rect;
}

auto LayoutIter::get_line_logical_extents() const -> Rectangle
{
  Rectangle logical_rect;
  pango_layout_iter_get_line_extents(const_cast<PangoLayoutIter*>(gobj()), 0, logical_rect.gobj());
  return logical_rect;
}

auto LayoutIter::get_layout_ink_extents() const -> Rectangle
{
  Rectangle ink_rect;
  pango_layout_iter_get_layout_extents(const_cast<PangoLayoutIter*>(gobj()), ink_rect.gobj(), 0);
  return ink_rect;
}

auto LayoutIter::get_layout_logical_extents() const -> Rectangle
{
  Rectangle logical_rect;
  pango_layout_iter_get_layout_extents(const_cast<PangoLayoutIter*>(gobj()), 0, logical_rect.gobj());
  return logical_rect;
}

} // namespace Pango

namespace
{
} // anonymous namespace


namespace Glib
{

auto wrap(PangoLayoutIter* object, const bool take_copy) -> Pango::LayoutIter
{
  return Pango::LayoutIter(object, take_copy);
}

} // namespace Glib


namespace Pango
{


// static
auto LayoutIter::get_type() -> GType
{
  return pango_layout_iter_get_type();
}

LayoutIter::LayoutIter()
:
  gobject_ (nullptr) // Allows creation of invalid wrapper, e.g. for output arguments to methods.
{}

LayoutIter::LayoutIter(const LayoutIter& other)
:
  gobject_ (other.gobject_ ? pango_layout_iter_copy(other.gobject_) : nullptr)
{}

LayoutIter::LayoutIter(LayoutIter&& other) noexcept
:
  gobject_(other.gobject_)
{
  other.gobject_ = nullptr;
}

auto LayoutIter::operator=(LayoutIter&& other) noexcept -> LayoutIter&
{
  LayoutIter temp (std::move(other));
  swap(temp);
  return *this;
}

LayoutIter::LayoutIter(PangoLayoutIter* gobject, const bool make_a_copy)
:
  // For BoxedType wrappers, make_a_copy is true by default.  The static
  // BoxedType wrappers must always take a copy, thus make_a_copy = true
  // ensures identical behaviour if the default argument is used.
  gobject_ (make_a_copy && gobject ? pango_layout_iter_copy(gobject) : gobject)
{}

auto LayoutIter::operator=(const LayoutIter& other) -> LayoutIter&
{
  LayoutIter temp (other);
  swap(temp);
  return *this;
}

LayoutIter::~LayoutIter() noexcept
{
  if(gobject_)
    pango_layout_iter_free(gobject_);
}

auto LayoutIter::swap (LayoutIter &other) noexcept -> void
{
  std::swap(gobject_, other.gobject_);
}

auto LayoutIter::gobj_copy() const -> PangoLayoutIter*
{
  return pango_layout_iter_copy(gobject_);
}


auto LayoutIter::get_index() const -> int
{
  return pango_layout_iter_get_index(const_cast<PangoLayoutIter*>(gobj()));
}

auto LayoutIter::get_run() const -> GlyphItem
{
  return GlyphItem(pango_layout_iter_get_run_readonly(const_cast<PangoLayoutIter*>(gobj())));
}

auto LayoutIter::get_line() -> Glib::RefPtr<LayoutLine>
{
  auto retvalue = Glib::wrap(pango_layout_iter_get_line(gobj()));
  if(retvalue)
    retvalue->reference(); //The function does not do a ref for us.
  return retvalue;
}

auto LayoutIter::get_line() const -> Glib::RefPtr<const LayoutLine>
{
  auto retvalue = Glib::wrap(pango_layout_iter_get_line_readonly(const_cast<PangoLayoutIter*>(gobj())));
  if(retvalue)
    retvalue->reference(); //The function does not do a ref for us.
  return retvalue;
}

auto LayoutIter::get_const_line() const -> Glib::RefPtr<const LayoutLine>
{
  auto retvalue = Glib::wrap(pango_layout_iter_get_line_readonly(const_cast<PangoLayoutIter*>(gobj())));
  if(retvalue)
    retvalue->reference(); //The function does not do a ref for us.
  return retvalue;
}

auto LayoutIter::at_last_line() const -> bool
{
  return pango_layout_iter_at_last_line(const_cast<PangoLayoutIter*>(gobj()));
}

auto LayoutIter::get_layout() -> Glib::RefPtr<Layout>
{
  auto retvalue = Glib::wrap(pango_layout_iter_get_layout(gobj()));
  if(retvalue)
    retvalue->reference(); //The function does not do a ref for us.
  return retvalue;
}

auto LayoutIter::get_layout() const -> Glib::RefPtr<const Layout>
{
  return const_cast<LayoutIter*>(this)->get_layout();
}

auto LayoutIter::next_char() -> bool
{
  return pango_layout_iter_next_char(gobj());
}

auto LayoutIter::next_cluster() -> bool
{
  return pango_layout_iter_next_cluster(gobj());
}

auto LayoutIter::next_run() -> bool
{
  return pango_layout_iter_next_run(gobj());
}

auto LayoutIter::next_line() -> bool
{
  return pango_layout_iter_next_line(gobj());
}

auto LayoutIter::get_cluster_extents (Rectangle &ink_rect, Rectangle &logical_rect) const -> void
{
  pango_layout_iter_get_cluster_extents(const_cast<PangoLayoutIter*>(gobj()), ink_rect.gobj(), logical_rect.gobj());
}

auto LayoutIter::get_run_extents (Rectangle &ink_rect, Rectangle &logical_rect) const -> void
{
  pango_layout_iter_get_run_extents(const_cast<PangoLayoutIter*>(gobj()), ink_rect.gobj(), logical_rect.gobj());
}

auto LayoutIter::get_line_extents (Rectangle &ink_rect, Rectangle &logical_rect) const -> void
{
  pango_layout_iter_get_line_extents(const_cast<PangoLayoutIter*>(gobj()), ink_rect.gobj(), logical_rect.gobj());
}

auto LayoutIter::get_line_yrange (int &y0, int &y1) const -> void
{
  pango_layout_iter_get_line_yrange(const_cast<PangoLayoutIter*>(gobj()), &y0, &y1);
}

auto LayoutIter::get_layout_extents (Rectangle &ink_rect, Rectangle &logical_rect) const -> void
{
  pango_layout_iter_get_layout_extents(const_cast<PangoLayoutIter*>(gobj()), ink_rect.gobj(), logical_rect.gobj());
}

auto LayoutIter::get_baseline() const -> int
{
  return pango_layout_iter_get_baseline(const_cast<PangoLayoutIter*>(gobj()));
}


} // namespace Pango


