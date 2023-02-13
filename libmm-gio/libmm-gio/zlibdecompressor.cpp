


#include <libmm-glib/mm-glib.hpp>

#include <libmm-gio/zlibdecompressor.hpp>
#include <libmm-gio/zlibdecompressor_p.hpp>


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
#include <libmm-gio/fileinfo.hpp>

namespace Gio
{

} // namespace Gio

namespace
{
} // anonymous namespace


namespace Glib
{

auto wrap(GZlibDecompressor* object, const bool take_copy) -> RefPtr<Gio::ZlibDecompressor>
{
  return Glib::make_refptr_for_instance<Gio::ZlibDecompressor>( dynamic_cast<Gio::ZlibDecompressor*> (wrap_auto((GObject*)object, take_copy)) );
  //We use dynamic_cast<> in case of multiple inheritance.
}

} /* namespace Glib */


namespace Gio
{


/* The *_Class implementation: */

auto ZlibDecompressor_Class::init() -> const Class&
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Class has to know the class init function to clone custom types.
    class_init_func_ = &ZlibDecompressor_Class::class_init_function;

    // This is actually just optimized away, apparently with no harm.
    // Make sure that the parent type has been created.
    //CppClassParent::CppObjectType::get_type();

    // Create the wrapper type, with the same class/instance size as the base type.
    register_derived_type(g_zlib_decompressor_get_type());

    // Add derived versions of interfaces, if the C type implements any interfaces:
  Converter::add_interface(get_type());

  }

  return *this;
}


auto ZlibDecompressor_Class::class_init_function (void *g_class, void *class_data) -> void
{
  const auto klass = static_cast<BaseClassType*>(g_class);
  CppClassParent::class_init_function(klass, class_data);


}


auto ZlibDecompressor_Class::wrap_new(GObject* object) -> Glib::ObjectBase*
{
  return new ZlibDecompressor((GZlibDecompressor*)object);
}


/* The implementation: */

auto ZlibDecompressor::gobj_copy() -> GZlibDecompressor*
{
  reference();
  return gobj();
}

ZlibDecompressor::ZlibDecompressor(const Glib::ConstructParams& construct_params)
: Object(construct_params)
{

}

ZlibDecompressor::ZlibDecompressor(GZlibDecompressor* castitem)
: Object((GObject*)castitem)
{}


ZlibDecompressor::ZlibDecompressor(ZlibDecompressor&& src) noexcept
: Object(std::move(src))
  , Converter(std::move(src))
{}

auto ZlibDecompressor::operator=(ZlibDecompressor&& src) noexcept -> ZlibDecompressor&
{
  Object::operator=(std::move(src));
  Converter::operator=(std::move(src));
  return *this;
}


ZlibDecompressor::~ZlibDecompressor() noexcept = default;

ZlibDecompressor::CppClassType ZlibDecompressor::zlibdecompressor_class_; // initialize static member

auto ZlibDecompressor::get_type() -> GType
{
  return zlibdecompressor_class_.init().get_type();
}


auto ZlibDecompressor::get_base_type() -> GType
{
  return g_zlib_decompressor_get_type();
}


ZlibDecompressor::ZlibDecompressor(const ZlibCompressorFormat format)
:
  // Mark this class as non-derived to allow C++ vfuncs to be skipped.
ObjectBase(nullptr),
Object(Glib::ConstructParams(zlibdecompressor_class_.init(), "format", format, nullptr))
{


}

auto ZlibDecompressor::create(
  const ZlibCompressorFormat format) -> Glib::RefPtr<ZlibDecompressor>
{
  return Glib::make_refptr_for_instance<ZlibDecompressor>( new ZlibDecompressor(format) );
}

auto ZlibDecompressor::get_file_info() -> Glib::RefPtr<FileInfo>
{
  return Glib::wrap(g_zlib_decompressor_get_file_info(gobj()));
}

auto ZlibDecompressor::get_file_info() const -> Glib::RefPtr<const FileInfo>
{
  return const_cast<ZlibDecompressor*>(this)->get_file_info();
}


static_assert(Glib::Traits::ValueCompatibleWithWrapProperty<Glib::RefPtr<FileInfo>>::value,
  "Type Glib::RefPtr<FileInfo> cannot be used in _WRAP_PROPERTY. "
  "There is no suitable template specialization of Glib::Value<>.");

auto ZlibDecompressor::property_file_info() const -> Glib::PropertyProxy_ReadOnly< Glib::RefPtr<FileInfo> >
{
  return {this, "file-info"};
}

static_assert(Glib::Traits::ValueCompatibleWithWrapProperty<ZlibCompressorFormat>::value,
  "Type ZlibCompressorFormat cannot be used in _WRAP_PROPERTY. "
  "There is no suitable template specialization of Glib::Value<>.");

auto ZlibDecompressor::property_format() const -> Glib::PropertyProxy_ReadOnly< ZlibCompressorFormat >
{
  return {this, "format"};
}


} // namespace Gio


