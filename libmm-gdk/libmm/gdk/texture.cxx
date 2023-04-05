// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/gdk/texture.hxx>
#include <libmm/gdk/texture_p.hxx>

#include <gdk/gdk.h>
#include <libmm/gdk/pixbuf.hxx>
#include <libmm/gio/file.hxx>
#include <libmm/glib/bytes.hxx>

namespace
{
}

gdk::TextureError::TextureError (gdk::TextureError::Code error_code,
                                 const glib::ustring& error_message)
  : glib::Error (GDK_TEXTURE_ERROR, error_code, error_message)
{
}

gdk::TextureError::TextureError (GError* gobject)
  : glib::Error (gobject)
{
}

auto
gdk::TextureError::code () const -> gdk::TextureError::Code
{
  return static_cast<Code> (glib::Error::code ());
}

auto
gdk::TextureError::throw_func (GError* gobject) -> void
{
  throw gdk::TextureError (gobject);
}

auto
glib::Value<gdk::TextureError::Code>::value_type () -> GType
{
  return gdk_texture_error_get_type ();
}

namespace glib
{

  auto
  wrap (GdkTexture* object, bool take_copy) -> glib::RefPtr<gdk::Texture>
  {
    return glib::make_refptr_for_instance<gdk::Texture> (
        dynamic_cast<gdk::Texture*> (
            glib::wrap_auto ((GObject*) (object), take_copy)));
  }

} // namespace glib

namespace gdk
{

  auto
  Texture_Class::init () -> const glib::Class&
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
  Texture_Class::wrap_new (GObject* object) -> glib::ObjectBase*
  {
    return new Texture ((GdkTexture*) object);
  }

  auto
  Texture::gobj_copy () -> GdkTexture*
  {
    reference ();
    return gobj ();
  }

  Texture::Texture (const glib::ConstructParams& construct_params)
    : glib::Object (construct_params)
  {
  }

  Texture::Texture (GdkTexture* castitem)
    : glib::Object ((GObject*) (castitem))
  {
  }

  Texture::Texture (Texture&& src) noexcept
    : glib::Object (std::move (src)),
      Paintable (std::move (src))
  {
  }

  auto
  Texture::operator= (Texture&& src) noexcept -> Texture&
  {
    glib::Object::operator= (std::move (src));
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
    : glib::ObjectBase (nullptr),
      glib::Object (glib::ConstructParams (texture_class_.init ()))
  {
  }

  auto
  Texture::create_for_pixbuf (const glib::RefPtr<Pixbuf>& pixbuf) -> glib::RefPtr<Texture>
  {
    return glib::wrap (gdk_texture_new_for_pixbuf (glib::unwrap (pixbuf)));
  }

  auto
  Texture::create_from_resource (const std::string& resource_path) -> glib::RefPtr<Texture>
  {
    return glib::wrap (gdk_texture_new_from_resource (resource_path.c_str ()));
  }

  auto
  Texture::create_from_file (const glib::RefPtr<gio::File>& file) -> glib::RefPtr<Texture>
  {
    GError* gerror = nullptr;
    auto retvalue = glib::wrap (gdk_texture_new_from_file (
        const_cast<GFile*> (glib::unwrap<gio::File> (file)),
        &(gerror)));
    if (gerror)
      ::glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  Texture::create_from_filename (const std::string& path) -> glib::RefPtr<Texture>
  {
    GError* gerror = nullptr;
    auto retvalue =
        glib::wrap (gdk_texture_new_from_filename (path.c_str (), &(gerror)));
    if (gerror)
      ::glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  Texture::create_from_bytes (const glib::RefPtr<const glib::Bytes>& bytes) -> glib::RefPtr<Texture>
  {
    GError* gerror = nullptr;
    auto retvalue = glib::wrap (gdk_texture_new_from_bytes (
        const_cast<GBytes*> (glib::unwrap<glib::Bytes> (bytes)),
        &(gerror)));
    if (gerror)
      ::glib::Error::throw_exception (gerror);
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
  Texture::save_to_png (const glib::ustring& filename) const -> bool
  {
    return gdk_texture_save_to_png (const_cast<GdkTexture*> (gobj ()),
                                    filename.c_str ());
  }

  auto
  Texture::save_to_png_bytes () const -> glib::RefPtr<glib::Bytes>
  {
    return glib::wrap (
        gdk_texture_save_to_png_bytes (const_cast<GdkTexture*> (gobj ())));
  }

  auto
  Texture::save_to_tiff (const std::string& filename) const -> bool
  {
    return gdk_texture_save_to_tiff (const_cast<GdkTexture*> (gobj ()),
                                     filename.c_str ());
  }

  auto
  Texture::save_to_tiff_bytes () const -> glib::RefPtr<glib::Bytes>
  {
    return glib::wrap (
        gdk_texture_save_to_tiff_bytes (const_cast<GdkTexture*> (gobj ())));
  }

  auto
  Texture::property_width () const -> glib::PropertyProxy_ReadOnly<int>
  {
    return glib::PropertyProxy_ReadOnly<int> (this, "width");
  }

  auto
  Texture::property_height () const -> glib::PropertyProxy_ReadOnly<int>
  {
    return glib::PropertyProxy_ReadOnly<int> (this, "height");
  }

} // namespace gdk
