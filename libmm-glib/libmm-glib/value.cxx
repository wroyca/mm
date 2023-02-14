// SPDX-License-Identifier: LGPL-2.1-or-later

#include <cstring>
#include <libmm-glib/objectbase.hxx>
#include <libmm-glib/utility.hxx>
#include <libmm-glib/value.hxx>
#include <libmm-glib/vectorutils.hxx>
#include <libmm-glib/wrap.hxx>

namespace Glib
{

  ValueBase::ValueBase ()
  {
    std::memset (&gobject_, 0, sizeof (GValue));
  }

  auto
  ValueBase::init (const GType type) -> void
  {
    g_value_init (&gobject_, type);
  }

  auto
  ValueBase::init (const GValue* value) -> void
  {
    g_value_init (&gobject_, G_VALUE_TYPE (value));

    if (value)
      g_value_copy (value, &gobject_);
  }

  ValueBase::ValueBase (const ValueBase& other)
  {
    std::memset (&gobject_, 0, sizeof (GValue));

    g_value_init (&gobject_, G_VALUE_TYPE (&other.gobject_));
    g_value_copy (&other.gobject_, &gobject_);
  }

  auto
  ValueBase::operator= (const ValueBase& other) -> ValueBase&
  {
    g_value_copy (&other.gobject_, &gobject_);
    return *this;
  }

  ValueBase::~ValueBase () noexcept
  {
    g_value_unset (&gobject_);
  }

  auto
  ValueBase::reset () -> void
  {
    g_value_reset (&gobject_);
  }

  auto
  ValueBase_Boxed::value_type () -> GType
  {
    return G_TYPE_BOXED;
  }

  auto
  ValueBase_Boxed::set_boxed (const void* data) -> void
  {
    g_value_set_boxed (&gobject_, data);
  }

  auto
  ValueBase_Boxed::get_boxed () const -> void*
  {
    return g_value_get_boxed (&gobject_);
  }

  auto
  ValueBase_Boxed::create_param_spec (const ustring& name,
                                      const ustring& nick,
                                      const ustring& blurb,
                                      ParamFlags flags) const -> GParamSpec*
  {
    return g_param_spec_boxed (name.c_str (),
                               c_str_or_nullptr (nick),
                               c_str_or_nullptr (blurb),
                               G_VALUE_TYPE (&gobject_),
                               static_cast<GParamFlags> (flags));
  }

  auto
  ValueBase_Object::value_type () -> GType
  {
    return G_TYPE_OBJECT;
  }

  auto
  ValueBase_Object::set_object (ObjectBase* data) -> void
  {
    g_value_set_object (&gobject_, data ? data->gobj () : nullptr);
  }

  auto
  ValueBase_Object::get_object () const -> ObjectBase*
  {
    GObject* const data =
        static_cast<GObject*> (g_value_get_object (&gobject_));
    return wrap_auto (data, false);
  }

  auto
  ValueBase_Object::get_object_copy () const -> RefPtr<ObjectBase>
  {
    GObject* const data =
        static_cast<GObject*> (g_value_get_object (&gobject_));
    return Glib::make_refptr_for_instance<ObjectBase> (wrap_auto (data, true));
  }

  auto
  ValueBase_Object::create_param_spec (const ustring& name,
                                       const ustring& nick,
                                       const ustring& blurb,
                                       ParamFlags flags) const -> GParamSpec*
  {
    if (G_VALUE_HOLDS_OBJECT (&gobject_))
    {
      return g_param_spec_object (name.c_str (),
                                  c_str_or_nullptr (nick),
                                  c_str_or_nullptr (blurb),
                                  G_VALUE_TYPE (&gobject_),
                                  static_cast<GParamFlags> (flags));
    }
    else
    {
      g_return_val_if_fail (G_VALUE_HOLDS_POINTER (&gobject_), nullptr);

      return g_param_spec_pointer (name.c_str (),
                                   c_str_or_nullptr (nick),
                                   c_str_or_nullptr (blurb),
                                   static_cast<GParamFlags> (flags));
    }
  }

  auto
  ValueBase_Enum::value_type () -> GType
  {
    return G_TYPE_ENUM;
  }

  auto
  ValueBase_Enum::set_enum (const int data) -> void
  {
    g_value_set_enum (&gobject_, data);
  }

  auto
  ValueBase_Enum::get_enum () const -> int
  {
    return g_value_get_enum (&gobject_);
  }

  auto
  ValueBase_Enum::create_param_spec (const ustring& name,
                                     const ustring& nick,
                                     const ustring& blurb,
                                     ParamFlags flags) const -> GParamSpec*
  {
    return g_param_spec_enum (name.c_str (),
                              c_str_or_nullptr (nick),
                              c_str_or_nullptr (blurb),
                              G_VALUE_TYPE (&gobject_),
                              g_value_get_enum (&gobject_),
                              static_cast<GParamFlags> (flags));
  }

  auto
  ValueBase_Flags::value_type () -> GType
  {
    return G_TYPE_FLAGS;
  }

  auto
  ValueBase_Flags::set_flags (const unsigned int data) -> void
  {
    g_value_set_flags (&gobject_, data);
  }

  auto
  ValueBase_Flags::get_flags () const -> unsigned int
  {
    return g_value_get_flags (&gobject_);
  }

  auto
  ValueBase_Flags::create_param_spec (const ustring& name,
                                      const ustring& nick,
                                      const ustring& blurb,
                                      ParamFlags flags) const -> GParamSpec*
  {
    return g_param_spec_flags (name.c_str (),
                               c_str_or_nullptr (nick),
                               c_str_or_nullptr (blurb),
                               G_VALUE_TYPE (&gobject_),
                               g_value_get_flags (&gobject_),
                               static_cast<GParamFlags> (flags));
  }

  auto
  ValueBase_String::value_type () -> GType
  {
    return G_TYPE_STRING;
  }

  auto
  ValueBase_String::set_cstring (const char* data) -> void
  {
    g_value_set_string (&gobject_, data);
  }

  auto
  ValueBase_String::get_cstring () const -> const char*
  {
    if (const char* const data = g_value_get_string (&gobject_))
      return data;
    else
      return "";
  }

  auto
  ValueBase_String::create_param_spec (const ustring& name,
                                       const ustring& nick,
                                       const ustring& blurb,
                                       ParamFlags flags) const -> GParamSpec*
  {
    return g_param_spec_string (name.c_str (),
                                c_str_or_nullptr (nick),
                                c_str_or_nullptr (blurb),
                                get_cstring (),
                                static_cast<GParamFlags> (flags));
  }

  auto
  ValueBase_Variant::value_type () -> GType
  {
    return G_TYPE_VARIANT;
  }

  auto
  ValueBase_Variant::set_variant (GVariant* data) -> void
  {
    g_value_set_variant (&gobject_, data);
  }

  auto
  ValueBase_Variant::get_variant () const -> GVariant*
  {
    return g_value_get_variant (&gobject_);
  }

  auto
  ValueBase_Variant::create_param_spec (const ustring& name,
                                        const ustring& nick,
                                        const ustring& blurb,
                                        ParamFlags flags) const -> GParamSpec*
  {
    GVariant* gvariant = g_value_get_variant (&gobject_);
    const GVariantType* gvariant_type =
        gvariant ? g_variant_get_type (gvariant) : G_VARIANT_TYPE_ANY;

    return g_param_spec_variant (name.c_str (),
                                 c_str_or_nullptr (nick),
                                 c_str_or_nullptr (blurb),
                                 gvariant_type,
                                 gvariant,
                                 static_cast<GParamFlags> (flags));
  }

  auto
  Value<std::string>::set (const std::string& data) -> void
  {
    g_value_set_string (&gobject_, data.c_str ());
  }

  auto
  Value<ustring>::set (const ustring& data) -> void
  {
    g_value_set_string (&gobject_, data.c_str ());
  }

  auto
  Value<std::vector<std::string>>::value_type () -> GType
  {
    return G_TYPE_STRV;
  }

  auto
  Value<std::vector<std::string>>::set (const CppType& data) -> void
  {
    set_boxed (ArrayHandler<std::string>::vector_to_array (data).data ());
  }

  auto
  Value<std::vector<std::string>>::get () const -> std::vector<std::string>
  {
    return ArrayHandler<std::string>::array_to_vector (
        static_cast<const char* const*> (get_boxed ()),
        OWNERSHIP_NONE);
  }

  auto
  Value<std::vector<ustring>>::value_type () -> GType
  {
    return G_TYPE_STRV;
  }

  auto
  Value<std::vector<ustring>>::set (const CppType& data) -> void
  {
    set_boxed (ArrayHandler<ustring>::vector_to_array (data).data ());
  }

  auto
  Value<std::vector<ustring>>::get () const -> std::vector<ustring>
  {
    return ArrayHandler<ustring>::array_to_vector (
        static_cast<const char* const*> (get_boxed ()),
        OWNERSHIP_NONE);
  }

} // namespace Glib
