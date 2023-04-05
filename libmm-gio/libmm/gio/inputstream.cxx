// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/gio/inputstream.hxx>
#include <libmm/gio/inputstream_p.hxx>

#include <gio/gio.h>
#include <libmm/gio/asyncresult.hxx>
#include <libmm/gio/slot_async.hxx>
#include <libmm/glib/error.hxx>

namespace gio
{

  auto
  InputStream::read_async (void* buffer,
                           const gsize count,
                           const SlotAsyncReady& slot,
                           const glib::RefPtr<Cancellable>& cancellable,
                           const int io_priority) -> void
  {
    const auto slot_copy = new SlotAsyncReady (slot);

    g_input_stream_read_async (gobj (),
                               buffer,
                               count,
                               io_priority,
                               glib::unwrap (cancellable),
                               &SignalProxy_async_callback,
                               slot_copy);
  }

  auto
  InputStream::read_async (void* buffer,
                           const gsize count,
                           const SlotAsyncReady& slot,
                           const int io_priority) -> void
  {
    const auto slot_copy = new SlotAsyncReady (slot);

    g_input_stream_read_async (gobj (),
                               buffer,
                               count,
                               io_priority,
                               nullptr,
                               &SignalProxy_async_callback,
                               slot_copy);
  }

  auto
  InputStream::read_all_async (void* buffer,
                               const gsize count,
                               const SlotAsyncReady& slot,
                               const glib::RefPtr<Cancellable>& cancellable,
                               const int io_priority) -> void
  {
    const auto slot_copy = new SlotAsyncReady (slot);

    g_input_stream_read_all_async (gobj (),
                                   buffer,
                                   count,
                                   io_priority,
                                   glib::unwrap (cancellable),
                                   &SignalProxy_async_callback,
                                   slot_copy);
  }

  auto
  InputStream::read_all_async (void* buffer,
                               const gsize count,
                               const SlotAsyncReady& slot,
                               const int io_priority) -> void
  {
    const auto slot_copy = new SlotAsyncReady (slot);

    g_input_stream_read_all_async (gobj (),
                                   buffer,
                                   count,
                                   io_priority,
                                   nullptr,
                                   &SignalProxy_async_callback,
                                   slot_copy);
  }

  auto
  InputStream::read_bytes_async (const gsize count,
                                 const SlotAsyncReady& slot,
                                 const glib::RefPtr<Cancellable>& cancellable,
                                 const int io_priority) -> void
  {
    const auto slot_copy = new SlotAsyncReady (slot);

    g_input_stream_read_bytes_async (gobj (),
                                     count,
                                     io_priority,
                                     glib::unwrap (cancellable),
                                     &SignalProxy_async_callback,
                                     slot_copy);
  }

  auto
  InputStream::read_bytes_async (const gsize count,
                                 const SlotAsyncReady& slot,
                                 const int io_priority) -> void
  {
    const auto slot_copy = new SlotAsyncReady (slot);

    g_input_stream_read_bytes_async (gobj (),
                                     count,
                                     io_priority,
                                     nullptr,
                                     &SignalProxy_async_callback,
                                     slot_copy);
  }

  auto
  InputStream::skip_async (const gsize count,
                           const SlotAsyncReady& slot,
                           const glib::RefPtr<Cancellable>& cancellable,
                           const int io_priority) -> void
  {
    const auto slot_copy = new SlotAsyncReady (slot);

    g_input_stream_skip_async (gobj (),
                               count,
                               io_priority,
                               glib::unwrap (cancellable),
                               &SignalProxy_async_callback,
                               slot_copy);
  }

  auto
  InputStream::skip_async (const gsize count,
                           const SlotAsyncReady& slot,
                           const int io_priority) -> void
  {
    const auto slot_copy = new SlotAsyncReady (slot);

    g_input_stream_skip_async (gobj (),
                               count,
                               io_priority,
                               nullptr,
                               &SignalProxy_async_callback,
                               slot_copy);
  }

  auto
  InputStream::close_async (const SlotAsyncReady& slot,
                            const glib::RefPtr<Cancellable>& cancellable,
                            const int io_priority) -> void
  {
    const auto slot_copy = new SlotAsyncReady (slot);

    g_input_stream_close_async (gobj (),
                                io_priority,
                                glib::unwrap (cancellable),
                                &SignalProxy_async_callback,
                                slot_copy);
  }

  auto
  InputStream::close_async (const SlotAsyncReady& slot, const int io_priority) -> void
  {
    const auto slot_copy = new SlotAsyncReady (slot);

    g_input_stream_close_async (gobj (),
                                io_priority,
                                nullptr,
                                &SignalProxy_async_callback,
                                slot_copy);
  }

} // namespace gio

namespace
{
}

namespace glib
{

  auto
  wrap (GInputStream* object, const bool take_copy) -> RefPtr<gio::InputStream>
  {
    return glib::make_refptr_for_instance<gio::InputStream> (
        dynamic_cast<gio::InputStream*> (
            wrap_auto ((GObject*) object, take_copy)));
  }

} // namespace glib

namespace gio
{

  auto
  InputStream_Class::init () -> const Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &InputStream_Class::class_init_function;

      register_derived_type (g_input_stream_get_type ());
    }

    return *this;
  }

  auto
  InputStream_Class::class_init_function (void* g_class, void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);

    klass->read_fn = &read_fn_vfunc_callback;
    klass->skip = &skip_vfunc_callback;
    klass->close_fn = &close_fn_vfunc_callback;
  }

  auto
  InputStream_Class::read_fn_vfunc_callback (GInputStream* self,
                                             void* buffer,
                                             const gsize count,
                                             GCancellable* cancellable,
                                             GError** error) -> gssize
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
          return obj->read_vfunc (buffer,
                                  count,
                                  glib::wrap (cancellable, true));
        }
        catch (glib::Error& errormm)
        {
          errormm.propagate (error);
          return -1;
        }
        catch (...)
        {
          glib::exception_handlers_invoke ();
        }
      }
    }

    const BaseClassType* const base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (self)));

    if (base && base->read_fn)
      return (*base->read_fn) (self, buffer, count, cancellable, error);

    using RType = gssize;
    return RType ();
  }

  auto
  InputStream_Class::skip_vfunc_callback (GInputStream* self,
                                          const gsize count,
                                          GCancellable* cancellable,
                                          GError** error) -> gssize
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
          return obj->skip_vfunc (count, glib::wrap (cancellable, true));
        }
        catch (glib::Error& errormm)
        {
          errormm.propagate (error);
          return -1;
        }
        catch (...)
        {
          glib::exception_handlers_invoke ();
        }
      }
    }

    const BaseClassType* const base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (self)));

    if (base && base->skip)
      return (*base->skip) (self, count, cancellable, error);

    using RType = gssize;
    return RType ();
  }

  auto
  InputStream_Class::close_fn_vfunc_callback (GInputStream* self,
                                              GCancellable* cancellable,
                                              GError** error) -> gboolean
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
          return obj->close_vfunc (glib::wrap (cancellable, true));
        }
        catch (glib::Error& errormm)
        {
          errormm.propagate (error);
          using RType = gboolean;
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

    if (base && base->close_fn)
      return (*base->close_fn) (self, cancellable, error);

    using RType = gboolean;
    return RType ();
  }

  auto
  InputStream_Class::wrap_new (GObject* object) -> glib::ObjectBase*
  {
    return new InputStream ((GInputStream*) object);
  }

  auto
  InputStream::gobj_copy () -> GInputStream*
  {
    reference ();
    return gobj ();
  }

  InputStream::InputStream (const glib::ConstructParams& construct_params)
    : Object (construct_params)
  {
  }

  InputStream::InputStream (GInputStream* castitem)
    : Object ((GObject*) castitem)
  {
  }

  InputStream::InputStream (InputStream&& src) noexcept
    : Object (std::move (src))
  {
  }

  auto
  InputStream::operator= (InputStream&& src) noexcept -> InputStream&
  {
    Object::operator= (std::move (src));
    return *this;
  }

  InputStream::~InputStream () noexcept = default;

  InputStream::CppClassType InputStream::inputstream_class_;

  auto
  InputStream::get_type () -> GType
  {
    return inputstream_class_.init ().get_type ();
  }

  auto
  InputStream::get_base_type () -> GType
  {
    return g_input_stream_get_type ();
  }

  InputStream::InputStream ()
    : ObjectBase (nullptr),
      Object (glib::ConstructParams (inputstream_class_.init ()))
  {
  }

  auto
  InputStream::read (void* buffer,
                     const gsize count,
                     const glib::RefPtr<Cancellable>& cancellable) -> gssize
  {
    GError* gerror = nullptr;
    const auto retvalue = g_input_stream_read (gobj (),
                                               buffer,
                                               count,
                                               glib::unwrap (cancellable),
                                               &gerror);
    if (gerror)
      glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  InputStream::read (void* buffer, const gsize count) -> gssize
  {
    GError* gerror = nullptr;
    const auto retvalue =
        g_input_stream_read (gobj (), buffer, count, nullptr, &gerror);
    if (gerror)
      glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  InputStream::read_all (void* buffer,
                         const gsize count,
                         gsize& bytes_read,
                         const glib::RefPtr<Cancellable>& cancellable) -> bool
  {
    GError* gerror = nullptr;
    const auto retvalue = g_input_stream_read_all (gobj (),
                                                   buffer,
                                                   count,
                                                   &bytes_read,
                                                   glib::unwrap (cancellable),
                                                   &gerror);
    if (gerror)
      glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  InputStream::read_all (void* buffer, const gsize count, gsize& bytes_read) -> bool
  {
    GError* gerror = nullptr;
    const auto retvalue = g_input_stream_read_all (gobj (),
                                                   buffer,
                                                   count,
                                                   &bytes_read,
                                                   nullptr,
                                                   &gerror);
    if (gerror)
      glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  InputStream::read_bytes (const gsize count,
                           const glib::RefPtr<Cancellable>& cancellable) -> glib::RefPtr<glib::Bytes>
  {
    GError* gerror = nullptr;
    auto retvalue =
        glib::wrap (g_input_stream_read_bytes (gobj (),
                                               count,
                                               glib::unwrap (cancellable),
                                               &gerror));
    if (gerror)
      glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  InputStream::read_bytes_finish (const glib::RefPtr<AsyncResult>& result) -> glib::RefPtr<glib::Bytes>
  {
    GError* gerror = nullptr;
    auto retvalue =
        glib::wrap (g_input_stream_read_bytes_finish (gobj (),
                                                      glib::unwrap (result),
                                                      &gerror));
    if (gerror)
      glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  InputStream::skip (const gsize count,
                     const glib::RefPtr<Cancellable>& cancellable) -> gssize
  {
    GError* gerror = nullptr;
    const auto retvalue = g_input_stream_skip (gobj (),
                                               count,
                                               glib::unwrap (cancellable),
                                               &gerror);
    if (gerror)
      glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  InputStream::skip (const gsize count) -> gssize
  {
    GError* gerror = nullptr;
    const auto retvalue =
        g_input_stream_skip (gobj (), count, nullptr, &gerror);
    if (gerror)
      glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  InputStream::close (const glib::RefPtr<Cancellable>& cancellable) -> bool
  {
    GError* gerror = nullptr;
    const auto retvalue =
        g_input_stream_close (gobj (), glib::unwrap (cancellable), &gerror);
    if (gerror)
      glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  InputStream::close () -> bool
  {
    GError* gerror = nullptr;
    const auto retvalue = g_input_stream_close (gobj (), nullptr, &gerror);
    if (gerror)
      glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  InputStream::read_finish (const glib::RefPtr<AsyncResult>& result) -> gssize
  {
    GError* gerror = nullptr;
    const auto retvalue =
        g_input_stream_read_finish (gobj (), glib::unwrap (result), &gerror);
    if (gerror)
      glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  InputStream::read_all_finish (const glib::RefPtr<AsyncResult>& result,
                                gsize& bytes_read) -> bool
  {
    GError* gerror = nullptr;
    const auto retvalue = g_input_stream_read_all_finish (gobj (),
                                                          glib::unwrap (result),
                                                          &bytes_read,
                                                          &gerror);
    if (gerror)
      glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  InputStream::skip_finish (const glib::RefPtr<AsyncResult>& result) -> gssize
  {
    GError* gerror = nullptr;
    const auto retvalue =
        g_input_stream_skip_finish (gobj (), glib::unwrap (result), &gerror);
    if (gerror)
      glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  InputStream::close_finish (const glib::RefPtr<AsyncResult>& result) -> gboolean
  {
    GError* gerror = nullptr;
    const auto retvalue =
        g_input_stream_close_finish (gobj (), glib::unwrap (result), &gerror);
    if (gerror)
      glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  InputStream::is_closed () const -> bool
  {
    return g_input_stream_is_closed (const_cast<GInputStream*> (gobj ()));
  }

  auto
  InputStream::has_pending () const -> bool
  {
    return g_input_stream_has_pending (const_cast<GInputStream*> (gobj ()));
  }

  auto
  InputStream::set_pending () -> bool
  {
    GError* gerror = nullptr;
    const auto retvalue = g_input_stream_set_pending (gobj (), &gerror);
    if (gerror)
      glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  InputStream::clear_pending () -> void
  {
    g_input_stream_clear_pending (gobj ());
  }

  auto
  InputStream::read_vfunc (void* buffer,
                           const gsize count,
                           const glib::RefPtr<Cancellable>& cancellable) -> gssize
  {
    const auto base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (gobject_)));

    if (base && base->read_fn)
    {
      GError* gerror = nullptr;
      const gssize retval ((*base->read_fn) (gobj (),
                                             buffer,
                                             count,
                                             glib::unwrap (cancellable),
                                             &gerror));
      if (gerror)
        glib::Error::throw_exception (gerror);
      return retval;
    }

    using RType = gssize;
    return RType ();
  }

  auto
  InputStream::skip_vfunc (const gsize count,
                           const glib::RefPtr<Cancellable>& cancellable) -> gssize
  {
    const auto base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (gobject_)));

    if (base && base->skip)
    {
      GError* gerror = nullptr;
      const gssize retval (
          (*base->skip) (gobj (), count, glib::unwrap (cancellable), &gerror));
      if (gerror)
        glib::Error::throw_exception (gerror);
      return retval;
    }

    using RType = gssize;
    return RType ();
  }

  auto
  InputStream::close_vfunc (const glib::RefPtr<Cancellable>& cancellable) -> bool
  {
    const auto base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (gobject_)));

    if (base && base->close_fn)
    {
      GError* gerror = nullptr;
      const bool retval (
          (*base->close_fn) (gobj (), glib::unwrap (cancellable), &gerror));
      if (gerror)
        glib::Error::throw_exception (gerror);
      return retval;
    }

    using RType = bool;
    return RType ();
  }

} // namespace gio
