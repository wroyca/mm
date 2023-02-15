// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm-glib/mm-glib.hxx>

#include <libmm-gio/tlsdatabase.hxx>
#include <libmm-gio/tlsdatabase_p.hxx>

#include <gio/gio.h>
#include <libmm-gio/cancellable.hxx>
#include <libmm-gio/slot_async.hxx>
#include <libmm-gio/socketconnectable.hxx>
#include <libmm-gio/tlscertificate.hxx>
#include <libmm-gio/tlsinteraction.hxx>

using VerifyFlags = Gio::TlsDatabase::VerifyFlags;
using LookupFlags = Gio::TlsDatabase::LookupFlags;

namespace
{

  auto
  list_copy_ref (const void* src, void*) -> void*
  {
    return g_object_ref (const_cast<void*> (src));
  }
} // namespace

namespace
{
}

auto
Glib::Value<Gio::TlsDatabase::VerifyFlags>::value_type () -> GType
{
  return g_tls_database_verify_flags_get_type ();
}

auto
Glib::Value<Gio::TlsDatabase::LookupFlags>::value_type () -> GType
{
  return g_tls_database_lookup_flags_get_type ();
}

namespace Glib
{

  auto
  wrap (GTlsDatabase* object, const bool take_copy) -> RefPtr<Gio::TlsDatabase>
  {
    return Glib::make_refptr_for_instance<Gio::TlsDatabase> (
        dynamic_cast<Gio::TlsDatabase*> (
            wrap_auto ((GObject*) object, take_copy)));
  }

} // namespace Glib

namespace Gio
{

  auto
  TlsDatabase_Class::init () -> const Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &TlsDatabase_Class::class_init_function;

      register_derived_type (g_tls_database_get_type ());
    }

    return *this;
  }

  auto
  TlsDatabase_Class::class_init_function (void* g_class, void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);

    klass->verify_chain = &verify_chain_vfunc_callback;
    klass->verify_chain_async = &verify_chain_async_vfunc_callback;
    klass->verify_chain_finish = &verify_chain_finish_vfunc_callback;
    klass->create_certificate_handle =
        &create_certificate_handle_vfunc_callback;
    klass->lookup_certificate_for_handle =
        &lookup_certificate_for_handle_vfunc_callback;
    klass->lookup_certificate_for_handle_async =
        &lookup_certificate_for_handle_async_vfunc_callback;
    klass->lookup_certificate_for_handle_finish =
        &lookup_certificate_for_handle_finish_vfunc_callback;
    klass->lookup_certificate_issuer =
        &lookup_certificate_issuer_vfunc_callback;
    klass->lookup_certificate_issuer_async =
        &lookup_certificate_issuer_async_vfunc_callback;
    klass->lookup_certificate_issuer_finish =
        &lookup_certificate_issuer_finish_vfunc_callback;
    klass->lookup_certificates_issued_by =
        &lookup_certificates_issued_by_vfunc_callback;
    klass->lookup_certificates_issued_by_async =
        &lookup_certificates_issued_by_async_vfunc_callback;
    klass->lookup_certificates_issued_by_finish =
        &lookup_certificates_issued_by_finish_vfunc_callback;
  }

  auto
  TlsDatabase_Class::verify_chain_vfunc_callback (GTlsDatabase* self,
                                                  GTlsCertificate* chain,
                                                  const gchar* purpose,
                                                  GSocketConnectable* identity,
                                                  GTlsInteraction* interaction,
                                                  GTlsDatabaseVerifyFlags flags,
                                                  GCancellable* cancellable,
                                                  GError** error) -> GTlsCertificateFlags
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
          return static_cast<GTlsCertificateFlags> (obj->verify_chain_vfunc (
              Glib::wrap (chain, true),
              Glib::convert_const_gchar_ptr_to_ustring (purpose),
              Glib::wrap (identity, true),
              Glib::wrap (interaction, true),
              Glib::wrap (cancellable),
              static_cast<VerifyFlags> (flags)));
        }
        catch (Glib::Error& errormm)
        {
          errormm.propagate (error);
          using RType = GTlsCertificateFlags;
          return RType ();
        }
        catch (...)
        {
          Glib::exception_handlers_invoke ();
        }
      }
    }

    const BaseClassType* const base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (self)));

    if (base && base->verify_chain)
      return (*base->verify_chain) (self,
                                    chain,
                                    purpose,
                                    identity,
                                    interaction,
                                    flags,
                                    cancellable,
                                    error);

    using RType = GTlsCertificateFlags;
    return RType ();
  }

  auto
  TlsDatabase_Class::verify_chain_async_vfunc_callback (
      GTlsDatabase* self,
      GTlsCertificate* chain,
      const gchar* purpose,
      GSocketConnectable* identity,
      GTlsInteraction* interaction,
      GTlsDatabaseVerifyFlags flags,
      GCancellable* cancellable,
      const GAsyncReadyCallback callback,
      const gpointer user_data) -> void
  {
    const auto slot = static_cast<SlotAsyncReady*> (user_data);

    const auto obj_base =
        Glib::ObjectBase::_get_current_wrapper ((GObject*) self);

    if (obj_base && obj_base->is_derived_ ())
    {
      const auto obj = dynamic_cast<CppObjectType* const> (obj_base);
      if (obj)
      {
        try
        {
          obj->verify_chain_async_vfunc (
              Glib::wrap (chain, true),
              Glib::convert_const_gchar_ptr_to_ustring (purpose),
              Glib::wrap (identity, true),
              Glib::wrap (interaction, true),
              *slot,
              Glib::wrap (cancellable),
              static_cast<VerifyFlags> (flags));
          return;
        }
        catch (...)
        {
          Glib::exception_handlers_invoke ();
        }
      }
    }

    const BaseClassType* const base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (self)));

    if (base && base->verify_chain_async)
      (*base->verify_chain_async) (self,
                                   chain,
                                   purpose,
                                   identity,
                                   interaction,
                                   flags,
                                   cancellable,
                                   callback,
                                   user_data);
  }

  auto
  TlsDatabase_Class::verify_chain_finish_vfunc_callback (GTlsDatabase* self,
                                                         GAsyncResult* result,
                                                         GError** error) -> GTlsCertificateFlags
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
          return static_cast<GTlsCertificateFlags> (
              obj->verify_chain_finish_vfunc (Glib::wrap (result, true)));
        }
        catch (Glib::Error& errormm)
        {
          errormm.propagate (error);
          using RType = GTlsCertificateFlags;
          return RType ();
        }
        catch (...)
        {
          Glib::exception_handlers_invoke ();
        }
      }
    }

    const BaseClassType* const base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (self)));

    if (base && base->verify_chain_finish)
      return (*base->verify_chain_finish) (self, result, error);

    using RType = GTlsCertificateFlags;
    return RType ();
  }

  auto
  TlsDatabase_Class::create_certificate_handle_vfunc_callback (
      GTlsDatabase* self,
      GTlsCertificate* certificate) -> gchar*
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
          return g_strdup (
              c_str_or_nullptr (obj->create_certificate_handle_vfunc (
                  Glib::wrap (certificate, true))));
        }
        catch (...)
        {
          Glib::exception_handlers_invoke ();
        }
      }
    }

    const BaseClassType* const base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (self)));

    if (base && base->create_certificate_handle)
      return (*base->create_certificate_handle) (self, certificate);

    using RType = gchar*;
    return RType ();
  }

  auto
  TlsDatabase_Class::lookup_certificate_for_handle_vfunc_callback (
      GTlsDatabase* self,
      const gchar* handle,
      GTlsInteraction* interaction,
      GTlsDatabaseLookupFlags flags,
      GCancellable* cancellable,
      GError** error) -> GTlsCertificate*
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
          return unwrap_copy (obj->lookup_certificate_for_handle_vfunc (
              Glib::convert_const_gchar_ptr_to_ustring (handle),
              Glib::wrap (interaction, true),
              Glib::wrap (cancellable),
              static_cast<LookupFlags> (flags)));
        }
        catch (Glib::Error& errormm)
        {
          errormm.propagate (error);
          using RType = GTlsCertificate*;
          return RType ();
        }
        catch (...)
        {
          Glib::exception_handlers_invoke ();
        }
      }
    }

    const BaseClassType* const base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (self)));

    if (base && base->lookup_certificate_for_handle)
      return (*base->lookup_certificate_for_handle) (self,
                                                     handle,
                                                     interaction,
                                                     flags,
                                                     cancellable,
                                                     error);

    using RType = GTlsCertificate*;
    return RType ();
  }

  auto
  TlsDatabase_Class::lookup_certificate_for_handle_async_vfunc_callback (
      GTlsDatabase* self,
      const gchar* handle,
      GTlsInteraction* interaction,
      GTlsDatabaseLookupFlags flags,
      GCancellable* cancellable,
      const GAsyncReadyCallback callback,
      const gpointer user_data) -> void
  {
    const auto slot = static_cast<SlotAsyncReady*> (user_data);

    const auto obj_base =
        Glib::ObjectBase::_get_current_wrapper ((GObject*) self);

    if (obj_base && obj_base->is_derived_ ())
    {
      const auto obj = dynamic_cast<CppObjectType* const> (obj_base);
      if (obj)
      {
        try
        {
          obj->lookup_certificate_for_handle_async_vfunc (
              Glib::convert_const_gchar_ptr_to_ustring (handle),
              Glib::wrap (interaction, true),
              *slot,
              Glib::wrap (cancellable),
              static_cast<LookupFlags> (flags));
          return;
        }
        catch (...)
        {
          Glib::exception_handlers_invoke ();
        }
      }
    }

    const BaseClassType* const base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (self)));

    if (base && base->lookup_certificate_for_handle_async)
      (*base->lookup_certificate_for_handle_async) (self,
                                                    handle,
                                                    interaction,
                                                    flags,
                                                    cancellable,
                                                    callback,
                                                    user_data);
  }

  auto
  TlsDatabase_Class::lookup_certificate_for_handle_finish_vfunc_callback (
      GTlsDatabase* self,
      GAsyncResult* result,
      GError** error) -> GTlsCertificate*
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
          return unwrap_copy (obj->lookup_certificate_for_handle_finish_vfunc (
              Glib::wrap (result, true)));
        }
        catch (Glib::Error& errormm)
        {
          errormm.propagate (error);
          using RType = GTlsCertificate*;
          return RType ();
        }
        catch (...)
        {
          Glib::exception_handlers_invoke ();
        }
      }
    }

    const BaseClassType* const base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (self)));

    if (base && base->lookup_certificate_for_handle_finish)
      return (
          *base->lookup_certificate_for_handle_finish) (self, result, error);

    using RType = GTlsCertificate*;
    return RType ();
  }

  auto
  TlsDatabase_Class::lookup_certificate_issuer_vfunc_callback (
      GTlsDatabase* self,
      GTlsCertificate* certificate,
      GTlsInteraction* interaction,
      GTlsDatabaseLookupFlags flags,
      GCancellable* cancellable,
      GError** error) -> GTlsCertificate*
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
          return unwrap_copy (obj->lookup_certificate_issuer_vfunc (
              Glib::wrap (certificate, true),
              Glib::wrap (interaction, true),
              Glib::wrap (cancellable),
              static_cast<LookupFlags> (flags)));
        }
        catch (Glib::Error& errormm)
        {
          errormm.propagate (error);
          using RType = GTlsCertificate*;
          return RType ();
        }
        catch (...)
        {
          Glib::exception_handlers_invoke ();
        }
      }
    }

    const BaseClassType* const base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (self)));

    if (base && base->lookup_certificate_issuer)
      return (*base->lookup_certificate_issuer) (self,
                                                 certificate,
                                                 interaction,
                                                 flags,
                                                 cancellable,
                                                 error);

    using RType = GTlsCertificate*;
    return RType ();
  }

  auto
  TlsDatabase_Class::lookup_certificate_issuer_async_vfunc_callback (
      GTlsDatabase* self,
      GTlsCertificate* certificate,
      GTlsInteraction* interaction,
      GTlsDatabaseLookupFlags flags,
      GCancellable* cancellable,
      const GAsyncReadyCallback callback,
      const gpointer user_data) -> void
  {
    const auto slot = static_cast<SlotAsyncReady*> (user_data);

    const auto obj_base =
        Glib::ObjectBase::_get_current_wrapper ((GObject*) self);

    if (obj_base && obj_base->is_derived_ ())
    {
      const auto obj = dynamic_cast<CppObjectType* const> (obj_base);
      if (obj)
      {
        try
        {
          obj->lookup_certificate_issuer_async_vfunc (
              Glib::wrap (certificate, true),
              Glib::wrap (interaction, true),
              *slot,
              Glib::wrap (cancellable),
              static_cast<LookupFlags> (flags));
          return;
        }
        catch (...)
        {
          Glib::exception_handlers_invoke ();
        }
      }
    }

    const BaseClassType* const base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (self)));

    if (base && base->lookup_certificate_issuer_async)
      (*base->lookup_certificate_issuer_async) (self,
                                                certificate,
                                                interaction,
                                                flags,
                                                cancellable,
                                                callback,
                                                user_data);
  }

  auto
  TlsDatabase_Class::lookup_certificate_issuer_finish_vfunc_callback (
      GTlsDatabase* self,
      GAsyncResult* result,
      GError** error) -> GTlsCertificate*
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
          return unwrap_copy (obj->lookup_certificate_issuer_finish_vfunc (
              Glib::wrap (result, true)));
        }
        catch (Glib::Error& errormm)
        {
          errormm.propagate (error);
          using RType = GTlsCertificate*;
          return RType ();
        }
        catch (...)
        {
          Glib::exception_handlers_invoke ();
        }
      }
    }

    const BaseClassType* const base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (self)));

    if (base && base->lookup_certificate_issuer_finish)
      return (*base->lookup_certificate_issuer_finish) (self, result, error);

    using RType = GTlsCertificate*;
    return RType ();
  }

  auto
  TlsDatabase_Class::lookup_certificates_issued_by_vfunc_callback (
      GTlsDatabase* self,
      GByteArray* issuer_raw_dn,
      GTlsInteraction* interaction,
      GTlsDatabaseLookupFlags flags,
      GCancellable* cancellable,
      GError** error) -> GList*
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
          return g_list_copy_deep (
              Glib::ListHandler<Glib::RefPtr<TlsCertificate>>::vector_to_list (
                  obj->lookup_certificates_issued_by_vfunc (
                      Glib::wrap (issuer_raw_dn, true),
                      Glib::wrap (interaction, true),
                      Glib::wrap (cancellable),
                      static_cast<LookupFlags> (flags)))
                  .data (),
              list_copy_ref,
              nullptr);
        }
        catch (Glib::Error& errormm)
        {
          errormm.propagate (error);
          using RType = GList*;
          return RType ();
        }
        catch (...)
        {
          Glib::exception_handlers_invoke ();
        }
      }
    }

    const BaseClassType* const base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (self)));

    if (base && base->lookup_certificates_issued_by)
      return (*base->lookup_certificates_issued_by) (self,
                                                     issuer_raw_dn,
                                                     interaction,
                                                     flags,
                                                     cancellable,
                                                     error);

    using RType = GList*;
    return RType ();
  }

  auto
  TlsDatabase_Class::lookup_certificates_issued_by_async_vfunc_callback (
      GTlsDatabase* self,
      GByteArray* issuer_raw_dn,
      GTlsInteraction* interaction,
      GTlsDatabaseLookupFlags flags,
      GCancellable* cancellable,
      const GAsyncReadyCallback callback,
      const gpointer user_data) -> void
  {
    const auto slot = static_cast<SlotAsyncReady*> (user_data);

    const auto obj_base =
        Glib::ObjectBase::_get_current_wrapper ((GObject*) self);

    if (obj_base && obj_base->is_derived_ ())
    {
      const auto obj = dynamic_cast<CppObjectType* const> (obj_base);
      if (obj)
      {
        try
        {
          obj->lookup_certificates_issued_by_async_vfunc (
              Glib::wrap (issuer_raw_dn, true),
              Glib::wrap (interaction, true),
              *slot,
              Glib::wrap (cancellable),
              static_cast<LookupFlags> (flags));
          return;
        }
        catch (...)
        {
          Glib::exception_handlers_invoke ();
        }
      }
    }

    const BaseClassType* const base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (self)));

    if (base && base->lookup_certificates_issued_by_async)
      (*base->lookup_certificates_issued_by_async) (self,
                                                    issuer_raw_dn,
                                                    interaction,
                                                    flags,
                                                    cancellable,
                                                    callback,
                                                    user_data);
  }

  auto
  TlsDatabase_Class::lookup_certificates_issued_by_finish_vfunc_callback (
      GTlsDatabase* self,
      GAsyncResult* result,
      GError** error) -> GList*
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
          return g_list_copy_deep (
              Glib::ListHandler<Glib::RefPtr<TlsCertificate>>::vector_to_list (
                  obj->lookup_certificates_issued_by_finish_vfunc (
                      Glib::wrap (result, true)))
                  .data (),
              list_copy_ref,
              nullptr);
        }
        catch (Glib::Error& errormm)
        {
          errormm.propagate (error);
          using RType = GList*;
          return RType ();
        }
        catch (...)
        {
          Glib::exception_handlers_invoke ();
        }
      }
    }

    const BaseClassType* const base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (self)));

    if (base && base->lookup_certificates_issued_by_finish)
      return (
          *base->lookup_certificates_issued_by_finish) (self, result, error);

    using RType = GList*;
    return RType ();
  }

  auto
  TlsDatabase_Class::wrap_new (GObject* object) -> Glib::ObjectBase*
  {
    return new TlsDatabase ((GTlsDatabase*) object);
  }

  auto
  TlsDatabase::gobj_copy () -> GTlsDatabase*
  {
    reference ();
    return gobj ();
  }

  TlsDatabase::TlsDatabase (const Glib::ConstructParams& construct_params)
    : Object (construct_params)
  {
  }

  TlsDatabase::TlsDatabase (GTlsDatabase* castitem)
    : Object ((GObject*) castitem)
  {
  }

  TlsDatabase::TlsDatabase (TlsDatabase&& src) noexcept
    : Object (std::move (src))
  {
  }

  auto
  TlsDatabase::operator= (TlsDatabase&& src) noexcept -> TlsDatabase&
  {
    Object::operator= (std::move (src));
    return *this;
  }

  TlsDatabase::~TlsDatabase () noexcept = default;

  TlsDatabase::CppClassType TlsDatabase::tlsdatabase_class_;

  auto
  TlsDatabase::get_type () -> GType
  {
    return tlsdatabase_class_.init ().get_type ();
  }

  auto
  TlsDatabase::get_base_type () -> GType
  {
    return g_tls_database_get_type ();
  }

  TlsDatabase::TlsDatabase ()
    : ObjectBase (nullptr),
      Object (Glib::ConstructParams (tlsdatabase_class_.init ()))
  {
  }

  auto
  TlsDatabase::verify_chain (
      const Glib::RefPtr<TlsCertificate>& chain,
      const Glib::ustring& purpose,
      const Glib::RefPtr<const SocketConnectable>& identity,
      const Glib::RefPtr<TlsInteraction>& interaction,
      const Glib::RefPtr<Cancellable>& cancellable,
      VerifyFlags flags) const -> TlsCertificateFlags
  {
    GError* gerror = nullptr;
    const auto retvalue =
        static_cast<TlsCertificateFlags> (g_tls_database_verify_chain (
            const_cast<GTlsDatabase*> (gobj ()),
            Glib::unwrap (chain),
            purpose.c_str (),
            const_cast<GSocketConnectable*> (Glib::unwrap (identity)),
            Glib::unwrap (interaction),
            static_cast<GTlsDatabaseVerifyFlags> (flags),
            Glib::unwrap (cancellable),
            &gerror));
    if (gerror)
      Glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  TlsDatabase::verify_chain (
      const Glib::RefPtr<TlsCertificate>& chain,
      const Glib::ustring& purpose,
      const Glib::RefPtr<const SocketConnectable>& identity,
      const Glib::RefPtr<TlsInteraction>& interaction,
      VerifyFlags flags) const -> TlsCertificateFlags
  {
    GError* gerror = nullptr;
    const auto retvalue =
        static_cast<TlsCertificateFlags> (g_tls_database_verify_chain (
            const_cast<GTlsDatabase*> (gobj ()),
            Glib::unwrap (chain),
            purpose.c_str (),
            const_cast<GSocketConnectable*> (Glib::unwrap (identity)),
            Glib::unwrap (interaction),
            static_cast<GTlsDatabaseVerifyFlags> (flags),
            nullptr,
            &gerror));
    if (gerror)
      Glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  TlsDatabase::verify_chain (
      const Glib::RefPtr<TlsCertificate>& chain,
      const Glib::ustring& purpose,
      const Glib::RefPtr<const SocketConnectable>& identity,
      const Glib::RefPtr<Cancellable>& cancellable,
      VerifyFlags flags) const -> TlsCertificateFlags
  {
    GError* gerror = nullptr;
    const auto retvalue =
        static_cast<TlsCertificateFlags> (g_tls_database_verify_chain (
            const_cast<GTlsDatabase*> (gobj ()),
            Glib::unwrap (chain),
            purpose.c_str (),
            const_cast<GSocketConnectable*> (Glib::unwrap (identity)),
            nullptr,
            static_cast<GTlsDatabaseVerifyFlags> (flags),
            Glib::unwrap (cancellable),
            &gerror));
    if (gerror)
      Glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  TlsDatabase::verify_chain (
      const Glib::RefPtr<TlsCertificate>& chain,
      const Glib::ustring& purpose,
      const Glib::RefPtr<const SocketConnectable>& identity,
      VerifyFlags flags) const -> TlsCertificateFlags
  {
    GError* gerror = nullptr;
    const auto retvalue =
        static_cast<TlsCertificateFlags> (g_tls_database_verify_chain (
            const_cast<GTlsDatabase*> (gobj ()),
            Glib::unwrap (chain),
            purpose.c_str (),
            const_cast<GSocketConnectable*> (Glib::unwrap (identity)),
            nullptr,
            static_cast<GTlsDatabaseVerifyFlags> (flags),
            nullptr,
            &gerror));
    if (gerror)
      Glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  TlsDatabase::verify_chain (const Glib::RefPtr<TlsCertificate>& chain,
                             const Glib::ustring& purpose,
                             const Glib::RefPtr<TlsInteraction>& interaction,
                             const Glib::RefPtr<Cancellable>& cancellable,
                             VerifyFlags flags) const -> TlsCertificateFlags
  {
    GError* gerror = nullptr;
    const auto retvalue =
        static_cast<TlsCertificateFlags> (g_tls_database_verify_chain (
            const_cast<GTlsDatabase*> (gobj ()),
            Glib::unwrap (chain),
            purpose.c_str (),
            nullptr,
            Glib::unwrap (interaction),
            static_cast<GTlsDatabaseVerifyFlags> (flags),
            Glib::unwrap (cancellable),
            &gerror));
    if (gerror)
      Glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  TlsDatabase::verify_chain (const Glib::RefPtr<TlsCertificate>& chain,
                             const Glib::ustring& purpose,
                             const Glib::RefPtr<TlsInteraction>& interaction,
                             VerifyFlags flags) const -> TlsCertificateFlags
  {
    GError* gerror = nullptr;
    const auto retvalue =
        static_cast<TlsCertificateFlags> (g_tls_database_verify_chain (
            const_cast<GTlsDatabase*> (gobj ()),
            Glib::unwrap (chain),
            purpose.c_str (),
            nullptr,
            Glib::unwrap (interaction),
            static_cast<GTlsDatabaseVerifyFlags> (flags),
            nullptr,
            &gerror));
    if (gerror)
      Glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  TlsDatabase::verify_chain (const Glib::RefPtr<TlsCertificate>& chain,
                             const Glib::ustring& purpose,
                             const Glib::RefPtr<Cancellable>& cancellable,
                             VerifyFlags flags) const -> TlsCertificateFlags
  {
    GError* gerror = nullptr;
    const auto retvalue =
        static_cast<TlsCertificateFlags> (g_tls_database_verify_chain (
            const_cast<GTlsDatabase*> (gobj ()),
            Glib::unwrap (chain),
            purpose.c_str (),
            nullptr,
            nullptr,
            static_cast<GTlsDatabaseVerifyFlags> (flags),
            Glib::unwrap (cancellable),
            &gerror));
    if (gerror)
      Glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  TlsDatabase::verify_chain (const Glib::RefPtr<TlsCertificate>& chain,
                             const Glib::ustring& purpose,
                             VerifyFlags flags) const -> TlsCertificateFlags
  {
    GError* gerror = nullptr;
    const auto retvalue =
        static_cast<TlsCertificateFlags> (g_tls_database_verify_chain (
            const_cast<GTlsDatabase*> (gobj ()),
            Glib::unwrap (chain),
            purpose.c_str (),
            nullptr,
            nullptr,
            static_cast<GTlsDatabaseVerifyFlags> (flags),
            nullptr,
            &gerror));
    if (gerror)
      Glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  TlsDatabase::verify_chain_async (
      const Glib::RefPtr<TlsCertificate>& chain,
      const Glib::ustring& purpose,
      const Glib::RefPtr<const SocketConnectable>& identity,
      const Glib::RefPtr<TlsInteraction>& interaction,
      const SlotAsyncReady& slot,
      const Glib::RefPtr<Cancellable>& cancellable,
      VerifyFlags flags) const -> void
  {
    const auto slot_copy = new SlotAsyncReady (slot);

    g_tls_database_verify_chain_async (
        const_cast<GTlsDatabase*> (gobj ()),
        Glib::unwrap (chain),
        purpose.c_str (),
        const_cast<GSocketConnectable*> (Glib::unwrap (identity)),
        Glib::unwrap (interaction),
        static_cast<GTlsDatabaseVerifyFlags> (flags),
        Glib::unwrap (cancellable),
        &SignalProxy_async_callback,
        slot_copy);
  }

  auto
  TlsDatabase::verify_chain_async (
      const Glib::RefPtr<TlsCertificate>& chain,
      const Glib::ustring& purpose,
      const Glib::RefPtr<const SocketConnectable>& identity,
      const Glib::RefPtr<TlsInteraction>& interaction,
      const SlotAsyncReady& slot,
      VerifyFlags flags) const -> void
  {
    const auto slot_copy = new SlotAsyncReady (slot);

    g_tls_database_verify_chain_async (
        const_cast<GTlsDatabase*> (gobj ()),
        Glib::unwrap (chain),
        purpose.c_str (),
        const_cast<GSocketConnectable*> (Glib::unwrap (identity)),
        Glib::unwrap (interaction),
        static_cast<GTlsDatabaseVerifyFlags> (flags),
        nullptr,
        &SignalProxy_async_callback,
        slot_copy);
  }

  auto
  TlsDatabase::verify_chain_async (
      const Glib::RefPtr<TlsCertificate>& chain,
      const Glib::ustring& purpose,
      const Glib::RefPtr<const SocketConnectable>& identity,
      const SlotAsyncReady& slot,
      const Glib::RefPtr<Cancellable>& cancellable,
      VerifyFlags flags) const -> void
  {
    const auto slot_copy = new SlotAsyncReady (slot);

    g_tls_database_verify_chain_async (
        const_cast<GTlsDatabase*> (gobj ()),
        Glib::unwrap (chain),
        purpose.c_str (),
        const_cast<GSocketConnectable*> (Glib::unwrap (identity)),
        nullptr,
        static_cast<GTlsDatabaseVerifyFlags> (flags),
        Glib::unwrap (cancellable),
        &SignalProxy_async_callback,
        slot_copy);
  }

  auto
  TlsDatabase::verify_chain_async (
      const Glib::RefPtr<TlsCertificate>& chain,
      const Glib::ustring& purpose,
      const Glib::RefPtr<const SocketConnectable>& identity,
      const SlotAsyncReady& slot,
      VerifyFlags flags) const -> void
  {
    const auto slot_copy = new SlotAsyncReady (slot);

    g_tls_database_verify_chain_async (
        const_cast<GTlsDatabase*> (gobj ()),
        Glib::unwrap (chain),
        purpose.c_str (),
        const_cast<GSocketConnectable*> (Glib::unwrap (identity)),
        nullptr,
        static_cast<GTlsDatabaseVerifyFlags> (flags),
        nullptr,
        &SignalProxy_async_callback,
        slot_copy);
  }

  auto
  TlsDatabase::verify_chain_async (
      const Glib::RefPtr<TlsCertificate>& chain,
      const Glib::ustring& purpose,
      const Glib::RefPtr<TlsInteraction>& interaction,
      const SlotAsyncReady& slot,
      const Glib::RefPtr<Cancellable>& cancellable,
      VerifyFlags flags) const -> void
  {
    const auto slot_copy = new SlotAsyncReady (slot);

    g_tls_database_verify_chain_async (
        const_cast<GTlsDatabase*> (gobj ()),
        Glib::unwrap (chain),
        purpose.c_str (),
        nullptr,
        Glib::unwrap (interaction),
        static_cast<GTlsDatabaseVerifyFlags> (flags),
        Glib::unwrap (cancellable),
        &SignalProxy_async_callback,
        slot_copy);
  }

  auto
  TlsDatabase::verify_chain_async (
      const Glib::RefPtr<TlsCertificate>& chain,
      const Glib::ustring& purpose,
      const Glib::RefPtr<TlsInteraction>& interaction,
      const SlotAsyncReady& slot,
      VerifyFlags flags) const -> void
  {
    const auto slot_copy = new SlotAsyncReady (slot);

    g_tls_database_verify_chain_async (
        const_cast<GTlsDatabase*> (gobj ()),
        Glib::unwrap (chain),
        purpose.c_str (),
        nullptr,
        Glib::unwrap (interaction),
        static_cast<GTlsDatabaseVerifyFlags> (flags),
        nullptr,
        &SignalProxy_async_callback,
        slot_copy);
  }

  auto
  TlsDatabase::verify_chain_async (const Glib::RefPtr<TlsCertificate>& chain,
                                   const Glib::ustring& purpose,
                                   const SlotAsyncReady& slot,
                                   const Glib::RefPtr<Cancellable>& cancellable,
                                   VerifyFlags flags) const -> void
  {
    const auto slot_copy = new SlotAsyncReady (slot);

    g_tls_database_verify_chain_async (
        const_cast<GTlsDatabase*> (gobj ()),
        Glib::unwrap (chain),
        purpose.c_str (),
        nullptr,
        nullptr,
        static_cast<GTlsDatabaseVerifyFlags> (flags),
        Glib::unwrap (cancellable),
        &SignalProxy_async_callback,
        slot_copy);
  }

  auto
  TlsDatabase::verify_chain_async (const Glib::RefPtr<TlsCertificate>& chain,
                                   const Glib::ustring& purpose,
                                   const SlotAsyncReady& slot,
                                   VerifyFlags flags) const -> void
  {
    const auto slot_copy = new SlotAsyncReady (slot);

    g_tls_database_verify_chain_async (
        const_cast<GTlsDatabase*> (gobj ()),
        Glib::unwrap (chain),
        purpose.c_str (),
        nullptr,
        nullptr,
        static_cast<GTlsDatabaseVerifyFlags> (flags),
        nullptr,
        &SignalProxy_async_callback,
        slot_copy);
  }

  auto
  TlsDatabase::verify_chain_finish (const Glib::RefPtr<AsyncResult>& result) -> TlsCertificateFlags
  {
    GError* gerror = nullptr;
    const auto retvalue = static_cast<TlsCertificateFlags> (
        g_tls_database_verify_chain_finish (gobj (),
                                            Glib::unwrap (result),
                                            &gerror));
    if (gerror)
      Glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  TlsDatabase::lookup_certificate_issuer (
      const Glib::RefPtr<const TlsCertificate>& certificate,
      const Glib::RefPtr<TlsInteraction>& interaction,
      const Glib::RefPtr<Cancellable>& cancellable,
      LookupFlags flags) -> Glib::RefPtr<TlsCertificate>
  {
    GError* gerror = nullptr;
    auto retvalue = Glib::wrap (g_tls_database_lookup_certificate_issuer (
        gobj (),
        const_cast<GTlsCertificate*> (Glib::unwrap (certificate)),
        Glib::unwrap (interaction),
        static_cast<GTlsDatabaseLookupFlags> (flags),
        Glib::unwrap (cancellable),
        &gerror));
    if (gerror)
      Glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  TlsDatabase::lookup_certificate_issuer (
      const Glib::RefPtr<const TlsCertificate>& certificate,
      const Glib::RefPtr<TlsInteraction>& interaction,
      LookupFlags flags) -> Glib::RefPtr<TlsCertificate>
  {
    GError* gerror = nullptr;
    auto retvalue = Glib::wrap (g_tls_database_lookup_certificate_issuer (
        gobj (),
        const_cast<GTlsCertificate*> (Glib::unwrap (certificate)),
        Glib::unwrap (interaction),
        static_cast<GTlsDatabaseLookupFlags> (flags),
        nullptr,
        &gerror));
    if (gerror)
      Glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  TlsDatabase::lookup_certificate_issuer (
      const Glib::RefPtr<const TlsCertificate>& certificate,
      const Glib::RefPtr<Cancellable>& cancellable,
      LookupFlags flags) -> Glib::RefPtr<TlsCertificate>
  {
    GError* gerror = nullptr;
    auto retvalue = Glib::wrap (g_tls_database_lookup_certificate_issuer (
        gobj (),
        const_cast<GTlsCertificate*> (Glib::unwrap (certificate)),
        nullptr,
        static_cast<GTlsDatabaseLookupFlags> (flags),
        Glib::unwrap (cancellable),
        &gerror));
    if (gerror)
      Glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  TlsDatabase::lookup_certificate_issuer (
      const Glib::RefPtr<const TlsCertificate>& certificate,
      LookupFlags flags) -> Glib::RefPtr<TlsCertificate>
  {
    GError* gerror = nullptr;
    auto retvalue = Glib::wrap (g_tls_database_lookup_certificate_issuer (
        gobj (),
        const_cast<GTlsCertificate*> (Glib::unwrap (certificate)),
        nullptr,
        static_cast<GTlsDatabaseLookupFlags> (flags),
        nullptr,
        &gerror));
    if (gerror)
      Glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  TlsDatabase::lookup_certificate_issuer (
      const Glib::RefPtr<const TlsCertificate>& certificate,
      const Glib::RefPtr<TlsInteraction>& interaction,
      const Glib::RefPtr<Cancellable>& cancellable,
      const LookupFlags flags) const -> Glib::RefPtr<const TlsCertificate>
  {
    return const_cast<TlsDatabase*> (this)->lookup_certificate_issuer (
        certificate,
        interaction,
        cancellable,
        flags);
  }

  auto
  TlsDatabase::lookup_certificate_issuer (
      const Glib::RefPtr<const TlsCertificate>& certificate,
      const Glib::RefPtr<TlsInteraction>& interaction,
      const LookupFlags flags) const -> Glib::RefPtr<const TlsCertificate>
  {
    return const_cast<TlsDatabase*> (this)->lookup_certificate_issuer (
        certificate,
        interaction,
        flags);
  }

  auto
  TlsDatabase::lookup_certificate_issuer (
      const Glib::RefPtr<const TlsCertificate>& certificate,
      const Glib::RefPtr<Cancellable>& cancellable,
      const LookupFlags flags) const -> Glib::RefPtr<const TlsCertificate>
  {
    return const_cast<TlsDatabase*> (this)->lookup_certificate_issuer (
        certificate,
        cancellable,
        flags);
  }

  auto
  TlsDatabase::lookup_certificate_issuer (
      const Glib::RefPtr<const TlsCertificate>& certificate,
      const LookupFlags flags) const -> Glib::RefPtr<const TlsCertificate>
  {
    return const_cast<TlsDatabase*> (this)->lookup_certificate_issuer (
        certificate,
        flags);
  }

  auto
  TlsDatabase::lookup_certificate_issuer_async (
      const Glib::RefPtr<const TlsCertificate>& certificate,
      const Glib::RefPtr<TlsInteraction>& interaction,
      const SlotAsyncReady& slot,
      const Glib::RefPtr<Cancellable>& cancellable,
      LookupFlags flags) -> void
  {
    const auto slot_copy = new SlotAsyncReady (slot);

    g_tls_database_lookup_certificate_issuer_async (
        gobj (),
        const_cast<GTlsCertificate*> (Glib::unwrap (certificate)),
        Glib::unwrap (interaction),
        static_cast<GTlsDatabaseLookupFlags> (flags),
        Glib::unwrap (cancellable),
        &SignalProxy_async_callback,
        slot_copy);
  }

  auto
  TlsDatabase::lookup_certificate_issuer_async (
      const Glib::RefPtr<const TlsCertificate>& certificate,
      const Glib::RefPtr<TlsInteraction>& interaction,
      const SlotAsyncReady& slot,
      LookupFlags flags) -> void
  {
    const auto slot_copy = new SlotAsyncReady (slot);

    g_tls_database_lookup_certificate_issuer_async (
        gobj (),
        const_cast<GTlsCertificate*> (Glib::unwrap (certificate)),
        Glib::unwrap (interaction),
        static_cast<GTlsDatabaseLookupFlags> (flags),
        nullptr,
        &SignalProxy_async_callback,
        slot_copy);
  }

  auto
  TlsDatabase::lookup_certificate_issuer_async (
      const Glib::RefPtr<const TlsCertificate>& certificate,
      const SlotAsyncReady& slot,
      const Glib::RefPtr<Cancellable>& cancellable,
      LookupFlags flags) -> void
  {
    const auto slot_copy = new SlotAsyncReady (slot);

    g_tls_database_lookup_certificate_issuer_async (
        gobj (),
        const_cast<GTlsCertificate*> (Glib::unwrap (certificate)),
        nullptr,
        static_cast<GTlsDatabaseLookupFlags> (flags),
        Glib::unwrap (cancellable),
        &SignalProxy_async_callback,
        slot_copy);
  }

  auto
  TlsDatabase::lookup_certificate_issuer_async (
      const Glib::RefPtr<const TlsCertificate>& certificate,
      const SlotAsyncReady& slot,
      LookupFlags flags) -> void
  {
    const auto slot_copy = new SlotAsyncReady (slot);

    g_tls_database_lookup_certificate_issuer_async (
        gobj (),
        const_cast<GTlsCertificate*> (Glib::unwrap (certificate)),
        nullptr,
        static_cast<GTlsDatabaseLookupFlags> (flags),
        nullptr,
        &SignalProxy_async_callback,
        slot_copy);
  }

  auto
  TlsDatabase::lookup_certificate_issuer_finish (
      const Glib::RefPtr<AsyncResult>& result) -> Glib::RefPtr<TlsCertificate>
  {
    GError* gerror = nullptr;
    auto retvalue = Glib::wrap (
        g_tls_database_lookup_certificate_issuer_finish (gobj (),
                                                         Glib::unwrap (result),
                                                         &gerror));
    if (gerror)
      Glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  TlsDatabase::lookup_certificates_issued_by (
      const Glib::RefPtr<Glib::ByteArray>& issuer_raw_dn,
      const Glib::RefPtr<TlsInteraction>& interaction,
      const Glib::RefPtr<Cancellable>& cancellable,
      LookupFlags flags) -> std::vector<Glib::RefPtr<TlsCertificate>>
  {
    GError* gerror = nullptr;
    auto retvalue =
        Glib::ListHandler<Glib::RefPtr<TlsCertificate>>::list_to_vector (
            g_tls_database_lookup_certificates_issued_by (
                gobj (),
                unwrap (issuer_raw_dn),
                Glib::unwrap (interaction),
                static_cast<GTlsDatabaseLookupFlags> (flags),
                Glib::unwrap (cancellable),
                &gerror),
            Glib::OWNERSHIP_DEEP);
    if (gerror)
      Glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  TlsDatabase::lookup_certificates_issued_by (
      const Glib::RefPtr<Glib::ByteArray>& issuer_raw_dn,
      const Glib::RefPtr<TlsInteraction>& interaction,
      LookupFlags flags) -> std::vector<Glib::RefPtr<TlsCertificate>>
  {
    GError* gerror = nullptr;
    auto retvalue =
        Glib::ListHandler<Glib::RefPtr<TlsCertificate>>::list_to_vector (
            g_tls_database_lookup_certificates_issued_by (
                gobj (),
                unwrap (issuer_raw_dn),
                Glib::unwrap (interaction),
                static_cast<GTlsDatabaseLookupFlags> (flags),
                nullptr,
                &gerror),
            Glib::OWNERSHIP_DEEP);
    if (gerror)
      Glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  TlsDatabase::lookup_certificates_issued_by (
      const Glib::RefPtr<Glib::ByteArray>& issuer_raw_dn,
      const Glib::RefPtr<Cancellable>& cancellable,
      LookupFlags flags) -> std::vector<Glib::RefPtr<TlsCertificate>>
  {
    GError* gerror = nullptr;
    auto retvalue =
        Glib::ListHandler<Glib::RefPtr<TlsCertificate>>::list_to_vector (
            g_tls_database_lookup_certificates_issued_by (
                gobj (),
                unwrap (issuer_raw_dn),
                nullptr,
                static_cast<GTlsDatabaseLookupFlags> (flags),
                Glib::unwrap (cancellable),
                &gerror),
            Glib::OWNERSHIP_DEEP);
    if (gerror)
      Glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  TlsDatabase::lookup_certificates_issued_by (
      const Glib::RefPtr<Glib::ByteArray>& issuer_raw_dn,
      LookupFlags flags) -> std::vector<Glib::RefPtr<TlsCertificate>>
  {
    GError* gerror = nullptr;
    auto retvalue =
        Glib::ListHandler<Glib::RefPtr<TlsCertificate>>::list_to_vector (
            g_tls_database_lookup_certificates_issued_by (
                gobj (),
                unwrap (issuer_raw_dn),
                nullptr,
                static_cast<GTlsDatabaseLookupFlags> (flags),
                nullptr,
                &gerror),
            Glib::OWNERSHIP_DEEP);
    if (gerror)
      Glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  TlsDatabase::lookup_certificates_issued_by (
      const Glib::RefPtr<Glib::ByteArray>& issuer_raw_dn,
      const Glib::RefPtr<TlsInteraction>& interaction,
      const Glib::RefPtr<Cancellable>& cancellable,
      LookupFlags flags) const -> std::vector<Glib::RefPtr<const TlsCertificate>>
  {
    GError* gerror = nullptr;
    auto retvalue =
        Glib::ListHandler<Glib::RefPtr<const TlsCertificate>>::list_to_vector (
            g_tls_database_lookup_certificates_issued_by (
                const_cast<GTlsDatabase*> (gobj ()),
                unwrap (issuer_raw_dn),
                Glib::unwrap (interaction),
                static_cast<GTlsDatabaseLookupFlags> (flags),
                Glib::unwrap (cancellable),
                &gerror),
            Glib::OWNERSHIP_DEEP);
    if (gerror)
      Glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  TlsDatabase::lookup_certificates_issued_by (
      const Glib::RefPtr<Glib::ByteArray>& issuer_raw_dn,
      const Glib::RefPtr<TlsInteraction>& interaction,
      LookupFlags flags) const -> std::vector<Glib::RefPtr<const TlsCertificate>>
  {
    GError* gerror = nullptr;
    auto retvalue =
        Glib::ListHandler<Glib::RefPtr<const TlsCertificate>>::list_to_vector (
            g_tls_database_lookup_certificates_issued_by (
                const_cast<GTlsDatabase*> (gobj ()),
                unwrap (issuer_raw_dn),
                Glib::unwrap (interaction),
                static_cast<GTlsDatabaseLookupFlags> (flags),
                nullptr,
                &gerror),
            Glib::OWNERSHIP_DEEP);
    if (gerror)
      Glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  TlsDatabase::lookup_certificates_issued_by (
      const Glib::RefPtr<Glib::ByteArray>& issuer_raw_dn,
      const Glib::RefPtr<Cancellable>& cancellable,
      LookupFlags flags) const -> std::vector<Glib::RefPtr<const TlsCertificate>>
  {
    GError* gerror = nullptr;
    auto retvalue =
        Glib::ListHandler<Glib::RefPtr<const TlsCertificate>>::list_to_vector (
            g_tls_database_lookup_certificates_issued_by (
                const_cast<GTlsDatabase*> (gobj ()),
                unwrap (issuer_raw_dn),
                nullptr,
                static_cast<GTlsDatabaseLookupFlags> (flags),
                Glib::unwrap (cancellable),
                &gerror),
            Glib::OWNERSHIP_DEEP);
    if (gerror)
      Glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  TlsDatabase::lookup_certificates_issued_by (
      const Glib::RefPtr<Glib::ByteArray>& issuer_raw_dn,
      LookupFlags flags) const -> std::vector<Glib::RefPtr<const TlsCertificate>>
  {
    GError* gerror = nullptr;
    auto retvalue =
        Glib::ListHandler<Glib::RefPtr<const TlsCertificate>>::list_to_vector (
            g_tls_database_lookup_certificates_issued_by (
                const_cast<GTlsDatabase*> (gobj ()),
                unwrap (issuer_raw_dn),
                nullptr,
                static_cast<GTlsDatabaseLookupFlags> (flags),
                nullptr,
                &gerror),
            Glib::OWNERSHIP_DEEP);
    if (gerror)
      Glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  TlsDatabase::lookup_certificates_issued_by_async (
      const Glib::RefPtr<Glib::ByteArray>& issuer_raw_dn,
      const Glib::RefPtr<TlsInteraction>& interaction,
      const SlotAsyncReady& slot,
      const Glib::RefPtr<Cancellable>& cancellable,
      LookupFlags flags) -> void
  {
    const auto slot_copy = new SlotAsyncReady (slot);

    g_tls_database_lookup_certificates_issued_by_async (
        gobj (),
        unwrap (issuer_raw_dn),
        Glib::unwrap (interaction),
        static_cast<GTlsDatabaseLookupFlags> (flags),
        Glib::unwrap (cancellable),
        &SignalProxy_async_callback,
        slot_copy);
  }

  auto
  TlsDatabase::lookup_certificates_issued_by_async (
      const Glib::RefPtr<Glib::ByteArray>& issuer_raw_dn,
      const Glib::RefPtr<TlsInteraction>& interaction,
      const SlotAsyncReady& slot,
      LookupFlags flags) -> void
  {
    const auto slot_copy = new SlotAsyncReady (slot);

    g_tls_database_lookup_certificates_issued_by_async (
        gobj (),
        unwrap (issuer_raw_dn),
        Glib::unwrap (interaction),
        static_cast<GTlsDatabaseLookupFlags> (flags),
        nullptr,
        &SignalProxy_async_callback,
        slot_copy);
  }

  auto
  TlsDatabase::lookup_certificates_issued_by_async (
      const Glib::RefPtr<Glib::ByteArray>& issuer_raw_dn,
      const SlotAsyncReady& slot,
      const Glib::RefPtr<Cancellable>& cancellable,
      LookupFlags flags) -> void
  {
    const auto slot_copy = new SlotAsyncReady (slot);

    g_tls_database_lookup_certificates_issued_by_async (
        gobj (),
        unwrap (issuer_raw_dn),
        nullptr,
        static_cast<GTlsDatabaseLookupFlags> (flags),
        Glib::unwrap (cancellable),
        &SignalProxy_async_callback,
        slot_copy);
  }

  auto
  TlsDatabase::lookup_certificates_issued_by_async (
      const Glib::RefPtr<Glib::ByteArray>& issuer_raw_dn,
      const SlotAsyncReady& slot,
      LookupFlags flags) -> void
  {
    const auto slot_copy = new SlotAsyncReady (slot);

    g_tls_database_lookup_certificates_issued_by_async (
        gobj (),
        unwrap (issuer_raw_dn),
        nullptr,
        static_cast<GTlsDatabaseLookupFlags> (flags),
        nullptr,
        &SignalProxy_async_callback,
        slot_copy);
  }

  auto
  TlsDatabase::lookup_certificates_issued_by_finish (
      const Glib::RefPtr<AsyncResult>& result) -> std::vector<Glib::RefPtr<TlsCertificate>>
  {
    GError* gerror = nullptr;
    auto retvalue =
        Glib::ListHandler<Glib::RefPtr<TlsCertificate>>::list_to_vector (
            g_tls_database_lookup_certificates_issued_by_finish (
                gobj (),
                Glib::unwrap (result),
                &gerror),
            Glib::OWNERSHIP_DEEP);
    if (gerror)
      Glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  TlsDatabase::create_certificate_handle (
      const Glib::RefPtr<const TlsCertificate>& certificate) const -> Glib::ustring
  {
    return Glib::convert_return_gchar_ptr_to_ustring (
        g_tls_database_create_certificate_handle (
            const_cast<GTlsDatabase*> (gobj ()),
            const_cast<GTlsCertificate*> (Glib::unwrap (certificate))));
  }

  auto
  TlsDatabase::lookup_certificate_for_handle (
      const Glib::ustring& handle,
      const Glib::RefPtr<TlsInteraction>& interaction,
      const Glib::RefPtr<Cancellable>& cancellable,
      LookupFlags flags) -> Glib::RefPtr<TlsCertificate>
  {
    GError* gerror = nullptr;
    auto retvalue = Glib::wrap (g_tls_database_lookup_certificate_for_handle (
        gobj (),
        handle.c_str (),
        Glib::unwrap (interaction),
        static_cast<GTlsDatabaseLookupFlags> (flags),
        Glib::unwrap (cancellable),
        &gerror));
    if (gerror)
      Glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  TlsDatabase::lookup_certificate_for_handle (
      const Glib::ustring& handle,
      const Glib::RefPtr<TlsInteraction>& interaction,
      LookupFlags flags) -> Glib::RefPtr<TlsCertificate>
  {
    GError* gerror = nullptr;
    auto retvalue = Glib::wrap (g_tls_database_lookup_certificate_for_handle (
        gobj (),
        handle.c_str (),
        Glib::unwrap (interaction),
        static_cast<GTlsDatabaseLookupFlags> (flags),
        nullptr,
        &gerror));
    if (gerror)
      Glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  TlsDatabase::lookup_certificate_for_handle (
      const Glib::ustring& handle,
      const Glib::RefPtr<Cancellable>& cancellable,
      LookupFlags flags) -> Glib::RefPtr<TlsCertificate>
  {
    GError* gerror = nullptr;
    auto retvalue = Glib::wrap (g_tls_database_lookup_certificate_for_handle (
        gobj (),
        handle.c_str (),
        nullptr,
        static_cast<GTlsDatabaseLookupFlags> (flags),
        Glib::unwrap (cancellable),
        &gerror));
    if (gerror)
      Glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  TlsDatabase::lookup_certificate_for_handle (const Glib::ustring& handle,
                                              LookupFlags flags) -> Glib::RefPtr<TlsCertificate>
  {
    GError* gerror = nullptr;
    auto retvalue = Glib::wrap (g_tls_database_lookup_certificate_for_handle (
        gobj (),
        handle.c_str (),
        nullptr,
        static_cast<GTlsDatabaseLookupFlags> (flags),
        nullptr,
        &gerror));
    if (gerror)
      Glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  TlsDatabase::lookup_certificate_for_handle (
      const Glib::ustring& handle,
      const Glib::RefPtr<TlsInteraction>& interaction,
      const Glib::RefPtr<Cancellable>& cancellable,
      const LookupFlags flags) const -> Glib::RefPtr<const TlsCertificate>
  {
    return const_cast<TlsDatabase*> (this)->lookup_certificate_for_handle (
        handle,
        interaction,
        cancellable,
        flags);
  }

  auto
  TlsDatabase::lookup_certificate_for_handle (
      const Glib::ustring& handle,
      const Glib::RefPtr<TlsInteraction>& interaction,
      const LookupFlags flags) const -> Glib::RefPtr<const TlsCertificate>
  {
    return const_cast<TlsDatabase*> (this)->lookup_certificate_for_handle (
        handle,
        interaction,
        flags);
  }

  auto
  TlsDatabase::lookup_certificate_for_handle (
      const Glib::ustring& handle,
      const Glib::RefPtr<Cancellable>& cancellable,
      const LookupFlags flags) const -> Glib::RefPtr<const TlsCertificate>
  {
    return const_cast<TlsDatabase*> (this)->lookup_certificate_for_handle (
        handle,
        cancellable,
        flags);
  }

  auto
  TlsDatabase::lookup_certificate_for_handle (const Glib::ustring& handle,
                                              const LookupFlags flags) const -> Glib::RefPtr<const TlsCertificate>
  {
    return const_cast<TlsDatabase*> (this)->lookup_certificate_for_handle (
        handle,
        flags);
  }

  auto
  TlsDatabase::lookup_certificate_for_handle_async (
      const Glib::ustring& handle,
      const Glib::RefPtr<TlsInteraction>& interaction,
      const SlotAsyncReady& slot,
      const Glib::RefPtr<Cancellable>& cancellable,
      LookupFlags flags) -> void
  {
    const auto slot_copy = new SlotAsyncReady (slot);

    g_tls_database_lookup_certificate_for_handle_async (
        gobj (),
        handle.c_str (),
        Glib::unwrap (interaction),
        static_cast<GTlsDatabaseLookupFlags> (flags),
        Glib::unwrap (cancellable),
        &SignalProxy_async_callback,
        slot_copy);
  }

  auto
  TlsDatabase::lookup_certificate_for_handle_async (
      const Glib::ustring& handle,
      const Glib::RefPtr<TlsInteraction>& interaction,
      const SlotAsyncReady& slot,
      LookupFlags flags) -> void
  {
    const auto slot_copy = new SlotAsyncReady (slot);

    g_tls_database_lookup_certificate_for_handle_async (
        gobj (),
        handle.c_str (),
        Glib::unwrap (interaction),
        static_cast<GTlsDatabaseLookupFlags> (flags),
        nullptr,
        &SignalProxy_async_callback,
        slot_copy);
  }

  auto
  TlsDatabase::lookup_certificate_for_handle_async (
      const Glib::ustring& handle,
      const SlotAsyncReady& slot,
      const Glib::RefPtr<Cancellable>& cancellable,
      LookupFlags flags) -> void
  {
    const auto slot_copy = new SlotAsyncReady (slot);

    g_tls_database_lookup_certificate_for_handle_async (
        gobj (),
        handle.c_str (),
        nullptr,
        static_cast<GTlsDatabaseLookupFlags> (flags),
        Glib::unwrap (cancellable),
        &SignalProxy_async_callback,
        slot_copy);
  }

  auto
  TlsDatabase::lookup_certificate_for_handle_async (const Glib::ustring& handle,
                                                    const SlotAsyncReady& slot,
                                                    LookupFlags flags) -> void
  {
    const auto slot_copy = new SlotAsyncReady (slot);

    g_tls_database_lookup_certificate_for_handle_async (
        gobj (),
        handle.c_str (),
        nullptr,
        static_cast<GTlsDatabaseLookupFlags> (flags),
        nullptr,
        &SignalProxy_async_callback,
        slot_copy);
  }

  auto
  TlsDatabase::lookup_certificate_for_handle_finish (
      const Glib::RefPtr<AsyncResult>& result) -> Glib::RefPtr<TlsCertificate>
  {
    GError* gerror = nullptr;
    auto retvalue =
        Glib::wrap (g_tls_database_lookup_certificate_for_handle_finish (
            gobj (),
            Glib::unwrap (result),
            &gerror));
    if (gerror)
      Glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  TlsDatabase::verify_chain_vfunc (
      const Glib::RefPtr<TlsCertificate>& chain,
      const Glib::ustring& purpose,
      const Glib::RefPtr<const SocketConnectable>& identity,
      const Glib::RefPtr<TlsInteraction>& interaction,
      const Glib::RefPtr<Cancellable>& cancellable,
      VerifyFlags flags) const -> TlsCertificateFlags
  {
    const auto base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (gobject_)));

    if (base && base->verify_chain)
    {
      GError* gerror = nullptr;
      const TlsCertificateFlags retval (
          static_cast<TlsCertificateFlags> ((*base->verify_chain) (
              const_cast<GTlsDatabase*> (gobj ()),
              Glib::unwrap (chain),
              purpose.c_str (),
              const_cast<GSocketConnectable*> (Glib::unwrap (identity)),
              Glib::unwrap (interaction),
              static_cast<GTlsDatabaseVerifyFlags> (flags),
              Glib::unwrap (cancellable),
              &gerror)));
      if (gerror)
        Glib::Error::throw_exception (gerror);
      return retval;
    }

    using RType = TlsCertificateFlags;
    return RType ();
  }

  auto
  TlsDatabase::verify_chain_async_vfunc (
      const Glib::RefPtr<TlsCertificate>& chain,
      const Glib::ustring& purpose,
      const Glib::RefPtr<const SocketConnectable>& identity,
      const Glib::RefPtr<TlsInteraction>& interaction,
      const SlotAsyncReady& slot,
      const Glib::RefPtr<Cancellable>& cancellable,
      VerifyFlags flags) const -> void
  {
    const auto slot_copy = new SlotAsyncReady (slot);

    const auto base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (gobject_)));

    if (base && base->verify_chain_async)
    {
      (*base->verify_chain_async) (
          const_cast<GTlsDatabase*> (gobj ()),
          Glib::unwrap (chain),
          purpose.c_str (),
          const_cast<GSocketConnectable*> (Glib::unwrap (identity)),
          Glib::unwrap (interaction),
          static_cast<GTlsDatabaseVerifyFlags> (flags),
          Glib::unwrap (cancellable),
          &SignalProxy_async_callback,
          slot_copy);
    }
  }

  auto
  TlsDatabase::verify_chain_finish_vfunc (
      const Glib::RefPtr<AsyncResult>& result) -> TlsCertificateFlags
  {
    const auto base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (gobject_)));

    if (base && base->verify_chain_finish)
    {
      GError* gerror = nullptr;
      const TlsCertificateFlags retval (static_cast<TlsCertificateFlags> (
          (*base->verify_chain_finish) (gobj (),
                                        Glib::unwrap (result),
                                        &gerror)));
      if (gerror)
        Glib::Error::throw_exception (gerror);
      return retval;
    }

    using RType = TlsCertificateFlags;
    return RType ();
  }

  auto
  TlsDatabase::create_certificate_handle_vfunc (
      const Glib::RefPtr<const TlsCertificate>& certificate) const -> Glib::ustring
  {
    const auto base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (gobject_)));

    if (base && base->create_certificate_handle)
    {
      Glib::ustring retval (Glib::convert_return_gchar_ptr_to_ustring (
          (*base->create_certificate_handle) (
              const_cast<GTlsDatabase*> (gobj ()),
              const_cast<GTlsCertificate*> (Glib::unwrap (certificate)))));
      return retval;
    }

    using RType = Glib::ustring;
    return {};
  }

  auto
  TlsDatabase::lookup_certificate_for_handle_vfunc (
      const Glib::ustring& handle,
      const Glib::RefPtr<TlsInteraction>& interaction,
      const Glib::RefPtr<Cancellable>& cancellable,
      LookupFlags flags) -> Glib::RefPtr<TlsCertificate>
  {
    const auto base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (gobject_)));

    if (base && base->lookup_certificate_for_handle)
    {
      GError* gerror = nullptr;
      Glib::RefPtr<TlsCertificate> retval (
          Glib::wrap ((*base->lookup_certificate_for_handle) (
              gobj (),
              handle.c_str (),
              Glib::unwrap (interaction),
              static_cast<GTlsDatabaseLookupFlags> (flags),
              Glib::unwrap (cancellable),
              &gerror)));
      if (gerror)
        Glib::Error::throw_exception (gerror);
      return retval;
    }

    using RType = Glib::RefPtr<TlsCertificate>;
    return {};
  }

  auto
  TlsDatabase::lookup_certificate_for_handle_async_vfunc (
      const Glib::ustring& handle,
      const Glib::RefPtr<TlsInteraction>& interaction,
      const SlotAsyncReady& slot,
      const Glib::RefPtr<Cancellable>& cancellable,
      LookupFlags flags) -> void
  {
    const auto slot_copy = new SlotAsyncReady (slot);

    const auto base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (gobject_)));

    if (base && base->lookup_certificate_for_handle_async)
    {
      (*base->lookup_certificate_for_handle_async) (
          gobj (),
          handle.c_str (),
          Glib::unwrap (interaction),
          static_cast<GTlsDatabaseLookupFlags> (flags),
          Glib::unwrap (cancellable),
          &SignalProxy_async_callback,
          slot_copy);
    }
  }

  auto
  TlsDatabase::lookup_certificate_for_handle_finish_vfunc (
      const Glib::RefPtr<AsyncResult>& result) -> Glib::RefPtr<TlsCertificate>
  {
    const auto base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (gobject_)));

    if (base && base->lookup_certificate_for_handle_finish)
    {
      GError* gerror = nullptr;
      Glib::RefPtr<TlsCertificate> retval (Glib::wrap (
          (*base->lookup_certificate_for_handle_finish) (gobj (),
                                                         Glib::unwrap (result),
                                                         &gerror)));
      if (gerror)
        Glib::Error::throw_exception (gerror);
      return retval;
    }

    using RType = Glib::RefPtr<TlsCertificate>;
    return {};
  }

  auto
  TlsDatabase::lookup_certificate_issuer_vfunc (
      const Glib::RefPtr<TlsCertificate>& certificate,
      const Glib::RefPtr<TlsInteraction>& interaction,
      const Glib::RefPtr<Cancellable>& cancellable,
      LookupFlags flags) -> Glib::RefPtr<TlsCertificate>
  {
    const auto base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (gobject_)));

    if (base && base->lookup_certificate_issuer)
    {
      GError* gerror = nullptr;
      Glib::RefPtr<TlsCertificate> retval (
          Glib::wrap ((*base->lookup_certificate_issuer) (
              gobj (),
              Glib::unwrap (certificate),
              Glib::unwrap (interaction),
              static_cast<GTlsDatabaseLookupFlags> (flags),
              Glib::unwrap (cancellable),
              &gerror)));
      if (gerror)
        Glib::Error::throw_exception (gerror);
      return retval;
    }

    using RType = Glib::RefPtr<TlsCertificate>;
    return {};
  }

  auto
  TlsDatabase::lookup_certificate_issuer_async_vfunc (
      const Glib::RefPtr<TlsCertificate>& certificate,
      const Glib::RefPtr<TlsInteraction>& interaction,
      const SlotAsyncReady& slot,
      const Glib::RefPtr<Cancellable>& cancellable,
      LookupFlags flags) -> void
  {
    const auto slot_copy = new SlotAsyncReady (slot);

    const auto base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (gobject_)));

    if (base && base->lookup_certificate_issuer_async)
    {
      (*base->lookup_certificate_issuer_async) (
          gobj (),
          Glib::unwrap (certificate),
          Glib::unwrap (interaction),
          static_cast<GTlsDatabaseLookupFlags> (flags),
          Glib::unwrap (cancellable),
          &SignalProxy_async_callback,
          slot_copy);
    }
  }

  auto
  TlsDatabase::lookup_certificate_issuer_finish_vfunc (
      const Glib::RefPtr<AsyncResult>& result) -> Glib::RefPtr<TlsCertificate>
  {
    const auto base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (gobject_)));

    if (base && base->lookup_certificate_issuer_finish)
    {
      GError* gerror = nullptr;
      Glib::RefPtr<TlsCertificate> retval (Glib::wrap (
          (*base->lookup_certificate_issuer_finish) (gobj (),
                                                     Glib::unwrap (result),
                                                     &gerror)));
      if (gerror)
        Glib::Error::throw_exception (gerror);
      return retval;
    }

    using RType = Glib::RefPtr<TlsCertificate>;
    return {};
  }

  auto
  TlsDatabase::lookup_certificates_issued_by_vfunc (
      const Glib::RefPtr<Glib::ByteArray>& issuer_raw_dn,
      const Glib::RefPtr<TlsInteraction>& interaction,
      const Glib::RefPtr<Cancellable>& cancellable,
      LookupFlags flags) -> std::vector<Glib::RefPtr<TlsCertificate>>
  {
    const auto base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (gobject_)));

    if (base && base->lookup_certificates_issued_by)
    {
      GError* gerror = nullptr;
      std::vector<Glib::RefPtr<TlsCertificate>> retval (
          Glib::ListHandler<Glib::RefPtr<TlsCertificate>>::list_to_vector (
              (*base->lookup_certificates_issued_by) (
                  gobj (),
                  unwrap (issuer_raw_dn),
                  Glib::unwrap (interaction),
                  static_cast<GTlsDatabaseLookupFlags> (flags),
                  Glib::unwrap (cancellable),
                  &gerror),
              Glib::OWNERSHIP_DEEP));
      if (gerror)
        Glib::Error::throw_exception (gerror);
      return retval;
    }

    using RType = std::vector<Glib::RefPtr<TlsCertificate>>;
    return {};
  }

  auto
  TlsDatabase::lookup_certificates_issued_by_async_vfunc (
      const Glib::RefPtr<Glib::ByteArray>& issuer_raw_dn,
      const Glib::RefPtr<TlsInteraction>& interaction,
      const SlotAsyncReady& slot,
      const Glib::RefPtr<Cancellable>& cancellable,
      LookupFlags flags) -> void
  {
    const auto slot_copy = new SlotAsyncReady (slot);

    const auto base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (gobject_)));

    if (base && base->lookup_certificates_issued_by_async)
    {
      (*base->lookup_certificates_issued_by_async) (
          gobj (),
          unwrap (issuer_raw_dn),
          Glib::unwrap (interaction),
          static_cast<GTlsDatabaseLookupFlags> (flags),
          Glib::unwrap (cancellable),
          &SignalProxy_async_callback,
          slot_copy);
    }
  }

  auto
  TlsDatabase::lookup_certificates_issued_by_finish_vfunc (
      const Glib::RefPtr<AsyncResult>& result) -> std::vector<Glib::RefPtr<TlsCertificate>>
  {
    const auto base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (gobject_)));

    if (base && base->lookup_certificates_issued_by_finish)
    {
      GError* gerror = nullptr;
      std::vector<Glib::RefPtr<TlsCertificate>> retval (
          Glib::ListHandler<Glib::RefPtr<TlsCertificate>>::list_to_vector (
              (*base->lookup_certificates_issued_by_finish) (
                  gobj (),
                  Glib::unwrap (result),
                  &gerror),
              Glib::OWNERSHIP_DEEP));
      if (gerror)
        Glib::Error::throw_exception (gerror);
      return retval;
    }

    using RType = std::vector<Glib::RefPtr<TlsCertificate>>;
    return {};
  }

} // namespace Gio
