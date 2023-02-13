
#ifndef _GIOMM_UNIXCONNECTION_P_H
#define _GIOMM_UNIXCONNECTION_P_H


#include <libmm-gio/socketconnection_p.hxx>

#include <libmm-glib/class.hxx>

namespace Gio
{

class GIOMM_API UnixConnection_Class : public Glib::Class
{
public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  using CppObjectType = UnixConnection;
  using BaseObjectType = GUnixConnection;
  using BaseClassType = GUnixConnectionClass;
  using CppClassParent = SocketConnection_Class;
  using BaseClassParent = GSocketConnectionClass;

  friend class UnixConnection;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

  auto init () -> const Class&;


  static auto class_init_function (void *g_class, void *class_data) -> void;

  static auto wrap_new (GObject *) -> Glib::ObjectBase*;

protected:

  //Callbacks (default signal handlers):
  //These will call the *_impl member methods, which will then call the existing default signal callbacks, if any.
  //You could prevent the original default signal handlers being called by overriding the *_impl method.

  //Callbacks (virtual functions):
};


} // namespace Gio


#endif /* _GIOMM_UNIXCONNECTION_P_H */

