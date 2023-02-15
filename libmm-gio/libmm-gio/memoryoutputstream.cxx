// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm-glib/mm-glib.hxx>

#include <libmm-gio/memoryoutputstream.hxx>
#include <libmm-gio/memoryoutputstream_p.hxx>

#include <gio/gio.h>
#include <libmm-glib/bytes.hxx>

namespace Gio
{

  MemoryOutputStream::MemoryOutputStream ()
    : ObjectBase (nullptr),
      OutputStream (Glib::ConstructParams (memoryoutputstream_class_.init (),
                                           "data",
                                           nullptr,
                                           "size",
                                           0,
                                           "realloc-function",
                                           g_realloc,
                                           "destroy-function",
                                           g_free,
                                           nullptr))
  {
  }

} // namespace Gio

namespace
{
}

namespace Glib
{

  auto
  wrap (GMemoryOutputStream* object, const bool take_copy) -> RefPtr<Gio::MemoryOutputStream>
  {
    return Glib::make_refptr_for_instance<Gio::MemoryOutputStream> (
        dynamic_cast<Gio::MemoryOutputStream*> (
            wrap_auto ((GObject*) object, take_copy)));
  }

} // namespace Glib

namespace Gio
{

  auto
  MemoryOutputStream_Class::init () -> const Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &MemoryOutputStream_Class::class_init_function;

      register_derived_type (g_memory_output_stream_get_type ());

      Seekable::add_interface (get_type ());
      PollableOutputStream::add_interface (get_type ());
    }

    return *this;
  }

  auto
  MemoryOutputStream_Class::class_init_function (void* g_class,
                                                 void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);
  }

  auto
  MemoryOutputStream_Class::wrap_new (GObject* object) -> Glib::ObjectBase*
  {
    return new MemoryOutputStream ((GMemoryOutputStream*) object);
  }

  auto
  MemoryOutputStream::gobj_copy () -> GMemoryOutputStream*
  {
    reference ();
    return gobj ();
  }

  MemoryOutputStream::MemoryOutputStream (
      const Glib::ConstructParams& construct_params)
    : OutputStream (construct_params)
  {
  }

  MemoryOutputStream::MemoryOutputStream (GMemoryOutputStream* castitem)
    : OutputStream ((GOutputStream*) castitem)
  {
  }

  MemoryOutputStream::MemoryOutputStream (MemoryOutputStream&& src) noexcept
    : OutputStream (std::move (src)),
      Seekable (std::move (src)),
      PollableOutputStream (std::move (src))
  {
  }

  auto
  MemoryOutputStream::operator= (MemoryOutputStream&& src) noexcept -> MemoryOutputStream&
  {
    OutputStream::operator= (std::move (src));
    Seekable::operator= (std::move (src));
    PollableOutputStream::operator= (std::move (src));
    return *this;
  }

  MemoryOutputStream::~MemoryOutputStream () noexcept = default;

  MemoryOutputStream::CppClassType
      MemoryOutputStream::memoryoutputstream_class_;

  auto
  MemoryOutputStream::get_type () -> GType
  {
    return memoryoutputstream_class_.init ().get_type ();
  }

  auto
  MemoryOutputStream::get_base_type () -> GType
  {
    return g_memory_output_stream_get_type ();
  }

  MemoryOutputStream::MemoryOutputStream (void* data,
                                          const gsize size,
                                          const GReallocFunc realloc_function,
                                          const GDestroyNotify destroy_function)
    : ObjectBase (nullptr),
      OutputStream (Glib::ConstructParams (memoryoutputstream_class_.init (),
                                           "data",
                                           data,
                                           "size",
                                           size,
                                           "realloc_function",
                                           realloc_function,
                                           "destroy_function",
                                           destroy_function,
                                           nullptr))
  {
  }

  auto
  MemoryOutputStream::create () -> Glib::RefPtr<MemoryOutputStream>
  {
    return Glib::make_refptr_for_instance<MemoryOutputStream> (
        new MemoryOutputStream ());
  }

  auto
  MemoryOutputStream::create (void* data,
                              const gsize size,
                              const GReallocFunc realloc_function,
                              const GDestroyNotify destroy_function) -> Glib::RefPtr<MemoryOutputStream>
  {
    return Glib::make_refptr_for_instance<MemoryOutputStream> (
        new MemoryOutputStream (data,
                                size,
                                realloc_function,
                                destroy_function));
  }

  auto
  MemoryOutputStream::get_data () -> void*
  {
    return g_memory_output_stream_get_data (gobj ());
  }

  auto
  MemoryOutputStream::get_data () const -> const void*
  {
    return const_cast<MemoryOutputStream*> (this)->get_data ();
  }

  auto
  MemoryOutputStream::steal_data () -> void*
  {
    return g_memory_output_stream_steal_data (gobj ());
  }

  auto
  MemoryOutputStream::get_size () const -> gsize
  {
    return g_memory_output_stream_get_size (
        const_cast<GMemoryOutputStream*> (gobj ()));
  }

  auto
  MemoryOutputStream::get_data_size () const -> gsize
  {
    return g_memory_output_stream_get_data_size (
        const_cast<GMemoryOutputStream*> (gobj ()));
  }

  auto
  MemoryOutputStream::steal_as_bytes () -> Glib::RefPtr<Glib::Bytes>
  {
    return Glib::wrap (g_memory_output_stream_steal_as_bytes (gobj ()));
  }

  static_assert (
      Glib::Traits::ValueCompatibleWithWrapProperty<void*>::value,
      "Type void* cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  auto
  MemoryOutputStream::property_data () const -> Glib::PropertyProxy_ReadOnly<void*>
  {
    return {this, "data"};
  }

  static_assert (
      Glib::Traits::ValueCompatibleWithWrapProperty<gulong>::value,
      "Type gulong cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  auto
  MemoryOutputStream::property_data_size () const -> Glib::PropertyProxy_ReadOnly<gulong>
  {
    return {this, "data-size"};
  }

  static_assert (
      Glib::Traits::ValueCompatibleWithWrapProperty<gulong>::value,
      "Type gulong cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  auto
  MemoryOutputStream::property_size () const -> Glib::PropertyProxy_ReadOnly<gulong>
  {
    return {this, "size"};
  }

} // namespace Gio
