// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/gio/settingsschemasource.hxx>
#include <libmm/gio/settingsschemasource_p.hxx>

#include <gio/gio.h>

#include <libmm/glib/vectorutils.hxx>

namespace Gio
{

  auto
  SettingsSchemaSource::list_schemas (const bool relocatable,
                                      const bool recursive) const -> std::vector<Glib::ustring>
  {
    const auto gobject = const_cast<GSettingsSchemaSource*> (gobj ());
    gchar** schemas{};

    if (relocatable)
      g_settings_schema_source_list_schemas (gobject,
                                             recursive,
                                             nullptr,
                                             &schemas);
    else
      g_settings_schema_source_list_schemas (gobject,
                                             recursive,
                                             &schemas,
                                             nullptr);

    return Glib::ArrayHandler<Glib::ustring>::array_to_vector (
        schemas,
        Glib::OWNERSHIP_DEEP);
  }

} // namespace Gio

namespace
{
}

namespace Glib
{

  auto
  wrap (GSettingsSchemaSource* object, const bool take_copy) -> RefPtr<Gio::SettingsSchemaSource>
  {
    if (take_copy && object)
      g_settings_schema_source_ref (object);

    return Glib::make_refptr_for_instance<Gio::SettingsSchemaSource> (
        reinterpret_cast<Gio::SettingsSchemaSource*> (object));
  }

} // namespace Glib

namespace Gio
{

  auto
  SettingsSchemaSource::reference () const -> void
  {
    g_settings_schema_source_ref (reinterpret_cast<GSettingsSchemaSource*> (
        const_cast<SettingsSchemaSource*> (this)));
  }

  auto
  SettingsSchemaSource::unreference () const -> void
  {
    g_settings_schema_source_unref (reinterpret_cast<GSettingsSchemaSource*> (
        const_cast<SettingsSchemaSource*> (this)));
  }

  auto
  SettingsSchemaSource::gobj () -> GSettingsSchemaSource*
  {
    return reinterpret_cast<GSettingsSchemaSource*> (this);
  }

  auto
  SettingsSchemaSource::gobj () const -> const GSettingsSchemaSource*
  {
    return reinterpret_cast<const GSettingsSchemaSource*> (this);
  }

  auto
  SettingsSchemaSource::gobj_copy () const -> GSettingsSchemaSource*
  {
    const auto gobject = reinterpret_cast<GSettingsSchemaSource*> (
        const_cast<SettingsSchemaSource*> (this));
    g_settings_schema_source_ref (gobject);
    return gobject;
  }

  auto
  SettingsSchemaSource::get_default () -> Glib::RefPtr<SettingsSchemaSource>
  {
    auto retvalue = Glib::wrap (g_settings_schema_source_get_default ());
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  SettingsSchemaSource::create (
      const std::string& directory,
      const bool trusted,
      const Glib::RefPtr<SettingsSchemaSource>& parent) -> Glib::RefPtr<SettingsSchemaSource>
  {
    GError* gerror = nullptr;
    auto retvalue = Glib::wrap (
        g_settings_schema_source_new_from_directory (directory.c_str (),
                                                     Glib::unwrap (parent),
                                                     trusted,
                                                     &gerror));
    if (gerror)
      Glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  SettingsSchemaSource::lookup (const Glib::ustring& schema_id,
                                const bool recursive) -> Glib::RefPtr<SettingsSchema>
  {
    return Glib::wrap (g_settings_schema_source_lookup (gobj (),
                                                        schema_id.c_str (),
                                                        recursive));
  }

  auto
  SettingsSchemaSource::lookup (const Glib::ustring& schema_id,
                                const bool recursive) const -> Glib::RefPtr<const SettingsSchema>
  {
    return Glib::wrap (g_settings_schema_source_lookup (
        const_cast<GSettingsSchemaSource*> (gobj ()),
        schema_id.c_str (),
        recursive));
  }

} // namespace Gio
