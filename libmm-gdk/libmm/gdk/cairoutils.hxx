// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GDKMM_CAIROUTILS_H
#define _GDKMM_CAIROUTILS_H

#include <libmm/gdk/mm-gdkconfig.hxx>

#include <libmm/cairo/context.hxx>
#include <libmm/cairo/region.hxx>
#include <libmm/cairo/surface.hxx>
#include <libmm/glib/containerhandle_shared.hxx>
#include <type_traits>

namespace gdk
{
  namespace cairo
  {
    LIBMM_GDK_SYMEXPORT auto
    wrap (cairo_t* cobject, bool has_reference = true)
        -> ::cairo::RefPtr<::cairo::Context>;

    LIBMM_GDK_SYMEXPORT auto
    wrap (cairo_region_t* cobject, bool has_reference = true)
        -> ::cairo::RefPtr<::cairo::Region>;

    template <
        typename T = ::cairo::Surface,
        typename = std::enable_if<std::is_base_of<::cairo::Surface, T>::value>>
    auto
    wrap (cairo_surface_t* cobject, bool has_reference = true)
        -> ::cairo::RefPtr<T>
    {
      return ::cairo::make_refptr_for_instance<T> (
          cobject ? new T (cobject, has_reference) : nullptr);
    }

  } // namespace cairo
} // namespace gdk

namespace glib
{
  namespace Container_Helpers
  {

    template <>
    struct TypeTraits<::cairo::RefPtr<::cairo::Surface>>
    {
      using CppType = ::cairo::RefPtr<::cairo::Surface>;
      using CType = ::cairo::Surface::cobject*;
      using CTypeNonConst = ::cairo::Surface::cobject*;

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
        return gdk::cairo::wrap (ptr, false);
      }

      static auto
      release_c_type (CType ptr) -> void
      {
        cairo_surface_destroy (ptr);
      }
    };

    template <>
    struct TypeTraits<::cairo::RefPtr<const ::cairo::Surface>>
    {
      using CppType = cairo::RefPtr<const ::cairo::Surface>;
      using CType = const ::cairo::Surface::cobject*;
      using CTypeNonConst = ::cairo::Surface::cobject*;

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
        return gdk::cairo::wrap (const_cast<CTypeNonConst> (ptr), false);
      }

      static auto
      release_c_type (CType ptr) -> void
      {
        cairo_surface_destroy (const_cast<CTypeNonConst> (ptr));
      }
    };

  } // namespace Container_Helpers
} // namespace glib

#endif
