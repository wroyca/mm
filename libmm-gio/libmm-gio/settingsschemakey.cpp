


#include <mm/glib/mm-glib.hpp>

#include <mm/gio/settingsschemakey.hpp>
#include <mm/gio/private/settingsschemakey_p.hpp>


/* Copyright (C) 2015 The giomm Development Team
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

namespace Gio
{

} // namespace Gio

namespace
{
} // anonymous namespace


/* Why reinterpret_cast<SettingsSchemaKey*>(gobject) is needed:
 *
 * A SettingsSchemaKey instance is in fact always a GSettingsSchemaKey instance.
 * Unfortunately, GSettingsSchemaKey cannot be a member of SettingsSchemaKey,
 * because it is an opaque struct.  Also, the C interface does not provide
 * any hooks to install a destroy notification handler, thus we cannot
 * wrap it dynamically either.
 *
 * The cast works because SettingsSchemaKey does not have any member data, and
 * it is impossible to derive from it.  This is ensured by using final on the
 * class and by using = delete on the default constructor.
 */

namespace Glib
{

auto wrap(GSettingsSchemaKey* object, const bool take_copy) -> RefPtr<Gio::SettingsSchemaKey>
{
  if(take_copy && object)
    g_settings_schema_key_ref(object);

  // See the comment at the top of this file, if you want to know why the cast works.
  return Glib::make_refptr_for_instance<Gio::SettingsSchemaKey>(reinterpret_cast<Gio::SettingsSchemaKey*>(object));
}

} // namespace Glib


namespace Gio
{

auto SettingsSchemaKey::reference () const -> void
{
  // See the comment at the top of this file, if you want to know why the cast works.
  g_settings_schema_key_ref(reinterpret_cast<GSettingsSchemaKey*>(const_cast<SettingsSchemaKey*>(this)));
}

auto SettingsSchemaKey::unreference () const -> void
{
  // See the comment at the top of this file, if you want to know why the cast works.
  g_settings_schema_key_unref(reinterpret_cast<GSettingsSchemaKey*>(const_cast<SettingsSchemaKey*>(this)));
}

auto SettingsSchemaKey::gobj() -> GSettingsSchemaKey*
{
  // See the comment at the top of this file, if you want to know why the cast works.
  return reinterpret_cast<GSettingsSchemaKey*>(this);
}

auto SettingsSchemaKey::gobj() const -> const GSettingsSchemaKey*
{
  // See the comment at the top of this file, if you want to know why the cast works.
  return reinterpret_cast<const GSettingsSchemaKey*>(this);
}

auto SettingsSchemaKey::gobj_copy() const -> GSettingsSchemaKey*
{
  // See the comment at the top of this file, if you want to know why the cast works.
  const auto gobject = reinterpret_cast<GSettingsSchemaKey*>(const_cast<SettingsSchemaKey*>(this));
  g_settings_schema_key_ref(gobject);
  return gobject;
}


auto SettingsSchemaKey::get_name() const -> Glib::ustring
{
  return Glib::convert_const_gchar_ptr_to_ustring(g_settings_schema_key_get_name(const_cast<GSettingsSchemaKey*>(gobj())));
}

auto SettingsSchemaKey::get_summary() const -> Glib::ustring
{
  return Glib::convert_const_gchar_ptr_to_ustring(g_settings_schema_key_get_summary(const_cast<GSettingsSchemaKey*>(gobj())));
}

auto SettingsSchemaKey::get_description() const -> Glib::ustring
{
  return Glib::convert_const_gchar_ptr_to_ustring(g_settings_schema_key_get_description(const_cast<GSettingsSchemaKey*>(gobj())));
}

auto SettingsSchemaKey::get_value_type() const -> Glib::VariantType
{
  return Glib::wrap(const_cast<GVariantType*>(g_settings_schema_key_get_value_type(const_cast<GSettingsSchemaKey*>(gobj()))), true);
}

auto SettingsSchemaKey::get_default_value() const -> Glib::VariantBase
{
  return Glib::wrap(g_settings_schema_key_get_default_value(const_cast<GSettingsSchemaKey*>(gobj())), false);
}

auto SettingsSchemaKey::get_range() const -> Glib::VariantBase
{
  return Glib::wrap(g_settings_schema_key_get_range(const_cast<GSettingsSchemaKey*>(gobj())), false);
}

auto SettingsSchemaKey::range_check(const Glib::VariantBase& value) const -> bool
{
  return g_settings_schema_key_range_check(const_cast<GSettingsSchemaKey*>(gobj()), const_cast<GVariant*>(value.gobj()));
}


} // namespace Gio


