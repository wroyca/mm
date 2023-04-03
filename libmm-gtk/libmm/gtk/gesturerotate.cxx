// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/gtk/gesturerotate.hxx>
#include <libmm/gtk/gesturerotate_p.hxx>

#include <gtk/gtk.h>

namespace
{

  static auto
  GestureRotate_signal_angle_changed_callback (GtkGestureRotate* self,
                                               gdouble p0,
                                               gdouble p1,
                                               void* data) -> void
  {
    using namespace Gtk;
    using SlotType = sigc::slot<void (double, double)>;

    auto obj = dynamic_cast<GestureRotate*> (
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

  static const Glib::SignalProxyInfo GestureRotate_signal_angle_changed_info = {
      "angle-changed",
      (GCallback) &GestureRotate_signal_angle_changed_callback,
      (GCallback) &GestureRotate_signal_angle_changed_callback};

} // namespace

namespace Glib
{

  auto
  wrap (GtkGestureRotate* object, bool take_copy) -> Glib::RefPtr<Gtk::GestureRotate>
  {
    return Glib::make_refptr_for_instance<Gtk::GestureRotate> (
        dynamic_cast<Gtk::GestureRotate*> (
            Glib::wrap_auto ((GObject*) (object), take_copy)));
  }

} // namespace Glib

namespace Gtk
{

  auto
  GestureRotate_Class::init () -> const Glib::Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &GestureRotate_Class::class_init_function;

      register_derived_type (gtk_gesture_rotate_get_type ());
    }

    return *this;
  }

  auto
  GestureRotate_Class::class_init_function (void* g_class, void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);
  }

  auto
  GestureRotate_Class::wrap_new (GObject* object) -> Glib::ObjectBase*
  {
    return new GestureRotate ((GtkGestureRotate*) object);
  }

  auto
  GestureRotate::gobj_copy () -> GtkGestureRotate*
  {
    reference ();
    return gobj ();
  }

  GestureRotate::GestureRotate (const Glib::ConstructParams& construct_params)
    : Gesture (construct_params)
  {
  }

  GestureRotate::GestureRotate (GtkGestureRotate* castitem)
    : Gesture ((GtkGesture*) (castitem))
  {
  }

  GestureRotate::GestureRotate (GestureRotate&& src) noexcept
    : Gesture (std::move (src))
  {
  }

  auto
  GestureRotate::operator= (GestureRotate&& src) noexcept -> GestureRotate&
  {
    Gesture::operator= (std::move (src));
    return *this;
  }

  GestureRotate::~GestureRotate () noexcept {}

  GestureRotate::CppClassType GestureRotate::gesturerotate_class_;

  auto
  GestureRotate::get_type () -> GType
  {
    return gesturerotate_class_.init ().get_type ();
  }

  auto
  GestureRotate::get_base_type () -> GType
  {
    return gtk_gesture_rotate_get_type ();
  }

  GestureRotate::GestureRotate ()
    : Glib::ObjectBase (nullptr),
      Gesture (Glib::ConstructParams (gesturerotate_class_.init ()))
  {
  }

  auto
  GestureRotate::create () -> Glib::RefPtr<GestureRotate>
  {
    return Glib::make_refptr_for_instance<GestureRotate> (new GestureRotate ());
  }

  auto
  GestureRotate::get_angle_delta () const -> double
  {
    return gtk_gesture_rotate_get_angle_delta (
        const_cast<GtkGestureRotate*> (gobj ()));
  }

  auto
  GestureRotate::signal_angle_changed () -> Glib::SignalProxy<void (double, double)>
  {
    return Glib::SignalProxy<void (double, double)> (
        this,
        &GestureRotate_signal_angle_changed_info);
  }

} // namespace Gtk
