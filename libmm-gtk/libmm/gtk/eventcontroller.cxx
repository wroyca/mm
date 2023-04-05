// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/gtk/eventcontroller.hxx>
#include <libmm/gtk/eventcontroller_p.hxx>

#include <gtk/gtk.h>

namespace
{
}

auto
glib::Value<gtk::PropagationPhase>::value_type () -> GType
{
  return gtk_propagation_phase_get_type ();
}

auto
glib::Value<gtk::PropagationLimit>::value_type () -> GType
{
  return gtk_propagation_limit_get_type ();
}

namespace glib
{

  auto
  wrap (GtkEventController* object, bool take_copy) -> glib::RefPtr<gtk::EventController>
  {
    return glib::make_refptr_for_instance<gtk::EventController> (
        dynamic_cast<gtk::EventController*> (
            glib::wrap_auto ((GObject*) (object), take_copy)));
  }

} // namespace glib

namespace gtk
{

  auto
  EventController_Class::init () -> const glib::Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &EventController_Class::class_init_function;

      register_derived_type (gtk_event_controller_get_type ());
    }

    return *this;
  }

  auto
  EventController_Class::class_init_function (void* g_class, void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);
  }

  auto
  EventController_Class::wrap_new (GObject* object) -> glib::ObjectBase*
  {
    return new EventController ((GtkEventController*) object);
  }

  auto
  EventController::gobj_copy () -> GtkEventController*
  {
    reference ();
    return gobj ();
  }

  EventController::EventController (
      const glib::ConstructParams& construct_params)
    : glib::Object (construct_params)
  {
  }

  EventController::EventController (GtkEventController* castitem)
    : glib::Object ((GObject*) (castitem))
  {
  }

  EventController::EventController (EventController&& src) noexcept
    : glib::Object (std::move (src))
  {
  }

  auto
  EventController::operator= (EventController&& src) noexcept -> EventController&
  {
    glib::Object::operator= (std::move (src));
    return *this;
  }

  EventController::~EventController () noexcept {}

  EventController::CppClassType EventController::eventcontroller_class_;

  auto
  EventController::get_type () -> GType
  {
    return eventcontroller_class_.init ().get_type ();
  }

  auto
  EventController::get_base_type () -> GType
  {
    return gtk_event_controller_get_type ();
  }

  EventController::EventController ()
    : glib::ObjectBase (nullptr),
      glib::Object (glib::ConstructParams (eventcontroller_class_.init ()))
  {
  }

  auto
  EventController::get_widget () -> Widget*
  {
    return glib::wrap (gtk_event_controller_get_widget (gobj ()));
  }

  auto
  EventController::get_widget () const -> const Widget*
  {
    return const_cast<EventController*> (this)->get_widget ();
  }

  auto
  EventController::reset () -> void
  {
    gtk_event_controller_reset (gobj ());
  }

  auto
  EventController::get_propagation_phase () const -> PropagationPhase
  {
    return static_cast<PropagationPhase> (
        gtk_event_controller_get_propagation_phase (
            const_cast<GtkEventController*> (gobj ())));
  }

  auto
  EventController::set_propagation_phase (PropagationPhase phase) -> void
  {
    gtk_event_controller_set_propagation_phase (
        gobj (),
        static_cast<GtkPropagationPhase> (phase));
  }

  auto
  EventController::get_propagation_limit () const -> PropagationLimit
  {
    return static_cast<PropagationLimit> (
        gtk_event_controller_get_propagation_limit (
            const_cast<GtkEventController*> (gobj ())));
  }

  auto
  EventController::set_propagation_limit (PropagationLimit limit) -> void
  {
    gtk_event_controller_set_propagation_limit (
        gobj (),
        static_cast<GtkPropagationLimit> (limit));
  }

  auto
  EventController::get_name () const -> glib::ustring
  {
    return glib::convert_const_gchar_ptr_to_ustring (
        gtk_event_controller_get_name (
            const_cast<GtkEventController*> (gobj ())));
  }

  auto
  EventController::set_name (const glib::ustring& name) -> void
  {
    gtk_event_controller_set_name (gobj (), name.c_str ());
  }

  auto
  EventController::get_current_event () const -> glib::RefPtr<const gdk::Event>
  {
    auto retvalue = glib::wrap (gtk_event_controller_get_current_event (
        const_cast<GtkEventController*> (gobj ())));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  EventController::get_current_event_time () const -> guint32
  {
    return gtk_event_controller_get_current_event_time (
        const_cast<GtkEventController*> (gobj ()));
  }

  auto
  EventController::get_current_event_device () -> glib::RefPtr<gdk::Device>
  {
    auto retvalue =
        glib::wrap (gtk_event_controller_get_current_event_device (gobj ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  EventController::get_current_event_device () const -> glib::RefPtr<const gdk::Device>
  {
    return const_cast<EventController*> (this)->get_current_event_device ();
  }

  auto
  EventController::get_current_event_state () const -> gdk::ModifierType
  {
    return static_cast<gdk::ModifierType> (
        gtk_event_controller_get_current_event_state (
            const_cast<GtkEventController*> (gobj ())));
  }

  auto
  EventController::property_widget () const -> glib::PropertyProxy_ReadOnly<Widget*>
  {
    return glib::PropertyProxy_ReadOnly<Widget*> (this, "widget");
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<PropagationPhase>::value,
      "Type PropagationPhase cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  EventController::property_propagation_phase () -> glib::PropertyProxy<PropagationPhase>
  {
    return glib::PropertyProxy<PropagationPhase> (this, "propagation-phase");
  }

  auto
  EventController::property_propagation_phase () const -> glib::PropertyProxy_ReadOnly<PropagationPhase>
  {
    return glib::PropertyProxy_ReadOnly<PropagationPhase> (this,
                                                           "propagation-phase");
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<PropagationLimit>::value,
      "Type PropagationLimit cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  EventController::property_propagation_limit () -> glib::PropertyProxy<PropagationLimit>
  {
    return glib::PropertyProxy<PropagationLimit> (this, "propagation-limit");
  }

  auto
  EventController::property_propagation_limit () const -> glib::PropertyProxy_ReadOnly<PropagationLimit>
  {
    return glib::PropertyProxy_ReadOnly<PropagationLimit> (this,
                                                           "propagation-limit");
  }

  auto
  EventController::property_name () -> glib::PropertyProxy<glib::ustring>
  {
    return glib::PropertyProxy<glib::ustring> (this, "name");
  }

  auto
  EventController::property_name () const -> glib::PropertyProxy_ReadOnly<glib::ustring>
  {
    return glib::PropertyProxy_ReadOnly<glib::ustring> (this, "name");
  }

} // namespace gtk
