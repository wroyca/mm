// Generated by gmmproc 2.74.0 -- DO NOT MODIFY!
#ifndef _GTKMM_INFOBAR_H
#define _GTKMM_INFOBAR_H


#include <glibmm/ustring.h>
#include <sigc++/sigc++.h>

/* Copyright (C) 2009 The gtkmm Development Team
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

#include <gtkmm/widget.h>
#include <gtkmm/button.h>
#include <gtkmm/enums.h>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkInfoBar = struct _GtkInfoBar;
using GtkInfoBarClass = struct _GtkInfoBarClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{ class GTKMM_API InfoBar_Class; } // namespace Gtk
#endif //DOXYGEN_SHOULD_SKIP_THIS

namespace Gtk
{

/** This widget that can be used to show messages to the user without showing a dialog.
 * It is often temporarily shown at the top or bottom of a document. In contrast to
 * Dialog, which has a horizontal action area at the bottom, InfoBar has a vertical
 * action area at the side.
 *
 * The API is very similar to Dialog, allowing you to add buttons to the action
 * area with add_button(). The sensitivity of action widgets can be controlled
 * with set_response_sensitive(). To add widgets to the main content area, use
 * add_child().
 *
 * Similar to MessageDialog, the contents can by classified as error message,
 * warning, informational message, etc, by using set_message_type(). This
 * determines the background color of the message area.
 *
 * The InfoBar widget looks like
 * @image html infobar1.png
 *
 * @newin{2,18}
 *
 * @ingroup Widgets
 */

class GTKMM_API InfoBar : public Widget
{
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  typedef InfoBar CppObjectType;
  typedef InfoBar_Class CppClassType;
  typedef GtkInfoBar BaseObjectType;
  typedef GtkInfoBarClass BaseClassType;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

  InfoBar(InfoBar&& src) noexcept;
  InfoBar& operator=(InfoBar&& src) noexcept;

  // noncopyable
  InfoBar(const InfoBar&) = delete;
  InfoBar& operator=(const InfoBar&) = delete;

  ~InfoBar() noexcept override;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

private:
  friend GTKMM_API class InfoBar_Class;
  static CppClassType infobar_class_;

protected:
  explicit InfoBar(const Glib::ConstructParams& construct_params);
  explicit InfoBar(GtkInfoBar* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static GType get_type()      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS


  static GType get_base_type() G_GNUC_CONST;
#endif

  /// Provides access to the underlying C GObject.
  GtkInfoBar*       gobj()       { return reinterpret_cast<GtkInfoBar*>(gobject_); }

  /// Provides access to the underlying C GObject.
  const GtkInfoBar* gobj() const { return reinterpret_cast<GtkInfoBar*>(gobject_); }

private:

public:

  InfoBar();
  

  /** Add an activatable widget to the action area of a `Gtk::InfoBar`.
   * 
   * This also connects a signal handler that will emit the
   * signal_response() signal on the message area
   * when the widget is activated. The widget is appended to the
   * end of the message areas action area.
   * 
   * @param child An activatable widget.
   * @param response_id Response ID for @a child.
   */
  void add_action_widget(Widget& child, int response_id);
  
  /** Removes a widget from the action area of @a info_bar.
   * 
   * The widget must have been put there by a call to
   * add_action_widget() or add_button().
   * 
   * @param widget An action widget to remove.
   */
  void remove_action_widget(Widget& widget);

  
  /** Adds a button with the given text.
   * 
   * Clicking the button will emit the signal_response()
   * signal with the given response_id. The button is appended to the
   * end of the info bars's action area. The button widget is returned,
   * but usually you don't need it.
   * 
   * @param button_text Text of button.
   * @param response_id Response ID for the button.
   * @return The `Gtk::Button` widget
   * that was added.
   */
  Button* add_button(const Glib::ustring& button_text, int response_id);

  
  /** Adds a widget to the content area of the info bar.
   * 
   * @param widget The child to be added.
   */
  void add_child(Widget& widget);
  
  /** Removes a widget from the content area of the info bar.
   * 
   * @param widget A child that has been added to the content area.
   */
  void remove_child(Widget& widget);

  
  /** Sets the sensitivity of action widgets for @a response_id.
   * 
   * Calls `gtk_widget_set_sensitive (widget, setting)` for each
   * widget in the info bars’s action area with the given @a response_id.
   * A convenient way to sensitize/desensitize buttons.
   * 
   * @param response_id A response ID.
   * @param setting <tt>true</tt> for sensitive.
   */
  void set_response_sensitive(int response_id, bool setting =  true);
  
  /** Sets the last widget in the info bar’s action area with
   * the given response_id as the default widget for the dialog.
   * 
   * Pressing “Enter” normally activates the default widget.
   * 
   * Note that this function currently requires @a info_bar to
   * be added to a widget hierarchy.
   * 
   * @param response_id A response ID.
   */
  void set_default_response(int response_id);

  
  /** Emits the “response” signal with the given @a response_id.
   * 
   * @param response_id A response ID.
   */
  void response(int response_id);

  
  /** Sets the message type of the message area.
   * 
   * GTK uses this type to determine how the message is displayed.
   * 
   * @param message_type A `Gtk::MessageType`.
   */
  void set_message_type(MessageType message_type);
  
  /** Returns the message type of the message area.
   * 
   * @return The message type of the message area.
   */
  MessageType get_message_type() const;

  
  /** If true, a standard close button is shown.
   * 
   * When clicked it emits the response Gtk::ResponseType::CLOSE.
   * 
   * @param setting <tt>true</tt> to include a close button.
   */
  void set_show_close_button(bool setting =  true);
  
  /** Returns whether the widget will display a standard close button.
   * 
   * @return <tt>true</tt> if the widget displays standard close button.
   */
  bool get_show_close_button() const;

  
  /** Sets whether the `Gtk::InfoBar` is revealed.
   * 
   * Changing this will make @a info_bar reveal or conceal
   * itself via a sliding transition.
   * 
   * @note this does not show or hide @a info_bar in the
   * Gtk::Widget::property_visible() sense, so revealing has no effect
   * if Gtk::Widget::property_visible() is <tt>false</tt>.
   * 
   * @param revealed The new value of the property.
   */
  void set_revealed(bool revealed =  true);
  
  /** Returns whether the info bar is currently revealed.
   * 
   * @return The current value of the property_revealed() property.
   */
  bool get_revealed() const;

  
  // no_default_handler because GtkInfoBarClass is private.
  
  /**
   * @par Slot Prototype:
   * <tt>void on_my_%response(int response_id)</tt>
   *
   * Flags: Run Last
   *
   * Emitted when an action widget is clicked.
   * 
   * The signal is also emitted when the application programmer
   * calls Gtk::InfoBar::response(). The @a response_id depends
   * on which action widget was clicked.
   * 
   * @param response_id The response ID.
   */

  Glib::SignalProxy<void(int)> signal_response();


  /** The type of the message.
   * 
   * The type may be used to determine the appearance of the info bar.
   *
   * Default value: Gtk::MessageType::INFO
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  Glib::PropertyProxy< MessageType > property_message_type() ;

/** The type of the message.
   * 
   * The type may be used to determine the appearance of the info bar.
   *
   * Default value: Gtk::MessageType::INFO
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  Glib::PropertyProxy_ReadOnly< MessageType > property_message_type() const;

  /** Whether to include a standard close button.
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  Glib::PropertyProxy< bool > property_show_close_button() ;

/** Whether to include a standard close button.
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  Glib::PropertyProxy_ReadOnly< bool > property_show_close_button() const;

  /** Whether the info bar shows its contents.
   *
   * Default value: <tt>true</tt>
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  Glib::PropertyProxy< bool > property_revealed() ;

/** Whether the info bar shows its contents.
   *
   * Default value: <tt>true</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  Glib::PropertyProxy_ReadOnly< bool > property_revealed() const;


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
   * @relates Gtk::InfoBar
   */
  GTKMM_API
  Gtk::InfoBar* wrap(GtkInfoBar* object, bool take_copy = false);
} //namespace Glib


#endif /* _GTKMM_INFOBAR_H */

