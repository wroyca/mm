// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GIOMM_SOCKETCLIENT_P_H
#define _GIOMM_SOCKETCLIENT_P_H

#include <libmm/glib/object_p.hxx>

#include <libmm/glib/class.hxx>

namespace gio
{

  class LIBMM_GIO_SYMEXPORT SocketClient_Class : public glib::Class
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    using CppObjectType = SocketClient;
    using BaseObjectType = GSocketClient;
    using BaseClassType = GSocketClientClass;
    using CppClassParent = glib::Object_Class;
    using BaseClassParent = GObjectClass;

    friend class SocketClient;
#endif

    auto
    init () -> const Class&;

    static auto
    class_init_function (void* g_class, void* class_data) -> void;

    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;

  protected:
    static auto
    event_callback (GSocketClient* self,
                    GSocketClientEvent p0,
                    GSocketConnectable* p1,
                    GIOStream* p2) -> void;
  };

} // namespace gio

#endif
