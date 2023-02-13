


#include <libmm-glib/mm-glib.hpp>

#include <libmm-gtk/spinbutton.hpp>
#include <libmm-gtk/spinbutton_p.hpp>

#include <gtk/gtk.h>

/* Copyright 1998-2002 The gtkmm Development Team
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 */

#include <libmm-gtk/adjustment.hpp>
#include <gtk/gtk.h>

using UpdatePolicy = Gtk::SpinButton::UpdatePolicy;

namespace Gtk
{

SpinButton::SpinButton(const double climb_rate, const guint digits)
:
  // Mark this class as non-derived to allow C++ vfuncs to be skipped.
ObjectBase(nullptr),
Widget(Glib::ConstructParams(spinbutton_class_.init(), "climb_rate",climb_rate,"digits",digits, nullptr))
{}

auto SpinButton::unset_adjustment () -> void
{
  gtk_spin_button_set_adjustment(gobj(), nullptr);
}

} // namespace Gtk


namespace
{


auto SpinButton_signal_input_callback(GtkSpinButton* self, double* p0,void* data) -> gint
{
  using namespace Gtk;
  using SlotType = sigc::slot<int(double&)>;

  const auto obj = dynamic_cast<SpinButton*>(Glib::ObjectBase::_get_current_wrapper((GObject*) self));
  // Do not try to call a signal on a disassociated wrapper.
  if(obj)
  {
    try
    {
      if(const auto slot = Glib::SignalProxyNormal::data_to_slot(data))
        return (*static_cast<SlotType*>(slot))(*p0
);
    }
    catch(...)
    {
       Glib::exception_handlers_invoke();
    }
  }

  using RType = gint;
  return RType();
}

auto SpinButton_signal_input_notify_callback(GtkSpinButton* self, double* p0, void* data) -> gint
{
  using namespace Gtk;
  using SlotType = sigc::slot<void(double&)>;

  const auto obj = dynamic_cast<SpinButton*>(Glib::ObjectBase::_get_current_wrapper((GObject*) self));
  // Do not try to call a signal on a disassociated wrapper.
  if(obj)
  {
    try
    {
      if(const auto slot = Glib::SignalProxyNormal::data_to_slot(data))
        (*static_cast<SlotType*>(slot))(*p0
);
    }
    catch(...)
    {
      Glib::exception_handlers_invoke();
    }
  }

  using RType = gint;
  return RType();
}

const Glib::SignalProxyInfo SpinButton_signal_input_info =
{
  "input",
  (GCallback) &SpinButton_signal_input_callback,
  (GCallback) &SpinButton_signal_input_notify_callback
};


auto SpinButton_signal_output_callback(GtkSpinButton* self, void* data) -> gboolean
{
  using namespace Gtk;
  using SlotType = sigc::slot<bool()>;

  const auto obj = dynamic_cast<SpinButton*>(Glib::ObjectBase::_get_current_wrapper((GObject*) self));
  // Do not try to call a signal on a disassociated wrapper.
  if(obj)
  {
    try
    {
      if(const auto slot = Glib::SignalProxyNormal::data_to_slot(data))
        return (*static_cast<SlotType*>(slot))();
    }
    catch(...)
    {
       Glib::exception_handlers_invoke();
    }
  }

  using RType = gboolean;
  return RType();
}

auto SpinButton_signal_output_notify_callback(GtkSpinButton* self,  void* data) -> gboolean
{
  using namespace Gtk;
  using SlotType = sigc::slot<void()>;

  const auto obj = dynamic_cast<SpinButton*>(Glib::ObjectBase::_get_current_wrapper((GObject*) self));
  // Do not try to call a signal on a disassociated wrapper.
  if(obj)
  {
    try
    {
      if(const auto slot = Glib::SignalProxyNormal::data_to_slot(data))
        (*static_cast<SlotType*>(slot))();
    }
    catch(...)
    {
      Glib::exception_handlers_invoke();
    }
  }

  using RType = gboolean;
  return RType();
}

const Glib::SignalProxyInfo SpinButton_signal_output_info =
{
  "output",
  (GCallback) &SpinButton_signal_output_callback,
  (GCallback) &SpinButton_signal_output_notify_callback
};


const Glib::SignalProxyInfo SpinButton_signal_wrapped_info =
{
  "wrapped",
  (GCallback) &Glib::SignalProxyNormal::slot0_void_callback,
  (GCallback) &Glib::SignalProxyNormal::slot0_void_callback
};


const Glib::SignalProxyInfo SpinButton_signal_value_changed_info =
{
  "value_changed",
  (GCallback) &Glib::SignalProxyNormal::slot0_void_callback,
  (GCallback) &Glib::SignalProxyNormal::slot0_void_callback
};


} // anonymous namespace

// static
auto Glib::Value<Gtk::SpinType>::value_type() -> GType
{
  return gtk_spin_type_get_type();
}

// static
auto Glib::Value<Gtk::SpinButton::UpdatePolicy>::value_type() -> GType
{
  return gtk_spin_button_update_policy_get_type();
}


namespace Glib
{

auto wrap(GtkSpinButton* object, const bool take_copy) -> Gtk::SpinButton*
{
  return dynamic_cast<Gtk::SpinButton *> (wrap_auto((GObject*)object, take_copy));
}

} /* namespace Glib */

namespace Gtk
{


/* The *_Class implementation: */

auto SpinButton_Class::init() -> const Class&
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Class has to know the class init function to clone custom types.
    class_init_func_ = &SpinButton_Class::class_init_function;

    // This is actually just optimized away, apparently with no harm.
    // Make sure that the parent type has been created.
    //CppClassParent::CppObjectType::get_type();

    // Create the wrapper type, with the same class/instance size as the base type.
    register_derived_type(gtk_spin_button_get_type());

    // Add derived versions of interfaces, if the C type implements any interfaces:
  Orientable::add_interface(get_type());
  Editable::add_interface(get_type());
  CellEditable::add_interface(get_type());

  }

  return *this;
}


auto SpinButton_Class::class_init_function (void *g_class, void *class_data) -> void
{
  const auto klass = static_cast<BaseClassType*>(g_class);
  CppClassParent::class_init_function(klass, class_data);


}


auto SpinButton_Class::wrap_new(GObject* o) -> Glib::ObjectBase*
{
  return manage(new SpinButton((GtkSpinButton*)o));

}


/* The implementation: */

SpinButton::SpinButton(const Glib::ConstructParams& construct_params)
: Widget(construct_params)
{
  }

SpinButton::SpinButton(GtkSpinButton* castitem)
: Widget((GtkWidget*)castitem)
{
  }


SpinButton::SpinButton(SpinButton&& src) noexcept
: Widget(std::move(src))
  , Orientable(std::move(src))
  , Editable(std::move(src))
  , CellEditable(std::move(src))
{}

auto SpinButton::operator=(SpinButton&& src) noexcept -> SpinButton&
{
  Widget::operator=(std::move(src));
  Orientable::operator=(std::move(src));
  Editable::operator=(std::move(src));
  CellEditable::operator=(std::move(src));
  return *this;
}

SpinButton::~SpinButton() noexcept
{
  destroy_();
}

SpinButton::CppClassType SpinButton::spinbutton_class_; // initialize static member

auto SpinButton::get_type() -> GType
{
  return spinbutton_class_.init().get_type();
}


auto SpinButton::get_base_type() -> GType
{
  return gtk_spin_button_get_type();
}


SpinButton::SpinButton(const Glib::RefPtr<Adjustment>& adjustment, const double climb_rate, const guint digits)
:
  // Mark this class as non-derived to allow C++ vfuncs to be skipped.
ObjectBase(nullptr),
Widget(Glib::ConstructParams(spinbutton_class_.init(), "adjustment", Glib::unwrap(adjustment), "climb_rate", climb_rate, "digits", digits, nullptr))
{


}

auto SpinButton::configure (
  const Glib::RefPtr <Adjustment> &adjustment, const double climb_rate, const guint digits) -> void
{
  gtk_spin_button_configure(gobj(), Glib::unwrap(adjustment), climb_rate, digits);
}

auto SpinButton::set_adjustment (const Glib::RefPtr <Adjustment> &adjustment) -> void
{
  gtk_spin_button_set_adjustment(gobj(), Glib::unwrap(adjustment));
}

auto SpinButton::get_adjustment() -> Glib::RefPtr<Adjustment>
{
  auto retvalue = Glib::wrap(gtk_spin_button_get_adjustment(gobj()));
  if(retvalue)
    retvalue->reference(); //The function does not do a ref for us.
  return retvalue;
}

auto SpinButton::get_adjustment() const -> Glib::RefPtr<const Adjustment>
{
  return const_cast<SpinButton*>(this)->get_adjustment();
}

auto SpinButton::set_digits (
  const guint digits) -> void
{
  gtk_spin_button_set_digits(gobj(), digits);
}

auto SpinButton::get_digits() const -> guint
{
  return gtk_spin_button_get_digits(const_cast<GtkSpinButton*>(gobj()));
}

auto SpinButton::set_increments (
  const double step, const double page) -> void
{
  gtk_spin_button_set_increments(gobj(), step, page);
}

auto SpinButton::get_increments (double &step, double &page) const -> void
{
  gtk_spin_button_get_increments(const_cast<GtkSpinButton*>(gobj()), &step, &page);
}

auto SpinButton::set_range (
  const double min, const double max) -> void
{
  gtk_spin_button_set_range(gobj(), min, max);
}

auto SpinButton::get_range (double &min, double &max) const -> void
{
  gtk_spin_button_get_range(const_cast<GtkSpinButton*>(gobj()), &min, &max);
}

auto SpinButton::get_value() const -> double
{
  return gtk_spin_button_get_value(const_cast<GtkSpinButton*>(gobj()));
}

auto SpinButton::get_value_as_int() const -> int
{
  return gtk_spin_button_get_value_as_int(const_cast<GtkSpinButton*>(gobj()));
}

auto SpinButton::set_value (
  const double value) -> void
{
  gtk_spin_button_set_value(gobj(), value);
}

auto SpinButton::set_update_policy (UpdatePolicy policy) -> void
{
  gtk_spin_button_set_update_policy(gobj(), static_cast<GtkSpinButtonUpdatePolicy>(policy));
}

auto SpinButton::get_update_policy() const -> UpdatePolicy
{
  return static_cast<UpdatePolicy>(gtk_spin_button_get_update_policy(const_cast<GtkSpinButton*>(gobj())));
}

auto SpinButton::set_numeric (
  const bool numeric) -> void
{
  gtk_spin_button_set_numeric(gobj(), numeric);
}

auto SpinButton::get_numeric() const -> bool
{
  return gtk_spin_button_get_numeric(const_cast<GtkSpinButton*>(gobj()));
}

auto SpinButton::spin (SpinType direction, const double increment) -> void
{
  gtk_spin_button_spin(gobj(), static_cast<GtkSpinType>(direction), increment);
}

auto SpinButton::set_wrap (
  const bool wrap) -> void
{
  gtk_spin_button_set_wrap(gobj(), wrap);
}

auto SpinButton::get_wrap() const -> bool
{
  return gtk_spin_button_get_wrap(const_cast<GtkSpinButton*>(gobj()));
}

auto SpinButton::set_snap_to_ticks (
  const bool snap_to_ticks) -> void
{
  gtk_spin_button_set_snap_to_ticks(gobj(), snap_to_ticks);
}

auto SpinButton::get_snap_to_ticks() const -> bool
{
  return gtk_spin_button_get_snap_to_ticks(const_cast<GtkSpinButton*>(gobj()));
}

auto SpinButton::set_climb_rate (
  const double climb_rate) -> void
{
  gtk_spin_button_set_climb_rate(gobj(), climb_rate);
}

auto SpinButton::get_climb_rate() const -> double
{
  return gtk_spin_button_get_climb_rate(const_cast<GtkSpinButton*>(gobj()));
}

auto SpinButton::update () -> void
{
  gtk_spin_button_update(gobj());
}


auto SpinButton::signal_input() -> Glib::SignalProxy<int(double&)>
{
  return {this, &SpinButton_signal_input_info};
}


auto SpinButton::signal_output() -> Glib::SignalProxy<bool()>
{
  return {this, &SpinButton_signal_output_info};
}


auto SpinButton::signal_wrapped() -> Glib::SignalProxy<void()>
{
  return {this, &SpinButton_signal_wrapped_info};
}


auto SpinButton::signal_value_changed() -> Glib::SignalProxy<void()>
{
  return {this, &SpinButton_signal_value_changed_info};
}


static_assert(Glib::Traits::ValueCompatibleWithWrapProperty<Glib::RefPtr<Adjustment>>::value,
  "Type Glib::RefPtr<Adjustment> cannot be used in _WRAP_PROPERTY. "
  "There is no suitable template specialization of Glib::Value<>.");

auto SpinButton::property_adjustment() -> Glib::PropertyProxy< Glib::RefPtr<Adjustment> >
{
  return {this, "adjustment"};
}

auto SpinButton::property_adjustment() const -> Glib::PropertyProxy_ReadOnly< Glib::RefPtr<Adjustment> >
{
  return {this, "adjustment"};
}

auto SpinButton::property_climb_rate() -> Glib::PropertyProxy< double >
{
  return {this, "climb-rate"};
}

auto SpinButton::property_climb_rate() const -> Glib::PropertyProxy_ReadOnly< double >
{
  return {this, "climb-rate"};
}

auto SpinButton::property_digits() -> Glib::PropertyProxy< guint >
{
  return {this, "digits"};
}

auto SpinButton::property_digits() const -> Glib::PropertyProxy_ReadOnly< guint >
{
  return {this, "digits"};
}

auto SpinButton::property_snap_to_ticks() -> Glib::PropertyProxy< bool >
{
  return {this, "snap-to-ticks"};
}

auto SpinButton::property_snap_to_ticks() const -> Glib::PropertyProxy_ReadOnly< bool >
{
  return {this, "snap-to-ticks"};
}

auto SpinButton::property_numeric() -> Glib::PropertyProxy< bool >
{
  return {this, "numeric"};
}

auto SpinButton::property_numeric() const -> Glib::PropertyProxy_ReadOnly< bool >
{
  return {this, "numeric"};
}

auto SpinButton::property_wrap() -> Glib::PropertyProxy< bool >
{
  return {this, "wrap"};
}

auto SpinButton::property_wrap() const -> Glib::PropertyProxy_ReadOnly< bool >
{
  return {this, "wrap"};
}

static_assert(Glib::Traits::ValueCompatibleWithWrapProperty<UpdatePolicy>::value,
  "Type UpdatePolicy cannot be used in _WRAP_PROPERTY. "
  "There is no suitable template specialization of Glib::Value<>.");

auto SpinButton::property_update_policy() -> Glib::PropertyProxy< UpdatePolicy >
{
  return {this, "update-policy"};
}

auto SpinButton::property_update_policy() const -> Glib::PropertyProxy_ReadOnly< UpdatePolicy >
{
  return {this, "update-policy"};
}

auto SpinButton::property_value() -> Glib::PropertyProxy< double >
{
  return {this, "value"};
}

auto SpinButton::property_value() const -> Glib::PropertyProxy_ReadOnly< double >
{
  return {this, "value"};
}


} // namespace Gtk


