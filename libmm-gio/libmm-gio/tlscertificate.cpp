


#include <mm/glib/mm-glib.hpp>

#include <mm/gio/tlscertificate.hpp>
#include <mm/gio/private/tlscertificate_p.hpp>


/* Copyright (C) 2012 The giomm Development Team
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

#include <gio/gio.h>
#include <mm/glib/bytearray.hpp>
#include <mm/gio/socketconnectable.hpp>

namespace
{
} // anonymous namespace


namespace Glib
{

auto wrap(GTlsCertificate* object, const bool take_copy) -> RefPtr<Gio::TlsCertificate>
{
  return Glib::make_refptr_for_instance<Gio::TlsCertificate>( dynamic_cast<Gio::TlsCertificate*> (wrap_auto((GObject*)object, take_copy)) );
  //We use dynamic_cast<> in case of multiple inheritance.
}

} /* namespace Glib */


namespace Gio
{


/* The *_Class implementation: */

auto TlsCertificate_Class::init() -> const Class&
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Class has to know the class init function to clone custom types.
    class_init_func_ = &TlsCertificate_Class::class_init_function;

    // This is actually just optimized away, apparently with no harm.
    // Make sure that the parent type has been created.
    //CppClassParent::CppObjectType::get_type();

    // Create the wrapper type, with the same class/instance size as the base type.
    register_derived_type(g_tls_certificate_get_type());

    // Add derived versions of interfaces, if the C type implements any interfaces:

  }

  return *this;
}


auto TlsCertificate_Class::class_init_function (void *g_class, void *class_data) -> void
{
  const auto klass = static_cast<BaseClassType*>(g_class);
  CppClassParent::class_init_function(klass, class_data);

  klass->verify = &verify_vfunc_callback;

}

auto TlsCertificate_Class::verify_vfunc_callback(GTlsCertificate* self, GSocketConnectable* identity, GTlsCertificate* trusted_ca) -> GTlsCertificateFlags
{
  const auto obj_base = Glib::ObjectBase::_get_current_wrapper((GObject*)self);

  // Non-gtkmmproc-generated custom classes implicitly call the default
  // Glib::ObjectBase constructor, which sets is_derived_. But gtkmmproc-
  // generated classes can use this optimisation, which avoids the unnecessary
  // parameter conversions if there is no possibility of the virtual function
  // being overridden:
  if(obj_base && obj_base->is_derived_())
  {
    const auto obj = dynamic_cast<CppObjectType* const>(obj_base);
    if(obj) // This can be NULL during destruction.
    {
      try // Trap C++ exceptions which would normally be lost because this is a C callback.
      {
        // Call the virtual member method, which derived classes might override.
        return static_cast<GTlsCertificateFlags>(obj->verify_vfunc(Glib::wrap(identity, true)
, Glib::wrap(trusted_ca, true)
));
      }
      catch(...)
      {
        Glib::exception_handlers_invoke();
      }
    }
  }

  const BaseClassType *const base = static_cast<BaseClassType*>(
      g_type_class_peek_parent(G_OBJECT_GET_CLASS(self)) // Get the parent class of the object class (The original underlying C class).
  );

  // Call the original underlying C function:
  if(base && base->verify)
    return (*base->verify)(self, identity, trusted_ca);

  using RType = GTlsCertificateFlags;
  return RType();
}


auto TlsCertificate_Class::wrap_new(GObject* object) -> Glib::ObjectBase*
{
  return new TlsCertificate((GTlsCertificate*)object);
}


/* The implementation: */

auto TlsCertificate::gobj_copy() -> GTlsCertificate*
{
  reference();
  return gobj();
}

TlsCertificate::TlsCertificate(const Glib::ConstructParams& construct_params)
: Object(construct_params)
{

}

TlsCertificate::TlsCertificate(GTlsCertificate* castitem)
: Object((GObject*)castitem)
{}


TlsCertificate::TlsCertificate(TlsCertificate&& src) noexcept
: Object(std::move(src))
{}

auto TlsCertificate::operator=(TlsCertificate&& src) noexcept -> TlsCertificate&
{
  Object::operator=(std::move(src));
  return *this;
}


TlsCertificate::~TlsCertificate() noexcept = default;

TlsCertificate::CppClassType TlsCertificate::tlscertificate_class_; // initialize static member

auto TlsCertificate::get_type() -> GType
{
  return tlscertificate_class_.init().get_type();
}


auto TlsCertificate::get_base_type() -> GType
{
  return g_tls_certificate_get_type();
}


TlsCertificate::TlsCertificate(const std::string& data, const gssize length)
:
  // Mark this class as non-derived to allow C++ vfuncs to be skipped.
ObjectBase(nullptr),
Object(Glib::ConstructParams(tlscertificate_class_.init(), "data", data.c_str(), "length", length, nullptr))
{


}

TlsCertificate::TlsCertificate(const std::string& file)
:
  // Mark this class as non-derived to allow C++ vfuncs to be skipped.
ObjectBase(nullptr),
Object(Glib::ConstructParams(tlscertificate_class_.init(), "file", file.c_str(), nullptr))
{


}

TlsCertificate::TlsCertificate(const std::string& cert_file, const std::string& key_file)
:
  // Mark this class as non-derived to allow C++ vfuncs to be skipped.
ObjectBase(nullptr),
Object(Glib::ConstructParams(tlscertificate_class_.init(), "cert_file", cert_file.c_str(), "key_file", key_file.c_str(), nullptr))
{


}

auto TlsCertificate::create_from_pem(const std::string& data, const gssize length) -> Glib::RefPtr<TlsCertificate>
{
  GError* gerror = nullptr;
  auto retvalue = Glib::wrap(g_tls_certificate_new_from_pem(data.c_str(), length, &gerror));
  if(gerror)
    Glib::Error::throw_exception(gerror);
  return retvalue;
}

auto TlsCertificate::create(const std::string& file) -> Glib::RefPtr<TlsCertificate>
{
  GError* gerror = nullptr;
  auto retvalue = Glib::wrap(g_tls_certificate_new_from_file(file.c_str(), &gerror));
  if(gerror)
    Glib::Error::throw_exception(gerror);
  return retvalue;
}

auto TlsCertificate::create(const std::string& cert_file, const std::string& key_file) -> Glib::RefPtr<TlsCertificate>
{
  GError* gerror = nullptr;
  auto retvalue = Glib::wrap(g_tls_certificate_new_from_files(cert_file.c_str(), key_file.c_str(), &gerror));
  if(gerror)
    Glib::Error::throw_exception(gerror);
  return retvalue;
}

auto TlsCertificate::create_list_from_file(const std::string& file) -> std::vector< Glib::RefPtr<TlsCertificate> >
{
  GError* gerror = nullptr;
  auto retvalue = Glib::ListHandler< Glib::RefPtr<TlsCertificate> >::list_to_vector(g_tls_certificate_list_new_from_file(file.c_str(), &gerror), Glib::OWNERSHIP_DEEP);
  if(gerror)
    Glib::Error::throw_exception(gerror);
  return retvalue;
}

auto TlsCertificate::get_issuer() -> Glib::RefPtr<TlsCertificate>
{
  auto retvalue = Glib::wrap(g_tls_certificate_get_issuer(gobj()));
  if(retvalue)
    retvalue->reference(); //The function does not do a ref for us.
  return retvalue;
}

auto TlsCertificate::get_issuer() const -> Glib::RefPtr<const TlsCertificate>
{
  return const_cast<TlsCertificate*>(this)->get_issuer();
}

auto TlsCertificate::verify(const Glib::RefPtr<const SocketConnectable>& identity, const Glib::RefPtr<const TlsCertificate>& trusted_ca) const -> TlsCertificateFlags
{
  return static_cast<TlsCertificateFlags>(g_tls_certificate_verify(const_cast<GTlsCertificate*>(gobj()), const_cast<GSocketConnectable*>(Glib::unwrap(identity)), const_cast<GTlsCertificate*>(Glib::unwrap(trusted_ca))));
}

auto TlsCertificate::verify(const Glib::RefPtr<const SocketConnectable>& identity) const -> TlsCertificateFlags
{
  return static_cast<TlsCertificateFlags>(g_tls_certificate_verify(const_cast<GTlsCertificate*>(gobj()), const_cast<GSocketConnectable*>(Glib::unwrap(identity)), nullptr));
}

auto TlsCertificate::verify(const Glib::RefPtr<const TlsCertificate>& trusted_ca) const -> TlsCertificateFlags
{
  return static_cast<TlsCertificateFlags>(g_tls_certificate_verify(const_cast<GTlsCertificate*>(gobj()), nullptr, const_cast<GTlsCertificate*>(Glib::unwrap(trusted_ca))));
}

auto TlsCertificate::verify() const -> TlsCertificateFlags
{
  return static_cast<TlsCertificateFlags>(g_tls_certificate_verify(const_cast<GTlsCertificate*>(gobj()), nullptr, nullptr));
}

auto TlsCertificate::is_same(const Glib::RefPtr<const TlsCertificate>& cert_two) const -> bool
{
  return g_tls_certificate_is_same(const_cast<GTlsCertificate*>(gobj()), const_cast<GTlsCertificate*>(Glib::unwrap(cert_two)));
}

auto TlsCertificate::get_not_valid_before() const -> Glib::DateTime
{
  return Glib::wrap(g_tls_certificate_get_not_valid_before(const_cast<GTlsCertificate*>(gobj())));
}

auto TlsCertificate::get_not_valid_after() const -> Glib::DateTime
{
  return Glib::wrap(g_tls_certificate_get_not_valid_after(const_cast<GTlsCertificate*>(gobj())));
}

auto TlsCertificate::get_subject_name() const -> Glib::ustring
{
  return Glib::convert_return_gchar_ptr_to_ustring(g_tls_certificate_get_subject_name(const_cast<GTlsCertificate*>(gobj())));
}

auto TlsCertificate::get_issuer_name() const -> Glib::ustring
{
  return Glib::convert_return_gchar_ptr_to_ustring(g_tls_certificate_get_issuer_name(const_cast<GTlsCertificate*>(gobj())));
}


static_assert(Glib::Traits::ValueCompatibleWithWrapProperty<Glib::RefPtr<Glib::ByteArray>>::value,
  "Type Glib::RefPtr<Glib::ByteArray> cannot be used in _WRAP_PROPERTY. "
  "There is no suitable template specialization of Glib::Value<>.");

auto TlsCertificate::property_certificate() const -> Glib::PropertyProxy_ReadOnly< Glib::RefPtr<Glib::ByteArray> >
{
  return {this, "certificate"};
}

auto TlsCertificate::property_certificate_pem() const -> Glib::PropertyProxy_ReadOnly< std::string >
{
  return {this, "certificate-pem"};
}

static_assert(Glib::Traits::ValueCompatibleWithWrapProperty<Glib::RefPtr<Glib::ByteArray>>::value,
  "Type Glib::RefPtr<Glib::ByteArray> cannot be used in _WRAP_PROPERTY. "
  "There is no suitable template specialization of Glib::Value<>.");

auto TlsCertificate::property_private_key() const -> Glib::PropertyProxy_ReadOnly< Glib::RefPtr<Glib::ByteArray> >
{
  return {this, "private-key"};
}

auto TlsCertificate::property_private_key_pem() const -> Glib::PropertyProxy_ReadOnly< std::string >
{
  return {this, "private-key-pem"};
}

static_assert(Glib::Traits::ValueCompatibleWithWrapProperty<Glib::RefPtr<TlsCertificate>>::value,
  "Type Glib::RefPtr<TlsCertificate> cannot be used in _WRAP_PROPERTY. "
  "There is no suitable template specialization of Glib::Value<>.");

auto TlsCertificate::property_issuer() const -> Glib::PropertyProxy_ReadOnly< Glib::RefPtr<TlsCertificate> >
{
  return {this, "issuer"};
}

auto TlsCertificate::property_pkcs11_uri() const -> Glib::PropertyProxy_ReadOnly< std::string >
{
  return {this, "pkcs11-uri"};
}

auto TlsCertificate::property_private_key_pkcs11_uri() const -> Glib::PropertyProxy_ReadOnly< std::string >
{
  return {this, "private-key-pkcs11-uri"};
}

static_assert(Glib::Traits::ValueCompatibleWithWrapProperty<Glib::DateTime>::value,
  "Type Glib::DateTime cannot be used in _WRAP_PROPERTY. "
  "There is no suitable template specialization of Glib::Value<>.");

auto TlsCertificate::property_not_valid_before() const -> Glib::PropertyProxy_ReadOnly< Glib::DateTime >
{
  return {this, "not-valid-before"};
}

static_assert(Glib::Traits::ValueCompatibleWithWrapProperty<Glib::DateTime>::value,
  "Type Glib::DateTime cannot be used in _WRAP_PROPERTY. "
  "There is no suitable template specialization of Glib::Value<>.");

auto TlsCertificate::property_not_valid_after() const -> Glib::PropertyProxy_ReadOnly< Glib::DateTime >
{
  return {this, "not-valid-after"};
}

auto TlsCertificate::property_subject_name() const -> Glib::PropertyProxy_ReadOnly< Glib::ustring >
{
  return {this, "subject-name"};
}

auto TlsCertificate::property_issuer_name() const -> Glib::PropertyProxy_ReadOnly< Glib::ustring >
{
  return {this, "issuer-name"};
}


auto TlsCertificate::verify_vfunc(const Glib::RefPtr<const SocketConnectable>& identity, const Glib::RefPtr<const TlsCertificate>& trusted_ca) const -> TlsCertificateFlags
{
  const auto base = static_cast<BaseClassType*>(
      g_type_class_peek_parent(G_OBJECT_GET_CLASS(gobject_)) // Get the parent class of the object class (The original underlying C class).
  );

  if(base && base->verify)
  {
    const TlsCertificateFlags retval(static_cast<TlsCertificateFlags>((*base->verify)(const_cast<GTlsCertificate*>(gobj()),const_cast<GSocketConnectable*>(Glib::unwrap(identity)),const_cast<GTlsCertificate*>(Glib::unwrap(trusted_ca)))));
    return retval;
  }

  using RType = TlsCertificateFlags;
  return RType();
}


} // namespace Gio


