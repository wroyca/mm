/* Copyright 2002 The gtkmm Development Team
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

#include <mm/glib/value.h>
#include <mm/glib/objectbase.h>
#include <mm/glib/utility.h>
#include <mm/glib/vectorutils.h>
#include <mm/glib/wrap.h>
#include <cstring> // std::memset()

namespace Glib
{

/**** Glib::ValueBase ******************************************************/

ValueBase::ValueBase()
{
  std::memset(&gobject_, 0, sizeof(GValue));
}

void
ValueBase::init(GType type)
{
  g_value_init(&gobject_, type);
}

void
ValueBase::init(const GValue* value)
{
  g_value_init(&gobject_, G_VALUE_TYPE(value));

  if (value)
    g_value_copy(value, &gobject_);
}

ValueBase::ValueBase(const ValueBase& other)
{
  std::memset(&gobject_, 0, sizeof(GValue));

  g_value_init(&gobject_, G_VALUE_TYPE(&other.gobject_));
  g_value_copy(&other.gobject_, &gobject_);
}

auto
ValueBase::operator=(const ValueBase& other) -> ValueBase&
{
  // g_value_copy() prevents self-assignment and deletes the destination.
  g_value_copy(&other.gobject_, &gobject_);
  return *this;
}

ValueBase::~ValueBase() noexcept
{
  g_value_unset(&gobject_);
}

void
ValueBase::reset()
{
  g_value_reset(&gobject_);
}

/**** Glib::ValueBase_Boxed ************************************************/

// static
auto
ValueBase_Boxed::value_type() -> GType
{
  return G_TYPE_BOXED;
}

void
ValueBase_Boxed::set_boxed(const void* data)
{
  g_value_set_boxed(&gobject_, data);
}

auto
ValueBase_Boxed::get_boxed() const -> void*
{
  return g_value_get_boxed(&gobject_);
}

auto ValueBase_Boxed::create_param_spec(const Glib::ustring& name,
  const Glib::ustring& nick, const Glib::ustring& blurb, Glib::ParamFlags flags) const -> GParamSpec*
{
  return g_param_spec_boxed(
      name.c_str(), c_str_or_nullptr(nick), c_str_or_nullptr(blurb),
      G_VALUE_TYPE(&gobject_), static_cast<GParamFlags>(flags));
}

/**** Glib::ValueBase_Object ***********************************************/

// static
auto
ValueBase_Object::value_type() -> GType
{
  return G_TYPE_OBJECT;
}

void
ValueBase_Object::set_object(Glib::ObjectBase* data)
{
  g_value_set_object(&gobject_, (data) ? data->gobj() : nullptr);
}

auto
ValueBase_Object::get_object() const -> Glib::ObjectBase*
{
  GObject* const data = static_cast<GObject*>(g_value_get_object(&gobject_));
  return Glib::wrap_auto(data, false);
}

auto
ValueBase_Object::get_object_copy() const -> Glib::RefPtr<Glib::ObjectBase>
{
  GObject* const data = static_cast<GObject*>(g_value_get_object(&gobject_));
  return Glib::make_refptr_for_instance<Glib::ObjectBase>(Glib::wrap_auto(data, true));
}

auto
ValueBase_Object::create_param_spec(const Glib::ustring& name,
  const Glib::ustring& nick, const Glib::ustring& blurb, Glib::ParamFlags flags) const -> GParamSpec*
{
  // Glib::Value_Pointer<> derives from Glib::ValueBase_Object, because
  // we don't know beforehand whether a certain type is derived from
  // Glib::Object or not.  To keep create_param_spec() out of the template
  // struggle, we dispatch here at runtime.

  if (G_VALUE_HOLDS_OBJECT(&gobject_))
  {
    return g_param_spec_object(name.c_str(), c_str_or_nullptr(nick), c_str_or_nullptr(blurb),
      G_VALUE_TYPE(&gobject_), static_cast<GParamFlags>(flags));
  }
  else
  {
    g_return_val_if_fail(G_VALUE_HOLDS_POINTER(&gobject_), nullptr);

    return g_param_spec_pointer(
      name.c_str(), c_str_or_nullptr(nick), c_str_or_nullptr(blurb),
      static_cast<GParamFlags>(flags));
  }
}

/**** Glib::ValueBase_Enum *************************************************/

// static
auto
ValueBase_Enum::value_type() -> GType
{
  return G_TYPE_ENUM;
}

void
ValueBase_Enum::set_enum(int data)
{
  g_value_set_enum(&gobject_, data);
}

auto
ValueBase_Enum::get_enum() const -> int
{
  return g_value_get_enum(&gobject_);
}

auto
ValueBase_Enum::create_param_spec(const Glib::ustring& name,
  const Glib::ustring& nick, const Glib::ustring& blurb, Glib::ParamFlags flags) const -> GParamSpec*
{
  return g_param_spec_enum(
      name.c_str(), c_str_or_nullptr(nick), c_str_or_nullptr(blurb), G_VALUE_TYPE(&gobject_),
      g_value_get_enum(&gobject_), static_cast<GParamFlags>(flags));
}

/**** Glib::ValueBase_Flags ************************************************/

// static
auto
ValueBase_Flags::value_type() -> GType
{
  return G_TYPE_FLAGS;
}

void
ValueBase_Flags::set_flags(unsigned int data)
{
  g_value_set_flags(&gobject_, data);
}

auto
ValueBase_Flags::get_flags() const -> unsigned int
{
  return g_value_get_flags(&gobject_);
}

auto ValueBase_Flags::create_param_spec(const Glib::ustring& name,
  const Glib::ustring& nick, const Glib::ustring& blurb, Glib::ParamFlags flags) const -> GParamSpec*
{
  return g_param_spec_flags(name.c_str(), c_str_or_nullptr(nick), c_str_or_nullptr(blurb),
      G_VALUE_TYPE(&gobject_), g_value_get_flags(&gobject_), static_cast<GParamFlags>(flags));
}

/**** Glib::ValueBase_String ***********************************************/

// static
auto
ValueBase_String::value_type() -> GType
{
  return G_TYPE_STRING;
}

void
ValueBase_String::set_cstring(const char* data)
{
  g_value_set_string(&gobject_, data);
}

auto
ValueBase_String::get_cstring() const -> const char*
{
  if (const char* const data = g_value_get_string(&gobject_))
    return data;
  else
    return "";
}

auto
ValueBase_String::create_param_spec(const Glib::ustring& name,
  const Glib::ustring& nick, const Glib::ustring& blurb, Glib::ParamFlags flags) const -> GParamSpec*
{
  return g_param_spec_string(name.c_str(), c_str_or_nullptr(nick), c_str_or_nullptr(blurb),
      get_cstring(), static_cast<GParamFlags>(flags));
}

/**** Glib::ValueBase_Variant ************************************************/

// static
auto ValueBase_Variant::value_type() -> GType
{
  return G_TYPE_VARIANT;
}

void ValueBase_Variant::set_variant(GVariant* data)
{
  g_value_set_variant(&gobject_, data);
}

auto ValueBase_Variant::get_variant() const -> GVariant*
{
  return g_value_get_variant(&gobject_);
}

auto ValueBase_Variant::create_param_spec(const Glib::ustring& name,
  const Glib::ustring& nick, const Glib::ustring& blurb, Glib::ParamFlags flags) const -> GParamSpec*
{
  GVariant* gvariant = g_value_get_variant(&gobject_);
  const GVariantType* gvariant_type = gvariant ? g_variant_get_type(gvariant) : G_VARIANT_TYPE_ANY;

  return g_param_spec_variant(
    name.c_str(), c_str_or_nullptr(nick), c_str_or_nullptr(blurb),
    gvariant_type, gvariant, static_cast<GParamFlags>(flags));
}

/**** Glib::Value<std::string> *********************************************/

void
Value<std::string>::set(const std::string& data)
{
  g_value_set_string(&gobject_, data.c_str());
}

/**** Glib::Value<Glib::ustring> *******************************************/

void
Value<Glib::ustring>::set(const Glib::ustring& data)
{
  g_value_set_string(&gobject_, data.c_str());
}

/**** Glib::Value<std::vector<std::string>> ********************************/

// static
auto Value<std::vector<std::string>>::value_type() -> GType
{
  return G_TYPE_STRV;
}

void Value<std::vector<std::string>>::set(const CppType& data)
{
  set_boxed(Glib::ArrayHandler<std::string>::vector_to_array(data).data());
}

auto Value<std::vector<std::string>>::get() const -> std::vector<std::string>
{
  return Glib::ArrayHandler<std::string>::array_to_vector(
    static_cast<const char* const*>(get_boxed()), Glib::OWNERSHIP_NONE);
}

/**** Glib::Value<std::vector<Glib::ustring>> ********************************/

// static
auto Value<std::vector<Glib::ustring>>::value_type() -> GType
{
  return G_TYPE_STRV;
}

void Value<std::vector<Glib::ustring>>::set(const CppType& data)
{
  set_boxed(Glib::ArrayHandler<Glib::ustring>::vector_to_array(data).data());
}

auto Value<std::vector<Glib::ustring>>::get() const -> std::vector<Glib::ustring>
{
  return Glib::ArrayHandler<Glib::ustring>::array_to_vector(
    static_cast<const char* const*>(get_boxed()), Glib::OWNERSHIP_NONE);
}

} // namespace Glib
