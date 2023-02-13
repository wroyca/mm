


#include <mm/glib/mm-glib.hpp>

#include <mm/gdk/seat.hpp>
#include <mm/gdk/private/seat_p.hpp>


/* Copyright (C) 2015 The gtkmm Development Team
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

#include <mm/gdk/devicetool.hpp>
#include <mm/gdk/display.hpp>
#include <mm/gdk/surface.hpp>

using Capabilities = Gdk::Seat::Capabilities;

namespace
{


auto Seat_signal_device_added_callback (GdkSeat *self, GdkDevice *p0, void *data) -> void
{
  using namespace Gdk;
  using SlotType = sigc::slot<void(const Glib::RefPtr<Device>&)>;

  const auto obj = dynamic_cast<Seat*>(Glib::ObjectBase::_get_current_wrapper((GObject*) self));
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

const Glib::SignalProxyInfo Seat_signal_device_added_info =
{
  "device-added",
  (GCallback) &Seat_signal_device_added_callback,
  (GCallback) &Seat_signal_device_added_callback
};


auto Seat_signal_device_removed_callback (GdkSeat *self, GdkDevice *p0, void *data) -> void
{
  using namespace Gdk;
  using SlotType = sigc::slot<void(const Glib::RefPtr<Device>&)>;

  const auto obj = dynamic_cast<Seat*>(Glib::ObjectBase::_get_current_wrapper((GObject*) self));
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

const Glib::SignalProxyInfo Seat_signal_device_removed_info =
{
  "device-removed",
  (GCallback) &Seat_signal_device_removed_callback,
  (GCallback) &Seat_signal_device_removed_callback
};


auto Seat_signal_tool_added_callback (GdkSeat *self, GdkDeviceTool *p0, void *data) -> void
{
  using namespace Gdk;
  using SlotType = sigc::slot<void(const Glib::RefPtr<DeviceTool>&)>;

  const auto obj = dynamic_cast<Seat*>(Glib::ObjectBase::_get_current_wrapper((GObject*) self));
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

const Glib::SignalProxyInfo Seat_signal_tool_added_info =
{
  "tool-added",
  (GCallback) &Seat_signal_tool_added_callback,
  (GCallback) &Seat_signal_tool_added_callback
};


auto Seat_signal_tool_removed_callback (GdkSeat *self, GdkDeviceTool *p0, void *data) -> void
{
  using namespace Gdk;
  using SlotType = sigc::slot<void(const Glib::RefPtr<DeviceTool>&)>;

  const auto obj = dynamic_cast<Seat*>(Glib::ObjectBase::_get_current_wrapper((GObject*) self));
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

const Glib::SignalProxyInfo Seat_signal_tool_removed_info =
{
  "tool-removed",
  (GCallback) &Seat_signal_tool_removed_callback,
  (GCallback) &Seat_signal_tool_removed_callback
};


} // anonymous namespace

// static
auto Glib::Value<Gdk::Seat::Capabilities>::value_type() -> GType
{
  return gdk_seat_capabilities_get_type();
}


namespace Glib
{

auto wrap(GdkSeat* object, const bool take_copy) -> RefPtr<Gdk::Seat>
{
  return Glib::make_refptr_for_instance<Gdk::Seat>( dynamic_cast<Gdk::Seat*> (wrap_auto((GObject*)object, take_copy)) );
  //We use dynamic_cast<> in case of multiple inheritance.
}

} /* namespace Glib */


namespace Gdk
{


/* The *_Class implementation: */

auto Seat_Class::init() -> const Class&
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Class has to know the class init function to clone custom types.
    class_init_func_ = &Seat_Class::class_init_function;

    // This is actually just optimized away, apparently with no harm.
    // Make sure that the parent type has been created.
    //CppClassParent::CppObjectType::get_type();

    // Create the wrapper type, with the same class/instance size as the base type.
    register_derived_type(gdk_seat_get_type());

    // Add derived versions of interfaces, if the C type implements any interfaces:

  }

  return *this;
}


auto Seat_Class::class_init_function (void *g_class, void *class_data) -> void
{
  const auto klass = static_cast<BaseClassType*>(g_class);
  CppClassParent::class_init_function(klass, class_data);


}


auto Seat_Class::wrap_new(GObject* object) -> Glib::ObjectBase*
{
  return new Seat((GdkSeat*)object);
}


/* The implementation: */

auto Seat::gobj_copy() -> GdkSeat*
{
  reference();
  return gobj();
}

Seat::Seat(const Glib::ConstructParams& construct_params)
: Object(construct_params)
{

}

Seat::Seat(GdkSeat* castitem)
: Object((GObject*)castitem)
{}


Seat::Seat(Seat&& src) noexcept
: Object(std::move(src))
{}

auto Seat::operator=(Seat&& src) noexcept -> Seat&
{
  Object::operator=(std::move(src));
  return *this;
}


Seat::~Seat() noexcept = default;

Seat::CppClassType Seat::seat_class_; // initialize static member

auto Seat::get_type() -> GType
{
  return seat_class_.init().get_type();
}


auto Seat::get_base_type() -> GType
{
  return gdk_seat_get_type();
}


Seat::Seat()
:
  // Mark this class as non-derived to allow C++ vfuncs to be skipped.
ObjectBase(nullptr),
Object(Glib::ConstructParams(seat_class_.init()))
{


}

auto Seat::get_display() -> Glib::RefPtr<Display>
{
  auto retvalue = Glib::wrap(gdk_seat_get_display(gobj()));
  if(retvalue)
    retvalue->reference(); //The function does not do a ref for us.
  return retvalue;
}

auto Seat::get_display() const -> Glib::RefPtr<const Display>
{
  return const_cast<Seat*>(this)->get_display();
}

auto Seat::get_capabilities() const -> Capabilities
{
  return static_cast<Capabilities>(gdk_seat_get_capabilities(const_cast<GdkSeat*>(gobj())));
}

auto Seat::get_devices(Capabilities capabilities) -> std::vector<Glib::RefPtr<Device>>
{
  return Glib::ListHandler<Glib::RefPtr<Device>>::list_to_vector(gdk_seat_get_devices(gobj(), static_cast<GdkSeatCapabilities>(capabilities)), Glib::OWNERSHIP_SHALLOW);
}

auto Seat::get_devices(Capabilities capabilities) const -> std::vector<Glib::RefPtr<const Device>>
{
  return Glib::ListHandler<Glib::RefPtr<const Device>>::list_to_vector(gdk_seat_get_devices(const_cast<GdkSeat*>(gobj()), static_cast<GdkSeatCapabilities>(capabilities)), Glib::OWNERSHIP_SHALLOW);
}

auto Seat::get_tools() -> std::vector<Glib::RefPtr<DeviceTool>>
{
  return Glib::ListHandler<Glib::RefPtr<DeviceTool>>::list_to_vector(gdk_seat_get_tools(gobj()), Glib::OWNERSHIP_SHALLOW);
}

auto Seat::get_tools() const -> std::vector<Glib::RefPtr<const DeviceTool>>
{
  return Glib::ListHandler<Glib::RefPtr<const DeviceTool>>::list_to_vector(gdk_seat_get_tools(const_cast<GdkSeat*>(gobj())), Glib::OWNERSHIP_SHALLOW);
}

auto Seat::get_pointer() -> Glib::RefPtr<Device>
{
  auto retvalue = Glib::wrap(gdk_seat_get_pointer(gobj()));
  if(retvalue)
    retvalue->reference(); //The function does not do a ref for us.
  return retvalue;
}

auto Seat::get_pointer() const -> Glib::RefPtr<const Device>
{
  return const_cast<Seat*>(this)->get_pointer();
}

auto Seat::get_keyboard() -> Glib::RefPtr<Device>
{
  auto retvalue = Glib::wrap(gdk_seat_get_keyboard(gobj()));
  if(retvalue)
    retvalue->reference(); //The function does not do a ref for us.
  return retvalue;
}

auto Seat::get_keyboard() const -> Glib::RefPtr<const Device>
{
  return const_cast<Seat*>(this)->get_keyboard();
}


auto Seat::signal_device_added() -> Glib::SignalProxy<void(const Glib::RefPtr<Device>&)>
{
  return {this, &Seat_signal_device_added_info};
}


auto Seat::signal_device_removed() -> Glib::SignalProxy<void(const Glib::RefPtr<Device>&)>
{
  return {this, &Seat_signal_device_removed_info};
}


auto Seat::signal_tool_added() -> Glib::SignalProxy<void(const Glib::RefPtr<DeviceTool>&)>
{
  return {this, &Seat_signal_tool_added_info};
}


auto Seat::signal_tool_removed() -> Glib::SignalProxy<void(const Glib::RefPtr<DeviceTool>&)>
{
  return {this, &Seat_signal_tool_removed_info};
}


static_assert(Glib::Traits::ValueCompatibleWithWrapProperty<Glib::RefPtr<Display>>::value,
  "Type Glib::RefPtr<Display> cannot be used in _WRAP_PROPERTY. "
  "There is no suitable template specialization of Glib::Value<>.");

auto Seat::property_display() const -> Glib::PropertyProxy_ReadOnly< Glib::RefPtr<Display> >
{
  return {this, "display"};
}


} // namespace Gdk


