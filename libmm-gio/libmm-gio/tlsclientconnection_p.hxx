
#ifndef _GIOMM_TLSCLIENTCONNECTION_P_H
#define _GIOMM_TLSCLIENTCONNECTION_P_H

#include <gio/gio.h>
#include <libmm-glib/interface_p.hxx>

#include <libmm-glib/interface_p.hxx>

namespace Gio
{

  class GIOMM_API TlsClientConnection_Class : public Glib::Interface_Class
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
    wrap_new (GObject*) -> Glib::ObjectBase*;

  protected:
  };

} // namespace Gio

#endif
