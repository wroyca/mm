// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/gio/bufferedinputstream.hxx>
#include <libmm/gio/bufferedinputstream_p.hxx>

#include <gio/gio.h>
#include <libmm/gio/slot_async.hxx>
#include <libmm/glib/error.hxx>

namespace gio
{
  auto
  BufferedInputStream::create_sized (
      const glib::RefPtr<InputStream>& base_stream,
      const gsize buffer_size) -> glib::RefPtr<BufferedInputStream>
  {
    return glib::make_refptr_for_instance<BufferedInputStream> (
        new BufferedInputStream (base_stream, buffer_size));
  }

  auto
  BufferedInputStream::fill_async (const SlotAsyncReady& slot,
                                   const gssize count,
                                   const glib::RefPtr<Cancellable>& cancellable,
                                   const int io_priority) -> void
  {
    const auto slot_copy = new SlotAsyncReady (slot);

    g_buffered_input_stream_fill_async (gobj (),
                                        count,
                                        io_priority,
                                        glib::unwrap (cancellable),
                                        &SignalProxy_async_callback,
                                        slot_copy);
  }

  auto
  BufferedInputStream::fill_async (const SlotAsyncReady& slot,
                                   const gssize count,
                                   const int io_priority) -> void
  {
    const auto slot_copy = new SlotAsyncReady (slot);

    g_buffered_input_stream_fill_async (gobj (),
                                        count,
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
  wrap (GBufferedInputStream* object, const bool take_copy) -> RefPtr<gio::BufferedInputStream>
  {
    return glib::make_refptr_for_instance<gio::BufferedInputStream> (
        dynamic_cast<gio::BufferedInputStream*> (
            wrap_auto ((GObject*) object, take_copy)));
  }

} // namespace glib

namespace gio
{

  auto
  BufferedInputStream_Class::init () -> const Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &BufferedInputStream_Class::class_init_function;

      register_derived_type (g_buffered_input_stream_get_type ());

      Seekable::add_interface (get_type ());
    }

    return *this;
  }

  auto
  BufferedInputStream_Class::class_init_function (void* g_class,
                                                  void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);

    klass->fill = &fill_vfunc_callback;
  }

  auto
  BufferedInputStream_Class::fill_vfunc_callback (GBufferedInputStream* self,
                                                  const gssize count,
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
          return obj->fill_vfunc (count, glib::wrap (cancellable, true));
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

    if (base && base->fill)
      return (*base->fill) (self, count, cancellable, error);

    using RType = gssize;
    return RType ();
  }

  auto
  BufferedInputStream_Class::wrap_new (GObject* object) -> glib::ObjectBase*
  {
    return new BufferedInputStream ((GBufferedInputStream*) object);
  }

  auto
  BufferedInputStream::gobj_copy () -> GBufferedInputStream*
  {
    reference ();
    return gobj ();
  }

  BufferedInputStream::BufferedInputStream (
      const glib::ConstructParams& construct_params)
    : FilterInputStream (construct_params)
  {
  }

  BufferedInputStream::BufferedInputStream (GBufferedInputStream* castitem)
    : FilterInputStream ((GFilterInputStream*) castitem)
  {
  }

  BufferedInputStream::BufferedInputStream (BufferedInputStream&& src) noexcept
    : FilterInputStream (std::move (src)),
      Seekable (std::move (src))
  {
  }

  auto
  BufferedInputStream::operator= (BufferedInputStream&& src) noexcept -> BufferedInputStream&
  {
    FilterInputStream::operator= (std::move (src));
    Seekable::operator= (std::move (src));
    return *this;
  }

  BufferedInputStream::~BufferedInputStream () noexcept = default;

  BufferedInputStream::CppClassType
      BufferedInputStream::bufferedinputstream_class_;

  auto
  BufferedInputStream::get_type () -> GType
  {
    return bufferedinputstream_class_.init ().get_type ();
  }

  auto
  BufferedInputStream::get_base_type () -> GType
  {
    return g_buffered_input_stream_get_type ();
  }

  BufferedInputStream::BufferedInputStream (
      const glib::RefPtr<InputStream>& base_stream)
    : ObjectBase (nullptr),
      FilterInputStream (
          glib::ConstructParams (bufferedinputstream_class_.init (),
                                 "base_stream",
                                 glib::unwrap (base_stream),
                                 nullptr))
  {
  }

  BufferedInputStream::BufferedInputStream (
      const glib::RefPtr<InputStream>& base_stream,
      const gsize buffer_size)
    : ObjectBase (nullptr),
      FilterInputStream (
          glib::ConstructParams (bufferedinputstream_class_.init (),
                                 "base_stream",
                                 glib::unwrap (base_stream),
                                 "buffer_size",
                                 buffer_size,
                                 nullptr))
  {
  }

  auto
  BufferedInputStream::create (const glib::RefPtr<InputStream>& base_stream) -> glib::RefPtr<BufferedInputStream>
  {
    return glib::make_refptr_for_instance<BufferedInputStream> (
        new BufferedInputStream (base_stream));
  }

  auto
  BufferedInputStream::get_buffer_size () const -> gsize
  {
    return g_buffered_input_stream_get_buffer_size (
        const_cast<GBufferedInputStream*> (gobj ()));
  }

  auto
  BufferedInputStream::set_buffer_size (const gsize size) -> void
  {
    g_buffered_input_stream_set_buffer_size (gobj (), size);
  }

  auto
  BufferedInputStream::get_available () const -> gsize
  {
    return g_buffered_input_stream_get_available (
        const_cast<GBufferedInputStream*> (gobj ()));
  }

  auto
  BufferedInputStream::peek (void* buffer,
                             const gsize offset,
                             const gsize count) const -> gsize
  {
    return g_buffered_input_stream_peek (
        const_cast<GBufferedInputStream*> (gobj ()),
        buffer,
        offset,
        count);
  }

  auto
  BufferedInputStream::peek_buffer (gsize& count) const -> const void*
  {
    return g_buffered_input_stream_peek_buffer (
        const_cast<GBufferedInputStream*> (gobj ()),
        &count);
  }

  auto
  BufferedInputStream::fill (const gssize count,
                             const glib::RefPtr<Cancellable>& cancellable) -> gssize
  {
    GError* gerror = nullptr;
    const auto retvalue = g_buffered_input_stream_fill (
        gobj (),
        count,
        glib::unwrap (cancellable),
        &gerror);
    if (gerror)
      glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  BufferedInputStream::fill (const gssize count) -> gssize
  {
    GError* gerror = nullptr;
    const auto retvalue =
        g_buffered_input_stream_fill (gobj (), count, nullptr, &gerror);
    if (gerror)
      glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  BufferedInputStream::fill_finish (const glib::RefPtr<AsyncResult>& result) -> gssize
  {
    GError* gerror = nullptr;
    const auto retvalue = g_buffered_input_stream_fill_finish (
        gobj (),
        glib::unwrap (result),
        &gerror);
    if (gerror)
      glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  BufferedInputStream::read_byte (const glib::RefPtr<Cancellable>& cancellable) -> int
  {
    GError* gerror = nullptr;
    const auto retvalue = g_buffered_input_stream_read_byte (
        gobj (),
        glib::unwrap (cancellable),
        &gerror);
    if (gerror)
      glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  BufferedInputStream::read_byte () -> int
  {
    GError* gerror = nullptr;
    const auto retvalue =
        g_buffered_input_stream_read_byte (gobj (), nullptr, &gerror);
    if (gerror)
      glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  BufferedInputStream::property_buffer_size () -> glib::PropertyProxy<guint>
  {
    return {this, "buffer-size"};
  }

  auto
  BufferedInputStream::property_buffer_size () const -> glib::PropertyProxy_ReadOnly<guint>
  {
    return {this, "buffer-size"};
  }

  auto
  BufferedInputStream::fill_vfunc (const gssize count,
                                   const glib::RefPtr<Cancellable>& cancellable) -> gssize
  {
    const auto base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (gobject_)));

    if (base && base->fill)
    {
      GError* gerror = nullptr;
      const gssize retval (
          (*base->fill) (gobj (), count, glib::unwrap (cancellable), &gerror));
      if (gerror)
        glib::Error::throw_exception (gerror);
      return retval;
    }

    using RType = gssize;
    return RType ();
  }

} // namespace gio
