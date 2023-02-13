
#ifndef _GTKMM_SEARCHENTRY_H
#define _GTKMM_SEARCHENTRY_H


#include <libmm-glib/ustring.hpp>
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

#include <libmm-gtk/entry.hpp>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkSearchEntry = struct _GtkSearchEntry;
using GtkSearchEntryClass = struct _GtkSearchEntryClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{ class GTKMM_API SearchEntry_Class; } // namespace Gtk
#endif //DOXYGEN_SHOULD_SKIP_THIS

namespace Gtk
{

/** This is a subclass of Gtk::Entry that has
 * been tailored for use as a search entry.
 *
 * It will show an inactive symbolic "find" icon when the
 * search entry is empty, and a symbolic "clear" icon when
 * there is text. Clicking on the "clear" icon will empty
 * the search entry.
 *
 * Note that the search/clear icon is shown using a secondary
 * icon, and thus does not work if you are using the secondary
 * icon position for some other purpose.
 *
 * To make filtering appear more reactive, it is a good idea to
 * not react to every change in the entry text immediately, but
 * only after a short delay. To support this, Gtk::SearchEntry
 * emits the signal_search_changed() signal which can
 * be used instead of the Gtk::Editable::signal_changed() signal.
 *
 * The signal_previous_match(), signal_next_match()
 * and signal_stop_search() signals can be uesd to implement
 * moving between search results and ending the search.
 *
 * Often, %Gtk::SearchEntry will be fed events by means of being
 * placed inside a Gtk::SearchBar. If that is not the case,
 * you can use set_key_capture_widget() to let it
 * capture key input from another widget.
 *
 * @ingroup Widgets
 * @newin{3,6}
 */

class GTKMM_API SearchEntry
: public Entry
{
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  typedef SearchEntry CppObjectType;
  typedef SearchEntry_Class CppClassType;
  typedef GtkSearchEntry BaseObjectType;
  typedef GtkSearchEntryClass BaseClassType;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

  SearchEntry(SearchEntry&& src) noexcept;
  auto operator=(SearchEntry&& src) noexcept -> SearchEntry&;

  // noncopyable
  SearchEntry(const SearchEntry&) = delete;
  auto operator=(const SearchEntry&) -> SearchEntry& = delete;

  ~SearchEntry() noexcept override;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

private:
  friend GTKMM_API class SearchEntry_Class;
  static CppClassType searchentry_class_;

protected:
  explicit SearchEntry(const Glib::ConstructParams& construct_params);
  explicit SearchEntry(GtkSearchEntry* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS


  static auto get_base_type() -> GType G_GNUC_CONST;
#endif

  /// Provides access to the underlying C GObject.
  auto       gobj() -> GtkSearchEntry*       { return reinterpret_cast<GtkSearchEntry*>(gobject_); }

  /// Provides access to the underlying C GObject.
  auto gobj() const -> const GtkSearchEntry* { return reinterpret_cast<GtkSearchEntry*>(gobject_); }

private:

public:

  SearchEntry();


  /** Sets @a widget as the widget that @a entry will capture key
   * events from.
   *
   * Key events are consumed by the search entry to start or
   * continue a search.
   *
   * If the entry is part of a `Gtk::SearchBar`, it is preferable
   * to call Gtk::SearchBar::set_key_capture_widget() instead,
   * which will reveal the entry in addition to triggering the
   * search entry.
   *
   * Note that despite the name of this function, the events
   * are only 'captured' in the bubble phase, which means that
   * editable child widgets of @a widget will receive text input
   * before it gets captured. If that is not desired, you can
   * capture and forward the events yourself with
   * Gtk::EventControllerKey::forward().
   *
   * @param widget A `Gtk::Widget`.
   */
  void set_key_capture_widget(Widget& widget);

  /** Gets the widget that @a entry is capturing key events from.
   *
   * @return The key capture widget.
   */
  auto get_key_capture_widget() -> Widget*;

  /** Gets the widget that @a entry is capturing key events from.
   *
   * @return The key capture widget.
   */
  auto get_key_capture_widget() const -> const Widget*;
  void unset_key_capture_widget();


  /** Set the delay to be used between the last keypress and the
   * signal_search_changed() signal being emitted.
   *
   * @newin{4,8}
   *
   * @param delay A delay in milliseconds.
   */
  void set_search_delay(unsigned int delay);

  /** Get the delay to be used between the last keypress and the
   * signal_search_changed() signal being emitted.
   *
   * @newin{4,8}
   *
   * @return A delay in milliseconds.
   */
  auto get_search_delay() const -> unsigned int;

  // no_default_handler because GtkSearchEntryClass is private.

  /**
   * @par Slot Prototype:
   * <tt>void on_my_%search_changed()</tt>
   *
   * Flags: Run Last
   *
   * Emitted with a delay. The length of the delay can be
   * changed with the property_search_delay()
   * property.
   */

  auto signal_search_changed() -> Glib::SignalProxy<void()>;

  // Although next-match, previous-match and stop-search are keybinding signals,
  // applications shall connect to them.

  /**
   * @par Slot Prototype:
   * <tt>void on_my_%next_match()</tt>
   *
   * Flags: Run Last, Action
   *
   * Emitted when the user initiates a move to the next match
   * for the current search string.
   *
   * This is a [keybinding signal](class.SignalAction.html).
   *
   * Applications should connect to it, to implement moving
   * between matches.
   *
   * The default bindings for this signal is Ctrl-g.
   */

  auto signal_next_match() -> Glib::SignalProxy<void()>;


  /**
   * @par Slot Prototype:
   * <tt>void on_my_%previous_match()</tt>
   *
   * Flags: Run Last, Action
   *
   * Emitted when the user initiates a move to the previous match
   * for the current search string.
   *
   * This is a [keybinding signal](class.SignalAction.html).
   *
   * Applications should connect to it, to implement moving
   * between matches.
   *
   * The default bindings for this signal is Ctrl-Shift-g.
   */

  auto signal_previous_match() -> Glib::SignalProxy<void()>;


  /**
   * @par Slot Prototype:
   * <tt>void on_my_%stop_search()</tt>
   *
   * Flags: Run Last, Action
   *
   * Emitted when the user stops a search via keyboard input.
   *
   * This is a [keybinding signal](class.SignalAction.html).
   *
   * Applications should connect to it, to implement hiding
   * the search entry in this case.
   *
   * The default bindings for this signal is Escape.
   */

  auto signal_stop_search() -> Glib::SignalProxy<void()>;


  /**
   * @par Slot Prototype:
   * <tt>void on_my_%search_started()</tt>
   *
   * Flags: Run Last
   *
   * Emitted when the user initiated a search on the entry.
   */

  auto signal_search_started() -> Glib::SignalProxy<void()>;


  /** The text that will be displayed in the `Gtk::SearchEntry`
   * when it is empty and unfocused.
   *
   * Default value: ""
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_placeholder_text() -> Glib::PropertyProxy< Glib::ustring > ;

/** The text that will be displayed in the `Gtk::SearchEntry`
   * when it is empty and unfocused.
   *
   * Default value: ""
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_placeholder_text() const -> Glib::PropertyProxy_ReadOnly< Glib::ustring >;

  /** Whether to activate the default widget when Enter is pressed.
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_activates_default() -> Glib::PropertyProxy< bool > ;

/** Whether to activate the default widget when Enter is pressed.
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_activates_default() const -> Glib::PropertyProxy_ReadOnly< bool >;

  /** The delay in milliseconds from last keypress to the search
   * changed signal.
   *
   * @newin{4,8}
   *
   * Default value: 150
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_search_delay() -> Glib::PropertyProxy< unsigned int > ;

/** The delay in milliseconds from last keypress to the search
   * changed signal.
   *
   * @newin{4,8}
   *
   * Default value: 150
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_search_delay() const -> Glib::PropertyProxy_ReadOnly< unsigned int >;


public:

public:
  //C++ methods used to invoke GTK+ virtual functions:

protected:
  //GTK+ Virtual Functions (override these to change behaviour):

  //Default Signal Handlers::


};

} /* namespace Gtk */


namespace Glib
{
  /** A Glib::wrap() method for this object.
   *
   * @param object The C instance.
   * @param take_copy False if the result should take ownership of the C instance. True if it should take a new copy or ref.
   * @result A C++ instance that wraps this C instance.
   *
   * @relates Gtk::SearchEntry
   */
  GTKMM_API
  auto wrap(GtkSearchEntry* object, bool take_copy = false) -> Gtk::SearchEntry*;
} //namespace Glib


#endif /* _GTKMM_SEARCHENTRY_H */

