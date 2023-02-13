
#ifndef _GTKMM_LEVELBAR_H
#define _GTKMM_LEVELBAR_H


#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

/* Copyright (C) 2012 The gtkmm Development Team
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


#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkLevelBar = struct _GtkLevelBar;
using GtkLevelBarClass = struct _GtkLevelBarClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{ class GTKMM_API LevelBar_Class; } // namespace Gtk
#endif //DOXYGEN_SHOULD_SKIP_THIS

namespace Gtk
{

/** A bar that can be used as a level indicator.
 *
 * Typical use cases are displaying the strength
 * of a password, or showing the charge level of a battery.
 *
 * Use set_value() to set the current value, and
 * add_offset_value() to set the value offsets at which
 * the bar will be considered in a different state. There will be three offsets
 * by default on the level bar: GTK_LEVEL_BAR_OFFSET_LOW,
 * GTK_LEVEL_BAR_OFFSET_HIGH and GTK_LEVEL_BAR_OFFSET_FULL, with
 * values 0.25, 0.75 and 1.0 respectively.
 *
 * The default interval of values is between zero and one, but it's possible to
 * modify the interval using set_min_value() and
 * set_max_value(). The value will be always drawn in proportion to
 * the admissible interval, i.e. a value of 15 with a specified interval between
 * 10 and 20 is equivalent to a value of 0.5 with an interval between 0 and 1.
 * When Gtk::LevelBar::Mode::DISCRETE is used, the bar level is rendered
 * as a finite and number of separated blocks instead of a single one. The number
 * of blocks that will be rendered is equal to the number of units specified by
 * the admissible interval.
 * For instance, to build a bar rendered with five blocks, it's sufficient to
 * set the minimum value to 0 and the maximum value to 5 after changing the indicator
 * mode to discrete.
 *
 * @ingroup Widgets
 * @newin{3,6}
 */

class GTKMM_API LevelBar
: public Widget,
  public Orientable
{
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  typedef LevelBar CppObjectType;
  typedef LevelBar_Class CppClassType;
  typedef GtkLevelBar BaseObjectType;
  typedef GtkLevelBarClass BaseClassType;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

  LevelBar(LevelBar&& src) noexcept;
  auto operator=(LevelBar&& src) noexcept -> LevelBar&;

  // noncopyable
  LevelBar(const LevelBar&) = delete;
  auto operator=(const LevelBar&) -> LevelBar& = delete;

  ~LevelBar() noexcept override;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

private:
  friend GTKMM_API class LevelBar_Class;
  static CppClassType levelbar_class_;

protected:
  explicit LevelBar(const Glib::ConstructParams& construct_params);
  explicit LevelBar(GtkLevelBar* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS


  static auto get_base_type() -> GType G_GNUC_CONST;
#endif

  /// Provides access to the underlying C GObject.
  auto       gobj() -> GtkLevelBar*       { return reinterpret_cast<GtkLevelBar*>(gobject_); }

  /// Provides access to the underlying C GObject.
  auto gobj() const -> const GtkLevelBar* { return reinterpret_cast<GtkLevelBar*>(gobject_); }

private:


public:
  /** @addtogroup gtkmmEnums gtkmm Enums and Flags */

  /**
   *  @var Mode CONTINUOUS
   * The bar has a continuous mode.
   *
   *  @var Mode DISCRETE
   * The bar has a discrete mode.
   *
   *  @enum Mode
   *
   * Describes how Gtk::LevelBar contents should be rendered.
   *
   * Note that this enumeration could be extended with additional modes
   * in the future.
   *
   * @ingroup gtkmmEnums
   */
  enum class Mode
  {
    CONTINUOUS,
    DISCRETE
  };


  LevelBar();


  /** Sets the `mode` of the `Gtk::LevelBar`.
   *
   * @param mode A `Gtk::LevelBar::Mode`.
   */
  void set_mode(Mode mode);

  /** Returns the `mode` of the `Gtk::LevelBar`.
   *
   * @return A `Gtk::LevelBar::Mode`.
   */
  auto get_mode() const -> Mode;


  /** Sets the value of the `Gtk::LevelBar`.
   *
   * @param value A value in the interval between
   * property_min_value() and property_max_value().
   */
  void set_value(double value);

  /** Returns the `value` of the `Gtk::LevelBar`.
   *
   * @return A value in the interval between
   * [property@Gtk.LevelBar:min-value[ and [property @a Gtk.LevelBar:max-value].
   */
  auto get_value() const -> double;


  /** Sets the `min-value` of the `Gtk::LevelBar`.
   *
   * You probably want to update preexisting level offsets after calling
   * this function.
   *
   * @param value A positive value.
   */
  void set_min_value(double value);

  /** Returns the `min-value of the `Gtk::LevelBar`.
   *
   * @return A positive value.
   */
  auto get_min_value() const -> double;


  /** Sets the `max-value` of the `Gtk::LevelBar`.
   *
   * You probably want to update preexisting level offsets after calling
   * this function.
   *
   * @param value A positive value.
   */
  void set_max_value(double value);

  /** Returns the `max-value` of the `Gtk::LevelBar`.
   *
   * @return A positive value.
   */
  auto get_max_value() const -> double;


  /** Sets whether the `Gtk::LevelBar` is inverted.
   *
   * @param inverted <tt>true</tt> to invert the level bar.
   */
  void set_inverted(bool inverted =  true);

  /** Returns whether the levelbar is inverted.
   *
   * @return <tt>true</tt> if the level bar is inverted.
   */
  auto get_inverted() const -> bool;


  /** Adds a new offset marker on @a self at the position specified by @a value.
   *
   * When the bar value is in the interval topped by @a value (or between @a value
   * and property_max_value() in case the offset is the last one
   * on the bar) a style class named `level-` @a name will be applied
   * when rendering the level bar fill.
   *
   * If another offset marker named @a name exists, its value will be
   * replaced by @a value.
   *
   * @param name The name of the new offset.
   * @param value The value for the new offset.
   */
  void add_offset_value(const Glib::ustring& name, double value);

  /** Removes an offset marker from a `Gtk::LevelBar`.
   *
   * The marker must have been previously added with
   * add_offset_value().
   *
   * @param name The name of an offset in the bar.
   */
  void remove_offset_value(const Glib::ustring& name);

  /** Fetches the value specified for the offset marker @a name in @a self.
   *
   * @param name The name of an offset in the bar.
   * @param value Location where to store the value.
   * @return <tt>true</tt> if the specified offset is found.
   */
  auto get_offset_value(const Glib::ustring& name, double& value) const -> bool;

  // no_default_handler because GtkLevelBarClass is private.

  /**
   * @par Slot Prototype:
   * <tt>void on_my_%offset_changed(const Glib::ustring& name)</tt>
   *
   * Flags: Run First
   *
   * Emitted when an offset specified on the bar changes value.
   *
   * This typically is the result of a Gtk::LevelBar::add_offset_value()
   * call.
   *
   * The signal supports detailed connections; you can connect to the
   * detailed signal "changed::x" in order to only receive callbacks when
   * the value of offset "x" changes.
   *
   * @param name The name of the offset that changed value.
   */

  auto signal_offset_changed(const Glib::ustring& offset_name = {}) -> Glib::SignalProxyDetailed<void(const Glib::ustring&)>;


  /** Determines the currently filled value of the level bar.
   *
   * Default value: 0
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_value() -> Glib::PropertyProxy< double > ;

/** Determines the currently filled value of the level bar.
   *
   * Default value: 0
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_value() const -> Glib::PropertyProxy_ReadOnly< double >;

  /** Determines the minimum value of the interval that can be displayed by the bar.
   *
   * Default value: 0
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_min_value() -> Glib::PropertyProxy< double > ;

/** Determines the minimum value of the interval that can be displayed by the bar.
   *
   * Default value: 0
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_min_value() const -> Glib::PropertyProxy_ReadOnly< double >;

  /** Determines the maximum value of the interval that can be displayed by the bar.
   *
   * Default value: 1
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_max_value() -> Glib::PropertyProxy< double > ;

/** Determines the maximum value of the interval that can be displayed by the bar.
   *
   * Default value: 1
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_max_value() const -> Glib::PropertyProxy_ReadOnly< double >;

  /** Determines the way `Gtk::LevelBar` interprets the value properties to draw the
   * level fill area.
   *
   * Specifically, when the value is Gtk::LevelBar::Mode::CONTINUOUS,
   * `Gtk::LevelBar` will draw a single block representing the current value in
   * that area; when the value is Gtk::LevelBar::Mode::DISCRETE,
   * the widget will draw a succession of separate blocks filling the
   * draw area, with the number of blocks being equal to the units separating
   * the integral roundings of property_min_value() and
   * property_max_value().
   *
   * Default value: Gtk::LevelBar::Mode::CONTINUOUS
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_mode() -> Glib::PropertyProxy< Mode > ;

/** Determines the way `Gtk::LevelBar` interprets the value properties to draw the
   * level fill area.
   *
   * Specifically, when the value is Gtk::LevelBar::Mode::CONTINUOUS,
   * `Gtk::LevelBar` will draw a single block representing the current value in
   * that area; when the value is Gtk::LevelBar::Mode::DISCRETE,
   * the widget will draw a succession of separate blocks filling the
   * draw area, with the number of blocks being equal to the units separating
   * the integral roundings of property_min_value() and
   * property_max_value().
   *
   * Default value: Gtk::LevelBar::Mode::CONTINUOUS
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_mode() const -> Glib::PropertyProxy_ReadOnly< Mode >;

  /** Whether the `Gtk::LeveBar` is inverted.
   *
   * Level bars normally grow from top to bottom or left to right.
   * Inverted level bars grow in the opposite direction.
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_inverted() -> Glib::PropertyProxy< bool > ;

/** Whether the `Gtk::LeveBar` is inverted.
   *
   * Level bars normally grow from top to bottom or left to right.
   * Inverted level bars grow in the opposite direction.
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_inverted() const -> Glib::PropertyProxy_ReadOnly< bool >;


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
class GTKMM_API Value<Gtk::LevelBar::Mode> : public Glib::Value_Enum<Gtk::LevelBar::Mode>
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
   * @relates Gtk::LevelBar
   */
  GTKMM_API
  auto wrap(GtkLevelBar* object, bool take_copy = false) -> Gtk::LevelBar*;
} //namespace Glib


#endif /* _GTKMM_LEVELBAR_H */

