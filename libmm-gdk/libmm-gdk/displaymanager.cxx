


#include <libmm-glib/mm-glib.hxx>

#include <libmm-gdk/displaymanager.hxx>
#include <libmm-gdk/displaymanager_p.hxx>


/*
 * Copyright 2002 The gtkmm Development Team
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
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 */

#include <gdk/gdk.h>
namespace Gdk
{


} //namespace Gdk


namespace
{


auto DisplayManager_signal_display_opened_callback (
  GdkDisplayManager *self, GdkDisplay *p0, void *data) -> void
{
  using namespace Gdk;
  using SlotType = sigc::slot<void(const Glib::RefPtr<Display>&)>;

  const auto obj = dynamic_cast<DisplayManager*>(Glib::ObjectBase::_get_current_wrapper((GObject*) self));
  // Do not try to call a signal on a disassociated wrapper.
  if(obj)
  {
    try
    {
      if(const auto slot = Glib::SignalProxyNormal::data_to_slot(data))
        (*static_cast<SlotType*>(slot))(Glib::wrap(p0, true)
);
    }
    catch(...)
    {
       Glib::exception_handlers_invoke();
    }
  }
}

const Glib::SignalProxyInfo DisplayManager_signal_display_opened_info =
{
  "display-opened",
  (GCallback) &DisplayManager_signal_display_opened_callback,
  (GCallback) &DisplayManager_signal_display_opened_callback
};


} // anonymous namespace


namespace Glib
{

auto wrap(GdkDisplayManager* object, const bool take_copy) -> RefPtr<Gdk::DisplayManager>
{
  return Glib::make_refptr_for_instance<Gdk::DisplayManager>( dynamic_cast<Gdk::DisplayManager*> (wrap_auto((GObject*)object, take_copy)) );
  //We use dynamic_cast<> in case of multiple inheritance.
}

} /* namespace Glib */


namespace Gdk
{


/* The *_Class implementation: */

auto DisplayManager_Class::init() -> const Class&
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Class has to know the class init function to clone custom types.
    class_init_func_ = &DisplayManager_Class::class_init_function;

    // This is actually just optimized away, apparently with no harm.
    // Make sure that the parent type has been created.
    //CppClassParent::CppObjectType::get_type();

    // Create the wrapper type, with the same class/instance size as the base type.
    register_derived_type(gdk_display_manager_get_type());

    // Add derived versions of interfaces, if the C type implements any interfaces:

  }

  return *this;
}


auto DisplayManager_Class::class_init_function (void *g_class, void *class_data) -> void
{
  const auto klass = static_cast<BaseClassType*>(g_class);
  CppClassParent::class_init_function(klass, class_data);


}


auto DisplayManager_Class::wrap_new(GObject* object) -> Glib::ObjectBase*
{
  return new DisplayManager((GdkDisplayManager*)object);
}


/* The implementation: */

auto DisplayManager::gobj_copy() -> GdkDisplayManager*
{
  reference();
  return gobj();
}

DisplayManager::DisplayManager(const Glib::ConstructParams& construct_params)
: Object(construct_params)
{

}

DisplayManager::DisplayManager(GdkDisplayManager* castitem)
: Object((GObject*)castitem)
{}


DisplayManager::DisplayManager(DisplayManager&& src) noexcept
: Object(std::move(src))
{}

auto DisplayManager::operator=(DisplayManager&& src) noexcept -> DisplayManager&
{
  Object::operator=(std::move(src));
  return *this;
}


DisplayManager::~DisplayManager() noexcept = default;

DisplayManager::CppClassType DisplayManager::displaymanager_class_; // initialize static member

auto DisplayManager::get_type() -> GType
{
  return displaymanager_class_.init().get_type();
}


auto DisplayManager::get_base_type() -> GType
{
  return gdk_display_manager_get_type();
}


auto DisplayManager::get() -> Glib::RefPtr<DisplayManager>
{

  auto retvalue = Glib::wrap(gdk_display_manager_get());
  if(retvalue)
    retvalue->reference(); //The function does not do a ref for us
  return retvalue;
}

auto DisplayManager::get_default_display() -> Glib::RefPtr<Display>
{
  auto retvalue = Glib::wrap(gdk_display_manager_get_default_display(gobj()));
  if(retvalue)
    retvalue->reference(); //The function does not do a ref for us.
  return retvalue;
}

auto DisplayManager::get_default_display() const -> Glib::RefPtr<const Display>
{
  return const_cast<DisplayManager*>(this)->get_default_display();
}

auto DisplayManager::set_default_display (const Glib::RefPtr <Display> &display) -> void
{
  gdk_display_manager_set_default_display(gobj(), Glib::unwrap(display));
}

auto DisplayManager::list_displays() -> std::vector< Glib::RefPtr<Display> >
{
  return Glib::SListHandler<Glib::RefPtr<Display> >::slist_to_vector(gdk_display_manager_list_displays(gobj()), Glib::OWNERSHIP_SHALLOW);
}

auto DisplayManager::open_display(const Glib::ustring& name) -> Glib::RefPtr<Display>
{
  auto retvalue = Glib::wrap(gdk_display_manager_open_display(gobj(), name.c_str()));
  if(retvalue)
    retvalue->reference(); //The function does not do a ref for us.
  return retvalue;
}


auto DisplayManager::signal_display_opened() -> Glib::SignalProxy<void(const Glib::RefPtr<Display>&)>
{
  return {this, &DisplayManager_signal_display_opened_info};
}


static_assert(Glib::Traits::ValueCompatibleWithWrapProperty<Glib::RefPtr<Display>>::value,
  "Type Glib::RefPtr<Display> cannot be used in _WRAP_PROPERTY. "
  "There is no suitable template specialization of Glib::Value<>.");

auto DisplayManager::property_default_display() -> Glib::PropertyProxy< Glib::RefPtr<Display> >
{
  return {this, "default-display"};
}

auto DisplayManager::property_default_display() const -> Glib::PropertyProxy_ReadOnly< Glib::RefPtr<Display> >
{
  return {this, "default-display"};
}


} // namespace Gdk

