


#include <libmm-glib/mm-glib.hpp>

#include <libmm-gtk/dropcontrollermotion.hpp>
#include <libmm-gtk/dropcontrollermotion_p.hpp>


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


namespace
{


auto DropControllerMotion_signal_enter_callback (
  GtkDropControllerMotion *self, const gdouble p0, const gdouble p1, void *data) -> void
{
  using namespace Gtk;
  using SlotType = sigc::slot<void(double, double)>;

  const auto obj = dynamic_cast<DropControllerMotion*>(Glib::ObjectBase::_get_current_wrapper((GObject*) self));
  // Do not try to call a signal on a disassociated wrapper.
  if(obj)
  {
    try
    {
      if(const auto slot = Glib::SignalProxyNormal::data_to_slot(data))
        (*static_cast<SlotType*>(slot))(p0
, p1
);
    }
    catch(...)
    {
       Glib::exception_handlers_invoke();
    }
  }
}

const Glib::SignalProxyInfo DropControllerMotion_signal_enter_info =
{
  "enter",
  (GCallback) &DropControllerMotion_signal_enter_callback,
  (GCallback) &DropControllerMotion_signal_enter_callback
};


const Glib::SignalProxyInfo DropControllerMotion_signal_leave_info =
{
  "leave",
  (GCallback) &Glib::SignalProxyNormal::slot0_void_callback,
  (GCallback) &Glib::SignalProxyNormal::slot0_void_callback
};


auto DropControllerMotion_signal_motion_callback (
  GtkDropControllerMotion *self, const gdouble p0, const gdouble p1, void *data) -> void
{
  using namespace Gtk;
  using SlotType = sigc::slot<void(double, double)>;

  const auto obj = dynamic_cast<DropControllerMotion*>(Glib::ObjectBase::_get_current_wrapper((GObject*) self));
  // Do not try to call a signal on a disassociated wrapper.
  if(obj)
  {
    try
    {
      if(const auto slot = Glib::SignalProxyNormal::data_to_slot(data))
        (*static_cast<SlotType*>(slot))(p0
, p1
);
    }
    catch(...)
    {
       Glib::exception_handlers_invoke();
    }
  }
}

const Glib::SignalProxyInfo DropControllerMotion_signal_motion_info =
{
  "motion",
  (GCallback) &DropControllerMotion_signal_motion_callback,
  (GCallback) &DropControllerMotion_signal_motion_callback
};


} // anonymous namespace


namespace Glib
{

auto wrap(GtkDropControllerMotion* object, const bool take_copy) -> RefPtr<Gtk::DropControllerMotion>
{
  return Glib::make_refptr_for_instance<Gtk::DropControllerMotion>( dynamic_cast<Gtk::DropControllerMotion*> (wrap_auto((GObject*)object, take_copy)) );
  //We use dynamic_cast<> in case of multiple inheritance.
}

} /* namespace Glib */


namespace Gtk
{


/* The *_Class implementation: */

auto DropControllerMotion_Class::init() -> const Class&
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Class has to know the class init function to clone custom types.
    class_init_func_ = &DropControllerMotion_Class::class_init_function;

    // This is actually just optimized away, apparently with no harm.
    // Make sure that the parent type has been created.
    //CppClassParent::CppObjectType::get_type();

    // Create the wrapper type, with the same class/instance size as the base type.
    register_derived_type(gtk_drop_controller_motion_get_type());

    // Add derived versions of interfaces, if the C type implements any interfaces:

  }

  return *this;
}


auto DropControllerMotion_Class::class_init_function (void *g_class, void *class_data) -> void
{
  const auto klass = static_cast<BaseClassType*>(g_class);
  CppClassParent::class_init_function(klass, class_data);


}


auto DropControllerMotion_Class::wrap_new(GObject* object) -> Glib::ObjectBase*
{
  return new DropControllerMotion((GtkDropControllerMotion*)object);
}


/* The implementation: */

auto DropControllerMotion::gobj_copy() -> GtkDropControllerMotion*
{
  reference();
  return gobj();
}

DropControllerMotion::DropControllerMotion(const Glib::ConstructParams& construct_params)
:
  EventController(construct_params)
{

}

DropControllerMotion::DropControllerMotion(GtkDropControllerMotion* castitem)
:
  EventController((GtkEventController*)castitem)
{}


DropControllerMotion::DropControllerMotion(DropControllerMotion&& src) noexcept
: EventController(std::move(src))
{}

auto DropControllerMotion::operator=(DropControllerMotion&& src) noexcept -> DropControllerMotion&
{
  EventController::operator=(std::move(src));
  return *this;
}


DropControllerMotion::~DropControllerMotion() noexcept = default;

DropControllerMotion::CppClassType DropControllerMotion::dropcontrollermotion_class_; // initialize static member

auto DropControllerMotion::get_type() -> GType
{
  return dropcontrollermotion_class_.init().get_type();
}


auto DropControllerMotion::get_base_type() -> GType
{
  return gtk_drop_controller_motion_get_type();
}


DropControllerMotion::DropControllerMotion()
:
  // Mark this class as non-derived to allow C++ vfuncs to be skipped.
ObjectBase(nullptr),
  EventController(Glib::ConstructParams(dropcontrollermotion_class_.init()))
{


}

auto DropControllerMotion::create() -> Glib::RefPtr<DropControllerMotion>
{
  return Glib::make_refptr_for_instance<DropControllerMotion>( new DropControllerMotion() );
}

auto DropControllerMotion::contains_pointer() const -> bool
{
  return gtk_drop_controller_motion_contains_pointer(const_cast<GtkDropControllerMotion*>(gobj()));
}

auto DropControllerMotion::is_pointer() const -> bool
{
  return gtk_drop_controller_motion_is_pointer(const_cast<GtkDropControllerMotion*>(gobj()));
}

auto DropControllerMotion::get_drop() -> Glib::RefPtr<Gdk::Drop>
{
  auto retvalue = Glib::wrap(gtk_drop_controller_motion_get_drop(gobj()));
  if(retvalue)
    retvalue->reference(); //The function does not do a ref for us.
  return retvalue;
}

auto DropControllerMotion::get_drop() const -> Glib::RefPtr<const Gdk::Drop>
{
  return const_cast<DropControllerMotion*>(this)->get_drop();
}


auto DropControllerMotion::signal_enter() -> Glib::SignalProxy<void(double, double)>
{
  return {this, &DropControllerMotion_signal_enter_info};
}


auto DropControllerMotion::signal_leave() -> Glib::SignalProxy<void()>
{
  return {this, &DropControllerMotion_signal_leave_info};
}


auto DropControllerMotion::signal_motion() -> Glib::SignalProxy<void(double, double)>
{
  return {this, &DropControllerMotion_signal_motion_info};
}


auto DropControllerMotion::property_contains_pointer() const -> Glib::PropertyProxy_ReadOnly< bool >
{
  return {this, "contains-pointer"};
}

static_assert(Glib::Traits::ValueCompatibleWithWrapProperty<Glib::RefPtr<Gdk::Drop>>::value,
  "Type Glib::RefPtr<Gdk::Drop> cannot be used in _WRAP_PROPERTY. "
  "There is no suitable template specialization of Glib::Value<>.");

auto DropControllerMotion::property_drop() const -> Glib::PropertyProxy_ReadOnly< Glib::RefPtr<Gdk::Drop> >
{
  return {this, "drop"};
}

auto DropControllerMotion::property_is_pointer() const -> Glib::PropertyProxy_ReadOnly< bool >
{
  return {this, "is-pointer"};
}


} // namespace Gtk


