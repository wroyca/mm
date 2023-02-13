
#ifndef _GTKMM_FLOWBOX_H
#define _GTKMM_FLOWBOX_H


#include <libmm-glib/ustring.hpp>
#include <sigc++/sigc++.h>

/* Copyright (C) 2014 The gtkmm Development Team
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

#include <libmm-gtk/widget.hpp>
#include <libmm-gtk/orientable.hpp>
#include <libmm-gtk/flowboxchild.hpp>
#include <libmm-gio/liststore.hpp>
#include <libmm-glib/exceptionhandler.hpp>
#include <vector>
#include <utility> // std::forward


#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkFlowBox = struct _GtkFlowBox;
using GtkFlowBoxClass = struct _GtkFlowBoxClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{ class GTKMM_API FlowBox_Class; } // namespace Gtk
#endif //DOXYGEN_SHOULD_SKIP_THIS

namespace Gtk
{

/** A container that allows reflowing its children.
 *
 * A %FlowBox positions child widgets in sequence according to its
 * orientation.
 *
 * For instance, with the horizontal orientation, the widgets will be
 * arranged from left to right, starting a new row under the previous
 * row when necessary. Reducing the width in this case will require more
 * rows, so a larger height will be requested.
 *
 * Likewise, with the vertical orientation, the widgets will be arranged
 * from top to bottom, starting a new column to the right when necessary.
 * Reducing the height will require more columns, so a larger width will
 * be requested.
 *
 * The children of a FlowBox can be dynamically sorted and filtered.
 *
 * Although a %FlowBox must have only FlowBoxChild children,
 * you can add any kind of widget to it via insert(), and
 * a FlowBoxChild widget will automatically be inserted between
 * the box and the widget.
 *
 * Also see ListBox.
 *
 * @ingroup Widgets
 * @ingroup Containers
 *
 * @newin{3,12}
 */

class GTKMM_API FlowBox
  : public Widget,
    public Orientable
{
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  typedef FlowBox CppObjectType;
  typedef FlowBox_Class CppClassType;
  typedef GtkFlowBox BaseObjectType;
  typedef GtkFlowBoxClass BaseClassType;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

  FlowBox(FlowBox&& src) noexcept;
  auto operator=(FlowBox&& src) noexcept -> FlowBox&;

  // noncopyable
  FlowBox(const FlowBox&) = delete;
  auto operator=(const FlowBox&) -> FlowBox& = delete;

  ~FlowBox() noexcept override;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

private:
  friend GTKMM_API class FlowBox_Class;
  static CppClassType flowbox_class_;

protected:
  explicit FlowBox(const Glib::ConstructParams& construct_params);
  explicit FlowBox(GtkFlowBox* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS


  static auto get_base_type() -> GType G_GNUC_CONST;
#endif

  /// Provides access to the underlying C GObject.
  auto       gobj() -> GtkFlowBox*       { return reinterpret_cast<GtkFlowBox*>(gobject_); }

  /// Provides access to the underlying C GObject.
  auto gobj() const -> const GtkFlowBox* { return reinterpret_cast<GtkFlowBox*>(gobject_); }

private:


public:

  /** Creates a FlowBox.
   */
  FlowBox();

  /** For instance: void foreach_child(FlowBox* box, FlowBoxChild* child);
   *
   * A function used by FlowBox::selected_foreach().
   * It will be called on every selected child of the @a box.
   *
   * @param box FlowBox containing the selected children
   * @param child Each selected FlowBoxChild
   *
   * @newin{3,12}
   */
  typedef sigc::slot<void(FlowBox*, FlowBoxChild*)> SlotSelectedForeach;

  /** For instance: bool on_filter(FlowBoxChild* child);
   *
   * Will be called for each child after a call to FlowBox::set_filter_func(),
   * and it will continue to be called each time a child changes (via
   * FlowBoxChild::changed()) or when FlowBox::invalidate_filter()
   * is called.
   *
   * @param child A FlowBoxChild that may be filtered
   * @returns <tt>true</tt> if the child should be visible, <tt>false</tt> otherwise
   *
   * @newin{3,12}
   */
  typedef sigc::slot<bool(FlowBoxChild*)> SlotFilter;

  /** For instance: int on_sort(FlowBoxChild* child1, FlowBoxChild* child2)
   *
   * Will be called for each child after a call to FlowBox::set_sort_func(),
   * and will continue to be called each time a child changes (via
   * FlowBoxChild::changed()) and when FlowBox::invalidate_sort()
   * is called.
   *
   * @param child1 The first child.
   * @param child2 The second child.
   * @returns < 0 if @a child1 should be before @a child2, 0 if
   * they are equal, and > 0 otherwise
   *
   * @newin{3,12}
   */
  typedef sigc::slot<int(FlowBoxChild*, FlowBoxChild*)> SlotSort;


  /** Sets whether or not all children of @a box are given
   * equal space in the box.
   *
   * @param homogeneous <tt>true</tt> to create equal allotments,
   * <tt>false</tt> for variable allotments.
   */
  void set_homogeneous(bool homogeneous =  true);

  /** Returns whether the box is homogeneous.
   *
   * @return <tt>true</tt> if the box is homogeneous.
   */
  auto get_homogeneous() const -> bool;


  /** Sets the vertical space to add between children.
   *
   * @param spacing The spacing to use.
   */
  void set_row_spacing(guint spacing);

  /** Gets the vertical spacing.
   *
   * @return The vertical spacing.
   */
  auto get_row_spacing() const -> guint;


  /** Sets the horizontal space to add between children.
   *
   * @param spacing The spacing to use.
   */
  void set_column_spacing(guint spacing);

  /** Gets the horizontal spacing.
   *
   * @return The horizontal spacing.
   */
  auto get_column_spacing() const -> guint;


  /** Sets the minimum number of children to line up
   * in @a box’s orientation before flowing.
   *
   * @param n_children The minimum number of children per line.
   */
  void set_min_children_per_line(guint n_children);

  /** Gets the minimum number of children per line.
   *
   * @return The minimum number of children per line.
   */
  auto get_min_children_per_line() const -> guint;


  /** Sets the maximum number of children to request and
   * allocate space for in @a box’s orientation.
   *
   * Setting the maximum number of children per line
   * limits the overall natural size request to be no more
   * than @a n_children children long in the given orientation.
   *
   * @param n_children The maximum number of children per line.
   */
  void set_max_children_per_line(guint n_children);

  /** Gets the maximum number of children per line.
   *
   * @return The maximum number of children per line.
   */
  auto get_max_children_per_line() const -> guint;


  /** If @a single is <tt>true</tt>, children will be activated when you click
   * on them, otherwise you need to double-click.
   *
   * @param single <tt>true</tt> to emit child-activated on a single click.
   */
  void set_activate_on_single_click(bool single =  true);

  /** Returns whether children activate on single clicks.
   *
   * @return <tt>true</tt> if children are activated on single click,
   * <tt>false</tt> otherwise.
   */
  auto get_activate_on_single_click() const -> bool;


  /** Adds @a child to the start of @a self.
   *
   * If a sort function is set, the widget will
   * actually be inserted at the calculated position.
   *
   * See also: insert().
   *
   * @newin{4,6}
   *
   * @param child The `Gtk::Widget` to add.
   */
  void prepend(Widget& child);

  /** Adds @a child to the end of @a self.
   *
   * If a sort function is set, the widget will
   * actually be inserted at the calculated position.
   *
   * See also: insert().
   *
   * @newin{4,6}
   *
   * @param child The `Gtk::Widget` to add.
   */
  void append(Widget& child);

  /** Inserts the @a widget into @a box at @a position.
   *
   * If a sort function is set, the widget will actually be inserted
   * at the calculated position.
   *
   * If @a position is -1, or larger than the total number of children
   * in the @a box, then the @a widget will be appended to the end.
   *
   * @param widget The `Gtk::Widget` to add.
   * @param position The position to insert @a child in.
   */
  void insert(Widget& widget, int position);

  /** Removes a child from @a box.
   *
   * @param widget The child widget to remove.
   */
  void remove(Widget& widget);


  /** Gets the nth child in the @a box.
   *
   * @param idx The position of the child.
   * @return The child widget, which will
   * always be a `Gtk::FlowBoxChild` or <tt>nullptr</tt> in case no child widget
   * with the given index exists.
   */
  auto get_child_at_index(int idx) -> FlowBoxChild*;

  /** Gets the nth child in the @a box.
   *
   * @param idx The position of the child.
   * @return The child widget, which will
   * always be a `Gtk::FlowBoxChild` or <tt>nullptr</tt> in case no child widget
   * with the given index exists.
   */
  auto get_child_at_index(int idx) const -> const FlowBoxChild*;


  /** Gets the child in the ( @a x, @a y) position.
   *
   * Both @a x and @a y are assumed to be relative to the origin of @a box.
   *
   * @param x The x coordinate of the child.
   * @param y The y coordinate of the child.
   * @return The child widget, which will
   * always be a `Gtk::FlowBoxChild` or <tt>nullptr</tt> in case no child widget
   * exists for the given x and y coordinates.
   */
  auto get_child_at_pos(int x, int y) -> FlowBoxChild*;

  /** Gets the child in the ( @a x, @a y) position.
   *
   * Both @a x and @a y are assumed to be relative to the origin of @a box.
   *
   * @param x The x coordinate of the child.
   * @param y The y coordinate of the child.
   * @return The child widget, which will
   * always be a `Gtk::FlowBoxChild` or <tt>nullptr</tt> in case no child widget
   * exists for the given x and y coordinates.
   */
  auto get_child_at_pos(int x, int y) const -> const FlowBoxChild*;

  /** Calls a function for each selected child.
   *
   * Note that the selection cannot be modified from within
   * this function.
   *
   * @param slot The function to call for each selected child
   *
   * @newin{3,12}
   */
  void selected_foreach(const SlotSelectedForeach& slot);


  // transfer container


  /** Creates a list of all selected children.
   *
   * @return A `GList` containing the `Gtk::Widget` for each selected child.
   */
  auto get_selected_children() -> std::vector< Gtk::FlowBoxChild*>;


  /** Creates a list of all selected children.
   *
   * @return A `GList` containing the `Gtk::Widget` for each selected child.
   */
  auto get_selected_children() const -> std::vector< const Gtk::FlowBoxChild*>;


  /** Selects a single child of @a box, if the selection
   * mode allows it.
   *
   * @param child A child of @a box.
   */
  void select_child(FlowBoxChild& child);

  /** Unselects a single child of @a box, if the selection
   * mode allows it.
   *
   * @param child A child of @a box.
   */
  void unselect_child(FlowBoxChild& child);


  /** Select all children of @a box, if the selection
   * mode allows it.
   */
  void select_all();

  /** Unselect all children of @a box, if the selection
   * mode allows it.
   */
  void unselect_all();


  /** Sets how selection works in @a box.
   *
   * @param mode The new selection mode.
   */
  void set_selection_mode(SelectionMode mode =  SelectionMode::NONE);

  /** Gets the selection mode of @a box.
   *
   * @return The `Gtk::SelectionMode`.
   */
  auto get_selection_mode() const -> SelectionMode;


  /** Hooks up an adjustment to focus handling in @a box.
   *
   * The adjustment is also used for autoscrolling during
   * rubberband selection. See Gtk::ScrolledWindow::get_hadjustment()
   * for a typical way of obtaining the adjustment, and
   * set_vadjustment() for setting the vertical
   * adjustment.
   *
   * The adjustments have to be in pixel units and in the same
   * coordinate system as the allocation for immediate children
   * of the box.
   *
   * @param adjustment An adjustment which should be adjusted
   * when the focus is moved among the descendents of @a container.
   */
  void set_hadjustment(const Glib::RefPtr<Adjustment>& adjustment);

  /** Hooks up an adjustment to focus handling in @a box.
   *
   * The adjustment is also used for autoscrolling during
   * rubberband selection. See Gtk::ScrolledWindow::get_vadjustment()
   * for a typical way of obtaining the adjustment, and
   * set_hadjustment() for setting the horizontal
   * adjustment.
   *
   * The adjustments have to be in pixel units and in the same
   * coordinate system as the allocation for immediate children
   * of the box.
   *
   * @param adjustment An adjustment which should be adjusted
   * when the focus is moved among the descendents of @a container.
   */
  void set_vadjustment(const Glib::RefPtr<Adjustment>& adjustment);

  /** Sets a filter function.
   *
   * By setting a filter function on the FlowBox one can decide dynamically
   * which of the children to show. For instance, to implement a search
   * function that only shows the children matching the search terms.
   *
   * The @a slot will be called for each child after the call, and
   * it will continue to be called each time a child changes (via
   * FlowBoxChild::changed()) or when FlowBox::invalidate_filter()
   * is called.
   *
   * @param slot Callback that lets you filter which children to show
   *
   * @newin{3,12}
   */
  void set_filter_func(const SlotFilter& slot);


  /** Removes the filter function, if any.
   *
   * @newin{3,12}
   */
  void unset_filter_func();


  /** Updates the filtering for all children.
   *
   * Call this function when the result of the filter
   * function on the @a box is changed due ot an external
   * factor. For instance, this would be used if the
   * filter function just looked for a specific search
   * term, and the entry with the string has changed.
   */
  void invalidate_filter();

  /** Sets a sort function.
   *
   * By setting a sort function on the FlowBox, one can dynamically
   * reorder the children of the box, based on the contents of
   * the children.
   *
   * The @a slot will be called for each child after the call,
   * and will continue to be called each time a child changes (via
   * FlowBoxChild::changed()) and when FlowBox::invalidate_sort()
   * is called.
   *
   * @param slot The sort function
   *
   * @newin{3,12}
   */
  void set_sort_func(const SlotSort& slot);


  /** Removes the sort function, if any.
   *
   * @newin{3,12}
   */
  void unset_sort_func();


  /** Updates the sorting for all children.
   *
   * Call this when the result of the sort function on
   *  @a box is changed due to an external factor.
   */
  void invalidate_sort();

  /** For instance:
   * Gtk::Widget* on_create_widget(const Glib::RefPtr<T_item>& item);
   *
   * Called for flow boxes that are bound to a Gio::ListModel with bind_model()
   * or bind_list_store() for each item that gets added to the model.
   *
   * @newin{3,22}
   *
   * @tparam T_item Base class of the items in the Gio::ListModel. All items must
   *                be of type T_item or a type derived from T_item.
   *                T_item must be Glib::Object or a type derived from Glib::Object.
   * @param item The item from the model for which to create a widget.
   * @return A Gtk::Widget that represents @a item.
   */
  template <typename T_item>
  using SlotCreateWidget = sigc::slot<Gtk::Widget*(const Glib::RefPtr<T_item>&)>;

  /** Binds a Gio::ListModel.
   *
   * If this FlowBox was already bound to a model, that previous binding is
   * destroyed.
   *
   * The contents of the FlowBox are cleared and then filled with widgets that
   * represent items from @a model. The FlowBox is updated whenever @a model changes.
   * If @a model is an empty Glib::RefPtr, the FlowBox is left empty.
   *
   * It is undefined to add or remove widgets directly (for example, with
   * insert() or Gtk::Container::add()) while the FlowBox is bound to a model.
   *
   * Note that using a model is incompatible with the filtering and sorting
   * functionality in FlowBox. When using a model, filtering and sorting
   * should be implemented by the model.
   *
   * @newin{3,22}
   *
   * @param model The Gio::ListModel to be bound.
   * @param slot_create_widget A slot that creates widgets for items.
   *
   * @see bind_list_store()
   */
  void bind_model(const Glib::RefPtr<Gio::ListModel>& model,
    const SlotCreateWidget<Glib::Object>& slot_create_widget);


  /** Binds a Gio::ListStore<>.
   *
   * If this FlowBox was already bound to a Gio::ListModel, that previous binding is
   * destroyed. (Gio::ListStore is a Gio::ListModel.)
   *
   * The contents of the FlowBox are cleared and then filled with widgets that
   * represent items from @a store. The FlowBox is updated whenever @a store changes.
   * If @a store is an empty Glib::RefPtr, the FlowBox is left empty.
   *
   * It is undefined to add or remove widgets directly (for example, with
   * insert() or Gtk::Container::add()) while the FlowBox is bound to a model.
   *
   * Note that using a model is incompatible with the filtering and sorting
   * functionality in FlowBox. When using a model, filtering and sorting
   * should be implemented by the model.
   *
   * @newin{3,22}
   *
   * @tparam T_item Base class of the items in the Gio::ListStore. All items must
   *                be of type T_item or a type derived from T_item.
   *                T_item must be Glib::Object or a type derived from Glib::Object.
   * @tparam T_slot SlotCreateWidget<T_item> or a type that can be converted
   *                to SlotCreateWidget<T_item>.
   * @param store The Gio::ListStore<> to be bound.
   * @param slot_create_widget A slot that creates widgets for items.
   */
  template <typename T_item, typename T_slot>
  void bind_list_store(const Glib::RefPtr<Gio::ListStore<T_item>>& store,
    T_slot&& slot_create_widget);

  /** The selection mode used by the flow box.
   *
   * Default value: Gtk::SelectionMode::SINGLE
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_selection_mode() -> Glib::PropertyProxy< SelectionMode > ;

/** The selection mode used by the flow box.
   *
   * Default value: Gtk::SelectionMode::SINGLE
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_selection_mode() const -> Glib::PropertyProxy_ReadOnly< SelectionMode >;

  /** Determines whether children can be activated with a single
   * click, or require a double-click.
   *
   * Default value: <tt>true</tt>
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_activate_on_single_click() -> Glib::PropertyProxy< bool > ;

/** Determines whether children can be activated with a single
   * click, or require a double-click.
   *
   * Default value: <tt>true</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_activate_on_single_click() const -> Glib::PropertyProxy_ReadOnly< bool >;

  /** Default value: <tt>false</tt>
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_accept_unpaired_release() -> Glib::PropertyProxy< bool > ;

/** Default value: <tt>false</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_accept_unpaired_release() const -> Glib::PropertyProxy_ReadOnly< bool >;

  /** Determines whether all children should be allocated the
   * same size.
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_homogeneous() -> Glib::PropertyProxy< bool > ;

/** Determines whether all children should be allocated the
   * same size.
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_homogeneous() const -> Glib::PropertyProxy_ReadOnly< bool >;

  /** The minimum number of children to allocate consecutively
   * in the given orientation.
   *
   * Setting the minimum children per line ensures
   * that a reasonably small height will be requested
   * for the overall minimum width of the box.
   *
   * Default value: 0
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_min_children_per_line() -> Glib::PropertyProxy< guint > ;

/** The minimum number of children to allocate consecutively
   * in the given orientation.
   *
   * Setting the minimum children per line ensures
   * that a reasonably small height will be requested
   * for the overall minimum width of the box.
   *
   * Default value: 0
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_min_children_per_line() const -> Glib::PropertyProxy_ReadOnly< guint >;

  /** The maximum amount of children to request space for consecutively
   * in the given orientation.
   *
   * Default value: 7
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_max_children_per_line() -> Glib::PropertyProxy< guint > ;

/** The maximum amount of children to request space for consecutively
   * in the given orientation.
   *
   * Default value: 7
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_max_children_per_line() const -> Glib::PropertyProxy_ReadOnly< guint >;

  /** The amount of vertical space between two children.
   *
   * Default value: 0
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_row_spacing() -> Glib::PropertyProxy< guint > ;

/** The amount of vertical space between two children.
   *
   * Default value: 0
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_row_spacing() const -> Glib::PropertyProxy_ReadOnly< guint >;

  /** The amount of horizontal space between two children.
   *
   * Default value: 0
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_column_spacing() -> Glib::PropertyProxy< guint > ;

/** The amount of horizontal space between two children.
   *
   * Default value: 0
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_column_spacing() const -> Glib::PropertyProxy_ReadOnly< guint >;


  // no_default_handler because GtkFlowBoxClass is private.

  /**
   * @par Slot Prototype:
   * <tt>void on_my_%child_activated(FlowBoxChild* child)</tt>
   *
   * Flags: Run Last
   *
   * Emitted when a child has been activated by the user.
   *
   * @param child The child that is activated.
   */

  auto signal_child_activated() -> Glib::SignalProxy<void(FlowBoxChild*)>;


  /**
   * @par Slot Prototype:
   * <tt>void on_my_%selected_children_changed()</tt>
   *
   * Flags: Run First
   *
   * Emitted when the set of selected children changes.
   *
   * Use Gtk::FlowBox::selected_foreach() or
   * Gtk::FlowBox::get_selected_children() to obtain the
   * selected children.
   */

  auto signal_selected_children_changed() -> Glib::SignalProxy<void()>;

   // Action signals

private:
  template <typename T_item>
  static auto proxy_bind_list_store_create_widget_callback(void* item, void* data) -> GtkWidget*;


public:

public:
  //C++ methods used to invoke GTK+ virtual functions:

protected:
  //GTK+ Virtual Functions (override these to change behaviour):

  //Default Signal Handlers::


};

#ifndef DOXYGEN_SHOULD_SKIP_THIS

template <typename T_item, typename T_slot>
void FlowBox::bind_list_store(const Glib::RefPtr<Gio::ListStore<T_item>>& store,
  T_slot&& slot_create_widget)
{
  // Create a copy of the slot.
  // It will be deleted by Glib::destroy_notify_delete<SlotCreateWidget>.
  auto slot_copy = new SlotCreateWidget<T_item>(std::forward<T_slot>(slot_create_widget));

  gtk_flow_box_bind_model(gobj(),
    store ? store->Gio::ListModel::gobj() : nullptr,
    &proxy_bind_list_store_create_widget_callback<T_item>,
    slot_copy, &Glib::destroy_notify_delete<SlotCreateWidget<T_item>>);
}

template <typename T_item>
auto FlowBox::proxy_bind_list_store_create_widget_callback(void* item, void* data) -> GtkWidget*
{
  auto& slot = *static_cast<SlotCreateWidget<T_item>*>(data);
  auto cobject = static_cast<typename T_item::BaseObjectType*>(item);

  try
  {
    // cast_dynamic is necessary if T_item is a user-defined type, such as
    // class MyObject : public Glib::Object
    // take_copy is true here, because wrap() returns a Glib::RefPtr<>.
    // cobject will be unreferenced when the RefPtr is deleted.
    Gtk::Widget* widget = slot(std::dynamic_pointer_cast<T_item>(Glib::wrap(cobject, true)));
    if (widget)
      return widget->gobj();
  }
  catch(...)
  {
    Glib::exception_handlers_invoke();
  }
  return nullptr;
}

#endif // DOXYGEN_SHOULD_SKIP_THIS

} // namespace Gtk


namespace Glib
{
  /** A Glib::wrap() method for this object.
   *
   * @param object The C instance.
   * @param take_copy False if the result should take ownership of the C instance. True if it should take a new copy or ref.
   * @result A C++ instance that wraps this C instance.
   *
   * @relates Gtk::FlowBox
   */
  GTKMM_API
  auto wrap(GtkFlowBox* object, bool take_copy = false) -> Gtk::FlowBox*;
} //namespace Glib


#endif /* _GTKMM_FLOWBOX_H */

