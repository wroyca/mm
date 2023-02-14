
#ifndef _GIOMM_NOTIFICATION_H
#define _GIOMM_NOTIFICATION_H

#include <libmm-gio/gioconfig.hxx>

#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm-glib/object.hxx>
#include <libmm-glib/ustring.hxx>
#include <libmm-glib/variant.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GNotification = struct _GNotification;
using GNotificationClass = struct _GNotificationClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gio
{
  class GIOMM_API Notification_Class;
}
#endif

namespace Gio
{
  class GIOMM_API Icon;

  class GIOMM_API Notification : public Glib::Object
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
    explicit Notification (const Glib::ConstructParams& construct_params);
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
    explicit Notification (const Glib::ustring& title);

  public:
    enum class Priority
    {
      NORMAL,
      LOW,
      HIGH,
      URGENT
    };

    static auto
    create (const Glib::ustring& title) -> Glib::RefPtr<Notification>;

    void
    set_title (const Glib::ustring& title);

    void
    set_body (const Glib::ustring& body);

    void
    set_icon (const Glib::RefPtr<Icon>& icon);

    void
    set_priority (Priority priority = Priority::NORMAL);

    void
    set_category (const Glib::ustring& category);

    void
    add_button (const Glib::ustring& label,
                const Glib::ustring& detailed_action);

    template <typename T_Value>
    void
    add_button (const Glib::ustring& label,
                const Glib::ustring& action,
                const T_Value& target);

    void
    add_button_variant (const Glib::ustring& label,
                        const Glib::ustring& action,
                        const Glib::VariantBase& target);

    void
    set_default_action (const Glib::ustring& detailed_action);

    template <typename T_Value>
    void
    set_default_action (const Glib::ustring& action, const T_Value& target);

    void
    set_default_action_variant (const Glib::ustring& action,
                                const Glib::VariantBase& target);

  public:
  public:
  protected:
  };

  template <typename T_Value>
  void
  Notification::add_button (const Glib::ustring& label,
                            const Glib::ustring& action,
                            const T_Value& target)
  {
    using type_glib_variant = Glib::Variant<T_Value>;

    add_button_variant (label, action, type_glib_variant::create (target));
  }

  template <typename T_Value>
  void
  Notification::set_default_action (const Glib::ustring& action,
                                    const T_Value& target)
  {
    using type_glib_variant = Glib::Variant<T_Value>;

    set_default_action_variant (action, type_glib_variant::create (target));
  }

} // namespace Gio

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

  template <>
  class GIOMM_API Value<Gio::Notification::Priority>
    : public Glib::Value_Enum<Gio::Notification::Priority>
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
  wrap (GNotification* object, bool take_copy = false) -> Glib::RefPtr<Gio::Notification>;
} // namespace Glib

#endif
