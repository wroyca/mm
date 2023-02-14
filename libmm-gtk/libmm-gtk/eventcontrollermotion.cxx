// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm-glib/mm-glib.hxx>

#include <libmm-gtk/eventcontrollermotion.hxx>
#include <libmm-gtk/eventcontrollermotion_p.hxx>

#include <gtk/gtk.h>

namespace
{

  auto
  EventControllerMotion_signal_enter_callback (GtkEventControllerMotion* self,
                                               const gdouble p0,
                                               const gdouble p1,
                                               void* data) -> void
  {
    using namespace Gtk;
    using SlotType = sigc::slot<void (double, double)>;

    const auto obj = dynamic_cast<EventControllerMotion*> (
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

  const Glib::SignalProxyInfo EventControllerMotion_signal_enter_info = {
      "enter",
      (GCallback) &EventControllerMotion_signal_enter_callback,
      (GCallback) &EventControllerMotion_signal_enter_callback};

  const Glib::SignalProxyInfo EventControllerMotion_signal_leave_info = {
      "leave",
      (GCallback) &Glib::SignalProxyNormal::slot0_void_callback,
      (GCallback) &Glib::SignalProxyNormal::slot0_void_callback};

  auto
  EventControllerMotion_signal_motion_callback (GtkEventControllerMotion* self,
                                                const gdouble p0,
                                                const gdouble p1,
                                                void* data) -> void
  {
    using namespace Gtk;
    using SlotType = sigc::slot<void (double, double)>;

    const auto obj = dynamic_cast<EventControllerMotion*> (
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

  const Glib::SignalProxyInfo EventControllerMotion_signal_motion_info = {
      "motion",
      (GCallback) &EventControllerMotion_signal_motion_callback,
      (GCallback) &EventControllerMotion_signal_motion_callback};

} // namespace

namespace Glib
{

  auto
  wrap (GtkEventControllerMotion* object, const bool take_copy) -> RefPtr<Gtk::EventControllerMotion>
  {
    return Glib::make_refptr_for_instance<Gtk::EventControllerMotion> (
        dynamic_cast<Gtk::EventControllerMotion*> (
            wrap_auto ((GObject*) object, take_copy)));
  }

} // namespace Glib

namespace Gtk
{

  auto
  EventControllerMotion_Class::init () -> const Class&
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
  EventControllerMotion_Class::wrap_new (GObject* object) -> Glib::ObjectBase*
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
      const Glib::ConstructParams& construct_params)
    : EventController (construct_params)
  {
  }

  EventControllerMotion::EventControllerMotion (
      GtkEventControllerMotion* castitem)
    : EventController ((GtkEventController*) castitem)
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

  EventControllerMotion::~EventControllerMotion () noexcept = default;

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
    : ObjectBase (nullptr),
      EventController (
          Glib::ConstructParams (eventcontrollermotion_class_.init ()))
  {
  }

  auto
  EventControllerMotion::create () -> Glib::RefPtr<EventControllerMotion>
  {
    return Glib::make_refptr_for_instance<EventControllerMotion> (
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
  EventControllerMotion::signal_enter () -> Glib::SignalProxy<void (double, double)>
  {
    return {this, &EventControllerMotion_signal_enter_info};
  }

  auto
  EventControllerMotion::signal_leave () -> Glib::SignalProxy<void ()>
  {
    return {this, &EventControllerMotion_signal_leave_info};
  }

  auto
  EventControllerMotion::signal_motion () -> Glib::SignalProxy<void (double, double)>
  {
    return {this, &EventControllerMotion_signal_motion_info};
  }

  auto
  EventControllerMotion::property_is_pointer () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return {this, "is-pointer"};
  }

  auto
  EventControllerMotion::property_contains_pointer () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return {this, "contains-pointer"};
  }

} // namespace Gtk
