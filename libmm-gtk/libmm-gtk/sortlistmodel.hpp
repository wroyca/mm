
#ifndef _GTKMM_SORTLISTMODEL_H
#define _GTKMM_SORTLISTMODEL_H

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


#include <libmm-gio/listmodel.hpp>
#include <libmm-gtk/sorter.hpp>
#include <gtk/gtk.h>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{ class GTKMM_API SortListModel_Class; } // namespace Gtk
#endif //DOXYGEN_SHOULD_SKIP_THIS

namespace Gtk
{

/** A list model that sorts its items.
 *
 * %Gtk::SortListModel is a list model that takes a list model and
 * sorts its elements according to a Gtk::Sorter.
 *
 * The model can be set up to do incremental sorting, so that
 * sorting long lists doesn't block the UI. See set_incremental()
 * for details.
 *
 * %Gtk::SortListModel is a generic model and because of that it
 * cannot take advantage of any external knowledge when sorting.
 * If you run into performance issues with %Gtk::SortListModel, it
 * is strongly recommended that you write your own sorting list
 * model.
 *
 * @see Gio::ListModel, Gtk::Sorter
 * @newin{3,98}
 */

class GTKMM_API SortListModel : public Glib::Object, public Gio::ListModel
{

#ifndef DOXYGEN_SHOULD_SKIP_THIS

public:
  using CppObjectType = SortListModel;
  using CppClassType = SortListModel_Class;
  using BaseObjectType = GtkSortListModel;
  using BaseClassType = GtkSortListModelClass;

  // noncopyable
  SortListModel(const SortListModel&) = delete;
  auto operator=(const SortListModel&) -> SortListModel& = delete;

private:  friend class SortListModel_Class;
  static CppClassType sortlistmodel_class_;

protected:
  explicit SortListModel(const Glib::ConstructParams& construct_params);
  explicit SortListModel(GtkSortListModel* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  SortListModel(SortListModel&& src) noexcept;
  auto operator=(SortListModel&& src) noexcept -> SortListModel&;

  ~SortListModel() noexcept override;

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS


  static auto get_base_type() -> GType G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GObject.
  auto       gobj() -> GtkSortListModel*       { return reinterpret_cast<GtkSortListModel*>(gobject_); }

  ///Provides access to the underlying C GObject.
  auto gobj() const -> const GtkSortListModel* { return reinterpret_cast<GtkSortListModel*>(gobject_); }

  ///Provides access to the underlying C instance. The caller is responsible for unrefing it. Use when directly setting fields in structs.
  auto gobj_copy() -> GtkSortListModel*;

private:


protected:
    explicit SortListModel(const Glib::RefPtr<Gio::ListModel>& model, const Glib::RefPtr<Sorter>& sorter);


public:

  static auto create(const Glib::RefPtr<Gio::ListModel>& model, const Glib::RefPtr<Sorter>& sorter) -> Glib::RefPtr<SortListModel>;


  /** Sets a new sorter on @a self.
   *
   * @param sorter The `Gtk::Sorter` to sort @a model with.
   */
  void set_sorter(const Glib::RefPtr<Sorter>& sorter);

  /** Gets the sorter that is used to sort @a self.
   *
   * @return The sorter of #self.
   */
  auto get_sorter() -> Glib::RefPtr<Sorter>;

  /** Gets the sorter that is used to sort @a self.
   *
   * @return The sorter of #self.
   */
  auto get_sorter() const -> Glib::RefPtr<const Sorter>;


  /** Sets the model to be sorted.
   *
   * The @a model's item type must conform to the item type of @a self.
   *
   * @param model The model to be sorted.
   */
  void set_model(const Glib::RefPtr<Gio::ListModel>& model);

  /** Gets the model currently sorted or <tt>nullptr</tt> if none.
   *
   * @return The model that gets sorted.
   */
  auto get_model() -> Glib::RefPtr<Gio::ListModel>;

  /** Gets the model currently sorted or <tt>nullptr</tt> if none.
   *
   * @return The model that gets sorted.
   */
  auto get_model() const -> Glib::RefPtr<const Gio::ListModel>;


  /** Sets the sort model to do an incremental sort.
   *
   * When incremental sorting is enabled, the `Gtk::SortListModel` will not do
   * a complete sort immediately, but will instead queue an idle handler that
   * incrementally sorts the items towards their correct position. This of
   * course means that items do not instantly appear in the right place. It
   * also means that the total sorting time is a lot slower.
   *
   * When your filter blocks the UI while sorting, you might consider
   * turning this on. Depending on your model and sorters, this may become
   * interesting around 10,000 to 100,000 items.
   *
   * By default, incremental sorting is disabled.
   *
   * See get_pending() for progress information
   * about an ongoing incremental sorting operation.
   *
   * @param incremental <tt>true</tt> to sort incrementally.
   */
  void set_incremental(bool incremental =  true);

  /** Returns whether incremental sorting is enabled.
   *
   * See set_incremental().
   *
   * @return <tt>true</tt> if incremental sorting is enabled.
   */
  auto get_incremental() const -> bool;


  /** Estimates progress of an ongoing sorting operation.
   *
   * The estimate is the number of items that would still need to be
   * sorted to finish the sorting operation if this was a linear
   * algorithm. So this number is not related to how many items are
   * already correctly sorted.
   *
   * If you want to estimate the progress, you can use code like this:
   *
   * [C example ellipted]
   *
   * If no sort operation is ongoing - in particular when
   * property_incremental() is <tt>false</tt> - this
   * function returns 0.
   *
   * @return A progress estimate of remaining items to sort.
   */
  auto get_pending() const -> guint;

  /** If the model should sort items incrementally.
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_incremental() -> Glib::PropertyProxy< bool > ;

/** If the model should sort items incrementally.
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_incremental() const -> Glib::PropertyProxy_ReadOnly< bool >;

  /** The type of items. See Gio::ListModel::get_item_type().
   *
   * @newin{4,8}
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_item_type() const -> Glib::PropertyProxy_ReadOnly< GType >;


  /** The model being sorted.
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_model() -> Glib::PropertyProxy< Glib::RefPtr<Gio::ListModel> > ;

/** The model being sorted.
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


  /** Estimate of unsorted items remaining.
   *
   * Default value: 0
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_pending() const -> Glib::PropertyProxy_ReadOnly< guint >;


  /** The sorter for this model.
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_sorter() -> Glib::PropertyProxy< Glib::RefPtr<Sorter> > ;

/** The sorter for this model.
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_sorter() const -> Glib::PropertyProxy_ReadOnly< Glib::RefPtr<Sorter> >;


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
   * @relates Gtk::SortListModel
   */
  GTKMM_API
  auto wrap(GtkSortListModel* object, bool take_copy = false) -> Glib::RefPtr<Gtk::SortListModel>;
}


#endif /* _GTKMM_SORTLISTMODEL_H */

