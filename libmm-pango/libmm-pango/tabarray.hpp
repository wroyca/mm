
#ifndef _PANGOMM_TABARRAY_H
#define _PANGOMM_TABARRAY_H


#include <libmm-glib/ustring.hpp>
#include <sigc++/sigc++.h>

/* tabarray.h
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

#include <libmm-pango/attrlist.hpp>
#include <pango/pango.h>
#include <utility>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
extern "C" { typedef struct _PangoTabArray PangoTabArray; }
#endif

namespace Pango
{

/** @addtogroup pangommEnums pangomm Enums and Flags */

/**
 *  @var TabAlign LEFT
 * The text appears to the right of the tab stop position.
 *
 *  @var TabAlign RIGHT
 * The text appears to the left of the tab stop position
 * until the available space is filled.
 *
 *  @var TabAlign CENTER
 * The text is centered at the tab stop position
 * until the available space is filled.
 *
 *  @var TabAlign DECIMAL
 * Text before the first '.' appears to the left of the
 * tab stop position (until the available space is filled), the rest to
 * the right.
 *
 *  @enum TabAlign
 *
 * `Pango::TabAlign` specifies where the text appears relative to the tab stop
 * position.
 *
 * Support for tab alignments other than Pango::TabAlign::LEFT was added
 * in Pango 1.50.
 *
 * @ingroup pangommEnums
 */
enum class TabAlign
{
  LEFT,
  RIGHT,
  CENTER,
  DECIMAL
};


} // namespace Pango

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

template <>
class PANGOMM_API Value<Pango::TabAlign> : public Glib::Value_Enum<Pango::TabAlign>
{
public:
  static auto value_type() -> GType G_GNUC_CONST;
};

} // namespace Glib
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

namespace Pango
{


/** A Pango::TabArray contains an array of tab stops.
 * Each tab stop has an alignment and a position.
 */
class PANGOMM_API TabArray
{
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  using CppObjectType = TabArray;
  using BaseObjectType = PangoTabArray;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType G_GNUC_CONST;

  TabArray();

  explicit TabArray(PangoTabArray* gobject, bool make_a_copy = true);

  TabArray(const TabArray& other);
  auto operator=(const TabArray& other) -> TabArray&;

  TabArray(TabArray&& other) noexcept;
  auto operator=(TabArray&& other) noexcept -> TabArray&;

  ~TabArray() noexcept;

  void swap(TabArray& other) noexcept;

  ///Provides access to the underlying C instance.
  auto       gobj() -> PangoTabArray*       { return gobject_; }

  ///Provides access to the underlying C instance.
  auto gobj() const -> const PangoTabArray* { return gobject_; }

  ///Provides access to the underlying C instance. The caller is responsible for freeing it. Use when directly setting fields in structs.
  auto gobj_copy() const -> PangoTabArray*;

protected:
  PangoTabArray* gobject_;

private:


public:
  explicit TabArray(int initial_size, bool positions_in_pixels = true);


  /** Gets the number of tab stops in @a tab_array.
   *
   * @return The number of tab stops in the array.
   */
  auto get_size() const -> int;

  /** Resizes a tab array.
   *
   * You must subsequently initialize any tabs
   * that were added as a result of growing the array.
   *
   * @param new_size New size of the array.
   */
  void resize(int new_size);

  /** Sets the alignment and location of a tab stop.
   *
   * @param tab_index The index of a tab stop.
   * @param alignment Tab alignment.
   * @param location Tab location in Pango units.
   */
  void set_tab(int tab_index, TabAlign alignment, int location);

  /** Gets the alignment and position of a tab stop.
   * @return An std::pair<TabAlign, int>. The first element represents the tab stop alignment, the second one is the tab position.
   */
  auto get_tab(int tab_index) const -> std::pair<TabAlign, int>;

  /** Gets an array of std::pairs containing the tab stop alignments and tab positions.
   * @return An array of std::pair<TabAlign, int>. The first element in each pair represents the tab stop alignment, the second one is the tab position.
   */
  auto get_tabs() const -> std::vector<std::pair<TabAlign, int>>;


  /** Returns <tt>true</tt> if the tab positions are in pixels,
   * <tt>false</tt> if they are in Pango units.
   *
   * @return Whether positions are in pixels.
   */
  auto get_positions_in_pixels() const -> bool;


};

} //namespace Pango


namespace Pango
{

/** @relates Pango::TabArray
 * @param lhs The left-hand side
 * @param rhs The right-hand side
 */
inline void swap(TabArray& lhs, TabArray& rhs) noexcept
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
 * @relates Pango::TabArray
 */
PANGOMM_API
auto wrap(PangoTabArray* object, bool take_copy = false) -> Pango::TabArray;

#ifndef DOXYGEN_SHOULD_SKIP_THIS
template <>
class PANGOMM_API Value<Pango::TabArray> : public Glib::Value_Boxed<Pango::TabArray>
{};
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

} // namespace Glib


#endif /* _PANGOMM_TABARRAY_H */

