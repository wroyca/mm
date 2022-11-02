// Generated by gmmproc 2.74.0 -- DO NOT MODIFY!


#include <mm/glib/mm-glib.h>

#include <mm/gdk/memorytexture.h>
#include <mm/gdk/private/memorytexture_p.h>


/* Copyright (C) 2020 The gtkmm Development Team
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

namespace
{
} // anonymous namespace

// static
auto Glib::Value<Gdk::MemoryTexture::Format>::value_type() -> GType
{
  return gdk_memory_format_get_type();
}


namespace Glib
{

auto wrap(GdkMemoryTexture* object, bool take_copy) -> Glib::RefPtr<Gdk::MemoryTexture>
{
  return Glib::make_refptr_for_instance<Gdk::MemoryTexture>( dynamic_cast<Gdk::MemoryTexture*> (Glib::wrap_auto ((GObject*)(object), take_copy)) );
  //We use dynamic_cast<> in case of multiple inheritance.
}

} /* namespace Glib */


namespace Gdk
{


/* The *_Class implementation: */

auto MemoryTexture_Class::init() -> const Glib::Class&
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Class has to know the class init function to clone custom types.
    class_init_func_ = &MemoryTexture_Class::class_init_function;

    // This is actually just optimized away, apparently with no harm.
    // Make sure that the parent type has been created.
    //CppClassParent::CppObjectType::get_type();

    // Create the wrapper type, with the same class/instance size as the base type.
    register_derived_type(gdk_memory_texture_get_type());

    // Add derived versions of interfaces, if the C type implements any interfaces:

  }

  return *this;
}


void MemoryTexture_Class::class_init_function(void* g_class, void* class_data)
{
  const auto klass = static_cast<BaseClassType*>(g_class);
  CppClassParent::class_init_function(klass, class_data);


}


auto MemoryTexture_Class::wrap_new(GObject* object) -> Glib::ObjectBase*
{
  return new MemoryTexture((GdkMemoryTexture*)object);
}


/* The implementation: */

auto MemoryTexture::gobj_copy() -> GdkMemoryTexture*
{
  reference();
  return gobj();
}

MemoryTexture::MemoryTexture(const Glib::ConstructParams& construct_params)
:
  Gdk::Texture(construct_params)
{

}

MemoryTexture::MemoryTexture(GdkMemoryTexture* castitem)
:
  Gdk::Texture((GdkTexture*)(castitem))
{}


MemoryTexture::MemoryTexture(MemoryTexture&& src) noexcept
: Gdk::Texture(std::move(src))
{}

auto MemoryTexture::operator=(MemoryTexture&& src) noexcept -> MemoryTexture&
{
  Gdk::Texture::operator=(std::move(src));
  return *this;
}


MemoryTexture::~MemoryTexture() noexcept
{}


MemoryTexture::CppClassType MemoryTexture::memorytexture_class_; // initialize static member

auto MemoryTexture::get_type() -> GType
{
  return memorytexture_class_.init().get_type();
}


auto MemoryTexture::get_base_type() -> GType
{
  return gdk_memory_texture_get_type();
}


MemoryTexture::MemoryTexture()
:
  // Mark this class as non-derived to allow C++ vfuncs to be skipped.
  Glib::ObjectBase(nullptr),
  Gdk::Texture(Glib::ConstructParams(memorytexture_class_.init()))
{


}

auto MemoryTexture::create(int width, int height, Format format, const Glib::RefPtr<const Glib::Bytes>& bytes, gsize stride) -> Glib::RefPtr<Texture>
{
  return Glib::wrap(gdk_memory_texture_new(width, height, static_cast<GdkMemoryFormat>(format), const_cast<GBytes*>(Glib::unwrap<Glib::Bytes>(bytes)), stride));
}


} // namespace Gdk

