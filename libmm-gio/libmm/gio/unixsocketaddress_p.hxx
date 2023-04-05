// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GIOMM_UNIXSOCKETADDRESS_P_H
#define _GIOMM_UNIXSOCKETADDRESS_P_H

#include <libmm/gio/socketaddress_p.hxx>

#include <libmm/glib/class.hxx>

namespace gio
{

  class LIBMM_GIO_SYMEXPORT UnixSocketAddress_Class : public glib::Class
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    using CppObjectType = UnixSocketAddress;
    using BaseObjectType = GUnixSocketAddress;
    using BaseClassType = GUnixSocketAddressClass;
    using CppClassParent = SocketAddress_Class;
    using BaseClassParent = GSocketAddressClass;

    friend class UnixSocketAddress;
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
