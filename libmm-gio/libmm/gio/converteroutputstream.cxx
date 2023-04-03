// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/gio/converteroutputstream.hxx>
#include <libmm/gio/converteroutputstream_p.hxx>

#include <gio/gio.h>
#include <libmm/gio/converter.hxx>
#include <libmm/gio/outputstream.hxx>

namespace Gio
{

}

namespace
{
}

namespace Glib
{

  auto
  wrap (GConverterOutputStream* object, const bool take_copy) -> RefPtr<Gio::ConverterOutputStream>
  {
    return Glib::make_refptr_for_instance<Gio::ConverterOutputStream> (
        dynamic_cast<Gio::ConverterOutputStream*> (
            wrap_auto ((GObject*) object, take_copy)));
  }

} // namespace Glib

namespace Gio
{

  auto
  ConverterOutputStream_Class::init () -> const Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &ConverterOutputStream_Class::class_init_function;

      register_derived_type (g_converter_output_stream_get_type ());

      PollableOutputStream::add_interface (get_type ());
    }

    return *this;
  }

  auto
  ConverterOutputStream_Class::class_init_function (void* g_class,
                                                    void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);
  }

  auto
  ConverterOutputStream_Class::wrap_new (GObject* object) -> Glib::ObjectBase*
  {
    return new ConverterOutputStream ((GConverterOutputStream*) object);
  }

  auto
  ConverterOutputStream::gobj_copy () -> GConverterOutputStream*
  {
    reference ();
    return gobj ();
  }

  ConverterOutputStream::ConverterOutputStream (
      const Glib::ConstructParams& construct_params)
    : FilterOutputStream (construct_params)
  {
  }

  ConverterOutputStream::ConverterOutputStream (
      GConverterOutputStream* castitem)
    : FilterOutputStream ((GFilterOutputStream*) castitem)
  {
  }

  ConverterOutputStream::ConverterOutputStream (
      ConverterOutputStream&& src) noexcept
    : FilterOutputStream (std::move (src)),
      PollableOutputStream (std::move (src))
  {
  }

  auto
  ConverterOutputStream::operator= (ConverterOutputStream&& src) noexcept -> ConverterOutputStream&
  {
    FilterOutputStream::operator= (std::move (src));
    PollableOutputStream::operator= (std::move (src));
    return *this;
  }

  ConverterOutputStream::~ConverterOutputStream () noexcept = default;

  ConverterOutputStream::CppClassType
      ConverterOutputStream::converteroutputstream_class_;

  auto
  ConverterOutputStream::get_type () -> GType
  {
    return converteroutputstream_class_.init ().get_type ();
  }

  auto
  ConverterOutputStream::get_base_type () -> GType
  {
    return g_converter_output_stream_get_type ();
  }

  ConverterOutputStream::ConverterOutputStream (
      const Glib::RefPtr<OutputStream>& base_stream,
      const Glib::RefPtr<Converter>& converter)
    : ObjectBase (nullptr),
      FilterOutputStream (
          Glib::ConstructParams (converteroutputstream_class_.init (),
                                 "base_stream",
                                 Glib::unwrap (base_stream),
                                 "converter",
                                 Glib::unwrap (converter),
                                 nullptr))
  {
  }

  auto
  ConverterOutputStream::create (const Glib::RefPtr<OutputStream>& base_stream,
                                 const Glib::RefPtr<Converter>& converter) -> Glib::RefPtr<ConverterOutputStream>
  {
    return Glib::make_refptr_for_instance<ConverterOutputStream> (
        new ConverterOutputStream (base_stream, converter));
  }

  auto
  ConverterOutputStream::get_converter () -> Glib::RefPtr<Converter>
  {
    auto retvalue =
        Glib::wrap (g_converter_output_stream_get_converter (gobj ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  ConverterOutputStream::get_converter () const -> Glib::RefPtr<const Converter>
  {
    return const_cast<ConverterOutputStream*> (this)->get_converter ();
  }

  static_assert (
      Glib::Traits::ValueCompatibleWithWrapProperty<
          Glib::RefPtr<Converter>>::value,
      "Type Glib::RefPtr<Converter> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  auto
  ConverterOutputStream::property_converter () const -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<Converter>>
  {
    return {this, "converter"};
  }

} // namespace Gio
