/* Copyright 1998-2002 The gtkmm Development Team
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
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 */

#include <mm/glib/utility.hpp>
#include <mm/gtk/accelerator.hpp>
#include <gtk/gtk.h>

// The corresponding gtk functions are defined in gtkaccelgroup.c.

namespace Gtk::Accelerator
{

auto valid(
  const guint keyval, Gdk::ModifierType modifiers) -> bool
{
  return gtk_accelerator_valid(keyval, (GdkModifierType) modifiers);
}

auto parse(const Glib::ustring& accelerator,
           guint&               accelerator_key,
           Gdk::ModifierType&   accelerator_mods) -> bool
{
  auto mods = GdkModifierType(0);
  const auto result = gtk_accelerator_parse(accelerator.c_str(), &accelerator_key, &mods);

  accelerator_mods = static_cast<Gdk::ModifierType>(mods);
  return result;
}

auto name(
  const guint accelerator_key, Gdk::ModifierType accelerator_mods) -> Glib::ustring
{
  return Glib::convert_return_gchar_ptr_to_ustring(gtk_accelerator_name(
    accelerator_key, static_cast<GdkModifierType>(accelerator_mods)));
}

auto get_label(
  const guint accelerator_key, Gdk::ModifierType accelerator_mods) -> Glib::ustring
{
  return Glib::convert_return_gchar_ptr_to_ustring(gtk_accelerator_get_label(
    accelerator_key, static_cast<GdkModifierType>(accelerator_mods)));
}

auto get_default_mod_mask() -> Gdk::ModifierType
{
  return static_cast<Gdk::ModifierType>(gtk_accelerator_get_default_mod_mask());
}

} // namespace Gtk
