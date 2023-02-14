

#include <libmm-glib/mm-glib.hxx>

#include <libmm-gtk/gestureclick.hxx>
#include <libmm-gtk/gestureclick_p.hxx>

#include <gtk/gtk.h>

namespace
{

  auto
  GestureClick_signal_pressed_callback (GtkGestureClick* self,
                                        const gint p0,
                                        const gdouble p1,
                                        const gdouble p2,
                                        void* data) -> void
  {
    using namespace Gtk;
    using SlotType = sigc::slot<void (int, double, double)>;

    const auto obj = dynamic_cast<GestureClick*> (
        Glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj)
    {
      try
      {
        if (const auto slot = Glib::SignalProxyNormal::data_to_slot (data))
          (*static_cast<SlotType*> (slot)) (p0, p1, p2);
      }
      catch (...)
      {
        Glib::exception_handlers_invoke ();
      }
    }
  }

  const Glib::SignalProxyInfo GestureClick_signal_pressed_info = {
      "pressed",
      (GCallback) &GestureClick_signal_pressed_callback,
      (GCallback) &GestureClick_signal_pressed_callback};

  auto
  GestureClick_signal_released_callback (GtkGestureClick* self,
                                         const gint p0,
                                         const gdouble p1,
                                         const gdouble p2,
                                         void* data) -> void
  {
    using namespace Gtk;
    using SlotType = sigc::slot<void (int, double, double)>;

    const auto obj = dynamic_cast<GestureClick*> (
        Glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj)
    {
      try
      {
        if (const auto slot = Glib::SignalProxyNormal::data_to_slot (data))
          (*static_cast<SlotType*> (slot)) (p0, p1, p2);
      }
      catch (...)
      {
        Glib::exception_handlers_invoke ();
      }
    }
  }

  const Glib::SignalProxyInfo GestureClick_signal_released_info = {
      "released",
      (GCallback) &GestureClick_signal_released_callback,
      (GCallback) &GestureClick_signal_released_callback};

  const Glib::SignalProxyInfo GestureClick_signal_stopped_info = {
      "stopped",
      (GCallback) &Glib::SignalProxyNormal::slot0_void_callback,
      (GCallback) &Glib::SignalProxyNormal::slot0_void_callback};

  auto
  GestureClick_signal_unpaired_release_callback (GtkGestureClick* self,
                                                 const gdouble p0,
                                                 const gdouble p1,
                                                 const guint p2,
                                                 GdkEventSequence* p3,
                                                 void* data) -> void
  {
    using namespace Gtk;
    using SlotType =
        sigc::slot<void (double, double, guint, Gdk::EventSequence*)>;

    const auto obj = dynamic_cast<GestureClick*> (
        Glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj)
    {
      try
      {
        if (const auto slot = Glib::SignalProxyNormal::data_to_slot (data))
          (*static_cast<SlotType*> (
              slot)) (p0, p1, p2, reinterpret_cast<Gdk::EventSequence*> (p3));
      }
      catch (...)
      {
        Glib::exception_handlers_invoke ();
      }
    }
  }

  const Glib::SignalProxyInfo GestureClick_signal_unpaired_release_info = {
      "unpaired-release",
      (GCallback) &GestureClick_signal_unpaired_release_callback,
      (GCallback) &GestureClick_signal_unpaired_release_callback};

} // namespace

namespace Glib
{

  auto
  wrap (GtkGestureClick* object, const bool take_copy) -> RefPtr<Gtk::GestureClick>
  {
    return Glib::make_refptr_for_instance<Gtk::GestureClick> (
        dynamic_cast<Gtk::GestureClick*> (
            wrap_auto ((GObject*) object, take_copy)));
  }

} // namespace Glib

namespace Gtk
{

  auto
  GestureClick_Class::init () -> const Class&
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
  GestureClick_Class::wrap_new (GObject* object) -> Glib::ObjectBase*
  {
    return new GestureClick ((GtkGestureClick*) object);
  }

  auto
  GestureClick::gobj_copy () -> GtkGestureClick*
  {
    reference ();
    return gobj ();
  }

  GestureClick::GestureClick (const Glib::ConstructParams& construct_params)
    : GestureSingle (construct_params)
  {
  }

  GestureClick::GestureClick (GtkGestureClick* castitem)
    : GestureSingle ((GtkGestureSingle*) castitem)
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

  GestureClick::~GestureClick () noexcept = default;

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
    : ObjectBase (nullptr),
      GestureSingle (Glib::ConstructParams (gestureclick_class_.init ()))
  {
  }

  auto
  GestureClick::create () -> Glib::RefPtr<GestureClick>
  {
    return Glib::make_refptr_for_instance<GestureClick> (new GestureClick ());
  }

  auto
  GestureClick::signal_pressed () -> Glib::SignalProxy<void (int, double, double)>
  {
    return {this, &GestureClick_signal_pressed_info};
  }

  auto
  GestureClick::signal_released () -> Glib::SignalProxy<void (int, double, double)>
  {
    return {this, &GestureClick_signal_released_info};
  }

  auto
  GestureClick::signal_stopped () -> Glib::SignalProxy<void ()>
  {
    return {this, &GestureClick_signal_stopped_info};
  }

  auto
  GestureClick::signal_unpaired_release () -> Glib::SignalProxy<void (double, double, guint, Gdk::EventSequence*)>
  {
    return {this, &GestureClick_signal_unpaired_release_info};
  }

} // namespace Gtk
