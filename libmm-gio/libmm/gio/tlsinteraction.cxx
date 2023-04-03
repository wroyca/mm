// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/gio/tlsinteraction.hxx>
#include <libmm/gio/tlsinteraction_p.hxx>

#include <gio/gio.h>
#include <libmm/gio/cancellable.hxx>
#include <libmm/gio/slot_async.hxx>
#include <libmm/gio/tlspassword.hxx>

namespace
{
}

auto
Glib::Value<Gio::TlsInteractionResult>::value_type () -> GType
{
  return g_tls_interaction_result_get_type ();
}

auto
Glib::Value<Gio::TlsCertificateRequestFlags>::value_type () -> GType
{
  return g_tls_certificate_request_flags_get_type ();
}

namespace Glib
{

  auto
  wrap (GTlsInteraction* object, const bool take_copy) -> RefPtr<Gio::TlsInteraction>
  {
    return Glib::make_refptr_for_instance<Gio::TlsInteraction> (
        dynamic_cast<Gio::TlsInteraction*> (
            wrap_auto ((GObject*) object, take_copy)));
  }

} // namespace Glib

namespace Gio
{

  auto
  TlsInteraction_Class::init () -> const Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &TlsInteraction_Class::class_init_function;

      register_derived_type (g_tls_interaction_get_type ());
    }

    return *this;
  }

  auto
  TlsInteraction_Class::class_init_function (void* g_class, void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);

    klass->ask_password = &ask_password_vfunc_callback;
    klass->ask_password_async = &ask_password_async_vfunc_callback;
    klass->ask_password_finish = &ask_password_finish_vfunc_callback;
  }

  auto
  TlsInteraction_Class::ask_password_vfunc_callback (GTlsInteraction* self,
                                                     GTlsPassword* password,
                                                     GCancellable* cancellable,
                                                     GError** error) -> GTlsInteractionResult
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
          return static_cast<GTlsInteractionResult> (
              obj->ask_password_vfunc (Glib::wrap (password, true),
                                       Glib::wrap (cancellable)));
        }
        catch (Glib::Error& errormm)
        {
          errormm.propagate (error);
          using RType = GTlsInteractionResult;
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

    if (base && base->ask_password)
      return (*base->ask_password) (self, password, cancellable, error);

    using RType = GTlsInteractionResult;
    return RType ();
  }

  auto
  TlsInteraction_Class::ask_password_async_vfunc_callback (
      GTlsInteraction* self,
      GTlsPassword* password,
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
          obj->ask_password_async_vfunc (Glib::wrap (password, true),
                                         *slot,
                                         Glib::wrap (cancellable));
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

    if (base && base->ask_password_async)
      (*base->ask_password_async) (self,
                                   password,
                                   cancellable,
                                   callback,
                                   user_data);
  }

  auto
  TlsInteraction_Class::ask_password_finish_vfunc_callback (
      GTlsInteraction* self,
      GAsyncResult* result,
      GError** error) -> GTlsInteractionResult
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
          return static_cast<GTlsInteractionResult> (
              obj->ask_password_finish_vfunc (Glib::wrap (result, true)));
        }
        catch (Glib::Error& errormm)
        {
          errormm.propagate (error);
          using RType = GTlsInteractionResult;
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

    if (base && base->ask_password_finish)
      return (*base->ask_password_finish) (self, result, error);

    using RType = GTlsInteractionResult;
    return RType ();
  }

  auto
  TlsInteraction_Class::wrap_new (GObject* object) -> Glib::ObjectBase*
  {
    return new TlsInteraction ((GTlsInteraction*) object);
  }

  auto
  TlsInteraction::gobj_copy () -> GTlsInteraction*
  {
    reference ();
    return gobj ();
  }

  TlsInteraction::TlsInteraction (const Glib::ConstructParams& construct_params)
    : Object (construct_params)
  {
  }

  TlsInteraction::TlsInteraction (GTlsInteraction* castitem)
    : Object ((GObject*) castitem)
  {
  }

  TlsInteraction::TlsInteraction (TlsInteraction&& src) noexcept
    : Object (std::move (src))
  {
  }

  auto
  TlsInteraction::operator= (TlsInteraction&& src) noexcept -> TlsInteraction&
  {
    Object::operator= (std::move (src));
    return *this;
  }

  TlsInteraction::~TlsInteraction () noexcept = default;

  TlsInteraction::CppClassType TlsInteraction::tlsinteraction_class_;

  auto
  TlsInteraction::get_type () -> GType
  {
    return tlsinteraction_class_.init ().get_type ();
  }

  auto
  TlsInteraction::get_base_type () -> GType
  {
    return g_tls_interaction_get_type ();
  }

  TlsInteraction::TlsInteraction ()
    : ObjectBase (nullptr),
      Object (Glib::ConstructParams (tlsinteraction_class_.init ()))
  {
  }

  auto
  TlsInteraction::ask_password (const Glib::RefPtr<TlsPassword>& password,
                                const Glib::RefPtr<Cancellable>& cancellable) -> TlsInteractionResult
  {
    GError* gerror = nullptr;
    const auto retvalue = static_cast<TlsInteractionResult> (
        g_tls_interaction_ask_password (gobj (),
                                        Glib::unwrap (password),
                                        Glib::unwrap (cancellable),
                                        &gerror));
    if (gerror)
      Glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  TlsInteraction::ask_password (const Glib::RefPtr<TlsPassword>& password) -> TlsInteractionResult
  {
    GError* gerror = nullptr;
    const auto retvalue = static_cast<TlsInteractionResult> (
        g_tls_interaction_ask_password (gobj (),
                                        Glib::unwrap (password),
                                        nullptr,
                                        &gerror));
    if (gerror)
      Glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  TlsInteraction::ask_password_async (
      const Glib::RefPtr<TlsPassword>& password,
      const SlotAsyncReady& slot,
      const Glib::RefPtr<Cancellable>& cancellable) -> void
  {
    const auto slot_copy = new SlotAsyncReady (slot);

    g_tls_interaction_ask_password_async (gobj (),
                                          Glib::unwrap (password),
                                          Glib::unwrap (cancellable),
                                          &SignalProxy_async_callback,
                                          slot_copy);
  }

  auto
  TlsInteraction::ask_password_async (const Glib::RefPtr<TlsPassword>& password,
                                      const SlotAsyncReady& slot) -> void
  {
    const auto slot_copy = new SlotAsyncReady (slot);

    g_tls_interaction_ask_password_async (gobj (),
                                          Glib::unwrap (password),
                                          nullptr,
                                          &SignalProxy_async_callback,
                                          slot_copy);
  }

  auto
  TlsInteraction::ask_password_async (
      const Glib::RefPtr<TlsPassword>& password,
      const Glib::RefPtr<Cancellable>& cancellable) -> void
  {
    g_tls_interaction_ask_password_async (gobj (),
                                          Glib::unwrap (password),
                                          Glib::unwrap (cancellable),
                                          nullptr,
                                          nullptr);
  }

  auto
  TlsInteraction::ask_password_async (const Glib::RefPtr<TlsPassword>& password) -> void
  {
    g_tls_interaction_ask_password_async (gobj (),
                                          Glib::unwrap (password),
                                          nullptr,
                                          nullptr,
                                          nullptr);
  }

  auto
  TlsInteraction::ask_password_finish (const Glib::RefPtr<AsyncResult>& result) -> TlsInteractionResult
  {
    GError* gerror = nullptr;
    const auto retvalue = static_cast<TlsInteractionResult> (
        g_tls_interaction_ask_password_finish (gobj (),
                                               Glib::unwrap (result),
                                               &gerror));
    if (gerror)
      Glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  TlsInteraction::invoke_ask_password (
      const Glib::RefPtr<TlsPassword>& password,
      const Glib::RefPtr<Cancellable>& cancellable) -> TlsInteractionResult
  {
    GError* gerror = nullptr;
    const auto retvalue = static_cast<TlsInteractionResult> (
        g_tls_interaction_invoke_ask_password (gobj (),
                                               Glib::unwrap (password),
                                               Glib::unwrap (cancellable),
                                               &gerror));
    if (gerror)
      Glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  TlsInteraction::invoke_ask_password (
      const Glib::RefPtr<TlsPassword>& password) -> TlsInteractionResult
  {
    GError* gerror = nullptr;
    const auto retvalue = static_cast<TlsInteractionResult> (
        g_tls_interaction_invoke_ask_password (gobj (),
                                               Glib::unwrap (password),
                                               nullptr,
                                               &gerror));
    if (gerror)
      Glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  TlsInteraction::invoke_request_certificate (
      const Glib::RefPtr<TlsConnection>& connection,
      TlsCertificateRequestFlags flags,
      const Glib::RefPtr<Cancellable>& cancellable) -> TlsInteractionResult
  {
    GError* gerror = nullptr;
    const auto retvalue = static_cast<TlsInteractionResult> (
        g_tls_interaction_invoke_request_certificate (
            gobj (),
            Glib::unwrap (connection),
            static_cast<GTlsCertificateRequestFlags> (flags),
            Glib::unwrap (cancellable),
            &gerror));
    if (gerror)
      Glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  TlsInteraction::invoke_request_certificate (
      const Glib::RefPtr<TlsConnection>& connection,
      TlsCertificateRequestFlags flags) -> TlsInteractionResult
  {
    GError* gerror = nullptr;
    const auto retvalue = static_cast<TlsInteractionResult> (
        g_tls_interaction_invoke_request_certificate (
            gobj (),
            Glib::unwrap (connection),
            static_cast<GTlsCertificateRequestFlags> (flags),
            nullptr,
            &gerror));
    if (gerror)
      Glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  TlsInteraction::request_certificate (
      const Glib::RefPtr<TlsConnection>& connection,
      TlsCertificateRequestFlags flags,
      const Glib::RefPtr<Cancellable>& cancellable) -> TlsInteractionResult
  {
    GError* gerror = nullptr;
    const auto retvalue = static_cast<TlsInteractionResult> (
        g_tls_interaction_request_certificate (
            gobj (),
            Glib::unwrap (connection),
            static_cast<GTlsCertificateRequestFlags> (flags),
            Glib::unwrap (cancellable),
            &gerror));
    if (gerror)
      Glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  TlsInteraction::request_certificate (
      const Glib::RefPtr<TlsConnection>& connection,
      TlsCertificateRequestFlags flags) -> TlsInteractionResult
  {
    GError* gerror = nullptr;
    const auto retvalue = static_cast<TlsInteractionResult> (
        g_tls_interaction_request_certificate (
            gobj (),
            Glib::unwrap (connection),
            static_cast<GTlsCertificateRequestFlags> (flags),
            nullptr,
            &gerror));
    if (gerror)
      Glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  TlsInteraction::request_certificate_async (
      const Glib::RefPtr<TlsConnection>& connection,
      TlsCertificateRequestFlags flags,
      const SlotAsyncReady& slot,
      const Glib::RefPtr<Cancellable>& cancellable) -> void
  {
    const auto slot_copy = new SlotAsyncReady (slot);

    g_tls_interaction_request_certificate_async (
        gobj (),
        Glib::unwrap (connection),
        static_cast<GTlsCertificateRequestFlags> (flags),
        Glib::unwrap (cancellable),
        &SignalProxy_async_callback,
        slot_copy);
  }

  auto
  TlsInteraction::request_certificate_async (
      const Glib::RefPtr<TlsConnection>& connection,
      TlsCertificateRequestFlags flags,
      const SlotAsyncReady& slot) -> void
  {
    const auto slot_copy = new SlotAsyncReady (slot);

    g_tls_interaction_request_certificate_async (
        gobj (),
        Glib::unwrap (connection),
        static_cast<GTlsCertificateRequestFlags> (flags),
        nullptr,
        &SignalProxy_async_callback,
        slot_copy);
  }

  auto
  TlsInteraction::request_certificate_async (
      const Glib::RefPtr<TlsConnection>& connection,
      TlsCertificateRequestFlags flags,
      const Glib::RefPtr<Cancellable>& cancellable) -> void
  {
    g_tls_interaction_request_certificate_async (
        gobj (),
        Glib::unwrap (connection),
        static_cast<GTlsCertificateRequestFlags> (flags),
        Glib::unwrap (cancellable),
        nullptr,
        nullptr);
  }

  auto
  TlsInteraction::request_certificate_async (
      const Glib::RefPtr<TlsConnection>& connection,
      TlsCertificateRequestFlags flags) -> void
  {
    g_tls_interaction_request_certificate_async (
        gobj (),
        Glib::unwrap (connection),
        static_cast<GTlsCertificateRequestFlags> (flags),
        nullptr,
        nullptr,
        nullptr);
  }

  auto
  TlsInteraction::request_certificate_finish (
      const Glib::RefPtr<AsyncResult>& result) -> TlsInteractionResult
  {
    GError* gerror = nullptr;
    const auto retvalue = static_cast<TlsInteractionResult> (
        g_tls_interaction_request_certificate_finish (gobj (),
                                                      Glib::unwrap (result),
                                                      &gerror));
    if (gerror)
      Glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  TlsInteraction::ask_password_vfunc (
      const Glib::RefPtr<TlsPassword>& password,
      const Glib::RefPtr<Cancellable>& cancellable) -> TlsInteractionResult
  {
    const auto base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (gobject_)));

    if (base && base->ask_password)
    {
      GError* gerror = nullptr;
      const TlsInteractionResult retval (static_cast<TlsInteractionResult> (
          (*base->ask_password) (gobj (),
                                 Glib::unwrap (password),
                                 Glib::unwrap (cancellable),
                                 &gerror)));
      if (gerror)
        Glib::Error::throw_exception (gerror);
      return retval;
    }

    using RType = TlsInteractionResult;
    return RType ();
  }

  auto
  TlsInteraction::ask_password_async_vfunc (
      const Glib::RefPtr<TlsPassword>& password,
      const SlotAsyncReady& slot,
      const Glib::RefPtr<Cancellable>& cancellable) -> void
  {
    const auto slot_copy = new SlotAsyncReady (slot);

    const auto base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (gobject_)));

    if (base && base->ask_password_async)
    {
      (*base->ask_password_async) (gobj (),
                                   Glib::unwrap (password),
                                   Glib::unwrap (cancellable),
                                   &SignalProxy_async_callback,
                                   slot_copy);
    }
  }

  auto
  TlsInteraction::ask_password_finish_vfunc (
      const Glib::RefPtr<AsyncResult>& result) -> TlsInteractionResult
  {
    const auto base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (gobject_)));

    if (base && base->ask_password_finish)
    {
      GError* gerror = nullptr;
      const TlsInteractionResult retval (static_cast<TlsInteractionResult> (
          (*base->ask_password_finish) (gobj (),
                                        Glib::unwrap (result),
                                        &gerror)));
      if (gerror)
        Glib::Error::throw_exception (gerror);
      return retval;
    }

    using RType = TlsInteractionResult;
    return RType ();
  }

} // namespace Gio
