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
    auto the_slot = static_cast<gdk::GLTexture::SlotGLReleased*> (data);
    try
    {
      (*the_slot) ();
    }
    catch (...)
    {
      glib::exception_handlers_invoke ();
    }
    delete the_slot;
  }

} // namespace

namespace
{
}

namespace glib
{

  auto
  wrap (GdkGLTexture* object, bool take_copy) -> glib::RefPtr<gdk::GLTexture>
  {
    return glib::make_refptr_for_instance<gdk::GLTexture> (
        dynamic_cast<gdk::GLTexture*> (
            glib::wrap_auto ((GObject*) (object), take_copy)));
  }

} // namespace glib

namespace gdk
{

  auto
  GLTexture_Class::init () -> const glib::Class&
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
  GLTexture_Class::wrap_new (GObject* object) -> glib::ObjectBase*
  {
    return new GLTexture ((GdkGLTexture*) object);
  }

  auto
  GLTexture::gobj_copy () -> GdkGLTexture*
  {
    reference ();
    return gobj ();
  }

  GLTexture::GLTexture (const glib::ConstructParams& construct_params)
    : gdk::Texture (construct_params)
  {
  }

  GLTexture::GLTexture (GdkGLTexture* castitem)
    : gdk::Texture ((GdkTexture*) (castitem))
  {
  }

  GLTexture::GLTexture (GLTexture&& src) noexcept
    : gdk::Texture (std::move (src))
  {
  }

  auto
  GLTexture::operator= (GLTexture&& src) noexcept -> GLTexture&
  {
    gdk::Texture::operator= (std::move (src));
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
    : glib::ObjectBase (nullptr),
      gdk::Texture (glib::ConstructParams (gltexture_class_.init ()))
  {
  }

  auto
  GLTexture::create (const glib::RefPtr<GLContext>& context,
                     guint id,
                     int width,
                     int height,
                     const SlotGLReleased& slot) -> glib::RefPtr<Texture>
  {
    auto slot_copy = new SlotGLReleased (slot);

    return glib::wrap (gdk_gl_texture_new (glib::unwrap (context),
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

} // namespace gdk
