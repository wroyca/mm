

#include <libmm-glib/mm-glib.hxx>

#include <libmm-gtk/eventcontrollerfocus.hxx>
#include <libmm-gtk/eventcontrollerfocus_p.hxx>

#include <gtk/gtk.h>

namespace
{

  const Glib::SignalProxyInfo EventControllerFocus_signal_enter_info = {
      "enter",
      (GCallback) &Glib::SignalProxyNormal::slot0_void_callback,
      (GCallback) &Glib::SignalProxyNormal::slot0_void_callback};

  const Glib::SignalProxyInfo EventControllerFocus_signal_leave_info = {
      "leave",
      (GCallback) &Glib::SignalProxyNormal::slot0_void_callback,
      (GCallback) &Glib::SignalProxyNormal::slot0_void_callback};

} // namespace

namespace Glib
{

  auto
  wrap (GtkEventControllerFocus* object, const bool take_copy) -> RefPtr<Gtk::EventControllerFocus>
  {
    return Glib::make_refptr_for_instance<Gtk::EventControllerFocus> (
        dynamic_cast<Gtk::EventControllerFocus*> (
            wrap_auto ((GObject*) object, take_copy)));
  }

} // namespace Glib

namespace Gtk
{

  auto
  EventControllerFocus_Class::init () -> const Class&
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
  EventControllerFocus_Class::wrap_new (GObject* object) -> Glib::ObjectBase*
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
      const Glib::ConstructParams& construct_params)
    : EventController (construct_params)
  {
  }

  EventControllerFocus::EventControllerFocus (GtkEventControllerFocus* castitem)
    : EventController ((GtkEventController*) castitem)
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

  EventControllerFocus::~EventControllerFocus () noexcept = default;

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
    : ObjectBase (nullptr),
      EventController (
          Glib::ConstructParams (eventcontrollerfocus_class_.init ()))
  {
  }

  auto
  EventControllerFocus::create () -> Glib::RefPtr<EventControllerFocus>
  {
    return Glib::make_refptr_for_instance<EventControllerFocus> (
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
  EventControllerFocus::signal_enter () -> Glib::SignalProxy<void ()>
  {
    return {this, &EventControllerFocus_signal_enter_info};
  }

  auto
  EventControllerFocus::signal_leave () -> Glib::SignalProxy<void ()>
  {
    return {this, &EventControllerFocus_signal_leave_info};
  }

  auto
  EventControllerFocus::property_is_focus () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return {this, "is-focus"};
  }

  auto
  EventControllerFocus::property_contains_focus () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return {this, "contains-focus"};
  }

} // namespace Gtk
