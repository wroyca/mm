
#ifndef _GTKMM_ENTRY_H
#define _GTKMM_ENTRY_H


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

#include <mm/gtk/widget.hpp>
#include <mm/gtk/editable.hpp>
#include <mm/gtk/celleditable.hpp>
#include <mm/gtk/entrycompletion.hpp>
#include <mm/gtk/image.hpp> //For Image::Type.
#include <mm/gtk/border.hpp>
#include <mm/gtk/entrybuffer.hpp>
#include <mm/gio/menumodel.hpp>
#include <mm/pango/attrlist.hpp>
#include <mm/pango/tabarray.hpp>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkEntry = struct _GtkEntry;
using GtkEntryClass = struct _GtkEntryClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{ class GTKMM_API Entry_Class; } // namespace Gtk
#endif //DOXYGEN_SHOULD_SKIP_THIS

namespace Gtk
{

/** A single line text entry field.
 *
 * The Gtk::Entry widget is a single line text entry widget. A fairly large
 * set of key bindings are supported by default. If the entered text is
 * longer than the allocation of the widget, the widget will scroll so that
 * the cursor position is visible.
 *
 * The Entry widget looks like this:
 * @image html entry1.png
 *
 * @ingroup Widgets
 */

class Entry
: public Widget,
  public Editable,
  public CellEditable
{
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  typedef Entry CppObjectType;
  typedef Entry_Class CppClassType;
  typedef GtkEntry BaseObjectType;
  typedef GtkEntryClass BaseClassType;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

  Entry(Entry&& src) noexcept;
  auto operator=(Entry&& src) noexcept -> Entry&;

  // noncopyable
  Entry(const Entry&) = delete;
  auto operator=(const Entry&) -> Entry& = delete;

  ~Entry() noexcept override;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

private:
  friend GTKMM_API class Entry_Class;
  static CppClassType entry_class_;

protected:
  explicit Entry(const Glib::ConstructParams& construct_params);
  explicit Entry(GtkEntry* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS


  static auto get_base_type() -> GType G_GNUC_CONST;
#endif

  /// Provides access to the underlying C GObject.
  auto       gobj() -> GtkEntry*       { return reinterpret_cast<GtkEntry*>(gobject_); }

  /// Provides access to the underlying C GObject.
  auto gobj() const -> const GtkEntry* { return reinterpret_cast<GtkEntry*>(gobject_); }

private:


public:
  /** @addtogroup gtkmmEnums gtkmm Enums and Flags */

  /**
   *  @var IconPosition PRIMARY
   * At the beginning of the entry (depending on the text direction).
   *
   *  @var IconPosition SECONDARY
   * At the end of the entry (depending on the text direction).
   *
   *  @enum IconPosition
   *
   * Specifies the side of the entry at which an icon is placed.
   *
   * @ingroup gtkmmEnums
   */
  enum class IconPosition
  {
    PRIMARY,
    SECONDARY
  };


  Entry();
    explicit Entry(const Glib::RefPtr<EntryBuffer>& buffer);


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

  /** Sets whether the contents of the entry are visible or not.
   *
   * When visibility is set to <tt>false</tt>, characters are displayed
   * as the invisible char, and will also appear that way when
   * the text in the entry widget is copied elsewhere.
   *
   * By default, GTK picks the best invisible character available
   * in the current font, but it can be changed with
   * set_invisible_char().
   *
   * Note that you probably want to set property_input_purpose()
   * to Gtk::InputPurpose::PASSWORD or Gtk::InputPurpose::PIN to
   * inform input methods about the purpose of this entry,
   * in addition to setting visibility to <tt>false</tt>.
   *
   * @param visible <tt>true</tt> if the contents of the entry are displayed as plaintext.
   */
  void set_visibility(bool visible =  true);

  /** Retrieves whether the text in @a entry is visible.
   *
   * See set_visibility().
   *
   * @return <tt>true</tt> if the text is currently visible.
   */
  auto get_visibility() const -> bool;

  /** Sets the character to use in place of the actual text
   * in “password mode”.
   *
   * See set_visibility() for how to enable
   * “password mode”.
   *
   * By default, GTK picks the best invisible char available in
   * the current font. If you set the invisible char to 0, then
   * the user will get no feedback at all; there will be no text
   * on the screen as they type.
   *
   * @param ch A Unicode character.
   */
  void set_invisible_char(gunichar ch);

  /** Unsets the invisible char, so that the default invisible char
   * is used again. See set_invisible_char().
   */
  void unset_invisible_char();

  /** Retrieves the character displayed in place of the actual text
   * in “password mode”.
   *
   * @return The current invisible char, or 0, if the entry does not
   * show invisible text at all.
   */
  auto get_invisible_char() const -> gunichar;

  /** Sets whether the entry has a beveled frame around it.
   *
   * @param setting New value.
   */
  void set_has_frame(bool setting =  true);

  /** Gets the value set by set_has_frame().
   *
   * @return Whether the entry has a beveled frame.
   */
  auto get_has_frame() const -> bool;


  /** Sets whether the text is overwritten when typing in the `Gtk::Entry`.
   *
   * @param overwrite New value.
   */
  void set_overwrite_mode(bool overwrite =  true);

  /** Gets whether the `Gtk::Entry` is in overwrite mode.
   *
   * @return Whether the text is overwritten when typing.
   */
  auto get_overwrite_mode() const -> bool;

  /** Sets the maximum allowed length of the contents of the widget.
   *
   * If the current contents are longer than the given length, then
   * they will be truncated to fit. The length is is in characters.
   *
   * This is equivalent to getting @a entry's `Gtk::EntryBuffer` and
   * calling Gtk::EntryBuffer::set_max_length() on it.
   *
   * @param max The maximum length of the entry, or 0 for no maximum.
   * (other than the maximum length of entries.) The value passed in will
   * be clamped to the range 0-65536.
   */
  void set_max_length(int max);

  /** Retrieves the maximum allowed length of the text in @a entry.
   *
   * See set_max_length().
   *
   * @return The maximum allowed number of characters
   * in `Gtk::Entry`, or 0 if there is no maximum.
   */
  auto get_max_length() const -> int;

  /** Retrieves the current length of the text in @a entry.
   *
   * This is equivalent to getting @a entry's `Gtk::EntryBuffer`
   * and calling Gtk::EntryBuffer::get_length() on it.
   *
   * @return The current number of characters
   * in `Gtk::Entry`, or 0 if there are none.
   */
  auto get_text_length() const -> guint16;

  /** Sets whether pressing Enter in the @a entry will activate the default
   * widget for the window containing the entry.
   *
   * This usually means that the dialog containing the entry will be closed,
   * since the default widget is usually one of the dialog buttons.
   *
   * @param setting <tt>true</tt> to activate window’s default widget on Enter keypress.
   */
  void set_activates_default(bool setting =  true);

  /** Retrieves the value set by set_activates_default().
   *
   * @return <tt>true</tt> if the entry will activate the default widget.
   */
  auto get_activates_default() const -> gboolean;


  /** Sets the alignment for the contents of the entry.
   *
   * This controls the horizontal positioning of the contents when
   * the displayed text is shorter than the width of the entry.
   *
   * See also: Gtk::Editable::property_xalign()
   *
   * @param xalign The horizontal alignment, from 0 (left) to 1 (right).
   * Reversed for RTL layouts.
   */
  void set_alignment(float xalign);

  /** Sets the alignment for the contents of the entry.
   *
   * This controls the horizontal positioning of the contents when
   * the displayed text is shorter than the width of the entry.
   *
   * See also: Gtk::Editable::property_xalign()
   *
   * @param xalign The horizontal alignment, from 0 (left) to 1 (right).
   * Reversed for RTL layouts.
   */
  void set_alignment(Align xalign);

  /** Gets the value set by set_alignment().
   *
   * See also: Gtk::Editable::property_xalign()
   *
   * @return The alignment.
   */
  auto get_alignment() const -> float;


  /** Sets @a completion to be the auxiliary completion object
   * to use with @a entry.
   *
   * All further configuration of the completion mechanism is
   * done on @a completion using the `Gtk::EntryCompletion` API.
   * Completion is disabled if @a completion is set to <tt>nullptr</tt>.
   *
   * @param completion The `Gtk::EntryCompletion`.
   */
  void set_completion(const Glib::RefPtr<EntryCompletion>& completion);

  /** Returns the auxiliary completion object currently
   * in use by @a entry.
   *
   * @return The auxiliary
   * completion object currently in use by @a entry.
   */
  auto get_completion() -> Glib::RefPtr<EntryCompletion>;

  /** Returns the auxiliary completion object currently
   * in use by @a entry.
   *
   * @return The auxiliary
   * completion object currently in use by @a entry.
   */
  auto get_completion() const -> Glib::RefPtr<const EntryCompletion>;


  /** Causes the entry’s progress indicator to “fill in” the given
   * fraction of the bar.
   *
   * The fraction should be between 0.0 and 1.0, inclusive.
   *
   * @param fraction Fraction of the task that’s been completed.
   */
  void set_progress_fraction(double fraction);

  /** Returns the current fraction of the task that’s been completed.
   *
   * See set_progress_fraction().
   *
   * @return A fraction from 0.0 to 1.0.
   */
  auto get_progress_fraction() const -> double;

  /** Sets the fraction of total entry width to move the progress
   * bouncing block for each pulse.
   *
   * Use progress_pulse() to pulse
   * the progress.
   *
   * @param fraction Fraction between 0.0 and 1.0.
   */
  void set_progress_pulse_step(double fraction);

  /** Retrieves the pulse step set with
   * set_progress_pulse_step().
   *
   * @return A fraction from 0.0 to 1.0.
   */
  auto get_progress_pulse_step() -> double;

  /** Indicates that some progress is made, but you don’t
   * know how much.
   *
   * Causes the entry’s progress indicator to enter “activity
   * mode”, where a block bounces back and forth. Each call to
   * progress_pulse() causes the block to move by a
   * little bit (the amount of movement per pulse is determined
   * by set_progress_pulse_step()).
   */
  void progress_pulse();


  /** Retrieves the text that will be displayed when @a entry
   * is empty and unfocused
   *
   * @return A pointer to the
   * placeholder text as a string. This string points to
   * internally allocated storage in the widget and must
   * not be freed, modified or stored. If no placeholder
   * text has been set, <tt>nullptr</tt> will be returned.
   */
  auto get_placeholder_text() const -> Glib::ustring;

  /** Sets text to be displayed in @a entry when it is empty.
   *
   * This can be used to give a visual hint of the expected
   * contents of the `Gtk::Entry`.
   *
   * @param text A string to be displayed when @a entry is empty and unfocused.
   */
  void set_placeholder_text(const Glib::ustring& text);


  /** Sets the icon shown in the specified position using a `Gdk::Paintable`.
   *
   * If @a paintable is <tt>nullptr</tt>, no icon will be shown in the specified position.
   *
   * @param icon_pos Icon position.
   * @param paintable A `Gdk::Paintable`.
   */
  void set_icon_from_paintable(const Glib::RefPtr<Gdk::Paintable>& paintable, IconPosition icon_pos =  IconPosition::PRIMARY);


  /** Sets the icon shown in the entry at the specified position
   * from the current icon theme.
   *
   * If the icon name isn’t known, a “broken image” icon will be
   * displayed instead.
   *
   * If @a icon_name is <tt>nullptr</tt>, no icon will be shown in the
   * specified position.
   *
   * @param icon_pos The position at which to set the icon.
   * @param icon_name An icon name.
   */

  void set_icon_from_icon_name(const Glib::ustring& icon_name, IconPosition icon_pos = IconPosition::PRIMARY);


  /** Sets the icon shown in the entry at the specified position
   * from the current icon theme.
   *
   * If the icon isn’t known, a “broken image” icon will be
   * displayed instead.
   *
   * If @a icon is <tt>nullptr</tt>, no icon will be shown in the
   * specified position.
   *
   * @param icon_pos The position at which to set the icon.
   * @param icon The icon to set.
   */

  void set_icon_from_gicon(const Glib::RefPtr<Gio::Icon>& icon, IconPosition icon_pos = IconPosition::PRIMARY);


  /** Do not show any icon in the specified position.
   * See set_icon_from_paintable(), set_icon_from_icon_name(), and set_icon_from_gicon().
   *
   * @param icon_pos The icon position.
   *
   * @newin{3,0}
   */
  void unset_icon(IconPosition icon_pos = IconPosition::PRIMARY);


  /** Gets the type of representation being used by the icon
   * to store image data.
   *
   * If the icon has no image data, the return value will
   * be Gtk::Image::Type::EMPTY.
   *
   * @param icon_pos Icon position.
   * @return Image representation being used.
   */
  auto get_icon_storage_type(IconPosition icon_pos =  IconPosition::PRIMARY) const -> Image::Type;

  /** Retrieves the `Gdk::Paintable` used for the icon.
   *
   * If no `Gdk::Paintable` was used for the icon, <tt>nullptr</tt> is returned.
   *
   * @param icon_pos Icon position.
   * @return A `Gdk::Paintable`
   * if no icon is set for this position or the icon set is not
   * a `Gdk::Paintable`.
   */
  auto get_icon_paintable(IconPosition icon_pos =  IconPosition::PRIMARY) -> Glib::RefPtr<Gdk::Paintable>;

  /** Retrieves the `Gdk::Paintable` used for the icon.
   *
   * If no `Gdk::Paintable` was used for the icon, <tt>nullptr</tt> is returned.
   *
   * @param icon_pos Icon position.
   * @return A `Gdk::Paintable`
   * if no icon is set for this position or the icon set is not
   * a `Gdk::Paintable`.
   */
  auto get_icon_paintable(IconPosition icon_pos =  IconPosition::PRIMARY) const -> Glib::RefPtr<const Gdk::Paintable>;

  /** Retrieves the icon name used for the icon.
   *
   * <tt>nullptr</tt> is returned if there is no icon or if the icon was set
   * by some other method (e.g., by `Gdk::Paintable` or gicon).
   *
   * @param icon_pos Icon position.
   * @return An icon name.
   */
  auto get_icon_name(IconPosition icon_pos =  IconPosition::PRIMARY) const -> Glib::ustring;

  /** Retrieves the `Gio::Icon` used for the icon.
   *
   * <tt>nullptr</tt> will be returned if there is no icon or if the icon was
   * set by some other method (e.g., by `Gdk::Paintable` or icon name).
   *
   * @param icon_pos Icon position.
   * @return A `Gio::Icon`.
   */
  auto get_icon_gicon(IconPosition icon_pos =  IconPosition::PRIMARY) -> Glib::RefPtr<Gio::Icon>;

  /** Retrieves the `Gio::Icon` used for the icon.
   *
   * <tt>nullptr</tt> will be returned if there is no icon or if the icon was
   * set by some other method (e.g., by `Gdk::Paintable` or icon name).
   *
   * @param icon_pos Icon position.
   * @return A `Gio::Icon`.
   */
  auto get_icon_gicon(IconPosition icon_pos =  IconPosition::PRIMARY) const -> Glib::RefPtr<const Gio::Icon>;


  /** Sets whether the icon is activatable.
   *
   * @param icon_pos Icon position.
   * @param activatable <tt>true</tt> if the icon should be activatable.
   */

  void set_icon_activatable(bool activatable = true, IconPosition icon_pos = IconPosition::PRIMARY);


  /** Returns whether the icon is activatable.
   *
   * @param icon_pos Icon position.
   * @return <tt>true</tt> if the icon is activatable.
   */
  auto get_icon_activatable(IconPosition icon_pos =  IconPosition::PRIMARY) const -> bool;

  /** Sets the sensitivity for the specified icon.
   *
   * @param icon_pos Icon position.
   * @param sensitive Specifies whether the icon should appear
   * sensitive or insensitive.
   */
  void set_icon_sensitive(IconPosition icon_pos =  IconPosition::PRIMARY, bool sensitive =  true);

  /** Returns whether the icon appears sensitive or insensitive.
   *
   * @param icon_pos Icon position.
   * @return <tt>true</tt> if the icon is sensitive.
   */
  auto get_icon_sensitive(IconPosition icon_pos =  IconPosition::PRIMARY) -> bool;

  /** Finds the icon at the given position and return its index.
   *
   * The position’s coordinates are relative to the @a entry’s
   * top left corner. If @a x, @a y doesn’t lie inside an icon,
   * -1 is returned. This function is intended for use in a
   * Gtk::Widget::signal_query_tooltip() signal handler.
   *
   * @param x The x coordinate of the position to find, relative to @a entry.
   * @param y The y coordinate of the position to find, relative to @a entry.
   * @return The index of the icon at the given position, or -1.
   */
  auto get_icon_at_pos(int x, int y) const -> int;


  /** Sets @a tooltip as the contents of the tooltip for the icon
   * at the specified position.
   *
   * Use <tt>nullptr</tt> for @a tooltip to remove an existing tooltip.
   *
   * See also Gtk::Widget::set_tooltip_text() and
   * set_icon_tooltip_markup().
   *
   * If you unset the widget tooltip via
   * Gtk::Widget::set_tooltip_text() or
   * Gtk::Widget::set_tooltip_markup(), this sets
   * Gtk::Widget::property_has_tooltip() to <tt>false</tt>, which suppresses
   * icon tooltips too. You can resolve this by then calling
   * Gtk::Widget::set_has_tooltip() to set
   * Gtk::Widget::property_has_tooltip() back to <tt>true</tt>, or
   * setting at least one non-empty tooltip on any icon
   * achieves the same result.
   *
   * @param icon_pos The icon position.
   * @param tooltip The contents of the tooltip for the icon.
   */

  void set_icon_tooltip_text(const Glib::ustring& tooltip, IconPosition icon_pos = IconPosition::PRIMARY);


  /** Gets the contents of the tooltip on the icon at the specified
   * position in @a entry.
   *
   * @param icon_pos The icon position.
   * @return The tooltip text.
   */
  auto get_icon_tooltip_text(IconPosition icon_pos =  IconPosition::PRIMARY) const -> Glib::ustring;


  /** Sets @a tooltip as the contents of the tooltip for the icon at
   * the specified position.
   *
   *  @a tooltip is assumed to be marked up with Pango Markup.
   *
   * Use <tt>nullptr</tt> for @a tooltip to remove an existing tooltip.
   *
   * See also Gtk::Widget::set_tooltip_markup() and
   * set_icon_tooltip_text().
   *
   * @param icon_pos The icon position.
   * @param tooltip The contents of the tooltip for the icon.
   */

  void set_icon_tooltip_markup(const Glib::ustring& tooltip, IconPosition icon_pos = IconPosition::PRIMARY);


  /** Gets the contents of the tooltip on the icon at the specified
   * position in @a entry.
   *
   * @param icon_pos The icon position.
   * @return The tooltip text.
   */
  auto get_icon_tooltip_markup(IconPosition icon_pos =  IconPosition::PRIMARY) const -> Glib::ustring;


  /** Sets up the icon at the given position as drag source.
   *
   * This makes it so that GTK will start a drag
   * operation when the user clicks and drags the icon.
   *
   * @param icon_pos Icon position.
   * @param provider A `Gdk::ContentProvider`.
   * @param actions A bitmask of the allowed drag actions.
   */
  void set_icon_drag_source(const Glib::RefPtr<Gdk::ContentProvider>& provider, Gdk::DragAction actions =  Gdk::DragAction::COPY, IconPosition icon_pos =  IconPosition::PRIMARY);

  /** Returns the area where entry's icon at @a icon_pos is drawn.
   * This function is useful when drawing something to the
   * entry in a draw callback.
   *
   * @param icon_pos Icon position.
   * @result The location for the icon area.
   *
   * @newin{3,0}
   */
  auto get_icon_area(IconPosition icon_pos = IconPosition::PRIMARY) const -> Gdk::Rectangle;


  /** Returns the index of the icon which is the source of the
   * current  DND operation, or -1.
   *
   * @return Index of the icon which is the source of the
   * current DND operation, or -1.
   */
  auto get_current_icon_drag_source() -> int;

  /** Reset the input method context of the entry if needed.
   *
   * This can be necessary in the case where modifying the buffer
   * would confuse on-going input method behavior.
   */
  void reset_im_context();


  /** Sets the input purpose which can be used by input methods
   * to adjust their behavior.
   *
   * @param purpose The purpose.
   */
  void set_input_purpose(InputPurpose purpose);

  /** Gets the input purpose of the `Gtk::Entry`.
   *
   * @return The input purpose.
   */
  auto get_input_purpose() const -> InputPurpose;


  /** Set additional hints which allow input methods to
   * fine-tune their behavior.
   *
   * @param hints The hints.
   */
  void set_input_hints(InputHints hints);

  /** Gets the input hints of this `Gtk::Entry`.
   *
   * @return The input hints.
   */
  auto get_input_hints() const -> InputHints;


  /** Sets a `Pango::AttrList`.
   *
   * The attributes in the list are applied to the entry text.
   *
   * Since the attributes will be applies to text that changes
   * as the user types, it makes most sense to use attributes
   * with unlimited extent.
   *
   * @param attrs A `Pango::AttrList`.
   */
  void set_attributes(Pango::AttrList& attrs);

  /** Gets the attribute list of the `Gtk::Entry`.
   *
   * See set_attributes().
   *
   * @return The attribute list.
   */
  auto get_attributes() const -> Pango::AttrList;


  /** Sets a `Pango::TabArray`.
   *
   * The tabstops in the array are applied to the entry text.
   *
   * @param tabs A `Pango::TabArray`.
   */
  void set_tabs(const Pango::TabArray& tabs);

  /** Gets the tabstops of the `GtkEntry.
   *
   * See set_tabs().
   *
   * @return The tabstops.
   */
  auto get_tabs() const -> Pango::TabArray;


  /** Causes @a entry to have keyboard focus.
   *
   * It behaves like Gtk::Widget::grab_focus(), except that it doesn't
   * select the contents of the entry. You only want to call this on some
   * special entries which the user usually doesn't want to replace all text
   * in, such as search-as-you-type entries.
   */
  void grab_focus_without_selecting();


  /** Sets a menu model to add when constructing
   * the context menu for @a entry.
   *
   * @param model A `Gio::MenuModel`.
   */
  void set_extra_menu(const Glib::RefPtr<Gio::MenuModel>& model);

  /** Gets the menu model set with set_extra_menu().
   *
   * @return The menu model.
   */
  auto get_extra_menu() -> Glib::RefPtr<Gio::MenuModel>;

  /** Gets the menu model set with set_extra_menu().
   *
   * @return The menu model.
   */
  auto get_extra_menu() const -> Glib::RefPtr<const Gio::MenuModel>;

  //TODO: Remove no_default_handler on "activate" when we can break ABI.
  // "activate" is an action signal. Nevertheless it can be used by applications.
  // https://gitlab.gnome.org/GNOME/gtk/-/issues/4848
  // https://gitlab.gnome.org/GNOME/gtkmm/-/issues/100

  /**
   * @par Slot Prototype:
   * <tt>void on_my_%activate()</tt>
   *
   * Flags: Run Last, Action
   *
   * Emitted when the entry is activated.
   *
   * The keybindings for this signal are all forms of the Enter key.
   *
   * @newin{4,8}
   */

  auto signal_activate() -> Glib::SignalProxy<void()>;


  // no_default_handler because the wrapped C signals have no default handlers.

  /**
   * @par Slot Prototype:
   * <tt>void on_my_%icon_release(IconPosition icon_position)</tt>
   *
   * Flags: Run Last
   *
   * Emitted on the button release from a mouse click
   * over an activatable icon.
   *
   * @param icon_position The position of the clicked icon.
   */

  auto signal_icon_release() -> Glib::SignalProxy<void(IconPosition)>;


  /**
   * @par Slot Prototype:
   * <tt>void on_my_%icon_press(IconPosition icon_position)</tt>
   *
   * Flags: Run Last
   *
   * Emitted when an activatable icon is clicked.
   *
   * @param icon_position The position of the clicked icon.
   */

  auto signal_icon_press() -> Glib::SignalProxy<void(IconPosition)>;


  /** The buffer object which actually stores the text.
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_buffer() -> Glib::PropertyProxy< Glib::RefPtr<EntryBuffer> > ;

/** The buffer object which actually stores the text.
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_buffer() const -> Glib::PropertyProxy_ReadOnly< Glib::RefPtr<EntryBuffer> >;

  /** Maximum number of characters for this entry.
   *
   * Default value: 0
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_max_length() -> Glib::PropertyProxy< int > ;

/** Maximum number of characters for this entry.
   *
   * Default value: 0
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_max_length() const -> Glib::PropertyProxy_ReadOnly< int >;

  /** Whether the entry should show the “invisible char” instead of the
   * actual text (“password mode”).
   *
   * Default value: <tt>true</tt>
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_visibility() -> Glib::PropertyProxy< bool > ;

/** Whether the entry should show the “invisible char” instead of the
   * actual text (“password mode”).
   *
   * Default value: <tt>true</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_visibility() const -> Glib::PropertyProxy_ReadOnly< bool >;

  /** Whehter the entry should draw a frame.
   *
   * Default value: <tt>true</tt>
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_has_frame() -> Glib::PropertyProxy< bool > ;

/** Whehter the entry should draw a frame.
   *
   * Default value: <tt>true</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_has_frame() const -> Glib::PropertyProxy_ReadOnly< bool >;

  /** The character to use when masking entry contents (“password mode”).
   *
   * Default value: 42
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_invisible_char() -> Glib::PropertyProxy< gunichar > ;

/** The character to use when masking entry contents (“password mode”).
   *
   * Default value: 42
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_invisible_char() const -> Glib::PropertyProxy_ReadOnly< gunichar >;

  /** Whether the invisible char has been set for the `Gtk::Entry`.
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_invisible_char_set() -> Glib::PropertyProxy< bool > ;

/** Whether the invisible char has been set for the `Gtk::Entry`.
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

  /** Number of pixels of the entry scrolled off the screen to the left.
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

  /** If text is overwritten when typing in the `Gtk::Entry`.
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_overwrite_mode() -> Glib::PropertyProxy< bool > ;

/** If text is overwritten when typing in the `Gtk::Entry`.
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_overwrite_mode() const -> Glib::PropertyProxy_ReadOnly< bool >;

  /** The length of the text in the `Gtk::Entry`.
   *
   * Default value: 0
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_text_length() const -> Glib::PropertyProxy_ReadOnly< guint >;


  /** The current fraction of the task that's been completed.
   *
   * Default value: 0
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_progress_fraction() -> Glib::PropertyProxy< double > ;

/** The current fraction of the task that's been completed.
   *
   * Default value: 0
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_progress_fraction() const -> Glib::PropertyProxy_ReadOnly< double >;

  /** The fraction of total entry width to move the progress
   * bouncing block for each pulse.
   *
   * See Gtk::Entry::progress_pulse().
   *
   * Default value: 0
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_progress_pulse_step() -> Glib::PropertyProxy< double > ;

/** The fraction of total entry width to move the progress
   * bouncing block for each pulse.
   *
   * See Gtk::Entry::progress_pulse().
   *
   * Default value: 0
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_progress_pulse_step() const -> Glib::PropertyProxy_ReadOnly< double >;

  /** A `Gdk::Paintable` to use as the primary icon for the entry.
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_primary_icon_paintable() -> Glib::PropertyProxy< Glib::RefPtr<Gdk::Paintable> > ;

/** A `Gdk::Paintable` to use as the primary icon for the entry.
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_primary_icon_paintable() const -> Glib::PropertyProxy_ReadOnly< Glib::RefPtr<Gdk::Paintable> >;

  /** A `Gdk::Paintable` to use as the secondary icon for the entry.
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_secondary_icon_paintable() -> Glib::PropertyProxy< Glib::RefPtr<Gdk::Paintable> > ;

/** A `Gdk::Paintable` to use as the secondary icon for the entry.
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_secondary_icon_paintable() const -> Glib::PropertyProxy_ReadOnly< Glib::RefPtr<Gdk::Paintable> >;

  /** The icon name to use for the primary icon for the entry.
   *
   * Default value: ""
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_primary_icon_name() -> Glib::PropertyProxy< Glib::ustring > ;

/** The icon name to use for the primary icon for the entry.
   *
   * Default value: ""
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_primary_icon_name() const -> Glib::PropertyProxy_ReadOnly< Glib::ustring >;

  /** The icon name to use for the secondary icon for the entry.
   *
   * Default value: ""
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_secondary_icon_name() -> Glib::PropertyProxy< Glib::ustring > ;

/** The icon name to use for the secondary icon for the entry.
   *
   * Default value: ""
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_secondary_icon_name() const -> Glib::PropertyProxy_ReadOnly< Glib::ustring >;

  /** The `Gio::Icon` to use for the primary icon for the entry.
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_primary_icon_gicon() -> Glib::PropertyProxy< Glib::RefPtr<Gio::Icon> > ;

/** The `Gio::Icon` to use for the primary icon for the entry.
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_primary_icon_gicon() const -> Glib::PropertyProxy_ReadOnly< Glib::RefPtr<Gio::Icon> >;

  /** The `Gio::Icon` to use for the secondary icon for the entry.
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_secondary_icon_gicon() -> Glib::PropertyProxy< Glib::RefPtr<Gio::Icon> > ;

/** The `Gio::Icon` to use for the secondary icon for the entry.
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_secondary_icon_gicon() const -> Glib::PropertyProxy_ReadOnly< Glib::RefPtr<Gio::Icon> >;

  /** The representation which is used for the primary icon of the entry.
   *
   * Default value: Gtk::Image::Type::EMPTY
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_primary_icon_storage_type() const -> Glib::PropertyProxy_ReadOnly< Image::Type >;


  /** The representation which is used for the secondary icon of the entry.
   *
   * Default value: Gtk::Image::Type::EMPTY
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_secondary_icon_storage_type() const -> Glib::PropertyProxy_ReadOnly< Image::Type >;


  /** Whether the primary icon is activatable.
   *
   * GTK emits the signal_icon_press() and
   * signal_icon_release() signals only on sensitive,
   * activatable icons.
   *
   * Sensitive, but non-activatable icons can be used for purely
   * informational purposes.
   *
   * Default value: <tt>true</tt>
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_primary_icon_activatable() -> Glib::PropertyProxy< bool > ;

/** Whether the primary icon is activatable.
   *
   * GTK emits the signal_icon_press() and
   * signal_icon_release() signals only on sensitive,
   * activatable icons.
   *
   * Sensitive, but non-activatable icons can be used for purely
   * informational purposes.
   *
   * Default value: <tt>true</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_primary_icon_activatable() const -> Glib::PropertyProxy_ReadOnly< bool >;

  /** Whether the secondary icon is activatable.
   *
   * GTK emits the signal_icon_press() and
   * signal_icon_release() signals only on sensitive,
   * activatable icons.
   *
   * Sensitive, but non-activatable icons can be used for purely
   * informational purposes.
   *
   * Default value: <tt>true</tt>
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_secondary_icon_activatable() -> Glib::PropertyProxy< bool > ;

/** Whether the secondary icon is activatable.
   *
   * GTK emits the signal_icon_press() and
   * signal_icon_release() signals only on sensitive,
   * activatable icons.
   *
   * Sensitive, but non-activatable icons can be used for purely
   * informational purposes.
   *
   * Default value: <tt>true</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_secondary_icon_activatable() const -> Glib::PropertyProxy_ReadOnly< bool >;

  /** Whether the primary icon is sensitive.
   *
   * An insensitive icon appears grayed out. GTK does not emit the
   * signal_icon_press() and signal_icon_release()
   * signals and does not allow DND from insensitive icons.
   *
   * An icon should be set insensitive if the action that would trigger
   * when clicked is currently not available.
   *
   * Default value: <tt>true</tt>
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_primary_icon_sensitive() -> Glib::PropertyProxy< bool > ;

/** Whether the primary icon is sensitive.
   *
   * An insensitive icon appears grayed out. GTK does not emit the
   * signal_icon_press() and signal_icon_release()
   * signals and does not allow DND from insensitive icons.
   *
   * An icon should be set insensitive if the action that would trigger
   * when clicked is currently not available.
   *
   * Default value: <tt>true</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_primary_icon_sensitive() const -> Glib::PropertyProxy_ReadOnly< bool >;

  /** Whether the secondary icon is sensitive.
   *
   * An insensitive icon appears grayed out. GTK does not emit the
   * [signal@Gtk.Entry::icon-press[ and [signal @a Gtk.Entry::icon-release]
   * signals and does not allow DND from insensitive icons.
   *
   * An icon should be set insensitive if the action that would trigger
   * when clicked is currently not available.
   *
   * Default value: <tt>true</tt>
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_secondary_icon_sensitive() -> Glib::PropertyProxy< bool > ;

/** Whether the secondary icon is sensitive.
   *
   * An insensitive icon appears grayed out. GTK does not emit the
   * [signal@Gtk.Entry::icon-press[ and [signal @a Gtk.Entry::icon-release]
   * signals and does not allow DND from insensitive icons.
   *
   * An icon should be set insensitive if the action that would trigger
   * when clicked is currently not available.
   *
   * Default value: <tt>true</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_secondary_icon_sensitive() const -> Glib::PropertyProxy_ReadOnly< bool >;

  /** The contents of the tooltip on the primary icon.
   *
   * Also see Gtk::Entry::set_icon_tooltip_text().
   *
   * Default value: ""
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_primary_icon_tooltip_text() -> Glib::PropertyProxy< bool > ;

/** The contents of the tooltip on the primary icon.
   *
   * Also see Gtk::Entry::set_icon_tooltip_text().
   *
   * Default value: ""
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_primary_icon_tooltip_text() const -> Glib::PropertyProxy_ReadOnly< bool >;

  /** The contents of the tooltip on the secondary icon.
   *
   * Also see Gtk::Entry::set_icon_tooltip_text().
   *
   * Default value: ""
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_secondary_icon_tooltip_text() -> Glib::PropertyProxy< bool > ;

/** The contents of the tooltip on the secondary icon.
   *
   * Also see Gtk::Entry::set_icon_tooltip_text().
   *
   * Default value: ""
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_secondary_icon_tooltip_text() const -> Glib::PropertyProxy_ReadOnly< bool >;

  /** The contents of the tooltip on the primary icon, with markup.
   *
   * Also see Gtk::Entry::set_icon_tooltip_markup().
   *
   * Default value: ""
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_primary_icon_tooltip_markup() -> Glib::PropertyProxy< bool > ;

/** The contents of the tooltip on the primary icon, with markup.
   *
   * Also see Gtk::Entry::set_icon_tooltip_markup().
   *
   * Default value: ""
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_primary_icon_tooltip_markup() const -> Glib::PropertyProxy_ReadOnly< bool >;

  /** The contents of the tooltip on the secondary icon, with markup.
   *
   * Also see Gtk::Entry::set_icon_tooltip_markup().
   *
   * Default value: ""
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_secondary_icon_tooltip_markup() -> Glib::PropertyProxy< bool > ;

/** The contents of the tooltip on the secondary icon, with markup.
   *
   * Also see Gtk::Entry::set_icon_tooltip_markup().
   *
   * Default value: ""
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_secondary_icon_tooltip_markup() const -> Glib::PropertyProxy_ReadOnly< bool >;

  /** Which IM (input method) module should be used for this entry.
   *
   * See Gtk::IMContext.
   *
   * Setting this to a non-<tt>nullptr</tt> value overrides the system-wide IM
   * module setting. See the GtkSettings Gtk::Settings::property_gtk_im_module()
   * property.
   *
   * Default value: ""
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_im_module() -> Glib::PropertyProxy< Glib::ustring > ;

/** Which IM (input method) module should be used for this entry.
   *
   * See Gtk::IMContext.
   *
   * Setting this to a non-<tt>nullptr</tt> value overrides the system-wide IM
   * module setting. See the GtkSettings Gtk::Settings::property_gtk_im_module()
   * property.
   *
   * Default value: ""
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_im_module() const -> Glib::PropertyProxy_ReadOnly< Glib::ustring >;

  /** The text that will be displayed in the `Gtk::Entry` when it is empty
   * and unfocused.
   *
   * Default value: ""
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_placeholder_text() -> Glib::PropertyProxy< Glib::ustring > ;

/** The text that will be displayed in the `Gtk::Entry` when it is empty
   * and unfocused.
   *
   * Default value: ""
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_placeholder_text() const -> Glib::PropertyProxy_ReadOnly< Glib::ustring >;

  /** The auxiliary completion object to use with the entry.
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_completion() -> Glib::PropertyProxy< Glib::RefPtr<EntryCompletion> > ;

/** The auxiliary completion object to use with the entry.
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_completion() const -> Glib::PropertyProxy_ReadOnly< Glib::RefPtr<EntryCompletion> >;

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

  /** Additional hints that allow input methods to fine-tune their behavior.
   *
   * Also see property_input_purpose()
   *
   * Default value: Gtk::InputHints::NONE
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_input_hints() -> Glib::PropertyProxy< InputHints > ;

/** Additional hints that allow input methods to fine-tune their behavior.
   *
   * Also see property_input_purpose()
   *
   * Default value: Gtk::InputHints::NONE
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_input_hints() const -> Glib::PropertyProxy_ReadOnly< InputHints >;

  /** A list of Pango attributes to apply to the text of the entry.
   *
   * This is mainly useful to change the size or weight of the text.
   *
   * The `Pango::Attribute`'s @a start_index and @a end_index must refer to the
   * Gtk::EntryBuffer text, i.e. without the preedit string.
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_attributes() -> Glib::PropertyProxy< Pango::AttrList > ;

/** A list of Pango attributes to apply to the text of the entry.
   *
   * This is mainly useful to change the size or weight of the text.
   *
   * The `Pango::Attribute`'s @a start_index and @a end_index must refer to the
   * Gtk::EntryBuffer text, i.e. without the preedit string.
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_attributes() const -> Glib::PropertyProxy_ReadOnly< Pango::AttrList >;

  /**
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_tabs() -> Glib::PropertyProxy< Pango::TabArray > ;

/**
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_tabs() const -> Glib::PropertyProxy_ReadOnly< Pango::TabArray >;

  /** A menu model whose contents will be appended to the context menu.
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_extra_menu() -> Glib::PropertyProxy< Glib::RefPtr<Gio::MenuModel> > ;

/** A menu model whose contents will be appended to the context menu.
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_extra_menu() const -> Glib::PropertyProxy_ReadOnly< Glib::RefPtr<Gio::MenuModel> >;

  /** Default value: <tt>false</tt>
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_show_emoji_icon() -> Glib::PropertyProxy< bool > ;

/** Default value: <tt>false</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_show_emoji_icon() const -> Glib::PropertyProxy_ReadOnly< bool >;

  /** Whether to suggest Emoji replacements for :-delimited names
   * like `:heart:`.
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_enable_emoji_completion() -> Glib::PropertyProxy< bool > ;

/** Whether to suggest Emoji replacements for :-delimited names
   * like `:heart:`.
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_enable_emoji_completion() const -> Glib::PropertyProxy_ReadOnly< bool >;


public:

public:
  //C++ methods used to invoke GTK+ virtual functions:

protected:
  //GTK+ Virtual Functions (override these to change behaviour):

  //Default Signal Handlers::


};

} //namespace Gtk


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

template <>
class GTKMM_API Value<Gtk::Entry::IconPosition> : public Glib::Value_Enum<Gtk::Entry::IconPosition>
{
public:
  static auto value_type() -> GType G_GNUC_CONST;
};

} // namespace Glib
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


namespace Glib
{
  /** A Glib::wrap() method for this object.
   *
   * @param object The C instance.
   * @param take_copy False if the result should take ownership of the C instance. True if it should take a new copy or ref.
   * @result A C++ instance that wraps this C instance.
   *
   * @relates Gtk::Entry
   */
  GTKMM_API
  auto wrap(GtkEntry* object, bool take_copy = false) -> Gtk::Entry*;
} //namespace Glib


#endif /* _GTKMM_ENTRY_H */

