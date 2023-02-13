


#include <libmm-glib/mm-glib.hxx>

#include <libmm-gio/tlsinteraction.hxx>
#include <libmm-gio/tlsinteraction_p.hxx>


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
#include <libmm-gio/cancellable.hxx>
#include <libmm-gio/tlspassword.hxx>
#include <libmm-gio/slot_async.hxx>

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

auto wrap(GTlsInteraction* object, const bool take_copy) -> RefPtr<Gio::TlsInteraction>
{
  return Glib::make_refptr_for_instance<Gio::TlsInteraction>( dynamic_cast<Gio::TlsInteraction*> (wrap_auto((GObject*)object, take_copy)) );
  //We use dynamic_cast<> in case of multiple inheritance.
}

} /* namespace Glib */


namespace Gio
{


/* The *_Class implementation: */

auto TlsInteraction_Class::init() -> const Class&
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


auto TlsInteraction_Class::class_init_function (void *g_class, void *class_data) -> void
{
  const auto klass = static_cast<BaseClassType*>(g_class);
  CppClassParent::class_init_function(klass, class_data);

  klass->ask_password = &ask_password_vfunc_callback;
  klass->ask_password_async = &ask_password_async_vfunc_callback;
  klass->ask_password_finish = &ask_password_finish_vfunc_callback;

}

auto TlsInteraction_Class::ask_password_vfunc_callback(GTlsInteraction* self, GTlsPassword* password, GCancellable* cancellable, GError** error) -> GTlsInteractionResult
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

  const BaseClassType *const base = static_cast<BaseClassType*>(
      g_type_class_peek_parent(G_OBJECT_GET_CLASS(self)) // Get the parent class of the object class (The original underlying C class).
  );

  // Call the original underlying C function:
  if(base && base->ask_password)
    return (*base->ask_password)(self, password, cancellable, error);

  using RType = GTlsInteractionResult;
  return RType();
}
auto TlsInteraction_Class::ask_password_async_vfunc_callback (
  GTlsInteraction *self, GTlsPassword *password, GCancellable *cancellable, const GAsyncReadyCallback callback, const gpointer user_data) -> void
{
  const auto slot = static_cast<SlotAsyncReady *>(user_data);

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

  const BaseClassType *const base = static_cast<BaseClassType*>(
      g_type_class_peek_parent(G_OBJECT_GET_CLASS(self)) // Get the parent class of the object class (The original underlying C class).
  );

  // Call the original underlying C function:
  if(base && base->ask_password_async)
    (*base->ask_password_async)(self, password, cancellable, callback, user_data);
}
auto TlsInteraction_Class::ask_password_finish_vfunc_callback(GTlsInteraction* self, GAsyncResult* result, GError** error) -> GTlsInteractionResult
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

  const BaseClassType *const base = static_cast<BaseClassType*>(
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
: Object(construct_params)
{

}

TlsInteraction::TlsInteraction(GTlsInteraction* castitem)
: Object((GObject*)castitem)
{}


TlsInteraction::TlsInteraction(TlsInteraction&& src) noexcept
: Object(std::move(src))
{}

auto TlsInteraction::operator=(TlsInteraction&& src) noexcept -> TlsInteraction&
{
  Object::operator=(std::move(src));
  return *this;
}


TlsInteraction::~TlsInteraction() noexcept = default;

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
ObjectBase(nullptr),
Object(Glib::ConstructParams(tlsinteraction_class_.init()))
{


}

auto TlsInteraction::ask_password(const Glib::RefPtr<TlsPassword>& password, const Glib::RefPtr<Cancellable>& cancellable) -> TlsInteractionResult
{
  GError* gerror = nullptr;
  const auto retvalue = static_cast<TlsInteractionResult>(g_tls_interaction_ask_password(gobj(), Glib::unwrap(password), Glib::unwrap(cancellable), &gerror));
  if(gerror)
    Glib::Error::throw_exception(gerror);
  return retvalue;
}

auto TlsInteraction::ask_password(const Glib::RefPtr<TlsPassword>& password) -> TlsInteractionResult
{
  GError* gerror = nullptr;
  const auto retvalue = static_cast<TlsInteractionResult>(g_tls_interaction_ask_password(gobj(), Glib::unwrap(password), nullptr, &gerror));
  if(gerror)
    Glib::Error::throw_exception(gerror);
  return retvalue;
}

auto TlsInteraction::ask_password_async (
  const Glib::RefPtr <TlsPassword> &password, const SlotAsyncReady &slot,
  const Glib::RefPtr <Cancellable> &cancellable) -> void
{
  // Create a copy of the slot.
  const auto slot_copy = new SlotAsyncReady(slot);

  g_tls_interaction_ask_password_async(gobj(), Glib::unwrap(password), Glib::unwrap(cancellable), &SignalProxy_async_callback, slot_copy);
}

auto TlsInteraction::ask_password_async (
  const Glib::RefPtr <TlsPassword> &password, const SlotAsyncReady &slot) -> void
{
  // Create a copy of the slot.
  const auto slot_copy = new SlotAsyncReady(slot);

  g_tls_interaction_ask_password_async(gobj(), Glib::unwrap(password), nullptr, &SignalProxy_async_callback, slot_copy);
}

auto TlsInteraction::ask_password_async (
  const Glib::RefPtr <TlsPassword> &password, const Glib::RefPtr <Cancellable> &cancellable) -> void
{
  g_tls_interaction_ask_password_async(gobj(), Glib::unwrap(password), Glib::unwrap(cancellable), nullptr, nullptr);
}

auto TlsInteraction::ask_password_async (const Glib::RefPtr <TlsPassword> &password) -> void
{
  g_tls_interaction_ask_password_async(gobj(), Glib::unwrap(password), nullptr, nullptr, nullptr);
}

auto TlsInteraction::ask_password_finish(const Glib::RefPtr<AsyncResult>& result) -> TlsInteractionResult
{
  GError* gerror = nullptr;
  const auto retvalue = static_cast<TlsInteractionResult>(g_tls_interaction_ask_password_finish(gobj(), Glib::unwrap(result), &gerror));
  if(gerror)
    Glib::Error::throw_exception(gerror);
  return retvalue;
}

auto TlsInteraction::invoke_ask_password(const Glib::RefPtr<TlsPassword>& password, const Glib::RefPtr<Cancellable>& cancellable) -> TlsInteractionResult
{
  GError* gerror = nullptr;
  const auto retvalue = static_cast<TlsInteractionResult>(g_tls_interaction_invoke_ask_password(gobj(), Glib::unwrap(password), Glib::unwrap(cancellable), &gerror));
  if(gerror)
    Glib::Error::throw_exception(gerror);
  return retvalue;
}

auto TlsInteraction::invoke_ask_password(const Glib::RefPtr<TlsPassword>& password) -> TlsInteractionResult
{
  GError* gerror = nullptr;
  const auto retvalue = static_cast<TlsInteractionResult>(g_tls_interaction_invoke_ask_password(gobj(), Glib::unwrap(password), nullptr, &gerror));
  if(gerror)
    Glib::Error::throw_exception(gerror);
  return retvalue;
}

auto TlsInteraction::invoke_request_certificate(const Glib::RefPtr<TlsConnection>& connection, TlsCertificateRequestFlags flags, const Glib::RefPtr<Cancellable>& cancellable) -> TlsInteractionResult
{
  GError* gerror = nullptr;
  const auto retvalue = static_cast<TlsInteractionResult>(g_tls_interaction_invoke_request_certificate(gobj(), Glib::unwrap(connection), static_cast<GTlsCertificateRequestFlags>(flags), Glib::unwrap(cancellable), &gerror));
  if(gerror)
    Glib::Error::throw_exception(gerror);
  return retvalue;
}

auto TlsInteraction::invoke_request_certificate(const Glib::RefPtr<TlsConnection>& connection, TlsCertificateRequestFlags flags) -> TlsInteractionResult
{
  GError* gerror = nullptr;
  const auto retvalue = static_cast<TlsInteractionResult>(g_tls_interaction_invoke_request_certificate(gobj(), Glib::unwrap(connection), static_cast<GTlsCertificateRequestFlags>(flags), nullptr, &gerror));
  if(gerror)
    Glib::Error::throw_exception(gerror);
  return retvalue;
}

auto TlsInteraction::request_certificate(const Glib::RefPtr<TlsConnection>& connection, TlsCertificateRequestFlags flags, const Glib::RefPtr<Cancellable>& cancellable) -> TlsInteractionResult
{
  GError* gerror = nullptr;
  const auto retvalue = static_cast<TlsInteractionResult>(g_tls_interaction_request_certificate(gobj(), Glib::unwrap(connection), static_cast<GTlsCertificateRequestFlags>(flags), Glib::unwrap(cancellable), &gerror));
  if(gerror)
    Glib::Error::throw_exception(gerror);
  return retvalue;
}

auto TlsInteraction::request_certificate(const Glib::RefPtr<TlsConnection>& connection, TlsCertificateRequestFlags flags) -> TlsInteractionResult
{
  GError* gerror = nullptr;
  const auto retvalue = static_cast<TlsInteractionResult>(g_tls_interaction_request_certificate(gobj(), Glib::unwrap(connection), static_cast<GTlsCertificateRequestFlags>(flags), nullptr, &gerror));
  if(gerror)
    Glib::Error::throw_exception(gerror);
  return retvalue;
}

auto TlsInteraction::request_certificate_async (
  const Glib::RefPtr <TlsConnection> &connection, TlsCertificateRequestFlags flags,
  const SlotAsyncReady &slot, const Glib::RefPtr <Cancellable> &cancellable) -> void
{
  // Create a copy of the slot.
  const auto slot_copy = new SlotAsyncReady(slot);

  g_tls_interaction_request_certificate_async(gobj(), Glib::unwrap(connection), static_cast<GTlsCertificateRequestFlags>(flags), Glib::unwrap(cancellable), &SignalProxy_async_callback, slot_copy);
}

auto TlsInteraction::request_certificate_async (
  const Glib::RefPtr <TlsConnection> &connection, TlsCertificateRequestFlags flags,
  const SlotAsyncReady &slot) -> void
{
  // Create a copy of the slot.
  const auto slot_copy = new SlotAsyncReady(slot);

  g_tls_interaction_request_certificate_async(gobj(), Glib::unwrap(connection), static_cast<GTlsCertificateRequestFlags>(flags), nullptr, &SignalProxy_async_callback, slot_copy);
}

auto TlsInteraction::request_certificate_async (
  const Glib::RefPtr <TlsConnection> &connection, TlsCertificateRequestFlags flags,
  const Glib::RefPtr <Cancellable> &cancellable) -> void
{
  g_tls_interaction_request_certificate_async(gobj(), Glib::unwrap(connection), static_cast<GTlsCertificateRequestFlags>(flags), Glib::unwrap(cancellable), nullptr, nullptr);
}

auto TlsInteraction::request_certificate_async (
  const Glib::RefPtr <TlsConnection> &connection, TlsCertificateRequestFlags flags) -> void
{
  g_tls_interaction_request_certificate_async(gobj(), Glib::unwrap(connection), static_cast<GTlsCertificateRequestFlags>(flags), nullptr, nullptr, nullptr);
}

auto TlsInteraction::request_certificate_finish(const Glib::RefPtr<AsyncResult>& result) -> TlsInteractionResult
{
  GError* gerror = nullptr;
  const auto retvalue = static_cast<TlsInteractionResult>(g_tls_interaction_request_certificate_finish(gobj(), Glib::unwrap(result), &gerror));
  if(gerror)
    Glib::Error::throw_exception(gerror);
  return retvalue;
}


auto TlsInteraction::ask_password_vfunc(const Glib::RefPtr<TlsPassword>& password, const Glib::RefPtr<Cancellable>& cancellable) -> TlsInteractionResult
{
  const auto base = static_cast<BaseClassType*>(
      g_type_class_peek_parent(G_OBJECT_GET_CLASS(gobject_)) // Get the parent class of the object class (The original underlying C class).
  );

  if(base && base->ask_password)
  {
    GError* gerror = nullptr;
    const TlsInteractionResult retval(static_cast<TlsInteractionResult>((*base->ask_password)(gobj(),Glib::unwrap(password),Glib::unwrap(cancellable),&gerror)));
    if(gerror)
      Glib::Error::throw_exception(gerror);
    return retval;
  }

  using RType = TlsInteractionResult;
  return RType();
}
auto TlsInteraction::ask_password_async_vfunc (
  const Glib::RefPtr <TlsPassword> &password, const SlotAsyncReady &slot,
  const Glib::RefPtr <Cancellable> &cancellable) -> void
{
  // Create a copy of the slot.
  const auto slot_copy = new SlotAsyncReady(slot);

  const auto base = static_cast<BaseClassType*>(
      g_type_class_peek_parent(G_OBJECT_GET_CLASS(gobject_)) // Get the parent class of the object class (The original underlying C class).
  );

  if(base && base->ask_password_async)
  {
    (*base->ask_password_async)(gobj(),Glib::unwrap(password),Glib::unwrap(cancellable),&SignalProxy_async_callback,slot_copy);
  }
}
auto TlsInteraction::ask_password_finish_vfunc(const Glib::RefPtr<AsyncResult>& result) -> TlsInteractionResult
{
  const auto base = static_cast<BaseClassType*>(
      g_type_class_peek_parent(G_OBJECT_GET_CLASS(gobject_)) // Get the parent class of the object class (The original underlying C class).
  );

  if(base && base->ask_password_finish)
  {
    GError* gerror = nullptr;
    const TlsInteractionResult retval(static_cast<TlsInteractionResult>((*base->ask_password_finish)(gobj(),Glib::unwrap(result),&gerror)));
    if(gerror)
      Glib::Error::throw_exception(gerror);
    return retval;
  }

  using RType = TlsInteractionResult;
  return RType();
}


} // namespace Gio


