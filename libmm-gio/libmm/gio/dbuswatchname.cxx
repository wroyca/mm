// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/gio/dbuswatchname.hxx>
#include <libmm/gio/dbuswatchname_p.hxx>

#include <gio/gio.h>
#include <libmm/glib/exceptionhandler.hxx>

namespace
{

  struct WatchSlots
  {
    gio::DBus::SlotNameAppeared* name_appeared_slot;
    gio::DBus::SlotNameVanished* name_vanished_slot;
  };

  extern "C"
  {
    static auto
    Bus_Name_Appeared_giomm_callback (GDBusConnection* connection,
                                      const gchar* name,
                                      const char* name_owner,
                                      const gpointer data) -> void
    {
      const auto slots = static_cast<WatchSlots*> (data);
      const auto the_slot = slots->name_appeared_slot;

      try
      {
        (*the_slot) (glib::wrap (connection, true),
                     glib::convert_const_gchar_ptr_to_ustring (name),
                     glib::convert_const_gchar_ptr_to_ustring (name_owner));
      }
      catch (...)
      {
        glib::exception_handlers_invoke ();
      }
    }

    static auto
    Bus_Name_Vanished_giomm_callback (GDBusConnection* connection,
                                      const gchar* name,
                                      const gpointer data) -> void
    {
      const auto slots = static_cast<WatchSlots*> (data);
      const auto the_slot = slots->name_vanished_slot;

      try
      {
        (*the_slot) (glib::wrap (connection, true),
                     glib::convert_const_gchar_ptr_to_ustring (name));
      }
      catch (...)
      {
        glib::exception_handlers_invoke ();
      }
    }

    static auto
    Bus_Watch_Name_giomm_callback_destroy (void* data) -> void
    {
      const auto slots = static_cast<WatchSlots*> (data);

      if (slots->name_appeared_slot)
        delete slots->name_appeared_slot;

      if (slots->name_vanished_slot)
        delete slots->name_vanished_slot;

      delete slots;
    }
  }

} // namespace

namespace gio::DBus
{

  auto
  watch_name (BusType bus_type,
              const glib::ustring& name,
              const SlotNameAppeared& name_appeared_slot,
              const SlotNameVanished& name_vanished_slot,
              BusNameWatcherFlags flags) -> guint
  {
    const auto slots = new WatchSlots;

    slots->name_appeared_slot = new SlotNameAppeared (name_appeared_slot);
    slots->name_vanished_slot = new SlotNameVanished (name_vanished_slot);

    return g_bus_watch_name (static_cast<GBusType> (bus_type),
                             name.c_str (),
                             static_cast<GBusNameWatcherFlags> (flags),
                             &Bus_Name_Appeared_giomm_callback,
                             &Bus_Name_Vanished_giomm_callback,
                             slots,
                             &Bus_Watch_Name_giomm_callback_destroy);
  }

  auto
  watch_name (const glib::RefPtr<Connection>& connection,
              const glib::ustring& name,
              const SlotNameAppeared& name_appeared_slot,
              const SlotNameVanished& name_vanished_slot,
              BusNameWatcherFlags flags) -> guint
  {
    const auto slots = new WatchSlots;

    slots->name_appeared_slot = new SlotNameAppeared (name_appeared_slot);
    slots->name_vanished_slot = new SlotNameVanished (name_vanished_slot);

    return g_bus_watch_name_on_connection (
        glib::unwrap (connection),
        name.c_str (),
        static_cast<GBusNameWatcherFlags> (flags),
        &Bus_Name_Appeared_giomm_callback,
        &Bus_Name_Vanished_giomm_callback,
        slots,
        &Bus_Watch_Name_giomm_callback_destroy);
  }

  auto
  unwatch_name (const guint watcher_id) -> void
  {
    g_bus_unwatch_name (watcher_id);
  }

} // namespace gio::DBus

namespace
{
}
