// Generated by gmmproc 2.74.0 -- DO NOT MODIFY!
#ifndef _GTKMM_SCROLLABLE_P_H
#define _GTKMM_SCROLLABLE_P_H


#include <glibmm/private/interface_p.h>

#include <glibmm/private/interface_p.h>

namespace Gtk
{

class GTKMM_API Scrollable_Class : public Glib::Interface_Class
{
public:
  using CppObjectType = Scrollable;
  using BaseObjectType = GtkScrollable;
  using BaseClassType = GtkScrollableInterface;
  using CppClassParent = Glib::Interface_Class;

  friend class Scrollable;

  const Glib::Interface_Class& init();

  static void iface_init_function(void* g_iface, void* iface_data);

  static Glib::ObjectBase* wrap_new(GObject*);

protected:

  //Callbacks (default signal handlers):
  //These will call the *_impl member methods, which will then call the existing default signal callbacks, if any.
  //You could prevent the original default signal handlers being called by overriding the *_impl method.

  //Callbacks (virtual functions):
  static gboolean get_border_vfunc_callback(GtkScrollable* self, GtkBorder* border);
};


} // namespace Gtk


#endif /* _GTKMM_SCROLLABLE_P_H */

