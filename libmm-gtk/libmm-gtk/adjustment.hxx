
#ifndef _GTKMM_ADJUSTMENT_H
#define _GTKMM_ADJUSTMENT_H

#include <libmm-gtk/mm-gtkconfig.hxx>


#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

/*
 * Copyright (C) 1998-2002 The gtkmm Development Team
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


#include <libmm-glib/object.hxx>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkAdjustment = struct _GtkAdjustment;
using GtkAdjustmentClass = struct _GtkAdjustmentClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{ class GTKMM_API Adjustment_Class; } // namespace Gtk
#endif //DOXYGEN_SHOULD_SKIP_THIS

namespace Gtk
{

/** A class representing an adjustable bounded value.
 *
 * The Gtk::Adjustment object represents a value which has an associated
 * lower and upper bound, together with step and page increments, and a page
 * size.  It is used within several gtkmm widgets, including
 * Gtk::SpinButton, Gtk::Viewport, and Gtk::Range (which is a base class for
 * Gtk::Scrollbar and Gtk::Scale).
 *
 * The Gtk::Adjustment object does not update the value itself. Instead it
 * is left up to the owner of the Gtk::Adjustment to control the value.
 */

class GTKMM_API Adjustment : public Glib::Object
{

#ifndef DOXYGEN_SHOULD_SKIP_THIS

public:
  using CppObjectType = Adjustment;
  using CppClassType = Adjustment_Class;
  using BaseObjectType = GtkAdjustment;
  using BaseClassType = GtkAdjustmentClass;

  // noncopyable
  Adjustment(const Adjustment&) = delete;
  auto operator=(const Adjustment&) -> Adjustment& = delete;

private:  friend class Adjustment_Class;
  static CppClassType adjustment_class_;

protected:
  explicit Adjustment(const Glib::ConstructParams& construct_params);
  explicit Adjustment(GtkAdjustment* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  Adjustment(Adjustment&& src) noexcept;
  auto operator=(Adjustment&& src) noexcept -> Adjustment&;

  ~Adjustment() noexcept override;

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS


  static auto get_base_type() -> GType G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GObject.
  auto       gobj() -> GtkAdjustment*       { return reinterpret_cast<GtkAdjustment*>(gobject_); }

  ///Provides access to the underlying C GObject.
  auto gobj() const -> const GtkAdjustment* { return reinterpret_cast<GtkAdjustment*>(gobject_); }

  ///Provides access to the underlying C instance. The caller is responsible for unrefing it. Use when directly setting fields in structs.
  auto gobj_copy() -> GtkAdjustment*;

private:


public:

  friend GTKMM_API class Range;
  friend GTKMM_API class HScrollbar;
  friend GTKMM_API class VScrollbar;

protected:
  /** Constructor to create an Adjustment object.
   * @param value The initial value
   * @param lower The minimum value
   * @param upper The maximum value
   * @param step_increment The step increment
   * @param page_increment The page increment
   * @param page_size The page size
   */
  Adjustment(double value, double lower, double upper, double step_increment = 1, double page_increment = 10, double page_size = 0);

public:

  static auto create(double value, double lower, double upper, double step_increment =  1, double page_increment =  10, double page_size =  0) -> Glib::RefPtr<Adjustment>;


  /** Updates the Adjustment value to ensure that the range between the parameters @a lower and @a upper is in the current page (i.e.\ between @a value and @a value + @a page_size).  If this range is larger than the page size, then only the start of it will be in the current page.  A "changed" signal will be emitted if the value is changed.
   *
   * @param lower The lower value.
   * @param upper The upper value.
   */
  void clamp_page(double lower, double upper);


  /** Sets the current value of the Adjustment
   *
   * @param value The new value of the Adjustment.
   */
  void set_value(double value);

  /** Gets the current value of the adjustment.
   *
   * @return The current value of the adjustment.
   */
  auto get_value() const -> double;


  /** Sets the minimum value of the adjustment.
   *
   * When setting multiple adjustment properties via their individual
   * setters, multiple signal_changed() signals will
   * be emitted. However, since the emission of the
   * signal_changed() signal is tied to the emission
   * of the signal_notify() signals of the changed properties, it’s possible
   * to compress the signal_changed() signals into one
   * by calling Glib::object_freeze_notify() and Glib::object_thaw_notify()
   * around the calls to the individual setters.
   *
   * Alternatively, using a single Glib::object_set() for all the properties
   * to change, or using configure() has the same effect.
   *
   * @param lower The new minimum value.
   */
  void set_lower(double lower);

  /** Retrieves the minimum value of the adjustment.
   *
   * @return The current minimum value of the adjustment.
   */
  auto get_lower() const -> double;


  /** Sets the maximum value of the adjustment.
   *
   * Note that values will be restricted by `upper - page-size`
   * if the page-size property is nonzero.
   *
   * See set_lower() about how to compress
   * multiple emissions of the signal_changed()
   * signal when setting multiple adjustment properties.
   *
   * @param upper The new maximum value.
   */
  void set_upper(double upper);

  /** Retrieves the maximum value of the adjustment.
   *
   * @return The current maximum value of the adjustment.
   */
  auto get_upper() const -> double;


  /** Sets the step increment of the adjustment.
   *
   * See set_lower() about how to compress
   * multiple emissions of the signal_changed()
   * signal when setting multiple adjustment properties.
   *
   * @param step_increment The new step increment.
   */
  void set_step_increment(double step_increment);

  /** Retrieves the step increment of the adjustment.
   *
   * @return The current step increment of the adjustment.
   */
  auto get_step_increment() const -> double;


  /** Sets the page increment of the adjustment.
   *
   * See set_lower() about how to compress
   * multiple emissions of the signal_changed()
   * signal when setting multiple adjustment properties.
   *
   * @param page_increment The new page increment.
   */
  void set_page_increment(double page_increment);

  /** Retrieves the page increment of the adjustment.
   *
   * @return The current page increment of the adjustment.
   */
  auto get_page_increment() const -> double;


  /** Sets the page size of the adjustment.
   *
   * See set_lower() about how to compress
   * multiple emissions of the signal_changed()
   * signal when setting multiple adjustment properties.
   *
   * @param page_size The new page size.
   */
  void set_page_size(double page_size);

  /** Retrieves the page size of the adjustment.
   *
   * @return The current page size of the adjustment.
   */
  auto get_page_size() const -> double;


  /** Sets all properties of the adjustment at once.
   *
   * Use this function to avoid multiple emissions of the
   * signal_changed() signal. See
   * set_lower() for an alternative
   * way of compressing multiple emissions of
   * signal_changed() into one.
   *
   * @param value The new value.
   * @param lower The new minimum value.
   * @param upper The new maximum value.
   * @param step_increment The new step increment.
   * @param page_increment The new page increment.
   * @param page_size The new page size.
   */
  void configure(double value, double lower, double upper, double step_increment, double page_increment, double page_size);


  /** Gets the smaller of step increment and page increment.
   *
   * @return The minimum increment of @a adjustment.
   */
  auto get_minimum_increment() const -> double;


  /**
   * @par Slot Prototype:
   * <tt>void on_my_%changed()</tt>
   *
   * Flags: Run First, No Recurse
   *
   * Emitted when one or more of the `Gtk::Adjustment` properties have been
   * changed.
   *
   * Note that the property_value() property is
   * covered by the signal_value_changed() signal.
   */

  auto signal_changed() -> Glib::SignalProxy<void()>;


  /**
   * @par Slot Prototype:
   * <tt>void on_my_%value_changed()</tt>
   *
   * Flags: Run First, No Recurse
   *
   * Emitted when the value has been changed.
   */

  auto signal_value_changed() -> Glib::SignalProxy<void()>;


  /** The value of the adjustment.
   *
   * Default value: 0
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_value() -> Glib::PropertyProxy< double > ;

/** The value of the adjustment.
   *
   * Default value: 0
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_value() const -> Glib::PropertyProxy_ReadOnly< double >;

  /** The minimum value of the adjustment.
   *
   * Default value: 0
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_lower() -> Glib::PropertyProxy< double > ;

/** The minimum value of the adjustment.
   *
   * Default value: 0
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_lower() const -> Glib::PropertyProxy_ReadOnly< double >;

  /** The maximum value of the adjustment.
   *
   * Note that values will be restricted by `upper - page-size` if the page-size
   * property is nonzero.
   *
   * Default value: 0
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_upper() -> Glib::PropertyProxy< double > ;

/** The maximum value of the adjustment.
   *
   * Note that values will be restricted by `upper - page-size` if the page-size
   * property is nonzero.
   *
   * Default value: 0
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_upper() const -> Glib::PropertyProxy_ReadOnly< double >;

  /** The step increment of the adjustment.
   *
   * Default value: 0
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_step_increment() -> Glib::PropertyProxy< double > ;

/** The step increment of the adjustment.
   *
   * Default value: 0
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_step_increment() const -> Glib::PropertyProxy_ReadOnly< double >;

  /** The page increment of the adjustment.
   *
   * Default value: 0
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_page_increment() -> Glib::PropertyProxy< double > ;

/** The page increment of the adjustment.
   *
   * Default value: 0
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_page_increment() const -> Glib::PropertyProxy_ReadOnly< double >;

  /** The page size of the adjustment.
   *
   * Note that the page-size is irrelevant and should be set to zero
   * if the adjustment is used for a simple scalar value, e.g. in a
   * `Gtk::SpinButton`.
   *
   * Default value: 0
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_page_size() -> Glib::PropertyProxy< double > ;

/** The page size of the adjustment.
   *
   * Note that the page-size is irrelevant and should be set to zero
   * if the adjustment is used for a simple scalar value, e.g. in a
   * `Gtk::SpinButton`.
   *
   * Default value: 0
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_page_size() const -> Glib::PropertyProxy_ReadOnly< double >;


public:

public:
  //C++ methods used to invoke GTK+ virtual functions:

protected:
  //GTK+ Virtual Functions (override these to change behaviour):

  //Default Signal Handlers::
  /// This is a default handler for the signal signal_changed().
  virtual void on_changed();
  /// This is a default handler for the signal signal_value_changed().
  virtual void on_value_changed();


};

} //namespace Gtk


namespace Glib
{
  /** A Glib::wrap() method for this object.
   *
   * @param object The C instance.
   * @param take_copy False if the result should take ownership of the C instance. True if it should take a new copy or ref.
   * @result A C++ instance that wraps this C instance.
   *
   * @relates Gtk::Adjustment
   */
  GTKMM_API
  auto wrap(GtkAdjustment* object, bool take_copy = false) -> Glib::RefPtr<Gtk::Adjustment>;
}


#endif /* _GTKMM_ADJUSTMENT_H */

