// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/gdk/seat.hxx>
#include <libmm/gdk/seat_p.hxx>

#include <libmm/gdk/devicetool.hxx>
#include <libmm/gdk/display.hxx>
#include <libmm/gdk/surface.hxx>

using Capabilities = Gdk::Seat::Capabilities;

namespace
{

  static auto
  Seat_signal_device_added_callback (GdkSeat* self, GdkDevice* p0, void* data) -> void
  {
    using namespace Gdk;
    using SlotType = sigc::slot<void (const Glib::RefPtr<Device>&)>;

    auto obj = dynamic_cast<Seat*> (
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

  static const Glib::SignalProxyInfo Seat_signal_device_added_info = {
      "device-added",
      (GCallback) &Seat_signal_device_added_callback,
      (GCallback) &Seat_signal_device_added_callback};

  static auto
  Seat_signal_device_removed_callback (GdkSeat* self, GdkDevice* p0, void* data) -> void
  {
    using namespace Gdk;
    using SlotType = sigc::slot<void (const Glib::RefPtr<Device>&)>;

    auto obj = dynamic_cast<Seat*> (
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

  static const Glib::SignalProxyInfo Seat_signal_device_removed_info = {
      "device-removed",
      (GCallback) &Seat_signal_device_removed_callback,
      (GCallback) &Seat_signal_device_removed_callback};

  static auto
  Seat_signal_tool_added_callback (GdkSeat* self, GdkDeviceTool* p0, void* data) -> void
  {
    using namespace Gdk;
    using SlotType = sigc::slot<void (const Glib::RefPtr<DeviceTool>&)>;

    auto obj = dynamic_cast<Seat*> (
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

  static const Glib::SignalProxyInfo Seat_signal_tool_added_info = {
      "tool-added",
      (GCallback) &Seat_signal_tool_added_callback,
      (GCallback) &Seat_signal_tool_added_callback};

  static auto
  Seat_signal_tool_removed_callback (GdkSeat* self,
                                     GdkDeviceTool* p0,
                                     void* data) -> void
  {
    using namespace Gdk;
    using SlotType = sigc::slot<void (const Glib::RefPtr<DeviceTool>&)>;

    auto obj = dynamic_cast<Seat*> (
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

  static const Glib::SignalProxyInfo Seat_signal_tool_removed_info = {
      "tool-removed",
      (GCallback) &Seat_signal_tool_removed_callback,
      (GCallback) &Seat_signal_tool_removed_callback};

} // namespace

auto
Glib::Value<Gdk::Seat::Capabilities>::value_type () -> GType
{
  return gdk_seat_capabilities_get_type ();
}

namespace Glib
{

  auto
  wrap (GdkSeat* object, bool take_copy) -> Glib::RefPtr<Gdk::Seat>
  {
    return Glib::make_refptr_for_instance<Gdk::Seat> (dynamic_cast<Gdk::Seat*> (
        Glib::wrap_auto ((GObject*) (object), take_copy)));
  }

} // namespace Glib

namespace Gdk
{

  auto
  Seat_Class::init () -> const Glib::Class&
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
  Seat_Class::wrap_new (GObject* object) -> Glib::ObjectBase*
  {
    return new Seat ((GdkSeat*) object);
  }

  auto
  Seat::gobj_copy () -> GdkSeat*
  {
    reference ();
    return gobj ();
  }

  Seat::Seat (const Glib::ConstructParams& construct_params)
    : Glib::Object (construct_params)
  {
  }

  Seat::Seat (GdkSeat* castitem)
    : Glib::Object ((GObject*) (castitem))
  {
  }

  Seat::Seat (Seat&& src) noexcept
    : Glib::Object (std::move (src))
  {
  }

  auto
  Seat::operator= (Seat&& src) noexcept -> Seat&
  {
    Glib::Object::operator= (std::move (src));
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
    : Glib::ObjectBase (nullptr),
      Glib::Object (Glib::ConstructParams (seat_class_.init ()))
  {
  }

  auto
  Seat::get_display () -> Glib::RefPtr<Display>
  {
    auto retvalue = Glib::wrap (gdk_seat_get_display (gobj ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  Seat::get_display () const -> Glib::RefPtr<const Display>
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
  Seat::get_devices (Capabilities capabilities) -> std::vector<Glib::RefPtr<Device>>
  {
    return Glib::ListHandler<Glib::RefPtr<Device>>::list_to_vector (
        gdk_seat_get_devices (gobj (),
                              static_cast<GdkSeatCapabilities> (capabilities)),
        Glib::OWNERSHIP_SHALLOW);
  }

  auto
  Seat::get_devices (Capabilities capabilities) const -> std::vector<Glib::RefPtr<const Device>>
  {
    return Glib::ListHandler<Glib::RefPtr<const Device>>::list_to_vector (
        gdk_seat_get_devices (const_cast<GdkSeat*> (gobj ()),
                              static_cast<GdkSeatCapabilities> (capabilities)),
        Glib::OWNERSHIP_SHALLOW);
  }

  auto
  Seat::get_tools () -> std::vector<Glib::RefPtr<DeviceTool>>
  {
    return Glib::ListHandler<Glib::RefPtr<DeviceTool>>::list_to_vector (
        gdk_seat_get_tools (gobj ()),
        Glib::OWNERSHIP_SHALLOW);
  }

  auto
  Seat::get_tools () const -> std::vector<Glib::RefPtr<const DeviceTool>>
  {
    return Glib::ListHandler<Glib::RefPtr<const DeviceTool>>::list_to_vector (
        gdk_seat_get_tools (const_cast<GdkSeat*> (gobj ())),
        Glib::OWNERSHIP_SHALLOW);
  }

  auto
  Seat::get_pointer () -> Glib::RefPtr<Device>
  {
    auto retvalue = Glib::wrap (gdk_seat_get_pointer (gobj ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  Seat::get_pointer () const -> Glib::RefPtr<const Device>
  {
    return const_cast<Seat*> (this)->get_pointer ();
  }

  auto
  Seat::get_keyboard () -> Glib::RefPtr<Device>
  {
    auto retvalue = Glib::wrap (gdk_seat_get_keyboard (gobj ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  Seat::get_keyboard () const -> Glib::RefPtr<const Device>
  {
    return const_cast<Seat*> (this)->get_keyboard ();
  }

  auto
  Seat::signal_device_added () -> Glib::SignalProxy<void (const Glib::RefPtr<Device>&)>
  {
    return Glib::SignalProxy<void (const Glib::RefPtr<Device>&)> (
        this,
        &Seat_signal_device_added_info);
  }

  auto
  Seat::signal_device_removed () -> Glib::SignalProxy<void (const Glib::RefPtr<Device>&)>
  {
    return Glib::SignalProxy<void (const Glib::RefPtr<Device>&)> (
        this,
        &Seat_signal_device_removed_info);
  }

  auto
  Seat::signal_tool_added () -> Glib::SignalProxy<void (const Glib::RefPtr<DeviceTool>&)>
  {
    return Glib::SignalProxy<void (const Glib::RefPtr<DeviceTool>&)> (
        this,
        &Seat_signal_tool_added_info);
  }

  auto
  Seat::signal_tool_removed () -> Glib::SignalProxy<void (const Glib::RefPtr<DeviceTool>&)>
  {
    return Glib::SignalProxy<void (const Glib::RefPtr<DeviceTool>&)> (
        this,
        &Seat_signal_tool_removed_info);
  }

  static_assert (
      Glib::Traits::ValueCompatibleWithWrapProperty<
          Glib::RefPtr<Display>>::value,
      "Type Glib::RefPtr<Display> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  auto
  Seat::property_display () const -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<Display>>
  {
    return Glib::PropertyProxy_ReadOnly<Glib::RefPtr<Display>> (this,
                                                                "display");
  }

} // namespace Gdk
