
#ifndef _GTKMM_WINDOW_P_H
#define _GTKMM_WINDOW_P_H


#include <libmm-gtk/widget_p.hxx>

#include <libmm-glib/class.hxx>

namespace Gtk
{

class GTKMM_API Window_Class : public Glib::Class
{
public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  using CppObjectType = Window;
  using BaseObjectType = GtkWindow;
  using BaseClassType = GtkWindowClass;
  using CppClassParent = Widget_Class;
  using BaseClassParent = GtkWidgetClass;

  friend class Window;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

  auto init () -> const Class&;


  static auto class_init_function (void *g_class, void *class_data) -> void;

  static auto wrap_new (GObject *) -> Glib::ObjectBase*;

protected:

  //Callbacks (default signal handlers):
  //These will call the *_impl member methods, which will then call the existing default signal callbacks, if any.
  //You could prevent the original default signal handlers being called by overriding the *_impl method.
  static auto keys_changed_callback (GtkWindow *self) -> void;
  static auto close_request_callback (GtkWindow *self) -> gboolean;

  //Callbacks (virtual functions):
    static auto dispose_vfunc_callback (GObject *self) -> void;
  };


} // namespace Gtk


#endif /* _GTKMM_WINDOW_P_H */

