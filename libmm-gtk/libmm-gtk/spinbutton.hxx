
#ifndef _GTKMM_SPINBUTTON_H
#define _GTKMM_SPINBUTTON_H


#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

/* Copyright (C) 1998-2002 The gtkmm Development Team
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

#include <libmm-gtk/widget.hxx>
#include <libmm-gtk/orientable.hxx>
#include <libmm-gtk/editable.hxx>
#include <libmm-gtk/celleditable.hxx>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkSpinButton = struct _GtkSpinButton;
using GtkSpinButtonClass = struct _GtkSpinButtonClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{ class GTKMM_API SpinButton_Class; } // namespace Gtk
#endif //DOXYGEN_SHOULD_SKIP_THIS

namespace Gtk
{


/** @addtogroup gtkmmEnums gtkmm Enums and Flags */

/**
 *  @var SpinType STEP_FORWARD
 * Increment by the adjustments step increment.
 *
 *  @var SpinType STEP_BACKWARD
 * Decrement by the adjustments step increment.
 *
 *  @var SpinType PAGE_FORWARD
 * Increment by the adjustments page increment.
 *
 *  @var SpinType PAGE_BACKWARD
 * Decrement by the adjustments page increment.
 *
 *  @var SpinType HOME
 * Go to the adjustments lower bound.
 *
 *  @var SpinType END
 * Go to the adjustments upper bound.
 *
 *  @var SpinType USER_DEFINED
 * Change by a specified amount.
 *
 *  @enum SpinType
 *
 * The values of the GtkSpinType enumeration are used to specify the
 * change to make in Gtk::SpinButton::spin().
 *
 * @ingroup gtkmmEnums
 */
enum class SpinType
{
  STEP_FORWARD,
  STEP_BACKWARD,
  PAGE_FORWARD,
  PAGE_BACKWARD,
  HOME,
  END,
  USER_DEFINED
};


} // namespace Gtk

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

template <>
class GTKMM_API Value<Gtk::SpinType> : public Glib::Value_Enum<Gtk::SpinType>
{
public:
  static auto value_type() -> GType G_GNUC_CONST;
};

} // namespace Glib
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

namespace Gtk
{


class GTKMM_API Adjustment;

/** Numeric Entry with up/down buttons.
 * Slightly misnamed, this should be called a SpinEntry.
 *
 * The %SpinButton widget looks like this:
 * @image html spinbutton1.png
 *
 * @ingroup Widgets
 */

class GTKMM_API SpinButton
: public Widget,
  public Orientable,
  public Editable,
  public CellEditable
{
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  typedef SpinButton CppObjectType;
  typedef SpinButton_Class CppClassType;
  typedef GtkSpinButton BaseObjectType;
  typedef GtkSpinButtonClass BaseClassType;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

  SpinButton(SpinButton&& src) noexcept;
  auto operator=(SpinButton&& src) noexcept -> SpinButton&;

  // noncopyable
  SpinButton(const SpinButton&) = delete;
  auto operator=(const SpinButton&) -> SpinButton& = delete;

  ~SpinButton() noexcept override;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

private:
  friend GTKMM_API class SpinButton_Class;
  static CppClassType spinbutton_class_;

protected:
  explicit SpinButton(const Glib::ConstructParams& construct_params);
  explicit SpinButton(GtkSpinButton* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS


  static auto get_base_type() -> GType G_GNUC_CONST;
#endif

  /// Provides access to the underlying C GObject.
  auto       gobj() -> GtkSpinButton*       { return reinterpret_cast<GtkSpinButton*>(gobject_); }

  /// Provides access to the underlying C GObject.
  auto gobj() const -> const GtkSpinButton* { return reinterpret_cast<GtkSpinButton*>(gobject_); }

private:


public:
  /**
   *  @var UpdatePolicy ALWAYS
   * When refreshing your `Gtk::SpinButton`, the value is
   * always displayed.
   *
   *  @var UpdatePolicy IF_VALID
   * When refreshing your `Gtk::SpinButton`, the value is
   * only displayed if it is valid within the bounds of the spin button's
   * adjustment.
   *
   *  @enum UpdatePolicy
   *
   * Determines whether the spin button displays values outside the adjustment
   * bounds.
   *
   * See Gtk::SpinButton::set_update_policy().
   *
   * @ingroup gtkmmEnums
   */
  enum class UpdatePolicy
  {
    ALWAYS,
    IF_VALID
  };


  /** Creates a %SpinButton.
   * @param climb_rate The acceleration rate when you hold down a button.
   * @param digits The number of decimal places to display.
   */
  explicit SpinButton(double climb_rate = 0.0, guint digits = 0);

  /** Creates a %SpinButton.
   * @param adjustment The Adjustment object that this spin button should use.
   * @param climb_rate The acceleration rate when you hold down a button.
   * @param digits The number of decimal places to display.
   */
    explicit SpinButton(const Glib::RefPtr<Adjustment>& adjustment, double climb_rate =  0.0, guint digits =  0);


  /** Changes the properties of an existing spin button.
   *
   * The adjustment, climb rate, and number of decimal places
   * are updated accordingly.
   *
   * @param adjustment A `Gtk::Adjustment` to replace the spin button’s
   * existing adjustment, or <tt>nullptr</tt> to leave its current adjustment unchanged.
   * @param climb_rate The new climb rate.
   * @param digits The number of decimal places to display in the spin button.
   */
  void configure(const Glib::RefPtr<Adjustment>& adjustment, double climb_rate, guint digits);


  /** Replaces the `Gtk::Adjustment` associated with @a spin_button.
   *
   * @param adjustment A `Gtk::Adjustment` to replace the existing adjustment.
   */
  void set_adjustment(const Glib::RefPtr<Adjustment>& adjustment);
  void unset_adjustment();

  /** Get the adjustment associated with a `Gtk::SpinButton`.
   *
   * @return The `Gtk::Adjustment` of @a spin_button.
   */
  auto get_adjustment() -> Glib::RefPtr<Adjustment>;

  /** Get the adjustment associated with a `Gtk::SpinButton`.
   *
   * @return The `Gtk::Adjustment` of @a spin_button.
   */
  auto get_adjustment() const -> Glib::RefPtr<const Adjustment>;


  /** Set the precision to be displayed by @a spin_button.
   *
   * Up to 20 digit precision is allowed.
   *
   * @param digits The number of digits after the decimal point to be
   * displayed for the spin button’s value.
   */
  void set_digits(guint digits);

  /** Fetches the precision of @a spin_button.
   *
   * @return The current precision.
   */
  auto get_digits() const -> guint;


  /** Sets the step and page increments for spin_button.
   *
   * This affects how quickly the value changes when
   * the spin button’s arrows are activated.
   *
   * @param step Increment applied for a button 1 press.
   * @param page Increment applied for a button 2 press.
   */
  void set_increments(double step, double page);

  /** Gets the current step and page the increments
   * used by @a spin_button.
   *
   * See set_increments().
   *
   * @param step Location to store step increment.
   * @param page Location to store page increment.
   */
  void get_increments(double& step, double& page) const;


  /** Sets the minimum and maximum allowable values for @a spin_button.
   *
   * If the current value is outside this range, it will be adjusted
   * to fit within the range, otherwise it will remain unchanged.
   *
   * @param min Minimum allowable value.
   * @param max Maximum allowable value.
   */
  void set_range(double min, double max);

  /** Gets the range allowed for @a spin_button.
   *
   * See set_range().
   *
   * @param min Location to store minimum allowed value.
   * @param max Location to store maximum allowed value.
   */
  void get_range(double& min, double& max) const;


  /** Get the value in the @a spin_button.
   *
   * @return The value of @a spin_button.
   */
  auto get_value() const -> double;

  /** Get the value @a spin_button represented as an integer.
   *
   * @return The value of @a spin_button.
   */
  auto get_value_as_int() const -> int;

  /** Sets the value of @a spin_button.
   *
   * @param value The new value.
   */
  void set_value(double value);


  /** Sets the update behavior of a spin button.
   *
   * This determines whether the spin button is always
   * updated or only when a valid value is set.
   *
   * @param policy A `Gtk::SpinButton::UpdatePolicy` value.
   */
  void set_update_policy(UpdatePolicy policy);

  /** Gets the update behavior of a spin button.
   *
   * See set_update_policy().
   *
   * @return The current update policy.
   */
  auto get_update_policy() const -> UpdatePolicy;


  /** Sets the flag that determines if non-numeric text can be typed
   * into the spin button.
   *
   * @param numeric Flag indicating if only numeric entry is allowed.
   */
  void set_numeric(bool numeric =  true);

  /** Returns whether non-numeric text can be typed into the spin button.
   *
   * @return <tt>true</tt> if only numeric text can be entered.
   */
  auto get_numeric() const -> bool;


  /** Increment or decrement a spin button’s value in a specified
   * direction by a specified amount.
   *
   * @param direction A `Gtk::SpinType` indicating the direction to spin.
   * @param increment Step increment to apply in the specified direction.
   */
  void spin(SpinType direction, double increment);


  /** Sets the flag that determines if a spin button value wraps
   * around to the opposite limit when the upper or lower limit
   * of the range is exceeded.
   *
   * @param wrap A flag indicating if wrapping behavior is performed.
   */
  void set_wrap(bool wrap =  true);

  /** Returns whether the spin button’s value wraps around to the
   * opposite limit when the upper or lower limit of the range is
   * exceeded.
   *
   * @return <tt>true</tt> if the spin button wraps around.
   */
  auto get_wrap() const -> bool;


  /** Sets the policy as to whether values are corrected to the
   * nearest step increment when a spin button is activated after
   * providing an invalid value.
   *
   * @param snap_to_ticks A flag indicating if invalid values should be corrected.
   */
  void set_snap_to_ticks(bool snap_to_ticks =  true);

  /** Returns whether the values are corrected to the nearest step.
   *
   * @return <tt>true</tt> if values are snapped to the nearest step.
   */
  auto get_snap_to_ticks() const -> bool;


  /** Sets the acceleration rate for repeated changes when you
   * hold down a button or key.
   *
   * @param climb_rate The rate of acceleration, must be >= 0.
   */
  void set_climb_rate(double climb_rate);

  /** Returns the acceleration rate for repeated changes.
   *
   * @return The acceleration rate.
   */
  auto get_climb_rate() const -> double;


  /** Manually force an update of the spin button.
   */
  void update();

  /** Constant to return from a signal handler for the input
   * signal in case of conversion failure.
   *
   * @ingroup gtkmmEnums
   */
  enum { INPUT_ERROR = -1 };

  // no_default_handler because GtkSpinButtonClass is private.

  /**
   * @par Slot Prototype:
   * <tt>int on_my_%input(double& new_value)</tt>
   *
   * Flags: Run Last
   *
   * Emitted to convert the users input into a double value.
   *
   * The signal handler is expected to use Gtk::Editable::get_text()
   * to retrieve the text of the spinbutton and set @a new_value to the
   * new value.
   *
   * The default conversion uses Glib::strtod().
   *
   * @param new_value Return location for the new value.
   * @return <tt>true</tt> for a successful conversion, <tt>false</tt> if the input
   * was not handled, and GTK_INPUT_ERROR if the conversion failed.
   */

  auto signal_input() -> Glib::SignalProxy<int(double&)>;


  /**
   * @par Slot Prototype:
   * <tt>bool on_my_%output()</tt>
   *
   * Flags: Run Last
   *
   * Emitted to tweak the formatting of the value for display.
   *
   *
   * [C example ellipted]
   *
   * @return <tt>true</tt> if the value has been displayed.
   */

  auto signal_output() -> Glib::SignalProxy<bool()>;


  /**
   * @par Slot Prototype:
   * <tt>void on_my_%wrapped()</tt>
   *
   * Flags: Run Last
   *
   * Emitted right after the spinbutton wraps from its maximum
   * to its minimum value or vice-versa.
   */

  auto signal_wrapped() -> Glib::SignalProxy<void()>;


  /**
   * @par Slot Prototype:
   * <tt>void on_my_%value_changed()</tt>
   *
   * Flags: Run Last
   *
   * Emitted when the value is changed.
   *
   * Also see the signal_output() signal.
   */

  auto signal_value_changed() -> Glib::SignalProxy<void()>;


  //Keybinding signals:


  /** The adjustment that holds the value of the spin button.
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_adjustment() -> Glib::PropertyProxy< Glib::RefPtr<Adjustment> > ;

/** The adjustment that holds the value of the spin button.
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_adjustment() const -> Glib::PropertyProxy_ReadOnly< Glib::RefPtr<Adjustment> >;

  /** The acceleration rate when you hold down a button or key.
   *
   * Default value: 0
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_climb_rate() -> Glib::PropertyProxy< double > ;

/** The acceleration rate when you hold down a button or key.
   *
   * Default value: 0
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_climb_rate() const -> Glib::PropertyProxy_ReadOnly< double >;

  /** The number of decimal places to display.
   *
   * Default value: 0
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_digits() -> Glib::PropertyProxy< guint > ;

/** The number of decimal places to display.
   *
   * Default value: 0
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_digits() const -> Glib::PropertyProxy_ReadOnly< guint >;

  /** Whether erroneous values are automatically changed to the spin buttons
   * nearest step increment.
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_snap_to_ticks() -> Glib::PropertyProxy< bool > ;

/** Whether erroneous values are automatically changed to the spin buttons
   * nearest step increment.
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_snap_to_ticks() const -> Glib::PropertyProxy_ReadOnly< bool >;

  /** Whether non-numeric characters should be ignored.
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_numeric() -> Glib::PropertyProxy< bool > ;

/** Whether non-numeric characters should be ignored.
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_numeric() const -> Glib::PropertyProxy_ReadOnly< bool >;

  /** Whether a spin button should wrap upon reaching its limits.
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_wrap() -> Glib::PropertyProxy< bool > ;

/** Whether a spin button should wrap upon reaching its limits.
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_wrap() const -> Glib::PropertyProxy_ReadOnly< bool >;

  /** Whether the spin button should update always, or only when the value
   * is acceptable.
   *
   * Default value: Gtk::SpinButton::UpdatePolicy::ALWAYS
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_update_policy() -> Glib::PropertyProxy< UpdatePolicy > ;

/** Whether the spin button should update always, or only when the value
   * is acceptable.
   *
   * Default value: Gtk::SpinButton::UpdatePolicy::ALWAYS
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_update_policy() const -> Glib::PropertyProxy_ReadOnly< UpdatePolicy >;

  /** The current value.
   *
   * Default value: 0
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_value() -> Glib::PropertyProxy< double > ;

/** The current value.
   *
   * Default value: 0
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_value() const -> Glib::PropertyProxy_ReadOnly< double >;


public:

public:
  //C++ methods used to invoke GTK+ virtual functions:

protected:
  //GTK+ Virtual Functions (override these to change behaviour):

  //Default Signal Handlers::


};

} // namespace Gtk


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

template <>
class GTKMM_API Value<Gtk::SpinButton::UpdatePolicy> : public Glib::Value_Enum<Gtk::SpinButton::UpdatePolicy>
{
public:
  static auto value_type() -> GType G_GNUC_CONST;
};

} // namespace Glib
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


namespace Glib
{
  /** A Glib::wrap() method for this object.
   *
   * @param object The C instance.
   * @param take_copy False if the result should take ownership of the C instance. True if it should take a new copy or ref.
   * @result A C++ instance that wraps this C instance.
   *
   * @relates Gtk::SpinButton
   */
  GTKMM_API
  auto wrap(GtkSpinButton* object, bool take_copy = false) -> Gtk::SpinButton*;
} //namespace Glib


#endif /* _GTKMM_SPINBUTTON_H */

