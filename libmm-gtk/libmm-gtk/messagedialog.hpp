
#ifndef _GTKMM_MESSAGEDIALOG_H
#define _GTKMM_MESSAGEDIALOG_H


#include <mm/glib/ustring.hpp>
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

#include <mm/gtk/dialog.hpp>
#include <mm/gtk/enums.hpp>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkMessageDialog = struct _GtkMessageDialog;
using GtkMessageDialogClass = struct _GtkMessageDialogClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{ class GTKMM_API MessageDialog_Class; } // namespace Gtk
#endif //DOXYGEN_SHOULD_SKIP_THIS

namespace Gtk
{


/** @addtogroup gtkmmEnums gtkmm Enums and Flags */

/**
 *  @var ButtonsType NONE
 * No buttons at all.
 *
 *  @var ButtonsType OK
 * An OK button.
 *
 *  @var ButtonsType CLOSE
 * A Close button.
 *
 *  @var ButtonsType CANCEL
 * A Cancel button.
 *
 *  @var ButtonsType YES_NO
 * Yes and No buttons.
 *
 *  @var ButtonsType OK_CANCEL
 * OK and Cancel buttons.
 *
 *  @enum ButtonsType
 *
 * Prebuilt sets of buttons for `Gtk::Dialog`.
 *
 * If none of these choices are appropriate, simply use
 * Gtk::ButtonsType::NONE and call Gtk::Dialog::add_buttons().
 *
 * > Please note that Gtk::ButtonsType::OK, Gtk::ButtonsType::YES_NO
 * > and Gtk::ButtonsType::OK_CANCEL are discouraged by the
 * > [GNOME Human Interface Guidelines](http://library.gnome.org/devel/hig-book/stable/).
 *
 * @ingroup gtkmmEnums
 */
enum class ButtonsType
{
  NONE,
  OK,
  CLOSE,
  CANCEL,
  YES_NO,
  OK_CANCEL
};


} // namespace Gtk

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

template <>
class GTKMM_API Value<Gtk::ButtonsType> : public Glib::Value_Enum<Gtk::ButtonsType>
{
public:
  static auto value_type() -> GType G_GNUC_CONST;
};

} // namespace Glib
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

namespace Gtk
{


/** Convenient message window.
 *
 * Gtk::MessageDialog presents a dialog with an image representing the type
 * of message (Error, Question, etc.) alongside some message text. It's
 * simply a convenience widget; you could construct the equivalent of
 * Gtk::MessageDialog from Gtk::Dialog without too much effort, but
 * Gtk::MessageDialog saves typing.
 *
 * A MessageDialog looks like this:
 * @image html messagedialog1.png
 *
 * @ingroup Dialogs
 */

class GTKMM_API MessageDialog : public Dialog
{
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  typedef MessageDialog CppObjectType;
  typedef MessageDialog_Class CppClassType;
  typedef GtkMessageDialog BaseObjectType;
  typedef GtkMessageDialogClass BaseClassType;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

  MessageDialog(MessageDialog&& src) noexcept;
  auto operator=(MessageDialog&& src) noexcept -> MessageDialog&;

  // noncopyable
  MessageDialog(const MessageDialog&) = delete;
  auto operator=(const MessageDialog&) -> MessageDialog& = delete;

  ~MessageDialog() noexcept override;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

private:
  friend GTKMM_API class MessageDialog_Class;
  static CppClassType messagedialog_class_;

protected:
  explicit MessageDialog(const Glib::ConstructParams& construct_params);
  explicit MessageDialog(GtkMessageDialog* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS


  static auto get_base_type() -> GType G_GNUC_CONST;
#endif

  /// Provides access to the underlying C GObject.
  auto       gobj() -> GtkMessageDialog*       { return reinterpret_cast<GtkMessageDialog*>(gobject_); }

  /// Provides access to the underlying C GObject.
  auto gobj() const -> const GtkMessageDialog* { return reinterpret_cast<GtkMessageDialog*>(gobject_); }

private:


public:
  explicit MessageDialog(const Glib::ustring& message, bool use_markup = false, MessageType type = MessageType::INFO, ButtonsType buttons = ButtonsType::OK, bool modal = false);
  MessageDialog(Gtk::Window& parent, const Glib::ustring& message, bool use_markup = false, MessageType type = MessageType::INFO, ButtonsType buttons = ButtonsType::OK, bool modal = false);


  /** Sets the primary text of the message dialog.
   *
   * @param message The message.
   * @param use_markup Whether @a message contains pango markup.
   */
  void set_message(const Glib::ustring& message, bool use_markup = false);


  /** Sets the secondary text of the message dialog.
   * Note that setting a secondary text makes the primary text become bold, unless you have provided explicit markup.
   *
   * @newin{2,6}
   *
   * @param text The message.
   * @param use_markup Whether @a message contains pango markup.
   */
  void set_secondary_text(const Glib::ustring& text, bool use_markup = false);


  /** Returns the message area of the dialog.
   *
   * This is the box where the dialog’s primary and secondary labels
   * are packed. You can add your own extra content to that box and it
   * will appear below those labels. See Gtk::Dialog::get_content_area()
   * for the corresponding function in the parent Gtk::Dialog.
   *
   * @return A `Gtk::Box` corresponding to the
   * “message area” in the @a message_dialog.
   */
  auto get_message_area() -> Box*;

  /** Returns the message area of the dialog.
   *
   * This is the box where the dialog’s primary and secondary labels
   * are packed. You can add your own extra content to that box and it
   * will appear below those labels. See Gtk::Dialog::get_content_area()
   * for the corresponding function in the parent Gtk::Dialog.
   *
   * @return A `Gtk::Box` corresponding to the
   * “message area” in the @a message_dialog.
   */
  auto get_message_area() const -> const Box*;

  /** The type of the message.
   *
   * Default value: Gtk::MessageType::INFO
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_message_type() -> Glib::PropertyProxy< MessageType > ;

/** The type of the message.
   *
   * Default value: Gtk::MessageType::INFO
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_message_type() const -> Glib::PropertyProxy_ReadOnly< MessageType >;

  //Not wrapped because it is write-only and construct: _WRAP_PROPERTY("buttons", ButtonsType)
  /** The primary text of the message dialog.
   *
   * If the dialog has a secondary text, this will appear as the title.
   *
   * Default value: ""
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_text() -> Glib::PropertyProxy< Glib::ustring > ;

/** The primary text of the message dialog.
   *
   * If the dialog has a secondary text, this will appear as the title.
   *
   * Default value: ""
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_text() const -> Glib::PropertyProxy_ReadOnly< Glib::ustring >;

  /** <tt>true</tt> if the primary text of the dialog includes Pango markup.
   *
   * See pango_parse_markup().
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_use_markup() -> Glib::PropertyProxy< bool > ;

/** <tt>true</tt> if the primary text of the dialog includes Pango markup.
   *
   * See pango_parse_markup().
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_use_markup() const -> Glib::PropertyProxy_ReadOnly< bool >;

  /** The secondary text of the message dialog.
   *
   * Default value: ""
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_secondary_text() -> Glib::PropertyProxy< Glib::ustring > ;

/** The secondary text of the message dialog.
   *
   * Default value: ""
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_secondary_text() const -> Glib::PropertyProxy_ReadOnly< Glib::ustring >;

  /** <tt>true</tt> if the secondary text of the dialog includes Pango markup.
   *
   * See pango_parse_markup().
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_secondary_use_markup() -> Glib::PropertyProxy< bool > ;

/** <tt>true</tt> if the secondary text of the dialog includes Pango markup.
   *
   * See pango_parse_markup().
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_secondary_use_markup() const -> Glib::PropertyProxy_ReadOnly< bool >;

  /** The `Gtk::Box` that corresponds to the message area of this dialog.
   *
   * See Gtk::MessageDialog::get_message_area() for a detailed
   * description of this area.
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_message_area() const -> Glib::PropertyProxy_ReadOnly< Box* >;


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
   * @relates Gtk::MessageDialog
   */
  GTKMM_API
  auto wrap(GtkMessageDialog* object, bool take_copy = false) -> Gtk::MessageDialog*;
} //namespace Glib


#endif /* _GTKMM_MESSAGEDIALOG_H */

