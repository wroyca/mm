// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm-glib/mm-glib.hxx>

#include <libmm-gtk/gesturelongpress.hxx>
#include <libmm-gtk/gesturelongpress_p.hxx>

#include <gtk/gtk.h>

namespace
{

  static auto
  GestureLongPress_signal_pressed_callback (GtkGestureLongPress* self,
                                            gdouble p0,
                                            gdouble p1,
                                            void* data) -> void
  {
    using namespace Gtk;
    using SlotType = sigc::slot<void (double, double)>;

    auto obj = dynamic_cast<GestureLongPress*> (
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

  static const Glib::SignalProxyInfo GestureLongPress_signal_pressed_info = {
      "pressed",
      (GCallback) &GestureLongPress_signal_pressed_callback,
      (GCallback) &GestureLongPress_signal_pressed_callback};

  static const Glib::SignalProxyInfo GestureLongPress_signal_cancelled_info = {
      "cancelled",
      (GCallback) &Glib::SignalProxyNormal::slot0_void_callback,
      (GCallback) &Glib::SignalProxyNormal::slot0_void_callback};

} // namespace

namespace Glib
{

  auto
  wrap (GtkGestureLongPress* object, bool take_copy) -> Glib::RefPtr<Gtk::GestureLongPress>
  {
    return Glib::make_refptr_for_instance<Gtk::GestureLongPress> (
        dynamic_cast<Gtk::GestureLongPress*> (
            Glib::wrap_auto ((GObject*) (object), take_copy)));
  }

} // namespace Glib

namespace Gtk
{

  auto
  GestureLongPress_Class::init () -> const Glib::Class&
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
  GestureLongPress_Class::wrap_new (GObject* object) -> Glib::ObjectBase*
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
      const Glib::ConstructParams& construct_params)
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
    : Glib::ObjectBase (nullptr),
      GestureSingle (Glib::ConstructParams (gesturelongpress_class_.init ()))
  {
  }

  auto
  GestureLongPress::create () -> Glib::RefPtr<GestureLongPress>
  {
    return Glib::make_refptr_for_instance<GestureLongPress> (
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
  GestureLongPress::signal_pressed () -> Glib::SignalProxy<void (double, double)>
  {
    return Glib::SignalProxy<void (double, double)> (
        this,
        &GestureLongPress_signal_pressed_info);
  }

  auto
  GestureLongPress::signal_cancelled () -> Glib::SignalProxy<void ()>
  {
    return Glib::SignalProxy<void ()> (this,
                                       &GestureLongPress_signal_cancelled_info);
  }

  auto
  GestureLongPress::property_delay_factor () -> Glib::PropertyProxy<double>
  {
    return Glib::PropertyProxy<double> (this, "delay-factor");
  }

  auto
  GestureLongPress::property_delay_factor () const -> Glib::PropertyProxy_ReadOnly<double>
  {
    return Glib::PropertyProxy_ReadOnly<double> (this, "delay-factor");
  }

} // namespace Gtk
