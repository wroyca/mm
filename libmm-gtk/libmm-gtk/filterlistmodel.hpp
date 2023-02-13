
#ifndef _GTKMM_FILTERLISTMODEL_H
#define _GTKMM_FILTERLISTMODEL_H

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


#include <mm/gio/listmodel.hpp>
#include <mm/gtk/filter.hpp>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{ class GTKMM_API FilterListModel_Class; } // namespace Gtk
#endif //DOXYGEN_SHOULD_SKIP_THIS

namespace Gtk
{

/** A list model that filters its items.
 *
 * %Gtk::FilterListModel is a list model that filters a given other
 * listmodel.
 * It hides some elements from the other model according to
 * criteria given by a Gtk::Filter.
 *
 * The model can be set up to do incremental searching, so that
 * filtering long lists doesn't block the UI. See set_incremental()
 * for details.
 *
 * @see Gio::ListModel, Gtk::Filter
 * @newin{3,98}
 */

class GTKMM_API FilterListModel : public Glib::Object, public Gio::ListModel
{

#ifndef DOXYGEN_SHOULD_SKIP_THIS

public:
  using CppObjectType = FilterListModel;
  using CppClassType = FilterListModel_Class;
  using BaseObjectType = GtkFilterListModel;
  using BaseClassType = GtkFilterListModelClass;

  // noncopyable
  FilterListModel(const FilterListModel&) = delete;
  auto operator=(const FilterListModel&) -> FilterListModel& = delete;

private:  friend class FilterListModel_Class;
  static CppClassType filterlistmodel_class_;

protected:
  explicit FilterListModel(const Glib::ConstructParams& construct_params);
  explicit FilterListModel(GtkFilterListModel* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  FilterListModel(FilterListModel&& src) noexcept;
  auto operator=(FilterListModel&& src) noexcept -> FilterListModel&;

  ~FilterListModel() noexcept override;

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS


  static auto get_base_type() -> GType G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GObject.
  auto       gobj() -> GtkFilterListModel*       { return reinterpret_cast<GtkFilterListModel*>(gobject_); }

  ///Provides access to the underlying C GObject.
  auto gobj() const -> const GtkFilterListModel* { return reinterpret_cast<GtkFilterListModel*>(gobject_); }

  ///Provides access to the underlying C instance. The caller is responsible for unrefing it. Use when directly setting fields in structs.
  auto gobj_copy() -> GtkFilterListModel*;

private:


protected:
    explicit FilterListModel(const Glib::RefPtr<Gio::ListModel>& model, const Glib::RefPtr<Filter>& filter);


public:

  static auto create(const Glib::RefPtr<Gio::ListModel>& model, const Glib::RefPtr<Filter>& filter) -> Glib::RefPtr<FilterListModel>;


  /** Sets the filter used to filter items.
   *
   * @param filter Filter to use.
   */
  void set_filter(const Glib::RefPtr<Filter>& filter);

  /** Gets the `Gtk::Filter` currently set on @a self.
   *
   * @return The filter currently in use.
   */
  auto get_filter() -> Glib::RefPtr<Filter>;

  /** Gets the `Gtk::Filter` currently set on @a self.
   *
   * @return The filter currently in use.
   */
  auto get_filter() const -> Glib::RefPtr<const Filter>;


  /** Sets the model to be filtered.
   *
   * Note that GTK makes no effort to ensure that @a model conforms to
   * the item type of @a self. It assumes that the caller knows what they
   * are doing and have set up an appropriate filter to ensure that item
   * types match.
   *
   * @param model The model to be filtered.
   */
  void set_model(const Glib::RefPtr<Gio::ListModel>& model);

  /** Gets the model currently filtered or <tt>nullptr</tt> if none.
   *
   * @return The model that gets filtered.
   */
  auto get_model() -> Glib::RefPtr<Gio::ListModel>;

  /** Gets the model currently filtered or <tt>nullptr</tt> if none.
   *
   * @return The model that gets filtered.
   */
  auto get_model() const -> Glib::RefPtr<const Gio::ListModel>;


  /** Sets the filter model to do an incremental sort.
   *
   * When incremental filtering is enabled, the `Gtk::FilterListModel` will not
   * run filters immediately, but will instead queue an idle handler that
   * incrementally filters the items and adds them to the list. This of course
   * means that items are not instantly added to the list, but only appear
   * incrementally.
   *
   * When your filter blocks the UI while filtering, you might consider
   * turning this on. Depending on your model and filters, this may become
   * interesting around 10,000 to 100,000 items.
   *
   * By default, incremental filtering is disabled.
   *
   * See get_pending() for progress information
   * about an ongoing incremental filtering operation.
   *
   * @param incremental <tt>true</tt> to enable incremental filtering.
   */
  void set_incremental(bool incremental =  true);

  /** Returns whether incremental filtering is enabled.
   *
   * See set_incremental().
   *
   * @return <tt>true</tt> if incremental filtering is enabled.
   */
  auto get_incremental() const -> bool;


  /** Returns the number of items that have not been filtered yet.
   *
   * You can use this value to check if @a self is busy filtering by
   * comparing the return value to 0 or you can compute the percentage
   * of the filter remaining by dividing the return value by the total
   * number of items in the underlying model:
   *
   *
   * [C example ellipted]
   *
   * If no filter operation is ongoing - in particular when
   * property_incremental() is <tt>false</tt> - this
   * function returns 0.
   *
   * @return The number of items not yet filtered.
   */
  auto get_pending() const -> guint;

  /** The filter for this model.
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_filter() -> Glib::PropertyProxy< Glib::RefPtr<Filter> > ;

/** The filter for this model.
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_filter() const -> Glib::PropertyProxy_ReadOnly< Glib::RefPtr<Filter> >;

  /** If the model should filter items incrementally.
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_incremental() -> Glib::PropertyProxy< bool > ;

/** If the model should filter items incrementally.
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


  /** The model being filtered.
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_model() -> Glib::PropertyProxy< Glib::RefPtr<Gio::ListModel> > ;

/** The model being filtered.
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


  /** Number of items not yet filtered.
   *
   * Default value: 0
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_pending() const -> Glib::PropertyProxy_ReadOnly< guint >;


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
   * @relates Gtk::FilterListModel
   */
  GTKMM_API
  auto wrap(GtkFilterListModel* object, bool take_copy = false) -> Glib::RefPtr<Gtk::FilterListModel>;
}


#endif /* _GTKMM_FILTERLISTMODEL_H */

