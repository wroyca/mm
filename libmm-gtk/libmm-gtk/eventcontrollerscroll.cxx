// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm-glib/mm-glib.hxx>

#include <libmm-gtk/eventcontrollerscroll.hxx>
#include <libmm-gtk/eventcontrollerscroll_p.hxx>

#include <gtk/gtk.h>

using Flags = Gtk::EventControllerScroll::Flags;

namespace
{

  static const Glib::SignalProxyInfo
      EventControllerScroll_signal_scroll_begin_info = {
          "scroll-begin",
          (GCallback) &Glib::SignalProxyNormal::slot0_void_callback,
          (GCallback) &Glib::SignalProxyNormal::slot0_void_callback};

  static auto
  EventControllerScroll_signal_scroll_callback (GtkEventControllerScroll* self,
                                                gdouble p0,
                                                gdouble p1,
                                                void* data) -> gboolean
  {
    using namespace Gtk;
    using SlotType = sigc::slot<bool (double, double)>;

    auto obj = dynamic_cast<EventControllerScroll*> (
        Glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj)
    {
      try
      {
        if (const auto slot = Glib::SignalProxyNormal::data_to_slot (data))
          return static_cast<int> ((*static_cast<SlotType*> (slot)) (p0, p1));
      }
      catch (...)
      {
        Glib::exception_handlers_invoke ();
      }
    }

    using RType = gboolean;
    return RType ();
  }

  static auto
  EventControllerScroll_signal_scroll_notify_callback (
      GtkEventControllerScroll* self,
      gdouble p0,
      gdouble p1,
      void* data) -> gboolean
  {
    using namespace Gtk;
    using SlotType = sigc::slot<void (double, double)>;

    auto obj = dynamic_cast<EventControllerScroll*> (
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

    using RType = gboolean;
    return RType ();
  }

  static const Glib::SignalProxyInfo EventControllerScroll_signal_scroll_info =
      {"scroll",
       (GCallback) &EventControllerScroll_signal_scroll_callback,
       (GCallback) &EventControllerScroll_signal_scroll_notify_callback};

  static const Glib::SignalProxyInfo
      EventControllerScroll_signal_scroll_end_info = {
          "scroll-end",
          (GCallback) &Glib::SignalProxyNormal::slot0_void_callback,
          (GCallback) &Glib::SignalProxyNormal::slot0_void_callback};

  static auto
  EventControllerScroll_signal_decelerate_callback (
      GtkEventControllerScroll* self,
      gdouble p0,
      gdouble p1,
      void* data) -> void
  {
    using namespace Gtk;
    using SlotType = sigc::slot<void (double, double)>;

    auto obj = dynamic_cast<EventControllerScroll*> (
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

  static const Glib::SignalProxyInfo
      EventControllerScroll_signal_decelerate_info = {
          "decelerate",
          (GCallback) &EventControllerScroll_signal_decelerate_callback,
          (GCallback) &EventControllerScroll_signal_decelerate_callback};

} // namespace

auto
Glib::Value<Gtk::EventControllerScroll::Flags>::value_type () -> GType
{
  return gtk_event_controller_scroll_flags_get_type ();
}

namespace Glib
{

  auto
  wrap (GtkEventControllerScroll* object, bool take_copy) -> Glib::RefPtr<Gtk::EventControllerScroll>
  {
    return Glib::make_refptr_for_instance<Gtk::EventControllerScroll> (
        dynamic_cast<Gtk::EventControllerScroll*> (
            Glib::wrap_auto ((GObject*) (object), take_copy)));
  }

} // namespace Glib

namespace Gtk
{

  auto
  EventControllerScroll_Class::init () -> const Glib::Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &EventControllerScroll_Class::class_init_function;

      register_derived_type (gtk_event_controller_scroll_get_type ());
    }

    return *this;
  }

  auto
  EventControllerScroll_Class::class_init_function (void* g_class,
                                                    void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);
  }

  auto
  EventControllerScroll_Class::wrap_new (GObject* object) -> Glib::ObjectBase*
  {
    return new EventControllerScroll ((GtkEventControllerScroll*) object);
  }

  auto
  EventControllerScroll::gobj_copy () -> GtkEventControllerScroll*
  {
    reference ();
    return gobj ();
  }

  EventControllerScroll::EventControllerScroll (
      const Glib::ConstructParams& construct_params)
    : EventController (construct_params)
  {
  }

  EventControllerScroll::EventControllerScroll (
      GtkEventControllerScroll* castitem)
    : EventController ((GtkEventController*) (castitem))
  {
  }

  EventControllerScroll::EventControllerScroll (
      EventControllerScroll&& src) noexcept
    : EventController (std::move (src))
  {
  }

  auto
  EventControllerScroll::operator= (EventControllerScroll&& src) noexcept -> EventControllerScroll&
  {
    EventController::operator= (std::move (src));
    return *this;
  }

  EventControllerScroll::~EventControllerScroll () noexcept {}

  EventControllerScroll::CppClassType
      EventControllerScroll::eventcontrollerscroll_class_;

  auto
  EventControllerScroll::get_type () -> GType
  {
    return eventcontrollerscroll_class_.init ().get_type ();
  }

  auto
  EventControllerScroll::get_base_type () -> GType
  {
    return gtk_event_controller_scroll_get_type ();
  }

  EventControllerScroll::EventControllerScroll ()
    : Glib::ObjectBase (nullptr),
      EventController (
          Glib::ConstructParams (eventcontrollerscroll_class_.init ()))
  {
  }

  auto
  EventControllerScroll::create () -> Glib::RefPtr<EventControllerScroll>
  {
    return Glib::make_refptr_for_instance<EventControllerScroll> (
        new EventControllerScroll ());
  }

  auto
  EventControllerScroll::set_flags (Flags flags) -> void
  {
    gtk_event_controller_scroll_set_flags (
        gobj (),
        static_cast<GtkEventControllerScrollFlags> (flags));
  }

  auto
  EventControllerScroll::get_flags () const -> Flags
  {
    return static_cast<Flags> (gtk_event_controller_scroll_get_flags (
        const_cast<GtkEventControllerScroll*> (gobj ())));
  }

  auto
  EventControllerScroll::get_unit () const -> Gdk::ScrollUnit
  {
    return static_cast<Gdk::ScrollUnit> (gtk_event_controller_scroll_get_unit (
        const_cast<GtkEventControllerScroll*> (gobj ())));
  }

  auto
  EventControllerScroll::signal_scroll_begin () -> Glib::SignalProxy<void ()>
  {
    return Glib::SignalProxy<void ()> (
        this,
        &EventControllerScroll_signal_scroll_begin_info);
  }

  auto
  EventControllerScroll::signal_scroll () -> Glib::SignalProxy<bool (double, double)>
  {
    return Glib::SignalProxy<bool (double, double)> (
        this,
        &EventControllerScroll_signal_scroll_info);
  }

  auto
  EventControllerScroll::signal_scroll_end () -> Glib::SignalProxy<void ()>
  {
    return Glib::SignalProxy<void ()> (
        this,
        &EventControllerScroll_signal_scroll_end_info);
  }

  auto
  EventControllerScroll::signal_decelerate () -> Glib::SignalProxy<void (double, double)>
  {
    return Glib::SignalProxy<void (double, double)> (
        this,
        &EventControllerScroll_signal_decelerate_info);
  }

  static_assert (
      Glib::Traits::ValueCompatibleWithWrapProperty<Flags>::value,
      "Type Flags cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  auto
  EventControllerScroll::property_flags () -> Glib::PropertyProxy<Flags>
  {
    return Glib::PropertyProxy<Flags> (this, "flags");
  }

  auto
  EventControllerScroll::property_flags () const -> Glib::PropertyProxy_ReadOnly<Flags>
  {
    return Glib::PropertyProxy_ReadOnly<Flags> (this, "flags");
  }

} // namespace Gtk
