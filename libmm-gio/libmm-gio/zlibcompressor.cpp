


#include <libmm-glib/mm-glib.hpp>

#include <libmm-gio/zlibcompressor.hpp>
#include <libmm-gio/zlibcompressor_p.hpp>


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

// static
auto Glib::Value<Gio::ZlibCompressorFormat>::value_type() -> GType
{
  return g_zlib_compressor_format_get_type();
}


namespace Glib
{

auto wrap(GZlibCompressor* object, const bool take_copy) -> RefPtr<Gio::ZlibCompressor>
{
  return Glib::make_refptr_for_instance<Gio::ZlibCompressor>( dynamic_cast<Gio::ZlibCompressor*> (wrap_auto((GObject*)object, take_copy)) );
  //We use dynamic_cast<> in case of multiple inheritance.
}

} /* namespace Glib */


namespace Gio
{


/* The *_Class implementation: */

auto ZlibCompressor_Class::init() -> const Class&
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Class has to know the class init function to clone custom types.
    class_init_func_ = &ZlibCompressor_Class::class_init_function;

    // This is actually just optimized away, apparently with no harm.
    // Make sure that the parent type has been created.
    //CppClassParent::CppObjectType::get_type();

    // Create the wrapper type, with the same class/instance size as the base type.
    register_derived_type(g_zlib_compressor_get_type());

    // Add derived versions of interfaces, if the C type implements any interfaces:
  Converter::add_interface(get_type());

  }

  return *this;
}


auto ZlibCompressor_Class::class_init_function (void *g_class, void *class_data) -> void
{
  const auto klass = static_cast<BaseClassType*>(g_class);
  CppClassParent::class_init_function(klass, class_data);


}


auto ZlibCompressor_Class::wrap_new(GObject* object) -> Glib::ObjectBase*
{
  return new ZlibCompressor((GZlibCompressor*)object);
}


/* The implementation: */

auto ZlibCompressor::gobj_copy() -> GZlibCompressor*
{
  reference();
  return gobj();
}

ZlibCompressor::ZlibCompressor(const Glib::ConstructParams& construct_params)
: Object(construct_params)
{

}

ZlibCompressor::ZlibCompressor(GZlibCompressor* castitem)
: Object((GObject*)castitem)
{}


ZlibCompressor::ZlibCompressor(ZlibCompressor&& src) noexcept
: Object(std::move(src))
  , Converter(std::move(src))
{}

auto ZlibCompressor::operator=(ZlibCompressor&& src) noexcept -> ZlibCompressor&
{
  Object::operator=(std::move(src));
  Converter::operator=(std::move(src));
  return *this;
}


ZlibCompressor::~ZlibCompressor() noexcept = default;

ZlibCompressor::CppClassType ZlibCompressor::zlibcompressor_class_; // initialize static member

auto ZlibCompressor::get_type() -> GType
{
  return zlibcompressor_class_.init().get_type();
}


auto ZlibCompressor::get_base_type() -> GType
{
  return g_zlib_compressor_get_type();
}


ZlibCompressor::ZlibCompressor(const ZlibCompressorFormat format, const int level)
:
  // Mark this class as non-derived to allow C++ vfuncs to be skipped.
ObjectBase(nullptr),
Object(Glib::ConstructParams(zlibcompressor_class_.init(), "format", format, "level", level, nullptr))
{


}

auto ZlibCompressor::create(
  const ZlibCompressorFormat format, const int level) -> Glib::RefPtr<ZlibCompressor>
{
  return Glib::make_refptr_for_instance<ZlibCompressor>( new ZlibCompressor(format, level) );
}

auto ZlibCompressor::get_file_info() -> Glib::RefPtr<FileInfo>
{
  return Glib::wrap(g_zlib_compressor_get_file_info(gobj()));
}

auto ZlibCompressor::get_file_info() const -> Glib::RefPtr<const FileInfo>
{
  return const_cast<ZlibCompressor*>(this)->get_file_info();
}

auto ZlibCompressor::set_file_info (const Glib::RefPtr <FileInfo> &file_info) -> void
{
  g_zlib_compressor_set_file_info(gobj(), Glib::unwrap(file_info));
}


static_assert(Glib::Traits::ValueCompatibleWithWrapProperty<Glib::RefPtr<FileInfo>>::value,
  "Type Glib::RefPtr<FileInfo> cannot be used in _WRAP_PROPERTY. "
  "There is no suitable template specialization of Glib::Value<>.");

auto ZlibCompressor::property_file_info() -> Glib::PropertyProxy< Glib::RefPtr<FileInfo> >
{
  return {this, "file-info"};
}

auto ZlibCompressor::property_file_info() const -> Glib::PropertyProxy_ReadOnly< Glib::RefPtr<FileInfo> >
{
  return {this, "file-info"};
}

static_assert(Glib::Traits::ValueCompatibleWithWrapProperty<ZlibCompressorFormat>::value,
  "Type ZlibCompressorFormat cannot be used in _WRAP_PROPERTY. "
  "There is no suitable template specialization of Glib::Value<>.");

auto ZlibCompressor::property_format() const -> Glib::PropertyProxy_ReadOnly< ZlibCompressorFormat >
{
  return {this, "format"};
}

auto ZlibCompressor::property_level() const -> Glib::PropertyProxy_ReadOnly< int >
{
  return {this, "level"};
}


} // namespace Gio


