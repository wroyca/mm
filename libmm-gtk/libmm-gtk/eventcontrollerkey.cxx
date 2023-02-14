// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm-glib/mm-glib.hxx>

#include <libmm-gtk/eventcontrollerkey.hxx>
#include <libmm-gtk/eventcontrollerkey_p.hxx>

#include <gtk/gtk.h>

namespace
{

  auto
  EventControllerKey_signal_key_pressed_callback (GtkEventControllerKey* self,
                                                  const guint p0,
                                                  const guint p1,
                                                  GdkModifierType p2,
                                                  void* data) -> gboolean
  {
    using namespace Gtk;
    using SlotType = sigc::slot<bool (guint, guint, Gdk::ModifierType)>;

    const auto obj = dynamic_cast<EventControllerKey*> (
        Glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj)
    {
      try
      {
        if (const auto slot = Glib::SignalProxyNormal::data_to_slot (data))
          return (*static_cast<SlotType*> (
              slot)) (p0, p1, static_cast<Gdk::ModifierType> (p2));
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
  EventControllerKey_signal_key_pressed_notify_callback (
      GtkEventControllerKey* self,
      const guint p0,
      const guint p1,
      GdkModifierType p2,
      void* data) -> gboolean
  {
    using namespace Gtk;
    using SlotType = sigc::slot<void (guint, guint, Gdk::ModifierType)>;

    const auto obj = dynamic_cast<EventControllerKey*> (
        Glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj)
    {
      try
      {
        if (const auto slot = Glib::SignalProxyNormal::data_to_slot (data))
          (*static_cast<SlotType*> (
              slot)) (p0, p1, static_cast<Gdk::ModifierType> (p2));
      }
      catch (...)
      {
        Glib::exception_handlers_invoke ();
      }
    }

    using RType = gboolean;
    return RType ();
  }

  const Glib::SignalProxyInfo EventControllerKey_signal_key_pressed_info = {
      "key-pressed",
      (GCallback) &EventControllerKey_signal_key_pressed_callback,
      (GCallback) &EventControllerKey_signal_key_pressed_notify_callback};

  auto
  EventControllerKey_signal_key_released_callback (GtkEventControllerKey* self,
                                                   const guint p0,
                                                   const guint p1,
                                                   GdkModifierType p2,
                                                   void* data) -> void
  {
    using namespace Gtk;
    using SlotType = sigc::slot<void (guint, guint, Gdk::ModifierType)>;

    const auto obj = dynamic_cast<EventControllerKey*> (
        Glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj)
    {
      try
      {
        if (const auto slot = Glib::SignalProxyNormal::data_to_slot (data))
          (*static_cast<SlotType*> (
              slot)) (p0, p1, static_cast<Gdk::ModifierType> (p2));
      }
      catch (...)
      {
        Glib::exception_handlers_invoke ();
      }
    }
  }

  const Glib::SignalProxyInfo EventControllerKey_signal_key_released_info = {
      "key-released",
      (GCallback) &EventControllerKey_signal_key_released_callback,
      (GCallback) &EventControllerKey_signal_key_released_callback};

  auto
  EventControllerKey_signal_modifiers_callback (GtkEventControllerKey* self,
                                                GdkModifierType p0,
                                                void* data) -> gboolean
  {
    using namespace Gtk;
    using SlotType = sigc::slot<bool (Gdk::ModifierType)>;

    const auto obj = dynamic_cast<EventControllerKey*> (
        Glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj)
    {
      try
      {
        if (const auto slot = Glib::SignalProxyNormal::data_to_slot (data))
          return (*static_cast<SlotType*> (slot)) (
              static_cast<Gdk::ModifierType> (p0));
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
  EventControllerKey_signal_modifiers_notify_callback (
      GtkEventControllerKey* self,
      GdkModifierType p0,
      void* data) -> gboolean
  {
    using namespace Gtk;
    using SlotType = sigc::slot<void (Gdk::ModifierType)>;

    const auto obj = dynamic_cast<EventControllerKey*> (
        Glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj)
    {
      try
      {
        if (const auto slot = Glib::SignalProxyNormal::data_to_slot (data))
          (*static_cast<SlotType*> (slot)) (
              static_cast<Gdk::ModifierType> (p0));
      }
      catch (...)
      {
        Glib::exception_handlers_invoke ();
      }
    }

    using RType = gboolean;
    return RType ();
  }

  const Glib::SignalProxyInfo EventControllerKey_signal_modifiers_info = {
      "modifiers",
      (GCallback) &EventControllerKey_signal_modifiers_callback,
      (GCallback) &EventControllerKey_signal_modifiers_notify_callback};

  const Glib::SignalProxyInfo EventControllerKey_signal_im_update_info = {
      "im-update",
      (GCallback) &Glib::SignalProxyNormal::slot0_void_callback,
      (GCallback) &Glib::SignalProxyNormal::slot0_void_callback};

} // namespace

namespace Glib
{

  auto
  wrap (GtkEventControllerKey* object, const bool take_copy) -> RefPtr<Gtk::EventControllerKey>
  {
    return Glib::make_refptr_for_instance<Gtk::EventControllerKey> (
        dynamic_cast<Gtk::EventControllerKey*> (
            wrap_auto ((GObject*) object, take_copy)));
  }

} // namespace Glib

namespace Gtk
{

  auto
  EventControllerKey_Class::init () -> const Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &EventControllerKey_Class::class_init_function;

      register_derived_type (gtk_event_controller_key_get_type ());
    }

    return *this;
  }

  auto
  EventControllerKey_Class::class_init_function (void* g_class,
                                                 void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);
  }

  auto
  EventControllerKey_Class::wrap_new (GObject* object) -> Glib::ObjectBase*
  {
    return new EventControllerKey ((GtkEventControllerKey*) object);
  }

  auto
  EventControllerKey::gobj_copy () -> GtkEventControllerKey*
  {
    reference ();
    return gobj ();
  }

  EventControllerKey::EventControllerKey (
      const Glib::ConstructParams& construct_params)
    : EventController (construct_params)
  {
  }

  EventControllerKey::EventControllerKey (GtkEventControllerKey* castitem)
    : EventController ((GtkEventController*) castitem)
  {
  }

  EventControllerKey::EventControllerKey (EventControllerKey&& src) noexcept
    : EventController (std::move (src))
  {
  }

  auto
  EventControllerKey::operator= (EventControllerKey&& src) noexcept -> EventControllerKey&
  {
    EventController::operator= (std::move (src));
    return *this;
  }

  EventControllerKey::~EventControllerKey () noexcept = default;

  EventControllerKey::CppClassType
      EventControllerKey::eventcontrollerkey_class_;

  auto
  EventControllerKey::get_type () -> GType
  {
    return eventcontrollerkey_class_.init ().get_type ();
  }

  auto
  EventControllerKey::get_base_type () -> GType
  {
    return gtk_event_controller_key_get_type ();
  }

  EventControllerKey::EventControllerKey ()
    : ObjectBase (nullptr),
      EventController (
          Glib::ConstructParams (eventcontrollerkey_class_.init ()))
  {
  }

  auto
  EventControllerKey::create () -> Glib::RefPtr<EventControllerKey>
  {
    return Glib::make_refptr_for_instance<EventControllerKey> (
        new EventControllerKey ());
  }

  auto
  EventControllerKey::forward (Widget& widget) -> bool
  {
    return gtk_event_controller_key_forward (gobj (), widget.gobj ());
  }

  auto
  EventControllerKey::get_group () const -> guint
  {
    return gtk_event_controller_key_get_group (
        const_cast<GtkEventControllerKey*> (gobj ()));
  }

  auto
  EventControllerKey::signal_key_pressed () -> Glib::SignalProxy<bool (guint, guint, Gdk::ModifierType)>
  {
    return {this, &EventControllerKey_signal_key_pressed_info};
  }

  auto
  EventControllerKey::signal_key_released () -> Glib::SignalProxy<void (guint, guint, Gdk::ModifierType)>
  {
    return {this, &EventControllerKey_signal_key_released_info};
  }

  auto
  EventControllerKey::signal_modifiers () -> Glib::SignalProxy<bool (Gdk::ModifierType)>
  {
    return {this, &EventControllerKey_signal_modifiers_info};
  }

  auto
  EventControllerKey::signal_im_update () -> Glib::SignalProxy<void ()>
  {
    return {this, &EventControllerKey_signal_im_update_info};
  }

} // namespace Gtk
