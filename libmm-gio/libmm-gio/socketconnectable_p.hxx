// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GIOMM_SOCKETCONNECTABLE_P_H
#define _GIOMM_SOCKETCONNECTABLE_P_H

#include <libmm-glib/interface_p.hxx>

#include <libmm-glib/interface_p.hxx>

namespace Gio
{

  class LIBMM_GIO_SYMEXPORT SocketConnectable_Class : public Glib::Interface_Class
  {
  public:
    using CppObjectType = SocketConnectable;
    using BaseObjectType = GSocketConnectable;
    using BaseClassType = GSocketConnectableIface;
    using CppClassParent = Interface_Class;

    friend class SocketConnectable;

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
