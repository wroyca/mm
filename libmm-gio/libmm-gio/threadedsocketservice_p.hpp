
#ifndef _GIOMM_THREADEDSOCKETSERVICE_P_H
#define _GIOMM_THREADEDSOCKETSERVICE_P_H


#include <mm/gio/private/socketservice_p.hpp>

#include <mm/glib/class.hpp>

namespace Gio
{

class GIOMM_API ThreadedSocketService_Class : public Glib::Class
{
public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  using CppObjectType = ThreadedSocketService;
  using BaseObjectType = GThreadedSocketService;
  using BaseClassType = GThreadedSocketServiceClass;
  using CppClassParent = SocketService_Class;
  using BaseClassParent = GSocketServiceClass;

  friend class ThreadedSocketService;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

  auto init () -> const Class&;


  static auto class_init_function (void *g_class, void *class_data) -> void;

  static auto wrap_new (GObject *) -> Glib::ObjectBase*;

protected:

  //Callbacks (default signal handlers):
  //These will call the *_impl member methods, which will then call the existing default signal callbacks, if any.
  //You could prevent the original default signal handlers being called by overriding the *_impl method.
  static auto run_callback (
    GThreadedSocketService *self, GSocketConnection *p0, GObject *p1) -> gboolean;

  //Callbacks (virtual functions):
};


} // namespace Gio


#endif /* _GIOMM_THREADEDSOCKETSERVICE_P_H */

