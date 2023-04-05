// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GIOMM_DBUSOWNNAME_H
#define _GIOMM_DBUSOWNNAME_H

#include <libmm/glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm/gio/dbusconnection.hxx>

namespace gio::DBus
{

  enum class BusNameOwnerFlags
  {
    NONE = 0x0,
    ALLOW_REPLACEMENT = (1 << 0),
    REPLACE = (1 << 1),
    DO_NOT_QUEUE = (1 << 2)
  };

  inline auto
  operator| (BusNameOwnerFlags lhs, BusNameOwnerFlags rhs) -> BusNameOwnerFlags
  {
    return static_cast<BusNameOwnerFlags> (static_cast<unsigned> (lhs) |
                                           static_cast<unsigned> (rhs));
  }

  inline auto
  operator& (BusNameOwnerFlags lhs, BusNameOwnerFlags rhs) -> BusNameOwnerFlags
  {
    return static_cast<BusNameOwnerFlags> (static_cast<unsigned> (lhs) &
                                           static_cast<unsigned> (rhs));
  }

  inline auto
  operator^ (BusNameOwnerFlags lhs, BusNameOwnerFlags rhs) -> BusNameOwnerFlags
  {
    return static_cast<BusNameOwnerFlags> (static_cast<unsigned> (lhs) ^
                                           static_cast<unsigned> (rhs));
  }

  inline auto
  operator~(BusNameOwnerFlags flags) -> BusNameOwnerFlags
  {
    return static_cast<BusNameOwnerFlags> (~static_cast<unsigned> (flags));
  }

  inline auto
  operator|= (BusNameOwnerFlags& lhs, BusNameOwnerFlags rhs) -> BusNameOwnerFlags&
  {
    return (lhs = static_cast<BusNameOwnerFlags> (static_cast<unsigned> (lhs) |
                                                  static_cast<unsigned> (rhs)));
  }

  inline auto
  operator&= (BusNameOwnerFlags& lhs, BusNameOwnerFlags rhs) -> BusNameOwnerFlags&
  {
    return (lhs = static_cast<BusNameOwnerFlags> (static_cast<unsigned> (lhs) &
                                                  static_cast<unsigned> (rhs)));
  }

  inline auto
  operator^= (BusNameOwnerFlags& lhs, BusNameOwnerFlags rhs) -> BusNameOwnerFlags&
  {
    return (lhs = static_cast<BusNameOwnerFlags> (static_cast<unsigned> (lhs) ^
                                                  static_cast<unsigned> (rhs)));
  }

} // namespace gio::DBus

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace glib
{

  template <>
  class LIBMM_GIO_SYMEXPORT Value<gio::DBus::BusNameOwnerFlags>
    : public glib::Value_Flags<gio::DBus::BusNameOwnerFlags>
  {
  public:
    static auto
    value_type () -> GType G_GNUC_CONST;
  };

} // namespace glib
#endif

namespace gio::DBus
{

  using SlotBusAcquired =
      sigc::slot<void (const glib::RefPtr<gio::DBus::Connection>&,
                       glib::ustring)>;

  using SlotNameAcquired =
      sigc::slot<void (const glib::RefPtr<gio::DBus::Connection>&,
                       glib::ustring)>;

  using SlotNameLost =
      sigc::slot<void (const glib::RefPtr<gio::DBus::Connection>&,
                       glib::ustring)>;

  LIBMM_GIO_SYMEXPORT
  auto
  own_name (BusType bus_type,
            const glib::ustring& name,
            const SlotBusAcquired& bus_acquired_slot = {},
            const SlotNameAcquired& name_acquired_slot = {},
            const SlotNameLost& name_lost_slot = {},
            BusNameOwnerFlags flags = gio::DBus::BusNameOwnerFlags::NONE) -> guint;

  LIBMM_GIO_SYMEXPORT auto
  unown_name (guint owner_id) -> void;

} // namespace gio::DBus

#endif
