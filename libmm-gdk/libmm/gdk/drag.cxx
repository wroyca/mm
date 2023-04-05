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
    using namespace gdk;
    using SlotType = sigc::slot<void (DragCancelReason)>;

    auto obj = dynamic_cast<Drag*> (
        glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj)
    {
      try
      {
        if (const auto slot = glib::SignalProxyNormal::data_to_slot (data))
          (*static_cast<SlotType*> (slot)) (static_cast<DragCancelReason> (p0));
      }
      catch (...)
      {
        glib::exception_handlers_invoke ();
      }
    }
  }

  static const glib::SignalProxyInfo Drag_signal_cancel_info = {
      "cancel",
      (GCallback) &Drag_signal_cancel_callback,
      (GCallback) &Drag_signal_cancel_callback};

  static const glib::SignalProxyInfo Drag_signal_drop_performed_info = {
      "drop-performed",
      (GCallback) &glib::SignalProxyNormal::slot0_void_callback,
      (GCallback) &glib::SignalProxyNormal::slot0_void_callback};

  static const glib::SignalProxyInfo Drag_signal_dnd_finished_info = {
      "dnd-finished",
      (GCallback) &glib::SignalProxyNormal::slot0_void_callback,
      (GCallback) &glib::SignalProxyNormal::slot0_void_callback};

} // namespace

auto
glib::Value<gdk::DragCancelReason>::value_type () -> GType
{
  return gdk_drag_cancel_reason_get_type ();
}

namespace glib
{

  auto
  wrap (GdkDrag* object, bool take_copy) -> glib::RefPtr<gdk::Drag>
  {
    return glib::make_refptr_for_instance<gdk::Drag> (dynamic_cast<gdk::Drag*> (
        glib::wrap_auto ((GObject*) (object), take_copy)));
  }

} // namespace glib

namespace gdk
{

  auto
  Drag_Class::init () -> const glib::Class&
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
  Drag_Class::wrap_new (GObject* object) -> glib::ObjectBase*
  {
    return new Drag ((GdkDrag*) object);
  }

  auto
  Drag::gobj_copy () -> GdkDrag*
  {
    reference ();
    return gobj ();
  }

  Drag::Drag (const glib::ConstructParams& construct_params)
    : glib::Object (construct_params)
  {
  }

  Drag::Drag (GdkDrag* castitem)
    : glib::Object ((GObject*) (castitem))
  {
  }

  Drag::Drag (Drag&& src) noexcept
    : glib::Object (std::move (src))
  {
  }

  auto
  Drag::operator= (Drag&& src) noexcept -> Drag&
  {
    glib::Object::operator= (std::move (src));
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
  Drag::get_display () -> glib::RefPtr<Display>
  {
    auto retvalue = glib::wrap (gdk_drag_get_display (gobj ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  Drag::get_display () const -> glib::RefPtr<const Display>
  {
    return const_cast<Drag*> (this)->get_display ();
  }

  auto
  Drag::get_device () -> glib::RefPtr<Device>
  {
    auto retvalue = glib::wrap (gdk_drag_get_device (gobj ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  Drag::get_device () const -> glib::RefPtr<const Device>
  {
    return const_cast<Drag*> (this)->get_device ();
  }

  auto
  Drag::get_formats () -> glib::RefPtr<ContentFormats>
  {
    auto retvalue = glib::wrap (gdk_drag_get_formats (gobj ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  Drag::get_formats () const -> glib::RefPtr<const ContentFormats>
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
  Drag::get_drag_surface () -> glib::RefPtr<Surface>
  {
    auto retvalue = glib::wrap (gdk_drag_get_drag_surface (gobj ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  Drag::get_drag_surface () const -> glib::RefPtr<const Surface>
  {
    return const_cast<Drag*> (this)->get_drag_surface ();
  }

  auto
  Drag::set_hotspot (int hot_x, int hot_y) -> void
  {
    gdk_drag_set_hotspot (gobj (), hot_x, hot_y);
  }

  auto
  Drag::get_content () -> glib::RefPtr<ContentProvider>
  {
    auto retvalue = glib::wrap (gdk_drag_get_content (gobj ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  Drag::get_content () const -> glib::RefPtr<const ContentProvider>
  {
    return const_cast<Drag*> (this)->get_content ();
  }

  auto
  Drag::get_surface () -> glib::RefPtr<Surface>
  {
    auto retvalue = glib::wrap (gdk_drag_get_surface (gobj ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  Drag::get_surface () const -> glib::RefPtr<const Surface>
  {
    return const_cast<Drag*> (this)->get_surface ();
  }

  auto
  Drag::signal_cancel () -> glib::SignalProxy<void (DragCancelReason)>
  {
    return glib::SignalProxy<void (DragCancelReason)> (
        this,
        &Drag_signal_cancel_info);
  }

  auto
  Drag::signal_drop_performed () -> glib::SignalProxy<void ()>
  {
    return glib::SignalProxy<void ()> (this, &Drag_signal_drop_performed_info);
  }

  auto
  Drag::signal_dnd_finished () -> glib::SignalProxy<void ()>
  {
    return glib::SignalProxy<void ()> (this, &Drag_signal_dnd_finished_info);
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<
          glib::RefPtr<ContentProvider>>::value,
      "Type glib::RefPtr<ContentProvider> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  Drag::property_content () const -> glib::PropertyProxy_ReadOnly<glib::RefPtr<ContentProvider>>
  {
    return glib::PropertyProxy_ReadOnly<glib::RefPtr<ContentProvider>> (
        this,
        "content");
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<
          glib::RefPtr<Device>>::value,
      "Type glib::RefPtr<Device> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  Drag::property_device () const -> glib::PropertyProxy_ReadOnly<glib::RefPtr<Device>>
  {
    return glib::PropertyProxy_ReadOnly<glib::RefPtr<Device>> (this, "device");
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<
          glib::RefPtr<Display>>::value,
      "Type glib::RefPtr<Display> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  Drag::property_display () const -> glib::PropertyProxy_ReadOnly<glib::RefPtr<Display>>
  {
    return glib::PropertyProxy_ReadOnly<glib::RefPtr<Display>> (this,
                                                                "display");
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<
          glib::RefPtr<ContentFormats>>::value,
      "Type glib::RefPtr<ContentFormats> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  Drag::property_formats () const -> glib::PropertyProxy_ReadOnly<glib::RefPtr<ContentFormats>>
  {
    return glib::PropertyProxy_ReadOnly<glib::RefPtr<ContentFormats>> (
        this,
        "formats");
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<DragAction>::value,
      "Type DragAction cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  Drag::property_selected_action () -> glib::PropertyProxy<DragAction>
  {
    return glib::PropertyProxy<DragAction> (this, "selected-action");
  }

  auto
  Drag::property_selected_action () const -> glib::PropertyProxy_ReadOnly<DragAction>
  {
    return glib::PropertyProxy_ReadOnly<DragAction> (this, "selected-action");
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<DragAction>::value,
      "Type DragAction cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  Drag::property_actions () -> glib::PropertyProxy<DragAction>
  {
    return glib::PropertyProxy<DragAction> (this, "actions");
  }

  auto
  Drag::property_actions () const -> glib::PropertyProxy_ReadOnly<DragAction>
  {
    return glib::PropertyProxy_ReadOnly<DragAction> (this, "actions");
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<
          glib::RefPtr<Surface>>::value,
      "Type glib::RefPtr<Surface> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  Drag::property_surface () const -> glib::PropertyProxy_ReadOnly<glib::RefPtr<Surface>>
  {
    return glib::PropertyProxy_ReadOnly<glib::RefPtr<Surface>> (this,
                                                                "surface");
  }

} // namespace gdk
