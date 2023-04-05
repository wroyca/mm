// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GIOMM_DBUSWATCHNAME_H
#define _GIOMM_DBUSWATCHNAME_H

#include <libmm/glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm/gio/dbusconnection.hxx>

namespace gio::DBus
{

  enum class BusNameWatcherFlags
  {
    NONE = 0x0,
    AUTO_START = (1 << 0)
  };

  inline auto
  operator| (BusNameWatcherFlags lhs, BusNameWatcherFlags rhs) -> BusNameWatcherFlags
  {
    return static_cast<BusNameWatcherFlags> (static_cast<unsigned> (lhs) |
                                             static_cast<unsigned> (rhs));
  }

  inline auto
  operator& (BusNameWatcherFlags lhs, BusNameWatcherFlags rhs) -> BusNameWatcherFlags
  {
    return static_cast<BusNameWatcherFlags> (static_cast<unsigned> (lhs) &
                                             static_cast<unsigned> (rhs));
  }

  inline auto
  operator^ (BusNameWatcherFlags lhs, BusNameWatcherFlags rhs) -> BusNameWatcherFlags
  {
    return static_cast<BusNameWatcherFlags> (static_cast<unsigned> (lhs) ^
                                             static_cast<unsigned> (rhs));
  }

  inline auto
  operator~(BusNameWatcherFlags flags) -> BusNameWatcherFlags
  {
    return static_cast<BusNameWatcherFlags> (~static_cast<unsigned> (flags));
  }

  inline auto
  operator|= (BusNameWatcherFlags& lhs, BusNameWatcherFlags rhs) -> BusNameWatcherFlags&
  {
    return (lhs = static_cast<BusNameWatcherFlags> (
                static_cast<unsigned> (lhs) | static_cast<unsigned> (rhs)));
  }

  inline auto
  operator&= (BusNameWatcherFlags& lhs, BusNameWatcherFlags rhs) -> BusNameWatcherFlags&
  {
    return (lhs = static_cast<BusNameWatcherFlags> (
                static_cast<unsigned> (lhs) & static_cast<unsigned> (rhs)));
  }

  inline auto
  operator^= (BusNameWatcherFlags& lhs, BusNameWatcherFlags rhs) -> BusNameWatcherFlags&
  {
    return (lhs = static_cast<BusNameWatcherFlags> (
                static_cast<unsigned> (lhs) ^ static_cast<unsigned> (rhs)));
  }

  using SlotNameAppeared =
      sigc::slot<void (const glib::RefPtr<gio::DBus::Connection>&,
                       glib::ustring,
                       const glib::ustring&)>;

  using SlotNameVanished =
      sigc::slot<void (const glib::RefPtr<gio::DBus::Connection>&,
                       glib::ustring)>;

  LIBMM_GIO_SYMEXPORT
  auto
  watch_name (BusType bus_type,
              const glib::ustring& name,
              const SlotNameAppeared& name_appeared_slot = {},
              const SlotNameVanished& name_vanished_slot = {},
              BusNameWatcherFlags flags = gio::DBus::BusNameWatcherFlags::NONE) -> guint;

  LIBMM_GIO_SYMEXPORT
  auto
  watch_name (const glib::RefPtr<Connection>& connection,
              const glib::ustring& name,
              const SlotNameAppeared& name_appeared_slot = {},
              const SlotNameVanished& name_vanished_slot = {},
              BusNameWatcherFlags flags = gio::DBus::BusNameWatcherFlags::NONE) -> guint;

  LIBMM_GIO_SYMEXPORT auto
  unwatch_name (guint watcher_id) -> void;

} // namespace gio::DBus

#endif
