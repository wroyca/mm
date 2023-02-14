

#ifndef _GLIBMM_VALUE_CUSTOM_H
#define _GLIBMM_VALUE_CUSTOM_H

#ifndef DOXYGEN_SHOULD_SKIP_THIS
  #ifndef _GLIBMM_VALUE_H_INCLUDE_VALUE_CUSTOM_H
    #error "glibmm/value_custom.h cannot be included directly"
  #endif
#endif

#include <libmm-glib/mm-glibconfig.hxx>
#include <new>
#include <type_traits>
#include <typeinfo>

namespace Glib
{

#ifndef DOXYGEN_SHOULD_SKIP_THIS

  extern "C"
  {
    typedef void (*ValueInitFunc) (GValue*);
    typedef void (*ValueFreeFunc) (GValue*);
    typedef void (*ValueCopyFunc) (const GValue*, GValue*);
  }

  GLIBMM_API
  GType
  custom_boxed_type_register (const char* type_name,
                              ValueInitFunc init_func,
                              ValueFreeFunc free_func,
                              ValueCopyFunc copy_func);

  GLIBMM_API
  GType
  custom_pointer_type_register (const char* type_name);

#endif

  template <class PtrT>
  class Value_Pointer : public ValueBase_Object
  {
  public:
    using T = std::remove_cv_t<std::remove_pointer_t<PtrT>>;
    using CppType = PtrT;

    static inline GType
    value_type () G_GNUC_CONST;

    inline void
    set (CppType data);
    inline CppType
    get () const;

  private:
    inline static GType
    value_type_ (Glib::Object*);
    static GType
    value_type_ (void*);

    inline void
    set_ (CppType data, Glib::Object*);
    inline void
    set_ (CppType data, void*);

    inline CppType
    get_ (Glib::Object*) const;
    inline CppType
    get_ (void*) const;
  };

  template <class T, typename Enable = void>
  class Value : public ValueBase_Boxed
  {
    static_assert (std::is_default_constructible<T> (),
                   "T should be default constructible");
    static_assert (std::is_copy_constructible<T> (),
                   "T should be copy constructible");
    static_assert (std::is_assignable<T&, T> (), "T should be assignable");
    static_assert (std::is_assignable<T&, T&> (), "T should be assignable");
    static_assert (std::is_assignable<T&, const T&> (),
                   "T should be assignable");
    static_assert (std::is_destructible<T> (), "T should be destructible");
    static_assert (std::is_move_assignable<T> (),
                   "T should be move assignable");
    static_assert (std::is_move_constructible<T> (),
                   "T should be move constructible");

  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS

    using dont_use_with_wrap_property_ = int;
#endif
    using CppType = T;

    static GType
    value_type () G_GNUC_CONST;

    inline void
    set (const CppType& data);
    inline CppType
    get () const;

  private:
    static GType custom_type_;

    static void
    value_init_func (GValue* value);
    static void
    value_free_func (GValue* value);
    static void
    value_copy_func (const GValue* src_value, GValue* dest_value);
  };

  template <class T, typename Enable>
  class GLIBMM_API Value<T*, Enable> : public Value_Pointer<T*>
  {
  };

  template <class T, typename Enable>
  class GLIBMM_API Value<const T*, Enable> : public Value_Pointer<const T*>
  {
  };

#ifndef DOXYGEN_SHOULD_SKIP_THIS

  template <class PtrT>
  inline GType
  Value_Pointer<PtrT>::value_type_ (Glib::Object*)
  {
    return T::get_base_type ();
  }

  template <class PtrT>
  inline void
  Value_Pointer<PtrT>::set_ (PtrT data, Glib::Object*)
  {
    set_object (const_cast<T*> (data));
  }

  #ifdef GLIBMM_CAN_USE_DYNAMIC_CAST_IN_UNUSED_TEMPLATE_WITHOUT_DEFINITION
  template <class PtrT>
  inline PtrT
  Value_Pointer<PtrT>::get_ (Glib::Object*) const
  {
    return dynamic_cast<T*> (get_object ());
  }
  #endif

  template <class PtrT>
  GType
  Value_Pointer<PtrT>::value_type_ (void*)
  {
    static GType custom_type = 0;

    if (!custom_type)
      custom_type = Glib::custom_pointer_type_register (typeid (PtrT).name ());

    return custom_type;
  }

  template <class PtrT>
  inline void
  Value_Pointer<PtrT>::set_ (PtrT data, void*)
  {
    gobject_.data[0].v_pointer = const_cast<T*> (data);
  }

  template <class PtrT>
  inline PtrT
  Value_Pointer<PtrT>::get_ (void*) const
  {
    return static_cast<T*> (gobject_.data[0].v_pointer);
  }

  template <class PtrT>
  inline GType
  Value_Pointer<PtrT>::value_type ()
  {
    return Value_Pointer<PtrT>::value_type_ (static_cast<T*> (nullptr));
  }

  template <class PtrT>
  inline void
  Value_Pointer<PtrT>::set (PtrT data)
  {
    this->set_ (data, static_cast<T*> (nullptr));
  }

  template <class PtrT>
  inline PtrT
  Value_Pointer<PtrT>::get () const
  {
    return this->get_ (static_cast<T*> (nullptr));
  }

  template <class T, typename Enable>
  GType Value<T, Enable>::custom_type_ = 0;

  template <class T, typename Enable>
  inline void
  Value<T, Enable>::set (const typename Value<T, Enable>::CppType& data)
  {
    *static_cast<T*> (gobject_.data[0].v_pointer) = data;
  }

  template <class T, typename Enable>
  inline typename Value<T, Enable>::CppType
  Value<T, Enable>::get () const
  {
    return *static_cast<T*> (gobject_.data[0].v_pointer);
  }

  template <class T, typename Enable>
  GType
  Value<T, Enable>::value_type ()
  {
    if (!custom_type_)
    {
      custom_type_ = Glib::custom_boxed_type_register (
          typeid (CppType).name (),
          &Value<T>::value_init_func,
          &Value<T>::value_free_func,
          &Value<T>::value_copy_func);
    }
    return custom_type_;
  }

  template <class T, typename Enable>
  void
  Value<T, Enable>::value_init_func (GValue* value)
  {
    value->data[0].v_pointer = new (std::nothrow) T ();
  }

  template <class T, typename Enable>
  void
  Value<T, Enable>::value_free_func (GValue* value)
  {
    delete static_cast<T*> (value->data[0].v_pointer);
  }

  template <class T, typename Enable>
  void
  Value<T, Enable>::value_copy_func (const GValue* src_value,
                                     GValue* dest_value)
  {
    const T& source = *static_cast<T*> (src_value->data[0].v_pointer);
    dest_value->data[0].v_pointer = new (std::nothrow) T (source);
  }

  namespace Traits
  {

    template <typename T>
    class ValueCompatibleWithWrapProperty
    {
    private:
      struct big
      {
        int memory[64];
      };

      static big
      check_type (...);

      template <typename X>
      static typename Glib::Value<X>::dont_use_with_wrap_property_
      check_type (X* obj);

    public:
      static const bool value =
          sizeof (check_type (static_cast<T*> (nullptr))) == sizeof (big);
    };

  } // namespace Traits

#endif

} // namespace Glib

#endif
