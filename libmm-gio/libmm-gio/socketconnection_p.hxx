
#ifndef _GIOMM_SOCKETCONNECTION_P_H
#define _GIOMM_SOCKETCONNECTION_P_H

#include <libmm-gio/iostream_p.hxx>

#include <libmm-glib/class.hxx>

namespace Gio
{

  class GIOMM_API SocketConnection_Class : public Glib::Class
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    using CppObjectType = SocketConnection;
    using BaseObjectType = GSocketConnection;
    using BaseClassType = GSocketConnectionClass;
    using CppClassParent = IOStream_Class;
    using BaseClassParent = GIOStreamClass;

    friend class SocketConnection;
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
