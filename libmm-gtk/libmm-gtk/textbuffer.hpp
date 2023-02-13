
#ifndef _GTKMM_TEXTBUFFER_H
#define _GTKMM_TEXTBUFFER_H

#include <libmm-gtk/mm-gtkconfig.hpp>


#include <libmm-glib/ustring.hpp>
#include <sigc++/sigc++.h>

/* Copyright(C) 1998-2002 The gtkmm Development Team
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


#include <vector>

#include <libmm-gdk/contentprovider.hpp>
#include <libmm-gtk/texttagtable.hpp>
#include <libmm-gtk/textchildanchor.hpp>
#include <libmm-gtk/textmark.hpp>
#include <libmm-gtk/textiter.hpp>
#include <libmm-gdk/clipboard.hpp>
#include <libmm-gdk/paintable.hpp>
#include <libmm-gtk/mm-gtkconfig.hpp>
#include <utility>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkTextBuffer = struct _GtkTextBuffer;
using GtkTextBufferClass = struct _GtkTextBufferClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{ class GTKMM_API TextBuffer_Class; } // namespace Gtk
#endif //DOXYGEN_SHOULD_SKIP_THIS

namespace Gtk
{

/** Multi-line attributed text that can be displayed by one or more Gtk::TextView widgets.
 *
 * Text in a buffer can be marked with tags. A @link Gtk::TextTag Gtk::TextBuffer::Tag@endlink is an attribute that can be applied to some range of text. For example, a tag
 * might be called "bold" and make the text inside the tag bold. However, the tag concept is more general than that; tags don't
 * have to affect appearance. They can instead affect the behavior of mouse and key presses, "lock" a range of text so the user
 * can't edit it, or countless other things. A tag is represented by a @link Gtk::TextTag Gtk::TextBuffer::Tag@endlink object.
 * One @link Gtk::TextTag Gtk::TextBuffer::Tag@endlink can be applied to any number of text ranges in any number of @link Gtk::TextBuffer Gtk::TextBuffers@endlink.
 *
 * Each tag is stored in a @link Gtk::TextTagTable Gtk::TextBuffer::TagTable@endlink. A tag table defines a set of tags that can be used together. Each buffer has one tag
 * table associated with it; only tags from that tag table can be used with the buffer. A single tag table can be shared between
 * multiple buffers, however.
 *
 * Most text manipulation is accomplished with iterators, represented by an @link Gtk::TextIter iterator@endlink
 * or a @link Gtk::ConstTextIter const_iterator@endlink. The iterator can
 * be used to navigate over characters, words, lines, and sentences.
 *
 * But iterators can't be used to preserve positions across buffer modifications. To preserve a position, the
 * @link Gtk::TextMark Gtk::TextBuffer::Mark@endlink object is ideal. There are two marks built-in to GtkTextBuffer; these are
 * named "insert" and "selection_bound" and refer to the insertion point and the boundary of the selection which is not the
 * insertion point. If no text is selected, these two marks will be in the same position. You can manipulate what is selected and
 * where the cursor appears by moving these marks around.
 *
 * Text buffers always contain at least one line, but may be empty (that is, buffers can contain zero characters). The last line
 * in the text buffer never ends in a line separator (such as newline); the other lines in the buffer always end in a line
 * separator. Line separators count as characters when computing character counts and character offsets. Note that some Unicode
 * line separators are represented with multiple bytes in UTF-8, and the two-character sequence "\r\n" is also considered a line
 * separator.
 *
 * @ingroup TextView
 */

class GTKMM_API TextBuffer : public Glib::Object
{

#ifndef DOXYGEN_SHOULD_SKIP_THIS

public:
  using CppObjectType = TextBuffer;
  using CppClassType = TextBuffer_Class;
  using BaseObjectType = GtkTextBuffer;
  using BaseClassType = GtkTextBufferClass;

  // noncopyable
  TextBuffer(const TextBuffer&) = delete;
  auto operator=(const TextBuffer&) -> TextBuffer& = delete;

private:  friend class TextBuffer_Class;
  static CppClassType textbuffer_class_;

protected:
  explicit TextBuffer(const Glib::ConstructParams& construct_params);
  explicit TextBuffer(GtkTextBuffer* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  TextBuffer(TextBuffer&& src) noexcept;
  auto operator=(TextBuffer&& src) noexcept -> TextBuffer&;

  ~TextBuffer() noexcept override;

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS


  static auto get_base_type() -> GType G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GObject.
  auto       gobj() -> GtkTextBuffer*       { return reinterpret_cast<GtkTextBuffer*>(gobject_); }

  ///Provides access to the underlying C GObject.
  auto gobj() const -> const GtkTextBuffer* { return reinterpret_cast<GtkTextBuffer*>(gobject_); }

  ///Provides access to the underlying C instance. The caller is responsible for unrefing it. Use when directly setting fields in structs.
  auto gobj_copy() -> GtkTextBuffer*;

private:


public:
  typedef TextIter iterator;
  typedef TextConstIter const_iterator;
  typedef TextTag Tag;
  typedef TextTagTable TagTable;
  typedef TextMark Mark;
  typedef TextChildAnchor ChildAnchor;

protected:
  TextBuffer();
  explicit TextBuffer(const Glib::RefPtr<TagTable>& tag_table);

public:

  static auto create() -> Glib::RefPtr<TextBuffer>;


  static auto create(const Glib::RefPtr<TagTable>& tag_table) -> Glib::RefPtr<TextBuffer>;


  /** Obtains the number of lines in the buffer.
   *
   * This value is cached, so the function is very fast.
   *
   * @return Number of lines in the buffer.
   */
  auto get_line_count() const -> int;

  /** Gets the number of characters in the buffer.
   *
   * Note that characters and bytes are not the same, you can’t e.g.
   * expect the contents of the buffer in string form to be this
   * many bytes long.
   *
   * The character count is cached, so this function is very fast.
   *
   * @return Number of characters in the buffer.
   */
  auto get_char_count() const -> int;

  /// See get_char_count().
  auto size() const -> int;


  /** Get the `Gtk::TextTagTable` associated with this buffer.
   *
   * @return The buffer’s tag table.
   */
  auto get_tag_table() -> Glib::RefPtr<TextBuffer::TagTable>;

  /** Get the `Gtk::TextTagTable` associated with this buffer.
   *
   * @return The buffer’s tag table.
   */
  auto get_tag_table() const -> Glib::RefPtr<const TextBuffer::TagTable>;

  /** Removes the current contents of the buffer, and inserts @a text instead.
   * @param text The text to put in the buffer.
   */
  void set_text(const Glib::ustring& text);

  /** Removes the current contents of the buffer, and inserts @a text instead.
   * @param text_begin The start of a UTF8 character array.
   * @param text_end The end of the UTF8 character array.
   */
  void set_text(const char* text_begin, const char* text_end);


  //TODO: Make all insert() methods have the same return type:

  /** Inserts @a text at position @a pos.
   * Emits the "insert_text" signal; insertion actually occurs in the default handler for the signal.
   * The @a pos iterator is invalidated when insertion occurs (because the buffer contents change).
   *
   * @param pos An iterator pointing to the position at which the text should be inserted.
   * @param text The text to be inserted in the buffer.
   * @result An iterator that points to the end of the inserted text.
   */
  auto insert(const iterator& pos, const Glib::ustring& text) -> iterator;

  /** Inserts text at position @a pos.
   * Emits the "insert_text" signal; insertion actually occurs in the default handler for the signal.
   * The @a pos iterator is invalidated when insertion occurs (because the buffer contents change).
   *
   * @param pos An iterator pointing to the position at which the text should be inserted.
   * @param text_begin The start of a UTF8 character array.
   * @param text_end The end of the UTF8 character array.
   * @result An iterator that points to the end of the inserted text.
   */
  auto insert(const iterator& pos, const char* text_begin, const char* text_end) -> iterator;

  /** Inserts @a text, using the current cursor position as the insertion point.
   * Emits the "insert_text" signal; insertion actually occurs in the default handler for the signal.
   *
   * @param text The text to be inserted in the buffer.
   */
  void insert_at_cursor(const Glib::ustring& text);

  /** Inserts text, using the current cursor position as the insertion point.
   * Emits the "insert_text" signal; insertion actually occurs in the default handler for the signal.
   *
   * @param text_begin The start of a UTF8 character array.
   * @param text_end The end of the UTF8 character array.
   */
  void insert_at_cursor(const char* text_begin, const char* text_end);

  /** Like insert(), but the insertion will not occur if @a iter is at a non-editable location in the buffer.
   * Usually you want to prevent insertions at ineditable locations if the insertion results from a user action (is interactive).
   *
   * @a default_editable indicates the editability of text that doesn't have a tag affecting editability applied to it.
   * Typically the result of Gtk::TextView::get_editable() is appropriate here.
   *
   * @param pos An iterator pointing to the position at which the text should be inserted.
   * @param text The text to be inserted in the buffer.
   * @param default_editable Default editability of buffer
   * @result Whether text was actually inserted
   */
  auto insert_interactive(
      const iterator& pos, const Glib::ustring& text, bool default_editable = true) -> std::pair<iterator,bool>;

  /** Like insert(), but the insertion will not occur if @a pos is at a non-editable location in the buffer.
   * Usually you want to prevent insertions at ineditable locations if the insertion results from a user action (is interactive).
   *
   * @a default_editable indicates the editability of text that doesn't have a tag affecting editability applied to it.
   * Typically the result of Gtk::TextView::get_editable() is appropriate here.
   *
   * @param pos An iterator pointing to the position at which the text should be inserted.
   * @param text_begin The start of a UTF8 character array.
   * @param text_end The end of the UTF8 character array.
   * @param default_editable Default editability of buffer.
   * @result Whether text was actually inserted
   */
  auto insert_interactive(
      const iterator& pos, const char* text_begin, const char* text_end, bool default_editable = true) -> std::pair<iterator,bool>;

  /** Calls insert_interactive() at the cursor position.
   *
   * @a default_editable indicates the editability of text that doesn't have a tag affecting editability applied to it.
   * Typically the result of Gtk::TextView::get_editable() is appropriate here.
   *
   * @param text The text to be inserted in the buffer.
   * @param default_editable Default editability of buffer
   * @result Whether text was actually inserted
   */
  auto insert_interactive_at_cursor(const Glib::ustring& text, bool default_editable = true) -> bool;

  /** Calls insert_interactive() at the cursor position.
   *
   * @a default_editable indicates the editability of text that doesn't have a tag affecting editability applied to it.
   * Typically the result of Gtk::TextView::get_editable() is appropriate here.
   *
   * @param text_begin The start of a UTF8 character array.
   * @param text_end The end of the UTF8 character array.
   * @param default_editable Default editability of buffer
   * @result Whether text was actually inserted
   */
  auto insert_interactive_at_cursor(const char* text_begin, const char* text_end,
                                    bool default_editable = true) -> bool;

  /** Copies text, tags, and paintable between @a range_begin and @a range_end (the order of range_begin and range_begin doesn't
   * matter) and inserts the copy at @a pos. Used instead of simply getting/inserting text because it preserves images and tags.
   * If range_begin and range_end are in a different buffer, the two buffers must share the same tag table.
   *
   * Implemented via emissions of the insert_text and apply_tag signals, so expect those.
   *
   * @param pos An iterator pointing to the position at which the text should be inserted.
   * @param range_begin A position in a buffer.
   * @param range_end Another position in the same buffer as @a range_begin.
   * @result Whether text was actually inserted
   */
  auto insert(const iterator& pos, const const_iterator& range_begin, const const_iterator& range_end) -> iterator;


  /** Same as insert_range(), but does nothing if the insertion point isn't editable.
   *
   * The @a default_editable parameter indicates whether the text is editable at @a pos if no tags enclosing @a pos affect editability.
   * Typically the result of Gtk::TextView::get_editable() is appropriate here.
   *
   * @param pos An iterator pointing to the position at which the text should be inserted.
   * @param range_begin A position in a buffer.
   * @param range_end Another position in the same buffer as @a range_begin.
   * @param default_editable Default editability of buffer.
   * @result Whether text was actually inserted
   */
  auto insert_interactive(const iterator& pos, const const_iterator& range_begin, const const_iterator& range_end, bool default_editable = true) -> std::pair<iterator,bool>;


  auto insert_with_tag(const iterator& pos, const Glib::ustring& text, const Glib::RefPtr<Tag>& tag) -> iterator;
  auto insert_with_tag(const iterator& pos, const char* text_begin, const char* text_end, const Glib::RefPtr<Tag>& tag) -> iterator;

  auto insert_with_tag(const iterator& pos, const Glib::ustring& text, const Glib::ustring& tag_name) -> iterator;
  auto insert_with_tag(const iterator& pos, const char* text_begin, const char* text_end, const Glib::ustring& tag_name) -> iterator;

  /** Inserts text into buffer at @a pos, applying the list of tags to the newly-inserted text.
   * Equivalent to calling insert(), then apply_tag() on the inserted text; This is just a convenience function.
   *
   * @param pos An iterator pointing to the position at which the text should be inserted.
   * @param text The text to be inserted in the buffer.
   * @param tags A standard C++ container of @link Gtk::TextTag Gtk::TextBuffer::Tags@endlink.
   * @result Whether text was actually inserted
   */
  auto insert_with_tags(const iterator& pos, const Glib::ustring& text,
                            const std::vector< Glib::RefPtr<Tag> >& tags) -> iterator;

  /** Inserts text into buffer at @a pos, applying the list of tags to the newly-inserted text.
   * Equivalent to calling insert(), then apply_tag() on the inserted text; This is just a convenience function.
   *
   * @param pos An iterator pointing to the position at which the text should be inserted.
   * @param text_begin The start of a UTF8 character array.
   * @param text_end The end of the UTF8 character array.
   * @param tags A standard C++ container of @link Gtk::TextTag Gtk::TextBuffer::Tags@endlink.
   * @result Whether text was actually inserted
   */
  auto insert_with_tags(const iterator& pos, const char* text_begin, const char* text_end,
                            const std::vector< Glib::RefPtr<Tag> >& tags) -> iterator;

  /** Inserts text into buffer at @a pos, applying the list of tags to the newly-inserted text.
   * Equivalent to calling insert(), then apply_tag() on the inserted text; This is just a convenience function.
   *
   * @param pos An iterator pointing to the position at which the text should be inserted.
   * @param text The text to be inserted in the buffer.
   * @param tag_names A standard C++ container of tag names.
   * @result Whether text was actually inserted
   */
  auto insert_with_tags_by_name(const iterator& pos, const Glib::ustring& text,
                                    const std::vector<Glib::ustring>& tag_names) -> iterator;


  /** Equivalent to calling insert(), then apply_tag() on the inserted text; This is just a convenience function.
   *
   * @param pos An iterator pointing to the position at which the text should be inserted.
   * @param text_begin The start of a UTF8 character array.
   * @param text_end The end of the UTF8 character array.
   * @param tag_names A standard C++ container of tag names.
   * @result Whether text was actually inserted
   */
  auto insert_with_tags_by_name(const iterator& pos, const char* text_begin, const char* text_end,
                                    const std::vector<Glib::ustring>& tag_names) -> iterator;

  /** Inserts text in @a markup at position @a pos.
   * Emits the "insert_text" signal, possibly multiple times; insertion actually occurs in the
   * default handler for the signal. The @a pos iterator will point to the end of the
   * inserted text on return.
   *
   * @param pos Location to insert the markup.
   * @param markup The text containing pango markup to be inserted in the buffer.
   * @result An iterator that points to the end of the inserted markup text.
   */
  auto insert_markup(const iterator& pos, const Glib::ustring& markup) -> iterator;

  /** Inserts markup text at position @a pos.
   * Emits the "insert_text" signal; insertion actually occurs in the default handler for the signal.
   * The @a pos iterator will point to the end of the inserted text on return.
   *
   * @param pos Location to insert the markup.
   * @param markup_begin The start of a UTF8 character array containing pango markup.
   * @param markup_end The end of the UTF8 character array containing pango markup.
   * @result An iterator that points to the end of the inserted markup text.
   */
  auto insert_markup(const iterator& pos, const char* markup_begin, const char* markup_end) -> iterator;

  /* Deletes all text between @a range_begin and @a range_end. The order of range_begin and range_end is not actually relevant.
   * This function actually emits the "delete_range" signal, and the default handler of that signal deletes the text.
   * Because the buffer is modified, all outstanding iterators become invalid after calling this function.
   * @param range_begin
   * @param range_end
   * @result An iterator that points to the location where text was deleted.
   */
  auto erase(const iterator& range_begin, const iterator& range_end) -> iterator;


   /* Deletes all editable text between @a range_begin and @a range_end. The order of range_begin and range_end is not actually relevant.
   * This function actually emits the "delete_range" signal, and the default handler of that signal deletes the text.
   * Because the buffer is modified, all outstanding iterators become invalid after calling this function.
   *
   * @a default_editable indicates the editability of text that doesn't have a tag affecting editability applied to it.
   * Typically the result of Gtk::TextView::get_editable() is appropriate here.
   *
   * @param range_begin
   * @param range_end
   * @param default_editable Default editability of buffer
   * @result An iterator that points to the location where text was deleted, or end() is no text was deleted.
   */
  auto erase_interactive(const iterator& range_begin, const iterator& range_end, bool default_editable = true) -> std::pair<iterator,bool>;


  /** Performs the appropriate action as if the user hit the delete
   * key with the cursor at the position specified by @a iter. In the
   * normal case a single character will be deleted, but when
   * combining accents are involved, more than one character can
   * be deleted, and when precomposed character and accent combinations
   * are involved, less than one character will be deleted.
   *
   * Because the buffer is modified, all outstanding iterators become
   * invalid after calling this method; however, this method returns
   * a valid iterator that points to the location where text was deleted.
   *
   * @param iter A position in the buffer.
   * @param interactive Whether the deletion is caused by user interaction.
   * @param default_editable Whether the buffer is editable by default.
   * @result An iterator to the location where text was deleted, if the buffer was modified.
   *
   * @newin{2,6}
   */
  auto backspace(const iterator& iter, bool interactive = true, bool default_editable = true) -> iterator;


  /** Returns the text in the range [ @a range_start, @a range_end).
   *
   * Excludes undisplayed text (text marked with tags that set the
   * invisibility attribute) if @a include_hidden_chars is <tt>false</tt>.
   * Does not include characters representing embedded images, so
   * byte and character indexes into the returned string do not
   * correspond to byte and character indexes into the buffer.
   * Contrast with get_slice().
   *
   * @param range_start Start of a range.
   * @param range_end End of a range.
   * @param include_hidden_chars Whether to include invisible text.
   * @return An allocated UTF-8 string.
   */
  auto get_text(const const_iterator& range_start, const const_iterator& range_end, bool include_hidden_chars =  true) const -> Glib::ustring;

  /** Returns all the text in the buffer. Excludes undisplayed
   * text (text marked with tags that set the invisibility attribute) if
   *  @a include_hidden_chars  is <tt>false</tt>. Does not include characters
   * representing embedded images, so byte and character indexes into
   * the returned string do <em>not</em> correspond to byte
   * and character indexes into the buffer. Contrast with
   * get_slice().
   *
   * @param include_hidden_chars Whether to include invisible text.
   * @return An allocated UTF-8 string.
   */
  auto get_text(bool include_hidden_chars = true) const -> Glib::ustring;


  /** Returns the text in the range [ @a range_start, @a range_end).
   *
   * Excludes undisplayed text (text marked with tags that set the
   * invisibility attribute) if @a include_hidden_chars is <tt>false</tt>.
   * The returned string includes a 0xFFFC character whenever the
   * buffer contains embedded images, so byte and character indexes
   * into the returned string do correspond to byte and character
   * indexes into the buffer. Contrast with get_text().
   * Note that 0xFFFC can occur in normal text as well, so it is not a
   * reliable indicator that a paintable or widget is in the buffer.
   *
   * @param range_start Start of a range.
   * @param range_end End of a range.
   * @param include_hidden_chars Whether to include invisible text.
   * @return An allocated UTF-8 string.
   */
  auto get_slice(const const_iterator& range_start, const const_iterator& range_end, bool include_hidden_chars =  true) const -> Glib::ustring;

  auto insert_paintable(const iterator& pos, const Glib::RefPtr<Gdk::Paintable>& paintable) -> iterator;


  auto insert_child_anchor(const iterator& pos, const Glib::RefPtr<ChildAnchor>& anchor) -> iterator;


  auto create_child_anchor(const iterator& pos) -> Glib::RefPtr<ChildAnchor>;


  /** Adds the mark at position @a where.
   *
   * The mark must not be added to another buffer, and if its name
   * is not <tt>nullptr</tt> then there must not be another mark in the buffer
   * with the same name.
   *
   * Emits the signal_mark_set() signal as notification
   * of the mark's initial placement.
   *
   * @param mark The mark to add.
   * @param where Location to place mark.
   */
  void add_mark(const Glib::RefPtr<TextBuffer::Mark>& mark, const iterator& where);


  /** Creates a mark at position @a where. The mark can be retrieved by name using
   * get_mark(). If a mark has left gravity, and text is
   * inserted at the mark's current location, the mark will be moved to
   * the left of the newly-inserted text. If the mark has right gravity
   * ( @a left_gravity = <tt>false</tt>), the mark will end up on the right of
   * newly-inserted text. The standard left-to-right cursor is a mark
   * with right gravity (when you type, the cursor stays on the right
   * side of the text you're typing).
   *
   * Emits the "mark_set" signal as notification of the mark's initial
   * placement.
   *
   * @param mark_name Name for mark.
   * @param where Location to place mark.
   * @param left_gravity Whether the mark has left gravity.
   * @return The new `Gtk::TextMark` object.
   */
  auto create_mark(const Glib::ustring& mark_name, const iterator& where, bool left_gravity =  true) -> Glib::RefPtr<TextBuffer::Mark>;

  /** Create an anonymous mark. */
  /** Creates an anonymous mark at position @a where.
   *
   * If a mark has left gravity, and text is
   * inserted at the mark's current location, the mark will be moved to
   * the left of the newly-inserted text. If the mark has right gravity
   * ( @a left_gravity  = <tt>false</tt>), the mark will end up on the right of
   * newly-inserted text. The standard left-to-right cursor is a mark
   * with right gravity (when you type, the cursor stays on the right
   * side of the text you're typing).
   *
   * Emits the "mark_set" signal as notification of the mark's initial
   * placement.
   * @param where Location to place mark.
   * @param left_gravity Whether the mark has left gravity.
   * @return The new Gtk::TextMark object.
   */
  auto create_mark(const iterator& where, bool left_gravity = true) -> Glib::RefPtr<Mark>;


  /** Moves @a mark to the new location @a where.
   *
   * Emits the signal_mark_set() signal
   * as notification of the move.
   *
   * @param mark A `Gtk::TextMark`.
   * @param where New location for @a mark in @a buffer.
   */
  void move_mark(const Glib::RefPtr<Mark>& mark, const iterator& where);

  /** Deletes @a mark, so that it's no longer located anywhere in the
   * buffer. Removes the reference the buffer holds to the mark, so if
   * you don't keep a Glib::RefPtr to the mark, it will be freed. Even
   * if the mark isn't freed, most operations on @a mark become
   * invalid. There is no way to undelete a
   * mark. Gtk::TextMark::get_deleted() will return <tt>true</tt> after this
   * function has been called on a mark; Gtk::TextMark::get_deleted()
   * indicates that a mark no longer belongs to a buffer. The "mark_deleted"
   * signal will be emitted as notification after the mark is deleted.
   *
   * @param mark A `Gtk::TextMark` in @a buffer.
   */
  void delete_mark(const Glib::RefPtr<Mark>& mark);


  /** Returns the mark named @a name in buffer @a buffer, or <tt>nullptr</tt> if no such
   * mark exists in the buffer.
   *
   * @param name A mark name.
   * @return A `Gtk::TextMark`.
   */
  auto get_mark(const Glib::ustring& name) -> Glib::RefPtr<TextBuffer::Mark>;

  /** Returns the mark named @a name in buffer @a buffer, or <tt>nullptr</tt> if no such
   * mark exists in the buffer.
   *
   * @param name A mark name.
   * @return A `Gtk::TextMark`.
   */
  auto get_mark(const Glib::ustring& name) const -> Glib::RefPtr<const TextBuffer::Mark>;


  /** Moves the mark named @a name (which must exist) to location @a where.
   *
   * See move_mark() for details.
   *
   * @param name Name of a mark.
   * @param where New location for mark.
   */
  void move_mark_by_name(const Glib::ustring& name, const iterator& where);

  /** Deletes the mark named @a name; the mark must exist.
   *
   * See delete_mark() for details.
   *
   * @param name Name of a mark in @a buffer.
   */
  void delete_mark_by_name(const Glib::ustring& name);


  /** Returns the mark that represents the cursor (insertion point).
   *
   * Equivalent to calling get_mark()
   * to get the mark named “insert”, but very slightly more
   * efficient, and involves less typing.
   *
   * @return Insertion point mark.
   */
  auto get_insert() -> Glib::RefPtr<TextBuffer::Mark>;

  /** Returns the mark that represents the selection bound.
   *
   * Equivalent to calling get_mark()
   * to get the mark named “selection_bound”, but very slightly
   * more efficient, and involves less typing.
   *
   * The currently-selected text in @a buffer is the region between the
   * “selection_bound” and “insert” marks. If “selection_bound” and
   * “insert” are in the same place, then there is no current selection.
   * get_selection_bounds() is another convenient
   * function for handling the selection, if you just want to know whether
   * there’s a selection and what its bounds are.
   *
   * @return Selection bound mark.
   */
  auto get_selection_bound() -> Glib::RefPtr<TextBuffer::Mark>;


  /** This function moves the “insert” and “selection_bound” marks
   * simultaneously.
   *
   * If you move them to the same place in two steps with
   * move_mark(), you will temporarily select a
   * region in between their old and new locations, which can be pretty
   * inefficient since the temporarily-selected region will force stuff
   * to be recalculated. This function moves them as a unit, which can
   * be optimized.
   *
   * @param where Where to put the cursor.
   */
  void place_cursor(const iterator& where);

  /** Emits the “apply-tag” signal on @a buffer.
   *
   * The default handler for the signal applies
   *  @a tag to the given range. @a range_start and @a range_end do
   * not have to be in order.
   *
   * @param tag A `Gtk::TextTag`.
   * @param range_start One bound of range to be tagged.
   * @param range_end Other bound of range to be tagged.
   */
  void apply_tag(const Glib::RefPtr<Tag>& tag, const iterator& range_start, const iterator& range_end);

  /** Emits the “remove-tag” signal.
   *
   * The default handler for the signal removes all occurrences
   * of @a tag from the given range. @a range_start and @a range_end don’t have
   * to be in order.
   *
   * @param tag A `Gtk::TextTag`.
   * @param range_start One bound of range to be untagged.
   * @param range_end Other bound of range to be untagged.
   */
  void remove_tag(const Glib::RefPtr<Tag>& tag, const iterator& range_start, const iterator& range_end);

  /** Emits the “apply-tag” signal on @a buffer.
   *
   * Calls Gtk::TextTagTable::lookup() on the buffer’s
   * tag table to get a `Gtk::TextTag`, then calls
   * apply_tag().
   *
   * @param name Name of a named `Gtk::TextTag`.
   * @param range_start One bound of range to be tagged.
   * @param range_end Other bound of range to be tagged.
   */
  void apply_tag_by_name(const Glib::ustring& name, const iterator& range_start, const iterator& range_end);

  /** Emits the “remove-tag” signal.
   *
   * Calls Gtk::TextTagTable::lookup() on the buffer’s
   * tag table to get a `Gtk::TextTag`, then calls
   * remove_tag().
   *
   * @param name Name of a `Gtk::TextTag`.
   * @param range_start One bound of range to be untagged.
   * @param range_end Other bound of range to be untagged.
   */
  void remove_tag_by_name(const Glib::ustring& name, const iterator& range_start, const iterator& range_end);

  /** Removes all tags in the range between @a range_start and @a range_end.
   *
   * Be careful with this function; it could remove tags added in code
   * unrelated to the code you’re currently writing. That is, using this
   * function is probably a bad idea if you have two or more unrelated
   * code sections that add tags.
   *
   * @param range_start One bound of range to be untagged.
   * @param range_end Other bound of range to be untagged.
   */
  void remove_all_tags(const iterator& range_start, const iterator& range_end);

  /** Creates a tag and adds it to the tag table for buffer. Equivalent to calling Gtk::TextBuffer::Tag::create() and then adding
   * the tag to the buffer's tag table.
   * A tag called @a tag_name must not already exist in the tag table for this buffer.
   *
   * @param tag_name The name for the new tag.
   * @result The new tag.
   */
  auto create_tag(const Glib::ustring& tag_name) -> Glib::RefPtr<Tag>;


  /** Creates an anoymous tag and adds it to the tag table for buffer. Equivalent to calling Gtk::TextBuffer::Tag::create() and then adding
   * the tag to the buffer's tag table.
   *
   * @result The new tag.
   */
  auto create_tag() -> Glib::RefPtr<Tag>;

  auto get_iter_at_line_offset(int line_number, int char_offset) -> iterator;
  auto get_iter_at_line_offset(int line_number, int char_offset) const -> const_iterator;
  auto get_iter_at_line_index(int line_number, int byte_index) -> iterator;
  auto get_iter_at_line_index(int line_number, int byte_index) const -> const_iterator;
  auto get_iter_at_offset(int char_offset) -> iterator;
  auto get_iter_at_offset(int char_offset) const -> const_iterator;
  auto get_iter_at_line(int line_number) -> iterator;
  auto get_iter_at_line(int line_number) const -> const_iterator;
  auto begin() -> iterator;
  auto begin() const -> const_iterator;
  auto end() -> iterator;
  auto end() const -> const_iterator;
  void get_bounds(iterator& range_begin, iterator& range_end);
  void get_bounds(const_iterator& range_begin, const_iterator& range_end) const;

  /** Get the current position of a mark.
   * @param mark The @link Gtk::TextMark Gtk::TextBuffer::Mark@endlink
   * @result An iterator that points to the position of the @a mark.
   */
  auto get_iter_at_mark(const Glib::RefPtr<Mark>& mark) -> iterator;

  /** Get the current position of a mark.
   * @param mark The @link Gtk::TextMark Gtk::TextBuffer::Mark@endlink
   * @result An iterator that points to the position of the @a mark.
   */
  auto get_iter_at_mark(const Glib::RefPtr<Mark>& mark) const -> const_iterator;

  /** Get the current position of an anchor.
   * @param anchor A @link Gtk::TextChildAnchor Gtk::TextBuffer::Anchor@endlink that appears in the buffer.
   * @result An iterator that points to the position of the @a anchor.
   */
  auto get_iter_at_child_anchor(const Glib::RefPtr<ChildAnchor>& anchor) -> iterator;

  /** Get the current position of an anchor.
   * @param anchor A @link Gtk::TextChildAnchor Gtk::TextBuffer::Anchor@endlink that appears in the buffer.
   * @result An iterator that points to the position of the @a anchor.
   */
  auto get_iter_at_child_anchor(const Glib::RefPtr<ChildAnchor>& anchor) const -> const_iterator;


  /** Indicates whether the buffer has been modified since the last call
   * to set_modified() set the modification flag to
   * <tt>false</tt>.
   *
   * Used for example to enable a “save” function in a text editor.
   *
   * @return <tt>true</tt> if the buffer has been modified.
   */
  auto get_modified() const -> bool;

  /** Used to keep track of whether the buffer has been
   * modified since the last time it was saved.
   *
   * Whenever the buffer is saved to disk, call
   * `gtk_text_buffer_set_modified ( @a buffer, <tt>false</tt>)`.
   * When the buffer is modified, it will automatically
   * toggled on the modified bit again. When the modified
   * bit flips, the buffer emits the
   * signal_modified_changed() signal.
   *
   * @param setting Modification flag setting.
   */
  void set_modified(bool setting =  true);


  /** Indicates whether the buffer has some text currently selected.
   *
   * @return <tt>true</tt> if the there is text selected.
   */
  auto get_has_selection() const -> bool;


  /** Adds @a clipboard to the list of clipboards in which the selection
   * contents of @a buffer are available.
   *
   * In most cases, @a clipboard will be the `Gdk::Clipboard` returned by
   * Gtk::Widget::get_primary_clipboard() for a view of @a buffer.
   *
   * @param clipboard A `Gdk::Clipboard`.
   */
  void add_selection_clipboard(const Glib::RefPtr<Gdk::Clipboard>& clipboard);

  /** Removes a `Gdk::Clipboard` added with
   * add_selection_clipboard().
   *
   * @param clipboard A `Gdk::Clipboard` added to @a buffer by
   * add_selection_clipboard().
   */
  void remove_selection_clipboard(const Glib::RefPtr<Gdk::Clipboard>& clipboard);

  /** Copies the currently-selected text to a clipboard,
   * then deletes said text if it’s editable.
   *
   * @param clipboard The `Gdk::Clipboard` object to cut to.
   * @param default_editable Default editability of the buffer.
   */
  void cut_clipboard(const Glib::RefPtr<Gdk::Clipboard>& clipboard, bool default_editable =  true);

  /** Copies the currently-selected text to a clipboard.
   *
   * @param clipboard The `Gdk::Clipboard` object to copy to.
   */
  void copy_clipboard(const Glib::RefPtr<Gdk::Clipboard>& clipboard);

  /** Pastes the contents of a clipboard.
   *
   * If @a override_location is <tt>nullptr</tt>, the pasted text will be inserted
   * at the cursor position, or the buffer selection will be replaced
   * if the selection is non-empty.
   *
   * @note pasting is asynchronous, that is, we’ll ask for the paste data
   * and return, and at some point later after the main loop runs, the paste
   * data will be inserted.
   *
   * @param clipboard The `Gdk::Clipboard` to paste from.
   * @param override_location Location to insert pasted text.
   * @param default_editable Whether the buffer is editable by default.
   */
  void paste_clipboard(const Glib::RefPtr<Gdk::Clipboard>& clipboard, const iterator& override_location, bool default_editable =  true);

  /// A paste_clipboard() convenience overload.
  void paste_clipboard(const Glib::RefPtr<Gdk::Clipboard>& clipboard, bool default_editable =  true);


  /** Returns <tt>true</tt> if some text is selected; places the bounds
   * of the selection in @a range_start and @a range_end.
   *
   * If the selection has length 0, then @a range_start and @a range_end are filled
   * in with the same value. @a range_start and @a range_end will be in ascending order.
   * If @a range_start and @a range_end are <tt>nullptr</tt>, then they are not filled in, but the
   * return value still indicates whether text is selected.
   *
   * @param range_start Iterator to initialize with selection start.
   * @param range_end Iterator to initialize with selection end.
   * @return Whether the selection has nonzero length.
   */
  auto get_selection_bounds(iterator& range_start, iterator& range_end) -> bool;

  /** Returns <tt>true</tt> if some text is selected; places the bounds
   * of the selection in @a range_start and @a range_end.
   *
   * If the selection has length 0, then @a range_start and @a range_end are filled
   * in with the same value. @a range_start and @a range_end will be in ascending order.
   * If @a range_start and @a range_end are <tt>nullptr</tt>, then they are not filled in, but the
   * return value still indicates whether text is selected.
   *
   * @param range_start Iterator to initialize with selection start.
   * @param range_end Iterator to initialize with selection end.
   * @return Whether the selection has nonzero length.
   */
  auto get_selection_bounds(const_iterator& range_start, const_iterator& range_end) const -> bool;

  /** Deletes the range between the “insert” and “selection_bound” marks,
   * that is, the currently-selected text.
   *
   * If @a interactive is <tt>true</tt>, the editability of the selection will be
   * considered (users can’t delete uneditable text).
   *
   * @param interactive Whether the deletion is caused by user interaction.
   * @param default_editable Whether the buffer is editable by default.
   * @return Whether there was a non-empty selection to delete.
   */
  auto erase_selection(bool interactive =  true, bool default_editable =  true) -> bool;

  // gtk_text_buffer_get_selection_content() gives us a ref. Don't add refreturn.

  /** Get a content provider for this buffer.
   *
   * It can be used to make the content of @a buffer available
   * in a `Gdk::Clipboard`, see Gdk::Clipboard::set_content().
   *
   * @return A new `Gdk::ContentProvider`.
   */
  auto get_selection_content() -> Glib::RefPtr<Gdk::ContentProvider>;


  /** This function moves the “insert” and “selection_bound” marks
   * simultaneously.
   *
   * If you move them in two steps with
   * move_mark(), you will temporarily select a
   * region in between their old and new locations, which can be pretty
   * inefficient since the temporarily-selected region will force stuff
   * to be recalculated. This function moves them as a unit, which can
   * be optimized.
   *
   * @param ins Where to put the “insert” mark.
   * @param bound Where to put the “selection_bound” mark.
   */
  void select_range(const iterator& ins, const iterator& bound);


  /** Gets whether there is an undoable action in the history.
   *
   * @return <tt>true</tt> if there is an undoable action.
   */
  auto get_can_undo() const -> bool;

  /** Gets whether there is a redoable action in the history.
   *
   * @return <tt>true</tt> if there is an redoable action.
   */
  auto get_can_redo() const -> bool;

  /** Gets whether the buffer is saving modifications to the buffer
   * to allow for undo and redo actions.
   *
   * See begin_irreversible_action() and
   * end_irreversible_action() to create
   * changes to the buffer that cannot be undone.
   */
  auto get_enable_undo() const -> bool;

  /** Sets whether or not to enable undoable actions in the text buffer.
   *
   * Undoable actions in this context are changes to the text content of
   * the buffer. Changes to tags and marks are not tracked.
   *
   * If enabled, the user will be able to undo the last number of actions
   * up to get_max_undo_levels().
   *
   * See begin_irreversible_action() and
   * end_irreversible_action() to create
   * changes to the buffer that cannot be undone.
   *
   * @param enable_undo <tt>true</tt> to enable undo.
   */
  void set_enable_undo(bool enable_undo =  true);

  /** Gets the maximum number of undo levels to perform.
   *
   * If 0, unlimited undo actions may be performed. Note that this may
   * have a memory usage impact as it requires storing an additional
   * copy of the inserted or removed text within the text buffer.
   */
  auto get_max_undo_levels() const -> guint;

  /** Sets the maximum number of undo levels to perform.
   *
   * If 0, unlimited undo actions may be performed. Note that this may
   * have a memory usage impact as it requires storing an additional
   * copy of the inserted or removed text within the text buffer.
   *
   * @param max_undo_levels The maximum number of undo actions to perform.
   */
  void set_max_undo_levels(guint max_undo_levels);

  /** Undoes the last undoable action on the buffer, if there is one.
   */
  void undo();

  /** Redoes the next redoable action on the buffer, if there is one.
   */
  void redo();

  /** Denotes the beginning of an action that may not be undone.
   *
   * This will cause any previous operations in the undo/redo queue
   * to be cleared.
   *
   * This should be paired with a call to
   * end_irreversible_action() after the irreversible
   * action has completed.
   *
   * You may nest calls to begin_irreversible_action()
   * and end_irreversible_action() pairs.
   */
  void begin_irreversible_action();

  /** Denotes the end of an action that may not be undone.
   *
   * This will cause any previous operations in the undo/redo
   * queue to be cleared.
   *
   * This should be called after completing modifications to the
   * text buffer after begin_irreversible_action()
   * was called.
   *
   * You may nest calls to begin_irreversible_action()
   * and end_irreversible_action() pairs.
   */
  void end_irreversible_action();

  /** Called to indicate that the buffer operations between here and a
   * call to end_user_action() are part of a single
   * user-visible operation.
   *
   * The operations between begin_user_action() and
   * end_user_action() can then be grouped when creating
   * an undo stack. `Gtk::TextBuffer` maintains a count of calls to
   * begin_user_action() that have not been closed with
   * a call to end_user_action(), and emits the
   * “begin-user-action” and “end-user-action” signals only for the
   * outermost pair of calls. This allows you to build user actions
   * from other user actions.
   *
   * The “interactive” buffer mutation functions, such as
   * insert_interactive(), automatically call
   * begin/end user action around the buffer operations they perform,
   * so there's no need to add extra calls if you user action consists
   * solely of a single call to one of those functions.
   */
  void begin_user_action();

  /** Ends a user-visible operation.
   *
   * Should be paired with a call to
   * begin_user_action().
   * See that function for a full explanation.
   */
  void end_user_action();


  /**
   * @par Slot Prototype:
   * <tt>void on_my_%insert(TextBuffer::iterator& pos, const Glib::ustring& text, int bytes)</tt>
   *
   * Flags: Run Last
   *
   * Emitted to insert text in a `Gtk::TextBuffer`.
   *
   * Insertion actually occurs in the default handler.
   *
   * Note that if your handler runs before the default handler
   * it must not invalidate the @a pos iter (or has to
   * revalidate it). The default signal handler revalidates
   * it to point to the end of the inserted text.
   *
   * See also: Gtk::TextBuffer::insert(),
   * Gtk::TextBuffer::insert_range().
   *
   * @param pos Position to insert @a text in @a textbuffer.
   * @param text The UTF-8 text to be inserted.
   * @param bytes Length of the inserted text in bytes.
   */

  auto signal_insert() -> Glib::SignalProxy<void(TextBuffer::iterator&, const Glib::ustring&, int)>;


  /**
   * @par Slot Prototype:
   * <tt>void on_my_%insert_paintable(TextBuffer::iterator& pos, const Glib::RefPtr<Gdk::Paintable>& paintable)</tt>
   *
   * Flags: Run Last
   *
   * Emitted to insert a `Gdk::Paintable` in a `Gtk::TextBuffer`.
   *
   * Insertion actually occurs in the default handler.
   *
   * Note that if your handler runs before the default handler
   * it must not invalidate the @a pos iter (or has to
   * revalidate it). The default signal handler revalidates
   * it to be placed after the inserted @a paintable.
   *
   * See also: Gtk::TextBuffer::insert_paintable().
   *
   * @param pos Position to insert @a paintable in @a textbuffer.
   * @param paintable The `Gdk::Paintable` to be inserted.
   */

  auto signal_insert_paintable() -> Glib::SignalProxy<void(TextBuffer::iterator&, const Glib::RefPtr<Gdk::Paintable>&)>;


  /**
   * @par Slot Prototype:
   * <tt>void on_my_%insert_child_anchor(TextBuffer::iterator& pos, const Glib::RefPtr<ChildAnchor>& anchor)</tt>
   *
   * Flags: Run Last
   *
   * Emitted to insert a `Gtk::TextChildAnchor` in a `Gtk::TextBuffer`.
   *
   * Insertion actually occurs in the default handler.
   *
   * Note that if your handler runs before the default handler
   * it must not invalidate the @a pos iter (or has to
   * revalidate it). The default signal handler revalidates
   * it to be placed after the inserted @a anchor.
   *
   * See also: Gtk::TextBuffer::insert_child_anchor().
   *
   * @param pos Position to insert @a anchor in @a textbuffer.
   * @param anchor The `Gtk::TextChildAnchor` to be inserted.
   */

  auto signal_insert_child_anchor() -> Glib::SignalProxy<void(TextBuffer::iterator&, const Glib::RefPtr<ChildAnchor>&)>;


  /**
   * @par Slot Prototype:
   * <tt>void on_my_%erase(TextBuffer::iterator& range_start, TextBuffer::iterator& range_end)</tt>
   *
   * Flags: Run Last
   *
   * Emitted to delete a range from a `Gtk::TextBuffer`.
   *
   * Note that if your handler runs before the default handler
   * it must not invalidate the @a range_start and @a range_end iters (or has
   * to revalidate them). The default signal handler revalidates
   * the @a range_start and @a range_end iters to both point to the location
   * where text was deleted. Handlers which run after the default
   * handler (see Glib::signal_connect_after()) do not have access to
   * the deleted text.
   *
   * See also: Gtk::TextBuffer::delete().
   *
   * @param range_start The start of the range to be deleted.
   * @param range_end The end of the range to be deleted.
   */

  auto signal_erase() -> Glib::SignalProxy<void(TextBuffer::iterator&, TextBuffer::iterator&)>;


  /**
   * @par Slot Prototype:
   * <tt>void on_my_%changed()</tt>
   *
   * Flags: Run Last
   *
   * Emitted when the content of a `Gtk::TextBuffer` has changed.
   */

  auto signal_changed() -> Glib::SignalProxy<void()>;


  /**
   * @par Slot Prototype:
   * <tt>void on_my_%modified_changed()</tt>
   *
   * Flags: Run Last
   *
   * Emitted when the modified bit of a `Gtk::TextBuffer` flips.
   *
   * See also: Gtk::TextBuffer::set_modified().
   */

  auto signal_modified_changed() -> Glib::SignalProxy<void()>;


  /**
   * @par Slot Prototype:
   * <tt>void on_my_%mark_set(const TextBuffer::iterator& location, const Glib::RefPtr<TextBuffer::Mark>& mark)</tt>
   *
   * Flags: Run Last
   *
   * Emitted as notification after a `Gtk::TextMark` is set.
   *
   * See also:
   * Gtk::TextBuffer::create_mark(),
   * Gtk::TextBuffer::move_mark().
   *
   * @param location The location of @a mark in @a textbuffer.
   * @param mark The mark that is set.
   */

  auto signal_mark_set() -> Glib::SignalProxy<void(const TextBuffer::iterator&, const Glib::RefPtr<TextBuffer::Mark>&)>;


  /**
   * @par Slot Prototype:
   * <tt>void on_my_%mark_deleted(const Glib::RefPtr<TextBuffer::Mark>& mark)</tt>
   *
   * Flags: Run Last
   *
   * Emitted as notification after a `Gtk::TextMark` is deleted.
   *
   * See also: Gtk::TextBuffer::delete_mark().
   *
   * @param mark The mark that was deleted.
   */

  auto signal_mark_deleted() -> Glib::SignalProxy<void(const Glib::RefPtr<TextBuffer::Mark>&)>;


  /**
   * @par Slot Prototype:
   * <tt>void on_my_%apply_tag(const Glib::RefPtr<TextBuffer::Tag>& tag, const TextBuffer::iterator& range_begin, const TextBuffer::iterator& range_end)</tt>
   *
   * Flags: Run Last
   *
   * Emitted to apply a tag to a range of text in a `Gtk::TextBuffer`.
   *
   * Applying actually occurs in the default handler.
   *
   * Note that if your handler runs before the default handler
   * it must not invalidate the @a range_begin and @a range_end iters (or has to
   * revalidate them).
   *
   * See also:
   * Gtk::TextBuffer::apply_tag(),
   * Gtk::TextBuffer::insert_with_tags(),
   * Gtk::TextBuffer::insert_range().
   *
   * @param tag The applied tag.
   * @param range_begin The start of the range the tag is applied to.
   * @param range_end The end of the range the tag is applied to.
   */

  auto signal_apply_tag() -> Glib::SignalProxy<void(const Glib::RefPtr<TextBuffer::Tag>&, const TextBuffer::iterator&, const TextBuffer::iterator&)>;


  /**
   * @par Slot Prototype:
   * <tt>void on_my_%remove_tag(const Glib::RefPtr<TextBuffer::Tag>& tag, const TextBuffer::iterator& range_begin, const TextBuffer::iterator& range_end)</tt>
   *
   * Flags: Run Last
   *
   * Emitted to remove all occurrences of @a tag from a range
   * of text in a `Gtk::TextBuffer`.
   *
   * Removal actually occurs in the default handler.
   *
   * Note that if your handler runs before the default handler
   * it must not invalidate the @a range_begin and @a range_end iters (or has
   * to revalidate them).
   *
   * See also: Gtk::TextBuffer::remove_tag().
   *
   * @param tag The tag to be removed.
   * @param range_begin The start of the range the tag is removed from.
   * @param range_end The end of the range the tag is removed from.
   */

  auto signal_remove_tag() -> Glib::SignalProxy<void(const Glib::RefPtr<TextBuffer::Tag>&, const TextBuffer::iterator&, const TextBuffer::iterator&)>;


  /**
   * @par Slot Prototype:
   * <tt>void on_my_%begin_user_action()</tt>
   *
   * Flags: Run Last
   *
   * Emitted at the beginning of a single user-visible
   * operation on a `Gtk::TextBuffer`.
   *
   * See also:
   * Gtk::TextBuffer::begin_user_action(),
   * Gtk::TextBuffer::insert_interactive(),
   * Gtk::TextBuffer::insert_range_interactive(),
   * Gtk::TextBuffer::delete_interactive(),
   * Gtk::TextBuffer::backspace(),
   * Gtk::TextBuffer::delete_selection().
   */

  auto signal_begin_user_action() -> Glib::SignalProxy<void()>;


  /**
   * @par Slot Prototype:
   * <tt>void on_my_%end_user_action()</tt>
   *
   * Flags: Run Last
   *
   * Emitted at the end of a single user-visible
   * operation on the `Gtk::TextBuffer`.
   *
   * See also:
   * Gtk::TextBuffer::end_user_action(),
   * Gtk::TextBuffer::insert_interactive(),
   * Gtk::TextBuffer::insert_range_interactive(),
   * Gtk::TextBuffer::delete_interactive(),
   * Gtk::TextBuffer::backspace(),
   * Gtk::TextBuffer::delete_selection(),
   * Gtk::TextBuffer::backspace().
   */

  auto signal_end_user_action() -> Glib::SignalProxy<void()>;


  /**
   * @par Slot Prototype:
   * <tt>void on_my_%paste_done(const Glib::RefPtr<Gdk::Clipboard>& clipboard)</tt>
   *
   * Flags: Run Last
   *
   * Emitted after paste operation has been completed.
   *
   * This is useful to properly scroll the view to the end
   * of the pasted text. See Gtk::TextBuffer::paste_clipboard()
   * for more details.
   *
   * @param clipboard The `Gdk::Clipboard` pasted from.
   */

  auto signal_paste_done() -> Glib::SignalProxy<void(const Glib::RefPtr<Gdk::Clipboard>&)>;


  /**
   * @par Slot Prototype:
   * <tt>void on_my_%redo()</tt>
   *
   * Flags: Run Last
   *
   * Emitted when a request has been made to redo the
   * previously undone operation.
   */

  auto signal_redo() -> Glib::SignalProxy<void()>;


  /**
   * @par Slot Prototype:
   * <tt>void on_my_%undo()</tt>
   *
   * Flags: Run Last
   *
   * Emitted when a request has been made to undo the
   * previous operation or set of operations that have
   * been grouped together.
   */

  auto signal_undo() -> Glib::SignalProxy<void()>;


  /** The GtkTextTagTable for the buffer.
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_tag_table() const -> Glib::PropertyProxy_ReadOnly< Glib::RefPtr<TextBuffer::TagTable> >;


  /** The text content of the buffer.
   *
   * Without child widgets and images,
   * see Gtk::TextBuffer::get_text() for more information.
   *
   * Default value: ""
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_text() -> Glib::PropertyProxy< Glib::ustring > ;

/** The text content of the buffer.
   *
   * Without child widgets and images,
   * see Gtk::TextBuffer::get_text() for more information.
   *
   * Default value: ""
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_text() const -> Glib::PropertyProxy_ReadOnly< Glib::ustring >;

  /** Whether the buffer has some text currently selected.
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_has_selection() const -> Glib::PropertyProxy_ReadOnly< bool >;


  /** The position of the insert mark.
   *
   * This is an offset from the beginning of the buffer.
   * It is useful for getting notified when the cursor moves.
   *
   * Default value: 0
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_cursor_position() const -> Glib::PropertyProxy_ReadOnly< int >;


  /** Denotes that the buffer can undo the last applied action.
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_can_undo() const -> Glib::PropertyProxy_ReadOnly< bool >;


  /** Denotes that the buffer can reapply the last undone action.
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_can_redo() const -> Glib::PropertyProxy_ReadOnly< bool >;


  /** Denotes if support for undoing and redoing changes to the buffer is allowed.
   *
   * Default value: <tt>true</tt>
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_enable_undo() -> Glib::PropertyProxy< bool > ;

/** Denotes if support for undoing and redoing changes to the buffer is allowed.
   *
   * Default value: <tt>true</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_enable_undo() const -> Glib::PropertyProxy_ReadOnly< bool >;


private:
  friend TextMark;

  auto get_iter_at_mark(GtkTextMark* mark) -> iterator;


public:

public:
  //C++ methods used to invoke GTK+ virtual functions:

protected:
  //GTK+ Virtual Functions (override these to change behaviour):

  //Default Signal Handlers::
  /// This is a default handler for the signal signal_insert().
  virtual void on_insert(TextBuffer::iterator& pos, const Glib::ustring& text, int bytes);
  /// This is a default handler for the signal signal_insert_paintable().
  virtual void on_insert_paintable(TextBuffer::iterator& pos, const Glib::RefPtr<Gdk::Paintable>& paintable);
  /// This is a default handler for the signal signal_insert_child_anchor().
  virtual void on_insert_child_anchor(TextBuffer::iterator& pos, const Glib::RefPtr<ChildAnchor>& anchor);
  /// This is a default handler for the signal signal_erase().
  virtual void on_erase(TextBuffer::iterator& range_start, TextBuffer::iterator& range_end);
  /// This is a default handler for the signal signal_changed().
  virtual void on_changed();
  /// This is a default handler for the signal signal_modified_changed().
  virtual void on_modified_changed();
  /// This is a default handler for the signal signal_mark_set().
  virtual void on_mark_set(const TextBuffer::iterator& location, const Glib::RefPtr<TextBuffer::Mark>& mark);
  /// This is a default handler for the signal signal_mark_deleted().
  virtual void on_mark_deleted(const Glib::RefPtr<TextBuffer::Mark>& mark);
  /// This is a default handler for the signal signal_apply_tag().
  virtual void on_apply_tag(const Glib::RefPtr<TextBuffer::Tag>& tag, const TextBuffer::iterator& range_begin, const TextBuffer::iterator& range_end);
  /// This is a default handler for the signal signal_remove_tag().
  virtual void on_remove_tag(const Glib::RefPtr<TextBuffer::Tag>& tag, const TextBuffer::iterator& range_begin, const TextBuffer::iterator& range_end);
  /// This is a default handler for the signal signal_begin_user_action().
  virtual void on_begin_user_action();
  /// This is a default handler for the signal signal_end_user_action().
  virtual void on_end_user_action();
  /// This is a default handler for the signal signal_paste_done().
  virtual void on_paste_done(const Glib::RefPtr<Gdk::Clipboard>& clipboard);
  /// This is a default handler for the signal signal_redo().
  virtual void on_redo();
  /// This is a default handler for the signal signal_undo().
  virtual void on_undo();


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
   * @relates Gtk::TextBuffer
   */
  GTKMM_API
  auto wrap(GtkTextBuffer* object, bool take_copy = false) -> Glib::RefPtr<Gtk::TextBuffer>;
}


#endif /* _GTKMM_TEXTBUFFER_H */

