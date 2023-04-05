// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/gtk/gesturezoom.hxx>
#include <libmm/gtk/gesturezoom_p.hxx>

#include <gtk/gtk.h>

namespace
{

  static auto
  GestureZoom_signal_scale_changed_callback (GtkGestureZoom* self,
                                             gdouble p0,
                                             void* data) -> void
  {
    using namespace gtk;
    using SlotType = sigc::slot<void (double)>;

    auto obj = dynamic_cast<GestureZoom*> (
        glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj)
    {
      try
      {
        if (const auto slot = glib::SignalProxyNormal::data_to_slot (data))
          (*static_cast<SlotType*> (slot)) (p0);
      }
      catch (...)
      {
        glib::exception_handlers_invoke ();
      }
    }
  }

  static const glib::SignalProxyInfo GestureZoom_signal_scale_changed_info = {
      "scale-changed",
      (GCallback) &GestureZoom_signal_scale_changed_callback,
      (GCallback) &GestureZoom_signal_scale_changed_callback};

} // namespace

namespace glib
{

  auto
  wrap (GtkGestureZoom* object, bool take_copy) -> glib::RefPtr<gtk::GestureZoom>
  {
    return glib::make_refptr_for_instance<gtk::GestureZoom> (
        dynamic_cast<gtk::GestureZoom*> (
            glib::wrap_auto ((GObject*) (object), take_copy)));
  }

} // namespace glib

namespace gtk
{

  auto
  GestureZoom_Class::init () -> const glib::Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &GestureZoom_Class::class_init_function;

      register_derived_type (gtk_gesture_zoom_get_type ());
    }

    return *this;
  }

  auto
  GestureZoom_Class::class_init_function (void* g_class, void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);
  }

  auto
  GestureZoom_Class::wrap_new (GObject* object) -> glib::ObjectBase*
  {
    return new GestureZoom ((GtkGestureZoom*) object);
  }

  auto
  GestureZoom::gobj_copy () -> GtkGestureZoom*
  {
    reference ();
    return gobj ();
  }

  GestureZoom::GestureZoom (const glib::ConstructParams& construct_params)
    : Gesture (construct_params)
  {
  }

  GestureZoom::GestureZoom (GtkGestureZoom* castitem)
    : Gesture ((GtkGesture*) (castitem))
  {
  }

  GestureZoom::GestureZoom (GestureZoom&& src) noexcept
    : Gesture (std::move (src))
  {
  }

  auto
  GestureZoom::operator= (GestureZoom&& src) noexcept -> GestureZoom&
  {
    Gesture::operator= (std::move (src));
    return *this;
  }

  GestureZoom::~GestureZoom () noexcept {}

  GestureZoom::CppClassType GestureZoom::gesturezoom_class_;

  auto
  GestureZoom::get_type () -> GType
  {
    return gesturezoom_class_.init ().get_type ();
  }

  auto
  GestureZoom::get_base_type () -> GType
  {
    return gtk_gesture_zoom_get_type ();
  }

  GestureZoom::GestureZoom ()
    : glib::ObjectBase (nullptr),
      Gesture (glib::ConstructParams (gesturezoom_class_.init ()))
  {
  }

  auto
  GestureZoom::create () -> glib::RefPtr<GestureZoom>
  {
    return glib::make_refptr_for_instance<GestureZoom> (new GestureZoom ());
  }

  auto
  GestureZoom::get_scale_delta () const -> double
  {
    return gtk_gesture_zoom_get_scale_delta (
        const_cast<GtkGestureZoom*> (gobj ()));
  }

  auto
  GestureZoom::signal_scale_changed () -> glib::SignalProxy<void (double)>
  {
    return glib::SignalProxy<void (double)> (
        this,
        &GestureZoom_signal_scale_changed_info);
  }

} // namespace gtk
