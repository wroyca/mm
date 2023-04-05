// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/gdk/memorytexture.hxx>
#include <libmm/gdk/memorytexture_p.hxx>

namespace
{
}

auto
glib::Value<gdk::MemoryTexture::Format>::value_type () -> GType
{
  return gdk_memory_format_get_type ();
}

namespace glib
{

  auto
  wrap (GdkMemoryTexture* object, bool take_copy) -> glib::RefPtr<gdk::MemoryTexture>
  {
    return glib::make_refptr_for_instance<gdk::MemoryTexture> (
        dynamic_cast<gdk::MemoryTexture*> (
            glib::wrap_auto ((GObject*) (object), take_copy)));
  }

} // namespace glib

namespace gdk
{

  auto
  MemoryTexture_Class::init () -> const glib::Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &MemoryTexture_Class::class_init_function;

      register_derived_type (gdk_memory_texture_get_type ());
    }

    return *this;
  }

  auto
  MemoryTexture_Class::class_init_function (void* g_class, void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);
  }

  auto
  MemoryTexture_Class::wrap_new (GObject* object) -> glib::ObjectBase*
  {
    return new MemoryTexture ((GdkMemoryTexture*) object);
  }

  auto
  MemoryTexture::gobj_copy () -> GdkMemoryTexture*
  {
    reference ();
    return gobj ();
  }

  MemoryTexture::MemoryTexture (const glib::ConstructParams& construct_params)
    : gdk::Texture (construct_params)
  {
  }

  MemoryTexture::MemoryTexture (GdkMemoryTexture* castitem)
    : gdk::Texture ((GdkTexture*) (castitem))
  {
  }

  MemoryTexture::MemoryTexture (MemoryTexture&& src) noexcept
    : gdk::Texture (std::move (src))
  {
  }

  auto
  MemoryTexture::operator= (MemoryTexture&& src) noexcept -> MemoryTexture&
  {
    gdk::Texture::operator= (std::move (src));
    return *this;
  }

  MemoryTexture::~MemoryTexture () noexcept {}

  MemoryTexture::CppClassType MemoryTexture::memorytexture_class_;

  auto
  MemoryTexture::get_type () -> GType
  {
    return memorytexture_class_.init ().get_type ();
  }

  auto
  MemoryTexture::get_base_type () -> GType
  {
    return gdk_memory_texture_get_type ();
  }

  MemoryTexture::MemoryTexture ()
    : glib::ObjectBase (nullptr),
      gdk::Texture (glib::ConstructParams (memorytexture_class_.init ()))
  {
  }

  auto
  MemoryTexture::create (int width,
                         int height,
                         Format format,
                         const glib::RefPtr<const glib::Bytes>& bytes,
                         gsize stride) -> glib::RefPtr<Texture>
  {
    return glib::wrap (gdk_memory_texture_new (
        width,
        height,
        static_cast<GdkMemoryFormat> (format),
        const_cast<GBytes*> (glib::unwrap<glib::Bytes> (bytes)),
        stride));
  }

} // namespace gdk
