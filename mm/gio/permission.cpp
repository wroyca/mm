// Generated by gmmproc 2.74.0 -- DO NOT MODIFY!


#include <mm/glib/mm-glib.hpp>

#include <mm/gio/permission.hpp>
#include <mm/gio/private/permission_p.hpp>


/* Copyright (C) 2014 The giomm Development Team
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
#include <mm/gio/slot_async.hpp>

namespace Gio
{
} // namespace Gio

namespace
{
} // anonymous namespace


namespace Glib
{

auto wrap(GPermission* object, bool take_copy) -> Glib::RefPtr<Gio::Permission>
{
  return Glib::make_refptr_for_instance<Gio::Permission>( dynamic_cast<Gio::Permission*> (Glib::wrap_auto ((GObject*)(object), take_copy)) );
  //We use dynamic_cast<> in case of multiple inheritance.
}

} /* namespace Glib */


namespace Gio
{


/* The *_Class implementation: */

auto Permission_Class::init() -> const Glib::Class&
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Class has to know the class init function to clone custom types.
    class_init_func_ = &Permission_Class::class_init_function;

    // This is actually just optimized away, apparently with no harm.
    // Make sure that the parent type has been created.
    //CppClassParent::CppObjectType::get_type();

    // Create the wrapper type, with the same class/instance size as the base type.
    register_derived_type(g_permission_get_type());

    // Add derived versions of interfaces, if the C type implements any interfaces:

  }

  return *this;
}


void Permission_Class::class_init_function(void* g_class, void* class_data)
{
  const auto klass = static_cast<BaseClassType*>(g_class);
  CppClassParent::class_init_function(klass, class_data);

  klass->acquire = &acquire_vfunc_callback;
  klass->acquire_async = &acquire_async_vfunc_callback;
  klass->acquire_finish = &acquire_finish_vfunc_callback;
  klass->release = &release_vfunc_callback;
  klass->release_async = &release_async_vfunc_callback;
  klass->release_finish = &release_finish_vfunc_callback;

}

auto Permission_Class::acquire_vfunc_callback(GPermission* self, GCancellable* cancellable, GError** error) -> gboolean
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
        return static_cast<int>(obj->acquire_vfunc(Glib::wrap(cancellable, true)
));
      }
      catch(Glib::Error& errormm)
      {
        errormm.propagate(error);
        using RType = gboolean;
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
  if(base && base->acquire)
    return (*base->acquire)(self, cancellable, error);

  using RType = gboolean;
  return RType();
}
void Permission_Class::acquire_async_vfunc_callback(GPermission* self, GCancellable* cancellable, GAsyncReadyCallback callback, gpointer user_data)
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
        obj->acquire_async_vfunc(*slot, Glib::wrap(cancellable, true)
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
  if(base && base->acquire_async)
    (*base->acquire_async)(self, cancellable, callback, user_data);
}
auto Permission_Class::acquire_finish_vfunc_callback(GPermission* self, GAsyncResult* result, GError** error) -> gboolean
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
        return static_cast<int>(obj->acquire_finish_vfunc(Glib::wrap(result, true)
));
      }
      catch(Glib::Error& errormm)
      {
        errormm.propagate(error);
        using RType = gboolean;
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
  if(base && base->acquire_finish)
    return (*base->acquire_finish)(self, result, error);

  using RType = gboolean;
  return RType();
}
auto Permission_Class::release_vfunc_callback(GPermission* self, GCancellable* cancellable, GError** error) -> gboolean
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
        return static_cast<int>(obj->release_vfunc(Glib::wrap(cancellable, true)
));
      }
      catch(Glib::Error& errormm)
      {
        errormm.propagate(error);
        using RType = gboolean;
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
  if(base && base->release)
    return (*base->release)(self, cancellable, error);

  using RType = gboolean;
  return RType();
}
void Permission_Class::release_async_vfunc_callback(GPermission* self, GCancellable* cancellable, GAsyncReadyCallback callback, gpointer user_data)
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
        obj->release_async_vfunc(*slot, Glib::wrap(cancellable, true)
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
  if(base && base->release_async)
    (*base->release_async)(self, cancellable, callback, user_data);
}
auto Permission_Class::release_finish_vfunc_callback(GPermission* self, GAsyncResult* result, GError** error) -> gboolean
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
        return static_cast<int>(obj->release_finish_vfunc(Glib::wrap(result, true)
));
      }
      catch(Glib::Error& errormm)
      {
        errormm.propagate(error);
        using RType = gboolean;
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
  if(base && base->release_finish)
    return (*base->release_finish)(self, result, error);

  using RType = gboolean;
  return RType();
}


auto Permission_Class::wrap_new(GObject* object) -> Glib::ObjectBase*
{
  return new Permission((GPermission*)object);
}


/* The implementation: */

auto Permission::gobj_copy() -> GPermission*
{
  reference();
  return gobj();
}

Permission::Permission(const Glib::ConstructParams& construct_params)
:
  Glib::Object(construct_params)
{

}

Permission::Permission(GPermission* castitem)
:
  Glib::Object((GObject*)(castitem))
{}


Permission::Permission(Permission&& src) noexcept
: Glib::Object(std::move(src))
{}

auto Permission::operator=(Permission&& src) noexcept -> Permission&
{
  Glib::Object::operator=(std::move(src));
  return *this;
}


Permission::~Permission() noexcept
{}


Permission::CppClassType Permission::permission_class_; // initialize static member

auto Permission::get_type() -> GType
{
  return permission_class_.init().get_type();
}


auto Permission::get_base_type() -> GType
{
  return g_permission_get_type();
}


auto Permission::acquire(const Glib::RefPtr<Cancellable>& cancellable) -> bool
{
  GError* gerror = nullptr;
  auto retvalue = g_permission_acquire(gobj(), const_cast<GCancellable*>(Glib::unwrap(cancellable)), &(gerror));
  if(gerror)
    ::Glib::Error::throw_exception(gerror);
  return retvalue;
}

auto Permission::acquire() -> bool
{
  GError* gerror = nullptr;
  auto retvalue = g_permission_acquire(gobj(), nullptr, &(gerror));
  if(gerror)
    ::Glib::Error::throw_exception(gerror);
  return retvalue;
}

void Permission::acquire_async(const SlotAsyncReady& slot, const Glib::RefPtr<Cancellable>& cancellable)
{
  // Create a copy of the slot.
  auto slot_copy = new SlotAsyncReady(slot);

  g_permission_acquire_async(gobj(), const_cast<GCancellable*>(Glib::unwrap(cancellable)), &SignalProxy_async_callback, slot_copy);
}

void Permission::acquire_async(const SlotAsyncReady& slot)
{
  // Create a copy of the slot.
  auto slot_copy = new SlotAsyncReady(slot);

  g_permission_acquire_async(gobj(), nullptr, &SignalProxy_async_callback, slot_copy);
}

auto Permission::acquire_finish(const Glib::RefPtr<AsyncResult>& result) -> bool
{
  GError* gerror = nullptr;
  auto retvalue = g_permission_acquire_finish(gobj(), Glib::unwrap(result), &(gerror));
  if(gerror)
    ::Glib::Error::throw_exception(gerror);
  return retvalue;
}

auto Permission::release(const Glib::RefPtr<Cancellable>& cancellable) -> bool
{
  GError* gerror = nullptr;
  auto retvalue = g_permission_release(gobj(), const_cast<GCancellable*>(Glib::unwrap(cancellable)), &(gerror));
  if(gerror)
    ::Glib::Error::throw_exception(gerror);
  return retvalue;
}

auto Permission::release() -> bool
{
  GError* gerror = nullptr;
  auto retvalue = g_permission_release(gobj(), nullptr, &(gerror));
  if(gerror)
    ::Glib::Error::throw_exception(gerror);
  return retvalue;
}

void Permission::release_async(const SlotAsyncReady& slot, const Glib::RefPtr<Cancellable>& cancellable)
{
  // Create a copy of the slot.
  auto slot_copy = new SlotAsyncReady(slot);

  g_permission_release_async(gobj(), const_cast<GCancellable*>(Glib::unwrap(cancellable)), &SignalProxy_async_callback, slot_copy);
}

void Permission::release_async(const SlotAsyncReady& slot)
{
  // Create a copy of the slot.
  auto slot_copy = new SlotAsyncReady(slot);

  g_permission_release_async(gobj(), nullptr, &SignalProxy_async_callback, slot_copy);
}

auto Permission::release_finish(const Glib::RefPtr<AsyncResult>& result) -> bool
{
  GError* gerror = nullptr;
  auto retvalue = g_permission_release_finish(gobj(), Glib::unwrap(result), &(gerror));
  if(gerror)
    ::Glib::Error::throw_exception(gerror);
  return retvalue;
}

auto Permission::get_allowed() const -> bool
{
  return g_permission_get_allowed(const_cast<GPermission*>(gobj()));
}

auto Permission::get_can_acquire() const -> bool
{
  return g_permission_get_can_acquire(const_cast<GPermission*>(gobj()));
}

auto Permission::get_can_release() const -> bool
{
  return g_permission_get_can_release(const_cast<GPermission*>(gobj()));
}

Permission::Permission()
:
  // Mark this class as non-derived to allow C++ vfuncs to be skipped.
  Glib::ObjectBase(nullptr),
  Glib::Object(Glib::ConstructParams(permission_class_.init()))
{


}

void Permission::impl_update(bool allowed, bool can_acquire, bool can_release)
{
  g_permission_impl_update(gobj(), static_cast<int>(allowed), static_cast<int>(can_acquire), static_cast<int>(can_release));
}


auto Permission::property_allowed() const -> Glib::PropertyProxy_ReadOnly< bool >
{
  return Glib::PropertyProxy_ReadOnly< bool >(this, "allowed");
}

auto Permission::property_can_acquire() const -> Glib::PropertyProxy_ReadOnly< bool >
{
  return Glib::PropertyProxy_ReadOnly< bool >(this, "can-acquire");
}

auto Permission::property_can_release() const -> Glib::PropertyProxy_ReadOnly< bool >
{
  return Glib::PropertyProxy_ReadOnly< bool >(this, "can-release");
}


auto Gio::Permission::acquire_vfunc(const Glib::RefPtr<Cancellable>& cancellable) -> bool
{
  const auto base = static_cast<BaseClassType*>(
      g_type_class_peek_parent(G_OBJECT_GET_CLASS(gobject_)) // Get the parent class of the object class (The original underlying C class).
  );

  if(base && base->acquire)
  {
    GError* gerror = nullptr;
    bool retval((*base->acquire)(gobj(),const_cast<GCancellable*>(Glib::unwrap(cancellable)),&(gerror)));
    if(gerror)
      ::Glib::Error::throw_exception(gerror);
    return retval;
  }

  using RType = bool;
  return RType();
}
void Gio::Permission::acquire_async_vfunc(const SlotAsyncReady& slot, const Glib::RefPtr<Cancellable>& cancellable)
{
  // Create a copy of the slot.
  auto slot_copy = new SlotAsyncReady(slot);

  const auto base = static_cast<BaseClassType*>(
      g_type_class_peek_parent(G_OBJECT_GET_CLASS(gobject_)) // Get the parent class of the object class (The original underlying C class).
  );

  if(base && base->acquire_async)
  {
    (*base->acquire_async)(gobj(),const_cast<GCancellable*>(Glib::unwrap(cancellable)),&SignalProxy_async_callback,slot_copy);
  }
}
auto Gio::Permission::acquire_finish_vfunc(const Glib::RefPtr<AsyncResult>& result) -> bool
{
  const auto base = static_cast<BaseClassType*>(
      g_type_class_peek_parent(G_OBJECT_GET_CLASS(gobject_)) // Get the parent class of the object class (The original underlying C class).
  );

  if(base && base->acquire_finish)
  {
    GError* gerror = nullptr;
    bool retval((*base->acquire_finish)(gobj(),Glib::unwrap(result),&(gerror)));
    if(gerror)
      ::Glib::Error::throw_exception(gerror);
    return retval;
  }

  using RType = bool;
  return RType();
}
auto Gio::Permission::release_vfunc(const Glib::RefPtr<Cancellable>& cancellable) -> bool
{
  const auto base = static_cast<BaseClassType*>(
      g_type_class_peek_parent(G_OBJECT_GET_CLASS(gobject_)) // Get the parent class of the object class (The original underlying C class).
  );

  if(base && base->release)
  {
    GError* gerror = nullptr;
    bool retval((*base->release)(gobj(),const_cast<GCancellable*>(Glib::unwrap(cancellable)),&(gerror)));
    if(gerror)
      ::Glib::Error::throw_exception(gerror);
    return retval;
  }

  using RType = bool;
  return RType();
}
void Gio::Permission::release_async_vfunc(const SlotAsyncReady& slot, const Glib::RefPtr<Cancellable>& cancellable)
{
  // Create a copy of the slot.
  auto slot_copy = new SlotAsyncReady(slot);

  const auto base = static_cast<BaseClassType*>(
      g_type_class_peek_parent(G_OBJECT_GET_CLASS(gobject_)) // Get the parent class of the object class (The original underlying C class).
  );

  if(base && base->release_async)
  {
    (*base->release_async)(gobj(),const_cast<GCancellable*>(Glib::unwrap(cancellable)),&SignalProxy_async_callback,slot_copy);
  }
}
auto Gio::Permission::release_finish_vfunc(const Glib::RefPtr<AsyncResult>& result) -> bool
{
  const auto base = static_cast<BaseClassType*>(
      g_type_class_peek_parent(G_OBJECT_GET_CLASS(gobject_)) // Get the parent class of the object class (The original underlying C class).
  );

  if(base && base->release_finish)
  {
    GError* gerror = nullptr;
    bool retval((*base->release_finish)(gobj(),Glib::unwrap(result),&(gerror)));
    if(gerror)
      ::Glib::Error::throw_exception(gerror);
    return retval;
  }

  using RType = bool;
  return RType();
}


} // namespace Gio

