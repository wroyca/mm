// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/gdk/device.hxx>
#include <libmm/gdk/device_p.hxx>

#include <gdk/gdk.h>
#include <libmm/gdk/cursor.hxx>
#include <libmm/gdk/devicetool.hxx>
#include <libmm/gdk/devicewithpad.hxx>
#include <libmm/gdk/display.hxx>
#include <libmm/gdk/seat.hxx>
#include <libmm/gdk/surface.hxx>

namespace gdk
{

  auto
  Device::get_surface_at_position () -> glib::RefPtr<Surface>
  {
    auto retvalue = glib::wrap (
        gdk_device_get_surface_at_position (gobj (), nullptr, nullptr));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  Device::get_surface_at_position () const -> glib::RefPtr<const Surface>
  {
    return const_cast<Device*> (this)->get_surface_at_position ();
  }

  G_GNUC_BEGIN_IGNORE_DEPRECATIONS
  auto
  Device::get_device_tool () -> glib::RefPtr<DeviceTool>
  {
    auto retvalue = glib::wrap (gdk_device_get_device_tool (gobj ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  Device::get_device_tool () const -> glib::RefPtr<const DeviceTool>
  {
    return const_cast<Device*> (this)->get_device_tool ();
  }

  G_GNUC_END_IGNORE_DEPRECATIONS

  auto
  Device_Class::wrap_new (GObject* object) -> glib::ObjectBase*
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
  Device::device_with_pad_cast () -> glib::RefPtr<DeviceWithPad>
  {
    auto retvalue = glib::make_refptr_for_instance<DeviceWithPad> (
        dynamic_cast<DeviceWithPad*> (this));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  Device::device_with_pad_cast () const -> glib::RefPtr<const DeviceWithPad>
  {
    return const_cast<Device*> (this)->device_with_pad_cast ();
  }

} // namespace gdk

namespace
{

  static const glib::SignalProxyInfo Device_signal_changed_info = {
      "changed",
      (GCallback) &glib::SignalProxyNormal::slot0_void_callback,
      (GCallback) &glib::SignalProxyNormal::slot0_void_callback};

  static auto
  Device_signal_tool_changed_callback (GdkDevice* self,
                                       GdkDeviceTool* p0,
                                       void* data) -> void
  {
    using namespace gdk;
    using SlotType = sigc::slot<void (const glib::RefPtr<DeviceTool>&)>;

    auto obj = dynamic_cast<Device*> (
        glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj)
    {
      try
      {
        if (const auto slot = glib::SignalProxyNormal::data_to_slot (data))
          (*static_cast<SlotType*> (slot)) (glib::wrap (p0, true));
      }
      catch (...)
      {
        glib::exception_handlers_invoke ();
      }
    }
  }

  static const glib::SignalProxyInfo Device_signal_tool_changed_info = {
      "tool-changed",
      (GCallback) &Device_signal_tool_changed_callback,
      (GCallback) &Device_signal_tool_changed_callback};

} // namespace

auto
glib::Value<gdk::InputSource>::value_type () -> GType
{
  return gdk_input_source_get_type ();
}

namespace glib
{

  auto
  wrap (GdkDevice* object, bool take_copy) -> glib::RefPtr<gdk::Device>
  {
    return glib::make_refptr_for_instance<gdk::Device> (
        dynamic_cast<gdk::Device*> (
            glib::wrap_auto ((GObject*) (object), take_copy)));
  }

} // namespace glib

namespace gdk
{

  auto
  Device_Class::init () -> const glib::Class&
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

  Device::Device (const glib::ConstructParams& construct_params)
    : glib::Object (construct_params)
  {
  }

  Device::Device (GdkDevice* castitem)
    : glib::Object ((GObject*) (castitem))
  {
  }

  Device::Device (Device&& src) noexcept
    : glib::Object (std::move (src))
  {
  }

  auto
  Device::operator= (Device&& src) noexcept -> Device&
  {
    glib::Object::operator= (std::move (src));
    return *this;
  }

  Device::~Device () noexcept {}

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
    : glib::ObjectBase (nullptr),
      glib::Object (glib::ConstructParams (device_class_.init ()))
  {
  }

  auto
  Device::get_name () const -> glib::ustring
  {
    return glib::convert_const_gchar_ptr_to_ustring (
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
  Device::get_display () -> glib::RefPtr<Display>
  {
    auto retvalue = glib::wrap (gdk_device_get_display (gobj ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  Device::get_display () const -> glib::RefPtr<const Display>
  {
    return const_cast<Device*> (this)->get_display ();
  }

  auto
  Device::get_surface_at_position (double& win_x, double& win_y) -> glib::RefPtr<Surface>
  {
    auto retvalue = glib::wrap (
        gdk_device_get_surface_at_position (gobj (), &(win_x), &(win_y)));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  Device::get_surface_at_position (double& win_x, double& win_y) const -> glib::RefPtr<const Surface>
  {
    return const_cast<Device*> (this)->get_surface_at_position (win_x, win_y);
  }

  auto
  Device::get_vendor_id () const -> glib::ustring
  {
    return glib::convert_const_gchar_ptr_to_ustring (
        gdk_device_get_vendor_id (const_cast<GdkDevice*> (gobj ())));
  }

  auto
  Device::get_product_id () -> glib::ustring
  {
    return glib::convert_const_gchar_ptr_to_ustring (
        gdk_device_get_product_id (gobj ()));
  }

  auto
  Device::get_seat () -> glib::RefPtr<Seat>
  {
    auto retvalue = glib::wrap (gdk_device_get_seat (gobj ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  Device::get_seat () const -> glib::RefPtr<const Seat>
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
  Device::get_direction () const -> pango::Direction
  {
    return static_cast<pango::Direction> (
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
  Device::signal_changed () -> glib::SignalProxy<void ()>
  {
    return glib::SignalProxy<void ()> (this, &Device_signal_changed_info);
  }

  auto
  Device::signal_tool_changed () -> glib::SignalProxy<void (const glib::RefPtr<DeviceTool>&)>
  {
    return glib::SignalProxy<void (const glib::RefPtr<DeviceTool>&)> (
        this,
        &Device_signal_tool_changed_info);
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<
          glib::RefPtr<Display>>::value,
      "Type glib::RefPtr<Display> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  Device::property_display () const -> glib::PropertyProxy_ReadOnly<glib::RefPtr<Display>>
  {
    return glib::PropertyProxy_ReadOnly<glib::RefPtr<Display>> (this,
                                                                "display");
  }

  auto
  Device::property_name () const -> glib::PropertyProxy_ReadOnly<glib::ustring>
  {
    return glib::PropertyProxy_ReadOnly<glib::ustring> (this, "name");
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<InputSource>::value,
      "Type InputSource cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  Device::property_source () const -> glib::PropertyProxy_ReadOnly<InputSource>
  {
    return glib::PropertyProxy_ReadOnly<InputSource> (this, "source");
  }

  auto
  Device::property_has_cursor () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "has-cursor");
  }

  auto
  Device::property_n_axes () const -> glib::PropertyProxy_ReadOnly<guint>
  {
    return glib::PropertyProxy_ReadOnly<guint> (this, "n-axes");
  }

  auto
  Device::property_vendor_id () const -> glib::PropertyProxy_ReadOnly<glib::ustring>
  {
    return glib::PropertyProxy_ReadOnly<glib::ustring> (this, "vendor-id");
  }

  auto
  Device::property_product_id () const -> glib::PropertyProxy_ReadOnly<glib::ustring>
  {
    return glib::PropertyProxy_ReadOnly<glib::ustring> (this, "product-id");
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<glib::RefPtr<Seat>>::value,
      "Type glib::RefPtr<Seat> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  Device::property_seat () -> glib::PropertyProxy<glib::RefPtr<Seat>>
  {
    return glib::PropertyProxy<glib::RefPtr<Seat>> (this, "seat");
  }

  auto
  Device::property_seat () const -> glib::PropertyProxy_ReadOnly<glib::RefPtr<Seat>>
  {
    return glib::PropertyProxy_ReadOnly<glib::RefPtr<Seat>> (this, "seat");
  }

  auto
  Device::property_num_touches () const -> glib::PropertyProxy_ReadOnly<guint>
  {
    return glib::PropertyProxy_ReadOnly<guint> (this, "num-touches");
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<
          glib::RefPtr<DeviceTool>>::value,
      "Type glib::RefPtr<DeviceTool> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  Device::property_tool () const -> glib::PropertyProxy_ReadOnly<glib::RefPtr<DeviceTool>>
  {
    return glib::PropertyProxy_ReadOnly<glib::RefPtr<DeviceTool>> (this,
                                                                   "tool");
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<pango::Direction>::value,
      "Type pango::Direction cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  Device::property_direction () const -> glib::PropertyProxy_ReadOnly<pango::Direction>
  {
    return glib::PropertyProxy_ReadOnly<pango::Direction> (this, "direction");
  }

  auto
  Device::property_has_bidi_layouts () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "has-bidi-layouts");
  }

  auto
  Device::property_caps_lock_state () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "caps-lock-state");
  }

  auto
  Device::property_num_lock_state () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "num-lock-state");
  }

  auto
  Device::property_scroll_lock_state () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "scroll-lock-state");
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<ModifierType>::value,
      "Type ModifierType cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  Device::property_modifier_state () const -> glib::PropertyProxy_ReadOnly<ModifierType>
  {
    return glib::PropertyProxy_ReadOnly<ModifierType> (this, "modifier-state");
  }

} // namespace gdk
