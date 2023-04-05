// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GLIBMM_CONTAINERHANDLE_SHARED_H
#define _GLIBMM_CONTAINERHANDLE_SHARED_H

#include <glib-object.h>
#include <libmm/glib/debug.hxx>
#include <libmm/glib/mm-glibconfig.hxx>
#include <libmm/glib/refptr.hxx>
#include <libmm/glib/ustring.hxx>
#include <libmm/glib/variant.hxx>
#include <libmm/glib/wrap.hxx>

#include <algorithm>
#include <cstddef>
#include <deque>
#include <iterator>
#include <list>
#include <vector>

namespace glib
{

  enum OwnershipType
  {
    OWNERSHIP_NONE = 0,
    OWNERSHIP_SHALLOW,
    OWNERSHIP_DEEP
  };

  namespace Container_Helpers
  {

    template <class T>
    struct TypeTraits
    {
      using CppType = T;
      using CType = T;
      using CTypeNonConst = T;

      static auto
      to_c_type (const CppType& item) -> CType
      {
        return item;
      }

      static auto
      to_cpp_type (const CType& item) -> CppType
      {
        return item;
      }

      static auto
      release_c_type (const CType&) -> void
      {
      }
    };

#ifndef DOXYGEN_SHOULD_SKIP_THIS

  #ifdef GLIBMM_CAN_USE_DYNAMIC_CAST_IN_UNUSED_TEMPLATE_WITHOUT_DEFINITION

    template <class T>
    struct TypeTraits<T*>
    {
      using CppType = T*;
      using CType = typename T::BaseObjectType*;
      using CTypeNonConst = typename T::BaseObjectType*;

      static auto
      to_c_type (CppType ptr) -> CType
      {
        return glib::unwrap (ptr);
      }

      static auto
      to_c_type (CType ptr) -> CType
      {
        return ptr;
      }

      static auto
      to_cpp_type (CType ptr) -> CppType
      {
        GObject* cobj = (GObject*) ptr;
        return dynamic_cast<CppType> (glib::wrap_auto (cobj, false));
      }

      static auto
      release_c_type (CType ptr) -> void
      {
        GLIBMM_DEBUG_UNREFERENCE (nullptr, ptr);
        g_object_unref (ptr);
      }
    };

    #ifdef GLIBMM_HAVE_DISAMBIGUOUS_CONST_TEMPLATE_SPECIALIZATIONS

    template <class T>
    struct TypeTraits<const T*>
    {
      using CppType = const T*;
      using CType = const typename T::BaseObjectType*;
      using CTypeNonConst = typename T::BaseObjectType*;

      static auto
      to_c_type (CppType ptr) -> CType
      {
        return glib::unwrap (ptr);
      }

      static auto
      to_c_type (CType ptr) -> CType
      {
        return ptr;
      }

      static auto
      to_cpp_type (CType ptr) -> CppType
      {
        GObject* cobj = (GObject*) const_cast<CTypeNonConst> (ptr);
        return dynamic_cast<CppType> (glib::wrap_auto (cobj, false));
      }

      static auto
      release_c_type (CType ptr) -> void
      {
        GLIBMM_DEBUG_UNREFERENCE (nullptr, ptr);
        g_object_unref (const_cast<CTypeNonConst> (ptr));
      }
    };
    #endif

    template <class T>
    struct TypeTraits<glib::RefPtr<T>>
    {
      using CppType = glib::RefPtr<T>;
      using CType = typename T::BaseObjectType*;
      using CTypeNonConst = typename T::BaseObjectType*;

      static auto
      to_c_type (const CppType& ptr) -> CType
      {
        return glib::unwrap (ptr);
      }

      static auto
      to_c_type (CType ptr) -> CType
      {
        return ptr;
      }

      static auto
      to_cpp_type (CType ptr) -> CppType
      {
        GObject* cobj = (GObject*) (ptr);
        return glib::make_refptr_for_instance<T> (
            dynamic_cast<T*> (glib::wrap_auto (cobj, true)));
      }

      static auto
      release_c_type (CType ptr) -> void
      {
        GLIBMM_DEBUG_UNREFERENCE (nullptr, ptr);
        g_object_unref (ptr);
      }
    };

    #ifdef GLIBMM_HAVE_DISAMBIGUOUS_CONST_TEMPLATE_SPECIALIZATIONS

    template <class T>
    struct TypeTraits<glib::RefPtr<const T>>
    {
      using CppType = glib::RefPtr<const T>;
      using CType = const typename T::BaseObjectType*;
      using CTypeNonConst = typename T::BaseObjectType*;

      static auto
      to_c_type (const CppType& ptr) -> CType
      {
        return glib::unwrap (ptr);
      }

      static auto
      to_c_type (CType ptr) -> CType
      {
        return ptr;
      }

      static auto
      to_cpp_type (CType ptr) -> CppType
      {
        GObject* cobj = (GObject*) const_cast<CTypeNonConst> (ptr);
        return glib::make_refptr_for_instance<const T> (
            dynamic_cast<const T*> (glib::wrap_auto (cobj, true)));
      }

      static auto
      release_c_type (CType ptr) -> void
      {
        GLIBMM_DEBUG_UNREFERENCE (nullptr, ptr);
        g_object_unref (const_cast<CTypeNonConst> (ptr));
      }
    };

    #endif

  #endif

    template <>
    struct TypeTraits<glib::ustring>
    {
      using CppType = glib::ustring;
      using CType = const char*;
      using CTypeNonConst = char*;

      static auto
      to_c_type (const glib::ustring& str) -> CType
      {
        return str.c_str ();
      }

      static auto
      to_c_type (const std::string& str) -> CType
      {
        return str.c_str ();
      }

      static auto
      to_c_type (CType str) -> CType
      {
        return str;
      }

      static auto
      to_cpp_type (CType str) -> CppType
      {
        return (str) ? glib::ustring (str) : glib::ustring ();
      }

      static auto
      release_c_type (CType str) -> void
      {
        g_free (const_cast<CTypeNonConst> (str));
      }
    };

    template <>
    struct TypeTraits<std::string>
    {
      using CppType = std::string;
      using CType = const char*;
      using CTypeNonConst = char*;

      static auto
      to_c_type (const std::string& str) -> CType
      {
        return str.c_str ();
      }

      static auto
      to_c_type (const glib::ustring& str) -> CType
      {
        return str.c_str ();
      }

      static auto
      to_c_type (CType str) -> CType
      {
        return str;
      }

      static auto
      to_cpp_type (CType str) -> CppType
      {
        return (str) ? std::string (str) : std::string ();
      }

      static auto
      release_c_type (CType str) -> void
      {
        g_free (const_cast<CTypeNonConst> (str));
      }
    };

    template <>
    struct TypeTraits<bool>
    {
      using CppType = bool;
      using CType = gboolean;
      using CTypeNonConst = gboolean;

      static auto
      to_c_type (CppType item) -> CType
      {
        return static_cast<CType> (item);
      }

      static auto
      to_c_type (CType item) -> CType
      {
        return item;
      }

      static auto
      to_cpp_type (CType item) -> CppType
      {
        return (item != 0);
      }

      static auto
      release_c_type (CType) -> void
      {
      }
    };

    template <>
    struct TypeTraits<glib::VariantBase>
    {
      using CppType = glib::VariantBase;
      using CType = GVariant*;
      using CTypeNonConst = GVariant*;

      static auto
      to_c_type (const glib::VariantBase& v) -> CType
      {
        return const_cast<CTypeNonConst> (v.gobj ());
      }

      static auto
      to_c_type (CType v) -> CType
      {
        return v;
      }

      static auto
      to_cpp_type (CType v) -> CppType
      {
        return glib::VariantBase (v, true);
      }

      static auto
      release_c_type (CType v) -> void
      {
        g_variant_unref (const_cast<CTypeNonConst> (v));
      }
    };

    template <>
    struct TypeTraits<glib::VariantContainerBase>
    {
      using CppType = glib::VariantContainerBase;
      using CType = GVariant*;
      using CTypeNonConst = GVariant*;

      static auto
      to_c_type (const glib::VariantContainerBase& v) -> CType
      {
        return const_cast<CTypeNonConst> (v.gobj ());
      }

      static auto
      to_c_type (CType v) -> CType
      {
        return v;
      }

      static auto
      to_cpp_type (CType v) -> CppType
      {
        return glib::VariantContainerBase (v, true);
      }

      static auto
      release_c_type (CType v) -> void
      {
        g_variant_unref (const_cast<CTypeNonConst> (v));
      }
    };

  #ifndef GLIBMM_HAVE_TEMPLATE_SEQUENCE_CTORS

    template <class Cont, class In>
    void
    fill_container (Cont& container, In pbegin, In pend)
    {
      for (; pbegin != pend; ++pbegin)
        container.emplace_back (*pbegin);
    }

  #endif
#endif

  } // namespace Container_Helpers

} // namespace glib

#endif
