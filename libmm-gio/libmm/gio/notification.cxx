// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/gio/notification.hxx>
#include <libmm/gio/notification_p.hxx>

#include <gio/gio.h>
#include <libmm/gio/icon.hxx>
#include <libmm/glib/variant.hxx>

namespace gio
{

  Notification::Notification (const glib::ustring& title)
    : ObjectBase (nullptr),
      Object (glib::ConstructParams (notification_class_.init ()))
  {
    set_title (title);
  }

} // namespace gio

namespace
{
}

auto
glib::Value<gio::Notification::Priority>::value_type () -> GType
{
  return g_notification_priority_get_type ();
}

namespace glib
{

  auto
  wrap (GNotification* object, const bool take_copy) -> RefPtr<gio::Notification>
  {
    return glib::make_refptr_for_instance<gio::Notification> (
        dynamic_cast<gio::Notification*> (
            wrap_auto ((GObject*) object, take_copy)));
  }

} // namespace glib

namespace gio
{

  auto
  Notification_Class::init () -> const Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &Notification_Class::class_init_function;

      register_derived_type (g_notification_get_type ());
    }

    return *this;
  }

  auto
  Notification_Class::class_init_function (void* g_class, void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);
  }

  auto
  Notification_Class::wrap_new (GObject* object) -> glib::ObjectBase*
  {
    return new Notification ((GNotification*) object);
  }

  auto
  Notification::gobj_copy () -> GNotification*
  {
    reference ();
    return gobj ();
  }

  Notification::Notification (const glib::ConstructParams& construct_params)
    : Object (construct_params)
  {
  }

  Notification::Notification (GNotification* castitem)
    : Object ((GObject*) castitem)
  {
  }

  Notification::Notification (Notification&& src) noexcept
    : Object (std::move (src))
  {
  }

  auto
  Notification::operator= (Notification&& src) noexcept -> Notification&
  {
    Object::operator= (std::move (src));
    return *this;
  }

  Notification::~Notification () noexcept = default;

  Notification::CppClassType Notification::notification_class_;

  auto
  Notification::get_type () -> GType
  {
    return notification_class_.init ().get_type ();
  }

  auto
  Notification::get_base_type () -> GType
  {
    return g_notification_get_type ();
  }

  auto
  Notification::create (const glib::ustring& title) -> glib::RefPtr<Notification>
  {
    return glib::make_refptr_for_instance<Notification> (
        new Notification (title));
  }

  auto
  Notification::set_title (const glib::ustring& title) -> void
  {
    g_notification_set_title (gobj (), title.c_str ());
  }

  auto
  Notification::set_body (const glib::ustring& body) -> void
  {
    g_notification_set_body (gobj (), body.c_str ());
  }

  auto
  Notification::set_icon (const glib::RefPtr<Icon>& icon) -> void
  {
    g_notification_set_icon (gobj (), glib::unwrap (icon));
  }

  auto
  Notification::set_priority (Priority priority) -> void
  {
    g_notification_set_priority (gobj (),
                                 static_cast<GNotificationPriority> (priority));
  }

  auto
  Notification::set_category (const glib::ustring& category) -> void
  {
    g_notification_set_category (gobj (), category.c_str ());
  }

  auto
  Notification::add_button (const glib::ustring& label,
                            const glib::ustring& detailed_action) -> void
  {
    g_notification_add_button (gobj (),
                               label.c_str (),
                               detailed_action.c_str ());
  }

  auto
  Notification::add_button_variant (const glib::ustring& label,
                                    const glib::ustring& action,
                                    const glib::VariantBase& target) -> void
  {
    g_notification_add_button_with_target_value (
        gobj (),
        label.c_str (),
        action.c_str (),
        const_cast<GVariant*> (target.gobj ()));
  }

  auto
  Notification::set_default_action (const glib::ustring& detailed_action) -> void
  {
    g_notification_set_default_action (gobj (), detailed_action.c_str ());
  }

  auto
  Notification::set_default_action_variant (const glib::ustring& action,
                                            const glib::VariantBase& target) -> void
  {
    g_notification_set_default_action_and_target_value (
        gobj (),
        action.c_str (),
        const_cast<GVariant*> (target.gobj ()));
  }

} // namespace gio
