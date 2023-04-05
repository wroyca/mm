// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GIOMM_SETTINGSSCHEMA_H
#define _GIOMM_SETTINGSSCHEMA_H

#include <libmm/gio/mm-gioconfig.hxx>

#include <libmm/glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm/gio/settingsschemakey.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
typedef struct _GSettingsSchema GSettingsSchema;
#endif

namespace gio
{

  class LIBMM_GIO_SYMEXPORT SettingsSchema final
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    using CppObjectType = SettingsSchema;
    using BaseObjectType = GSettingsSchema;
#endif

    static auto
    get_type () -> GType G_GNUC_CONST;

    auto
    reference () const -> void;

    auto
    unreference () const -> void;

    auto
    gobj () -> GSettingsSchema*;

    auto
    gobj () const -> const GSettingsSchema*;

    auto
    gobj_copy () const -> GSettingsSchema*;

    SettingsSchema () = delete;

    SettingsSchema (const SettingsSchema&) = delete;
    auto
    operator= (const SettingsSchema&) -> SettingsSchema& = delete;

  protected:
    auto
    operator delete (void*, std::size_t) -> void;

  private:
  protected:
  public:
    auto
    get_id () const -> glib::ustring;

    auto
    get_path () const -> glib::ustring;

    auto
    get_key (const glib::ustring& name) -> glib::RefPtr<SettingsSchemaKey>;

    auto
    get_key (const glib::ustring& name) const
        -> glib::RefPtr<const SettingsSchemaKey>;

    auto
    has_key (const glib::ustring& name) const -> bool;

    auto
    list_keys () const -> std::vector<glib::ustring>;

    auto
    list_children () const -> std::vector<glib::ustring>;
  };

} // namespace gio

namespace glib
{

  LIBMM_GIO_SYMEXPORT
  auto
  wrap (GSettingsSchema* object, bool take_copy = false) -> glib::RefPtr<gio::SettingsSchema>;

#ifndef DOXYGEN_SHOULD_SKIP_THIS
  template <>
  class LIBMM_GIO_SYMEXPORT Value<glib::RefPtr<gio::SettingsSchema>>
    : public glib::Value_RefPtrBoxed<gio::SettingsSchema>
  {
  public:
    auto
    get () const -> CppType
    {
      return glib::wrap (static_cast<GSettingsSchema*> (get_boxed ()), true);
    }
  };
#endif

} // namespace glib

#endif
