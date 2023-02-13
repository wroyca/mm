


#include <libmm-glib/mm-glib.hpp>

#include <libmm-gio/notification.hpp>
#include <libmm-gio/notification_p.hpp>


/* Copyright (C) 2014 The giomm Development Team
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library. If not, see <http://www.gnu.org/licenses/>.
 */

#include <gio/gio.h>
#include <libmm-gio/icon.hpp>
#include <libmm-glib/variant.hpp>

namespace Gio
{

Notification::Notification(const Glib::ustring& title) : // Mark this class as non-derived to allow C++ vfuncs to be skipped.
  ObjectBase(nullptr),
  Object(Glib::ConstructParams(notification_class_.init()))
{
  // The title is compulsory. Don't skip it, if it's empty.
  set_title(title);
}

} // namespace Gio

namespace
{
} // anonymous namespace

// static
auto Glib::Value<Gio::Notification::Priority>::value_type() -> GType
{
  return g_notification_priority_get_type();
}


namespace Glib
{

auto wrap(GNotification* object, const bool take_copy) -> RefPtr<Gio::Notification>
{
  return Glib::make_refptr_for_instance<Gio::Notification>( dynamic_cast<Gio::Notification*> (wrap_auto((GObject*)object, take_copy)) );
  //We use dynamic_cast<> in case of multiple inheritance.
}

} /* namespace Glib */


namespace Gio
{


/* The *_Class implementation: */

auto Notification_Class::init() -> const Class&
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Class has to know the class init function to clone custom types.
    class_init_func_ = &Notification_Class::class_init_function;

    // This is actually just optimized away, apparently with no harm.
    // Make sure that the parent type has been created.
    //CppClassParent::CppObjectType::get_type();

    // Create the wrapper type, with the same class/instance size as the base type.
    register_derived_type(g_notification_get_type());

    // Add derived versions of interfaces, if the C type implements any interfaces:

  }

  return *this;
}


auto Notification_Class::class_init_function (void *g_class, void *class_data) -> void
{
  const auto klass = static_cast<BaseClassType*>(g_class);
  CppClassParent::class_init_function(klass, class_data);


}


auto Notification_Class::wrap_new(GObject* object) -> Glib::ObjectBase*
{
  return new Notification((GNotification*)object);
}


/* The implementation: */

auto Notification::gobj_copy() -> GNotification*
{
  reference();
  return gobj();
}

Notification::Notification(const Glib::ConstructParams& construct_params)
: Object(construct_params)
{

}

Notification::Notification(GNotification* castitem)
: Object((GObject*)castitem)
{}


Notification::Notification(Notification&& src) noexcept
: Object(std::move(src))
{}

auto Notification::operator=(Notification&& src) noexcept -> Notification&
{
  Object::operator=(std::move(src));
  return *this;
}


Notification::~Notification() noexcept = default;

Notification::CppClassType Notification::notification_class_; // initialize static member

auto Notification::get_type() -> GType
{
  return notification_class_.init().get_type();
}


auto Notification::get_base_type() -> GType
{
  return g_notification_get_type();
}


auto Notification::create(const Glib::ustring& title) -> Glib::RefPtr<Notification>
{
  return Glib::make_refptr_for_instance<Notification>( new Notification(title) );
}

auto Notification::set_title (const Glib::ustring &title) -> void
{
  g_notification_set_title(gobj(), title.c_str());
}

auto Notification::set_body (const Glib::ustring &body) -> void
{
  g_notification_set_body(gobj(), body.c_str());
}

auto Notification::set_icon (const Glib::RefPtr <Icon> &icon) -> void
{
  g_notification_set_icon(gobj(), Glib::unwrap(icon));
}

auto Notification::set_priority (Priority priority) -> void
{
  g_notification_set_priority(gobj(), static_cast<GNotificationPriority>(priority));
}

auto Notification::set_category (const Glib::ustring &category) -> void
{
  g_notification_set_category(gobj(), category.c_str());
}

auto Notification::add_button (
  const Glib::ustring &label, const Glib::ustring &detailed_action) -> void
{
  g_notification_add_button(gobj(), label.c_str(), detailed_action.c_str());
}

auto Notification::add_button_variant (
  const Glib::ustring &label, const Glib::ustring &action, const Glib::VariantBase &target) -> void
{
  g_notification_add_button_with_target_value(gobj(), label.c_str(), action.c_str(), const_cast<GVariant*>(target.gobj()));
}

auto Notification::set_default_action (const Glib::ustring &detailed_action) -> void
{
  g_notification_set_default_action(gobj(), detailed_action.c_str());
}

auto Notification::set_default_action_variant (
  const Glib::ustring &action, const Glib::VariantBase &target) -> void
{
  g_notification_set_default_action_and_target_value(gobj(), action.c_str(), const_cast<GVariant*>(target.gobj()));
}


} // namespace Gio


