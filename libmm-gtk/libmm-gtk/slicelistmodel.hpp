
#ifndef _GTKMM_SLICELISTMODEL_H
#define _GTKMM_SLICELISTMODEL_H

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
#include <gtk/gtk.h>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{ class GTKMM_API SliceListModel_Class; } // namespace Gtk
#endif //DOXYGEN_SHOULD_SKIP_THIS

namespace Gtk
{

/** A list model that presents a slice out of a larger list.
 *
 * %Gtk::SliceListModel is a list model that takes a list model and presents a
 * slice of that model.
 *
 * This is useful when implementing paging by setting the size to the number
 * of elements per page and updating the offset whenever a different page is
 * opened.
 *
 * @see Gio::ListModel
 * @newin{3,98}
 */

class GTKMM_API SliceListModel : public Glib::Object, public Gio::ListModel
{

#ifndef DOXYGEN_SHOULD_SKIP_THIS

public:
  using CppObjectType = SliceListModel;
  using CppClassType = SliceListModel_Class;
  using BaseObjectType = GtkSliceListModel;
  using BaseClassType = GtkSliceListModelClass;

  // noncopyable
  SliceListModel(const SliceListModel&) = delete;
  auto operator=(const SliceListModel&) -> SliceListModel& = delete;

private:  friend class SliceListModel_Class;
  static CppClassType slicelistmodel_class_;

protected:
  explicit SliceListModel(const Glib::ConstructParams& construct_params);
  explicit SliceListModel(GtkSliceListModel* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  SliceListModel(SliceListModel&& src) noexcept;
  auto operator=(SliceListModel&& src) noexcept -> SliceListModel&;

  ~SliceListModel() noexcept override;

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS


  static auto get_base_type() -> GType G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GObject.
  auto       gobj() -> GtkSliceListModel*       { return reinterpret_cast<GtkSliceListModel*>(gobject_); }

  ///Provides access to the underlying C GObject.
  auto gobj() const -> const GtkSliceListModel* { return reinterpret_cast<GtkSliceListModel*>(gobject_); }

  ///Provides access to the underlying C instance. The caller is responsible for unrefing it. Use when directly setting fields in structs.
  auto gobj_copy() -> GtkSliceListModel*;

private:


protected:
    explicit SliceListModel(const Glib::RefPtr<Gio::ListModel>& model, guint offset, guint size);


public:

  static auto create(const Glib::RefPtr<Gio::ListModel>& model, guint offset, guint size) -> Glib::RefPtr<SliceListModel>;


  /** Sets the model to show a slice of.
   *
   * The model's item type must conform to @a self's item type.
   *
   * @param model The model to be sliced.
   */
  void set_model(const Glib::RefPtr<Gio::ListModel>& model);

  /** Gets the model that is currently being used or <tt>nullptr</tt> if none.
   *
   * @return The model in use.
   */
  auto get_model() -> Glib::RefPtr<Gio::ListModel>;

  /** Gets the model that is currently being used or <tt>nullptr</tt> if none.
   *
   * @return The model in use.
   */
  auto get_model() const -> Glib::RefPtr<const Gio::ListModel>;

  /** Sets the offset into the original model for this slice.
   *
   * If the offset is too large for the sliced model,
   *  @a self will end up empty.
   *
   * @param offset The new offset to use.
   */
  void set_offset(guint offset);

  /** Gets the offset set via set_offset().
   *
   * @return The offset.
   */
  auto get_offset() const -> guint;

  /** Sets the maximum size. @a self will never have more items
   * than @a size.
   *
   * It can however have fewer items if the offset is too large
   * or the model sliced from doesn't have enough items.
   *
   * @param size The maximum size.
   */
  void set_size(guint size);

  /** Gets the size set via set_size().
   *
   * @return The size.
   */
  auto get_size() const -> guint;

  /** The type of items. See Gio::ListModel::get_item_type().
   *
   * @newin{4,8}
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_item_type() const -> Glib::PropertyProxy_ReadOnly< GType >;


  /** Child model to take slice from.
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_model() -> Glib::PropertyProxy< Glib::RefPtr<Gio::ListModel> > ;

/** Child model to take slice from.
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


  /** Offset of slice.
   *
   * Default value: 0
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_offset() -> Glib::PropertyProxy< guint > ;

/** Offset of slice.
   *
   * Default value: 0
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_offset() const -> Glib::PropertyProxy_ReadOnly< guint >;

  /** Maximum size of slice.
   *
   * Default value: 10
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_size() -> Glib::PropertyProxy< guint > ;

/** Maximum size of slice.
   *
   * Default value: 10
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_size() const -> Glib::PropertyProxy_ReadOnly< guint >;


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
   * @relates Gtk::SliceListModel
   */
  GTKMM_API
  auto wrap(GtkSliceListModel* object, bool take_copy = false) -> Glib::RefPtr<Gtk::SliceListModel>;
}


#endif /* _GTKMM_SLICELISTMODEL_H */

