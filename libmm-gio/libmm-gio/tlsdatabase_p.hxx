// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GIOMM_TLSDATABASE_P_H
#define _GIOMM_TLSDATABASE_P_H

#include <libmm-glib/object_p.hxx>

#include <libmm-glib/class.hxx>

namespace Gio
{

  class GIOMM_API TlsDatabase_Class : public Glib::Class
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    using CppObjectType = TlsDatabase;
    using BaseObjectType = GTlsDatabase;
    using BaseClassType = GTlsDatabaseClass;
    using CppClassParent = Glib::Object_Class;
    using BaseClassParent = GObjectClass;

    friend class TlsDatabase;
#endif

    auto
    init () -> const Class&;

    static auto
    class_init_function (void* g_class, void* class_data) -> void;

    static auto
    wrap_new (GObject*) -> Glib::ObjectBase*;

  protected:
    static auto
    verify_chain_vfunc_callback (GTlsDatabase* self,
                                 GTlsCertificate* chain,
                                 const gchar* purpose,
                                 GSocketConnectable* identity,
                                 GTlsInteraction* interaction,
                                 GTlsDatabaseVerifyFlags flags,
                                 GCancellable* cancellable,
                                 GError** error) -> GTlsCertificateFlags;
    static auto
    verify_chain_async_vfunc_callback (GTlsDatabase* self,
                                       GTlsCertificate* chain,
                                       const gchar* purpose,
                                       GSocketConnectable* identity,
                                       GTlsInteraction* interaction,
                                       GTlsDatabaseVerifyFlags flags,
                                       GCancellable* cancellable,
                                       GAsyncReadyCallback callback,
                                       gpointer user_data) -> void;
    static auto
    verify_chain_finish_vfunc_callback (GTlsDatabase* self,
                                        GAsyncResult* result,
                                        GError** error) -> GTlsCertificateFlags;
    static auto
    create_certificate_handle_vfunc_callback (GTlsDatabase* self,
                                              GTlsCertificate* certificate)
        -> gchar*;
    static auto
    lookup_certificate_for_handle_vfunc_callback (GTlsDatabase* self,
                                                  const gchar* handle,
                                                  GTlsInteraction* interaction,
                                                  GTlsDatabaseLookupFlags flags,
                                                  GCancellable* cancellable,
                                                  GError** error)
        -> GTlsCertificate*;
    static auto
    lookup_certificate_for_handle_async_vfunc_callback (
        GTlsDatabase* self,
        const gchar* handle,
        GTlsInteraction* interaction,
        GTlsDatabaseLookupFlags flags,
        GCancellable* cancellable,
        GAsyncReadyCallback callback,
        gpointer user_data) -> void;
    static auto
    lookup_certificate_for_handle_finish_vfunc_callback (GTlsDatabase* self,
                                                         GAsyncResult* result,
                                                         GError** error)
        -> GTlsCertificate*;
    static auto
    lookup_certificate_issuer_vfunc_callback (GTlsDatabase* self,
                                              GTlsCertificate* certificate,
                                              GTlsInteraction* interaction,
                                              GTlsDatabaseLookupFlags flags,
                                              GCancellable* cancellable,
                                              GError** error)
        -> GTlsCertificate*;
    static auto
    lookup_certificate_issuer_async_vfunc_callback (
        GTlsDatabase* self,
        GTlsCertificate* certificate,
        GTlsInteraction* interaction,
        GTlsDatabaseLookupFlags flags,
        GCancellable* cancellable,
        GAsyncReadyCallback callback,
        gpointer user_data) -> void;
    static auto
    lookup_certificate_issuer_finish_vfunc_callback (GTlsDatabase* self,
                                                     GAsyncResult* result,
                                                     GError** error)
        -> GTlsCertificate*;
    static auto
    lookup_certificates_issued_by_vfunc_callback (GTlsDatabase* self,
                                                  GByteArray* issuer_raw_dn,
                                                  GTlsInteraction* interaction,
                                                  GTlsDatabaseLookupFlags flags,
                                                  GCancellable* cancellable,
                                                  GError** error) -> GList*;
    static auto
    lookup_certificates_issued_by_async_vfunc_callback (
        GTlsDatabase* self,
        GByteArray* issuer_raw_dn,
        GTlsInteraction* interaction,
        GTlsDatabaseLookupFlags flags,
        GCancellable* cancellable,
        GAsyncReadyCallback callback,
        gpointer user_data) -> void;
    static auto
    lookup_certificates_issued_by_finish_vfunc_callback (GTlsDatabase* self,
                                                         GAsyncResult* result,
                                                         GError** error)
        -> GList*;
  };

} // namespace Gio

#endif
