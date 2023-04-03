// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GIOMM_INETSOCKETADDRESS_P_H
#define _GIOMM_INETSOCKETADDRESS_P_H

#include <libmm/gio/socketaddress_p.hxx>

#include <libmm/glib/class.hxx>

namespace Gio
{

  class LIBMM_GIO_SYMEXPORT InetSocketAddress_Class : public Glib::Class
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    using CppObjectType = InetSocketAddress;
    using BaseObjectType = GInetSocketAddress;
    using BaseClassType = GInetSocketAddressClass;
    using CppClassParent = SocketAddress_Class;
    using BaseClassParent = GSocketAddressClass;

    friend class InetSocketAddress;
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
