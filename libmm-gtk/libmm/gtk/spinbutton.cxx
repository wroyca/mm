// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/gtk/spinbutton.hxx>
#include <libmm/gtk/spinbutton_p.hxx>

#include <gtk/gtk.h>

#include <gtk/gtk.h>
#include <libmm/gtk/adjustment.hxx>

using UpdatePolicy = Gtk::SpinButton::UpdatePolicy;

namespace Gtk
{

  SpinButton::SpinButton (double climb_rate, guint digits)
    : Glib::ObjectBase (nullptr),
      Gtk::Widget (Glib::ConstructParams (spinbutton_class_.init (),
                                          "climb_rate",
                                          climb_rate,
                                          "digits",
                                          digits,
                                          nullptr))
  {
  }

  auto
  SpinButton::unset_adjustment () -> void
  {
    gtk_spin_button_set_adjustment (gobj (), nullptr);
  }

} // namespace Gtk

namespace
{

  static auto
  SpinButton_signal_input_callback (GtkSpinButton* self, double* p0, void* data) -> gint
  {
    using namespace Gtk;
    using SlotType = sigc::slot<int (double&)>;

    auto obj = dynamic_cast<SpinButton*> (
        Glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj)
    {
      try
      {
        if (const auto slot = Glib::SignalProxyNormal::data_to_slot (data))
          return (*static_cast<SlotType*> (slot)) (*(p0));
      }
      catch (...)
      {
        Glib::exception_handlers_invoke ();
      }
    }

    using RType = gint;
    return RType ();
  }

  static auto
  SpinButton_signal_input_notify_callback (GtkSpinButton* self,
                                           double* p0,
                                           void* data) -> gint
  {
    using namespace Gtk;
    using SlotType = sigc::slot<void (double&)>;

    auto obj = dynamic_cast<SpinButton*> (
        Glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj)
    {
      try
      {
        if (const auto slot = Glib::SignalProxyNormal::data_to_slot (data))
          (*static_cast<SlotType*> (slot)) (*(p0));
      }
      catch (...)
      {
        Glib::exception_handlers_invoke ();
      }
    }

    using RType = gint;
    return RType ();
  }

  static const Glib::SignalProxyInfo SpinButton_signal_input_info = {
      "input",
      (GCallback) &SpinButton_signal_input_callback,
      (GCallback) &SpinButton_signal_input_notify_callback};

  static auto
  SpinButton_signal_output_callback (GtkSpinButton* self, void* data) -> gboolean
  {
    using namespace Gtk;
    using SlotType = sigc::slot<bool ()>;

    auto obj = dynamic_cast<SpinButton*> (
        Glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj)
    {
      try
      {
        if (const auto slot = Glib::SignalProxyNormal::data_to_slot (data))
          return static_cast<int> ((*static_cast<SlotType*> (slot)) ());
      }
      catch (...)
      {
        Glib::exception_handlers_invoke ();
      }
    }

    using RType = gboolean;
    return RType ();
  }

  static auto
  SpinButton_signal_output_notify_callback (GtkSpinButton* self, void* data) -> gboolean
  {
    using namespace Gtk;
    using SlotType = sigc::slot<void ()>;

    auto obj = dynamic_cast<SpinButton*> (
        Glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj)
    {
      try
      {
        if (const auto slot = Glib::SignalProxyNormal::data_to_slot (data))
          (*static_cast<SlotType*> (slot)) ();
      }
      catch (...)
      {
        Glib::exception_handlers_invoke ();
      }
    }

    using RType = gboolean;
    return RType ();
  }

  static const Glib::SignalProxyInfo SpinButton_signal_output_info = {
      "output",
      (GCallback) &SpinButton_signal_output_callback,
      (GCallback) &SpinButton_signal_output_notify_callback};

  static const Glib::SignalProxyInfo SpinButton_signal_wrapped_info = {
      "wrapped",
      (GCallback) &Glib::SignalProxyNormal::slot0_void_callback,
      (GCallback) &Glib::SignalProxyNormal::slot0_void_callback};

  static const Glib::SignalProxyInfo SpinButton_signal_value_changed_info = {
      "value_changed",
      (GCallback) &Glib::SignalProxyNormal::slot0_void_callback,
      (GCallback) &Glib::SignalProxyNormal::slot0_void_callback};

} // namespace

auto
Glib::Value<Gtk::SpinType>::value_type () -> GType
{
  return gtk_spin_type_get_type ();
}

auto
Glib::Value<Gtk::SpinButton::UpdatePolicy>::value_type () -> GType
{
  return gtk_spin_button_update_policy_get_type ();
}

namespace Glib
{

  auto
  wrap (GtkSpinButton* object, bool take_copy) -> Gtk::SpinButton*
  {
    return dynamic_cast<Gtk::SpinButton*> (
        Glib::wrap_auto ((GObject*) (object), take_copy));
  }

} // namespace Glib

namespace Gtk
{

  auto
  SpinButton_Class::init () -> const Glib::Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &SpinButton_Class::class_init_function;

      register_derived_type (gtk_spin_button_get_type ());

      Orientable::add_interface (get_type ());
      Editable::add_interface (get_type ());
      CellEditable::add_interface (get_type ());
    }

    return *this;
  }

  auto
  SpinButton_Class::class_init_function (void* g_class, void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);
  }

  auto
  SpinButton_Class::wrap_new (GObject* o) -> Glib::ObjectBase*
  {
    return manage (new SpinButton ((GtkSpinButton*) (o)));
  }

  SpinButton::SpinButton (const Glib::ConstructParams& construct_params)
    : Gtk::Widget (construct_params)
  {
  }

  SpinButton::SpinButton (GtkSpinButton* castitem)
    : Gtk::Widget ((GtkWidget*) (castitem))
  {
  }

  SpinButton::SpinButton (SpinButton&& src) noexcept
    : Gtk::Widget (std::move (src)),
      Orientable (std::move (src)),
      Editable (std::move (src)),
      CellEditable (std::move (src))
  {
  }

  auto
  SpinButton::operator= (SpinButton&& src) noexcept -> SpinButton&
  {
    Gtk::Widget::operator= (std::move (src));
    Orientable::operator= (std::move (src));
    Editable::operator= (std::move (src));
    CellEditable::operator= (std::move (src));
    return *this;
  }

  SpinButton::~SpinButton () noexcept
  {
    destroy_ ();
  }

  SpinButton::CppClassType SpinButton::spinbutton_class_;

  auto
  SpinButton::get_type () -> GType
  {
    return spinbutton_class_.init ().get_type ();
  }

  auto
  SpinButton::get_base_type () -> GType
  {
    return gtk_spin_button_get_type ();
  }

  SpinButton::SpinButton (const Glib::RefPtr<Adjustment>& adjustment,
                          double climb_rate,
                          guint digits)
    : Glib::ObjectBase (nullptr),
      Gtk::Widget (Glib::ConstructParams (spinbutton_class_.init (),
                                          "adjustment",
                                          Glib::unwrap (adjustment),
                                          "climb_rate",
                                          climb_rate,
                                          "digits",
                                          digits,
                                          nullptr))
  {
  }

  auto
  SpinButton::configure (const Glib::RefPtr<Adjustment>& adjustment,
                         double climb_rate,
                         guint digits) -> void
  {
    gtk_spin_button_configure (gobj (),
                               Glib::unwrap (adjustment),
                               climb_rate,
                               digits);
  }

  auto
  SpinButton::set_adjustment (const Glib::RefPtr<Adjustment>& adjustment) -> void
  {
    gtk_spin_button_set_adjustment (gobj (), Glib::unwrap (adjustment));
  }

  auto
  SpinButton::get_adjustment () -> Glib::RefPtr<Adjustment>
  {
    auto retvalue = Glib::wrap (gtk_spin_button_get_adjustment (gobj ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  SpinButton::get_adjustment () const -> Glib::RefPtr<const Adjustment>
  {
    return const_cast<SpinButton*> (this)->get_adjustment ();
  }

  auto
  SpinButton::set_digits (guint digits) -> void
  {
    gtk_spin_button_set_digits (gobj (), digits);
  }

  auto
  SpinButton::get_digits () const -> guint
  {
    return gtk_spin_button_get_digits (const_cast<GtkSpinButton*> (gobj ()));
  }

  auto
  SpinButton::set_increments (double step, double page) -> void
  {
    gtk_spin_button_set_increments (gobj (), step, page);
  }

  auto
  SpinButton::get_increments (double& step, double& page) const -> void
  {
    gtk_spin_button_get_increments (const_cast<GtkSpinButton*> (gobj ()),
                                    &(step),
                                    &(page));
  }

  auto
  SpinButton::set_range (double min, double max) -> void
  {
    gtk_spin_button_set_range (gobj (), min, max);
  }

  auto
  SpinButton::get_range (double& min, double& max) const -> void
  {
    gtk_spin_button_get_range (const_cast<GtkSpinButton*> (gobj ()),
                               &(min),
                               &(max));
  }

  auto
  SpinButton::get_value () const -> double
  {
    return gtk_spin_button_get_value (const_cast<GtkSpinButton*> (gobj ()));
  }

  auto
  SpinButton::get_value_as_int () const -> int
  {
    return gtk_spin_button_get_value_as_int (
        const_cast<GtkSpinButton*> (gobj ()));
  }

  auto
  SpinButton::set_value (double value) -> void
  {
    gtk_spin_button_set_value (gobj (), value);
  }

  auto
  SpinButton::set_update_policy (UpdatePolicy policy) -> void
  {
    gtk_spin_button_set_update_policy (
        gobj (),
        static_cast<GtkSpinButtonUpdatePolicy> (policy));
  }

  auto
  SpinButton::get_update_policy () const -> UpdatePolicy
  {
    return static_cast<UpdatePolicy> (gtk_spin_button_get_update_policy (
        const_cast<GtkSpinButton*> (gobj ())));
  }

  auto
  SpinButton::set_numeric (bool numeric) -> void
  {
    gtk_spin_button_set_numeric (gobj (), static_cast<int> (numeric));
  }

  auto
  SpinButton::get_numeric () const -> bool
  {
    return gtk_spin_button_get_numeric (const_cast<GtkSpinButton*> (gobj ()));
  }

  auto
  SpinButton::spin (SpinType direction, double increment) -> void
  {
    gtk_spin_button_spin (gobj (),
                          static_cast<GtkSpinType> (direction),
                          increment);
  }

  auto
  SpinButton::set_wrap (bool wrap) -> void
  {
    gtk_spin_button_set_wrap (gobj (), static_cast<int> (wrap));
  }

  auto
  SpinButton::get_wrap () const -> bool
  {
    return gtk_spin_button_get_wrap (const_cast<GtkSpinButton*> (gobj ()));
  }

  auto
  SpinButton::set_snap_to_ticks (bool snap_to_ticks) -> void
  {
    gtk_spin_button_set_snap_to_ticks (gobj (),
                                       static_cast<int> (snap_to_ticks));
  }

  auto
  SpinButton::get_snap_to_ticks () const -> bool
  {
    return gtk_spin_button_get_snap_to_ticks (
        const_cast<GtkSpinButton*> (gobj ()));
  }

  auto
  SpinButton::set_climb_rate (double climb_rate) -> void
  {
    gtk_spin_button_set_climb_rate (gobj (), climb_rate);
  }

  auto
  SpinButton::get_climb_rate () const -> double
  {
    return gtk_spin_button_get_climb_rate (
        const_cast<GtkSpinButton*> (gobj ()));
  }

  auto
  SpinButton::update () -> void
  {
    gtk_spin_button_update (gobj ());
  }

  auto
  SpinButton::signal_input () -> Glib::SignalProxy<int (double&)>
  {
    return Glib::SignalProxy<int (double&)> (this,
                                             &SpinButton_signal_input_info);
  }

  auto
  SpinButton::signal_output () -> Glib::SignalProxy<bool ()>
  {
    return Glib::SignalProxy<bool ()> (this, &SpinButton_signal_output_info);
  }

  auto
  SpinButton::signal_wrapped () -> Glib::SignalProxy<void ()>
  {
    return Glib::SignalProxy<void ()> (this, &SpinButton_signal_wrapped_info);
  }

  auto
  SpinButton::signal_value_changed () -> Glib::SignalProxy<void ()>
  {
    return Glib::SignalProxy<void ()> (this,
                                       &SpinButton_signal_value_changed_info);
  }

  static_assert (
      Glib::Traits::ValueCompatibleWithWrapProperty<
          Glib::RefPtr<Adjustment>>::value,
      "Type Glib::RefPtr<Adjustment> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  auto
  SpinButton::property_adjustment () -> Glib::PropertyProxy<Glib::RefPtr<Adjustment>>
  {
    return Glib::PropertyProxy<Glib::RefPtr<Adjustment>> (this, "adjustment");
  }

  auto
  SpinButton::property_adjustment () const -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<Adjustment>>
  {
    return Glib::PropertyProxy_ReadOnly<Glib::RefPtr<Adjustment>> (
        this,
        "adjustment");
  }

  auto
  SpinButton::property_climb_rate () -> Glib::PropertyProxy<double>
  {
    return Glib::PropertyProxy<double> (this, "climb-rate");
  }

  auto
  SpinButton::property_climb_rate () const -> Glib::PropertyProxy_ReadOnly<double>
  {
    return Glib::PropertyProxy_ReadOnly<double> (this, "climb-rate");
  }

  auto
  SpinButton::property_digits () -> Glib::PropertyProxy<guint>
  {
    return Glib::PropertyProxy<guint> (this, "digits");
  }

  auto
  SpinButton::property_digits () const -> Glib::PropertyProxy_ReadOnly<guint>
  {
    return Glib::PropertyProxy_ReadOnly<guint> (this, "digits");
  }

  auto
  SpinButton::property_snap_to_ticks () -> Glib::PropertyProxy<bool>
  {
    return Glib::PropertyProxy<bool> (this, "snap-to-ticks");
  }

  auto
  SpinButton::property_snap_to_ticks () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return Glib::PropertyProxy_ReadOnly<bool> (this, "snap-to-ticks");
  }

  auto
  SpinButton::property_numeric () -> Glib::PropertyProxy<bool>
  {
    return Glib::PropertyProxy<bool> (this, "numeric");
  }

  auto
  SpinButton::property_numeric () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return Glib::PropertyProxy_ReadOnly<bool> (this, "numeric");
  }

  auto
  SpinButton::property_wrap () -> Glib::PropertyProxy<bool>
  {
    return Glib::PropertyProxy<bool> (this, "wrap");
  }

  auto
  SpinButton::property_wrap () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return Glib::PropertyProxy_ReadOnly<bool> (this, "wrap");
  }

  static_assert (
      Glib::Traits::ValueCompatibleWithWrapProperty<UpdatePolicy>::value,
      "Type UpdatePolicy cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  auto
  SpinButton::property_update_policy () -> Glib::PropertyProxy<UpdatePolicy>
  {
    return Glib::PropertyProxy<UpdatePolicy> (this, "update-policy");
  }

  auto
  SpinButton::property_update_policy () const -> Glib::PropertyProxy_ReadOnly<UpdatePolicy>
  {
    return Glib::PropertyProxy_ReadOnly<UpdatePolicy> (this, "update-policy");
  }

  auto
  SpinButton::property_value () -> Glib::PropertyProxy<double>
  {
    return Glib::PropertyProxy<double> (this, "value");
  }

  auto
  SpinButton::property_value () const -> Glib::PropertyProxy_ReadOnly<double>
  {
    return Glib::PropertyProxy_ReadOnly<double> (this, "value");
  }

} // namespace Gtk
