// SPDX-License-Identifier: LGPL-2.1-or-later

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

  GLIBMM_API auto
  custom_boxed_type_register (const char* type_name,
                              ValueInitFunc init_func,
                              ValueFreeFunc free_func,
                              ValueCopyFunc copy_func) -> GType;

  GLIBMM_API auto
  custom_pointer_type_register (const char* type_name) -> GType;

#endif

  template <class PtrT>
  class Value_Pointer : public ValueBase_Object
  {
  public:
    using T = std::remove_cv_t<std::remove_pointer_t<PtrT>>;
    using CppType = PtrT;

    static inline auto
    value_type () -> GType G_GNUC_CONST;

    inline auto
    set (CppType data) -> void;
    inline auto
    get () const -> CppType;

  private:
    inline static auto
    value_type_ (Glib::Object*) -> GType;
    static auto
    value_type_ (void*) -> GType;

    inline auto
    set_ (CppType data, Glib::Object*) -> void;
    inline auto
    set_ (CppType data, void*) -> void;

    inline auto
    get_ (Glib::Object*) const -> CppType;
    inline auto
    get_ (void*) const -> CppType;
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

    static auto
    value_type () -> GType G_GNUC_CONST;

    inline auto
    set (const CppType& data) -> void;
    inline auto
    get () const -> CppType;

  private:
    static GType custom_type_;

    static auto
    value_init_func (GValue* value) -> void;
    static auto
    value_free_func (GValue* value) -> void;
    static auto
    value_copy_func (const GValue* src_value, GValue* dest_value) -> void;
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
  inline auto
  Value_Pointer<PtrT>::value_type_ (Glib::Object*) -> GType
  {
    return T::get_base_type ();
  }

  template <class PtrT>
  inline auto
  Value_Pointer<PtrT>::set_ (PtrT data, Glib::Object*) -> void
  {
    set_object (const_cast<T*> (data));
  }

  #ifdef GLIBMM_CAN_USE_DYNAMIC_CAST_IN_UNUSED_TEMPLATE_WITHOUT_DEFINITION
  template <class PtrT>
  inline auto
  Value_Pointer<PtrT>::get_ (Glib::Object*) const -> PtrT
  {
    return dynamic_cast<T*> (get_object ());
  }
  #endif

  template <class PtrT>
  auto
  Value_Pointer<PtrT>::value_type_ (void*) -> GType
  {
    static GType custom_type = 0;

    if (!custom_type)
      custom_type = Glib::custom_pointer_type_register (typeid (PtrT).name ());

    return custom_type;
  }

  template <class PtrT>
  inline auto
  Value_Pointer<PtrT>::set_ (PtrT data, void*) -> void
  {
    gobject_.data[0].v_pointer = const_cast<T*> (data);
  }

  template <class PtrT>
  inline auto
  Value_Pointer<PtrT>::get_ (void*) const -> PtrT
  {
    return static_cast<T*> (gobject_.data[0].v_pointer);
  }

  template <class PtrT>
  inline auto
  Value_Pointer<PtrT>::value_type () -> GType
  {
    return Value_Pointer<PtrT>::value_type_ (static_cast<T*> (nullptr));
  }

  template <class PtrT>
  inline auto
  Value_Pointer<PtrT>::set (PtrT data) -> void
  {
    this->set_ (data, static_cast<T*> (nullptr));
  }

  template <class PtrT>
  inline auto
  Value_Pointer<PtrT>::get () const -> PtrT
  {
    return this->get_ (static_cast<T*> (nullptr));
  }

  template <class T, typename Enable>
  GType Value<T, Enable>::custom_type_ = 0;

  template <class T, typename Enable>
  inline auto
  Value<T, Enable>::set (const typename Value<T, Enable>::CppType& data) -> void
  {
    *static_cast<T*> (gobject_.data[0].v_pointer) = data;
  }

  template <class T, typename Enable>
  inline auto
  Value<T, Enable>::get () const -> typename Value<T, Enable>::CppType
  {
    return *static_cast<T*> (gobject_.data[0].v_pointer);
  }

  template <class T, typename Enable>
  auto
  Value<T, Enable>::value_type () -> GType
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
  auto
  Value<T, Enable>::value_init_func (GValue* value) -> void
  {
    value->data[0].v_pointer = new (std::nothrow) T ();
  }

  template <class T, typename Enable>
  auto
  Value<T, Enable>::value_free_func (GValue* value) -> void
  {
    delete static_cast<T*> (value->data[0].v_pointer);
  }

  template <class T, typename Enable>
  auto
  Value<T, Enable>::value_copy_func (const GValue* src_value,
                                     GValue* dest_value) -> void
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

      static auto
      check_type (...) -> big;

      template <typename X>
      static auto
      check_type (X* obj) ->
          typename Glib::Value<X>::dont_use_with_wrap_property_;

    public:
      static const bool value =
          sizeof (check_type (static_cast<T*> (nullptr))) == sizeof (big);
    };

  } // namespace Traits

#endif

} // namespace Glib

#endif
