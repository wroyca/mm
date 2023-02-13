


#include <mm/glib/mm-glib.hpp>

#include <mm/pango/coverage.hpp>
#include <mm/pango/private/coverage_p.hpp>


/*
 * Copyright 1998-1999 The Gtk-- Development Team
 * Copyright 2001      Free Software Foundation
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

using Level = Pango::Coverage::Level;

namespace
{
} // anonymous namespace

// static
auto Glib::Value<Pango::Coverage::Level>::value_type() -> GType
{
  return pango_coverage_level_get_type();
}


/* Why reinterpret_cast<Coverage*>(gobject) is needed:
 *
 * A Coverage instance is in fact always a PangoCoverage instance.
 * Unfortunately, PangoCoverage cannot be a member of Coverage,
 * because it is an opaque struct.  Also, the C interface does not provide
 * any hooks to install a destroy notification handler, thus we cannot
 * wrap it dynamically either.
 *
 * The cast works because Coverage does not have any member data, and
 * it is impossible to derive from it.  This is ensured by using final on the
 * class and by using = delete on the default constructor.
 */

namespace Glib
{

auto wrap(PangoCoverage* object, const bool take_copy) -> RefPtr<Pango::Coverage>
{
  if(take_copy && object)
    pango_coverage_ref(object);

  // See the comment at the top of this file, if you want to know why the cast works.
  return Glib::make_refptr_for_instance<Pango::Coverage>(reinterpret_cast<Pango::Coverage*>(object));
}

} // namespace Glib


namespace Pango
{

// static
auto Coverage::create() -> Glib::RefPtr<Coverage>
{
  // See the comment at the top of this file, if you want to know why the cast works.
  return Glib::make_refptr_for_instance<Coverage>(reinterpret_cast<Coverage*>(pango_coverage_new()));
}

auto Coverage::reference () const -> void
{
  // See the comment at the top of this file, if you want to know why the cast works.
  pango_coverage_ref(reinterpret_cast<PangoCoverage*>(const_cast<Coverage*>(this)));
}

auto Coverage::unreference () const -> void
{
  // See the comment at the top of this file, if you want to know why the cast works.
  pango_coverage_unref(reinterpret_cast<PangoCoverage*>(const_cast<Coverage*>(this)));
}

auto Coverage::gobj() -> PangoCoverage*
{
  // See the comment at the top of this file, if you want to know why the cast works.
  return reinterpret_cast<PangoCoverage*>(this);
}

auto Coverage::gobj() const -> const PangoCoverage*
{
  // See the comment at the top of this file, if you want to know why the cast works.
  return reinterpret_cast<const PangoCoverage*>(this);
}

auto Coverage::gobj_copy() const -> PangoCoverage*
{
  // See the comment at the top of this file, if you want to know why the cast works.
  const auto gobject = reinterpret_cast<PangoCoverage*>(const_cast<Coverage*>(this));
  pango_coverage_ref(gobject);
  return gobject;
}


auto Coverage::get(
  const int index) const -> Level
{
  return static_cast<Level>(pango_coverage_get(const_cast<PangoCoverage*>(gobj()), index));
}

auto Coverage::set (
  const int index, Level level) -> void
{
  pango_coverage_set(gobj(), index, static_cast<PangoCoverageLevel>(level));
}


} // namespace Pango


