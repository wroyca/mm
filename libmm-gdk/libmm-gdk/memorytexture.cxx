

#include <libmm-glib/mm-glib.hxx>

#include <libmm-gdk/memorytexture.hxx>
#include <libmm-gdk/memorytexture_p.hxx>

namespace
{
}

auto
Glib::Value<Gdk::MemoryTexture::Format>::value_type () -> GType
{
  return gdk_memory_format_get_type ();
}

namespace Glib
{

  auto
  wrap (GdkMemoryTexture* object, const bool take_copy) -> RefPtr<Gdk::MemoryTexture>
  {
    return Glib::make_refptr_for_instance<Gdk::MemoryTexture> (
        dynamic_cast<Gdk::MemoryTexture*> (
            wrap_auto ((GObject*) object, take_copy)));
  }

} // namespace Glib

namespace Gdk
{

  auto
  MemoryTexture_Class::init () -> const Class&
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
  MemoryTexture_Class::wrap_new (GObject* object) -> Glib::ObjectBase*
  {
    return new MemoryTexture ((GdkMemoryTexture*) object);
  }

  auto
  MemoryTexture::gobj_copy () -> GdkMemoryTexture*
  {
    reference ();
    return gobj ();
  }

  MemoryTexture::MemoryTexture (const Glib::ConstructParams& construct_params)
    : Texture (construct_params)
  {
  }

  MemoryTexture::MemoryTexture (GdkMemoryTexture* castitem)
    : Texture ((GdkTexture*) castitem)
  {
  }

  MemoryTexture::MemoryTexture (MemoryTexture&& src) noexcept
    : Texture (std::move (src))
  {
  }

  auto
  MemoryTexture::operator= (MemoryTexture&& src) noexcept -> MemoryTexture&
  {
    Texture::operator= (std::move (src));
    return *this;
  }

  MemoryTexture::~MemoryTexture () noexcept = default;

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
    : ObjectBase (nullptr),
      Texture (Glib::ConstructParams (memorytexture_class_.init ()))
  {
  }

  auto
  MemoryTexture::create (const int width,
                         const int height,
                         Format format,
                         const Glib::RefPtr<const Glib::Bytes>& bytes,
                         const gsize stride) -> Glib::RefPtr<Texture>
  {
    return Glib::wrap (gdk_memory_texture_new (
        width,
        height,
        static_cast<GdkMemoryFormat> (format),
        const_cast<GBytes*> (Glib::unwrap<Glib::Bytes> (bytes)),
        stride));
  }

} // namespace Gdk
