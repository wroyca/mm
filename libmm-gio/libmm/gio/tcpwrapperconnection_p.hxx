// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GIOMM_TCPWRAPPERCONNECTION_P_H
#define _GIOMM_TCPWRAPPERCONNECTION_P_H

#include <libmm/gio/tcpconnection_p.hxx>

#include <libmm/glib/class.hxx>

namespace gio
{

  class LIBMM_GIO_SYMEXPORT TcpWrapperConnection_Class : public glib::Class
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    using CppObjectType = TcpWrapperConnection;
    using BaseObjectType = GTcpWrapperConnection;
    using BaseClassType = GTcpWrapperConnectionClass;
    using CppClassParent = TcpConnection_Class;
    using BaseClassParent = GTcpConnectionClass;

    friend class TcpWrapperConnection;
#endif

    auto
    init () -> const Class&;

    static auto
    class_init_function (void* g_class, void* class_data) -> void;

    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;

  protected:
  };

} // namespace gio

#endif
