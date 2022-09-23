// Generated by gmmproc 2.74.0 -- DO NOT MODIFY!


#include <glibmm.h>

#include <glibmm/checksum.h>
#include <glibmm/private/checksum_p.h>


/* Copyright (C) 2002 The gtkmm Development Team
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

#include <glibmm/utility.h>
#include <glibmm/checksum.h>

namespace Glib
{

Checksum::Checksum(Type type) : gobject_(g_checksum_new((GChecksumType)type))
{
}

Checksum::operator bool() const
{
  return gobject_ != nullptr;
}

gssize
Checksum::get_length(Type checksum_type)
{
  return g_checksum_type_get_length((GChecksumType)checksum_type);
}

std::string
Checksum::compute_checksum(Type checksum_type, const std::string& data)
{
  return Glib::convert_return_gchar_ptr_to_stdstring(
    g_compute_checksum_for_string(((GChecksumType)checksum_type), data.c_str(), data.size()));
}

void
Checksum::update(const std::string& data)
{
  g_checksum_update(gobj(), (const guchar*)data.c_str(), data.size());
}

} // Glib namespace

namespace
{
} // anonymous namespace


namespace Glib
{

Glib::Checksum wrap(GChecksum* object, bool take_copy)
{
  return Glib::Checksum(object, take_copy);
}

} // namespace Glib


namespace Glib
{


// static
GType Checksum::get_type()
{
  return g_checksum_get_type();
}

Checksum::Checksum()
:
  gobject_ (nullptr) // Allows creation of invalid wrapper, e.g. for output arguments to methods.
{}

Checksum::Checksum(const Checksum& other)
:
  gobject_ ((other.gobject_) ? g_checksum_copy(other.gobject_) : nullptr)
{}

Checksum::Checksum(Checksum&& other) noexcept
:
  gobject_(other.gobject_)
{
  other.gobject_ = nullptr;
}

Checksum& Checksum::operator=(Checksum&& other) noexcept
{
  Checksum temp (std::move(other));
  swap(temp);
  return *this;
}

Checksum::Checksum(GChecksum* gobject, bool make_a_copy)
:
  // For BoxedType wrappers, make_a_copy is true by default.  The static
  // BoxedType wrappers must always take a copy, thus make_a_copy = true
  // ensures identical behaviour if the default argument is used.
  gobject_ ((make_a_copy && gobject) ? g_checksum_copy(gobject) : gobject)
{}

Checksum& Checksum::operator=(const Checksum& other)
{
  Checksum temp (other);
  swap(temp);
  return *this;
}

Checksum::~Checksum() noexcept
{
  if(gobject_)
    g_checksum_free(gobject_);
}

void Checksum::swap(Checksum& other) noexcept
{
  std::swap(gobject_, other.gobject_);
}

GChecksum* Checksum::gobj_copy() const
{
  return g_checksum_copy(gobject_);
}


void Checksum::reset()
{
  g_checksum_reset(gobj());
}

void Checksum::update(const guchar* data, gssize length)
{
  g_checksum_update(gobj(), data, length);
}

void Checksum::get_digest(guint8 * buffer, gsize * digest_len) const
{
  g_checksum_get_digest(const_cast<GChecksum*>(gobj()), buffer, digest_len);
}

std::string Checksum::get_string() const
{
  return Glib::convert_const_gchar_ptr_to_stdstring(g_checksum_get_string(const_cast<GChecksum*>(gobj())));
}

std::string Checksum::compute_checksum(Type checksum_type, const guchar* data, gsize length)
{
  return Glib::convert_return_gchar_ptr_to_stdstring(g_compute_checksum_for_data((static_cast<GChecksumType>(checksum_type)), data, length));
}


} // namespace Glib


