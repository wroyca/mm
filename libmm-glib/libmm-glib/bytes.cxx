


#include <libmm-glib/mm-glib.hxx>

#include <libmm-glib/bytes.hxx>
#include <libmm-glib/bytes_p.hxx>


/* Copyright (C) 2012 The glibmm Development Team
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

namespace Glib
{

auto
Bytes::create(
  const gconstpointer data, const gsize size) -> RefPtr<Bytes>
{
  GBytes* bytes = g_bytes_new(data, size);
  return wrap(bytes);
}

} // namespace Glib

namespace
{
} // anonymous namespace


/* Why reinterpret_cast<Bytes*>(gobject) is needed:
 *
 * A Bytes instance is in fact always a GBytes instance.
 * Unfortunately, GBytes cannot be a member of Bytes,
 * because it is an opaque struct.  Also, the C interface does not provide
 * any hooks to install a destroy notification handler, thus we cannot
 * wrap it dynamically either.
 *
 * The cast works because Bytes does not have any member data, and
 * it is impossible to derive from it.  This is ensured by using final on the
 * class and by using = delete on the default constructor.
 */

namespace Glib
{

auto wrap(GBytes* object, const bool take_copy) -> RefPtr<Bytes>
{
  if(take_copy && object)
    g_bytes_ref(object);

  // See the comment at the top of this file, if you want to know why the cast works.
  return Glib::make_refptr_for_instance<Bytes>(reinterpret_cast<Bytes *>(object));
}

} // namespace Glib


namespace Glib
{

auto Bytes::reference () const -> void
{
  // See the comment at the top of this file, if you want to know why the cast works.
  g_bytes_ref(reinterpret_cast<GBytes*>(const_cast<Bytes*>(this)));
}

auto Bytes::unreference () const -> void
{
  // See the comment at the top of this file, if you want to know why the cast works.
  g_bytes_unref(reinterpret_cast<GBytes*>(const_cast<Bytes*>(this)));
}

auto Bytes::gobj() -> GBytes*
{
  // See the comment at the top of this file, if you want to know why the cast works.
  return reinterpret_cast<GBytes*>(this);
}

auto Bytes::gobj() const -> const GBytes*
{
  // See the comment at the top of this file, if you want to know why the cast works.
  return reinterpret_cast<const GBytes*>(this);
}

auto Bytes::gobj_copy() const -> GBytes*
{
  // See the comment at the top of this file, if you want to know why the cast works.
  const auto gobject = reinterpret_cast<GBytes*>(const_cast<Bytes*>(this));
  g_bytes_ref(gobject);
  return gobject;
}


auto Bytes::get_data(gsize& size) const -> gconstpointer
{
  return g_bytes_get_data(const_cast<GBytes*>(gobj()), &size);
}

auto Bytes::get_size() const -> gsize
{
  return g_bytes_get_size(const_cast<GBytes*>(gobj()));
}

auto Bytes::hash(
  const gconstpointer bytes) -> guint
{
  return g_bytes_hash(bytes);
}

auto Bytes::equal(
  const gconstpointer bytes1, const gconstpointer bytes2) -> bool
{
  return g_bytes_equal(bytes1, bytes2);
}

auto Bytes::compare(
  const gconstpointer bytes1, const gconstpointer bytes2) -> gint
{
  return g_bytes_compare(bytes1, bytes2);
}


} // namespace Glib


