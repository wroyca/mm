// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GDKMM_CAIROUTILS_H
#define _GDKMM_CAIROUTILS_H

#include <libmm/gdk/mm-gdkconfig.hxx>

#include <libmm/cairo/context.hxx>
#include <libmm/cairo/region.hxx>
#include <libmm/cairo/surface.hxx>
#include <libmm/glib/containerhandle_shared.hxx>
#include <type_traits>

namespace Gdk
{
  namespace Cairo
  {
    LIBMM_GDK_SYMEXPORT auto
    wrap (cairo_t* cobject, bool has_reference = true)
        -> ::Cairo::RefPtr<::Cairo::Context>;

    LIBMM_GDK_SYMEXPORT auto
    wrap (cairo_region_t* cobject, bool has_reference = true)
        -> ::Cairo::RefPtr<::Cairo::Region>;

    template <
        typename T = ::Cairo::Surface,
        typename = std::enable_if<std::is_base_of<::Cairo::Surface, T>::value>>
    auto
    wrap (cairo_surface_t* cobject, bool has_reference = true)
        -> ::Cairo::RefPtr<T>
    {
      return ::Cairo::make_refptr_for_instance<T> (
          cobject ? new T (cobject, has_reference) : nullptr);
    }

  } // namespace Cairo
} // namespace Gdk

namespace Glib
{
  namespace Container_Helpers
  {

    template <>
    struct TypeTraits<::Cairo::RefPtr<::Cairo::Surface>>
    {
      using CppType = ::Cairo::RefPtr<::Cairo::Surface>;
      using CType = ::Cairo::Surface::cobject*;
      using CTypeNonConst = ::Cairo::Surface::cobject*;

      static auto
      to_c_type (const CppType& ptr) -> CType
      {
        return ptr ? ptr->cobj () : nullptr;
      }

      static auto
      to_c_type (CType ptr) -> CType
      {
        return ptr;
      }

      static auto
      to_cpp_type (CType ptr) -> CppType
      {
        return Gdk::Cairo::wrap (ptr, false);
      }

      static auto
      release_c_type (CType ptr) -> void
      {
        cairo_surface_destroy (ptr);
      }
    };

    template <>
    struct TypeTraits<::Cairo::RefPtr<const ::Cairo::Surface>>
    {
      using CppType = Cairo::RefPtr<const ::Cairo::Surface>;
      using CType = const ::Cairo::Surface::cobject*;
      using CTypeNonConst = ::Cairo::Surface::cobject*;

      static auto
      to_c_type (const CppType& ptr) -> CType
      {
        return ptr ? ptr->cobj () : nullptr;
      }

      static auto
      to_c_type (CType ptr) -> CType
      {
        return ptr;
      }

      static auto
      to_cpp_type (CType ptr) -> CppType
      {
        return Gdk::Cairo::wrap (const_cast<CTypeNonConst> (ptr), false);
      }

      static auto
      release_c_type (CType ptr) -> void
      {
        cairo_surface_destroy (const_cast<CTypeNonConst> (ptr));
      }
    };

  } // namespace Container_Helpers
} // namespace Glib

#endif
