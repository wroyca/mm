// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GIOMM_SETTINGSSCHEMASOURCE_H
#define _GIOMM_SETTINGSSCHEMASOURCE_H

#include <libmm/gio/mm-gioconfig.hxx>

#include <libmm/glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm/gio/settingsschema.hxx>

#include <libmm/glib/ustring.hxx>
#include <vector>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
typedef struct _GSettingsSchemaSource GSettingsSchemaSource;
#endif

namespace gio
{

  class LIBMM_GIO_SYMEXPORT SettingsSchemaSource final
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    using CppObjectType = SettingsSchemaSource;
    using BaseObjectType = GSettingsSchemaSource;
#endif

    auto
    reference () const -> void;

    auto
    unreference () const -> void;

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
    auto
    operator delete (void*, std::size_t) -> void;

  private:
  protected:
  public:
    static auto
    get_default () -> glib::RefPtr<SettingsSchemaSource>;

    static auto
    create (const std::string& directory,
            bool trusted,
            const glib::RefPtr<SettingsSchemaSource>& parent = get_default ())
        -> glib::RefPtr<SettingsSchemaSource>;

    auto
    lookup (const glib::ustring& schema_id, bool recursive)
        -> glib::RefPtr<SettingsSchema>;

    auto
    lookup (const glib::ustring& schema_id, bool recursive) const
        -> glib::RefPtr<const SettingsSchema>;

    auto
    list_schemas (bool relocatable, bool recursive) const
        -> std::vector<glib::ustring>;
  };

} // namespace gio

namespace glib
{

  LIBMM_GIO_SYMEXPORT
  auto
  wrap (GSettingsSchemaSource* object, bool take_copy = false) -> glib::RefPtr<gio::SettingsSchemaSource>;

} // namespace glib

#endif
