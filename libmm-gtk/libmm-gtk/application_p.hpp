
#ifndef _GTKMM_APPLICATION_P_H
#define _GTKMM_APPLICATION_P_H


#include <libmm-gio/application_p.hpp>

#include <libmm-glib/class.hpp>

namespace Gtk
{

class GTKMM_API Application_Class : public Glib::Class
{
public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  using CppObjectType = Application;
  using BaseObjectType = GtkApplication;
  using BaseClassType = GtkApplicationClass;
  using CppClassParent = Gio::Application_Class;
  using BaseClassParent = GApplicationClass;

  friend class Application;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

  auto init () -> const Class&;


  static auto class_init_function (void *g_class, void *class_data) -> void;

  static auto wrap_new (GObject *) -> Glib::ObjectBase*;

protected:

  //Callbacks (default signal handlers):
  //These will call the *_impl member methods, which will then call the existing default signal callbacks, if any.
  //You could prevent the original default signal handlers being called by overriding the *_impl method.
  static auto window_added_callback (GtkApplication *self, GtkWindow *p0) -> void;
  static auto window_removed_callback (GtkApplication *self, GtkWindow *p0) -> void;

  //Callbacks (virtual functions):
};


} // namespace Gtk


#endif /* _GTKMM_APPLICATION_P_H */

