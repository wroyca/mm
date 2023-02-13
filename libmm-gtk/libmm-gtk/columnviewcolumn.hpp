
#ifndef _GTKMM_COLUMNVIEWCOLUMN_H
#define _GTKMM_COLUMNVIEWCOLUMN_H

#include <mm/gtk/mm-gtkconfig.hpp>


#include <mm/glib/ustring.hpp>
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


#include <mm/glib/object.hpp>
#include <mm/gtk/listitemfactory.hpp>
#include <mm/gio/menumodel.hpp>
#include <mm/gtk/sorter.hpp>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkColumnViewColumn = struct _GtkColumnViewColumn;
using GtkColumnViewColumnClass = struct _GtkColumnViewColumnClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{ class GTKMM_API ColumnViewColumn_Class; } // namespace Gtk
#endif //DOXYGEN_SHOULD_SKIP_THIS

namespace Gtk
{
class GTKMM_API ColumnView;

/** The column added to Gtk::ColumnView.
 *
 * %Gtk::ColumnViewColumn represents the columns being added to Gtk::ColumnView.
 *
 * Columns have a title, and can optionally have a header menu set
 * with set_header_menu().
 *
 * A sorter can be associated with a column using set_sorter(), to let
 * users influence sorting by clicking on the column header.
 *
 * @see Gtk::ColumnView
 */

class GTKMM_API ColumnViewColumn : public Glib::Object
{

#ifndef DOXYGEN_SHOULD_SKIP_THIS

public:
  using CppObjectType = ColumnViewColumn;
  using CppClassType = ColumnViewColumn_Class;
  using BaseObjectType = GtkColumnViewColumn;
  using BaseClassType = GtkColumnViewColumnClass;

  // noncopyable
  ColumnViewColumn(const ColumnViewColumn&) = delete;
  auto operator=(const ColumnViewColumn&) -> ColumnViewColumn& = delete;

private:  friend class ColumnViewColumn_Class;
  static CppClassType columnviewcolumn_class_;

protected:
  explicit ColumnViewColumn(const Glib::ConstructParams& construct_params);
  explicit ColumnViewColumn(GtkColumnViewColumn* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  ColumnViewColumn(ColumnViewColumn&& src) noexcept;
  auto operator=(ColumnViewColumn&& src) noexcept -> ColumnViewColumn&;

  ~ColumnViewColumn() noexcept override;

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS


  static auto get_base_type() -> GType G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GObject.
  auto       gobj() -> GtkColumnViewColumn*       { return reinterpret_cast<GtkColumnViewColumn*>(gobject_); }

  ///Provides access to the underlying C GObject.
  auto gobj() const -> const GtkColumnViewColumn* { return reinterpret_cast<GtkColumnViewColumn*>(gobject_); }

  ///Provides access to the underlying C instance. The caller is responsible for unrefing it. Use when directly setting fields in structs.
  auto gobj_copy() -> GtkColumnViewColumn*;

private:


protected:
    explicit ColumnViewColumn(const Glib::ustring& title, const Glib::RefPtr<ListItemFactory>& factory =  {});


public:

  static auto create(const Glib::ustring& title, const Glib::RefPtr<ListItemFactory>& factory =  {}) -> Glib::RefPtr<ColumnViewColumn>;


  /** Gets the column view that's currently displaying this column.
   *
   * If @a self has not been added to a column view yet, <tt>nullptr</tt> is returned.
   *
   * @return The column view displaying @a self.
   */
  auto get_column_view() -> ColumnView*;

  /** Gets the column view that's currently displaying this column.
   *
   * If @a self has not been added to a column view yet, <tt>nullptr</tt> is returned.
   *
   * @return The column view displaying @a self.
   */
  auto get_column_view() const -> const ColumnView*;

  /** Sets the `Gtk::ListItemFactory` to use for populating list items for this
   * column.
   *
   * @param factory The factory to use.
   */
  void set_factory(const Glib::RefPtr<ListItemFactory>& factory);

  /** Gets the factory that's currently used to populate list items for
   * this column.
   *
   * @return The factory in use.
   */
  auto get_factory() -> Glib::RefPtr<ListItemFactory>;

  /** Gets the factory that's currently used to populate list items for
   * this column.
   *
   * @return The factory in use.
   */
  auto get_factory() const -> Glib::RefPtr<const ListItemFactory>;


  /** Sets the title of this column.
   *
   * The title is displayed in the header of a `Gtk::ColumnView`
   * for this column and is therefore user-facing text that should
   * be translated.
   *
   * @param title Title to use for this column.
   */
  void set_title(const Glib::ustring& title);

  /** Returns the title set with set_title().
   *
   * @return The column's title.
   */
  auto get_title() const -> Glib::ustring;


  /** Associates a sorter with the column.
   *
   * If @a sorter is <tt>nullptr</tt>, the column will not let users change
   * the sorting by clicking on its header.
   *
   * This sorter can be made active by clicking on the column
   * header, or by calling sort_by_column().
   *
   * See get_sorter() for the necessary steps
   * for setting up customizable sorting for Gtk::ColumnView.
   *
   * @param sorter The `Gtk::Sorter` to associate with @a column.
   */
  void set_sorter(const Glib::RefPtr<Sorter>& sorter);

  /** Returns the sorter that is associated with the column.
   *
   * @return The `Gtk::Sorter` of @a self.
   */
  auto get_sorter() -> Glib::RefPtr<Sorter>;

  /** Returns the sorter that is associated with the column.
   *
   * @return The `Gtk::Sorter` of @a self.
   */
  auto get_sorter() const -> Glib::RefPtr<const Sorter>;


  /** Sets whether this column should be visible in views.
   *
   * @param visible Whether this column should be visible.
   */
  void set_visible(bool visible =  true);

  /** Returns whether this column is visible.
   *
   * @return <tt>true</tt> if this column is visible.
   */
  auto get_visible() const -> bool;


  /** Sets the menu model that is used to create the context menu
   * for the column header.
   *
   * @param model A `Gio::MenuModel`.
   */
  void set_header_menu(const Glib::RefPtr<Gio::MenuModel>& model);

  /** Gets the menu model that is used to create the context menu
   * for the column header.
   *
   * @return The `Gio::MenuModel`.
   */
  auto get_header_menu() -> Glib::RefPtr<Gio::MenuModel>;

  /** Gets the menu model that is used to create the context menu
   * for the column header.
   *
   * @return The `Gio::MenuModel`.
   */
  auto get_header_menu() const -> Glib::RefPtr<const Gio::MenuModel>;


  /** If @a fixed_width is not -1, sets the fixed width of @a column;
   * otherwise unsets it.
   *
   * Setting a fixed width overrides the automatically calculated
   * width. Interactive resizing also sets the “fixed-width” property.
   *
   * @param fixed_width The new fixed width, or -1.
   */
  void set_fixed_width(int fixed_width);

  /** Gets the fixed width of the column.
   *
   * @return The fixed with of the column.
   */
  auto get_fixed_width() const -> int;


  /** Sets whether this column should be resizable by dragging.
   *
   * @param resizable Whether this column should be resizable.
   */
  void set_resizable(bool resizable =  true);

  /** Returns whether this column is resizable.
   *
   * @return <tt>true</tt> if this column is resizable.
   */
  auto get_resizable() const -> bool;


  /** Sets the column to take available extra space.
   *
   * The extra space is shared equally amongst all columns that
   * have the expand set to <tt>true</tt>.
   *
   * @param expand <tt>true</tt> if this column should expand to fill available sace.
   */
  void set_expand(bool expand =  true);

  /** Returns whether this column should expand.
   *
   * @return <tt>true</tt> if this column expands.
   */
  auto get_expand() const -> bool;

  /** The `Gtk::ColumnView` this column is a part of.
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_column_view() const -> Glib::PropertyProxy_ReadOnly< ColumnView* >;


  /** Factory for populating list items.
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_factory() -> Glib::PropertyProxy< Glib::RefPtr<ListItemFactory> > ;

/** Factory for populating list items.
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_factory() const -> Glib::PropertyProxy_ReadOnly< Glib::RefPtr<ListItemFactory> >;

  /** Title displayed in the header.
   *
   * Default value: ""
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_title() -> Glib::PropertyProxy< Glib::ustring > ;

/** Title displayed in the header.
   *
   * Default value: ""
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_title() const -> Glib::PropertyProxy_ReadOnly< Glib::ustring >;

  /** Sorter for sorting items according to this column.
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_sorter() -> Glib::PropertyProxy< Glib::RefPtr<Sorter> > ;

/** Sorter for sorting items according to this column.
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_sorter() const -> Glib::PropertyProxy_ReadOnly< Glib::RefPtr<Sorter> >;

  /** Whether this column is visible.
   *
   * Default value: <tt>true</tt>
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_visible() -> Glib::PropertyProxy< bool > ;

/** Whether this column is visible.
   *
   * Default value: <tt>true</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_visible() const -> Glib::PropertyProxy_ReadOnly< bool >;

  /** Menu model used to create the context menu for the column header.
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_header_menu() -> Glib::PropertyProxy< Glib::RefPtr<Gio::MenuModel> > ;

/** Menu model used to create the context menu for the column header.
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_header_menu() const -> Glib::PropertyProxy_ReadOnly< Glib::RefPtr<Gio::MenuModel> >;

  /** Whether this column is resizable.
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_resizable() -> Glib::PropertyProxy< bool > ;

/** Whether this column is resizable.
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_resizable() const -> Glib::PropertyProxy_ReadOnly< bool >;

  /** Column gets share of extra width allocated to the view.
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_expand() -> Glib::PropertyProxy< bool > ;

/** Column gets share of extra width allocated to the view.
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_expand() const -> Glib::PropertyProxy_ReadOnly< bool >;

  /** If not -1, this is the width that the column is allocated,
   * regardless of the size of its content.
   *
   * Default value: -1
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_fixed_width() -> Glib::PropertyProxy< int > ;

/** If not -1, this is the width that the column is allocated,
   * regardless of the size of its content.
   *
   * Default value: -1
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_fixed_width() const -> Glib::PropertyProxy_ReadOnly< int >;


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
   * @relates Gtk::ColumnViewColumn
   */
  GTKMM_API
  auto wrap(GtkColumnViewColumn* object, bool take_copy = false) -> Glib::RefPtr<Gtk::ColumnViewColumn>;
}


#endif /* _GTKMM_COLUMNVIEWCOLUMN_H */

