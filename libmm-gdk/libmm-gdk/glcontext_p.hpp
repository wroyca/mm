
#ifndef _GDKMM_GLCONTEXT_P_H
#define _GDKMM_GLCONTEXT_P_H


#include <mm/gdk/private/drawcontext_p.hpp>

#include <mm/glib/class.hpp>

namespace Gdk
{

class GDKMM_API GLContext_Class : public Glib::Class
{
public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  using CppObjectType = GLContext;
  using BaseObjectType = GdkGLContext;
  using BaseClassType = GdkGLContextClass;
  using CppClassParent = DrawContext_Class;
  using BaseClassParent = GdkDrawContextClass;

  friend class GLContext;
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


#endif /* _GDKMM_GLCONTEXT_P_H */

