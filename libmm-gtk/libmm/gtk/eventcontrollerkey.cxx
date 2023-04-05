// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/gtk/eventcontrollerkey.hxx>
#include <libmm/gtk/eventcontrollerkey_p.hxx>

#include <gtk/gtk.h>

namespace
{

  static auto
  EventControllerKey_signal_key_pressed_callback (GtkEventControllerKey* self,
                                                  guint p0,
                                                  guint p1,
                                                  GdkModifierType p2,
                                                  void* data) -> gboolean
  {
    using namespace gtk;
    using SlotType = sigc::slot<bool (guint, guint, gdk::ModifierType)>;

    auto obj = dynamic_cast<EventControllerKey*> (
        glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj)
    {
      try
      {
        if (const auto slot = glib::SignalProxyNormal::data_to_slot (data))
          return static_cast<int> ((*static_cast<SlotType*> (
              slot)) (p0, p1, static_cast<gdk::ModifierType> (p2)));
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
  EventControllerKey_signal_key_pressed_notify_callback (
      GtkEventControllerKey* self,
      guint p0,
      guint p1,
      GdkModifierType p2,
      void* data) -> gboolean
  {
    using namespace gtk;
    using SlotType = sigc::slot<void (guint, guint, gdk::ModifierType)>;

    auto obj = dynamic_cast<EventControllerKey*> (
        glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj)
    {
      try
      {
        if (const auto slot = glib::SignalProxyNormal::data_to_slot (data))
          (*static_cast<SlotType*> (
              slot)) (p0, p1, static_cast<gdk::ModifierType> (p2));
      }
      catch (...)
      {
        glib::exception_handlers_invoke ();
      }
    }

    using RType = gboolean;
    return RType ();
  }

  static const glib::SignalProxyInfo
      EventControllerKey_signal_key_pressed_info = {
          "key-pressed",
          (GCallback) &EventControllerKey_signal_key_pressed_callback,
          (GCallback) &EventControllerKey_signal_key_pressed_notify_callback};

  static auto
  EventControllerKey_signal_key_released_callback (GtkEventControllerKey* self,
                                                   guint p0,
                                                   guint p1,
                                                   GdkModifierType p2,
                                                   void* data) -> void
  {
    using namespace gtk;
    using SlotType = sigc::slot<void (guint, guint, gdk::ModifierType)>;

    auto obj = dynamic_cast<EventControllerKey*> (
        glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj)
    {
      try
      {
        if (const auto slot = glib::SignalProxyNormal::data_to_slot (data))
          (*static_cast<SlotType*> (
              slot)) (p0, p1, static_cast<gdk::ModifierType> (p2));
      }
      catch (...)
      {
        glib::exception_handlers_invoke ();
      }
    }
  }

  static const glib::SignalProxyInfo
      EventControllerKey_signal_key_released_info = {
          "key-released",
          (GCallback) &EventControllerKey_signal_key_released_callback,
          (GCallback) &EventControllerKey_signal_key_released_callback};

  static auto
  EventControllerKey_signal_modifiers_callback (GtkEventControllerKey* self,
                                                GdkModifierType p0,
                                                void* data) -> gboolean
  {
    using namespace gtk;
    using SlotType = sigc::slot<bool (gdk::ModifierType)>;

    auto obj = dynamic_cast<EventControllerKey*> (
        glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj)
    {
      try
      {
        if (const auto slot = glib::SignalProxyNormal::data_to_slot (data))
          return static_cast<int> ((*static_cast<SlotType*> (slot)) (
              static_cast<gdk::ModifierType> (p0)));
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
  EventControllerKey_signal_modifiers_notify_callback (
      GtkEventControllerKey* self,
      GdkModifierType p0,
      void* data) -> gboolean
  {
    using namespace gtk;
    using SlotType = sigc::slot<void (gdk::ModifierType)>;

    auto obj = dynamic_cast<EventControllerKey*> (
        glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj)
    {
      try
      {
        if (const auto slot = glib::SignalProxyNormal::data_to_slot (data))
          (*static_cast<SlotType*> (slot)) (
              static_cast<gdk::ModifierType> (p0));
      }
      catch (...)
      {
        glib::exception_handlers_invoke ();
      }
    }

    using RType = gboolean;
    return RType ();
  }

  static const glib::SignalProxyInfo EventControllerKey_signal_modifiers_info =
      {"modifiers",
       (GCallback) &EventControllerKey_signal_modifiers_callback,
       (GCallback) &EventControllerKey_signal_modifiers_notify_callback};

  static const glib::SignalProxyInfo EventControllerKey_signal_im_update_info =
      {"im-update",
       (GCallback) &glib::SignalProxyNormal::slot0_void_callback,
       (GCallback) &glib::SignalProxyNormal::slot0_void_callback};

} // namespace

namespace glib
{

  auto
  wrap (GtkEventControllerKey* object, bool take_copy) -> glib::RefPtr<gtk::EventControllerKey>
  {
    return glib::make_refptr_for_instance<gtk::EventControllerKey> (
        dynamic_cast<gtk::EventControllerKey*> (
            glib::wrap_auto ((GObject*) (object), take_copy)));
  }

} // namespace glib

namespace gtk
{

  auto
  EventControllerKey_Class::init () -> const glib::Class&
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
  EventControllerKey_Class::wrap_new (GObject* object) -> glib::ObjectBase*
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
      const glib::ConstructParams& construct_params)
    : EventController (construct_params)
  {
  }

  EventControllerKey::EventControllerKey (GtkEventControllerKey* castitem)
    : EventController ((GtkEventController*) (castitem))
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

  EventControllerKey::~EventControllerKey () noexcept {}

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
    : glib::ObjectBase (nullptr),
      EventController (
          glib::ConstructParams (eventcontrollerkey_class_.init ()))
  {
  }

  auto
  EventControllerKey::create () -> glib::RefPtr<EventControllerKey>
  {
    return glib::make_refptr_for_instance<EventControllerKey> (
        new EventControllerKey ());
  }

  auto
  EventControllerKey::forward (Widget& widget) -> bool
  {
    return gtk_event_controller_key_forward (gobj (), (widget).gobj ());
  }

  auto
  EventControllerKey::get_group () const -> guint
  {
    return gtk_event_controller_key_get_group (
        const_cast<GtkEventControllerKey*> (gobj ()));
  }

  auto
  EventControllerKey::signal_key_pressed () -> glib::SignalProxy<bool (guint, guint, gdk::ModifierType)>
  {
    return glib::SignalProxy<bool (guint, guint, gdk::ModifierType)> (
        this,
        &EventControllerKey_signal_key_pressed_info);
  }

  auto
  EventControllerKey::signal_key_released () -> glib::SignalProxy<void (guint, guint, gdk::ModifierType)>
  {
    return glib::SignalProxy<void (guint, guint, gdk::ModifierType)> (
        this,
        &EventControllerKey_signal_key_released_info);
  }

  auto
  EventControllerKey::signal_modifiers () -> glib::SignalProxy<bool (gdk::ModifierType)>
  {
    return glib::SignalProxy<bool (gdk::ModifierType)> (
        this,
        &EventControllerKey_signal_modifiers_info);
  }

  auto
  EventControllerKey::signal_im_update () -> glib::SignalProxy<void ()>
  {
    return glib::SignalProxy<void ()> (
        this,
        &EventControllerKey_signal_im_update_info);
  }

} // namespace gtk
