
#ifndef _GTKMM_RANGE_H
#define _GTKMM_RANGE_H


#include <libmm-glib/ustring.hpp>
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

#include <libmm-gtk/widget.hpp>
#include <libmm-gtk/enums.hpp> //For SensitivityType.
#include <libmm-gtk/border.hpp>
#include <libmm-gtk/orientable.hpp>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkRange = struct _GtkRange;
using GtkRangeClass = struct _GtkRangeClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{ class GTKMM_API Range_Class; } // namespace Gtk
#endif //DOXYGEN_SHOULD_SKIP_THIS

namespace Gtk
{

class GTKMM_API Adjustment;

/** Base class for widgets which visualize an adjustment.
 *
 * @ingroup Widgets
 */

class GTKMM_API Range
: public Widget,
  public Orientable
{
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  typedef Range CppObjectType;
  typedef Range_Class CppClassType;
  typedef GtkRange BaseObjectType;
  typedef GtkRangeClass BaseClassType;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

  Range(Range&& src) noexcept;
  auto operator=(Range&& src) noexcept -> Range&;

  // noncopyable
  Range(const Range&) = delete;
  auto operator=(const Range&) -> Range& = delete;

  ~Range() noexcept override;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

private:
  friend GTKMM_API class Range_Class;
  static CppClassType range_class_;

protected:
  explicit Range(const Glib::ConstructParams& construct_params);
  explicit Range(GtkRange* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS


  static auto get_base_type() -> GType G_GNUC_CONST;
#endif

  /// Provides access to the underlying C GObject.
  auto       gobj() -> GtkRange*       { return reinterpret_cast<GtkRange*>(gobject_); }

  /// Provides access to the underlying C GObject.
  auto gobj() const -> const GtkRange* { return reinterpret_cast<GtkRange*>(gobject_); }

private:


protected:
  Range();
public:


  /** Sets the adjustment to be used as the “model” object for the `Gtk::Range`
   *
   * The adjustment indicates the current range value, the minimum and
   * maximum range values, the step/page increments used for keybindings
   * and scrolling, and the page size.
   *
   * The page size is normally 0 for `Gtk::Scale` and nonzero for `Gtk::Scrollbar`,
   * and indicates the size of the visible area of the widget being scrolled.
   * The page size affects the size of the scrollbar slider.
   *
   * @param adjustment A `Gtk::Adjustment`.
   */
  void set_adjustment(const Glib::RefPtr<Adjustment>& adjustment);
  void unset_adjustment();


  /** Get the adjustment which is the “model” object for `Gtk::Range`.
   *
   * @return A `Gtk::Adjustment`.
   */
  auto get_adjustment() -> Glib::RefPtr<Adjustment>;

  /** Get the adjustment which is the “model” object for `Gtk::Range`.
   *
   * @return A `Gtk::Adjustment`.
   */
  auto get_adjustment() const -> Glib::RefPtr<const Adjustment>;

  /** Sets whether to invert the range.
   *
   * Ranges normally move from lower to higher values as the
   * slider moves from top to bottom or left to right. Inverted
   * ranges have higher values at the top or on the right rather
   * than on the bottom or left.
   *
   * @param setting <tt>true</tt> to invert the range.
   */
  void set_inverted(bool setting =  true);

  /** Gets whether the range is inverted.
   *
   * See set_inverted().
   *
   * @return <tt>true</tt> if the range is inverted.
   */
  auto get_inverted() const -> bool;

  /** Sets whether the `Gtk::Range` respects text direction.
   *
   * If a range is flippable, it will switch its direction
   * if it is horizontal and its direction is Gtk::TextDirection::RTL.
   *
   * See Gtk::Widget::get_direction().
   *
   * @param flippable <tt>true</tt> to make the range flippable.
   */
  void set_flippable(bool flippable =  true);

  /** Gets whether the `Gtk::Range` respects text direction.
   *
   * See set_flippable().
   *
   * @return <tt>true</tt> if the range is flippable.
   */
  auto get_flippable() const -> bool;


  /** Sets whether the range’s slider has a fixed size, or a size that
   * depends on its adjustment’s page size.
   *
   * This function is useful mainly for `Gtk::Range` subclasses.
   *
   * @param size_fixed <tt>true</tt> to make the slider size constant.
   */
  void set_slider_size_fixed(bool size_fixed =  true);

  /** This function is useful mainly for `Gtk::Range` subclasses.
   *
   * See set_slider_size_fixed().
   *
   * @return Whether the range’s slider has a fixed size.
   */
  auto get_slider_size_fixed() const -> bool;

  /** This method returns the area that contains the range's trough
   * and its steppers, in the widget's Gdk::Surface coordinates.
   *
   * This method is useful mainly for Range subclasses.
   *
   * @result The range rectangle.
   *
   * @@newin{2,20}
   */
  auto get_range_rect() const -> Gdk::Rectangle;


  /** This function returns sliders range along the long dimension,
   * in widget->window coordinates.
   *
   * This function is useful mainly for `Gtk::Range` subclasses.
   *
   * @param slider_start Return location for the slider's start.
   * @param slider_end Return location for the slider's end.
   */
  void get_slider_range(int& slider_start, int& slider_end) const;


  /** Sets the step and page sizes for the range.
   *
   * The step size is used when the user clicks the `Gtk::Scrollbar`
   * arrows or moves a `Gtk::Scale` via arrow keys. The page size
   * is used for example when moving via Page Up or Page Down keys.
   *
   * @param step Step size.
   * @param page Page size.
   */
  void set_increments(double step, double page);

  /** Sets the allowable values in the `Gtk::Range`.
   *
   * The range value is clamped to be between @a min and @a max.
   * (If the range has a non-zero page size, it is clamped
   * between @a min and @a max - page-size.)
   *
   * @param min Minimum range value.
   * @param max Maximum range value.
   */
  void set_range(double min, double max);

  /** Sets the current value of the range.
   *
   * If the value is outside the minimum or maximum range values,
   * it will be clamped to fit inside them. The range emits the
   * signal_value_changed() signal if the value changes.
   *
   * @param value New value of the range.
   */
  void set_value(double value);

  /** Gets the current value of the range.
   *
   * @return Current value of the range.
   */
  auto get_value() const -> double;


  /** Sets whether a graphical fill level is show on the trough.
   *
   * See set_fill_level() for a general description
   * of the fill level concept.
   *
   * @param show_fill_level Whether a fill level indicator graphics is shown.
   */
  void set_show_fill_level(bool show_fill_level =  true);

  /** Gets whether the range displays the fill level graphically.
   *
   * @return <tt>true</tt> if @a range shows the fill level.
   */
  auto get_show_fill_level() const -> bool;

  /** Sets whether the slider is restricted to the fill level.
   *
   * See set_fill_level() for a general description
   * of the fill level concept.
   *
   * @param restrict_to_fill_level Whether the fill level restricts slider movement.
   */
  void set_restrict_to_fill_level(bool restrict_to_fill_level =  true);

  /** Gets whether the range is restricted to the fill level.
   *
   * @return <tt>true</tt> if @a range is restricted to the fill level.
   */
  auto get_restrict_to_fill_level() const -> bool;

  /** Set the new position of the fill level indicator.
   *
   * The “fill level” is probably best described by its most prominent
   * use case, which is an indicator for the amount of pre-buffering in
   * a streaming media player. In that use case, the value of the range
   * would indicate the current play position, and the fill level would
   * be the position up to which the file/stream has been downloaded.
   *
   * This amount of prebuffering can be displayed on the range’s trough
   * and is themeable separately from the trough. To enable fill level
   * display, use set_show_fill_level(). The range defaults
   * to not showing the fill level.
   *
   * Additionally, it’s possible to restrict the range’s slider position
   * to values which are smaller than the fill level. This is controlled
   * by set_restrict_to_fill_level() and is by default
   * enabled.
   *
   * @param fill_level The new position of the fill level indicator.
   */
  void set_fill_level(double fill_level);

  /** Gets the current position of the fill level indicator.
   *
   * @return The current fill level.
   */
  auto get_fill_level() const -> double;

  /** Sets the number of digits to round the value to when
   * it changes.
   *
   * See signal_change_value().
   *
   * @param round_digits The precision in digits, or -1.
   */
  void set_round_digits(int round_digits);

  /** Gets the number of digits to round the value to when
   * it changes.
   *
   * See signal_change_value().
   *
   * @return The number of digits to round to.
   */
  auto get_round_digits() const -> int;


  /**
   * @par Slot Prototype:
   * <tt>void on_my_%value_changed()</tt>
   *
   * Flags: Run Last
   *
   * Emitted when the range value changes.
   */

  auto signal_value_changed() -> Glib::SignalProxy<void()>;


  /**
   * @par Slot Prototype:
   * <tt>void on_my_%adjust_bounds(double new_value)</tt>
   *
   * Flags: Run Last
   *
   * Emitted before clamping a value, to give the application a
   * chance to adjust the bounds.
   *
   * @param new_value The value before we clamp.
   */

  auto signal_adjust_bounds() -> Glib::SignalProxy<void(double)>;


  /**
   * @par Slot Prototype:
   * <tt>void on_my_%move_slider(ScrollType scroll)</tt>
   *
   * Flags: Run Last, Action
   *
   * Virtual function that moves the slider.
   *
   * Used for keybindings.
   *
   * @param scroll How to move the slider.
   */

  auto signal_move_slider() -> Glib::SignalProxy<void(ScrollType)>;


  /**
   * @par Slot Prototype:
   * <tt>bool on_my_%change_value(ScrollType scroll, double new_value)</tt>
   *
   * Flags: Run Last
   *
   * Emitted when a scroll action is performed on a range.
   *
   * It allows an application to determine the type of scroll event
   * that occurred and the resultant new value. The application can
   * handle the event itself and return <tt>true</tt> to prevent further
   * processing. Or, by returning <tt>false</tt>, it can pass the event to
   * other handlers until the default GTK handler is reached.
   *
   * The value parameter is unrounded. An application that overrides
   * the signal_change_value() signal is responsible for clamping the value
   * to the desired number of decimal digits; the default GTK
   * handler clamps the value based on property_round_digits().
   *
   * @param scroll The type of scroll action that was performed.
   * @param new_value The new value resulting from the scroll action.
   * @return <tt>true</tt> to prevent other handlers from being invoked for
   * the signal, <tt>false</tt> to propagate the signal further.
   */

  auto signal_change_value() -> Glib::SignalProxy<bool(ScrollType, double)>;


  /** The adjustment that is controlled by the range.
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_adjustment() -> Glib::PropertyProxy< Glib::RefPtr<Adjustment> > ;

/** The adjustment that is controlled by the range.
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_adjustment() const -> Glib::PropertyProxy_ReadOnly< Glib::RefPtr<Adjustment> >;

  /** If <tt>true</tt>, the direction in which the slider moves is inverted.
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_inverted() -> Glib::PropertyProxy< bool > ;

/** If <tt>true</tt>, the direction in which the slider moves is inverted.
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_inverted() const -> Glib::PropertyProxy_ReadOnly< bool >;

  /** Controls whether fill level indicator graphics are displayed
   * on the trough.
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_show_fill_level() -> Glib::PropertyProxy< bool > ;

/** Controls whether fill level indicator graphics are displayed
   * on the trough.
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_show_fill_level() const -> Glib::PropertyProxy_ReadOnly< bool >;

  /** Controls whether slider movement is restricted to an
   * upper boundary set by the fill level.
   *
   * Default value: <tt>true</tt>
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_restrict_to_fill_level() -> Glib::PropertyProxy< bool > ;

/** Controls whether slider movement is restricted to an
   * upper boundary set by the fill level.
   *
   * Default value: <tt>true</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_restrict_to_fill_level() const -> Glib::PropertyProxy_ReadOnly< bool >;

  /** The fill level (e.g.\ prebuffering of a network stream).
   *
   * Default value: 1.79769e+308
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_fill_level() -> Glib::PropertyProxy< double > ;

/** The fill level (e.g.\ prebuffering of a network stream).
   *
   * Default value: 1.79769e+308
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_fill_level() const -> Glib::PropertyProxy_ReadOnly< double >;

  /** The number of digits to round the value to when
   * it changes.
   *
   * See signal_change_value().
   *
   * Default value: -1
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_round_digits() -> Glib::PropertyProxy< int > ;

/** The number of digits to round the value to when
   * it changes.
   *
   * See signal_change_value().
   *
   * Default value: -1
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_round_digits() const -> Glib::PropertyProxy_ReadOnly< int >;


protected:
  virtual void get_range_border_vfunc(Gtk::Border& border) const;


public:

public:
  //C++ methods used to invoke GTK+ virtual functions:

protected:
  //GTK+ Virtual Functions (override these to change behaviour):

  //Default Signal Handlers::
  /// This is a default handler for the signal signal_value_changed().
  virtual void on_value_changed();
  /// This is a default handler for the signal signal_adjust_bounds().
  virtual void on_adjust_bounds(double new_value);
  /// This is a default handler for the signal signal_move_slider().
  virtual void on_move_slider(ScrollType scroll);
  /// This is a default handler for the signal signal_change_value().
  virtual auto on_change_value(ScrollType scroll, double new_value) -> bool;


};

} // namespace Gtk


namespace Glib
{
  /** A Glib::wrap() method for this object.
   *
   * @param object The C instance.
   * @param take_copy False if the result should take ownership of the C instance. True if it should take a new copy or ref.
   * @result A C++ instance that wraps this C instance.
   *
   * @relates Gtk::Range
   */
  GTKMM_API
  auto wrap(GtkRange* object, bool take_copy = false) -> Gtk::Range*;
} //namespace Glib


#endif /* _GTKMM_RANGE_H */

