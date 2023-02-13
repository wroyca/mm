
#ifndef _GTKMM_SELECTIONMODEL_H
#define _GTKMM_SELECTIONMODEL_H

#include <libmm-gtk/mm-gtkconfig.hpp>


#include <libmm-glib/ustring.hpp>
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


#include <libmm-glib/interface.hpp>
#include <libmm-gtk/bitset.hpp>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
extern "C"
{
typedef struct _GtkSelectionModelInterface GtkSelectionModelInterface;
}
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkSelectionModel = struct _GtkSelectionModel;
using GtkSelectionModelClass = struct _GtkSelectionModelClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{ class GTKMM_API SelectionModel_Class; } // namespace Gtk
#endif // DOXYGEN_SHOULD_SKIP_THIS

namespace Gtk
{

/** An extension of the list model interface that handles selections.
 *
 * %Gtk::SelectionModel is an interface that extends the Gio::ListModel interface by adding
 * support for selections. This support is then used by widgets using list models to add
 * the ability to select and unselect various items.
 *
 * GTK provides default implementations of the common selection modes such as
 * Gtk::SingleSelection, so you will only need to implement this interface if you want
 * detailed control about how selections should be handled.
 *
 * A %Gtk::SelectionModel supports a single boolean per row indicating if a row is selected
 * or not. This can be queried via is_selected(). When the selected
 * state of one or more rows changes, the model will emit
 * signal_selection_changed() by calling the
 * selection_changed() method. The positions given in that signal
 * may have their selection state changed, though that is not a requirement.
 * If new items added to the model via Gio::ListModel::signal_items_changed() are selected
 * or not is up to the implementation.
 *
 * Additionally, the interface can expose functionality to select and unselect items.
 * If these functions are implemented, GTK's list widgets will allow users to select and
 * unselect items. However, %Gtk::SelectionModels are free to only implement them
 * partially or not at all. In that case the widgets will not support the unimplemented
 * operations.
 *
 * When selecting or unselecting is supported by a model, the return values of the
 * selection functions do NOT indicate if selection or unselection happened. They are
 * only meant to indicate complete failure, like when this mode of selecting is not
 * supported by the model.
 * Selections may happen asynchronously, so the only reliable way to find out when an
 * item was selected is to listen to the signals that indicate selection.
 *
 * @see Gio::ListModel, Gtk::SingleSelection
 * @newin{3,96}
 */

class GTKMM_API SelectionModel : public Glib::Interface
{

#ifndef DOXYGEN_SHOULD_SKIP_THIS

public:
  using CppObjectType = SelectionModel;
  using CppClassType = SelectionModel_Class;
  using BaseObjectType = GtkSelectionModel;
  using BaseClassType = GtkSelectionModelInterface;

  // noncopyable
  SelectionModel(const SelectionModel&) = delete;
  auto operator=(const SelectionModel&) -> SelectionModel& = delete;

private:
  friend class SelectionModel_Class;
  static CppClassType selectionmodel_class_;

#endif /* DOXYGEN_SHOULD_SKIP_THIS */
protected:
  /**
   * You should derive from this class to use it.
   */
  SelectionModel();

#ifndef DOXYGEN_SHOULD_SKIP_THIS
  /** Called by constructors of derived classes. Provide the result of
   * the Class init() function to ensure that it is properly
   * initialized.
   *
   * @param interface_class The Class object for the derived type.
   */
  explicit SelectionModel(const Glib::Interface_Class& interface_class);

public:
  // This is public so that C++ wrapper instances can be
  // created for C instances of unwrapped types.
  // For instance, if an unexpected C type implements the C interface.
  explicit SelectionModel(GtkSelectionModel* castitem);

protected:
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  SelectionModel(SelectionModel&& src) noexcept;
  auto operator=(SelectionModel&& src) noexcept -> SelectionModel&;

  ~SelectionModel() noexcept override;

  static void add_interface(GType gtype_implementer);

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS
  static auto get_base_type() -> GType G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GObject.
  auto       gobj() -> GtkSelectionModel*       { return reinterpret_cast<GtkSelectionModel*>(gobject_); }

  ///Provides access to the underlying C GObject.
  auto gobj() const -> const GtkSelectionModel* { return reinterpret_cast<GtkSelectionModel*>(gobject_); }

private:


public:

  /** Checks if the given item is selected.
   *
   * @param position The position of the item to query.
   * @return <tt>true</tt> if the item is selected.
   */
  auto is_selected(guint position) const -> bool;

  /** Gets the set containing all currently selected items in the model.
   *
   * This function may be slow, so if you are only interested in single item,
   * consider using is_selected() or if you are only
   * interested in a few, consider get_selection_in_range().
   *
   * @return A `Gtk::Bitset` containing all the values currently
   * selected in @a model. If no items are selected, the bitset is empty.
   * The bitset must not be modified.
   */
  auto get_selection() const -> Glib::RefPtr<const Bitset>;

  /** Gets the set of selected items in a range.
   *
   * This function is an optimization for
   * get_selection() when you are only
   * interested in part of the model's selected state. A common use
   * case is in response to the signal_selection_changed()
   * signal.
   *
   * @param position Start of the queired range.
   * @param n_items Number of items in the queried range.
   * @return A `Gtk::Bitset` that matches the selection state
   * for the given range with all other values being undefined.
   * The bitset must not be modified.
   */
  auto get_selection(guint position, guint n_items) const -> Glib::RefPtr<const Bitset>;

  /** Requests to select an item in the model.
   *
   * @param position The position of the item to select.
   * @param unselect_rest Whether previously selected items should be unselected.
   * @return <tt>true</tt> if this action was supported and no fallback should be
   * tried. This does not mean the item was selected.
   */
  auto select_item(guint position, bool unselect_rest) -> bool;

  /** Requests to unselect an item in the model.
   *
   * @param position The position of the item to unselect.
   * @return <tt>true</tt> if this action was supported and no fallback should be
   * tried. This does not mean the item was unselected.
   */
  auto unselect_item(guint position) -> bool;

  /** Requests to select a range of items in the model.
   *
   * @param position The first item to select.
   * @param n_items The number of items to select.
   * @param unselect_rest Whether previously selected items should be unselected.
   * @return <tt>true</tt> if this action was supported and no fallback should be
   * tried. This does not mean the range was selected.
   */
  auto select_range(guint position, guint n_items, bool unselect_rest) -> bool;

  /** Requests to unselect a range of items in the model.
   *
   * @param position The first item to unselect.
   * @param n_items The number of items to unselect.
   * @return <tt>true</tt> if this action was supported and no fallback should be
   * tried. This does not mean the range was unselected.
   */
  auto unselect_range(guint position, guint n_items) -> bool;

  /** Requests to select all items in the model.
   *
   * @return <tt>true</tt> if this action was supported and no fallback should be
   * tried. This does not mean that all items are now selected.
   */
  auto select_all() -> bool;

  /** Requests to unselect all items in the model.
   *
   * @return <tt>true</tt> if this action was supported and no fallback should be
   * tried. This does not mean that all items are now unselected.
   */
  auto unselect_all() -> bool;

  /** Make selection changes.
   *
   * This is the most advanced selection updating method that allows
   * the most fine-grained control over selection changes. If you can,
   * you should try the simpler versions, as implementations are more
   * likely to implement support for those.
   *
   * Requests that the selection state of all positions set in @a mask
   * be updated to the respective value in the @a selected bitmask.
   *
   * In pseudocode, it would look something like this:
   *
   *
   * [C example ellipted]
   *
   *  @a mask and @a selected must not be modified. They may refer to the
   * same bitset, which would mean that every item in the set should
   * be selected.
   *
   * @param selected Bitmask specifying if items should be selected or unselected.
   * @param mask Bitmask specifying which items should be updated.
   * @return <tt>true</tt> if this action was supported and no fallback should be
   * tried. This does not mean that all items were updated according
   * to the inputs.
   */
  auto set_selection(const Glib::RefPtr<const Bitset>& selected, const Glib::RefPtr<const Bitset>& mask) -> bool;

  // no_default_handler because the wrapped C signal has no default handler.

  /**
   * @par Slot Prototype:
   * <tt>void on_my_%selection_changed(guint position, guint n_items)</tt>
   *
   * Flags: Run Last
   *
   * Emitted when the selection state of some of the items in @a model changes.
   *
   * Note that this signal does not specify the new selection state of the
   * items, they need to be queried manually. It is also not necessary for
   * a model to change the selection state of any of the items in the selection
   * model, though it would be rather useless to emit such a signal.
   *
   * @param position The first item that may have changed.
   * @param n_items Number of items with changes.
   */

  auto signal_selection_changed() -> Glib::SignalProxy<void(guint, guint)>;


protected:
  // For implementations only

  /** Helper function for implementations of `Gtk::SelectionModel`.
   *
   * Call this when a the selection changes to emit the
   * signal_selection_changed() signal.
   *
   * @param position The first changed item.
   * @param n_items The number of changed items.
   */
  void selection_changed(guint position, guint n_items);

    virtual auto is_selected_vfunc(guint position) const -> bool;


    virtual auto get_selection_vfunc(guint position, guint n_items) -> Glib::RefPtr<const Bitset>;

    virtual auto select_item_vfunc(guint position, bool unselect_rest) -> bool;

    virtual auto unselect_item_vfunc(guint position) -> bool;

    virtual auto select_range_vfunc(guint position, guint n_items, bool unselect_rest) -> bool;

    virtual auto unselect_range_vfunc(guint position, guint n_items) -> bool;

    virtual auto select_all_vfunc() -> bool;

    virtual auto unselect_all_vfunc() -> bool;


    virtual auto set_selection_vfunc(const Glib::RefPtr<const Bitset>& selected, const Glib::RefPtr<const Bitset>& mask) -> bool;


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
   * @relates Gtk::SelectionModel
   */
  GTKMM_API
  auto wrap(GtkSelectionModel* object, bool take_copy = false) -> Glib::RefPtr<Gtk::SelectionModel>;

} // namespace Glib


#endif /* _GTKMM_SELECTIONMODEL_H */

