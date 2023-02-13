


#include <libmm-glib/mm-glib.hxx>

#include <libmm-gio/settingsschema.hxx>
#include <libmm-gio/settingsschema_p.hxx>


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


/* Why reinterpret_cast<SettingsSchema*>(gobject) is needed:
 *
 * A SettingsSchema instance is in fact always a GSettingsSchema instance.
 * Unfortunately, GSettingsSchema cannot be a member of SettingsSchema,
 * because it is an opaque struct.  Also, the C interface does not provide
 * any hooks to install a destroy notification handler, thus we cannot
 * wrap it dynamically either.
 *
 * The cast works because SettingsSchema does not have any member data, and
 * it is impossible to derive from it.  This is ensured by using final on the
 * class and by using = delete on the default constructor.
 */

namespace Glib
{

auto wrap(GSettingsSchema* object, const bool take_copy) -> RefPtr<Gio::SettingsSchema>
{
  if(take_copy && object)
    g_settings_schema_ref(object);

  // See the comment at the top of this file, if you want to know why the cast works.
  return Glib::make_refptr_for_instance<Gio::SettingsSchema>(reinterpret_cast<Gio::SettingsSchema*>(object));
}

} // namespace Glib


namespace Gio
{

// static
auto SettingsSchema::get_type() -> GType
{
  return g_settings_schema_get_type();
}

auto SettingsSchema::reference () const -> void
{
  // See the comment at the top of this file, if you want to know why the cast works.
  g_settings_schema_ref(reinterpret_cast<GSettingsSchema*>(const_cast<SettingsSchema*>(this)));
}

auto SettingsSchema::unreference () const -> void
{
  // See the comment at the top of this file, if you want to know why the cast works.
  g_settings_schema_unref(reinterpret_cast<GSettingsSchema*>(const_cast<SettingsSchema*>(this)));
}

auto SettingsSchema::gobj() -> GSettingsSchema*
{
  // See the comment at the top of this file, if you want to know why the cast works.
  return reinterpret_cast<GSettingsSchema*>(this);
}

auto SettingsSchema::gobj() const -> const GSettingsSchema*
{
  // See the comment at the top of this file, if you want to know why the cast works.
  return reinterpret_cast<const GSettingsSchema*>(this);
}

auto SettingsSchema::gobj_copy() const -> GSettingsSchema*
{
  // See the comment at the top of this file, if you want to know why the cast works.
  const auto gobject = reinterpret_cast<GSettingsSchema*>(const_cast<SettingsSchema*>(this));
  g_settings_schema_ref(gobject);
  return gobject;
}


auto SettingsSchema::get_id() const -> Glib::ustring
{
  return Glib::convert_const_gchar_ptr_to_ustring(g_settings_schema_get_id(const_cast<GSettingsSchema*>(gobj())));
}

auto SettingsSchema::get_path() const -> Glib::ustring
{
  return Glib::convert_const_gchar_ptr_to_ustring(g_settings_schema_get_path(const_cast<GSettingsSchema*>(gobj())));
}

auto SettingsSchema::get_key(const Glib::ustring& name) -> Glib::RefPtr<SettingsSchemaKey>
{
  return Glib::wrap(g_settings_schema_get_key(gobj(), name.c_str()));
}

auto SettingsSchema::get_key(const Glib::ustring& name) const -> Glib::RefPtr<const SettingsSchemaKey>
{
  return Glib::wrap(g_settings_schema_get_key(const_cast<GSettingsSchema*>(gobj()), name.c_str()));
}

auto SettingsSchema::has_key(const Glib::ustring& name) const -> bool
{
  return g_settings_schema_has_key(const_cast<GSettingsSchema*>(gobj()), name.c_str());
}

auto SettingsSchema::list_keys() const -> std::vector<Glib::ustring>
{
  return Glib::ArrayHandler<Glib::ustring>::array_to_vector(g_settings_schema_list_keys(const_cast<GSettingsSchema*>(gobj())), Glib::OWNERSHIP_DEEP);
}

auto SettingsSchema::list_children() const -> std::vector<Glib::ustring>
{
  return Glib::ArrayHandler<Glib::ustring>::array_to_vector(g_settings_schema_list_children(const_cast<GSettingsSchema*>(gobj())), Glib::OWNERSHIP_DEEP);
}


} // namespace Gio


