
#ifndef _GIOMM_DBUSADDRESS_H
#define _GIOMM_DBUSADDRESS_H

#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm-gio/dbusconnection.hxx>

namespace Gio::DBus::Address
{

  GIOMM_API
  auto
  is_address (const std::string& string) -> bool;

  GIOMM_API
  auto
  is_supported (const std::string& address) -> bool;

  GIOMM_API
  void
  get_stream (const std::string& address,
              const SlotAsyncReady slot,
              const Glib::RefPtr<Cancellable>& cancellable);

  GIOMM_API
  void
  get_stream (const std::string& address, const SlotAsyncReady slot);

  GIOMM_API
  auto
  get_stream_finish (const Glib::RefPtr<AsyncResult>& res,
                     std::string& out_guid) -> Glib::RefPtr<IOStream>;

  GIOMM_API
  auto
  get_stream_finish (const Glib::RefPtr<AsyncResult>& res) -> Glib::RefPtr<IOStream>;

  GIOMM_API
  auto
  get_stream_sync (const std::string& address,
                   const Glib::RefPtr<Cancellable>& cancellable,
                   std::string& out_guid) -> Glib::RefPtr<IOStream>;

  GIOMM_API
  auto
  get_stream_sync (const std::string& address, std::string& out_guid) -> Glib::RefPtr<IOStream>;

  GIOMM_API
  auto
  get_stream_sync (const std::string& address,
                   const Glib::RefPtr<Cancellable>& cancellable) -> Glib::RefPtr<IOStream>;

  GIOMM_API
  auto
  get_stream_sync (const std::string& address) -> Glib::RefPtr<IOStream>;

  GIOMM_API
  auto
  get_for_bus_sync (BusType bus_type,
                    const Glib::RefPtr<Cancellable>& cancellable) -> std::string;

  GIOMM_API
  auto
  get_for_bus_sync (BusType bus_type) -> std::string;

} // namespace Gio::DBus::Address

#endif
