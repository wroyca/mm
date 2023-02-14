

#include <libmm-glib/mm-glib.hxx>

#include <libmm-gio/tlspassword.hxx>
#include <libmm-gio/tlspassword_p.hxx>

#include <gio/gio.h>

using Flags = Gio::TlsPassword::Flags;

namespace
{
}

auto
Glib::Value<Gio::TlsPassword::Flags>::value_type () -> GType
{
  return g_tls_password_flags_get_type ();
}

namespace Glib
{

  auto
  wrap (GTlsPassword* object, const bool take_copy) -> RefPtr<Gio::TlsPassword>
  {
    return Glib::make_refptr_for_instance<Gio::TlsPassword> (
        dynamic_cast<Gio::TlsPassword*> (
            wrap_auto ((GObject*) object, take_copy)));
  }

} // namespace Glib

namespace Gio
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
        Glib::ObjectBase::_get_current_wrapper ((GObject*) self);

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
          Glib::exception_handlers_invoke ();
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
        Glib::ObjectBase::_get_current_wrapper ((GObject*) self);

    if (obj_base && obj_base->is_derived_ ())
    {
      const auto obj = dynamic_cast<CppObjectType* const> (obj_base);
      if (obj)
      {
        try
        {
          static auto quark_return_value = g_quark_from_static_string (
              "Gio::TlsPassword::get_default_warning_vfunc");

          auto return_value = static_cast<Glib::ustring*> (
              g_object_get_qdata (obj_base->gobj (), quark_return_value));
          if (!return_value)
          {
            return_value = new Glib::ustring ();
            g_object_set_qdata_full (
                obj_base->gobj (),
                quark_return_value,
                return_value,
                &Glib::destroy_notify_delete<Glib::ustring>);
          }

          *return_value = obj->get_default_warning_vfunc ();
          return (*return_value).c_str ();
        }
        catch (...)
        {
          Glib::exception_handlers_invoke ();
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
  TlsPassword_Class::wrap_new (GObject* object) -> Glib::ObjectBase*
  {
    return new TlsPassword ((GTlsPassword*) object);
  }

  auto
  TlsPassword::gobj_copy () -> GTlsPassword*
  {
    reference ();
    return gobj ();
  }

  TlsPassword::TlsPassword (const Glib::ConstructParams& construct_params)
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

  TlsPassword::TlsPassword (const Glib::ustring& description, const Flags flags)
    : ObjectBase (nullptr),
      Object (Glib::ConstructParams (tlspassword_class_.init (),
                                     "flags",
                                     flags,
                                     "description",
                                     description.c_str (),
                                     nullptr))
  {
  }

  auto
  TlsPassword::create (const Glib::ustring& description, const Flags flags) -> Glib::RefPtr<TlsPassword>
  {
    return Glib::make_refptr_for_instance<TlsPassword> (
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
  TlsPassword::get_description () const -> Glib::ustring
  {
    return Glib::convert_const_gchar_ptr_to_ustring (
        g_tls_password_get_description (const_cast<GTlsPassword*> (gobj ())));
  }

  auto
  TlsPassword::set_description (const Glib::ustring& description) -> void
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
  TlsPassword::get_warning () const -> Glib::ustring
  {
    return Glib::convert_const_gchar_ptr_to_ustring (
        g_tls_password_get_warning (const_cast<GTlsPassword*> (gobj ())));
  }

  auto
  TlsPassword::set_warning (const Glib::ustring& warning) -> void
  {
    g_tls_password_set_warning (gobj (), warning.c_str ());
  }

  auto
  TlsPassword::property_description () -> Glib::PropertyProxy<Glib::ustring>
  {
    return {this, "description"};
  }

  auto
  TlsPassword::property_description () const -> Glib::PropertyProxy_ReadOnly<Glib::ustring>
  {
    return {this, "description"};
  }

  static_assert (
      Glib::Traits::ValueCompatibleWithWrapProperty<Flags>::value,
      "Type Flags cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  auto
  TlsPassword::property_flags () -> Glib::PropertyProxy<Flags>
  {
    return {this, "flags"};
  }

  auto
  TlsPassword::property_flags () const -> Glib::PropertyProxy_ReadOnly<Flags>
  {
    return {this, "flags"};
  }

  auto
  TlsPassword::property_warning () -> Glib::PropertyProxy<Glib::ustring>
  {
    return {this, "warning"};
  }

  auto
  TlsPassword::property_warning () const -> Glib::PropertyProxy_ReadOnly<Glib::ustring>
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
  TlsPassword::get_default_warning_vfunc () const -> Glib::ustring
  {
    const auto base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (gobject_)));

    if (base && base->get_default_warning)
    {
      Glib::ustring retval (Glib::convert_const_gchar_ptr_to_ustring (
          (*base->get_default_warning) (const_cast<GTlsPassword*> (gobj ()))));
      return retval;
    }

    using RType = Glib::ustring;
    return {};
  }

} // namespace Gio
