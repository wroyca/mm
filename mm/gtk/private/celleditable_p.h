// Generated by gmmproc 2.74.0 -- DO NOT MODIFY!
#ifndef _GTKMM_CELLEDITABLE_P_H
#define _GTKMM_CELLEDITABLE_P_H


#include <mm/glib/private/interface_p.h>

#include <mm/glib/private/interface_p.h>

namespace Gtk
{

class GTKMM_API CellEditable_Class : public Glib::Interface_Class
{
public:
  using CppObjectType = CellEditable;
  using BaseObjectType = GtkCellEditable;
  using BaseClassType = GtkCellEditableIface;
  using CppClassParent = Glib::Interface_Class;

  friend class CellEditable;

  const Glib::Interface_Class& init();

  static void iface_init_function(void* g_iface, void* iface_data);

  static Glib::ObjectBase* wrap_new(GObject*);

protected:

  //Callbacks (default signal handlers):
  //These will call the *_impl member methods, which will then call the existing default signal callbacks, if any.
  //You could prevent the original default signal handlers being called by overriding the *_impl method.
  static void editing_done_callback(GtkCellEditable* self);
  static void remove_widget_callback(GtkCellEditable* self);

  //Callbacks (virtual functions):
  static void start_editing_vfunc_callback(GtkCellEditable* self, GdkEvent* event);
};


} // namespace Gtk


#endif /* _GTKMM_CELLEDITABLE_P_H */
