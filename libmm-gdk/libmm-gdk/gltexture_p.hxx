
#ifndef _GDKMM_GLTEXTURE_P_H
#define _GDKMM_GLTEXTURE_P_H

#include <libmm-gdk/texture_p.hxx>

#include <libmm-glib/class.hxx>

namespace Gdk
{

  class GDKMM_API GLTexture_Class : public Glib::Class
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    using CppObjectType = GLTexture;
    using BaseObjectType = GdkGLTexture;
    using BaseClassType = GdkGLTextureClass;
    using CppClassParent = Texture_Class;
    using BaseClassParent = GdkTextureClass;

    friend class GLTexture;
#endif

    auto
    init () -> const Class&;

    static auto
    class_init_function (void* g_class, void* class_data) -> void;

    static auto
    wrap_new (GObject*) -> Glib::ObjectBase*;

  protected:
  };

} // namespace Gdk

#endif
