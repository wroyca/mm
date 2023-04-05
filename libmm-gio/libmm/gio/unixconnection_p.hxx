// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GIOMM_UNIXCONNECTION_P_H
#define _GIOMM_UNIXCONNECTION_P_H

#include <libmm/gio/socketconnection_p.hxx>

#include <libmm/glib/class.hxx>

namespace gio
{

  class LIBMM_GIO_SYMEXPORT UnixConnection_Class : public glib::Class
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    using CppObjectType = UnixConnection;
    using BaseObjectType = GUnixConnection;
    using BaseClassType = GUnixConnectionClass;
    using CppClassParent = SocketConnection_Class;
    using BaseClassParent = GSocketConnectionClass;

    friend class UnixConnection;
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
