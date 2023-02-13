
#ifndef _GTKMM_SCROLLABLE_P_H
#define _GTKMM_SCROLLABLE_P_H


#include <mm/glib/private/interface_p.hpp>

#include <mm/glib/private/interface_p.hpp>

namespace Gtk
{

class GTKMM_API Scrollable_Class : public Glib::Interface_Class
{
public:
  using CppObjectType = Scrollable;
  using BaseObjectType = GtkScrollable;
  using BaseClassType = GtkScrollableInterface;
  using CppClassParent = Interface_Class;

  friend class Scrollable;

  auto init () -> const Interface_Class&;

  static auto iface_init_function (void *g_iface, void *iface_data) -> void;

  static auto wrap_new (GObject *) -> Glib::ObjectBase*;

protected:

  //Callbacks (default signal handlers):
  //These will call the *_impl member methods, which will then call the existing default signal callbacks, if any.
  //You could prevent the original default signal handlers being called by overriding the *_impl method.

  //Callbacks (virtual functions):
  static auto get_border_vfunc_callback (GtkScrollable *self, GtkBorder *border) -> gboolean;
};


} // namespace Gtk


#endif /* _GTKMM_SCROLLABLE_P_H */

