// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GIOMM_SOCKETSERVICE_P_H
#define _GIOMM_SOCKETSERVICE_P_H

#include <libmm/gio/socketlistener_p.hxx>

#include <libmm/glib/class.hxx>

namespace gio
{

  class LIBMM_GIO_SYMEXPORT SocketService_Class : public glib::Class
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    using CppObjectType = SocketService;
    using BaseObjectType = GSocketService;
    using BaseClassType = GSocketServiceClass;
    using CppClassParent = SocketListener_Class;
    using BaseClassParent = GSocketListenerClass;

    friend class SocketService;
#endif

    auto
    init () -> const Class&;

    static auto
    class_init_function (void* g_class, void* class_data) -> void;

    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;

  protected:
    static auto
    incoming_callback (GSocketService* self, GSocketConnection* p0, GObject* p1)
        -> gboolean;
  };

} // namespace gio

#endif
