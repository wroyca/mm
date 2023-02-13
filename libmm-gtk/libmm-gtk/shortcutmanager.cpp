


#include <libmm-glib/mm-glib.hpp>

#include <libmm-gtk/shortcutmanager.hpp>
#include <libmm-gtk/shortcutmanager_p.hpp>


/* Copyright (C) 2020 The gtkmm Development Team
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

#include <gtk/gtk.h>
#include <libmm-gtk/shortcutcontroller.hpp>

namespace
{
} // anonymous namespace


namespace Glib
{

auto wrap(GtkShortcutManager* object, const bool take_copy) -> RefPtr<Gtk::ShortcutManager>
{
  return Glib::make_refptr_for_instance<Gtk::ShortcutManager>( Glib::wrap_auto_interface<Gtk::ShortcutManager> ((GObject*)object, take_copy) );
  //We use dynamic_cast<> in case of multiple inheritance.
}

} // namespace Glib


namespace Gtk
{


/* The *_Class implementation: */

auto ShortcutManager_Class::init() -> const Interface_Class&
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Interface_Class has to know the interface init function
    // in order to add interfaces to implementing types.
    class_init_func_ = &ShortcutManager_Class::iface_init_function;

    // We can not derive from another interface, and it is not necessary anyway.
    gtype_ = gtk_shortcut_manager_get_type();
  }

  return *this;
}

auto ShortcutManager_Class::iface_init_function (void *g_iface, void *) -> void
{
  const auto klass = static_cast<BaseClassType*>(g_iface);

  //This is just to avoid an "unused variable" warning when there are no vfuncs or signal handlers to connect.
  //This is a temporary fix until I find out why I can not seem to derive a GtkFileChooser interface. murrayc
  g_assert(klass != nullptr);

  klass->add_controller = &add_controller_vfunc_callback;
  klass->remove_controller = &remove_controller_vfunc_callback;

}

auto ShortcutManager_Class::add_controller_vfunc_callback (
  GtkShortcutManager *self, GtkShortcutController *controller) -> void
{
  const auto obj_base = Glib::ObjectBase::_get_current_wrapper((GObject*)self);

  // Non-gtkmmproc-generated custom classes implicitly call the default
  // Glib::ObjectBase constructor, which sets is_derived_. But gtkmmproc-
  // generated classes can use this optimisation, which avoids the unnecessary
  // parameter conversions if there is no possibility of the virtual function
  // being overridden:
  if(obj_base && obj_base->is_derived_())
  {
    const auto obj = dynamic_cast<CppObjectType* const>(obj_base);
    if(obj) // This can be NULL during destruction.
    {
      try // Trap C++ exceptions which would normally be lost because this is a C callback.
      {
        // Call the virtual member method, which derived classes might override.
        obj->add_controller_vfunc(Glib::wrap(controller, true)
);
        return;
      }
      catch(...)
      {
        Glib::exception_handlers_invoke();
      }
    }
  }

  const BaseClassType *const base = static_cast<BaseClassType*>(
      g_type_interface_peek_parent( // Get the parent interface of the interface (The original underlying C interface).
g_type_interface_peek(G_OBJECT_GET_CLASS(self), CppObjectType::get_type()) // Get the interface.
)  );

  // Call the original underlying C function:
  if(base && base->add_controller)
    (*base->add_controller)(self, controller);
}
auto ShortcutManager_Class::remove_controller_vfunc_callback (
  GtkShortcutManager *self, GtkShortcutController *controller) -> void
{
  const auto obj_base = Glib::ObjectBase::_get_current_wrapper((GObject*)self);

  // Non-gtkmmproc-generated custom classes implicitly call the default
  // Glib::ObjectBase constructor, which sets is_derived_. But gtkmmproc-
  // generated classes can use this optimisation, which avoids the unnecessary
  // parameter conversions if there is no possibility of the virtual function
  // being overridden:
  if(obj_base && obj_base->is_derived_())
  {
    const auto obj = dynamic_cast<CppObjectType* const>(obj_base);
    if(obj) // This can be NULL during destruction.
    {
      try // Trap C++ exceptions which would normally be lost because this is a C callback.
      {
        // Call the virtual member method, which derived classes might override.
        obj->remove_controller_vfunc(Glib::wrap(controller, true)
);
        return;
      }
      catch(...)
      {
        Glib::exception_handlers_invoke();
      }
    }
  }

  const BaseClassType *const base = static_cast<BaseClassType*>(
      g_type_interface_peek_parent( // Get the parent interface of the interface (The original underlying C interface).
g_type_interface_peek(G_OBJECT_GET_CLASS(self), CppObjectType::get_type()) // Get the interface.
)  );

  // Call the original underlying C function:
  if(base && base->remove_controller)
    (*base->remove_controller)(self, controller);
}


auto ShortcutManager_Class::wrap_new(GObject* object) -> Glib::ObjectBase*
{
  return new ShortcutManager((GtkShortcutManager*)object);
}


/* The implementation: */

ShortcutManager::ShortcutManager()
: Interface(shortcutmanager_class_.init())
{}

ShortcutManager::ShortcutManager(GtkShortcutManager* castitem)
: Interface((GObject*)castitem)
{}

ShortcutManager::ShortcutManager(const Glib::Interface_Class& interface_class)
: Interface(interface_class)
{
}

ShortcutManager::ShortcutManager(ShortcutManager&& src) noexcept
: Interface(std::move(src))
{}

auto ShortcutManager::operator=(ShortcutManager&& src) noexcept -> ShortcutManager&
{
  Interface::operator=(std::move(src));
  return *this;
}

ShortcutManager::~ShortcutManager() noexcept = default;

// static
auto ShortcutManager::add_interface (
  const GType gtype_implementer) -> void
{
  shortcutmanager_class_.init().add_interface(gtype_implementer);
}

ShortcutManager::CppClassType ShortcutManager::shortcutmanager_class_; // initialize static member

auto ShortcutManager::get_type() -> GType
{
  return shortcutmanager_class_.init().get_type();
}


auto ShortcutManager::get_base_type() -> GType
{
  return gtk_shortcut_manager_get_type();
}


auto ShortcutManager::add_controller_vfunc (
  const Glib::RefPtr <ShortcutController> &controller) -> void
{
  const auto base = static_cast<BaseClassType*>(
      g_type_interface_peek_parent(                             // Get the parent interface of the interface (The original underlying C interface).
g_type_interface_peek(G_OBJECT_GET_CLASS(gobject_), get_type()) // Get the interface.
)  );

  if(base && base->add_controller)
  {
    (*base->add_controller)(gobj(),Glib::unwrap(controller));
  }
}
auto ShortcutManager::remove_controller_vfunc (
  const Glib::RefPtr <ShortcutController> &controller) -> void
{
  const auto base = static_cast<BaseClassType*>(
      g_type_interface_peek_parent(                             // Get the parent interface of the interface (The original underlying C interface).
g_type_interface_peek(G_OBJECT_GET_CLASS(gobject_), get_type()) // Get the interface.
)  );

  if(base && base->remove_controller)
  {
    (*base->remove_controller)(gobj(),Glib::unwrap(controller));
  }
}


} // namespace Gtk


