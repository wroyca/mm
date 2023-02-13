
#ifndef _GIOMM_SOCKETCLIENT_P_H
#define _GIOMM_SOCKETCLIENT_P_H


#include <libmm-glib/object_p.hxx>

#include <libmm-glib/class.hxx>

namespace Gio
{

class GIOMM_API SocketClient_Class : public Glib::Class
{
public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  using CppObjectType = SocketClient;
  using BaseObjectType = GSocketClient;
  using BaseClassType = GSocketClientClass;
  using CppClassParent = Glib::Object_Class;
  using BaseClassParent = GObjectClass;

  friend class SocketClient;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

  auto init () -> const Class&;


  static auto class_init_function (void *g_class, void *class_data) -> void;

  static auto wrap_new (GObject *) -> Glib::ObjectBase*;

protected:

  //Callbacks (default signal handlers):
  //These will call the *_impl member methods, which will then call the existing default signal callbacks, if any.
  //You could prevent the original default signal handlers being called by overriding the *_impl method.
  static auto event_callback (
    GSocketClient *self, GSocketClientEvent p0, GSocketConnectable *p1, GIOStream *p2) -> void;

  //Callbacks (virtual functions):
};


} // namespace Gio


#endif /* _GIOMM_SOCKETCLIENT_P_H */

