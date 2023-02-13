
#ifndef _GTKMM_ACCESSIBLE_H
#define _GTKMM_ACCESSIBLE_H

#include <libmm-gtk/mm-gtkconfig.hxx>


#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

/* Copyright (C) 2020 The gtkmm Development Team
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
 * License along with this library. If not, see <http://www.gnu.org/licenses/>.
 */


#include <libmm-glib/interface.hxx>
#include <libmm-glib/value.hxx>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
extern "C"
{
typedef struct _GtkAccessibleInterface GtkAccessibleInterface;
}
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkAccessible = struct _GtkAccessible;
using GtkAccessibleClass = struct _GtkAccessibleClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{ class GTKMM_API Accessible_Class; } // namespace Gtk
#endif // DOXYGEN_SHOULD_SKIP_THIS

namespace Gtk
{
/** %Accessible interface.
 *
 * %Gtk::Accessible provides an interface for describing a UI element, like a
 * Gtk::Widget, in a way that can be consumed by Assistive Technologies, or
 * “AT”. Every accessible implementation has:
 *
 *  - a “role”, represented by a value of the Gtk::Accessible::Role enumeration
 *  - an “attribute”, represented by a set of Gtk::Accessible::State,
 *    Gtk::Accessible::Property and Gtk::Accessible::Relation values
 *
 * The role cannot be changed after instantiating a %Gtk::Accessible
 * implementation.
 *
 * The attributes are updated every time a UI element's state changes in a way that
 * should be reflected by assistive technologies. For instance, if a Gtk::Widget
 * visibility changes, the Gtk::Accessible::State::HIDDEN state will also change
 * to reflect Gtk::Widget::property_visible().
 *
 * @newin{3,98}
 */

class GTKMM_API Accessible : public Glib::Interface
{

#ifndef DOXYGEN_SHOULD_SKIP_THIS

public:
  using CppObjectType = Accessible;
  using CppClassType = Accessible_Class;
  using BaseObjectType = GtkAccessible;
  using BaseClassType = GtkAccessibleInterface;

  // noncopyable
  Accessible(const Accessible&) = delete;
  auto operator=(const Accessible&) -> Accessible& = delete;

private:
  friend class Accessible_Class;
  static CppClassType accessible_class_;

#endif /* DOXYGEN_SHOULD_SKIP_THIS */
protected:
  /**
   * You should derive from this class to use it.
   */
  Accessible();

#ifndef DOXYGEN_SHOULD_SKIP_THIS
  /** Called by constructors of derived classes. Provide the result of
   * the Class init() function to ensure that it is properly
   * initialized.
   *
   * @param interface_class The Class object for the derived type.
   */
  explicit Accessible(const Glib::Interface_Class& interface_class);

public:
  // This is public so that C++ wrapper instances can be
  // created for C instances of unwrapped types.
  // For instance, if an unexpected C type implements the C interface.
  explicit Accessible(GtkAccessible* castitem);

protected:
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  Accessible(Accessible&& src) noexcept;
  auto operator=(Accessible&& src) noexcept -> Accessible&;

  ~Accessible() noexcept override;

  static void add_interface(GType gtype_implementer);

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS
  static auto get_base_type() -> GType G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GObject.
  auto       gobj() -> GtkAccessible*       { return reinterpret_cast<GtkAccessible*>(gobject_); }

  ///Provides access to the underlying C GObject.
  auto gobj() const -> const GtkAccessible* { return reinterpret_cast<GtkAccessible*>(gobject_); }

private:


public:
  /** @addtogroup gtkmmEnums gtkmm Enums and Flags */

  /**
   *  @var Role ALERT
   * An element with important, and usually
   * time-sensitive, information.
   *
   *  @var Role ALERT_DIALOG
   * A type of dialog that contains an
   * alert message.
   *
   *  @var Role BANNER
   * Unused.
   *
   *  @var Role BUTTON
   * An input element that allows for
   * user-triggered actions when clicked or pressed.
   *
   *  @var Role CAPTION
   * Unused.
   *
   *  @var Role CELL
   * Unused.
   *
   *  @var Role CHECKBOX
   * A checkable input element that has
   * three possible values: `true`, `false`, or `mixed`.
   *
   *  @var Role COLUMN_HEADER
   * A header in a columned list.
   *
   *  @var Role COMBO_BOX
   * An input that controls another element,
   * such as a list or a grid, that can dynamically pop up to help the user
   * set the value of the input.
   *
   *  @var Role COMMAND
   * Abstract role.
   *
   *  @var Role COMPOSITE
   * Abstract role.
   *
   *  @var Role DIALOG
   * A dialog is a window that is designed to interrupt
   * the current processing of an application in order to prompt the user to enter
   * information or require a response.
   *
   *  @var Role DOCUMENT
   * Unused.
   *
   *  @var Role FEED
   * Unused.
   *
   *  @var Role FORM
   * Unused.
   *
   *  @var Role GENERIC
   * Unused.
   *
   *  @var Role GRID
   * A grid of items.
   *
   *  @var Role GRID_CELL
   * An item in a grid or tree grid.
   *
   *  @var Role GROUP
   * An element that groups multiple widgets. GTK uses
   * this role for various containers, like Gtk::Box, Gtk::Viewport, and Gtk::HeaderBar.
   *
   *  @var Role HEADING
   * Unused.
   *
   *  @var Role IMG
   * An image.
   *
   *  @var Role INPUT
   * Abstract role.
   *
   *  @var Role LABEL
   * A visible name or caption for a user interface component.
   *
   *  @var Role LANDMARK
   * Abstract role.
   *
   *  @var Role LEGEND
   * Unused.
   *
   *  @var Role LINK
   * A clickable link.
   *
   *  @var Role LIST
   * A list of items.
   *
   *  @var Role LIST_BOX
   * Unused.
   *
   *  @var Role LIST_ITEM
   * An item in a list.
   *
   *  @var Role LOG
   * Unused.
   *
   *  @var Role MAIN
   * Unused.
   *
   *  @var Role MARQUEE
   * Unused.
   *
   *  @var Role MATH
   * Unused.
   *
   *  @var Role METER
   * An element that represents a value within a known range.
   *
   *  @var Role MENU
   * A menu.
   *
   *  @var Role MENU_BAR
   * A menubar.
   *
   *  @var Role MENU_ITEM
   * An item in a menu.
   *
   *  @var Role MENU_ITEM_CHECKBOX
   * A check item in a menu.
   *
   *  @var Role MENU_ITEM_RADIO
   * A radio item in a menu.
   *
   *  @var Role NAVIGATION
   * Unused.
   *
   *  @var Role NONE
   * An element that is not represented to accessibility technologies.
   *
   *  @var Role NOTE
   * Unused.
   *
   *  @var Role OPTION
   * Unused.
   *
   *  @var Role PRESENTATION
   * An element that is not represented to accessibility technologies.
   *
   *  @var Role PROGRESS_BAR
   * An element that displays the progress
   * status for tasks that take a long time.
   *
   *  @var Role RADIO
   * A checkable input in a group of radio roles,
   * only one of which can be checked at a time.
   *
   *  @var Role RADIO_GROUP
   * Unused.
   *
   *  @var Role RANGE
   * Abstract role.
   *
   *  @var Role REGION
   * Unused.
   *
   *  @var Role ROW
   * A row in a columned list.
   *
   *  @var Role ROW_GROUP
   * Unused.
   *
   *  @var Role ROW_HEADER
   * Unused.
   *
   *  @var Role SCROLLBAR
   * A graphical object that controls the scrolling
   * of content within a viewing area, regardless of whether the content is fully
   * displayed within the viewing area.
   *
   *  @var Role SEARCH
   * Unused.
   *
   *  @var Role SEARCH_BOX
   * A type of textbox intended for specifying
   * search criteria.
   *
   *  @var Role SECTION
   * Abstract role.
   *
   *  @var Role SECTION_HEAD
   * Abstract role.
   *
   *  @var Role SELECT
   * Abstract role.
   *
   *  @var Role SEPARATOR
   * A divider that separates and distinguishes
   * sections of content or groups of menuitems.
   *
   *  @var Role SLIDER
   * A user input where the user selects a value
   * from within a given range.
   *
   *  @var Role SPIN_BUTTON
   * A form of range that expects the user to
   * select from among discrete choices.
   *
   *  @var Role STATUS
   * Unused.
   *
   *  @var Role STRUCTURE
   * Abstract role.
   *
   *  @var Role SWITCH
   * A type of checkbox that represents on/off values,
   * as opposed to checked/unchecked values.
   *
   *  @var Role TAB
   * An item in a list of tab used for switching pages.
   *
   *  @var Role TABLE
   * Unused.
   *
   *  @var Role TAB_LIST
   * A list of tabs for switching pages.
   *
   *  @var Role TAB_PANEL
   * A page in a notebook or stack.
   *
   *  @var Role TEXT_BOX
   * A type of input that allows free-form text
   * as its value.
   *
   *  @var Role TIME
   * Unused.
   *
   *  @var Role TIMER
   * Unused.
   *
   *  @var Role TOOLBAR
   * Unused.
   *
   *  @var Role TOOLTIP
   * Unused.
   *
   *  @var Role TREE
   * Unused.
   *
   *  @var Role TREE_GRID
   * A treeview-like, columned list.
   *
   *  @var Role TREE_ITEM
   * Unused.
   *
   *  @var Role WIDGET
   * An interactive component of a graphical user
   * interface. This is the role that GTK uses by default for widgets.
   *
   *  @var Role WINDOW
   * An application window.
   *
   *  @enum Role
   *
   * The accessible role for a Gtk::Accessible implementation.
   *
   * Abstract roles are only used as part of the ontology; application
   * developers must not use abstract roles in their code.
   *
   * @ingroup gtkmmEnums
   */
  enum class Role
  {
    ALERT,
    ALERT_DIALOG,
    BANNER,
    BUTTON,
    CAPTION,
    CELL,
    CHECKBOX,
    COLUMN_HEADER,
    COMBO_BOX,
    COMMAND,
    COMPOSITE,
    DIALOG,
    DOCUMENT,
    FEED,
    FORM,
    GENERIC,
    GRID,
    GRID_CELL,
    GROUP,
    HEADING,
    IMG,
    INPUT,
    LABEL,
    LANDMARK,
    LEGEND,
    LINK,
    LIST,
    LIST_BOX,
    LIST_ITEM,
    LOG,
    MAIN,
    MARQUEE,
    MATH,
    METER,
    MENU,
    MENU_BAR,
    MENU_ITEM,
    MENU_ITEM_CHECKBOX,
    MENU_ITEM_RADIO,
    NAVIGATION,
    NONE,
    NOTE,
    OPTION,
    PRESENTATION,
    PROGRESS_BAR,
    RADIO,
    RADIO_GROUP,
    RANGE,
    REGION,
    ROW,
    ROW_GROUP,
    ROW_HEADER,
    SCROLLBAR,
    SEARCH,
    SEARCH_BOX,
    SECTION,
    SECTION_HEAD,
    SELECT,
    SEPARATOR,
    SLIDER,
    SPIN_BUTTON,
    STATUS,
    STRUCTURE,
    SWITCH,
    TAB,
    TABLE,
    TAB_LIST,
    TAB_PANEL,
    TEXT_BOX,
    TIME,
    TIMER,
    TOOLBAR,
    TOOLTIP,
    TREE,
    TREE_GRID,
    TREE_ITEM,
    WIDGET,
    WINDOW
  };


  /**
   *  @var State BUSY
   * A “busy” state. This state has boolean values.
   *
   *  @var State CHECKED
   * A “checked” state; indicates the current
   * state of a Gtk::CheckButton. Value type: Gtk::AccessibleTristate.
   *
   *  @var State DISABLED
   * A “disabled” state; corresponds to the
   * Gtk::Widget::property_sensitive() property. It indicates a UI element
   * that is perceivable, but not editable or operable. Value type: boolean.
   *
   *  @var State EXPANDED
   * An “expanded” state; corresponds to the
   * Gtk::Expander::property_expanded() property. Value type: boolean
   * or undefined.
   *
   *  @var State HIDDEN
   * A “hidden” state; corresponds to the
   * Gtk::Widget::property_visible() property. You can use this state
   * explicitly on UI elements that should not be exposed to an assistive
   * technology. Value type: boolean
   * See also: Gtk::Accessible::State::DISABLED.
   *
   *  @var State INVALID
   * An “invalid” state; set when a widget
   * is showing an error. Value type: Gtk::AccessibleInvalidState.
   *
   *  @var State PRESSED
   * A “pressed” state; indicates the current
   * state of a Gtk::ToggleButton. Value type: Gtk::AccessibleTristate
   * enumeration.
   *
   *  @var State SELECTED
   * A “selected” state; set when a widget
   * is selected. Value type: boolean or undefined.
   *
   *  @enum State
   *
   * The possible accessible states of a Gtk::Accessible.
   *
   * @ingroup gtkmmEnums
   */
  enum class State
  {
    BUSY,
    CHECKED,
    DISABLED,
    EXPANDED,
    HIDDEN,
    INVALID,
    PRESSED,
    SELECTED
  };


  /**
   *  @var Property AUTOCOMPLETE
   * Indicates whether inputting text
   * could trigger display of one or more predictions of the user's intended
   * value for a combobox, searchbox, or textbox and specifies how predictions
   * would be presented if they were made. Value type: Gtk::AccessibleAutocomplete.
   *
   *  @var Property DESCRIPTION
   * Defines a string value that describes
   * or annotates the current element. Value type: string.
   *
   *  @var Property HAS_POPUP
   * Indicates the availability and type of
   * interactive popup element, such as menu or dialog, that can be triggered
   * by an element.
   *
   *  @var Property KEY_SHORTCUTS
   * Indicates keyboard shortcuts that an
   * author has implemented to activate or give focus to an element. Value type:
   * string.
   *
   *  @var Property LABEL
   * Defines a string value that labels the current
   * element. Value type: string.
   *
   *  @var Property LEVEL
   * Defines the hierarchical level of an element
   * within a structure. Value type: integer.
   *
   *  @var Property MODAL
   * Indicates whether an element is modal when
   * displayed. Value type: boolean.
   *
   *  @var Property MULTI_LINE
   * Indicates whether a text box accepts
   * multiple lines of input or only a single line. Value type: boolean.
   *
   *  @var Property MULTI_SELECTABLE
   * Indicates that the user may select
   * more than one item from the current selectable descendants. Value type:
   * boolean.
   *
   *  @var Property ORIENTATION
   * Indicates whether the element's
   * orientation is horizontal, vertical, or unknown/ambiguous. Value type:
   * Gtk::Orientation.
   *
   *  @var Property PLACEHOLDER
   * Defines a short hint (a word or short
   * phrase) intended to aid the user with data entry when the control has no
   * value. A hint could be a sample value or a brief description of the expected
   * format. Value type: string.
   *
   *  @var Property READ_ONLY
   * Indicates that the element is not editable,
   * but is otherwise operable. Value type: boolean.
   *
   *  @var Property REQUIRED
   * Indicates that user input is required on
   * the element before a form may be submitted. Value type: boolean.
   *
   *  @var Property ROLE_DESCRIPTION
   * Defines a human-readable,
   * author-localized description for the role of an element. Value type: string.
   *
   *  @var Property SORT
   * Indicates if items in a table or grid are
   * sorted in ascending or descending order. Value type: Gtk::AccessibleSort.
   *
   *  @var Property VALUE_MAX
   * Defines the maximum allowed value for a
   * range widget. Value type: double.
   *
   *  @var Property VALUE_MIN
   * Defines the minimum allowed value for a
   * range widget. Value type: double.
   *
   *  @var Property VALUE_NOW
   * Defines the current value for a range widget.
   * Value type: double.
   *
   *  @var Property VALUE_TEXT
   * Defines the human readable text alternative
   * of aria-valuenow for a range widget. Value type: string.
   *
   *  @enum Property
   *
   * The possible accessible properties of a Gtk::Accessible.
   *
   * @ingroup gtkmmEnums
   */
  enum class Property
  {
    AUTOCOMPLETE,
    DESCRIPTION,
    HAS_POPUP,
    KEY_SHORTCUTS,
    LABEL,
    LEVEL,
    MODAL,
    MULTI_LINE,
    MULTI_SELECTABLE,
    ORIENTATION,
    PLACEHOLDER,
    READ_ONLY,
    REQUIRED,
    ROLE_DESCRIPTION,
    SORT,
    VALUE_MAX,
    VALUE_MIN,
    VALUE_NOW,
    VALUE_TEXT
  };


  /**
   *  @var Relation ACTIVE_DESCENDANT
   * Identifies the currently active
   * element when focus is on a composite widget, combobox, textbox, group,
   * or application. Value type: reference.
   *
   *  @var Relation COL_COUNT
   * Defines the total number of columns
   * in a table, grid, or treegrid. Value type: integer.
   *
   *  @var Relation COL_INDEX
   * Defines an element's column index or
   * position with respect to the total number of columns within a table,
   * grid, or treegrid. Value type: integer.
   *
   *  @var Relation COL_INDEX_TEXT
   * Defines a human readable text
   * alternative of Gtk::Accessible::Relation::COL_INDEX. Value type: string.
   *
   *  @var Relation COL_SPAN
   * Defines the number of columns spanned
   * by a cell or gridcell within a table, grid, or treegrid. Value type: integer.
   *
   *  @var Relation CONTROLS
   * Identifies the element (or elements) whose
   * contents or presence are controlled by the current element. Value type: reference.
   *
   *  @var Relation DESCRIBED_BY
   * Identifies the element (or elements)
   * that describes the object. Value type: reference.
   *
   *  @var Relation DETAILS
   * Identifies the element (or elements) that
   * provide additional information related to the object. Value type: reference.
   *
   *  @var Relation ERROR_MESSAGE
   * Identifies the element that provides
   * an error message for an object. Value type: reference.
   *
   *  @var Relation FLOW_TO
   * Identifies the next element (or elements)
   * in an alternate reading order of content which, at the user's discretion,
   * allows assistive technology to override the general default of reading in
   * document source order. Value type: reference.
   *
   *  @var Relation LABELLED_BY
   * Identifies the element (or elements)
   * that labels the current element. Value type: reference.
   *
   *  @var Relation OWNS
   * Identifies an element (or elements) in order
   * to define a visual, functional, or contextual parent/child relationship
   * between elements where the widget hierarchy cannot be used to represent
   * the relationship. Value type: reference.
   *
   *  @var Relation POS_IN_SET
   * Defines an element's number or position
   * in the current set of listitems or treeitems. Value type: integer.
   *
   *  @var Relation ROW_COUNT
   * Defines the total number of rows in a table,
   * grid, or treegrid. Value type: integer.
   *
   *  @var Relation ROW_INDEX
   * Defines an element's row index or position
   * with respect to the total number of rows within a table, grid, or treegrid.
   * Value type: integer.
   *
   *  @var Relation ROW_INDEX_TEXT
   * Defines a human readable text
   * alternative of aria-rowindex. Value type: string.
   *
   *  @var Relation ROW_SPAN
   * Defines the number of rows spanned by a
   * cell or gridcell within a table, grid, or treegrid. Value type: integer.
   *
   *  @var Relation SET_SIZE
   * Defines the number of items in the current
   * set of listitems or treeitems. Value type: integer.
   *
   *  @enum Relation
   *
   * The possible accessible relations of a Gtk::Accessible.
   *
   * Accessible relations can be references to other widgets,
   * integers or strings.
   *
   * @ingroup gtkmmEnums
   */
  enum class Relation
  {
    ACTIVE_DESCENDANT,
    COL_COUNT,
    COL_INDEX,
    COL_INDEX_TEXT,
    COL_SPAN,
    CONTROLS,
    DESCRIBED_BY,
    DETAILS,
    ERROR_MESSAGE,
    FLOW_TO,
    LABELLED_BY,
    OWNS,
    POS_IN_SET,
    ROW_COUNT,
    ROW_INDEX,
    ROW_INDEX_TEXT,
    ROW_SPAN,
    SET_SIZE
  };


  /** Retrieves the `Gtk::Accessible::Role` for the given `Gtk::Accessible`.
   *
   * @return A `Gtk::Accessible::Role`.
   */
  auto get_accessible_role() const -> Role;


  /** Updates an accessible state.
   *
   * This function should be called by Gtk::Widget types whenever an accessible
   * state change must be communicated to assistive technologies.
   *
   * @param state A Gtk::Accessible::State.
   * @param value A Glib::ValueBase.
   */
  void update_state(State state, const Glib::ValueBase& value);

  /** Updates an accessible property.
   *
   * This function should be called by Gtk::Widget types whenever an accessible
   * property change must be communicated to assistive technologies.
   *
   * @param property A Gtk::Accessible::Property.
   * @param value A Glib::ValueBase.
   */
  void update_property(Property property, const Glib::ValueBase& value);

  /** Updates an accessible relation.
   *
   * This function should be called by Gtk::Widget types whenever an accessible
   * relation change must be communicated to assistive technologies.
   *
   * @param relation A Gtk::Accessible::Relation.
   * @param value A Glib::ValueBase.
   */
  void update_relation(Relation relation, const Glib::ValueBase& value);


  /** Resets the accessible @a state to its default value.
   *
   * @param state A `Gtk::Accessible::State`.
   */
  void reset_state(State state);

  /** Resets the accessible @a property to its default value.
   *
   * @param property A `Gtk::Accessible::Property`.
   */
  void reset_property(Property property);

  /** Resets the accessible @a relation to its default value.
   *
   * @param relation A `Gtk::Accessible::Relation`.
   */
  void reset_relation(Relation relation);

  /** The accessible role of the given `Gtk::Accessible` implementation.
   *
   * The accessible role cannot be changed once set.
   *
   * Default value: Gtk::Accessible::Role::NONE
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_accessible_role() -> Glib::PropertyProxy< Role > ;

/** The accessible role of the given `Gtk::Accessible` implementation.
   *
   * The accessible role cannot be changed once set.
   *
   * Default value: Gtk::Accessible::Role::NONE
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_accessible_role() const -> Glib::PropertyProxy_ReadOnly< Role >;


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
class GTKMM_API Value<Gtk::Accessible::Role> : public Glib::Value_Enum<Gtk::Accessible::Role>
{
public:
  static auto value_type() -> GType G_GNUC_CONST;
};

} // namespace Glib
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

template <>
class GTKMM_API Value<Gtk::Accessible::State> : public Glib::Value_Enum<Gtk::Accessible::State>
{
public:
  static auto value_type() -> GType G_GNUC_CONST;
};

} // namespace Glib
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

template <>
class GTKMM_API Value<Gtk::Accessible::Property> : public Glib::Value_Enum<Gtk::Accessible::Property>
{
public:
  static auto value_type() -> GType G_GNUC_CONST;
};

} // namespace Glib
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

template <>
class GTKMM_API Value<Gtk::Accessible::Relation> : public Glib::Value_Enum<Gtk::Accessible::Relation>
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
   * @relates Gtk::Accessible
   */
  GTKMM_API
  auto wrap(GtkAccessible* object, bool take_copy = false) -> Glib::RefPtr<Gtk::Accessible>;

} // namespace Glib


#endif /* _GTKMM_ACCESSIBLE_H */

