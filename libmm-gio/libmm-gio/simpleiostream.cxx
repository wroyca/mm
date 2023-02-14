

#include <libmm-glib/mm-glib.hxx>

#include <libmm-gio/simpleiostream.hxx>
#include <libmm-gio/simpleiostream_p.hxx>

#include <gio/gio.h>

namespace
{
}

namespace Glib
{

  auto
  wrap (GSimpleIOStream* object, const bool take_copy) -> RefPtr<Gio::SimpleIOStream>
  {
    return Glib::make_refptr_for_instance<Gio::SimpleIOStream> (
        dynamic_cast<Gio::SimpleIOStream*> (
            wrap_auto ((GObject*) object, take_copy)));
  }

} // namespace Glib

namespace Gio
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
  SimpleIOStream_Class::wrap_new (GObject* object) -> Glib::ObjectBase*
  {
    return new SimpleIOStream ((GSimpleIOStream*) object);
  }

  auto
  SimpleIOStream::gobj_copy () -> GSimpleIOStream*
  {
    reference ();
    return gobj ();
  }

  SimpleIOStream::SimpleIOStream (const Glib::ConstructParams& construct_params)
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
      const Glib::RefPtr<InputStream>& input_stream,
      const Glib::RefPtr<OutputStream>& output_stream)
    : ObjectBase (nullptr),
      IOStream (Glib::ConstructParams (simpleiostream_class_.init (),
                                       "input_stream",
                                       Glib::unwrap (input_stream),
                                       "output_stream",
                                       Glib::unwrap (output_stream),
                                       nullptr))
  {
  }

  auto
  SimpleIOStream::create (const Glib::RefPtr<InputStream>& input_stream,
                          const Glib::RefPtr<OutputStream>& output_stream) -> Glib::RefPtr<SimpleIOStream>
  {
    return Glib::make_refptr_for_instance<SimpleIOStream> (
        new SimpleIOStream (input_stream, output_stream));
  }

  static_assert (
      Glib::Traits::ValueCompatibleWithWrapProperty<
          Glib::RefPtr<InputStream>>::value,
      "Type Glib::RefPtr<InputStream> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  auto
  SimpleIOStream::property_input_stream () const -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<InputStream>>
  {
    return {this, "input-stream"};
  }

  static_assert (
      Glib::Traits::ValueCompatibleWithWrapProperty<
          Glib::RefPtr<OutputStream>>::value,
      "Type Glib::RefPtr<OutputStream> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  auto
  SimpleIOStream::property_output_stream () const -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<OutputStream>>
  {
    return {this, "output-stream"};
  }

} // namespace Gio
