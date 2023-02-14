

#include <libmm-glib/mm-glib.hxx>

#include <libmm-gio/settingsschemakey.hxx>
#include <libmm-gio/settingsschemakey_p.hxx>

#include <gio/gio.h>

namespace Gio
{

}

namespace
{
}

namespace Glib
{

  auto
  wrap (GSettingsSchemaKey* object, const bool take_copy) -> RefPtr<Gio::SettingsSchemaKey>
  {
    if (take_copy && object)
      g_settings_schema_key_ref (object);

    return Glib::make_refptr_for_instance<Gio::SettingsSchemaKey> (
        reinterpret_cast<Gio::SettingsSchemaKey*> (object));
  }

} // namespace Glib

namespace Gio
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
  SettingsSchemaKey::get_name () const -> Glib::ustring
  {
    return Glib::convert_const_gchar_ptr_to_ustring (
        g_settings_schema_key_get_name (
            const_cast<GSettingsSchemaKey*> (gobj ())));
  }

  auto
  SettingsSchemaKey::get_summary () const -> Glib::ustring
  {
    return Glib::convert_const_gchar_ptr_to_ustring (
        g_settings_schema_key_get_summary (
            const_cast<GSettingsSchemaKey*> (gobj ())));
  }

  auto
  SettingsSchemaKey::get_description () const -> Glib::ustring
  {
    return Glib::convert_const_gchar_ptr_to_ustring (
        g_settings_schema_key_get_description (
            const_cast<GSettingsSchemaKey*> (gobj ())));
  }

  auto
  SettingsSchemaKey::get_value_type () const -> Glib::VariantType
  {
    return Glib::wrap (
        const_cast<GVariantType*> (g_settings_schema_key_get_value_type (
            const_cast<GSettingsSchemaKey*> (gobj ()))),
        true);
  }

  auto
  SettingsSchemaKey::get_default_value () const -> Glib::VariantBase
  {
    return Glib::wrap (g_settings_schema_key_get_default_value (
                           const_cast<GSettingsSchemaKey*> (gobj ())),
                       false);
  }

  auto
  SettingsSchemaKey::get_range () const -> Glib::VariantBase
  {
    return Glib::wrap (g_settings_schema_key_get_range (
                           const_cast<GSettingsSchemaKey*> (gobj ())),
                       false);
  }

  auto
  SettingsSchemaKey::range_check (const Glib::VariantBase& value) const -> bool
  {
    return g_settings_schema_key_range_check (
        const_cast<GSettingsSchemaKey*> (gobj ()),
        const_cast<GVariant*> (value.gobj ()));
  }

} // namespace Gio
