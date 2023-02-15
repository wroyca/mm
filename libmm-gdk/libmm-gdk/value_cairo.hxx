// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GDKMM_VALUE_CAIRO_H
#define _GDKMM_VALUE_CAIRO_H

#include <libmm-gdk/mm-gdkconfig.hxx>

#include <libmm-cairo/refptr.hxx>
#include <libmm-glib/value.hxx>
#include <type_traits>

namespace Cairo
{
  class GDKMM_API Region;
  class GDKMM_API Surface;
} // namespace Cairo

namespace Gdk
{
  namespace Cairo
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
    GDKMM_API auto
    get_base_type<::Cairo::Region> () -> GType;

    template <>
    GDKMM_API auto
    get_base_type<::Cairo::Surface> () -> GType;
#endif

  } // namespace Cairo

} // namespace Gdk

namespace Glib
{

  template <typename T>
  class Value<::Cairo::RefPtr<T>,
              typename std::enable_if<
                  std::is_base_of<::Cairo::Region, T>::value ||
                  std::is_base_of<::Cairo::Surface, T>::value>::type>
    : public ValueBase_Boxed
  {
  public:
    using CppType = ::Cairo::RefPtr<T>;
    using CType = typename T::cobject;

    static auto
    value_type () -> GType
    {
      return Gdk::Cairo::get_base_type<std::remove_const_t<T>> ();
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
      return ::Cairo::make_refptr_for_instance<T> (CppObj);
    }
  };

} // namespace Glib

#endif
