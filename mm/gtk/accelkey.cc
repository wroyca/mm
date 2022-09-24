/*
 * Copyright 1998-2002 The gtkmm Development Team
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

#include <mm/gtk/accelkey.h>
#include <mm/gtk/accelerator.h>

namespace Gtk
{

AccelKey::AccelKey()
: key_(GDK_KEY_VoidSymbol),
  mod_((Gdk::ModifierType)0)
{
}

AccelKey::AccelKey(guint accel_key, Gdk::ModifierType accel_mods,
                   const Glib::ustring& accel_path)
: key_(accel_key),
  mod_(accel_mods),
  path_(accel_path)
{
}

AccelKey::AccelKey(const Glib::ustring& accelerator, const Glib::ustring& accel_path)
: path_(accel_path)
{
  //Get the key and mod by parsing the accelerator string:
  Accelerator::parse (accelerator, key_, mod_);
}

AccelKey::AccelKey(const AccelKey& src)
{
  key_ = src.key_;
  mod_ = src.mod_;
  path_ = src.path_;
}

auto AccelKey::operator=(const AccelKey& src) -> AccelKey&
{
  key_ = src.key_;
  mod_ = src.mod_;
  path_ = src.path_;

  return *this;
}

auto AccelKey::get_key() const -> guint
{
  return key_;
}

auto AccelKey::get_mod() const -> Gdk::ModifierType
{
  return mod_;
}

auto AccelKey::get_path() const -> Glib::ustring
{
  return path_;
}

auto AccelKey::is_null() const -> bool
{
  return ( (key_ == GDK_KEY_VoidSymbol) || !(get_key() > 0) ); //both seem to be invalid.
}

auto AccelKey::get_abbrev() const -> Glib::ustring
{
  return Accelerator::name(key_, mod_);
}

} // namespace Gtk
