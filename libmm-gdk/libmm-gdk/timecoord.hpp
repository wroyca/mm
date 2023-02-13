
#ifndef _GDKMM_TIMECOORD_H
#define _GDKMM_TIMECOORD_H

#include <libmm-gdk/mm-gdkconfig.hpp>


#include <libmm-glib/ustring.hpp>
#include <sigc++/sigc++.h>

/* Copyright (C) 2011 The gtkmm Development Team
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


#include <gdk/gdk.h>


namespace Gdk
{

/** A Gdk::TimeCoord instance contains a single event of motion history.
 * You shouldn't be using it as a standalone object.
 */
class GDKMM_API TimeCoord
{
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  using CppObjectType = TimeCoord;
  using BaseObjectType = GdkTimeCoord;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

private:

public:
  explicit TimeCoord(GdkTimeCoord* gobject, bool make_a_copy = true);

  TimeCoord(const TimeCoord& other);
  auto operator=(const TimeCoord& other) -> TimeCoord&;

  TimeCoord(TimeCoord&& other) noexcept;
  auto operator=(TimeCoord&& other) noexcept -> TimeCoord&;

  ~TimeCoord() noexcept;

  auto get_time() const -> guint32;

  /** Gets value at @a index axis.
   * @note
   * Gdk::Device::get_n_axes() will tell you how many axes are stored here.
   *
   * @param index Index of an axis from which the value will be taken.
   * @return A value at @a index.
   */
  auto get_value_at_axis(guint index) const -> double;

  ///Provides access to the underlying C object.
  auto gobj() -> GdkTimeCoord* {return gobject_;}
  ///Provides access to the underlying C object.
  auto gobj() const -> const GdkTimeCoord* {return gobject_;}
protected:
  GdkTimeCoord* gobject_;


};

#ifndef DOXYGEN_SHOULD_SKIP_THIS
/* These traits are for arrays of GdkTimeCoord* pointers.
 */
struct TimeCoordPtrTraits
{
  using CppType = Gdk::TimeCoord;
  using CType = GdkTimeCoord*;
  using CTypeNonConst = GdkTimeCoord*;

  static auto to_c_type(const CppType& obj) -> CType { return const_cast<CType>(obj.gobj()); }
  static auto to_c_type(const CType& obj) -> CType { return obj; }
  static auto to_cpp_type(const CType& obj) -> CppType { return CppType(const_cast<CType>(obj)); }
  static void release_c_type(const CType& obj) { g_free(const_cast<CType>(obj)); }
};

/* These traits are for arrays of GdkTimeCoord structs -- not pointer arrays.
 */
struct TimeCoordTraits
{
  using CppType = Gdk::TimeCoord;
  using CType = GdkTimeCoord;
  using CTypeNonConst = GdkTimeCoord;

  static auto to_c_type(const CppType& obj) -> CType { return *obj.gobj(); }
  static auto to_c_type(const CType& obj) -> CType { return obj; }
  static auto to_cpp_type(const CType& obj) -> CppType { return CppType(const_cast<CType*>(&obj), true); }
  static void release_c_type(const CType&) {}
};
#endif //DOXYGEN_SHOULD_SKIP_THIS

} // namespace Gdk


#endif /* _GDKMM_TIMECOORD_H */

