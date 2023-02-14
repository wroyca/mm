

#include <libmm-glib/mm-glib.hxx>

#include <libmm-glib/variant.hxx>
#include <libmm-glib/variant_p.hxx>

#include <glib.h>
#include <iostream>
#include <libmm-glib/utility.hxx>
#include <libmm-glib/variant.hxx>

namespace Glib
{

  VariantBase::VariantBase (GVariant* castitem, const bool make_a_copy)
  {
    if (castitem)
    {
      if (g_variant_is_floating (castitem))
        g_variant_ref_sink (castitem);

      if (make_a_copy)
        g_variant_ref (castitem);
    }

    gobject_ = castitem;
  }

  VariantBase::operator bool () const
  {
    return gobj ();
  }

  auto
  VariantBase::init (const GVariant* cobject, const bool take_a_reference) -> void
  {
    if (gobject_)
      g_variant_unref (gobject_);

    gobject_ = const_cast<GVariant*> (cobject);
    if (take_a_reference)
      g_variant_ref (gobject_);
  }

  auto
  VariantBase::operator== (const VariantBase& other) const -> bool
  {
    return equal (other);
  }

  auto
  VariantBase::operator!= (const VariantBase& other) const -> bool
  {
    return !equal (other);
  }

  auto
  VariantBase::get_normal_form (VariantBase& result) const -> void
  {
    const GVariant* const g_value =
        g_variant_get_normal_form (const_cast<GVariant*> (gobj ()));

    result.init (g_value);
  }

  auto
  VariantBase::byteswap (VariantBase& result) const -> void
  {
    const GVariant* const g_value =
        g_variant_byteswap (const_cast<GVariant*> (gobj ()));
    result.init (g_value);
  }

  auto
  VariantBase::is_castable_to (const VariantType& supertype) const -> bool
  {
    const std::string subtype_string = get_type_string ();
    const std::string supertype_string = supertype.get_string ();

    std::size_t subtype_index = 0;
    std::size_t supertype_index = 0;
    const std::size_t supertype_size = supertype_string.size ();
    while (supertype_index < supertype_size)
    {
      const char supertype_char = supertype_string[supertype_index++];
      const char subtype_char = subtype_string[subtype_index++];

      if (supertype_char == subtype_char)
        continue;

      switch (supertype_char)
      {
        case 's':
          if (!(subtype_char == 'o' || subtype_char == 'g'))
            return false;
          break;

        case 'a':
          if (!(supertype_string[supertype_index] == 'y' &&
                (subtype_char == 's' || subtype_char == 'o' ||
                 subtype_char == 'g')))
            return false;
          supertype_index++;
          break;

        case 'i':
          if (!(subtype_char == 'h'))
            return false;
          break;

        default:
          return false;
      }
    }
    return true;
  }

  VariantStringBase::VariantStringBase ()
    : VariantBase ()
  {
  }

  VariantStringBase::VariantStringBase (GVariant* castitem,
                                        const bool take_a_reference)
    : VariantBase (castitem, take_a_reference)
  {
  }

  auto
  VariantStringBase::create_object_path (VariantStringBase& output,
                                         const std::string& object_path) -> void
  {
    GVariant* result = nullptr;
    result = g_variant_new_object_path (object_path.c_str ());
    g_variant_ref_sink (result);
    output.init (result);
  }

  auto
  VariantStringBase::create_signature (VariantStringBase& output,
                                       const std::string& signature) -> void
  {
    GVariant* result = nullptr;
    result = g_variant_new_signature (signature.c_str ());
    g_variant_ref_sink (result);
    output.init (result);
  }

  VariantContainerBase::VariantContainerBase ()
    : VariantBase ()
  {
  }

  VariantContainerBase::VariantContainerBase (GVariant* castitem,
                                              const bool take_a_reference)
    : VariantBase (castitem, take_a_reference)
  {
  }

  auto
  VariantContainerBase::create_tuple (const std::vector<VariantBase>& children) -> VariantContainerBase
  {
    using var_ptr = GVariant*;
    var_ptr* const var_array = new var_ptr[children.size ()];

    for (std::vector<VariantBase>::size_type i = 0; i < children.size (); i++)
      var_array[i] = const_cast<GVariant*> (children[i].gobj ());

    VariantContainerBase result = VariantContainerBase (
        g_variant_new_tuple (var_array, children.size ()));
    delete[] var_array;
    return result;
  }

  auto
  VariantContainerBase::create_tuple (const VariantBase& child) -> VariantContainerBase
  {
    std::vector<VariantBase> vec;
    vec.emplace_back (child);
    return create_tuple (vec);
  }

  auto
  VariantContainerBase::create_maybe (const VariantType& child_type,
                                      const VariantBase& child) -> VariantContainerBase
  {
    GVariant* g_variant = g_variant_new_maybe (
        child_type.gobj (),
        const_cast<GVariant*> (child.gobj ()));
    VariantContainerBase result = VariantContainerBase (g_variant);
    return result;
  }

  auto
  VariantContainerBase::get_child (VariantBase& child, const gsize index) const -> void
  {
    if (index >= get_n_children ())
      throw std::out_of_range (
          "VariantContainerBase::get_child(): Index out of bounds.");

    const GVariant* const gvariant = g_variant_get_child_value (gobject_,
                                                                index);
    child.init (gvariant);
  }

  template <>
  auto
  VariantBase::cast_dynamic<VariantContainerBase> (const VariantBase& v) -> VariantContainerBase
  {
    if (!v.gobj ())
      return {};

    if (v.get_type ().is_container ())
    {
      return VariantContainerBase (const_cast<GVariant*> (v.gobj ()), true);
    }
    else
    {
      throw std::bad_cast ();
    }
  }

  auto
  VariantContainerBase::get_maybe (VariantBase& maybe) const -> bool
  {
    const GVariant* const g_value =
        g_variant_get_maybe (const_cast<GVariant*> (gobj ()));

    if (g_value)
    {
      maybe.init (g_value);
      return true;
    }
    else
    {
      return false;
    }
  }

  auto
  VariantContainerBase::get_iter (
      const VariantType& container_variant_type) const -> VariantIter
  {
    GVariantIter* g_iter = nullptr;
    g_variant_get (const_cast<GVariant*> (gobj ()),
                   is_castable_to (container_variant_type) ?
                       get_type_string ().c_str () :
                       container_variant_type.get_string ().c_str (),
                   &g_iter);

    return VariantIter (g_iter);
  }

  Variant<VariantBase>::Variant ()
    : VariantContainerBase ()
  {
  }

  Variant<VariantBase>::Variant (GVariant* castitem,
                                 const bool take_a_reference)
    : VariantContainerBase (castitem, take_a_reference)
  {
  }

  auto
  Variant<VariantBase>::variant_type () -> const VariantType&
  {
    return VARIANT_TYPE_VARIANT;
  }

  auto
  Variant<VariantBase>::create (const VariantBase& data) -> Variant<VariantBase>
  {
    auto result = Variant<VariantBase> (
        g_variant_new_variant (const_cast<GVariant*> (data.gobj ())));
    return result;
  }

  auto
  Variant<VariantBase>::get (VariantBase& variant) const -> void
  {
    const GVariant* const gvariant = g_variant_get_variant (gobject_);
    variant.init (gvariant);
  }

  Variant<ustring>::Variant ()
    : VariantStringBase ()
  {
  }

  Variant<ustring>::Variant (GVariant* castitem, const bool take_a_reference)
    : VariantStringBase (castitem, take_a_reference)
  {
  }

  auto
  Variant<ustring>::variant_type () -> const VariantType&
  {
    return VARIANT_TYPE_STRING;
  }

  auto
  Variant<ustring>::create (const ustring& data) -> Variant<ustring>
  {
    auto result = Variant<ustring> (g_variant_new_string (data.c_str ()));
    return result;
  }

  auto
  Variant<ustring>::get () const -> ustring
  {
    return convert_const_gchar_ptr_to_ustring (
        g_variant_get_string (gobject_, nullptr));
  }

  Variant<DBusObjectPathString>::Variant ()
    : VariantStringBase ()
  {
  }

  Variant<DBusObjectPathString>::Variant (GVariant* castitem,
                                          const bool take_a_reference)
    : VariantStringBase (castitem, take_a_reference)
  {
  }

  auto
  Variant<DBusObjectPathString>::variant_type () -> const VariantType&
  {
    return VARIANT_TYPE_OBJECT_PATH;
  }

  auto
  Variant<DBusObjectPathString>::create (const DBusObjectPathString& data) -> Variant<DBusObjectPathString>
  {
    auto result = Variant<CppType> (g_variant_new_object_path (data.c_str ()));
    return result;
  }

  auto
  Variant<DBusObjectPathString>::get () const -> DBusObjectPathString
  {
    const char* s = g_variant_get_string (gobject_, nullptr);
    return s ? CppType (s) : CppType ();
  }

  Variant<DBusSignatureString>::Variant ()
    : VariantStringBase ()
  {
  }

  Variant<DBusSignatureString>::Variant (GVariant* castitem,
                                         const bool take_a_reference)
    : VariantStringBase (castitem, take_a_reference)
  {
  }

  auto
  Variant<DBusSignatureString>::variant_type () -> const VariantType&
  {
    return VARIANT_TYPE_SIGNATURE;
  }

  auto
  Variant<DBusSignatureString>::create (const DBusSignatureString& data) -> Variant<DBusSignatureString>
  {
    auto result = Variant<CppType> (g_variant_new_signature (data.c_str ()));
    return result;
  }

  auto
  Variant<DBusSignatureString>::get () const -> DBusSignatureString
  {
    const char* s = g_variant_get_string (gobject_, nullptr);
    return s ? CppType (s) : CppType ();
  }

  Variant<std::string>::Variant ()
    : VariantStringBase ()
  {
  }

  Variant<std::string>::Variant (GVariant* castitem,
                                 const bool take_a_reference)
    : VariantStringBase (castitem, take_a_reference)
  {
  }

  auto
  Variant<std::string>::variant_type () -> const VariantType&
  {
    return VARIANT_TYPE_BYTESTRING;
  }

  auto
  Variant<std::string>::create (const std::string& data) -> Variant<std::string>
  {
    auto result =
        Variant<std::string> (g_variant_new_bytestring (data.c_str ()));
    return result;
  }

  auto
  Variant<std::string>::get () const -> std::string
  {
    const VariantType vtype = get_type ();

    const char* pch = nullptr;
    if (vtype.equal (VARIANT_TYPE_BYTESTRING))
      pch = g_variant_get_bytestring (gobject_);
    else
      pch = g_variant_get_string (gobject_, nullptr);

    return convert_const_gchar_ptr_to_stdstring (pch);
  }

  using type_vec_ustring = std::vector<ustring>;

  Variant<type_vec_ustring>::Variant ()
    : VariantContainerBase ()
  {
  }

  Variant<type_vec_ustring>::Variant (GVariant* castitem,
                                      const bool take_a_reference)
    : VariantContainerBase (castitem, take_a_reference)
  {
  }

  auto
  Variant<type_vec_ustring>::variant_type () -> const VariantType&
  {
    return VARIANT_TYPE_STRING_ARRAY;
  }

  auto
  Variant<type_vec_ustring>::create (const type_vec_ustring& data) -> Variant<type_vec_ustring>
  {
    const VariantType element_variant_type = Variant<ustring>::variant_type ();

    VariantType array_variant_type = variant_type ();

    GVariantBuilder* builder =
        g_variant_builder_new (array_variant_type.gobj ());

    for (const auto& str : data)
      g_variant_builder_add (builder,
                             element_variant_type.get_string ().c_str (),
                             str.c_str ());

    auto result = Variant<type_vec_ustring> (
        g_variant_new (array_variant_type.get_string ().c_str (), builder));

    g_variant_builder_unref (builder);

    return result;
  }

  auto
  Variant<type_vec_ustring>::get_child (const gsize index) const -> ustring
  {
    if (index >= get_n_children ())
      throw std::out_of_range ("Variant< std::vector<Glib::ustring> "
                               ">::get_child(): Index out of bounds.");

    GVariant* gvariant =
        g_variant_get_child_value (const_cast<GVariant*> (gobj ()), index);

    return Glib::Variant<ustring> (gvariant).get ();
  }

  auto
  Variant<type_vec_ustring>::get () const -> type_vec_ustring
  {
    type_vec_ustring result;

    for (gsize i = 0, n_children = get_n_children (); i < n_children; ++i)
    {
      GVariant* gvariant =
          g_variant_get_child_value (const_cast<GVariant*> (gobj ()), i);
      result.emplace_back (Glib::Variant<ustring> (gvariant).get ());
    }

    return result;
  }

  auto
  Variant<type_vec_ustring>::get_iter () const -> VariantIter
  {
    return VariantContainerBase::get_iter (variant_type ());
  }

  using type_vec_opstring = std::vector<DBusObjectPathString>;

  Variant<type_vec_opstring>::Variant ()
    : VariantContainerBase ()
  {
  }

  Variant<type_vec_opstring>::Variant (GVariant* castitem,
                                       const bool take_a_reference)
    : VariantContainerBase (castitem, take_a_reference)
  {
  }

  auto
  Variant<type_vec_opstring>::variant_type () -> const VariantType&
  {
    return VARIANT_TYPE_OBJECT_PATH_ARRAY;
  }

  auto
  Variant<type_vec_opstring>::create (const type_vec_opstring& data) -> Variant<type_vec_opstring>
  {
    const VariantType element_variant_type = Variant<CppType>::variant_type ();

    VariantType array_variant_type = variant_type ();

    GVariantBuilder* builder =
        g_variant_builder_new (array_variant_type.gobj ());

    for (const auto& str : data)
      g_variant_builder_add (builder,
                             element_variant_type.get_string ().c_str (),
                             str.c_str ());

    auto result = Variant<type_vec_opstring> (
        g_variant_new (array_variant_type.get_string ().c_str (), builder));

    g_variant_builder_unref (builder);

    return result;
  }

  auto
  Variant<type_vec_opstring>::get_child (const gsize index) const -> DBusObjectPathString
  {
    if (index >= get_n_children ())
      throw std::out_of_range (
          "Variant< std::vector<Glib::DBusObjectPathString> >::get_child(): "
          "Index out of bounds.");

    GVariant* gvariant =
        g_variant_get_child_value (const_cast<GVariant*> (gobj ()), index);

    return Glib::Variant<CppType> (gvariant).get ();
  }

  auto
  Variant<type_vec_opstring>::get () const -> type_vec_opstring
  {
    gsize n_children = 0;
    const gchar** children =
        g_variant_get_objv (const_cast<GVariant*> (gobj ()), &n_children);
    type_vec_opstring result = type_vec_opstring (children,
                                                  children + n_children);
    g_free (children);
    return result;
  }

  auto
  Variant<type_vec_opstring>::get_iter () const -> VariantIter
  {
    return VariantContainerBase::get_iter (variant_type ());
  }

  using type_vec_string = std::vector<std::string>;

  Variant<type_vec_string>::Variant ()
    : VariantContainerBase ()
  {
  }

  Variant<type_vec_string>::Variant (GVariant* castitem,
                                     const bool take_a_reference)
    : VariantContainerBase (castitem, take_a_reference)
  {
  }

  auto
  Variant<type_vec_string>::variant_type () -> const VariantType&
  {
    return VARIANT_TYPE_BYTESTRING_ARRAY;
  }

  auto
  Variant<type_vec_string>::create (const type_vec_string& data) -> Variant<type_vec_string>
  {
    char** str_array = g_new (char*, data.size () + 1);

    for (type_vec_string::size_type i = 0; i < data.size (); i++)
      str_array[i] = g_strdup (data[i].c_str ());

    str_array[data.size ()] = nullptr;

    auto result = Variant<type_vec_string> (
        g_variant_new_bytestring_array (str_array, data.size ()));

    g_strfreev (str_array);
    return result;
  }

  auto
  Variant<type_vec_string>::create_from_object_paths (
      const type_vec_string& data) -> Variant<type_vec_string>
  {
    char** str_array = g_new (char*, data.size () + 1);

    for (type_vec_string::size_type i = 0; i < data.size (); i++)
      str_array[i] = g_strdup (data[i].c_str ());

    str_array[data.size ()] = nullptr;

    auto result =
        Variant<type_vec_string> (g_variant_new_objv (str_array, data.size ()));

    g_strfreev (str_array);
    return result;
  }

  auto
  Variant<type_vec_string>::get_child (const gsize index) const -> std::string
  {
    if (index >= get_n_children ())
      throw std::out_of_range ("Variant< std::vector<std::string> "
                               ">::get_child(): Index out of bounds.");

    GVariant* gvariant =
        g_variant_get_child_value (const_cast<GVariant*> (gobj ()), index);

    return Glib::Variant<std::string> (gvariant).get ();
  }

  auto
  Variant<type_vec_string>::get () const -> type_vec_string
  {
    type_vec_string result;

    for (gsize i = 0, n_children = get_n_children (); i < n_children; ++i)
    {
      GVariant* gvariant =
          g_variant_get_child_value (const_cast<GVariant*> (gobj ()), i);
      result.emplace_back (Glib::Variant<std::string> (gvariant).get ());
    }

    return result;
  }

  auto
  Variant<type_vec_string>::get_iter () const -> VariantIter
  {
    return VariantContainerBase::get_iter (variant_type ());
  }

  auto
  Value<VariantBase>::set (CppType data) -> void
  {
    set_variant (data.gobj ());
  }

  auto
  Value<VariantBase>::get () const -> CppType
  {
    return CppType (get_variant (), true);
  }

} // namespace Glib

namespace
{
}

Glib::VariantParseError::VariantParseError (const Code error_code,
                                            const ustring& error_message)
  : Error (G_VARIANT_PARSE_ERROR, error_code, error_message)
{
}

Glib::VariantParseError::VariantParseError (GError* gobject)
  : Error (gobject)
{
}

auto
Glib::VariantParseError::code () const -> Code
{
  return static_cast<Code> (Error::code ());
}

auto
Glib::VariantParseError::throw_func (GError* gobject) -> void
{
  throw VariantParseError (gobject);
}

namespace Glib
{

  auto
  wrap (GVariant* object, const bool take_copy) -> VariantBase
  {
    return VariantBase (object, take_copy);
  }

} // namespace Glib

namespace Glib
{

  VariantBase::VariantBase ()
    : gobject_ (nullptr)
  {
  }

  VariantBase::VariantBase (const VariantBase& src)
    : gobject_ (src.gobject_ ? g_variant_ref_sink (src.gobject_) : nullptr)
  {
  }

  auto
  VariantBase::operator= (const VariantBase& src) -> VariantBase&
  {
    const auto new_gobject = src.gobject_ ? g_variant_ref_sink (src.gobject_) :
                                            nullptr;

    if (gobject_)
      g_variant_unref (gobject_);

    gobject_ = new_gobject;

    return *this;
  }

  VariantBase::VariantBase (VariantBase&& other) noexcept
    : gobject_ (other.gobject_)
  {
    other.gobject_ = nullptr;
  }

  auto
  VariantBase::operator= (VariantBase&& other) noexcept -> VariantBase&
  {
    VariantBase temp (std::move (other));
    swap (temp);
    return *this;
  }

  VariantBase::~VariantBase () noexcept
  {
    if (gobject_)
      g_variant_unref (gobject_);
  }

  auto
  VariantBase::swap (VariantBase& other) noexcept -> void
  {
    std::swap (gobject_, other.gobject_);
  }

  auto
  VariantBase::gobj_copy () const -> GVariant*
  {
    return g_variant_ref_sink (gobject_);
  }

  auto
  VariantBase::get_type () const -> VariantType
  {
    return wrap (const_cast<GVariantType*> (
                     g_variant_get_type (const_cast<GVariant*> (gobj ()))),
                 true);
  }

  auto
  VariantBase::get_type_string () const -> std::string
  {
    return convert_const_gchar_ptr_to_stdstring (
        g_variant_get_type_string (const_cast<GVariant*> (gobj ())));
  }

  auto
  VariantBase::is_floating () const -> bool
  {
    return g_variant_is_floating (const_cast<GVariant*> (gobj ()));
  }

  auto
  VariantBase::is_of_type (const VariantType& type) const -> bool
  {
    return g_variant_is_of_type (const_cast<GVariant*> (gobj ()), type.gobj ());
  }

  auto
  VariantBase::is_container () const -> bool
  {
    return g_variant_is_container (const_cast<GVariant*> (gobj ()));
  }

  auto
  VariantBase::classify () const -> GVariantClass
  {
    return g_variant_classify (const_cast<GVariant*> (gobj ()));
  }

  auto
  VariantBase::get_size () const -> gsize
  {
    return g_variant_get_size (const_cast<GVariant*> (gobj ()));
  }

  auto
  VariantBase::get_data () const -> gconstpointer
  {
    return g_variant_get_data (const_cast<GVariant*> (gobj ()));
  }

  auto
  VariantBase::get_data_as_bytes () const -> RefPtr<const Bytes>
  {
    return wrap (g_variant_get_data_as_bytes (const_cast<GVariant*> (gobj ())));
  }

  auto
  VariantBase::store (const gpointer data) const -> void
  {
    g_variant_store (const_cast<GVariant*> (gobj ()), data);
  }

  auto
  VariantBase::print (const bool type_annotate) const -> ustring
  {
    return convert_return_gchar_ptr_to_ustring (
        g_variant_print (const_cast<GVariant*> (gobj ()), type_annotate));
  }

  auto
  VariantBase::hash () const -> guint
  {
    return g_variant_hash (gobj ());
  }

  auto
  VariantBase::equal (const VariantBase& other) const -> bool
  {
    return g_variant_equal (gobj (), other.gobj ());
  }

  auto
  VariantBase::is_normal_form () const -> bool
  {
    return g_variant_is_normal_form (const_cast<GVariant*> (gobj ()));
  }

  auto
  VariantBase::check_format_string (const std::string& format_string,
                                    const bool copy_only) const -> bool
  {
    return g_variant_check_format_string (const_cast<GVariant*> (gobj ()),
                                          format_string.c_str (),
                                          copy_only);
  }

} // namespace Glib

namespace Glib
{

  auto
  VariantStringBase::is_object_path (const std::string& string) -> bool
  {
    return g_variant_is_object_path (string.c_str ());
  }

  auto
  VariantStringBase::is_signature (const std::string& string) -> bool
  {
    return g_variant_is_signature (string.c_str ());
  }

} // namespace Glib

namespace Glib
{

  auto
  VariantContainerBase::get_n_children () const -> gsize
  {
    return g_variant_n_children (const_cast<GVariant*> (gobj ()));
  }

  auto
  VariantContainerBase::get_child (const gsize index) -> VariantBase
  {
    return wrap (g_variant_get_child_value (gobj (), index));
  }

} // namespace Glib

namespace Glib
{

  auto
  Variant<VariantBase>::get () const -> VariantBase
  {
    return wrap (g_variant_get_variant (const_cast<GVariant*> (gobj ())));
  }

} // namespace Glib

namespace Glib
{

}

namespace Glib
{

}

namespace Glib
{

}

namespace Glib
{

}
