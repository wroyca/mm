// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/gio/tlscertificate.hxx>
#include <libmm/gio/tlscertificate_p.hxx>

#include <gio/gio.h>
#include <libmm/gio/socketconnectable.hxx>
#include <libmm/glib/bytearray.hxx>

namespace
{
}

namespace glib
{

  auto
  wrap (GTlsCertificate* object, const bool take_copy) -> RefPtr<gio::TlsCertificate>
  {
    return glib::make_refptr_for_instance<gio::TlsCertificate> (
        dynamic_cast<gio::TlsCertificate*> (
            wrap_auto ((GObject*) object, take_copy)));
  }

} // namespace glib

namespace gio
{

  auto
  TlsCertificate_Class::init () -> const Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &TlsCertificate_Class::class_init_function;

      register_derived_type (g_tls_certificate_get_type ());
    }

    return *this;
  }

  auto
  TlsCertificate_Class::class_init_function (void* g_class, void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);

    klass->verify = &verify_vfunc_callback;
  }

  auto
  TlsCertificate_Class::verify_vfunc_callback (GTlsCertificate* self,
                                               GSocketConnectable* identity,
                                               GTlsCertificate* trusted_ca) -> GTlsCertificateFlags
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
          return static_cast<GTlsCertificateFlags> (
              obj->verify_vfunc (glib::wrap (identity, true),
                                 glib::wrap (trusted_ca, true)));
        }
        catch (...)
        {
          glib::exception_handlers_invoke ();
        }
      }
    }

    const BaseClassType* const base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (self)));

    if (base && base->verify)
      return (*base->verify) (self, identity, trusted_ca);

    using RType = GTlsCertificateFlags;
    return RType ();
  }

  auto
  TlsCertificate_Class::wrap_new (GObject* object) -> glib::ObjectBase*
  {
    return new TlsCertificate ((GTlsCertificate*) object);
  }

  auto
  TlsCertificate::gobj_copy () -> GTlsCertificate*
  {
    reference ();
    return gobj ();
  }

  TlsCertificate::TlsCertificate (const glib::ConstructParams& construct_params)
    : Object (construct_params)
  {
  }

  TlsCertificate::TlsCertificate (GTlsCertificate* castitem)
    : Object ((GObject*) castitem)
  {
  }

  TlsCertificate::TlsCertificate (TlsCertificate&& src) noexcept
    : Object (std::move (src))
  {
  }

  auto
  TlsCertificate::operator= (TlsCertificate&& src) noexcept -> TlsCertificate&
  {
    Object::operator= (std::move (src));
    return *this;
  }

  TlsCertificate::~TlsCertificate () noexcept = default;

  TlsCertificate::CppClassType TlsCertificate::tlscertificate_class_;

  auto
  TlsCertificate::get_type () -> GType
  {
    return tlscertificate_class_.init ().get_type ();
  }

  auto
  TlsCertificate::get_base_type () -> GType
  {
    return g_tls_certificate_get_type ();
  }

  TlsCertificate::TlsCertificate (const std::string& data, const gssize length)
    : ObjectBase (nullptr),
      Object (glib::ConstructParams (tlscertificate_class_.init (),
                                     "data",
                                     data.c_str (),
                                     "length",
                                     length,
                                     nullptr))
  {
  }

  TlsCertificate::TlsCertificate (const std::string& file)
    : ObjectBase (nullptr),
      Object (glib::ConstructParams (tlscertificate_class_.init (),
                                     "file",
                                     file.c_str (),
                                     nullptr))
  {
  }

  TlsCertificate::TlsCertificate (const std::string& cert_file,
                                  const std::string& key_file)
    : ObjectBase (nullptr),
      Object (glib::ConstructParams (tlscertificate_class_.init (),
                                     "cert_file",
                                     cert_file.c_str (),
                                     "key_file",
                                     key_file.c_str (),
                                     nullptr))
  {
  }

  auto
  TlsCertificate::create_from_pem (const std::string& data, const gssize length) -> glib::RefPtr<TlsCertificate>
  {
    GError* gerror = nullptr;
    auto retvalue = glib::wrap (
        g_tls_certificate_new_from_pem (data.c_str (), length, &gerror));
    if (gerror)
      glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  TlsCertificate::create (const std::string& file) -> glib::RefPtr<TlsCertificate>
  {
    GError* gerror = nullptr;
    auto retvalue =
        glib::wrap (g_tls_certificate_new_from_file (file.c_str (), &gerror));
    if (gerror)
      glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  TlsCertificate::create (const std::string& cert_file,
                          const std::string& key_file) -> glib::RefPtr<TlsCertificate>
  {
    GError* gerror = nullptr;
    auto retvalue =
        glib::wrap (g_tls_certificate_new_from_files (cert_file.c_str (),
                                                      key_file.c_str (),
                                                      &gerror));
    if (gerror)
      glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  TlsCertificate::create_list_from_file (const std::string& file) -> std::vector<glib::RefPtr<TlsCertificate>>
  {
    GError* gerror = nullptr;
    auto retvalue =
        glib::ListHandler<glib::RefPtr<TlsCertificate>>::list_to_vector (
            g_tls_certificate_list_new_from_file (file.c_str (), &gerror),
            glib::OWNERSHIP_DEEP);
    if (gerror)
      glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  TlsCertificate::get_issuer () -> glib::RefPtr<TlsCertificate>
  {
    auto retvalue = glib::wrap (g_tls_certificate_get_issuer (gobj ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  TlsCertificate::get_issuer () const -> glib::RefPtr<const TlsCertificate>
  {
    return const_cast<TlsCertificate*> (this)->get_issuer ();
  }

  auto
  TlsCertificate::verify (const glib::RefPtr<const SocketConnectable>& identity,
                          const glib::RefPtr<const TlsCertificate>& trusted_ca)
      const -> TlsCertificateFlags
  {
    return static_cast<TlsCertificateFlags> (g_tls_certificate_verify (
        const_cast<GTlsCertificate*> (gobj ()),
        const_cast<GSocketConnectable*> (glib::unwrap (identity)),
        const_cast<GTlsCertificate*> (glib::unwrap (trusted_ca))));
  }

  auto
  TlsCertificate::verify (const glib::RefPtr<const SocketConnectable>& identity)
      const -> TlsCertificateFlags
  {
    return static_cast<TlsCertificateFlags> (g_tls_certificate_verify (
        const_cast<GTlsCertificate*> (gobj ()),
        const_cast<GSocketConnectable*> (glib::unwrap (identity)),
        nullptr));
  }

  auto
  TlsCertificate::verify (const glib::RefPtr<const TlsCertificate>& trusted_ca)
      const -> TlsCertificateFlags
  {
    return static_cast<TlsCertificateFlags> (g_tls_certificate_verify (
        const_cast<GTlsCertificate*> (gobj ()),
        nullptr,
        const_cast<GTlsCertificate*> (glib::unwrap (trusted_ca))));
  }

  auto
  TlsCertificate::verify () const -> TlsCertificateFlags
  {
    return static_cast<TlsCertificateFlags> (
        g_tls_certificate_verify (const_cast<GTlsCertificate*> (gobj ()),
                                  nullptr,
                                  nullptr));
  }

  auto
  TlsCertificate::is_same (
      const glib::RefPtr<const TlsCertificate>& cert_two) const -> bool
  {
    return g_tls_certificate_is_same (
        const_cast<GTlsCertificate*> (gobj ()),
        const_cast<GTlsCertificate*> (glib::unwrap (cert_two)));
  }

  auto
  TlsCertificate::get_not_valid_before () const -> glib::DateTime
  {
    return glib::wrap (g_tls_certificate_get_not_valid_before (
        const_cast<GTlsCertificate*> (gobj ())));
  }

  auto
  TlsCertificate::get_not_valid_after () const -> glib::DateTime
  {
    return glib::wrap (g_tls_certificate_get_not_valid_after (
        const_cast<GTlsCertificate*> (gobj ())));
  }

  auto
  TlsCertificate::get_subject_name () const -> glib::ustring
  {
    return glib::convert_return_gchar_ptr_to_ustring (
        g_tls_certificate_get_subject_name (
            const_cast<GTlsCertificate*> (gobj ())));
  }

  auto
  TlsCertificate::get_issuer_name () const -> glib::ustring
  {
    return glib::convert_return_gchar_ptr_to_ustring (
        g_tls_certificate_get_issuer_name (
            const_cast<GTlsCertificate*> (gobj ())));
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<
          glib::RefPtr<glib::ByteArray>>::value,
      "Type glib::RefPtr<glib::ByteArray> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  TlsCertificate::property_certificate () const -> glib::PropertyProxy_ReadOnly<glib::RefPtr<glib::ByteArray>>
  {
    return {this, "certificate"};
  }

  auto
  TlsCertificate::property_certificate_pem () const -> glib::PropertyProxy_ReadOnly<std::string>
  {
    return {this, "certificate-pem"};
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<
          glib::RefPtr<glib::ByteArray>>::value,
      "Type glib::RefPtr<glib::ByteArray> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  TlsCertificate::property_private_key () const -> glib::PropertyProxy_ReadOnly<glib::RefPtr<glib::ByteArray>>
  {
    return {this, "private-key"};
  }

  auto
  TlsCertificate::property_private_key_pem () const -> glib::PropertyProxy_ReadOnly<std::string>
  {
    return {this, "private-key-pem"};
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<
          glib::RefPtr<TlsCertificate>>::value,
      "Type glib::RefPtr<TlsCertificate> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  TlsCertificate::property_issuer () const -> glib::PropertyProxy_ReadOnly<glib::RefPtr<TlsCertificate>>
  {
    return {this, "issuer"};
  }

  auto
  TlsCertificate::property_pkcs11_uri () const -> glib::PropertyProxy_ReadOnly<std::string>
  {
    return {this, "pkcs11-uri"};
  }

  auto
  TlsCertificate::property_private_key_pkcs11_uri () const -> glib::PropertyProxy_ReadOnly<std::string>
  {
    return {this, "private-key-pkcs11-uri"};
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<glib::DateTime>::value,
      "Type glib::DateTime cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  TlsCertificate::property_not_valid_before () const -> glib::PropertyProxy_ReadOnly<glib::DateTime>
  {
    return {this, "not-valid-before"};
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<glib::DateTime>::value,
      "Type glib::DateTime cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  TlsCertificate::property_not_valid_after () const -> glib::PropertyProxy_ReadOnly<glib::DateTime>
  {
    return {this, "not-valid-after"};
  }

  auto
  TlsCertificate::property_subject_name () const -> glib::PropertyProxy_ReadOnly<glib::ustring>
  {
    return {this, "subject-name"};
  }

  auto
  TlsCertificate::property_issuer_name () const -> glib::PropertyProxy_ReadOnly<glib::ustring>
  {
    return {this, "issuer-name"};
  }

  auto
  TlsCertificate::verify_vfunc (
      const glib::RefPtr<const SocketConnectable>& identity,
      const glib::RefPtr<const TlsCertificate>& trusted_ca) const -> TlsCertificateFlags
  {
    const auto base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (gobject_)));

    if (base && base->verify)
    {
      const TlsCertificateFlags retval (
          static_cast<TlsCertificateFlags> ((*base->verify) (
              const_cast<GTlsCertificate*> (gobj ()),
              const_cast<GSocketConnectable*> (glib::unwrap (identity)),
              const_cast<GTlsCertificate*> (glib::unwrap (trusted_ca)))));
      return retval;
    }

    using RType = TlsCertificateFlags;
    return RType ();
  }

} // namespace gio
