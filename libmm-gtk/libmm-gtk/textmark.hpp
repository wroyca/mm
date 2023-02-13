
#ifndef _GTKMM_TEXTMARK_H
#define _GTKMM_TEXTMARK_H

#include <mm/gtk/mm-gtkconfig.hpp>


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


#include <mm/glib/object.hpp>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkTextMark = struct _GtkTextMark;
using GtkTextMarkClass = struct _GtkTextMarkClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{ class GTKMM_API TextMark_Class; } // namespace Gtk
#endif //DOXYGEN_SHOULD_SKIP_THIS

namespace Gtk
{

class GTKMM_API TextBuffer;
class GTKMM_API TextIter;
class GTKMM_API TextConstIter;

/** Typedefed as Gtk::TextBuffer::Mark. A position in the buffer, preserved across buffer modifications.
 *
 * A Mark is like a bookmark in a text buffer; it preserves a position in the text.  Unlike iterators, marks remain valid across buffer mutations, because
 * their behavior is defined when text is inserted or deleted. When text containing a mark is deleted, the mark remains in
 * the position originally occupied by the deleted text. When text is inserted at a mark, a mark with left gravity will be
 * moved to the beginning of the newly-inserted text, and a mark with right gravity will be moved to the end.
 * The standard text cursor in left-to-right languages is a mark with right gravity, because it stays to the right of inserted
 * text.
 *
 * Like tags, marks can be either named or anonymous. There are two marks built-in to Gtk::TextBuffer; these are named "insert" and
 * "selection_bound" and refer to the insertion point and the boundary of the selection which is not the insertion point,
 * respectively. If no text is selected, these two marks will be in the same position. You can manipulate what is selected and
 * where the cursor appears by moving these marks around.
 *
 * "left" and "right" here refer to logical direction (left is the toward the start of the buffer); in some languages such as
 * Hebrew the logically-leftmost text is not actually on the left when displayed.
 *
 * You can convert the mark to an @link Gtk::TextIter iterator@endlink or
 * a @link Gtk::TextConstIter const_iterator@endlink using Gtk::TextBuffer::get_iter_at_mark().
 *
 * Marks can be deleted from the buffer at any time with Gtk::TextBuffer::delete_mark(). Once deleted from the buffer, a mark is essentially useless.
 *
 * Marks optionally have names; these can be convenient to avoid passing the Gtk::TextBuffer::Mark object around.
 *
 * Marks are typically created using the Gtk::TextBuffer::create_mark() function.
 *
 * @ingroup TextView
 */

class GTKMM_API TextMark : public Glib::Object
{

#ifndef DOXYGEN_SHOULD_SKIP_THIS

public:
  using CppObjectType = TextMark;
  using CppClassType = TextMark_Class;
  using BaseObjectType = GtkTextMark;
  using BaseClassType = GtkTextMarkClass;

  // noncopyable
  TextMark(const TextMark&) = delete;
  auto operator=(const TextMark&) -> TextMark& = delete;

private:  friend class TextMark_Class;
  static CppClassType textmark_class_;

protected:
  explicit TextMark(const Glib::ConstructParams& construct_params);
  explicit TextMark(GtkTextMark* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  TextMark(TextMark&& src) noexcept;
  auto operator=(TextMark&& src) noexcept -> TextMark&;

  ~TextMark() noexcept override;

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS


  static auto get_base_type() -> GType G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GObject.
  auto       gobj() -> GtkTextMark*       { return reinterpret_cast<GtkTextMark*>(gobject_); }

  ///Provides access to the underlying C GObject.
  auto gobj() const -> const GtkTextMark* { return reinterpret_cast<GtkTextMark*>(gobject_); }

  ///Provides access to the underlying C instance. The caller is responsible for unrefing it. Use when directly setting fields in structs.
  auto gobj_copy() -> GtkTextMark*;

private:

protected:

  /** Creates an anoymous text mark. Add it to a buffer using Gtk::TextBuffer::add_mark().
   * If a mark has left
   * gravity, and text is inserted at the mark's current location, the mark
   * will be moved to the left of the newly-inserted text. If the mark has
   * right gravity (@a left_gravity = false), the mark will end up on the
   * right of newly-inserted text. The standard left-to-right cursor is a
   * mark with right gravity (when you type, the cursor stays on the right
   * side of the text you're typing).
   *
   * @param left_gravity Whether the mark should have left gravity.
   * @newin{2,12}
   */
  explicit TextMark(bool left_gravity = true);

  /** Creates a text mark. Add it to a buffer using Gtk::TextBuffer::add_mark().
   * The mark can be retrieved by name using Gtk::TextBuffer::get_mark(). If a mark has left
   * gravity, and text is inserted at the mark's current location, the mark
   * will be moved to the left of the newly-inserted text. If the mark has
   * right gravity (@a left_gravity = false), the mark will end up on the
   * right of newly-inserted text. The standard left-to-right cursor is a
   * mark with right gravity (when you type, the cursor stays on the right
   * side of the text you're typing).
   *
   * @param name mark name.
   * @param left_gravity Whether the mark should have left gravity.
   * @newin{2,12}
   */
    explicit TextMark(const Glib::ustring& name, bool left_gravity =  true);


public:

  /** Creates an anoymous text mark. Add it to a buffer using Gtk::TextBuffer::add_mark().
   * If a mark has left
   * gravity, and text is inserted at the mark's current location, the mark
   * will be moved to the left of the newly-inserted text. If the mark has
   * right gravity (@a left_gravity = false), the mark will end up on the
   * right of newly-inserted text. The standard left-to-right cursor is a
   * mark with right gravity (when you type, the cursor stays on the right
   * side of the text you're typing).
   *
   * @param left_gravity Whether the mark should have left gravity.
   * @result A RefPtr to a new text mark.
   * @newin{2,12}
   */

  static auto create(bool left_gravity =  true) -> Glib::RefPtr<TextMark>;


/** Creates a text mark. Add it to a buffer using Gtk::TextBuffer::add_mark().
   * The mark can be retrieved by name using Gtk::TextBuffer::get_mark(). If a mark has left
   * gravity, and text is inserted at the mark's current location, the mark
   * will be moved to the left of the newly-inserted text. If the mark has
   * right gravity (@a left_gravity = false), the mark will end up on the
   * right of newly-inserted text. The standard left-to-right cursor is a
   * mark with right gravity (when you type, the cursor stays on the right
   * side of the text you're typing).
   *
   * @param name mark name.
   * @param left_gravity Whether the mark should have left gravity.
   * @result A RefPtr to a new text mark.
   * @newin{2,12}
   */

  static auto create(const Glib::ustring& name, bool left_gravity =  true) -> Glib::RefPtr<TextMark>;


  /** Sets the visibility of @a mark.
   *
   * The insertion point is normally visible, i.e. you can see it as
   * a vertical bar. Also, the text widget uses a visible mark to
   * indicate where a drop will occur when dragging-and-dropping text.
   * Most other marks are not visible.
   *
   * Marks are not visible by default.
   *
   * @param setting Visibility of mark.
   */
  void set_visible(bool setting =  true);

  /** Returns <tt>true</tt> if the mark is visible.
   *
   * A cursor is displayed for visible marks.
   *
   * @return <tt>true</tt> if visible.
   */
  auto get_visible() const -> bool;

  /** Returns the mark name.
   *
   * @return Mark name.
   */
  auto get_name() const -> Glib::ustring;

  /** Returns <tt>true</tt> if the mark has been removed from its buffer.
   *
   * See Gtk::TextBuffer::add_mark() for a way to add it
   * to a buffer again.
   *
   * @return Whether the mark is deleted.
   */
  auto get_deleted() const -> bool;

  /** Gets the buffer this mark is located inside.
   *
   * @return The mark’s `Gtk::TextBuffer`.
   */
  auto get_buffer() -> Glib::RefPtr<TextBuffer>;

  /** Gets the buffer this mark is located inside.
   *
   * @return The mark’s `Gtk::TextBuffer`.
   */
  auto get_buffer() const -> Glib::RefPtr<const TextBuffer>;

  /** Determines whether the mark has left gravity.
   *
   * @return <tt>true</tt> if the mark has left gravity, <tt>false</tt> otherwise.
   */
  auto get_left_gravity() const -> bool;

  auto get_iter() -> TextIter;
  auto get_iter() const -> TextConstIter;

  /** The name of the mark or <tt>nullptr</tt> if the mark is anonymous.
   *
   * Default value: ""
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_name() const -> Glib::PropertyProxy_ReadOnly< Glib::ustring >;


  /** Whether the mark has left gravity.
   *
   * When text is inserted at the mark’s current location, if the mark
   * has left gravity it will be moved to the left of the newly-inserted
   * text, otherwise to the right.
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_left_gravity() const -> Glib::PropertyProxy_ReadOnly< bool >;


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
   * @relates Gtk::TextMark
   */
  GTKMM_API
  auto wrap(GtkTextMark* object, bool take_copy = false) -> Glib::RefPtr<Gtk::TextMark>;
}


#endif /* _GTKMM_TEXTMARK_H */

