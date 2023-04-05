// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GIOMM_SETTINGS_H
#define _GIOMM_SETTINGS_H

#include <libmm/gio/mm-gioconfig.hxx>

#include <libmm/glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm/gio/action.hxx>
#include <libmm/glib/object.hxx>
#include <libmm/glib/variant.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GSettings = struct _GSettings;
using GSettingsClass = struct _GSettingsClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace gio
{
  class LIBMM_GIO_SYMEXPORT Settings_Class;
}
#endif

namespace gio
{
  class LIBMM_GIO_SYMEXPORT SettingsSchema;

  class LIBMM_GIO_SYMEXPORT Settings : public glib::Object
  {
#ifndef DOXYGEN_SHOULD_SKIP_THIS

  public:
    using CppObjectType = Settings;
    using CppClassType = Settings_Class;
    using BaseObjectType = GSettings;
    using BaseClassType = GSettingsClass;

    Settings (const Settings&) = delete;
    auto
    operator= (const Settings&) -> Settings& = delete;

  private:
    friend class Settings_Class;
    static CppClassType settings_class_;

  protected:
    explicit Settings (const glib::ConstructParams& construct_params);
    explicit Settings (GSettings* castitem);

#endif

  public:
    Settings (Settings&& src) noexcept;
    auto
    operator= (Settings&& src) noexcept -> Settings&;

    ~Settings () noexcept override;

    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GSettings*
    {
      return reinterpret_cast<GSettings*> (gobject_);
    }

    auto
    gobj () const -> const GSettings*
    {
      return reinterpret_cast<GSettings*> (gobject_);
    }

    auto
    gobj_copy () -> GSettings*;

  private:
  public:
    enum class BindFlags
    {
      DEFAULT = 0x0,
      GET = (1 << 0),
      SET = (1 << 1),
      NO_SENSITIVITY = (1 << 2),
      GET_NO_CHANGES = (1 << 3),
      INVERT_BOOLEAN = (1 << 4)
    };

  protected:
    explicit Settings (const glib::ustring& schema_id);

    explicit Settings (const glib::ustring& schema_id,
                       const glib::ustring& path);

  public:
    static auto
    create (const glib::ustring& schema_id) -> glib::RefPtr<Settings>;

    static auto
    create (const glib::ustring& schema_id, const glib::ustring& path)
        -> glib::RefPtr<Settings>;

    auto
    set_value (const glib::ustring& key, const glib::VariantBase& value)
        -> bool;

    auto
    get_value (const glib::ustring& key, glib::VariantBase& value) const
        -> void;

    auto
    get_user_value (const glib::ustring& key, glib::VariantBase& value) const
        -> bool;

    auto
    get_default_value (const glib::ustring& key, glib::VariantBase& value) const
        -> void;

    auto
    get_int (const glib::ustring& key) const -> int;

    auto
    set_int (const glib::ustring& key, int value) -> bool;

    auto
    get_int64 (const glib::ustring& key) const -> gint64;

    auto
    set_int64 (const glib::ustring& key, gint64 value) -> bool;

    auto
    get_uint (const glib::ustring& key) const -> guint;

    auto
    set_uint (const glib::ustring& key, guint value) -> bool;

    auto
    get_uint64 (const glib::ustring& key) const -> guint64;

    auto
    set_uint64 (const glib::ustring& key, guint64 value) -> bool;

    auto
    get_boolean (const glib::ustring& key) const -> bool;

    auto
    set_boolean (const glib::ustring& key, bool value) -> bool;

    auto
    get_string (const glib::ustring& key) const -> glib::ustring;

    auto
    set_string (const glib::ustring& key, const glib::ustring& value) -> bool;

    auto
    get_double (const glib::ustring& key) const -> double;

    auto
    set_double (const glib::ustring& key, double value) -> bool;

    auto
    get_string_array (const glib::ustring& key) const
        -> std::vector<glib::ustring>;

    auto
    set_string_array (const glib::ustring& key,
                      const std::vector<glib::ustring>& value) -> bool;

    auto
    get_enum (const glib::ustring& key) const -> int;

    auto
    set_enum (const glib::ustring& key, int value) -> bool;

    auto
    get_flags (const glib::ustring& key) const -> guint;

    auto
    set_flags (const glib::ustring& key, guint value) -> bool;

    auto
    get_child (const glib::ustring& name) -> glib::RefPtr<Settings>;

    auto
    get_child (const glib::ustring& name) const -> glib::RefPtr<const Settings>;

    auto
    is_writable (const glib::ustring& name) const -> bool;

    auto
    delay () -> void;

    auto
    apply () -> void;

    auto
    revert () -> void;

    auto
    get_has_unapplied () const -> bool;

    auto
    reset (const glib::ustring& key) -> void;

    auto
    list_children () const -> std::vector<glib::ustring>;

    auto
    bind (const glib::ustring& key,
          glib::ObjectBase* object,
          const glib::ustring& property,
          BindFlags flags = BindFlags::DEFAULT) -> void;
    auto
    bind (const glib::ustring& key,
          const glib::PropertyProxy_Base& property_proxy,
          BindFlags flags = BindFlags::DEFAULT) -> void;

    auto
    bind_writable (const glib::ustring& key,
                   glib::ObjectBase* object,
                   const glib::ustring& property,
                   bool inverted = false) -> void;
    auto
    bind_writable (const glib::ustring& key,
                   const glib::PropertyProxy_Base& property_proxy,
                   bool inverted = false) -> void;

    auto
    create_action (const glib::ustring& key) -> glib::RefPtr<Action>;

    auto
    property_delay_apply () const -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_has_unapplied () const -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_path () const -> glib::PropertyProxy_ReadOnly<std::string>;

    auto
    property_schema_id () const -> glib::PropertyProxy_ReadOnly<glib::ustring>;

    auto
    property_settings_schema () const
        -> glib::PropertyProxy_ReadOnly<glib::RefPtr<SettingsSchema>>;

    auto
    signal_changed (const glib::ustring& key = {})
        -> glib::SignalProxyDetailed<void (const glib::ustring&)>;

    auto
    signal_writable_change_event () -> glib::SignalProxy<bool (GQuark)>;

    auto
    signal_writable_changed (const glib::ustring& key = {})
        -> glib::SignalProxyDetailed<void (const glib::ustring&)>;

  public:
  public:
  protected:
    virtual auto
    on_changed (const glib::ustring& key) -> void;

    virtual auto
    on_writable_change_event (GQuark key) -> bool;

    virtual auto
    on_writable_changed (const glib::ustring& key) -> void;
  };

} // namespace gio

namespace gio
{

  inline auto
  operator| (Settings::BindFlags lhs, Settings::BindFlags rhs) -> Settings::BindFlags
  {
    return static_cast<Settings::BindFlags> (static_cast<unsigned> (lhs) |
                                             static_cast<unsigned> (rhs));
  }

  inline auto
  operator& (Settings::BindFlags lhs, Settings::BindFlags rhs) -> Settings::BindFlags
  {
    return static_cast<Settings::BindFlags> (static_cast<unsigned> (lhs) &
                                             static_cast<unsigned> (rhs));
  }

  inline auto
  operator^ (Settings::BindFlags lhs, Settings::BindFlags rhs) -> Settings::BindFlags
  {
    return static_cast<Settings::BindFlags> (static_cast<unsigned> (lhs) ^
                                             static_cast<unsigned> (rhs));
  }

  inline auto
  operator~(Settings::BindFlags flags) -> Settings::BindFlags
  {
    return static_cast<Settings::BindFlags> (~static_cast<unsigned> (flags));
  }

  inline auto
  operator|= (Settings::BindFlags& lhs, Settings::BindFlags rhs) -> Settings::BindFlags&
  {
    return (lhs = static_cast<Settings::BindFlags> (
                static_cast<unsigned> (lhs) | static_cast<unsigned> (rhs)));
  }

  inline auto
  operator&= (Settings::BindFlags& lhs, Settings::BindFlags rhs) -> Settings::BindFlags&
  {
    return (lhs = static_cast<Settings::BindFlags> (
                static_cast<unsigned> (lhs) & static_cast<unsigned> (rhs)));
  }

  inline auto
  operator^= (Settings::BindFlags& lhs, Settings::BindFlags rhs) -> Settings::BindFlags&
  {
    return (lhs = static_cast<Settings::BindFlags> (
                static_cast<unsigned> (lhs) ^ static_cast<unsigned> (rhs)));
  }
} // namespace gio

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace glib
{

  template <>
  class LIBMM_GIO_SYMEXPORT Value<gio::Settings::BindFlags>
    : public glib::Value_Flags<gio::Settings::BindFlags>
  {
  public:
    static auto
    value_type () -> GType G_GNUC_CONST;
  };

} // namespace glib
#endif

namespace glib
{

  LIBMM_GIO_SYMEXPORT
  auto
  wrap (GSettings* object, bool take_copy = false) -> glib::RefPtr<gio::Settings>;
} // namespace glib

#endif
