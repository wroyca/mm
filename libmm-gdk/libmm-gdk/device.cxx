// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm-glib/mm-glib.hxx>

#include <libmm-gdk/device.hxx>
#include <libmm-gdk/device_p.hxx>

#include <gdk/gdk.h>
#include <libmm-gdk/cursor.hxx>
#include <libmm-gdk/devicetool.hxx>
#include <libmm-gdk/devicewithpad.hxx>
#include <libmm-gdk/display.hxx>
#include <libmm-gdk/seat.hxx>
#include <libmm-gdk/surface.hxx>

namespace Gdk
{

  auto
  Device::get_surface_at_position () -> Glib::RefPtr<Surface>
  {
    auto retvalue = Glib::wrap (
        gdk_device_get_surface_at_position (gobj (), nullptr, nullptr));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  Device::get_surface_at_position () const -> Glib::RefPtr<const Surface>
  {
    return const_cast<Device*> (this)->get_surface_at_position ();
  }

  G_GNUC_BEGIN_IGNORE_DEPRECATIONS
  auto
  Device::get_device_tool () -> Glib::RefPtr<DeviceTool>
  {
    auto retvalue = Glib::wrap (gdk_device_get_device_tool (gobj ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  Device::get_device_tool () const -> Glib::RefPtr<const DeviceTool>
  {
    return const_cast<Device*> (this)->get_device_tool ();
  }

  G_GNUC_END_IGNORE_DEPRECATIONS

  auto
  Device_Class::wrap_new (GObject* object) -> Glib::ObjectBase*
  {
    if (GDK_IS_DEVICE_PAD (object))
      return new DeviceWithPad ((GdkDevice*) object);
    return new Device ((GdkDevice*) object);
  }

  auto
  Device::has_device_pad () const -> bool
  {
    return dynamic_cast<const DeviceWithPad*> (this) != nullptr;
  }

  auto
  Device::device_with_pad_cast () -> Glib::RefPtr<DeviceWithPad>
  {
    auto retvalue = Glib::make_refptr_for_instance<DeviceWithPad> (
        dynamic_cast<DeviceWithPad*> (this));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  Device::device_with_pad_cast () const -> Glib::RefPtr<const DeviceWithPad>
  {
    return const_cast<Device*> (this)->device_with_pad_cast ();
  }

} // namespace Gdk

namespace
{

  const Glib::SignalProxyInfo Device_signal_changed_info = {
      "changed",
      (GCallback) &Glib::SignalProxyNormal::slot0_void_callback,
      (GCallback) &Glib::SignalProxyNormal::slot0_void_callback};

  auto
  Device_signal_tool_changed_callback (GdkDevice* self,
                                       GdkDeviceTool* p0,
                                       void* data) -> void
  {
    using namespace Gdk;
    using SlotType = sigc::slot<void (const Glib::RefPtr<DeviceTool>&)>;

    const auto obj = dynamic_cast<Device*> (
        Glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj)
    {
      try
      {
        if (const auto slot = Glib::SignalProxyNormal::data_to_slot (data))
          (*static_cast<SlotType*> (slot)) (Glib::wrap (p0, true));
      }
      catch (...)
      {
        Glib::exception_handlers_invoke ();
      }
    }
  }

  const Glib::SignalProxyInfo Device_signal_tool_changed_info = {
      "tool-changed",
      (GCallback) &Device_signal_tool_changed_callback,
      (GCallback) &Device_signal_tool_changed_callback};

} // namespace

auto
Glib::Value<Gdk::InputSource>::value_type () -> GType
{
  return gdk_input_source_get_type ();
}

namespace Glib
{

  auto
  wrap (GdkDevice* object, const bool take_copy) -> RefPtr<Gdk::Device>
  {
    return Glib::make_refptr_for_instance<Gdk::Device> (
        dynamic_cast<Gdk::Device*> (wrap_auto ((GObject*) object, take_copy)));
  }

} // namespace Glib

namespace Gdk
{

  auto
  Device_Class::init () -> const Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &Device_Class::class_init_function;

      register_derived_type (gdk_device_get_type ());
    }

    return *this;
  }

  auto
  Device_Class::class_init_function (void* g_class, void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);
  }

  auto
  Device::gobj_copy () -> GdkDevice*
  {
    reference ();
    return gobj ();
  }

  Device::Device (const Glib::ConstructParams& construct_params)
    : Object (construct_params)
  {
  }

  Device::Device (GdkDevice* castitem)
    : Object ((GObject*) castitem)
  {
  }

  Device::Device (Device&& src) noexcept
    : Object (std::move (src))
  {
  }

  auto
  Device::operator= (Device&& src) noexcept -> Device&
  {
    Object::operator= (std::move (src));
    return *this;
  }

  Device::~Device () noexcept = default;

  Device::CppClassType Device::device_class_;

  auto
  Device::get_type () -> GType
  {
    return device_class_.init ().get_type ();
  }

  auto
  Device::get_base_type () -> GType
  {
    return gdk_device_get_type ();
  }

  Device::Device ()
    : ObjectBase (nullptr),
      Object (Glib::ConstructParams (device_class_.init ()))
  {
  }

  auto
  Device::get_name () const -> Glib::ustring
  {
    return Glib::convert_const_gchar_ptr_to_ustring (
        gdk_device_get_name (const_cast<GdkDevice*> (gobj ())));
  }

  auto
  Device::get_has_cursor () const -> bool
  {
    return gdk_device_get_has_cursor (const_cast<GdkDevice*> (gobj ()));
  }

  auto
  Device::get_source () const -> InputSource
  {
    return static_cast<InputSource> (
        gdk_device_get_source (const_cast<GdkDevice*> (gobj ())));
  }

  auto
  Device::get_display () -> Glib::RefPtr<Display>
  {
    auto retvalue = Glib::wrap (gdk_device_get_display (gobj ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  Device::get_display () const -> Glib::RefPtr<const Display>
  {
    return const_cast<Device*> (this)->get_display ();
  }

  auto
  Device::get_surface_at_position (double& win_x, double& win_y) -> Glib::RefPtr<Surface>
  {
    auto retvalue = Glib::wrap (
        gdk_device_get_surface_at_position (gobj (), &win_x, &win_y));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  Device::get_surface_at_position (double& win_x, double& win_y) const -> Glib::RefPtr<const Surface>
  {
    return const_cast<Device*> (this)->get_surface_at_position (win_x, win_y);
  }

  auto
  Device::get_vendor_id () const -> Glib::ustring
  {
    return Glib::convert_const_gchar_ptr_to_ustring (
        gdk_device_get_vendor_id (const_cast<GdkDevice*> (gobj ())));
  }

  auto
  Device::get_product_id () -> Glib::ustring
  {
    return Glib::convert_const_gchar_ptr_to_ustring (
        gdk_device_get_product_id (gobj ()));
  }

  auto
  Device::get_seat () -> Glib::RefPtr<Seat>
  {
    auto retvalue = Glib::wrap (gdk_device_get_seat (gobj ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  Device::get_seat () const -> Glib::RefPtr<const Seat>
  {
    return const_cast<Device*> (this)->get_seat ();
  }

  auto
  Device::get_num_touches () const -> guint
  {
    return gdk_device_get_num_touches (const_cast<GdkDevice*> (gobj ()));
  }

  auto
  Device::get_caps_lock_state () const -> bool
  {
    return gdk_device_get_caps_lock_state (const_cast<GdkDevice*> (gobj ()));
  }

  auto
  Device::get_num_lock_state () const -> bool
  {
    return gdk_device_get_num_lock_state (const_cast<GdkDevice*> (gobj ()));
  }

  auto
  Device::get_scroll_lock_state () const -> bool
  {
    return gdk_device_get_scroll_lock_state (const_cast<GdkDevice*> (gobj ()));
  }

  auto
  Device::get_modifier_state () const -> ModifierType
  {
    return static_cast<ModifierType> (
        gdk_device_get_modifier_state (const_cast<GdkDevice*> (gobj ())));
  }

  auto
  Device::get_direction () const -> Pango::Direction
  {
    return static_cast<Pango::Direction> (
        gdk_device_get_direction (const_cast<GdkDevice*> (gobj ())));
  }

  auto
  Device::has_bidi_layouts () const -> bool
  {
    return gdk_device_has_bidi_layouts (const_cast<GdkDevice*> (gobj ()));
  }

  auto
  Device::get_timestamp () const -> guint32
  {
    return gdk_device_get_timestamp (const_cast<GdkDevice*> (gobj ()));
  }

  auto
  Device::signal_changed () -> Glib::SignalProxy<void ()>
  {
    return {this, &Device_signal_changed_info};
  }

  auto
  Device::signal_tool_changed () -> Glib::SignalProxy<void (const Glib::RefPtr<DeviceTool>&)>
  {
    return {this, &Device_signal_tool_changed_info};
  }

  static_assert (
      Glib::Traits::ValueCompatibleWithWrapProperty<
          Glib::RefPtr<Display>>::value,
      "Type Glib::RefPtr<Display> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  auto
  Device::property_display () const -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<Display>>
  {
    return {this, "display"};
  }

  auto
  Device::property_name () const -> Glib::PropertyProxy_ReadOnly<Glib::ustring>
  {
    return {this, "name"};
  }

  static_assert (
      Glib::Traits::ValueCompatibleWithWrapProperty<InputSource>::value,
      "Type InputSource cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  auto
  Device::property_source () const -> Glib::PropertyProxy_ReadOnly<InputSource>
  {
    return {this, "source"};
  }

  auto
  Device::property_has_cursor () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return {this, "has-cursor"};
  }

  auto
  Device::property_n_axes () const -> Glib::PropertyProxy_ReadOnly<guint>
  {
    return {this, "n-axes"};
  }

  auto
  Device::property_vendor_id () const -> Glib::PropertyProxy_ReadOnly<Glib::ustring>
  {
    return {this, "vendor-id"};
  }

  auto
  Device::property_product_id () const -> Glib::PropertyProxy_ReadOnly<Glib::ustring>
  {
    return {this, "product-id"};
  }

  static_assert (
      Glib::Traits::ValueCompatibleWithWrapProperty<Glib::RefPtr<Seat>>::value,
      "Type Glib::RefPtr<Seat> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  auto
  Device::property_seat () -> Glib::PropertyProxy<Glib::RefPtr<Seat>>
  {
    return {this, "seat"};
  }

  auto
  Device::property_seat () const -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<Seat>>
  {
    return {this, "seat"};
  }

  auto
  Device::property_num_touches () const -> Glib::PropertyProxy_ReadOnly<guint>
  {
    return {this, "num-touches"};
  }

  static_assert (
      Glib::Traits::ValueCompatibleWithWrapProperty<
          Glib::RefPtr<DeviceTool>>::value,
      "Type Glib::RefPtr<DeviceTool> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  auto
  Device::property_tool () const -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<DeviceTool>>
  {
    return {this, "tool"};
  }

  static_assert (
      Glib::Traits::ValueCompatibleWithWrapProperty<Pango::Direction>::value,
      "Type Pango::Direction cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  auto
  Device::property_direction () const -> Glib::PropertyProxy_ReadOnly<Pango::Direction>
  {
    return {this, "direction"};
  }

  auto
  Device::property_has_bidi_layouts () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return {this, "has-bidi-layouts"};
  }

  auto
  Device::property_caps_lock_state () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return {this, "caps-lock-state"};
  }

  auto
  Device::property_num_lock_state () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return {this, "num-lock-state"};
  }

  auto
  Device::property_scroll_lock_state () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return {this, "scroll-lock-state"};
  }

  static_assert (
      Glib::Traits::ValueCompatibleWithWrapProperty<ModifierType>::value,
      "Type ModifierType cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  auto
  Device::property_modifier_state () const -> Glib::PropertyProxy_ReadOnly<ModifierType>
  {
    return {this, "modifier-state"};
  }

} // namespace Gdk
