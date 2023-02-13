


#include <libmm-glib/mm-glib.hxx>

#include <libmm-gdk/texture.hxx>
#include <libmm-gdk/texture_p.hxx>


/* Copyright (C) 2017 The gtkmm Development Team
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

#include <libmm-glib/bytes.hxx>
#include <libmm-gio/file.hxx>
#include <libmm-gdk/pixbuf.hxx>
#include <gdk/gdk.h>

namespace
{
} // anonymous namespace


Gdk::TextureError::TextureError(const Code error_code, const Glib::ustring& error_message)
: Error(GDK_TEXTURE_ERROR, error_code, error_message)
{}

Gdk::TextureError::TextureError(GError* gobject)
: Error(gobject)
{}

auto Gdk::TextureError::code() const -> Code
{
  return static_cast<Code>(Error::code());
}

auto Gdk::TextureError::throw_func (GError *gobject) -> void
{
  throw TextureError(gobject);
}

// static
auto Glib::Value<Gdk::TextureError::Code>::value_type() -> GType
{
  return gdk_texture_error_get_type();
}


namespace Glib
{

auto wrap(GdkTexture* object, const bool take_copy) -> RefPtr<Gdk::Texture>
{
  return Glib::make_refptr_for_instance<Gdk::Texture>( dynamic_cast<Gdk::Texture*> (wrap_auto((GObject*)object, take_copy)) );
  //We use dynamic_cast<> in case of multiple inheritance.
}

} /* namespace Glib */


namespace Gdk
{


/* The *_Class implementation: */

auto Texture_Class::init() -> const Class&
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Class has to know the class init function to clone custom types.
    class_init_func_ = &Texture_Class::class_init_function;

    // This is actually just optimized away, apparently with no harm.
    // Make sure that the parent type has been created.
    //CppClassParent::CppObjectType::get_type();

    // Create the wrapper type, with the same class/instance size as the base type.
    register_derived_type(gdk_texture_get_type());

    // Add derived versions of interfaces, if the C type implements any interfaces:
  Paintable::add_interface(get_type());

  }

  return *this;
}


auto Texture_Class::class_init_function (void *g_class, void *class_data) -> void
{
  const auto klass = static_cast<BaseClassType*>(g_class);
  CppClassParent::class_init_function(klass, class_data);


}


auto Texture_Class::wrap_new(GObject* object) -> Glib::ObjectBase*
{
  return new Texture((GdkTexture*)object);
}


/* The implementation: */

auto Texture::gobj_copy() -> GdkTexture*
{
  reference();
  return gobj();
}

Texture::Texture(const Glib::ConstructParams& construct_params)
: Object(construct_params)
{

}

Texture::Texture(GdkTexture* castitem)
: Object((GObject*)castitem)
{}


Texture::Texture(Texture&& src) noexcept
: Object(std::move(src))
  , Paintable(std::move(src))
{}

auto Texture::operator=(Texture&& src) noexcept -> Texture&
{
  Object::operator=(std::move(src));
  Paintable::operator=(std::move(src));
  return *this;
}


Texture::~Texture() noexcept = default;

Texture::CppClassType Texture::texture_class_; // initialize static member

auto Texture::get_type() -> GType
{
  return texture_class_.init().get_type();
}


auto Texture::get_base_type() -> GType
{
  return gdk_texture_get_type();
}


Texture::Texture()
:
  // Mark this class as non-derived to allow C++ vfuncs to be skipped.
ObjectBase(nullptr),
Object(Glib::ConstructParams(texture_class_.init()))
{


}

auto Texture::create_for_pixbuf(const Glib::RefPtr<Pixbuf>& pixbuf) -> Glib::RefPtr<Texture>
{
  return Glib::wrap(gdk_texture_new_for_pixbuf(Glib::unwrap(pixbuf)));
}

auto Texture::create_from_resource(const std::string& resource_path) -> Glib::RefPtr<Texture>
{
  return Glib::wrap(gdk_texture_new_from_resource(resource_path.c_str()));
}

auto Texture::create_from_file(const Glib::RefPtr<Gio::File>& file) -> Glib::RefPtr<Texture>
{
  GError* gerror = nullptr;
  auto retvalue = Glib::wrap(gdk_texture_new_from_file(Glib::unwrap<Gio::File>(file), &gerror));
  if(gerror)
    Glib::Error::throw_exception(gerror);
  return retvalue;
}

auto Texture::create_from_filename(const std::string& path) -> Glib::RefPtr<Texture>
{
  GError* gerror = nullptr;
  auto retvalue = Glib::wrap(gdk_texture_new_from_filename(path.c_str(), &gerror));
  if(gerror)
    Glib::Error::throw_exception(gerror);
  return retvalue;
}

auto Texture::create_from_bytes(const Glib::RefPtr<const Glib::Bytes>& bytes) -> Glib::RefPtr<Texture>
{
  GError* gerror = nullptr;
  auto retvalue = Glib::wrap(gdk_texture_new_from_bytes(const_cast<GBytes*>(Glib::unwrap<Glib::Bytes>(bytes)), &gerror));
  if(gerror)
    Glib::Error::throw_exception(gerror);
  return retvalue;
}

auto Texture::get_width() const -> int
{
  return gdk_texture_get_width(const_cast<GdkTexture*>(gobj()));
}

auto Texture::get_height() const -> int
{
  return gdk_texture_get_height(const_cast<GdkTexture*>(gobj()));
}

auto Texture::download (guchar *data, const gsize stride) const -> void
{
  gdk_texture_download(const_cast<GdkTexture*>(gobj()), data, stride);
}

auto Texture::save_to_png(const Glib::ustring& filename) const -> bool
{
  return gdk_texture_save_to_png(const_cast<GdkTexture*>(gobj()), filename.c_str());
}

auto Texture::save_to_png_bytes() const -> Glib::RefPtr<Glib::Bytes>
{
  return Glib::wrap(gdk_texture_save_to_png_bytes(const_cast<GdkTexture*>(gobj())));
}

auto Texture::save_to_tiff(const std::string& filename) const -> bool
{
  return gdk_texture_save_to_tiff(const_cast<GdkTexture*>(gobj()), filename.c_str());
}

auto Texture::save_to_tiff_bytes() const -> Glib::RefPtr<Glib::Bytes>
{
  return Glib::wrap(gdk_texture_save_to_tiff_bytes(const_cast<GdkTexture*>(gobj())));
}


auto Texture::property_width() const -> Glib::PropertyProxy_ReadOnly< int >
{
  return {this, "width"};
}

auto Texture::property_height() const -> Glib::PropertyProxy_ReadOnly< int >
{
  return {this, "height"};
}


} // namespace Gdk


