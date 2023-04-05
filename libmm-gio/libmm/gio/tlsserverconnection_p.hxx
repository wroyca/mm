// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GIOMM_TLSSERVERCONNECTION_P_H
#define _GIOMM_TLSSERVERCONNECTION_P_H

#include <gio/gio.h>
#include <libmm/glib/interface_p.hxx>

#include <libmm/glib/interface_p.hxx>

namespace gio
{

  class LIBMM_GIO_SYMEXPORT TlsServerConnection_Class : public glib::Interface_Class
  {
  public:
    using CppObjectType = TlsServerConnection;
    using BaseObjectType = GTlsServerConnection;
    using BaseClassType = GTlsServerConnectionInterface;
    using CppClassParent = Interface_Class;

    friend class TlsServerConnection;

    auto
    init () -> const Interface_Class&;

    static auto
    iface_init_function (void* g_iface, void* iface_data) -> void;

    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;

  protected:
  };

} // namespace gio

#endif
