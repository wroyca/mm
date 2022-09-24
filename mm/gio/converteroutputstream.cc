// Generated by gmmproc 2.74.0 -- DO NOT MODIFY!


#include <mm/glib/mm-glib.h>

#include <mm/gio/converteroutputstream.h>
#include <mm/gio/private/converteroutputstream_p.h>


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
#include <mm/gio/converter.h>
#include <mm/gio/outputstream.h>

namespace Gio
{

} // namespace Gio

namespace
{
} // anonymous namespace


namespace Glib
{

auto wrap(GConverterOutputStream* object, bool take_copy) -> Glib::RefPtr<Gio::ConverterOutputStream>
{
  return Glib::make_refptr_for_instance<Gio::ConverterOutputStream>( dynamic_cast<Gio::ConverterOutputStream*> (Glib::wrap_auto ((GObject*)(object), take_copy)) );
  //We use dynamic_cast<> in case of multiple inheritance.
}

} /* namespace Glib */


namespace Gio
{


/* The *_Class implementation: */

auto ConverterOutputStream_Class::init() -> const Glib::Class&
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Class has to know the class init function to clone custom types.
    class_init_func_ = &ConverterOutputStream_Class::class_init_function;

    // This is actually just optimized away, apparently with no harm.
    // Make sure that the parent type has been created.
    //CppClassParent::CppObjectType::get_type();

    // Create the wrapper type, with the same class/instance size as the base type.
    register_derived_type(g_converter_output_stream_get_type());

    // Add derived versions of interfaces, if the C type implements any interfaces:
  PollableOutputStream::add_interface(get_type());

  }

  return *this;
}


void ConverterOutputStream_Class::class_init_function(void* g_class, void* class_data)
{
  const auto klass = static_cast<BaseClassType*>(g_class);
  CppClassParent::class_init_function(klass, class_data);


}


auto ConverterOutputStream_Class::wrap_new(GObject* object) -> Glib::ObjectBase*
{
  return new ConverterOutputStream((GConverterOutputStream*)object);
}


/* The implementation: */

auto ConverterOutputStream::gobj_copy() -> GConverterOutputStream*
{
  reference();
  return gobj();
}

ConverterOutputStream::ConverterOutputStream(const Glib::ConstructParams& construct_params)
:
  FilterOutputStream(construct_params)
{

}

ConverterOutputStream::ConverterOutputStream(GConverterOutputStream* castitem)
:
  FilterOutputStream((GFilterOutputStream*)(castitem))
{}


ConverterOutputStream::ConverterOutputStream(ConverterOutputStream&& src) noexcept
: FilterOutputStream(std::move(src))
  , PollableOutputStream(std::move(src))
{}

auto ConverterOutputStream::operator=(ConverterOutputStream&& src) noexcept -> ConverterOutputStream&
{
  FilterOutputStream::operator=(std::move(src));
  PollableOutputStream::operator=(std::move(src));
  return *this;
}


ConverterOutputStream::~ConverterOutputStream() noexcept
{}


ConverterOutputStream::CppClassType ConverterOutputStream::converteroutputstream_class_; // initialize static member

auto ConverterOutputStream::get_type() -> GType
{
  return converteroutputstream_class_.init().get_type();
}


auto ConverterOutputStream::get_base_type() -> GType
{
  return g_converter_output_stream_get_type();
}


ConverterOutputStream::ConverterOutputStream(const Glib::RefPtr<OutputStream>& base_stream, const Glib::RefPtr<Converter>& converter)
:
  // Mark this class as non-derived to allow C++ vfuncs to be skipped.
  Glib::ObjectBase(nullptr),
  FilterOutputStream(Glib::ConstructParams(converteroutputstream_class_.init(), "base_stream", const_cast<GOutputStream*>(Glib::unwrap(base_stream)), "converter", Glib::unwrap(converter), nullptr))
{


}

auto ConverterOutputStream::create(const Glib::RefPtr<OutputStream>& base_stream, const Glib::RefPtr<Converter>& converter) -> Glib::RefPtr<ConverterOutputStream>
{
  return Glib::make_refptr_for_instance<ConverterOutputStream>( new ConverterOutputStream(base_stream, converter) );
}

auto ConverterOutputStream::get_converter() -> Glib::RefPtr<Converter>
{
  auto retvalue = Glib::wrap(g_converter_output_stream_get_converter(gobj()));
  if(retvalue)
    retvalue->reference(); //The function does not do a ref for us.
  return retvalue;
}

auto ConverterOutputStream::get_converter() const -> Glib::RefPtr<const Converter>
{
  return const_cast<ConverterOutputStream*>(this)->get_converter();
}


static_assert(Glib::Traits::ValueCompatibleWithWrapProperty<Glib::RefPtr<Converter>>::value,
  "Type Glib::RefPtr<Converter> cannot be used in _WRAP_PROPERTY. "
  "There is no suitable template specialization of Glib::Value<>.");

auto ConverterOutputStream::property_converter() const -> Glib::PropertyProxy_ReadOnly< Glib::RefPtr<Converter> >
{
  return Glib::PropertyProxy_ReadOnly< Glib::RefPtr<Converter> >(this, "converter");
}


} // namespace Gio


