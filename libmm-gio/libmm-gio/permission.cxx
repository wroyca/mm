

#include <libmm-glib/mm-glib.hxx>

#include <libmm-gio/permission.hxx>
#include <libmm-gio/permission_p.hxx>

#include <gio/gio.h>
#include <libmm-gio/slot_async.hxx>

namespace Gio
{
}

namespace
{
}

namespace Glib
{

  auto
  wrap (GPermission* object, const bool take_copy) -> RefPtr<Gio::Permission>
  {
    return Glib::make_refptr_for_instance<Gio::Permission> (
        dynamic_cast<Gio::Permission*> (
            wrap_auto ((GObject*) object, take_copy)));
  }

} // namespace Glib

namespace Gio
{

  auto
  Permission_Class::init () -> const Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &Permission_Class::class_init_function;

      register_derived_type (g_permission_get_type ());
    }

    return *this;
  }

  auto
  Permission_Class::class_init_function (void* g_class, void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);

    klass->acquire = &acquire_vfunc_callback;
    klass->acquire_async = &acquire_async_vfunc_callback;
    klass->acquire_finish = &acquire_finish_vfunc_callback;
    klass->release = &release_vfunc_callback;
    klass->release_async = &release_async_vfunc_callback;
    klass->release_finish = &release_finish_vfunc_callback;
  }

  auto
  Permission_Class::acquire_vfunc_callback (GPermission* self,
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
          return obj->acquire_vfunc (Glib::wrap (cancellable, true));
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

    if (base && base->acquire)
      return (*base->acquire) (self, cancellable, error);

    using RType = gboolean;
    return RType ();
  }

  auto
  Permission_Class::acquire_async_vfunc_callback (
      GPermission* self,
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
          obj->acquire_async_vfunc (*slot, Glib::wrap (cancellable, true));
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

    if (base && base->acquire_async)
      (*base->acquire_async) (self, cancellable, callback, user_data);
  }

  auto
  Permission_Class::acquire_finish_vfunc_callback (GPermission* self,
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
          return obj->acquire_finish_vfunc (Glib::wrap (result, true));
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

    if (base && base->acquire_finish)
      return (*base->acquire_finish) (self, result, error);

    using RType = gboolean;
    return RType ();
  }

  auto
  Permission_Class::release_vfunc_callback (GPermission* self,
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
          return obj->release_vfunc (Glib::wrap (cancellable, true));
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

    if (base && base->release)
      return (*base->release) (self, cancellable, error);

    using RType = gboolean;
    return RType ();
  }

  auto
  Permission_Class::release_async_vfunc_callback (
      GPermission* self,
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
          obj->release_async_vfunc (*slot, Glib::wrap (cancellable, true));
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

    if (base && base->release_async)
      (*base->release_async) (self, cancellable, callback, user_data);
  }

  auto
  Permission_Class::release_finish_vfunc_callback (GPermission* self,
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
          return obj->release_finish_vfunc (Glib::wrap (result, true));
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

    if (base && base->release_finish)
      return (*base->release_finish) (self, result, error);

    using RType = gboolean;
    return RType ();
  }

  auto
  Permission_Class::wrap_new (GObject* object) -> Glib::ObjectBase*
  {
    return new Permission ((GPermission*) object);
  }

  auto
  Permission::gobj_copy () -> GPermission*
  {
    reference ();
    return gobj ();
  }

  Permission::Permission (const Glib::ConstructParams& construct_params)
    : Object (construct_params)
  {
  }

  Permission::Permission (GPermission* castitem)
    : Object ((GObject*) castitem)
  {
  }

  Permission::Permission (Permission&& src) noexcept
    : Object (std::move (src))
  {
  }

  auto
  Permission::operator= (Permission&& src) noexcept -> Permission&
  {
    Object::operator= (std::move (src));
    return *this;
  }

  Permission::~Permission () noexcept = default;

  Permission::CppClassType Permission::permission_class_;

  auto
  Permission::get_type () -> GType
  {
    return permission_class_.init ().get_type ();
  }

  auto
  Permission::get_base_type () -> GType
  {
    return g_permission_get_type ();
  }

  auto
  Permission::acquire (const Glib::RefPtr<Cancellable>& cancellable) -> bool
  {
    GError* gerror = nullptr;
    const auto retvalue =
        g_permission_acquire (gobj (), Glib::unwrap (cancellable), &gerror);
    if (gerror)
      Glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  Permission::acquire () -> bool
  {
    GError* gerror = nullptr;
    const auto retvalue = g_permission_acquire (gobj (), nullptr, &gerror);
    if (gerror)
      Glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  Permission::acquire_async (const SlotAsyncReady& slot,
                             const Glib::RefPtr<Cancellable>& cancellable) -> void
  {
    const auto slot_copy = new SlotAsyncReady (slot);

    g_permission_acquire_async (gobj (),
                                Glib::unwrap (cancellable),
                                &SignalProxy_async_callback,
                                slot_copy);
  }

  auto
  Permission::acquire_async (const SlotAsyncReady& slot) -> void
  {
    const auto slot_copy = new SlotAsyncReady (slot);

    g_permission_acquire_async (gobj (),
                                nullptr,
                                &SignalProxy_async_callback,
                                slot_copy);
  }

  auto
  Permission::acquire_finish (const Glib::RefPtr<AsyncResult>& result) -> bool
  {
    GError* gerror = nullptr;
    const auto retvalue =
        g_permission_acquire_finish (gobj (), Glib::unwrap (result), &gerror);
    if (gerror)
      Glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  Permission::release (const Glib::RefPtr<Cancellable>& cancellable) -> bool
  {
    GError* gerror = nullptr;
    const auto retvalue =
        g_permission_release (gobj (), Glib::unwrap (cancellable), &gerror);
    if (gerror)
      Glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  Permission::release () -> bool
  {
    GError* gerror = nullptr;
    const auto retvalue = g_permission_release (gobj (), nullptr, &gerror);
    if (gerror)
      Glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  Permission::release_async (const SlotAsyncReady& slot,
                             const Glib::RefPtr<Cancellable>& cancellable) -> void
  {
    const auto slot_copy = new SlotAsyncReady (slot);

    g_permission_release_async (gobj (),
                                Glib::unwrap (cancellable),
                                &SignalProxy_async_callback,
                                slot_copy);
  }

  auto
  Permission::release_async (const SlotAsyncReady& slot) -> void
  {
    const auto slot_copy = new SlotAsyncReady (slot);

    g_permission_release_async (gobj (),
                                nullptr,
                                &SignalProxy_async_callback,
                                slot_copy);
  }

  auto
  Permission::release_finish (const Glib::RefPtr<AsyncResult>& result) -> bool
  {
    GError* gerror = nullptr;
    const auto retvalue =
        g_permission_release_finish (gobj (), Glib::unwrap (result), &gerror);
    if (gerror)
      Glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  Permission::get_allowed () const -> bool
  {
    return g_permission_get_allowed (const_cast<GPermission*> (gobj ()));
  }

  auto
  Permission::get_can_acquire () const -> bool
  {
    return g_permission_get_can_acquire (const_cast<GPermission*> (gobj ()));
  }

  auto
  Permission::get_can_release () const -> bool
  {
    return g_permission_get_can_release (const_cast<GPermission*> (gobj ()));
  }

  Permission::Permission ()
    : ObjectBase (nullptr),
      Object (Glib::ConstructParams (permission_class_.init ()))
  {
  }

  auto
  Permission::impl_update (const bool allowed,
                           const bool can_acquire,
                           const bool can_release) -> void
  {
    g_permission_impl_update (gobj (), allowed, can_acquire, can_release);
  }

  auto
  Permission::property_allowed () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return {this, "allowed"};
  }

  auto
  Permission::property_can_acquire () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return {this, "can-acquire"};
  }

  auto
  Permission::property_can_release () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return {this, "can-release"};
  }

  auto
  Permission::acquire_vfunc (const Glib::RefPtr<Cancellable>& cancellable) -> bool
  {
    const auto base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (gobject_)));

    if (base && base->acquire)
    {
      GError* gerror = nullptr;
      const bool retval (
          (*base->acquire) (gobj (), Glib::unwrap (cancellable), &gerror));
      if (gerror)
        Glib::Error::throw_exception (gerror);
      return retval;
    }

    using RType = bool;
    return RType ();
  }

  auto
  Permission::acquire_async_vfunc (const SlotAsyncReady& slot,
                                   const Glib::RefPtr<Cancellable>& cancellable) -> void
  {
    const auto slot_copy = new SlotAsyncReady (slot);

    const auto base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (gobject_)));

    if (base && base->acquire_async)
    {
      (*base->acquire_async) (gobj (),
                              Glib::unwrap (cancellable),
                              &SignalProxy_async_callback,
                              slot_copy);
    }
  }

  auto
  Permission::acquire_finish_vfunc (const Glib::RefPtr<AsyncResult>& result) -> bool
  {
    const auto base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (gobject_)));

    if (base && base->acquire_finish)
    {
      GError* gerror = nullptr;
      const bool retval (
          (*base->acquire_finish) (gobj (), Glib::unwrap (result), &gerror));
      if (gerror)
        Glib::Error::throw_exception (gerror);
      return retval;
    }

    using RType = bool;
    return RType ();
  }

  auto
  Permission::release_vfunc (const Glib::RefPtr<Cancellable>& cancellable) -> bool
  {
    const auto base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (gobject_)));

    if (base && base->release)
    {
      GError* gerror = nullptr;
      const bool retval (
          (*base->release) (gobj (), Glib::unwrap (cancellable), &gerror));
      if (gerror)
        Glib::Error::throw_exception (gerror);
      return retval;
    }

    using RType = bool;
    return RType ();
  }

  auto
  Permission::release_async_vfunc (const SlotAsyncReady& slot,
                                   const Glib::RefPtr<Cancellable>& cancellable) -> void
  {
    const auto slot_copy = new SlotAsyncReady (slot);

    const auto base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (gobject_)));

    if (base && base->release_async)
    {
      (*base->release_async) (gobj (),
                              Glib::unwrap (cancellable),
                              &SignalProxy_async_callback,
                              slot_copy);
    }
  }

  auto
  Permission::release_finish_vfunc (const Glib::RefPtr<AsyncResult>& result) -> bool
  {
    const auto base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (gobject_)));

    if (base && base->release_finish)
    {
      GError* gerror = nullptr;
      const bool retval (
          (*base->release_finish) (gobj (), Glib::unwrap (result), &gerror));
      if (gerror)
        Glib::Error::throw_exception (gerror);
      return retval;
    }

    using RType = bool;
    return RType ();
  }

} // namespace Gio
