
#ifndef _GTKMM_MULTISELECTION_H
#define _GTKMM_MULTISELECTION_H


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
#include <libmm-glib/refptr.hpp>
#include <libmm-gio/listmodel.hpp>
#include <libmm-gtk/selectionmodel.hpp>
#include <gtk/gtk.h> // Declares GtkMultiSelection and GtkMultiSelectionClass


#ifndef DOXYGEN_SHOULD_SKIP_THIS
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{ class GTKMM_API MultiSelection_Class; } // namespace Gtk
#endif //DOXYGEN_SHOULD_SKIP_THIS

namespace Gtk
{
/** A selection model that allows selecting multiple items.
 *
 * %Gtk::MultiSelection is an implementation of the Gtk::SelectionModel interface
 * that allows selecting multiple elements.
 *
 * @see SelectionModel
 * @newin{3,98}
 */

class GTKMM_API MultiSelection : public Glib::Object, public Gio::ListModel, public SelectionModel
{

#ifndef DOXYGEN_SHOULD_SKIP_THIS

public:
  using CppObjectType = MultiSelection;
  using CppClassType = MultiSelection_Class;
  using BaseObjectType = GtkMultiSelection;
  using BaseClassType = GtkMultiSelectionClass;

  // noncopyable
  MultiSelection(const MultiSelection&) = delete;
  auto operator=(const MultiSelection&) -> MultiSelection& = delete;

private:  friend class MultiSelection_Class;
  static CppClassType multiselection_class_;

protected:
  explicit MultiSelection(const Glib::ConstructParams& construct_params);
  explicit MultiSelection(GtkMultiSelection* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  MultiSelection(MultiSelection&& src) noexcept;
  auto operator=(MultiSelection&& src) noexcept -> MultiSelection&;

  ~MultiSelection() noexcept override;

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS


  static auto get_base_type() -> GType G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GObject.
  auto       gobj() -> GtkMultiSelection*       { return reinterpret_cast<GtkMultiSelection*>(gobject_); }

  ///Provides access to the underlying C GObject.
  auto gobj() const -> const GtkMultiSelection* { return reinterpret_cast<GtkMultiSelection*>(gobject_); }

  ///Provides access to the underlying C instance. The caller is responsible for unrefing it. Use when directly setting fields in structs.
  auto gobj_copy() -> GtkMultiSelection*;

private:


protected:
  MultiSelection();
    explicit MultiSelection(const Glib::RefPtr<Gio::ListModel>& model);


public:

  static auto create() -> Glib::RefPtr<MultiSelection>;


  static auto create(const Glib::RefPtr<Gio::ListModel>& model) -> Glib::RefPtr<MultiSelection>;


  /** Returns the underlying model of @a self.
   *
   * @return The underlying model.
   */
  auto get_model() -> Glib::RefPtr<Gio::ListModel>;

  /** Returns the underlying model of @a self.
   *
   * @return The underlying model.
   */
  auto get_model() const -> Glib::RefPtr<const Gio::ListModel>;

  /** Sets the model that @a self should wrap.
   *
   * If @a model is <tt>nullptr</tt>, @a self will be empty.
   *
   * @param model A `Gio::ListModel` to wrap.
   */
  void set_model(const Glib::RefPtr<Gio::ListModel>& model);

  /** The type of items. See Gio::ListModel::get_item_type().
   *
   * @newin{4,8}
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_item_type() const -> Glib::PropertyProxy_ReadOnly< GType >;


  /** The list managed by this selection.
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_model() -> Glib::PropertyProxy< Glib::RefPtr<Gio::ListModel> > ;

/** The list managed by this selection.
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
   * @relates Gtk::MultiSelection
   */
  GTKMM_API
  auto wrap(GtkMultiSelection* object, bool take_copy = false) -> Glib::RefPtr<Gtk::MultiSelection>;
}


#endif /* _GTKMM_MULTISELECTION_H */

