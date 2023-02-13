


#include <libmm-glib/mm-glib.hxx>

#include <libmm-gdk/devicetool.hxx>
#include <libmm-gdk/devicetool_p.hxx>

#include <gdk/gdk.h>

/* Copyright (C) 2018 The gtkmm Development Team
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

using Type = Gdk::DeviceTool::Type;

namespace
{
} // anonymous namespace

// static
auto Glib::Value<Gdk::DeviceTool::Type>::value_type() -> GType
{
  return gdk_device_tool_type_get_type();
}


namespace Glib
{

auto wrap(GdkDeviceTool* object, const bool take_copy) -> RefPtr<Gdk::DeviceTool>
{
  return Glib::make_refptr_for_instance<Gdk::DeviceTool>( dynamic_cast<Gdk::DeviceTool*> (wrap_auto((GObject*)object, take_copy)) );
  //We use dynamic_cast<> in case of multiple inheritance.
}

} /* namespace Glib */


namespace Gdk
{


/* The *_Class implementation: */

auto DeviceTool_Class::init() -> const Class&
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Class has to know the class init function to clone custom types.
    class_init_func_ = &DeviceTool_Class::class_init_function;

    // This is actually just optimized away, apparently with no harm.
    // Make sure that the parent type has been created.
    //CppClassParent::CppObjectType::get_type();

    // Create the wrapper type, with the same class/instance size as the base type.
    register_derived_type(gdk_device_tool_get_type());

    // Add derived versions of interfaces, if the C type implements any interfaces:

  }

  return *this;
}


auto DeviceTool_Class::class_init_function (void *g_class, void *class_data) -> void
{
  const auto klass = static_cast<BaseClassType*>(g_class);
  CppClassParent::class_init_function(klass, class_data);


}


auto DeviceTool_Class::wrap_new(GObject* object) -> Glib::ObjectBase*
{
  return new DeviceTool((GdkDeviceTool*)object);
}


/* The implementation: */

auto DeviceTool::gobj_copy() -> GdkDeviceTool*
{
  reference();
  return gobj();
}

DeviceTool::DeviceTool(const Glib::ConstructParams& construct_params)
: Object(construct_params)
{

}

DeviceTool::DeviceTool(GdkDeviceTool* castitem)
: Object((GObject*)castitem)
{}


DeviceTool::DeviceTool(DeviceTool&& src) noexcept
: Object(std::move(src))
{}

auto DeviceTool::operator=(DeviceTool&& src) noexcept -> DeviceTool&
{
  Object::operator=(std::move(src));
  return *this;
}


DeviceTool::~DeviceTool() noexcept = default;

DeviceTool::CppClassType DeviceTool::devicetool_class_; // initialize static member

auto DeviceTool::get_type() -> GType
{
  return devicetool_class_.init().get_type();
}


auto DeviceTool::get_base_type() -> GType
{
  return gdk_device_tool_get_type();
}


auto DeviceTool::get_serial() const -> guint64
{
  return gdk_device_tool_get_serial(const_cast<GdkDeviceTool*>(gobj()));
}

auto DeviceTool::get_hardware_id() const -> guint64
{
  return gdk_device_tool_get_hardware_id(const_cast<GdkDeviceTool*>(gobj()));
}

auto DeviceTool::get_tool_type() const -> Type
{
  return static_cast<Type>(gdk_device_tool_get_tool_type(const_cast<GdkDeviceTool*>(gobj())));
}

auto DeviceTool::get_axes() const -> AxisFlags
{
  return static_cast<AxisFlags>(gdk_device_tool_get_axes(const_cast<GdkDeviceTool*>(gobj())));
}


static_assert(Glib::Traits::ValueCompatibleWithWrapProperty<guint64>::value,
  "Type guint64 cannot be used in _WRAP_PROPERTY. "
  "There is no suitable template specialization of Glib::Value<>.");

auto DeviceTool::property_serial() const -> Glib::PropertyProxy_ReadOnly< guint64 >
{
  return {this, "serial"};
}

static_assert(Glib::Traits::ValueCompatibleWithWrapProperty<Type>::value,
  "Type Type cannot be used in _WRAP_PROPERTY. "
  "There is no suitable template specialization of Glib::Value<>.");

auto DeviceTool::property_tool_type() const -> Glib::PropertyProxy_ReadOnly< Type >
{
  return {this, "tool-type"};
}

static_assert(Glib::Traits::ValueCompatibleWithWrapProperty<AxisFlags>::value,
  "Type AxisFlags cannot be used in _WRAP_PROPERTY. "
  "There is no suitable template specialization of Glib::Value<>.");

auto DeviceTool::property_axes() const -> Glib::PropertyProxy_ReadOnly< AxisFlags >
{
  return {this, "axes"};
}

static_assert(Glib::Traits::ValueCompatibleWithWrapProperty<guint64>::value,
  "Type guint64 cannot be used in _WRAP_PROPERTY. "
  "There is no suitable template specialization of Glib::Value<>.");

auto DeviceTool::property_hardware_id() const -> Glib::PropertyProxy_ReadOnly< guint64 >
{
  return {this, "hardware-id"};
}


} // namespace Gdk


