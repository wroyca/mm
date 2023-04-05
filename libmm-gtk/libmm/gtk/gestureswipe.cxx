// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/gtk/gestureswipe.hxx>
#include <libmm/gtk/gestureswipe_p.hxx>

#include <gtk/gtk.h>

namespace
{

  static auto
  GestureSwipe_signal_swipe_callback (GtkGestureSwipe* self,
                                      gdouble p0,
                                      gdouble p1,
                                      void* data) -> void
  {
    using namespace gtk;
    using SlotType = sigc::slot<void (double, double)>;

    auto obj = dynamic_cast<GestureSwipe*> (
        glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj)
    {
      try
      {
        if (const auto slot = glib::SignalProxyNormal::data_to_slot (data))
          (*static_cast<SlotType*> (slot)) (p0, p1);
      }
      catch (...)
      {
        glib::exception_handlers_invoke ();
      }
    }
  }

  static const glib::SignalProxyInfo GestureSwipe_signal_swipe_info = {
      "swipe",
      (GCallback) &GestureSwipe_signal_swipe_callback,
      (GCallback) &GestureSwipe_signal_swipe_callback};

} // namespace

namespace glib
{

  auto
  wrap (GtkGestureSwipe* object, bool take_copy) -> glib::RefPtr<gtk::GestureSwipe>
  {
    return glib::make_refptr_for_instance<gtk::GestureSwipe> (
        dynamic_cast<gtk::GestureSwipe*> (
            glib::wrap_auto ((GObject*) (object), take_copy)));
  }

} // namespace glib

namespace gtk
{

  auto
  GestureSwipe_Class::init () -> const glib::Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &GestureSwipe_Class::class_init_function;

      register_derived_type (gtk_gesture_swipe_get_type ());
    }

    return *this;
  }

  auto
  GestureSwipe_Class::class_init_function (void* g_class, void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);
  }

  auto
  GestureSwipe_Class::wrap_new (GObject* object) -> glib::ObjectBase*
  {
    return new GestureSwipe ((GtkGestureSwipe*) object);
  }

  auto
  GestureSwipe::gobj_copy () -> GtkGestureSwipe*
  {
    reference ();
    return gobj ();
  }

  GestureSwipe::GestureSwipe (const glib::ConstructParams& construct_params)
    : GestureSingle (construct_params)
  {
  }

  GestureSwipe::GestureSwipe (GtkGestureSwipe* castitem)
    : GestureSingle ((GtkGestureSingle*) (castitem))
  {
  }

  GestureSwipe::GestureSwipe (GestureSwipe&& src) noexcept
    : GestureSingle (std::move (src))
  {
  }

  auto
  GestureSwipe::operator= (GestureSwipe&& src) noexcept -> GestureSwipe&
  {
    GestureSingle::operator= (std::move (src));
    return *this;
  }

  GestureSwipe::~GestureSwipe () noexcept {}

  GestureSwipe::CppClassType GestureSwipe::gestureswipe_class_;

  auto
  GestureSwipe::get_type () -> GType
  {
    return gestureswipe_class_.init ().get_type ();
  }

  auto
  GestureSwipe::get_base_type () -> GType
  {
    return gtk_gesture_swipe_get_type ();
  }

  GestureSwipe::GestureSwipe ()
    : glib::ObjectBase (nullptr),
      GestureSingle (glib::ConstructParams (gestureswipe_class_.init ()))
  {
  }

  auto
  GestureSwipe::create () -> glib::RefPtr<GestureSwipe>
  {
    return glib::make_refptr_for_instance<GestureSwipe> (new GestureSwipe ());
  }

  auto
  GestureSwipe::get_velocity (double& velocity_x, double& velocity_y) const -> bool
  {
    return gtk_gesture_swipe_get_velocity (
        const_cast<GtkGestureSwipe*> (gobj ()),
        &(velocity_x),
        &(velocity_y));
  }

  auto
  GestureSwipe::signal_swipe () -> glib::SignalProxy<void (double, double)>
  {
    return glib::SignalProxy<void (double, double)> (
        this,
        &GestureSwipe_signal_swipe_info);
  }

} // namespace gtk
