
#ifndef _GTKMM_TEXTVIEW_H
#define _GTKMM_TEXTVIEW_H

#include <mm/gtk/mm-gtkconfig.hpp>


#include <mm/glib/ustring.hpp>
#include <sigc++/sigc++.h>

/* Copyright(C) 2002 The gtkmm Development Team
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or(at your option) any later version.
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

// This is for including the config header before any code (such as
// the #ifndef GTKMM_DISABLE_DEPRECATED in deprecated classes) is generated:


#include <mm/gtk/widget.hpp>
#include <mm/gtk/scrollable.hpp>
#include <mm/gtk/textbuffer.hpp>
#include <mm/gtk/textmark.hpp>
#include <mm/gio/menumodel.hpp>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkTextView = struct _GtkTextView;
using GtkTextViewClass = struct _GtkTextViewClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{ class GTKMM_API TextView_Class; } // namespace Gtk
#endif //DOXYGEN_SHOULD_SKIP_THIS

namespace Gtk
{


/** @addtogroup gtkmmEnums gtkmm Enums and Flags */

/**
 *  @var TextWindowType WIDGET
 * Window that floats over scrolling areas.
 *
 *  @var TextWindowType TEXT
 * Scrollable text window.
 *
 *  @var TextWindowType LEFT
 * Left side border window.
 *
 *  @var TextWindowType RIGHT
 * Right side border window.
 *
 *  @var TextWindowType TOP
 * Top border window.
 *
 *  @var TextWindowType BOTTOM
 * Bottom border window.
 *
 *  @enum TextWindowType
 *
 * Used to reference the parts of `Gtk::TextView`.
 *
 * @ingroup gtkmmEnums
 */
enum class TextWindowType
{
  WIDGET = 1,
  TEXT,
  LEFT,
  RIGHT,
  TOP,
  BOTTOM
};


} // namespace Gtk

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

template <>
class GTKMM_API Value<Gtk::TextWindowType> : public Glib::Value_Enum<Gtk::TextWindowType>
{
public:
  static auto value_type() -> GType G_GNUC_CONST;
};

} // namespace Glib
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

namespace Gtk
{


/** @defgroup TextView TextView Classes
 * These classes are used with the Gtk::TextView widget.
 */

/** Multi-line text editing widget. It displays a Gtk::TextBuffer.
 *
 * The TextView widget looks like this:
 * @image html textview1.png
 *
 * @ingroup Widgets
 * @ingroup Containers
 * @ingroup TextView
 */

class GTKMM_API TextView
 : public Widget,
   public Scrollable
{
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  typedef TextView CppObjectType;
  typedef TextView_Class CppClassType;
  typedef GtkTextView BaseObjectType;
  typedef GtkTextViewClass BaseClassType;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

  TextView(TextView&& src) noexcept;
  auto operator=(TextView&& src) noexcept -> TextView&;

  // noncopyable
  TextView(const TextView&) = delete;
  auto operator=(const TextView&) -> TextView& = delete;

  ~TextView() noexcept override;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

private:
  friend GTKMM_API class TextView_Class;
  static CppClassType textview_class_;

protected:
  explicit TextView(const Glib::ConstructParams& construct_params);
  explicit TextView(GtkTextView* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS


  static auto get_base_type() -> GType G_GNUC_CONST;
#endif

  /// Provides access to the underlying C GObject.
  auto       gobj() -> GtkTextView*       { return reinterpret_cast<GtkTextView*>(gobject_); }

  /// Provides access to the underlying C GObject.
  auto gobj() const -> const GtkTextView* { return reinterpret_cast<GtkTextView*>(gobject_); }

private:


public:
  TextView();
  explicit TextView(const Glib::RefPtr<TextBuffer>& buffer);


  /** Sets @a buffer as the buffer being displayed by @a text_view.
   *
   * The previous buffer displayed by the text view is unreferenced, and
   * a reference is added to @a buffer. If you owned a reference to @a buffer
   * before passing it to this function, you must remove that reference
   * yourself; `Gtk::TextView` will not “adopt” it.
   *
   * @param buffer A `Gtk::TextBuffer`.
   */
  void set_buffer(const Glib::RefPtr<TextBuffer>& buffer);

  /** Returns the `Gtk::TextBuffer` being displayed by this text view.
   *
   * The reference count on the buffer is not incremented; the caller
   * of this function won’t own a new reference.
   *
   * @return A `Gtk::TextBuffer`.
   */
  auto get_buffer() -> Glib::RefPtr<TextBuffer>;

  /** Returns the `Gtk::TextBuffer` being displayed by this text view.
   *
   * The reference count on the buffer is not incremented; the caller
   * of this function won’t own a new reference.
   *
   * @return A `Gtk::TextBuffer`.
   */
  auto get_buffer() const -> Glib::RefPtr<const TextBuffer>;

  /** Scrolls the TextView so that @a iter is on the screen, by scrolling the minimal distance to get the mark onscreen,
   * possibly not scrolling at all. The effective screen for purposes of this function is reduced by a margin of size
   * @a within_margin.
   * @note This function uses the currently-computed height of the lines in the text buffer. Note that line heights are computed
   * in an idle handler; so this function may not have the desired effect if it's called before the height computations. To avoid
   * oddness, consider using gtk_text_view_scroll_to_mark() which saves a point to be scrolled to after line validation.
   *
   * @param iter An iterator pointing to the position that should be made visible by scrolling.
   * @param within_margin margin as a [0.0,0.5] fraction of screen size.
   * @result true if scrolling occurred.
   */
  auto scroll_to(TextBuffer::iterator& iter, double within_margin = 0) -> bool;

  /** Scrolls the TextView so that @a iter is on the screen, in the position indicated by xalign and yalign,
   * possibly not scrolling at all. The effective screen for purposes of this function is reduced by a margin of size
   * @a within_margin.
   * @note This function uses the currently-computed height of the lines in the text buffer. Note that line heights are computed
   * in an idle handler; so this function may not have the desired effect if it's called before the height computations. To avoid
   * oddness, consider using gtk_text_view_scroll_to_mark() which saves a point to be scrolled to after line validation.
   *
   * @param iter An iterator pointing to the position that should be made visible by scrolling.
   * @param within_margin margin as a [0.0,0.5] fraction of screen size.
   * @param xalign horizontal alignment of mark within visible area. An alignment of 0.0 indicates left, 1.0 indicates right, 0.5 means center.
   * @param yalign vertical alignment of mark within visible area. An alignment of 0.0 indicates top, 1.0 indicates bottom, 0.5 means center.
   * @result true if scrolling occurred.
   */
  auto scroll_to(TextBuffer::iterator& iter, double within_margin, double xalign, double yalign) -> bool;


  /** Scrolls text_view so that @a mark is on the screen, by scrolling the minimal distance to get the mark onscreen,
   * possibly not scrolling at all. The effective screen for purposes of this function is reduced by a margin of size
   * @a within_margin.
   *
   * @param mark An mark pointing to the position that should be made visible by scrolling.
   * @param within_margin margin as a [0.0,0.5] fraction of screen size.
   */
  void scroll_to(const Glib::RefPtr<TextBuffer::Mark>& mark, double within_margin = 0);

 /** Scrolls the TextView so that @a mark is on the screen, in the position indicated by xalign and yalign,
   * possibly not scrolling at all. The effective screen for purposes of this function is reduced by a margin of size
   * @a within_margin.
   *
   * @param mark An mark pointing to the position that should be made visible by scrolling.
   * @param within_margin margin as a [0.0,0.5] fraction of screen size.
   * @param xalign horizontal alignment of mark within visible area. An alignment of 0.0 indicates left, 1.0 indicates right, 0.5 means center.
   * @param yalign vertical alignment of mark within visible area. An alignment of 0.0 indicates top, 1.0 indicates bottom, 0.5 means center.
   */
  void scroll_to(const Glib::RefPtr<TextBuffer::Mark>& mark, double within_margin, double xalign, double yalign);


   //It does not do anything more than the default scroll_to(mark).


  /** Moves a mark within the buffer so that it's
   * located within the currently-visible text area.
   *
   * @param mark A `Gtk::TextMark`.
   * @return <tt>true</tt> if the mark moved (wasn’t already onscreen).
   */
  auto move_mark_onscreen(const Glib::RefPtr<TextBuffer::Mark>& mark) -> bool;

  /** Moves the cursor to the currently visible region of the
   * buffer.
   *
   * @return <tt>true</tt> if the cursor had to be moved.
   */
  auto place_cursor_onscreen() -> bool;


  /** Fills @a visible_rect with the currently-visible
   * region of the buffer, in buffer coordinates.
   *
   * Convert to window coordinates with
   * buffer_to_window_coords().
   *
   * @param visible_rect Rectangle to fill.
   */
  void get_visible_rect(Gdk::Rectangle& visible_rect) const;

  /** Toggles whether the insertion point should be displayed.
   *
   * A buffer with no editable text probably shouldn’t have a visible
   * cursor, so you may want to turn the cursor off.
   *
   * Note that this property may be overridden by the
   * Gtk::GtkSettings::property_gtk_keynav_use_caret() setting.
   *
   * @param setting Whether to show the insertion cursor.
   */
  void set_cursor_visible(bool setting =  true);

  /** Find out whether the cursor should be displayed.
   *
   * @return Whether the insertion mark is visible.
   */
  auto get_cursor_visible() const -> bool;

  /** Ensures that the cursor is shown.
   *
   * This also resets the time that it will stay blinking (or
   * visible, in case blinking is disabled).
   *
   * This function should be called in response to user input
   * (e.g. from derived classes that override the textview's
   * event handlers).
   */
  void reset_cursor_blink();


  /** Determine the positions of the strong and weak cursors if the
   * insertion point is at @a iter.
   *
   * The position of each cursor is stored as a zero-width rectangle.
   * The strong cursor location is the location where characters of
   * the directionality equal to the base direction of the paragraph
   * are inserted. The weak cursor location is the location where
   * characters of the directionality opposite to the base direction
   * of the paragraph are inserted.
   *
   * If @a iter is <tt>nullptr</tt>, the actual cursor position is used.
   *
   * Note that if @a iter happens to be the actual cursor position, and
   * there is currently an IM preedit sequence being entered, the
   * returned locations will be adjusted to account for the preedit
   * cursor’s offset within the preedit sequence.
   *
   * The rectangle position is in buffer coordinates; use
   * buffer_to_window_coords() to convert these
   * coordinates to coordinates for one of the windows in the text view.
   *
   * @param iter A `Gtk::TextIter`.
   * @param strong Location to store the strong cursor position.
   * @param weak Location to store the weak cursor position.
   */
  void get_cursor_locations(const TextBuffer::const_iterator& iter, Gdk::Rectangle& strong, Gdk::Rectangle& weak) const;

  /// A get_cursor_locations() convenience overload.
  void get_cursor_locations(Gdk::Rectangle& strong, Gdk::Rectangle& weak) const;


  /** Gets a rectangle which roughly contains the character at @a iter.
   *
   * The rectangle position is in buffer coordinates; use
   * buffer_to_window_coords() to convert these
   * coordinates to coordinates for one of the windows in the text view.
   *
   * @param iter A `Gtk::TextIter`.
   * @param location Bounds of the character at @a iter.
   */
  void get_iter_location(const TextBuffer::const_iterator& iter, Gdk::Rectangle& location) const;

  /** Retrieves the iterator at buffer coordinates @a x and @a y.
   *
   * Buffer coordinates are coordinates for the entire buffer, not just
   * the currently-displayed portion. If you have coordinates from an
   * event, you have to convert those to buffer coordinates with
   * window_to_buffer_coords().
   *
   * @param iter A `Gtk::TextIter`.
   * @param x X position, in buffer coordinates.
   * @param y Y position, in buffer coordinates.
   * @return <tt>true</tt> if the position is over text.
   */
  auto get_iter_at_location(TextBuffer::iterator& iter, int x, int y) -> bool;

  /** Retrieves the iterator at buffer coordinates @a x and @a y.
   *
   * Buffer coordinates are coordinates for the entire buffer, not just
   * the currently-displayed portion. If you have coordinates from an
   * event, you have to convert those to buffer coordinates with
   * window_to_buffer_coords().
   *
   * @param iter A `Gtk::TextIter`.
   * @param x X position, in buffer coordinates.
   * @param y Y position, in buffer coordinates.
   * @return <tt>true</tt> if the position is over text.
   */
  auto get_iter_at_location(TextBuffer::const_iterator& iter, int x, int y) const -> bool;

  /** Retrieves the iterator pointing to the character at buffer
   * coordinates @a x and @a y.
   *
   * Buffer coordinates are coordinates for the entire buffer, not just
   * the currently-displayed portion. If you have coordinates from an event,
   * you have to convert those to buffer coordinates with
   * window_to_buffer_coords().
   *
   * Note that this is different from get_iter_at_location(),
   * which returns cursor locations, i.e. positions between characters.
   *
   * @param iter A `Gtk::TextIter`.
   * @param trailing If non-<tt>nullptr</tt>, location to store
   * an integer indicating where in the grapheme the user clicked.
   * It will either be zero, or the number of characters in the grapheme.
   * 0 represents the trailing edge of the grapheme.
   * @param x X position, in buffer coordinates.
   * @param y Y position, in buffer coordinates.
   * @return <tt>true</tt> if the position is over text.
   */
  auto get_iter_at_position(TextBuffer::iterator& iter, int& trailing, int x, int y) -> bool;

  /** Retrieves the iterator pointing to the character at buffer
   * coordinates @a x and @a y.
   *
   * Buffer coordinates are coordinates for the entire buffer, not just
   * the currently-displayed portion. If you have coordinates from an event,
   * you have to convert those to buffer coordinates with
   * window_to_buffer_coords().
   *
   * Note that this is different from get_iter_at_location(),
   * which returns cursor locations, i.e. positions between characters.
   *
   * @param iter A `Gtk::TextIter`.
   * @param trailing If non-<tt>nullptr</tt>, location to store
   * an integer indicating where in the grapheme the user clicked.
   * It will either be zero, or the number of characters in the grapheme.
   * 0 represents the trailing edge of the grapheme.
   * @param x X position, in buffer coordinates.
   * @param y Y position, in buffer coordinates.
   * @return <tt>true</tt> if the position is over text.
   */
  auto get_iter_at_position(TextBuffer::const_iterator& iter, int& trailing, int x, int y) const -> bool;

  /** Gets the y coordinate of the top of the line containing @a iter,
   * and the height of the line.
   *
   * The coordinate is a buffer coordinate; convert to window
   * coordinates with buffer_to_window_coords().
   *
   * @param iter A `Gtk::TextIter`.
   * @param y Return location for a y coordinate.
   * @param height Return location for a height.
   */
  void get_line_yrange(const TextBuffer::const_iterator& iter, int& y, int& height) const;


  /** Gets the `Gtk::TextIter` at the start of the line containing
   * the coordinate @a y.
   *
   *  @a y is in buffer coordinates, convert from window coordinates with
   * window_to_buffer_coords(). If non-<tt>nullptr</tt>,
   *  @a line_top will be filled with the coordinate of the top edge
   * of the line.
   *
   * @param target_iter A `Gtk::TextIter`.
   * @param y A y coordinate.
   * @param line_top Return location for top coordinate of the line.
   */
  void get_line_at_y(TextBuffer::iterator& target_iter, int y, int& line_top);

  /** Gets the `Gtk::TextIter` at the start of the line containing
   * the coordinate @a y.
   *
   *  @a y is in buffer coordinates, convert from window coordinates with
   * window_to_buffer_coords(). If non-<tt>nullptr</tt>,
   *  @a line_top will be filled with the coordinate of the top edge
   * of the line.
   *
   * @param target_iter A `Gtk::TextIter`.
   * @param y A y coordinate.
   * @param line_top Return location for top coordinate of the line.
   */
  void get_line_at_y(TextBuffer::const_iterator& target_iter, int y, int& line_top) const;


  /** Converts buffer coordinates to window coordinates.
   *
   * @param win A `Gtk::TextWindowType`.
   * @param buffer_x Buffer x coordinate.
   * @param buffer_y Buffer y coordinate.
   * @param window_x Window x coordinate return location.
   * @param window_y Window y coordinate return location.
   */
  void buffer_to_window_coords(TextWindowType win, int buffer_x, int buffer_y, int& window_x, int& window_y) const;

  /** Converts coordinates on the window identified by @a win to buffer
   * coordinates.
   *
   * @param win A `Gtk::TextWindowType`.
   * @param window_x Window x coordinate.
   * @param window_y Window y coordinate.
   * @param buffer_x Buffer x coordinate return location.
   * @param buffer_y Buffer y coordinate return location.
   */
  void window_to_buffer_coords(TextWindowType win, int window_x, int window_y, int& buffer_x, int& buffer_y) const;


  /** Moves the given @a iter forward by one display (wrapped) line.
   *
   * A display line is different from a paragraph. Paragraphs are
   * separated by newlines or other paragraph separator characters.
   * Display lines are created by line-wrapping a paragraph. If
   * wrapping is turned off, display lines and paragraphs will be the
   * same. Display lines are divided differently for each view, since
   * they depend on the view’s width; paragraphs are the same in all
   * views, since they depend on the contents of the `Gtk::TextBuffer`.
   *
   * @param iter A `Gtk::TextIter`.
   * @return <tt>true</tt> if @a iter was moved and is not on the end iterator.
   */
  auto forward_display_line(TextBuffer::iterator& iter) -> bool;

  /** Moves the given @a iter backward by one display (wrapped) line.
   *
   * A display line is different from a paragraph. Paragraphs are
   * separated by newlines or other paragraph separator characters.
   * Display lines are created by line-wrapping a paragraph. If
   * wrapping is turned off, display lines and paragraphs will be the
   * same. Display lines are divided differently for each view, since
   * they depend on the view’s width; paragraphs are the same in all
   * views, since they depend on the contents of the `Gtk::TextBuffer`.
   *
   * @param iter A `Gtk::TextIter`.
   * @return <tt>true</tt> if @a iter was moved and is not on the end iterator.
   */
  auto backward_display_line(TextBuffer::iterator& iter) -> bool;

  /** Moves the given @a iter forward to the next display line end.
   *
   * A display line is different from a paragraph. Paragraphs are
   * separated by newlines or other paragraph separator characters.
   * Display lines are created by line-wrapping a paragraph. If
   * wrapping is turned off, display lines and paragraphs will be the
   * same. Display lines are divided differently for each view, since
   * they depend on the view’s width; paragraphs are the same in all
   * views, since they depend on the contents of the `Gtk::TextBuffer`.
   *
   * @param iter A `Gtk::TextIter`.
   * @return <tt>true</tt> if @a iter was moved and is not on the end iterator.
   */
  auto forward_display_line_end(TextBuffer::iterator& iter) -> bool;

  /** Moves the given @a iter backward to the next display line start.
   *
   * A display line is different from a paragraph. Paragraphs are
   * separated by newlines or other paragraph separator characters.
   * Display lines are created by line-wrapping a paragraph. If
   * wrapping is turned off, display lines and paragraphs will be the
   * same. Display lines are divided differently for each view, since
   * they depend on the view’s width; paragraphs are the same in all
   * views, since they depend on the contents of the `Gtk::TextBuffer`.
   *
   * @param iter A `Gtk::TextIter`.
   * @return <tt>true</tt> if @a iter was moved and is not on the end iterator.
   */
  auto backward_display_line_start(TextBuffer::iterator& iter) -> bool;

  /** Determines whether @a iter is at the start of a display line.
   *
   * See forward_display_line() for an
   * explanation of display lines vs. paragraphs.
   *
   * @param iter A `Gtk::TextIter`.
   * @return <tt>true</tt> if @a iter begins a wrapped line.
   */
  auto starts_display_line(const TextBuffer::iterator& iter) -> bool;

  /** Move the iterator a given number of characters visually, treating
   * it as the strong cursor position.
   *
   * If @a count is positive, then the new strong cursor position will
   * be @a count positions to the right of the old cursor position.
   * If @a count is negative then the new strong cursor position will
   * be @a count positions to the left of the old cursor position.
   *
   * In the presence of bi-directional text, the correspondence
   * between logical and visual order will depend on the direction
   * of the current run, and there may be jumps when the cursor
   * is moved off of the end of a run.
   *
   * @param iter A `Gtk::TextIter`.
   * @param count Number of characters to move (negative moves left,
   * positive moves right).
   * @return <tt>true</tt> if @a iter moved and is not on the end iterator.
   */
  auto move_visually(TextBuffer::iterator& iter, int count) -> bool;


  /** Allow the `Gtk::TextView` input method to internally handle key press
   * and release events.
   *
   * If this function returns <tt>true</tt>, then no further processing should be
   * done for this key event. See Gtk::IMContext::filter_keypress().
   *
   * Note that you are expected to call this function from your handler
   * when overriding key event handling. This is needed in the case when
   * you need to insert your own key handling between the input method
   * and the default key event handling of the `Gtk::TextView`.
   *
   *
   * [C example ellipted]
   *
   * @param event The key event.
   * @return <tt>true</tt> if the input method handled the key event.
   */
  auto im_context_filter_keypress(const Glib::RefPtr<Gdk::Event>& event) -> bool;

  /** Reset the input method context of the text view if needed.
   *
   * This can be necessary in the case where modifying the buffer
   * would confuse on-going input method behavior.
   */
  void reset_im_context();


  /** Gets a `Gtk::Widget` that has previously been set as gutter.
   *
   * See set_gutter().
   *
   *  @a win must be one of Gtk::TextWindowType::LEFT, Gtk::TextWindowType::RIGHT,
   * Gtk::TextWindowType::TOP, or Gtk::TextWindowType::BOTTOM.
   *
   * @param win A `Gtk::TextWindowType`.
   * @return A `Gtk::Widget`.
   */
  auto get_gutter(TextWindowType win) -> Widget*;

  /** Gets a `Gtk::Widget` that has previously been set as gutter.
   *
   * See set_gutter().
   *
   *  @a win must be one of Gtk::TextWindowType::LEFT, Gtk::TextWindowType::RIGHT,
   * Gtk::TextWindowType::TOP, or Gtk::TextWindowType::BOTTOM.
   *
   * @param win A `Gtk::TextWindowType`.
   * @return A `Gtk::Widget`.
   */
  auto get_gutter(TextWindowType win) const -> const Widget*;

  /** Places @a widget into the gutter specified by @a win.
   *
   *  @a win must be one of Gtk::TextWindowType::LEFT, Gtk::TextWindowType::RIGHT,
   * Gtk::TextWindowType::TOP, or Gtk::TextWindowType::BOTTOM.
   *
   * @param win A `Gtk::TextWindowType`.
   * @param widget A `Gtk::Widget`.
   */
  void set_gutter(TextWindowType win, Widget& widget);
  /** Removes a widget from the gutter specified by @a win.
   *
   * @a win must be one of Gtk::TextWindowType::LEFT, Gtk::TextWindowType::RIGHT,
   * Gtk::TextWindowType::TOP, or Gtk::TextWindowType::BOTTOM.
   *
   * @param win A Gtk::TextWindowType.
   */
  void unset_gutter(TextWindowType win);


  /** Adds a child widget in the text buffer, at the given @a anchor.
   *
   * @param child A `Gtk::Widget`.
   * @param anchor A `Gtk::TextChildAnchor` in the `Gtk::TextBuffer` for @a text_view.
   */
  void add_child_at_anchor(Widget& child, const Glib::RefPtr<TextBuffer::ChildAnchor>& anchor);


  /** Adds @a child at a fixed coordinate in the `Gtk::TextView`'s text window.
   *
   * The @a xpos and @a ypos must be in buffer coordinates (see
   * get_iter_location() to convert to
   * buffer coordinates).
   *
   *  @a child will scroll with the text view.
   *
   * If instead you want a widget that will not move with the
   * `Gtk::TextView` contents see `Gtk::Overlay`.
   *
   * @param child A `Gtk::Widget`.
   * @param xpos X position of child in window coordinates.
   * @param ypos Y position of child in window coordinates.
   */
  void add_overlay(Widget& child, int xpos, int ypos);


  /** Updates the position of a child.
   *
   * See add_overlay().
   *
   * @param child A widget already added with add_overlay().
   * @param xpos New X position in buffer coordinates.
   * @param ypos New Y position in buffer coordinates.
   */
  void move_overlay(Widget& child, int xpos, int ypos);


  /** Removes a child widget from @a text_view.
   *
   * @param child The child to remove.
   */
  void remove(Widget& child);


  /** Sets the line wrapping for the view.
   *
   * @param wrap_mode A `Gtk::WrapMode`.
   */
  void set_wrap_mode(WrapMode wrap_mode);

  /** Gets the line wrapping for the view.
   *
   * @return The line wrap setting.
   */
  auto get_wrap_mode() const -> WrapMode;

  /** Sets the default editability of the `Gtk::TextView`.
   *
   * You can override this default setting with tags in the buffer,
   * using the “editable” attribute of tags.
   *
   * @param setting Whether it’s editable.
   */
  void set_editable(bool setting =  true);

  /** Returns the default editability of the `Gtk::TextView`.
   *
   * Tags in the buffer may override this setting for some ranges of text.
   *
   * @return Whether text is editable by default.
   */
  auto get_editable() const -> bool;

  /** Sets the default number of blank pixels above paragraphs in @a text_view.
   *
   * Tags in the buffer for @a text_view may override the defaults.
   *
   * @param pixels_above_lines Pixels above paragraphs.
   */
  void set_pixels_above_lines(int pixels_above_lines);

  /** Gets the default number of pixels to put above paragraphs.
   *
   * Adding this function with get_pixels_below_lines()
   * is equal to the line space between each paragraph.
   *
   * @return Default number of pixels above paragraphs.
   */
  auto get_pixels_above_lines() const -> int;

  /** Sets the default number of pixels of blank space
   * to put below paragraphs in @a text_view.
   *
   * May be overridden by tags applied to @a text_view’s buffer.
   *
   * @param pixels_below_lines Pixels below paragraphs.
   */
  void set_pixels_below_lines(int pixels_below_lines);

  /** Gets the default number of pixels to put below paragraphs.
   *
   * The line space is the sum of the value returned by this function and
   * the value returned by get_pixels_above_lines().
   *
   * @return Default number of blank pixels below paragraphs.
   */
  auto get_pixels_below_lines() const -> int;

  /** Sets the default number of pixels of blank space to leave between
   * display/wrapped lines within a paragraph.
   *
   * May be overridden by tags in @a text_view’s buffer.
   *
   * @param pixels_inside_wrap Default number of pixels between wrapped lines.
   */
  void set_pixels_inside_wrap(int pixels_inside_wrap);

  /** Gets the default number of pixels to put between wrapped lines
   * inside a paragraph.
   *
   * @return Default number of pixels of blank space between wrapped lines.
   */
  auto get_pixels_inside_wrap() const -> int;

  /** Sets the default justification of text in @a text_view.
   *
   * Tags in the view’s buffer may override the default.
   *
   * @param justification Justification.
   */
  void set_justification(Justification justification);

  /** Gets the default justification of paragraphs in @a text_view.
   *
   * Tags in the buffer may override the default.
   *
   * @return Default justification.
   */
  auto get_justification() const -> Justification;

  /** Sets the default left margin for text in @a text_view.
   *
   * Tags in the buffer may override the default.
   *
   * Note that this function is confusingly named.
   * In CSS terms, the value set here is padding.
   *
   * @param left_margin Left margin in pixels.
   */
  void set_left_margin(int left_margin);

  /** Gets the default left margin size of paragraphs in the @a text_view.
   *
   * Tags in the buffer may override the default.
   *
   * @return Left margin in pixels.
   */
  auto get_left_margin() const -> int;

  /** Sets the default right margin for text in the text view.
   *
   * Tags in the buffer may override the default.
   *
   * Note that this function is confusingly named.
   * In CSS terms, the value set here is padding.
   *
   * @param right_margin Right margin in pixels.
   */
  void set_right_margin(int right_margin);

  /** Gets the default right margin for text in @a text_view.
   *
   * Tags in the buffer may override the default.
   *
   * @return Right margin in pixels.
   */
  auto get_right_margin() const -> int;

  /** Sets the top margin for text in @a text_view.
   *
   * Note that this function is confusingly named.
   * In CSS terms, the value set here is padding.
   *
   * @newin{3,20}
   *
   * @param top_margin Top margin in pixels.
   */
  void set_top_margin(int top_margin);

  /** Gets the top margin for text in the @a text_view.
   *
   * @newin{3,20}
   *
   * @return Top margin in pixels.
   */
  auto get_top_margin() const -> int;

  /** Sets the bottom margin for text in @a text_view.
   *
   * Note that this function is confusingly named.
   * In CSS terms, the value set here is padding.
   *
   * @newin{3,20}
   *
   * @param bottom_margin Bottom margin in pixels.
   */
  void set_bottom_margin(int bottom_margin);

  /** Gets the bottom margin for text in the @a text_view.
   *
   * @newin{3,20}
   *
   * @return Bottom margin in pixels.
   */
  auto get_bottom_margin() const -> int;

  /** Sets the default indentation for paragraphs in @a text_view.
   *
   * Tags in the buffer may override the default.
   *
   * @param indent Indentation in pixels.
   */
  void set_indent(int indent);

  /** Gets the default indentation of paragraphs in @a text_view.
   *
   * Tags in the view’s buffer may override the default.
   * The indentation may be negative.
   *
   * @return Number of pixels of indentation.
   */
  auto get_indent() const -> int;


  /** Sets the default tab stops for paragraphs in @a text_view.
   *
   * Tags in the buffer may override the default.
   *
   * @param tabs Tabs as a `Pango::TabArray`.
   */
  void set_tabs(Pango::TabArray& tabs);

  /** Gets the default tabs for @a text_view. Tags in the buffer may
   * override the defaults. The returned array will be empty if
   * "standard" (8-space) tabs are used.
   *
   * @return Copy of default tab array, or an empty array if "standard" tabs are used.
   */
  auto get_tabs() const -> Pango::TabArray;


  /** Changes the `Gtk::TextView` overwrite mode.
   *
   * @param overwrite <tt>true</tt> to turn on overwrite mode, <tt>false</tt> to turn it off.
   */
  void set_overwrite(bool overwrite =  true);

  /** Returns whether the `Gtk::TextView` is in overwrite mode or not.
   *
   * @return Whether @a text_view is in overwrite mode or not.
   */
  auto get_overwrite() const -> bool;


  /** Sets the behavior of the text widget when the <kbd>Tab</kbd> key is pressed.
   *
   * If @a accepts_tab is <tt>true</tt>, a tab character is inserted. If @a accepts_tab
   * is <tt>false</tt> the keyboard focus is moved to the next widget in the focus
   * chain.
   *
   * @param accepts_tab <tt>true</tt> if pressing the Tab key should insert a tab
   * character, <tt>false</tt>, if pressing the Tab key should move the
   * keyboard focus.
   */
  void set_accepts_tab(bool accepts_tab =  true);

  /** Returns whether pressing the <kbd>Tab</kbd> key inserts a tab characters.
   *
   * See set_accepts_tab().
   *
   * @return <tt>true</tt> if pressing the Tab key inserts a tab character,
   * <tt>false</tt> if pressing the Tab key moves the keyboard focus.
   */
  auto get_accepts_tab() const -> bool;


  /** Sets the `input-purpose` of the `Gtk::TextView`.
   *
   * The `input-purpose` can be used by on-screen keyboards
   * and other input methods to adjust their behaviour.
   *
   * @param purpose The purpose.
   */
  void set_input_purpose(InputPurpose purpose);

  /** Gets the `input-purpose` of the `Gtk::TextView`.
   */
  auto get_input_purpose() const -> InputPurpose;


  /** Sets the `input-hints` of the `Gtk::TextView`.
   *
   * The `input-hints` allow input methods to fine-tune
   * their behaviour.
   *
   * @param hints The hints.
   */
  void set_input_hints(InputHints hints);

  /** Gets the `input-hints` of the `Gtk::TextView`.
   */
  auto get_input_hints() const -> InputHints;


  /** Sets whether the `Gtk::TextView` should display text in
   * monospace styling.
   *
   * @param monospace <tt>true</tt> to request monospace styling.
   */
  void set_monospace(bool monospace =  true);

  /** Gets whether the `Gtk::TextView` uses monospace styling.
   *
   * Return: <tt>true</tt> if monospace fonts are desired
   */
  auto get_monospace() const -> bool;


  /** Sets a menu model to add when constructing the context
   * menu for @a text_view.
   *
   * You can pass <tt>nullptr</tt> to remove a previously set extra menu.
   *
   * @param model A `Gio::MenuModel`.
   */
  void set_extra_menu(const Glib::RefPtr<Gio::MenuModel>& model);

  /** Gets the menu model that gets added to the context menu
   * or <tt>nullptr</tt> if none has been set.
   *
   * @return The menu model.
   */
  auto get_extra_menu() -> Glib::RefPtr<Gio::MenuModel>;

  /** Gets the menu model that gets added to the context menu
   * or <tt>nullptr</tt> if none has been set.
   *
   * @return The menu model.
   */
  auto get_extra_menu() const -> Glib::RefPtr<const Gio::MenuModel>;


  /** Gets the `Pango::Context` that is used for rendering RTL directed
   * text layouts.
   *
   * The context may be replaced when CSS changes occur.
   *
   * @newin{4,4}
   *
   * @return A `Pango::Context`.
   */
  auto get_rtl_context() -> Glib::RefPtr<Pango::Context>;

  /** Gets the `Pango::Context` that is used for rendering RTL directed
   * text layouts.
   *
   * The context may be replaced when CSS changes occur.
   *
   * @newin{4,4}
   *
   * @return A `Pango::Context`.
   */
  auto get_rtl_context() const -> Glib::RefPtr<const Pango::Context>;

  /** Gets the `Pango::Context` that is used for rendering LTR directed
   * text layouts.
   *
   * The context may be replaced when CSS changes occur.
   *
   * @newin{4,4}
   *
   * @return A `Pango::Context`.
   */
  auto get_ltr_context() -> Glib::RefPtr<Pango::Context>;

  /** Gets the `Pango::Context` that is used for rendering LTR directed
   * text layouts.
   *
   * The context may be replaced when CSS changes occur.
   *
   * @newin{4,4}
   *
   * @return A `Pango::Context`.
   */
  auto get_ltr_context() const -> Glib::RefPtr<const Pango::Context>;


  /**
   * @par Slot Prototype:
   * <tt>void on_my_%set_anchor()</tt>
   *
   * Flags: Run Last, Action
   *
   * Gets emitted when the user initiates settings the "anchor" mark.
   *
   * The signal_set_anchor() signal is a [keybinding signal](class.SignalAction.html)
   * which gets emitted when the user initiates setting the "anchor"
   * mark. The "anchor" mark gets placed at the same position as the
   * "insert" mark.
   *
   * This signal has no default bindings.
   */

  auto signal_set_anchor() -> Glib::SignalProxy<void()>;


  /**
   * @par Slot Prototype:
   * <tt>void on_my_%insert_at_cursor(const Glib::ustring& str)</tt>
   *
   * Flags: Run Last, Action
   *
   * Gets emitted when the user initiates the insertion of a
   * fixed string at the cursor.
   *
   * The signal_insert_at_cursor() signal is a [keybinding signal](class.SignalAction.html).
   *
   * This signal has no default bindings.
   *
   * @param str The string to insert.
   */

  auto signal_insert_at_cursor() -> Glib::SignalProxy<void(const Glib::ustring&)>;


  //Keybinding signals:


  /** Default value: 0
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_pixels_above_lines() -> Glib::PropertyProxy< int > ;

/** Default value: 0
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_pixels_above_lines() const -> Glib::PropertyProxy_ReadOnly< int >;

  /** Default value: 0
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_pixels_below_lines() -> Glib::PropertyProxy< int > ;

/** Default value: 0
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_pixels_below_lines() const -> Glib::PropertyProxy_ReadOnly< int >;

  /** Default value: 0
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_pixels_inside_wrap() -> Glib::PropertyProxy< int > ;

/** Default value: 0
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_pixels_inside_wrap() const -> Glib::PropertyProxy_ReadOnly< int >;

  /** Default value: <tt>true</tt>
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_editable() -> Glib::PropertyProxy< bool > ;

/** Default value: <tt>true</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_editable() const -> Glib::PropertyProxy_ReadOnly< bool >;

  /** Default value: Gtk::WrapMode::NONE
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_wrap_mode() -> Glib::PropertyProxy< WrapMode > ;

/** Default value: Gtk::WrapMode::NONE
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_wrap_mode() const -> Glib::PropertyProxy_ReadOnly< WrapMode >;

  /** Default value: Gtk::Justification::LEFT
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_justification() -> Glib::PropertyProxy< Justification > ;

/** Default value: Gtk::Justification::LEFT
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_justification() const -> Glib::PropertyProxy_ReadOnly< Justification >;

  /** The default left margin for text in the text view.
   *
   * Tags in the buffer may override the default.
   *
   * Note that this property is confusingly named. In CSS terms,
   * the value set here is padding, and it is applied in addition
   * to the padding from the theme.
   *
   * Default value: 0
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_left_margin() -> Glib::PropertyProxy< int > ;

/** The default left margin for text in the text view.
   *
   * Tags in the buffer may override the default.
   *
   * Note that this property is confusingly named. In CSS terms,
   * the value set here is padding, and it is applied in addition
   * to the padding from the theme.
   *
   * Default value: 0
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_left_margin() const -> Glib::PropertyProxy_ReadOnly< int >;

  /** The default right margin for text in the text view.
   *
   * Tags in the buffer may override the default.
   *
   * Note that this property is confusingly named. In CSS terms,
   * the value set here is padding, and it is applied in addition
   * to the padding from the theme.
   *
   * Default value: 0
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_right_margin() -> Glib::PropertyProxy< int > ;

/** The default right margin for text in the text view.
   *
   * Tags in the buffer may override the default.
   *
   * Note that this property is confusingly named. In CSS terms,
   * the value set here is padding, and it is applied in addition
   * to the padding from the theme.
   *
   * Default value: 0
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_right_margin() const -> Glib::PropertyProxy_ReadOnly< int >;

  /** The top margin for text in the text view.
   *
   * Note that this property is confusingly named. In CSS terms,
   * the value set here is padding, and it is applied in addition
   * to the padding from the theme.
   *
   * Don't confuse this property with Gtk::Widget::property_margin_top().
   *
   * @newin{2,30}
   *
   * Default value: 0
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_top_margin() -> Glib::PropertyProxy< int > ;

/** The top margin for text in the text view.
   *
   * Note that this property is confusingly named. In CSS terms,
   * the value set here is padding, and it is applied in addition
   * to the padding from the theme.
   *
   * Don't confuse this property with Gtk::Widget::property_margin_top().
   *
   * @newin{2,30}
   *
   * Default value: 0
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_top_margin() const -> Glib::PropertyProxy_ReadOnly< int >;

  /** The bottom margin for text in the text view.
   *
   * Note that this property is confusingly named. In CSS terms,
   * the value set here is padding, and it is applied in addition
   * to the padding from the theme.
   *
   * Don't confuse this property with Gtk::Widget::property_margin_bottom().
   *
   * @newin{2,30}
   *
   * Default value: 0
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_bottom_margin() -> Glib::PropertyProxy< int > ;

/** The bottom margin for text in the text view.
   *
   * Note that this property is confusingly named. In CSS terms,
   * the value set here is padding, and it is applied in addition
   * to the padding from the theme.
   *
   * Don't confuse this property with Gtk::Widget::property_margin_bottom().
   *
   * @newin{2,30}
   *
   * Default value: 0
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_bottom_margin() const -> Glib::PropertyProxy_ReadOnly< int >;

  /** Amount to indent the paragraph, in pixels.
   *
   * Default value: 0
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_indent() -> Glib::PropertyProxy< int > ;

/** Amount to indent the paragraph, in pixels.
   *
   * Default value: 0
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_indent() const -> Glib::PropertyProxy_ReadOnly< int >;

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

  /** If the insertion cursor is shown.
   *
   * Default value: <tt>true</tt>
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_cursor_visible() -> Glib::PropertyProxy< bool > ;

/** If the insertion cursor is shown.
   *
   * Default value: <tt>true</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_cursor_visible() const -> Glib::PropertyProxy_ReadOnly< bool >;

  /** The buffer which is displayed.
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_buffer() -> Glib::PropertyProxy< Glib::RefPtr<TextBuffer> > ;

/** The buffer which is displayed.
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_buffer() const -> Glib::PropertyProxy_ReadOnly< Glib::RefPtr<TextBuffer> >;

  /** Whether entered text overwrites existing contents.
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_overwrite() -> Glib::PropertyProxy< bool > ;

/** Whether entered text overwrites existing contents.
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_overwrite() const -> Glib::PropertyProxy_ReadOnly< bool >;

  /** Whether Tab will result in a tab character being entered.
   *
   * Default value: <tt>true</tt>
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_accepts_tab() -> Glib::PropertyProxy< bool > ;

/** Whether Tab will result in a tab character being entered.
   *
   * Default value: <tt>true</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_accepts_tab() const -> Glib::PropertyProxy_ReadOnly< bool >;

  /** Which IM (input method) module should be used for this text_view.
   *
   * See Gtk::IMMulticontext.
   *
   * Setting this to a non-<tt>nullptr</tt> value overrides the system-wide IM module
   * setting. See the GtkSettings Gtk::Settings::property_gtk_im_module() property.
   *
   * Default value: ""
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_im_module() -> Glib::PropertyProxy< Glib::ustring > ;

/** Which IM (input method) module should be used for this text_view.
   *
   * See Gtk::IMMulticontext.
   *
   * Setting this to a non-<tt>nullptr</tt> value overrides the system-wide IM module
   * setting. See the GtkSettings Gtk::Settings::property_gtk_im_module() property.
   *
   * Default value: ""
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_im_module() const -> Glib::PropertyProxy_ReadOnly< Glib::ustring >;

  /** The purpose of this text field.
   *
   * This property can be used by on-screen keyboards and other input
   * methods to adjust their behaviour.
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
   * Default value: Gtk::InputPurpose::FREE_FORM
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_input_purpose() const -> Glib::PropertyProxy_ReadOnly< InputPurpose >;

  /** Additional hints (beyond property_input_purpose())
   * that allow input methods to fine-tune their behaviour.
   *
   * Default value: Gtk::InputHints::NONE
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_input_hints() -> Glib::PropertyProxy< InputHints > ;

/** Additional hints (beyond property_input_purpose())
   * that allow input methods to fine-tune their behaviour.
   *
   * Default value: Gtk::InputHints::NONE
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_input_hints() const -> Glib::PropertyProxy_ReadOnly< InputHints >;

  /** Whether text should be displayed in a monospace font.
   *
   * If <tt>true</tt>, set the .monospace style class on the
   * text view to indicate that a monospace font is desired.
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_monospace() -> Glib::PropertyProxy< bool > ;

/** Whether text should be displayed in a monospace font.
   *
   * If <tt>true</tt>, set the .monospace style class on the
   * text view to indicate that a monospace font is desired.
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_monospace() const -> Glib::PropertyProxy_ReadOnly< bool >;

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


public:

public:
  //C++ methods used to invoke GTK+ virtual functions:

protected:
  //GTK+ Virtual Functions (override these to change behaviour):

  //Default Signal Handlers::
  /// This is a default handler for the signal signal_set_anchor().
  virtual void on_set_anchor();
  /// This is a default handler for the signal signal_insert_at_cursor().
  virtual void on_insert_at_cursor(const Glib::ustring& str);


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
   * @relates Gtk::TextView
   */
  GTKMM_API
  auto wrap(GtkTextView* object, bool take_copy = false) -> Gtk::TextView*;
} //namespace Glib


#endif /* _GTKMM_TEXTVIEW_H */

