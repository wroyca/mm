
#ifndef _GTKMM_FLOWBOXCHILD_H
#define _GTKMM_FLOWBOXCHILD_H


#include <libmm-glib/ustring.hxx>
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

#include <libmm-gtk/widget.hxx>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkFlowBoxChild = struct _GtkFlowBoxChild;
using GtkFlowBoxChildClass = struct _GtkFlowBoxChildClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{ class GTKMM_API FlowBoxChild_Class; } // namespace Gtk
#endif //DOXYGEN_SHOULD_SKIP_THIS

namespace Gtk
{

/** See the description of FlowBox.
 *
 * @ingroup Widgets
 * @ingroup Containers
 *
 * @newin{3,12}
 */

class GTKMM_API FlowBoxChild
  : public Widget
{
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  typedef FlowBoxChild CppObjectType;
  typedef FlowBoxChild_Class CppClassType;
  typedef GtkFlowBoxChild BaseObjectType;
  typedef GtkFlowBoxChildClass BaseClassType;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

  FlowBoxChild(FlowBoxChild&& src) noexcept;
  auto operator=(FlowBoxChild&& src) noexcept -> FlowBoxChild&;

  // noncopyable
  FlowBoxChild(const FlowBoxChild&) = delete;
  auto operator=(const FlowBoxChild&) -> FlowBoxChild& = delete;

  ~FlowBoxChild() noexcept override;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

private:
  friend GTKMM_API class FlowBoxChild_Class;
  static CppClassType flowboxchild_class_;

protected:
  explicit FlowBoxChild(const Glib::ConstructParams& construct_params);
  explicit FlowBoxChild(GtkFlowBoxChild* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS


  static auto get_base_type() -> GType G_GNUC_CONST;
#endif

  /// Provides access to the underlying C GObject.
  auto       gobj() -> GtkFlowBoxChild*       { return reinterpret_cast<GtkFlowBoxChild*>(gobject_); }

  /// Provides access to the underlying C GObject.
  auto gobj() const -> const GtkFlowBoxChild* { return reinterpret_cast<GtkFlowBoxChild*>(gobject_); }

private:

public:

  /** Creates a new FlowBoxChild, to be used as a child of a FlowBox.
   */
  FlowBoxChild();


  /** Sets the child widget of @a self.
   *
   * @param child The child widget.
   */
  void set_child(Widget& child);
  void unset_child();

  /** Gets the child widget of @a self.
   *
   * @return The child widget of @a self.
   */
  auto get_child() -> Widget*;

  /** Gets the child widget of @a self.
   *
   * @return The child widget of @a self.
   */
  auto get_child() const -> const Widget*;

  /** Gets the current index of the @a child in its `Gtk::FlowBox` container.
   *
   * @return The index of the @a child, or -1 if the @a child is not
   * in a flow box.
   */
  auto get_index() const -> int;

  /** Returns whether the @a child is currently selected in its
   * `Gtk::FlowBox` container.
   *
   * @return <tt>true</tt> if @a child is selected.
   */
  auto is_selected() const -> bool;

  /** Marks @a child as changed, causing any state that depends on this
   * to be updated.
   *
   * This affects sorting and filtering.
   *
   * Note that calls to this method must be in sync with the data
   * used for the sorting and filtering functions. For instance, if
   * the list is mirroring some external data set, and *two* children
   * changed in the external data set when you call
   * changed() on the first child, the sort function
   * must only read the new data for the first of the two changed
   * children, otherwise the resorting of the children will be wrong.
   *
   * This generally means that if you don’t fully control the data
   * model, you have to duplicate the data that affects the sorting
   * and filtering functions into the widgets themselves.
   *
   * Another alternative is to call invalidate_sort()
   * on any model change, but that is more expensive.
   */
  void changed();


  /**
   * @par Slot Prototype:
   * <tt>void on_my_%activate()</tt>
   *
   * Flags: Run First, Action
   *
   * Emitted when the user activates a child widget in a `Gtk::FlowBox`.
   *
   * This can be happen either by clicking or double-clicking,
   * or via a keybinding.
   *
   * This is a [keybinding signal](class.SignalAction.html),
   * but it can be used by applications for their own purposes.
   *
   * The default bindings are <kbd>Space</kbd> and <kbd>Enter</kbd>.
   */

  auto signal_activate() -> Glib::SignalProxy<void()>;


  /** The child widget.
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_child() -> Glib::PropertyProxy< Widget* > ;

/** The child widget.
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_child() const -> Glib::PropertyProxy_ReadOnly< Widget* >;


public:

public:
  //C++ methods used to invoke GTK+ virtual functions:

protected:
  //GTK+ Virtual Functions (override these to change behaviour):

  //Default Signal Handlers::
  /// This is a default handler for the signal signal_activate().
  virtual void on_activate();


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
   * @relates Gtk::FlowBoxChild
   */
  GTKMM_API
  auto wrap(GtkFlowBoxChild* object, bool take_copy = false) -> Gtk::FlowBoxChild*;
} //namespace Glib


#endif /* _GTKMM_FLOWBOXCHILD_H */

