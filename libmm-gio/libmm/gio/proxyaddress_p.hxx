// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GIOMM_PROXYADDRESS_P_H
#define _GIOMM_PROXYADDRESS_P_H

#include <libmm/gio/inetsocketaddress_p.hxx>

#include <libmm/glib/class.hxx>

namespace Gio
{

  class LIBMM_GIO_SYMEXPORT ProxyAddress_Class : public Glib::Class
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    using CppObjectType = ProxyAddress;
    using BaseObjectType = GProxyAddress;
    using BaseClassType = GProxyAddressClass;
    using CppClassParent = InetSocketAddress_Class;
    using BaseClassParent = GInetSocketAddressClass;

    friend class ProxyAddress;
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
