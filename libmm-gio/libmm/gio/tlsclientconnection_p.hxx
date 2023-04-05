// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GIOMM_TLSCLIENTCONNECTION_P_H
#define _GIOMM_TLSCLIENTCONNECTION_P_H

#include <gio/gio.h>
#include <libmm/glib/interface_p.hxx>

#include <libmm/glib/interface_p.hxx>

namespace gio
{

  class LIBMM_GIO_SYMEXPORT TlsClientConnection_Class : public glib::Interface_Class
  {
  public:
    using CppObjectType = TlsClientConnection;
    using BaseObjectType = GTlsClientConnection;
    using BaseClassType = GTlsClientConnectionInterface;
    using CppClassParent = Interface_Class;

    friend class TlsClientConnection;

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
