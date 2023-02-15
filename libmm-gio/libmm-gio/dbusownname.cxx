// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm-glib/mm-glib.hxx>

#include <libmm-gio/dbusownname.hxx>
#include <libmm-gio/dbusownname_p.hxx>

#include <gio/gio.h>
#include <libmm-glib/exceptionhandler.hxx>

namespace
{

  struct OwnSlots
  {
    Gio::DBus::SlotBusAcquired* bus_acquired_slot;
    Gio::DBus::SlotNameAcquired* name_acquired_slot;
    Gio::DBus::SlotNameLost* name_lost_slot;
  };

  extern "C"
  {
    static auto
    Bus_Acquired_giomm_callback (GDBusConnection* connection,
                                 const gchar* name,
                                 const gpointer data) -> void
    {
      const auto slots = static_cast<OwnSlots*> (data);
      const auto the_slot = slots->bus_acquired_slot;

      try
      {
        (*the_slot) (Glib::wrap (connection, true),
                     Glib::convert_const_gchar_ptr_to_ustring (name));
      }
      catch (...)
      {
        Glib::exception_handlers_invoke ();
      }
    }

    static auto
    Bus_Name_Acquired_giomm_callback (GDBusConnection* connection,
                                      const gchar* name,
                                      const gpointer data) -> void
    {
      const auto slots = static_cast<OwnSlots*> (data);
      const auto the_slot = slots->name_acquired_slot;

      try
      {
        (*the_slot) (Glib::wrap (connection, true),
                     Glib::convert_const_gchar_ptr_to_ustring (name));
      }
      catch (...)
      {
        Glib::exception_handlers_invoke ();
      }
    }

    static auto
    Bus_Name_Lost_giomm_callback (GDBusConnection* connection,
                                  const gchar* name,
                                  const gpointer data) -> void
    {
      const auto slots = static_cast<OwnSlots*> (data);
      const auto the_slot = slots->name_lost_slot;

      try
      {
        (*the_slot) (Glib::wrap (connection, true),
                     Glib::convert_const_gchar_ptr_to_ustring (name));
      }
      catch (...)
      {
        Glib::exception_handlers_invoke ();
      }
    }

    static auto
    Bus_Own_Name_giomm_callback_destroy (void* data) -> void
    {
      const auto slots = static_cast<OwnSlots*> (data);

      if (slots->bus_acquired_slot)
        delete slots->bus_acquired_slot;

      if (slots->name_acquired_slot)
        delete slots->name_acquired_slot;

      if (slots->name_lost_slot)
        delete slots->name_lost_slot;

      delete slots;
    }
  }

} // namespace

namespace Gio::DBus
{

  auto
  own_name (BusType bus_type,
            const Glib::ustring& name,
            const SlotBusAcquired& bus_acquired_slot,
            const SlotNameAcquired& name_acquired_slot,
            const SlotNameLost& name_lost_slot,
            BusNameOwnerFlags flags) -> guint
  {
    const auto slots = new OwnSlots;

    slots->bus_acquired_slot = new SlotBusAcquired (bus_acquired_slot);
    slots->name_acquired_slot = new SlotNameAcquired (name_acquired_slot);
    slots->name_lost_slot = new SlotNameLost (name_lost_slot);

    return g_bus_own_name (static_cast<GBusType> (bus_type),
                           name.c_str (),
                           static_cast<GBusNameOwnerFlags> (flags),
                           &Bus_Acquired_giomm_callback,
                           &Bus_Name_Acquired_giomm_callback,
                           &Bus_Name_Lost_giomm_callback,
                           slots,
                           &Bus_Own_Name_giomm_callback_destroy);
  }

  auto
  unown_name (const guint owner_id) -> void
  {
    g_bus_unown_name (owner_id);
  }

} // namespace Gio::DBus

namespace
{
}

auto
Glib::Value<Gio::DBus::BusNameOwnerFlags>::value_type () -> GType
{
  return g_bus_name_owner_flags_get_type ();
}
