
#ifndef _GTKMM_GLAREA_P_H
#define _GTKMM_GLAREA_P_H


#include <libmm-gtk/widget_p.hxx>

#include <libmm-glib/class.hxx>

namespace Gtk
{

class GTKMM_API GLArea_Class : public Glib::Class
{
public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  using CppObjectType = GLArea;
  using BaseObjectType = GtkGLArea;
  using BaseClassType = GtkGLAreaClass;
  using CppClassParent = Widget_Class;
  using BaseClassParent = GtkWidgetClass;

  friend class GLArea;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

  auto init () -> const Class&;


  static auto class_init_function (void *g_class, void *class_data) -> void;

  static auto wrap_new (GObject *) -> Glib::ObjectBase*;

protected:

  //Callbacks (default signal handlers):
  //These will call the *_impl member methods, which will then call the existing default signal callbacks, if any.
  //You could prevent the original default signal handlers being called by overriding the *_impl method.
  static auto create_context_callback (GtkGLArea *self) -> GdkGLContext*;
  static auto render_callback (GtkGLArea *self, GdkGLContext *p0) -> gboolean;
  static auto resize_callback (GtkGLArea *self, gint p0, gint p1) -> void;

  //Callbacks (virtual functions):
};


} // namespace Gtk


#endif /* _GTKMM_GLAREA_P_H */

