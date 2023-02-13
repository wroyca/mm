
#ifndef _GTKMM_DROPDOWN_H
#define _GTKMM_DROPDOWN_H


#include <libmm-glib/ustring.hpp>
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

#include <libmm-gio/listmodel.hpp>
#include <libmm-gtk/listitemfactory.hpp>
#include <libmm-gtk/expression.hpp>
#include <libmm-gtk/widget.hpp>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{ class GTKMM_API DropDown_Class; } // namespace Gtk
#endif //DOXYGEN_SHOULD_SKIP_THIS

namespace Gtk
{

/** Choose an item from a list.
 *
 * %Gtk::DropDown is a widget that allows the user to choose an item
 * from a list of options. The %Gtk::DropDown displays the selected
 * choice.
 *
 * The options are given to %Gtk::DropDown in the form of Gio::ListModel,
 * and how the individual options are represented is determined by
 * a Gtk::ListItemFactory. The default factory displays simple strings.
 *
 * %Gtk::DropDown knows how to obtain strings from the items in a
 * Gtk::StringList; for other models, you have to provide an expression
 * to find the strings via set_expression().
 *
 * %Gtk::DropDown can optionally allow search in the popup, which is
 * useful if the list of options is long. To enable the search entry,
 * use set_enable_search().
 *
 * @par CSS nodes
 * %Gtk::DropDown has a single CSS node with name dropdown,
 * with the button and popover nodes as children.
 *
 * @see Gtk::ComboBox
 *
 * @ingroup Widgets
 *
 * @newin{3,98}
 */

class GTKMM_API DropDown : public Widget
{
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  typedef DropDown CppObjectType;
  typedef DropDown_Class CppClassType;
  typedef GtkDropDown BaseObjectType;
  typedef GtkDropDownClass BaseClassType;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

  DropDown(DropDown&& src) noexcept;
  auto operator=(DropDown&& src) noexcept -> DropDown&;

  // noncopyable
  DropDown(const DropDown&) = delete;
  auto operator=(const DropDown&) -> DropDown& = delete;

  ~DropDown() noexcept override;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

private:
  friend GTKMM_API class DropDown_Class;
  static CppClassType dropdown_class_;

protected:
  explicit DropDown(const Glib::ConstructParams& construct_params);
  explicit DropDown(GtkDropDown* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS


  static auto get_base_type() -> GType G_GNUC_CONST;
#endif

  /// Provides access to the underlying C GObject.
  auto       gobj() -> GtkDropDown*       { return reinterpret_cast<GtkDropDown*>(gobject_); }

  /// Provides access to the underlying C GObject.
  auto gobj() const -> const GtkDropDown* { return reinterpret_cast<GtkDropDown*>(gobject_); }

private:


public:
    explicit DropDown(const Glib::RefPtr<Gio::ListModel>& model =  {}, const Glib::RefPtr<Expression<Glib::ustring>>& expression =  {});


  /** Creates a new %DropDown that is populated with the strings in @a strings.
   *
   * @param strings The strings to put in the dropdown.
   */
  explicit DropDown(const std::vector<Glib::ustring>& strings);


  /** Sets the `Gio::ListModel` to use.
   *
   * @param model The model to use.
   */
  void set_model(const Glib::RefPtr<Gio::ListModel>& model);

  /** Gets the model that provides the displayed items.
   *
   * @return The model in use.
   */
  auto get_model() -> Glib::RefPtr<Gio::ListModel>;

  /** Gets the model that provides the displayed items.
   *
   * @return The model in use.
   */
  auto get_model() const -> Glib::RefPtr<const Gio::ListModel>;

  /** Selects the item at the given position.
   *
   * @param position The position of the item to select, or GTK_INVALID_LIST_POSITION.
   */
  void set_selected(guint position);

  /** Gets the position of the selected item.
   *
   * @return The position of the selected item, or GTK_INVALID_LIST_POSITION
   * if not item is selected.
   */
  auto get_selected() const -> guint;


  /** Gets the selected item. If no item is selected, <tt>nullptr</tt> is returned.
   *
   * @return The selected item.
   */
  auto get_selected_item() -> Glib::RefPtr<Glib::ObjectBase>;

  /** Gets the selected item. If no item is selected, <tt>nullptr</tt> is returned.
   *
   * @return The selected item.
   */
  auto get_selected_item() const -> Glib::RefPtr<const Glib::ObjectBase>;


  /** Sets the `Gtk::ListItemFactory` to use for populating list items.
   *
   * @param factory The factory to use.
   */
  void set_factory(const Glib::RefPtr<ListItemFactory>& factory);

  /** Gets the factory that's currently used to populate list items.
   *
   * The factory returned by this function is always used for the
   * item in the button. It is also used for items in the popup
   * if property_list_factory() is not set.
   *
   * @return The factory in use.
   */
  auto get_factory() -> Glib::RefPtr<ListItemFactory>;

  /** Gets the factory that's currently used to populate list items.
   *
   * The factory returned by this function is always used for the
   * item in the button. It is also used for items in the popup
   * if property_list_factory() is not set.
   *
   * @return The factory in use.
   */
  auto get_factory() const -> Glib::RefPtr<const ListItemFactory>;

  /** Sets the `Gtk::ListItemFactory` to use for populating list items in the popup.
   *
   * @param factory The factory to use.
   */
  void set_list_factory(const Glib::RefPtr<ListItemFactory>& factory);

  /** Gets the factory that's currently used to populate list items in the popup.
   *
   * @return The factory in use.
   */
  auto get_list_factory() -> Glib::RefPtr<ListItemFactory>;

  /** Gets the factory that's currently used to populate list items in the popup.
   *
   * @return The factory in use.
   */
  auto get_list_factory() const -> Glib::RefPtr<const ListItemFactory>;

  /** Sets the expression that gets evaluated to obtain strings from items.
   *
   * This is used for search in the popup. The expression must have
   * a value type of G_TYPE_STRING.
   *
   * @param expression A `Gtk::Expression`.
   */
  void set_expression(const Glib::RefPtr<Expression<Glib::ustring>>& expression);

  /** Gets the expression set that is used to obtain strings from items.
   *
   * See set_expression().
   *
   * @return A `Gtk::Expression`.
   */
  auto get_expression() -> Glib::RefPtr<Expression<Glib::ustring>>;

  /** Gets the expression set that is used to obtain strings from items.
   *
   * See set_expression().
   *
   * @return A `Gtk::Expression`.
   */
  auto get_expression() const -> Glib::RefPtr<const Expression<Glib::ustring>>;


  /** Sets whether a search entry will be shown in the popup that
   * allows to search for items in the list.
   *
   * Note that property_expression() must be set for
   * search to work.
   *
   * @param enable_search Whether to enable search.
   */
  void set_enable_search(bool enable_search =  true);

  /** Returns whether search is enabled.
   *
   * @return <tt>true</tt> if the popup includes a search entry.
   */
  auto get_enable_search() const -> bool;

  /** Sets whether an arrow will be displayed within the widget.
   *
   * @newin{4,6}
   *
   * @param show_arrow Whether to show an arrow within the widget.
   */
  void set_show_arrow(bool show_arrow =  true);

  /** Returns whether to show an arrow within the widget.
   *
   * @newin{4,6}
   *
   * @return <tt>true</tt> if an arrow will be shown.
   */
  auto set_show_arrow() const -> bool;

  // Action signal:


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

  /** The factory for populating list items in the popup.
   *
   * If this is not set, property_factory() is used.
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_list_factory() -> Glib::PropertyProxy< Glib::RefPtr<ListItemFactory> > ;

/** The factory for populating list items in the popup.
   *
   * If this is not set, property_factory() is used.
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_list_factory() const -> Glib::PropertyProxy_ReadOnly< Glib::RefPtr<ListItemFactory> >;

  /** Model for the displayed items.
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_model() -> Glib::PropertyProxy< Glib::RefPtr<Gio::ListModel> > ;

/** Model for the displayed items.
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_model() const -> Glib::PropertyProxy_ReadOnly< Glib::RefPtr<Gio::ListModel> >;

  /** The position of the selected item.
   *
   * If no item is selected, the property has the value
   * GTK_INVALID_LIST_POSITION.
   *
   * Default value: 4294967295
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_selected() -> Glib::PropertyProxy< guint > ;

/** The position of the selected item.
   *
   * If no item is selected, the property has the value
   * GTK_INVALID_LIST_POSITION.
   *
   * Default value: 4294967295
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_selected() const -> Glib::PropertyProxy_ReadOnly< guint >;

  /** The selected item.
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_selected_item() const -> Glib::PropertyProxy_ReadOnly< Glib::RefPtr<Glib::ObjectBase> >;


  /** Whether to show a search entry in the popup.
   *
   * Note that search requires property_expression()
   * to be set.
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_enable_search() -> Glib::PropertyProxy< bool > ;

/** Whether to show a search entry in the popup.
   *
   * Note that search requires property_expression()
   * to be set.
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_enable_search() const -> Glib::PropertyProxy_ReadOnly< bool >;

  /** An expression to evaluate to obtain strings to match against the search
   * term.
   *
   * See property_enable_search() for how to enable search.
   * If property_factory() is not set, the expression is also
   * used to bind strings to labels produced by a default factory.
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_expression() -> Glib::PropertyProxy< Glib::RefPtr<Expression<Glib::ustring>> > ;

/** An expression to evaluate to obtain strings to match against the search
   * term.
   *
   * See property_enable_search() for how to enable search.
   * If property_factory() is not set, the expression is also
   * used to bind strings to labels produced by a default factory.
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_expression() const -> Glib::PropertyProxy_ReadOnly< Glib::RefPtr<Expression<Glib::ustring>> >;

  /** Whether to show an arrow within the GtkDropDown widget.
   *
   * @newin{4,6}
   *
   * Default value: <tt>true</tt>
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_show_arrow() -> Glib::PropertyProxy< bool > ;

/** Whether to show an arrow within the GtkDropDown widget.
   *
   * @newin{4,6}
   *
   * Default value: <tt>true</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_show_arrow() const -> Glib::PropertyProxy_ReadOnly< bool >;


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
   * @relates Gtk::DropDown
   */
  GTKMM_API
  auto wrap(GtkDropDown* object, bool take_copy = false) -> Gtk::DropDown*;
} //namespace Glib


#endif /* _GTKMM_DROPDOWN_H */

