// Generated by gmmproc 2.74.0 -- DO NOT MODIFY!


#include <mm/glib/mm-glib.h>

#include <mm/gio/tlsinteraction.h>
#include <mm/gio/private/tlsinteraction_p.h>


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
#include <mm/gio/cancellable.h>
#include <mm/gio/tlspassword.h>
#include <mm/gio/slot_async.h>

namespace
{
} // anonymous namespace

// static
auto Glib::Value<Gio::TlsInteractionResult>::value_type() -> GType
{
  return g_tls_interaction_result_get_type();
}

// static
auto Glib::Value<Gio::TlsCertificateRequestFlags>::value_type() -> GType
{
  return g_tls_certificate_request_flags_get_type();
}


namespace Glib
{

auto wrap(GTlsInteraction* object, bool take_copy) -> Glib::RefPtr<Gio::TlsInteraction>
{
  return Glib::make_refptr_for_instance<Gio::TlsInteraction>( dynamic_cast<Gio::TlsInteraction*> (Glib::wrap_auto ((GObject*)(object), take_copy)) );
  //We use dynamic_cast<> in case of multiple inheritance.
}

} /* namespace Glib */


namespace Gio
{


/* The *_Class implementation: */

auto TlsInteraction_Class::init() -> const Glib::Class&
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Class has to know the class init function to clone custom types.
    class_init_func_ = &TlsInteraction_Class::class_init_function;

    // This is actually just optimized away, apparently with no harm.
    // Make sure that the parent type has been created.
    //CppClassParent::CppObjectType::get_type();

    // Create the wrapper type, with the same class/instance size as the base type.
    register_derived_type(g_tls_interaction_get_type());

    // Add derived versions of interfaces, if the C type implements any interfaces:

  }

  return *this;
}


void TlsInteraction_Class::class_init_function(void* g_class, void* class_data)
{
  const auto klass = static_cast<BaseClassType*>(g_class);
  CppClassParent::class_init_function(klass, class_data);

  klass->ask_password = &ask_password_vfunc_callback;
  klass->ask_password_async = &ask_password_async_vfunc_callback;
  klass->ask_password_finish = &ask_password_finish_vfunc_callback;

}

auto TlsInteraction_Class::ask_password_vfunc_callback(GTlsInteraction* self, GTlsPassword* password, GCancellable* cancellable, GError** error) -> GTlsInteractionResult
{
  const auto obj_base = static_cast<Glib::ObjectBase*>(
      Glib::ObjectBase::_get_current_wrapper((GObject*)self));

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
        return static_cast<GTlsInteractionResult>(obj->ask_password_vfunc(Glib::wrap(password, true)
, Glib::wrap(cancellable)
));
      }
      catch(Glib::Error& errormm)
      {
        errormm.propagate(error);
        using RType = GTlsInteractionResult;
        return RType();
      }
      catch(...)
      {
        Glib::exception_handlers_invoke();
      }
    }
  }

  BaseClassType *const base = static_cast<BaseClassType*>(
      g_type_class_peek_parent(G_OBJECT_GET_CLASS(self)) // Get the parent class of the object class (The original underlying C class).
  );

  // Call the original underlying C function:
  if(base && base->ask_password)
    return (*base->ask_password)(self, password, cancellable, error);

  using RType = GTlsInteractionResult;
  return RType();
}
void TlsInteraction_Class::ask_password_async_vfunc_callback(GTlsInteraction* self, GTlsPassword* password, GCancellable* cancellable, GAsyncReadyCallback callback, gpointer user_data)
{
  const auto slot = static_cast<Gio::SlotAsyncReady*>(user_data);

  const auto obj_base = static_cast<Glib::ObjectBase*>(
      Glib::ObjectBase::_get_current_wrapper((GObject*)self));

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
        obj->ask_password_async_vfunc(Glib::wrap(password, true)
, *slot, Glib::wrap(cancellable)
);
        return;
      }
      catch(...)
      {
        Glib::exception_handlers_invoke();
      }
    }
  }

  BaseClassType *const base = static_cast<BaseClassType*>(
      g_type_class_peek_parent(G_OBJECT_GET_CLASS(self)) // Get the parent class of the object class (The original underlying C class).
  );

  // Call the original underlying C function:
  if(base && base->ask_password_async)
    (*base->ask_password_async)(self, password, cancellable, callback, user_data);
}
auto TlsInteraction_Class::ask_password_finish_vfunc_callback(GTlsInteraction* self, GAsyncResult* result, GError** error) -> GTlsInteractionResult
{
  const auto obj_base = static_cast<Glib::ObjectBase*>(
      Glib::ObjectBase::_get_current_wrapper((GObject*)self));

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
        return static_cast<GTlsInteractionResult>(obj->ask_password_finish_vfunc(Glib::wrap(result, true)
));
      }
      catch(Glib::Error& errormm)
      {
        errormm.propagate(error);
        using RType = GTlsInteractionResult;
        return RType();
      }
      catch(...)
      {
        Glib::exception_handlers_invoke();
      }
    }
  }

  BaseClassType *const base = static_cast<BaseClassType*>(
      g_type_class_peek_parent(G_OBJECT_GET_CLASS(self)) // Get the parent class of the object class (The original underlying C class).
  );

  // Call the original underlying C function:
  if(base && base->ask_password_finish)
    return (*base->ask_password_finish)(self, result, error);

  using RType = GTlsInteractionResult;
  return RType();
}


auto TlsInteraction_Class::wrap_new(GObject* object) -> Glib::ObjectBase*
{
  return new TlsInteraction((GTlsInteraction*)object);
}


/* The implementation: */

auto TlsInteraction::gobj_copy() -> GTlsInteraction*
{
  reference();
  return gobj();
}

TlsInteraction::TlsInteraction(const Glib::ConstructParams& construct_params)
:
  Glib::Object(construct_params)
{

}

TlsInteraction::TlsInteraction(GTlsInteraction* castitem)
:
  Glib::Object((GObject*)(castitem))
{}


TlsInteraction::TlsInteraction(TlsInteraction&& src) noexcept
: Glib::Object(std::move(src))
{}

auto TlsInteraction::operator=(TlsInteraction&& src) noexcept -> TlsInteraction&
{
  Glib::Object::operator=(std::move(src));
  return *this;
}


TlsInteraction::~TlsInteraction() noexcept
{}


TlsInteraction::CppClassType TlsInteraction::tlsinteraction_class_; // initialize static member

auto TlsInteraction::get_type() -> GType
{
  return tlsinteraction_class_.init().get_type();
}


auto TlsInteraction::get_base_type() -> GType
{
  return g_tls_interaction_get_type();
}


TlsInteraction::TlsInteraction()
:
  // Mark this class as non-derived to allow C++ vfuncs to be skipped.
  Glib::ObjectBase(nullptr),
  Glib::Object(Glib::ConstructParams(tlsinteraction_class_.init()))
{


}

auto TlsInteraction::ask_password(const Glib::RefPtr<TlsPassword>& password, const Glib::RefPtr<Cancellable>& cancellable) -> TlsInteractionResult
{
  GError* gerror = nullptr;
  auto retvalue = static_cast<TlsInteractionResult>(g_tls_interaction_ask_password(gobj(), Glib::unwrap(password), const_cast<GCancellable*>(Glib::unwrap(cancellable)), &(gerror)));
  if(gerror)
    ::Glib::Error::throw_exception(gerror);
  return retvalue;
}

auto TlsInteraction::ask_password(const Glib::RefPtr<TlsPassword>& password) -> TlsInteractionResult
{
  GError* gerror = nullptr;
  auto retvalue = static_cast<TlsInteractionResult>(g_tls_interaction_ask_password(gobj(), Glib::unwrap(password), nullptr, &(gerror)));
  if(gerror)
    ::Glib::Error::throw_exception(gerror);
  return retvalue;
}

void TlsInteraction::ask_password_async(const Glib::RefPtr<TlsPassword>& password, const SlotAsyncReady& slot, const Glib::RefPtr<Cancellable>& cancellable)
{
  // Create a copy of the slot.
  auto slot_copy = new SlotAsyncReady(slot);

  g_tls_interaction_ask_password_async(gobj(), Glib::unwrap(password), const_cast<GCancellable*>(Glib::unwrap(cancellable)), &SignalProxy_async_callback, slot_copy);
}

void TlsInteraction::ask_password_async(const Glib::RefPtr<TlsPassword>& password, const SlotAsyncReady& slot)
{
  // Create a copy of the slot.
  auto slot_copy = new SlotAsyncReady(slot);

  g_tls_interaction_ask_password_async(gobj(), Glib::unwrap(password), nullptr, &SignalProxy_async_callback, slot_copy);
}

void TlsInteraction::ask_password_async(const Glib::RefPtr<TlsPassword>& password, const Glib::RefPtr<Cancellable>& cancellable)
{
  g_tls_interaction_ask_password_async(gobj(), Glib::unwrap(password), const_cast<GCancellable*>(Glib::unwrap(cancellable)), nullptr, nullptr);
}

void TlsInteraction::ask_password_async(const Glib::RefPtr<TlsPassword>& password)
{
  g_tls_interaction_ask_password_async(gobj(), Glib::unwrap(password), nullptr, nullptr, nullptr);
}

auto TlsInteraction::ask_password_finish(const Glib::RefPtr<AsyncResult>& result) -> TlsInteractionResult
{
  GError* gerror = nullptr;
  auto retvalue = static_cast<TlsInteractionResult>(g_tls_interaction_ask_password_finish(gobj(), Glib::unwrap(result), &(gerror)));
  if(gerror)
    ::Glib::Error::throw_exception(gerror);
  return retvalue;
}

auto TlsInteraction::invoke_ask_password(const Glib::RefPtr<TlsPassword>& password, const Glib::RefPtr<Cancellable>& cancellable) -> TlsInteractionResult
{
  GError* gerror = nullptr;
  auto retvalue = static_cast<TlsInteractionResult>(g_tls_interaction_invoke_ask_password(gobj(), Glib::unwrap(password), const_cast<GCancellable*>(Glib::unwrap(cancellable)), &(gerror)));
  if(gerror)
    ::Glib::Error::throw_exception(gerror);
  return retvalue;
}

auto TlsInteraction::invoke_ask_password(const Glib::RefPtr<TlsPassword>& password) -> TlsInteractionResult
{
  GError* gerror = nullptr;
  auto retvalue = static_cast<TlsInteractionResult>(g_tls_interaction_invoke_ask_password(gobj(), Glib::unwrap(password), nullptr, &(gerror)));
  if(gerror)
    ::Glib::Error::throw_exception(gerror);
  return retvalue;
}

auto TlsInteraction::invoke_request_certificate(const Glib::RefPtr<TlsConnection>& connection, TlsCertificateRequestFlags flags, const Glib::RefPtr<Cancellable>& cancellable) -> TlsInteractionResult
{
  GError* gerror = nullptr;
  auto retvalue = static_cast<TlsInteractionResult>(g_tls_interaction_invoke_request_certificate(gobj(), Glib::unwrap(connection), static_cast<GTlsCertificateRequestFlags>(flags), const_cast<GCancellable*>(Glib::unwrap(cancellable)), &(gerror)));
  if(gerror)
    ::Glib::Error::throw_exception(gerror);
  return retvalue;
}

auto TlsInteraction::invoke_request_certificate(const Glib::RefPtr<TlsConnection>& connection, TlsCertificateRequestFlags flags) -> TlsInteractionResult
{
  GError* gerror = nullptr;
  auto retvalue = static_cast<TlsInteractionResult>(g_tls_interaction_invoke_request_certificate(gobj(), Glib::unwrap(connection), static_cast<GTlsCertificateRequestFlags>(flags), nullptr, &(gerror)));
  if(gerror)
    ::Glib::Error::throw_exception(gerror);
  return retvalue;
}

auto TlsInteraction::request_certificate(const Glib::RefPtr<TlsConnection>& connection, TlsCertificateRequestFlags flags, const Glib::RefPtr<Cancellable>& cancellable) -> TlsInteractionResult
{
  GError* gerror = nullptr;
  auto retvalue = static_cast<TlsInteractionResult>(g_tls_interaction_request_certificate(gobj(), Glib::unwrap(connection), static_cast<GTlsCertificateRequestFlags>(flags), const_cast<GCancellable*>(Glib::unwrap(cancellable)), &(gerror)));
  if(gerror)
    ::Glib::Error::throw_exception(gerror);
  return retvalue;
}

auto TlsInteraction::request_certificate(const Glib::RefPtr<TlsConnection>& connection, TlsCertificateRequestFlags flags) -> TlsInteractionResult
{
  GError* gerror = nullptr;
  auto retvalue = static_cast<TlsInteractionResult>(g_tls_interaction_request_certificate(gobj(), Glib::unwrap(connection), static_cast<GTlsCertificateRequestFlags>(flags), nullptr, &(gerror)));
  if(gerror)
    ::Glib::Error::throw_exception(gerror);
  return retvalue;
}

void TlsInteraction::request_certificate_async(const Glib::RefPtr<TlsConnection>& connection, TlsCertificateRequestFlags flags, const SlotAsyncReady& slot, const Glib::RefPtr<Cancellable>& cancellable)
{
  // Create a copy of the slot.
  auto slot_copy = new SlotAsyncReady(slot);

  g_tls_interaction_request_certificate_async(gobj(), Glib::unwrap(connection), static_cast<GTlsCertificateRequestFlags>(flags), const_cast<GCancellable*>(Glib::unwrap(cancellable)), &SignalProxy_async_callback, slot_copy);
}

void TlsInteraction::request_certificate_async(const Glib::RefPtr<TlsConnection>& connection, TlsCertificateRequestFlags flags, const SlotAsyncReady& slot)
{
  // Create a copy of the slot.
  auto slot_copy = new SlotAsyncReady(slot);

  g_tls_interaction_request_certificate_async(gobj(), Glib::unwrap(connection), static_cast<GTlsCertificateRequestFlags>(flags), nullptr, &SignalProxy_async_callback, slot_copy);
}

void TlsInteraction::request_certificate_async(const Glib::RefPtr<TlsConnection>& connection, TlsCertificateRequestFlags flags, const Glib::RefPtr<Cancellable>& cancellable)
{
  g_tls_interaction_request_certificate_async(gobj(), Glib::unwrap(connection), static_cast<GTlsCertificateRequestFlags>(flags), const_cast<GCancellable*>(Glib::unwrap(cancellable)), nullptr, nullptr);
}

void TlsInteraction::request_certificate_async(const Glib::RefPtr<TlsConnection>& connection, TlsCertificateRequestFlags flags)
{
  g_tls_interaction_request_certificate_async(gobj(), Glib::unwrap(connection), static_cast<GTlsCertificateRequestFlags>(flags), nullptr, nullptr, nullptr);
}

auto TlsInteraction::request_certificate_finish(const Glib::RefPtr<AsyncResult>& result) -> TlsInteractionResult
{
  GError* gerror = nullptr;
  auto retvalue = static_cast<TlsInteractionResult>(g_tls_interaction_request_certificate_finish(gobj(), Glib::unwrap(result), &(gerror)));
  if(gerror)
    ::Glib::Error::throw_exception(gerror);
  return retvalue;
}


auto Gio::TlsInteraction::ask_password_vfunc(const Glib::RefPtr<TlsPassword>& password, const Glib::RefPtr<Cancellable>& cancellable) -> TlsInteractionResult
{
  const auto base = static_cast<BaseClassType*>(
      g_type_class_peek_parent(G_OBJECT_GET_CLASS(gobject_)) // Get the parent class of the object class (The original underlying C class).
  );

  if(base && base->ask_password)
  {
    GError* gerror = nullptr;
    TlsInteractionResult retval(static_cast<TlsInteractionResult>((*base->ask_password)(gobj(),Glib::unwrap(password),const_cast<GCancellable*>(Glib::unwrap(cancellable)),&(gerror))));
    if(gerror)
      ::Glib::Error::throw_exception(gerror);
    return retval;
  }

  using RType = TlsInteractionResult;
  return RType();
}
void Gio::TlsInteraction::ask_password_async_vfunc(const Glib::RefPtr<TlsPassword>& password, const SlotAsyncReady& slot, const Glib::RefPtr<Cancellable>& cancellable)
{
  // Create a copy of the slot.
  auto slot_copy = new SlotAsyncReady(slot);

  const auto base = static_cast<BaseClassType*>(
      g_type_class_peek_parent(G_OBJECT_GET_CLASS(gobject_)) // Get the parent class of the object class (The original underlying C class).
  );

  if(base && base->ask_password_async)
  {
    (*base->ask_password_async)(gobj(),Glib::unwrap(password),const_cast<GCancellable*>(Glib::unwrap(cancellable)),&SignalProxy_async_callback,slot_copy);
  }
}
auto Gio::TlsInteraction::ask_password_finish_vfunc(const Glib::RefPtr<AsyncResult>& result) -> TlsInteractionResult
{
  const auto base = static_cast<BaseClassType*>(
      g_type_class_peek_parent(G_OBJECT_GET_CLASS(gobject_)) // Get the parent class of the object class (The original underlying C class).
  );

  if(base && base->ask_password_finish)
  {
    GError* gerror = nullptr;
    TlsInteractionResult retval(static_cast<TlsInteractionResult>((*base->ask_password_finish)(gobj(),Glib::unwrap(result),&(gerror))));
    if(gerror)
      ::Glib::Error::throw_exception(gerror);
    return retval;
  }

  using RType = TlsInteractionResult;
  return RType();
}


} // namespace Gio

