
#ifndef _GDKMM_MEMORYTEXTURE_P_H
#define _GDKMM_MEMORYTEXTURE_P_H


#include <libmm-gdk/texture_p.hxx>

#include <libmm-glib/class.hxx>

namespace Gdk
{

class GDKMM_API MemoryTexture_Class : public Glib::Class
{
public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  using CppObjectType = MemoryTexture;
  using BaseObjectType = GdkMemoryTexture;
  using BaseClassType = GdkMemoryTextureClass;
  using CppClassParent = Texture_Class;
  using BaseClassParent = GdkTextureClass;

  friend class MemoryTexture;
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


#endif /* _GDKMM_MEMORYTEXTURE_P_H */

