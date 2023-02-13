
#ifndef _GTKMM_NOTEBOOKPAGE_H
#define _GTKMM_NOTEBOOKPAGE_H

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


#include <libmm-glib/object.hpp>
#include <libmm-glib/refptr.hpp>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkNotebookPage = struct _GtkNotebookPage;
using GtkNotebookPageClass = struct _GtkNotebookPageClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{ class GTKMM_API NotebookPage_Class; } // namespace Gtk
#endif //DOXYGEN_SHOULD_SKIP_THIS

namespace Gtk
{
class GTKMM_API Widget;

/** Holds properties of a Gtk::Notebook page.
 *
 * Use Gtk::Notebook::get_page() to get a pointer to a %NotebookPage object.
 *
 * @see Notebook
 * @newin{3,96}
 */

class GTKMM_API NotebookPage : public Glib::Object
{

#ifndef DOXYGEN_SHOULD_SKIP_THIS

public:
  using CppObjectType = NotebookPage;
  using CppClassType = NotebookPage_Class;
  using BaseObjectType = GtkNotebookPage;
  using BaseClassType = GtkNotebookPageClass;

  // noncopyable
  NotebookPage(const NotebookPage&) = delete;
  auto operator=(const NotebookPage&) -> NotebookPage& = delete;

private:  friend class NotebookPage_Class;
  static CppClassType notebookpage_class_;

protected:
  explicit NotebookPage(const Glib::ConstructParams& construct_params);
  explicit NotebookPage(GtkNotebookPage* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  NotebookPage(NotebookPage&& src) noexcept;
  auto operator=(NotebookPage&& src) noexcept -> NotebookPage&;

  ~NotebookPage() noexcept override;

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS


  static auto get_base_type() -> GType G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GObject.
  auto       gobj() -> GtkNotebookPage*       { return reinterpret_cast<GtkNotebookPage*>(gobject_); }

  ///Provides access to the underlying C GObject.
  auto gobj() const -> const GtkNotebookPage* { return reinterpret_cast<GtkNotebookPage*>(gobject_); }

  ///Provides access to the underlying C instance. The caller is responsible for unrefing it. Use when directly setting fields in structs.
  auto gobj_copy() -> GtkNotebookPage*;

private:


public:

  /** Returns the notebook child to which @a page belongs.
   *
   * @return The child to which @a page belongs.
   */
  auto get_child() -> Widget*;

  /** Returns the notebook child to which @a page belongs.
   *
   * @return The child to which @a page belongs.
   */
  auto get_child() const -> const Widget*;

  /** The child for this page.
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_child() const -> Glib::PropertyProxy_ReadOnly< Widget* >;


  /** The tab widget for tihs page.
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_tab() const -> Glib::PropertyProxy_ReadOnly< Widget* >;


  /** The label widget displayed in the childs menu entry.
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_menu() const -> Glib::PropertyProxy_ReadOnly< Widget* >;


  /** The text of the tab widget.
   *
   * Default value: ""
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_tab_label() -> Glib::PropertyProxy< Glib::ustring > ;

/** The text of the tab widget.
   *
   * Default value: ""
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_tab_label() const -> Glib::PropertyProxy_ReadOnly< Glib::ustring >;

  /** The text of the menu widget.
   *
   * Default value: ""
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_menu_label() -> Glib::PropertyProxy< Glib::ustring > ;

/** The text of the menu widget.
   *
   * Default value: ""
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_menu_label() const -> Glib::PropertyProxy_ReadOnly< Glib::ustring >;

  /** The index of the child in the parent.
   *
   * Default value: 0
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_position() -> Glib::PropertyProxy< int > ;

/** The index of the child in the parent.
   *
   * Default value: 0
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_position() const -> Glib::PropertyProxy_ReadOnly< int >;

  /** Whether to expand the childs tab.
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_tab_expand() -> Glib::PropertyProxy< bool > ;

/** Whether to expand the childs tab.
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_tab_expand() const -> Glib::PropertyProxy_ReadOnly< bool >;

  /** Whether the childs tab should fill the allocated area.
   *
   * Default value: <tt>true</tt>
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_tab_fill() -> Glib::PropertyProxy< bool > ;

/** Whether the childs tab should fill the allocated area.
   *
   * Default value: <tt>true</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_tab_fill() const -> Glib::PropertyProxy_ReadOnly< bool >;

  /** Whether the tab is reorderable by user action.
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_reorderable() -> Glib::PropertyProxy< bool > ;

/** Whether the tab is reorderable by user action.
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_reorderable() const -> Glib::PropertyProxy_ReadOnly< bool >;

  /** Whether the tab is detachable.
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_detachable() -> Glib::PropertyProxy< bool > ;

/** Whether the tab is detachable.
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_detachable() const -> Glib::PropertyProxy_ReadOnly< bool >;


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
   * @relates Gtk::NotebookPage
   */
  GTKMM_API
  auto wrap(GtkNotebookPage* object, bool take_copy = false) -> Glib::RefPtr<Gtk::NotebookPage>;
}


#endif /* _GTKMM_NOTEBOOKPAGE_H */

