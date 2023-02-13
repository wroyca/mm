


#include <libmm-glib/mm-glib.hpp>

#include <libmm-gio/filterinputstream.hpp>
#include <libmm-gio/filterinputstream_p.hpp>


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

FilterInputStream::FilterInputStream(const Glib::RefPtr<InputStream>& base_stream)
: // Mark this class as non-derived to allow C++ vfuncs to be skipped.
ObjectBase(nullptr),
InputStream(Glib::ConstructParams(filterinputstream_class_.init(), "base_stream",Glib::unwrap(base_stream), nullptr))
{
}

} // namespace Gio

namespace
{
} // anonymous namespace


namespace Glib
{

auto wrap(GFilterInputStream* object, const bool take_copy) -> RefPtr<Gio::FilterInputStream>
{
  return Glib::make_refptr_for_instance<Gio::FilterInputStream>( dynamic_cast<Gio::FilterInputStream*> (wrap_auto((GObject*)object, take_copy)) );
  //We use dynamic_cast<> in case of multiple inheritance.
}

} /* namespace Glib */


namespace Gio
{


/* The *_Class implementation: */

auto FilterInputStream_Class::init() -> const Class&
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Class has to know the class init function to clone custom types.
    class_init_func_ = &FilterInputStream_Class::class_init_function;

    // This is actually just optimized away, apparently with no harm.
    // Make sure that the parent type has been created.
    //CppClassParent::CppObjectType::get_type();

    // Create the wrapper type, with the same class/instance size as the base type.
    register_derived_type(g_filter_input_stream_get_type());

    // Add derived versions of interfaces, if the C type implements any interfaces:

  }

  return *this;
}


auto FilterInputStream_Class::class_init_function (void *g_class, void *class_data) -> void
{
  const auto klass = static_cast<BaseClassType*>(g_class);
  CppClassParent::class_init_function(klass, class_data);


}


auto FilterInputStream_Class::wrap_new(GObject* object) -> Glib::ObjectBase*
{
  return new FilterInputStream((GFilterInputStream*)object);
}


/* The implementation: */

auto FilterInputStream::gobj_copy() -> GFilterInputStream*
{
  reference();
  return gobj();
}

FilterInputStream::FilterInputStream(const Glib::ConstructParams& construct_params)
: InputStream(construct_params)
{

}

FilterInputStream::FilterInputStream(GFilterInputStream* castitem)
: InputStream((GInputStream*)castitem)
{}


FilterInputStream::FilterInputStream(FilterInputStream&& src) noexcept
: InputStream(std::move(src))
{}

auto FilterInputStream::operator=(FilterInputStream&& src) noexcept -> FilterInputStream&
{
  InputStream::operator=(std::move(src));
  return *this;
}


FilterInputStream::~FilterInputStream() noexcept = default;

FilterInputStream::CppClassType FilterInputStream::filterinputstream_class_; // initialize static member

auto FilterInputStream::get_type() -> GType
{
  return filterinputstream_class_.init().get_type();
}


auto FilterInputStream::get_base_type() -> GType
{
  return g_filter_input_stream_get_type();
}


auto FilterInputStream::get_base_stream() -> Glib::RefPtr<InputStream>
{
  auto retvalue = Glib::wrap(g_filter_input_stream_get_base_stream(gobj()));
  if(retvalue)
    retvalue->reference(); //The function does not do a ref for us.
  return retvalue;
}

auto FilterInputStream::get_base_stream() const -> Glib::RefPtr<const InputStream>
{
  return const_cast<FilterInputStream*>(this)->get_base_stream();
}

auto FilterInputStream::get_close_base_stream() const -> bool
{
  return g_filter_input_stream_get_close_base_stream(const_cast<GFilterInputStream*>(gobj()));
}

auto FilterInputStream::set_close_base_stream (
  const bool close_base) -> void
{
  g_filter_input_stream_set_close_base_stream(gobj(), close_base);
}


static_assert(Glib::Traits::ValueCompatibleWithWrapProperty<Glib::RefPtr<InputStream>>::value,
  "Type Glib::RefPtr<InputStream> cannot be used in _WRAP_PROPERTY. "
  "There is no suitable template specialization of Glib::Value<>.");

auto FilterInputStream::property_base_stream() const -> Glib::PropertyProxy_ReadOnly< Glib::RefPtr<InputStream> >
{
  return {this, "base-stream"};
}

auto FilterInputStream::property_close_base_stream() -> Glib::PropertyProxy< bool >
{
  return {this, "close-base-stream"};
}

auto FilterInputStream::property_close_base_stream() const -> Glib::PropertyProxy_ReadOnly< bool >
{
  return {this, "close-base-stream"};
}


} // namespace Gio


