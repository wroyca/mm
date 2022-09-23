// Generated by gmmproc 2.74.0 -- DO NOT MODIFY!


#include <glibmm.h>

#include <giomm/dbusaddress.h>
#include <giomm/private/dbusaddress_p.h>


/* Copyright (C) 2010 The giomm Development Team
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
#include <glibmm/error.h>
#include <giomm/slot_async.h>

namespace Gio
{

namespace DBus
{

namespace Address
{

bool
is_address(const std::string& string)
{
  return static_cast<bool>(g_dbus_is_address(string.c_str()));
}

bool
is_supported(const std::string& address)
{
  GError* gerror = nullptr;
  bool const result = g_dbus_is_supported_address(address.c_str(), &gerror);
  if (gerror)
    ::Glib::Error::throw_exception(gerror);
  return result;
}

void
get_stream(const std::string& address, const SlotAsyncReady slot,
  const Glib::RefPtr<Cancellable>& cancellable)
{
  auto slot_copy = new SlotAsyncReady(slot);
  g_dbus_address_get_stream(
    address.c_str(), Glib::unwrap(cancellable), &SignalProxy_async_callback, slot_copy);
}

void
get_stream(const std::string& address, const SlotAsyncReady slot)
{
  auto slot_copy = new SlotAsyncReady(slot);
  g_dbus_address_get_stream(address.c_str(), nullptr, &SignalProxy_async_callback, slot_copy);
}

Glib::RefPtr<IOStream>
get_stream_finish(const Glib::RefPtr<AsyncResult>& res, std::string& out_guid)
{
  GError* gerror = nullptr;
  gchar* g_out_guid = nullptr;

  auto result =
    Glib::wrap(g_dbus_address_get_stream_finish(Glib::unwrap(res), &g_out_guid, &gerror));

  if (gerror)
    ::Glib::Error::throw_exception(gerror);

  out_guid = g_out_guid;
  return result;
}

Glib::RefPtr<IOStream>
get_stream_finish(const Glib::RefPtr<AsyncResult>& res)
{
  GError* gerror = nullptr;

  auto result = Glib::wrap(g_dbus_address_get_stream_finish(Glib::unwrap(res), nullptr, &gerror));

  if (gerror)
    ::Glib::Error::throw_exception(gerror);

  return result;
}

Glib::RefPtr<IOStream>
get_stream_sync(
  const std::string& address, const Glib::RefPtr<Cancellable>& cancellable, std::string& out_guid)
{
  GError* gerror = nullptr;
  gchar* g_out_guid = nullptr;

  auto result = Glib::wrap(g_dbus_address_get_stream_sync(
    address.c_str(), &g_out_guid, Glib::unwrap(cancellable), &gerror));

  if (gerror)
    ::Glib::Error::throw_exception(gerror);

  out_guid = g_out_guid;
  return result;
}

Glib::RefPtr<IOStream>
get_stream_sync(const std::string& address, std::string& out_guid)
{
  GError* gerror = nullptr;
  gchar* g_out_guid = nullptr;

  auto result =
    Glib::wrap(g_dbus_address_get_stream_sync(address.c_str(), &g_out_guid, nullptr, &gerror));

  if (gerror)
    ::Glib::Error::throw_exception(gerror);

  out_guid = g_out_guid;
  return result;
}

Glib::RefPtr<IOStream>
get_stream_sync(const std::string& address, const Glib::RefPtr<Cancellable>& cancellable)
{
  GError* gerror = nullptr;

  auto result = Glib::wrap(
    g_dbus_address_get_stream_sync(address.c_str(), nullptr, Glib::unwrap(cancellable), &gerror));

  if (gerror)
    ::Glib::Error::throw_exception(gerror);

  return result;
}

Glib::RefPtr<IOStream>
get_stream_sync(const std::string& address)
{
  GError* gerror = nullptr;

  auto result =
    Glib::wrap(g_dbus_address_get_stream_sync(address.c_str(), nullptr, nullptr, &gerror));

  if (gerror)
    ::Glib::Error::throw_exception(gerror);

  return result;
}

std::string
get_for_bus_sync(BusType bus_type, const Glib::RefPtr<Cancellable>& cancellable)
{
  GError* gerror = nullptr;

  std::string result(g_dbus_address_get_for_bus_sync(
    static_cast<GBusType>(bus_type), Glib::unwrap(cancellable), &gerror));

  if (gerror)
    ::Glib::Error::throw_exception(gerror);

  return result;
}

std::string
get_for_bus_sync(BusType bus_type)
{
  GError* gerror = nullptr;

  std::string result(
    g_dbus_address_get_for_bus_sync(static_cast<GBusType>(bus_type), nullptr, &gerror));

  if (gerror)
    ::Glib::Error::throw_exception(gerror);

  return result;
}

} // namespace Address

} // namespace DBus

} // namespace Gio

namespace
{
} // anonymous namespace


