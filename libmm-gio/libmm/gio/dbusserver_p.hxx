// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GIOMM_DBUSSERVER_P_H
#define _GIOMM_DBUSSERVER_P_H

#include <libmm/glib/object_p.hxx>

#include <libmm/glib/class.hxx>

namespace Gio
{

  namespace DBus
  {

    class LIBMM_GIO_SYMEXPORT Server_Class : public Glib::Class
    {
    public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
      using CppObjectType = Server;
      using BaseObjectType = GDBusServer;
      using BaseClassType = GDBusServerClass;
      using CppClassParent = Glib::Object_Class;
      using BaseClassParent = GObjectClass;

      friend class Server;
#endif

      auto
      init () -> const Class&;

      static auto
      class_init_function (void* g_class, void* class_data) -> void;

      static auto
      wrap_new (GObject*) -> Glib::ObjectBase*;

    protected:
    };

  } // namespace DBus

} // namespace Gio

#endif
