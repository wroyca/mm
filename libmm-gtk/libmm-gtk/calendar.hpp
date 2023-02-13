
#ifndef _GTKMM_CALENDAR_H
#define _GTKMM_CALENDAR_H

#include <mm/gtk/mm-gtkconfig.hpp>


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


#include <mm/gtk/widget.hpp>
#include <mm/glib/datetime.hpp>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkCalendar = struct _GtkCalendar;
using GtkCalendarClass = struct _GtkCalendarClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{ class GTKMM_API Calendar_Class; } // namespace Gtk
#endif //DOXYGEN_SHOULD_SKIP_THIS

namespace Gtk
{


/** Display a calendar and/or allow the user to select a date.
 *
 * This is a widget that displays a calendar, one month at a time.
 *
 * The month and year currently displayed can be altered with
 * select_month().  The exact day can be selected from the displayed month
 * using select_day().
 *
 * The way in which the calendar itself is displayed can be altered using
 * set_display_options().
 *
 * The selected date can be retrieved from a GtkCalendar using get_date().
 *
 * If performing many 'mark' operations, the calendar can be frozen to
 * prevent flicker, using freeze(), and 'thawed' again using thaw().
 *
 * The Calendar widget looks like this:
 * @image html calendar1.png
 *
 * @ingroup Widgets
 */

class GTKMM_API Calendar : public Widget
{
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  typedef Calendar CppObjectType;
  typedef Calendar_Class CppClassType;
  typedef GtkCalendar BaseObjectType;
  typedef GtkCalendarClass BaseClassType;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

  Calendar(Calendar&& src) noexcept;
  auto operator=(Calendar&& src) noexcept -> Calendar&;

  // noncopyable
  Calendar(const Calendar&) = delete;
  auto operator=(const Calendar&) -> Calendar& = delete;

  ~Calendar() noexcept override;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

private:
  friend GTKMM_API class Calendar_Class;
  static CppClassType calendar_class_;

protected:
  explicit Calendar(const Glib::ConstructParams& construct_params);
  explicit Calendar(GtkCalendar* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS


  static auto get_base_type() -> GType G_GNUC_CONST;
#endif

  /// Provides access to the underlying C GObject.
  auto       gobj() -> GtkCalendar*       { return reinterpret_cast<GtkCalendar*>(gobject_); }

  /// Provides access to the underlying C GObject.
  auto gobj() const -> const GtkCalendar* { return reinterpret_cast<GtkCalendar*>(gobject_); }

private:

public:
  Calendar();


  /** Switches to @a day's year and month and select its day.
   *
   * @param day A `Glib::DateTime` representing the day to select.
   */
  void select_day(const Glib::DateTime& day);

  /** Places a visual marker on a particular day.
   *
   * @param day The day number to mark between 1 and 31.
   */
  void mark_day(guint day);

  /** Removes the visual marker from a particular day.
   *
   * @param day The day number to unmark between 1 and 31.
   */
  void unmark_day(guint day);

  /** Remove all visual markers.
   */
  void clear_marks();


  /** Sets whether week numbers are shown in the calendar.
   *
   * @param value Whether to show week numbers on the left of the days.
   */
  void set_show_week_numbers(bool value =  true);

  /** Returns whether @a self is showing week numbers right
   * now.
   *
   * This is the value of the property_show_week_numbers()
   * property.
   *
   * Return: Whether the calendar is showing week numbers.
   */
  auto get_show_week_numbers() const -> bool;

  /** Sets whether the calendar should show a heading.
   *
   * The heading contains the current year and month as well as
   * buttons for changing both.
   *
   * @param value Whether to show the heading in the calendar.
   */
  void set_show_heading(bool value =  true);

  /** Returns whether @a self is currently showing the heading.
   *
   * This is the value of the property_show_heading()
   * property.
   *
   * Return: Whether the calendar is showing a heading.
   */
  auto get_show_heading() const -> bool;

  /** Sets whether the calendar shows day names.
   *
   * @param value Whether to show day names above the day numbers.
   */
  void set_show_day_names(bool value =  true);

  /** Returns whether @a self is currently showing the names
   * of the week days.
   *
   * This is the value of the property_show_day_names()
   * property.
   *
   * @return Whether the calendar shows day names.
   */
  auto get_show_day_names() const -> bool;


  /** Returns a `Glib::DateTime` representing the shown
   * year, month and the selected day.
   *
   * The returned date is in the local time zone.
   *
   * @return The `Glib::Date` representing the shown date.
   */
  auto get_date() const -> Glib::DateTime;


  /** Returns if the @a day of the @a calendar is already marked.
   *
   * @param day The day number between 1 and 31.
   * @return Whether the day is marked.
   */
  auto get_day_is_marked(guint day) const -> bool;

  // no_default_handler because GtkCalendarClass is private.

  /**
   * @par Slot Prototype:
   * <tt>void on_my_%day_selected()</tt>
   *
   * Flags: Run First
   *
   * Emitted when the user selects a day.
   */

  auto signal_day_selected() -> Glib::SignalProxy<void()>;


  /**
   * @par Slot Prototype:
   * <tt>void on_my_%prev_month()</tt>
   *
   * Flags: Run First
   *
   * Emitted when the user switched to the previous month.
   */

  auto signal_prev_month() -> Glib::SignalProxy<void()>;


  /**
   * @par Slot Prototype:
   * <tt>void on_my_%next_month()</tt>
   *
   * Flags: Run First
   *
   * Emitted when the user switched to the next month.
   */

  auto signal_next_month() -> Glib::SignalProxy<void()>;


  /**
   * @par Slot Prototype:
   * <tt>void on_my_%prev_year()</tt>
   *
   * Flags: Run First
   *
   * Emitted when user switched to the previous year.
   */

  auto signal_prev_year() -> Glib::SignalProxy<void()>;


  /**
   * @par Slot Prototype:
   * <tt>void on_my_%next_year()</tt>
   *
   * Flags: Run First
   *
   * Emitted when user switched to the next year.
   */

  auto signal_next_year() -> Glib::SignalProxy<void()>;


  /** The selected year.
   *
   * This property gets initially set to the current year.
   *
   * Default value: 1
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_year() -> Glib::PropertyProxy< int > ;

/** The selected year.
   *
   * This property gets initially set to the current year.
   *
   * Default value: 1
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_year() const -> Glib::PropertyProxy_ReadOnly< int >;

  /** The selected month (as a number between 0 and 11).
   *
   * This property gets initially set to the current month.
   *
   * Default value: 0
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_month() -> Glib::PropertyProxy< int > ;

/** The selected month (as a number between 0 and 11).
   *
   * This property gets initially set to the current month.
   *
   * Default value: 0
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_month() const -> Glib::PropertyProxy_ReadOnly< int >;

  /** The selected day (as a number between 1 and 31).
   *
   * Default value: 1
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_day() -> Glib::PropertyProxy< int > ;

/** The selected day (as a number between 1 and 31).
   *
   * Default value: 1
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_day() const -> Glib::PropertyProxy_ReadOnly< int >;

  /** Determines whether a heading is displayed.
   *
   * Default value: <tt>true</tt>
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_show_heading() -> Glib::PropertyProxy< bool > ;

/** Determines whether a heading is displayed.
   *
   * Default value: <tt>true</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_show_heading() const -> Glib::PropertyProxy_ReadOnly< bool >;

  /** Determines whether day names are displayed.
   *
   * Default value: <tt>true</tt>
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_show_day_names() -> Glib::PropertyProxy< bool > ;

/** Determines whether day names are displayed.
   *
   * Default value: <tt>true</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_show_day_names() const -> Glib::PropertyProxy_ReadOnly< bool >;

  /** Determines whether week numbers are displayed.
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_show_week_numbers() -> Glib::PropertyProxy< bool > ;

/** Determines whether week numbers are displayed.
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_show_week_numbers() const -> Glib::PropertyProxy_ReadOnly< bool >;


public:

public:
  //C++ methods used to invoke GTK+ virtual functions:

protected:
  //GTK+ Virtual Functions (override these to change behaviour):

  //Default Signal Handlers::


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
   * @relates Gtk::Calendar
   */
  GTKMM_API
  auto wrap(GtkCalendar* object, bool take_copy = false) -> Gtk::Calendar*;
} //namespace Glib


#endif /* _GTKMM_CALENDAR_H */

