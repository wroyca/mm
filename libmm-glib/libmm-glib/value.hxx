#ifndef _GLIBMM_VALUE_H
#define _GLIBMM_VALUE_H

#include <glib-object.h>
#include <libmm-glib/enums.hxx>
#include <libmm-glib/mm-glibconfig.hxx>
#include <libmm-glib/refptr.hxx>
#include <libmm-glib/ustring.hxx>
#include <vector>

namespace Glib
{

  class ObjectBase;
  class Object;

  class GLIBMM_API ValueBase
  {
  public:
    ValueBase ();

    ValueBase (const ValueBase& other);
    auto
    operator= (const ValueBase& other) -> ValueBase&;

    ~ValueBase () noexcept;

    void
    init (GType type);

    void
    init (const GValue* value);

    void
    reset ();

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

  class GLIBMM_API ValueBase_Boxed : public ValueBase
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
    void
    set_boxed (const void* data);
    auto
    get_boxed () const -> void*;
  };

  class GLIBMM_API ValueBase_Object : public ValueBase
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
    void
    set_object (Glib::ObjectBase* data);
    auto
    get_object () const -> Glib::ObjectBase*;
    auto
    get_object_copy () const -> Glib::RefPtr<Glib::ObjectBase>;
  };

  class GLIBMM_API ValueBase_Enum : public ValueBase
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
    void
    set_enum (int data);
    auto
    get_enum () const -> int;
  };

  class GLIBMM_API ValueBase_Flags : public ValueBase
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
    void
    set_flags (unsigned int data);
    auto
    get_flags () const -> unsigned int;
  };

  class GLIBMM_API ValueBase_String : public ValueBase
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
    void
    set_cstring (const char* data);
    auto
    get_cstring () const -> const char*;
  };

  class GLIBMM_API ValueBase_Variant : public ValueBase
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
    void
    set_variant (GVariant* data);
    auto
    get_variant () const -> GVariant*;
  };

} // namespace Glib

#define _GLIBMM_VALUE_H_INCLUDE_VALUE_CUSTOM_H
#include <libmm-glib/value_custom.hxx>
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

    void
    set (const CppType& data)
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

    void
    set (const CppType& data)
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

    void
    set (const CppType& data)
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
#include <libmm-glib/value_basictypes.hxx>
#undef _GLIBMM_VALUE_H_INCLUDE_VALUE_BASICTYPES_H

namespace Glib
{

  template <>
  class GLIBMM_API Value<std::string> : public ValueBase_String
  {
  public:
    using CppType = std::string;

    void
    set (const std::string& data);

    auto
    get () const -> std::string
    {
      return get_cstring ();
    }
  };

  template <>
  class GLIBMM_API Value<Glib::ustring> : public ValueBase_String
  {
  public:
    using CppType = Glib::ustring;

    void
    set (const Glib::ustring& data);

    auto
    get () const -> Glib::ustring
    {
      return get_cstring ();
    }
  };

  template <>
  class GLIBMM_API Value<std::vector<std::string>> : public ValueBase_Boxed
  {
  public:
    using CppType = std::vector<std::string>;

    static auto
    value_type () -> GType;

    void
    set (const CppType& data);
    auto
    get () const -> CppType;
  };

  template <>
  class GLIBMM_API Value<std::vector<Glib::ustring>> : public ValueBase_Boxed
  {
  public:
    using CppType = std::vector<Glib::ustring>;

    static auto
    value_type () -> GType;

    void
    set (const CppType& data);
    auto
    get () const -> CppType;
  };

  template <class T>
  class Value_Enum : public ValueBase_Enum
  {
  public:
    using CppType = T;

    void
    set (CppType data)
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

    void
    set (CppType data)
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
