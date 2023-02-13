
#ifndef _GDKMM_DRAGSURFACE_P_H
#define _GDKMM_DRAGSURFACE_P_H


#include <mm/glib/private/interface_p.hpp>
#include <gdk/gdk.h>

#include <mm/glib/private/interface_p.hpp>

namespace Gdk
{

class GDKMM_API DragSurface_Class : public Glib::Interface_Class
{
public:
  using CppObjectType = DragSurface;
  using BaseObjectType = GdkDragSurface;
  using BaseClassType = GdkDragSurfaceInterface;
  using CppClassParent = Interface_Class;

  friend class DragSurface;

  auto init () -> const Interface_Class&;

  static auto iface_init_function (void *g_iface, void *iface_data) -> void;

  static auto wrap_new (GObject *) -> Glib::ObjectBase*;

protected:

  //Callbacks (default signal handlers):
  //These will call the *_impl member methods, which will then call the existing default signal callbacks, if any.
  //You could prevent the original default signal handlers being called by overriding the *_impl method.

  //Callbacks (virtual functions):
};


} // namespace Gdk


#endif /* _GDKMM_DRAGSURFACE_P_H */

