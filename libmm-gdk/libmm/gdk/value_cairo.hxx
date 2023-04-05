// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GDKMM_VALUE_CAIRO_H
#define _GDKMM_VALUE_CAIRO_H

#include <libmm/gdk/mm-gdkconfig.hxx>

#include <libmm/cairo/refptr.hxx>
#include <libmm/glib/value.hxx>
#include <type_traits>

namespace cairo
{
  class LIBMM_GDK_SYMEXPORT Region;
  class LIBMM_GDK_SYMEXPORT Surface;
} // namespace cairo

namespace gdk
{
  namespace cairo
  {

#ifndef DOXYGEN_SHOULD_SKIP_THIS
    template <typename T>
    auto
    get_base_type () -> GType
    {
      static_assert (!std::is_same<T, T>::value,
                     "No specialization available for type T.");
      return 0;
    }

    template <>
    LIBMM_GDK_SYMEXPORT auto
    get_base_type<::cairo::Region> () -> GType;

    template <>
    LIBMM_GDK_SYMEXPORT auto
    get_base_type<::cairo::Surface> () -> GType;
#endif

  } // namespace cairo

} // namespace gdk

namespace glib
{

  template <typename T>
  class Value<::cairo::RefPtr<T>,
              typename std::enable_if<
                  std::is_base_of<::cairo::Region, T>::value ||
                  std::is_base_of<::cairo::Surface, T>::value>::type>
    : public ValueBase_Boxed
  {
  public:
    using CppType = ::cairo::RefPtr<T>;
    using CType = typename T::cobject;

    static auto
    value_type () -> GType
    {
      return gdk::cairo::get_base_type<std::remove_const_t<T>> ();
    }

    auto
    set (const CppType& data) -> void
    {
      set_boxed (data->cobj ());
    }

    auto
    get () const -> CppType
    {
      CType* CObj = static_cast<CType*> (get_boxed ());
      T* CppObj = new T (CObj, false);
      return ::cairo::make_refptr_for_instance<T> (CppObj);
    }
  };

} // namespace glib

#endif
