// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/gtk/eventcontrollerfocus.hxx>
#include <libmm/gtk/eventcontrollerfocus_p.hxx>

#include <gtk/gtk.h>

namespace
{

  static const glib::SignalProxyInfo EventControllerFocus_signal_enter_info = {
      "enter",
      (GCallback) &glib::SignalProxyNormal::slot0_void_callback,
      (GCallback) &glib::SignalProxyNormal::slot0_void_callback};

  static const glib::SignalProxyInfo EventControllerFocus_signal_leave_info = {
      "leave",
      (GCallback) &glib::SignalProxyNormal::slot0_void_callback,
      (GCallback) &glib::SignalProxyNormal::slot0_void_callback};

} // namespace

namespace glib
{

  auto
  wrap (GtkEventControllerFocus* object, bool take_copy) -> glib::RefPtr<gtk::EventControllerFocus>
  {
    return glib::make_refptr_for_instance<gtk::EventControllerFocus> (
        dynamic_cast<gtk::EventControllerFocus*> (
            glib::wrap_auto ((GObject*) (object), take_copy)));
  }

} // namespace glib

namespace gtk
{

  auto
  EventControllerFocus_Class::init () -> const glib::Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &EventControllerFocus_Class::class_init_function;

      register_derived_type (gtk_event_controller_focus_get_type ());
    }

    return *this;
  }

  auto
  EventControllerFocus_Class::class_init_function (void* g_class,
                                                   void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);
  }

  auto
  EventControllerFocus_Class::wrap_new (GObject* object) -> glib::ObjectBase*
  {
    return new EventControllerFocus ((GtkEventControllerFocus*) object);
  }

  auto
  EventControllerFocus::gobj_copy () -> GtkEventControllerFocus*
  {
    reference ();
    return gobj ();
  }

  EventControllerFocus::EventControllerFocus (
      const glib::ConstructParams& construct_params)
    : EventController (construct_params)
  {
  }

  EventControllerFocus::EventControllerFocus (GtkEventControllerFocus* castitem)
    : EventController ((GtkEventController*) (castitem))
  {
  }

  EventControllerFocus::EventControllerFocus (
      EventControllerFocus&& src) noexcept
    : EventController (std::move (src))
  {
  }

  auto
  EventControllerFocus::operator= (EventControllerFocus&& src) noexcept -> EventControllerFocus&
  {
    EventController::operator= (std::move (src));
    return *this;
  }

  EventControllerFocus::~EventControllerFocus () noexcept {}

  EventControllerFocus::CppClassType
      EventControllerFocus::eventcontrollerfocus_class_;

  auto
  EventControllerFocus::get_type () -> GType
  {
    return eventcontrollerfocus_class_.init ().get_type ();
  }

  auto
  EventControllerFocus::get_base_type () -> GType
  {
    return gtk_event_controller_focus_get_type ();
  }

  EventControllerFocus::EventControllerFocus ()
    : glib::ObjectBase (nullptr),
      EventController (
          glib::ConstructParams (eventcontrollerfocus_class_.init ()))
  {
  }

  auto
  EventControllerFocus::create () -> glib::RefPtr<EventControllerFocus>
  {
    return glib::make_refptr_for_instance<EventControllerFocus> (
        new EventControllerFocus ());
  }

  auto
  EventControllerFocus::contains_focus () const -> bool
  {
    return gtk_event_controller_focus_contains_focus (
        const_cast<GtkEventControllerFocus*> (gobj ()));
  }

  auto
  EventControllerFocus::is_focus () const -> bool
  {
    return gtk_event_controller_focus_is_focus (
        const_cast<GtkEventControllerFocus*> (gobj ()));
  }

  auto
  EventControllerFocus::signal_enter () -> glib::SignalProxy<void ()>
  {
    return glib::SignalProxy<void ()> (this,
                                       &EventControllerFocus_signal_enter_info);
  }

  auto
  EventControllerFocus::signal_leave () -> glib::SignalProxy<void ()>
  {
    return glib::SignalProxy<void ()> (this,
                                       &EventControllerFocus_signal_leave_info);
  }

  auto
  EventControllerFocus::property_is_focus () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "is-focus");
  }

  auto
  EventControllerFocus::property_contains_focus () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "contains-focus");
  }

} // namespace gtk
