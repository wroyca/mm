
#ifndef _GTKMM_TREELISTMODEL_H
#define _GTKMM_TREELISTMODEL_H

#include <libmm-gtk/mm-gtkconfig.hpp>


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


#include <libmm-glib/object.hpp>
#include <libmm-gio/listmodel.hpp>
#include <libmm-gtk/treelistrow.hpp>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{ class GTKMM_API TreeListModel_Class; } // namespace Gtk
#endif //DOXYGEN_SHOULD_SKIP_THIS

namespace Gtk
{

/** A list model that can create child models on demand.
 *
 * %Gtk::TreeListModel is a Gio::ListModel implementation that can expand rows
 * by creating new child list models on demand.
 *
 * @see Gio::ListModel
 *
 * @newin{3,98}
 */

class GTKMM_API TreeListModel : public Glib::Object, public Gio::ListModel
{

#ifndef DOXYGEN_SHOULD_SKIP_THIS

public:
  using CppObjectType = TreeListModel;
  using CppClassType = TreeListModel_Class;
  using BaseObjectType = GtkTreeListModel;
  using BaseClassType = GtkTreeListModelClass;

  // noncopyable
  TreeListModel(const TreeListModel&) = delete;
  auto operator=(const TreeListModel&) -> TreeListModel& = delete;

private:  friend class TreeListModel_Class;
  static CppClassType treelistmodel_class_;

protected:
  explicit TreeListModel(const Glib::ConstructParams& construct_params);
  explicit TreeListModel(GtkTreeListModel* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  TreeListModel(TreeListModel&& src) noexcept;
  auto operator=(TreeListModel&& src) noexcept -> TreeListModel&;

  ~TreeListModel() noexcept override;

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS


  static auto get_base_type() -> GType G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GObject.
  auto       gobj() -> GtkTreeListModel*       { return reinterpret_cast<GtkTreeListModel*>(gobject_); }

  ///Provides access to the underlying C GObject.
  auto gobj() const -> const GtkTreeListModel* { return reinterpret_cast<GtkTreeListModel*>(gobject_); }

  ///Provides access to the underlying C instance. The caller is responsible for unrefing it. Use when directly setting fields in structs.
  auto gobj_copy() -> GtkTreeListModel*;

private:


public:

  /** For instance:
   * Glib::RefPtr<Gio::ListModel> create_func(const Glib::RefPtr<Glib::ObjectBase>& item);
   *
   * Prototype of the function called to create new child models when
   * Gtk::TreeListRow::set_expanded() is called.
   *
   * This function can return <tt>nullptr</tt> to indicate that @a item is
   * guaranteed to be a leaf node and will never have children.
   * If it does not have children but may get children later, it should return
   * an empty model that is filled once children arrive.
   *
   * @param item The item that is being expanded.
   *
   * @return The model tracking the children of @a item or <tt>nullptr</tt> if
   * @a item can never have children.
   */
  using SlotCreateModel = sigc::slot<Glib::RefPtr<Gio::ListModel>(const Glib::RefPtr<Glib::ObjectBase>&)>;

protected:

  TreeListModel(const Glib::RefPtr<Gio::ListModel>& root, const SlotCreateModel& slot_create, bool passthrough = false, bool autoexpand = false);

public:

  /** Creates a new empty %Gtk::TreeListModel displaying @a root with
   * all rows collapsed.
   *
   * @param root The Gio::ListModel to use as root.
   * @param slot_create Slot to call to create the Gio::ListModel for
   * the children of an item.
   * @param passthrough <tt>true</tt> to pass through items from the models.
   * @param autoexpand <tt>true</tt> to set the autoexpand property and
   * expand the @a root model.
   */

  static auto create(const Glib::RefPtr<Gio::ListModel>& root, const SlotCreateModel& slot_create, bool passthrough =  false, bool autoexpand =  false) -> Glib::RefPtr<TreeListModel>;


  /** Gets the root model that @a self was created with.
   *
   * @return The root model.
   */
  auto get_model() -> Glib::RefPtr<Gio::ListModel>;

  /** Gets the root model that @a self was created with.
   *
   * @return The root model.
   */
  auto get_model() const -> Glib::RefPtr<const Gio::ListModel>;

  /** Gets whether the model is passing through original row items.
   *
   * If this function returns <tt>false</tt>, the `Gio::ListModel` functions for @a self
   * return custom `Gtk::TreeListRow` objects. You need to call
   * Gtk::TreeListRow::get_item() on these objects to get the original
   * item.
   *
   * If <tt>true</tt>, the values of the child models are passed through in their
   * original state. You then need to call get_row()
   * to get the custom `Gtk::TreeListRow`s.
   *
   * @return <tt>true</tt> if the model is passing through original row items.
   */
  auto get_passthrough() const -> bool;

  /** Sets whether the model should autoexpand.
   *
   * If set to <tt>true</tt>, the model will recursively expand all rows that
   * get added to the model. This can be either rows added by changes
   * to the underlying models or via Gtk::TreeListRow::set_expanded().
   *
   * @param autoexpand <tt>true</tt> to make the model autoexpand its rows.
   */
  void set_autoexpand(bool autoexpand =  true);

  /** Gets whether the model is set to automatically expand new rows
   * that get added.
   *
   * This can be either rows added by changes to the underlying
   * models or via Gtk::TreeListRow::set_expanded().
   *
   * @return <tt>true</tt> if the model is set to autoexpand.
   */
  auto get_autoexpand() const -> bool;


  /** Gets the row item corresponding to the child at index @a position for
   *  @a self's root model.
   *
   * If @a position is greater than the number of children in the root model,
   * <tt>nullptr</tt> is returned.
   *
   * Do not confuse this function with get_row().
   *
   * @param position Position of the child to get.
   * @return The child in @a position.
   */
  auto get_child_row(guint position) -> Glib::RefPtr<TreeListRow>;

  /** Gets the row item corresponding to the child at index @a position for
   *  @a self's root model.
   *
   * If @a position is greater than the number of children in the root model,
   * <tt>nullptr</tt> is returned.
   *
   * Do not confuse this function with get_row().
   *
   * @param position Position of the child to get.
   * @return The child in @a position.
   */
  auto get_child_row(guint position) const -> Glib::RefPtr<const TreeListRow>;

  /** Gets the row object for the given row.
   *
   * If @a position is greater than the number of items in @a self,
   * <tt>nullptr</tt> is returned.
   *
   * The row object can be used to expand and collapse rows as
   * well as to inspect its position in the tree. See its
   * documentation for details.
   *
   * This row object is persistent and will refer to the current
   * item as long as the row is present in @a self, independent of
   * other rows being added or removed.
   *
   * If @a self is set to not be passthrough, this function is
   * equivalent to calling Glib::list_model_get_item().
   *
   * Do not confuse this function with get_child_row().
   *
   * @param position The position of the row to fetch.
   * @return The row item.
   */
  auto get_row(guint position) -> Glib::RefPtr<TreeListRow>;

  /** Gets the row object for the given row.
   *
   * If @a position is greater than the number of items in @a self,
   * <tt>nullptr</tt> is returned.
   *
   * The row object can be used to expand and collapse rows as
   * well as to inspect its position in the tree. See its
   * documentation for details.
   *
   * This row object is persistent and will refer to the current
   * item as long as the row is present in @a self, independent of
   * other rows being added or removed.
   *
   * If @a self is set to not be passthrough, this function is
   * equivalent to calling Glib::list_model_get_item().
   *
   * Do not confuse this function with get_child_row().
   *
   * @param position The position of the row to fetch.
   * @return The row item.
   */
  auto get_row(guint position) const -> Glib::RefPtr<const TreeListRow>;

  /** If all rows should be expanded by default.
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_autoexpand() -> Glib::PropertyProxy< bool > ;

/** If all rows should be expanded by default.
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_autoexpand() const -> Glib::PropertyProxy_ReadOnly< bool >;

  /** The type of items. See Gio::ListModel::get_item_type().
   *
   * @newin{4,8}
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_item_type() const -> Glib::PropertyProxy_ReadOnly< GType >;


  /** The root model displayed.
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_model() const -> Glib::PropertyProxy_ReadOnly< Glib::RefPtr<Gio::ListModel> >;


  /** The number of items. See Gio::ListModel::get_n_items().
   *
   * @newin{4,8}
   *
   * Default value: 0
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_n_items() const -> Glib::PropertyProxy_ReadOnly< unsigned int >;


  /** Gets whether the model is in passthrough mode.
   *
   * If <tt>false</tt>, the `Gio::ListModel` functions for this object return custom
   * Gtk::TreeListRow objects. If <tt>true</tt>, the values of the child
   * models are pass through unmodified.
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_passthrough() const -> Glib::PropertyProxy_ReadOnly< bool >;


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
   * @relates Gtk::TreeListModel
   */
  GTKMM_API
  auto wrap(GtkTreeListModel* object, bool take_copy = false) -> Glib::RefPtr<Gtk::TreeListModel>;
}


#endif /* _GTKMM_TREELISTMODEL_H */

