// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GIOMM_DBUSOBJECTPROXY_P_H
#define _GIOMM_DBUSOBJECTPROXY_P_H

#include <libmm-glib/object_p.hxx>

#include <libmm-glib/class.hxx>

namespace Gio
{

  namespace DBus
  {

    class LIBMM_GIO_SYMEXPORT ObjectProxy_Class : public Glib::Class
    {
    public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
      using CppObjectType = ObjectProxy;
      using BaseObjectType = GDBusObjectProxy;
      using BaseClassType = GDBusObjectProxyClass;
      using CppClassParent = Glib::Object_Class;
      using BaseClassParent = GObjectClass;

      friend class ObjectProxy;
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
