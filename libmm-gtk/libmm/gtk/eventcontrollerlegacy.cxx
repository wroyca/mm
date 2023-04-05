// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/gtk/eventcontrollerlegacy.hxx>
#include <libmm/gtk/eventcontrollerlegacy_p.hxx>

#include <gtk/gtk.h>

namespace
{

  static auto
  EventControllerLegacy_signal_event_callback (GtkEventControllerLegacy* self,
                                               GdkEvent* p0,
                                               void* data) -> gboolean
  {
    using namespace gtk;
    using SlotType = sigc::slot<bool (const glib::RefPtr<const gdk::Event>&)>;

    auto obj = dynamic_cast<EventControllerLegacy*> (
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
  EventControllerLegacy_signal_event_notify_callback (
      GtkEventControllerLegacy* self,
      GdkEvent* p0,
      void* data) -> gboolean
  {
    using namespace gtk;
    using SlotType = sigc::slot<void (const glib::RefPtr<const gdk::Event>&)>;

    auto obj = dynamic_cast<EventControllerLegacy*> (
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

  static const glib::SignalProxyInfo EventControllerLegacy_signal_event_info = {
      "event",
      (GCallback) &EventControllerLegacy_signal_event_callback,
      (GCallback) &EventControllerLegacy_signal_event_notify_callback};

} // namespace

namespace glib
{

  auto
  wrap (GtkEventControllerLegacy* object, bool take_copy) -> glib::RefPtr<gtk::EventControllerLegacy>
  {
    return glib::make_refptr_for_instance<gtk::EventControllerLegacy> (
        dynamic_cast<gtk::EventControllerLegacy*> (
            glib::wrap_auto ((GObject*) (object), take_copy)));
  }

} // namespace glib

namespace gtk
{

  auto
  EventControllerLegacy_Class::init () -> const glib::Class&
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
  EventControllerLegacy_Class::wrap_new (GObject* object) -> glib::ObjectBase*
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
      const glib::ConstructParams& construct_params)
    : EventController (construct_params)
  {
  }

  EventControllerLegacy::EventControllerLegacy (
      GtkEventControllerLegacy* castitem)
    : EventController ((GtkEventController*) (castitem))
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

  EventControllerLegacy::~EventControllerLegacy () noexcept {}

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
    : glib::ObjectBase (nullptr),
      EventController (
          glib::ConstructParams (eventcontrollerlegacy_class_.init ()))
  {
  }

  auto
  EventControllerLegacy::create () -> glib::RefPtr<EventControllerLegacy>
  {
    return glib::make_refptr_for_instance<EventControllerLegacy> (
        new EventControllerLegacy ());
  }

  auto
  EventControllerLegacy::signal_event () -> glib::SignalProxy<bool (const glib::RefPtr<const gdk::Event>&)>
  {
    return glib::SignalProxy<bool (const glib::RefPtr<const gdk::Event>&)> (
        this,
        &EventControllerLegacy_signal_event_info);
  }

} // namespace gtk
