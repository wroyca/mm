// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GDKMM_GLTEXTURE_H
#define _GDKMM_GLTEXTURE_H

#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm-gdk/texture.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GdkGLTexture = struct _GdkGLTexture;
using GdkGLTextureClass = struct _GdkGLTextureClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gdk
{
  class GDKMM_API GLTexture_Class;
}
#endif

namespace Gdk
{
  class GDKMM_API GLContext;

  class GDKMM_API GLTexture : public Gdk::Texture
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
    explicit GLTexture (const Glib::ConstructParams& construct_params);
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
    create (const Glib::RefPtr<GLContext>& context,
            guint id,
            int width,
            int height,
            const SlotGLReleased& slot = {}) -> Glib::RefPtr<Texture>;

    auto
    release () -> void;

  public:
  public:
  protected:
  };

} // namespace Gdk

namespace Glib
{
  GDKMM_API auto
  wrap (GdkGLTexture* object, bool take_copy = false) -> Glib::RefPtr<Gdk::GLTexture>;
} // namespace Glib

#endif
