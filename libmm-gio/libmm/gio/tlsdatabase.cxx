// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/gio/tlsdatabase.hxx>
#include <libmm/gio/tlsdatabase_p.hxx>

#include <gio/gio.h>
#include <libmm/gio/cancellable.hxx>
#include <libmm/gio/slot_async.hxx>
#include <libmm/gio/socketconnectable.hxx>
#include <libmm/gio/tlscertificate.hxx>
#include <libmm/gio/tlsinteraction.hxx>

using VerifyFlags = gio::TlsDatabase::VerifyFlags;
using LookupFlags = gio::TlsDatabase::LookupFlags;

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
glib::Value<gio::TlsDatabase::VerifyFlags>::value_type () -> GType
{
  return g_tls_database_verify_flags_get_type ();
}

auto
glib::Value<gio::TlsDatabase::LookupFlags>::value_type () -> GType
{
  return g_tls_database_lookup_flags_get_type ();
}

namespace glib
{

  auto
  wrap (GTlsDatabase* object, const bool take_copy) -> RefPtr<gio::TlsDatabase>
  {
    return glib::make_refptr_for_instance<gio::TlsDatabase> (
        dynamic_cast<gio::TlsDatabase*> (
            wrap_auto ((GObject*) object, take_copy)));
  }

} // namespace glib

namespace gio
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
        glib::ObjectBase::_get_current_wrapper ((GObject*) self);

    if (obj_base && obj_base->is_derived_ ())
    {
      const auto obj = dynamic_cast<CppObjectType* const> (obj_base);
      if (obj)
      {
        try
        {
          return static_cast<GTlsCertificateFlags> (obj->verify_chain_vfunc (
              glib::wrap (chain, true),
              glib::convert_const_gchar_ptr_to_ustring (purpose),
              glib::wrap (identity, true),
              glib::wrap (interaction, true),
              glib::wrap (cancellable),
              static_cast<VerifyFlags> (flags)));
        }
        catch (glib::Error& errormm)
        {
          errormm.propagate (error);
          using RType = GTlsCertificateFlags;
          return RType ();
        }
        catch (...)
        {
          glib::exception_handlers_invoke ();
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
        glib::ObjectBase::_get_current_wrapper ((GObject*) self);

    if (obj_base && obj_base->is_derived_ ())
    {
      const auto obj = dynamic_cast<CppObjectType* const> (obj_base);
      if (obj)
      {
        try
        {
          obj->verify_chain_async_vfunc (
              glib::wrap (chain, true),
              glib::convert_const_gchar_ptr_to_ustring (purpose),
              glib::wrap (identity, true),
              glib::wrap (interaction, true),
              *slot,
              glib::wrap (cancellable),
              static_cast<VerifyFlags> (flags));
          return;
        }
        catch (...)
        {
          glib::exception_handlers_invoke ();
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
        glib::ObjectBase::_get_current_wrapper ((GObject*) self);

    if (obj_base && obj_base->is_derived_ ())
    {
      const auto obj = dynamic_cast<CppObjectType* const> (obj_base);
      if (obj)
      {
        try
        {
          return static_cast<GTlsCertificateFlags> (
              obj->verify_chain_finish_vfunc (glib::wrap (result, true)));
        }
        catch (glib::Error& errormm)
        {
          errormm.propagate (error);
          using RType = GTlsCertificateFlags;
          return RType ();
        }
        catch (...)
        {
          glib::exception_handlers_invoke ();
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
        glib::ObjectBase::_get_current_wrapper ((GObject*) self);

    if (obj_base && obj_base->is_derived_ ())
    {
      const auto obj = dynamic_cast<CppObjectType* const> (obj_base);
      if (obj)
      {
        try
        {
          return g_strdup (
              c_str_or_nullptr (obj->create_certificate_handle_vfunc (
                  glib::wrap (certificate, true))));
        }
        catch (...)
        {
          glib::exception_handlers_invoke ();
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
        glib::ObjectBase::_get_current_wrapper ((GObject*) self);

    if (obj_base && obj_base->is_derived_ ())
    {
      const auto obj = dynamic_cast<CppObjectType* const> (obj_base);
      if (obj)
      {
        try
        {
          return unwrap_copy (obj->lookup_certificate_for_handle_vfunc (
              glib::convert_const_gchar_ptr_to_ustring (handle),
              glib::wrap (interaction, true),
              glib::wrap (cancellable),
              static_cast<LookupFlags> (flags)));
        }
        catch (glib::Error& errormm)
        {
          errormm.propagate (error);
          using RType = GTlsCertificate*;
          return RType ();
        }
        catch (...)
        {
          glib::exception_handlers_invoke ();
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
        glib::ObjectBase::_get_current_wrapper ((GObject*) self);

    if (obj_base && obj_base->is_derived_ ())
    {
      const auto obj = dynamic_cast<CppObjectType* const> (obj_base);
      if (obj)
      {
        try
        {
          obj->lookup_certificate_for_handle_async_vfunc (
              glib::convert_const_gchar_ptr_to_ustring (handle),
              glib::wrap (interaction, true),
              *slot,
              glib::wrap (cancellable),
              static_cast<LookupFlags> (flags));
          return;
        }
        catch (...)
        {
          glib::exception_handlers_invoke ();
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
        glib::ObjectBase::_get_current_wrapper ((GObject*) self);

    if (obj_base && obj_base->is_derived_ ())
    {
      const auto obj = dynamic_cast<CppObjectType* const> (obj_base);
      if (obj)
      {
        try
        {
          return unwrap_copy (obj->lookup_certificate_for_handle_finish_vfunc (
              glib::wrap (result, true)));
        }
        catch (glib::Error& errormm)
        {
          errormm.propagate (error);
          using RType = GTlsCertificate*;
          return RType ();
        }
        catch (...)
        {
          glib::exception_handlers_invoke ();
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
        glib::ObjectBase::_get_current_wrapper ((GObject*) self);

    if (obj_base && obj_base->is_derived_ ())
    {
      const auto obj = dynamic_cast<CppObjectType* const> (obj_base);
      if (obj)
      {
        try
        {
          return unwrap_copy (obj->lookup_certificate_issuer_vfunc (
              glib::wrap (certificate, true),
              glib::wrap (interaction, true),
              glib::wrap (cancellable),
              static_cast<LookupFlags> (flags)));
        }
        catch (glib::Error& errormm)
        {
          errormm.propagate (error);
          using RType = GTlsCertificate*;
          return RType ();
        }
        catch (...)
        {
          glib::exception_handlers_invoke ();
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
        glib::ObjectBase::_get_current_wrapper ((GObject*) self);

    if (obj_base && obj_base->is_derived_ ())
    {
      const auto obj = dynamic_cast<CppObjectType* const> (obj_base);
      if (obj)
      {
        try
        {
          obj->lookup_certificate_issuer_async_vfunc (
              glib::wrap (certificate, true),
              glib::wrap (interaction, true),
              *slot,
              glib::wrap (cancellable),
              static_cast<LookupFlags> (flags));
          return;
        }
        catch (...)
        {
          glib::exception_handlers_invoke ();
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
        glib::ObjectBase::_get_current_wrapper ((GObject*) self);

    if (obj_base && obj_base->is_derived_ ())
    {
      const auto obj = dynamic_cast<CppObjectType* const> (obj_base);
      if (obj)
      {
        try
        {
          return unwrap_copy (obj->lookup_certificate_issuer_finish_vfunc (
              glib::wrap (result, true)));
        }
        catch (glib::Error& errormm)
        {
          errormm.propagate (error);
          using RType = GTlsCertificate*;
          return RType ();
        }
        catch (...)
        {
          glib::exception_handlers_invoke ();
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
        glib::ObjectBase::_get_current_wrapper ((GObject*) self);

    if (obj_base && obj_base->is_derived_ ())
    {
      const auto obj = dynamic_cast<CppObjectType* const> (obj_base);
      if (obj)
      {
        try
        {
          return g_list_copy_deep (
              glib::ListHandler<glib::RefPtr<TlsCertificate>>::vector_to_list (
                  obj->lookup_certificates_issued_by_vfunc (
                      glib::wrap (issuer_raw_dn, true),
                      glib::wrap (interaction, true),
                      glib::wrap (cancellable),
                      static_cast<LookupFlags> (flags)))
                  .data (),
              list_copy_ref,
              nullptr);
        }
        catch (glib::Error& errormm)
        {
          errormm.propagate (error);
          using RType = GList*;
          return RType ();
        }
        catch (...)
        {
          glib::exception_handlers_invoke ();
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
        glib::ObjectBase::_get_current_wrapper ((GObject*) self);

    if (obj_base && obj_base->is_derived_ ())
    {
      const auto obj = dynamic_cast<CppObjectType* const> (obj_base);
      if (obj)
      {
        try
        {
          obj->lookup_certificates_issued_by_async_vfunc (
              glib::wrap (issuer_raw_dn, true),
              glib::wrap (interaction, true),
              *slot,
              glib::wrap (cancellable),
              static_cast<LookupFlags> (flags));
          return;
        }
        catch (...)
        {
          glib::exception_handlers_invoke ();
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
        glib::ObjectBase::_get_current_wrapper ((GObject*) self);

    if (obj_base && obj_base->is_derived_ ())
    {
      const auto obj = dynamic_cast<CppObjectType* const> (obj_base);
      if (obj)
      {
        try
        {
          return g_list_copy_deep (
              glib::ListHandler<glib::RefPtr<TlsCertificate>>::vector_to_list (
                  obj->lookup_certificates_issued_by_finish_vfunc (
                      glib::wrap (result, true)))
                  .data (),
              list_copy_ref,
              nullptr);
        }
        catch (glib::Error& errormm)
        {
          errormm.propagate (error);
          using RType = GList*;
          return RType ();
        }
        catch (...)
        {
          glib::exception_handlers_invoke ();
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
  TlsDatabase_Class::wrap_new (GObject* object) -> glib::ObjectBase*
  {
    return new TlsDatabase ((GTlsDatabase*) object);
  }

  auto
  TlsDatabase::gobj_copy () -> GTlsDatabase*
  {
    reference ();
    return gobj ();
  }

  TlsDatabase::TlsDatabase (const glib::ConstructParams& construct_params)
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
      Object (glib::ConstructParams (tlsdatabase_class_.init ()))
  {
  }

  auto
  TlsDatabase::verify_chain (
      const glib::RefPtr<TlsCertificate>& chain,
      const glib::ustring& purpose,
      const glib::RefPtr<const SocketConnectable>& identity,
      const glib::RefPtr<TlsInteraction>& interaction,
      const glib::RefPtr<Cancellable>& cancellable,
      VerifyFlags flags) const -> TlsCertificateFlags
  {
    GError* gerror = nullptr;
    const auto retvalue =
        static_cast<TlsCertificateFlags> (g_tls_database_verify_chain (
            const_cast<GTlsDatabase*> (gobj ()),
            glib::unwrap (chain),
            purpose.c_str (),
            const_cast<GSocketConnectable*> (glib::unwrap (identity)),
            glib::unwrap (interaction),
            static_cast<GTlsDatabaseVerifyFlags> (flags),
            glib::unwrap (cancellable),
            &gerror));
    if (gerror)
      glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  TlsDatabase::verify_chain (
      const glib::RefPtr<TlsCertificate>& chain,
      const glib::ustring& purpose,
      const glib::RefPtr<const SocketConnectable>& identity,
      const glib::RefPtr<TlsInteraction>& interaction,
      VerifyFlags flags) const -> TlsCertificateFlags
  {
    GError* gerror = nullptr;
    const auto retvalue =
        static_cast<TlsCertificateFlags> (g_tls_database_verify_chain (
            const_cast<GTlsDatabase*> (gobj ()),
            glib::unwrap (chain),
            purpose.c_str (),
            const_cast<GSocketConnectable*> (glib::unwrap (identity)),
            glib::unwrap (interaction),
            static_cast<GTlsDatabaseVerifyFlags> (flags),
            nullptr,
            &gerror));
    if (gerror)
      glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  TlsDatabase::verify_chain (
      const glib::RefPtr<TlsCertificate>& chain,
      const glib::ustring& purpose,
      const glib::RefPtr<const SocketConnectable>& identity,
      const glib::RefPtr<Cancellable>& cancellable,
      VerifyFlags flags) const -> TlsCertificateFlags
  {
    GError* gerror = nullptr;
    const auto retvalue =
        static_cast<TlsCertificateFlags> (g_tls_database_verify_chain (
            const_cast<GTlsDatabase*> (gobj ()),
            glib::unwrap (chain),
            purpose.c_str (),
            const_cast<GSocketConnectable*> (glib::unwrap (identity)),
            nullptr,
            static_cast<GTlsDatabaseVerifyFlags> (flags),
            glib::unwrap (cancellable),
            &gerror));
    if (gerror)
      glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  TlsDatabase::verify_chain (
      const glib::RefPtr<TlsCertificate>& chain,
      const glib::ustring& purpose,
      const glib::RefPtr<const SocketConnectable>& identity,
      VerifyFlags flags) const -> TlsCertificateFlags
  {
    GError* gerror = nullptr;
    const auto retvalue =
        static_cast<TlsCertificateFlags> (g_tls_database_verify_chain (
            const_cast<GTlsDatabase*> (gobj ()),
            glib::unwrap (chain),
            purpose.c_str (),
            const_cast<GSocketConnectable*> (glib::unwrap (identity)),
            nullptr,
            static_cast<GTlsDatabaseVerifyFlags> (flags),
            nullptr,
            &gerror));
    if (gerror)
      glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  TlsDatabase::verify_chain (const glib::RefPtr<TlsCertificate>& chain,
                             const glib::ustring& purpose,
                             const glib::RefPtr<TlsInteraction>& interaction,
                             const glib::RefPtr<Cancellable>& cancellable,
                             VerifyFlags flags) const -> TlsCertificateFlags
  {
    GError* gerror = nullptr;
    const auto retvalue =
        static_cast<TlsCertificateFlags> (g_tls_database_verify_chain (
            const_cast<GTlsDatabase*> (gobj ()),
            glib::unwrap (chain),
            purpose.c_str (),
            nullptr,
            glib::unwrap (interaction),
            static_cast<GTlsDatabaseVerifyFlags> (flags),
            glib::unwrap (cancellable),
            &gerror));
    if (gerror)
      glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  TlsDatabase::verify_chain (const glib::RefPtr<TlsCertificate>& chain,
                             const glib::ustring& purpose,
                             const glib::RefPtr<TlsInteraction>& interaction,
                             VerifyFlags flags) const -> TlsCertificateFlags
  {
    GError* gerror = nullptr;
    const auto retvalue =
        static_cast<TlsCertificateFlags> (g_tls_database_verify_chain (
            const_cast<GTlsDatabase*> (gobj ()),
            glib::unwrap (chain),
            purpose.c_str (),
            nullptr,
            glib::unwrap (interaction),
            static_cast<GTlsDatabaseVerifyFlags> (flags),
            nullptr,
            &gerror));
    if (gerror)
      glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  TlsDatabase::verify_chain (const glib::RefPtr<TlsCertificate>& chain,
                             const glib::ustring& purpose,
                             const glib::RefPtr<Cancellable>& cancellable,
                             VerifyFlags flags) const -> TlsCertificateFlags
  {
    GError* gerror = nullptr;
    const auto retvalue =
        static_cast<TlsCertificateFlags> (g_tls_database_verify_chain (
            const_cast<GTlsDatabase*> (gobj ()),
            glib::unwrap (chain),
            purpose.c_str (),
            nullptr,
            nullptr,
            static_cast<GTlsDatabaseVerifyFlags> (flags),
            glib::unwrap (cancellable),
            &gerror));
    if (gerror)
      glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  TlsDatabase::verify_chain (const glib::RefPtr<TlsCertificate>& chain,
                             const glib::ustring& purpose,
                             VerifyFlags flags) const -> TlsCertificateFlags
  {
    GError* gerror = nullptr;
    const auto retvalue =
        static_cast<TlsCertificateFlags> (g_tls_database_verify_chain (
            const_cast<GTlsDatabase*> (gobj ()),
            glib::unwrap (chain),
            purpose.c_str (),
            nullptr,
            nullptr,
            static_cast<GTlsDatabaseVerifyFlags> (flags),
            nullptr,
            &gerror));
    if (gerror)
      glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  TlsDatabase::verify_chain_async (
      const glib::RefPtr<TlsCertificate>& chain,
      const glib::ustring& purpose,
      const glib::RefPtr<const SocketConnectable>& identity,
      const glib::RefPtr<TlsInteraction>& interaction,
      const SlotAsyncReady& slot,
      const glib::RefPtr<Cancellable>& cancellable,
      VerifyFlags flags) const -> void
  {
    const auto slot_copy = new SlotAsyncReady (slot);

    g_tls_database_verify_chain_async (
        const_cast<GTlsDatabase*> (gobj ()),
        glib::unwrap (chain),
        purpose.c_str (),
        const_cast<GSocketConnectable*> (glib::unwrap (identity)),
        glib::unwrap (interaction),
        static_cast<GTlsDatabaseVerifyFlags> (flags),
        glib::unwrap (cancellable),
        &SignalProxy_async_callback,
        slot_copy);
  }

  auto
  TlsDatabase::verify_chain_async (
      const glib::RefPtr<TlsCertificate>& chain,
      const glib::ustring& purpose,
      const glib::RefPtr<const SocketConnectable>& identity,
      const glib::RefPtr<TlsInteraction>& interaction,
      const SlotAsyncReady& slot,
      VerifyFlags flags) const -> void
  {
    const auto slot_copy = new SlotAsyncReady (slot);

    g_tls_database_verify_chain_async (
        const_cast<GTlsDatabase*> (gobj ()),
        glib::unwrap (chain),
        purpose.c_str (),
        const_cast<GSocketConnectable*> (glib::unwrap (identity)),
        glib::unwrap (interaction),
        static_cast<GTlsDatabaseVerifyFlags> (flags),
        nullptr,
        &SignalProxy_async_callback,
        slot_copy);
  }

  auto
  TlsDatabase::verify_chain_async (
      const glib::RefPtr<TlsCertificate>& chain,
      const glib::ustring& purpose,
      const glib::RefPtr<const SocketConnectable>& identity,
      const SlotAsyncReady& slot,
      const glib::RefPtr<Cancellable>& cancellable,
      VerifyFlags flags) const -> void
  {
    const auto slot_copy = new SlotAsyncReady (slot);

    g_tls_database_verify_chain_async (
        const_cast<GTlsDatabase*> (gobj ()),
        glib::unwrap (chain),
        purpose.c_str (),
        const_cast<GSocketConnectable*> (glib::unwrap (identity)),
        nullptr,
        static_cast<GTlsDatabaseVerifyFlags> (flags),
        glib::unwrap (cancellable),
        &SignalProxy_async_callback,
        slot_copy);
  }

  auto
  TlsDatabase::verify_chain_async (
      const glib::RefPtr<TlsCertificate>& chain,
      const glib::ustring& purpose,
      const glib::RefPtr<const SocketConnectable>& identity,
      const SlotAsyncReady& slot,
      VerifyFlags flags) const -> void
  {
    const auto slot_copy = new SlotAsyncReady (slot);

    g_tls_database_verify_chain_async (
        const_cast<GTlsDatabase*> (gobj ()),
        glib::unwrap (chain),
        purpose.c_str (),
        const_cast<GSocketConnectable*> (glib::unwrap (identity)),
        nullptr,
        static_cast<GTlsDatabaseVerifyFlags> (flags),
        nullptr,
        &SignalProxy_async_callback,
        slot_copy);
  }

  auto
  TlsDatabase::verify_chain_async (
      const glib::RefPtr<TlsCertificate>& chain,
      const glib::ustring& purpose,
      const glib::RefPtr<TlsInteraction>& interaction,
      const SlotAsyncReady& slot,
      const glib::RefPtr<Cancellable>& cancellable,
      VerifyFlags flags) const -> void
  {
    const auto slot_copy = new SlotAsyncReady (slot);

    g_tls_database_verify_chain_async (
        const_cast<GTlsDatabase*> (gobj ()),
        glib::unwrap (chain),
        purpose.c_str (),
        nullptr,
        glib::unwrap (interaction),
        static_cast<GTlsDatabaseVerifyFlags> (flags),
        glib::unwrap (cancellable),
        &SignalProxy_async_callback,
        slot_copy);
  }

  auto
  TlsDatabase::verify_chain_async (
      const glib::RefPtr<TlsCertificate>& chain,
      const glib::ustring& purpose,
      const glib::RefPtr<TlsInteraction>& interaction,
      const SlotAsyncReady& slot,
      VerifyFlags flags) const -> void
  {
    const auto slot_copy = new SlotAsyncReady (slot);

    g_tls_database_verify_chain_async (
        const_cast<GTlsDatabase*> (gobj ()),
        glib::unwrap (chain),
        purpose.c_str (),
        nullptr,
        glib::unwrap (interaction),
        static_cast<GTlsDatabaseVerifyFlags> (flags),
        nullptr,
        &SignalProxy_async_callback,
        slot_copy);
  }

  auto
  TlsDatabase::verify_chain_async (const glib::RefPtr<TlsCertificate>& chain,
                                   const glib::ustring& purpose,
                                   const SlotAsyncReady& slot,
                                   const glib::RefPtr<Cancellable>& cancellable,
                                   VerifyFlags flags) const -> void
  {
    const auto slot_copy = new SlotAsyncReady (slot);

    g_tls_database_verify_chain_async (
        const_cast<GTlsDatabase*> (gobj ()),
        glib::unwrap (chain),
        purpose.c_str (),
        nullptr,
        nullptr,
        static_cast<GTlsDatabaseVerifyFlags> (flags),
        glib::unwrap (cancellable),
        &SignalProxy_async_callback,
        slot_copy);
  }

  auto
  TlsDatabase::verify_chain_async (const glib::RefPtr<TlsCertificate>& chain,
                                   const glib::ustring& purpose,
                                   const SlotAsyncReady& slot,
                                   VerifyFlags flags) const -> void
  {
    const auto slot_copy = new SlotAsyncReady (slot);

    g_tls_database_verify_chain_async (
        const_cast<GTlsDatabase*> (gobj ()),
        glib::unwrap (chain),
        purpose.c_str (),
        nullptr,
        nullptr,
        static_cast<GTlsDatabaseVerifyFlags> (flags),
        nullptr,
        &SignalProxy_async_callback,
        slot_copy);
  }

  auto
  TlsDatabase::verify_chain_finish (const glib::RefPtr<AsyncResult>& result) -> TlsCertificateFlags
  {
    GError* gerror = nullptr;
    const auto retvalue = static_cast<TlsCertificateFlags> (
        g_tls_database_verify_chain_finish (gobj (),
                                            glib::unwrap (result),
                                            &gerror));
    if (gerror)
      glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  TlsDatabase::lookup_certificate_issuer (
      const glib::RefPtr<const TlsCertificate>& certificate,
      const glib::RefPtr<TlsInteraction>& interaction,
      const glib::RefPtr<Cancellable>& cancellable,
      LookupFlags flags) -> glib::RefPtr<TlsCertificate>
  {
    GError* gerror = nullptr;
    auto retvalue = glib::wrap (g_tls_database_lookup_certificate_issuer (
        gobj (),
        const_cast<GTlsCertificate*> (glib::unwrap (certificate)),
        glib::unwrap (interaction),
        static_cast<GTlsDatabaseLookupFlags> (flags),
        glib::unwrap (cancellable),
        &gerror));
    if (gerror)
      glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  TlsDatabase::lookup_certificate_issuer (
      const glib::RefPtr<const TlsCertificate>& certificate,
      const glib::RefPtr<TlsInteraction>& interaction,
      LookupFlags flags) -> glib::RefPtr<TlsCertificate>
  {
    GError* gerror = nullptr;
    auto retvalue = glib::wrap (g_tls_database_lookup_certificate_issuer (
        gobj (),
        const_cast<GTlsCertificate*> (glib::unwrap (certificate)),
        glib::unwrap (interaction),
        static_cast<GTlsDatabaseLookupFlags> (flags),
        nullptr,
        &gerror));
    if (gerror)
      glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  TlsDatabase::lookup_certificate_issuer (
      const glib::RefPtr<const TlsCertificate>& certificate,
      const glib::RefPtr<Cancellable>& cancellable,
      LookupFlags flags) -> glib::RefPtr<TlsCertificate>
  {
    GError* gerror = nullptr;
    auto retvalue = glib::wrap (g_tls_database_lookup_certificate_issuer (
        gobj (),
        const_cast<GTlsCertificate*> (glib::unwrap (certificate)),
        nullptr,
        static_cast<GTlsDatabaseLookupFlags> (flags),
        glib::unwrap (cancellable),
        &gerror));
    if (gerror)
      glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  TlsDatabase::lookup_certificate_issuer (
      const glib::RefPtr<const TlsCertificate>& certificate,
      LookupFlags flags) -> glib::RefPtr<TlsCertificate>
  {
    GError* gerror = nullptr;
    auto retvalue = glib::wrap (g_tls_database_lookup_certificate_issuer (
        gobj (),
        const_cast<GTlsCertificate*> (glib::unwrap (certificate)),
        nullptr,
        static_cast<GTlsDatabaseLookupFlags> (flags),
        nullptr,
        &gerror));
    if (gerror)
      glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  TlsDatabase::lookup_certificate_issuer (
      const glib::RefPtr<const TlsCertificate>& certificate,
      const glib::RefPtr<TlsInteraction>& interaction,
      const glib::RefPtr<Cancellable>& cancellable,
      const LookupFlags flags) const -> glib::RefPtr<const TlsCertificate>
  {
    return const_cast<TlsDatabase*> (this)->lookup_certificate_issuer (
        certificate,
        interaction,
        cancellable,
        flags);
  }

  auto
  TlsDatabase::lookup_certificate_issuer (
      const glib::RefPtr<const TlsCertificate>& certificate,
      const glib::RefPtr<TlsInteraction>& interaction,
      const LookupFlags flags) const -> glib::RefPtr<const TlsCertificate>
  {
    return const_cast<TlsDatabase*> (this)->lookup_certificate_issuer (
        certificate,
        interaction,
        flags);
  }

  auto
  TlsDatabase::lookup_certificate_issuer (
      const glib::RefPtr<const TlsCertificate>& certificate,
      const glib::RefPtr<Cancellable>& cancellable,
      const LookupFlags flags) const -> glib::RefPtr<const TlsCertificate>
  {
    return const_cast<TlsDatabase*> (this)->lookup_certificate_issuer (
        certificate,
        cancellable,
        flags);
  }

  auto
  TlsDatabase::lookup_certificate_issuer (
      const glib::RefPtr<const TlsCertificate>& certificate,
      const LookupFlags flags) const -> glib::RefPtr<const TlsCertificate>
  {
    return const_cast<TlsDatabase*> (this)->lookup_certificate_issuer (
        certificate,
        flags);
  }

  auto
  TlsDatabase::lookup_certificate_issuer_async (
      const glib::RefPtr<const TlsCertificate>& certificate,
      const glib::RefPtr<TlsInteraction>& interaction,
      const SlotAsyncReady& slot,
      const glib::RefPtr<Cancellable>& cancellable,
      LookupFlags flags) -> void
  {
    const auto slot_copy = new SlotAsyncReady (slot);

    g_tls_database_lookup_certificate_issuer_async (
        gobj (),
        const_cast<GTlsCertificate*> (glib::unwrap (certificate)),
        glib::unwrap (interaction),
        static_cast<GTlsDatabaseLookupFlags> (flags),
        glib::unwrap (cancellable),
        &SignalProxy_async_callback,
        slot_copy);
  }

  auto
  TlsDatabase::lookup_certificate_issuer_async (
      const glib::RefPtr<const TlsCertificate>& certificate,
      const glib::RefPtr<TlsInteraction>& interaction,
      const SlotAsyncReady& slot,
      LookupFlags flags) -> void
  {
    const auto slot_copy = new SlotAsyncReady (slot);

    g_tls_database_lookup_certificate_issuer_async (
        gobj (),
        const_cast<GTlsCertificate*> (glib::unwrap (certificate)),
        glib::unwrap (interaction),
        static_cast<GTlsDatabaseLookupFlags> (flags),
        nullptr,
        &SignalProxy_async_callback,
        slot_copy);
  }

  auto
  TlsDatabase::lookup_certificate_issuer_async (
      const glib::RefPtr<const TlsCertificate>& certificate,
      const SlotAsyncReady& slot,
      const glib::RefPtr<Cancellable>& cancellable,
      LookupFlags flags) -> void
  {
    const auto slot_copy = new SlotAsyncReady (slot);

    g_tls_database_lookup_certificate_issuer_async (
        gobj (),
        const_cast<GTlsCertificate*> (glib::unwrap (certificate)),
        nullptr,
        static_cast<GTlsDatabaseLookupFlags> (flags),
        glib::unwrap (cancellable),
        &SignalProxy_async_callback,
        slot_copy);
  }

  auto
  TlsDatabase::lookup_certificate_issuer_async (
      const glib::RefPtr<const TlsCertificate>& certificate,
      const SlotAsyncReady& slot,
      LookupFlags flags) -> void
  {
    const auto slot_copy = new SlotAsyncReady (slot);

    g_tls_database_lookup_certificate_issuer_async (
        gobj (),
        const_cast<GTlsCertificate*> (glib::unwrap (certificate)),
        nullptr,
        static_cast<GTlsDatabaseLookupFlags> (flags),
        nullptr,
        &SignalProxy_async_callback,
        slot_copy);
  }

  auto
  TlsDatabase::lookup_certificate_issuer_finish (
      const glib::RefPtr<AsyncResult>& result) -> glib::RefPtr<TlsCertificate>
  {
    GError* gerror = nullptr;
    auto retvalue = glib::wrap (
        g_tls_database_lookup_certificate_issuer_finish (gobj (),
                                                         glib::unwrap (result),
                                                         &gerror));
    if (gerror)
      glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  TlsDatabase::lookup_certificates_issued_by (
      const glib::RefPtr<glib::ByteArray>& issuer_raw_dn,
      const glib::RefPtr<TlsInteraction>& interaction,
      const glib::RefPtr<Cancellable>& cancellable,
      LookupFlags flags) -> std::vector<glib::RefPtr<TlsCertificate>>
  {
    GError* gerror = nullptr;
    auto retvalue =
        glib::ListHandler<glib::RefPtr<TlsCertificate>>::list_to_vector (
            g_tls_database_lookup_certificates_issued_by (
                gobj (),
                unwrap (issuer_raw_dn),
                glib::unwrap (interaction),
                static_cast<GTlsDatabaseLookupFlags> (flags),
                glib::unwrap (cancellable),
                &gerror),
            glib::OWNERSHIP_DEEP);
    if (gerror)
      glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  TlsDatabase::lookup_certificates_issued_by (
      const glib::RefPtr<glib::ByteArray>& issuer_raw_dn,
      const glib::RefPtr<TlsInteraction>& interaction,
      LookupFlags flags) -> std::vector<glib::RefPtr<TlsCertificate>>
  {
    GError* gerror = nullptr;
    auto retvalue =
        glib::ListHandler<glib::RefPtr<TlsCertificate>>::list_to_vector (
            g_tls_database_lookup_certificates_issued_by (
                gobj (),
                unwrap (issuer_raw_dn),
                glib::unwrap (interaction),
                static_cast<GTlsDatabaseLookupFlags> (flags),
                nullptr,
                &gerror),
            glib::OWNERSHIP_DEEP);
    if (gerror)
      glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  TlsDatabase::lookup_certificates_issued_by (
      const glib::RefPtr<glib::ByteArray>& issuer_raw_dn,
      const glib::RefPtr<Cancellable>& cancellable,
      LookupFlags flags) -> std::vector<glib::RefPtr<TlsCertificate>>
  {
    GError* gerror = nullptr;
    auto retvalue =
        glib::ListHandler<glib::RefPtr<TlsCertificate>>::list_to_vector (
            g_tls_database_lookup_certificates_issued_by (
                gobj (),
                unwrap (issuer_raw_dn),
                nullptr,
                static_cast<GTlsDatabaseLookupFlags> (flags),
                glib::unwrap (cancellable),
                &gerror),
            glib::OWNERSHIP_DEEP);
    if (gerror)
      glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  TlsDatabase::lookup_certificates_issued_by (
      const glib::RefPtr<glib::ByteArray>& issuer_raw_dn,
      LookupFlags flags) -> std::vector<glib::RefPtr<TlsCertificate>>
  {
    GError* gerror = nullptr;
    auto retvalue =
        glib::ListHandler<glib::RefPtr<TlsCertificate>>::list_to_vector (
            g_tls_database_lookup_certificates_issued_by (
                gobj (),
                unwrap (issuer_raw_dn),
                nullptr,
                static_cast<GTlsDatabaseLookupFlags> (flags),
                nullptr,
                &gerror),
            glib::OWNERSHIP_DEEP);
    if (gerror)
      glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  TlsDatabase::lookup_certificates_issued_by (
      const glib::RefPtr<glib::ByteArray>& issuer_raw_dn,
      const glib::RefPtr<TlsInteraction>& interaction,
      const glib::RefPtr<Cancellable>& cancellable,
      LookupFlags flags) const -> std::vector<glib::RefPtr<const TlsCertificate>>
  {
    GError* gerror = nullptr;
    auto retvalue =
        glib::ListHandler<glib::RefPtr<const TlsCertificate>>::list_to_vector (
            g_tls_database_lookup_certificates_issued_by (
                const_cast<GTlsDatabase*> (gobj ()),
                unwrap (issuer_raw_dn),
                glib::unwrap (interaction),
                static_cast<GTlsDatabaseLookupFlags> (flags),
                glib::unwrap (cancellable),
                &gerror),
            glib::OWNERSHIP_DEEP);
    if (gerror)
      glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  TlsDatabase::lookup_certificates_issued_by (
      const glib::RefPtr<glib::ByteArray>& issuer_raw_dn,
      const glib::RefPtr<TlsInteraction>& interaction,
      LookupFlags flags) const -> std::vector<glib::RefPtr<const TlsCertificate>>
  {
    GError* gerror = nullptr;
    auto retvalue =
        glib::ListHandler<glib::RefPtr<const TlsCertificate>>::list_to_vector (
            g_tls_database_lookup_certificates_issued_by (
                const_cast<GTlsDatabase*> (gobj ()),
                unwrap (issuer_raw_dn),
                glib::unwrap (interaction),
                static_cast<GTlsDatabaseLookupFlags> (flags),
                nullptr,
                &gerror),
            glib::OWNERSHIP_DEEP);
    if (gerror)
      glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  TlsDatabase::lookup_certificates_issued_by (
      const glib::RefPtr<glib::ByteArray>& issuer_raw_dn,
      const glib::RefPtr<Cancellable>& cancellable,
      LookupFlags flags) const -> std::vector<glib::RefPtr<const TlsCertificate>>
  {
    GError* gerror = nullptr;
    auto retvalue =
        glib::ListHandler<glib::RefPtr<const TlsCertificate>>::list_to_vector (
            g_tls_database_lookup_certificates_issued_by (
                const_cast<GTlsDatabase*> (gobj ()),
                unwrap (issuer_raw_dn),
                nullptr,
                static_cast<GTlsDatabaseLookupFlags> (flags),
                glib::unwrap (cancellable),
                &gerror),
            glib::OWNERSHIP_DEEP);
    if (gerror)
      glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  TlsDatabase::lookup_certificates_issued_by (
      const glib::RefPtr<glib::ByteArray>& issuer_raw_dn,
      LookupFlags flags) const -> std::vector<glib::RefPtr<const TlsCertificate>>
  {
    GError* gerror = nullptr;
    auto retvalue =
        glib::ListHandler<glib::RefPtr<const TlsCertificate>>::list_to_vector (
            g_tls_database_lookup_certificates_issued_by (
                const_cast<GTlsDatabase*> (gobj ()),
                unwrap (issuer_raw_dn),
                nullptr,
                static_cast<GTlsDatabaseLookupFlags> (flags),
                nullptr,
                &gerror),
            glib::OWNERSHIP_DEEP);
    if (gerror)
      glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  TlsDatabase::lookup_certificates_issued_by_async (
      const glib::RefPtr<glib::ByteArray>& issuer_raw_dn,
      const glib::RefPtr<TlsInteraction>& interaction,
      const SlotAsyncReady& slot,
      const glib::RefPtr<Cancellable>& cancellable,
      LookupFlags flags) -> void
  {
    const auto slot_copy = new SlotAsyncReady (slot);

    g_tls_database_lookup_certificates_issued_by_async (
        gobj (),
        unwrap (issuer_raw_dn),
        glib::unwrap (interaction),
        static_cast<GTlsDatabaseLookupFlags> (flags),
        glib::unwrap (cancellable),
        &SignalProxy_async_callback,
        slot_copy);
  }

  auto
  TlsDatabase::lookup_certificates_issued_by_async (
      const glib::RefPtr<glib::ByteArray>& issuer_raw_dn,
      const glib::RefPtr<TlsInteraction>& interaction,
      const SlotAsyncReady& slot,
      LookupFlags flags) -> void
  {
    const auto slot_copy = new SlotAsyncReady (slot);

    g_tls_database_lookup_certificates_issued_by_async (
        gobj (),
        unwrap (issuer_raw_dn),
        glib::unwrap (interaction),
        static_cast<GTlsDatabaseLookupFlags> (flags),
        nullptr,
        &SignalProxy_async_callback,
        slot_copy);
  }

  auto
  TlsDatabase::lookup_certificates_issued_by_async (
      const glib::RefPtr<glib::ByteArray>& issuer_raw_dn,
      const SlotAsyncReady& slot,
      const glib::RefPtr<Cancellable>& cancellable,
      LookupFlags flags) -> void
  {
    const auto slot_copy = new SlotAsyncReady (slot);

    g_tls_database_lookup_certificates_issued_by_async (
        gobj (),
        unwrap (issuer_raw_dn),
        nullptr,
        static_cast<GTlsDatabaseLookupFlags> (flags),
        glib::unwrap (cancellable),
        &SignalProxy_async_callback,
        slot_copy);
  }

  auto
  TlsDatabase::lookup_certificates_issued_by_async (
      const glib::RefPtr<glib::ByteArray>& issuer_raw_dn,
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
      const glib::RefPtr<AsyncResult>& result) -> std::vector<glib::RefPtr<TlsCertificate>>
  {
    GError* gerror = nullptr;
    auto retvalue =
        glib::ListHandler<glib::RefPtr<TlsCertificate>>::list_to_vector (
            g_tls_database_lookup_certificates_issued_by_finish (
                gobj (),
                glib::unwrap (result),
                &gerror),
            glib::OWNERSHIP_DEEP);
    if (gerror)
      glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  TlsDatabase::create_certificate_handle (
      const glib::RefPtr<const TlsCertificate>& certificate) const -> glib::ustring
  {
    return glib::convert_return_gchar_ptr_to_ustring (
        g_tls_database_create_certificate_handle (
            const_cast<GTlsDatabase*> (gobj ()),
            const_cast<GTlsCertificate*> (glib::unwrap (certificate))));
  }

  auto
  TlsDatabase::lookup_certificate_for_handle (
      const glib::ustring& handle,
      const glib::RefPtr<TlsInteraction>& interaction,
      const glib::RefPtr<Cancellable>& cancellable,
      LookupFlags flags) -> glib::RefPtr<TlsCertificate>
  {
    GError* gerror = nullptr;
    auto retvalue = glib::wrap (g_tls_database_lookup_certificate_for_handle (
        gobj (),
        handle.c_str (),
        glib::unwrap (interaction),
        static_cast<GTlsDatabaseLookupFlags> (flags),
        glib::unwrap (cancellable),
        &gerror));
    if (gerror)
      glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  TlsDatabase::lookup_certificate_for_handle (
      const glib::ustring& handle,
      const glib::RefPtr<TlsInteraction>& interaction,
      LookupFlags flags) -> glib::RefPtr<TlsCertificate>
  {
    GError* gerror = nullptr;
    auto retvalue = glib::wrap (g_tls_database_lookup_certificate_for_handle (
        gobj (),
        handle.c_str (),
        glib::unwrap (interaction),
        static_cast<GTlsDatabaseLookupFlags> (flags),
        nullptr,
        &gerror));
    if (gerror)
      glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  TlsDatabase::lookup_certificate_for_handle (
      const glib::ustring& handle,
      const glib::RefPtr<Cancellable>& cancellable,
      LookupFlags flags) -> glib::RefPtr<TlsCertificate>
  {
    GError* gerror = nullptr;
    auto retvalue = glib::wrap (g_tls_database_lookup_certificate_for_handle (
        gobj (),
        handle.c_str (),
        nullptr,
        static_cast<GTlsDatabaseLookupFlags> (flags),
        glib::unwrap (cancellable),
        &gerror));
    if (gerror)
      glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  TlsDatabase::lookup_certificate_for_handle (const glib::ustring& handle,
                                              LookupFlags flags) -> glib::RefPtr<TlsCertificate>
  {
    GError* gerror = nullptr;
    auto retvalue = glib::wrap (g_tls_database_lookup_certificate_for_handle (
        gobj (),
        handle.c_str (),
        nullptr,
        static_cast<GTlsDatabaseLookupFlags> (flags),
        nullptr,
        &gerror));
    if (gerror)
      glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  TlsDatabase::lookup_certificate_for_handle (
      const glib::ustring& handle,
      const glib::RefPtr<TlsInteraction>& interaction,
      const glib::RefPtr<Cancellable>& cancellable,
      const LookupFlags flags) const -> glib::RefPtr<const TlsCertificate>
  {
    return const_cast<TlsDatabase*> (this)->lookup_certificate_for_handle (
        handle,
        interaction,
        cancellable,
        flags);
  }

  auto
  TlsDatabase::lookup_certificate_for_handle (
      const glib::ustring& handle,
      const glib::RefPtr<TlsInteraction>& interaction,
      const LookupFlags flags) const -> glib::RefPtr<const TlsCertificate>
  {
    return const_cast<TlsDatabase*> (this)->lookup_certificate_for_handle (
        handle,
        interaction,
        flags);
  }

  auto
  TlsDatabase::lookup_certificate_for_handle (
      const glib::ustring& handle,
      const glib::RefPtr<Cancellable>& cancellable,
      const LookupFlags flags) const -> glib::RefPtr<const TlsCertificate>
  {
    return const_cast<TlsDatabase*> (this)->lookup_certificate_for_handle (
        handle,
        cancellable,
        flags);
  }

  auto
  TlsDatabase::lookup_certificate_for_handle (const glib::ustring& handle,
                                              const LookupFlags flags) const -> glib::RefPtr<const TlsCertificate>
  {
    return const_cast<TlsDatabase*> (this)->lookup_certificate_for_handle (
        handle,
        flags);
  }

  auto
  TlsDatabase::lookup_certificate_for_handle_async (
      const glib::ustring& handle,
      const glib::RefPtr<TlsInteraction>& interaction,
      const SlotAsyncReady& slot,
      const glib::RefPtr<Cancellable>& cancellable,
      LookupFlags flags) -> void
  {
    const auto slot_copy = new SlotAsyncReady (slot);

    g_tls_database_lookup_certificate_for_handle_async (
        gobj (),
        handle.c_str (),
        glib::unwrap (interaction),
        static_cast<GTlsDatabaseLookupFlags> (flags),
        glib::unwrap (cancellable),
        &SignalProxy_async_callback,
        slot_copy);
  }

  auto
  TlsDatabase::lookup_certificate_for_handle_async (
      const glib::ustring& handle,
      const glib::RefPtr<TlsInteraction>& interaction,
      const SlotAsyncReady& slot,
      LookupFlags flags) -> void
  {
    const auto slot_copy = new SlotAsyncReady (slot);

    g_tls_database_lookup_certificate_for_handle_async (
        gobj (),
        handle.c_str (),
        glib::unwrap (interaction),
        static_cast<GTlsDatabaseLookupFlags> (flags),
        nullptr,
        &SignalProxy_async_callback,
        slot_copy);
  }

  auto
  TlsDatabase::lookup_certificate_for_handle_async (
      const glib::ustring& handle,
      const SlotAsyncReady& slot,
      const glib::RefPtr<Cancellable>& cancellable,
      LookupFlags flags) -> void
  {
    const auto slot_copy = new SlotAsyncReady (slot);

    g_tls_database_lookup_certificate_for_handle_async (
        gobj (),
        handle.c_str (),
        nullptr,
        static_cast<GTlsDatabaseLookupFlags> (flags),
        glib::unwrap (cancellable),
        &SignalProxy_async_callback,
        slot_copy);
  }

  auto
  TlsDatabase::lookup_certificate_for_handle_async (const glib::ustring& handle,
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
      const glib::RefPtr<AsyncResult>& result) -> glib::RefPtr<TlsCertificate>
  {
    GError* gerror = nullptr;
    auto retvalue =
        glib::wrap (g_tls_database_lookup_certificate_for_handle_finish (
            gobj (),
            glib::unwrap (result),
            &gerror));
    if (gerror)
      glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  TlsDatabase::verify_chain_vfunc (
      const glib::RefPtr<TlsCertificate>& chain,
      const glib::ustring& purpose,
      const glib::RefPtr<const SocketConnectable>& identity,
      const glib::RefPtr<TlsInteraction>& interaction,
      const glib::RefPtr<Cancellable>& cancellable,
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
              glib::unwrap (chain),
              purpose.c_str (),
              const_cast<GSocketConnectable*> (glib::unwrap (identity)),
              glib::unwrap (interaction),
              static_cast<GTlsDatabaseVerifyFlags> (flags),
              glib::unwrap (cancellable),
              &gerror)));
      if (gerror)
        glib::Error::throw_exception (gerror);
      return retval;
    }

    using RType = TlsCertificateFlags;
    return RType ();
  }

  auto
  TlsDatabase::verify_chain_async_vfunc (
      const glib::RefPtr<TlsCertificate>& chain,
      const glib::ustring& purpose,
      const glib::RefPtr<const SocketConnectable>& identity,
      const glib::RefPtr<TlsInteraction>& interaction,
      const SlotAsyncReady& slot,
      const glib::RefPtr<Cancellable>& cancellable,
      VerifyFlags flags) const -> void
  {
    const auto slot_copy = new SlotAsyncReady (slot);

    const auto base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (gobject_)));

    if (base && base->verify_chain_async)
    {
      (*base->verify_chain_async) (
          const_cast<GTlsDatabase*> (gobj ()),
          glib::unwrap (chain),
          purpose.c_str (),
          const_cast<GSocketConnectable*> (glib::unwrap (identity)),
          glib::unwrap (interaction),
          static_cast<GTlsDatabaseVerifyFlags> (flags),
          glib::unwrap (cancellable),
          &SignalProxy_async_callback,
          slot_copy);
    }
  }

  auto
  TlsDatabase::verify_chain_finish_vfunc (
      const glib::RefPtr<AsyncResult>& result) -> TlsCertificateFlags
  {
    const auto base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (gobject_)));

    if (base && base->verify_chain_finish)
    {
      GError* gerror = nullptr;
      const TlsCertificateFlags retval (static_cast<TlsCertificateFlags> (
          (*base->verify_chain_finish) (gobj (),
                                        glib::unwrap (result),
                                        &gerror)));
      if (gerror)
        glib::Error::throw_exception (gerror);
      return retval;
    }

    using RType = TlsCertificateFlags;
    return RType ();
  }

  auto
  TlsDatabase::create_certificate_handle_vfunc (
      const glib::RefPtr<const TlsCertificate>& certificate) const -> glib::ustring
  {
    const auto base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (gobject_)));

    if (base && base->create_certificate_handle)
    {
      glib::ustring retval (glib::convert_return_gchar_ptr_to_ustring (
          (*base->create_certificate_handle) (
              const_cast<GTlsDatabase*> (gobj ()),
              const_cast<GTlsCertificate*> (glib::unwrap (certificate)))));
      return retval;
    }

    using RType = glib::ustring;
    return {};
  }

  auto
  TlsDatabase::lookup_certificate_for_handle_vfunc (
      const glib::ustring& handle,
      const glib::RefPtr<TlsInteraction>& interaction,
      const glib::RefPtr<Cancellable>& cancellable,
      LookupFlags flags) -> glib::RefPtr<TlsCertificate>
  {
    const auto base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (gobject_)));

    if (base && base->lookup_certificate_for_handle)
    {
      GError* gerror = nullptr;
      glib::RefPtr<TlsCertificate> retval (
          glib::wrap ((*base->lookup_certificate_for_handle) (
              gobj (),
              handle.c_str (),
              glib::unwrap (interaction),
              static_cast<GTlsDatabaseLookupFlags> (flags),
              glib::unwrap (cancellable),
              &gerror)));
      if (gerror)
        glib::Error::throw_exception (gerror);
      return retval;
    }

    using RType = glib::RefPtr<TlsCertificate>;
    return {};
  }

  auto
  TlsDatabase::lookup_certificate_for_handle_async_vfunc (
      const glib::ustring& handle,
      const glib::RefPtr<TlsInteraction>& interaction,
      const SlotAsyncReady& slot,
      const glib::RefPtr<Cancellable>& cancellable,
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
          glib::unwrap (interaction),
          static_cast<GTlsDatabaseLookupFlags> (flags),
          glib::unwrap (cancellable),
          &SignalProxy_async_callback,
          slot_copy);
    }
  }

  auto
  TlsDatabase::lookup_certificate_for_handle_finish_vfunc (
      const glib::RefPtr<AsyncResult>& result) -> glib::RefPtr<TlsCertificate>
  {
    const auto base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (gobject_)));

    if (base && base->lookup_certificate_for_handle_finish)
    {
      GError* gerror = nullptr;
      glib::RefPtr<TlsCertificate> retval (glib::wrap (
          (*base->lookup_certificate_for_handle_finish) (gobj (),
                                                         glib::unwrap (result),
                                                         &gerror)));
      if (gerror)
        glib::Error::throw_exception (gerror);
      return retval;
    }

    using RType = glib::RefPtr<TlsCertificate>;
    return {};
  }

  auto
  TlsDatabase::lookup_certificate_issuer_vfunc (
      const glib::RefPtr<TlsCertificate>& certificate,
      const glib::RefPtr<TlsInteraction>& interaction,
      const glib::RefPtr<Cancellable>& cancellable,
      LookupFlags flags) -> glib::RefPtr<TlsCertificate>
  {
    const auto base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (gobject_)));

    if (base && base->lookup_certificate_issuer)
    {
      GError* gerror = nullptr;
      glib::RefPtr<TlsCertificate> retval (
          glib::wrap ((*base->lookup_certificate_issuer) (
              gobj (),
              glib::unwrap (certificate),
              glib::unwrap (interaction),
              static_cast<GTlsDatabaseLookupFlags> (flags),
              glib::unwrap (cancellable),
              &gerror)));
      if (gerror)
        glib::Error::throw_exception (gerror);
      return retval;
    }

    using RType = glib::RefPtr<TlsCertificate>;
    return {};
  }

  auto
  TlsDatabase::lookup_certificate_issuer_async_vfunc (
      const glib::RefPtr<TlsCertificate>& certificate,
      const glib::RefPtr<TlsInteraction>& interaction,
      const SlotAsyncReady& slot,
      const glib::RefPtr<Cancellable>& cancellable,
      LookupFlags flags) -> void
  {
    const auto slot_copy = new SlotAsyncReady (slot);

    const auto base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (gobject_)));

    if (base && base->lookup_certificate_issuer_async)
    {
      (*base->lookup_certificate_issuer_async) (
          gobj (),
          glib::unwrap (certificate),
          glib::unwrap (interaction),
          static_cast<GTlsDatabaseLookupFlags> (flags),
          glib::unwrap (cancellable),
          &SignalProxy_async_callback,
          slot_copy);
    }
  }

  auto
  TlsDatabase::lookup_certificate_issuer_finish_vfunc (
      const glib::RefPtr<AsyncResult>& result) -> glib::RefPtr<TlsCertificate>
  {
    const auto base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (gobject_)));

    if (base && base->lookup_certificate_issuer_finish)
    {
      GError* gerror = nullptr;
      glib::RefPtr<TlsCertificate> retval (glib::wrap (
          (*base->lookup_certificate_issuer_finish) (gobj (),
                                                     glib::unwrap (result),
                                                     &gerror)));
      if (gerror)
        glib::Error::throw_exception (gerror);
      return retval;
    }

    using RType = glib::RefPtr<TlsCertificate>;
    return {};
  }

  auto
  TlsDatabase::lookup_certificates_issued_by_vfunc (
      const glib::RefPtr<glib::ByteArray>& issuer_raw_dn,
      const glib::RefPtr<TlsInteraction>& interaction,
      const glib::RefPtr<Cancellable>& cancellable,
      LookupFlags flags) -> std::vector<glib::RefPtr<TlsCertificate>>
  {
    const auto base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (gobject_)));

    if (base && base->lookup_certificates_issued_by)
    {
      GError* gerror = nullptr;
      std::vector<glib::RefPtr<TlsCertificate>> retval (
          glib::ListHandler<glib::RefPtr<TlsCertificate>>::list_to_vector (
              (*base->lookup_certificates_issued_by) (
                  gobj (),
                  unwrap (issuer_raw_dn),
                  glib::unwrap (interaction),
                  static_cast<GTlsDatabaseLookupFlags> (flags),
                  glib::unwrap (cancellable),
                  &gerror),
              glib::OWNERSHIP_DEEP));
      if (gerror)
        glib::Error::throw_exception (gerror);
      return retval;
    }

    using RType = std::vector<glib::RefPtr<TlsCertificate>>;
    return {};
  }

  auto
  TlsDatabase::lookup_certificates_issued_by_async_vfunc (
      const glib::RefPtr<glib::ByteArray>& issuer_raw_dn,
      const glib::RefPtr<TlsInteraction>& interaction,
      const SlotAsyncReady& slot,
      const glib::RefPtr<Cancellable>& cancellable,
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
          glib::unwrap (interaction),
          static_cast<GTlsDatabaseLookupFlags> (flags),
          glib::unwrap (cancellable),
          &SignalProxy_async_callback,
          slot_copy);
    }
  }

  auto
  TlsDatabase::lookup_certificates_issued_by_finish_vfunc (
      const glib::RefPtr<AsyncResult>& result) -> std::vector<glib::RefPtr<TlsCertificate>>
  {
    const auto base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (gobject_)));

    if (base && base->lookup_certificates_issued_by_finish)
    {
      GError* gerror = nullptr;
      std::vector<glib::RefPtr<TlsCertificate>> retval (
          glib::ListHandler<glib::RefPtr<TlsCertificate>>::list_to_vector (
              (*base->lookup_certificates_issued_by_finish) (
                  gobj (),
                  glib::unwrap (result),
                  &gerror),
              glib::OWNERSHIP_DEEP));
      if (gerror)
        glib::Error::throw_exception (gerror);
      return retval;
    }

    using RType = std::vector<glib::RefPtr<TlsCertificate>>;
    return {};
  }

} // namespace gio
