
#ifndef _GTKMM_TEXT_H
#define _GTKMM_TEXT_H


#include <mm/glib/ustring.hpp>
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

#include <mm/gtk/widget.hpp>
#include <mm/gtk/editable.hpp>
#include <mm/gtk/entrybuffer.hpp>
#include <mm/gio/menumodel.hpp>
#include <mm/pango/attrlist.hpp>
#include <mm/pango/tabarray.hpp>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkText = struct _GtkText;
using GtkTextClass = struct _GtkTextClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{ class GTKMM_API Text_Class; } // namespace Gtk
#endif //DOXYGEN_SHOULD_SKIP_THIS

namespace Gtk
{

/** A simple single-line text entry field.
 *
 * The %Gtk::Text widget is a single-line text entry widget.
 * A fairly large set of key bindings are supported by default. If the
 * entered text is longer than the allocation of the widget, the widget
 * will scroll so that the cursor position is visible.
 *
 * When using an entry for passwords and other sensitive information,
 * it can be put into “password mode” using set_visibility().
 * In this mode, entered text is displayed using an “invisible” character.
 * By default, GTK picks the best invisible character that is available
 * in the current font, but it can be changed with set_invisible_char().
 *
 * If you are looking to add icons or progress display in an entry, look
 * at Gtk::Entry. There are other alternatives for more specialized use cases,
 * such as Gtk::SearchEntry.
 * If you need multi-line editable text, look at Gtk::TextView.
 *
 * @see Entry, TextView
 * @newin{3,96}
 *
 * @ingroup Widgets
 */

class GTKMM_API Text : public Widget,  public Editable
{
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  typedef Text CppObjectType;
  typedef Text_Class CppClassType;
  typedef GtkText BaseObjectType;
  typedef GtkTextClass BaseClassType;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

  Text(Text&& src) noexcept;
  auto operator=(Text&& src) noexcept -> Text&;

  // noncopyable
  Text(const Text&) = delete;
  auto operator=(const Text&) -> Text& = delete;

  ~Text() noexcept override;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

private:
  friend GTKMM_API class Text_Class;
  static CppClassType text_class_;

protected:
  explicit Text(const Glib::ConstructParams& construct_params);
  explicit Text(GtkText* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS


  static auto get_base_type() -> GType G_GNUC_CONST;
#endif

  /// Provides access to the underlying C GObject.
  auto       gobj() -> GtkText*       { return reinterpret_cast<GtkText*>(gobject_); }

  /// Provides access to the underlying C GObject.
  auto gobj() const -> const GtkText* { return reinterpret_cast<GtkText*>(gobject_); }

private:


public:
  Text();
    explicit Text(const Glib::RefPtr<EntryBuffer>& buffer);


  /** Get the `Gtk::EntryBuffer` object which holds the text for
   * this widget.
   *
   * @return A `Gtk::EntryBuffer` object.
   */
  auto get_buffer() -> Glib::RefPtr<EntryBuffer>;

  /** Get the `Gtk::EntryBuffer` object which holds the text for
   * this widget.
   *
   * @return A `Gtk::EntryBuffer` object.
   */
  auto get_buffer() const -> Glib::RefPtr<const EntryBuffer>;

  /** Set the `Gtk::EntryBuffer` object which holds the text for
   * this widget.
   *
   * @param buffer A `Gtk::EntryBuffer`.
   */
  void set_buffer(const Glib::RefPtr<EntryBuffer>& buffer);


  /** Sets whether the contents of the `Gtk::Text` are visible or not.
   *
   * When visibility is set to <tt>false</tt>, characters are displayed
   * as the invisible char, and will also appear that way when
   * the text in the widget is copied to the clipboard.
   *
   * By default, GTK picks the best invisible character available
   * in the current font, but it can be changed with
   * set_invisible_char().
   *
   * Note that you probably want to set property_input_purpose()
   * to Gtk::InputPurpose::PASSWORD or Gtk::InputPurpose::PIN to
   * inform input methods about the purpose of this self,
   * in addition to setting visibility to <tt>false</tt>.
   *
   * @param visible <tt>true</tt> if the contents of the `Gtk::Text` are displayed
   * as plaintext.
   */
  void set_visibility(bool visible =  true);

  /** Retrieves whether the text in @a self is visible.
   *
   * @return <tt>true</tt> if the text is currently visible.
   */
  auto get_visibility() const -> bool;

  /** Sets the character to use when in “password mode”.
   *
   * By default, GTK picks the best invisible char available in the
   * current font. If you set the invisible char to 0, then the user
   * will get no feedback at all; there will be no text on the screen
   * as they type.
   *
   * @param ch A Unicode character.
   */
  void set_invisible_char(gunichar ch);

  /** Unsets the invisible char.
   *
   * After calling this, the default invisible
   * char is used again.
   */
  void unset_invisible_char();

  /** Retrieves the character displayed when visibility is set to false.
   *
   * Note that GTK does not compute this value unless it needs it,
   * so the value returned by this function is not very useful unless
   * it has been explicitly set with set_invisible_char().
   *
   * @return The current invisible char, or 0, if @a text does not
   * show invisible text at all.
   */
  auto get_invisible_char() const -> gunichar;

  /** Sets whether the text is overwritten when typing
   * in the `Gtk::Text`.
   *
   * @param overwrite New value.
   */
  void set_overwrite_mode(bool overwrite =  true);

  /** Gets whether text is overwritten when typing in the `Gtk::Text`.
   *
   * See set_overwrite_mode().
   *
   * @return Whether the text is overwritten when typing.
   */
  auto get_overwrite_mode() const -> bool;

  /** Sets the maximum allowed length of the contents of the widget.
   *
   * If the current contents are longer than the given length, then
   * they will be truncated to fit.
   *
   * This is equivalent to getting @a self's `Gtk::EntryBuffer` and
   * calling Gtk::EntryBuffer::set_max_length() on it.
   *
   * @param max The maximum length of the `Gtk::Text`, or 0 for no maximum.
   * (other than the maximum length of entries.) The value passed
   * in will be clamped to the range 0-65536.
   */
  void set_max_length(int max);

  /** Retrieves the maximum allowed length of the text in @a self.
   *
   * See set_max_length().
   *
   * This is equivalent to getting @a self's `Gtk::EntryBuffer` and
   * calling Gtk::EntryBuffer::get_max_length() on it.
   *
   * @return The maximum allowed number of characters
   * in `Gtk::Text`, or 0 if there is no maximum.
   */
  auto get_max_length() const -> int;

  /** Retrieves the current length of the text in @a self.
   *
   * This is equivalent to getting @a self's `Gtk::EntryBuffer`
   * and calling Gtk::EntryBuffer::get_length() on it.
   *
   * @return The current number of characters
   * in `Gtk::Text`, or 0 if there are none.
   */
  auto get_text_length() const -> guint16;

  /** If @a setting is <tt>true</tt>, pressing Enter will activate
   * the default widget for the window containing @a self.
   *
   * This usually means that the dialog containing the `Gtk::Text`
   * will be closed, since the default widget is usually one of
   * the dialog buttons.
   *
   * @param setting <tt>true</tt> to activate window’s default widget on Enter keypress.
   */
  void set_activates_default(bool setting =  true);

  /** Returns whether pressing Enter will activate
   * the default widget for the window containing @a self.
   *
   * See set_activates_default().
   *
   * @return <tt>true</tt> if the `Gtk::Text` will activate the default widget.
   */
  auto get_activates_default() const -> bool;

  /** Retrieves the text that will be displayed when
   *  @a self is empty and unfocused
   *
   * If no placeholder text has been set, <tt>nullptr</tt> will be returned.
   *
   * @return The placeholder text.
   */
  auto get_placeholder_text() const -> Glib::ustring;

  /** Sets text to be displayed in @a self when it is empty.
   *
   * This can be used to give a visual hint of the expected
   * contents of the `Gtk::Text`.
   *
   * @param text A string to be displayed when @a self
   * is empty and unfocused.
   */
  void set_placeholder_text(const Glib::ustring& text);


  /** Sets the input purpose of the `Gtk::Text`.
   *
   * This can be used by on-screen keyboards and other
   * input methods to adjust their behaviour.
   *
   * @param purpose The purpose.
   */
  void set_input_purpose(InputPurpose purpose);

  /** Gets the input purpose of the `Gtk::Text`.
   */
  auto get_input_purpose() const -> InputPurpose;


  /** Sets input hints that allow input methods
   * to fine-tune their behaviour.
   *
   * @param hints The hints.
   */
  void set_input_hints(InputHints hints);

  /** Gets the input hints of the `Gtk::Text`.
   */
  auto get_input_hints() const -> InputHints;


  /** Sets attributes that are applied to the text.
   *
   * @param attrs A `Pango::AttrList`.
   */
  void set_attributes(Pango::AttrList& attrs);

  /** Gets the attribute list that was set on the `Gtk::Text`.
   *
   * See set_attributes().
   *
   * @return The attribute list.
   */
  auto get_attributes() const -> Pango::AttrList;


  /** Sets tabstops that are applied to the text.
   *
   * @param tabs A `Pango::TabArray`.
   */
  void set_tabs(const Pango::TabArray& tabs);

  /** Gets the tabstops that were set on the `Gtk::Text`.
   *
   * See set_tabs().
   *
   * @return The tabstops.
   */
  auto get_tabs() const -> Pango::TabArray;


  /** Causes @a self to have keyboard focus.
   *
   * It behaves like Gtk::Widget::grab_focus(),
   * except that it doesn't select the contents of @a self.
   * You only want to call this on some special entries
   * which the user usually doesn't want to replace all text in,
   * such as search-as-you-type entries.
   *
   * @return <tt>true</tt> if focus is now inside @a self.
   */
  auto grab_focus_without_selecting() -> bool;


  /** Sets a menu model to add when constructing
   * the context menu for @a self.
   *
   * @param model A `Gio::MenuModel`.
   */
  void set_extra_menu(const Glib::RefPtr<Gio::MenuModel>& model);

  /** Gets the menu model for extra items in the context menu.
   *
   * See set_extra_menu().
   *
   * @return The menu model.
   */
  auto get_extra_menu() -> Glib::RefPtr<Gio::MenuModel>;

  /** Gets the menu model for extra items in the context menu.
   *
   * See set_extra_menu().
   *
   * @return The menu model.
   */
  auto get_extra_menu() const -> Glib::RefPtr<const Gio::MenuModel>;


  /** Sets whether Emoji completion is enabled.
   *
   * If it is, typing ':', followed by a recognized keyword,
   * will pop up a window with suggested Emojis matching the
   * keyword.
   *
   * @param enable_emoji_completion <tt>true</tt> to enable Emoji completion.
   */
  void set_enable_emoji_completion(bool enable_emoji_completion =  true);

  /** Returns whether Emoji completion is enabled for this
   * `Gtk::Text` widget.
   *
   * @return <tt>true</tt> if Emoji completion is enabled.
   */
  auto get_enable_emoji_completion() const -> bool;

  /** Sets whether the `Gtk::Text` should grow and shrink with the content.
   *
   * @param propagate_text_width <tt>true</tt> to propagate the text width.
   */
  void set_propagate_text_width(bool propagate_text_width =  true);

  /** Returns whether the `Gtk::Text` will grow and shrink
   * with the content.
   *
   * @return <tt>true</tt> if @a self will propagate the text width.
   */
  auto get_propagate_text_width() const -> bool;

  /** Sets whether the `Gtk::Text` should truncate multi-line text
   * that is pasted into the widget.
   *
   * @param truncate_multiline <tt>true</tt> to truncate multi-line text.
   */
  void set_truncate_multiline(bool truncate_multiline =  true);

  /** Returns whether the `Gtk::Text` will truncate multi-line text
   * that is pasted into the widget
   *
   * @return <tt>true</tt> if @a self will truncate multi-line text.
   */
  auto get_truncate_multiline() const -> bool;

  // Action signals


  /** The `Gtk::EntryBuffer` object which stores the text.
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_buffer() -> Glib::PropertyProxy< Glib::RefPtr<EntryBuffer> > ;

/** The `Gtk::EntryBuffer` object which stores the text.
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_buffer() const -> Glib::PropertyProxy_ReadOnly< Glib::RefPtr<EntryBuffer> >;

  /** Maximum number of characters that are allowed.
   *
   * Zero indicates no limit.
   *
   * Default value: 0
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_max_length() -> Glib::PropertyProxy< int > ;

/** Maximum number of characters that are allowed.
   *
   * Zero indicates no limit.
   *
   * Default value: 0
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_max_length() const -> Glib::PropertyProxy_ReadOnly< int >;

  /** If <tt>false</tt>, the text is masked with the “invisible char”.
   *
   * Default value: <tt>true</tt>
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_visibility() -> Glib::PropertyProxy< bool > ;

/** If <tt>false</tt>, the text is masked with the “invisible char”.
   *
   * Default value: <tt>true</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_visibility() const -> Glib::PropertyProxy_ReadOnly< bool >;

  /** The character to used when masking contents (in “password mode”).
   *
   * Default value: 42
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_invisible_char() -> Glib::PropertyProxy< gunichar > ;

/** The character to used when masking contents (in “password mode”).
   *
   * Default value: 42
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_invisible_char() const -> Glib::PropertyProxy_ReadOnly< gunichar >;

  /** Whether the invisible char has been set for the `Gtk::Text`.
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_invisible_char_set() -> Glib::PropertyProxy< bool > ;

/** Whether the invisible char has been set for the `Gtk::Text`.
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_invisible_char_set() const -> Glib::PropertyProxy_ReadOnly< bool >;

  /** Whether to activate the default widget when Enter is pressed.
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_activates_default() -> Glib::PropertyProxy< bool > ;

/** Whether to activate the default widget when Enter is pressed.
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_activates_default() const -> Glib::PropertyProxy_ReadOnly< bool >;

  /** Number of pixels scrolled of the screen to the left.
   *
   * Default value: 0
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_scroll_offset() const -> Glib::PropertyProxy_ReadOnly< int >;


  /** When <tt>true</tt>, pasted multi-line text is truncated to the first line.
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_truncate_multiline() -> Glib::PropertyProxy< bool > ;

/** When <tt>true</tt>, pasted multi-line text is truncated to the first line.
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_truncate_multiline() const -> Glib::PropertyProxy_ReadOnly< bool >;

  /** If text is overwritten when typing in the `Gtk::Text`.
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_overwrite_mode() -> Glib::PropertyProxy< bool > ;

/** If text is overwritten when typing in the `Gtk::Text`.
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_overwrite_mode() const -> Glib::PropertyProxy_ReadOnly< bool >;

  /** Which IM (input method) module should be used for this self.
   *
   * See Gtk::IMMulticontext.
   *
   * Setting this to a non-<tt>nullptr</tt> value overrides the system-wide
   * IM module setting. See the Gtk::Settings::property_gtk_im_module()
   * property.
   *
   * Default value: ""
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_im_module() -> Glib::PropertyProxy< Glib::ustring > ;

/** Which IM (input method) module should be used for this self.
   *
   * See Gtk::IMMulticontext.
   *
   * Setting this to a non-<tt>nullptr</tt> value overrides the system-wide
   * IM module setting. See the Gtk::Settings::property_gtk_im_module()
   * property.
   *
   * Default value: ""
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_im_module() const -> Glib::PropertyProxy_ReadOnly< Glib::ustring >;

  /** The text that will be displayed in the `Gtk::Text` when it is empty
   * and unfocused.
   *
   * Default value: ""
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_placeholder_text() -> Glib::PropertyProxy< Glib::ustring > ;

/** The text that will be displayed in the `Gtk::Text` when it is empty
   * and unfocused.
   *
   * Default value: ""
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_placeholder_text() const -> Glib::PropertyProxy_ReadOnly< Glib::ustring >;

  /** The purpose of this text field.
   *
   * This property can be used by on-screen keyboards and other input
   * methods to adjust their behaviour.
   *
   * Note that setting the purpose to Gtk::InputPurpose::PASSWORD or
   * Gtk::InputPurpose::PIN is independent from setting
   * property_visibility().
   *
   * Default value: Gtk::InputPurpose::FREE_FORM
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_input_purpose() -> Glib::PropertyProxy< InputPurpose > ;

/** The purpose of this text field.
   *
   * This property can be used by on-screen keyboards and other input
   * methods to adjust their behaviour.
   *
   * Note that setting the purpose to Gtk::InputPurpose::PASSWORD or
   * Gtk::InputPurpose::PIN is independent from setting
   * property_visibility().
   *
   * Default value: Gtk::InputPurpose::FREE_FORM
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_input_purpose() const -> Glib::PropertyProxy_ReadOnly< InputPurpose >;

  /** Additional hints that allow input methods to fine-tune
   * their behaviour.
   *
   * Default value: Gtk::InputHints::NONE
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_input_hints() -> Glib::PropertyProxy< InputHints > ;

/** Additional hints that allow input methods to fine-tune
   * their behaviour.
   *
   * Default value: Gtk::InputHints::NONE
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_input_hints() const -> Glib::PropertyProxy_ReadOnly< InputHints >;

  /** A list of Pango attributes to apply to the text of the `Gtk::Text`.
   *
   * This is mainly useful to change the size or weight of the text.
   *
   * The `Pango::Attribute`'s @a start_index and @a end_index must refer to the
   * `Gtk::EntryBuffer` text, i.e. without the preedit string.
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_attributes() -> Glib::PropertyProxy< Pango::AttrList > ;

/** A list of Pango attributes to apply to the text of the `Gtk::Text`.
   *
   * This is mainly useful to change the size or weight of the text.
   *
   * The `Pango::Attribute`'s @a start_index and @a end_index must refer to the
   * `Gtk::EntryBuffer` text, i.e. without the preedit string.
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_attributes() const -> Glib::PropertyProxy_ReadOnly< Pango::AttrList >;

  /** A list of tabstops to apply to the text of the `Gtk::Text`.
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_tabs() -> Glib::PropertyProxy< Pango::TabArray > ;

/** A list of tabstops to apply to the text of the `Gtk::Text`.
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_tabs() const -> Glib::PropertyProxy_ReadOnly< Pango::TabArray >;

  /** Whether to suggest Emoji replacements.
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_enable_emoji_completion() -> Glib::PropertyProxy< bool > ;

/** Whether to suggest Emoji replacements.
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_enable_emoji_completion() const -> Glib::PropertyProxy_ReadOnly< bool >;

  /** Whether the widget should grow and shrink with the content.
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_propagate_text_width() -> Glib::PropertyProxy< bool > ;

/** Whether the widget should grow and shrink with the content.
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_propagate_text_width() const -> Glib::PropertyProxy_ReadOnly< bool >;

  /** A menu model whose contents will be appended to
   * the context menu.
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_extra_menu() -> Glib::PropertyProxy< Glib::RefPtr<Gio::MenuModel> > ;

/** A menu model whose contents will be appended to
   * the context menu.
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_extra_menu() const -> Glib::PropertyProxy_ReadOnly< Glib::RefPtr<Gio::MenuModel> >;


public:

public:
  //C++ methods used to invoke GTK+ virtual functions:

protected:
  //GTK+ Virtual Functions (override these to change behaviour):

  //Default Signal Handlers::


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
   * @relates Gtk::Text
   */
  GTKMM_API
  auto wrap(GtkText* object, bool take_copy = false) -> Gtk::Text*;
} //namespace Glib


#endif /* _GTKMM_TEXT_H */

