
#ifndef _GTKMM_ASSISTANT_H
#define _GTKMM_ASSISTANT_H


#include <mm/glib/ustring.hpp>
#include <sigc++/sigc++.h>

/*
 * Copyright (C) 2004 The gtkmm Development Team
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

#include <mm/gio/listmodel.hpp>
#include <mm/gtk/window.hpp>
#include <mm/gtk/assistantpage.hpp>
#include <mm/gdk/pixbuf.hpp>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkAssistant = struct _GtkAssistant;
using GtkAssistantClass = struct _GtkAssistantClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{ class GTKMM_API Assistant_Class; } // namespace Gtk
#endif //DOXYGEN_SHOULD_SKIP_THIS

namespace Gtk
{

/** A widget used to guide users through multi-step operations.
 *
 * A %Gtk::Assistant is a widget used to represent a generally complex
 * operation split into several steps, guiding the user through its
 * pages and controlling the page flow to collect the necessary data.
 *
 * %Gtk::Assistant maintains a Gtk::AssistantPage object for each added
 * child, which holds additional per-child properties. You
 * obtain the Gtk::AssistantPage for a child with get_page().
 *
 * @newin{2,10}
 * @ingroup Dialogs
 */

class GTKMM_API Assistant : public Window
{
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  typedef Assistant CppObjectType;
  typedef Assistant_Class CppClassType;
  typedef GtkAssistant BaseObjectType;
  typedef GtkAssistantClass BaseClassType;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

  Assistant(Assistant&& src) noexcept;
  auto operator=(Assistant&& src) noexcept -> Assistant&;

  // noncopyable
  Assistant(const Assistant&) = delete;
  auto operator=(const Assistant&) -> Assistant& = delete;

  ~Assistant() noexcept override;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

private:
  friend GTKMM_API class Assistant_Class;
  static CppClassType assistant_class_;

protected:
  explicit Assistant(const Glib::ConstructParams& construct_params);
  explicit Assistant(GtkAssistant* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS


  static auto get_base_type() -> GType G_GNUC_CONST;
#endif

  /// Provides access to the underlying C GObject.
  auto       gobj() -> GtkAssistant*       { return reinterpret_cast<GtkAssistant*>(gobject_); }

  /// Provides access to the underlying C GObject.
  auto gobj() const -> const GtkAssistant* { return reinterpret_cast<GtkAssistant*>(gobject_); }

private:


public:
  Assistant();

  /** Constructor.
   *
   * @param use_header_bar <tt>true</tt> if the assistant shall use a HeaderBar
   *        for action buttons instead of the action-area.
   *
   * @newin{3,90}
   */
  explicit Assistant(bool use_header_bar);


  /** Navigate to the next page.
   *
   * It is a programming error to call this function when
   * there is no next page.
   *
   * This function is for use when creating pages of the
   * Gtk::AssistantPage::Type::CUSTOM type.
   */
  void next_page();

  /** Navigate to the previous visited page.
   *
   * It is a programming error to call this function when
   * no previous page is available.
   *
   * This function is for use when creating pages of the
   * Gtk::AssistantPage::Type::CUSTOM type.
   */
  void previous_page();


  /** Returns the page number of the current page.
   *
   * @return The index (starting from 0) of the current
   * page in the @a assistant, or -1 if the @a assistant has no pages,
   * or no current page.
   */
  auto get_current_page() const -> int;

  /** Switches the page to @a page_num.
   *
   * Note that this will only be necessary in custom buttons,
   * as the @a assistant flow can be set with
   * set_forward_page_func().
   *
   * @param page_num Index of the page to switch to, starting from 0.
   * If negative, the last page will be used. If greater
   * than the number of pages in the @a assistant, nothing
   * will be done.
   */
  void set_current_page(int page_num);

  /** Returns the number of pages in the @a assistant
   *
   * @return The number of pages in the @a assistant.
   */
  auto get_n_pages() const -> int;

  /** Returns the child widget contained in page number @a page_num.
   *
   * @param page_num The index of a page in the @a assistant,
   * or -1 to get the last page.
   * @return The child widget, or <tt>nullptr</tt>
   * if @a page_num is out of bounds.
   */
  auto get_nth_page(int page_num) -> Widget*;

  /** Returns the child widget contained in page number @a page_num.
   *
   * @param page_num The index of a page in the @a assistant,
   * or -1 to get the last page.
   * @return The child widget, or <tt>nullptr</tt>
   * if @a page_num is out of bounds.
   */
  auto get_nth_page(int page_num) const -> const Widget*;

  /** Prepends a page to the @a assistant.
   *
   * @param page A `Gtk::Widget`.
   * @return The index (starting at 0) of the inserted page.
   */
  auto prepend_page(Widget& page) -> int;

  /** Appends a page to the @a assistant.
   *
   * @param page A `Gtk::Widget`.
   * @return The index (starting at 0) of the inserted page.
   */
  auto append_page(Widget& page) -> int;

  /** Inserts a page in the @a assistant at a given position.
   *
   * @param page A `Gtk::Widget`.
   * @param position The index (starting at 0) at which to insert the page,
   * or -1 to append the page to the @a assistant.
   * @return The index (starting from 0) of the inserted page.
   */
  auto insert_page(Widget& page, int position) -> int;

  /** Removes the @a page_num’s page from @a assistant.
   *
   * @param page_num The index of a page in the @a assistant,
   * or -1 to remove the last page.
   */
  void remove_page(int page_num);

  typedef sigc::slot<int(int /* current_page */)> SlotForwardPage;

  void set_forward_page_func(const SlotForwardPage& slot);


  /** Sets the page type for @a page.
   *
   * The page type determines the page behavior in the @a assistant.
   *
   * @param page A page of @a assistant.
   * @param type The new type for @a page.
   */
  void set_page_type(const Widget& page, AssistantPage::Type type);

  /** Gets the page type of @a page.
   *
   * @param page A page of @a assistant.
   * @return The page type of @a page.
   */
  auto get_page_type(const Widget& page) const -> AssistantPage::Type;

  /** Sets a title for @a page.
   *
   * The title is displayed in the header area of the assistant
   * when @a page is the current page.
   *
   * @param page A page of @a assistant.
   * @param title The new title for @a page.
   */
  void set_page_title(const Widget& page, const Glib::ustring& title);

  /** Gets the title for @a page.
   *
   * @param page A page of @a assistant.
   * @return The title for @a page.
   */
  auto get_page_title(const Widget& page) const -> Glib::ustring;


  /** Sets whether @a page contents are complete.
   *
   * This will make @a assistant update the buttons state
   * to be able to continue the task.
   *
   * @param page A page of @a assistant.
   * @param complete The completeness status of the page.
   */
  void set_page_complete(const Widget& page, bool complete =  true);

  /** Gets whether @a page is complete.
   *
   * @param page A page of @a assistant.
   * @return <tt>true</tt> if @a page is complete.
   */
  auto get_page_complete(const Widget& page) const -> bool;

  /** Adds a widget to the action area of a `Gtk::Assistant`.
   *
   * @param child A `Gtk::Widget`.
   */
  void add_action_widget(Widget& child);

  /** Removes a widget from the action area of a `Gtk::Assistant`.
   *
   * @param child A `Gtk::Widget`.
   */
  void remove_action_widget(Widget& child);

  /** Forces @a assistant to recompute the buttons state.
   *
   * GTK automatically takes care of this in most situations,
   * e.g. when the user goes to a different page, or when the
   * visibility or completeness of a page changes.
   *
   * One situation where it can be necessary to call this
   * function is when changing a value on the current page
   * affects the future page flow of the assistant.
   */
  void update_buttons_state();

  /** Erases the visited page history.
   *
   * GTK will then hide the back button on the current page,
   * and removes the cancel button from subsequent pages.
   *
   * Use this when the information provided up to the current
   * page is hereafter deemed permanent and cannot be modified
   * or undone. For example, showing a progress page to track
   * a long-running, unreversible operation after the user has
   * clicked apply on a confirmation page.
   */
  void commit();


  /** Returns the `Gtk::AssistantPage` object for @a child.
   *
   * @param child A child of @a assistant.
   * @return The `Gtk::AssistantPage` for @a child.
   */
  auto get_page(Widget& child) -> Glib::RefPtr<AssistantPage>;

  /** Returns the `Gtk::AssistantPage` object for @a child.
   *
   * @param child A child of @a assistant.
   * @return The `Gtk::AssistantPage` for @a child.
   */
  auto get_page(const Widget& child) const -> Glib::RefPtr<const AssistantPage>;


  /** Gets a list model of the assistant pages.
   *
   * @return A list model of the pages.
   */
  auto get_pages() -> Glib::RefPtr<Gio::ListModel>;

  /** Gets a list model of the assistant pages.
   *
   * @return A list model of the pages.
   */
  auto get_pages() const -> Glib::RefPtr<const Gio::ListModel>;

  // no_default_handler because GtkAssistantClass is private.

  /**
   * @par Slot Prototype:
   * <tt>void on_my_%prepare(Gtk::Widget* page)</tt>
   *
   * Flags: Run Last
   *
   * Emitted when a new page is set as the assistant's current page,
   * before making the new page visible.
   *
   * A handler for this signal can do any preparations which are
   * necessary before showing @a page.
   *
   * @param page The current page.
   */

  auto signal_prepare() -> Glib::SignalProxy<void(Gtk::Widget*)>;


  /**
   * @par Slot Prototype:
   * <tt>void on_my_%apply()</tt>
   *
   * Flags: Run Last
   *
   * Emitted when the apply button is clicked.
   *
   * The default behavior of the `Gtk::Assistant` is to switch to the page
   * after the current page, unless the current page is the last one.
   *
   * A handler for the signal_apply() signal should carry out the actions for
   * which the wizard has collected data. If the action takes a long time
   * to complete, you might consider putting a page of type
   * Gtk::AssistantPage::Type::PROGRESS after the confirmation page and handle
   * this operation within the signal_prepare() signal of
   * the progress page.
   */

  auto signal_apply() -> Glib::SignalProxy<void()>;


  /**
   * @par Slot Prototype:
   * <tt>void on_my_%close()</tt>
   *
   * Flags: Run Last
   *
   * Emitted either when the close button of a summary page is clicked,
   * or when the apply button in the last page in the flow (of type
   * Gtk::AssistantPage::Type::CONFIRM) is clicked.
   */

  auto signal_close() -> Glib::SignalProxy<void()>;


  /**
   * @par Slot Prototype:
   * <tt>void on_my_%cancel()</tt>
   *
   * Flags: Run Last
   *
   * Emitted when then the cancel button is clicked.
   */

  auto signal_cancel() -> Glib::SignalProxy<void()>;


  //Ignore action signals.


  /** <tt>true</tt> if the assistant uses a `Gtk::HeaderBar` for action buttons
   * instead of the action-area.
   *
   * For technical reasons, this property is declared as an integer
   * property, but you should only set it to <tt>true</tt> or <tt>false</tt>.
   *
   * Default value: -1
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_use_header_bar() const -> Glib::PropertyProxy_ReadOnly< bool >;


  /** `Gio::ListModel` containing the pages.
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
   * @relates Gtk::Assistant
   */
  GTKMM_API
  auto wrap(GtkAssistant* object, bool take_copy = false) -> Gtk::Assistant*;
} //namespace Glib


#endif /* _GTKMM_ASSISTANT_H */

