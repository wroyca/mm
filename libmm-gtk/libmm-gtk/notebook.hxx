
#ifndef _GTKMM_NOTEBOOK_H
#define _GTKMM_NOTEBOOK_H

#include <libmm-gtk/mm-gtkconfig.hxx>


#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

/*
 * Copyright (C) 1998-2002 The gtkmm Development Team
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
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 */


#include <libmm-gio/listmodel.hxx>
#include <libmm-gtk/widget.hxx>
#include <libmm-gtk/label.hxx>
#include <libmm-gtk/notebookpage.hxx>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkNotebook = struct _GtkNotebook;
using GtkNotebookClass = struct _GtkNotebookClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{ class GTKMM_API Notebook_Class; } // namespace Gtk
#endif //DOXYGEN_SHOULD_SKIP_THIS

namespace Gtk
{


/** Container which shows one of its children at a time, in tabbed windows.
 *
 * The Gtk::Notebook widget is a layout container whose children are pages that
 * can be switched between using tab labels along one edge.
 *
 * A Notebook widget looks like this:
 * @image html notebook1.png
 *
 * @ingroup Widgets
 * @ingroup Containers
 */

class GTKMM_API Notebook : public Widget
{
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  typedef Notebook CppObjectType;
  typedef Notebook_Class CppClassType;
  typedef GtkNotebook BaseObjectType;
  typedef GtkNotebookClass BaseClassType;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

  Notebook(Notebook&& src) noexcept;
  auto operator=(Notebook&& src) noexcept -> Notebook&;

  // noncopyable
  Notebook(const Notebook&) = delete;
  auto operator=(const Notebook&) -> Notebook& = delete;

  ~Notebook() noexcept override;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

private:
  friend GTKMM_API class Notebook_Class;
  static CppClassType notebook_class_;

protected:
  explicit Notebook(const Glib::ConstructParams& construct_params);
  explicit Notebook(GtkNotebook* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS


  static auto get_base_type() -> GType G_GNUC_CONST;
#endif

  /// Provides access to the underlying C GObject.
  auto       gobj() -> GtkNotebook*       { return reinterpret_cast<GtkNotebook*>(gobject_); }

  /// Provides access to the underlying C GObject.
  auto gobj() const -> const GtkNotebook* { return reinterpret_cast<GtkNotebook*>(gobject_); }

private:


public:

  Notebook();


  /** Prepends a page to @a notebook.
   *
   * @param child The Gtk::Widget to use as the contents of the page.
   * @param tab_label The Gtk::Widget to be used as the label for the page.
   */
  auto prepend_page(Widget& child, Widget& tab_label) -> int;
  auto prepend_page(Widget& child) -> int;

  auto prepend_page(Widget& child, const Glib::ustring& tab_label, bool use_mnemonic = false) -> int;

  /** Prepends a page to @a notebook, specifying the widget to use as the
   * label in the popup menu.
   *
   * @param child The Gtk::Widget to use as the contents of the page.
   * @param tab_label The Gtk::Widget to be used as the label for the page.
   * @param menu_label The widget to use as a label for the page-switch
   * menu.
   */
  auto prepend_page(Widget& child, Widget& tab_label, Widget& menu_label) -> int;
  //Ignore the possible-0 menu_label version of this method. It would have the same signature as another method.

  auto prepend_page(Widget& child, const Glib::ustring& tab_label, const Glib::ustring& menu_label, bool use_mnemonic) -> int;


  /** Appends a page to @a notebook.
   *
   * @param child The Gtk::Widget to use as the contents of the page.
   * @param tab_label The Gtk::Widget to be used as the label for the page.
   */
  auto append_page(Widget& child, Widget& tab_label) -> int;
  auto append_page(Widget& child) -> int;
  auto append_page(Widget& child, const Glib::ustring& tab_label, bool use_mnemonic = false) -> int;


  /** Appends a page to @a notebook, specifying the widget to use as the
   * label in the popup menu.
   *
   * @param child The Gtk::Widget to use as the contents of the page.
   * @param tab_label The Gtk::Widget to be used as the label for the page.
   * @param menu_label The widget to use as a label for the page-switch
   * menu.
   */
  auto append_page(Widget& child, Widget& tab_label, Widget& menu_label) -> int;
  //Ignore the possible-0 menu_label version of this method. It would have the same signature as another method.

  auto append_page(Widget& child, const Glib::ustring& tab_label, const Glib::ustring& menu_label, bool use_mnemonic = false) -> int;


  /** Insert a page into @a notebook at the given position.
   *
   * @param child The Gtk::Widget to use as the contents of the page.
   * @param tab_label The Gtk::Widget to be used as the label for the page.
   * @param position The index (starting at 0) at which to insert the page,
   * or -1 to append the page after all other pages.
   */
  auto insert_page(Widget& child, Widget& tab_label, int position) -> int;
  auto insert_page(Widget& child, int position) -> int;

  auto insert_page(Widget& child, const Glib::ustring& tab_label, int position, bool use_mnemonic = false) -> int;

  /** Insert a page into @a notebook at the given position, specifying
   * the widget to use as the label in the popup menu.
   *
   * @param child The Gtk::Widget to use as the contents of the page.
   * @param tab_label The Gtk::Widget to be used as the label for the page..
   * @param menu_label The widget to use as a label for the page-switch
   * menu.
   * @param position The index (starting at 0) at which to insert the page,
   * or -1 to append the page after all other pages.
   */
  auto insert_page(Widget& child, Widget& tab_label, Widget& menu_label, int position) -> int;
  //Ignore the possible-0 menu_label version of this method. It would have the same signature as another method.

  auto insert_page(Widget& child, const Glib::ustring& tab_label, const Glib::ustring& menu_label, int position, bool use_mnemonic = false) -> int;


  /** Removes a page from the notebook given its index
   * in the notebook.
   *
   * @param page_number The index of a notebook page, starting
   * from 0. If -1, the last page will be removed.
   */
  void remove_page(int page_number =  0);
  void remove_page(Widget& child);


  /** Sets a group name for @a notebook.
   *
   * Notebooks with the same name will be able to exchange tabs
   * via drag and drop. A notebook with a <tt>nullptr</tt> group name will
   * not be able to exchange tabs with any other notebook.
   *
   * @param group_name The name of the notebook group,
   * or <tt>nullptr</tt> to unset it.
   */
  void set_group_name(const Glib::ustring& group_name);

  /** Gets the current group name for @a notebook.
   *
   * @return The group name,
   * or <tt>nullptr</tt> if none is set.
   */
  auto get_group_name() const -> Glib::ustring;


  /** Returns the page number of the current page.
   *
   * @return The index (starting from 0) of the current
   * page in the notebook. If the notebook has no pages,
   * then -1 will be returned.
   */
  auto get_current_page() const -> int;

  /** Returns the child widget contained in page number @a page_number.
   *
   * @param page_number The index of a page in the notebook, or -1
   * to get the last page.
   * @return The child widget, or <tt>nullptr</tt> if @a page_number
   * is out of bounds.
   */
  auto get_nth_page(int page_number) -> Widget*;

  /** Returns the child widget contained in page number @a page_number.
   *
   * @param page_number The index of a page in the notebook, or -1
   * to get the last page.
   * @return The child widget, or <tt>nullptr</tt> if @a page_number
   * is out of bounds.
   */
  auto get_nth_page(int page_number) const -> const Widget*;

  /** Gets the number of pages in a notebook.
   *
   * @return The number of pages in the notebook.
   */
  auto get_n_pages() const -> int;
  /*Widget* get_current_page();*/ /*inconsistency with set_current_page*/

  /** Finds the index of the page which contains the given child
   * widget.
   *
   * @param child A `Gtk::Widget`.
   * @return The index of the page containing @a child, or
   * -1 if @a child is not in the notebook.
   */
  auto page_num(const Widget& child) const -> int;


  /** Switches to the page number @a page_number.
   *
   * Note that due to historical reasons, GtkNotebook refuses
   * to switch to a page unless the child widget is visible.
   * Therefore, it is recommended to show child widgets before
   * adding them to a notebook.
   *
   * @param page_number Index of the page to switch to, starting from 0.
   * If negative, the last page will be used. If greater
   * than the number of pages in the notebook, nothing
   * will be done.
   */
  void set_current_page(int page_number);

  /** Switches to the next page.
   *
   * Nothing happens if the current page is the last page.
   */
  void next_page();

  /** Switches to the previous page.
   *
   * Nothing happens if the current page is the first page.
   */
  void prev_page();


  /** Sets whether a bevel will be drawn around the notebook pages.
   *
   * This only has a visual effect when the tabs are not shown.
   *
   * @param show_border <tt>true</tt> if a bevel should be drawn around the notebook.
   */
  void set_show_border(bool show_border =  true);


  /** Returns whether a bevel will be drawn around the notebook pages.
   *
   * @return <tt>true</tt> if the bevel is drawn.
   */
  auto get_show_border() const -> bool;

  /** Sets whether to show the tabs for the notebook or not.
   *
   * @param show_tabs <tt>true</tt> if the tabs should be shown.
   */
  void set_show_tabs(bool show_tabs =  true);

  /** Returns whether the tabs of the notebook are shown.
   *
   * @return <tt>true</tt> if the tabs are shown.
   */
  auto get_show_tabs() const -> bool;


  /** Sets the edge at which the tabs are drawn.
   *
   * @param pos The edge to draw the tabs at.
   */
  void set_tab_pos(PositionType pos);

  /** Gets the edge at which the tabs are drawn.
   *
   * @return The edge at which the tabs are drawn.
   */
  auto get_tab_pos() const -> PositionType;


  /** Sets whether the tab label area will have arrows for
   * scrolling if there are too many tabs to fit in the area.
   *
   * @param scrollable <tt>true</tt> if scroll arrows should be added.
   */
  void set_scrollable(bool scrollable =  true);

  /** Returns whether the tab label area has arrows for scrolling.
   *
   * @return <tt>true</tt> if arrows for scrolling are present.
   */
  auto get_scrollable() const -> bool;


  /** Enables the popup menu.
   *
   * If the user clicks with the right mouse button on the tab labels,
   * a menu with all the pages will be popped up.
   */
  void popup_enable();


  /** Disables the popup menu.
   */
  void popup_disable();


  /** Returns the tab label widget for the page @a child.
   *
   * <tt>nullptr</tt> is returned if @a child is not in @a notebook or
   * if no tab label has specifically been set for @a child.
   *
   * @param child The page.
   * @return The tab label.
   */
  auto get_tab_label(Widget& child) -> Widget*;

  /** Returns the tab label widget for the page @a child.
   *
   * <tt>nullptr</tt> is returned if @a child is not in @a notebook or
   * if no tab label has specifically been set for @a child.
   *
   * @param child The page.
   * @return The tab label.
   */
  auto get_tab_label(Widget& child) const -> const Widget*;

  /** Changes the tab label for @a child.
   *
   * If <tt>nullptr</tt> is specified for @a tab_label, then the page will
   * have the label “page N”.
   *
   * @param child The page.
   * @param tab_label The tab label widget to use, or <tt>nullptr</tt>
   * for default tab label.
   */
  void set_tab_label(Widget& child, Widget& tab_label);

  /** Creates a new label and sets it as the tab label for the page
   * containing @a child.
   *
   * @param child The page.
   * @param tab_text The label text.
   */
  void set_tab_label_text(Widget& child, const Glib::ustring& tab_text);

  /** Retrieves the text of the tab label for the page containing
   *  @a child.
   *
   * @param child A widget contained in a page of @a notebook.
   * @return The text of the tab label.
   */
  auto get_tab_label_text(Widget& child) const -> Glib::ustring;

  /** Retrieves the menu label widget of the page containing @a child.
   *
   * @param child A widget contained in a page of @a notebook.
   * @return The menu label, or <tt>nullptr</tt>
   * if the notebook page does not have a menu label other than
   * the default (the tab label).
   */
  auto get_menu_label(Widget& child) -> Widget*;

  /** Retrieves the menu label widget of the page containing @a child.
   *
   * @param child A widget contained in a page of @a notebook.
   * @return The menu label, or <tt>nullptr</tt>
   * if the notebook page does not have a menu label other than
   * the default (the tab label).
   */
  auto get_menu_label(Widget& child) const -> const Widget*;

  /** Changes the menu label for the page containing @a child.
   *
   * @param child The child widget.
   * @param menu_label The menu label, or <tt>nullptr</tt> for default.
   */
  void set_menu_label(Widget& child, Widget& menu_label);

  /** Creates a new label and sets it as the menu label of @a child.
   *
   * @param child The child widget.
   * @param menu_text The label text.
   */
  void set_menu_label_text(Widget& child, const Glib::ustring& menu_text);

  /** Retrieves the text of the menu label for the page containing
   *  @a child.
   *
   * @param child The child widget of a page of the notebook.
   * @return The text of the tab label.
   */
  auto get_menu_label_text(Widget& child) const -> Glib::ustring;


  /** Reorders the page containing @a child, so that it appears in position
   *  @a position.
   *
   * If @a position is greater than or equal to the number of children in
   * the list or negative, @a child will be moved to the end of the list.
   *
   * @param child The child to move.
   * @param position The new position, or -1 to move to the end.
   */
  void reorder_child(Widget& child, int position);


  /** Gets whether the tab can be reordered via drag and drop or not.
   *
   * @param child A child `Gtk::Widget`.
   * @return <tt>true</tt> if the tab is reorderable.
   */
  auto get_tab_reorderable(Widget& child) const -> bool;

  /** Sets whether the notebook tab can be reordered
   * via drag and drop or not.
   *
   * @param child A child `Gtk::Widget`.
   * @param reorderable Whether the tab is reorderable or not.
   */
  void set_tab_reorderable(Widget& child, bool reorderable =  true);

  /** Returns whether the tab contents can be detached from @a notebook.
   *
   * @param child A child `Gtk::Widget`.
   * @return <tt>true</tt> if the tab is detachable.
   */
  auto get_tab_detachable(Widget& child) const -> bool;

  /** Sets whether the tab can be detached from @a notebook to another
   * notebook or widget.
   *
   * Note that two notebooks must share a common group identificator
   * (see set_group_name()) to allow automatic tabs
   * interchange between them.
   *
   * If you want a widget to interact with a notebook through DnD
   * (i.e.: accept dragged tabs from it) it must be set as a drop
   * destination and accept the target “GTK_NOTEBOOK_TAB”. The notebook
   * will fill the selection with a GtkWidget** pointing to the child
   * widget that corresponds to the dropped tab.
   *
   * Note that you should use detach_tab() instead
   * of remove_page() if you want to remove the tab
   * from the source notebook as part of accepting a drop. Otherwise,
   * the source notebook will think that the dragged tab was removed
   * from underneath the ongoing drag operation, and will initiate a
   * drag cancel animation.
   *
   *
   * [C example ellipted]
   *
   * If you want a notebook to accept drags from other widgets,
   * you will have to set your own DnD code to do it.
   *
   * @param child A child `Gtk::Widget`.
   * @param detachable Whether the tab is detachable or not.
   */
  void set_tab_detachable(Widget& child, bool detachable =  true);

  /** Removes the child from the notebook.
   *
   * This function is very similar to remove_page(),
   * but additionally informs the notebook that the removal
   * is happening as part of a tab DND operation, which should
   * not be cancelled.
   *
   * @param child A child.
   */
  void detach_tab(Widget& child);


  /** Gets one of the action widgets.
   *
   * See set_action_widget().
   *
   * @param pack_type Pack type of the action widget to receive.
   * @return The action widget
   * with the given @a pack_type or <tt>nullptr</tt> when this action
   * widget has not been set.
   */
  auto get_action_widget(PackType pack_type =  PackType::START) -> Widget*;

  /** Sets @a widget as one of the action widgets.
   *
   * Depending on the pack type the widget will be placed before
   * or after the tabs. You can use a `Gtk::Box` if you need to pack
   * more than one widget on the same side.
   *
   * @param widget A `Gtk::Widget`.
   * @param pack_type Pack type of the action widget.
   */
  void set_action_widget(Widget* widget, PackType pack_type =  PackType::START);


  /** Returns the `Gtk::NotebookPage` for @a child.
   *
   * @param child A child of @a notebook.
   * @return The `Gtk::NotebookPage` for @a child.
   */
  auto get_page(Widget& child) -> Glib::RefPtr<NotebookPage>;

  /** Returns the `Gtk::NotebookPage` for @a child.
   *
   * @param child A child of @a notebook.
   * @return The `Gtk::NotebookPage` for @a child.
   */
  auto get_page(const Widget& child) const -> Glib::RefPtr<const NotebookPage>;


  /** Returns a `Gio::ListModel` that contains the pages of the notebook.
   *
   * This can be used to keep an up-to-date view. The model also
   * implements Gtk::SelectionModel and can be used to track
   * and modify the visible page.
   *
   * @return A
   * `Gio::ListModel` for the notebook's children.
   */
  auto get_pages() -> Glib::RefPtr<Gio::ListModel>;

  /** Returns a `Gio::ListModel` that contains the pages of the notebook.
   *
   * This can be used to keep an up-to-date view. The model also
   * implements Gtk::SelectionModel and can be used to track
   * and modify the visible page.
   *
   * @return A
   * `Gio::ListModel` for the notebook's children.
   */
  auto get_pages() const -> Glib::RefPtr<const Gio::ListModel>;

  // no_default_handler because GtkNotebookClass is private.

  /**
   * @par Slot Prototype:
   * <tt>void on_my_%switch_page(Widget* page, guint page_number)</tt>
   *
   * Flags: Run Last
   *
   * Emitted when the user or a function changes the current page.
   *
   * @param page The new current page.
   * @param page_number The index of the page.
   */

  auto signal_switch_page() -> Glib::SignalProxy<void(Widget*, guint)>;


  /**
   * @par Slot Prototype:
   * <tt>void on_my_%page_reordered(Widget* page, guint page_num)</tt>
   *
   * Flags: Run Last
   *
   * the signal_page_reordered() signal is emitted in the notebook
   * right after a page has been reordered.
   *
   * @param page The child `Gtk::Widget` affected.
   * @param page_num The new page number for @a page.
   */

  auto signal_page_reordered() -> Glib::SignalProxy<void(Widget*, guint)>;


  /**
   * @par Slot Prototype:
   * <tt>void on_my_%page_removed(Widget* page, guint page_num)</tt>
   *
   * Flags: Run Last
   *
   * the signal_page_removed() signal is emitted in the notebook
   * right after a page is removed from the notebook.
   *
   * @param page The child `Gtk::Widget` affected.
   * @param page_num The @a page page number.
   */

  auto signal_page_removed() -> Glib::SignalProxy<void(Widget*, guint)>;


  /**
   * @par Slot Prototype:
   * <tt>void on_my_%page_added(Widget* page, guint page_num)</tt>
   *
   * Flags: Run Last
   *
   * the signal_page_added() signal is emitted in the notebook
   * right after a page is added to the notebook.
   *
   * @param page The child `Gtk::Widget` affected.
   * @param page_num The new page number for @a page.
   */

  auto signal_page_added() -> Glib::SignalProxy<void(Widget*, guint)>;


  //Key-binding signals:


  //This doesn't seem generally useful:


  /** Which side of the notebook holds the tabs.
   *
   * Default value: Gtk::PositionType::TOP
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_tab_pos() -> Glib::PropertyProxy< PositionType > ;

/** Which side of the notebook holds the tabs.
   *
   * Default value: Gtk::PositionType::TOP
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_tab_pos() const -> Glib::PropertyProxy_ReadOnly< PositionType >;

  /** Whether tabs should be shown.
   *
   * Default value: <tt>true</tt>
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_show_tabs() -> Glib::PropertyProxy< bool > ;

/** Whether tabs should be shown.
   *
   * Default value: <tt>true</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_show_tabs() const -> Glib::PropertyProxy_ReadOnly< bool >;

  /** Whether the border should be shown.
   *
   * Default value: <tt>true</tt>
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_show_border() -> Glib::PropertyProxy< bool > ;

/** Whether the border should be shown.
   *
   * Default value: <tt>true</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_show_border() const -> Glib::PropertyProxy_ReadOnly< bool >;

  /** If <tt>true</tt>, scroll arrows are added if there are too many pages to fit.
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_scrollable() -> Glib::PropertyProxy< bool > ;

/** If <tt>true</tt>, scroll arrows are added if there are too many pages to fit.
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_scrollable() const -> Glib::PropertyProxy_ReadOnly< bool >;

  /** The index of the current page.
   *
   * Default value: -1
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_page() -> Glib::PropertyProxy< int > ;

/** The index of the current page.
   *
   * Default value: -1
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_page() const -> Glib::PropertyProxy_ReadOnly< int >;

  /** Group name for tab drag and drop.
   *
   * Default value: ""
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_group_name() -> Glib::PropertyProxy< Glib::ustring > ;

/** Group name for tab drag and drop.
   *
   * Default value: ""
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_group_name() const -> Glib::PropertyProxy_ReadOnly< Glib::ustring >;

  /** If <tt>true</tt>, pressing the right mouse button on the notebook shows a page switching menu.
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_enable_popup() -> Glib::PropertyProxy< bool > ;

/** If <tt>true</tt>, pressing the right mouse button on the notebook shows a page switching menu.
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_enable_popup() const -> Glib::PropertyProxy_ReadOnly< bool >;

  /** A selection model with the pages.
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_pages() const -> Glib::PropertyProxy_ReadOnly< Glib::RefPtr<Gio::ListModel> >;


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
   * @relates Gtk::Notebook
   */
  GTKMM_API
  auto wrap(GtkNotebook* object, bool take_copy = false) -> Gtk::Notebook*;
} //namespace Glib


#endif /* _GTKMM_NOTEBOOK_H */

