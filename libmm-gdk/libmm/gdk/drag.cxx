// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/gdk/drag.hxx>
#include <libmm/gdk/drag_p.hxx>

#include <gdk/gdk.h>
#include <libmm/gdk/contentformats.hxx>
#include <libmm/gdk/contentprovider.hxx>
#include <libmm/gdk/device.hxx>
#include <libmm/gdk/display.hxx>
#include <libmm/gdk/surface.hxx>

namespace
{

  static auto
  Drag_signal_cancel_callback (GdkDrag* self,
                               GdkDragCancelReason p0,
                               void* data) -> void
  {
    using namespace Gdk;
    using SlotType = sigc::slot<void (DragCancelReason)>;

    auto obj = dynamic_cast<Drag*> (
        Glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj)
    {
      try
      {
        if (const auto slot = Glib::SignalProxyNormal::data_to_slot (data))
          (*static_cast<SlotType*> (slot)) (static_cast<DragCancelReason> (p0));
      }
      catch (...)
      {
        Glib::exception_handlers_invoke ();
      }
    }
  }

  static const Glib::SignalProxyInfo Drag_signal_cancel_info = {
      "cancel",
      (GCallback) &Drag_signal_cancel_callback,
      (GCallback) &Drag_signal_cancel_callback};

  static const Glib::SignalProxyInfo Drag_signal_drop_performed_info = {
      "drop-performed",
      (GCallback) &Glib::SignalProxyNormal::slot0_void_callback,
      (GCallback) &Glib::SignalProxyNormal::slot0_void_callback};

  static const Glib::SignalProxyInfo Drag_signal_dnd_finished_info = {
      "dnd-finished",
      (GCallback) &Glib::SignalProxyNormal::slot0_void_callback,
      (GCallback) &Glib::SignalProxyNormal::slot0_void_callback};

} // namespace

auto
Glib::Value<Gdk::DragCancelReason>::value_type () -> GType
{
  return gdk_drag_cancel_reason_get_type ();
}

namespace Glib
{

  auto
  wrap (GdkDrag* object, bool take_copy) -> Glib::RefPtr<Gdk::Drag>
  {
    return Glib::make_refptr_for_instance<Gdk::Drag> (dynamic_cast<Gdk::Drag*> (
        Glib::wrap_auto ((GObject*) (object), take_copy)));
  }

} // namespace Glib

namespace Gdk
{

  auto
  Drag_Class::init () -> const Glib::Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &Drag_Class::class_init_function;

      register_derived_type (gdk_drag_get_type ());
    }

    return *this;
  }

  auto
  Drag_Class::class_init_function (void* g_class, void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);
  }

  auto
  Drag_Class::wrap_new (GObject* object) -> Glib::ObjectBase*
  {
    return new Drag ((GdkDrag*) object);
  }

  auto
  Drag::gobj_copy () -> GdkDrag*
  {
    reference ();
    return gobj ();
  }

  Drag::Drag (const Glib::ConstructParams& construct_params)
    : Glib::Object (construct_params)
  {
  }

  Drag::Drag (GdkDrag* castitem)
    : Glib::Object ((GObject*) (castitem))
  {
  }

  Drag::Drag (Drag&& src) noexcept
    : Glib::Object (std::move (src))
  {
  }

  auto
  Drag::operator= (Drag&& src) noexcept -> Drag&
  {
    Glib::Object::operator= (std::move (src));
    return *this;
  }

  Drag::~Drag () noexcept {}

  Drag::CppClassType Drag::drag_class_;

  auto
  Drag::get_type () -> GType
  {
    return drag_class_.init ().get_type ();
  }

  auto
  Drag::get_base_type () -> GType
  {
    return gdk_drag_get_type ();
  }

  auto
  Drag::get_display () -> Glib::RefPtr<Display>
  {
    auto retvalue = Glib::wrap (gdk_drag_get_display (gobj ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  Drag::get_display () const -> Glib::RefPtr<const Display>
  {
    return const_cast<Drag*> (this)->get_display ();
  }

  auto
  Drag::get_device () -> Glib::RefPtr<Device>
  {
    auto retvalue = Glib::wrap (gdk_drag_get_device (gobj ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  Drag::get_device () const -> Glib::RefPtr<const Device>
  {
    return const_cast<Drag*> (this)->get_device ();
  }

  auto
  Drag::get_formats () -> Glib::RefPtr<ContentFormats>
  {
    auto retvalue = Glib::wrap (gdk_drag_get_formats (gobj ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  Drag::get_formats () const -> Glib::RefPtr<const ContentFormats>
  {
    return const_cast<Drag*> (this)->get_formats ();
  }

  auto
  Drag::get_actions () const -> DragAction
  {
    return static_cast<DragAction> (
        gdk_drag_get_actions (const_cast<GdkDrag*> (gobj ())));
  }

  auto
  Drag::get_selected_action () const -> DragAction
  {
    return static_cast<DragAction> (
        gdk_drag_get_selected_action (const_cast<GdkDrag*> (gobj ())));
  }

  auto
  Drag::action_is_unique (DragAction action) -> bool
  {
    return gdk_drag_action_is_unique (static_cast<GdkDragAction> (action));
  }

  auto
  Drag::drag_drop_done (bool success) -> void
  {
    gdk_drag_drop_done (gobj (), static_cast<int> (success));
  }

  auto
  Drag::get_drag_surface () -> Glib::RefPtr<Surface>
  {
    auto retvalue = Glib::wrap (gdk_drag_get_drag_surface (gobj ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  Drag::get_drag_surface () const -> Glib::RefPtr<const Surface>
  {
    return const_cast<Drag*> (this)->get_drag_surface ();
  }

  auto
  Drag::set_hotspot (int hot_x, int hot_y) -> void
  {
    gdk_drag_set_hotspot (gobj (), hot_x, hot_y);
  }

  auto
  Drag::get_content () -> Glib::RefPtr<ContentProvider>
  {
    auto retvalue = Glib::wrap (gdk_drag_get_content (gobj ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  Drag::get_content () const -> Glib::RefPtr<const ContentProvider>
  {
    return const_cast<Drag*> (this)->get_content ();
  }

  auto
  Drag::get_surface () -> Glib::RefPtr<Surface>
  {
    auto retvalue = Glib::wrap (gdk_drag_get_surface (gobj ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  Drag::get_surface () const -> Glib::RefPtr<const Surface>
  {
    return const_cast<Drag*> (this)->get_surface ();
  }

  auto
  Drag::signal_cancel () -> Glib::SignalProxy<void (DragCancelReason)>
  {
    return Glib::SignalProxy<void (DragCancelReason)> (
        this,
        &Drag_signal_cancel_info);
  }

  auto
  Drag::signal_drop_performed () -> Glib::SignalProxy<void ()>
  {
    return Glib::SignalProxy<void ()> (this, &Drag_signal_drop_performed_info);
  }

  auto
  Drag::signal_dnd_finished () -> Glib::SignalProxy<void ()>
  {
    return Glib::SignalProxy<void ()> (this, &Drag_signal_dnd_finished_info);
  }

  static_assert (
      Glib::Traits::ValueCompatibleWithWrapProperty<
          Glib::RefPtr<ContentProvider>>::value,
      "Type Glib::RefPtr<ContentProvider> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  auto
  Drag::property_content () const -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<ContentProvider>>
  {
    return Glib::PropertyProxy_ReadOnly<Glib::RefPtr<ContentProvider>> (
        this,
        "content");
  }

  static_assert (
      Glib::Traits::ValueCompatibleWithWrapProperty<
          Glib::RefPtr<Device>>::value,
      "Type Glib::RefPtr<Device> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  auto
  Drag::property_device () const -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<Device>>
  {
    return Glib::PropertyProxy_ReadOnly<Glib::RefPtr<Device>> (this, "device");
  }

  static_assert (
      Glib::Traits::ValueCompatibleWithWrapProperty<
          Glib::RefPtr<Display>>::value,
      "Type Glib::RefPtr<Display> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  auto
  Drag::property_display () const -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<Display>>
  {
    return Glib::PropertyProxy_ReadOnly<Glib::RefPtr<Display>> (this,
                                                                "display");
  }

  static_assert (
      Glib::Traits::ValueCompatibleWithWrapProperty<
          Glib::RefPtr<ContentFormats>>::value,
      "Type Glib::RefPtr<ContentFormats> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  auto
  Drag::property_formats () const -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<ContentFormats>>
  {
    return Glib::PropertyProxy_ReadOnly<Glib::RefPtr<ContentFormats>> (
        this,
        "formats");
  }

  static_assert (
      Glib::Traits::ValueCompatibleWithWrapProperty<DragAction>::value,
      "Type DragAction cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  auto
  Drag::property_selected_action () -> Glib::PropertyProxy<DragAction>
  {
    return Glib::PropertyProxy<DragAction> (this, "selected-action");
  }

  auto
  Drag::property_selected_action () const -> Glib::PropertyProxy_ReadOnly<DragAction>
  {
    return Glib::PropertyProxy_ReadOnly<DragAction> (this, "selected-action");
  }

  static_assert (
      Glib::Traits::ValueCompatibleWithWrapProperty<DragAction>::value,
      "Type DragAction cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  auto
  Drag::property_actions () -> Glib::PropertyProxy<DragAction>
  {
    return Glib::PropertyProxy<DragAction> (this, "actions");
  }

  auto
  Drag::property_actions () const -> Glib::PropertyProxy_ReadOnly<DragAction>
  {
    return Glib::PropertyProxy_ReadOnly<DragAction> (this, "actions");
  }

  static_assert (
      Glib::Traits::ValueCompatibleWithWrapProperty<
          Glib::RefPtr<Surface>>::value,
      "Type Glib::RefPtr<Surface> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  auto
  Drag::property_surface () const -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<Surface>>
  {
    return Glib::PropertyProxy_ReadOnly<Glib::RefPtr<Surface>> (this,
                                                                "surface");
  }

} // namespace Gdk
