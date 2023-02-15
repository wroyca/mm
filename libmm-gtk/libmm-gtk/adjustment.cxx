// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm-glib/mm-glib.hxx>

#include <libmm-gtk/adjustment.hxx>
#include <libmm-gtk/adjustment_p.hxx>

#include <gtk/gtk.h>

namespace Gtk
{

  Adjustment::Adjustment (double value,
                          double lower,
                          double upper,
                          double step_increment,
                          double page_increment,
                          double page_size)
    : Glib::ObjectBase (nullptr),
      Glib::Object (Glib::ConstructParams (adjustment_class_.init (),
                                           "lower",
                                           lower,
                                           "upper",
                                           upper,
                                           "step_increment",
                                           step_increment,
                                           "page_increment",
                                           page_increment,
                                           "page_size",
                                           page_size,
                                           "value",
                                           value,
                                           nullptr))
  {
    if (gobject_ && g_object_is_floating (gobject_))
      g_object_ref_sink (gobject_);
  }

} // namespace Gtk

namespace
{

  static const Glib::SignalProxyInfo Adjustment_signal_changed_info = {
      "changed",
      (GCallback) &Glib::SignalProxyNormal::slot0_void_callback,
      (GCallback) &Glib::SignalProxyNormal::slot0_void_callback};

  static const Glib::SignalProxyInfo Adjustment_signal_value_changed_info = {
      "value_changed",
      (GCallback) &Glib::SignalProxyNormal::slot0_void_callback,
      (GCallback) &Glib::SignalProxyNormal::slot0_void_callback};

} // namespace

namespace Glib
{

  auto
  wrap (GtkAdjustment* object, bool take_copy) -> Glib::RefPtr<Gtk::Adjustment>
  {
    return Glib::make_refptr_for_instance<Gtk::Adjustment> (
        dynamic_cast<Gtk::Adjustment*> (
            Glib::wrap_auto ((GObject*) (object), take_copy)));
  }

} // namespace Glib

namespace Gtk
{

  auto
  Adjustment_Class::init () -> const Glib::Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &Adjustment_Class::class_init_function;

      register_derived_type (gtk_adjustment_get_type ());
    }

    return *this;
  }

  auto
  Adjustment_Class::class_init_function (void* g_class, void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);

    klass->changed = &changed_callback;
    klass->value_changed = &value_changed_callback;
  }

  auto
  Adjustment_Class::changed_callback (GtkAdjustment* self) -> void
  {
    const auto obj_base = static_cast<Glib::ObjectBase*> (
        Glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj_base && obj_base->is_derived_ ())
    {
      const auto obj = dynamic_cast<CppObjectType* const> (obj_base);
      if (obj)
      {
        try
        {
          obj->on_changed ();
          return;
        }
        catch (...)
        {
          Glib::exception_handlers_invoke ();
        }
      }
    }

    const auto base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (self)));

    if (base && base->changed)
      (*base->changed) (self);
  }

  auto
  Adjustment_Class::value_changed_callback (GtkAdjustment* self) -> void
  {
    const auto obj_base = static_cast<Glib::ObjectBase*> (
        Glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj_base && obj_base->is_derived_ ())
    {
      const auto obj = dynamic_cast<CppObjectType* const> (obj_base);
      if (obj)
      {
        try
        {
          obj->on_value_changed ();
          return;
        }
        catch (...)
        {
          Glib::exception_handlers_invoke ();
        }
      }
    }

    const auto base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (self)));

    if (base && base->value_changed)
      (*base->value_changed) (self);
  }

  auto
  Adjustment_Class::wrap_new (GObject* object) -> Glib::ObjectBase*
  {
    return new Adjustment ((GtkAdjustment*) object);
  }

  auto
  Adjustment::gobj_copy () -> GtkAdjustment*
  {
    reference ();
    return gobj ();
  }

  Adjustment::Adjustment (const Glib::ConstructParams& construct_params)
    : Glib::Object (construct_params)
  {
    if (gobject_ && g_object_is_floating (gobject_))
      g_object_ref_sink (gobject_);
  }

  Adjustment::Adjustment (GtkAdjustment* castitem)
    : Glib::Object ((GObject*) (castitem))
  {
  }

  Adjustment::Adjustment (Adjustment&& src) noexcept
    : Glib::Object (std::move (src))
  {
  }

  auto
  Adjustment::operator= (Adjustment&& src) noexcept -> Adjustment&
  {
    Glib::Object::operator= (std::move (src));
    return *this;
  }

  Adjustment::~Adjustment () noexcept {}

  Adjustment::CppClassType Adjustment::adjustment_class_;

  auto
  Adjustment::get_type () -> GType
  {
    return adjustment_class_.init ().get_type ();
  }

  auto
  Adjustment::get_base_type () -> GType
  {
    return gtk_adjustment_get_type ();
  }

  auto
  Adjustment::create (double value,
                      double lower,
                      double upper,
                      double step_increment,
                      double page_increment,
                      double page_size) -> Glib::RefPtr<Adjustment>
  {
    return Glib::make_refptr_for_instance<Adjustment> (
        new Adjustment (value,
                        lower,
                        upper,
                        step_increment,
                        page_increment,
                        page_size));
  }

  auto
  Adjustment::clamp_page (double lower, double upper) -> void
  {
    gtk_adjustment_clamp_page (gobj (), lower, upper);
  }

  auto
  Adjustment::set_value (double value) -> void
  {
    gtk_adjustment_set_value (gobj (), value);
  }

  auto
  Adjustment::get_value () const -> double
  {
    return gtk_adjustment_get_value (const_cast<GtkAdjustment*> (gobj ()));
  }

  auto
  Adjustment::set_lower (double lower) -> void
  {
    gtk_adjustment_set_lower (gobj (), lower);
  }

  auto
  Adjustment::get_lower () const -> double
  {
    return gtk_adjustment_get_lower (const_cast<GtkAdjustment*> (gobj ()));
  }

  auto
  Adjustment::set_upper (double upper) -> void
  {
    gtk_adjustment_set_upper (gobj (), upper);
  }

  auto
  Adjustment::get_upper () const -> double
  {
    return gtk_adjustment_get_upper (const_cast<GtkAdjustment*> (gobj ()));
  }

  auto
  Adjustment::set_step_increment (double step_increment) -> void
  {
    gtk_adjustment_set_step_increment (gobj (), step_increment);
  }

  auto
  Adjustment::get_step_increment () const -> double
  {
    return gtk_adjustment_get_step_increment (
        const_cast<GtkAdjustment*> (gobj ()));
  }

  auto
  Adjustment::set_page_increment (double page_increment) -> void
  {
    gtk_adjustment_set_page_increment (gobj (), page_increment);
  }

  auto
  Adjustment::get_page_increment () const -> double
  {
    return gtk_adjustment_get_page_increment (
        const_cast<GtkAdjustment*> (gobj ()));
  }

  auto
  Adjustment::set_page_size (double page_size) -> void
  {
    gtk_adjustment_set_page_size (gobj (), page_size);
  }

  auto
  Adjustment::get_page_size () const -> double
  {
    return gtk_adjustment_get_page_size (const_cast<GtkAdjustment*> (gobj ()));
  }

  auto
  Adjustment::configure (double value,
                         double lower,
                         double upper,
                         double step_increment,
                         double page_increment,
                         double page_size) -> void
  {
    gtk_adjustment_configure (gobj (),
                              value,
                              lower,
                              upper,
                              step_increment,
                              page_increment,
                              page_size);
  }

  auto
  Adjustment::get_minimum_increment () const -> double
  {
    return gtk_adjustment_get_minimum_increment (
        const_cast<GtkAdjustment*> (gobj ()));
  }

  auto
  Adjustment::signal_changed () -> Glib::SignalProxy<void ()>
  {
    return Glib::SignalProxy<void ()> (this, &Adjustment_signal_changed_info);
  }

  auto
  Adjustment::signal_value_changed () -> Glib::SignalProxy<void ()>
  {
    return Glib::SignalProxy<void ()> (this,
                                       &Adjustment_signal_value_changed_info);
  }

  auto
  Adjustment::property_value () -> Glib::PropertyProxy<double>
  {
    return Glib::PropertyProxy<double> (this, "value");
  }

  auto
  Adjustment::property_value () const -> Glib::PropertyProxy_ReadOnly<double>
  {
    return Glib::PropertyProxy_ReadOnly<double> (this, "value");
  }

  auto
  Adjustment::property_lower () -> Glib::PropertyProxy<double>
  {
    return Glib::PropertyProxy<double> (this, "lower");
  }

  auto
  Adjustment::property_lower () const -> Glib::PropertyProxy_ReadOnly<double>
  {
    return Glib::PropertyProxy_ReadOnly<double> (this, "lower");
  }

  auto
  Adjustment::property_upper () -> Glib::PropertyProxy<double>
  {
    return Glib::PropertyProxy<double> (this, "upper");
  }

  auto
  Adjustment::property_upper () const -> Glib::PropertyProxy_ReadOnly<double>
  {
    return Glib::PropertyProxy_ReadOnly<double> (this, "upper");
  }

  auto
  Adjustment::property_step_increment () -> Glib::PropertyProxy<double>
  {
    return Glib::PropertyProxy<double> (this, "step-increment");
  }

  auto
  Adjustment::property_step_increment () const -> Glib::PropertyProxy_ReadOnly<double>
  {
    return Glib::PropertyProxy_ReadOnly<double> (this, "step-increment");
  }

  auto
  Adjustment::property_page_increment () -> Glib::PropertyProxy<double>
  {
    return Glib::PropertyProxy<double> (this, "page-increment");
  }

  auto
  Adjustment::property_page_increment () const -> Glib::PropertyProxy_ReadOnly<double>
  {
    return Glib::PropertyProxy_ReadOnly<double> (this, "page-increment");
  }

  auto
  Adjustment::property_page_size () -> Glib::PropertyProxy<double>
  {
    return Glib::PropertyProxy<double> (this, "page-size");
  }

  auto
  Adjustment::property_page_size () const -> Glib::PropertyProxy_ReadOnly<double>
  {
    return Glib::PropertyProxy_ReadOnly<double> (this, "page-size");
  }

  auto
  Gtk::Adjustment::on_changed () -> void
  {
    const auto base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (gobject_)));

    if (base && base->changed)
      (*base->changed) (gobj ());
  }

  auto
  Gtk::Adjustment::on_value_changed () -> void
  {
    const auto base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (gobject_)));

    if (base && base->value_changed)
      (*base->value_changed) (gobj ());
  }

} // namespace Gtk
