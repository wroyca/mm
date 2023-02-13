


#include <libmm-glib/mm-glib.hpp>

#include <libmm-gio/converterinputstream.hpp>
#include <libmm-gio/converterinputstream_p.hpp>


/* Copyright (C) 2012 The giomm Development Team
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <gio/gio.h>
#include <libmm-gio/converter.hpp>
#include <libmm-gio/inputstream.hpp>

namespace Gio
{

} // namespace Gio

namespace
{
} // anonymous namespace


namespace Glib
{

auto wrap(GConverterInputStream* object, const bool take_copy) -> RefPtr<Gio::ConverterInputStream>
{
  return Glib::make_refptr_for_instance<Gio::ConverterInputStream>( dynamic_cast<Gio::ConverterInputStream*> (wrap_auto((GObject*)object, take_copy)) );
  //We use dynamic_cast<> in case of multiple inheritance.
}

} /* namespace Glib */


namespace Gio
{


/* The *_Class implementation: */

auto ConverterInputStream_Class::init() -> const Class&
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Class has to know the class init function to clone custom types.
    class_init_func_ = &ConverterInputStream_Class::class_init_function;

    // This is actually just optimized away, apparently with no harm.
    // Make sure that the parent type has been created.
    //CppClassParent::CppObjectType::get_type();

    // Create the wrapper type, with the same class/instance size as the base type.
    register_derived_type(g_converter_input_stream_get_type());

    // Add derived versions of interfaces, if the C type implements any interfaces:
  PollableInputStream::add_interface(get_type());

  }

  return *this;
}


auto ConverterInputStream_Class::class_init_function (void *g_class, void *class_data) -> void
{
  const auto klass = static_cast<BaseClassType*>(g_class);
  CppClassParent::class_init_function(klass, class_data);


}


auto ConverterInputStream_Class::wrap_new(GObject* object) -> Glib::ObjectBase*
{
  return new ConverterInputStream((GConverterInputStream*)object);
}


/* The implementation: */

auto ConverterInputStream::gobj_copy() -> GConverterInputStream*
{
  reference();
  return gobj();
}

ConverterInputStream::ConverterInputStream(const Glib::ConstructParams& construct_params)
:
  FilterInputStream(construct_params)
{

}

ConverterInputStream::ConverterInputStream(GConverterInputStream* castitem)
:
  FilterInputStream((GFilterInputStream*)castitem)
{}


ConverterInputStream::ConverterInputStream(ConverterInputStream&& src) noexcept
: FilterInputStream(std::move(src))
  , PollableInputStream(std::move(src))
{}

auto ConverterInputStream::operator=(ConverterInputStream&& src) noexcept -> ConverterInputStream&
{
  FilterInputStream::operator=(std::move(src));
  PollableInputStream::operator=(std::move(src));
  return *this;
}


ConverterInputStream::~ConverterInputStream() noexcept = default;

ConverterInputStream::CppClassType ConverterInputStream::converterinputstream_class_; // initialize static member

auto ConverterInputStream::get_type() -> GType
{
  return converterinputstream_class_.init().get_type();
}


auto ConverterInputStream::get_base_type() -> GType
{
  return g_converter_input_stream_get_type();
}


ConverterInputStream::ConverterInputStream(const Glib::RefPtr<InputStream>& base_stream, const Glib::RefPtr<Converter>& converter)
:
  // Mark this class as non-derived to allow C++ vfuncs to be skipped.
ObjectBase(nullptr),
  FilterInputStream(Glib::ConstructParams(converterinputstream_class_.init(), "base_stream", Glib::unwrap(base_stream), "converter", Glib::unwrap(converter), nullptr))
{


}

auto ConverterInputStream::create(const Glib::RefPtr<InputStream>& base_stream, const Glib::RefPtr<Converter>& converter) -> Glib::RefPtr<ConverterInputStream>
{
  return Glib::make_refptr_for_instance<ConverterInputStream>( new ConverterInputStream(base_stream, converter) );
}

auto ConverterInputStream::get_converter() -> Glib::RefPtr<Converter>
{
  auto retvalue = Glib::wrap(g_converter_input_stream_get_converter(gobj()));
  if(retvalue)
    retvalue->reference(); //The function does not do a ref for us.
  return retvalue;
}

auto ConverterInputStream::get_converter() const -> Glib::RefPtr<const Converter>
{
  return const_cast<ConverterInputStream*>(this)->get_converter();
}


static_assert(Glib::Traits::ValueCompatibleWithWrapProperty<Glib::RefPtr<Converter>>::value,
  "Type Glib::RefPtr<Converter> cannot be used in _WRAP_PROPERTY. "
  "There is no suitable template specialization of Glib::Value<>.");

auto ConverterInputStream::property_converter() const -> Glib::PropertyProxy_ReadOnly< Glib::RefPtr<Converter> >
{
  return {this, "converter"};
}


} // namespace Gio


