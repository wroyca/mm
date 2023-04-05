// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/gio/settingsschemakey.hxx>
#include <libmm/gio/settingsschemakey_p.hxx>

#include <gio/gio.h>

namespace gio
{

}

namespace
{
}

namespace glib
{

  auto
  wrap (GSettingsSchemaKey* object, const bool take_copy) -> RefPtr<gio::SettingsSchemaKey>
  {
    if (take_copy && object)
      g_settings_schema_key_ref (object);

    return glib::make_refptr_for_instance<gio::SettingsSchemaKey> (
        reinterpret_cast<gio::SettingsSchemaKey*> (object));
  }

} // namespace glib

namespace gio
{

  auto
  SettingsSchemaKey::reference () const -> void
  {
    g_settings_schema_key_ref (reinterpret_cast<GSettingsSchemaKey*> (
        const_cast<SettingsSchemaKey*> (this)));
  }

  auto
  SettingsSchemaKey::unreference () const -> void
  {
    g_settings_schema_key_unref (reinterpret_cast<GSettingsSchemaKey*> (
        const_cast<SettingsSchemaKey*> (this)));
  }

  auto
  SettingsSchemaKey::gobj () -> GSettingsSchemaKey*
  {
    return reinterpret_cast<GSettingsSchemaKey*> (this);
  }

  auto
  SettingsSchemaKey::gobj () const -> const GSettingsSchemaKey*
  {
    return reinterpret_cast<const GSettingsSchemaKey*> (this);
  }

  auto
  SettingsSchemaKey::gobj_copy () const -> GSettingsSchemaKey*
  {
    const auto gobject = reinterpret_cast<GSettingsSchemaKey*> (
        const_cast<SettingsSchemaKey*> (this));
    g_settings_schema_key_ref (gobject);
    return gobject;
  }

  auto
  SettingsSchemaKey::get_name () const -> glib::ustring
  {
    return glib::convert_const_gchar_ptr_to_ustring (
        g_settings_schema_key_get_name (
            const_cast<GSettingsSchemaKey*> (gobj ())));
  }

  auto
  SettingsSchemaKey::get_summary () const -> glib::ustring
  {
    return glib::convert_const_gchar_ptr_to_ustring (
        g_settings_schema_key_get_summary (
            const_cast<GSettingsSchemaKey*> (gobj ())));
  }

  auto
  SettingsSchemaKey::get_description () const -> glib::ustring
  {
    return glib::convert_const_gchar_ptr_to_ustring (
        g_settings_schema_key_get_description (
            const_cast<GSettingsSchemaKey*> (gobj ())));
  }

  auto
  SettingsSchemaKey::get_value_type () const -> glib::VariantType
  {
    return glib::wrap (
        const_cast<GVariantType*> (g_settings_schema_key_get_value_type (
            const_cast<GSettingsSchemaKey*> (gobj ()))),
        true);
  }

  auto
  SettingsSchemaKey::get_default_value () const -> glib::VariantBase
  {
    return glib::wrap (g_settings_schema_key_get_default_value (
                           const_cast<GSettingsSchemaKey*> (gobj ())),
                       false);
  }

  auto
  SettingsSchemaKey::get_range () const -> glib::VariantBase
  {
    return glib::wrap (g_settings_schema_key_get_range (
                           const_cast<GSettingsSchemaKey*> (gobj ())),
                       false);
  }

  auto
  SettingsSchemaKey::range_check (const glib::VariantBase& value) const -> bool
  {
    return g_settings_schema_key_range_check (
        const_cast<GSettingsSchemaKey*> (gobj ()),
        const_cast<GVariant*> (value.gobj ()));
  }

} // namespace gio
