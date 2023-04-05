// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/gio/simpleiostream.hxx>
#include <libmm/gio/simpleiostream_p.hxx>

#include <gio/gio.h>

namespace
{
}

namespace glib
{

  auto
  wrap (GSimpleIOStream* object, const bool take_copy) -> RefPtr<gio::SimpleIOStream>
  {
    return glib::make_refptr_for_instance<gio::SimpleIOStream> (
        dynamic_cast<gio::SimpleIOStream*> (
            wrap_auto ((GObject*) object, take_copy)));
  }

} // namespace glib

namespace gio
{

  auto
  SimpleIOStream_Class::init () -> const Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &SimpleIOStream_Class::class_init_function;

      register_derived_type (g_simple_io_stream_get_type ());
    }

    return *this;
  }

  auto
  SimpleIOStream_Class::class_init_function (void* g_class, void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);
  }

  auto
  SimpleIOStream_Class::wrap_new (GObject* object) -> glib::ObjectBase*
  {
    return new SimpleIOStream ((GSimpleIOStream*) object);
  }

  auto
  SimpleIOStream::gobj_copy () -> GSimpleIOStream*
  {
    reference ();
    return gobj ();
  }

  SimpleIOStream::SimpleIOStream (const glib::ConstructParams& construct_params)
    : IOStream (construct_params)
  {
  }

  SimpleIOStream::SimpleIOStream (GSimpleIOStream* castitem)
    : IOStream ((GIOStream*) castitem)
  {
  }

  SimpleIOStream::SimpleIOStream (SimpleIOStream&& src) noexcept
    : IOStream (std::move (src))
  {
  }

  auto
  SimpleIOStream::operator= (SimpleIOStream&& src) noexcept -> SimpleIOStream&
  {
    IOStream::operator= (std::move (src));
    return *this;
  }

  SimpleIOStream::~SimpleIOStream () noexcept = default;

  SimpleIOStream::CppClassType SimpleIOStream::simpleiostream_class_;

  auto
  SimpleIOStream::get_type () -> GType
  {
    return simpleiostream_class_.init ().get_type ();
  }

  auto
  SimpleIOStream::get_base_type () -> GType
  {
    return g_simple_io_stream_get_type ();
  }

  SimpleIOStream::SimpleIOStream (
      const glib::RefPtr<InputStream>& input_stream,
      const glib::RefPtr<OutputStream>& output_stream)
    : ObjectBase (nullptr),
      IOStream (glib::ConstructParams (simpleiostream_class_.init (),
                                       "input_stream",
                                       glib::unwrap (input_stream),
                                       "output_stream",
                                       glib::unwrap (output_stream),
                                       nullptr))
  {
  }

  auto
  SimpleIOStream::create (const glib::RefPtr<InputStream>& input_stream,
                          const glib::RefPtr<OutputStream>& output_stream) -> glib::RefPtr<SimpleIOStream>
  {
    return glib::make_refptr_for_instance<SimpleIOStream> (
        new SimpleIOStream (input_stream, output_stream));
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<
          glib::RefPtr<InputStream>>::value,
      "Type glib::RefPtr<InputStream> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  SimpleIOStream::property_input_stream () const -> glib::PropertyProxy_ReadOnly<glib::RefPtr<InputStream>>
  {
    return {this, "input-stream"};
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<
          glib::RefPtr<OutputStream>>::value,
      "Type glib::RefPtr<OutputStream> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  SimpleIOStream::property_output_stream () const -> glib::PropertyProxy_ReadOnly<glib::RefPtr<OutputStream>>
  {
    return {this, "output-stream"};
  }

} // namespace gio
