


#include <libmm-glib/mm-glib.hxx>

#include <libmm-glib/varianttype.hxx>
#include <libmm-glib/varianttype_p.hxx>


/* Copyright 2010 The glibmm Development Team
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

#include <libmm-glib/varianttype.hxx>
#include <libmm-glib/utility.hxx>
#include <glib.h>

namespace Glib
{

VariantType::VariantType(const GVariantType* castitem)
{
  if (castitem)
    gobject_ = g_variant_type_copy(castitem);
  else
    gobject_ = nullptr;
}

VariantType::VariantType(const std::string& type_string)
: gobject_(g_variant_type_new(type_string.c_str()))
{
}

auto
VariantType::operator=(const GVariantType* castitem) -> VariantType&
{
  if (gobject_)
  {
    g_variant_type_free(gobject_);
  }

  if (castitem)
    gobject_ = g_variant_type_copy(castitem);
  else
    gobject_ = nullptr;

  return *this;
}

auto
VariantType::create_tuple(const std::vector<VariantType>& items) -> VariantType
{
  using var_ptr = GVariantType*;
  const auto var_array = new var_ptr[items.size()];

  for (std::vector<VariantType>::size_type i = 0; i < items.size(); i++)
  {
    var_array[i] = const_cast<GVariantType*>(items[i].gobj());
  }

  auto result = wrap(g_variant_type_new_tuple(var_array, items.size()));
  delete[] var_array;
  return result;
}

const VariantType VARIANT_TYPE_BOOL(G_VARIANT_TYPE_BOOLEAN);

const VariantType VARIANT_TYPE_BYTE(G_VARIANT_TYPE_BYTE);

const VariantType VARIANT_TYPE_INT16(G_VARIANT_TYPE_INT16);

const VariantType VARIANT_TYPE_UINT16(G_VARIANT_TYPE_UINT16);

const VariantType VARIANT_TYPE_INT32(G_VARIANT_TYPE_INT32);

const VariantType VARIANT_TYPE_UINT32(G_VARIANT_TYPE_UINT32);

const VariantType VARIANT_TYPE_INT64(G_VARIANT_TYPE_INT64);

const VariantType VARIANT_TYPE_UINT64(G_VARIANT_TYPE_UINT64);

const VariantType VARIANT_TYPE_DOUBLE(G_VARIANT_TYPE_DOUBLE);

const VariantType VARIANT_TYPE_STRING(G_VARIANT_TYPE_STRING);

const VariantType VARIANT_TYPE_OBJECT_PATH(G_VARIANT_TYPE_OBJECT_PATH);

const VariantType VARIANT_TYPE_SIGNATURE(G_VARIANT_TYPE_SIGNATURE);

const VariantType VARIANT_TYPE_VARIANT(G_VARIANT_TYPE_VARIANT);

const VariantType VARIANT_TYPE_HANDLE(G_VARIANT_TYPE_HANDLE);

const VariantType VARIANT_TYPE_UNIT(G_VARIANT_TYPE_UNIT);

const VariantType VARIANT_TYPE_ANY(G_VARIANT_TYPE_ANY);

const VariantType VARIANT_TYPE_BASIC(G_VARIANT_TYPE_BASIC);

const VariantType VARIANT_TYPE_MAYBE(G_VARIANT_TYPE_MAYBE);

const VariantType VARIANT_TYPE_ARRAY(G_VARIANT_TYPE_ARRAY);

const VariantType VARIANT_TYPE_TUPLE(G_VARIANT_TYPE_TUPLE);

const VariantType VARIANT_TYPE_DICT_ENTRY(G_VARIANT_TYPE_DICT_ENTRY);

const VariantType VARIANT_TYPE_DICTIONARY(G_VARIANT_TYPE_DICTIONARY);

const VariantType VARIANT_TYPE_STRING_ARRAY(G_VARIANT_TYPE_STRING_ARRAY);

const VariantType VARIANT_TYPE_OBJECT_PATH_ARRAY(G_VARIANT_TYPE_OBJECT_PATH_ARRAY);

const VariantType VARIANT_TYPE_BYTESTRING(G_VARIANT_TYPE_BYTESTRING);

const VariantType VARIANT_TYPE_BYTESTRING_ARRAY(G_VARIANT_TYPE_BYTESTRING_ARRAY);

auto
VariantType::get_string() const -> std::string
{
  return std::string(g_variant_type_peek_string(gobj()), g_variant_type_get_string_length(gobj()));
}

auto VariantType::get_item_types() const -> std::vector<VariantType>
{
  std::vector<VariantType> result;
  auto next_item_type = g_variant_type_first(gobj());
  while (next_item_type)
  {
    result.emplace_back(const_cast<GVariantType*>(next_item_type), true);
    next_item_type = g_variant_type_next(next_item_type);
  }
  return result;
}

// Glib::Value<Glib::VariantType>
auto Value<VariantType>::value_type() -> GType
{
  // The type function is *not* called g_variant_type_get_type().
  // Use the macro in order to avoid using the non-standard function name here.
  return G_TYPE_VARIANT_TYPE;
}

auto Value <VariantType>::set (const CppType &data) -> void
{
  set_boxed(data.gobj());
}

auto Value<VariantType>::get() const -> CppType
{
  return wrap(static_cast<CType>(get_boxed()), true);
}

} // namespace GLib

namespace
{
} // anonymous namespace


namespace Glib
{

auto wrap(GVariantType* object, const bool take_copy /* = false */) -> VariantType
{
  return VariantType(object, take_copy);
}

} // namespace Glib


namespace Glib
{


VariantType::VariantType()
:
  gobject_ (nullptr) // Allows creation of invalid wrapper, e.g. for output arguments to methods.
{}

VariantType::VariantType(const VariantType& src)
:
  gobject_ (src.gobject_ ? g_variant_type_copy(src.gobject_) : nullptr)
{}

VariantType::VariantType(GVariantType* castitem, const bool make_a_copy /* = false */)
{
  if(!make_a_copy)
  {
    // It was given to us by a function which has already made a copy for us to keep.
    gobject_ = castitem;
  }
  else
  {
    // We are probably getting it via direct access to a struct,
    // so we can not just take it - we have to take a copy of it.
    if(castitem)
      gobject_ = g_variant_type_copy(castitem);
    else
      gobject_ = nullptr;
  }
}


auto VariantType::operator=(const VariantType& src) -> VariantType&
{
  const auto new_gobject = src.gobject_ ? g_variant_type_copy(src.gobject_) : nullptr;

  if(gobject_)
    g_variant_type_free(gobject_);

  gobject_ = new_gobject;

  return *this;
}

VariantType::VariantType(VariantType&& other) noexcept
:
  gobject_(other.gobject_)
{
  other.gobject_ = nullptr;
}

auto VariantType::operator=(VariantType&& other) noexcept -> VariantType&
{
  VariantType temp (std::move(other));
  swap(temp);
  return *this;
}

VariantType::~VariantType() noexcept
{
  if(gobject_)
    g_variant_type_free(gobject_);
}

auto VariantType::swap (VariantType &other) noexcept -> void
{
  std::swap(gobject_, other.gobject_);
}

auto VariantType::gobj_copy() const -> GVariantType*
{
  return g_variant_type_copy(gobject_);
}


auto VariantType::create_array(const VariantType& element) -> VariantType
{
  return wrap(g_variant_type_new_array(element.gobj()));
}

auto VariantType::create_maybe(const VariantType& element) -> VariantType
{
  return wrap(g_variant_type_new_maybe(element.gobj()));
}

auto VariantType::create_dict_entry(const VariantType& key, const VariantType& value) -> VariantType
{
  return wrap(g_variant_type_new_dict_entry(key.gobj(), value.gobj()));
}

auto VariantType::get_string_length() const -> gsize
{
  return g_variant_type_get_string_length(gobj());
}

auto VariantType::is_definite() const -> bool
{
  return g_variant_type_is_definite(gobj());
}

auto VariantType::is_container() const -> bool
{
  return g_variant_type_is_container(gobj());
}

auto VariantType::is_basic() const -> bool
{
  return g_variant_type_is_basic(gobj());
}

auto VariantType::is_maybe() const -> bool
{
  return g_variant_type_is_maybe(gobj());
}

auto VariantType::is_array() const -> bool
{
  return g_variant_type_is_array(gobj());
}

auto VariantType::is_tuple() const -> bool
{
  return g_variant_type_is_tuple(gobj());
}

auto VariantType::is_dict_entry() const -> bool
{
  return g_variant_type_is_dict_entry(gobj());
}

auto VariantType::is_variant() const -> bool
{
  return g_variant_type_is_variant(gobj());
}

auto VariantType::hash() const -> guint
{
  return g_variant_type_hash(gobj());
}

auto VariantType::equal(const VariantType& other) const -> bool
{
  return g_variant_type_equal(gobj(), other.gobj());
}

auto VariantType::is_subtype_of(const VariantType& supertype) const -> bool
{
  return g_variant_type_is_subtype_of(gobj(), supertype.gobj());
}

auto VariantType::element() const -> VariantType
{
  return wrap(const_cast<GVariantType*>(g_variant_type_element(gobj())), true);
}

auto VariantType::n_items() const -> gsize
{
  return g_variant_type_n_items(gobj());
}

auto VariantType::key() const -> VariantType
{
  return wrap(const_cast<GVariantType*>(g_variant_type_key(gobj())), true);
}

auto VariantType::value() const -> VariantType
{
  return wrap(const_cast<GVariantType*>(g_variant_type_value(gobj())), true);
}


} // namespace Glib


