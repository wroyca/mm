


#include <libmm-glib/mm-glib.hxx>

#include <libmm-gio/dbusownname.hxx>
#include <libmm-gio/dbusownname_p.hxx>


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
#include <libmm-glib/exceptionhandler.hxx>

namespace
{

// Structure to hold the slots registred with own_name().
struct OwnSlots
{
  Gio::DBus::SlotBusAcquired* bus_acquired_slot;
  Gio::DBus::SlotNameAcquired* name_acquired_slot;
  Gio::DBus::SlotNameLost* name_lost_slot;
};

extern "C" {

static auto Bus_Acquired_giomm_callback (
  GDBusConnection *connection, const gchar *name, const gpointer data) -> void
{
  const auto slots = static_cast<OwnSlots*>(data);
  const auto the_slot = slots->bus_acquired_slot;

  try
  {
    (*the_slot)(Glib::wrap(connection, true), Glib::convert_const_gchar_ptr_to_ustring(name));
  }
  catch (...)
  {
    Glib::exception_handlers_invoke();
  }
}

static auto Bus_Name_Acquired_giomm_callback (
  GDBusConnection *connection, const gchar *name, const gpointer data) -> void
{
  const auto slots = static_cast<OwnSlots*>(data);
  const auto the_slot = slots->name_acquired_slot;

  try
  {
    (*the_slot)(Glib::wrap(connection, true), Glib::convert_const_gchar_ptr_to_ustring(name));
  }
  catch (...)
  {
    Glib::exception_handlers_invoke();
  }
}

static auto Bus_Name_Lost_giomm_callback (
  GDBusConnection *connection, const gchar *name, const gpointer data) -> void
{
  const auto slots = static_cast<OwnSlots*>(data);
  const auto the_slot = slots->name_lost_slot;

  try
  {
    (*the_slot)(Glib::wrap(connection, true), Glib::convert_const_gchar_ptr_to_ustring(name));
  }
  catch (...)
  {
    Glib::exception_handlers_invoke();
  }
}

static auto Bus_Own_Name_giomm_callback_destroy (void *data) -> void
{
  const auto slots = static_cast<OwnSlots*>(data);

  if (slots->bus_acquired_slot)
    delete slots->bus_acquired_slot;

  if (slots->name_acquired_slot)
    delete slots->name_acquired_slot;

  if (slots->name_lost_slot)
    delete slots->name_lost_slot;

  delete slots;
}

} // extern "C"

} // anonymous namespace

namespace Gio::DBus
{

auto
own_name(BusType bus_type, const Glib::ustring& name, const SlotBusAcquired& bus_acquired_slot,
  const SlotNameAcquired& name_acquired_slot, const SlotNameLost& name_lost_slot,
  BusNameOwnerFlags flags) -> guint
{
  const auto slots = new OwnSlots;

  // Make copies of the slots which will be deleted on destroy notification.
  slots->bus_acquired_slot = new SlotBusAcquired(bus_acquired_slot);
  slots->name_acquired_slot = new SlotNameAcquired(name_acquired_slot);
  slots->name_lost_slot = new SlotNameLost(name_lost_slot);

  return g_bus_own_name(static_cast<GBusType>(bus_type), name.c_str(),
    static_cast<GBusNameOwnerFlags>(flags), &Bus_Acquired_giomm_callback,
    &Bus_Name_Acquired_giomm_callback, &Bus_Name_Lost_giomm_callback, slots,
    &Bus_Own_Name_giomm_callback_destroy);
}

auto unown_name (
  const guint owner_id) -> void
{
  g_bus_unown_name(owner_id);
}

} // namespace Gio

namespace
{
} // anonymous namespace

// static
auto Glib::Value<Gio::DBus::BusNameOwnerFlags>::value_type() -> GType
{
  return g_bus_name_owner_flags_get_type();
}

