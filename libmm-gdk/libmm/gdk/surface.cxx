// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/gdk/surface.hxx>
#include <libmm/gdk/surface_p.hxx>

#include <gdk/gdk.h>
#include <libmm/gdk/cairocontext.hxx>
#include <libmm/gdk/cairoutils.hxx>
#include <libmm/gdk/contentprovider.hxx>
#include <libmm/gdk/cursor.hxx>
#include <libmm/gdk/device.hxx>
#include <libmm/gdk/dragsurfaceimpl.hxx>
#include <libmm/gdk/frameclock.hxx>
#include <libmm/gdk/glcontext.hxx>
#include <libmm/gdk/monitor.hxx>
#include <libmm/gdk/popupsurfaceimpl.hxx>
#include <libmm/gdk/toplevelsurfaceimpl.hxx>

using CairoRegion = cairo_region_t;

namespace gdk
{

  auto
  Surface_Class::wrap_new (GObject* object) -> glib::ObjectBase*
  {
    if (GDK_IS_DRAG_SURFACE (object))
      return new DragSurfaceImpl ((GdkSurface*) object);
    if (GDK_IS_POPUP (object))
      return new PopupSurfaceImpl ((GdkSurface*) object);
    if (GDK_IS_TOPLEVEL (object))
      return new ToplevelSurfaceImpl ((GdkSurface*) object);
    return new Surface ((GdkSurface*) object);
  }

  auto
  Surface::set_cursor () -> void
  {
    gdk_surface_set_cursor (gobj (), nullptr);
  }

} // namespace gdk

namespace
{

  static auto
  Surface_signal_layout_callback (GdkSurface* self,
                                  gint p0,
                                  gint p1,
                                  void* data) -> void
  {
    using namespace gdk;
    using SlotType = sigc::slot<void (int, int)>;

    auto obj = dynamic_cast<Surface*> (
        glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj)
    {
      try
      {
        if (const auto slot = glib::SignalProxyNormal::data_to_slot (data))
          (*static_cast<SlotType*> (slot)) (p0, p1);
      }
      catch (...)
      {
        glib::exception_handlers_invoke ();
      }
    }
  }

  static const glib::SignalProxyInfo Surface_signal_layout_info = {
      "layout",
      (GCallback) &Surface_signal_layout_callback,
      (GCallback) &Surface_signal_layout_callback};

  static auto
  Surface_signal_render_callback (GdkSurface* self, CairoRegion* p0, void* data) -> gboolean
  {
    using namespace gdk;
    using SlotType =
        sigc::slot<bool (const ::cairo::RefPtr<const ::cairo::Region>&)>;

    auto obj = dynamic_cast<Surface*> (
        glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj)
    {
      try
      {
        if (const auto slot = glib::SignalProxyNormal::data_to_slot (data))
          return static_cast<int> (
              (*static_cast<SlotType*> (slot)) (gdk::cairo::wrap (p0, false)));
      }
      catch (...)
      {
        glib::exception_handlers_invoke ();
      }
    }

    using RType = gboolean;
    return RType ();
  }

  static auto
  Surface_signal_render_notify_callback (GdkSurface* self,
                                         CairoRegion* p0,
                                         void* data) -> gboolean
  {
    using namespace gdk;
    using SlotType =
        sigc::slot<void (const ::cairo::RefPtr<const ::cairo::Region>&)>;

    auto obj = dynamic_cast<Surface*> (
        glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj)
    {
      try
      {
        if (const auto slot = glib::SignalProxyNormal::data_to_slot (data))
          (*static_cast<SlotType*> (slot)) (gdk::cairo::wrap (p0, false));
      }
      catch (...)
      {
        glib::exception_handlers_invoke ();
      }
    }

    using RType = gboolean;
    return RType ();
  }

  static const glib::SignalProxyInfo Surface_signal_render_info = {
      "render",
      (GCallback) &Surface_signal_render_callback,
      (GCallback) &Surface_signal_render_notify_callback};

  static auto
  Surface_signal_event_callback (GdkSurface* self, GdkEvent* p0, void* data) -> gboolean
  {
    using namespace gdk;
    using SlotType = sigc::slot<bool (const glib::RefPtr<const Event>&)>;

    auto obj = dynamic_cast<Surface*> (
        glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj)
    {
      try
      {
        if (const auto slot = glib::SignalProxyNormal::data_to_slot (data))
          return static_cast<int> (
              (*static_cast<SlotType*> (slot)) (glib::wrap (p0, true)));
      }
      catch (...)
      {
        glib::exception_handlers_invoke ();
      }
    }

    using RType = gboolean;
    return RType ();
  }

  static auto
  Surface_signal_event_notify_callback (GdkSurface* self,
                                        GdkEvent* p0,
                                        void* data) -> gboolean
  {
    using namespace gdk;
    using SlotType = sigc::slot<void (const glib::RefPtr<const Event>&)>;

    auto obj = dynamic_cast<Surface*> (
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

    using RType = gboolean;
    return RType ();
  }

  static const glib::SignalProxyInfo Surface_signal_event_info = {
      "event",
      (GCallback) &Surface_signal_event_callback,
      (GCallback) &Surface_signal_event_notify_callback};

  static auto
  Surface_signal_enter_monitor_callback (GdkSurface* self,
                                         GdkMonitor* p0,
                                         void* data) -> void
  {
    using namespace gdk;
    using SlotType = sigc::slot<void (const glib::RefPtr<Monitor>&)>;

    auto obj = dynamic_cast<Surface*> (
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

  static const glib::SignalProxyInfo Surface_signal_enter_monitor_info = {
      "enter-monitor",
      (GCallback) &Surface_signal_enter_monitor_callback,
      (GCallback) &Surface_signal_enter_monitor_callback};

  static auto
  Surface_signal_leave_monitor_callback (GdkSurface* self,
                                         GdkMonitor* p0,
                                         void* data) -> void
  {
    using namespace gdk;
    using SlotType = sigc::slot<void (const glib::RefPtr<Monitor>&)>;

    auto obj = dynamic_cast<Surface*> (
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

  static const glib::SignalProxyInfo Surface_signal_leave_monitor_info = {
      "leave-monitor",
      (GCallback) &Surface_signal_leave_monitor_callback,
      (GCallback) &Surface_signal_leave_monitor_callback};

} // namespace

namespace glib
{

  auto
  wrap (GdkSurface* object, bool take_copy) -> glib::RefPtr<gdk::Surface>
  {
    return glib::make_refptr_for_instance<gdk::Surface> (
        dynamic_cast<gdk::Surface*> (
            glib::wrap_auto ((GObject*) (object), take_copy)));
  }

} // namespace glib

namespace gdk
{

  auto
  Surface_Class::init () -> const glib::Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &Surface_Class::class_init_function;

      register_derived_type (gdk_surface_get_type ());
    }

    return *this;
  }

  auto
  Surface_Class::class_init_function (void* g_class, void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);
  }

  auto
  Surface::gobj_copy () -> GdkSurface*
  {
    reference ();
    return gobj ();
  }

  Surface::Surface (const glib::ConstructParams& construct_params)
    : glib::Object (construct_params)
  {
  }

  Surface::Surface (GdkSurface* castitem)
    : glib::Object ((GObject*) (castitem))
  {
  }

  Surface::Surface (Surface&& src) noexcept
    : glib::Object (std::move (src))
  {
  }

  auto
  Surface::operator= (Surface&& src) noexcept -> Surface&
  {
    glib::Object::operator= (std::move (src));
    return *this;
  }

  Surface::~Surface () noexcept {}

  Surface::CppClassType Surface::surface_class_;

  auto
  Surface::get_type () -> GType
  {
    return surface_class_.init ().get_type ();
  }

  auto
  Surface::get_base_type () -> GType
  {
    return gdk_surface_get_type ();
  }

  auto
  Surface::create_toplevel (const glib::RefPtr<Display>& display) -> glib::RefPtr<Surface>
  {
    return glib::wrap (gdk_surface_new_toplevel (glib::unwrap (display)));
  }

  auto
  Surface::create_popup (const glib::RefPtr<Surface>& parent, bool autohide) -> glib::RefPtr<Surface>
  {
    return glib::wrap (gdk_surface_new_popup (glib::unwrap (parent),
                                              static_cast<int> (autohide)));
  }

  auto
  Surface::get_display () -> glib::RefPtr<Display>
  {
    auto retvalue = glib::wrap (gdk_surface_get_display (gobj ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  Surface::get_display () const -> glib::RefPtr<const Display>
  {
    return const_cast<Surface*> (this)->get_display ();
  }

  auto
  Surface::hide () -> void
  {
    gdk_surface_hide (gobj ());
  }

  auto
  Surface::set_input_region (const ::cairo::RefPtr<::cairo::Region>& region) -> void
  {
    gdk_surface_set_input_region (gobj (),
                                  ((region) ? (region)->cobj () : nullptr));
  }

  auto
  Surface::get_mapped () const -> bool
  {
    return gdk_surface_get_mapped (const_cast<GdkSurface*> (gobj ()));
  }

  auto
  Surface::set_cursor (const glib::RefPtr<Cursor>& cursor) -> void
  {
    gdk_surface_set_cursor (gobj (), glib::unwrap (cursor));
  }

  auto
  Surface::set_device_cursor (const glib::RefPtr<Device>& device,
                              const glib::RefPtr<Cursor>& cursor) -> void
  {
    gdk_surface_set_device_cursor (gobj (),
                                   glib::unwrap (device),
                                   glib::unwrap (cursor));
  }

  auto
  Surface::get_device_cursor (const glib::RefPtr<Device>& device) -> glib::RefPtr<Cursor>
  {
    auto retvalue = glib::wrap (
        gdk_surface_get_device_cursor (gobj (), glib::unwrap (device)));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  Surface::get_device_cursor (const glib::RefPtr<const Device>& device) const -> glib::RefPtr<const Cursor>
  {
    auto retvalue = glib::wrap (gdk_surface_get_device_cursor (
        const_cast<GdkSurface*> (gobj ()),
        const_cast<GdkDevice*> (glib::unwrap<gdk::Device> (device))));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  Surface::get_cursor () -> glib::RefPtr<Cursor>
  {
    auto retvalue = glib::wrap (gdk_surface_get_cursor (gobj ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  Surface::get_cursor () const -> glib::RefPtr<const Cursor>
  {
    return const_cast<Surface*> (this)->get_cursor ();
  }

  auto
  Surface::get_width () const -> int
  {
    return gdk_surface_get_width (const_cast<GdkSurface*> (gobj ()));
  }

  auto
  Surface::get_height () const -> int
  {
    return gdk_surface_get_height (const_cast<GdkSurface*> (gobj ()));
  }

  auto
  Surface::get_scale_factor () const -> int
  {
    return gdk_surface_get_scale_factor (const_cast<GdkSurface*> (gobj ()));
  }

  auto
  Surface::get_device_position (const glib::RefPtr<const Device>& device,
                                double& x,
                                double& y,
                                ModifierType& mask) const -> bool
  {
    return gdk_surface_get_device_position (
        const_cast<GdkSurface*> (gobj ()),
        const_cast<GdkDevice*> (glib::unwrap<gdk::Device> (device)),
        &(x),
        &(y),
        ((GdkModifierType*) &(mask)));
  }

  auto
  Surface::create_similar_surface (::cairo::Content content,
                                   int width,
                                   int height) -> ::cairo::RefPtr<::cairo::Surface>
  {
    return gdk::cairo::wrap (
        gdk_surface_create_similar_surface (gobj (),
                                            (cairo_content_t) (content),
                                            width,
                                            height));
  }

  auto
  Surface::beep () -> void
  {
    gdk_surface_beep (gobj ());
  }

  auto
  Surface::drag_begin_from_point (const glib::RefPtr<Device>& device,
                                  const glib::RefPtr<ContentProvider>& content,
                                  DragAction actions,
                                  double dx,
                                  double dy) -> glib::RefPtr<Drag>
  {
    return glib::wrap (gdk_drag_begin (gobj (),
                                       glib::unwrap (device),
                                       glib::unwrap (content),
                                       static_cast<GdkDragAction> (actions),
                                       dx,
                                       dy));
  }

  auto
  Surface::queue_render () -> void
  {
    gdk_surface_queue_render (gobj ());
  }

  auto
  Surface::request_layout () -> void
  {
    gdk_surface_request_layout (gobj ());
  }

  auto
  Surface::get_frame_clock () -> glib::RefPtr<FrameClock>
  {
    auto retvalue = glib::wrap (gdk_surface_get_frame_clock (gobj ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  Surface::get_frame_clock () const -> glib::RefPtr<const FrameClock>
  {
    return const_cast<Surface*> (this)->get_frame_clock ();
  }

  auto
  Surface::set_opaque_region (
      const ::cairo::RefPtr<const ::cairo::Region>& region) -> void
  {
    gdk_surface_set_opaque_region (
        gobj (),
        const_cast<cairo_region_t*> ((region) ? (region)->cobj () : nullptr));
  }

  auto
  Surface::create_gl_context () -> glib::RefPtr<gdk::GLContext>
  {
    GError* gerror = nullptr;
    auto retvalue =
        glib::wrap (gdk_surface_create_gl_context (gobj (), &(gerror)));
    if (gerror)
      ::glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  Surface::create_cairo_context () -> glib::RefPtr<gdk::CairoContext>
  {
    return glib::wrap (gdk_surface_create_cairo_context (gobj ()));
  }

  auto
  Surface::signal_layout () -> glib::SignalProxy<void (int, int)>
  {
    return glib::SignalProxy<void (int, int)> (this,
                                               &Surface_signal_layout_info);
  }

  auto
  Surface::signal_render () -> glib::SignalProxy<bool (const ::cairo::RefPtr<const ::cairo::Region>&)>
  {
    return glib::SignalProxy<bool (
        const ::cairo::RefPtr<const ::cairo::Region>&)> (
        this,
        &Surface_signal_render_info);
  }

  auto
  Surface::signal_event () -> glib::SignalProxy<bool (const glib::RefPtr<const Event>&)>
  {
    return glib::SignalProxy<bool (const glib::RefPtr<const Event>&)> (
        this,
        &Surface_signal_event_info);
  }

  auto
  Surface::signal_enter_monitor () -> glib::SignalProxy<void (const glib::RefPtr<Monitor>&)>
  {
    return glib::SignalProxy<void (const glib::RefPtr<Monitor>&)> (
        this,
        &Surface_signal_enter_monitor_info);
  }

  auto
  Surface::signal_leave_monitor () -> glib::SignalProxy<void (const glib::RefPtr<Monitor>&)>
  {
    return glib::SignalProxy<void (const glib::RefPtr<Monitor>&)> (
        this,
        &Surface_signal_leave_monitor_info);
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<
          glib::RefPtr<Cursor>>::value,
      "Type glib::RefPtr<Cursor> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  Surface::property_cursor () -> glib::PropertyProxy<glib::RefPtr<Cursor>>
  {
    return glib::PropertyProxy<glib::RefPtr<Cursor>> (this, "cursor");
  }

  auto
  Surface::property_cursor () const -> glib::PropertyProxy_ReadOnly<glib::RefPtr<Cursor>>
  {
    return glib::PropertyProxy_ReadOnly<glib::RefPtr<Cursor>> (this, "cursor");
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<
          glib::RefPtr<Display>>::value,
      "Type glib::RefPtr<Display> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  Surface::property_display () const -> glib::PropertyProxy_ReadOnly<glib::RefPtr<Display>>
  {
    return glib::PropertyProxy_ReadOnly<glib::RefPtr<Display>> (this,
                                                                "display");
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<
          glib::RefPtr<FrameClock>>::value,
      "Type glib::RefPtr<FrameClock> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  Surface::property_frame_clock () const -> glib::PropertyProxy_ReadOnly<glib::RefPtr<FrameClock>>
  {
    return glib::PropertyProxy_ReadOnly<glib::RefPtr<FrameClock>> (
        this,
        "frame-clock");
  }

  auto
  Surface::property_mapped () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "mapped");
  }

  auto
  Surface::property_width () const -> glib::PropertyProxy_ReadOnly<int>
  {
    return glib::PropertyProxy_ReadOnly<int> (this, "width");
  }

  auto
  Surface::property_height () const -> glib::PropertyProxy_ReadOnly<int>
  {
    return glib::PropertyProxy_ReadOnly<int> (this, "height");
  }

  auto
  Surface::property_scale_factor () const -> glib::PropertyProxy_ReadOnly<int>
  {
    return glib::PropertyProxy_ReadOnly<int> (this, "scale-factor");
  }

} // namespace gdk
