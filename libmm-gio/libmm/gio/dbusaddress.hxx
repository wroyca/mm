// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GIOMM_DBUSADDRESS_H
#define _GIOMM_DBUSADDRESS_H

#include <libmm/glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm/gio/dbusconnection.hxx>

namespace gio::DBus::Address
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
              const glib::RefPtr<Cancellable>& cancellable) -> void;

  LIBMM_GIO_SYMEXPORT auto
  get_stream (const std::string& address, const SlotAsyncReady slot) -> void;

  LIBMM_GIO_SYMEXPORT
  auto
  get_stream_finish (const glib::RefPtr<AsyncResult>& res,
                     std::string& out_guid) -> glib::RefPtr<IOStream>;

  LIBMM_GIO_SYMEXPORT
  auto
  get_stream_finish (const glib::RefPtr<AsyncResult>& res) -> glib::RefPtr<IOStream>;

  LIBMM_GIO_SYMEXPORT
  auto
  get_stream_sync (const std::string& address,
                   const glib::RefPtr<Cancellable>& cancellable,
                   std::string& out_guid) -> glib::RefPtr<IOStream>;

  LIBMM_GIO_SYMEXPORT
  auto
  get_stream_sync (const std::string& address, std::string& out_guid) -> glib::RefPtr<IOStream>;

  LIBMM_GIO_SYMEXPORT
  auto
  get_stream_sync (const std::string& address,
                   const glib::RefPtr<Cancellable>& cancellable) -> glib::RefPtr<IOStream>;

  LIBMM_GIO_SYMEXPORT
  auto
  get_stream_sync (const std::string& address) -> glib::RefPtr<IOStream>;

  LIBMM_GIO_SYMEXPORT
  auto
  get_for_bus_sync (BusType bus_type,
                    const glib::RefPtr<Cancellable>& cancellable) -> std::string;

  LIBMM_GIO_SYMEXPORT
  auto
  get_for_bus_sync (BusType bus_type) -> std::string;

} // namespace gio::DBus::Address

#endif
