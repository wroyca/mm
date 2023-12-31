// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GIOMM_DBUSOBJECTMANAGERCLIENT_P_H
#define _GIOMM_DBUSOBJECTMANAGERCLIENT_P_H

#include <libmm/glib/object_p.hxx>

#include <libmm/glib/class.hxx>

namespace gio
{

  namespace DBus
  {

    class LIBMM_GIO_SYMEXPORT ObjectManagerClient_Class : public glib::Class
    {
    public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
      using CppObjectType = ObjectManagerClient;
      using BaseObjectType = GDBusObjectManagerClient;
      using BaseClassType = GDBusObjectManagerClientClass;
      using CppClassParent = glib::Object_Class;
      using BaseClassParent = GObjectClass;

      friend class ObjectManagerClient;
#endif

      auto
      init () -> const Class&;

      static auto
      class_init_function (void* g_class, void* class_data) -> void;

      static auto
      wrap_new (GObject*) -> glib::ObjectBase*;

    protected:
      static auto
      interface_proxy_signal_callback (GDBusObjectManagerClient* self,
                                       GDBusObjectProxy* p0,
                                       GDBusProxy* p1,
                                       const gchar* p2,
                                       const gchar* p3,
                                       GVariant* p4) -> void;
      static auto
      interface_proxy_properties_changed_callback (
          GDBusObjectManagerClient* self,
          GDBusObjectProxy* p0,
          GDBusProxy* p1,
          GVariant* p2,
          const gchar* const* p3) -> void;
    };

  } // namespace DBus

} // namespace gio

#endif
