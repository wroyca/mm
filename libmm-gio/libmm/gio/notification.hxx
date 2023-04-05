// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GIOMM_NOTIFICATION_H
#define _GIOMM_NOTIFICATION_H

#include <libmm/gio/mm-gioconfig.hxx>

#include <libmm/glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm/glib/object.hxx>
#include <libmm/glib/ustring.hxx>
#include <libmm/glib/variant.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GNotification = struct _GNotification;
using GNotificationClass = struct _GNotificationClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace gio
{
  class LIBMM_GIO_SYMEXPORT Notification_Class;
}
#endif

namespace gio
{
  class LIBMM_GIO_SYMEXPORT Icon;

  class LIBMM_GIO_SYMEXPORT Notification : public glib::Object
  {
#ifndef DOXYGEN_SHOULD_SKIP_THIS

  public:
    using CppObjectType = Notification;
    using CppClassType = Notification_Class;
    using BaseObjectType = GNotification;
    using BaseClassType = GNotificationClass;

    Notification (const Notification&) = delete;
    auto
    operator= (const Notification&) -> Notification& = delete;

  private:
    friend class Notification_Class;
    static CppClassType notification_class_;

  protected:
    explicit Notification (const glib::ConstructParams& construct_params);
    explicit Notification (GNotification* castitem);

#endif

  public:
    Notification (Notification&& src) noexcept;
    auto
    operator= (Notification&& src) noexcept -> Notification&;

    ~Notification () noexcept override;

    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GNotification*
    {
      return reinterpret_cast<GNotification*> (gobject_);
    }

    auto
    gobj () const -> const GNotification*
    {
      return reinterpret_cast<GNotification*> (gobject_);
    }

    auto
    gobj_copy () -> GNotification*;

  private:
  protected:
    explicit Notification (const glib::ustring& title);

  public:
    enum class Priority
    {
      NORMAL,
      LOW,
      HIGH,
      URGENT
    };

    static auto
    create (const glib::ustring& title) -> glib::RefPtr<Notification>;

    auto
    set_title (const glib::ustring& title) -> void;

    auto
    set_body (const glib::ustring& body) -> void;

    auto
    set_icon (const glib::RefPtr<Icon>& icon) -> void;

    auto
    set_priority (Priority priority = Priority::NORMAL) -> void;

    auto
    set_category (const glib::ustring& category) -> void;

    auto
    add_button (const glib::ustring& label,
                const glib::ustring& detailed_action) -> void;

    template <typename T_Value>
    auto
    add_button (const glib::ustring& label,
                const glib::ustring& action,
                const T_Value& target) -> void;

    auto
    add_button_variant (const glib::ustring& label,
                        const glib::ustring& action,
                        const glib::VariantBase& target) -> void;

    auto
    set_default_action (const glib::ustring& detailed_action) -> void;

    template <typename T_Value>
    auto
    set_default_action (const glib::ustring& action, const T_Value& target)
        -> void;

    auto
    set_default_action_variant (const glib::ustring& action,
                                const glib::VariantBase& target) -> void;

  public:
  public:
  protected:
  };

  template <typename T_Value>
  auto
  Notification::add_button (const glib::ustring& label,
                            const glib::ustring& action,
                            const T_Value& target) -> void
  {
    using type_glib_variant = glib::Variant<T_Value>;

    add_button_variant (label, action, type_glib_variant::create (target));
  }

  template <typename T_Value>
  auto
  Notification::set_default_action (const glib::ustring& action,
                                    const T_Value& target) -> void
  {
    using type_glib_variant = glib::Variant<T_Value>;

    set_default_action_variant (action, type_glib_variant::create (target));
  }

} // namespace gio

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace glib
{

  template <>
  class LIBMM_GIO_SYMEXPORT Value<gio::Notification::Priority>
    : public glib::Value_Enum<gio::Notification::Priority>
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
  wrap (GNotification* object, bool take_copy = false) -> glib::RefPtr<gio::Notification>;
} // namespace glib

#endif
