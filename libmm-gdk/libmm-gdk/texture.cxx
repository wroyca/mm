// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm-glib/mm-glib.hxx>

#include <libmm-gdk/texture.hxx>
#include <libmm-gdk/texture_p.hxx>

#include <gdk/gdk.h>
#include <libmm-gdk/pixbuf.hxx>
#include <libmm-gio/file.hxx>
#include <libmm-glib/bytes.hxx>

namespace
{
}

Gdk::TextureError::TextureError (Gdk::TextureError::Code error_code,
                                 const Glib::ustring& error_message)
  : Glib::Error (GDK_TEXTURE_ERROR, error_code, error_message)
{
}

Gdk::TextureError::TextureError (GError* gobject)
  : Glib::Error (gobject)
{
}

auto
Gdk::TextureError::code () const -> Gdk::TextureError::Code
{
  return static_cast<Code> (Glib::Error::code ());
}

auto
Gdk::TextureError::throw_func (GError* gobject) -> void
{
  throw Gdk::TextureError (gobject);
}

auto
Glib::Value<Gdk::TextureError::Code>::value_type () -> GType
{
  return gdk_texture_error_get_type ();
}

namespace Glib
{

  auto
  wrap (GdkTexture* object, bool take_copy) -> Glib::RefPtr<Gdk::Texture>
  {
    return Glib::make_refptr_for_instance<Gdk::Texture> (
        dynamic_cast<Gdk::Texture*> (
            Glib::wrap_auto ((GObject*) (object), take_copy)));
  }

} // namespace Glib

namespace Gdk
{

  auto
  Texture_Class::init () -> const Glib::Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &Texture_Class::class_init_function;

      register_derived_type (gdk_texture_get_type ());

      Paintable::add_interface (get_type ());
    }

    return *this;
  }

  auto
  Texture_Class::class_init_function (void* g_class, void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);
  }

  auto
  Texture_Class::wrap_new (GObject* object) -> Glib::ObjectBase*
  {
    return new Texture ((GdkTexture*) object);
  }

  auto
  Texture::gobj_copy () -> GdkTexture*
  {
    reference ();
    return gobj ();
  }

  Texture::Texture (const Glib::ConstructParams& construct_params)
    : Glib::Object (construct_params)
  {
  }

  Texture::Texture (GdkTexture* castitem)
    : Glib::Object ((GObject*) (castitem))
  {
  }

  Texture::Texture (Texture&& src) noexcept
    : Glib::Object (std::move (src)),
      Paintable (std::move (src))
  {
  }

  auto
  Texture::operator= (Texture&& src) noexcept -> Texture&
  {
    Glib::Object::operator= (std::move (src));
    Paintable::operator= (std::move (src));
    return *this;
  }

  Texture::~Texture () noexcept {}

  Texture::CppClassType Texture::texture_class_;

  auto
  Texture::get_type () -> GType
  {
    return texture_class_.init ().get_type ();
  }

  auto
  Texture::get_base_type () -> GType
  {
    return gdk_texture_get_type ();
  }

  Texture::Texture ()
    : Glib::ObjectBase (nullptr),
      Glib::Object (Glib::ConstructParams (texture_class_.init ()))
  {
  }

  auto
  Texture::create_for_pixbuf (const Glib::RefPtr<Pixbuf>& pixbuf) -> Glib::RefPtr<Texture>
  {
    return Glib::wrap (gdk_texture_new_for_pixbuf (Glib::unwrap (pixbuf)));
  }

  auto
  Texture::create_from_resource (const std::string& resource_path) -> Glib::RefPtr<Texture>
  {
    return Glib::wrap (gdk_texture_new_from_resource (resource_path.c_str ()));
  }

  auto
  Texture::create_from_file (const Glib::RefPtr<Gio::File>& file) -> Glib::RefPtr<Texture>
  {
    GError* gerror = nullptr;
    auto retvalue = Glib::wrap (gdk_texture_new_from_file (
        const_cast<GFile*> (Glib::unwrap<Gio::File> (file)),
        &(gerror)));
    if (gerror)
      ::Glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  Texture::create_from_filename (const std::string& path) -> Glib::RefPtr<Texture>
  {
    GError* gerror = nullptr;
    auto retvalue =
        Glib::wrap (gdk_texture_new_from_filename (path.c_str (), &(gerror)));
    if (gerror)
      ::Glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  Texture::create_from_bytes (const Glib::RefPtr<const Glib::Bytes>& bytes) -> Glib::RefPtr<Texture>
  {
    GError* gerror = nullptr;
    auto retvalue = Glib::wrap (gdk_texture_new_from_bytes (
        const_cast<GBytes*> (Glib::unwrap<Glib::Bytes> (bytes)),
        &(gerror)));
    if (gerror)
      ::Glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  Texture::get_width () const -> int
  {
    return gdk_texture_get_width (const_cast<GdkTexture*> (gobj ()));
  }

  auto
  Texture::get_height () const -> int
  {
    return gdk_texture_get_height (const_cast<GdkTexture*> (gobj ()));
  }

  auto
  Texture::download (guchar* data, gsize stride) const -> void
  {
    gdk_texture_download (const_cast<GdkTexture*> (gobj ()), data, stride);
  }

  auto
  Texture::save_to_png (const Glib::ustring& filename) const -> bool
  {
    return gdk_texture_save_to_png (const_cast<GdkTexture*> (gobj ()),
                                    filename.c_str ());
  }

  auto
  Texture::save_to_png_bytes () const -> Glib::RefPtr<Glib::Bytes>
  {
    return Glib::wrap (
        gdk_texture_save_to_png_bytes (const_cast<GdkTexture*> (gobj ())));
  }

  auto
  Texture::save_to_tiff (const std::string& filename) const -> bool
  {
    return gdk_texture_save_to_tiff (const_cast<GdkTexture*> (gobj ()),
                                     filename.c_str ());
  }

  auto
  Texture::save_to_tiff_bytes () const -> Glib::RefPtr<Glib::Bytes>
  {
    return Glib::wrap (
        gdk_texture_save_to_tiff_bytes (const_cast<GdkTexture*> (gobj ())));
  }

  auto
  Texture::property_width () const -> Glib::PropertyProxy_ReadOnly<int>
  {
    return Glib::PropertyProxy_ReadOnly<int> (this, "width");
  }

  auto
  Texture::property_height () const -> Glib::PropertyProxy_ReadOnly<int>
  {
    return Glib::PropertyProxy_ReadOnly<int> (this, "height");
  }

} // namespace Gdk
