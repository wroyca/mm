#ifndef _GLIBMM_OBJECT_H
#define _GLIBMM_OBJECT_H

#ifdef DestroyNotify
  #error \
      "X11/Xlib.h seems to have been included before this header. Due to some commonly-named macros in X11/Xlib.h, it may only be included after any glibmm, gdkmm, or gtkmm headers."
#endif

#include <glib.h>
#include <libmm-glib/containerhandle_shared.hxx>
#include <libmm-glib/mm-glibconfig.hxx>
#include <libmm-glib/objectbase.hxx>
#include <libmm-glib/quark.hxx>
#include <libmm-glib/refptr.hxx>
#include <libmm-glib/utility.hxx>
#include <libmm-glib/value.hxx>
#include <libmm-glib/wrap.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
extern "C"
{
  using GObject = struct _GObject;
  using GObjectClass = struct _GObjectClass;
}
#endif

namespace Glib
{

#ifndef DOXYGEN_SHOULD_SKIP_THIS

  class GLIBMM_API Class;
  class GLIBMM_API Object_Class;
  class GLIBMM_API GSigConnectionNode;

  class GLIBMM_API ConstructParams
  {
  public:
    const Glib::Class& glibmm_class;
    unsigned int n_parameters;
    const char** parameter_names;
    GValue* parameter_values;

    explicit ConstructParams (const Glib::Class& glibmm_class_);
    ConstructParams (const Glib::Class& glibmm_class_,
                     const char* first_property_name,
                     ...) G_GNUC_NULL_TERMINATED;
    ~ConstructParams () noexcept;

    ConstructParams (const ConstructParams& other) = delete;
    auto
    operator= (const ConstructParams&) -> ConstructParams& = delete;
  };

#endif

  class GLIBMM_API Object : virtual public ObjectBase
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    using CppObjectType = Object;
    using CppClassType = Object_Class;
    using BaseObjectType = GObject;
    using BaseClassType = GObjectClass;
#endif

    Object (const Object&) = delete;
    auto
    operator= (const Object&) -> Object& = delete;

    Object (Object&& src) noexcept;
    auto
    operator= (Object&& src) noexcept -> Object&;

  protected:
    Object ();
    explicit Object (const Glib::ConstructParams& construct_params);
    explicit Object (GObject* castitem);
    ~Object () noexcept override;

  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    static auto
    get_type () -> GType G_GNUC_CONST;
    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    get_data (const QueryQuark& key) -> void*;
    void
    set_data (const Quark& key, void* data);
    using DestroyNotify = void (*) (gpointer data);
    void
    set_data (const Quark& key, void* data, DestroyNotify notify);
    void
    remove_data (const QueryQuark& quark);

    auto
    steal_data (const QueryQuark& quark) -> void*;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

  private:
    friend class Glib::Object_Class;
    static CppClassType object_class_;

#endif
  };

#ifndef GLIBMM_CAN_USE_DYNAMIC_CAST_IN_UNUSED_TEMPLATE_WITHOUT_DEFINITION
  #ifndef DOXYGEN_SHOULD_SKIP_THIS

  namespace Container_Helpers
  {

    template <class T>
    struct TypeTraits<Glib::RefPtr<T>>
    {
      using CppType = Glib::RefPtr<T>;
      using CType = typename T::BaseObjectType*;
      using CTypeNonConst = typename T::BaseObjectType*;

      static CType
      to_c_type (const CppType& ptr)
      {
        return Glib::unwrap (ptr);
      }

      static CType
      to_c_type (CType ptr)
      {
        return ptr;
      }

      static CppType
      to_cpp_type (CType ptr)
      {
        GObject* cobj = (GObject*) const_cast<CTypeNonConst> (ptr);
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

      static CType
      to_c_type (const CppType& ptr)
      {
        return Glib::unwrap (ptr);
      }

      static CType
      to_c_type (CType ptr)
      {
        return ptr;
      }

      static CppType
      to_cpp_type (CType ptr)
      {
        GObject* cobj = (GObject*) (ptr);
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

  } // namespace Container_Helpers

  template <class PtrT>
  inline PtrT
  Value_Pointer<PtrT>::get_ (Glib::Object*) const
  {
    return dynamic_cast<T*> (get_object ());
  }

  template <class T>
  class Value<Glib::RefPtr<T>> : public ValueBase_Object
  {
  public:
    using CppType = Glib::RefPtr<T>;
    using CType = typename T::BaseObjectType*;

    static GType
    value_type ()
    {
      return T::get_base_type ();
    }

    void
    set (const CppType& data)
    {
      set_object (data.get ());
    }

    CppType
    get () const
    {
      return std::dynamic_pointer_cast<T> (get_object_copy ());
    }
  };

    #ifdef GLIBMM_HAVE_DISAMBIGUOUS_CONST_TEMPLATE_SPECIALIZATIONS

  template <class T>
  class Value<Glib::RefPtr<const T>> : public ValueBase_Object
  {
  public:
    using CppType = Glib::RefPtr<const T>;
    using CType = typename T::BaseObjectType*;

    static GType
    value_type ()
    {
      return T::get_base_type ();
    }

    void
    set (const CppType& data)
    {
      set_object (const_cast<T*> (data.get ()));
    }

    CppType
    get () const
    {
      return std::dynamic_pointer_cast<T> (get_object_copy ());
    }
  };
    #endif

  #endif
#endif

} // namespace Glib

#endif
