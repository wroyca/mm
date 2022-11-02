// Generated by gmmproc 2.74.0 -- DO NOT MODIFY!
#ifndef _GTKMM_TREEDRAGDEST_P_H
#define _GTKMM_TREEDRAGDEST_P_H


#include <mm/glib/private/interface_p.hpp>

#include <mm/glib/private/interface_p.hpp>

namespace Gtk
{

class GTKMM_API TreeDragDest_Class : public Glib::Interface_Class
{
public:
  using CppObjectType = TreeDragDest;
  using BaseObjectType = GtkTreeDragDest;
  using BaseClassType = GtkTreeDragDestIface;
  using CppClassParent = Glib::Interface_Class;

  friend class TreeDragDest;

  const Glib::Interface_Class& init();

  static void iface_init_function(void* g_iface, void* iface_data);

  static Glib::ObjectBase* wrap_new(GObject*);

protected:

  //Callbacks (default signal handlers):
  //These will call the *_impl member methods, which will then call the existing default signal callbacks, if any.
  //You could prevent the original default signal handlers being called by overriding the *_impl method.

  //Callbacks (virtual functions):
  static gboolean drag_data_received_vfunc_callback(GtkTreeDragDest* self, GtkTreePath* dest, const GValue* value);
  static gboolean row_drop_possible_vfunc_callback(GtkTreeDragDest* self, GtkTreePath* dest_path, const GValue* value);
};


} // namespace Gtk


#endif /* _GTKMM_TREEDRAGDEST_P_H */
