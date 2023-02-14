#ifndef _GLIBMM_CONTAINERHANDLE_SHARED_H
#define _GLIBMM_CONTAINERHANDLE_SHARED_H

#include <glib-object.h>
#include <libmm-glib/debug.hxx>
#include <libmm-glib/mm-glibconfig.hxx>
#include <libmm-glib/refptr.hxx>
#include <libmm-glib/ustring.hxx>
#include <libmm-glib/variant.hxx>
#include <libmm-glib/wrap.hxx>

#include <algorithm>
#include <cstddef>
#include <deque>
#include <iterator>
#include <list>
#include <vector>

namespace Glib
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

      static void
      release_c_type (const CType&)
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
        return Glib::unwrap (ptr);
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
        return dynamic_cast<CppType> (Glib::wrap_auto (cobj, false));
      }

      static void
      release_c_type (CType ptr)
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
        return Glib::unwrap (ptr);
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
        return dynamic_cast<CppType> (Glib::wrap_auto (cobj, false));
      }

      static void
      release_c_type (CType ptr)
      {
        GLIBMM_DEBUG_UNREFERENCE (nullptr, ptr);
        g_object_unref (const_cast<CTypeNonConst> (ptr));
      }
    };
    #endif

    template <class T>
    struct TypeTraits<Glib::RefPtr<T>>
    {
      using CppType = Glib::RefPtr<T>;
      using CType = typename T::BaseObjectType*;
      using CTypeNonConst = typename T::BaseObjectType*;

      static auto
      to_c_type (const CppType& ptr) -> CType
      {
        return Glib::unwrap (ptr);
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
        return Glib::make_refptr_for_instance<T> (
            dynamic_cast<T*> (Glib::wrap_auto (cobj, true)));
      }

      static void
      release_c_type (CType ptr)
      {
        GLIBMM_DEBUG_UNREFERENCE (nullptr, ptr);
        g_object_unref (ptr);
      }
    };

    #ifdef GLIBMM_HAVE_DISAMBIGUOUS_CONST_TEMPLATE_SPECIALIZATIONS

    template <class T>
    struct TypeTraits<Glib::RefPtr<const T>>
    {
      using CppType = Glib::RefPtr<const T>;
      using CType = const typename T::BaseObjectType*;
      using CTypeNonConst = typename T::BaseObjectType*;

      static auto
      to_c_type (const CppType& ptr) -> CType
      {
        return Glib::unwrap (ptr);
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
        return Glib::make_refptr_for_instance<const T> (
            dynamic_cast<const T*> (Glib::wrap_auto (cobj, true)));
      }

      static void
      release_c_type (CType ptr)
      {
        GLIBMM_DEBUG_UNREFERENCE (nullptr, ptr);
        g_object_unref (const_cast<CTypeNonConst> (ptr));
      }
    };

    #endif

  #endif

    template <>
    struct TypeTraits<Glib::ustring>
    {
      using CppType = Glib::ustring;
      using CType = const char*;
      using CTypeNonConst = char*;

      static auto
      to_c_type (const Glib::ustring& str) -> CType
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
        return (str) ? Glib::ustring (str) : Glib::ustring ();
      }

      static void
      release_c_type (CType str)
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
      to_c_type (const Glib::ustring& str) -> CType
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

      static void
      release_c_type (CType str)
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

      static void
      release_c_type (CType)
      {
      }
    };

    template <>
    struct TypeTraits<Glib::VariantBase>
    {
      using CppType = Glib::VariantBase;
      using CType = GVariant*;
      using CTypeNonConst = GVariant*;

      static auto
      to_c_type (const Glib::VariantBase& v) -> CType
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
        return Glib::VariantBase (v, true);
      }

      static void
      release_c_type (CType v)
      {
        g_variant_unref (const_cast<CTypeNonConst> (v));
      }
    };

    template <>
    struct TypeTraits<Glib::VariantContainerBase>
    {
      using CppType = Glib::VariantContainerBase;
      using CType = GVariant*;
      using CTypeNonConst = GVariant*;

      static auto
      to_c_type (const Glib::VariantContainerBase& v) -> CType
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
        return Glib::VariantContainerBase (v, true);
      }

      static void
      release_c_type (CType v)
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

} // namespace Glib

#endif
