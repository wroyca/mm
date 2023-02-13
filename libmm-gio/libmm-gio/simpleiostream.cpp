


#include <mm/glib/mm-glib.hpp>

#include <mm/gio/simpleiostream.hpp>
#include <mm/gio/private/simpleiostream_p.hpp>


/* Copyright (C) 2015 The giomm Development Team
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
 * License along with this library. If not, see <http://www.gnu.org/licenses/>.
 */

#include <gio/gio.h>

namespace
{
} // anonymous namespace


namespace Glib
{

auto wrap(GSimpleIOStream* object, const bool take_copy) -> RefPtr<Gio::SimpleIOStream>
{
  return Glib::make_refptr_for_instance<Gio::SimpleIOStream>( dynamic_cast<Gio::SimpleIOStream*> (wrap_auto((GObject*)object, take_copy)) );
  //We use dynamic_cast<> in case of multiple inheritance.
}

} /* namespace Glib */


namespace Gio
{


/* The *_Class implementation: */

auto SimpleIOStream_Class::init() -> const Class&
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Class has to know the class init function to clone custom types.
    class_init_func_ = &SimpleIOStream_Class::class_init_function;

    // This is actually just optimized away, apparently with no harm.
    // Make sure that the parent type has been created.
    //CppClassParent::CppObjectType::get_type();

    // Create the wrapper type, with the same class/instance size as the base type.
    register_derived_type(g_simple_io_stream_get_type());

    // Add derived versions of interfaces, if the C type implements any interfaces:

  }

  return *this;
}


auto SimpleIOStream_Class::class_init_function (void *g_class, void *class_data) -> void
{
  const auto klass = static_cast<BaseClassType*>(g_class);
  CppClassParent::class_init_function(klass, class_data);


}


auto SimpleIOStream_Class::wrap_new(GObject* object) -> Glib::ObjectBase*
{
  return new SimpleIOStream((GSimpleIOStream*)object);
}


/* The implementation: */

auto SimpleIOStream::gobj_copy() -> GSimpleIOStream*
{
  reference();
  return gobj();
}

SimpleIOStream::SimpleIOStream(const Glib::ConstructParams& construct_params)
: IOStream(construct_params)
{

}

SimpleIOStream::SimpleIOStream(GSimpleIOStream* castitem)
: IOStream((GIOStream*)castitem)
{}


SimpleIOStream::SimpleIOStream(SimpleIOStream&& src) noexcept
: IOStream(std::move(src))
{}

auto SimpleIOStream::operator=(SimpleIOStream&& src) noexcept -> SimpleIOStream&
{
  IOStream::operator=(std::move(src));
  return *this;
}


SimpleIOStream::~SimpleIOStream() noexcept = default;

SimpleIOStream::CppClassType SimpleIOStream::simpleiostream_class_; // initialize static member

auto SimpleIOStream::get_type() -> GType
{
  return simpleiostream_class_.init().get_type();
}


auto SimpleIOStream::get_base_type() -> GType
{
  return g_simple_io_stream_get_type();
}


SimpleIOStream::SimpleIOStream(const Glib::RefPtr<InputStream>& input_stream, const Glib::RefPtr<OutputStream>& output_stream)
:
  // Mark this class as non-derived to allow C++ vfuncs to be skipped.
ObjectBase(nullptr),
IOStream(Glib::ConstructParams(simpleiostream_class_.init(), "input_stream", Glib::unwrap(input_stream), "output_stream", Glib::unwrap(output_stream), nullptr))
{


}

auto SimpleIOStream::create(const Glib::RefPtr<InputStream>& input_stream, const Glib::RefPtr<OutputStream>& output_stream) -> Glib::RefPtr<SimpleIOStream>
{
  return Glib::make_refptr_for_instance<SimpleIOStream>( new SimpleIOStream(input_stream, output_stream) );
}


static_assert(Glib::Traits::ValueCompatibleWithWrapProperty<Glib::RefPtr<InputStream>>::value,
  "Type Glib::RefPtr<InputStream> cannot be used in _WRAP_PROPERTY. "
  "There is no suitable template specialization of Glib::Value<>.");

auto SimpleIOStream::property_input_stream() const -> Glib::PropertyProxy_ReadOnly< Glib::RefPtr<InputStream> >
{
  return {this, "input-stream"};
}

static_assert(Glib::Traits::ValueCompatibleWithWrapProperty<Glib::RefPtr<OutputStream>>::value,
  "Type Glib::RefPtr<OutputStream> cannot be used in _WRAP_PROPERTY. "
  "There is no suitable template specialization of Glib::Value<>.");

auto SimpleIOStream::property_output_stream() const -> Glib::PropertyProxy_ReadOnly< Glib::RefPtr<OutputStream> >
{
  return {this, "output-stream"};
}


} // namespace Gio


