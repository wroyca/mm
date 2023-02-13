
#ifndef _GTKMM_BITSET_H
#define _GTKMM_BITSET_H

#include <libmm-gtk/mm-gtkconfig.hpp>


#include <libmm-glib/ustring.hpp>
#include <sigc++/sigc++.h>

/* Copyright (C) 2020 The gtkmm Development Team
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


#include <libmm-glib/refptr.hpp>
#include <libmm-gtk/bitsetconstiter.hpp>

extern "C" typedef struct _GtkBitset GtkBitset;

namespace Gtk
{

/** Sets of integers.
 *
 * %Gtk::Bitset is a data structure for representing a set of unsigned integers.
 * Another name for this data structure is "bitmap".
 *
 * This version is based on
 * <a href="https://roaringbitmap.org/">roaring bitmaps</a>.
 *
 * A bitset allows adding a set of integers and provides support for set operations
 * like unions, intersections and checks for equality or if a value is contained
 * in the set. %Gtk::Bitset also contains various functions to query metadata about
 * the bitset, such as the minimum or maximum values or its size.
 *
 * The fastest way to iterate values in a bitset is Gtk::BitsetConstIter which
 * allows quick iteration of all the values in a bitset.
 *
 * The main use case for %Gtk::Bitset is implementing complex selections for
 * Gtk::SelectionModel.
 *
 * @see SelectionModel, BitsetConstIter
 *
 * @newin{3,98}
 */
class GTKMM_API Bitset final
{
  // GtkBitset is registered as a boxed type, but it has custom
  // reference-counting instead of copy/free functions, so we use it via RefPtr.
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  using CppObjectType = Bitset;
  using BaseObjectType = GtkBitset;
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
  auto       gobj() -> GtkBitset*;

  ///Provides access to the underlying C instance.
  auto gobj() const -> const GtkBitset*;

  ///Provides access to the underlying C instance. The caller is responsible for unrefing it. Use when directly setting fields in structs.
  auto gobj_copy() const -> GtkBitset*;

  Bitset() = delete;

  // noncopyable
  Bitset(const Bitset&) = delete;
  auto operator=(const Bitset&) -> Bitset& = delete;

protected:
  // Do not derive this.  Gtk::Bitset can neither be constructed nor deleted.

  void operator delete(void*, std::size_t);

private:


public:
  using const_iterator = BitsetConstIter;

  auto begin() const -> const_iterator;
  auto end() const -> const_iterator;
  auto cbegin() const -> const_iterator { return begin(); }
  auto cend() const -> const_iterator { return end(); }


  /** Creates a new empty bitset.
   *
   * @return A new empty bitset.
   */
  static auto create() -> Glib::RefPtr<Bitset>;


  /** Checks if the given @a value has been added to @a self
   *
   * @param value The value to check.
   * @return <tt>true</tt> if @a self contains @a value.
   */
  auto contains(guint value) const -> bool;

  /** Check if no value is contained in bitset.
   *
   * @return <tt>true</tt> if @a self is empty.
   */
  auto is_empty() const -> bool;

  /** Gets the number of values that were added to the set.
   *
   * For example, if the set is empty, 0 is returned.
   *
   * Note that this function returns a `guint64`, because when all
   * values are set, the return value is `G_MAXUINT + 1`. Unless you
   * are sure this cannot happen (it can't with `Gio::ListModel`), be sure
   * to use a 64bit type.
   *
   * @return The number of values in the set.
   */
  auto get_size() const -> guint64;

  /** Gets the number of values that are part of the set from @a first to @a last
   * (inclusive).
   *
   * Note that this function returns a `guint64`, because when all values are
   * set, the return value is `G_MAXUINT + 1`. Unless you are sure this cannot
   * happen (it can't with `Gio::ListModel`), be sure to use a 64bit type.
   *
   * @param first The first element to include.
   * @param last The last element to include.
   * @return The number of values in the set from @a first to @a last.
   */
  auto get_size(guint first, guint last) const -> guint64;

  /** Returns the value of the @a nth item in self.
   *
   * If @a nth is >= the size of @a self, 0 is returned.
   *
   * @param nth Index of the item to get.
   * @return The value of the @a nth item in @a self.
   */
  auto get_nth(guint nth) const -> guint;

  /** Returns <tt>true</tt> if @a self and @a other contain the same values.
   *
   * @param other Another `Gtk::Bitset`.
   * @return <tt>true</tt> if @a self and @a other contain the same values.
   */
  auto equals(const Glib::RefPtr<const Bitset>& other) const -> bool;

  /** Returns the smallest value in @a self.
   *
   * If @a self is empty, `G_MAXUINT` is returned.
   *
   * @return The smallest value in @a self.
   */
  auto get_minimum() const -> guint;

  /** Returns the largest value in @a self.
   *
   * If @a self is empty, 0 is returned.
   *
   * @return The largest value in @a self.
   */
  auto get_maximum() const -> guint;

  /** Creates a copy of @a self.
   *
   * @return A new bitset that contains the same
   * values as @a self.
   */
  auto copy() const -> Glib::RefPtr<Bitset>;

  /** Removes all values from the bitset so that it is empty again.
   */
  void remove_all();

  /** Adds @a value to @a self if it wasn't part of it before.
   *
   * @param value Value to add.
   * @return <tt>true</tt> if @a value was not part of @a self and @a self
   * was changed.
   */
  auto add(guint value) -> bool;

  /** Removes @a value from @a self if it was part of it before.
   *
   * @param value Value to add.
   * @return <tt>true</tt> if @a value was part of @a self and @a self
   * was changed.
   */
  auto remove(guint value) -> bool;

  /** Adds all values from @a start (inclusive) to @a start + @a n_items
   * (exclusive) in @a self.
   *
   * @param start First value to add.
   * @param n_items Number of consecutive values to add.
   */
  void add_range(guint start, guint n_items);

  /** Removes all values from @a start (inclusive) to @a start + @a n_items (exclusive)
   * in @a self.
   *
   * @param start First value to remove.
   * @param n_items Number of consecutive values to remove.
   */
  void remove_range(guint start, guint n_items);

  /** Adds the closed range [ @a first, @a last], so @a first, @a last and all
   * values in between. @a first must be smaller than @a last.
   *
   * @param first First value to add.
   * @param last Last value to add.
   */
  void add_range_closed(guint first, guint last);

  /** Removes the closed range [ @a first, @a last], so @a first, @a last and all
   * values in between. @a first must be smaller than @a last.
   *
   * @param first First value to remove.
   * @param last Last value to remove.
   */
  void remove_range_closed(guint first, guint last);

  /** Interprets the values as a 2-dimensional boolean grid with the given @a stride
   * and inside that grid, adds a rectangle with the given @a width and @a height.
   *
   * @param start First value to add.
   * @param width Width of the rectangle.
   * @param height Height of the rectangle.
   * @param stride Row stride of the grid.
   */
  void add_rectangle(guint start, guint width, guint height, guint stride);

  /** Interprets the values as a 2-dimensional boolean grid with the given @a stride
   * and inside that grid, removes a rectangle with the given @a width and @a height.
   *
   * @param start First value to remove.
   * @param width Width of the rectangle.
   * @param height Height of the rectangle.
   * @param stride Row stride of the grid.
   */
  void remove_rectangle(guint start, guint width, guint height, guint stride);
  // 'union' is a C and C++ keyword. Can't be a method name. (see also Gdk::Rectangle)

  /** Sets @a self to be the union of @a self and @a other.
   *
   * That is, add all values from @a other into @a self that weren't part of it.
   *
   * It is allowed for @a self and @a other to be the same bitset. Nothing will
   * happen in that case.
   *
   * @param other The `Gtk::Bitset` to union with.
   */
  void join(const Glib::RefPtr<const Bitset>& other);

  /** Sets @a self to be the intersection of @a self and @a other.
   *
   * In other words, remove all values from @a self that are not part of @a other.
   *
   * It is allowed for @a self and @a other to be the same bitset. Nothing will
   * happen in that case.
   *
   * @param other The `Gtk::Bitset` to intersect with.
   */
  void intersect(const Glib::RefPtr<const Bitset>& other);

  /** Sets @a self to be the subtraction of @a other from @a self.
   *
   * In other words, remove all values from @a self that are part of @a other.
   *
   * It is allowed for @a self and @a other to be the same bitset. The bitset
   * will be emptied in that case.
   *
   * @param other The `Gtk::Bitset` to subtract.
   */
  void subtract(const Glib::RefPtr<const Bitset>& other);

  /** Sets @a self to be the symmetric difference of @a self and @a other.
   *
   * The symmetric difference is set @a self to contain all values that
   * were either contained in @a self or in @a other, but not in both.
   * This operation is also called an XOR.
   *
   * It is allowed for @a self and @a other to be the same bitset. The bitset
   * will be emptied in that case.
   *
   * @param other The `Gtk::Bitset` to compute the difference from.
   */
  void difference(const Glib::RefPtr<const Bitset>& other);

  /** Shifts all values in @a self to the left by @a amount.
   *
   * Values smaller than @a amount are discarded.
   *
   * @param amount Amount to shift all values to the left.
   */
  void shift_left(guint amount);

  /** Shifts all values in @a self to the right by @a amount.
   *
   * Values that end up too large to be held in a <tt>unsigned int</tt> are discarded.
   *
   * @param amount Amount to shift all values to the right.
   */
  void shift_right(guint amount);

  /** This is a support function for `Gio::ListModel` handling, by mirroring
   * the `GlistModel::items-changed` signal.
   *
   * First, it "cuts" the values from @a position to @a removed from
   * the bitset. That is, it removes all those values and shifts
   * all larger values to the left by @a removed places.
   *
   * Then, it "pastes" new room into the bitset by shifting all values
   * larger than @a position by @a value spaces to the right. This frees
   * up space that can then be filled.
   *
   * @param position Position at which to slice.
   * @param removed Number of values to remove.
   * @param value Number of values to add.
   */
  void splice(guint position, guint removed, guint value);


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
 * @relates Gtk::Bitset
 */
GTKMM_API
auto wrap(GtkBitset* object, bool take_copy = false) -> Glib::RefPtr<Gtk::Bitset>;

} // namespace Glib


#endif /* _GTKMM_BITSET_H */

