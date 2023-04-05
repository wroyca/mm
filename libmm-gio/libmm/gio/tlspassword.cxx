// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/gio/tlspassword.hxx>
#include <libmm/gio/tlspassword_p.hxx>

#include <gio/gio.h>

using Flags = gio::TlsPassword::Flags;

namespace
{
}

auto
glib::Value<gio::TlsPassword::Flags>::value_type () -> GType
{
  return g_tls_password_flags_get_type ();
}

namespace glib
{

  auto
  wrap (GTlsPassword* object, const bool take_copy) -> RefPtr<gio::TlsPassword>
  {
    return glib::make_refptr_for_instance<gio::TlsPassword> (
        dynamic_cast<gio::TlsPassword*> (
            wrap_auto ((GObject*) object, take_copy)));
  }

} // namespace glib

namespace gio
{

  auto
  TlsPassword_Class::init () -> const Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &TlsPassword_Class::class_init_function;

      register_derived_type (g_tls_password_get_type ());
    }

    return *this;
  }

  auto
  TlsPassword_Class::class_init_function (void* g_class, void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);

    klass->get_value = &get_value_vfunc_callback;
    klass->get_default_warning = &get_default_warning_vfunc_callback;
  }

  auto
  TlsPassword_Class::get_value_vfunc_callback (GTlsPassword* self,
                                               gsize* length) -> const guchar*
  {
    const auto obj_base =
        glib::ObjectBase::_get_current_wrapper ((GObject*) self);

    if (obj_base && obj_base->is_derived_ ())
    {
      const auto obj = dynamic_cast<CppObjectType* const> (obj_base);
      if (obj)
      {
        try
        {
          return obj->get_value_vfunc (*length);
        }
        catch (...)
        {
          glib::exception_handlers_invoke ();
        }
      }
    }

    const BaseClassType* const base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (self)));

    if (base && base->get_value)
      return (*base->get_value) (self, length);

    using RType = const guchar*;
    return RType ();
  }

  auto
  TlsPassword_Class::get_default_warning_vfunc_callback (GTlsPassword* self) -> const gchar*
  {
    const auto obj_base =
        glib::ObjectBase::_get_current_wrapper ((GObject*) self);

    if (obj_base && obj_base->is_derived_ ())
    {
      const auto obj = dynamic_cast<CppObjectType* const> (obj_base);
      if (obj)
      {
        try
        {
          static auto quark_return_value = g_quark_from_static_string (
              "gio::TlsPassword::get_default_warning_vfunc");

          auto return_value = static_cast<glib::ustring*> (
              g_object_get_qdata (obj_base->gobj (), quark_return_value));
          if (!return_value)
          {
            return_value = new glib::ustring ();
            g_object_set_qdata_full (
                obj_base->gobj (),
                quark_return_value,
                return_value,
                &glib::destroy_notify_delete<glib::ustring>);
          }

          *return_value = obj->get_default_warning_vfunc ();
          return (*return_value).c_str ();
        }
        catch (...)
        {
          glib::exception_handlers_invoke ();
        }
      }
    }

    const BaseClassType* const base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (self)));

    if (base && base->get_default_warning)
      return (*base->get_default_warning) (self);

    using RType = const gchar*;
    return RType ();
  }

  auto
  TlsPassword_Class::wrap_new (GObject* object) -> glib::ObjectBase*
  {
    return new TlsPassword ((GTlsPassword*) object);
  }

  auto
  TlsPassword::gobj_copy () -> GTlsPassword*
  {
    reference ();
    return gobj ();
  }

  TlsPassword::TlsPassword (const glib::ConstructParams& construct_params)
    : Object (construct_params)
  {
  }

  TlsPassword::TlsPassword (GTlsPassword* castitem)
    : Object ((GObject*) castitem)
  {
  }

  TlsPassword::TlsPassword (TlsPassword&& src) noexcept
    : Object (std::move (src))
  {
  }

  auto
  TlsPassword::operator= (TlsPassword&& src) noexcept -> TlsPassword&
  {
    Object::operator= (std::move (src));
    return *this;
  }

  TlsPassword::~TlsPassword () noexcept = default;

  TlsPassword::CppClassType TlsPassword::tlspassword_class_;

  auto
  TlsPassword::get_type () -> GType
  {
    return tlspassword_class_.init ().get_type ();
  }

  auto
  TlsPassword::get_base_type () -> GType
  {
    return g_tls_password_get_type ();
  }

  TlsPassword::TlsPassword (const glib::ustring& description, const Flags flags)
    : ObjectBase (nullptr),
      Object (glib::ConstructParams (tlspassword_class_.init (),
                                     "flags",
                                     flags,
                                     "description",
                                     description.c_str (),
                                     nullptr))
  {
  }

  auto
  TlsPassword::create (const glib::ustring& description, const Flags flags) -> glib::RefPtr<TlsPassword>
  {
    return glib::make_refptr_for_instance<TlsPassword> (
        new TlsPassword (description, flags));
  }

  auto
  TlsPassword::get_value (gsize& length) const -> const guchar*
  {
    return g_tls_password_get_value (const_cast<GTlsPassword*> (gobj ()),
                                     &length);
  }

  auto
  TlsPassword::get_value () const -> const guchar*
  {
    return g_tls_password_get_value (const_cast<GTlsPassword*> (gobj ()),
                                     nullptr);
  }

  auto
  TlsPassword::set_value (const guchar* value, const gssize length) -> void
  {
    g_tls_password_set_value (gobj (), value, length);
  }

  auto
  TlsPassword::get_description () const -> glib::ustring
  {
    return glib::convert_const_gchar_ptr_to_ustring (
        g_tls_password_get_description (const_cast<GTlsPassword*> (gobj ())));
  }

  auto
  TlsPassword::set_description (const glib::ustring& description) -> void
  {
    g_tls_password_set_description (gobj (), description.c_str ());
  }

  auto
  TlsPassword::get_flags () const -> Flags
  {
    return static_cast<Flags> (
        g_tls_password_get_flags (const_cast<GTlsPassword*> (gobj ())));
  }

  auto
  TlsPassword::set_flags (Flags flags) -> void
  {
    g_tls_password_set_flags (gobj (), static_cast<GTlsPasswordFlags> (flags));
  }

  auto
  TlsPassword::get_warning () const -> glib::ustring
  {
    return glib::convert_const_gchar_ptr_to_ustring (
        g_tls_password_get_warning (const_cast<GTlsPassword*> (gobj ())));
  }

  auto
  TlsPassword::set_warning (const glib::ustring& warning) -> void
  {
    g_tls_password_set_warning (gobj (), warning.c_str ());
  }

  auto
  TlsPassword::property_description () -> glib::PropertyProxy<glib::ustring>
  {
    return {this, "description"};
  }

  auto
  TlsPassword::property_description () const -> glib::PropertyProxy_ReadOnly<glib::ustring>
  {
    return {this, "description"};
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<Flags>::value,
      "Type Flags cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  TlsPassword::property_flags () -> glib::PropertyProxy<Flags>
  {
    return {this, "flags"};
  }

  auto
  TlsPassword::property_flags () const -> glib::PropertyProxy_ReadOnly<Flags>
  {
    return {this, "flags"};
  }

  auto
  TlsPassword::property_warning () -> glib::PropertyProxy<glib::ustring>
  {
    return {this, "warning"};
  }

  auto
  TlsPassword::property_warning () const -> glib::PropertyProxy_ReadOnly<glib::ustring>
  {
    return {this, "warning"};
  }

  auto
  TlsPassword::get_value_vfunc (gsize& length) const -> const guchar*
  {
    const auto base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (gobject_)));

    if (base && base->get_value)
    {
      const guchar* retval (
          (*base->get_value) (const_cast<GTlsPassword*> (gobj ()), &length));
      return retval;
    }

    using RType = const guchar*;
    return RType ();
  }

  auto
  TlsPassword::get_default_warning_vfunc () const -> glib::ustring
  {
    const auto base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (gobject_)));

    if (base && base->get_default_warning)
    {
      glib::ustring retval (glib::convert_const_gchar_ptr_to_ustring (
          (*base->get_default_warning) (const_cast<GTlsPassword*> (gobj ()))));
      return retval;
    }

    using RType = glib::ustring;
    return {};
  }

} // namespace gio
