

#include <libmm-glib/mm-glib.hxx>

#include <libmm-gtk/gestureswipe.hxx>
#include <libmm-gtk/gestureswipe_p.hxx>

#include <gtk/gtk.h>

namespace
{

  auto
  GestureSwipe_signal_swipe_callback (GtkGestureSwipe* self,
                                      const gdouble p0,
                                      const gdouble p1,
                                      void* data) -> void
  {
    using namespace Gtk;
    using SlotType = sigc::slot<void (double, double)>;

    const auto obj = dynamic_cast<GestureSwipe*> (
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

  const Glib::SignalProxyInfo GestureSwipe_signal_swipe_info = {
      "swipe",
      (GCallback) &GestureSwipe_signal_swipe_callback,
      (GCallback) &GestureSwipe_signal_swipe_callback};

} // namespace

namespace Glib
{

  auto
  wrap (GtkGestureSwipe* object, const bool take_copy) -> RefPtr<Gtk::GestureSwipe>
  {
    return Glib::make_refptr_for_instance<Gtk::GestureSwipe> (
        dynamic_cast<Gtk::GestureSwipe*> (
            wrap_auto ((GObject*) object, take_copy)));
  }

} // namespace Glib

namespace Gtk
{

  auto
  GestureSwipe_Class::init () -> const Class&
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
  GestureSwipe_Class::wrap_new (GObject* object) -> Glib::ObjectBase*
  {
    return new GestureSwipe ((GtkGestureSwipe*) object);
  }

  auto
  GestureSwipe::gobj_copy () -> GtkGestureSwipe*
  {
    reference ();
    return gobj ();
  }

  GestureSwipe::GestureSwipe (const Glib::ConstructParams& construct_params)
    : GestureSingle (construct_params)
  {
  }

  GestureSwipe::GestureSwipe (GtkGestureSwipe* castitem)
    : GestureSingle ((GtkGestureSingle*) castitem)
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

  GestureSwipe::~GestureSwipe () noexcept = default;

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
    : ObjectBase (nullptr),
      GestureSingle (Glib::ConstructParams (gestureswipe_class_.init ()))
  {
  }

  auto
  GestureSwipe::create () -> Glib::RefPtr<GestureSwipe>
  {
    return Glib::make_refptr_for_instance<GestureSwipe> (new GestureSwipe ());
  }

  auto
  GestureSwipe::get_velocity (double& velocity_x, double& velocity_y) const -> bool
  {
    return gtk_gesture_swipe_get_velocity (
        const_cast<GtkGestureSwipe*> (gobj ()),
        &velocity_x,
        &velocity_y);
  }

  auto
  GestureSwipe::signal_swipe () -> Glib::SignalProxy<void (double, double)>
  {
    return {this, &GestureSwipe_signal_swipe_info};
  }

} // namespace Gtk
