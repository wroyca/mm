
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
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

  auto init () -> const Class&;


  static auto class_init_function (void *g_class, void *class_data) -> void;

  static auto wrap_new (GObject *) -> Glib::ObjectBase*;

protected:

  //Callbacks (default signal handlers):
  //These will call the *_impl member methods, which will then call the existing default signal callbacks, if any.
  //You could prevent the original default signal handlers being called by overriding the *_impl method.

  //Callbacks (virtual functions):
};


} // namespace Gdk


#endif /* _GDKMM_GLTEXTURE_P_H */

