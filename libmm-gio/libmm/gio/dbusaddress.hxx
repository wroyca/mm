// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GIOMM_DBUSADDRESS_H
#define _GIOMM_DBUSADDRESS_H

#include <libmm/glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm/gio/dbusconnection.hxx>

namespace Gio::DBus::Address
{

  LIBMM_GIO_SYMEXPORT
  auto
  is_address (const std::string& string) -> bool;

  LIBMM_GIO_SYMEXPORT
  auto
  is_supported (const std::string& address) -> bool;

  LIBMM_GIO_SYMEXPORT auto
  get_stream (const std::string& address,
              const SlotAsyncReady slot,
              const Glib::RefPtr<Cancellable>& cancellable) -> void;

  LIBMM_GIO_SYMEXPORT auto
  get_stream (const std::string& address, const SlotAsyncReady slot) -> void;

  LIBMM_GIO_SYMEXPORT
  auto
  get_stream_finish (const Glib::RefPtr<AsyncResult>& res,
                     std::string& out_guid) -> Glib::RefPtr<IOStream>;

  LIBMM_GIO_SYMEXPORT
  auto
  get_stream_finish (const Glib::RefPtr<AsyncResult>& res) -> Glib::RefPtr<IOStream>;

  LIBMM_GIO_SYMEXPORT
  auto
  get_stream_sync (const std::string& address,
                   const Glib::RefPtr<Cancellable>& cancellable,
                   std::string& out_guid) -> Glib::RefPtr<IOStream>;

  LIBMM_GIO_SYMEXPORT
  auto
  get_stream_sync (const std::string& address, std::string& out_guid) -> Glib::RefPtr<IOStream>;

  LIBMM_GIO_SYMEXPORT
  auto
  get_stream_sync (const std::string& address,
                   const Glib::RefPtr<Cancellable>& cancellable) -> Glib::RefPtr<IOStream>;

  LIBMM_GIO_SYMEXPORT
  auto
  get_stream_sync (const std::string& address) -> Glib::RefPtr<IOStream>;

  LIBMM_GIO_SYMEXPORT
  auto
  get_for_bus_sync (BusType bus_type,
                    const Glib::RefPtr<Cancellable>& cancellable) -> std::string;

  LIBMM_GIO_SYMEXPORT
  auto
  get_for_bus_sync (BusType bus_type) -> std::string;

} // namespace Gio::DBus::Address

#endif