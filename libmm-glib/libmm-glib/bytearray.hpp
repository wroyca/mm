
#ifndef _GLIBMM_BYTEARRAY_H
#define _GLIBMM_BYTEARRAY_H


/* Copyright (C) 2013 The glibmm Development Team
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


#include <cstddef> // std::size_t
#include <sigc++/slot.h>
#include <libmm-glib/refptr.hpp>
#include <libmm-glib/value.hpp>
#include <libmm-glib/wrap.hpp>
#include <glib.h>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
typedef struct _GByteArray GByteArray;
#endif

namespace Glib
{

/** ByteArray - Arrays of bytes.
 * ByteArray is a mutable array of bytes, to provide arrays of bytes which grow
 * automatically as elements are added.
 *
 * To create a new ByteArray use create(). To add elements to a ByteArray, use
 * append(), and prepend().
 *
 * To set the size of a ByteArray, use set_size().
 *
 * @newin{2,36}
 */
class GLIBMM_API ByteArray final
{
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  using CppObjectType = ByteArray;
  using BaseObjectType = GByteArray;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType G_GNUC_CONST;


  /** Increment the reference count for this object.
   * You should never need to do this manually - use the object via a RefPtr instead.
   */
  void reference()   const;

  /** Decrement the reference count for this object.
   * You should never need to do this manually - use the object via a RefPtr instead.
   */
  void unreference() const;

  ///Provides access to the underlying C instance.
  auto       gobj() -> GByteArray*;

  ///Provides access to the underlying C instance.
  auto gobj() const -> const GByteArray*;

  ///Provides access to the underlying C instance. The caller is responsible for unrefing it. Use when directly setting fields in structs.
  auto gobj_copy() const -> GByteArray*;

  ByteArray() = delete;

  // noncopyable
  ByteArray(const ByteArray&) = delete;
  auto operator=(const ByteArray&) -> ByteArray& = delete;

protected:
  // Do not derive this.  Glib::ByteArray can neither be constructed nor deleted.

  void operator delete(void*, std::size_t);

private:


public:
  /** A Slot type to compare two elements in the array.  The slot should return
   * -1 if the first value is less than the second, 0 if they are equal and 1
   * if the first value is greater than the second.
   *
   * Slot Prototype:
   *
   * <code>
   * int compare(const guint8* first, const guint8* second);
   * </code>
   */
  using SlotCompare = sigc::slot<int(const guint8*, const guint8*)>;


  /** Creates a new ByteArray with a reference count of 1.
   *
   * @return The new ByteArray.
   */
  static auto create() -> Glib::RefPtr<ByteArray>;


  /** Adds the given bytes to the end of the ByteArray.
   * The array will grow in size automatically if necessary.
   *
   * @param data The byte data to be added.
   * @param len The number of bytes to add.
   * @return The ByteArray.
   */
  auto append(const guint8* data, guint len) -> Glib::RefPtr<ByteArray>;

  /** Adds the given data to the start of the ByteArray.
   * The array will grow in size automatically if necessary.
   *
   * @param data The byte data to be added.
   * @param len The number of bytes to add.
   * @return The ByteArray.
   */
  auto prepend(const guint8* data, guint len) -> Glib::RefPtr<ByteArray>;

  /** Gets the size of the byte array.
   * @return The size.
   * @newin{2,36}
   */
  auto size() const -> guint;

  /** Gets the data of the byte array.
   * @return The data.
   * @newin{2,36}
   */
  auto get_data() -> guint8*;

  /** Gets the data of the byte array.
   * @return The data.
   * @newin{2,36}
   */
  auto get_data() const -> const guint8*;


  /** Removes the byte at the given index from a ByteArray.
   * The following bytes are moved down one place.
   *
   * @param index The index of the byte to remove.
   * @return The ByteArray.
   */
  auto remove_index(guint index) -> Glib::RefPtr<ByteArray>;

  /** Removes the byte at the given index from a ByteArray. The last
   * element in the array is used to fill in the space, so this function
   * does not preserve the order of the ByteArray. But it is faster
   * than g_byte_array_remove_index().
   *
   * @param index The index of the byte to remove.
   * @return The ByteArray.
   */
  auto remove_index_fast(guint index) -> Glib::RefPtr<ByteArray>;

  /** Removes the given number of bytes starting at the given index from a
   * ByteArray.  The following elements are moved to close the gap.
   *
   * @newin{2,4}
   *
   * @param index The index of the first byte to remove.
   * @param length The number of bytes to remove.
   * @return The ByteArray.
   */
  auto remove_range(guint index, guint length) -> Glib::RefPtr<ByteArray>;


  /** Like g_byte_array_sort(), but the comparison function takes an extra
   * user data argument.
   *
   * @param slot Comparison function.
   */
  void sort(const SlotCompare& slot);


  /** Sets the size of the ByteArray, expanding it if necessary.
   *
   * @param length The new size of the ByteArray.
   * @return The ByteArray.
   */
  auto set_size(guint length) -> Glib::RefPtr<ByteArray>;


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
 * @relates Glib::ByteArray
 */
GLIBMM_API
auto wrap(GByteArray* object, bool take_copy = false) -> Glib::RefPtr<Glib::ByteArray>;

#ifndef DOXYGEN_SHOULD_SKIP_THIS
template <>
class GLIBMM_API Value<Glib::RefPtr<Glib::ByteArray>> : public Glib::Value_RefPtrBoxed<Glib::ByteArray>
{
public:
  auto get() const -> CppType { return Glib::wrap(static_cast<GByteArray*>(get_boxed()), true); }
};
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

} // namespace Glib


#endif /* _GLIBMM_BYTEARRAY_H */

