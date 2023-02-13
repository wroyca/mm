
#ifndef _GTKMM_LAYOUTMANAGER_P_H
#define _GTKMM_LAYOUTMANAGER_P_H


#include <mm/glib/private/object_p.hpp>

#include <mm/glib/class.hpp>

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

  auto init () -> const Class&;


  static auto class_init_function (void *g_class, void *class_data) -> void;

  static auto wrap_new (GObject *) -> Glib::ObjectBase*;

protected:

  //Callbacks (default signal handlers):
  //These will call the *_impl member methods, which will then call the existing default signal callbacks, if any.
  //You could prevent the original default signal handlers being called by overriding the *_impl method.

  //Callbacks (virtual functions):
  static auto get_request_mode_vfunc_callback (
    GtkLayoutManager *self, GtkWidget *widget) -> GtkSizeRequestMode;
  static auto measure_vfunc_callback (
    GtkLayoutManager *self, GtkWidget *widget, GtkOrientation orientation, int for_size,
    int *minimum, int *natural, int *minimum_baseline, int *natural_baseline) -> void;
  static auto allocate_vfunc_callback (
    GtkLayoutManager *self, GtkWidget *widget, int width, int height, int baseline) -> void;
  static auto create_layout_child_vfunc_callback (
    GtkLayoutManager *self, GtkWidget *widget, GtkWidget *for_child) -> GtkLayoutChild*;
  static auto root_vfunc_callback (GtkLayoutManager *self) -> void;
  static auto unroot_vfunc_callback (GtkLayoutManager *self) -> void;
};


} // namespace Gtk


#endif /* _GTKMM_LAYOUTMANAGER_P_H */

