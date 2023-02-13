
#ifndef _GTKMM_LISTBOXROW_H
#define _GTKMM_LISTBOXROW_H


#include <mm/glib/ustring.hpp>
#include <sigc++/sigc++.h>

/* Copyright (C) 2013 The gtkmm Development Team
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

#include <mm/gtk/widget.hpp>
#include <mm/gtk/actionable.hpp>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkListBoxRow = struct _GtkListBoxRow;
using GtkListBoxRowClass = struct _GtkListBoxRowClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{ class GTKMM_API ListBoxRow_Class; } // namespace Gtk
#endif //DOXYGEN_SHOULD_SKIP_THIS

namespace Gtk
{

/** See the description of ListBox.
 *
 * @ingroup Widgets
 * @ingroup Containers
 *
 * @newin{3,10}
 */

class GTKMM_API ListBoxRow : public Widget, public Actionable
{
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  typedef ListBoxRow CppObjectType;
  typedef ListBoxRow_Class CppClassType;
  typedef GtkListBoxRow BaseObjectType;
  typedef GtkListBoxRowClass BaseClassType;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

  ListBoxRow(ListBoxRow&& src) noexcept;
  auto operator=(ListBoxRow&& src) noexcept -> ListBoxRow&;

  // noncopyable
  ListBoxRow(const ListBoxRow&) = delete;
  auto operator=(const ListBoxRow&) -> ListBoxRow& = delete;

  ~ListBoxRow() noexcept override;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

private:
  friend GTKMM_API class ListBoxRow_Class;
  static CppClassType listboxrow_class_;

protected:
  explicit ListBoxRow(const Glib::ConstructParams& construct_params);
  explicit ListBoxRow(GtkListBoxRow* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS


  static auto get_base_type() -> GType G_GNUC_CONST;
#endif

  /// Provides access to the underlying C GObject.
  auto       gobj() -> GtkListBoxRow*       { return reinterpret_cast<GtkListBoxRow*>(gobject_); }

  /// Provides access to the underlying C GObject.
  auto gobj() const -> const GtkListBoxRow* { return reinterpret_cast<GtkListBoxRow*>(gobject_); }

private:


public:
  ListBoxRow();


  /** Sets the child widget of @a self.
   *
   * @param child The child widget.
   */
  void set_child(Widget& child);
  void unset_child();

  /** Gets the child widget of @a row.
   *
   * @return The child widget of @a row.
   */
  auto get_child() -> Widget*;

  /** Gets the child widget of @a row.
   *
   * @return The child widget of @a row.
   */
  auto get_child() const -> const Widget*;


  /** Sets the current header of the ListBoxRow. This is only allowed to be called
   * from a ListBox::SlotUpdateHeader. It will replace any existing
   * header in the row, and be shown in front of the row in the ListBox.
   *
   * @newin{3,10}
   *
   * @param header The header.
   */
  void set_header(Widget& header);

  /** Removes the current header, if any. This is only allowed to be called
   * from a ListBox::SlotUpdateHeader.
   *
   * @newin{3,10}
   */
  void unset_header();


  /** Returns the current header of the ListBoxRow. This can be used
   * in a ListBox::SlotUpdateHeader to see if there is a header
   * set already, and if so to update the state of it.
   *
   * @newin{3,10}
   *
   * @return The current header, or <tt>0</tt> if none.
   */
  auto get_header() -> Widget*;


  /** Returns the current header of the ListBoxRow. This can be used
   * in a ListBox::SlotUpdateHeader to see if there is a header
   * set already, and if so to update the state of it.
   *
   * @newin{3,10}
   *
   * @return The current header, or <tt>0</tt> if none.
   */
  auto get_header() const -> const Widget*;


  /** Gets the current index of the @a row in its `Gtk::ListBox` container.
   *
   * @return The index of the @a row, or -1 if the @a row is not in a listbox.
   */
  auto get_index() const -> int;

  /** Marks @a row as changed, causing any state that depends on this
   * to be updated.
   *
   * This affects sorting, filtering and headers.
   *
   * Note that calls to this method must be in sync with the data
   * used for the row functions. For instance, if the list is
   * mirroring some external data set, and *two* rows changed in the
   * external data set then when you call changed()
   * on the first row the sort function must only read the new data
   * for the first of the two changed rows, otherwise the resorting
   * of the rows will be wrong.
   *
   * This generally means that if you don’t fully control the data
   * model you have to duplicate the data that affects the listbox
   * row functions into the row widgets themselves. Another alternative
   * is to call invalidate_sort() on any model change,
   * but that is more expensive.
   */
  void changed();


  /** Returns whether the child is currently selected in its
   * `Gtk::ListBox` container.
   *
   * @return <tt>true</tt> if @a row is selected.
   */
  auto is_selected() const -> bool;


  /** Set whether the row can be selected.
   *
   * @param selectable <tt>true</tt> to mark the row as selectable.
   */
  void set_selectable(bool selectable =  true);

  /** Gets whether the row can be selected.
   *
   * @return <tt>true</tt> if the row is selectable.
   */
  auto get_selectable() const -> bool;


  /** Set whether the row is activatable.
   *
   * @param activatable <tt>true</tt> to mark the row as activatable.
   */
  void set_activatable(bool activatable =  true);

  /** Gets whether the row is activatable.
   *
   * @return <tt>true</tt> if the row is activatable.
   */
  auto get_activatable() const -> bool;

  /** Determines whether this row can be selected.
   *
   * Default value: <tt>true</tt>
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_selectable() -> Glib::PropertyProxy< bool > ;

/** Determines whether this row can be selected.
   *
   * Default value: <tt>true</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_selectable() const -> Glib::PropertyProxy_ReadOnly< bool >;

  /** Determines whether the signal_row_activated()
   * signal will be emitted for this row.
   *
   * Default value: <tt>true</tt>
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_activatable() -> Glib::PropertyProxy< bool > ;

/** Determines whether the signal_row_activated()
   * signal will be emitted for this row.
   *
   * Default value: <tt>true</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_activatable() const -> Glib::PropertyProxy_ReadOnly< bool >;

  /** The child widget.
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_child() -> Glib::PropertyProxy< Widget* > ;

/** The child widget.
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_child() const -> Glib::PropertyProxy_ReadOnly< Widget* >;


   // Action signal


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
   * @relates Gtk::ListBoxRow
   */
  GTKMM_API
  auto wrap(GtkListBoxRow* object, bool take_copy = false) -> Gtk::ListBoxRow*;
} //namespace Glib


#endif /* _GTKMM_LISTBOXROW_H */

