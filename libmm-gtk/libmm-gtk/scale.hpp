
#ifndef _GTKMM_SCALE_H
#define _GTKMM_SCALE_H


#include <mm/glib/ustring.hpp>
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

#include <mm/gtk/range.hpp>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkScale = struct _GtkScale;
using GtkScaleClass = struct _GtkScaleClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{ class GTKMM_API Scale_Class; } // namespace Gtk
#endif //DOXYGEN_SHOULD_SKIP_THIS

namespace Gtk
{

/** A slider widget for selecting a value from a range.
 *
 * A Gtk::Scale is a slider control used to select a numeric value. To use it,
 * you'll probably want to investigate the methods on its base class,
 * Gtk::Range, in addition to the methods for Gtk::Scale itself. To set the
 * value of a scale, you would normally use set_value(). To detect
 * changes to the value, you would normally use signal_value_changed().
 *
 * Note that using the same upper and lower bounds for the Scale (through
 * the Range methods) will hide the slider itself. This is useful for
 * applications that want to show an undeterminate value on the scale, without
 * changing the layout of the application (such as movie or music players).
 *
 * @ingroup Widgets
 */

class GTKMM_API Scale : public Range
{
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  typedef Scale CppObjectType;
  typedef Scale_Class CppClassType;
  typedef GtkScale BaseObjectType;
  typedef GtkScaleClass BaseClassType;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

  Scale(Scale&& src) noexcept;
  auto operator=(Scale&& src) noexcept -> Scale&;

  // noncopyable
  Scale(const Scale&) = delete;
  auto operator=(const Scale&) -> Scale& = delete;

  ~Scale() noexcept override;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

private:
  friend GTKMM_API class Scale_Class;
  static CppClassType scale_class_;

protected:
  explicit Scale(const Glib::ConstructParams& construct_params);
  explicit Scale(GtkScale* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS


  static auto get_base_type() -> GType G_GNUC_CONST;
#endif

  /// Provides access to the underlying C GObject.
  auto       gobj() -> GtkScale*       { return reinterpret_cast<GtkScale*>(gobject_); }

  /// Provides access to the underlying C GObject.
  auto gobj() const -> const GtkScale* { return reinterpret_cast<GtkScale*>(gobject_); }

private:

public:

  Scale();

  /**
   * @newin{3,2}
   */
  explicit Scale(Orientation orientation);

  //Note that we try to use the same default parameter value as the default property value.
  explicit Scale(const Glib::RefPtr<Adjustment>& adjustment, Orientation orientation = Orientation::HORIZONTAL);


  /** Set the number of decimal digits.
   *
   * This also causes the adjustment to be rounded off so the retrieved value
   * matches the value the user sees. Setting digits to 1 gives for example
   * 1.0, 2 gives 1.00, etc.
   */
  void set_digits(int digits);


  /** Get the number of decimal digits.
   */
  auto get_digits() const -> int;


  /** Set whether the current value is displayed as a string next to the slider.
   */
  void set_draw_value(bool draw_value =  true);


  /** Get whether the current value is displayed as a string next to the slider.
   */
  auto get_draw_value() const -> bool;


  /** Set the position in which the value is displayed.
   */
  void set_value_pos(PositionType pos);


  /** Get the position in which the value is displayed.
   */
  auto get_value_pos() const -> PositionType;


  /** Sets whether the scale has an origin.
   *
   * If Gtk::GtkScale::property_has_origin() is set to <tt>true</tt> (the default),
   * the scale will highlight the part of the trough between the origin
   * (bottom or left side) and the current value.
   *
   * @param has_origin <tt>true</tt> if the scale has an origin.
   */
  void set_has_origin(bool has_origin =  true);

  /** Returns whether the scale has an origin.
   *
   * @return <tt>true</tt> if the scale has an origin.
   */
  auto get_has_origin() const -> bool;


  /** Gets the `Pango::Layout` used to display the scale.
   *
   * The returned object is owned by the scale so does not need
   * to be freed by the caller.
   *
   * @return The Pango::Layout
   * for this scale, or <tt>nullptr</tt> if the Gtk::GtkScale::property_draw_value()
   * property is <tt>false</tt>.
   */
  auto get_layout() -> Glib::RefPtr<Pango::Layout>;

  /** Gets the `Pango::Layout` used to display the scale.
   *
   * The returned object is owned by the scale so does not need
   * to be freed by the caller.
   *
   * @return The Pango::Layout
   * for this scale, or <tt>nullptr</tt> if the Gtk::GtkScale::property_draw_value()
   * property is <tt>false</tt>.
   */
  auto get_layout() const -> Glib::RefPtr<const Pango::Layout>;

  /** Obtains the coordinates where the scale will draw the
   * `Pango::Layout` representing the text in the scale.
   *
   * Remember when using the `Pango::Layout` function you need to
   * convert to and from pixels using `PANGO_PIXELS()` or `Pango::SCALE`.
   *
   * If the Gtk::GtkScale::property_draw_value() property is <tt>false</tt>, the return
   * values are undefined.
   *
   * @param x Location to store X offset of layout.
   * @param y Location to store Y offset of layout.
   */
  void get_layout_offsets(int& x, int& y) const;


  /** Adds a mark at @a value.
   *
   * A mark is indicated visually by drawing a tick mark next to the scale,
   * and GTK makes it easy for the user to position the scale exactly at the
   * marks value.
   *
   * If @a markup is not <tt>nullptr</tt>, text is shown next to the tick mark.
   *
   * To remove marks from a scale, use clear_marks().
   *
   * @param value The value at which the mark is placed, must be between
   * the lower and upper limits of the scales’ adjustment.
   * @param position Where to draw the mark. For a horizontal scale, Gtk::PositionType::TOP
   * and Gtk::PositionType::LEFT are drawn above the scale, anything else below.
   * For a vertical scale, Gtk::PositionType::LEFT and Gtk::PositionType::TOP are drawn to
   * the left of the scale, anything else to the right.
   * @param markup Text to be shown at the mark, using Pango markup.
   */
  void add_mark(double value, PositionType position, const Glib::ustring& markup);

  /** Removes any marks that have been added.
   */
  void clear_marks();

  /** Slot that formats the value.
   *
   * For instance:
   * @code
   * Glib::ustring on_format_value(double value);
   * @endcode
   *
   * If set_format_value() is not used, the value will be displayed on
   * its own, rounded according to the value of property_digits().
   *
   * @param value The numeric value to format.
   * @return A string describing a textual representation of the given numerical value.
   */
  using SlotFormatValue = sigc::slot<Glib::ustring(double)>;

  /** Changes how the scale value is displayed.
   *
   * The given slot will return a string representing the value.
   * That string will then be used to display the scale's value.
   *
   * If this method is not called, or if unset_format_value_func() is called
   * afterwards, the value will be displayed on its own, rounded according
   * to the value of property_digits().
   *
   * @param slot Slot that formats the value.
   */
  void set_format_value_func(const SlotFormatValue& slot);


  /** Undoes the effect of a previous call to set_format_value_func().
   */
  void unset_format_value_func();

  /** The number of decimal places that are displayed in the value.
   *
   * Default value: 1
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_digits() -> Glib::PropertyProxy< int > ;

/** The number of decimal places that are displayed in the value.
   *
   * Default value: 1
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_digits() const -> Glib::PropertyProxy_ReadOnly< int >;

  /** Whether the current value is displayed as a string next to the slider.
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_draw_value() -> Glib::PropertyProxy< bool > ;

/** Whether the current value is displayed as a string next to the slider.
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_draw_value() const -> Glib::PropertyProxy_ReadOnly< bool >;

  /** The position in which the current value is displayed.
   *
   * Default value: Gtk::PositionType::TOP
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_value_pos() -> Glib::PropertyProxy< PositionType > ;

/** The position in which the current value is displayed.
   *
   * Default value: Gtk::PositionType::TOP
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_value_pos() const -> Glib::PropertyProxy_ReadOnly< PositionType >;

  /** Whether the scale has an origin.
   *
   * Default value: <tt>true</tt>
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_has_origin() -> Glib::PropertyProxy< bool > ;

/** Whether the scale has an origin.
   *
   * Default value: <tt>true</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_has_origin() const -> Glib::PropertyProxy_ReadOnly< bool >;


public:

public:
  //C++ methods used to invoke GTK+ virtual functions:

protected:
  //GTK+ Virtual Functions (override these to change behaviour):

  //Default Signal Handlers::


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
   * @relates Gtk::Scale
   */
  GTKMM_API
  auto wrap(GtkScale* object, bool take_copy = false) -> Gtk::Scale*;
} //namespace Glib


#endif /* _GTKMM_SCALE_H */

