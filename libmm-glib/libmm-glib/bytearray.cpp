


#include <mm/glib/mm-glib.hpp>

#include <mm/glib/bytearray.hpp>
#include <mm/glib/private/bytearray_p.hpp>


/* Copyright (C) 2013 The glibmm Development Team
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

namespace
{

extern "C" {

auto
ByteArray_Compare_Data_Func(
  const gconstpointer a, const gconstpointer b, const gpointer user_data) -> int
{
  const Glib::ByteArray::SlotCompare* slot = static_cast<Glib::ByteArray::SlotCompare*>(user_data);

  return (*slot)(static_cast<const guint8*>(a), static_cast<const guint8*>(b));
}
}
}

namespace Glib
{

auto
ByteArray::size() const -> guint
{
  return gobj()->len;
}

auto
ByteArray::get_data() -> guint8*
{
  return gobj()->data;
}

auto
ByteArray::get_data() const -> const guint8*
{
  return gobj()->data;
}

} // namespace Glib

namespace
{
} // anonymous namespace


/* Why reinterpret_cast<ByteArray*>(gobject) is needed:
 *
 * A ByteArray instance is in fact always a GByteArray instance.
 * Unfortunately, GByteArray cannot be a member of ByteArray,
 * because it is an opaque struct.  Also, the C interface does not provide
 * any hooks to install a destroy notification handler, thus we cannot
 * wrap it dynamically either.
 *
 * The cast works because ByteArray does not have any member data, and
 * it is impossible to derive from it.  This is ensured by using final on the
 * class and by using = delete on the default constructor.
 */

namespace Glib
{

auto wrap(GByteArray* object, const bool take_copy) -> RefPtr<ByteArray>
{
  if(take_copy && object)
    g_byte_array_ref(object);

  // See the comment at the top of this file, if you want to know why the cast works.
  return Glib::make_refptr_for_instance<ByteArray>(reinterpret_cast<ByteArray *>(object));
}

} // namespace Glib


namespace Glib
{

// static
auto ByteArray::get_type() -> GType
{
  return g_byte_array_get_type();
}

auto ByteArray::reference () const -> void
{
  // See the comment at the top of this file, if you want to know why the cast works.
  g_byte_array_ref(reinterpret_cast<GByteArray*>(const_cast<ByteArray*>(this)));
}

auto ByteArray::unreference () const -> void
{
  // See the comment at the top of this file, if you want to know why the cast works.
  g_byte_array_unref(reinterpret_cast<GByteArray*>(const_cast<ByteArray*>(this)));
}

auto ByteArray::gobj() -> GByteArray*
{
  // See the comment at the top of this file, if you want to know why the cast works.
  return reinterpret_cast<GByteArray*>(this);
}

auto ByteArray::gobj() const -> const GByteArray*
{
  // See the comment at the top of this file, if you want to know why the cast works.
  return reinterpret_cast<const GByteArray*>(this);
}

auto ByteArray::gobj_copy() const -> GByteArray*
{
  // See the comment at the top of this file, if you want to know why the cast works.
  const auto gobject = reinterpret_cast<GByteArray*>(const_cast<ByteArray*>(this));
  g_byte_array_ref(gobject);
  return gobject;
}


auto ByteArray::create() -> RefPtr<ByteArray>
{
  return wrap(g_byte_array_new());
}

auto ByteArray::append(const guint8* data, const guint len) -> RefPtr<ByteArray>
{
  auto retvalue = wrap(g_byte_array_append(gobj(), data, len));
  if(retvalue)
    retvalue->reference(); //The function does not do a ref for us.
  return retvalue;
}

auto ByteArray::prepend(const guint8* data, const guint len) -> RefPtr<ByteArray>
{
  auto retvalue = wrap(g_byte_array_prepend(gobj(), data, len));
  if(retvalue)
    retvalue->reference(); //The function does not do a ref for us.
  return retvalue;
}

auto ByteArray::remove_index(
  const guint index) -> RefPtr<ByteArray>
{
  auto retvalue = wrap(g_byte_array_remove_index(gobj(), index));
  if(retvalue)
    retvalue->reference(); //The function does not do a ref for us.
  return retvalue;
}

auto ByteArray::remove_index_fast(
  const guint index) -> RefPtr<ByteArray>
{
  auto retvalue = wrap(g_byte_array_remove_index_fast(gobj(), index));
  if(retvalue)
    retvalue->reference(); //The function does not do a ref for us.
  return retvalue;
}

auto ByteArray::remove_range(
  const guint index, const guint length) -> RefPtr<ByteArray>
{
  auto retvalue = wrap(g_byte_array_remove_range(gobj(), index, length));
  if(retvalue)
    retvalue->reference(); //The function does not do a ref for us.
  return retvalue;
}

auto ByteArray::sort (const SlotCompare &slot) -> void
{
  // Use the original slot (not a copy).
  const auto slot_copy = const_cast<SlotCompare*>(&slot);

  g_byte_array_sort_with_data(gobj(), &ByteArray_Compare_Data_Func, slot_copy);
}

auto ByteArray::set_size(
  const guint length) -> RefPtr<ByteArray>
{
  auto retvalue = wrap(g_byte_array_set_size(gobj(), length));
  if(retvalue)
    retvalue->reference(); //The function does not do a ref for us.
  return retvalue;
}


} // namespace Glib


