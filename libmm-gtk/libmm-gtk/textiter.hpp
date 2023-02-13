
#ifndef _GTKMM_TEXTITER_H
#define _GTKMM_TEXTITER_H


#include <mm/glib/ustring.hpp>
#include <sigc++/sigc++.h>

/* Copyright(C) 1998-2002 The gtkmm Development Team
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
#include <mm/pango/language.hpp>
#include <mm/gtk/texttag.hpp>
#include <gtk/gtk.h> /* we need the definition of GtkTextIter */


namespace Gdk
{
class Paintable;
}

namespace Gtk
{


/** @addtogroup gtkmmEnums gtkmm Enums and Flags */

/**
 *  @var TextSearchFlags VISIBLE_ONLY
 * Search only visible data. A search match may
 * have invisible text interspersed.
 *
 *  @var TextSearchFlags TEXT_ONLY
 * Search only text. A match may have paintables or
 * child widgets mixed inside the matched range.
 *
 *  @var TextSearchFlags CASE_INSENSITIVE
 * The text will be matched regardless of
 * what case it is in.
 *
 *  @enum TextSearchFlags
 *
 * Flags affecting how a search is done.
 *
 * If neither Gtk::TextSearchFlags::VISIBLE_ONLY nor Gtk::TextSearchFlags::TEXT_ONLY are
 * enabled, the match must be exact; the special 0xFFFC character will match
 * embedded paintables or child widgets.
 *
 * @ingroup gtkmmEnums
 * @par Bitwise operators:
 * <tt>TextSearchFlags operator|(TextSearchFlags, TextSearchFlags)</tt><br>
 * <tt>TextSearchFlags operator&(TextSearchFlags, TextSearchFlags)</tt><br>
 * <tt>TextSearchFlags operator^(TextSearchFlags, TextSearchFlags)</tt><br>
 * <tt>TextSearchFlags operator~(TextSearchFlags)</tt><br>
 * <tt>TextSearchFlags& operator|=(TextSearchFlags&, TextSearchFlags)</tt><br>
 * <tt>TextSearchFlags& operator&=(TextSearchFlags&, TextSearchFlags)</tt><br>
 * <tt>TextSearchFlags& operator^=(TextSearchFlags&, TextSearchFlags)</tt><br>
 */
enum class TextSearchFlags
{
  VISIBLE_ONLY = 1 << 0,
  TEXT_ONLY = 1 << 1,
  CASE_INSENSITIVE = 1 << 2
};

/** @ingroup gtkmmEnums */
inline auto operator|(TextSearchFlags lhs, TextSearchFlags rhs) -> TextSearchFlags
  { return static_cast<TextSearchFlags>(static_cast<unsigned>(lhs) | static_cast<unsigned>(rhs)); }

/** @ingroup gtkmmEnums */
inline auto operator&(TextSearchFlags lhs, TextSearchFlags rhs) -> TextSearchFlags
  { return static_cast<TextSearchFlags>(static_cast<unsigned>(lhs) & static_cast<unsigned>(rhs)); }

/** @ingroup gtkmmEnums */
inline auto operator^(TextSearchFlags lhs, TextSearchFlags rhs) -> TextSearchFlags
  { return static_cast<TextSearchFlags>(static_cast<unsigned>(lhs) ^ static_cast<unsigned>(rhs)); }

/** @ingroup gtkmmEnums */
inline auto operator~(TextSearchFlags flags) -> TextSearchFlags
  { return static_cast<TextSearchFlags>(~static_cast<unsigned>(flags)); }

/** @ingroup gtkmmEnums */
inline auto operator|=(TextSearchFlags& lhs, TextSearchFlags rhs) -> TextSearchFlags&
  { return (lhs = static_cast<TextSearchFlags>(static_cast<unsigned>(lhs) | static_cast<unsigned>(rhs))); }

/** @ingroup gtkmmEnums */
inline auto operator&=(TextSearchFlags& lhs, TextSearchFlags rhs) -> TextSearchFlags&
  { return (lhs = static_cast<TextSearchFlags>(static_cast<unsigned>(lhs) & static_cast<unsigned>(rhs))); }

/** @ingroup gtkmmEnums */
inline auto operator^=(TextSearchFlags& lhs, TextSearchFlags rhs) -> TextSearchFlags&
  { return (lhs = static_cast<TextSearchFlags>(static_cast<unsigned>(lhs) ^ static_cast<unsigned>(rhs))); }


} // namespace Gtk

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

template <>
class GTKMM_API Value<Gtk::TextSearchFlags> : public Glib::Value_Flags<Gtk::TextSearchFlags>
{
public:
  static auto value_type() -> GType G_GNUC_CONST;
};

} // namespace Glib
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

namespace Gtk
{


class GTKMM_API TextBuffer;
class GTKMM_API TextMark;
class GTKMM_API TextChildAnchor;

//TODO: Maybe we should have separate iterators for words, lines, and sentences.
/** Common base class of TextIter and TextConstIter.
 *
 * You don't create objects of this base class. Objects shall be either TextIter
 * or TextConstIter.
 *
 * @see TextIter
 * @ingroup TextView
 */
class GTKMM_API TextIterBase
{
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  using CppObjectType = TextIterBase;
  using BaseObjectType = GtkTextIter;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

  TextIterBase(const TextIterBase& other) noexcept;
  auto operator=(const TextIterBase& other) noexcept -> TextIterBase&;

  TextIterBase(TextIterBase&& other) noexcept;
  auto operator=(TextIterBase&& other) noexcept -> TextIterBase&;

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType G_GNUC_CONST;

  TextIterBase();

  explicit TextIterBase(const GtkTextIter* gobject); // always takes a copy

  ///Provides access to the underlying C instance.
  auto       gobj() -> GtkTextIter*       { return &gobject_; }

  ///Provides access to the underlying C instance.
  auto gobj() const -> const GtkTextIter* { return &gobject_; }

protected:
  GtkTextIter gobject_;

private:


public:
  using iterator_category = std::bidirectional_iterator_tag;
  using value_type        = gunichar;
  using difference_type   = int;
  using reference         = value_type;
  using pointer           = void;

  /** Alias for get_char(). */
  inline auto operator*() const -> value_type;

   /** Alias for !is_end().
   * For instance,
   * @code
   * if (textiter)
   *   do_something();
   * @endcode
    *
    * @newin{3,22}
    */
   explicit operator bool() const;


  /** Returns the character offset of an iterator.
   *
   * Each character in a `Gtk::TextBuffer` has an offset,
   * starting with 0 for the first character in the buffer.
   * Use [method@Gtk,TextBuffer.get_iter_at_offset] to convert
   * an offset back into an iterator.
   *
   * @return A character offset.
   */
  auto get_offset() const -> int;

  /** Returns the line number containing the iterator.
   *
   * Lines in a `Gtk::TextBuffer` are numbered beginning
   * with 0 for the first line in the buffer.
   *
   * @return A line number.
   */
  auto get_line() const -> int;

  /** Returns the character offset of the iterator,
   * counting from the start of a newline-terminated line.
   *
   * The first character on the line has offset 0.
   *
   * @return Offset from start of line.
   */
  auto get_line_offset() const -> int;

  /** Returns the byte index of the iterator, counting
   * from the start of a newline-terminated line.
   *
   * Remember that `Gtk::TextBuffer` encodes text in
   * UTF-8, and that characters can require a variable
   * number of bytes to represent.
   *
   * @return Distance from start of line, in bytes.
   */
  auto get_line_index() const -> int;


  /** Returns the offset in characters from the start of the
   * line to the given @a iter, not counting characters that
   * are invisible due to tags with the “invisible” flag
   * toggled on.
   *
   * @return Offset in visible characters from the start of the line.
   */
  auto get_visible_line_offset() const -> int;

  /** Returns the number of bytes from the start of the
   * line to the given @a iter, not counting bytes that
   * are invisible due to tags with the “invisible” flag
   * toggled on.
   *
   * @return Byte index of @a iter with respect to the start of the line.
   */
  auto get_visible_line_index() const -> int;


  /** The Unicode character at this iterator is returned.
   *
   * Equivalent to operator* on a C++ iterator. If the element at
   * this iterator is a non-character element, such as an image
   * embedded in the buffer, the Unicode “unknown” character 0xFFFC
   * is returned. If invoked on the end iterator, zero is returned;
   * zero is not a valid Unicode character.
   *
   * So you can write a loop which ends when this function returns 0.
   *
   * @return A Unicode character, or 0 if @a iter is not dereferenceable.
   */
  auto get_char() const -> gunichar;


  /** Returns the text in the given range.
   *
   * A “slice” is an array of characters encoded in UTF-8 format,
   * including the Unicode “unknown” character 0xFFFC for iterable
   * non-character elements in the buffer, such as images.
   * Because images are encoded in the slice, byte and
   * character offsets in the returned array will correspond to byte
   * offsets in the text buffer. Note that 0xFFFC can occur in normal
   * text as well, so it is not a reliable indicator that a paintable or
   * widget is in the buffer.
   *
   * @param end Iterator at end of a range.
   * @return Slice of text from the buffer.
   */
  auto get_slice(const TextIterBase& end) const -> Glib::ustring;

  /** Returns text in the given range.
   *
   * If the range
   * contains non-text elements such as images, the character and byte
   * offsets in the returned string will not correspond to character and
   * byte offsets in the buffer. If you want offsets to correspond, see
   * get_slice().
   *
   * @param end Iterator at end of a range.
   * @return Array of characters from the buffer.
   */
  auto get_text(const TextIterBase& end) const -> Glib::ustring;

  /** Returns visible text in the given range.
   *
   * Like get_slice(), but invisible text
   * is not included. Invisible text is usually invisible because
   * a `Gtk::TextTag` with the “invisible” attribute turned on has
   * been applied to it.
   *
   * @param end Iterator at end of range.
   * @return Slice of text from the buffer.
   */
  auto get_visible_slice(const TextIterBase& end) const -> Glib::ustring;

  /** Returns visible text in the given range.
   *
   * Like get_text(), but invisible text
   * is not included. Invisible text is usually invisible because
   * a `Gtk::TextTag` with the “invisible” attribute turned on has
   * been applied to it.
   *
   * @param end Iterator at end of range.
   * @return String containing visible text in the
   * range.
   */
  auto get_visible_text(const TextIterBase& end) const -> Glib::ustring;


  /** Returns <tt>true</tt> if @a tag is toggled on at exactly this point.
   *
   * If @a tag is <tt>nullptr</tt>, returns <tt>true</tt> if any tag is toggled on at this point.
   *
   * Note that if this function returns <tt>true</tt>, it means that
   *  @a iter is at the beginning of the tagged range, and that the
   * character at @a iter is inside the tagged range. In other
   * words, unlike ends_tag(), if
   * this function returns <tt>true</tt>, [method @a Gtk.TextIter.has_tag
   * will also return <tt>true</tt> for the same parameters.
   *
   * @param tag A `Gtk::TextTag`.
   * @return Whether @a iter is the start of a range tagged with @a tag.
   */
  auto starts_tag(const Glib::RefPtr<const TextTag>& tag =  {}) const -> bool;

  /** Returns <tt>true</tt> if @a tag is toggled off at exactly this point.
   *
   * If @a tag is <tt>nullptr</tt>, returns <tt>true</tt> if any tag is toggled off at this point.
   *
   * Note that if this function returns <tt>true</tt>, it means that
   *  @a iter is at the end of the tagged range, but that the character
   * at @a iter is outside the tagged range. In other words,
   * unlike starts_tag(), if this function
   * returns <tt>true</tt>, has_tag() will return
   * <tt>false</tt> for the same parameters.
   *
   * @param tag A `Gtk::TextTag`.
   * @return Whether @a iter is the end of a range tagged with @a tag.
   */
  auto ends_tag(const Glib::RefPtr<const TextTag>& tag =  {}) const -> bool;

  /** Gets whether a range with @a tag applied to it begins
   * or ends at @a iter.
   *
   * This is equivalent to (starts_tag() ||
   * ends_tag())
   *
   * @param tag A `Gtk::TextTag`.
   * @return Whether @a tag is toggled on or off at @a iter.
   */
  auto toggles_tag(const Glib::RefPtr<const TextTag>& tag =  {}) const -> bool;

  /** Returns <tt>true</tt> if @a iter points to a character that is part
   * of a range tagged with @a tag.
   *
   * See also starts_tag() and
   * ends_tag().
   *
   * @param tag A `Gtk::TextTag`.
   * @return Whether @a iter is tagged with @a tag.
   */
  auto has_tag(const Glib::RefPtr<const TextTag>& tag) const -> bool;


  /** Returns whether the character at @a iter is within an editable region
   * of text.
   *
   * Non-editable text is “locked” and can’t be changed by the
   * user via `Gtk::TextView`. If no tags applied to this text affect
   * editability, @a default_setting will be returned.
   *
   * You don’t want to use this function to decide whether text can be
   * inserted at @a iter, because for insertion you don’t want to know
   * whether the char at @a iter is inside an editable range, you want to
   * know whether a new character inserted at @a iter would be inside an
   * editable range. Use can_insert() to handle this
   * case.
   *
   * @param default_setting <tt>true</tt> if text is editable by default.
   * @return Whether @a iter is inside an editable range.
   */
  auto editable(bool default_setting =  true) const -> bool;

  /** Considering the default editability of the buffer, and tags that
   * affect editability, determines whether text inserted at @a iter would
   * be editable.
   *
   * If text inserted at @a iter would be editable then the
   * user should be allowed to insert text at @a iter.
   * Gtk::TextBuffer::insert_interactive() uses this function
   * to decide whether insertions are allowed at a given position.
   *
   * @param default_editability <tt>true</tt> if text is editable by default.
   * @return Whether text inserted at @a iter would be editable.
   */
  auto can_insert(bool default_editability =  true) const -> bool;


  /** Determines whether @a iter begins a natural-language word.
   *
   * Word breaks are determined by Pango and should be correct
   * for nearly any language.
   *
   * @return <tt>true</tt> if @a iter is at the start of a word.
   */
  auto starts_word() const -> bool;

  /** Determines whether @a iter ends a natural-language word.
   *
   * Word breaks are determined by Pango and should be correct
   * for nearly any language.
   *
   * @return <tt>true</tt> if @a iter is at the end of a word.
   */
  auto ends_word() const -> bool;

  /** Determines whether the character pointed by @a iter is part of a
   * natural-language word (as opposed to say inside some whitespace).
   *
   * Word breaks are determined by Pango and should be correct
   * for nearly any language.
   *
   * Note that if starts_word() returns <tt>true</tt>,
   * then this function returns <tt>true</tt> too, since @a iter points to
   * the first character of the word.
   *
   * @return <tt>true</tt> if @a iter is inside a word.
   */
  auto inside_word() const -> bool;

  /** Determines whether @a iter begins a sentence.
   *
   * Sentence boundaries are determined by Pango and
   * should be correct for nearly any language.
   *
   * @return <tt>true</tt> if @a iter is at the start of a sentence.
   */
  auto starts_sentence() const -> bool;

  /** Determines whether @a iter ends a sentence.
   *
   * Sentence boundaries are determined by Pango and should
   * be correct for nearly any language.
   *
   * @return <tt>true</tt> if @a iter is at the end of a sentence.
   */
  auto ends_sentence() const -> bool;

  /** Determines whether @a iter is inside a sentence (as opposed to in
   * between two sentences, e.g.\ after a period and before the first
   * letter of the next sentence).
   *
   * Sentence boundaries are determined by Pango and should be correct
   * for nearly any language.
   *
   * @return <tt>true</tt> if @a iter is inside a sentence.
   */
  auto inside_sentence() const -> bool;

  /** Returns <tt>true</tt> if @a iter begins a paragraph.
   *
   * This is the case if get_line_offset()
   * would return 0. However this function is potentially more
   * efficient than get_line_offset(), because
   * it doesn’t have to compute the offset, it just has to see
   * whether it’s 0.
   *
   * @return Whether @a iter begins a line.
   */
  auto starts_line() const -> bool;

  /** Returns <tt>true</tt> if @a iter points to the start of the paragraph
   * delimiter characters for a line.
   *
   * Delimiters will be either a newline, a carriage return, a carriage
   * return followed by a newline, or a Unicode paragraph separator
   * character.
   *
   * Note that an iterator pointing to the \\n of a \\r\\n pair will not be
   * counted as the end of a line, the line ends before the \\r. The end
   * iterator is considered to be at the end of a line, even though there
   * are no paragraph delimiter chars there.
   *
   * @return Whether @a iter is at the end of a line.
   */
  auto ends_line() const -> bool;

  /** Determine if @a iter is at a cursor position.
   *
   * See forward_cursor_position() or
   * Pango::LogAttr or pango_break() for details
   * on what a cursor position is.
   *
   * @return <tt>true</tt> if the cursor can be placed at @a iter.
   */
  auto is_cursor_position() const -> bool;


  /** Returns the number of characters in the line containing @a iter,
   * including the paragraph delimiters.
   *
   * @return Number of characters in the line.
   */
  auto get_chars_in_line() const -> int;

  /** Returns the number of bytes in the line containing @a iter,
   * including the paragraph delimiters.
   *
   * @return Number of bytes in the line.
   */
  auto get_bytes_in_line() const -> int;


  /** Returns the language in effect at @a iter.
   *
   * If no tags affecting language apply to @a iter, the return
   * value is identical to that of gtk_get_default_language().
   *
   * @return Language in effect at @a iter.
   */
  auto get_language() const -> Pango::Language;

  /** Returns <tt>true</tt> if @a iter is the end iterator.
   *
   * This means it is one past the last dereferenceable iterator
   * in the buffer. is_end() is the most efficient
   * way to check whether an iterator is the end iterator.
   *
   * @return Whether @a iter is the end iterator.
   */
  auto is_end() const -> bool;

  /** Returns <tt>true</tt> if @a iter is the first iterator in the buffer.
   *
   * @return Whether @a iter is the first in the buffer.
   */
  auto is_start() const -> bool;


  /** Moves @a iter forward by one character offset.
   *
   * Note that images embedded in the buffer occupy 1 character slot, so
   * this function may actually move onto an image instead of a character,
   * if you have images in your buffer. If @a iter is the end iterator or
   * one character before it, @a iter will now point at the end iterator,
   * and this function returns <tt>false</tt> for convenience when writing loops.
   *
   * @return Whether @a iter moved and is dereferenceable.
   */
  auto forward_char() -> bool;

  /** Moves backward by one character offset.
   *
   * @return Whether movement was possible.
   */
  auto backward_char() -> bool;

  /** Moves @a count characters if possible.
   *
   * If @a count would move past the start or end of the buffer,
   * moves to the start or end of the buffer.
   *
   * The return value indicates whether the new position of
   *  @a iter is different from its original position, and dereferenceable
   * (the last iterator in the buffer is not dereferenceable). If @a count
   * is 0, the function does nothing and returns <tt>false</tt>.
   *
   * @param count Number of characters to move, may be negative.
   * @return Whether @a iter moved and is dereferenceable.
   */
  auto forward_chars(int count) -> bool;

  /** Moves @a count characters backward, if possible.
   *
   * If @a count would move past the start or end of the buffer, moves
   * to the start or end of the buffer.
   *
   * The return value indicates whether the iterator moved
   * onto a dereferenceable position; if the iterator didn’t move, or
   * moved onto the end iterator, then <tt>false</tt> is returned. If @a count is 0,
   * the function does nothing and returns <tt>false</tt>.
   *
   * @param count Number of characters to move.
   * @return Whether @a iter moved and is dereferenceable.
   */
  auto backward_chars(int count) -> bool;

  /** Moves @a iter to the start of the next line.
   *
   * If the iter is already on the last line of the buffer,
   * moves the iter to the end of the current line. If after
   * the operation, the iter is at the end of the buffer and not
   * dereferenceable, returns <tt>false</tt>. Otherwise, returns <tt>true</tt>.
   *
   * @return Whether @a iter can be dereferenced.
   */
  auto forward_line() -> bool;

  /** Moves @a iter to the start of the previous line.
   *
   * @return Whether @a iter moved.
   */
  auto backward_line() -> bool;

  /** Moves @a count lines forward, if possible.
   *
   * If @a count would move past the start or end of the buffer, moves to
   * the start or end of the buffer.
   *
   * The return value indicates whether the iterator moved
   * onto a dereferenceable position; if the iterator didn’t move, or
   * moved onto the end iterator, then <tt>false</tt> is returned. If @a count is 0,
   * the function does nothing and returns <tt>false</tt>. If @a count is negative,
   * moves backward by 0 - @a count lines.
   *
   * @param count Number of lines to move forward.
   * @return Whether @a iter moved and is dereferenceable.
   */
  auto forward_lines(int count) -> bool;

  /** Moves @a count lines backward, if possible.
   *
   * If @a count would move past the start or end of the buffer, moves to
   * the start or end of the buffer.
   *
   * The return value indicates whether the iterator moved
   * onto a dereferenceable position; if the iterator didn’t move, or
   * moved onto the end iterator, then <tt>false</tt> is returned. If @a count is 0,
   * the function does nothing and returns <tt>false</tt>. If @a count is negative,
   * moves forward by 0 - @a count lines.
   *
   * @param count Number of lines to move backward.
   * @return Whether @a iter moved and is dereferenceable.
   */
  auto backward_lines(int count) -> bool;

  /** Moves forward to the next word end.
   *
   * If @a iter is currently on a word end, moves forward to the
   * next one after that.
   *
   * Word breaks are determined by Pango and should be correct
   * for nearly any language.
   *
   * @return <tt>true</tt> if @a iter moved and is not the end iterator.
   */
  auto forward_word_end() -> bool;

  /** Moves backward to the previous word start.
   *
   * If @a iter is currently on a word start, moves backward to the
   * next one after that.
   *
   * Word breaks are determined by Pango and should be correct
   * for nearly any language
   *
   * @return <tt>true</tt> if @a iter moved and is not the end iterator.
   */
  auto backward_word_start() -> bool;

  /** Calls forward_word_end() up to @a count times.
   *
   * @param count Number of times to move.
   * @return <tt>true</tt> if @a iter moved and is not the end iterator.
   */
  auto forward_word_ends(int count) -> bool;

  /** Calls backward_word_start() up to @a count times.
   *
   * @param count Number of times to move.
   * @return <tt>true</tt> if @a iter moved and is not the end iterator.
   */
  auto backward_word_starts(int count) -> bool;


  /** Moves @a iter to the start of the next visible line.
   *
   * @return Whether @a iter can be dereferenced.
   */
  auto forward_visible_line() -> bool;

  /** Moves @a iter to the start of the previous visible line.
   *
   * @return Whether @a iter moved.
   */
  auto backward_visible_line() -> bool;

  /** Moves @a count visible lines forward, if possible.
   *
   * If @a count would move past the start or end of the buffer, moves to
   * the start or end of the buffer.
   *
   * The return value indicates whether the iterator moved
   * onto a dereferenceable position; if the iterator didn’t move, or
   * moved onto the end iterator, then <tt>false</tt> is returned. If @a count is 0,
   * the function does nothing and returns <tt>false</tt>. If @a count is negative,
   * moves backward by 0 - @a count lines.
   *
   * @param count Number of lines to move forward.
   * @return Whether @a iter moved and is dereferenceable.
   */
  auto forward_visible_lines(int count) -> bool;

  /** Moves @a count visible lines backward, if possible.
   *
   * If @a count would move past the start or end of the buffer, moves to
   * the start or end of the buffer.
   *
   * The return value indicates whether the iterator moved
   * onto a dereferenceable position; if the iterator didn’t move, or
   * moved onto the end iterator, then <tt>false</tt> is returned. If @a count is 0,
   * the function does nothing and returns <tt>false</tt>. If @a count is negative,
   * moves forward by 0 - @a count lines.
   *
   * @param count Number of lines to move backward.
   * @return Whether @a iter moved and is dereferenceable.
   */
  auto backward_visible_lines(int count) -> bool;

  //TODO: Now that there are so many *_visible_ versions of the methods, maybe we should
  //just add a visible=false parameter and therefore halve the number of methods. murrayc


  /** Moves forward to the next visible word end.
   *
   * If @a iter is currently on a word end, moves forward to the
   * next one after that.
   *
   * Word breaks are determined by Pango and should be correct
   * for nearly any language
   *
   * @return <tt>true</tt> if @a iter moved and is not the end iterator.
   */
  auto forward_visible_word_end() -> bool;

  /** Moves backward to the previous visible word start.
   *
   * If @a iter is currently on a word start, moves backward to the
   * next one after that.
   *
   * Word breaks are determined by Pango and should be correct
   * for nearly any language.
   *
   * @return <tt>true</tt> if @a iter moved and is not the end iterator.
   */
  auto backward_visible_word_start() -> bool;

  /** Calls forward_visible_word_end() up to @a count times.
   *
   * @param count Number of times to move.
   * @return <tt>true</tt> if @a iter moved and is not the end iterator.
   */
  auto forward_visible_word_ends(int count) -> bool;

  /** Calls backward_visible_word_start() up to @a count times.
   *
   * @param count Number of times to move.
   * @return <tt>true</tt> if @a iter moved and is not the end iterator.
   */
  auto backward_visible_word_starts(int count) -> bool;


  /** Moves forward to the next sentence end.
   *
   * If @a iter is at the end of a sentence, moves to the next
   * end of sentence.
   *
   * Sentence boundaries are determined by Pango and should
   * be correct for nearly any language.
   *
   * @return <tt>true</tt> if @a iter moved and is not the end iterator.
   */
  auto forward_sentence_end() -> bool;

  /** Moves backward to the previous sentence start.
   *
   * If @a iter is already at the start of a sentence, moves backward
   * to the next one.
   *
   * Sentence boundaries are determined by Pango and should
   * be correct for nearly any language.
   *
   * @return <tt>true</tt> if @a iter moved and is not the end iterator.
   */
  auto backward_sentence_start() -> bool;

  /** Calls forward_sentence_end() @a count times.
   *
   * If @a count is negative, moves backward instead of forward.
   *
   * @param count Number of sentences to move.
   * @return <tt>true</tt> if @a iter moved and is not the end iterator.
   */
  auto forward_sentence_ends(int count) -> bool;

  /** Calls backward_sentence_start() up to @a count times.
   *
   * If @a count is negative, moves forward instead of backward.
   *
   * @param count Number of sentences to move.
   * @return <tt>true</tt> if @a iter moved and is not the end iterator.
   */
  auto backward_sentence_starts(int count) -> bool;


  /** Moves @a iter forward by a single cursor position.
   *
   * Cursor positions are (unsurprisingly) positions where the
   * cursor can appear. Perhaps surprisingly, there may not be
   * a cursor position between all characters. The most common
   * example for European languages would be a carriage return/newline
   * sequence.
   *
   * For some Unicode characters, the equivalent of say the letter “a”
   * with an accent mark will be represented as two characters, first
   * the letter then a "combining mark" that causes the accent to be
   * rendered; so the cursor can’t go between those two characters.
   *
   * See also the Pango::LogAttr struct and the pango_break()
   * function.
   *
   * @return <tt>true</tt> if we moved and the new position is dereferenceable.
   */
  auto forward_cursor_position() -> bool;

  /** Like forward_cursor_position(), but moves backward.
   *
   * @return <tt>true</tt> if we moved.
   */
  auto backward_cursor_position() -> bool;

  /** Moves up to @a count cursor positions.
   *
   * See forward_cursor_position() for details.
   *
   * @param count Number of positions to move.
   * @return <tt>true</tt> if we moved and the new position is dereferenceable.
   */
  auto forward_cursor_positions(int count) -> bool;

  /** Moves up to @a count cursor positions.
   *
   * See forward_cursor_position() for details.
   *
   * @param count Number of positions to move.
   * @return <tt>true</tt> if we moved and the new position is dereferenceable.
   */
  auto backward_cursor_positions(int count) -> bool;


  /** Moves @a iter forward to the next visible cursor position.
   *
   * See forward_cursor_position() for details.
   *
   * @return <tt>true</tt> if we moved and the new position is dereferenceable.
   */
  auto forward_visible_cursor_position() -> bool;

  /** Moves @a iter forward to the previous visible cursor position.
   *
   * See backward_cursor_position() for details.
   *
   * @return <tt>true</tt> if we moved and the new position is dereferenceable.
   */
  auto backward_visible_cursor_position() -> bool;

  /** Moves up to @a count visible cursor positions.
   *
   * See forward_cursor_position() for details.
   *
   * @param count Number of positions to move.
   * @return <tt>true</tt> if we moved and the new position is dereferenceable.
   */
  auto forward_visible_cursor_positions(int count) -> bool;

  /** Moves up to @a count visible cursor positions.
   *
   * See backward_cursor_position() for details.
   *
   * @param count Number of positions to move.
   * @return <tt>true</tt> if we moved and the new position is dereferenceable.
   */
  auto backward_visible_cursor_positions(int count) -> bool;


  /** Sets @a iter to point to @a char_offset.
   *
   *  @a char_offset counts from the start
   * of the entire text buffer, starting with 0.
   *
   * @param char_offset A character number.
   */
  void set_offset(int char_offset);

  /** Moves iterator @a iter to the start of the line @a line_number.
   *
   * If @a line_number is negative or larger than or equal to the number of lines
   * in the buffer, moves @a iter to the start of the last line in the buffer.
   *
   * @param line_number Line number (counted from 0).
   */
  void set_line(int line_number);

  /** Moves @a iter within a line, to a new character (not byte) offset.
   *
   * The given character offset must be less than or equal to the number
   * of characters in the line; if equal, @a iter moves to the start of the
   * next line. See set_line_index() if you have a byte
   * index rather than a character offset.
   *
   * @param char_on_line A character offset relative to the start of @a iter’s current line.
   */
  void set_line_offset(int char_on_line);

  /** Same as set_line_offset(), but works with a
   * byte index. The given byte index must be at
   * the start of a character, it can’t be in the middle of a UTF-8
   * encoded character.
   *
   * @param byte_on_line A byte index relative to the start of @a iter’s current line.
   */
  void set_line_index(int byte_on_line);

  /** Moves @a iter forward to the “end iterator”, which points
   * one past the last valid character in the buffer.
   *
   * get_char() called on the end iterator
   * returns 0, which is convenient for writing loops.
   */
  void forward_to_end();

  /** Moves the iterator to point to the paragraph delimiter characters.
   *
   * The possible characters are either a newline, a carriage return,
   * a carriage return/newline in sequence, or the Unicode paragraph
   * separator character.
   *
   * If the iterator is already at the paragraph delimiter
   * characters, moves to the paragraph delimiter characters for the
   * next line. If @a iter is on the last line in the buffer, which does
   * not end in paragraph delimiters, moves to the end iterator (end of
   * the last line), and returns <tt>false</tt>.
   *
   * @return <tt>true</tt> if we moved and the new location is not the end iterator.
   */
  auto forward_to_line_end() -> bool;


  /** Like set_line_offset(), but the offset is in visible
   * characters, i.e.\ text with a tag making it invisible is not
   * counted in the offset.
   *
   * @param char_on_line A character offset.
   */
  void set_visible_line_offset(int char_on_line);

  /** Like set_line_index(), but the index is in visible
   * bytes, i.e.\ text with a tag making it invisible is not counted
   * in the index.
   *
   * @param byte_on_line A byte index.
   */
  void set_visible_line_index(int byte_on_line);


  /** Moves forward to the next toggle (on or off) of the
   *  @a tag, or to the next toggle of any tag if
   *  @a tag is <tt>nullptr</tt>.
   *
   * If no matching tag toggles are found,
   * returns <tt>false</tt>, otherwise <tt>true</tt>. Does not return toggles
   * located at @a iter, only toggles after @a iter. Sets @a iter to
   * the location of the toggle, or to the end of the buffer
   * if no toggle is found.
   *
   * @param tag A `Gtk::TextTag`.
   * @return Whether we found a tag toggle after @a iter.
   */
  auto forward_to_tag_toggle(const Glib::RefPtr<const TextTag>& tag =  {}) -> bool;

  /** Moves backward to the next toggle (on or off) of the
   *  @a tag, or to the next toggle of any tag if
   *  @a tag is <tt>nullptr</tt>.
   *
   * If no matching tag toggles are found,
   * returns <tt>false</tt>, otherwise <tt>true</tt>. Does not return toggles
   * located at @a iter, only toggles before @a iter. Sets @a iter
   * to the location of the toggle, or the start of the buffer
   * if no toggle is found.
   *
   * @param tag A `Gtk::TextTag`.
   * @return Whether we found a tag toggle before @a iter.
   */
  auto backward_to_tag_toggle(const Glib::RefPtr<const TextTag>& tag =  {}) -> bool;

  /** A slot that will be called on each consecutive character.
   * forward_find_char() and backward_find_char() advance the iterator one
   * character at a time until the slot returns <tt>true</tt>.
   *
   * For instance,
   * @code
   * bool on_find_char(gunichar ch);
   * @endcode
   *
   * @newin{3,90}
   */
  using SlotFindChar = sigc::slot<bool(gunichar)>;

  // _WRAP_METHOD can't be used here, because user_data is not the last parameter
  // in the gtk+ functions.
  //_WRAP_METHOD(bool forward_find_char(const SlotFindChar& slot{pred}, const TextIterBase& limit{.?}),
  //  gtk_text_iter_forward_find_char, slot_name slot, slot_callback TextIterBase_find_char_callback, no_slot_copy)
  //_WRAP_METHOD(bool backward_find_char(const SlotFindChar& slot{pred}, const TextIterBase& limit{.?}),
  //  gtk_text_iter_backward_find_char, slot_name slot, slot_callback TextIterBase_find_char_callback, no_slot_copy)


  /** Advances this iterator, calling @a slot on each character.
   *
   * If @a slot returns <tt>true</tt>, %forward_find_char() returns <tt>true</tt>
   * and stops scanning.
   * If @a slot never returns <tt>true</tt>, this iterator is set to @a limit.
   *
   * @param slot A function to be called on each character.
   * @param limit Search limit.
   * @return Whether a match was found.
   */
  auto forward_find_char(const SlotFindChar& slot, const TextIterBase& limit) -> bool;

  /** Advances this iterator, calling @a slot on each character.
   *
   * If @a slot returns <tt>true</tt>, %forward_find_char() returns <tt>true</tt>
   * and stops scanning.
   * If @a slot never returns <tt>true</tt>, this iterator is set to the end iterator.
   *
   * @param slot A function to be called on each character.
   * @return Whether a match was found.
   */
  auto forward_find_char(const SlotFindChar& slot) -> bool;

  /** Same as forward_find_char(const SlotFindChar& slot, const TextIterBase& limit),
   * but goes backward.
   *
   * @param slot Function to be called on each character.
   * @param limit Search limit.
   * @return Whether a match was found.
   */
  auto backward_find_char(const SlotFindChar& slot, const TextIterBase& limit) -> bool;

  /** Same as forward_find_char(const SlotFindChar& slot), but goes backward.
   *
   * @param slot Function to be called on each character.
   * @return Whether a match was found.
   */
  auto backward_find_char(const SlotFindChar& slot) -> bool;


  /** A qsort()-style function that returns negative if @a lhs is less than
   *  @a rhs, positive if @a lhs is greater than @a rhs, and 0 if they’re equal.
   *
   * Ordering is in character offset order, i.e. the first character
   * in the buffer is less than the second character in the buffer.
   *
   * @param rhs Another `Gtk::TextIter`.
   * @return -1 if @a lhs is less than @a rhs, 1 if @a lhs is greater, 0 if they are equal.
   */
  auto compare(const TextIterBase& rhs) const -> int;

  /** Checks whether @a iter falls in the range [ @a start, @a end).
   *
   *  @a start and @a end must be in ascending order.
   *
   * @param start Start of range.
   * @param end End of range.
   * @return <tt>true</tt> if @a iter is in the range.
   */
  auto in_range(const TextIterBase& start, const TextIterBase& end) const -> bool;


}; // end TextIterBase


/** Typedefed as Gtk::TextBuffer::iterator.
 *
 * An iterator represents a position between two characters in the text buffer.
 * Iterators are not valid indefinitely; whenever the buffer is modified in a way that
 * affects the number of characters in the buffer, all outstanding iterators become invalid.
 * (Note that deleting 5 characters and then reinserting 5 still invalidates iterators,
 * though you end up with the same number of characters you pass through a state with
 * a different number).
 *
 * Because of this, iterators can't be used to preserve positions across buffer modifications.
 * To preserve a position, the @link Gtk::TextMark Gtk::TextBuffer::Mark@endlink object is ideal.
 *
 * You can iterate over characters, words, lines, and sentences,
 * but operator*() and operator++() deal only in characters.
 *
 * @ingroup TextView
 */
class GTKMM_API TextIter : public TextIterBase
{
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  using CppObjectType = TextIter;
  using BaseObjectType = GtkTextIter;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

private:

public:
  /** Alias for forward_char(). */
  inline auto operator++() -> TextIter&;
  inline auto  operator++(int) -> TextIter;

  /** Alias for backward_char(). */
  inline auto operator--() -> TextIter&;
  inline auto  operator--(int) -> TextIter;


  /** Returns the `Gtk::TextBuffer` this iterator is associated with.
   *
   * @return The buffer.
   */
  auto get_buffer() const -> Glib::RefPtr<TextBuffer>;


  /** If the element at @a iter is a paintable, the paintable is returned.
   *
   * Otherwise, <tt>nullptr</tt> is returned.
   *
   * @return The paintable at @a iter.
   */
  auto get_paintable() const -> Glib::RefPtr<Gdk::Paintable>;


  /** Returns a list of all `Gtk::TextMark` at this location.
   *
   * Because marks are not iterable (they don’t take up any "space"
   * in the buffer, they are just marks in between iterable locations),
   * multiple marks can exist in the same place.
   *
   * The returned list is not in any meaningful order.
   *
   * @return List of `Gtk::TextMark`.
   */
  auto get_marks() const -> std::vector<Glib::RefPtr<TextMark>>;


  /** If the location at @a iter contains a child anchor, the
   * anchor is returned.
   *
   * Otherwise, <tt>nullptr</tt> is returned.
   *
   * @return The anchor at @a iter.
   */
  auto get_child_anchor() const -> Glib::RefPtr<TextChildAnchor>;


  /** Returns a list of `Gtk::TextTag` that are toggled on or off at this
   * point.
   *
   * If @a toggled_on is <tt>true</tt>, the list contains tags that are
   * toggled on. If a tag is toggled on at @a iter, then some non-empty
   * range of characters following @a iter has that tag applied to it.  If
   * a tag is toggled off, then some non-empty range following @a iter
   * does not have the tag applied to it.
   *
   * @param toggled_on <tt>true</tt> to get toggled-on tags.
   * @return Tags
   * toggled at this point.
   */
  auto get_toggled_tags(bool toggled_on =  true) const -> std::vector<Glib::RefPtr<TextTag>>;


  /** Returns a list of tags that apply to @a iter, in ascending order of
   * priority (highest-priority tags are last).
   *
   * @return List of
   * `Gtk::TextTag`.
   */
  auto get_tags() const -> std::vector<Glib::RefPtr<TextTag>>;


  /** Searches forward for @a str. Any match is returned by setting
   *  @a match_start to the first character of the match and @a match_end to the
   * first character after the match. The search will not continue past
   *  @a limit. Note that a search is a linear or O(n) operation, so you
   * may wish to use @a limit to avoid locking up your UI on large
   * buffers.
   *
   * If the Gtk::TextSearchFlags::VISIBLE_ONLY flag is present, the match may
   * have invisible text interspersed in @a str. i.e. @a str will be a
   * possibly-noncontiguous subsequence of the matched range. similarly,
   * if you specify Gtk::TextSearchFlags::TEXT_ONLY, the match may have
   * pixbufs or child widgets mixed inside the matched range. If these
   * flags are not given, the match must be exact; the special 0xFFFC
   * character in @a str will match embedded pixbufs or child widgets.
   *
   * @param str A search string.
   * @param flags Flags affecting how the search is done.
   * @param match_start Return location for start of match.
   * @param match_end Return location for end of match.
   * @param limit Bound for the search.
   * @return Whether a match was found.
   */
  auto forward_search(const Glib::ustring& str, TextSearchFlags flags, TextIter& match_start, TextIter& match_end, const TextIterBase& limit) const -> bool;

  /// A forward_search() convenience overload.
  auto forward_search(const Glib::ustring& str, TextSearchFlags flags, TextIter& match_start, TextIter& match_end) const -> bool;


  /** Same as forward_search(), but moves backward.
   *
   * @param str Search string.
   * @param flags Bitmask of flags affecting the search.
   * @param match_start Return location for start of match.
   * @param match_end Return location for end of match.
   * @param limit Location of last possible @a match_start.
   * @return Whether a match was found.
   */
  auto backward_search(const Glib::ustring& str, TextSearchFlags flags, TextIter& match_start, TextIter& match_end, const TextIterBase& limit) const -> bool;

  /// A backward_search() convenience overload.
  auto backward_search(const Glib::ustring& str, TextSearchFlags flags, TextIter& match_start, TextIter& match_end) const -> bool;


  /** Swaps the value of @a first and @a second if @a second comes before
   *  @a first in the buffer.
   *
   * That is, ensures that @a first and @a second are in sequence.
   * Most text buffer functions that take a range call this
   * automatically on your behalf, so there’s no real reason to
   * call it yourself in those cases. There are some exceptions,
   * such as in_range(), that expect a
   * pre-sorted range.
   *
   * @param second Another `Gtk::TextIter`.
   */
  void order(TextIter& second);


};


/** Typedefed as Gtk::TextBuffer::const_iterator.
 *
 * @see TextIter
 * @ingroup TextView
 */
class GTKMM_API TextConstIter : public TextIterBase
{
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  using CppObjectType = TextConstIter;
  using BaseObjectType = GtkTextIter;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

private:

public:
  inline TextConstIter() noexcept;

  /** A TextIter can be implicitly converted to a TextConstIter.
   */
  inline TextConstIter(const TextIter& other) noexcept;

  /** A TextIter can be assigned to a TextConstIter.
   */
  inline auto operator=(const TextIter& other) noexcept -> TextConstIter&;

  /** Alias for forward_char(). */
  inline auto operator++() -> TextConstIter&;
  inline auto  operator++(int) -> TextConstIter;

  /** Alias for backward_char(). */
  inline auto operator--() -> TextConstIter&;
  inline auto  operator--(int) -> TextConstIter;


  /** Returns the `Gtk::TextBuffer` this iterator is associated with.
   *
   * @return The buffer.
   */
  auto get_buffer() const -> Glib::RefPtr<const TextBuffer>;


  /** If the element at @a iter is a paintable, the paintable is returned.
   *
   * Otherwise, <tt>nullptr</tt> is returned.
   *
   * @return The paintable at @a iter.
   */
  auto get_paintable() const -> Glib::RefPtr<const Gdk::Paintable>;


  /** Returns a list of all `Gtk::TextMark` at this location.
   *
   * Because marks are not iterable (they don’t take up any "space"
   * in the buffer, they are just marks in between iterable locations),
   * multiple marks can exist in the same place.
   *
   * The returned list is not in any meaningful order.
   *
   * @return List of `Gtk::TextMark`.
   */
  auto get_marks() const -> std::vector<Glib::RefPtr<const TextMark>>;


  /** If the location at @a iter contains a child anchor, the
   * anchor is returned.
   *
   * Otherwise, <tt>nullptr</tt> is returned.
   *
   * @return The anchor at @a iter.
   */
  auto get_child_anchor() const -> Glib::RefPtr<const TextChildAnchor>;


  /** Returns a list of `Gtk::TextTag` that are toggled on or off at this
   * point.
   *
   * If @a toggled_on is <tt>true</tt>, the list contains tags that are
   * toggled on. If a tag is toggled on at @a iter, then some non-empty
   * range of characters following @a iter has that tag applied to it.  If
   * a tag is toggled off, then some non-empty range following @a iter
   * does not have the tag applied to it.
   *
   * @param toggled_on <tt>true</tt> to get toggled-on tags.
   * @return Tags
   * toggled at this point.
   */
  auto get_toggled_tags(bool toggled_on =  true) const -> std::vector<Glib::RefPtr<const TextTag>>;


  /** Returns a list of tags that apply to @a iter, in ascending order of
   * priority (highest-priority tags are last).
   *
   * @return List of
   * `Gtk::TextTag`.
   */
  auto get_tags() const -> std::vector<Glib::RefPtr<const TextTag>>;


  /** Searches forward for @a str. Any match is returned by setting
   *  @a match_start to the first character of the match and @a match_end to the
   * first character after the match. The search will not continue past
   *  @a limit. Note that a search is a linear or O(n) operation, so you
   * may wish to use @a limit to avoid locking up your UI on large
   * buffers.
   *
   * If the Gtk::TextSearchFlags::VISIBLE_ONLY flag is present, the match may
   * have invisible text interspersed in @a str. i.e. @a str will be a
   * possibly-noncontiguous subsequence of the matched range. similarly,
   * if you specify Gtk::TextSearchFlags::TEXT_ONLY, the match may have
   * pixbufs or child widgets mixed inside the matched range. If these
   * flags are not given, the match must be exact; the special 0xFFFC
   * character in @a str will match embedded pixbufs or child widgets.
   *
   * @param str A search string.
   * @param flags Flags affecting how the search is done.
   * @param match_start Return location for start of match.
   * @param match_end Return location for end of match.
   * @param limit Bound for the search.
   * @return Whether a match was found.
   */
  auto forward_search(const Glib::ustring& str, TextSearchFlags flags, TextConstIter& match_start, TextConstIter& match_end, const TextIterBase& limit) const -> bool;

  /// A forward_search() convenience overload.
  auto forward_search(const Glib::ustring& str, TextSearchFlags flags, TextConstIter& match_start, TextConstIter& match_end) const -> bool;


  /** Same as forward_search(), but moves backward.
   *
   * @param str Search string.
   * @param flags Bitmask of flags affecting the search.
   * @param match_start Return location for start of match.
   * @param match_end Return location for end of match.
   * @param limit Location of last possible @a match_start.
   * @return Whether a match was found.
   */
  auto backward_search(const Glib::ustring& str, TextSearchFlags flags, TextConstIter& match_start, TextConstIter& match_end, const TextIterBase& limit) const -> bool;

  /// A backward_search() convenience overload.
  auto backward_search(const Glib::ustring& str, TextSearchFlags flags, TextConstIter& match_start, TextConstIter& match_end) const -> bool;


  /** Swaps the value of @a first and @a second if @a second comes before
   *  @a first in the buffer.
   *
   * That is, ensures that @a first and @a second are in sequence.
   * Most text buffer functions that take a range call this
   * automatically on your behalf, so there’s no real reason to
   * call it yourself in those cases. There are some exceptions,
   * such as in_range(), that expect a
   * pre-sorted range.
   *
   * @param second Another `Gtk::TextIter`.
   */
  void order(TextConstIter& second);


};

#ifndef DOXYGEN_SHOULD_SKIP_THIS

/**** Gtk::TextIterBase *******************************************************/

inline
auto TextIterBase::operator*() const -> TextIterBase::value_type
{
  return get_char();
}

inline
TextIterBase::operator bool() const
{
  return !is_end();
}

/**** Gtk::TextIter ***********************************************************/

inline
auto TextIter::operator++() -> TextIter&
{
  forward_char();
  return *this;
}

inline
auto TextIter::operator++(int) -> TextIter
{
  const TextIter temp(*this);
  forward_char();
  return temp;
}

inline
auto TextIter::operator--() -> TextIter&
{
  backward_char();
  return *this;
}

inline
auto TextIter::operator--(int) -> TextIter
{
  const TextIter temp(*this);
  backward_char();
  return temp;
}

/**** Gtk::TextConstIter ******************************************************/

TextConstIter::TextConstIter() noexcept
{
}

TextConstIter::TextConstIter(const TextIter& other) noexcept
: TextIterBase(other.gobj())
{
}

auto TextConstIter::operator=(const TextIter& other) noexcept -> TextConstIter&
{
  gobject_ = *other.gobj();
  return *this;
}

inline
auto TextConstIter::operator++() -> TextConstIter&
{
  forward_char();
  return *this;
}

inline
auto TextConstIter::operator++(int) -> TextConstIter
{
  const TextConstIter temp(*this);
  forward_char();
  return temp;
}

inline
auto TextConstIter::operator--() -> TextConstIter&
{
  backward_char();
  return *this;
}

inline
auto TextConstIter::operator--(int) -> TextConstIter
{
  const TextConstIter temp(*this);
  backward_char();
  return temp;
}

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

} // namespace Gtk

namespace Glib
{
// Can't have overloaded functions that differ only in return type.
// These can't be called Glib::wrap().

/** @relates Gtk::TextIter
 * @param object The C instance
 * @result A C++ instance that wraps this C instance.
 */
GTKMM_API
auto wrap_iter(GtkTextIter* object) -> Gtk::TextIter&;

/** @relates Gtk::TextIter
 * @param object The C instance
 * @result A C++ instance that wraps this C instance.
 */
GTKMM_API
auto wrap_iter(const GtkTextIter* object) -> const Gtk::TextIter&;

/** @relates Gtk::TextConstIter
 * @param object The C instance
 * @result A C++ instance that wraps this C instance.
 */
GTKMM_API
auto wrap_const_iter(GtkTextIter* object) -> Gtk::TextConstIter&;

/** @relates Gtk::TextConstIter
 * @param object The C instance
 * @result A C++ instance that wraps this C instance.
 */
GTKMM_API
auto wrap_const_iter(const GtkTextIter* object) -> const Gtk::TextConstIter&;

} // namespace Glib


namespace Gtk
{

/** @relates Gtk::TextIterBase
 * @param lhs The left-hand side
 * @param rhs The right-hand side
 * @result The result
 */
GTKMM_API
auto operator==(const TextIterBase& lhs, const TextIterBase& rhs) -> bool;

/** @relates Gtk::TextIterBase
 * @param lhs The left-hand side
 * @param rhs The right-hand side
 * @result The result
 */
GTKMM_API
auto operator!=(const TextIterBase& lhs, const TextIterBase& rhs) -> bool;

/** @relates Gtk::TextIterBase
 * @param lhs The left-hand side
 * @param rhs The right-hand side
 * @result The result
 */
GTKMM_API
auto operator<(const TextIterBase& lhs, const TextIterBase& rhs) -> bool;

/** @relates Gtk::TextIterBase
 * @param lhs The left-hand side
 * @param rhs The right-hand side
 * @result The result
 */
GTKMM_API
auto operator>(const TextIterBase& lhs, const TextIterBase& rhs) -> bool;

/** @relates Gtk::TextIterBase
 * @param lhs The left-hand side
 * @param rhs The right-hand side
 * @result The result
 */
GTKMM_API
auto operator<=(const TextIterBase& lhs, const TextIterBase& rhs) -> bool;

/** @relates Gtk::TextIterBase
 * @param lhs The left-hand side
 * @param rhs The right-hand side
 * @result The result
 */
GTKMM_API
auto operator>=(const TextIterBase& lhs, const TextIterBase& rhs) -> bool;


} // namespace Gtk


namespace Glib
{

/** @relates Gtk::TextIterBase
 * @param object The C instance
 * @result A C++ instance that wraps this C instance.
 */
GTKMM_API
auto wrap(GtkTextIter* object) -> Gtk::TextIterBase&;

/** @relates Gtk::TextIterBase
 * @param object The C instance
 * @result A C++ instance that wraps this C instance.
 */
GTKMM_API
auto wrap(const GtkTextIter* object) -> const Gtk::TextIterBase&;

#ifndef DOXYGEN_SHOULD_SKIP_THIS
template <>
class GTKMM_API Value<Gtk::TextIterBase> : public Glib::Value_Boxed<Gtk::TextIterBase>
{};
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

} // namespace Glib


#endif /* _GTKMM_TEXTITER_H */

