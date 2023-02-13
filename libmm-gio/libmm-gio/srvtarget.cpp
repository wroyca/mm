


#include <mm/glib/mm-glib.hpp>

#include <mm/gio/srvtarget.hpp>
#include <mm/gio/private/srvtarget_p.hpp>


/* Copyright (C) 2008 Jonathon Jongsma
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

#include <gio/gio.h>
#include <mm/glib/utility.hpp>

namespace Gio
{

} // namespace Gio

namespace
{
} // anonymous namespace


namespace Glib
{

auto wrap(GSrvTarget* object, const bool take_copy) -> Gio::SrvTarget
{
  return Gio::SrvTarget(object, take_copy);
}

} // namespace Glib


namespace Gio
{


// static
auto SrvTarget::get_type() -> GType
{
  return g_srv_target_get_type();
}

SrvTarget::SrvTarget()
:
  gobject_ (nullptr) // Allows creation of invalid wrapper, e.g. for output arguments to methods.
{}

SrvTarget::SrvTarget(const SrvTarget& other)
:
  gobject_ (other.gobject_ ? g_srv_target_copy(other.gobject_) : nullptr)
{}

SrvTarget::SrvTarget(SrvTarget&& other) noexcept
:
  gobject_(other.gobject_)
{
  other.gobject_ = nullptr;
}

auto SrvTarget::operator=(SrvTarget&& other) noexcept -> SrvTarget&
{
  SrvTarget temp (std::move(other));
  swap(temp);
  return *this;
}

SrvTarget::SrvTarget(GSrvTarget* gobject, const bool make_a_copy)
:
  // For BoxedType wrappers, make_a_copy is true by default.  The static
  // BoxedType wrappers must always take a copy, thus make_a_copy = true
  // ensures identical behaviour if the default argument is used.
  gobject_ (make_a_copy && gobject ? g_srv_target_copy(gobject) : gobject)
{}

auto SrvTarget::operator=(const SrvTarget& other) -> SrvTarget&
{
  SrvTarget temp (other);
  swap(temp);
  return *this;
}

SrvTarget::~SrvTarget() noexcept
{
  if(gobject_)
    g_srv_target_free(gobject_);
}

auto SrvTarget::swap (SrvTarget &other) noexcept -> void
{
  std::swap(gobject_, other.gobject_);
}

auto SrvTarget::gobj_copy() const -> GSrvTarget*
{
  return g_srv_target_copy(gobject_);
}


auto SrvTarget::get_hostname() const -> Glib::ustring
{
  return Glib::convert_const_gchar_ptr_to_ustring(g_srv_target_get_hostname(const_cast<GSrvTarget*>(gobj())));
}

auto SrvTarget::get_port() const -> guint16
{
  return g_srv_target_get_port(const_cast<GSrvTarget*>(gobj()));
}

auto SrvTarget::get_priority() const -> guint16
{
  return g_srv_target_get_priority(const_cast<GSrvTarget*>(gobj()));
}

auto SrvTarget::get_weight() const -> guint16
{
  return g_srv_target_get_weight(const_cast<GSrvTarget*>(gobj()));
}


} // namespace Gio


