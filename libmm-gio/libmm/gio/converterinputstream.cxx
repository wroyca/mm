// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/gio/converterinputstream.hxx>
#include <libmm/gio/converterinputstream_p.hxx>

#include <gio/gio.h>
#include <libmm/gio/converter.hxx>
#include <libmm/gio/inputstream.hxx>

namespace gio
{

}

namespace
{
}

namespace glib
{

  auto
  wrap (GConverterInputStream* object, const bool take_copy) -> RefPtr<gio::ConverterInputStream>
  {
    return glib::make_refptr_for_instance<gio::ConverterInputStream> (
        dynamic_cast<gio::ConverterInputStream*> (
            wrap_auto ((GObject*) object, take_copy)));
  }

} // namespace glib

namespace gio
{

  auto
  ConverterInputStream_Class::init () -> const Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &ConverterInputStream_Class::class_init_function;

      register_derived_type (g_converter_input_stream_get_type ());

      PollableInputStream::add_interface (get_type ());
    }

    return *this;
  }

  auto
  ConverterInputStream_Class::class_init_function (void* g_class,
                                                   void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);
  }

  auto
  ConverterInputStream_Class::wrap_new (GObject* object) -> glib::ObjectBase*
  {
    return new ConverterInputStream ((GConverterInputStream*) object);
  }

  auto
  ConverterInputStream::gobj_copy () -> GConverterInputStream*
  {
    reference ();
    return gobj ();
  }

  ConverterInputStream::ConverterInputStream (
      const glib::ConstructParams& construct_params)
    : FilterInputStream (construct_params)
  {
  }

  ConverterInputStream::ConverterInputStream (GConverterInputStream* castitem)
    : FilterInputStream ((GFilterInputStream*) castitem)
  {
  }

  ConverterInputStream::ConverterInputStream (
      ConverterInputStream&& src) noexcept
    : FilterInputStream (std::move (src)),
      PollableInputStream (std::move (src))
  {
  }

  auto
  ConverterInputStream::operator= (ConverterInputStream&& src) noexcept -> ConverterInputStream&
  {
    FilterInputStream::operator= (std::move (src));
    PollableInputStream::operator= (std::move (src));
    return *this;
  }

  ConverterInputStream::~ConverterInputStream () noexcept = default;

  ConverterInputStream::CppClassType
      ConverterInputStream::converterinputstream_class_;

  auto
  ConverterInputStream::get_type () -> GType
  {
    return converterinputstream_class_.init ().get_type ();
  }

  auto
  ConverterInputStream::get_base_type () -> GType
  {
    return g_converter_input_stream_get_type ();
  }

  ConverterInputStream::ConverterInputStream (
      const glib::RefPtr<InputStream>& base_stream,
      const glib::RefPtr<Converter>& converter)
    : ObjectBase (nullptr),
      FilterInputStream (
          glib::ConstructParams (converterinputstream_class_.init (),
                                 "base_stream",
                                 glib::unwrap (base_stream),
                                 "converter",
                                 glib::unwrap (converter),
                                 nullptr))
  {
  }

  auto
  ConverterInputStream::create (const glib::RefPtr<InputStream>& base_stream,
                                const glib::RefPtr<Converter>& converter) -> glib::RefPtr<ConverterInputStream>
  {
    return glib::make_refptr_for_instance<ConverterInputStream> (
        new ConverterInputStream (base_stream, converter));
  }

  auto
  ConverterInputStream::get_converter () -> glib::RefPtr<Converter>
  {
    auto retvalue =
        glib::wrap (g_converter_input_stream_get_converter (gobj ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  ConverterInputStream::get_converter () const -> glib::RefPtr<const Converter>
  {
    return const_cast<ConverterInputStream*> (this)->get_converter ();
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<
          glib::RefPtr<Converter>>::value,
      "Type glib::RefPtr<Converter> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  ConverterInputStream::property_converter () const -> glib::PropertyProxy_ReadOnly<glib::RefPtr<Converter>>
  {
    return {this, "converter"};
  }

} // namespace gio
