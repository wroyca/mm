
#ifndef _GIOMM_SETTINGSSCHEMASOURCE_H
#define _GIOMM_SETTINGSSCHEMASOURCE_H

#include <libmm-gio/gioconfig.hxx>

#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm-gio/settingsschema.hxx>

#include <libmm-glib/ustring.hxx>
#include <vector>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
typedef struct _GSettingsSchemaSource GSettingsSchemaSource;
#endif

namespace Gio
{

  class GIOMM_API SettingsSchemaSource final
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    using CppObjectType = SettingsSchemaSource;
    using BaseObjectType = GSettingsSchemaSource;
#endif

    void
    reference () const;

    void
    unreference () const;

    auto
    gobj () -> GSettingsSchemaSource*;

    auto
    gobj () const -> const GSettingsSchemaSource*;

    auto
    gobj_copy () const -> GSettingsSchemaSource*;

    SettingsSchemaSource () = delete;

    SettingsSchemaSource (const SettingsSchemaSource&) = delete;
    auto
    operator= (const SettingsSchemaSource&) -> SettingsSchemaSource& = delete;

  protected:
    void
    operator delete (void*, std::size_t);

  private:
  protected:
  public:
    static auto
    get_default () -> Glib::RefPtr<SettingsSchemaSource>;

    static auto
    create (const std::string& directory,
            bool trusted,
            const Glib::RefPtr<SettingsSchemaSource>& parent = get_default ())
        -> Glib::RefPtr<SettingsSchemaSource>;

    auto
    lookup (const Glib::ustring& schema_id, bool recursive)
        -> Glib::RefPtr<SettingsSchema>;

    auto
    lookup (const Glib::ustring& schema_id, bool recursive) const
        -> Glib::RefPtr<const SettingsSchema>;

    auto
    list_schemas (bool relocatable, bool recursive) const
        -> std::vector<Glib::ustring>;
  };

} // namespace Gio

namespace Glib
{

  GIOMM_API
  auto
  wrap (GSettingsSchemaSource* object, bool take_copy = false) -> Glib::RefPtr<Gio::SettingsSchemaSource>;

} // namespace Glib

#endif
