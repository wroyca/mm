// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GLIBMM_WRAP_H
#define _GLIBMM_WRAP_H

#include <glib-object.h>
#include <libmm-glib/objectbase.hxx>
#include <libmm-glib/refptr.hxx>

namespace Glib
{

#ifndef DOXYGEN_SHOULD_SKIP_THIS

  class LIBMM_GLIB_SYMEXPORT ObjectBase;
  class LIBMM_GLIB_SYMEXPORT Object;

  using WrapNewFunction = Glib::ObjectBase* (*) (GObject*);

  LIBMM_GLIB_SYMEXPORT auto
  wrap_register_init () -> void;

  LIBMM_GLIB_SYMEXPORT auto
  wrap_register_cleanup () -> void;

  LIBMM_GLIB_SYMEXPORT auto
  wrap_register (GType type, WrapNewFunction func) -> void;

  LIBMM_GLIB_SYMEXPORT
  auto
  wrap_auto (GObject* object, bool take_copy = false) -> Glib::ObjectBase*;

  LIBMM_GLIB_SYMEXPORT
  auto
  wrap_create_new_wrapper_for_interface (GObject* object, GType interface_gtype) -> Glib::ObjectBase*;

  template <class TInterface>
  auto
  wrap_auto_interface (GObject* object, bool take_copy = false) -> TInterface*
  {
    if (!object)
      return nullptr;

    ObjectBase* pCppObject = ObjectBase::_get_current_wrapper (object);

    if (!pCppObject)
    {
      pCppObject = wrap_create_new_wrapper_for_interface (
          object,
          TInterface::get_base_type ());
    }

    TInterface* result = nullptr;
    if (pCppObject)
    {
      result = dynamic_cast<TInterface*> (pCppObject);
      if (!result)
      {
        g_warning ("Glib::wrap_auto_interface(): The C++ instance (%s) does "
                   "not dynamic_cast to the "
                   "interface.\n",
                   typeid (*pCppObject).name ());
      }
    }
    else
      result = new TInterface ((typename TInterface::BaseObjectType*) object);

    if (take_copy && result)
      result->reference ();

    return result;
  }

#endif

  LIBMM_GLIB_SYMEXPORT
  auto
  wrap (GObject* object, bool take_copy = false) -> Glib::RefPtr<Glib::Object>;

  template <class T>
  inline auto
  unwrap (T* ptr) -> typename T::BaseObjectType*
  {
    return (ptr) ? ptr->gobj () : nullptr;
  }

  template <class T>
  inline auto
  unwrap (const T* ptr) -> const typename T::BaseObjectType*
  {
    return (ptr) ? ptr->gobj () : nullptr;
  }

  template <class T>
  inline auto
  unwrap (const Glib::RefPtr<T>& ptr) -> typename T::BaseObjectType*
  {
    return (ptr) ? ptr->gobj () : nullptr;
  }

  template <class T>
  inline auto
  unwrap (const Glib::RefPtr<const T>& ptr) -> const typename T::BaseObjectType*
  {
    return (ptr) ? ptr->gobj () : nullptr;
  }

  template <class T>
  inline auto
  unwrap_copy (const T& obj) -> typename T::BaseObjectType*
  {
    return obj.gobj () ? obj.gobj_copy () : nullptr;
  }

  template <class T>
  inline auto
  unwrap_copy (const Glib::RefPtr<T>& ptr) -> typename T::BaseObjectType*
  {
    return (ptr) ? ptr->gobj_copy () : nullptr;
  }

  template <class T>
  inline auto
  unwrap_copy (const Glib::RefPtr<const T>& ptr) -> const
      typename T::BaseObjectType*
  {
    return (ptr) ? ptr->gobj_copy () : nullptr;
  }

} // namespace Glib

#endif
