

#include <libmm-glib/mm-glib.hxx>

#include <libmm-gio/bufferedoutputstream.hxx>
#include <libmm-gio/bufferedoutputstream_p.hxx>

#include <gio/gio.h>
#include <libmm-gio/slot_async.hxx>

namespace Gio
{

  auto
  BufferedOutputStream::create_sized (
      const Glib::RefPtr<OutputStream>& base_stream,
      const gsize size) -> Glib::RefPtr<BufferedOutputStream>
  {
    return Glib::make_refptr_for_instance<BufferedOutputStream> (
        new BufferedOutputStream (base_stream, size));
  }

} // namespace Gio

namespace
{
}

namespace Glib
{

  auto
  wrap (GBufferedOutputStream* object, const bool take_copy) -> RefPtr<Gio::BufferedOutputStream>
  {
    return Glib::make_refptr_for_instance<Gio::BufferedOutputStream> (
        dynamic_cast<Gio::BufferedOutputStream*> (
            wrap_auto ((GObject*) object, take_copy)));
  }

} // namespace Glib

namespace Gio
{

  auto
  BufferedOutputStream_Class::init () -> const Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &BufferedOutputStream_Class::class_init_function;

      register_derived_type (g_buffered_output_stream_get_type ());

      Seekable::add_interface (get_type ());
    }

    return *this;
  }

  auto
  BufferedOutputStream_Class::class_init_function (void* g_class,
                                                   void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);
  }

  auto
  BufferedOutputStream_Class::wrap_new (GObject* object) -> Glib::ObjectBase*
  {
    return new BufferedOutputStream ((GBufferedOutputStream*) object);
  }

  auto
  BufferedOutputStream::gobj_copy () -> GBufferedOutputStream*
  {
    reference ();
    return gobj ();
  }

  BufferedOutputStream::BufferedOutputStream (
      const Glib::ConstructParams& construct_params)
    : FilterOutputStream (construct_params)
  {
  }

  BufferedOutputStream::BufferedOutputStream (GBufferedOutputStream* castitem)
    : FilterOutputStream ((GFilterOutputStream*) castitem)
  {
  }

  BufferedOutputStream::BufferedOutputStream (
      BufferedOutputStream&& src) noexcept
    : FilterOutputStream (std::move (src)),
      Seekable (std::move (src))
  {
  }

  auto
  BufferedOutputStream::operator= (BufferedOutputStream&& src) noexcept -> BufferedOutputStream&
  {
    FilterOutputStream::operator= (std::move (src));
    Seekable::operator= (std::move (src));
    return *this;
  }

  BufferedOutputStream::~BufferedOutputStream () noexcept = default;

  BufferedOutputStream::CppClassType
      BufferedOutputStream::bufferedoutputstream_class_;

  auto
  BufferedOutputStream::get_type () -> GType
  {
    return bufferedoutputstream_class_.init ().get_type ();
  }

  auto
  BufferedOutputStream::get_base_type () -> GType
  {
    return g_buffered_output_stream_get_type ();
  }

  BufferedOutputStream::BufferedOutputStream (
      const Glib::RefPtr<OutputStream>& base_stream)
    : ObjectBase (nullptr),
      FilterOutputStream (
          Glib::ConstructParams (bufferedoutputstream_class_.init (),
                                 "base_stream",
                                 Glib::unwrap (base_stream),
                                 nullptr))
  {
  }

  BufferedOutputStream::BufferedOutputStream (
      const Glib::RefPtr<OutputStream>& base_stream,
      const gsize buffer_size)
    : ObjectBase (nullptr),
      FilterOutputStream (
          Glib::ConstructParams (bufferedoutputstream_class_.init (),
                                 "base_stream",
                                 Glib::unwrap (base_stream),
                                 "buffer_size",
                                 buffer_size,
                                 nullptr))
  {
  }

  auto
  BufferedOutputStream::create (const Glib::RefPtr<OutputStream>& base_stream) -> Glib::RefPtr<BufferedOutputStream>
  {
    return Glib::make_refptr_for_instance<BufferedOutputStream> (
        new BufferedOutputStream (base_stream));
  }

  auto
  BufferedOutputStream::get_buffer_size () const -> gsize
  {
    return g_buffered_output_stream_get_buffer_size (
        const_cast<GBufferedOutputStream*> (gobj ()));
  }

  auto
  BufferedOutputStream::set_buffer_size (const gsize size) -> void
  {
    g_buffered_output_stream_set_buffer_size (gobj (), size);
  }

  auto
  BufferedOutputStream::set_auto_grow (const bool auto_grow) -> void
  {
    g_buffered_output_stream_set_auto_grow (gobj (), auto_grow);
  }

  auto
  BufferedOutputStream::get_auto_grow () const -> bool
  {
    return g_buffered_output_stream_get_auto_grow (
        const_cast<GBufferedOutputStream*> (gobj ()));
  }

  auto
  BufferedOutputStream::property_buffer_size () -> Glib::PropertyProxy<guint>
  {
    return {this, "buffer-size"};
  }

  auto
  BufferedOutputStream::property_buffer_size () const -> Glib::PropertyProxy_ReadOnly<guint>
  {
    return {this, "buffer-size"};
  }

  auto
  BufferedOutputStream::property_auto_grow () -> Glib::PropertyProxy<bool>
  {
    return {this, "auto-grow"};
  }

  auto
  BufferedOutputStream::property_auto_grow () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return {this, "auto-grow"};
  }

} // namespace Gio
