// Generated by gmmproc 2.74.0 -- DO NOT MODIFY!
#ifndef _GTKMM_SORTER_H
#define _GTKMM_SORTER_H


#include <mm/glib/ustring.hpp>
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

#include <mm/glib/object.hpp>
#include <mm/gtk/enums.hpp>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkSorter = struct _GtkSorter;
using GtkSorterClass = struct _GtkSorterClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{ class GTKMM_API Sorter_Class; } // namespace Gtk
#endif //DOXYGEN_SHOULD_SKIP_THIS

namespace Gtk
{

/** Sorting items.
 *
 * %Gtk::Sorter is the way to describe sorting criteria.
 * Its primary user is Gtk::SortListModel.
 *
 * The model will use a sorter to determine the order in which its items should appear
 * by calling compare() for pairs of items.
 *
 * Sorters may change their sorting behavior through their lifetime. In that case,
 * they will emit the signal_changed() signal to notify that the sort order is
 * no longer valid and should be updated by calling compare() again.
 *
 * GTK provides various pre-made sorter implementations for common sorting operations.
 * Gtk::ColumnView has built-in support for sorting lists via the
 * Gtk::ColumnViewColumn::property_sorter(), where the user can change the sorting by
 * clicking on list headers.
 *
 * Of course, in particular for large lists, it is also possible to subclass %Gtk::Sorter
 * and provide one's own sorter.
 *
 * @see Gtk::SortListModel
 * @newin{3,98}
 */

class GTKMM_API Sorter : public Glib::Object
{

#ifndef DOXYGEN_SHOULD_SKIP_THIS

public:
  using CppObjectType = Sorter;
  using CppClassType = Sorter_Class;
  using BaseObjectType = GtkSorter;
  using BaseClassType = GtkSorterClass;

  // noncopyable
  Sorter(const Sorter&) = delete;
  auto operator=(const Sorter&) -> Sorter& = delete;

private:  friend class Sorter_Class;
  static CppClassType sorter_class_;

protected:
  explicit Sorter(const Glib::ConstructParams& construct_params);
  explicit Sorter(GtkSorter* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  Sorter(Sorter&& src) noexcept;
  auto operator=(Sorter&& src) noexcept -> Sorter&;

  ~Sorter() noexcept override;

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS


  static auto get_base_type() -> GType G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GObject.
  auto       gobj() -> GtkSorter*       { return reinterpret_cast<GtkSorter*>(gobject_); }

  ///Provides access to the underlying C GObject.
  auto gobj() const -> const GtkSorter* { return reinterpret_cast<GtkSorter*>(gobject_); }

  ///Provides access to the underlying C instance. The caller is responsible for unrefing it. Use when directly setting fields in structs.
  auto gobj_copy() -> GtkSorter*;

private:


protected:
  Sorter();

public:
  /** @addtogroup gtkmmEnums gtkmm Enums and Flags */

  /**
   *  @var Order PARTIAL
   * A partial order. Any `Gtk::Ordering` is possible.
   *
   *  @var Order NONE
   * No order, all elements are considered equal.
   * Gtk::Sorter::compare() will only return Gtk::Ordering::EQUAL.
   *
   *  @var Order TOTAL
   * A total order. Gtk::Sorter::compare() will only
   * return Gtk::Ordering::EQUAL if an item is compared with itself. Two
   * different items will never cause this value to be returned.
   *
   *  @enum Order
   *
   * Describes the type of order that a `Gtk::Sorter` may produce.
   *
   * @ingroup gtkmmEnums
   */
  enum class Order
  {
    PARTIAL,
    NONE,
    TOTAL
  };


  /**
   *  @var Change DIFFERENT
   * The sorter change cannot be described
   * by any of the other enumeration values.
   *
   *  @var Change INVERTED
   * The sort order was inverted. Comparisons
   * that returned Gtk::Ordering::SMALLER now return Gtk::Ordering::LARGER
   * and vice versa. Other comparisons return the same values as before.
   *
   *  @var Change LESS_STRICT
   * The sorter is less strict: Comparisons
   * may now return Gtk::Ordering::EQUAL that did not do so before.
   *
   *  @var Change MORE_STRICT
   * The sorter is more strict: Comparisons
   * that did return Gtk::Ordering::EQUAL may not do so anymore.
   *
   *  @enum Change
   *
   * Describes changes in a sorter in more detail and allows users
   * to optimize resorting.
   *
   * @ingroup gtkmmEnums
   */
  enum class Change
  {
    DIFFERENT,
    INVERTED,
    LESS_STRICT,
    MORE_STRICT
  };


  /** Compares two given items according to the sort order implemented
   * by the sorter.
   *
   * Sorters implement a partial order:
   *
   * * It is reflexive, ie a = a
   * * It is antisymmetric, ie if a < b and b < a, then a = b
   * * It is transitive, ie given any 3 items with a ≤ b and b ≤ c,
   * then a ≤ c
   *
   * The sorter may signal it conforms to additional constraints
   * via the return value of get_order().
   *
   * @param item1 First item to compare.
   * @param item2 Second item to compare.
   * @return Gtk::Ordering::EQUAL if @a item1 == @a item2,
   * Gtk::Ordering::SMALLER if @a item1 < @a item2,
   * Gtk::Ordering::LARGER if @a item1 > @a item2.
   */
  auto compare(gpointer item1, gpointer item2) -> Ordering;

  /** Gets the order that @a self conforms to.
   *
   * See Gtk::SorterOrder for details
   * of the possible return values.
   *
   * This function is intended to allow optimizations.
   *
   * @return The order.
   */
  auto get_order() const -> Order;

  /** Notifies all users of the sorter that it has changed.
   *
   * This emits the signal_changed() signal. Users
   * of the sorter should then update the sort order via
   * compare().
   *
   * Depending on the @a change parameter, it may be possible to
   * update the sort order without a full resorting. Refer to
   * the Gtk::SorterChange documentation for details.
   *
   * This function is intended for implementors of `Gtk::Sorter`
   * subclasses and should not be called from other functions.
   *
   * @param change How the sorter changed.
   */
  void changed(Change change);


  /**
   * @par Slot Prototype:
   * <tt>void on_my_%changed(Change change)</tt>
   *
   * Flags: Run Last
   *
   * Emitted whenever the sorter changed.
   *
   * Users of the sorter should then update the sort order
   * again via Gtk::Sorter::compare().
   *
   * Gtk::SortListModel handles this signal automatically.
   *
   * Depending on the @a change parameter, it may be possible to update
   * the sort order without a full resorting. Refer to the
   * Gtk::SorterChange documentation for details.
   *
   * @param change How the sorter changed.
   */

  auto signal_changed() -> Glib::SignalProxy<void(Change)>;


protected:
    virtual auto compare_vfunc(gpointer item1, gpointer item2) -> Ordering;

    virtual auto get_order_vfunc() -> Order;


public:

public:
  //C++ methods used to invoke GTK+ virtual functions:

protected:
  //GTK+ Virtual Functions (override these to change behaviour):

  //Default Signal Handlers::


};

} // namespace Gtk


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

template <>
class GTKMM_API Value<Gtk::Sorter::Order> : public Glib::Value_Enum<Gtk::Sorter::Order>
{
public:
  static auto value_type() -> GType G_GNUC_CONST;
};

} // namespace Glib
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

template <>
class GTKMM_API Value<Gtk::Sorter::Change> : public Glib::Value_Enum<Gtk::Sorter::Change>
{
public:
  static auto value_type() -> GType G_GNUC_CONST;
};

} // namespace Glib
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


namespace Glib
{
  /** A Glib::wrap() method for this object.
   *
   * @param object The C instance.
   * @param take_copy False if the result should take ownership of the C instance. True if it should take a new copy or ref.
   * @result A C++ instance that wraps this C instance.
   *
   * @relates Gtk::Sorter
   */
  GTKMM_API
  auto wrap(GtkSorter* object, bool take_copy = false) -> Glib::RefPtr<Gtk::Sorter>;
}


#endif /* _GTKMM_SORTER_H */

