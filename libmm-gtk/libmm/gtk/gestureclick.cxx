// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/gtk/gestureclick.hxx>
#include <libmm/gtk/gestureclick_p.hxx>

#include <gtk/gtk.h>

namespace
{

  static auto
  GestureClick_signal_pressed_callback (GtkGestureClick* self,
                                        gint p0,
                                        gdouble p1,
                                        gdouble p2,
                                        void* data) -> void
  {
    using namespace gtk;
    using SlotType = sigc::slot<void (int, double, double)>;

    auto obj = dynamic_cast<GestureClick*> (
        glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj)
    {
      try
      {
        if (const auto slot = glib::SignalProxyNormal::data_to_slot (data))
          (*static_cast<SlotType*> (slot)) (p0, p1, p2);
      }
      catch (...)
      {
        glib::exception_handlers_invoke ();
      }
    }
  }

  static const glib::SignalProxyInfo GestureClick_signal_pressed_info = {
      "pressed",
      (GCallback) &GestureClick_signal_pressed_callback,
      (GCallback) &GestureClick_signal_pressed_callback};

  static auto
  GestureClick_signal_released_callback (GtkGestureClick* self,
                                         gint p0,
                                         gdouble p1,
                                         gdouble p2,
                                         void* data) -> void
  {
    using namespace gtk;
    using SlotType = sigc::slot<void (int, double, double)>;

    auto obj = dynamic_cast<GestureClick*> (
        glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj)
    {
      try
      {
        if (const auto slot = glib::SignalProxyNormal::data_to_slot (data))
          (*static_cast<SlotType*> (slot)) (p0, p1, p2);
      }
      catch (...)
      {
        glib::exception_handlers_invoke ();
      }
    }
  }

  static const glib::SignalProxyInfo GestureClick_signal_released_info = {
      "released",
      (GCallback) &GestureClick_signal_released_callback,
      (GCallback) &GestureClick_signal_released_callback};

  static const glib::SignalProxyInfo GestureClick_signal_stopped_info = {
      "stopped",
      (GCallback) &glib::SignalProxyNormal::slot0_void_callback,
      (GCallback) &glib::SignalProxyNormal::slot0_void_callback};

  static auto
  GestureClick_signal_unpaired_release_callback (GtkGestureClick* self,
                                                 gdouble p0,
                                                 gdouble p1,
                                                 guint p2,
                                                 GdkEventSequence* p3,
                                                 void* data) -> void
  {
    using namespace gtk;
    using SlotType =
        sigc::slot<void (double, double, guint, gdk::EventSequence*)>;

    auto obj = dynamic_cast<GestureClick*> (
        glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj)
    {
      try
      {
        if (const auto slot = glib::SignalProxyNormal::data_to_slot (data))
          (*static_cast<SlotType*> (
              slot)) (p0, p1, p2, reinterpret_cast<gdk::EventSequence*> (p3));
      }
      catch (...)
      {
        glib::exception_handlers_invoke ();
      }
    }
  }

  static const glib::SignalProxyInfo GestureClick_signal_unpaired_release_info =
      {"unpaired-release",
       (GCallback) &GestureClick_signal_unpaired_release_callback,
       (GCallback) &GestureClick_signal_unpaired_release_callback};

} // namespace

namespace glib
{

  auto
  wrap (GtkGestureClick* object, bool take_copy) -> glib::RefPtr<gtk::GestureClick>
  {
    return glib::make_refptr_for_instance<gtk::GestureClick> (
        dynamic_cast<gtk::GestureClick*> (
            glib::wrap_auto ((GObject*) (object), take_copy)));
  }

} // namespace glib

namespace gtk
{

  auto
  GestureClick_Class::init () -> const glib::Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &GestureClick_Class::class_init_function;

      register_derived_type (gtk_gesture_click_get_type ());
    }

    return *this;
  }

  auto
  GestureClick_Class::class_init_function (void* g_class, void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);
  }

  auto
  GestureClick_Class::wrap_new (GObject* object) -> glib::ObjectBase*
  {
    return new GestureClick ((GtkGestureClick*) object);
  }

  auto
  GestureClick::gobj_copy () -> GtkGestureClick*
  {
    reference ();
    return gobj ();
  }

  GestureClick::GestureClick (const glib::ConstructParams& construct_params)
    : GestureSingle (construct_params)
  {
  }

  GestureClick::GestureClick (GtkGestureClick* castitem)
    : GestureSingle ((GtkGestureSingle*) (castitem))
  {
  }

  GestureClick::GestureClick (GestureClick&& src) noexcept
    : GestureSingle (std::move (src))
  {
  }

  auto
  GestureClick::operator= (GestureClick&& src) noexcept -> GestureClick&
  {
    GestureSingle::operator= (std::move (src));
    return *this;
  }

  GestureClick::~GestureClick () noexcept {}

  GestureClick::CppClassType GestureClick::gestureclick_class_;

  auto
  GestureClick::get_type () -> GType
  {
    return gestureclick_class_.init ().get_type ();
  }

  auto
  GestureClick::get_base_type () -> GType
  {
    return gtk_gesture_click_get_type ();
  }

  GestureClick::GestureClick ()
    : glib::ObjectBase (nullptr),
      GestureSingle (glib::ConstructParams (gestureclick_class_.init ()))
  {
  }

  auto
  GestureClick::create () -> glib::RefPtr<GestureClick>
  {
    return glib::make_refptr_for_instance<GestureClick> (new GestureClick ());
  }

  auto
  GestureClick::signal_pressed () -> glib::SignalProxy<void (int, double, double)>
  {
    return glib::SignalProxy<void (int, double, double)> (
        this,
        &GestureClick_signal_pressed_info);
  }

  auto
  GestureClick::signal_released () -> glib::SignalProxy<void (int, double, double)>
  {
    return glib::SignalProxy<void (int, double, double)> (
        this,
        &GestureClick_signal_released_info);
  }

  auto
  GestureClick::signal_stopped () -> glib::SignalProxy<void ()>
  {
    return glib::SignalProxy<void ()> (this, &GestureClick_signal_stopped_info);
  }

  auto
  GestureClick::signal_unpaired_release () -> glib::SignalProxy<void (double, double, guint, gdk::EventSequence*)>
  {
    return glib::SignalProxy<
        void (double, double, guint, gdk::EventSequence*)> (
        this,
        &GestureClick_signal_unpaired_release_info);
  }

} // namespace gtk
