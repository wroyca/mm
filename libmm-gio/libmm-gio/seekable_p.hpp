
#ifndef _GIOMM_SEEKABLE_P_H
#define _GIOMM_SEEKABLE_P_H


#include <mm/glib/private/interface_p.hpp>

#include <mm/glib/private/interface_p.hpp>

namespace Gio
{

class GIOMM_API Seekable_Class : public Glib::Interface_Class
{
public:
  using CppObjectType = Seekable;
  using BaseObjectType = GSeekable;
  using BaseClassType = GSeekableIface;
  using CppClassParent = Interface_Class;

  friend class Seekable;

  auto init () -> const Interface_Class&;

  static auto iface_init_function (void *g_iface, void *iface_data) -> void;

  static auto wrap_new (GObject *) -> Glib::ObjectBase*;

protected:

  //Callbacks (default signal handlers):
  //These will call the *_impl member methods, which will then call the existing default signal callbacks, if any.
  //You could prevent the original default signal handlers being called by overriding the *_impl method.

  //Callbacks (virtual functions):
};


} // namespace Gio


#endif /* _GIOMM_SEEKABLE_P_H */

