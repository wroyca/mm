// Generated by gmmproc 2.74.0 -- DO NOT MODIFY!
#ifndef _GTKMM_CELLRENDERERPROGRESS_P_H
#define _GTKMM_CELLRENDERERPROGRESS_P_H


#include <mm/gtk/private/cellrenderer_p.hpp>

#include <mm/glib/class.hpp>

namespace Gtk
{

class GTKMM_API CellRendererProgress_Class : public Glib::Class
{
public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  using CppObjectType = CellRendererProgress;
  using BaseObjectType = GtkCellRendererProgress;
  using BaseClassType = GtkCellRendererProgressClass;
  using CppClassParent = Gtk::CellRenderer_Class;
  using BaseClassParent = GtkCellRendererClass;

  friend class CellRendererProgress;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

  const Glib::Class& init();


  static void class_init_function(void* g_class, void* class_data);

  static Glib::ObjectBase* wrap_new(GObject*);

protected:

  //Callbacks (default signal handlers):
  //These will call the *_impl member methods, which will then call the existing default signal callbacks, if any.
  //You could prevent the original default signal handlers being called by overriding the *_impl method.

  //Callbacks (virtual functions):
};


} // namespace Gtk


#endif /* _GTKMM_CELLRENDERERPROGRESS_P_H */
