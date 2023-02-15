// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GIOMM_NETWORKMONITOR_P_H
#define _GIOMM_NETWORKMONITOR_P_H

#include <gio/gio.h>
#include <libmm-glib/interface_p.hxx>

#include <libmm-glib/interface_p.hxx>

namespace Gio
{

  class LIBMM_GIO_SYMEXPORT NetworkMonitor_Class : public Glib::Interface_Class
  {
  public:
    using CppObjectType = NetworkMonitor;
    using BaseObjectType = GNetworkMonitor;
    using BaseClassType = GNetworkMonitorInterface;
    using CppClassParent = Interface_Class;

    friend class NetworkMonitor;

    auto
    init () -> const Interface_Class&;

    static auto
    iface_init_function (void* g_iface, void* iface_data) -> void;

    static auto
    wrap_new (GObject*) -> Glib::ObjectBase*;

  protected:
    static auto
    network_changed_callback (GNetworkMonitor* self, gboolean p0) -> void;
  };

} // namespace Gio

#endif
