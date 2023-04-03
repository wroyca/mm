// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/gdk/gltexture.hxx>
#include <libmm/gdk/gltexture_p.hxx>

#include <libmm/gdk/glcontext.hxx>

namespace
{
  auto
  GLTexture_destroy_callback (void* data) -> void
  {
    auto the_slot = static_cast<Gdk::GLTexture::SlotGLReleased*> (data);
    try
    {
      (*the_slot) ();
    }
    catch (...)
    {
      Glib::exception_handlers_invoke ();
    }
    delete the_slot;
  }

} // namespace

namespace
{
}

namespace Glib
{

  auto
  wrap (GdkGLTexture* object, bool take_copy) -> Glib::RefPtr<Gdk::GLTexture>
  {
    return Glib::make_refptr_for_instance<Gdk::GLTexture> (
        dynamic_cast<Gdk::GLTexture*> (
            Glib::wrap_auto ((GObject*) (object), take_copy)));
  }

} // namespace Glib

namespace Gdk
{

  auto
  GLTexture_Class::init () -> const Glib::Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &GLTexture_Class::class_init_function;

      register_derived_type (gdk_gl_texture_get_type ());
    }

    return *this;
  }

  auto
  GLTexture_Class::class_init_function (void* g_class, void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);
  }

  auto
  GLTexture_Class::wrap_new (GObject* object) -> Glib::ObjectBase*
  {
    return new GLTexture ((GdkGLTexture*) object);
  }

  auto
  GLTexture::gobj_copy () -> GdkGLTexture*
  {
    reference ();
    return gobj ();
  }

  GLTexture::GLTexture (const Glib::ConstructParams& construct_params)
    : Gdk::Texture (construct_params)
  {
  }

  GLTexture::GLTexture (GdkGLTexture* castitem)
    : Gdk::Texture ((GdkTexture*) (castitem))
  {
  }

  GLTexture::GLTexture (GLTexture&& src) noexcept
    : Gdk::Texture (std::move (src))
  {
  }

  auto
  GLTexture::operator= (GLTexture&& src) noexcept -> GLTexture&
  {
    Gdk::Texture::operator= (std::move (src));
    return *this;
  }

  GLTexture::~GLTexture () noexcept {}

  GLTexture::CppClassType GLTexture::gltexture_class_;

  auto
  GLTexture::get_type () -> GType
  {
    return gltexture_class_.init ().get_type ();
  }

  auto
  GLTexture::get_base_type () -> GType
  {
    return gdk_gl_texture_get_type ();
  }

  GLTexture::GLTexture ()
    : Glib::ObjectBase (nullptr),
      Gdk::Texture (Glib::ConstructParams (gltexture_class_.init ()))
  {
  }

  auto
  GLTexture::create (const Glib::RefPtr<GLContext>& context,
                     guint id,
                     int width,
                     int height,
                     const SlotGLReleased& slot) -> Glib::RefPtr<Texture>
  {
    auto slot_copy = new SlotGLReleased (slot);

    return Glib::wrap (gdk_gl_texture_new (Glib::unwrap (context),
                                           id,
                                           width,
                                           height,
                                           &GLTexture_destroy_callback,
                                           slot_copy));
  }

  auto
  GLTexture::release () -> void
  {
    gdk_gl_texture_release (gobj ());
  }

} // namespace Gdk
