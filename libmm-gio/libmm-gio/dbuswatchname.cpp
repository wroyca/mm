


#include <mm/glib/mm-glib.hpp>

#include <mm/gio/dbuswatchname.hpp>
#include <mm/gio/private/dbuswatchname_p.hpp>


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

#include <mm/glib/exceptionhandler.hpp>
#include <gio/gio.h>

namespace
{

// Structure to hold the slots registred with watch_name().
struct WatchSlots
{
  Gio::DBus::SlotNameAppeared* name_appeared_slot;
  Gio::DBus::SlotNameVanished* name_vanished_slot;
};

extern "C" {

static auto Bus_Name_Appeared_giomm_callback (
  GDBusConnection *connection, const gchar *name, const char *name_owner, const gpointer data) -> void
{
  const auto slots = static_cast<WatchSlots*>(data);
  const auto the_slot = slots->name_appeared_slot;

  try
  {
    (*the_slot)(Glib::wrap(connection, true), Glib::convert_const_gchar_ptr_to_ustring(name),
      Glib::convert_const_gchar_ptr_to_ustring(name_owner));
  }
  catch (...)
  {
    Glib::exception_handlers_invoke();
  }
}

static auto Bus_Name_Vanished_giomm_callback (
  GDBusConnection *connection, const gchar *name, const gpointer data) -> void
{
  const auto slots = static_cast<WatchSlots*>(data);
  const auto the_slot = slots->name_vanished_slot;

  try
  {
    (*the_slot)(Glib::wrap(connection, true), Glib::convert_const_gchar_ptr_to_ustring(name));
  }
  catch (...)
  {
    Glib::exception_handlers_invoke();
  }
}

static auto Bus_Watch_Name_giomm_callback_destroy (void *data) -> void
{
  const auto slots = static_cast<WatchSlots*>(data);

  if (slots->name_appeared_slot)
    delete slots->name_appeared_slot;

  if (slots->name_vanished_slot)
    delete slots->name_vanished_slot;

  delete slots;
}

} // extern "C"

} // anonymous namespace

namespace Gio::DBus
{

auto
watch_name(BusType bus_type, const Glib::ustring& name, const SlotNameAppeared& name_appeared_slot,
  const SlotNameVanished& name_vanished_slot, BusNameWatcherFlags flags) -> guint
{
  const auto slots = new WatchSlots;

  // Make copies of the slots which will be deleted on destroy notification.
  slots->name_appeared_slot = new SlotNameAppeared(name_appeared_slot);
  slots->name_vanished_slot = new SlotNameVanished(name_vanished_slot);

  return g_bus_watch_name(static_cast<GBusType>(bus_type), name.c_str(),
    static_cast<GBusNameWatcherFlags>(flags), &Bus_Name_Appeared_giomm_callback,
    &Bus_Name_Vanished_giomm_callback, slots, &Bus_Watch_Name_giomm_callback_destroy);
}

auto
watch_name(const Glib::RefPtr<Connection>& connection, const Glib::ustring& name,
  const SlotNameAppeared& name_appeared_slot, const SlotNameVanished& name_vanished_slot,
  BusNameWatcherFlags flags) -> guint
{
  const auto slots = new WatchSlots;

  // Make copies of the slots which will be deleted on destroy notification.
  slots->name_appeared_slot = new SlotNameAppeared(name_appeared_slot);
  slots->name_vanished_slot = new SlotNameVanished(name_vanished_slot);

  return g_bus_watch_name_on_connection(Glib::unwrap(connection), name.c_str(),
    static_cast<GBusNameWatcherFlags>(flags), &Bus_Name_Appeared_giomm_callback,
    &Bus_Name_Vanished_giomm_callback, slots, &Bus_Watch_Name_giomm_callback_destroy);
}

auto unwatch_name (
  const guint watcher_id) -> void
{
  g_bus_unwatch_name(watcher_id);
}

} // namespace Gio

namespace
{
} // anonymous namespace


