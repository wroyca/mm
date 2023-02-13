
#ifndef _GIOMM_FILEATTRIBUTEINFOLIST_H
#define _GIOMM_FILEATTRIBUTEINFOLIST_H


#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

/* Copyright (C) 2007 The gtkmm Development Team
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
 * License along with this library.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <libmm-gio/fileattributeinfo.hxx>


namespace Gio
{

/** Key-Value paired file attributes.
 * File attributes in GIO consist of a list of key-value pairs.
 *
 * Keys are strings that contain a key namespace and a key name, separated by a colon, e.g. "namespace:keyname".
 * Namespaces are included to sort key-value pairs by namespaces for relevance. Keys can be retreived using wildcards,
 * e.g. "standard::*" will return all of the keys in the "standard" namespace.
 *
 * Values are stored within the list in Gio::FileAttributeValue structures. Values can store different types, listed in the enum
 * Gio::FileAttributeType. Upon creation of a Gio::FileAttributeValue, the type will be set to Gio::FileAttributeType::INVALID.
 *
 * The list of possible attributes for a filesystem (pointed to by a Gio::File) is availible as a Gio::FileAttributeInfoList.
 * This list is queryable by key names as indicated earlier.
 *
 * Classes that implement Gio::FileIface will create a Gio::FileAttributeInfoList and install default keys and values for their given file
 * system, architecture, and other possible implementation details (e.g., on a UNIX system, a file attribute key will be registered for
 * the user id for a given file).
 *
 * See http://library.gnome.org/devel/gio/unstable/gio-GFileAttribute.html for the list of default namespaces and the list of default keys.
 *
 * @newin{2,16}
 */
class GIOMM_API FileAttributeInfoList final
{
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  using CppObjectType = FileAttributeInfoList;
  using BaseObjectType = GFileAttributeInfoList;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

  static auto create() -> Glib::RefPtr<FileAttributeInfoList>;

  /** Increment the reference count for this object.
   * You should never need to do this manually - use the object via a RefPtr instead.
   */
  void reference()   const;

  /** Decrement the reference count for this object.
   * You should never need to do this manually - use the object via a RefPtr instead.
   */
  void unreference() const;

  ///Provides access to the underlying C instance.
  auto       gobj() -> GFileAttributeInfoList*;

  ///Provides access to the underlying C instance.
  auto gobj() const -> const GFileAttributeInfoList*;

  ///Provides access to the underlying C instance. The caller is responsible for unrefing it. Use when directly setting fields in structs.
  auto gobj_copy() const -> GFileAttributeInfoList*;

  FileAttributeInfoList() = delete;

  // noncopyable
  FileAttributeInfoList(const FileAttributeInfoList&) = delete;
  auto operator=(const FileAttributeInfoList&) -> FileAttributeInfoList& = delete;

protected:
  // Do not derive this.  Gio::FileAttributeInfoList can neither be constructed nor deleted.

  void operator delete(void*, std::size_t);

private:


public:

  /** Whether the FileAttributeInfoList is valid and non empty.
   * @result true if this FileAttributeInfoList is not empty.
   */
  explicit operator bool() const;

  /** Whether the FileAttributeInfoList is empty or invalid.
   * @result true if this FileAttributeInfoList is empty.
   */
  auto empty() const -> bool;

  /** Gets the file attribute with the name name from list.
   * @param name The name of the attribute to lookup.
   * @result A FileAttributeInfo for the name.
   */
  auto lookup(const std::string& name) const -> FileAttributeInfo;


  /** Makes a duplicate of a file attribute info list.
   *
   * @return A copy of the given @a list.
   */
  auto dup() const -> Glib::RefPtr<FileAttributeInfoList>;


  /** Adds a new attribute with @a name to the @a list, setting
   * its @a type and @a flags.
   *
   * @param name The name of the attribute to add.
   * @param type The FileAttributeType for the attribute.
   * @param flags Gio::FileAttributeInfo::Flags for the attribute.
   */
  void add(const std::string& name, FileAttributeType type, FileAttributeInfo::Flags flags =  FileAttributeInfo::Flags::NONE);


};

} // namespace Gio


namespace Glib
{

/** A Glib::wrap() method for this object.
 *
 * @param object The C instance.
 * @param take_copy False if the result should take ownership of the C instance. True if it should take a new copy or ref.
 * @result A C++ instance that wraps this C instance.
 *
 * @relates Gio::FileAttributeInfoList
 */
GIOMM_API
auto wrap(GFileAttributeInfoList* object, bool take_copy = false) -> Glib::RefPtr<Gio::FileAttributeInfoList>;

} // namespace Glib


#endif /* _GIOMM_FILEATTRIBUTEINFOLIST_H */

