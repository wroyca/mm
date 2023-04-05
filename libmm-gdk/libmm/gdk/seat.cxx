// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/gdk/seat.hxx>
#include <libmm/gdk/seat_p.hxx>

#include <libmm/gdk/devicetool.hxx>
#include <libmm/gdk/display.hxx>
#include <libmm/gdk/surface.hxx>

using Capabilities = gdk::Seat::Capabilities;

namespace
{

  static auto
  Seat_signal_device_added_callback (GdkSeat* self, GdkDevice* p0, void* data) -> void
  {
    using namespace gdk;
    using SlotType = sigc::slot<void (const glib::RefPtr<Device>&)>;

    auto obj = dynamic_cast<Seat*> (
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

  static const glib::SignalProxyInfo Seat_signal_device_added_info = {
      "device-added",
      (GCallback) &Seat_signal_device_added_callback,
      (GCallback) &Seat_signal_device_added_callback};

  static auto
  Seat_signal_device_removed_callback (GdkSeat* self, GdkDevice* p0, void* data) -> void
  {
    using namespace gdk;
    using SlotType = sigc::slot<void (const glib::RefPtr<Device>&)>;

    auto obj = dynamic_cast<Seat*> (
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

  static const glib::SignalProxyInfo Seat_signal_device_removed_info = {
      "device-removed",
      (GCallback) &Seat_signal_device_removed_callback,
      (GCallback) &Seat_signal_device_removed_callback};

  static auto
  Seat_signal_tool_added_callback (GdkSeat* self, GdkDeviceTool* p0, void* data) -> void
  {
    using namespace gdk;
    using SlotType = sigc::slot<void (const glib::RefPtr<DeviceTool>&)>;

    auto obj = dynamic_cast<Seat*> (
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

  static const glib::SignalProxyInfo Seat_signal_tool_added_info = {
      "tool-added",
      (GCallback) &Seat_signal_tool_added_callback,
      (GCallback) &Seat_signal_tool_added_callback};

  static auto
  Seat_signal_tool_removed_callback (GdkSeat* self,
                                     GdkDeviceTool* p0,
                                     void* data) -> void
  {
    using namespace gdk;
    using SlotType = sigc::slot<void (const glib::RefPtr<DeviceTool>&)>;

    auto obj = dynamic_cast<Seat*> (
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

  static const glib::SignalProxyInfo Seat_signal_tool_removed_info = {
      "tool-removed",
      (GCallback) &Seat_signal_tool_removed_callback,
      (GCallback) &Seat_signal_tool_removed_callback};

} // namespace

auto
glib::Value<gdk::Seat::Capabilities>::value_type () -> GType
{
  return gdk_seat_capabilities_get_type ();
}

namespace glib
{

  auto
  wrap (GdkSeat* object, bool take_copy) -> glib::RefPtr<gdk::Seat>
  {
    return glib::make_refptr_for_instance<gdk::Seat> (dynamic_cast<gdk::Seat*> (
        glib::wrap_auto ((GObject*) (object), take_copy)));
  }

} // namespace glib

namespace gdk
{

  auto
  Seat_Class::init () -> const glib::Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &Seat_Class::class_init_function;

      register_derived_type (gdk_seat_get_type ());
    }

    return *this;
  }

  auto
  Seat_Class::class_init_function (void* g_class, void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);
  }

  auto
  Seat_Class::wrap_new (GObject* object) -> glib::ObjectBase*
  {
    return new Seat ((GdkSeat*) object);
  }

  auto
  Seat::gobj_copy () -> GdkSeat*
  {
    reference ();
    return gobj ();
  }

  Seat::Seat (const glib::ConstructParams& construct_params)
    : glib::Object (construct_params)
  {
  }

  Seat::Seat (GdkSeat* castitem)
    : glib::Object ((GObject*) (castitem))
  {
  }

  Seat::Seat (Seat&& src) noexcept
    : glib::Object (std::move (src))
  {
  }

  auto
  Seat::operator= (Seat&& src) noexcept -> Seat&
  {
    glib::Object::operator= (std::move (src));
    return *this;
  }

  Seat::~Seat () noexcept {}

  Seat::CppClassType Seat::seat_class_;

  auto
  Seat::get_type () -> GType
  {
    return seat_class_.init ().get_type ();
  }

  auto
  Seat::get_base_type () -> GType
  {
    return gdk_seat_get_type ();
  }

  Seat::Seat ()
    : glib::ObjectBase (nullptr),
      glib::Object (glib::ConstructParams (seat_class_.init ()))
  {
  }

  auto
  Seat::get_display () -> glib::RefPtr<Display>
  {
    auto retvalue = glib::wrap (gdk_seat_get_display (gobj ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  Seat::get_display () const -> glib::RefPtr<const Display>
  {
    return const_cast<Seat*> (this)->get_display ();
  }

  auto
  Seat::get_capabilities () const -> Capabilities
  {
    return static_cast<Capabilities> (
        gdk_seat_get_capabilities (const_cast<GdkSeat*> (gobj ())));
  }

  auto
  Seat::get_devices (Capabilities capabilities) -> std::vector<glib::RefPtr<Device>>
  {
    return glib::ListHandler<glib::RefPtr<Device>>::list_to_vector (
        gdk_seat_get_devices (gobj (),
                              static_cast<GdkSeatCapabilities> (capabilities)),
        glib::OWNERSHIP_SHALLOW);
  }

  auto
  Seat::get_devices (Capabilities capabilities) const -> std::vector<glib::RefPtr<const Device>>
  {
    return glib::ListHandler<glib::RefPtr<const Device>>::list_to_vector (
        gdk_seat_get_devices (const_cast<GdkSeat*> (gobj ()),
                              static_cast<GdkSeatCapabilities> (capabilities)),
        glib::OWNERSHIP_SHALLOW);
  }

  auto
  Seat::get_tools () -> std::vector<glib::RefPtr<DeviceTool>>
  {
    return glib::ListHandler<glib::RefPtr<DeviceTool>>::list_to_vector (
        gdk_seat_get_tools (gobj ()),
        glib::OWNERSHIP_SHALLOW);
  }

  auto
  Seat::get_tools () const -> std::vector<glib::RefPtr<const DeviceTool>>
  {
    return glib::ListHandler<glib::RefPtr<const DeviceTool>>::list_to_vector (
        gdk_seat_get_tools (const_cast<GdkSeat*> (gobj ())),
        glib::OWNERSHIP_SHALLOW);
  }

  auto
  Seat::get_pointer () -> glib::RefPtr<Device>
  {
    auto retvalue = glib::wrap (gdk_seat_get_pointer (gobj ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  Seat::get_pointer () const -> glib::RefPtr<const Device>
  {
    return const_cast<Seat*> (this)->get_pointer ();
  }

  auto
  Seat::get_keyboard () -> glib::RefPtr<Device>
  {
    auto retvalue = glib::wrap (gdk_seat_get_keyboard (gobj ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  Seat::get_keyboard () const -> glib::RefPtr<const Device>
  {
    return const_cast<Seat*> (this)->get_keyboard ();
  }

  auto
  Seat::signal_device_added () -> glib::SignalProxy<void (const glib::RefPtr<Device>&)>
  {
    return glib::SignalProxy<void (const glib::RefPtr<Device>&)> (
        this,
        &Seat_signal_device_added_info);
  }

  auto
  Seat::signal_device_removed () -> glib::SignalProxy<void (const glib::RefPtr<Device>&)>
  {
    return glib::SignalProxy<void (const glib::RefPtr<Device>&)> (
        this,
        &Seat_signal_device_removed_info);
  }

  auto
  Seat::signal_tool_added () -> glib::SignalProxy<void (const glib::RefPtr<DeviceTool>&)>
  {
    return glib::SignalProxy<void (const glib::RefPtr<DeviceTool>&)> (
        this,
        &Seat_signal_tool_added_info);
  }

  auto
  Seat::signal_tool_removed () -> glib::SignalProxy<void (const glib::RefPtr<DeviceTool>&)>
  {
    return glib::SignalProxy<void (const glib::RefPtr<DeviceTool>&)> (
        this,
        &Seat_signal_tool_removed_info);
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<
          glib::RefPtr<Display>>::value,
      "Type glib::RefPtr<Display> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  Seat::property_display () const -> glib::PropertyProxy_ReadOnly<glib::RefPtr<Display>>
  {
    return glib::PropertyProxy_ReadOnly<glib::RefPtr<Display>> (this,
                                                                "display");
  }

} // namespace gdk
