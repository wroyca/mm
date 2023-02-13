


#include <mm/glib/mm-glib.hpp>

#include <mm/gio/settingsschemasource.hpp>
#include <mm/gio/private/settingsschemasource_p.hpp>


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

#include <mm/glib/vectorutils.hpp>

namespace Gio
{

auto
SettingsSchemaSource::list_schemas(
  const bool relocatable, const bool recursive) const -> std::vector<Glib::ustring>
{
  const auto gobject = const_cast<GSettingsSchemaSource*>(gobj());
  gchar** schemas{};

  if (relocatable)
    g_settings_schema_source_list_schemas(gobject, recursive, nullptr, &schemas);
  else
    g_settings_schema_source_list_schemas(gobject, recursive, &schemas, nullptr);

  return Glib::ArrayHandler<Glib::ustring>::array_to_vector(schemas, Glib::OWNERSHIP_DEEP);
}

} // namespace Gio

namespace
{
} // anonymous namespace


/* Why reinterpret_cast<SettingsSchemaSource*>(gobject) is needed:
 *
 * A SettingsSchemaSource instance is in fact always a GSettingsSchemaSource instance.
 * Unfortunately, GSettingsSchemaSource cannot be a member of SettingsSchemaSource,
 * because it is an opaque struct.  Also, the C interface does not provide
 * any hooks to install a destroy notification handler, thus we cannot
 * wrap it dynamically either.
 *
 * The cast works because SettingsSchemaSource does not have any member data, and
 * it is impossible to derive from it.  This is ensured by using final on the
 * class and by using = delete on the default constructor.
 */

namespace Glib
{

auto wrap(GSettingsSchemaSource* object, const bool take_copy) -> RefPtr<Gio::SettingsSchemaSource>
{
  if(take_copy && object)
    g_settings_schema_source_ref(object);

  // See the comment at the top of this file, if you want to know why the cast works.
  return Glib::make_refptr_for_instance<Gio::SettingsSchemaSource>(reinterpret_cast<Gio::SettingsSchemaSource*>(object));
}

} // namespace Glib


namespace Gio
{

auto SettingsSchemaSource::reference () const -> void
{
  // See the comment at the top of this file, if you want to know why the cast works.
  g_settings_schema_source_ref(reinterpret_cast<GSettingsSchemaSource*>(const_cast<SettingsSchemaSource*>(this)));
}

auto SettingsSchemaSource::unreference () const -> void
{
  // See the comment at the top of this file, if you want to know why the cast works.
  g_settings_schema_source_unref(reinterpret_cast<GSettingsSchemaSource*>(const_cast<SettingsSchemaSource*>(this)));
}

auto SettingsSchemaSource::gobj() -> GSettingsSchemaSource*
{
  // See the comment at the top of this file, if you want to know why the cast works.
  return reinterpret_cast<GSettingsSchemaSource*>(this);
}

auto SettingsSchemaSource::gobj() const -> const GSettingsSchemaSource*
{
  // See the comment at the top of this file, if you want to know why the cast works.
  return reinterpret_cast<const GSettingsSchemaSource*>(this);
}

auto SettingsSchemaSource::gobj_copy() const -> GSettingsSchemaSource*
{
  // See the comment at the top of this file, if you want to know why the cast works.
  const auto gobject = reinterpret_cast<GSettingsSchemaSource*>(const_cast<SettingsSchemaSource*>(this));
  g_settings_schema_source_ref(gobject);
  return gobject;
}


auto SettingsSchemaSource::get_default() -> Glib::RefPtr<SettingsSchemaSource>
{

  auto retvalue = Glib::wrap(g_settings_schema_source_get_default());
  if(retvalue)
    retvalue->reference(); //The function does not do a ref for us
  return retvalue;
}

auto SettingsSchemaSource::create(const std::string& directory, const bool trusted, const Glib::RefPtr<SettingsSchemaSource>& parent) -> Glib::RefPtr<SettingsSchemaSource>
{
  GError* gerror = nullptr;
  auto retvalue = Glib::wrap(g_settings_schema_source_new_from_directory(directory.c_str(), Glib::unwrap(parent), trusted, &gerror));
  if(gerror)
    Glib::Error::throw_exception(gerror);
  return retvalue;
}

auto SettingsSchemaSource::lookup(const Glib::ustring& schema_id, const bool recursive) -> Glib::RefPtr<SettingsSchema>
{
  return Glib::wrap(g_settings_schema_source_lookup(gobj(), schema_id.c_str(), recursive));
}

auto SettingsSchemaSource::lookup(const Glib::ustring& schema_id, const bool recursive) const -> Glib::RefPtr<const SettingsSchema>
{
  return Glib::wrap(g_settings_schema_source_lookup(const_cast<GSettingsSchemaSource*>(gobj()), schema_id.c_str(), recursive));
}


} // namespace Gio


