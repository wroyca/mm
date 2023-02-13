
#ifndef _PANGOMM_ATTRLIST_H
#define _PANGOMM_ATTRLIST_H


#include <libmm-glib/ustring.hpp>
#include <sigc++/sigc++.h>

/* attrlist.h
 *
 * Copyright (C) 1998-1999 The gtkmm Development Team
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
 * License along with this library; if not, write to the Free
 * Software Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 */

#include <libmm-pango/attributes.hpp>
#include <libmm-pango/attriter.hpp>
#include <vector>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
extern "C" { typedef struct _PangoAttrList PangoAttrList; }
#endif

namespace Pango
{

/** A %Pango::AttrList represents a list of attributes that apply to a section of text.
 * The attributes are, in general, allowed to overlap in an arbitrary fashion, however,
 * if the attributes are manipulated only through Pango::AttrList::change(), the overlap between properties will meet stricter criteria.
 *
 * Since the %Pango::AttrList structure is stored as a linear list, it is not suitable for storing attributes for large amounts of text.
 * In general, you should not use a single %Pango::AttrList for more than one paragraph of text.
 *
 * When obtaining an %AttrList, you should check that it is valid. For instance, if(attrlist).
 */
class PANGOMM_API AttrList
{
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  using CppObjectType = AttrList;
  using BaseObjectType = PangoAttrList;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType G_GNUC_CONST;

  AttrList();

  explicit AttrList(PangoAttrList* gobject, bool make_a_copy = true);

  AttrList(const AttrList& other);
  auto operator=(const AttrList& other) -> AttrList&;

  AttrList(AttrList&& other) noexcept;
  auto operator=(AttrList&& other) noexcept -> AttrList&;

  ~AttrList() noexcept;

  void swap(AttrList& other) noexcept;

  ///Provides access to the underlying C instance.
  auto       gobj() -> PangoAttrList*       { return gobject_; }

  ///Provides access to the underlying C instance.
  auto gobj() const -> const PangoAttrList* { return gobject_; }

  ///Provides access to the underlying C instance. The caller is responsible for freeing it. Use when directly setting fields in structs.
  auto gobj_copy() const -> PangoAttrList*;

protected:
  PangoAttrList* gobject_;

private:


public:
  /** Constructs an attribute list by parsing a marked-up text (see markup format).
   * If @a accel_marker is nonzero, the given character will mark the character
   * following it as an accelerator. For example, the accel marker might be an
   * ampersand or underscore. All characters marked as an accelerator will receive
   * a Pango::UNDERLINE_LOW attribute.
   * Two @a accel_marker characters following each other
   * produce a single literal @a accel_marker character.
   *
   * @param markup_text Markup to parse (see markup format).
   * @param accel_marker Character that precedes an accelerator, or <tt>0</tt> for none.
   */
  explicit AttrList(const Glib::ustring& markup_text, gunichar accel_marker=0);

  /** Constructs an attribute list by parsing a marked-up text (see markup format).
   * @a text is set to the plaintext string.
   * If @a accel_marker is nonzero, the given character will mark the character
   * following it as an accelerator. For example, the accel marker might be an
   * ampersand or underscore. All characters marked as an accelerator will receive
   * a Pango::UNDERLINE_LOW attribute. The first character so marked will be
   * returned in @a accel_char. Two @a accel_marker characters following each other
   * produce a single literal @a accel_marker character.
   *
   * @param markup_text Markup to parse (see markup format).
   * @param accel_marker Character that precedes an accelerator, or <tt>0</tt> for none.
   * @param text Return location for text with tags stripped.
   * @param accel_char Return location for accelerator char.
   */
  AttrList(const Glib::ustring& markup_text, gunichar accel_marker, Glib::ustring& text, gunichar& accel_char);

  ///Tests whether the %AttrList is valid.
  explicit operator bool() const;

  void insert(Attribute& attr);
   // hand code because we need to pass a copy of the attribute
  void insert_before(Attribute& attr);
   // hand code because we need to pass a copy of the attribute
  void change(Attribute& attr);
   // hand code because we need to pass a copy of the attribute

  /** This function opens up a hole in @a list, fills it
   * in with attributes from the left, and then merges
   *  @a other on top of the hole.
   *
   * This operation is equivalent to stretching every attribute
   * that applies at position @a pos in @a list by an amount @a len,
   * and then calling change() with a copy
   * of each attribute in @a other in sequence (offset in position
   * by @a pos).
   *
   * This operation proves useful for, for instance, inserting
   * a pre-edit string in the middle of an edit buffer.
   *
   * @param other Another `Pango::AttrList`.
   * @param pos The position in @a list at which to insert @a other.
   * @param len The length of the spliced segment. (Note that this
   * must be specified since the attributes in @a other may only
   * be present at some subsection of this range).
   */
  void splice(AttrList& other, int pos, int len);

  /** Update indices of attributes in @a list for a change in the
   * text they refer to.
   *
   * The change that this function applies is removing @a remove
   * bytes at position @a pos and inserting @a add bytes instead.
   *
   * Attributes that fall entirely in the ( @a pos, @a pos + @a remove)
   * range are removed.
   *
   * Attributes that start or end inside the ( @a pos, @a pos + @a remove)
   * range are shortened to reflect the removal.
   *
   * Attributes start and end positions are updated if they are
   * behind @a pos + @a remove.
   *
   * @newin{2,50}
   *
   * @param pos The position of the change.
   * @param remove The number of removed bytes.
   * @param add The number of added bytes.
   */
  void update(int pos, int remove, int add);


  /** Gets a list of all attributes in @a list.
   *
   * @newin{2,50}
   *
   * @return A list of all attributes in @a list. To free this value,
   * call [method @a Pango.Attribute.
   */
  auto get_attributes() const -> std::vector<Attribute>;


  /** Checks whether @a list and @a other_list contain the same
   * attributes and whether those attributes apply to the
   * same ranges.
   *
   * Beware that this will return wrong values if any list
   * contains duplicates.
   *
   * @newin{2,50}
   *
   * @param other_list The other `Pango::AttrList`.
   * @return <tt>true</tt> if the lists are equal, <tt>false</tt> if
   * they aren't.
   */
  auto equal(const AttrList& other_list) const -> bool;

  /** Serializes a `Pango::AttrList` to a string.
   *
   * No guarantees are made about the format of the string,
   * it may change between Pango versions.
   *
   * The intended use of this function is testing and
   * debugging. The format is not meant as a permanent
   * storage format.
   *
   * @newin{2,50}
   *
   * @return A newly allocated string.
   */
  auto to_string() const -> Glib::ustring;
  // Don't replace from_string() by a constructor. A call to such a constructor would be
  // ambiguous because of AttrList(markup_text, accel_marker=0).


  /** Deserializes a `Pango::AttrList` from a string.
   *
   * This is the counterpart to to_string().
   * See that functions for details about the format.
   *
   * @newin{2,50}
   *
   * @param text A string.
   * @return A new `Pango::AttrList`.
   */
  static auto from_string(const Glib::ustring& text) -> AttrList;

  /** Create a iterator initialized to the beginning of the list.
   *
   *  @a list must not be modified until this iterator is freed.
   *
   * @return The newly allocated
   * `Pango::AttrIterator`, which should be freed with
   * Pango::AttrIterator::destroy().
   */
  auto get_iter() -> AttrIter;

  //TODO: Though it doesn't seem important:
  //PangoAttrList* pango_attr_list_filter (PangoAttrList* list, PangoAttrFilterFunc  func, gpointer             data)


};

} //namespace Pango


namespace Pango
{

/** @relates Pango::AttrList
 * @param lhs The left-hand side
 * @param rhs The right-hand side
 */
inline void swap(AttrList& lhs, AttrList& rhs) noexcept
  { lhs.swap(rhs); }

} // namespace Pango

namespace Glib
{

/** A Glib::wrap() method for this object.
 *
 * @param object The C instance.
 * @param take_copy False if the result should take ownership of the C instance. True if it should take a new copy or ref.
 * @result A C++ instance that wraps this C instance.
 *
 * @relates Pango::AttrList
 */
PANGOMM_API
auto wrap(PangoAttrList* object, bool take_copy = false) -> Pango::AttrList;

#ifndef DOXYGEN_SHOULD_SKIP_THIS
template <>
class PANGOMM_API Value<Pango::AttrList> : public Glib::Value_Boxed<Pango::AttrList>
{};
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

} // namespace Glib


#endif /* _PANGOMM_ATTRLIST_H */

