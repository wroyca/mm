// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/gio/tlsconnection.hxx>
#include <libmm/gio/tlsconnection_p.hxx>

#include <gio/gio.h>
#include <libmm/gio/cancellable.hxx>
#include <libmm/gio/slot_async.hxx>
#include <libmm/gio/tlsclientconnectionimpl.hxx>
#include <libmm/gio/tlsdatabase.hxx>
#include <libmm/gio/tlsinteraction.hxx>
#include <libmm/gio/tlsserverconnectionimpl.hxx>

namespace Gio
{

  auto
  TlsConnection_Class::wrap_new (GObject* object) -> Glib::ObjectBase*
  {
    if (G_IS_TLS_CLIENT_CONNECTION (object))
      return new TlsClientConnectionImpl ((GTlsConnection*) object);
    if (G_IS_TLS_SERVER_CONNECTION (object))
      return new TlsServerConnectionImpl ((GTlsConnection*) object);
    return new TlsConnection ((GTlsConnection*) object);
  }

} // namespace Gio

namespace
{

  auto
  TlsConnection_signal_accept_certificate_callback (GTlsConnection* self,
                                                    GTlsCertificate* p0,
                                                    GTlsCertificateFlags p1,
                                                    void* data) -> gboolean
  {
    using namespace Gio;
    using SlotType = sigc::slot<bool (const Glib::RefPtr<const TlsCertificate>&,
                                      TlsCertificateFlags)>;

    const auto obj = dynamic_cast<TlsConnection*> (
        Glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj)
    {
      try
      {
        if (const auto slot = Glib::SignalProxyNormal::data_to_slot (data))
          return (*static_cast<SlotType*> (slot)) (
              Glib::wrap (p0, true),
              static_cast<TlsCertificateFlags> (p1));
      }
      catch (...)
      {
        Glib::exception_handlers_invoke ();
      }
    }

    using RType = gboolean;
    return RType ();
  }

  auto
  TlsConnection_signal_accept_certificate_notify_callback (
      GTlsConnection* self,
      GTlsCertificate* p0,
      GTlsCertificateFlags p1,
      void* data) -> gboolean
  {
    using namespace Gio;
    using SlotType = sigc::slot<void (const Glib::RefPtr<const TlsCertificate>&,
                                      TlsCertificateFlags)>;

    const auto obj = dynamic_cast<TlsConnection*> (
        Glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj)
    {
      try
      {
        if (const auto slot = Glib::SignalProxyNormal::data_to_slot (data))
          (*static_cast<SlotType*> (slot)) (
              Glib::wrap (p0, true),
              static_cast<TlsCertificateFlags> (p1));
      }
      catch (...)
      {
        Glib::exception_handlers_invoke ();
      }
    }

    using RType = gboolean;
    return RType ();
  }

  const Glib::SignalProxyInfo TlsConnection_signal_accept_certificate_info = {
      "accept_certificate",
      (GCallback) &TlsConnection_signal_accept_certificate_callback,
      (GCallback) &TlsConnection_signal_accept_certificate_notify_callback};

} // namespace

auto
Glib::Value<Gio::TlsProtocolVersion>::value_type () -> GType
{
  return g_tls_protocol_version_get_type ();
}

namespace Glib
{

  auto
  wrap (GTlsConnection* object, const bool take_copy) -> RefPtr<Gio::TlsConnection>
  {
    return Glib::make_refptr_for_instance<Gio::TlsConnection> (
        dynamic_cast<Gio::TlsConnection*> (
            wrap_auto ((GObject*) object, take_copy)));
  }

} // namespace Glib

namespace Gio
{

  auto
  TlsConnection_Class::init () -> const Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &TlsConnection_Class::class_init_function;

      register_derived_type (g_tls_connection_get_type ());
    }

    return *this;
  }

  auto
  TlsConnection_Class::class_init_function (void* g_class, void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);

    klass->handshake = &handshake_vfunc_callback;
    klass->handshake_async = &handshake_async_vfunc_callback;
    klass->handshake_finish = &handshake_finish_vfunc_callback;

    klass->accept_certificate = &accept_certificate_callback;
  }

  auto
  TlsConnection_Class::handshake_vfunc_callback (GTlsConnection* self,
                                                 GCancellable* cancellable,
                                                 GError** error) -> gboolean
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
          return obj->handshake_vfunc (Glib::wrap (cancellable));
        }
        catch (Glib::Error& errormm)
        {
          errormm.propagate (error);
          using RType = gboolean;
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

    if (base && base->handshake)
      return (*base->handshake) (self, cancellable, error);

    using RType = gboolean;
    return RType ();
  }

  auto
  TlsConnection_Class::handshake_async_vfunc_callback (
      GTlsConnection* self,
      const int io_priority,
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
          obj->handshake_async_vfunc (*slot,
                                      Glib::wrap (cancellable),
                                      io_priority);
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

    if (base && base->handshake_async)
      (*base->handshake_async) (self,
                                io_priority,
                                cancellable,
                                callback,
                                user_data);
  }

  auto
  TlsConnection_Class::handshake_finish_vfunc_callback (GTlsConnection* self,
                                                        GAsyncResult* result,
                                                        GError** error) -> gboolean
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
          return obj->handshake_finish_vfunc (Glib::wrap (result, true));
        }
        catch (Glib::Error& errormm)
        {
          errormm.propagate (error);
          using RType = gboolean;
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

    if (base && base->handshake_finish)
      return (*base->handshake_finish) (self, result, error);

    using RType = gboolean;
    return RType ();
  }

  auto
  TlsConnection_Class::accept_certificate_callback (GTlsConnection* self,
                                                    GTlsCertificate* p0,
                                                    GTlsCertificateFlags p1) -> gboolean
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
          return obj->on_accept_certificate (
              Glib::wrap (p0, true),
              static_cast<TlsCertificateFlags> (p1));
        }
        catch (...)
        {
          Glib::exception_handlers_invoke ();
        }
      }
    }

    const auto base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (self)));

    if (base && base->accept_certificate)
      return (*base->accept_certificate) (self, p0, p1);

    using RType = gboolean;
    return RType ();
  }

  auto
  TlsConnection::gobj_copy () -> GTlsConnection*
  {
    reference ();
    return gobj ();
  }

  TlsConnection::TlsConnection (const Glib::ConstructParams& construct_params)
    : IOStream (construct_params)
  {
  }

  TlsConnection::TlsConnection (GTlsConnection* castitem)
    : IOStream ((GIOStream*) castitem)
  {
  }

  TlsConnection::TlsConnection (TlsConnection&& src) noexcept
    : IOStream (std::move (src))
  {
  }

  auto
  TlsConnection::operator= (TlsConnection&& src) noexcept -> TlsConnection&
  {
    IOStream::operator= (std::move (src));
    return *this;
  }

  TlsConnection::~TlsConnection () noexcept = default;

  TlsConnection::CppClassType TlsConnection::tlsconnection_class_;

  auto
  TlsConnection::get_type () -> GType
  {
    return tlsconnection_class_.init ().get_type ();
  }

  auto
  TlsConnection::get_base_type () -> GType
  {
    return g_tls_connection_get_type ();
  }

  TlsConnection::TlsConnection ()
    : ObjectBase (nullptr),
      IOStream (Glib::ConstructParams (tlsconnection_class_.init ()))
  {
  }

  auto
  TlsConnection::set_certificate (
      const Glib::RefPtr<TlsCertificate>& certificate) -> void
  {
    g_tls_connection_set_certificate (gobj (), Glib::unwrap (certificate));
  }

  auto
  TlsConnection::get_certificate () -> Glib::RefPtr<TlsCertificate>
  {
    auto retvalue = Glib::wrap (g_tls_connection_get_certificate (gobj ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  TlsConnection::get_certificate () const -> Glib::RefPtr<const TlsCertificate>
  {
    return const_cast<TlsConnection*> (this)->get_certificate ();
  }

  auto
  TlsConnection::get_peer_certificate () -> Glib::RefPtr<TlsCertificate>
  {
    auto retvalue =
        Glib::wrap (g_tls_connection_get_peer_certificate (gobj ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  TlsConnection::get_peer_certificate () const -> Glib::RefPtr<const TlsCertificate>
  {
    return const_cast<TlsConnection*> (this)->get_peer_certificate ();
  }

  auto
  TlsConnection::get_peer_certificate_errors () const -> TlsCertificateFlags
  {
    return static_cast<TlsCertificateFlags> (
        g_tls_connection_get_peer_certificate_errors (
            const_cast<GTlsConnection*> (gobj ())));
  }

  auto
  TlsConnection::set_require_close_notify (const bool require_close_notify) -> void
  {
    g_tls_connection_set_require_close_notify (gobj (), require_close_notify);
  }

  auto
  TlsConnection::get_require_close_notify () const -> bool
  {
    return g_tls_connection_get_require_close_notify (
        const_cast<GTlsConnection*> (gobj ()));
  }

  auto
  TlsConnection::get_database () -> Glib::RefPtr<TlsDatabase>
  {
    return Glib::wrap (g_tls_connection_get_database (gobj ()));
  }

  auto
  TlsConnection::get_database () const -> Glib::RefPtr<const TlsDatabase>
  {
    return const_cast<TlsConnection*> (this)->get_database ();
  }

  auto
  TlsConnection::set_database (const Glib::RefPtr<TlsDatabase>& database) -> void
  {
    g_tls_connection_set_database (gobj (), Glib::unwrap (database));
  }

  auto
  TlsConnection::get_interaction () -> Glib::RefPtr<TlsInteraction>
  {
    return Glib::wrap (g_tls_connection_get_interaction (gobj ()));
  }

  auto
  TlsConnection::get_interaction () const -> Glib::RefPtr<const TlsInteraction>
  {
    return const_cast<TlsConnection*> (this)->get_interaction ();
  }

  auto
  TlsConnection::set_interaction (
      const Glib::RefPtr<TlsInteraction>& interaction) -> void
  {
    g_tls_connection_set_interaction (gobj (), Glib::unwrap (interaction));
  }

  auto
  TlsConnection::handshake (const Glib::RefPtr<Cancellable>& cancellable) -> bool
  {
    GError* gerror = nullptr;
    const auto retvalue = g_tls_connection_handshake (
        gobj (),
        Glib::unwrap (cancellable),
        &gerror);
    if (gerror)
      Glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  TlsConnection::handshake () -> bool
  {
    GError* gerror = nullptr;
    const auto retvalue =
        g_tls_connection_handshake (gobj (), nullptr, &gerror);
    if (gerror)
      Glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  TlsConnection::handshake_async (const SlotAsyncReady& slot,
                                  const Glib::RefPtr<Cancellable>& cancellable,
                                  const int io_priority) -> void
  {
    const auto slot_copy = new SlotAsyncReady (slot);

    g_tls_connection_handshake_async (gobj (),
                                      io_priority,
                                      Glib::unwrap (cancellable),
                                      &SignalProxy_async_callback,
                                      slot_copy);
  }

  auto
  TlsConnection::handshake_async (const SlotAsyncReady& slot,
                                  const int io_priority) -> void
  {
    const auto slot_copy = new SlotAsyncReady (slot);

    g_tls_connection_handshake_async (gobj (),
                                      io_priority,
                                      nullptr,
                                      &SignalProxy_async_callback,
                                      slot_copy);
  }

  auto
  TlsConnection::handshake_finish (const Glib::RefPtr<AsyncResult>& result) -> bool
  {
    GError* gerror = nullptr;
    const auto retvalue = g_tls_connection_handshake_finish (
        gobj (),
        Glib::unwrap (result),
        &gerror);
    if (gerror)
      Glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  TlsConnection::get_protocol_version () const -> TlsProtocolVersion
  {
    return static_cast<TlsProtocolVersion> (
        g_tls_connection_get_protocol_version (
            const_cast<GTlsConnection*> (gobj ())));
  }

  auto
  TlsConnection::get_ciphersuite_name () const -> Glib::ustring
  {
    return Glib::convert_return_gchar_ptr_to_ustring (
        g_tls_connection_get_ciphersuite_name (
            const_cast<GTlsConnection*> (gobj ())));
  }

  auto
  TlsConnection::emit_accept_certificate (
      const Glib::RefPtr<const TlsCertificate>& peer_cert,
      TlsCertificateFlags errors) -> bool
  {
    return g_tls_connection_emit_accept_certificate (
        gobj (),
        const_cast<GTlsCertificate*> (Glib::unwrap (peer_cert)),
        static_cast<GTlsCertificateFlags> (errors));
  }

  auto
  TlsConnection::signal_accept_certificate () -> Glib::SignalProxy<bool (const Glib::RefPtr<const TlsCertificate>&,
                                 TlsCertificateFlags)>
  {
    return {this, &TlsConnection_signal_accept_certificate_info};
  }

  static_assert (
      Glib::Traits::ValueCompatibleWithWrapProperty<
          Glib::RefPtr<IOStream>>::value,
      "Type Glib::RefPtr<IOStream> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  auto
  TlsConnection::property_base_io_stream () const -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<IOStream>>
  {
    return {this, "base-io-stream"};
  }

  static_assert (
      Glib::Traits::ValueCompatibleWithWrapProperty<
          Glib::RefPtr<TlsCertificate>>::value,
      "Type Glib::RefPtr<TlsCertificate> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  auto
  TlsConnection::property_certificate () -> Glib::PropertyProxy<Glib::RefPtr<TlsCertificate>>
  {
    return {this, "certificate"};
  }

  auto
  TlsConnection::property_certificate () const -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<TlsCertificate>>
  {
    return {this, "certificate"};
  }

  static_assert (
      Glib::Traits::ValueCompatibleWithWrapProperty<
          Glib::RefPtr<TlsDatabase>>::value,
      "Type Glib::RefPtr<TlsDatabase> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  auto
  TlsConnection::property_database () -> Glib::PropertyProxy<Glib::RefPtr<TlsDatabase>>
  {
    return {this, "database"};
  }

  auto
  TlsConnection::property_database () const -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<TlsDatabase>>
  {
    return {this, "database"};
  }

  static_assert (
      Glib::Traits::ValueCompatibleWithWrapProperty<
          Glib::RefPtr<TlsInteraction>>::value,
      "Type Glib::RefPtr<TlsInteraction> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  auto
  TlsConnection::property_interaction () -> Glib::PropertyProxy<Glib::RefPtr<TlsInteraction>>
  {
    return {this, "interaction"};
  }

  auto
  TlsConnection::property_interaction () const -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<TlsInteraction>>
  {
    return {this, "interaction"};
  }

  static_assert (
      Glib::Traits::ValueCompatibleWithWrapProperty<
          Glib::RefPtr<TlsCertificate>>::value,
      "Type Glib::RefPtr<TlsCertificate> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  auto
  TlsConnection::property_peer_certificate () const -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<TlsCertificate>>
  {
    return {this, "peer-certificate"};
  }

  static_assert (
      Glib::Traits::ValueCompatibleWithWrapProperty<TlsCertificateFlags>::value,
      "Type TlsCertificateFlags cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  auto
  TlsConnection::property_peer_certificate_errors () const -> Glib::PropertyProxy_ReadOnly<TlsCertificateFlags>
  {
    return {this, "peer-certificate-errors"};
  }

  auto
  TlsConnection::property_require_close_notify () -> Glib::PropertyProxy<bool>
  {
    return {this, "require-close-notify"};
  }

  auto
  TlsConnection::property_require_close_notify () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return {this, "require-close-notify"};
  }

  static_assert (
      Glib::Traits::ValueCompatibleWithWrapProperty<TlsProtocolVersion>::value,
      "Type TlsProtocolVersion cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  auto
  TlsConnection::property_protocol_version () const -> Glib::PropertyProxy_ReadOnly<TlsProtocolVersion>
  {
    return {this, "protocol-version"};
  }

  auto
  TlsConnection::property_ciphersuite_name () const -> Glib::PropertyProxy_ReadOnly<Glib::ustring>
  {
    return {this, "ciphersuite-name"};
  }

  auto
  TlsConnection::on_accept_certificate (
      const Glib::RefPtr<const TlsCertificate>& peer_cert,
      TlsCertificateFlags errors) -> bool
  {
    const auto base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (gobject_)));

    if (base && base->accept_certificate)
      return (*base->accept_certificate) (
          gobj (),
          const_cast<GTlsCertificate*> (Glib::unwrap (peer_cert)),
          static_cast<GTlsCertificateFlags> (errors));

    using RType = bool;
    return RType ();
  }

  auto
  TlsConnection::handshake_vfunc (const Glib::RefPtr<Cancellable>& cancellable) -> bool
  {
    const auto base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (gobject_)));

    if (base && base->handshake)
    {
      GError* gerror = nullptr;
      const bool retval (
          (*base->handshake) (gobj (), Glib::unwrap (cancellable), &gerror));
      if (gerror)
        Glib::Error::throw_exception (gerror);
      return retval;
    }

    using RType = bool;
    return RType ();
  }

  auto
  TlsConnection::handshake_async_vfunc (
      const SlotAsyncReady& slot,
      const Glib::RefPtr<Cancellable>& cancellable,
      const int io_priority) -> void
  {
    const auto slot_copy = new SlotAsyncReady (slot);

    const auto base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (gobject_)));

    if (base && base->handshake_async)
    {
      (*base->handshake_async) (gobj (),
                                io_priority,
                                Glib::unwrap (cancellable),
                                &SignalProxy_async_callback,
                                slot_copy);
    }
  }

  auto
  TlsConnection::handshake_finish_vfunc (
      const Glib::RefPtr<AsyncResult>& result) -> bool
  {
    const auto base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (gobject_)));

    if (base && base->handshake_finish)
    {
      GError* gerror = nullptr;
      const bool retval (
          (*base->handshake_finish) (gobj (), Glib::unwrap (result), &gerror));
      if (gerror)
        Glib::Error::throw_exception (gerror);
      return retval;
    }

    using RType = bool;
    return RType ();
  }

} // namespace Gio