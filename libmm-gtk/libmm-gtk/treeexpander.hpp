
#ifndef _GTKMM_TREEEXPANDER_H
#define _GTKMM_TREEEXPANDER_H

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


#include <mm/gtk/widget.hpp>
#include <mm/gtk/treelistrow.hpp>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{ class GTKMM_API TreeExpander_Class; } // namespace Gtk
#endif //DOXYGEN_SHOULD_SKIP_THIS

namespace Gtk
{

/** An indenting expander button for use in a tree list.
 *
 * %Gtk::TreeExpander is a widget that provides an expander for a list.
 *
 * It is typically placed as a bottommost child into a Gtk::ListView to allow
 * users to expand and collapse children in a list with a Gtk::TreeListModel.
 * It will provide the common UI elements, gestures and keybindings for this
 * purpose.
 *
 * On top of this, the "listitem.expand", "listitem.collapse" and
 * "listitem.toggle-expand" actions are provided to allow adding custom UI
 * for managing expanded state.
 *
 * The Gtk::TreeListModel must be set to not be passthrough. Then it will provide
 * Gtk::TreeListRow items which can be set via set_list_row()
 * on the expander. The expander will then watch that row item automatically.
 * set_child() sets the widget that displays the actual row contents.
 *
 * @see Gtk::TreeListModel
 *
 * @newin{3,98}
 */

class GTKMM_API TreeExpander : public Widget
{
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  typedef TreeExpander CppObjectType;
  typedef TreeExpander_Class CppClassType;
  typedef GtkTreeExpander BaseObjectType;
  typedef GtkTreeExpanderClass BaseClassType;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

  TreeExpander(TreeExpander&& src) noexcept;
  auto operator=(TreeExpander&& src) noexcept -> TreeExpander&;

  // noncopyable
  TreeExpander(const TreeExpander&) = delete;
  auto operator=(const TreeExpander&) -> TreeExpander& = delete;

  ~TreeExpander() noexcept override;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

private:
  friend GTKMM_API class TreeExpander_Class;
  static CppClassType treeexpander_class_;

protected:
  explicit TreeExpander(const Glib::ConstructParams& construct_params);
  explicit TreeExpander(GtkTreeExpander* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS


  static auto get_base_type() -> GType G_GNUC_CONST;
#endif

  /// Provides access to the underlying C GObject.
  auto       gobj() -> GtkTreeExpander*       { return reinterpret_cast<GtkTreeExpander*>(gobject_); }

  /// Provides access to the underlying C GObject.
  auto gobj() const -> const GtkTreeExpander* { return reinterpret_cast<GtkTreeExpander*>(gobject_); }

private:


public:
  TreeExpander();


  /** Gets the child widget displayed by @a self.
   *
   * @return The child displayed by @a self.
   */
  auto get_child() -> Widget*;

  /** Gets the child widget displayed by @a self.
   *
   * @return The child displayed by @a self.
   */
  auto get_child() const -> const Widget*;

  /** Sets the content widget to display.
   *
   * @param widget A `Gtk::Widget`.
   */
  void set_child(Widget& widget);
  /** Removes the content widget to display.
   */
  void unset_child();


  /** Forwards the item set on the `Gtk::TreeListRow` that @a self is managing.
   *
   * This call is essentially equivalent to calling:
   *
   *
   * [C example ellipted]
   *
   * @return The item of the row.
   */
  auto get_item() -> Glib::RefPtr<Glib::ObjectBase>;

  /** Forwards the item set on the `Gtk::TreeListRow` that @a self is managing.
   *
   * This call is essentially equivalent to calling:
   *
   *
   * [C example ellipted]
   *
   * @return The item of the row.
   */
  auto get_item() const -> Glib::RefPtr<const Glib::ObjectBase>;


  /** Gets the list row managed by @a self.
   *
   * @return The list row displayed by @a self.
   */
  auto get_list_row() -> Glib::RefPtr<TreeListRow>;

  /** Gets the list row managed by @a self.
   *
   * @return The list row displayed by @a self.
   */
  auto get_list_row() const -> Glib::RefPtr<const TreeListRow>;

  /** Sets the tree list row that this expander should manage.
   *
   * @param list_row A `Gtk::TreeListRow`.
   */
  void set_list_row(const Glib::RefPtr<TreeListRow>& list_row);
  /** Removes the tree list row that this expander should manage.
   */
  void unset_list_row();


  /** TreeExpander indents the child by the width of an expander-icon if it is not expandable.
   *
   * @newin{4,6}
   *
   * @return <tt>true</tt> if the child should be indented when not expandable. Otherwise <tt>false</tt>.
   */
  auto get_indent_for_icon() const -> bool;

  /** Sets if the TreeExpander should indent the child by the width of an expander-icon when it is not expandable.
   *
   * @newin{4,6}
   *
   * @param indent_for_icon <tt>true</tt> if the child should be indented without expander. Otherwise <tt>false</tt>.
   */
  void set_indent_for_icon(bool indent_for_icon =  true);

  /** The child widget with the actual contents.
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_child() -> Glib::PropertyProxy< Widget* > ;

/** The child widget with the actual contents.
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_child() const -> Glib::PropertyProxy_ReadOnly< Widget* >;

  /** The item held by this expander's row.
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_item() const -> Glib::PropertyProxy_ReadOnly< Glib::RefPtr<Glib::ObjectBase> >;


  /** The list row to track for expander state.
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_list_row() -> Glib::PropertyProxy< Glib::RefPtr<TreeListRow> > ;

/** The list row to track for expander state.
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_list_row() const -> Glib::PropertyProxy_ReadOnly< Glib::RefPtr<TreeListRow> >;

  /** TreeExpander indents the child by the width of an expander-icon if it is not expandable.
   *
   * @newin{4,6}
   *
   * Default value: <tt>true</tt>
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_indent_for_icon() -> Glib::PropertyProxy< bool > ;

/** TreeExpander indents the child by the width of an expander-icon if it is not expandable.
   *
   * @newin{4,6}
   *
   * Default value: <tt>true</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_indent_for_icon() const -> Glib::PropertyProxy_ReadOnly< bool >;


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
   * @relates Gtk::TreeExpander
   */
  GTKMM_API
  auto wrap(GtkTreeExpander* object, bool take_copy = false) -> Gtk::TreeExpander*;
} //namespace Glib


#endif /* _GTKMM_TREEEXPANDER_H */

