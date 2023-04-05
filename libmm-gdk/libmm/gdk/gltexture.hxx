// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GDKMM_GLTEXTURE_H
#define _GDKMM_GLTEXTURE_H

#include <libmm/glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm/gdk/texture.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GdkGLTexture = struct _GdkGLTexture;
using GdkGLTextureClass = struct _GdkGLTextureClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace gdk
{
  class LIBMM_GDK_SYMEXPORT GLTexture_Class;
}
#endif

namespace gdk
{
  class LIBMM_GDK_SYMEXPORT GLContext;

  class LIBMM_GDK_SYMEXPORT GLTexture : public gdk::Texture
  {
#ifndef DOXYGEN_SHOULD_SKIP_THIS

  public:
    using CppObjectType = GLTexture;
    using CppClassType = GLTexture_Class;
    using BaseObjectType = GdkGLTexture;
    using BaseClassType = GdkGLTextureClass;

    GLTexture (const GLTexture&) = delete;
    auto
    operator= (const GLTexture&) -> GLTexture& = delete;

  private:
    friend class GLTexture_Class;
    static CppClassType gltexture_class_;

  protected:
    explicit GLTexture (const glib::ConstructParams& construct_params);
    explicit GLTexture (GdkGLTexture* castitem);

#endif

  public:
    GLTexture (GLTexture&& src) noexcept;
    auto
    operator= (GLTexture&& src) noexcept -> GLTexture&;

    ~GLTexture () noexcept override;

    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GdkGLTexture*
    {
      return reinterpret_cast<GdkGLTexture*> (gobject_);
    }

    auto
    gobj () const -> const GdkGLTexture*
    {
      return reinterpret_cast<GdkGLTexture*> (gobject_);
    }

    auto
    gobj_copy () -> GdkGLTexture*;

  private:
  protected:
    GLTexture ();

  public:
    using SlotGLReleased = sigc::slot<void ()>;

    static auto
    create (const glib::RefPtr<GLContext>& context,
            guint id,
            int width,
            int height,
            const SlotGLReleased& slot = {}) -> glib::RefPtr<Texture>;

    auto
    release () -> void;

  public:
  public:
  protected:
  };

} // namespace gdk

namespace glib
{
  LIBMM_GDK_SYMEXPORT auto
  wrap (GdkGLTexture* object, bool take_copy = false) -> glib::RefPtr<gdk::GLTexture>;
} // namespace glib

#endif
