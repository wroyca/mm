// Generated by gmmproc 2.74.0 -- DO NOT MODIFY!


#include <mm/glib/mm-glib.hpp>

#include <mm/glib/variant.hpp>
#include <mm/glib/private/variant_p.hpp>


/* Copyright 2010 The glibmm Development Team
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

#include <mm/glib/variant.hpp>
#include <mm/glib/utility.hpp>
#include <glib.h>
#include <iostream>

namespace Glib
{

/****************** VariantBase ***********************************/

VariantBase::VariantBase(GVariant* castitem, bool make_a_copy /* = false */)
{
  if (castitem)
  {
    if (g_variant_is_floating(castitem))
      g_variant_ref_sink(castitem);

    if (make_a_copy)
      g_variant_ref(castitem);
  }

  gobject_ = castitem;
}

VariantBase::operator bool() const
{
  return gobj();
}

auto VariantBase::init (const GVariant *cobject, bool take_a_reference) -> void
{
  if (gobject_)
    g_variant_unref(gobject_);

  gobject_ = const_cast<GVariant*>(cobject);
  if (take_a_reference)
    g_variant_ref(gobject_);
}

auto VariantBase::operator==(const VariantBase& other) const -> bool
{
  return equal(other);
}

auto VariantBase::operator!=(const VariantBase& other) const -> bool
{
  return !equal(other);
}

auto VariantBase::get_normal_form (VariantBase &result) const -> void
{
  GVariant* const g_value = g_variant_get_normal_form(const_cast<GVariant*>(gobj()));

  // The C function never returns NULL, according to its documenation,
  // so we don't need a bool return value.
  result.init(g_value); // g_value is already referenced.
}

auto VariantBase::byteswap (VariantBase &result) const -> void
{
  GVariant* const g_value = g_variant_byteswap(const_cast<GVariant*>(gobj()));
  result.init(g_value); // g_value is already referenced.
}

auto
VariantBase::is_castable_to(const VariantType& supertype) const -> bool
{
  const std::string subtype_string = get_type_string();
  const std::string supertype_string = supertype.get_string();

  // The following code is similar to g_variant_type_is_subtype_of(), with
  // these differences:
  // - Both types are assumed to be definite types (no indefinite types,
  //   no 'r', '?' or '*').
  // - VARIANT_TYPE_OBJECT_PATH (o) and VARIANT_TYPE_SIGNATURE (g) can be cast to
  //   VARIANT_TYPE_STRING (s), (Variant<Glib::ustring>::variant_type()).
  // - VARIANT_TYPE_STRING (s), VARIANT_TYPE_OBJECT_PATH (o) and
  //   VARIANT_TYPE_SIGNATURE (g) can be cast to VARIANT_TYPE_BYTESTRING (ay),
  //   (Variant<std::string>::variant_type()).
  // - VARIANT_TYPE_HANDLE (h) can be cast to VARIANT_TYPE_INT32 (i),
  //   (Variant<gint32>::variant_type()).

  std::size_t subtype_index = 0;
  std::size_t supertype_index = 0;
  const std::size_t supertype_size = supertype_string.size();
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
            (subtype_char == 's' || subtype_char == 'o' || subtype_char == 'g')))
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

/****************** VariantStringBase ***********************************/

VariantStringBase::VariantStringBase() : VariantBase()
{
}

VariantStringBase::VariantStringBase(GVariant* castitem, bool take_a_reference)
: VariantBase(castitem, take_a_reference)
{
}

// static
auto VariantStringBase::create_object_path (
  VariantStringBase &output, const std::string &object_path) -> void
{
  GVariant* result = nullptr;
  result = g_variant_new_object_path(object_path.c_str());
  g_variant_ref_sink(result);
  output.init(result);
}

// static
auto VariantStringBase::create_signature (
  VariantStringBase &output, const std::string &signature) -> void
{
  GVariant* result = nullptr;
  result = g_variant_new_signature(signature.c_str());
  g_variant_ref_sink(result);
  output.init(result);
}

/****************** VariantContainerBase ***********************************/

VariantContainerBase::VariantContainerBase() : VariantBase()
{
}

VariantContainerBase::VariantContainerBase(GVariant* castitem, bool take_a_reference)
: VariantBase(castitem, take_a_reference)
{
}

// static
auto
VariantContainerBase::create_tuple(const std::vector<VariantBase>& children) -> VariantContainerBase
{
  using var_ptr = GVariant*;
  var_ptr* const var_array = new var_ptr[children.size()];

  for (std::vector<VariantBase>::size_type i = 0; i < children.size(); i++)
    var_array[i] = const_cast<GVariant*>(children[i].gobj());

  VariantContainerBase result =
    VariantContainerBase(g_variant_new_tuple(var_array, children.size()));
  delete[] var_array;
  return result;
}

// static
auto
VariantContainerBase::create_tuple(const VariantBase& child) -> VariantContainerBase
{
  std::vector<VariantBase> vec;
  vec.emplace_back(child);
  return create_tuple(vec);
}

// static
auto
VariantContainerBase::create_maybe(const VariantType& child_type, const VariantBase& child) -> VariantContainerBase
{
  GVariant* g_variant = g_variant_new_maybe(child_type.gobj(), const_cast<GVariant*>(child.gobj()));
  VariantContainerBase result = VariantContainerBase(g_variant);
  return result;
}

auto VariantContainerBase::get_child (VariantBase &child, gsize index) const -> void
{
  if (index >= get_n_children())
    throw std::out_of_range("VariantContainerBase::get_child(): Index out of bounds.");

  GVariant* const gvariant = g_variant_get_child_value(gobject_, index);
  child.init(gvariant);
}

// VariantContainerBase has no method variant_type()
template <>
auto
VariantBase::cast_dynamic<VariantContainerBase>(const VariantBase& v) -> VariantContainerBase
{
  if (!v.gobj())
    return VariantContainerBase();

  if (v.get_type().is_container())
  {
    return VariantContainerBase(const_cast<GVariant*>(v.gobj()), true);
  }
  else
  {
    // std::cerr << "vtype=" << v.get_type_string() << std::endl;
    throw std::bad_cast();
  }
}

auto
VariantContainerBase::get_maybe(VariantBase& maybe) const -> bool
{
  GVariant* const g_value = g_variant_get_maybe(const_cast<GVariant*>(gobj()));

  if (g_value)
  {
    maybe.init(g_value); // g_value is already referenced.
    return true;
  }
  else
  {
    return false;
  }
}

auto
VariantContainerBase::get_iter(const VariantType& container_variant_type) const -> VariantIter
{
  // Get the GVariantIter.
  // If the underlying GVariant can be cast to the type of the container,
  // use the actual type (which may differ from container_variant_type, if
  // the GVariant contains strings, object paths or DBus type signatures),
  // otherwise let g_variant_get() report what's wrong with the type.
  GVariantIter* g_iter = nullptr;
  g_variant_get(const_cast<GVariant*>(gobj()),
    is_castable_to(container_variant_type) ? get_type_string().c_str()
                                           : container_variant_type.get_string().c_str(),
    &g_iter);

  return VariantIter(g_iter);
}

/****************** Specializations ***********************************/

/*--------------------Variant<VariantBase>---------------------*/

Variant<VariantBase>::Variant() : VariantContainerBase()
{
}

Variant<VariantBase>::Variant(GVariant* castitem, bool take_a_reference)
: VariantContainerBase(castitem, take_a_reference)
{
}

// static
auto
Variant<VariantBase>::variant_type() -> const VariantType&
{
  return VARIANT_TYPE_VARIANT;
}

auto
Variant<VariantBase>::create(const VariantBase& data) -> Variant<VariantBase>
{
  auto result = Variant<VariantBase>(g_variant_new_variant(const_cast<GVariant*>(data.gobj())));
  return result;
}

auto Variant <VariantBase>::get (VariantBase &variant) const -> void
{
  GVariant* const gvariant = g_variant_get_variant(gobject_);
  variant.init(gvariant);
}

/*--------------------Variant<Glib::ustring>---------------------*/

Variant<Glib::ustring>::Variant() : VariantStringBase()
{
}

Variant<Glib::ustring>::Variant(GVariant* castitem, bool take_a_reference)
: VariantStringBase(castitem, take_a_reference)
{
}

// static
auto
Variant<Glib::ustring>::variant_type() -> const VariantType&
{
  return VARIANT_TYPE_STRING;
}

auto
Variant<Glib::ustring>::create(const Glib::ustring& data) -> Variant<Glib::ustring>
{
  auto result = Variant<Glib::ustring>(g_variant_new_string(data.c_str()));
  return result;
}

auto
Variant<Glib::ustring>::get() const -> Glib::ustring
{
  return convert_const_gchar_ptr_to_ustring(g_variant_get_string(gobject_, nullptr));
}

/*--------------------Variant<Glib::DBusObjectPathString>---------------------*/

Variant<Glib::DBusObjectPathString>::Variant() : VariantStringBase()
{
}

Variant<Glib::DBusObjectPathString>::Variant(GVariant* castitem, bool take_a_reference)
: VariantStringBase(castitem, take_a_reference)
{
}

// static
auto
Variant<Glib::DBusObjectPathString>::variant_type() -> const VariantType&
{
  return VARIANT_TYPE_OBJECT_PATH;
}

auto
Variant<Glib::DBusObjectPathString>::create(const Glib::DBusObjectPathString& data) -> Variant<Glib::DBusObjectPathString>
{
  auto result = Variant<CppType>(g_variant_new_object_path(data.c_str()));
  return result;
}

auto
Variant<Glib::DBusObjectPathString>::get() const -> Glib::DBusObjectPathString
{
  const char* s = g_variant_get_string(gobject_, nullptr);
  return s ? CppType(s) : CppType();
}

/*--------------------Variant<Glib::DBusSignatureString>---------------------*/

Variant<Glib::DBusSignatureString>::Variant() : VariantStringBase()
{
}

Variant<Glib::DBusSignatureString>::Variant(GVariant* castitem, bool take_a_reference)
: VariantStringBase(castitem, take_a_reference)
{
}

// static
auto
Variant<Glib::DBusSignatureString>::variant_type() -> const VariantType&
{
  return VARIANT_TYPE_SIGNATURE;
}

auto
Variant<Glib::DBusSignatureString>::create(const Glib::DBusSignatureString& data) -> Variant<Glib::DBusSignatureString>
{
  auto result = Variant<CppType>(g_variant_new_signature(data.c_str()));
  return result;
}

auto
Variant<Glib::DBusSignatureString>::get() const -> Glib::DBusSignatureString
{
  const char* s = g_variant_get_string(gobject_, nullptr);
  return s ? CppType(s) : CppType();
}

/*--------------------Variant<std::string>---------------------*/

Variant<std::string>::Variant() : VariantStringBase()
{
}

Variant<std::string>::Variant(GVariant* castitem, bool take_a_reference)
: VariantStringBase(castitem, take_a_reference)
{
}

// static
auto
Variant<std::string>::variant_type() -> const VariantType&
{
  return VARIANT_TYPE_BYTESTRING;
}

auto
Variant<std::string>::create(const std::string& data) -> Variant<std::string>
{
  auto result = Variant<std::string>(g_variant_new_bytestring(data.c_str()));
  return result;
}

auto
Variant<std::string>::get() const -> std::string
{
  const VariantType vtype = get_type();

  const char* pch = nullptr;
  if (vtype.equal(VARIANT_TYPE_BYTESTRING))
    pch = g_variant_get_bytestring(gobject_);
  else // g_variant_get_string() can handle strings, object paths, and signatures.
    pch = g_variant_get_string(gobject_, nullptr);

  return convert_const_gchar_ptr_to_stdstring(pch);
}

/*--------------------Variant< std::vector<Glib::ustring> >---------------------*/

using type_vec_ustring = std::vector<Glib::ustring>;

Variant<type_vec_ustring>::Variant() : VariantContainerBase()
{
}

Variant<type_vec_ustring>::Variant(GVariant* castitem, bool take_a_reference)
: VariantContainerBase(castitem, take_a_reference)
{
}

// static
auto
Variant<type_vec_ustring>::variant_type() -> const VariantType&
{
  return VARIANT_TYPE_STRING_ARRAY;
}

auto
Variant<type_vec_ustring>::create(const type_vec_ustring& data) -> Variant<type_vec_ustring>
{
  // Get the variant type of the elements.
  VariantType element_variant_type = Variant<Glib::ustring>::variant_type();

  // Get the variant type of the array.
  VariantType array_variant_type = Variant<type_vec_ustring>::variant_type();

  // Create a GVariantBuilder to build the array.
  GVariantBuilder* builder = g_variant_builder_new(array_variant_type.gobj());

  // Add the elements of the vector into the builder.
  for (const auto& str : data)
    g_variant_builder_add(builder, element_variant_type.get_string().c_str(), str.c_str());

  // Create the variant using the builder.
  auto result =
    Variant<type_vec_ustring>(g_variant_new(array_variant_type.get_string().c_str(), builder));

  g_variant_builder_unref(builder);

  return result;
}

auto
Variant<type_vec_ustring>::get_child(gsize index) const -> Glib::ustring
{
  if (index >= get_n_children())
    throw std::out_of_range(
      "Variant< std::vector<Glib::ustring> >::get_child(): Index out of bounds.");

  GVariant* gvariant = g_variant_get_child_value(const_cast<GVariant*>(gobj()), index);

  return Glib::Variant<Glib::ustring>(gvariant).get();
}

auto
Variant<type_vec_ustring>::get() const -> type_vec_ustring
{
  // g_variant_get_strv() can be used only if the type is VARIANT_TYPE_STRING_ARRAY,
  // but the Variant can alternatively hold an array of object paths or DBus type signatures.
  type_vec_ustring result;

  for (gsize i = 0, n_children = get_n_children(); i < n_children; ++i)
  {
    GVariant* gvariant = g_variant_get_child_value(const_cast<GVariant*>(gobj()), i);
    result.emplace_back(Glib::Variant<Glib::ustring>(gvariant).get());
  }

  return result;
}

auto
Variant<type_vec_ustring>::get_iter() const -> VariantIter
{
  return VariantContainerBase::get_iter(variant_type());
}

/*--------------------Variant<std::vector<Glib::DBusObjectPathString>>---------------------*/

using type_vec_opstring = std::vector<Glib::DBusObjectPathString>;

Variant<type_vec_opstring>::Variant() : VariantContainerBase()
{
}

Variant<type_vec_opstring>::Variant(GVariant* castitem, bool take_a_reference)
: VariantContainerBase(castitem, take_a_reference)
{
}

// static
auto
Variant<type_vec_opstring>::variant_type() -> const VariantType&
{
  return VARIANT_TYPE_OBJECT_PATH_ARRAY;
}

// static
auto
Variant<type_vec_opstring>::create(const type_vec_opstring& data) -> Variant<type_vec_opstring>
{
  // Get the variant type of the elements.
  VariantType element_variant_type = Variant<CppType>::variant_type();

  // Get the variant type of the array.
  VariantType array_variant_type = Variant<type_vec_opstring>::variant_type();

  // Create a GVariantBuilder to build the array.
  GVariantBuilder* builder = g_variant_builder_new(array_variant_type.gobj());

  // Add the elements of the vector into the builder.
  for (const auto& str : data)
    g_variant_builder_add(builder, element_variant_type.get_string().c_str(), str.c_str());

  // Create the variant using the builder.
  auto result =
    Variant<type_vec_opstring>(g_variant_new(array_variant_type.get_string().c_str(), builder));

  g_variant_builder_unref(builder);

  return result;
}

auto
Variant<type_vec_opstring>::get_child(gsize index) const -> Glib::DBusObjectPathString
{
  if (index >= get_n_children())
    throw std::out_of_range(
      "Variant< std::vector<Glib::DBusObjectPathString> >::get_child(): Index out of bounds.");

  GVariant* gvariant = g_variant_get_child_value(const_cast<GVariant*>(gobj()), index);

  return Glib::Variant<CppType>(gvariant).get();
}

auto
Variant<type_vec_opstring>::get() const -> type_vec_opstring
{
  gsize n_children = 0;
  const gchar** children = g_variant_get_objv(const_cast<GVariant*>(gobj()), &n_children);
  type_vec_opstring result = type_vec_opstring(children, children+n_children);
  g_free(children);
  return result;
}

auto
Variant<type_vec_opstring>::get_iter() const -> VariantIter
{
  return VariantContainerBase::get_iter(variant_type());
}

/*--------------------Variant< std::vector<std::string> >---------------------*/

using type_vec_string = std::vector<std::string>;

Variant<type_vec_string>::Variant() : VariantContainerBase()
{
}

Variant<type_vec_string>::Variant(GVariant* castitem, bool take_a_reference)
: VariantContainerBase(castitem, take_a_reference)
{
}

// static
auto
Variant<type_vec_string>::variant_type() -> const VariantType&
{
  return VARIANT_TYPE_BYTESTRING_ARRAY;
}

auto
Variant<type_vec_string>::create(const type_vec_string& data) -> Variant<type_vec_string>
{
  // Create a string array to add the strings of the vector to.
  char** str_array = g_new(char*, data.size() + 1);

  // Add the elements of the vector into the string array.
  for (type_vec_string::size_type i = 0; i < data.size(); i++)
    str_array[i] = g_strdup(data[i].c_str());

  // Terminate the string array.
  str_array[data.size()] = nullptr;

  // Create the variant using g_variant_new_bytestring_array() (passing the
  // newly constructed array.
  auto result = Variant<type_vec_string>(g_variant_new_bytestring_array(str_array, data.size()));

  g_strfreev(str_array);
  return result;
}

auto
Variant<type_vec_string>::create_from_object_paths(const type_vec_string& data) -> Variant<type_vec_string>
{
  // Create a string array to add the strings of the vector to.
  char** str_array = g_new(char*, data.size() + 1);

  // Add the elements of the vector into the string array.
  for (type_vec_string::size_type i = 0; i < data.size(); i++)
    str_array[i] = g_strdup(data[i].c_str());

  // Terminate the string array.
  str_array[data.size()] = nullptr;

  // Create the variant using g_variant_new_objv() (passing the
  // newly constructed array.
  auto result = Variant<type_vec_string>(g_variant_new_objv(str_array, data.size()));

  g_strfreev(str_array);
  return result;
}

auto
Variant<type_vec_string>::get_child(gsize index) const -> std::string
{
  if (index >= get_n_children())
    throw std::out_of_range(
      "Variant< std::vector<std::string> >::get_child(): Index out of bounds.");

  GVariant* gvariant = g_variant_get_child_value(const_cast<GVariant*>(gobj()), index);

  return Glib::Variant<std::string>(gvariant).get();
}

auto
Variant<type_vec_string>::get() const -> type_vec_string
{
  // g_variant_get_bytestring_array() can be used only if the type is VARIANT_TYPE_BYTESTRING_ARRAY,
  // but the Variant can alternatively hold an array of strings, object paths or DBus type
  // signatures.
  type_vec_string result;

  for (gsize i = 0, n_children = get_n_children(); i < n_children; ++i)
  {
    GVariant* gvariant = g_variant_get_child_value(const_cast<GVariant*>(gobj()), i);
    result.emplace_back(Glib::Variant<std::string>(gvariant).get());
  }

  return result;
}

auto
Variant<type_vec_string>::get_iter() const -> VariantIter
{
  return VariantContainerBase::get_iter(variant_type());
}

/*---------------------Value<Glib::VariantBase>---------------------*/

auto Value <VariantBase>::set (CppType data) -> void
{
  set_variant(data.gobj());
}

auto Value<VariantBase>::get() const -> Value<VariantBase>::CppType
{
  return CppType(get_variant(), true);
}

} // namespace Glib

namespace
{
} // anonymous namespace


Glib::VariantParseError::VariantParseError(Glib::VariantParseError::Code error_code, const Glib::ustring& error_message)
:
  Glib::Error (G_VARIANT_PARSE_ERROR, error_code, error_message)
{}

Glib::VariantParseError::VariantParseError(GError* gobject)
:
  Glib::Error (gobject)
{}

auto Glib::VariantParseError::code() const -> Glib::VariantParseError::Code
{
  return static_cast<Code>(Glib::Error::code());
}

auto Glib::VariantParseError::throw_func (GError *gobject) -> void
{
  throw Glib::VariantParseError(gobject);
}


namespace Glib
{

auto wrap(GVariant* object, bool take_copy /* = false */) -> Glib::VariantBase
{
  return Glib::VariantBase(object, take_copy);
}

} // namespace Glib


namespace Glib
{


VariantBase::VariantBase()
:
  gobject_ (nullptr) // Allows creation of invalid wrapper, e.g. for output arguments to methods.
{}

VariantBase::VariantBase(const VariantBase& src)
:
  gobject_ ((src.gobject_) ? g_variant_ref_sink(src.gobject_) : nullptr)
{}


auto VariantBase::operator=(const VariantBase& src) -> VariantBase&
{
  const auto new_gobject = (src.gobject_) ? g_variant_ref_sink(src.gobject_) : nullptr;

  if(gobject_)
    g_variant_unref(gobject_);

  gobject_ = new_gobject;

  return *this;
}

VariantBase::VariantBase(VariantBase&& other) noexcept
:
  gobject_(other.gobject_)
{
  other.gobject_ = nullptr;
}

auto VariantBase::operator=(VariantBase&& other) noexcept -> VariantBase&
{
  VariantBase temp (std::move(other));
  swap(temp);
  return *this;
}

VariantBase::~VariantBase() noexcept
{
  if(gobject_)
    g_variant_unref(gobject_);
}

auto VariantBase::swap (VariantBase &other) noexcept -> void
{
  std::swap(gobject_, other.gobject_);
}

auto VariantBase::gobj_copy() const -> GVariant*
{
  return g_variant_ref_sink(gobject_);
}


auto VariantBase::get_type() const -> VariantType
{
  return Glib::wrap(const_cast<GVariantType*>(g_variant_get_type(const_cast<GVariant*>(gobj()))), true);
}

auto VariantBase::get_type_string() const -> std::string
{
  return Glib::convert_const_gchar_ptr_to_stdstring(g_variant_get_type_string(const_cast<GVariant*>(gobj())));
}

auto VariantBase::is_floating() const -> bool
{
  return g_variant_is_floating(const_cast<GVariant*>(gobj()));
}

auto VariantBase::is_of_type(const VariantType& type) const -> bool
{
  return g_variant_is_of_type(const_cast<GVariant*>(gobj()), (type).gobj());
}

auto VariantBase::is_container() const -> bool
{
  return g_variant_is_container(const_cast<GVariant*>(gobj()));
}

auto VariantBase::classify() const -> GVariantClass
{
  return g_variant_classify(const_cast<GVariant*>(gobj()));
}

auto VariantBase::get_size() const -> gsize
{
  return g_variant_get_size(const_cast<GVariant*>(gobj()));
}

auto VariantBase::get_data() const -> gconstpointer
{
  return g_variant_get_data(const_cast<GVariant*>(gobj()));
}

auto VariantBase::get_data_as_bytes() const -> Glib::RefPtr<const Glib::Bytes>
{
  return Glib::wrap(g_variant_get_data_as_bytes(const_cast<GVariant*>(gobj())));
}

auto VariantBase::store (gpointer data) const -> void
{
  g_variant_store(const_cast<GVariant*>(gobj()), data);
}

auto VariantBase::print(bool type_annotate) const -> Glib::ustring
{
  return Glib::convert_return_gchar_ptr_to_ustring(g_variant_print(const_cast<GVariant*>(gobj()), static_cast<int>(type_annotate)));
}

auto VariantBase::hash() const -> guint
{
  return g_variant_hash(const_cast<GVariant*>(gobj()));
}

auto VariantBase::equal(const VariantBase& other) const -> bool
{
  return g_variant_equal(const_cast<GVariant*>(gobj()), const_cast<GVariant*>((other).gobj()));
}

auto VariantBase::is_normal_form() const -> bool
{
  return g_variant_is_normal_form(const_cast<GVariant*>(gobj()));
}

auto VariantBase::check_format_string(const std::string& format_string, bool copy_only) const -> bool
{
  return g_variant_check_format_string(const_cast<GVariant*>(gobj()), format_string.c_str(), static_cast<int>(copy_only));
}


} // namespace Glib


namespace Glib
{


auto VariantStringBase::is_object_path(const std::string& string) -> bool
{
  return g_variant_is_object_path(string.c_str());
}

auto VariantStringBase::is_signature(const std::string& string) -> bool
{
  return g_variant_is_signature(string.c_str());
}


} // namespace Glib


namespace Glib
{


auto VariantContainerBase::get_n_children() const -> gsize
{
  return g_variant_n_children(const_cast<GVariant*>(gobj()));
}

auto VariantContainerBase::get_child(gsize index) -> VariantBase
{
  return Glib::wrap(g_variant_get_child_value(gobj(), index));
}


} // namespace Glib


namespace Glib
{


auto Variant<VariantBase>::get() const -> VariantBase
{
  return Glib::wrap(g_variant_get_variant(const_cast<GVariant*>(gobj())));
}


} // namespace Glib


namespace Glib
{


} // namespace Glib


namespace Glib
{


} // namespace Glib


namespace Glib
{


} // namespace Glib


namespace Glib
{


} // namespace Glib


