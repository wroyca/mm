#ifndef _GLIBMM_WRAP_H
#define _GLIBMM_WRAP_H

#include <glib-object.h>
#include <libmm-glib/objectbase.hxx>
#include <libmm-glib/refptr.hxx>

namespace Glib
{

#ifndef DOXYGEN_SHOULD_SKIP_THIS

  class GLIBMM_API ObjectBase;
  class GLIBMM_API Object;

  using WrapNewFunction = Glib::ObjectBase* (*) (GObject*);

  GLIBMM_API
  void
  wrap_register_init ();

  GLIBMM_API
  void
  wrap_register_cleanup ();

  GLIBMM_API
  void
  wrap_register (GType type, WrapNewFunction func);

  GLIBMM_API
  auto
  wrap_auto (GObject* object, bool take_copy = false) -> Glib::ObjectBase*;

  GLIBMM_API
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

  GLIBMM_API
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
