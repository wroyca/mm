
#ifndef _GIOMM_SOCKETSERVICE_P_H
#define _GIOMM_SOCKETSERVICE_P_H


#include <libmm-gio/socketlistener_p.hxx>

#include <libmm-glib/class.hxx>

namespace Gio
{

class GIOMM_API SocketService_Class : public Glib::Class
{
public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  using CppObjectType = SocketService;
  using BaseObjectType = GSocketService;
  using BaseClassType = GSocketServiceClass;
  using CppClassParent = SocketListener_Class;
  using BaseClassParent = GSocketListenerClass;

  friend class SocketService;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

  auto init () -> const Class&;


  static auto class_init_function (void *g_class, void *class_data) -> void;

  static auto wrap_new (GObject *) -> Glib::ObjectBase*;

protected:

  //Callbacks (default signal handlers):
  //These will call the *_impl member methods, which will then call the existing default signal callbacks, if any.
  //You could prevent the original default signal handlers being called by overriding the *_impl method.
  static auto incoming_callback (
    GSocketService *self, GSocketConnection *p0, GObject *p1) -> gboolean;

  //Callbacks (virtual functions):
};


} // namespace Gio


#endif /* _GIOMM_SOCKETSERVICE_P_H */

