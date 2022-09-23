// Generated by gmmproc 2.74.0 -- DO NOT MODIFY!
#ifndef _GTKMM_LAYOUTMANAGER_P_H
#define _GTKMM_LAYOUTMANAGER_P_H


#include <glibmm/private/object_p.h>

#include <glibmm/class.h>

namespace Gtk
{

class GTKMM_API LayoutManager_Class : public Glib::Class
{
public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  using CppObjectType = LayoutManager;
  using BaseObjectType = GtkLayoutManager;
  using BaseClassType = GtkLayoutManagerClass;
  using CppClassParent = Glib::Object_Class;
  using BaseClassParent = GObjectClass;

  friend class LayoutManager;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

  const Glib::Class& init();


  static void class_init_function(void* g_class, void* class_data);

  static Glib::ObjectBase* wrap_new(GObject*);

protected:

  //Callbacks (default signal handlers):
  //These will call the *_impl member methods, which will then call the existing default signal callbacks, if any.
  //You could prevent the original default signal handlers being called by overriding the *_impl method.

  //Callbacks (virtual functions):
  static GtkSizeRequestMode get_request_mode_vfunc_callback(GtkLayoutManager* self, GtkWidget* widget);
  static void measure_vfunc_callback(GtkLayoutManager* self, GtkWidget* widget, GtkOrientation orientation, int for_size, int* minimum, int* natural, int* minimum_baseline, int* natural_baseline);
  static void allocate_vfunc_callback(GtkLayoutManager* self, GtkWidget* widget, int width, int height, int baseline);
  static GtkLayoutChild* create_layout_child_vfunc_callback(GtkLayoutManager* self, GtkWidget* widget, GtkWidget* for_child);
  static void root_vfunc_callback(GtkLayoutManager* self);
  static void unroot_vfunc_callback(GtkLayoutManager* self);
};


} // namespace Gtk


#endif /* _GTKMM_LAYOUTMANAGER_P_H */

