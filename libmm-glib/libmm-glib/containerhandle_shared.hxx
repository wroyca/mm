#ifndef _GLIBMM_CONTAINERHANDLE_SHARED_H
#define _GLIBMM_CONTAINERHANDLE_SHARED_H

/* Copyright (C) 2002 The gtkmm Development Team
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
 * License along with this library.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <libmm-glib/mm-glibconfig.hxx>
#include <libmm-glib/refptr.hxx>
#include <libmm-glib/ustring.hxx>
#include <libmm-glib/variant.hxx>
#include <libmm-glib/wrap.hxx>
#include <libmm-glib/debug.hxx>
#include <glib-object.h>

#include <cstddef>
#include <algorithm>
#include <iterator>
#include <vector>
#include <deque>
#include <list>

namespace Glib
{

/** @defgroup ContHandles Generic container converters
 */

/**
 * @ingroup ContHandles
 */

//! Ownership of the container
/*! Defines how and if the container will release the list and
 * its elemens when it is destroyed
 */
enum OwnershipType
{
  OWNERSHIP_NONE = 0, /*!< Do not release anything */
  OWNERSHIP_SHALLOW, /*!< Release the list, but not its elements, when the container is deleted */
  OWNERSHIP_DEEP /*!< Release the list, and its elements, when the container is deleted. */
};

namespace Container_Helpers
{

/** @defgroup ContHelpers Helper classes
 * @ingroup ContHandles
 */

/** Generic TypeTraits implementation.
 * @ingroup ContHelpers
 * This can be used if the C++ type is the same as the C type, or if implicit
 * conversions between the types are available.  Also, the types are required
 * to implement copy-by-value semantics.  (Ownership is just ignored.)
 */
template <class T>
struct TypeTraits
{
  using CppType = T;
  using CType = T;
  using CTypeNonConst = T;

  static auto to_c_type(const CppType& item) -> CType { return item; }
  static auto to_cpp_type(const CType& item) -> CppType { return item; }
  static void release_c_type(const CType&) {}
};

#ifndef DOXYGEN_SHOULD_SKIP_THIS /* hide the specializations */

// For some (probably, more spec-compliant) compilers, these specializations must
// be next to the objects that they use.
#ifdef GLIBMM_CAN_USE_DYNAMIC_CAST_IN_UNUSED_TEMPLATE_WITHOUT_DEFINITION

/** Partial specialization for pointers to GObject instances.
 * The C++ type is not a Glib::RefPtr<>. It can be a gtkmm widget.
 * @ingroup ContHelpers
 */
template <class T>
struct TypeTraits<T*>
{
  using CppType = T*;
  using CType = typename T::BaseObjectType*;
  using CTypeNonConst = typename T::BaseObjectType*;

  static auto to_c_type(CppType ptr) -> CType { return Glib::unwrap(ptr); }
  static auto to_c_type(CType ptr) -> CType { return ptr; }
  static auto to_cpp_type(CType ptr) -> CppType
  {
    // We copy/paste the widget wrap() implementation here,
    // because we can not use a specific Glib::wrap(T_Impl) overload here,
    // because that would be "dependent", and g++ 3.4 does not allow that.
    // The specific Glib::wrap() overloads don't do anything special anyway.
    GObject* cobj = (GObject*)ptr;
    return dynamic_cast<CppType>(Glib::wrap_auto(cobj, false /* take_copy */));
  }

  static void release_c_type(CType ptr)
  {
    GLIBMM_DEBUG_UNREFERENCE(nullptr, ptr);
    g_object_unref(ptr);
  }
};

// This confuse the SUN Forte compiler, so we ifdef it out:
#ifdef GLIBMM_HAVE_DISAMBIGUOUS_CONST_TEMPLATE_SPECIALIZATIONS

/** Partial specialization for pointers to const GObject instances.
 * The C++ type is not a Glib::RefPtr<>. It can be a gtkmm widget.
 * @ingroup ContHelpers
 */
template <class T>
struct TypeTraits<const T*>
{
  using CppType = const T*;
  using CType = const typename T::BaseObjectType*;
  using CTypeNonConst = typename T::BaseObjectType*;

  static auto to_c_type(CppType ptr) -> CType { return Glib::unwrap(ptr); }
  static auto to_c_type(CType ptr) -> CType { return ptr; }
  static auto to_cpp_type(CType ptr) -> CppType
  {
    // We copy/paste the widget wrap() implementation here,
    // because we can not use a specific Glib::wrap(T_Impl) overload here,
    // because that would be "dependent", and g++ 3.4 does not allow that.
    // The specific Glib::wrap() overloads don't do anything special anyway.
    GObject* cobj = (GObject*)const_cast<CTypeNonConst>(ptr);
    return dynamic_cast<CppType>(Glib::wrap_auto(cobj, false /* take_copy */));
  }

  static void release_c_type(CType ptr)
  {
    GLIBMM_DEBUG_UNREFERENCE(nullptr, ptr);
    g_object_unref(const_cast<CTypeNonConst>(ptr));
  }
};
#endif // GLIBMM_HAVE_DISAMBIGUOUS_CONST_TEMPLATE_SPECIALIZATIONS

/** Partial specialization for pointers to GObject instances.
 * @ingroup ContHelpers
 * The C++ type is always a Glib::RefPtr<>.
 */
template <class T>
struct TypeTraits<Glib::RefPtr<T>>
{
  using CppType = Glib::RefPtr<T>;
  using CType = typename T::BaseObjectType*;
  using CTypeNonConst = typename T::BaseObjectType*;

  static auto to_c_type(const CppType& ptr) -> CType { return Glib::unwrap(ptr); }
  static auto to_c_type(CType ptr) -> CType { return ptr; }
  static auto to_cpp_type(CType ptr) -> CppType
  {
    // return Glib::wrap(ptr, true);

    // We copy/paste the wrap() implementation here,
    // because we can not use a specific Glib::wrap(CType) overload here,
    // because that would be "dependent", and g++ 3.4 does not allow that.
    // The specific Glib::wrap() overloads don't do anything special anyway.
    GObject* cobj = (GObject*)(ptr);
    return Glib::make_refptr_for_instance<T>(dynamic_cast<T*>(Glib::wrap_auto(cobj, true /* take_copy */)));
    // We use dynamic_cast<> in case of multiple inheritance.
  }

  static void release_c_type(CType ptr)
  {
    GLIBMM_DEBUG_UNREFERENCE(nullptr, ptr);
    g_object_unref(ptr);
  }
};

// This confuse the SUN Forte compiler, so we ifdef it out:
#ifdef GLIBMM_HAVE_DISAMBIGUOUS_CONST_TEMPLATE_SPECIALIZATIONS

/** Partial specialization for pointers to const GObject instances.
 * @ingroup ContHelpers
 * The C++ type is always a Glib::RefPtr<>.
 */
template <class T>
struct TypeTraits<Glib::RefPtr<const T>>
{
  using CppType = Glib::RefPtr<const T>;
  using CType = const typename T::BaseObjectType*;
  using CTypeNonConst = typename T::BaseObjectType*;

  static auto to_c_type(const CppType& ptr) -> CType { return Glib::unwrap(ptr); }
  static auto to_c_type(CType ptr) -> CType { return ptr; }
  static auto to_cpp_type(CType ptr) -> CppType
  {
    // return Glib::wrap(ptr, true);

    // We copy/paste the wrap() implementation here,
    // because we can not use a specific Glib::wrap(CType) overload here,
    // because that would be "dependent", and g++ 3.4 does not allow that.
    // The specific Glib::wrap() overloads don't do anything special anyway.
    GObject* cobj = (GObject*)const_cast<CTypeNonConst>(ptr);
    return Glib::make_refptr_for_instance<const T>(
      dynamic_cast<const T*>(Glib::wrap_auto(cobj, true /* take_copy */)));
    // We use dynamic_cast<> in case of multiple inheritance.
  }

  static void release_c_type(CType ptr)
  {
    GLIBMM_DEBUG_UNREFERENCE(nullptr, ptr);
    g_object_unref(const_cast<CTypeNonConst>(ptr));
  }
};

#endif // GLIBMM_HAVE_DISAMBIGUOUS_CONST_TEMPLATE_SPECIALIZATIONS

#endif // GLIBMM_CAN_USE_DYNAMIC_CAST_IN_UNUSED_TEMPLATE_WITHOUT_DEFINITION

/** Specialization for UTF-8 strings.
 * @ingroup ContHelpers
 * When converting from C++ to C, Glib::ustring will be accepted as well as
 * std::string and 'const char*'.  However, when converting to the C++ side,
 * the output type cannot be 'const char*'.
 */
template <>
struct TypeTraits<Glib::ustring>
{
  using CppType = Glib::ustring;
  using CType = const char*;
  using CTypeNonConst = char*;

  static auto to_c_type(const Glib::ustring& str) -> CType { return str.c_str(); }
  static auto to_c_type(const std::string& str) -> CType { return str.c_str(); }
  static auto to_c_type(CType str) -> CType { return str; }

  static auto to_cpp_type(CType str) -> CppType { return (str) ? Glib::ustring(str) : Glib::ustring(); }

  static void release_c_type(CType str) { g_free(const_cast<CTypeNonConst>(str)); }
};

/** Specialization for std::string.
 * @ingroup ContHelpers
 * When converting from C++ to C, std::string will be accepted as well as
 * 'const char*'.  However, when converting to the C++ side, the output type
 * cannot be 'const char*'.
 */
template <>
struct TypeTraits<std::string>
{
  using CppType = std::string;
  using CType = const char*;
  using CTypeNonConst = char*;

  static auto to_c_type(const std::string& str) -> CType { return str.c_str(); }
  static auto to_c_type(const Glib::ustring& str) -> CType { return str.c_str(); }
  static auto to_c_type(CType str) -> CType { return str; }

  static auto to_cpp_type(CType str) -> CppType { return (str) ? std::string(str) : std::string(); }

  static void release_c_type(CType str) { g_free(const_cast<CTypeNonConst>(str)); }
};

/** Specialization for bool.
 * @ingroup ContHelpers
 */
template <>
struct TypeTraits<bool>
{
  using CppType = bool;
  using CType = gboolean;
  using CTypeNonConst = gboolean;

  static auto to_c_type(CppType item) -> CType { return static_cast<CType>(item); }
  static auto to_c_type(CType item) -> CType { return item; }
  static auto to_cpp_type(CType item) -> CppType { return (item != 0); }
  static void release_c_type(CType) {}
};

/** Specialization for Glib::VariantBase.
 * @ingroup ContHelpers
 */
template <>
struct TypeTraits<Glib::VariantBase>
{
  using CppType = Glib::VariantBase;
  using CType = GVariant*;
  using CTypeNonConst = GVariant*;

  static auto to_c_type(const Glib::VariantBase& v) -> CType { return const_cast<CTypeNonConst>(v.gobj()); }

  static auto to_c_type(CType v) -> CType { return v; }

  static auto to_cpp_type(CType v) -> CppType { return Glib::VariantBase(v, true); }

  static void release_c_type(CType v) { g_variant_unref(const_cast<CTypeNonConst>(v)); }
};

/** Specialization for Glib::VariantContainerBase.
 * @ingroup ContHelpers
 */
template <>
struct TypeTraits<Glib::VariantContainerBase>
{
  using CppType = Glib::VariantContainerBase;
  using CType = GVariant*;
  using CTypeNonConst = GVariant*;

  static auto to_c_type(const Glib::VariantContainerBase& v) -> CType
  {
    return const_cast<CTypeNonConst>(v.gobj());
  }

  static auto to_c_type(CType v) -> CType { return v; }

  static auto to_cpp_type(CType v) -> CppType { return Glib::VariantContainerBase(v, true); }

  static void release_c_type(CType v) { g_variant_unref(const_cast<CTypeNonConst>(v)); }
};

#ifndef GLIBMM_HAVE_TEMPLATE_SEQUENCE_CTORS

/* The STL containers in Sun's libCstd don't support templated sequence
 * constructors, for "backward compatibility" reasons.  This helper function
 * is used in the ContainerHandle -> STL-container conversion workarounds.
 */
template <class Cont, class In>
void
fill_container(Cont& container, In pbegin, In pend)
{
  for (; pbegin != pend; ++pbegin)
    container.emplace_back(*pbegin);
}

#endif /* GLIBMM_HAVE_TEMPLATE_SEQUENCE_CTORS */
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

} // namespace Container_Helpers

} // namespace Glib

#endif /* _GLIBMM_CONTAINERHANDLE_SHARED_H */
