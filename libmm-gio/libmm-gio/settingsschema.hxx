// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GIOMM_SETTINGSSCHEMA_H
#define _GIOMM_SETTINGSSCHEMA_H

#include <libmm-gio/gioconfig.hxx>

#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm-gio/settingsschemakey.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
typedef struct _GSettingsSchema GSettingsSchema;
#endif

namespace Gio
{

  class GIOMM_API SettingsSchema final
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
    get_id () const -> Glib::ustring;

    auto
    get_path () const -> Glib::ustring;

    auto
    get_key (const Glib::ustring& name) -> Glib::RefPtr<SettingsSchemaKey>;

    auto
    get_key (const Glib::ustring& name) const
        -> Glib::RefPtr<const SettingsSchemaKey>;

    auto
    has_key (const Glib::ustring& name) const -> bool;

    auto
    list_keys () const -> std::vector<Glib::ustring>;

    auto
    list_children () const -> std::vector<Glib::ustring>;
  };

} // namespace Gio

namespace Glib
{

  GIOMM_API
  auto
  wrap (GSettingsSchema* object, bool take_copy = false) -> Glib::RefPtr<Gio::SettingsSchema>;

#ifndef DOXYGEN_SHOULD_SKIP_THIS
  template <>
  class GIOMM_API Value<Glib::RefPtr<Gio::SettingsSchema>>
    : public Glib::Value_RefPtrBoxed<Gio::SettingsSchema>
  {
  public:
    auto
    get () const -> CppType
    {
      return Glib::wrap (static_cast<GSettingsSchema*> (get_boxed ()), true);
    }
  };
#endif

} // namespace Glib

#endif
