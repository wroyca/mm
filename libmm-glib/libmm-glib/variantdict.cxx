


#include <libmm-glib/mm-glib.hpp>

#include <libmm-glib/variantdict.hpp>
#include <libmm-glib/variantdict_p.hpp>


/*
 * Copyright 2014 The gtkmm Development Team
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
 * License along with this library.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <glib.h>

namespace Glib
{

auto
VariantDict::lookup_value_variant(
  const ustring & key, const VariantType& expected_type, VariantBase& value) const -> bool
{
  const GVariant* const g_value = g_variant_dict_lookup_value(
    const_cast<GVariantDict*>(gobj()), key.c_str(), expected_type.gobj());
  if (!g_value)
    return false;

  value.init(g_value); // g_value is already referenced.
  return true;
}

} // namespace Glib

namespace
{
} // anonymous namespace


/* Why reinterpret_cast<VariantDict*>(gobject) is needed:
 *
 * A VariantDict instance is in fact always a GVariantDict instance.
 * Unfortunately, GVariantDict cannot be a member of VariantDict,
 * because it is an opaque struct.  Also, the C interface does not provide
 * any hooks to install a destroy notification handler, thus we cannot
 * wrap it dynamically either.
 *
 * The cast works because VariantDict does not have any member data, and
 * it is impossible to derive from it.  This is ensured by using final on the
 * class and by using = delete on the default constructor.
 */

namespace Glib
{

auto wrap(GVariantDict* object, const bool take_copy) -> RefPtr<VariantDict>
{
  if(take_copy && object)
    g_variant_dict_ref(object);

  // See the comment at the top of this file, if you want to know why the cast works.
  return Glib::make_refptr_for_instance<VariantDict>(reinterpret_cast<VariantDict *>(object));
}

} // namespace Glib


namespace Glib
{

auto VariantDict::reference () const -> void
{
  // See the comment at the top of this file, if you want to know why the cast works.
  g_variant_dict_ref(reinterpret_cast<GVariantDict*>(const_cast<VariantDict*>(this)));
}

auto VariantDict::unreference () const -> void
{
  // See the comment at the top of this file, if you want to know why the cast works.
  g_variant_dict_unref(reinterpret_cast<GVariantDict*>(const_cast<VariantDict*>(this)));
}

auto VariantDict::gobj() -> GVariantDict*
{
  // See the comment at the top of this file, if you want to know why the cast works.
  return reinterpret_cast<GVariantDict*>(this);
}

auto VariantDict::gobj() const -> const GVariantDict*
{
  // See the comment at the top of this file, if you want to know why the cast works.
  return reinterpret_cast<const GVariantDict*>(this);
}

auto VariantDict::gobj_copy() const -> GVariantDict*
{
  // See the comment at the top of this file, if you want to know why the cast works.
  const auto gobject = reinterpret_cast<GVariantDict*>(const_cast<VariantDict*>(this));
  g_variant_dict_ref(gobject);
  return gobject;
}


auto VariantDict::create(const VariantBase& from_asv) -> RefPtr<VariantDict>
{
  return wrap(g_variant_dict_new(const_cast<GVariant*>(from_asv.gobj())));
}

auto VariantDict::create() -> RefPtr<VariantDict>
{
  return wrap(g_variant_dict_new(nullptr));
}

auto VariantDict::contains(const ustring & key) const -> bool
{
  return g_variant_dict_contains(const_cast<GVariantDict*>(gobj()), key.c_str());
}

auto VariantDict::insert_value_variant (const ustring &key, const VariantBase &value) -> void
{
  g_variant_dict_insert_value(gobj(), key.c_str(), const_cast<GVariant*>(value.gobj()));
}

auto VariantDict::remove(const ustring & key) -> bool
{
  return g_variant_dict_remove(gobj(), key.c_str());
}

auto VariantDict::clear () -> void
{
  g_variant_dict_clear(gobj());
}


} // namespace Glib


