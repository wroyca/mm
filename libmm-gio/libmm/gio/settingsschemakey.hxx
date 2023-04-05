// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GIOMM_SETTINGSSCHEMAKEY_H
#define _GIOMM_SETTINGSSCHEMAKEY_H

#include <libmm/gio/mm-gioconfig.hxx>

#include <libmm/glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm/glib/variant.hxx>
#include <libmm/glib/varianttype.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
typedef struct _GSettingsSchemaKey GSettingsSchemaKey;
#endif

namespace gio
{

  class LIBMM_GIO_SYMEXPORT SettingsSchemaKey final
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    using CppObjectType = SettingsSchemaKey;
    using BaseObjectType = GSettingsSchemaKey;
#endif

    auto
    reference () const -> void;

    auto
    unreference () const -> void;

    auto
    gobj () -> GSettingsSchemaKey*;

    auto
    gobj () const -> const GSettingsSchemaKey*;

    auto
    gobj_copy () const -> GSettingsSchemaKey*;

    SettingsSchemaKey () = delete;

    SettingsSchemaKey (const SettingsSchemaKey&) = delete;
    auto
    operator= (const SettingsSchemaKey&) -> SettingsSchemaKey& = delete;

  protected:
    auto
    operator delete (void*, std::size_t) -> void;

  private:
  protected:
  public:
    auto
    get_name () const -> glib::ustring;

    auto
    get_summary () const -> glib::ustring;

    auto
    get_description () const -> glib::ustring;

    auto
    get_value_type () const -> glib::VariantType;

    auto
    get_default_value () const -> glib::VariantBase;

    auto
    get_range () const -> glib::VariantBase;

    auto
    range_check (const glib::VariantBase& value) const -> bool;
  };

} // namespace gio

namespace glib
{

  LIBMM_GIO_SYMEXPORT
  auto
  wrap (GSettingsSchemaKey* object, bool take_copy = false) -> glib::RefPtr<gio::SettingsSchemaKey>;

} // namespace glib

#endif
