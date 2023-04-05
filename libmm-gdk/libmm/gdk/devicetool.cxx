// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/gdk/devicetool.hxx>
#include <libmm/gdk/devicetool_p.hxx>

#include <gdk/gdk.h>

using Type = gdk::DeviceTool::Type;

namespace
{
}

auto
glib::Value<gdk::DeviceTool::Type>::value_type () -> GType
{
  return gdk_device_tool_type_get_type ();
}

namespace glib
{

  auto
  wrap (GdkDeviceTool* object, bool take_copy) -> glib::RefPtr<gdk::DeviceTool>
  {
    return glib::make_refptr_for_instance<gdk::DeviceTool> (
        dynamic_cast<gdk::DeviceTool*> (
            glib::wrap_auto ((GObject*) (object), take_copy)));
  }

} // namespace glib

namespace gdk
{

  auto
  DeviceTool_Class::init () -> const glib::Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &DeviceTool_Class::class_init_function;

      register_derived_type (gdk_device_tool_get_type ());
    }

    return *this;
  }

  auto
  DeviceTool_Class::class_init_function (void* g_class, void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);
  }

  auto
  DeviceTool_Class::wrap_new (GObject* object) -> glib::ObjectBase*
  {
    return new DeviceTool ((GdkDeviceTool*) object);
  }

  auto
  DeviceTool::gobj_copy () -> GdkDeviceTool*
  {
    reference ();
    return gobj ();
  }

  DeviceTool::DeviceTool (const glib::ConstructParams& construct_params)
    : glib::Object (construct_params)
  {
  }

  DeviceTool::DeviceTool (GdkDeviceTool* castitem)
    : glib::Object ((GObject*) (castitem))
  {
  }

  DeviceTool::DeviceTool (DeviceTool&& src) noexcept
    : glib::Object (std::move (src))
  {
  }

  auto
  DeviceTool::operator= (DeviceTool&& src) noexcept -> DeviceTool&
  {
    glib::Object::operator= (std::move (src));
    return *this;
  }

  DeviceTool::~DeviceTool () noexcept {}

  DeviceTool::CppClassType DeviceTool::devicetool_class_;

  auto
  DeviceTool::get_type () -> GType
  {
    return devicetool_class_.init ().get_type ();
  }

  auto
  DeviceTool::get_base_type () -> GType
  {
    return gdk_device_tool_get_type ();
  }

  auto
  DeviceTool::get_serial () const -> guint64
  {
    return gdk_device_tool_get_serial (const_cast<GdkDeviceTool*> (gobj ()));
  }

  auto
  DeviceTool::get_hardware_id () const -> guint64
  {
    return gdk_device_tool_get_hardware_id (
        const_cast<GdkDeviceTool*> (gobj ()));
  }

  auto
  DeviceTool::get_tool_type () const -> Type
  {
    return static_cast<Type> (
        gdk_device_tool_get_tool_type (const_cast<GdkDeviceTool*> (gobj ())));
  }

  auto
  DeviceTool::get_axes () const -> AxisFlags
  {
    return static_cast<AxisFlags> (
        gdk_device_tool_get_axes (const_cast<GdkDeviceTool*> (gobj ())));
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<guint64>::value,
      "Type guint64 cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  DeviceTool::property_serial () const -> glib::PropertyProxy_ReadOnly<guint64>
  {
    return glib::PropertyProxy_ReadOnly<guint64> (this, "serial");
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<Type>::value,
      "Type Type cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  DeviceTool::property_tool_type () const -> glib::PropertyProxy_ReadOnly<Type>
  {
    return glib::PropertyProxy_ReadOnly<Type> (this, "tool-type");
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<AxisFlags>::value,
      "Type AxisFlags cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  DeviceTool::property_axes () const -> glib::PropertyProxy_ReadOnly<AxisFlags>
  {
    return glib::PropertyProxy_ReadOnly<AxisFlags> (this, "axes");
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<guint64>::value,
      "Type guint64 cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  DeviceTool::property_hardware_id () const -> glib::PropertyProxy_ReadOnly<guint64>
  {
    return glib::PropertyProxy_ReadOnly<guint64> (this, "hardware-id");
  }

} // namespace gdk
