// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GLIBMM_VALUE_H
#define _GLIBMM_VALUE_H

#include <glib-object.h>
#include <libmm/glib/enums.hxx>
#include <libmm/glib/mm-glibconfig.hxx>
#include <libmm/glib/refptr.hxx>
#include <libmm/glib/ustring.hxx>
#include <vector>

namespace Glib
{

  class ObjectBase;
  class Object;

  class LIBMM_GLIB_SYMEXPORT ValueBase
  {
  public:
    ValueBase ();

    ValueBase (const ValueBase& other);
    auto
    operator= (const ValueBase& other) -> ValueBase&;

    ~ValueBase () noexcept;

    auto
    init (GType type) -> void;

    auto
    init (const GValue* value) -> void;

    auto
    reset () -> void;

    auto
    gobj () -> GValue*
    {
      return &gobject_;
    }

    auto
    gobj () const -> const GValue*
    {
      return &gobject_;
    }

  protected:
    GValue gobject_;
  };

  class LIBMM_GLIB_SYMEXPORT ValueBase_Boxed : public ValueBase
  {
  public:
    static auto
    value_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS
    auto
    create_param_spec (const Glib::ustring& name,
                       const Glib::ustring& nick,
                       const Glib::ustring& blurb,
                       Glib::ParamFlags flags) const -> GParamSpec*;
#endif

  protected:
    auto
    set_boxed (const void* data) -> void;
    auto
    get_boxed () const -> void*;
  };

  class LIBMM_GLIB_SYMEXPORT ValueBase_Object : public ValueBase
  {
  public:
    static auto
    value_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS
    auto
    create_param_spec (const Glib::ustring& name,
                       const Glib::ustring& nick,
                       const Glib::ustring& blurb,
                       Glib::ParamFlags flags) const -> GParamSpec*;
#endif

  protected:
    auto
    set_object (Glib::ObjectBase* data) -> void;
    auto
    get_object () const -> Glib::ObjectBase*;
    auto
    get_object_copy () const -> Glib::RefPtr<Glib::ObjectBase>;
  };

  class LIBMM_GLIB_SYMEXPORT ValueBase_Enum : public ValueBase
  {
  public:
    static auto
    value_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS
    auto
    create_param_spec (const Glib::ustring& name,
                       const Glib::ustring& nick,
                       const Glib::ustring& blurb,
                       Glib::ParamFlags flags) const -> GParamSpec*;
#endif

  protected:
    auto
    set_enum (int data) -> void;
    auto
    get_enum () const -> int;
  };

  class LIBMM_GLIB_SYMEXPORT ValueBase_Flags : public ValueBase
  {
  public:
    static auto
    value_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS
    auto
    create_param_spec (const Glib::ustring& name,
                       const Glib::ustring& nick,
                       const Glib::ustring& blurb,
                       Glib::ParamFlags flags) const -> GParamSpec*;
#endif

  protected:
    auto
    set_flags (unsigned int data) -> void;
    auto
    get_flags () const -> unsigned int;
  };

  class LIBMM_GLIB_SYMEXPORT ValueBase_String : public ValueBase
  {
  public:
    static auto
    value_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS
    auto
    create_param_spec (const Glib::ustring& name,
                       const Glib::ustring& nick,
                       const Glib::ustring& blurb,
                       Glib::ParamFlags flags) const -> GParamSpec*;
#endif

  protected:
    auto
    set_cstring (const char* data) -> void;
    auto
    get_cstring () const -> const char*;
  };

  class LIBMM_GLIB_SYMEXPORT ValueBase_Variant : public ValueBase
  {
  public:
    static auto
    value_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS
    auto
    create_param_spec (const Glib::ustring& name,
                       const Glib::ustring& nick,
                       const Glib::ustring& blurb,
                       Glib::ParamFlags flags) const -> GParamSpec*;
#endif

  protected:
    auto
    set_variant (GVariant* data) -> void;
    auto
    get_variant () const -> GVariant*;
  };

} // namespace Glib

#define _GLIBMM_VALUE_H_INCLUDE_VALUE_CUSTOM_H
#include <libmm/glib/value_custom.hxx>
#undef _GLIBMM_VALUE_H_INCLUDE_VALUE_CUSTOM_H

namespace Glib
{

  template <class T>
  class Value_Boxed : public ValueBase_Boxed
  {
  public:
    using CppType = T;

    static auto
    value_type () -> GType
    {
      return T::get_type ();
    }

    auto
    set (const CppType& data) -> void
    {
      set_boxed (data.gobj ());
    }

    auto
    get () const -> CppType
    {
      return CppType (static_cast<typename T::BaseObjectType*> (get_boxed ()));
    }
  };

  template <class T>
  class Value_RefPtrBoxed : public ValueBase_Boxed
  {
  public:
    using CppType = Glib::RefPtr<T>;

    static auto
    value_type () -> GType
    {
      return T::get_type ();
    }

    auto
    set (const CppType& data) -> void
    {
      set_boxed (data ? data->gobj () : nullptr);
    }
  };

#ifdef GLIBMM_CAN_USE_DYNAMIC_CAST_IN_UNUSED_TEMPLATE_WITHOUT_DEFINITION

  namespace Traits
  {

    template <typename, typename>
    struct HasGetBaseType;

    template <typename T, typename Ret, typename... Args>
    struct HasGetBaseType<T, Ret (Args...)>
    {
      template <typename U, U>
      struct Check;

      template <typename U>
      static auto
      Test (Check<Ret (*) (Args...), &U::get_base_type>*) -> std::true_type;

      template <typename U>
      static auto
      Test (...) -> std::false_type;

      static const bool value = decltype (Test<T> (0))::value;
    };

  } // namespace Traits

  template <class T>
  class Value<Glib::RefPtr<T>,
              typename std::enable_if<
                  Glib::Traits::HasGetBaseType<T, GType ()>::value>::type>
    : public ValueBase_Object
  {
  public:
    using CppType = Glib::RefPtr<T>;

    static auto
    value_type () -> GType
    {
      return T::get_base_type ();
    }

    auto
    set (const CppType& data) -> void
    {
      set_object (const_cast<std::remove_const_t<T>*> (data.get ()));
    }

    auto
    get () const -> CppType
    {
      return std::dynamic_pointer_cast<T> (get_object_copy ());
    }
  };

  #ifdef GLIBMM_HAVE_DISAMBIGUOUS_CONST_TEMPLATE_SPECIALIZATIONS

  #endif

#endif

} // namespace Glib

#define _GLIBMM_VALUE_H_INCLUDE_VALUE_BASICTYPES_H
#include <libmm/glib/value_basictypes.hxx>
#undef _GLIBMM_VALUE_H_INCLUDE_VALUE_BASICTYPES_H

namespace Glib
{

  template <>
  class LIBMM_GLIB_SYMEXPORT Value<std::string> : public ValueBase_String
  {
  public:
    using CppType = std::string;

    auto
    set (const std::string& data) -> void;

    auto
    get () const -> std::string
    {
      return get_cstring ();
    }
  };

  template <>
  class LIBMM_GLIB_SYMEXPORT Value<Glib::ustring> : public ValueBase_String
  {
  public:
    using CppType = Glib::ustring;

    auto
    set (const Glib::ustring& data) -> void;

    auto
    get () const -> Glib::ustring
    {
      return get_cstring ();
    }
  };

  template <>
  class LIBMM_GLIB_SYMEXPORT Value<std::vector<std::string>> : public ValueBase_Boxed
  {
  public:
    using CppType = std::vector<std::string>;

    static auto
    value_type () -> GType;

    auto
    set (const CppType& data) -> void;
    auto
    get () const -> CppType;
  };

  template <>
  class LIBMM_GLIB_SYMEXPORT Value<std::vector<Glib::ustring>> : public ValueBase_Boxed
  {
  public:
    using CppType = std::vector<Glib::ustring>;

    static auto
    value_type () -> GType;

    auto
    set (const CppType& data) -> void;
    auto
    get () const -> CppType;
  };

  template <class T>
  class Value_Enum : public ValueBase_Enum
  {
  public:
    using CppType = T;

    auto
    set (CppType data) -> void
    {
      set_enum (static_cast<int> (data));
    }

    auto
    get () const -> CppType
    {
      return CppType (get_enum ());
    }
  };

  template <class T>
  class Value_Flags : public ValueBase_Flags
  {
  public:
    using CppType = T;

    auto
    set (CppType data) -> void
    {
      set_flags (static_cast<unsigned int> (data));
    }

    auto
    get () const -> CppType
    {
      return CppType (get_flags ());
    }
  };

} // namespace Glib

#endif
