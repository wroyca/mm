

#include <libmm-glib/mm-glib.hxx>

#include <libmm-gdk/surface.hxx>
#include <libmm-gdk/surface_p.hxx>

#include <gdk/gdk.h>
#include <libmm-gdk/cairocontext.hxx>
#include <libmm-gdk/cairoutils.hxx>
#include <libmm-gdk/contentprovider.hxx>
#include <libmm-gdk/cursor.hxx>
#include <libmm-gdk/device.hxx>
#include <libmm-gdk/dragsurfaceimpl.hxx>
#include <libmm-gdk/frameclock.hxx>
#include <libmm-gdk/glcontext.hxx>
#include <libmm-gdk/monitor.hxx>
#include <libmm-gdk/popupsurfaceimpl.hxx>
#include <libmm-gdk/toplevelsurfaceimpl.hxx>

using CairoRegion = cairo_region_t;

namespace Gdk
{

  auto
  Surface_Class::wrap_new (GObject* object) -> Glib::ObjectBase*
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

} // namespace Gdk

namespace
{

  auto
  Surface_signal_layout_callback (GdkSurface* self,
                                  const gint p0,
                                  const gint p1,
                                  void* data) -> void
  {
    using namespace Gdk;
    using SlotType = sigc::slot<void (int, int)>;

    const auto obj = dynamic_cast<Surface*> (
        Glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj)
    {
      try
      {
        if (const auto slot = Glib::SignalProxyNormal::data_to_slot (data))
          (*static_cast<SlotType*> (slot)) (p0, p1);
      }
      catch (...)
      {
        Glib::exception_handlers_invoke ();
      }
    }
  }

  const Glib::SignalProxyInfo Surface_signal_layout_info = {
      "layout",
      (GCallback) &Surface_signal_layout_callback,
      (GCallback) &Surface_signal_layout_callback};

  auto
  Surface_signal_render_callback (GdkSurface* self, CairoRegion* p0, void* data) -> gboolean
  {
    using namespace Gdk;
    using SlotType =
        sigc::slot<bool (const ::Cairo::RefPtr<const ::Cairo::Region>&)>;

    const auto obj = dynamic_cast<Surface*> (
        Glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj)
    {
      try
      {
        if (const auto slot = Glib::SignalProxyNormal::data_to_slot (data))
          return (*static_cast<SlotType*> (slot)) (
              Gdk::Cairo::wrap (p0, false));
      }
      catch (...)
      {
        Glib::exception_handlers_invoke ();
      }
    }

    using RType = gboolean;
    return RType ();
  }

  auto
  Surface_signal_render_notify_callback (GdkSurface* self,
                                         CairoRegion* p0,
                                         void* data) -> gboolean
  {
    using namespace Gdk;
    using SlotType =
        sigc::slot<void (const ::Cairo::RefPtr<const ::Cairo::Region>&)>;

    const auto obj = dynamic_cast<Surface*> (
        Glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj)
    {
      try
      {
        if (const auto slot = Glib::SignalProxyNormal::data_to_slot (data))
          (*static_cast<SlotType*> (slot)) (Gdk::Cairo::wrap (p0, false));
      }
      catch (...)
      {
        Glib::exception_handlers_invoke ();
      }
    }

    using RType = gboolean;
    return RType ();
  }

  const Glib::SignalProxyInfo Surface_signal_render_info = {
      "render",
      (GCallback) &Surface_signal_render_callback,
      (GCallback) &Surface_signal_render_notify_callback};

  auto
  Surface_signal_event_callback (GdkSurface* self, GdkEvent* p0, void* data) -> gboolean
  {
    using namespace Gdk;
    using SlotType = sigc::slot<bool (const Glib::RefPtr<const Event>&)>;

    const auto obj = dynamic_cast<Surface*> (
        Glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj)
    {
      try
      {
        if (const auto slot = Glib::SignalProxyNormal::data_to_slot (data))
          return (*static_cast<SlotType*> (slot)) (Glib::wrap (p0, true));
      }
      catch (...)
      {
        Glib::exception_handlers_invoke ();
      }
    }

    using RType = gboolean;
    return RType ();
  }

  auto
  Surface_signal_event_notify_callback (GdkSurface* self,
                                        GdkEvent* p0,
                                        void* data) -> gboolean
  {
    using namespace Gdk;
    using SlotType = sigc::slot<void (const Glib::RefPtr<const Event>&)>;

    const auto obj = dynamic_cast<Surface*> (
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

    using RType = gboolean;
    return RType ();
  }

  const Glib::SignalProxyInfo Surface_signal_event_info = {
      "event",
      (GCallback) &Surface_signal_event_callback,
      (GCallback) &Surface_signal_event_notify_callback};

  auto
  Surface_signal_enter_monitor_callback (GdkSurface* self,
                                         GdkMonitor* p0,
                                         void* data) -> void
  {
    using namespace Gdk;
    using SlotType = sigc::slot<void (const Glib::RefPtr<Monitor>&)>;

    const auto obj = dynamic_cast<Surface*> (
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

  const Glib::SignalProxyInfo Surface_signal_enter_monitor_info = {
      "enter-monitor",
      (GCallback) &Surface_signal_enter_monitor_callback,
      (GCallback) &Surface_signal_enter_monitor_callback};

  auto
  Surface_signal_leave_monitor_callback (GdkSurface* self,
                                         GdkMonitor* p0,
                                         void* data) -> void
  {
    using namespace Gdk;
    using SlotType = sigc::slot<void (const Glib::RefPtr<Monitor>&)>;

    const auto obj = dynamic_cast<Surface*> (
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

  const Glib::SignalProxyInfo Surface_signal_leave_monitor_info = {
      "leave-monitor",
      (GCallback) &Surface_signal_leave_monitor_callback,
      (GCallback) &Surface_signal_leave_monitor_callback};

} // namespace

namespace Glib
{

  auto
  wrap (GdkSurface* object, const bool take_copy) -> RefPtr<Gdk::Surface>
  {
    return Glib::make_refptr_for_instance<Gdk::Surface> (
        dynamic_cast<Gdk::Surface*> (wrap_auto ((GObject*) object, take_copy)));
  }

} // namespace Glib

namespace Gdk
{

  auto
  Surface_Class::init () -> const Class&
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

  Surface::Surface (const Glib::ConstructParams& construct_params)
    : Object (construct_params)
  {
  }

  Surface::Surface (GdkSurface* castitem)
    : Object ((GObject*) castitem)
  {
  }

  Surface::Surface (Surface&& src) noexcept
    : Object (std::move (src))
  {
  }

  auto
  Surface::operator= (Surface&& src) noexcept -> Surface&
  {
    Object::operator= (std::move (src));
    return *this;
  }

  Surface::~Surface () noexcept = default;

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
  Surface::create_toplevel (const Glib::RefPtr<Display>& display) -> Glib::RefPtr<Surface>
  {
    return Glib::wrap (gdk_surface_new_toplevel (Glib::unwrap (display)));
  }

  auto
  Surface::create_popup (const Glib::RefPtr<Surface>& parent,
                         const bool autohide) -> Glib::RefPtr<Surface>
  {
    return Glib::wrap (gdk_surface_new_popup (Glib::unwrap (parent), autohide));
  }

  auto
  Surface::get_display () -> Glib::RefPtr<Display>
  {
    auto retvalue = Glib::wrap (gdk_surface_get_display (gobj ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  Surface::get_display () const -> Glib::RefPtr<const Display>
  {
    return const_cast<Surface*> (this)->get_display ();
  }

  auto
  Surface::hide () -> void
  {
    gdk_surface_hide (gobj ());
  }

  auto
  Surface::set_input_region (const ::Cairo::RefPtr<::Cairo::Region>& region) -> void
  {
    gdk_surface_set_input_region (gobj (), region ? region->cobj () : nullptr);
  }

  auto
  Surface::get_mapped () const -> bool
  {
    return gdk_surface_get_mapped (const_cast<GdkSurface*> (gobj ()));
  }

  auto
  Surface::set_cursor (const Glib::RefPtr<Cursor>& cursor) -> void
  {
    gdk_surface_set_cursor (gobj (), Glib::unwrap (cursor));
  }

  auto
  Surface::set_device_cursor (const Glib::RefPtr<Device>& device,
                              const Glib::RefPtr<Cursor>& cursor) -> void
  {
    gdk_surface_set_device_cursor (gobj (),
                                   Glib::unwrap (device),
                                   Glib::unwrap (cursor));
  }

  auto
  Surface::get_device_cursor (const Glib::RefPtr<Device>& device) -> Glib::RefPtr<Cursor>
  {
    auto retvalue = Glib::wrap (
        gdk_surface_get_device_cursor (gobj (), Glib::unwrap (device)));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  Surface::get_device_cursor (const Glib::RefPtr<const Device>& device) const -> Glib::RefPtr<const Cursor>
  {
    auto retvalue = Glib::wrap (gdk_surface_get_device_cursor (
        const_cast<GdkSurface*> (gobj ()),
        const_cast<GdkDevice*> (Glib::unwrap<Device> (device))));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  Surface::get_cursor () -> Glib::RefPtr<Cursor>
  {
    auto retvalue = Glib::wrap (gdk_surface_get_cursor (gobj ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  Surface::get_cursor () const -> Glib::RefPtr<const Cursor>
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
  Surface::get_device_position (const Glib::RefPtr<const Device>& device,
                                double& x,
                                double& y,
                                ModifierType& mask) const -> bool
  {
    return gdk_surface_get_device_position (
        const_cast<GdkSurface*> (gobj ()),
        const_cast<GdkDevice*> (Glib::unwrap<Device> (device)),
        &x,
        &y,
        (GdkModifierType*) &mask);
  }

  auto
  Surface::create_similar_surface (::Cairo::Content content,
                                   const int width,
                                   const int height) -> ::Cairo::RefPtr<::Cairo::Surface>
  {
    return Cairo::wrap (
        gdk_surface_create_similar_surface (gobj (),
                                            (cairo_content_t) content,
                                            width,
                                            height));
  }

  auto
  Surface::beep () -> void
  {
    gdk_surface_beep (gobj ());
  }

  auto
  Surface::drag_begin_from_point (const Glib::RefPtr<Device>& device,
                                  const Glib::RefPtr<ContentProvider>& content,
                                  DragAction actions,
                                  const double dx,
                                  const double dy) -> Glib::RefPtr<Drag>
  {
    return Glib::wrap (gdk_drag_begin (gobj (),
                                       Glib::unwrap (device),
                                       Glib::unwrap (content),
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
  Surface::get_frame_clock () -> Glib::RefPtr<FrameClock>
  {
    auto retvalue = Glib::wrap (gdk_surface_get_frame_clock (gobj ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  Surface::get_frame_clock () const -> Glib::RefPtr<const FrameClock>
  {
    return const_cast<Surface*> (this)->get_frame_clock ();
  }

  auto
  Surface::set_opaque_region (
      const ::Cairo::RefPtr<const ::Cairo::Region>& region) -> void
  {
    gdk_surface_set_opaque_region (
        gobj (),
        const_cast<cairo_region_t*> (region ? region->cobj () : nullptr));
  }

  auto
  Surface::create_gl_context () -> Glib::RefPtr<GLContext>
  {
    GError* gerror = nullptr;
    auto retvalue =
        Glib::wrap (gdk_surface_create_gl_context (gobj (), &gerror));
    if (gerror)
      Glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  Surface::create_cairo_context () -> Glib::RefPtr<CairoContext>
  {
    return Glib::wrap (gdk_surface_create_cairo_context (gobj ()));
  }

  auto
  Surface::signal_layout () -> Glib::SignalProxy<void (int, int)>
  {
    return {this, &Surface_signal_layout_info};
  }

  auto
  Surface::signal_render () -> Glib::SignalProxy<bool (const ::Cairo::RefPtr<const ::Cairo::Region>&)>
  {
    return {this, &Surface_signal_render_info};
  }

  auto
  Surface::signal_event () -> Glib::SignalProxy<bool (const Glib::RefPtr<const Event>&)>
  {
    return {this, &Surface_signal_event_info};
  }

  auto
  Surface::signal_enter_monitor () -> Glib::SignalProxy<void (const Glib::RefPtr<Monitor>&)>
  {
    return {this, &Surface_signal_enter_monitor_info};
  }

  auto
  Surface::signal_leave_monitor () -> Glib::SignalProxy<void (const Glib::RefPtr<Monitor>&)>
  {
    return {this, &Surface_signal_leave_monitor_info};
  }

  static_assert (
      Glib::Traits::ValueCompatibleWithWrapProperty<
          Glib::RefPtr<Cursor>>::value,
      "Type Glib::RefPtr<Cursor> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  auto
  Surface::property_cursor () -> Glib::PropertyProxy<Glib::RefPtr<Cursor>>
  {
    return {this, "cursor"};
  }

  auto
  Surface::property_cursor () const -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<Cursor>>
  {
    return {this, "cursor"};
  }

  static_assert (
      Glib::Traits::ValueCompatibleWithWrapProperty<
          Glib::RefPtr<Display>>::value,
      "Type Glib::RefPtr<Display> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  auto
  Surface::property_display () const -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<Display>>
  {
    return {this, "display"};
  }

  static_assert (
      Glib::Traits::ValueCompatibleWithWrapProperty<
          Glib::RefPtr<FrameClock>>::value,
      "Type Glib::RefPtr<FrameClock> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  auto
  Surface::property_frame_clock () const -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<FrameClock>>
  {
    return {this, "frame-clock"};
  }

  auto
  Surface::property_mapped () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return {this, "mapped"};
  }

  auto
  Surface::property_width () const -> Glib::PropertyProxy_ReadOnly<int>
  {
    return {this, "width"};
  }

  auto
  Surface::property_height () const -> Glib::PropertyProxy_ReadOnly<int>
  {
    return {this, "height"};
  }

  auto
  Surface::property_scale_factor () const -> Glib::PropertyProxy_ReadOnly<int>
  {
    return {this, "scale-factor"};
  }

} // namespace Gdk
