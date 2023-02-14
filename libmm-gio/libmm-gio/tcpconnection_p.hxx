
#ifndef _GIOMM_TCPCONNECTION_P_H
#define _GIOMM_TCPCONNECTION_P_H

#include <libmm-gio/socketconnection_p.hxx>

#include <libmm-glib/class.hxx>

namespace Gio
{

  class GIOMM_API TcpConnection_Class : public Glib::Class
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    using CppObjectType = TcpConnection;
    using BaseObjectType = GTcpConnection;
    using BaseClassType = GTcpConnectionClass;
    using CppClassParent = SocketConnection_Class;
    using BaseClassParent = GSocketConnectionClass;

    friend class TcpConnection;
#endif

    auto
    init () -> const Class&;

    static auto
    class_init_function (void* g_class, void* class_data) -> void;

    static auto
    wrap_new (GObject*) -> Glib::ObjectBase*;

  protected:
  };

} // namespace Gio

#endif
