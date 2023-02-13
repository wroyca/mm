
#ifndef _GTKMM_SINGLESELECTION_H
#define _GTKMM_SINGLESELECTION_H


#include <mm/glib/ustring.hpp>
#include <sigc++/sigc++.h>

/* Copyright (C) 2019 The gtkmm Development Team
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
#include <mm/glib/refptr.hpp>
#include <mm/gio/listmodel.hpp>
#include <mm/gtk/selectionmodel.hpp>
#include <gtk/gtk.h> // Declares GtkSingleSelection and GtkSingleSelectionClass


#ifndef DOXYGEN_SHOULD_SKIP_THIS
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{ class GTKMM_API SingleSelection_Class; } // namespace Gtk
#endif //DOXYGEN_SHOULD_SKIP_THIS

namespace Gtk
{
/** A selection model that allows selecting a single item.
 *
 * %Gtk::SingleSelection is an implementation of the Gtk::SelectionModel interface
 * that allows selecting a single element. It is the default selection method
 * used by list widgets in GTK.
 *
 * Note that the selection is *persistent* -- if the selected item is removed
 * and re-added in the same Gio::ListModel::signal_items_changed() emission,
 * it stays selected. In particular, this means that changing the sort order
 * of an underlying sort model will preserve the selection.
 *
 * @see SelectionModel
 * @newin{3,96}
 */

class GTKMM_API SingleSelection : public Glib::Object, public Gio::ListModel, public SelectionModel
{

#ifndef DOXYGEN_SHOULD_SKIP_THIS

public:
  using CppObjectType = SingleSelection;
  using CppClassType = SingleSelection_Class;
  using BaseObjectType = GtkSingleSelection;
  using BaseClassType = GtkSingleSelectionClass;

  // noncopyable
  SingleSelection(const SingleSelection&) = delete;
  auto operator=(const SingleSelection&) -> SingleSelection& = delete;

private:  friend class SingleSelection_Class;
  static CppClassType singleselection_class_;

protected:
  explicit SingleSelection(const Glib::ConstructParams& construct_params);
  explicit SingleSelection(GtkSingleSelection* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  SingleSelection(SingleSelection&& src) noexcept;
  auto operator=(SingleSelection&& src) noexcept -> SingleSelection&;

  ~SingleSelection() noexcept override;

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS


  static auto get_base_type() -> GType G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GObject.
  auto       gobj() -> GtkSingleSelection*       { return reinterpret_cast<GtkSingleSelection*>(gobject_); }

  ///Provides access to the underlying C GObject.
  auto gobj() const -> const GtkSingleSelection* { return reinterpret_cast<GtkSingleSelection*>(gobject_); }

  ///Provides access to the underlying C instance. The caller is responsible for unrefing it. Use when directly setting fields in structs.
  auto gobj_copy() -> GtkSingleSelection*;

private:


protected:
  SingleSelection();
    explicit SingleSelection(const Glib::RefPtr<Gio::ListModel>& model);


public:

  static auto create() -> Glib::RefPtr<SingleSelection>;


  static auto create(const Glib::RefPtr<Gio::ListModel>& model) -> Glib::RefPtr<SingleSelection>;


  /** Gets the model that @a self is wrapping.
   *
   * @return The model being wrapped.
   */
  auto get_model() -> Glib::RefPtr<Gio::ListModel>;

  /** Gets the model that @a self is wrapping.
   *
   * @return The model being wrapped.
   */
  auto get_model() const -> Glib::RefPtr<const Gio::ListModel>;

  /** Sets the model that @a self should wrap.
   *
   * If @a model is <tt>nullptr</tt>, @a self will be empty.
   *
   * @param model A `Gio::ListModel` to wrap.
   */
  void set_model(const Glib::RefPtr<Gio::ListModel>& model);


  /** Gets the position of the selected item.
   *
   * If no item is selected, GTK_INVALID_LIST_POSITION is returned.
   *
   * @return The position of the selected item.
   */
  auto get_selected() const -> guint;

  /** Selects the item at the given position.
   *
   * If the list does not have an item at @a position or
   * GTK_INVALID_LIST_POSITION is given, the behavior depends on the
   * value of the property_autoselect() property:
   * If it is set, no change will occur and the old item will stay
   * selected. If it is unset, the selection will be unset and no item
   * will be selected.
   *
   * @param position The item to select or GTK_INVALID_LIST_POSITION.
   */
  void set_selected(guint position);


  /** Gets the selected item.
   *
   * If no item is selected, <tt>nullptr</tt> is returned.
   *
   * @return The selected item.
   */
  auto get_selected_item() -> Glib::RefPtr<Glib::ObjectBase>;

  /** Gets the selected item.
   *
   * If no item is selected, <tt>nullptr</tt> is returned.
   *
   * @return The selected item.
   */
  auto get_selected_item() const -> Glib::RefPtr<const Glib::ObjectBase>;


  /** Checks if autoselect has been enabled or disabled via
   * set_autoselect().
   *
   * @return <tt>true</tt> if autoselect is enabled.
   */
  auto get_autoselect() const -> bool;

  /** Enables or disables autoselect.
   *
   * If @a autoselect is <tt>true</tt>, @a self will enforce that an item is always
   * selected. It will select a new item when the currently selected
   * item is deleted and it will disallow unselecting the current item.
   *
   * @param autoselect <tt>true</tt> to always select an item.
   */
  void set_autoselect(bool autoselect =  true);

  /** If <tt>true</tt>, Gtk::SelectionModel::unselect_item() is supported and allows
   * unselecting the selected item.
   *
   * @return <tt>true</tt> to support unselecting.
   */
  auto get_can_unselect() const -> bool;

  /** If <tt>true</tt>, unselecting the current item via
   * Gtk::SelectionModel::unselect_item() is supported.
   *
   * Note that setting property_autoselect() will
   * cause unselecting to not work, so it practically makes no sense
   * to set both at the same time the same time.
   *
   * @param can_unselect <tt>true</tt> to allow unselecting.
   */
  void set_can_unselect(bool can_unselect =  true);

  /** If the selection will always select an item.
   *
   * Default value: <tt>true</tt>
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_autoselect() -> Glib::PropertyProxy< bool > ;

/** If the selection will always select an item.
   *
   * Default value: <tt>true</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_autoselect() const -> Glib::PropertyProxy_ReadOnly< bool >;

  /** If unselecting the selected item is allowed.
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_can_unselect() -> Glib::PropertyProxy< bool > ;

/** If unselecting the selected item is allowed.
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_can_unselect() const -> Glib::PropertyProxy_ReadOnly< bool >;

  /** Position of the selected item.
   *
   * Default value: 4294967295
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_selected() -> Glib::PropertyProxy< guint > ;

/** Position of the selected item.
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


  /** The type of items. See Gio::ListModel::get_item_type().
   *
   * @newin{4,8}
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_item_type() const -> Glib::PropertyProxy_ReadOnly< GType >;


  /** The model being managed.
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_model() -> Glib::PropertyProxy< Glib::RefPtr<Gio::ListModel> > ;

/** The model being managed.
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


  // There are no signals or vfuncs.


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
   * @relates Gtk::SingleSelection
   */
  GTKMM_API
  auto wrap(GtkSingleSelection* object, bool take_copy = false) -> Glib::RefPtr<Gtk::SingleSelection>;
}


#endif /* _GTKMM_SINGLESELECTION_H */

