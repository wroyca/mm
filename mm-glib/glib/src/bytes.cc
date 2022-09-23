// Generated by gmmproc 2.74.0 -- DO NOT MODIFY!


#include <glibmm.h>

#include <glibmm/bytes.h>
#include <glibmm/private/bytes_p.h>


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

Glib::RefPtr<Glib::Bytes>
Bytes::create(gconstpointer data, gsize size)
{
  GBytes* bytes = g_bytes_new(data, size);
  return Glib::wrap(bytes);
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

Glib::RefPtr<Glib::Bytes> wrap(GBytes* object, bool take_copy)
{
  if(take_copy && object)
    g_bytes_ref(object);

  // See the comment at the top of this file, if you want to know why the cast works.
  return Glib::make_refptr_for_instance<Glib::Bytes>(reinterpret_cast<Glib::Bytes*>(object));
}

} // namespace Glib


namespace Glib
{

void Bytes::reference() const
{
  // See the comment at the top of this file, if you want to know why the cast works.
  g_bytes_ref(reinterpret_cast<GBytes*>(const_cast<Bytes*>(this)));
}

void Bytes::unreference() const
{
  // See the comment at the top of this file, if you want to know why the cast works.
  g_bytes_unref(reinterpret_cast<GBytes*>(const_cast<Bytes*>(this)));
}

GBytes* Bytes::gobj()
{
  // See the comment at the top of this file, if you want to know why the cast works.
  return reinterpret_cast<GBytes*>(this);
}

const GBytes* Bytes::gobj() const
{
  // See the comment at the top of this file, if you want to know why the cast works.
  return reinterpret_cast<const GBytes*>(this);
}

GBytes* Bytes::gobj_copy() const
{
  // See the comment at the top of this file, if you want to know why the cast works.
  const auto gobject = reinterpret_cast<GBytes*>(const_cast<Bytes*>(this));
  g_bytes_ref(gobject);
  return gobject;
}


gconstpointer Bytes::get_data(gsize& size) const
{
  return g_bytes_get_data(const_cast<GBytes*>(gobj()), &(size));
}

gsize Bytes::get_size() const
{
  return g_bytes_get_size(const_cast<GBytes*>(gobj()));
}

guint Bytes::hash(gconstpointer bytes)
{
  return g_bytes_hash(bytes);
}

bool Bytes::equal(gconstpointer bytes1, gconstpointer bytes2)
{
  return g_bytes_equal(bytes1, bytes2);
}

gint Bytes::compare(gconstpointer bytes1, gconstpointer bytes2)
{
  return g_bytes_compare(bytes1, bytes2);
}


} // namespace Glib


