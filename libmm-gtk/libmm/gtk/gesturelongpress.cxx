// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/gtk/gesturelongpress.hxx>
#include <libmm/gtk/gesturelongpress_p.hxx>

#include <gtk/gtk.h>

namespace
{

  static auto
  GestureLongPress_signal_pressed_callback (GtkGestureLongPress* self,
                                            gdouble p0,
                                            gdouble p1,
                                            void* data) -> void
  {
    using namespace gtk;
    using SlotType = sigc::slot<void (double, double)>;

    auto obj = dynamic_cast<GestureLongPress*> (
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

  static const glib::SignalProxyInfo GestureLongPress_signal_pressed_info = {
      "pressed",
      (GCallback) &GestureLongPress_signal_pressed_callback,
      (GCallback) &GestureLongPress_signal_pressed_callback};

  static const glib::SignalProxyInfo GestureLongPress_signal_cancelled_info = {
      "cancelled",
      (GCallback) &glib::SignalProxyNormal::slot0_void_callback,
      (GCallback) &glib::SignalProxyNormal::slot0_void_callback};

} // namespace

namespace glib
{

  auto
  wrap (GtkGestureLongPress* object, bool take_copy) -> glib::RefPtr<gtk::GestureLongPress>
  {
    return glib::make_refptr_for_instance<gtk::GestureLongPress> (
        dynamic_cast<gtk::GestureLongPress*> (
            glib::wrap_auto ((GObject*) (object), take_copy)));
  }

} // namespace glib

namespace gtk
{

  auto
  GestureLongPress_Class::init () -> const glib::Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &GestureLongPress_Class::class_init_function;

      register_derived_type (gtk_gesture_long_press_get_type ());
    }

    return *this;
  }

  auto
  GestureLongPress_Class::class_init_function (void* g_class, void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);
  }

  auto
  GestureLongPress_Class::wrap_new (GObject* object) -> glib::ObjectBase*
  {
    return new GestureLongPress ((GtkGestureLongPress*) object);
  }

  auto
  GestureLongPress::gobj_copy () -> GtkGestureLongPress*
  {
    reference ();
    return gobj ();
  }

  GestureLongPress::GestureLongPress (
      const glib::ConstructParams& construct_params)
    : GestureSingle (construct_params)
  {
  }

  GestureLongPress::GestureLongPress (GtkGestureLongPress* castitem)
    : GestureSingle ((GtkGestureSingle*) (castitem))
  {
  }

  GestureLongPress::GestureLongPress (GestureLongPress&& src) noexcept
    : GestureSingle (std::move (src))
  {
  }

  auto
  GestureLongPress::operator= (GestureLongPress&& src) noexcept -> GestureLongPress&
  {
    GestureSingle::operator= (std::move (src));
    return *this;
  }

  GestureLongPress::~GestureLongPress () noexcept {}

  GestureLongPress::CppClassType GestureLongPress::gesturelongpress_class_;

  auto
  GestureLongPress::get_type () -> GType
  {
    return gesturelongpress_class_.init ().get_type ();
  }

  auto
  GestureLongPress::get_base_type () -> GType
  {
    return gtk_gesture_long_press_get_type ();
  }

  GestureLongPress::GestureLongPress ()
    : glib::ObjectBase (nullptr),
      GestureSingle (glib::ConstructParams (gesturelongpress_class_.init ()))
  {
  }

  auto
  GestureLongPress::create () -> glib::RefPtr<GestureLongPress>
  {
    return glib::make_refptr_for_instance<GestureLongPress> (
        new GestureLongPress ());
  }

  auto
  GestureLongPress::set_delay_factor (double delay_factor) -> void
  {
    gtk_gesture_long_press_set_delay_factor (gobj (), delay_factor);
  }

  auto
  GestureLongPress::get_delay_factor () const -> double
  {
    return gtk_gesture_long_press_get_delay_factor (
        const_cast<GtkGestureLongPress*> (gobj ()));
  }

  auto
  GestureLongPress::signal_pressed () -> glib::SignalProxy<void (double, double)>
  {
    return glib::SignalProxy<void (double, double)> (
        this,
        &GestureLongPress_signal_pressed_info);
  }

  auto
  GestureLongPress::signal_cancelled () -> glib::SignalProxy<void ()>
  {
    return glib::SignalProxy<void ()> (this,
                                       &GestureLongPress_signal_cancelled_info);
  }

  auto
  GestureLongPress::property_delay_factor () -> glib::PropertyProxy<double>
  {
    return glib::PropertyProxy<double> (this, "delay-factor");
  }

  auto
  GestureLongPress::property_delay_factor () const -> glib::PropertyProxy_ReadOnly<double>
  {
    return glib::PropertyProxy_ReadOnly<double> (this, "delay-factor");
  }

} // namespace gtk
