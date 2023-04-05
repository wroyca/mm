// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/gtk/eventcontrollermotion.hxx>
#include <libmm/gtk/eventcontrollermotion_p.hxx>

#include <gtk/gtk.h>

namespace
{

  static auto
  EventControllerMotion_signal_enter_callback (GtkEventControllerMotion* self,
                                               gdouble p0,
                                               gdouble p1,
                                               void* data) -> void
  {
    using namespace gtk;
    using SlotType = sigc::slot<void (double, double)>;

    auto obj = dynamic_cast<EventControllerMotion*> (
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

  static const glib::SignalProxyInfo EventControllerMotion_signal_enter_info = {
      "enter",
      (GCallback) &EventControllerMotion_signal_enter_callback,
      (GCallback) &EventControllerMotion_signal_enter_callback};

  static const glib::SignalProxyInfo EventControllerMotion_signal_leave_info = {
      "leave",
      (GCallback) &glib::SignalProxyNormal::slot0_void_callback,
      (GCallback) &glib::SignalProxyNormal::slot0_void_callback};

  static auto
  EventControllerMotion_signal_motion_callback (GtkEventControllerMotion* self,
                                                gdouble p0,
                                                gdouble p1,
                                                void* data) -> void
  {
    using namespace gtk;
    using SlotType = sigc::slot<void (double, double)>;

    auto obj = dynamic_cast<EventControllerMotion*> (
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

  static const glib::SignalProxyInfo EventControllerMotion_signal_motion_info =
      {"motion",
       (GCallback) &EventControllerMotion_signal_motion_callback,
       (GCallback) &EventControllerMotion_signal_motion_callback};

} // namespace

namespace glib
{

  auto
  wrap (GtkEventControllerMotion* object, bool take_copy) -> glib::RefPtr<gtk::EventControllerMotion>
  {
    return glib::make_refptr_for_instance<gtk::EventControllerMotion> (
        dynamic_cast<gtk::EventControllerMotion*> (
            glib::wrap_auto ((GObject*) (object), take_copy)));
  }

} // namespace glib

namespace gtk
{

  auto
  EventControllerMotion_Class::init () -> const glib::Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &EventControllerMotion_Class::class_init_function;

      register_derived_type (gtk_event_controller_motion_get_type ());
    }

    return *this;
  }

  auto
  EventControllerMotion_Class::class_init_function (void* g_class,
                                                    void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);
  }

  auto
  EventControllerMotion_Class::wrap_new (GObject* object) -> glib::ObjectBase*
  {
    return new EventControllerMotion ((GtkEventControllerMotion*) object);
  }

  auto
  EventControllerMotion::gobj_copy () -> GtkEventControllerMotion*
  {
    reference ();
    return gobj ();
  }

  EventControllerMotion::EventControllerMotion (
      const glib::ConstructParams& construct_params)
    : EventController (construct_params)
  {
  }

  EventControllerMotion::EventControllerMotion (
      GtkEventControllerMotion* castitem)
    : EventController ((GtkEventController*) (castitem))
  {
  }

  EventControllerMotion::EventControllerMotion (
      EventControllerMotion&& src) noexcept
    : EventController (std::move (src))
  {
  }

  auto
  EventControllerMotion::operator= (EventControllerMotion&& src) noexcept -> EventControllerMotion&
  {
    EventController::operator= (std::move (src));
    return *this;
  }

  EventControllerMotion::~EventControllerMotion () noexcept {}

  EventControllerMotion::CppClassType
      EventControllerMotion::eventcontrollermotion_class_;

  auto
  EventControllerMotion::get_type () -> GType
  {
    return eventcontrollermotion_class_.init ().get_type ();
  }

  auto
  EventControllerMotion::get_base_type () -> GType
  {
    return gtk_event_controller_motion_get_type ();
  }

  EventControllerMotion::EventControllerMotion ()
    : glib::ObjectBase (nullptr),
      EventController (
          glib::ConstructParams (eventcontrollermotion_class_.init ()))
  {
  }

  auto
  EventControllerMotion::create () -> glib::RefPtr<EventControllerMotion>
  {
    return glib::make_refptr_for_instance<EventControllerMotion> (
        new EventControllerMotion ());
  }

  auto
  EventControllerMotion::contains_pointer () const -> bool
  {
    return gtk_event_controller_motion_contains_pointer (
        const_cast<GtkEventControllerMotion*> (gobj ()));
  }

  auto
  EventControllerMotion::is_pointer () const -> bool
  {
    return gtk_event_controller_motion_is_pointer (
        const_cast<GtkEventControllerMotion*> (gobj ()));
  }

  auto
  EventControllerMotion::signal_enter () -> glib::SignalProxy<void (double, double)>
  {
    return glib::SignalProxy<void (double, double)> (
        this,
        &EventControllerMotion_signal_enter_info);
  }

  auto
  EventControllerMotion::signal_leave () -> glib::SignalProxy<void ()>
  {
    return glib::SignalProxy<void ()> (
        this,
        &EventControllerMotion_signal_leave_info);
  }

  auto
  EventControllerMotion::signal_motion () -> glib::SignalProxy<void (double, double)>
  {
    return glib::SignalProxy<void (double, double)> (
        this,
        &EventControllerMotion_signal_motion_info);
  }

  auto
  EventControllerMotion::property_is_pointer () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "is-pointer");
  }

  auto
  EventControllerMotion::property_contains_pointer () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "contains-pointer");
  }

} // namespace gtk
