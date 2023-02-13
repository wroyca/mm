


#include <mm/glib/mm-glib.hpp>

#include <mm/gdk/monitor.hpp>
#include <mm/gdk/private/monitor_p.hpp>


/* Copyright (C) 2016 The gtkmm Development Team
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

#include <mm/gdk/display.hpp>


namespace
{


const Glib::SignalProxyInfo Monitor_signal_invalidate_info =
{
  "invalidate",
  (GCallback) &Glib::SignalProxyNormal::slot0_void_callback,
  (GCallback) &Glib::SignalProxyNormal::slot0_void_callback
};


} // anonymous namespace

// static
auto Glib::Value<Gdk::SubpixelLayout>::value_type() -> GType
{
  return gdk_subpixel_layout_get_type();
}


namespace Glib
{

auto wrap(GdkMonitor* object, const bool take_copy) -> RefPtr<Gdk::Monitor>
{
  return Glib::make_refptr_for_instance<Gdk::Monitor>( dynamic_cast<Gdk::Monitor*> (wrap_auto((GObject*)object, take_copy)) );
  //We use dynamic_cast<> in case of multiple inheritance.
}

} /* namespace Glib */


namespace Gdk
{


/* The *_Class implementation: */

auto Monitor_Class::init() -> const Class&
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Class has to know the class init function to clone custom types.
    class_init_func_ = &Monitor_Class::class_init_function;

    // This is actually just optimized away, apparently with no harm.
    // Make sure that the parent type has been created.
    //CppClassParent::CppObjectType::get_type();

    // Create the wrapper type, with the same class/instance size as the base type.
    register_derived_type(gdk_monitor_get_type());

    // Add derived versions of interfaces, if the C type implements any interfaces:

  }

  return *this;
}


auto Monitor_Class::class_init_function (void *g_class, void *class_data) -> void
{
  const auto klass = static_cast<BaseClassType*>(g_class);
  CppClassParent::class_init_function(klass, class_data);


}


auto Monitor_Class::wrap_new(GObject* object) -> Glib::ObjectBase*
{
  return new Monitor((GdkMonitor*)object);
}


/* The implementation: */

auto Monitor::gobj_copy() -> GdkMonitor*
{
  reference();
  return gobj();
}

Monitor::Monitor(const Glib::ConstructParams& construct_params)
: Object(construct_params)
{

}

Monitor::Monitor(GdkMonitor* castitem)
: Object((GObject*)castitem)
{}


Monitor::Monitor(Monitor&& src) noexcept
: Object(std::move(src))
{}

auto Monitor::operator=(Monitor&& src) noexcept -> Monitor&
{
  Object::operator=(std::move(src));
  return *this;
}


Monitor::~Monitor() noexcept = default;

Monitor::CppClassType Monitor::monitor_class_; // initialize static member

auto Monitor::get_type() -> GType
{
  return monitor_class_.init().get_type();
}


auto Monitor::get_base_type() -> GType
{
  return gdk_monitor_get_type();
}


Monitor::Monitor()
:
  // Mark this class as non-derived to allow C++ vfuncs to be skipped.
ObjectBase(nullptr),
Object(Glib::ConstructParams(monitor_class_.init()))
{


}

auto Monitor::get_display() -> Glib::RefPtr<Display>
{
  auto retvalue = Glib::wrap(gdk_monitor_get_display(gobj()));
  if(retvalue)
    retvalue->reference(); //The function does not do a ref for us.
  return retvalue;
}

auto Monitor::get_display() const -> Glib::RefPtr<const Display>
{
  return const_cast<Monitor*>(this)->get_display();
}

auto Monitor::get_geometry (Rectangle &geometry) const -> void
{
  gdk_monitor_get_geometry(const_cast<GdkMonitor*>(gobj()), geometry.gobj());
}

auto Monitor::get_width_mm() const -> int
{
  return gdk_monitor_get_width_mm(const_cast<GdkMonitor*>(gobj()));
}

auto Monitor::get_height_mm() const -> int
{
  return gdk_monitor_get_height_mm(const_cast<GdkMonitor*>(gobj()));
}

auto Monitor::get_manufacturer() const -> Glib::ustring
{
  return Glib::convert_const_gchar_ptr_to_ustring(gdk_monitor_get_manufacturer(const_cast<GdkMonitor*>(gobj())));
}

auto Monitor::get_model() const -> Glib::ustring
{
  return Glib::convert_const_gchar_ptr_to_ustring(gdk_monitor_get_model(const_cast<GdkMonitor*>(gobj())));
}

auto Monitor::get_connector() const -> Glib::ustring
{
  return Glib::convert_const_gchar_ptr_to_ustring(gdk_monitor_get_connector(const_cast<GdkMonitor*>(gobj())));
}

auto Monitor::get_scale_factor() const -> int
{
  return gdk_monitor_get_scale_factor(const_cast<GdkMonitor*>(gobj()));
}

auto Monitor::get_refresh_rate() const -> int
{
  return gdk_monitor_get_refresh_rate(const_cast<GdkMonitor*>(gobj()));
}

auto Monitor::get_subpixel_layout() const -> SubpixelLayout
{
  return static_cast<SubpixelLayout>(gdk_monitor_get_subpixel_layout(const_cast<GdkMonitor*>(gobj())));
}

auto Monitor::is_valid() const -> bool
{
  return gdk_monitor_is_valid(const_cast<GdkMonitor*>(gobj()));
}


auto Monitor::signal_invalidate() -> Glib::SignalProxy<void()>
{
  return {this, &Monitor_signal_invalidate_info};
}


static_assert(Glib::Traits::ValueCompatibleWithWrapProperty<Glib::RefPtr<Display>>::value,
  "Type Glib::RefPtr<Display> cannot be used in _WRAP_PROPERTY. "
  "There is no suitable template specialization of Glib::Value<>.");

auto Monitor::property_display() const -> Glib::PropertyProxy_ReadOnly< Glib::RefPtr<Display> >
{
  return {this, "display"};
}

auto Monitor::property_manufacturer() const -> Glib::PropertyProxy_ReadOnly< Glib::ustring >
{
  return {this, "manufacturer"};
}

auto Monitor::property_model() const -> Glib::PropertyProxy_ReadOnly< Glib::ustring >
{
  return {this, "model"};
}

auto Monitor::property_connector() const -> Glib::PropertyProxy_ReadOnly< Glib::ustring >
{
  return {this, "connector"};
}

auto Monitor::property_scale_factor() const -> Glib::PropertyProxy_ReadOnly< int >
{
  return {this, "scale-factor"};
}

static_assert(Glib::Traits::ValueCompatibleWithWrapProperty<Rectangle>::value,
  "Type Gdk::Rectangle cannot be used in _WRAP_PROPERTY. "
  "There is no suitable template specialization of Glib::Value<>.");

auto Monitor::property_geometry() const -> Glib::PropertyProxy_ReadOnly<Rectangle>
{
  return {this, "geometry"};
}

auto Monitor::property_width_mm() const -> Glib::PropertyProxy_ReadOnly< int >
{
  return {this, "width-mm"};
}

auto Monitor::property_height_mm() const -> Glib::PropertyProxy_ReadOnly< int >
{
  return {this, "height-mm"};
}

auto Monitor::property_refresh_rate() const -> Glib::PropertyProxy_ReadOnly< int >
{
  return {this, "refresh-rate"};
}

static_assert(Glib::Traits::ValueCompatibleWithWrapProperty<SubpixelLayout>::value,
  "Type SubpixelLayout cannot be used in _WRAP_PROPERTY. "
  "There is no suitable template specialization of Glib::Value<>.");

auto Monitor::property_subpixel_layout() const -> Glib::PropertyProxy_ReadOnly< SubpixelLayout >
{
  return {this, "subpixel-layout"};
}

auto Monitor::property_valid() const -> Glib::PropertyProxy_ReadOnly< bool >
{
  return {this, "valid"};
}


} // namespace Gdk


