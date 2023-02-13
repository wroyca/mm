


#include <libmm-glib/mm-glib.hxx>

#include <libmm-pango/tabarray.hxx>
#include <libmm-pango/tabarray_p.hxx>


// -*- c++ -*-
/* $Id: tabarray.ccg,v 1.2 2006/07/05 18:46:36 markoa Exp $ */

/*
 *
 * Copyright 2002 The gtkmm Development Team
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

namespace Pango
{

TabArray::TabArray(const int initial_size, const bool positions_in_pixels)
{
  gobject_ = pango_tab_array_new(initial_size, positions_in_pixels);
}

auto TabArray::get_tab(
  const int tab_index) const -> std::pair<TabAlign,int>
{
  PangoTabAlign p_alignment;
  TabAlign alignment;
  int location;
  pango_tab_array_get_tab(const_cast<PangoTabArray*>(gobj()), tab_index, &p_alignment, &location);
  alignment = static_cast<TabAlign>(p_alignment);
  return std::pair<TabAlign,int>(alignment, location);
}

auto TabArray::get_tabs() const -> std::vector<std::pair<TabAlign,int>>
{
  typedef std::pair<TabAlign,int> PairType;

  PairType* pair_buffer = nullptr;
  const int size = pango_tab_array_get_size(const_cast<PangoTabArray*>(gobj()));

  if(size > 0)
  {
    // Get arrays
    PangoTabAlign* pAlignments = nullptr;
    int*           pLocations  = nullptr;
    pango_tab_array_get_tabs(const_cast<PangoTabArray*>(gobj()), &pAlignments, &pLocations);

    if(pAlignments && pLocations)
    {
      // Create temporary C array.  Fortunately, the C++ type is POD,
      // so we can safely store it in the array.
      pair_buffer = g_new(PairType, size);

      for(int i = 0; i < size; ++i)
      {
        pair_buffer[i].first  = (TabAlign)pAlignments[i];
        pair_buffer[i].second = pLocations[i];
      }
    }

    g_free(pAlignments);
    g_free(pLocations);
  }

  return Glib::ArrayHandler<PairType>::array_to_vector(pair_buffer, size, Glib::OWNERSHIP_SHALLOW);
}

} /* namespace Pango */


namespace
{
} // anonymous namespace

// static
auto Glib::Value<Pango::TabAlign>::value_type() -> GType
{
  return pango_tab_align_get_type();
}


namespace Glib
{

auto wrap(PangoTabArray* object, const bool take_copy) -> Pango::TabArray
{
  return Pango::TabArray(object, take_copy);
}

} // namespace Glib


namespace Pango
{


// static
auto TabArray::get_type() -> GType
{
  return pango_tab_array_get_type();
}

TabArray::TabArray()
:
  gobject_ (nullptr) // Allows creation of invalid wrapper, e.g. for output arguments to methods.
{}

TabArray::TabArray(const TabArray& other)
:
  gobject_ (other.gobject_ ? pango_tab_array_copy(other.gobject_) : nullptr)
{}

TabArray::TabArray(TabArray&& other) noexcept
:
  gobject_(other.gobject_)
{
  other.gobject_ = nullptr;
}

auto TabArray::operator=(TabArray&& other) noexcept -> TabArray&
{
  TabArray temp (std::move(other));
  swap(temp);
  return *this;
}

TabArray::TabArray(PangoTabArray* gobject, const bool make_a_copy)
:
  // For BoxedType wrappers, make_a_copy is true by default.  The static
  // BoxedType wrappers must always take a copy, thus make_a_copy = true
  // ensures identical behaviour if the default argument is used.
  gobject_ (make_a_copy && gobject ? pango_tab_array_copy(gobject) : gobject)
{}

auto TabArray::operator=(const TabArray& other) -> TabArray&
{
  TabArray temp (other);
  swap(temp);
  return *this;
}

TabArray::~TabArray() noexcept
{
  if(gobject_)
    pango_tab_array_free(gobject_);
}

auto TabArray::swap (TabArray &other) noexcept -> void
{
  std::swap(gobject_, other.gobject_);
}

auto TabArray::gobj_copy() const -> PangoTabArray*
{
  return pango_tab_array_copy(gobject_);
}


auto TabArray::get_size() const -> int
{
  return pango_tab_array_get_size(const_cast<PangoTabArray*>(gobj()));
}

auto TabArray::resize (
  const int new_size) -> void
{
  pango_tab_array_resize(gobj(), new_size);
}

auto TabArray::set_tab (
  const int tab_index, TabAlign alignment, const int location) -> void
{
  pango_tab_array_set_tab(gobj(), tab_index, static_cast<PangoTabAlign>(alignment), location);
}

auto TabArray::get_positions_in_pixels() const -> bool
{
  return pango_tab_array_get_positions_in_pixels(const_cast<PangoTabArray*>(gobj()));
}


} // namespace Pango


