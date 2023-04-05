// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/gio/dbusaddress.hxx>
#include <libmm/gio/dbusaddress_p.hxx>

#include <gio/gio.h>
#include <libmm/gio/slot_async.hxx>
#include <libmm/glib/error.hxx>

namespace gio::DBus::Address
{

  auto
  is_address (const std::string& string) -> bool
  {
    return static_cast<bool> (g_dbus_is_address (string.c_str ()));
  }

  auto
  is_supported (const std::string& address) -> bool
  {
    GError* gerror = nullptr;
    const bool result = g_dbus_is_supported_address (address.c_str (), &gerror);
    if (gerror)
      glib::Error::throw_exception (gerror);
    return result;
  }

  auto
  get_stream (const std::string& address,
              const SlotAsyncReady slot,
              const glib::RefPtr<Cancellable>& cancellable) -> void
  {
    const auto slot_copy = new SlotAsyncReady (slot);
    g_dbus_address_get_stream (address.c_str (),
                               glib::unwrap (cancellable),
                               &SignalProxy_async_callback,
                               slot_copy);
  }

  auto
  get_stream (const std::string& address, const SlotAsyncReady slot) -> void
  {
    const auto slot_copy = new SlotAsyncReady (slot);
    g_dbus_address_get_stream (address.c_str (),
                               nullptr,
                               &SignalProxy_async_callback,
                               slot_copy);
  }

  auto
  get_stream_finish (const glib::RefPtr<AsyncResult>& res,
                     std::string& out_guid) -> glib::RefPtr<IOStream>
  {
    GError* gerror = nullptr;
    gchar* g_out_guid = nullptr;

    auto result =
        glib::wrap (g_dbus_address_get_stream_finish (glib::unwrap (res),
                                                      &g_out_guid,
                                                      &gerror));

    if (gerror)
      glib::Error::throw_exception (gerror);

    out_guid = g_out_guid;
    return result;
  }

  auto
  get_stream_finish (const glib::RefPtr<AsyncResult>& res) -> glib::RefPtr<IOStream>
  {
    GError* gerror = nullptr;

    auto result =
        glib::wrap (g_dbus_address_get_stream_finish (glib::unwrap (res),
                                                      nullptr,
                                                      &gerror));

    if (gerror)
      glib::Error::throw_exception (gerror);

    return result;
  }

  auto
  get_stream_sync (const std::string& address,
                   const glib::RefPtr<Cancellable>& cancellable,
                   std::string& out_guid) -> glib::RefPtr<IOStream>
  {
    GError* gerror = nullptr;
    gchar* g_out_guid = nullptr;

    auto result =
        glib::wrap (g_dbus_address_get_stream_sync (address.c_str (),
                                                    &g_out_guid,
                                                    glib::unwrap (cancellable),
                                                    &gerror));

    if (gerror)
      glib::Error::throw_exception (gerror);

    out_guid = g_out_guid;
    return result;
  }

  auto
  get_stream_sync (const std::string& address, std::string& out_guid) -> glib::RefPtr<IOStream>
  {
    GError* gerror = nullptr;
    gchar* g_out_guid = nullptr;

    auto result = glib::wrap (g_dbus_address_get_stream_sync (address.c_str (),
                                                              &g_out_guid,
                                                              nullptr,
                                                              &gerror));

    if (gerror)
      glib::Error::throw_exception (gerror);

    out_guid = g_out_guid;
    return result;
  }

  auto
  get_stream_sync (const std::string& address,
                   const glib::RefPtr<Cancellable>& cancellable) -> glib::RefPtr<IOStream>
  {
    GError* gerror = nullptr;

    auto result =
        glib::wrap (g_dbus_address_get_stream_sync (address.c_str (),
                                                    nullptr,
                                                    glib::unwrap (cancellable),
                                                    &gerror));

    if (gerror)
      glib::Error::throw_exception (gerror);

    return result;
  }

  auto
  get_stream_sync (const std::string& address) -> glib::RefPtr<IOStream>
  {
    GError* gerror = nullptr;

    auto result = glib::wrap (g_dbus_address_get_stream_sync (address.c_str (),
                                                              nullptr,
                                                              nullptr,
                                                              &gerror));

    if (gerror)
      glib::Error::throw_exception (gerror);

    return result;
  }

  auto
  get_for_bus_sync (BusType bus_type,
                    const glib::RefPtr<Cancellable>& cancellable) -> std::string
  {
    GError* gerror = nullptr;

    std::string result (
        g_dbus_address_get_for_bus_sync (static_cast<GBusType> (bus_type),
                                         glib::unwrap (cancellable),
                                         &gerror));

    if (gerror)
      glib::Error::throw_exception (gerror);

    return result;
  }

  auto
  get_for_bus_sync (BusType bus_type) -> std::string
  {
    GError* gerror = nullptr;

    std::string result (
        g_dbus_address_get_for_bus_sync (static_cast<GBusType> (bus_type),
                                         nullptr,
                                         &gerror));

    if (gerror)
      glib::Error::throw_exception (gerror);

    return result;
  }

} // namespace gio::DBus::Address

namespace
{
}
