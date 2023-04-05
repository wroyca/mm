// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/gio/outputstream.hxx>
#include <libmm/gio/outputstream_p.hxx>

#include <gio/gio.h>
#include <libmm/gio/slot_async.hxx>
#include <libmm/glib/error.hxx>
#include <libmm/glib/exceptionhandler.hxx>

using SpliceFlags = gio::OutputStream::SpliceFlags;

namespace gio
{

  auto
  OutputStream::write_async (const void* buffer,
                             const gsize count,
                             const SlotAsyncReady& slot,
                             const glib::RefPtr<Cancellable>& cancellable,
                             const int io_priority) -> void
  {
    const auto slot_copy = new SlotAsyncReady (slot);

    g_output_stream_write_async (gobj (),
                                 buffer,
                                 count,
                                 io_priority,
                                 glib::unwrap (cancellable),
                                 &SignalProxy_async_callback,
                                 slot_copy);
  }

  auto
  OutputStream::write_async (const void* buffer,
                             const gsize count,
                             const SlotAsyncReady& slot,
                             const int io_priority) -> void
  {
    const auto slot_copy = new SlotAsyncReady (slot);

    g_output_stream_write_async (gobj (),
                                 buffer,
                                 count,
                                 io_priority,
                                 nullptr,
                                 &SignalProxy_async_callback,
                                 slot_copy);
  }

  auto
  OutputStream::write_all_async (const void* buffer,
                                 const gsize count,
                                 const SlotAsyncReady& slot,
                                 const glib::RefPtr<Cancellable>& cancellable,
                                 const int io_priority) -> void
  {
    const auto slot_copy = new SlotAsyncReady (slot);

    g_output_stream_write_all_async (gobj (),
                                     buffer,
                                     count,
                                     io_priority,
                                     glib::unwrap (cancellable),
                                     &SignalProxy_async_callback,
                                     slot_copy);
  }

  auto
  OutputStream::write_all_async (const void* buffer,
                                 const gsize count,
                                 const SlotAsyncReady& slot,
                                 const int io_priority) -> void
  {
    const auto slot_copy = new SlotAsyncReady (slot);

    g_output_stream_write_all_async (gobj (),
                                     buffer,
                                     count,
                                     io_priority,
                                     nullptr,
                                     &SignalProxy_async_callback,
                                     slot_copy);
  }

  auto
  OutputStream::splice_async (const glib::RefPtr<InputStream>& source,
                              const SlotAsyncReady& slot,
                              const glib::RefPtr<Cancellable>& cancellable,
                              SpliceFlags flags,
                              const int io_priority) -> void
  {
    const auto slot_copy = new SlotAsyncReady (slot);

    g_output_stream_splice_async (gobj (),
                                  glib::unwrap (source),
                                  static_cast<GOutputStreamSpliceFlags> (flags),
                                  io_priority,
                                  glib::unwrap (cancellable),
                                  &SignalProxy_async_callback,
                                  slot_copy);
  }

  auto
  OutputStream::splice_async (const glib::RefPtr<InputStream>& source,
                              const SlotAsyncReady& slot,
                              SpliceFlags flags,
                              const int io_priority) -> void
  {
    const auto slot_copy = new SlotAsyncReady (slot);

    g_output_stream_splice_async (gobj (),
                                  glib::unwrap (source),
                                  static_cast<GOutputStreamSpliceFlags> (flags),
                                  io_priority,
                                  nullptr,
                                  &SignalProxy_async_callback,
                                  slot_copy);
  }

  auto
  OutputStream::flush_async (const SlotAsyncReady& slot,
                             const glib::RefPtr<Cancellable>& cancellable,
                             const int io_priority) -> void
  {
    const auto slot_copy = new SlotAsyncReady (slot);

    g_output_stream_flush_async (gobj (),
                                 io_priority,
                                 glib::unwrap (cancellable),
                                 &SignalProxy_async_callback,
                                 slot_copy);
  }

  auto
  OutputStream::flush_async (const SlotAsyncReady& slot, const int io_priority) -> void
  {
    const auto slot_copy = new SlotAsyncReady (slot);

    g_output_stream_flush_async (gobj (),
                                 io_priority,
                                 nullptr,
                                 &SignalProxy_async_callback,
                                 slot_copy);
  }

  auto
  OutputStream::close_async (const SlotAsyncReady& slot,
                             const glib::RefPtr<Cancellable>& cancellable,
                             const int io_priority) -> void
  {
    const auto slot_copy = new SlotAsyncReady (slot);

    g_output_stream_close_async (gobj (),
                                 io_priority,
                                 glib::unwrap (cancellable),
                                 &SignalProxy_async_callback,
                                 slot_copy);
  }

  auto
  OutputStream::close_async (const SlotAsyncReady& slot, const int io_priority) -> void
  {
    const auto slot_copy = new SlotAsyncReady (slot);

    g_output_stream_close_async (gobj (),
                                 io_priority,
                                 nullptr,
                                 &SignalProxy_async_callback,
                                 slot_copy);
  }

  auto
  OutputStream::write (const std::string& buffer,
                       const glib::RefPtr<Cancellable>& cancellable) -> gssize
  {
    GError* gerror = nullptr;
    const gssize retvalue = g_output_stream_write (gobj (),
                                                   buffer.data (),
                                                   buffer.size (),
                                                   glib::unwrap (cancellable),
                                                   &gerror);
    if (gerror)
      glib::Error::throw_exception (gerror);

    return retvalue;
  }

  auto
  OutputStream::write (const std::string& buffer) -> gssize
  {
    GError* gerror = nullptr;
    const gssize retvalue = g_output_stream_write (gobj (),
                                                   buffer.data (),
                                                   buffer.size (),
                                                   nullptr,
                                                   &gerror);
    if (gerror)
      glib::Error::throw_exception (gerror);

    return retvalue;
  }

  auto
  OutputStream::write_all (const std::string& buffer,
                           gsize& bytes_written,
                           const glib::RefPtr<Cancellable>& cancellable) -> bool
  {
    GError* gerror = nullptr;
    const bool retvalue = g_output_stream_write_all (gobj (),
                                                     buffer.data (),
                                                     buffer.size (),
                                                     &bytes_written,
                                                     glib::unwrap (cancellable),
                                                     &gerror);
    if (gerror)
      glib::Error::throw_exception (gerror);

    return retvalue;
  }

  auto
  OutputStream::write_all (const std::string& buffer, gsize& bytes_written) -> bool
  {
    GError* gerror = nullptr;
    const bool retvalue = g_output_stream_write_all (gobj (),
                                                     buffer.data (),
                                                     buffer.size (),
                                                     &bytes_written,
                                                     nullptr,
                                                     &gerror);
    if (gerror)
      glib::Error::throw_exception (gerror);

    return retvalue;
  }

  auto
  OutputStream::write_bytes_async (const glib::RefPtr<const glib::Bytes>& bytes,
                                   const SlotAsyncReady& slot,
                                   const glib::RefPtr<Cancellable>& cancellable,
                                   const int io_priority) -> void
  {
    SlotAsyncReady* slot_copy = new SlotAsyncReady (slot);

    g_output_stream_write_bytes_async (gobj (),
                                       const_cast<GBytes*> (unwrap (bytes)),
                                       io_priority,
                                       glib::unwrap (cancellable),
                                       &SignalProxy_async_callback,
                                       slot_copy);
  }

  auto
  OutputStream::write_bytes_async (const glib::RefPtr<const glib::Bytes>& bytes,
                                   const SlotAsyncReady& slot,
                                   const int io_priority) -> void
  {
    SlotAsyncReady* slot_copy = new SlotAsyncReady (slot);

    g_output_stream_write_bytes_async (gobj (),
                                       const_cast<GBytes*> (unwrap (bytes)),
                                       io_priority,
                                       nullptr,
                                       &SignalProxy_async_callback,
                                       slot_copy);
  }

  auto
  OutputStream::splice (const glib::RefPtr<InputStream>& source,
                        const glib::RefPtr<Cancellable>& cancellable,
                        SpliceFlags flags) -> gssize
  {
    GError* gerror = nullptr;
    const gssize retvalue = g_output_stream_splice (
        gobj (),
        glib::unwrap (source),
        (GOutputStreamSpliceFlags) flags,
        glib::unwrap (cancellable),
        &gerror);
    if (gerror)
      glib::Error::throw_exception (gerror);

    return retvalue;
  }

  auto
  OutputStream::splice (const glib::RefPtr<InputStream>& source,
                        SpliceFlags flags) -> gssize
  {
    GError* gerror = nullptr;
    const gssize retvalue = g_output_stream_splice (
        gobj (),
        glib::unwrap (source),
        (GOutputStreamSpliceFlags) flags,
        nullptr,
        &gerror);
    if (gerror)
      glib::Error::throw_exception (gerror);

    return retvalue;
  }

} // namespace gio

namespace
{
}

namespace glib
{

  auto
  wrap (GOutputStream* object, const bool take_copy) -> RefPtr<gio::OutputStream>
  {
    return glib::make_refptr_for_instance<gio::OutputStream> (
        dynamic_cast<gio::OutputStream*> (
            wrap_auto ((GObject*) object, take_copy)));
  }

} // namespace glib

namespace gio
{

  auto
  OutputStream_Class::init () -> const Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &OutputStream_Class::class_init_function;

      register_derived_type (g_output_stream_get_type ());
    }

    return *this;
  }

  auto
  OutputStream_Class::class_init_function (void* g_class, void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);

    klass->write_fn = &write_fn_vfunc_callback;
    klass->splice = &splice_vfunc_callback;
    klass->flush = &flush_vfunc_callback;
    klass->close_fn = &close_fn_vfunc_callback;
  }

  auto
  OutputStream_Class::write_fn_vfunc_callback (GOutputStream* self,
                                               const void* buffer,
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
          return obj->write_vfunc (buffer,
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

    if (base && base->write_fn)
      return (*base->write_fn) (self, buffer, count, cancellable, error);

    using RType = gssize;
    return RType ();
  }

  auto
  OutputStream_Class::splice_vfunc_callback (GOutputStream* self,
                                             GInputStream* source,
                                             GOutputStreamSpliceFlags flags,
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
          return obj->splice_vfunc (glib::wrap (source, true),
                                    glib::wrap (cancellable, true),
                                    static_cast<SpliceFlags> (flags));
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

    if (base && base->splice)
      return (*base->splice) (self, source, flags, cancellable, error);

    using RType = gssize;
    return RType ();
  }

  auto
  OutputStream_Class::flush_vfunc_callback (GOutputStream* self,
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
          return obj->flush_vfunc (glib::wrap (cancellable, true));
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

    if (base && base->flush)
      return (*base->flush) (self, cancellable, error);

    using RType = gboolean;
    return RType ();
  }

  auto
  OutputStream_Class::close_fn_vfunc_callback (GOutputStream* self,
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
  OutputStream_Class::wrap_new (GObject* object) -> glib::ObjectBase*
  {
    return new OutputStream ((GOutputStream*) object);
  }

  auto
  OutputStream::gobj_copy () -> GOutputStream*
  {
    reference ();
    return gobj ();
  }

  OutputStream::OutputStream (const glib::ConstructParams& construct_params)
    : Object (construct_params)
  {
  }

  OutputStream::OutputStream (GOutputStream* castitem)
    : Object ((GObject*) castitem)
  {
  }

  OutputStream::OutputStream (OutputStream&& src) noexcept
    : Object (std::move (src))
  {
  }

  auto
  OutputStream::operator= (OutputStream&& src) noexcept -> OutputStream&
  {
    Object::operator= (std::move (src));
    return *this;
  }

  OutputStream::~OutputStream () noexcept = default;

  OutputStream::CppClassType OutputStream::outputstream_class_;

  auto
  OutputStream::get_type () -> GType
  {
    return outputstream_class_.init ().get_type ();
  }

  auto
  OutputStream::get_base_type () -> GType
  {
    return g_output_stream_get_type ();
  }

  OutputStream::OutputStream ()
    : ObjectBase (nullptr),
      Object (glib::ConstructParams (outputstream_class_.init ()))
  {
  }

  auto
  OutputStream::write (const void* buffer,
                       const gsize count,
                       const glib::RefPtr<Cancellable>& cancellable) -> gssize
  {
    GError* gerror = nullptr;
    const auto retvalue = g_output_stream_write (gobj (),
                                                 buffer,
                                                 count,
                                                 glib::unwrap (cancellable),
                                                 &gerror);
    if (gerror)
      glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  OutputStream::write (const void* buffer, const gsize count) -> gssize
  {
    GError* gerror = nullptr;
    const auto retvalue =
        g_output_stream_write (gobj (), buffer, count, nullptr, &gerror);
    if (gerror)
      glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  OutputStream::write_all (const void* buffer,
                           const gsize count,
                           gsize& bytes_written,
                           const glib::RefPtr<Cancellable>& cancellable) -> bool
  {
    GError* gerror = nullptr;
    const auto retvalue = g_output_stream_write_all (gobj (),
                                                     buffer,
                                                     count,
                                                     &bytes_written,
                                                     glib::unwrap (cancellable),
                                                     &gerror);
    if (gerror)
      glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  OutputStream::write_all (const void* buffer,
                           const gsize count,
                           gsize& bytes_written) -> bool
  {
    GError* gerror = nullptr;
    const auto retvalue = g_output_stream_write_all (gobj (),
                                                     buffer,
                                                     count,
                                                     &bytes_written,
                                                     nullptr,
                                                     &gerror);
    if (gerror)
      glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  OutputStream::write_bytes (const glib::RefPtr<const glib::Bytes>& bytes,
                             const glib::RefPtr<Cancellable>& cancellable) -> gssize
  {
    GError* gerror = nullptr;
    const auto retvalue = g_output_stream_write_bytes (
        gobj (),
        const_cast<GBytes*> (glib::unwrap<glib::Bytes> (bytes)),
        glib::unwrap (cancellable),
        &gerror);
    if (gerror)
      glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  OutputStream::write_bytes (const glib::RefPtr<const glib::Bytes>& bytes) -> gssize
  {
    GError* gerror = nullptr;
    const auto retvalue = g_output_stream_write_bytes (
        gobj (),
        const_cast<GBytes*> (glib::unwrap<glib::Bytes> (bytes)),
        nullptr,
        &gerror);
    if (gerror)
      glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  OutputStream::write_bytes_finish (const glib::RefPtr<AsyncResult>& result) -> gssize
  {
    GError* gerror = nullptr;
    const auto retvalue = g_output_stream_write_bytes_finish (
        gobj (),
        glib::unwrap (result),
        &gerror);
    if (gerror)
      glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  OutputStream::flush (const glib::RefPtr<Cancellable>& cancellable) -> bool
  {
    GError* gerror = nullptr;
    const auto retvalue =
        g_output_stream_flush (gobj (), glib::unwrap (cancellable), &gerror);
    if (gerror)
      glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  OutputStream::flush () -> bool
  {
    GError* gerror = nullptr;
    const auto retvalue = g_output_stream_flush (gobj (), nullptr, &gerror);
    if (gerror)
      glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  OutputStream::close (const glib::RefPtr<Cancellable>& cancellable) -> bool
  {
    GError* gerror = nullptr;
    const auto retvalue =
        g_output_stream_close (gobj (), glib::unwrap (cancellable), &gerror);
    if (gerror)
      glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  OutputStream::close () -> bool
  {
    GError* gerror = nullptr;
    const auto retvalue = g_output_stream_close (gobj (), nullptr, &gerror);
    if (gerror)
      glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  OutputStream::write_finish (const glib::RefPtr<AsyncResult>& result) -> gssize
  {
    GError* gerror = nullptr;
    const auto retvalue =
        g_output_stream_write_finish (gobj (), glib::unwrap (result), &gerror);
    if (gerror)
      glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  OutputStream::write_all_finish (const glib::RefPtr<AsyncResult>& result,
                                  gsize& bytes_written) -> bool
  {
    GError* gerror = nullptr;
    const auto retvalue = g_output_stream_write_all_finish (
        gobj (),
        glib::unwrap (result),
        &bytes_written,
        &gerror);
    if (gerror)
      glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  OutputStream::splice_finish (const glib::RefPtr<AsyncResult>& result) -> gssize
  {
    GError* gerror = nullptr;
    const auto retvalue =
        g_output_stream_splice_finish (gobj (), glib::unwrap (result), &gerror);
    if (gerror)
      glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  OutputStream::flush_finish (const glib::RefPtr<AsyncResult>& result) -> bool
  {
    GError* gerror = nullptr;
    const auto retvalue =
        g_output_stream_flush_finish (gobj (), glib::unwrap (result), &gerror);
    if (gerror)
      glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  OutputStream::close_finish (const glib::RefPtr<AsyncResult>& result) -> bool
  {
    GError* gerror = nullptr;
    const auto retvalue =
        g_output_stream_close_finish (gobj (), glib::unwrap (result), &gerror);
    if (gerror)
      glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  OutputStream::is_closed () const -> bool
  {
    return g_output_stream_is_closed (const_cast<GOutputStream*> (gobj ()));
  }

  auto
  OutputStream::is_closing () const -> bool
  {
    return g_output_stream_is_closing (const_cast<GOutputStream*> (gobj ()));
  }

  auto
  OutputStream::has_pending () const -> bool
  {
    return g_output_stream_has_pending (const_cast<GOutputStream*> (gobj ()));
  }

  auto
  OutputStream::set_pending () -> bool
  {
    GError* gerror = nullptr;
    const auto retvalue = g_output_stream_set_pending (gobj (), &gerror);
    if (gerror)
      glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  OutputStream::clear_pending () -> void
  {
    g_output_stream_clear_pending (gobj ());
  }

  auto
  OutputStream::write_vfunc (const void* buffer,
                             const gsize count,
                             const glib::RefPtr<Cancellable>& cancellable) -> gssize
  {
    const auto base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (gobject_)));

    if (base && base->write_fn)
    {
      GError* gerror = nullptr;
      const gssize retval ((*base->write_fn) (gobj (),
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
  OutputStream::splice_vfunc (const glib::RefPtr<InputStream>& source,
                              const glib::RefPtr<Cancellable>& cancellable,
                              SpliceFlags flags) -> gssize
  {
    const auto base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (gobject_)));

    if (base && base->splice)
    {
      GError* gerror = nullptr;
      const gssize retval (
          (*base->splice) (gobj (),
                           glib::unwrap (source),
                           static_cast<GOutputStreamSpliceFlags> (flags),
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
  OutputStream::flush_vfunc (const glib::RefPtr<Cancellable>& cancellable) -> bool
  {
    const auto base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (gobject_)));

    if (base && base->flush)
    {
      GError* gerror = nullptr;
      const bool retval (
          (*base->flush) (gobj (), glib::unwrap (cancellable), &gerror));
      if (gerror)
        glib::Error::throw_exception (gerror);
      return retval;
    }

    using RType = bool;
    return RType ();
  }

  auto
  OutputStream::close_vfunc (const glib::RefPtr<Cancellable>& cancellable) -> bool
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
