
#ifndef _GTKMM_FLATTENLISTMODEL_H
#define _GTKMM_FLATTENLISTMODEL_H

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


#include <libmm-gio/listmodel.hxx>
#include <gtk/gtk.h>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{ class GTKMM_API FlattenListModel_Class; } // namespace Gtk
#endif //DOXYGEN_SHOULD_SKIP_THIS

namespace Gtk
{

/** A list model that flattens a list of lists.
 *
 * %Gtk::FlattenListModel is a list model that takes a list model containing
 * list models and flattens it into a single model.
 *
 * Another term for this is concatenation: %Gtk::FlattenListModel takes a
 * list of lists and concatenates them into a single list.
 *
 * @see Gio::ListModel
 * @newin{3,98}
 */

class GTKMM_API FlattenListModel : public Glib::Object, public Gio::ListModel
{

#ifndef DOXYGEN_SHOULD_SKIP_THIS

public:
  using CppObjectType = FlattenListModel;
  using CppClassType = FlattenListModel_Class;
  using BaseObjectType = GtkFlattenListModel;
  using BaseClassType = GtkFlattenListModelClass;

  // noncopyable
  FlattenListModel(const FlattenListModel&) = delete;
  auto operator=(const FlattenListModel&) -> FlattenListModel& = delete;

private:  friend class FlattenListModel_Class;
  static CppClassType flattenlistmodel_class_;

protected:
  explicit FlattenListModel(const Glib::ConstructParams& construct_params);
  explicit FlattenListModel(GtkFlattenListModel* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  FlattenListModel(FlattenListModel&& src) noexcept;
  auto operator=(FlattenListModel&& src) noexcept -> FlattenListModel&;

  ~FlattenListModel() noexcept override;

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS


  static auto get_base_type() -> GType G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GObject.
  auto       gobj() -> GtkFlattenListModel*       { return reinterpret_cast<GtkFlattenListModel*>(gobject_); }

  ///Provides access to the underlying C GObject.
  auto gobj() const -> const GtkFlattenListModel* { return reinterpret_cast<GtkFlattenListModel*>(gobject_); }

  ///Provides access to the underlying C instance. The caller is responsible for unrefing it. Use when directly setting fields in structs.
  auto gobj_copy() -> GtkFlattenListModel*;

private:


protected:
    explicit FlattenListModel(const Glib::RefPtr<Gio::ListModel>& model);


public:

  static auto create(const Glib::RefPtr<Gio::ListModel>& model) -> Glib::RefPtr<FlattenListModel>;


  /** Sets a new model to be flattened.
   *
   * @param model The new model.
   */
  void set_model(const Glib::RefPtr<Gio::ListModel>& model);

  /** Gets the model set via set_model().
   *
   * @return The model flattened by @a self.
   */
  auto get_model() -> Glib::RefPtr<Gio::ListModel>;

  /** Gets the model set via set_model().
   *
   * @return The model flattened by @a self.
   */
  auto get_model() const -> Glib::RefPtr<const Gio::ListModel>;


  /** Returns the model containing the item at the given position.
   *
   * @param position A position.
   * @return The model containing the item at @a position.
   */
  auto get_model_for_item(guint position) -> Glib::RefPtr<Gio::ListModel>;

  /** The type of items. See Gio::ListModel::get_item_type().
   *
   * @newin{4,8}
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_item_type() const -> Glib::PropertyProxy_ReadOnly< GType >;


  /** The model being flattened.
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_model() -> Glib::PropertyProxy< Glib::RefPtr<Gio::ListModel> > ;

/** The model being flattened.
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
   * @relates Gtk::FlattenListModel
   */
  GTKMM_API
  auto wrap(GtkFlattenListModel* object, bool take_copy = false) -> Glib::RefPtr<Gtk::FlattenListModel>;
}


#endif /* _GTKMM_FLATTENLISTMODEL_H */

