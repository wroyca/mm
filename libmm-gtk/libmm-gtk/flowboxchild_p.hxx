
#ifndef _GTKMM_FLOWBOXCHILD_P_H
#define _GTKMM_FLOWBOXCHILD_P_H


#include <libmm-gtk/widget_p.hpp>

#include <libmm-glib/class.hpp>

namespace Gtk
{

class GTKMM_API FlowBoxChild_Class : public Glib::Class
{
public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  using CppObjectType = FlowBoxChild;
  using BaseObjectType = GtkFlowBoxChild;
  using BaseClassType = GtkFlowBoxChildClass;
  using CppClassParent = Widget_Class;
  using BaseClassParent = GtkWidgetClass;

  friend class FlowBoxChild;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

  auto init () -> const Class&;


  static auto class_init_function (void *g_class, void *class_data) -> void;

  static auto wrap_new (GObject *) -> Glib::ObjectBase*;

protected:

  //Callbacks (default signal handlers):
  //These will call the *_impl member methods, which will then call the existing default signal callbacks, if any.
  //You could prevent the original default signal handlers being called by overriding the *_impl method.
  static auto activate_callback (GtkFlowBoxChild *self) -> void;

  //Callbacks (virtual functions):
};


} // namespace Gtk


#endif /* _GTKMM_FLOWBOXCHILD_P_H */

