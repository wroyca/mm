
#ifndef _GIOMM_SETTINGS_H
#define _GIOMM_SETTINGS_H

#include <libmm-gio/gioconfig.hxx>

#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm-gio/action.hxx>
#include <libmm-glib/object.hxx>
#include <libmm-glib/variant.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GSettings = struct _GSettings;
using GSettingsClass = struct _GSettingsClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gio
{
  class GIOMM_API Settings_Class;
}
#endif

namespace Gio
{
  class GIOMM_API SettingsSchema;

  class GIOMM_API Settings : public Glib::Object
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
    explicit Settings (const Glib::ConstructParams& construct_params);
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
    explicit Settings (const Glib::ustring& schema_id);

    explicit Settings (const Glib::ustring& schema_id,
                       const Glib::ustring& path);

  public:
    static auto
    create (const Glib::ustring& schema_id) -> Glib::RefPtr<Settings>;

    static auto
    create (const Glib::ustring& schema_id, const Glib::ustring& path)
        -> Glib::RefPtr<Settings>;

    auto
    set_value (const Glib::ustring& key, const Glib::VariantBase& value)
        -> bool;

    void
    get_value (const Glib::ustring& key, Glib::VariantBase& value) const;

    auto
    get_user_value (const Glib::ustring& key, Glib::VariantBase& value) const
        -> bool;

    void
    get_default_value (const Glib::ustring& key,
                       Glib::VariantBase& value) const;

    auto
    get_int (const Glib::ustring& key) const -> int;

    auto
    set_int (const Glib::ustring& key, int value) -> bool;

    auto
    get_int64 (const Glib::ustring& key) const -> gint64;

    auto
    set_int64 (const Glib::ustring& key, gint64 value) -> bool;

    auto
    get_uint (const Glib::ustring& key) const -> guint;

    auto
    set_uint (const Glib::ustring& key, guint value) -> bool;

    auto
    get_uint64 (const Glib::ustring& key) const -> guint64;

    auto
    set_uint64 (const Glib::ustring& key, guint64 value) -> bool;

    auto
    get_boolean (const Glib::ustring& key) const -> bool;

    auto
    set_boolean (const Glib::ustring& key, bool value) -> bool;

    auto
    get_string (const Glib::ustring& key) const -> Glib::ustring;

    auto
    set_string (const Glib::ustring& key, const Glib::ustring& value) -> bool;

    auto
    get_double (const Glib::ustring& key) const -> double;

    auto
    set_double (const Glib::ustring& key, double value) -> bool;

    auto
    get_string_array (const Glib::ustring& key) const
        -> std::vector<Glib::ustring>;

    auto
    set_string_array (const Glib::ustring& key,
                      const std::vector<Glib::ustring>& value) -> bool;

    auto
    get_enum (const Glib::ustring& key) const -> int;

    auto
    set_enum (const Glib::ustring& key, int value) -> bool;

    auto
    get_flags (const Glib::ustring& key) const -> guint;

    auto
    set_flags (const Glib::ustring& key, guint value) -> bool;

    auto
    get_child (const Glib::ustring& name) -> Glib::RefPtr<Settings>;

    auto
    get_child (const Glib::ustring& name) const -> Glib::RefPtr<const Settings>;

    auto
    is_writable (const Glib::ustring& name) const -> bool;

    void
    delay ();

    void
    apply ();

    void
    revert ();

    auto
    get_has_unapplied () const -> bool;

    void
    reset (const Glib::ustring& key);

    auto
    list_children () const -> std::vector<Glib::ustring>;

    void
    bind (const Glib::ustring& key,
          Glib::ObjectBase* object,
          const Glib::ustring& property,
          BindFlags flags = BindFlags::DEFAULT);
    void
    bind (const Glib::ustring& key,
          const Glib::PropertyProxy_Base& property_proxy,
          BindFlags flags = BindFlags::DEFAULT);

    void
    bind_writable (const Glib::ustring& key,
                   Glib::ObjectBase* object,
                   const Glib::ustring& property,
                   bool inverted = false);
    void
    bind_writable (const Glib::ustring& key,
                   const Glib::PropertyProxy_Base& property_proxy,
                   bool inverted = false);

    auto
    create_action (const Glib::ustring& key) -> Glib::RefPtr<Action>;

    auto
    property_delay_apply () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_has_unapplied () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_path () const -> Glib::PropertyProxy_ReadOnly<std::string>;

    auto
    property_schema_id () const -> Glib::PropertyProxy_ReadOnly<Glib::ustring>;

    auto
    property_settings_schema () const
        -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<SettingsSchema>>;

    auto
    signal_changed (const Glib::ustring& key = {})
        -> Glib::SignalProxyDetailed<void (const Glib::ustring&)>;

    auto
    signal_writable_change_event () -> Glib::SignalProxy<bool (GQuark)>;

    auto
    signal_writable_changed (const Glib::ustring& key = {})
        -> Glib::SignalProxyDetailed<void (const Glib::ustring&)>;

  public:
  public:
  protected:
    virtual void
    on_changed (const Glib::ustring& key);

    virtual auto
    on_writable_change_event (GQuark key) -> bool;

    virtual void
    on_writable_changed (const Glib::ustring& key);
  };

} // namespace Gio

namespace Gio
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
} // namespace Gio

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

  template <>
  class GIOMM_API Value<Gio::Settings::BindFlags>
    : public Glib::Value_Flags<Gio::Settings::BindFlags>
  {
  public:
    static auto
    value_type () -> GType G_GNUC_CONST;
  };

} // namespace Glib
#endif

namespace Glib
{

  GIOMM_API
  auto
  wrap (GSettings* object, bool take_copy = false) -> Glib::RefPtr<Gio::Settings>;
} // namespace Glib

#endif
