


#include <libmm-glib/mm-glib.hpp>

#include <libmm-gio/filteroutputstream.hpp>
#include <libmm-gio/filteroutputstream_p.hpp>


/* Copyright (C) 2008 The gtkmm Development Team
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

namespace Gio {

FilterOutputStream::FilterOutputStream(const Glib::RefPtr<OutputStream>& base_stream)
: // Mark this class as non-derived to allow C++ vfuncs to be skipped.
ObjectBase(nullptr),
OutputStream(Glib::ConstructParams(filteroutputstream_class_.init(), "base_stream",Glib::unwrap(base_stream), nullptr))
{
}

} // namespace Gio

namespace
{
} // anonymous namespace


namespace Glib
{

auto wrap(GFilterOutputStream* object, const bool take_copy) -> RefPtr<Gio::FilterOutputStream>
{
  return Glib::make_refptr_for_instance<Gio::FilterOutputStream>( dynamic_cast<Gio::FilterOutputStream*> (wrap_auto((GObject*)object, take_copy)) );
  //We use dynamic_cast<> in case of multiple inheritance.
}

} /* namespace Glib */


namespace Gio
{


/* The *_Class implementation: */

auto FilterOutputStream_Class::init() -> const Class&
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Class has to know the class init function to clone custom types.
    class_init_func_ = &FilterOutputStream_Class::class_init_function;

    // This is actually just optimized away, apparently with no harm.
    // Make sure that the parent type has been created.
    //CppClassParent::CppObjectType::get_type();

    // Create the wrapper type, with the same class/instance size as the base type.
    register_derived_type(g_filter_output_stream_get_type());

    // Add derived versions of interfaces, if the C type implements any interfaces:

  }

  return *this;
}


auto FilterOutputStream_Class::class_init_function (void *g_class, void *class_data) -> void
{
  const auto klass = static_cast<BaseClassType*>(g_class);
  CppClassParent::class_init_function(klass, class_data);


}


auto FilterOutputStream_Class::wrap_new(GObject* object) -> Glib::ObjectBase*
{
  return new FilterOutputStream((GFilterOutputStream*)object);
}


/* The implementation: */

auto FilterOutputStream::gobj_copy() -> GFilterOutputStream*
{
  reference();
  return gobj();
}

FilterOutputStream::FilterOutputStream(const Glib::ConstructParams& construct_params)
: OutputStream(construct_params)
{

}

FilterOutputStream::FilterOutputStream(GFilterOutputStream* castitem)
: OutputStream((GOutputStream*)castitem)
{}


FilterOutputStream::FilterOutputStream(FilterOutputStream&& src) noexcept
: OutputStream(std::move(src))
{}

auto FilterOutputStream::operator=(FilterOutputStream&& src) noexcept -> FilterOutputStream&
{
  OutputStream::operator=(std::move(src));
  return *this;
}


FilterOutputStream::~FilterOutputStream() noexcept = default;

FilterOutputStream::CppClassType FilterOutputStream::filteroutputstream_class_; // initialize static member

auto FilterOutputStream::get_type() -> GType
{
  return filteroutputstream_class_.init().get_type();
}


auto FilterOutputStream::get_base_type() -> GType
{
  return g_filter_output_stream_get_type();
}


auto FilterOutputStream::get_base_stream() -> Glib::RefPtr<OutputStream>
{
  auto retvalue = Glib::wrap(g_filter_output_stream_get_base_stream(gobj()));
  if(retvalue)
    retvalue->reference(); //The function does not do a ref for us.
  return retvalue;
}

auto FilterOutputStream::get_base_stream() const -> Glib::RefPtr<const OutputStream>
{
  return const_cast<FilterOutputStream*>(this)->get_base_stream();
}

auto FilterOutputStream::get_close_base_stream() const -> bool
{
  return g_filter_output_stream_get_close_base_stream(const_cast<GFilterOutputStream*>(gobj()));
}

auto FilterOutputStream::set_close_base_stream (
  const bool close_base) -> void
{
  g_filter_output_stream_set_close_base_stream(gobj(), close_base);
}


static_assert(Glib::Traits::ValueCompatibleWithWrapProperty<Glib::RefPtr<OutputStream>>::value,
  "Type Glib::RefPtr<OutputStream> cannot be used in _WRAP_PROPERTY. "
  "There is no suitable template specialization of Glib::Value<>.");

auto FilterOutputStream::property_base_stream() const -> Glib::PropertyProxy_ReadOnly< Glib::RefPtr<OutputStream> >
{
  return {this, "base-stream"};
}

auto FilterOutputStream::property_close_base_stream() const -> Glib::PropertyProxy_ReadOnly< bool >
{
  return {this, "close-base-stream"};
}


} // namespace Gio


