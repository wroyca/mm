

#include <libmm-glib/mm-glib.hxx>

#include <libmm-gtk/eventcontrollerlegacy.hxx>
#include <libmm-gtk/eventcontrollerlegacy_p.hxx>

#include <gtk/gtk.h>

namespace
{

  auto
  EventControllerLegacy_signal_event_callback (GtkEventControllerLegacy* self,
                                               GdkEvent* p0,
                                               void* data) -> gboolean
  {
    using namespace Gtk;
    using SlotType = sigc::slot<bool (const Glib::RefPtr<const Gdk::Event>&)>;

    const auto obj = dynamic_cast<EventControllerLegacy*> (
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
  EventControllerLegacy_signal_event_notify_callback (
      GtkEventControllerLegacy* self,
      GdkEvent* p0,
      void* data) -> gboolean
  {
    using namespace Gtk;
    using SlotType = sigc::slot<void (const Glib::RefPtr<const Gdk::Event>&)>;

    const auto obj = dynamic_cast<EventControllerLegacy*> (
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

  const Glib::SignalProxyInfo EventControllerLegacy_signal_event_info = {
      "event",
      (GCallback) &EventControllerLegacy_signal_event_callback,
      (GCallback) &EventControllerLegacy_signal_event_notify_callback};

} // namespace

namespace Glib
{

  auto
  wrap (GtkEventControllerLegacy* object, const bool take_copy) -> RefPtr<Gtk::EventControllerLegacy>
  {
    return Glib::make_refptr_for_instance<Gtk::EventControllerLegacy> (
        dynamic_cast<Gtk::EventControllerLegacy*> (
            wrap_auto ((GObject*) object, take_copy)));
  }

} // namespace Glib

namespace Gtk
{

  auto
  EventControllerLegacy_Class::init () -> const Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &EventControllerLegacy_Class::class_init_function;

      register_derived_type (gtk_event_controller_legacy_get_type ());
    }

    return *this;
  }

  auto
  EventControllerLegacy_Class::class_init_function (void* g_class,
                                                    void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);
  }

  auto
  EventControllerLegacy_Class::wrap_new (GObject* object) -> Glib::ObjectBase*
  {
    return new EventControllerLegacy ((GtkEventControllerLegacy*) object);
  }

  auto
  EventControllerLegacy::gobj_copy () -> GtkEventControllerLegacy*
  {
    reference ();
    return gobj ();
  }

  EventControllerLegacy::EventControllerLegacy (
      const Glib::ConstructParams& construct_params)
    : EventController (construct_params)
  {
  }

  EventControllerLegacy::EventControllerLegacy (
      GtkEventControllerLegacy* castitem)
    : EventController ((GtkEventController*) castitem)
  {
  }

  EventControllerLegacy::EventControllerLegacy (
      EventControllerLegacy&& src) noexcept
    : EventController (std::move (src))
  {
  }

  auto
  EventControllerLegacy::operator= (EventControllerLegacy&& src) noexcept -> EventControllerLegacy&
  {
    EventController::operator= (std::move (src));
    return *this;
  }

  EventControllerLegacy::~EventControllerLegacy () noexcept = default;

  EventControllerLegacy::CppClassType
      EventControllerLegacy::eventcontrollerlegacy_class_;

  auto
  EventControllerLegacy::get_type () -> GType
  {
    return eventcontrollerlegacy_class_.init ().get_type ();
  }

  auto
  EventControllerLegacy::get_base_type () -> GType
  {
    return gtk_event_controller_legacy_get_type ();
  }

  EventControllerLegacy::EventControllerLegacy ()
    : ObjectBase (nullptr),
      EventController (
          Glib::ConstructParams (eventcontrollerlegacy_class_.init ()))
  {
  }

  auto
  EventControllerLegacy::create () -> Glib::RefPtr<EventControllerLegacy>
  {
    return Glib::make_refptr_for_instance<EventControllerLegacy> (
        new EventControllerLegacy ());
  }

  auto
  EventControllerLegacy::signal_event () -> Glib::SignalProxy<bool (const Glib::RefPtr<const Gdk::Event>&)>
  {
    return {this, &EventControllerLegacy_signal_event_info};
  }

} // namespace Gtk
