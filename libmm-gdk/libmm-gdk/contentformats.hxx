
#ifndef _GDKMM_CONTENTFORMATS_H
#define _GDKMM_CONTENTFORMATS_H

#include <libmm-gdk/mm-gdkconfig.hxx>


#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

/* Copyright (C) 2017 The gtkmm Development Team
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


#include <libmm-glib/refptr.hxx>
#include <libmm-glib/ustring.hxx>
#include <libmm-glib/value.hxx>
#include <gdk/gdk.h> // For GdkContentFormats.
#include <vector>


namespace Gdk
{

/** Advertising and negotiating of content exchange formats.
 *
 * %Gdk::ContentFormats is used to advertise and negotiate the format of
 * content passed between different widgets, windows or applications using
 * for example the clipboard or drag'n'drop.
 *
 * GDK supports content in 2 forms: GType and mime type.
 * Using GTypes is meant only for in-process content transfers. Mime types
 * are meant to be used for data passing both in-process and out-of-process.
 * The details of how data is passed is described in the documentation of
 * the actual implementations.
 *
 * A %Gdk::ContentFormats describes a set of possible formats content can be
 * exchanged in. It is assumed that this set is ordered. GTypes are more
 * important than mime types. Order between different Gtypes or mime types
 * is the order they were added in, most important first. Functions that
 * care about order, such as join(), describe in
 * their documentation how they interpret that order, though in general the
 * order of the first argument is considered the primary order of the result,
 * followed by the order of further arguments.
 *
 * For debugging purposes, the function to_string() exists.
 * It will print a comma-separated list of formats from most important to least
 * important.
 *
 * %Gdk::ContentFormats is an immutable object. After creation, you cannot change
 * the types it represents. Instead, new %Gdk::ContentFormats have to be created.
 * Gdk::ContentFormatsBuilder is meant to help in this endeavor.
 *
 * @see Gdk::Drag, Gdk::Drop, Gdk::Clipboard
 *
 * @newin{3,94}
 */
class GDKMM_API ContentFormats final
{
  // GdkContentFormats is actually registered as a boxed type, but it has custom
  // reference-counting instead of copy/free functions, so we use it via RefPtr.
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  using CppObjectType = ContentFormats;
  using BaseObjectType = GdkContentFormats;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


  /** Increment the reference count for this object.
   * You should never need to do this manually - use the object via a RefPtr instead.
   */
  void reference()   const;

  /** Decrement the reference count for this object.
   * You should never need to do this manually - use the object via a RefPtr instead.
   */
  void unreference() const;

  ///Provides access to the underlying C instance.
  auto       gobj() -> GdkContentFormats*;

  ///Provides access to the underlying C instance.
  auto gobj() const -> const GdkContentFormats*;

  ///Provides access to the underlying C instance. The caller is responsible for unrefing it. Use when directly setting fields in structs.
  auto gobj_copy() const -> GdkContentFormats*;

  ContentFormats() = delete;

  // noncopyable
  ContentFormats(const ContentFormats&) = delete;
  auto operator=(const ContentFormats&) -> ContentFormats& = delete;

protected:
  // Do not derive this.  Gdk::ContentFormats can neither be constructed nor deleted.

  void operator delete(void*, std::size_t);

private:


public:
  /** Creates a new %Gdk::ContentFormats from an array of mime types.
   *
   * The mime types must be different or the behavior of the return value
   * is undefined. If you cannot guarantee this, use Gdk::ContentFormatsBuilder
   * instead.
   *
   * @param mime_types A vector of mime types.
   * @return The new %Gdk::ContentFormats.
   */
  static auto create(const std::vector<Glib::ustring>& mime_types = {}) -> Glib::RefPtr<ContentFormats>;


  /** Creates a new %Gdk::ContentFormats from a mime type.
   *
   * @param mime_type A mime type.
   * @return The new %Gdk::ContentFormats.
   */
  static auto create(const Glib::ustring& mime_type) -> Glib::RefPtr<ContentFormats>;


  /** Creates a new %Gdk::ContentFormats from a GType.
   *
   * @param type A GType.
   * @return The new %Gdk::ContentFormats.
   */
  static auto create(GType type) -> Glib::RefPtr<ContentFormats>;


  /** Parses the given @a string into `Gdk::ContentFormats` and
   * returns the formats.
   *
   * Strings printed via to_string()
   * can be read in again successfully using this function.
   *
   * If @a string does not describe valid content formats, <tt>nullptr</tt>
   * is returned.
   *
   * @newin{4,4}
   *
   * @param string The string to parse.
   * @return The content formats if @a string is valid.
   */
  static auto parse(const Glib::ustring& string) -> Glib::RefPtr<ContentFormats>;


  /** Prints the given %ContentFormats into a string for human consumption.
   *
   * The resulting string can be parsed with parse().
   *
   * @return A new string.
   */
  auto to_string() const -> Glib::ustring;


  /** Gets the Types included in the %ContentFormats.
   * Note that they may not contain any Types, in particular when they are empty.
   * In that case an empty vector will be returned.
   *
   * @return A vector of types included in the %ContentFormats. May be empty.
   */
  auto get_gtypes() const -> std::vector<GType>;


  /** Gets the mime types included in the %ContentFormats.
   * Note that they may not contain any mime types, in particular when they are empty.
   * In that case an empty vector will be returned.
   *
   * @return A vector of mime types included in the %ContentFormats. May be empty.
   */
  auto get_mime_types() const -> std::vector<Glib::ustring>;


  /** Checks if a given `GType` is part of the given @a formats.
   *
   * @param type The `GType` to search for.
   * @return <tt>true</tt> if the `GType` was found.
   */
  auto contain_gtype(GType type) const -> bool;

  /** Checks if a given mime type is part of the given @a formats.
   *
   * @param mime_type The mime type to search for.
   * @return <tt>true</tt> if the mime_type was found.
   */
  auto contain_mime_type(const Glib::ustring& mime_type) const -> bool;

  // 'union' is a C and C++ keyword. Can't be a method name.
  /** Append all missing types from @a second to <tt>*this</tt>, in the order
   * they had in @a second.
   *
   * @param second The %ContentFormats to merge from.
   * @return A new %ContentFormats.
   */
  auto join(const Glib::RefPtr<const ContentFormats>& second) const -> Glib::RefPtr<ContentFormats>;


  /** Checks if @a first and @a second have any matching formats.
   *
   * @param second The `Gdk::ContentFormats` to intersect with.
   * @return <tt>true</tt> if a matching format was found.
   */
  auto match(const Glib::RefPtr<const ContentFormats>& second) const -> bool;

  /** Finds the first `GType` from @a first that is also contained
   * in @a second.
   *
   * If no matching `GType` is found, G_TYPE_INVALID is returned.
   *
   * @param second The `Gdk::ContentFormats` to intersect with.
   * @return The first common `GType` or G_TYPE_INVALID if none.
   */
  auto match_gtype(const Glib::RefPtr<const ContentFormats>& second) const -> GType;

  /** Finds the first mime type from <tt>*this</tt> that is also contained in @a second.
   * If no matching mime type is found, an empty string is returned.
   *
   * @param second The Gdk::ContentFormats to intersect with.
   * @return The first common mime type, or an empty string if none.
   */
  auto match_mime_type(const Glib::RefPtr<const ContentFormats>& second) const -> Glib::ustring;


};

} // namespace Gdk

namespace Glib
{
// This is needed so Glib::RefPtr<Gdk::ContentFormats> can be used with
// Glib::Value and _WRAP_PROPERTY in Gtk::TextBuffer.
template <>
class GDKMM_API Value<Glib::RefPtr<Gdk::ContentFormats>> : public ValueBase_Boxed
{
public:
  typedef Glib::RefPtr<Gdk::ContentFormats> CppType;
  typedef GdkContentFormats* CType;

  static auto value_type() -> GType;

  void set(const CppType& data);
  auto get() const -> CppType;
};

} // namespace Glib


namespace Glib
{

/** A Glib::wrap() method for this object.
 *
 * @param object The C instance.
 * @param take_copy False if the result should take ownership of the C instance. True if it should take a new copy or ref.
 * @result A C++ instance that wraps this C instance.
 *
 * @relates Gdk::ContentFormats
 */
GDKMM_API
auto wrap(GdkContentFormats* object, bool take_copy = false) -> Glib::RefPtr<Gdk::ContentFormats>;

} // namespace Glib


#endif /* _GDKMM_CONTENTFORMATS_H */

