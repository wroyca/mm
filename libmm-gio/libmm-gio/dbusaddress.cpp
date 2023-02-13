


#include <mm/glib/mm-glib.hpp>

#include <mm/gio/dbusaddress.hpp>
#include <mm/gio/private/dbusaddress_p.hpp>


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
#include <mm/glib/error.hpp>
#include <mm/gio/slot_async.hpp>

namespace Gio::DBus::Address
{

auto
is_address(const std::string& string) -> bool
{
  return static_cast<bool>(g_dbus_is_address(string.c_str()));
}

auto
is_supported(const std::string& address) -> bool
{
  GError* gerror = nullptr;
  bool const result = g_dbus_is_supported_address(address.c_str(), &gerror);
  if (gerror)
    Glib::Error::throw_exception(gerror);
  return result;
}

auto get_stream (
  const std::string &address, const SlotAsyncReady slot,
  const Glib::RefPtr <Cancellable> &cancellable) -> void
{
  const auto slot_copy = new SlotAsyncReady(slot);
  g_dbus_address_get_stream(
    address.c_str(), Glib::unwrap(cancellable), &SignalProxy_async_callback, slot_copy);
}

auto get_stream (const std::string &address, const SlotAsyncReady slot) -> void
{
  const auto slot_copy = new SlotAsyncReady(slot);
  g_dbus_address_get_stream(address.c_str(), nullptr, &SignalProxy_async_callback, slot_copy);
}

auto
get_stream_finish(const Glib::RefPtr<AsyncResult>& res, std::string& out_guid) -> Glib::RefPtr<IOStream>
{
  GError* gerror = nullptr;
  gchar* g_out_guid = nullptr;

  auto result =
    Glib::wrap(g_dbus_address_get_stream_finish(Glib::unwrap(res), &g_out_guid, &gerror));

  if (gerror)
    Glib::Error::throw_exception(gerror);

  out_guid = g_out_guid;
  return result;
}

auto
get_stream_finish(const Glib::RefPtr<AsyncResult>& res) -> Glib::RefPtr<IOStream>
{
  GError* gerror = nullptr;

  auto result = Glib::wrap(g_dbus_address_get_stream_finish(Glib::unwrap(res), nullptr, &gerror));

  if (gerror)
    Glib::Error::throw_exception(gerror);

  return result;
}

auto
get_stream_sync(
  const std::string& address, const Glib::RefPtr<Cancellable>& cancellable, std::string& out_guid) -> Glib::RefPtr<IOStream>
{
  GError* gerror = nullptr;
  gchar* g_out_guid = nullptr;

  auto result = Glib::wrap(g_dbus_address_get_stream_sync(
    address.c_str(), &g_out_guid, Glib::unwrap(cancellable), &gerror));

  if (gerror)
    Glib::Error::throw_exception(gerror);

  out_guid = g_out_guid;
  return result;
}

auto
get_stream_sync(const std::string& address, std::string& out_guid) -> Glib::RefPtr<IOStream>
{
  GError* gerror = nullptr;
  gchar* g_out_guid = nullptr;

  auto result =
    Glib::wrap(g_dbus_address_get_stream_sync(address.c_str(), &g_out_guid, nullptr, &gerror));

  if (gerror)
    Glib::Error::throw_exception(gerror);

  out_guid = g_out_guid;
  return result;
}

auto
get_stream_sync(const std::string& address, const Glib::RefPtr<Cancellable>& cancellable) -> Glib::RefPtr<IOStream>
{
  GError* gerror = nullptr;

  auto result = Glib::wrap(
    g_dbus_address_get_stream_sync(address.c_str(), nullptr, Glib::unwrap(cancellable), &gerror));

  if (gerror)
    Glib::Error::throw_exception(gerror);

  return result;
}

auto
get_stream_sync(const std::string& address) -> Glib::RefPtr<IOStream>
{
  GError* gerror = nullptr;

  auto result =
    Glib::wrap(g_dbus_address_get_stream_sync(address.c_str(), nullptr, nullptr, &gerror));

  if (gerror)
    Glib::Error::throw_exception(gerror);

  return result;
}

auto
get_for_bus_sync(BusType bus_type, const Glib::RefPtr<Cancellable>& cancellable) -> std::string
{
  GError* gerror = nullptr;

  std::string result(g_dbus_address_get_for_bus_sync(
    static_cast<GBusType>(bus_type), Glib::unwrap(cancellable), &gerror));

  if (gerror)
    Glib::Error::throw_exception(gerror);

  return result;
}

auto
get_for_bus_sync(BusType bus_type) -> std::string
{
  GError* gerror = nullptr;

  std::string result(
    g_dbus_address_get_for_bus_sync(static_cast<GBusType>(bus_type), nullptr, &gerror));

  if (gerror)
    Glib::Error::throw_exception(gerror);

  return result;
}

} // namespace Gio

namespace
{
} // anonymous namespace


