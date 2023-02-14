

#include <libmm-glib/mm-glib.hxx>

#include <libmm-gio/settingsschema.hxx>
#include <libmm-gio/settingsschema_p.hxx>

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
  wrap (GSettingsSchema* object, const bool take_copy) -> RefPtr<Gio::SettingsSchema>
  {
    if (take_copy && object)
      g_settings_schema_ref (object);

    return Glib::make_refptr_for_instance<Gio::SettingsSchema> (
        reinterpret_cast<Gio::SettingsSchema*> (object));
  }

} // namespace Glib

namespace Gio
{

  auto
  SettingsSchema::get_type () -> GType
  {
    return g_settings_schema_get_type ();
  }

  auto
  SettingsSchema::reference () const -> void
  {
    g_settings_schema_ref (reinterpret_cast<GSettingsSchema*> (
        const_cast<SettingsSchema*> (this)));
  }

  auto
  SettingsSchema::unreference () const -> void
  {
    g_settings_schema_unref (reinterpret_cast<GSettingsSchema*> (
        const_cast<SettingsSchema*> (this)));
  }

  auto
  SettingsSchema::gobj () -> GSettingsSchema*
  {
    return reinterpret_cast<GSettingsSchema*> (this);
  }

  auto
  SettingsSchema::gobj () const -> const GSettingsSchema*
  {
    return reinterpret_cast<const GSettingsSchema*> (this);
  }

  auto
  SettingsSchema::gobj_copy () const -> GSettingsSchema*
  {
    const auto gobject =
        reinterpret_cast<GSettingsSchema*> (const_cast<SettingsSchema*> (this));
    g_settings_schema_ref (gobject);
    return gobject;
  }

  auto
  SettingsSchema::get_id () const -> Glib::ustring
  {
    return Glib::convert_const_gchar_ptr_to_ustring (
        g_settings_schema_get_id (const_cast<GSettingsSchema*> (gobj ())));
  }

  auto
  SettingsSchema::get_path () const -> Glib::ustring
  {
    return Glib::convert_const_gchar_ptr_to_ustring (
        g_settings_schema_get_path (const_cast<GSettingsSchema*> (gobj ())));
  }

  auto
  SettingsSchema::get_key (const Glib::ustring& name) -> Glib::RefPtr<SettingsSchemaKey>
  {
    return Glib::wrap (g_settings_schema_get_key (gobj (), name.c_str ()));
  }

  auto
  SettingsSchema::get_key (const Glib::ustring& name) const -> Glib::RefPtr<const SettingsSchemaKey>
  {
    return Glib::wrap (
        g_settings_schema_get_key (const_cast<GSettingsSchema*> (gobj ()),
                                   name.c_str ()));
  }

  auto
  SettingsSchema::has_key (const Glib::ustring& name) const -> bool
  {
    return g_settings_schema_has_key (const_cast<GSettingsSchema*> (gobj ()),
                                      name.c_str ());
  }

  auto
  SettingsSchema::list_keys () const -> std::vector<Glib::ustring>
  {
    return Glib::ArrayHandler<Glib::ustring>::array_to_vector (
        g_settings_schema_list_keys (const_cast<GSettingsSchema*> (gobj ())),
        Glib::OWNERSHIP_DEEP);
  }

  auto
  SettingsSchema::list_children () const -> std::vector<Glib::ustring>
  {
    return Glib::ArrayHandler<Glib::ustring>::array_to_vector (
        g_settings_schema_list_children (
            const_cast<GSettingsSchema*> (gobj ())),
        Glib::OWNERSHIP_DEEP);
  }

} // namespace Gio
