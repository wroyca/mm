// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GIOMM_DBUSCONNECTION_P_H
#define _GIOMM_DBUSCONNECTION_P_H

#include <libmm/glib/object_p.hxx>

#include <libmm/glib/class.hxx>

namespace gio
{

  namespace DBus
  {

    class LIBMM_GIO_SYMEXPORT Connection_Class : public glib::Class
    {
    public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
      using CppObjectType = Connection;
      using BaseObjectType = GDBusConnection;
      using BaseClassType = GDBusConnectionClass;
      using CppClassParent = glib::Object_Class;
      using BaseClassParent = GObjectClass;

      friend class Connection;
#endif

      auto
      init () -> const Class&;

      static auto
      class_init_function (void* g_class, void* class_data) -> void;

      static auto
      wrap_new (GObject*) -> glib::ObjectBase*;

    protected:
    };

  } // namespace DBus

} // namespace gio

#endif
