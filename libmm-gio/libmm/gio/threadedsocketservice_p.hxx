// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GIOMM_THREADEDSOCKETSERVICE_P_H
#define _GIOMM_THREADEDSOCKETSERVICE_P_H

#include <libmm/gio/socketservice_p.hxx>

#include <libmm/glib/class.hxx>

namespace gio
{

  class LIBMM_GIO_SYMEXPORT ThreadedSocketService_Class : public glib::Class
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    using CppObjectType = ThreadedSocketService;
    using BaseObjectType = GThreadedSocketService;
    using BaseClassType = GThreadedSocketServiceClass;
    using CppClassParent = SocketService_Class;
    using BaseClassParent = GSocketServiceClass;

    friend class ThreadedSocketService;
#endif

    auto
    init () -> const Class&;

    static auto
    class_init_function (void* g_class, void* class_data) -> void;

    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;

  protected:
    static auto
    run_callback (GThreadedSocketService* self,
                  GSocketConnection* p0,
                  GObject* p1) -> gboolean;
  };

} // namespace gio

#endif
