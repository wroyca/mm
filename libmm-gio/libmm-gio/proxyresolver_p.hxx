// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GIOMM_PROXYRESOLVER_P_H
#define _GIOMM_PROXYRESOLVER_P_H

#include <libmm-glib/interface_p.hxx>

#include <libmm-glib/interface_p.hxx>

namespace Gio
{

  class GIOMM_API ProxyResolver_Class : public Glib::Interface_Class
  {
  public:
    using CppObjectType = ProxyResolver;
    using BaseObjectType = GProxyResolver;
    using BaseClassType = GProxyResolverInterface;
    using CppClassParent = Interface_Class;

    friend class ProxyResolver;

    auto
    init () -> const Interface_Class&;

    static auto
    iface_init_function (void* g_iface, void* iface_data) -> void;

    static auto
    wrap_new (GObject*) -> Glib::ObjectBase*;

  protected:
  };

} // namespace Gio

#endif
