// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm-glib/mm-glib.hxx>

#include <libmm-gio/asyncinitable.hxx>
#include <libmm-gio/asyncinitable_p.hxx>

#include <gio/gio.h>
#include <libmm-gio/cancellable.hxx>
#include <libmm-gio/slot_async.hxx>
#include <libmm-glib/error.hxx>
#include <libmm-glib/exceptionhandler.hxx>

namespace Gio
{

  auto
  AsyncInitable::init_async (const SlotAsyncReady& slot,
                             const Glib::RefPtr<Cancellable>& cancellable,
                             const int io_priority) -> void
  {
    const auto slot_copy = new SlotAsyncReady (slot);

    g_async_initable_init_async (gobj (),
                                 io_priority,
                                 Glib::unwrap (cancellable),
                                 &SignalProxy_async_callback,
                                 slot_copy);
  }

  auto
  AsyncInitable::init_async (const SlotAsyncReady& slot, const int io_priority) -> void
  {
    const auto slot_copy = new SlotAsyncReady (slot);

    g_async_initable_init_async (gobj (),
                                 io_priority,
                                 nullptr,
                                 &SignalProxy_async_callback,
                                 slot_copy);
  }

  auto
  AsyncInitable_Class::init_async_vfunc_callback (
      GAsyncInitable* self,
      const int io_priority,
      GCancellable* cancellable,
      const GAsyncReadyCallback callback,
      const gpointer user_data) -> void
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
          const SlotAsyncReady* the_slot =
              static_cast<SlotAsyncReady*> (user_data);

          obj->init_async_vfunc (*the_slot,
                                 Glib::wrap (cancellable, true),
                                 io_priority);
          return;
        }
        catch (...)
        {
          Glib::exception_handlers_invoke ();
        }
      }
    }

    const auto base =
        static_cast<BaseClassType*> (g_type_interface_peek_parent (

            g_type_interface_peek (G_OBJECT_GET_CLASS (self),
                                   CppObjectType::get_type ())));

    if (base && base->init_async)
      (*base->init_async) (self, io_priority, cancellable, callback, user_data);
  }

  auto
  AsyncInitable::init_async_vfunc (const SlotAsyncReady& slot,
                                   const Glib::RefPtr<Cancellable>& cancellable,
                                   const int io_priority) -> void
  {
    const auto base =
        static_cast<BaseClassType*> (g_type_interface_peek_parent (

            g_type_interface_peek (G_OBJECT_GET_CLASS (gobject_),
                                   get_type ())));

    if (base && base->init_async)
    {
      (*base->init_async) (gobj (),
                           io_priority,
                           Glib::unwrap (cancellable),
                           &SignalProxy_async_callback,
                           const_cast<SlotAsyncReady*> (&slot));
    }
  }

  auto
  AsyncInitable_Class::init_finish_vfunc_callback (GAsyncInitable* self,
                                                   GAsyncResult* res,
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
          return obj->init_finish_vfunc (Glib::wrap (res, true));
        }
        catch (...)
        {
          Glib::exception_handlers_invoke ();
        }
      }
    }

    const auto base =
        static_cast<BaseClassType*> (g_type_interface_peek_parent (

            g_type_interface_peek (G_OBJECT_GET_CLASS (self),
                                   CppObjectType::get_type ())));

    if (base && base->init_finish)
      return (*base->init_finish) (self, res, error);

    using RType = gboolean;
    return RType ();
  }

  auto
  AsyncInitable::init_finish_vfunc (const Glib::RefPtr<AsyncResult>& res) -> bool
  {
    const auto base =
        static_cast<BaseClassType*> (g_type_interface_peek_parent (

            g_type_interface_peek (G_OBJECT_GET_CLASS (gobject_),
                                   get_type ())));

    if (base && base->init_finish)
    {
      GError* gerror = nullptr;

      const bool result =
          (*base->init_finish) (gobj (), Glib::unwrap (res), &gerror);

      if (gerror)
        Glib::Error::throw_exception (gerror);

      return result;
    }

    using RType = bool;
    return RType ();
  }

} // namespace Gio

namespace
{
}

namespace Glib
{

  auto
  wrap (GAsyncInitable* object, const bool take_copy) -> RefPtr<Gio::AsyncInitable>
  {
    return Glib::make_refptr_for_instance<Gio::AsyncInitable> (
        Glib::wrap_auto_interface<Gio::AsyncInitable> ((GObject*) object,
                                                       take_copy));
  }

} // namespace Glib

namespace Gio
{

  auto
  AsyncInitable_Class::init () -> const Interface_Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &AsyncInitable_Class::iface_init_function;

      gtype_ = g_async_initable_get_type ();
    }

    return *this;
  }

  auto
  AsyncInitable_Class::iface_init_function (void* g_iface, void*) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_iface);

    g_assert (klass != nullptr);

    klass->init_async = &init_async_vfunc_callback;
    klass->init_finish = &init_finish_vfunc_callback;
  }

  auto
  AsyncInitable_Class::wrap_new (GObject* object) -> Glib::ObjectBase*
  {
    return new AsyncInitable ((GAsyncInitable*) object);
  }

  AsyncInitable::AsyncInitable ()
    : Interface (asyncinitable_class_.init ())
  {
  }

  AsyncInitable::AsyncInitable (GAsyncInitable* castitem)
    : Interface ((GObject*) castitem)
  {
  }

  AsyncInitable::AsyncInitable (const Glib::Interface_Class& interface_class)
    : Interface (interface_class)
  {
  }

  AsyncInitable::AsyncInitable (AsyncInitable&& src) noexcept
    : Interface (std::move (src))
  {
  }

  auto
  AsyncInitable::operator= (AsyncInitable&& src) noexcept -> AsyncInitable&
  {
    Interface::operator= (std::move (src));
    return *this;
  }

  AsyncInitable::~AsyncInitable () noexcept = default;

  auto
  AsyncInitable::add_interface (const GType gtype_implementer) -> void
  {
    asyncinitable_class_.init ().add_interface (gtype_implementer);
  }

  AsyncInitable::CppClassType AsyncInitable::asyncinitable_class_;

  auto
  AsyncInitable::get_type () -> GType
  {
    return asyncinitable_class_.init ().get_type ();
  }

  auto
  AsyncInitable::get_base_type () -> GType
  {
    return g_async_initable_get_type ();
  }

  auto
  AsyncInitable::init_finish (const Glib::RefPtr<AsyncResult>& res) -> bool
  {
    GError* gerror = nullptr;
    const auto retvalue =
        g_async_initable_init_finish (gobj (), Glib::unwrap (res), &gerror);
    if (gerror)
      Glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  AsyncInitable::create_finish (const Glib::RefPtr<AsyncResult>& res) -> Glib::RefPtr<Glib::Object>
  {
    GError* gerror = nullptr;
    auto retvalue = Glib::wrap (
        g_async_initable_new_finish (gobj (), Glib::unwrap (res), &gerror));
    if (gerror)
      Glib::Error::throw_exception (gerror);
    return retvalue;
  }

} // namespace Gio
