
#ifndef _GLIBMM_VARIANTITER_H
#define _GLIBMM_VARIANTITER_H


/* Copyright(C) 2010 The glibmm Development Team
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

#include <libmm-glib/mm-glibconfig.hxx>
#include <glib.h>


namespace Glib
{

class GLIBMM_API VariantBase;
class GLIBMM_API VariantContainerBase;

//This can't be like a real iterator (like Gtk::TextIter),
//because g_iter_value_get_next_value() both gets a value and changes the iterator.
//GtkTextIter allows us to go forward and then separately get the current value.
/** VariantIter - An opaque data structure used to iterate through
 * VariantContainerBase containers such as arrays.
 * @newin{2,28}
 */
class GLIBMM_API VariantIter
{
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  using CppObjectType = VariantIter;
  using BaseObjectType = GVariantIter;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

  /** Constructs an invalid object.
   * E.g. for output arguments to methods. There is not much you can do with
   * the object before it has been assigned a valid value.
   */
  VariantIter();

  // Use make_a_copy=true when getting it directly from a struct.
  explicit VariantIter(GVariantIter* castitem, bool make_a_copy = false);

  VariantIter(const VariantIter& src);
  auto operator=(const VariantIter& src) -> VariantIter&;

  VariantIter(VariantIter&& other) noexcept;
  auto operator=(VariantIter&& other) noexcept -> VariantIter&;

  ~VariantIter() noexcept;

  void swap(VariantIter& other) noexcept;

  auto       gobj() -> GVariantIter*       { return gobject_; }
  auto gobj() const -> const GVariantIter* { return gobject_; }

  ///Provides access to the underlying C instance. The caller is responsible for freeing it. Use when directly setting fields in structs.
  auto gobj_copy() const -> GVariantIter*;

protected:
  GVariantIter* gobject_;

private:


public:
  explicit VariantIter(const VariantContainerBase& variant);


  /** Initialises (without allocating) a VariantIter.  @a iter may be
   * completely uninitialised prior to this call; its old value is
   * ignored.
   *
   * The iterator remains valid for as long as @a value exists, and need not
   * be freed in any way.
   *
   * @newin{2,24}
   *
   * @param value A container Variant.
   * @return The number of items in @a value.
   */
  auto init(const VariantContainerBase& value) -> gsize;


  /** Queries the number of child items in the container that we are
   * iterating over.  This is the total number of items -- not the number
   * of items remaining.
   *
   * This function might be useful for preallocation of arrays.
   *
   * @newin{2,24}
   *
   * @return The number of children in the container.
   */
  auto get_n_children() const -> gsize;

  auto next_value(VariantBase& value) -> bool;


  // Ignore varargs functions


};

} // namespace Glib


namespace Glib
{

/** @relates Glib::VariantIter
 * @param lhs The left-hand side
 * @param rhs The right-hand side
 */
inline void swap(VariantIter& lhs, VariantIter& rhs) noexcept
  { lhs.swap(rhs); }

} // namespace Glib

namespace Glib
{

  /** A Glib::wrap() method for this object.
   *
   * @param object The C instance.
   * @param take_copy False if the result should take ownership of the C instance. True if it should take a new copy or ref.
   * @result A C++ instance that wraps this C instance.
   *
   * @relates Glib::VariantIter
   */
  GLIBMM_API
  auto wrap(GVariantIter* object, bool take_copy = false) -> Glib::VariantIter;

} // namespace Glib


#endif /* _GLIBMM_VARIANTITER_H */

