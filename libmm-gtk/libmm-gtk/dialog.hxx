
#ifndef _GTKMM_DIALOG_H
#define _GTKMM_DIALOG_H


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

#include <vector>

#include <libmm-gtk/window.hxx>
#include <libmm-gtk/box.hxx>
#include <libmm-gtk/button.hxx>
#include <libmm-gtk/headerbar.hxx>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkDialog = struct _GtkDialog;
using GtkDialogClass = struct _GtkDialogClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{ class GTKMM_API Dialog_Class; } // namespace Gtk
#endif //DOXYGEN_SHOULD_SKIP_THIS

namespace Gtk
{

/** @defgroup Dialogs Dialogs
 */


/** @addtogroup gtkmmEnums gtkmm Enums and Flags */

/** Wrapper for enum ResponseType.
 * ResponseType enumerators are scoped and can be implicitly converted to int.
 * The scope is Gtk::ResponseType::
 *
 * @ingroup gtkmmEnums
 */
class ResponseType_Wrapper final
{
public:
  /**
   *  @var ResponseType NONE
   * Returned if an action widget has no response id,
   * or if the dialog gets programmatically hidden or destroyed.
   *
   *  @var ResponseType REJECT
   * Generic response id, not used by GTK dialogs.
   *
   *  @var ResponseType ACCEPT
   * Generic response id, not used by GTK dialogs.
   *
   *  @var ResponseType DELETE_EVENT
   * Returned if the dialog is deleted.
   *
   *  @var ResponseType OK
   * Returned by OK buttons in GTK dialogs.
   *
   *  @var ResponseType CANCEL
   * Returned by Cancel buttons in GTK dialogs.
   *
   *  @var ResponseType CLOSE
   * Returned by Close buttons in GTK dialogs.
   *
   *  @var ResponseType YES
   * Returned by Yes buttons in GTK dialogs.
   *
   *  @var ResponseType NO
   * Returned by No buttons in GTK dialogs.
   *
   *  @var ResponseType APPLY
   * Returned by Apply buttons in GTK dialogs.
   *
   *  @var ResponseType HELP
   * Returned by Help buttons in GTK dialogs.
   *
   *  @enum ResponseType
   *
   * Predefined values for use as response ids in Gtk::Dialog::add_button().
   *
   * All predefined values are negative; GTK leaves values of 0 or greater for
   * application-defined response ids.
   *
   * @ingroup gtkmmEnums
   */
  enum ResponseType
  {
    NONE = -1,
    REJECT = -2,
    ACCEPT = -3,
    DELETE_EVENT = -4,
    OK = -5,
    CANCEL = -6,
    CLOSE = -7,
    YES = -8,
    NO = -9,
    APPLY = -10,
    HELP = -11
  };
  #ifndef DOXYGEN_SHOULD_SKIP_THIS
  ResponseType_Wrapper() = delete;
  #endif
};
/** ResponseType enumerators are scoped by the wrapper class
 * and can be implicitly converted to int.
 *
 * @ingroup gtkmmEnums
 */
using ResponseType = ResponseType_Wrapper::ResponseType;


} // namespace Gtk

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

template <>
class GTKMM_API Value<Gtk::ResponseType> : public Glib::Value_Enum<Gtk::ResponseType>
{
public:
  static auto value_type() -> GType G_GNUC_CONST;
};

} // namespace Glib
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

namespace Gtk
{


/** Create popup windows.
 *
 * %Dialog boxes are a convenient way to prompt the user for a small amount
 * of input, eg. to display a message, ask a question, or anything else that
 * does not require extensive effort on the user's part.
 *
 * The main area of a %Dialog is called the "content area", and is yours
 * to populate with widgets such a Gtk::Label or Gtk::Entry, to present
 * your information, questions, or tasks to the user.
 *
 * In addition, dialogs allow you to add "action widgets". Most commonly,
 * action widgets are buttons. Depending on the platform, action widgets may
 * be presented in the header bar at the top of the window, or at the bottom
 * of the window.
 *
 * When adding buttons using add_button(), clicking the button will emit
 * signal_response() with a "response id" you specified. You are encouraged
 * to use the @ref Gtk::ResponseType_Wrapper::ResponseType "Gtk::ResponseType"
 * enum (these all have values less than zero). If a dialog receives a delete
 * event, the "response" signal will be emitted with a response id of
 * @ref Gtk::ResponseType_Wrapper::ResponseType "Gtk::ResponseType::DELETE_EVENT".
 *
 * A “modal” dialog (that is, one which freezes the rest of the application
 * from user input), can be created by calling Gtk::Window::set_modal() on the
 * dialog. It is also possible to set the modal property in the constructor.
 *
 * @ingroup Dialogs
 */

class GTKMM_API Dialog : public Window
{
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  typedef Dialog CppObjectType;
  typedef Dialog_Class CppClassType;
  typedef GtkDialog BaseObjectType;
  typedef GtkDialogClass BaseClassType;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

  Dialog(Dialog&& src) noexcept;
  auto operator=(Dialog&& src) noexcept -> Dialog&;

  // noncopyable
  Dialog(const Dialog&) = delete;
  auto operator=(const Dialog&) -> Dialog& = delete;

  ~Dialog() noexcept override;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

private:
  friend GTKMM_API class Dialog_Class;
  static CppClassType dialog_class_;

protected:
  explicit Dialog(const Glib::ConstructParams& construct_params);
  explicit Dialog(GtkDialog* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS


  static auto get_base_type() -> GType G_GNUC_CONST;
#endif

  /// Provides access to the underlying C GObject.
  auto       gobj() -> GtkDialog*       { return reinterpret_cast<GtkDialog*>(gobject_); }

  /// Provides access to the underlying C GObject.
  auto gobj() const -> const GtkDialog* { return reinterpret_cast<GtkDialog*>(gobject_); }

private:


public:
  Dialog();
  explicit Dialog(const Glib::ustring& title, bool modal = false, bool use_header_bar = false);
  Dialog(const Glib::ustring& title, Gtk::Window& parent, bool modal = false, bool use_header_bar = false);


  /** Adds an activatable widget to the action area of a `Gtk::Dialog`.
   *
   * GTK connects a signal handler that will emit the
   * signal_response() signal on the dialog when the widget
   * is activated. The widget is appended to the end of the dialog’s action
   * area.
   *
   * If you want to add a non-activatable widget, simply pack it into
   * the @a action_area field of the `Gtk::Dialog` struct.
   *
   * @param child An activatable widget.
   * @param response_id Response ID for @a child.
   */
  void add_action_widget(Widget& child, int response_id);

  /** Adds a button with the given text.
   *
   * GTK arranges things so that clicking the button will emit the
   * signal_response() signal with the given @a response_id.
   * The button is appended to the end of the dialog’s action area.
   * The button widget is returned, but usually you don’t need it.
   *
   * @param button_text Text of button.
   * @param response_id Response ID for the button.
   * @return The `Gtk::Button` widget that was added.
   */
  auto add_button(const Glib::ustring& button_text, int response_id) -> Button*;

  /** A convenient way to sensitize/desensitize dialog buttons.
   *
   * Calls `gtk_widget_set_sensitive (widget, @a setting)`
   * for each widget in the dialog’s action area with the given @a response_id.
   *
   * @param response_id A response ID.
   * @param setting <tt>true</tt> for sensitive.
   */
  void set_response_sensitive(int response_id, bool setting =  true);

  /** Sets the default widget for the dialog based on the response ID.
   *
   * Pressing “Enter” normally activates the default widget.
   *
   * @param response_id A response ID.
   */
  void set_default_response(int response_id);

  /** Gets the widget button that uses the given response ID in the action area
   * of a dialog.
   *
   * @param response_id The response ID used by the @a dialog widget.
   * @return The @a widget button that uses the given
   *  @a response_id.
   */
  auto get_widget_for_response(int response_id) -> Widget*;

  /** Gets the widget button that uses the given response ID in the action area
   * of a dialog.
   *
   * @param response_id The response ID used by the @a dialog widget.
   * @return The @a widget button that uses the given
   *  @a response_id.
   */
  auto get_widget_for_response(int response_id) const -> const Widget*;

  /** Gets the response id of a widget in the action area
   * of a dialog.
   *
   * @param widget A widget in the action area of @a dialog.
   * @return The response id of @a widget, or Gtk::ResponseType::NONE
   * if @a widget doesn’t have a response id set.
   */
  auto get_response_for_widget(const Gtk::Widget& widget) const -> int;


  /** Emits the signal_response() signal with the given response ID.
   *
   * Used to indicate that the user has responded to the dialog in some way.
   *
   * @param response_id Response ID.
   */
  void response(int response_id);


  /** Returns the content area of @a dialog.
   *
   * @return The content area `Gtk::Box`.
   */
  auto get_content_area() -> Box*;

  /** Returns the content area of @a dialog.
   *
   * @return The content area `Gtk::Box`.
   */
  auto get_content_area() const -> const Box*;


  /** Returns the header bar of @a dialog.
   *
   * Note that the headerbar is only used by the dialog if the
   * property_use_header_bar() property is <tt>true</tt>.
   *
   * @return The header bar.
   */
  auto get_header_bar() -> HeaderBar*; // transfer none

  /** Returns the header bar of @a dialog.
   *
   * Note that the headerbar is only used by the dialog if the
   * property_use_header_bar() property is <tt>true</tt>.
   *
   * @return The header bar.
   */
  auto get_header_bar() const -> const HeaderBar*; // transfer none


  /**
   * @par Slot Prototype:
   * <tt>void on_my_%response(int response_id)</tt>
   *
   * Flags: Run Last
   *
   * Emitted when an action widget is clicked.
   *
   * The signal is also emitted when the dialog receives a
   * delete event, and when Gtk::Dialog::response() is called.
   * On a delete event, the response ID is Gtk::ResponseType::DELETE_EVENT.
   * Otherwise, it depends on which action widget was clicked.
   *
   * @param response_id The response ID.
   */

  auto signal_response() -> Glib::SignalProxy<void(int)>;


  /** <tt>true</tt> if the dialog uses a headerbar for action buttons
   * instead of the action-area.
   *
   * For technical reasons, this property is declared as an integer
   * property, but you should only set it to <tt>true</tt> or <tt>false</tt>.
   *
   * ## Creating a dialog with headerbar
   *
   * Builtin `Gtk::Dialog` subclasses such as Gtk::ColorChooserDialog
   * set this property according to platform conventions (using the
   * Gtk::Settings::property_gtk_dialogs_use_header() setting).
   *
   * Here is how you can achieve the same:
   *
   *
   * [C example ellipted]
   *
   * Default value: -1
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_use_header_bar() const -> Glib::PropertyProxy_ReadOnly< bool >;


   // Keybinding signal


public:

public:
  //C++ methods used to invoke GTK+ virtual functions:

protected:
  //GTK+ Virtual Functions (override these to change behaviour):

  //Default Signal Handlers::
  /// This is a default handler for the signal signal_response().
  virtual void on_response(int response_id);


};

} //namespace Gtk


namespace Glib
{
  /** A Glib::wrap() method for this object.
   *
   * @param object The C instance.
   * @param take_copy False if the result should take ownership of the C instance. True if it should take a new copy or ref.
   * @result A C++ instance that wraps this C instance.
   *
   * @relates Gtk::Dialog
   */
  GTKMM_API
  auto wrap(GtkDialog* object, bool take_copy = false) -> Gtk::Dialog*;
} //namespace Glib


#endif /* _GTKMM_DIALOG_H */

