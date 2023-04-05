// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/gtk/spinbutton.hxx>
#include <libmm/gtk/spinbutton_p.hxx>

#include <gtk/gtk.h>

#include <gtk/gtk.h>
#include <libmm/gtk/adjustment.hxx>

using UpdatePolicy = gtk::SpinButton::UpdatePolicy;

namespace gtk
{

  SpinButton::SpinButton (double climb_rate, guint digits)
    : glib::ObjectBase (nullptr),
      gtk::Widget (glib::ConstructParams (spinbutton_class_.init (),
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

} // namespace gtk

namespace
{

  static auto
  SpinButton_signal_input_callback (GtkSpinButton* self, double* p0, void* data) -> gint
  {
    using namespace gtk;
    using SlotType = sigc::slot<int (double&)>;

    auto obj = dynamic_cast<SpinButton*> (
        glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj)
    {
      try
      {
        if (const auto slot = glib::SignalProxyNormal::data_to_slot (data))
          return (*static_cast<SlotType*> (slot)) (*(p0));
      }
      catch (...)
      {
        glib::exception_handlers_invoke ();
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
    using namespace gtk;
    using SlotType = sigc::slot<void (double&)>;

    auto obj = dynamic_cast<SpinButton*> (
        glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj)
    {
      try
      {
        if (const auto slot = glib::SignalProxyNormal::data_to_slot (data))
          (*static_cast<SlotType*> (slot)) (*(p0));
      }
      catch (...)
      {
        glib::exception_handlers_invoke ();
      }
    }

    using RType = gint;
    return RType ();
  }

  static const glib::SignalProxyInfo SpinButton_signal_input_info = {
      "input",
      (GCallback) &SpinButton_signal_input_callback,
      (GCallback) &SpinButton_signal_input_notify_callback};

  static auto
  SpinButton_signal_output_callback (GtkSpinButton* self, void* data) -> gboolean
  {
    using namespace gtk;
    using SlotType = sigc::slot<bool ()>;

    auto obj = dynamic_cast<SpinButton*> (
        glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj)
    {
      try
      {
        if (const auto slot = glib::SignalProxyNormal::data_to_slot (data))
          return static_cast<int> ((*static_cast<SlotType*> (slot)) ());
      }
      catch (...)
      {
        glib::exception_handlers_invoke ();
      }
    }

    using RType = gboolean;
    return RType ();
  }

  static auto
  SpinButton_signal_output_notify_callback (GtkSpinButton* self, void* data) -> gboolean
  {
    using namespace gtk;
    using SlotType = sigc::slot<void ()>;

    auto obj = dynamic_cast<SpinButton*> (
        glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj)
    {
      try
      {
        if (const auto slot = glib::SignalProxyNormal::data_to_slot (data))
          (*static_cast<SlotType*> (slot)) ();
      }
      catch (...)
      {
        glib::exception_handlers_invoke ();
      }
    }

    using RType = gboolean;
    return RType ();
  }

  static const glib::SignalProxyInfo SpinButton_signal_output_info = {
      "output",
      (GCallback) &SpinButton_signal_output_callback,
      (GCallback) &SpinButton_signal_output_notify_callback};

  static const glib::SignalProxyInfo SpinButton_signal_wrapped_info = {
      "wrapped",
      (GCallback) &glib::SignalProxyNormal::slot0_void_callback,
      (GCallback) &glib::SignalProxyNormal::slot0_void_callback};

  static const glib::SignalProxyInfo SpinButton_signal_value_changed_info = {
      "value_changed",
      (GCallback) &glib::SignalProxyNormal::slot0_void_callback,
      (GCallback) &glib::SignalProxyNormal::slot0_void_callback};

} // namespace

auto
glib::Value<gtk::SpinType>::value_type () -> GType
{
  return gtk_spin_type_get_type ();
}

auto
glib::Value<gtk::SpinButton::UpdatePolicy>::value_type () -> GType
{
  return gtk_spin_button_update_policy_get_type ();
}

namespace glib
{

  auto
  wrap (GtkSpinButton* object, bool take_copy) -> gtk::SpinButton*
  {
    return dynamic_cast<gtk::SpinButton*> (
        glib::wrap_auto ((GObject*) (object), take_copy));
  }

} // namespace glib

namespace gtk
{

  auto
  SpinButton_Class::init () -> const glib::Class&
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
  SpinButton_Class::wrap_new (GObject* o) -> glib::ObjectBase*
  {
    return manage (new SpinButton ((GtkSpinButton*) (o)));
  }

  SpinButton::SpinButton (const glib::ConstructParams& construct_params)
    : gtk::Widget (construct_params)
  {
  }

  SpinButton::SpinButton (GtkSpinButton* castitem)
    : gtk::Widget ((GtkWidget*) (castitem))
  {
  }

  SpinButton::SpinButton (SpinButton&& src) noexcept
    : gtk::Widget (std::move (src)),
      Orientable (std::move (src)),
      Editable (std::move (src)),
      CellEditable (std::move (src))
  {
  }

  auto
  SpinButton::operator= (SpinButton&& src) noexcept -> SpinButton&
  {
    gtk::Widget::operator= (std::move (src));
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

  SpinButton::SpinButton (const glib::RefPtr<Adjustment>& adjustment,
                          double climb_rate,
                          guint digits)
    : glib::ObjectBase (nullptr),
      gtk::Widget (glib::ConstructParams (spinbutton_class_.init (),
                                          "adjustment",
                                          glib::unwrap (adjustment),
                                          "climb_rate",
                                          climb_rate,
                                          "digits",
                                          digits,
                                          nullptr))
  {
  }

  auto
  SpinButton::configure (const glib::RefPtr<Adjustment>& adjustment,
                         double climb_rate,
                         guint digits) -> void
  {
    gtk_spin_button_configure (gobj (),
                               glib::unwrap (adjustment),
                               climb_rate,
                               digits);
  }

  auto
  SpinButton::set_adjustment (const glib::RefPtr<Adjustment>& adjustment) -> void
  {
    gtk_spin_button_set_adjustment (gobj (), glib::unwrap (adjustment));
  }

  auto
  SpinButton::get_adjustment () -> glib::RefPtr<Adjustment>
  {
    auto retvalue = glib::wrap (gtk_spin_button_get_adjustment (gobj ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  SpinButton::get_adjustment () const -> glib::RefPtr<const Adjustment>
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
  SpinButton::signal_input () -> glib::SignalProxy<int (double&)>
  {
    return glib::SignalProxy<int (double&)> (this,
                                             &SpinButton_signal_input_info);
  }

  auto
  SpinButton::signal_output () -> glib::SignalProxy<bool ()>
  {
    return glib::SignalProxy<bool ()> (this, &SpinButton_signal_output_info);
  }

  auto
  SpinButton::signal_wrapped () -> glib::SignalProxy<void ()>
  {
    return glib::SignalProxy<void ()> (this, &SpinButton_signal_wrapped_info);
  }

  auto
  SpinButton::signal_value_changed () -> glib::SignalProxy<void ()>
  {
    return glib::SignalProxy<void ()> (this,
                                       &SpinButton_signal_value_changed_info);
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<
          glib::RefPtr<Adjustment>>::value,
      "Type glib::RefPtr<Adjustment> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  SpinButton::property_adjustment () -> glib::PropertyProxy<glib::RefPtr<Adjustment>>
  {
    return glib::PropertyProxy<glib::RefPtr<Adjustment>> (this, "adjustment");
  }

  auto
  SpinButton::property_adjustment () const -> glib::PropertyProxy_ReadOnly<glib::RefPtr<Adjustment>>
  {
    return glib::PropertyProxy_ReadOnly<glib::RefPtr<Adjustment>> (
        this,
        "adjustment");
  }

  auto
  SpinButton::property_climb_rate () -> glib::PropertyProxy<double>
  {
    return glib::PropertyProxy<double> (this, "climb-rate");
  }

  auto
  SpinButton::property_climb_rate () const -> glib::PropertyProxy_ReadOnly<double>
  {
    return glib::PropertyProxy_ReadOnly<double> (this, "climb-rate");
  }

  auto
  SpinButton::property_digits () -> glib::PropertyProxy<guint>
  {
    return glib::PropertyProxy<guint> (this, "digits");
  }

  auto
  SpinButton::property_digits () const -> glib::PropertyProxy_ReadOnly<guint>
  {
    return glib::PropertyProxy_ReadOnly<guint> (this, "digits");
  }

  auto
  SpinButton::property_snap_to_ticks () -> glib::PropertyProxy<bool>
  {
    return glib::PropertyProxy<bool> (this, "snap-to-ticks");
  }

  auto
  SpinButton::property_snap_to_ticks () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "snap-to-ticks");
  }

  auto
  SpinButton::property_numeric () -> glib::PropertyProxy<bool>
  {
    return glib::PropertyProxy<bool> (this, "numeric");
  }

  auto
  SpinButton::property_numeric () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "numeric");
  }

  auto
  SpinButton::property_wrap () -> glib::PropertyProxy<bool>
  {
    return glib::PropertyProxy<bool> (this, "wrap");
  }

  auto
  SpinButton::property_wrap () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "wrap");
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<UpdatePolicy>::value,
      "Type UpdatePolicy cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  SpinButton::property_update_policy () -> glib::PropertyProxy<UpdatePolicy>
  {
    return glib::PropertyProxy<UpdatePolicy> (this, "update-policy");
  }

  auto
  SpinButton::property_update_policy () const -> glib::PropertyProxy_ReadOnly<UpdatePolicy>
  {
    return glib::PropertyProxy_ReadOnly<UpdatePolicy> (this, "update-policy");
  }

  auto
  SpinButton::property_value () -> glib::PropertyProxy<double>
  {
    return glib::PropertyProxy<double> (this, "value");
  }

  auto
  SpinButton::property_value () const -> glib::PropertyProxy_ReadOnly<double>
  {
    return glib::PropertyProxy_ReadOnly<double> (this, "value");
  }

} // namespace gtk
