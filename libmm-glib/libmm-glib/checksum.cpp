


#include <libmm-glib/mm-glib.hpp>

#include <libmm-glib/checksum.hpp>
#include <libmm-glib/checksum_p.hpp>


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

#include <libmm-glib/utility.hpp>
#include <libmm-glib/checksum.hpp>

namespace Glib
{

Checksum::Checksum(Type type) : gobject_(g_checksum_new((GChecksumType)type))
{
}

Checksum::operator bool() const
{
  return gobject_ != nullptr;
}

auto
Checksum::get_length(Type checksum_type) -> gssize
{
  return g_checksum_type_get_length((GChecksumType)checksum_type);
}

auto
Checksum::compute_checksum(Type checksum_type, const std::string& data) -> std::string
{
  return convert_return_gchar_ptr_to_stdstring(
    g_compute_checksum_for_string((GChecksumType)checksum_type, data.c_str(), data.size()));
}

auto Checksum::update (const std::string &data) -> void
{
  g_checksum_update(gobj(), (const guchar*)data.c_str(), data.size());
}

} // Glib namespace

namespace
{
} // anonymous namespace


namespace Glib
{

auto wrap(GChecksum* object, const bool take_copy) -> Checksum
{
  return Checksum(object, take_copy);
}

} // namespace Glib


namespace Glib
{


// static
auto Checksum::get_type() -> GType
{
  return g_checksum_get_type();
}

Checksum::Checksum()
:
  gobject_ (nullptr) // Allows creation of invalid wrapper, e.g. for output arguments to methods.
{}

Checksum::Checksum(const Checksum& other)
:
  gobject_ (other.gobject_ ? g_checksum_copy(other.gobject_) : nullptr)
{}

Checksum::Checksum(Checksum&& other) noexcept
:
  gobject_(other.gobject_)
{
  other.gobject_ = nullptr;
}

auto Checksum::operator=(Checksum&& other) noexcept -> Checksum&
{
  Checksum temp (std::move(other));
  swap(temp);
  return *this;
}

Checksum::Checksum(GChecksum* gobject, const bool make_a_copy)
:
  // For BoxedType wrappers, make_a_copy is true by default.  The static
  // BoxedType wrappers must always take a copy, thus make_a_copy = true
  // ensures identical behaviour if the default argument is used.
  gobject_ (make_a_copy && gobject ? g_checksum_copy(gobject) : gobject)
{}

auto Checksum::operator=(const Checksum& other) -> Checksum&
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

auto Checksum::swap (Checksum &other) noexcept -> void
{
  std::swap(gobject_, other.gobject_);
}

auto Checksum::gobj_copy() const -> GChecksum*
{
  return g_checksum_copy(gobject_);
}


auto Checksum::reset () -> void
{
  g_checksum_reset(gobj());
}

auto Checksum::update (const guchar *data, const gssize length) -> void
{
  g_checksum_update(gobj(), data, length);
}

auto Checksum::get_digest (guint8 *buffer, gsize *digest_len) const -> void
{
  g_checksum_get_digest(const_cast<GChecksum*>(gobj()), buffer, digest_len);
}

auto Checksum::get_string() const -> std::string
{
  return convert_const_gchar_ptr_to_stdstring(g_checksum_get_string(const_cast<GChecksum*>(gobj())));
}

auto Checksum::compute_checksum(Type checksum_type, const guchar* data, const gsize length) -> std::string
{
  return convert_return_gchar_ptr_to_stdstring(g_compute_checksum_for_data(static_cast<GChecksumType>(checksum_type), data, length));
}


} // namespace Glib


