
#ifndef _GTKMM_SELECTIONFILTERMODEL_H
#define _GTKMM_SELECTIONFILTERMODEL_H

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
#include <libmm-gtk/selectionmodel.hpp>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{ class GTKMM_API SelectionFilterModel_Class; } // namespace Gtk
#endif //DOXYGEN_SHOULD_SKIP_THIS

namespace Gtk
{

/** A list model that turns a selection in a model.
 *
 * %Gtk::SelectionFilterModel is a list model that presents the
 * selected items in a Gtk::SelectionModel as its own list model.
 *
 * @see Gtk::SelectionModel
 * @newin{3,98}
 */

class GTKMM_API SelectionFilterModel : public Glib::Object, public Gio::ListModel
{

#ifndef DOXYGEN_SHOULD_SKIP_THIS

public:
  using CppObjectType = SelectionFilterModel;
  using CppClassType = SelectionFilterModel_Class;
  using BaseObjectType = GtkSelectionFilterModel;
  using BaseClassType = GtkSelectionFilterModelClass;

  // noncopyable
  SelectionFilterModel(const SelectionFilterModel&) = delete;
  auto operator=(const SelectionFilterModel&) -> SelectionFilterModel& = delete;

private:  friend class SelectionFilterModel_Class;
  static CppClassType selectionfiltermodel_class_;

protected:
  explicit SelectionFilterModel(const Glib::ConstructParams& construct_params);
  explicit SelectionFilterModel(GtkSelectionFilterModel* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  SelectionFilterModel(SelectionFilterModel&& src) noexcept;
  auto operator=(SelectionFilterModel&& src) noexcept -> SelectionFilterModel&;

  ~SelectionFilterModel() noexcept override;

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS


  static auto get_base_type() -> GType G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GObject.
  auto       gobj() -> GtkSelectionFilterModel*       { return reinterpret_cast<GtkSelectionFilterModel*>(gobject_); }

  ///Provides access to the underlying C GObject.
  auto gobj() const -> const GtkSelectionFilterModel* { return reinterpret_cast<GtkSelectionFilterModel*>(gobject_); }

  ///Provides access to the underlying C instance. The caller is responsible for unrefing it. Use when directly setting fields in structs.
  auto gobj_copy() -> GtkSelectionFilterModel*;

private:


protected:
    explicit SelectionFilterModel(const Glib::RefPtr<SelectionModel>& model);


public:

  static auto create(const Glib::RefPtr<SelectionModel>& model) -> Glib::RefPtr<SelectionFilterModel>;


  /** Sets the model to be filtered.
   *
   * Note that GTK makes no effort to ensure that @a model conforms to
   * the item type of @a self. It assumes that the caller knows what they
   * are doing and have set up an appropriate filter to ensure that item
   * types match.
   *
   * @param model The model to be filtered.
   */
  void set_model(const Glib::RefPtr<SelectionModel>& model);

  /** Gets the model currently filtered or <tt>nullptr</tt> if none.
   *
   * @return The model that gets filtered.
   */
  auto get_model() -> Glib::RefPtr<SelectionModel>;

  /** Gets the model currently filtered or <tt>nullptr</tt> if none.
   *
   * @return The model that gets filtered.
   */
  auto get_model() const -> Glib::RefPtr<const SelectionModel>;

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
  auto property_model() -> Glib::PropertyProxy< Glib::RefPtr<SelectionModel> > ;

/** The model being filtered.
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_model() const -> Glib::PropertyProxy_ReadOnly< Glib::RefPtr<SelectionModel> >;

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
   * @relates Gtk::SelectionFilterModel
   */
  GTKMM_API
  auto wrap(GtkSelectionFilterModel* object, bool take_copy = false) -> Glib::RefPtr<Gtk::SelectionFilterModel>;
}


#endif /* _GTKMM_SELECTIONFILTERMODEL_H */

