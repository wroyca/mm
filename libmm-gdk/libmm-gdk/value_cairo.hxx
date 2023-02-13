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

#ifndef _GDKMM_VALUE_CAIRO_H
#define _GDKMM_VALUE_CAIRO_H

#include <libmm-gdk/mm-gdkconfig.hxx>

#include <libmm-glib/value.hxx>
#include <libmm-cairo/refptr.hxx>
#include <type_traits>

namespace Cairo
{
class GDKMM_API Region;
class GDKMM_API Surface;
}

namespace Gdk::Cairo
{

#ifndef DOXYGEN_SHOULD_SKIP_THIS
template <typename T>
auto get_base_type() -> GType
{
  static_assert(!std::is_same<T,T>::value, "No specialization available for type T.");
  return 0;
}

template <>
GDKMM_API auto get_base_type<::Cairo::Region>() -> GType;

template <>
GDKMM_API auto get_base_type<::Cairo::Surface>() -> GType;
#endif // DOXYGEN_SHOULD_SKIP_THIS

} //namespace Gdk

namespace Glib
{
/** Specialization of Glib::Value<> for Cairo::RefPtr<Cairo::Region>
 * and Cairo::RefPtr<Cairo::Surface>.
 */
template <typename T>
class Value<::Cairo::RefPtr<T>, typename std::enable_if<
  std::is_base_of<::Cairo::Region, T>::value ||
  std::is_base_of<::Cairo::Surface, T>::value>::type>
: public ValueBase_Boxed
{
public:
  using CppType = ::Cairo::RefPtr<T>;
  using CType = typename T::cobject;

  static auto value_type() -> GType
  {
    return Gdk::Cairo::get_base_type<std::remove_const_t<T>>();
  }

  void set(const CppType& data) { set_boxed(data->cobj()); }

  auto get() const -> CppType
  {
    CType* CObj = static_cast<CType*>(get_boxed());
    T* CppObj = new T(CObj, false); // false == take reference
    return ::Cairo::make_refptr_for_instance<T>(CppObj);
  }
};

} //namespace Glib

#endif //_GDKMM_VALUE_CAIRO_H
