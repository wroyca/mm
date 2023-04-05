// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GIOMM_DBUSPROXY_P_H
#define _GIOMM_DBUSPROXY_P_H

#include <libmm/glib/object_p.hxx>

#include <libmm/glib/class.hxx>

namespace gio
{

  namespace DBus
  {

    class LIBMM_GIO_SYMEXPORT Proxy_Class : public glib::Class
    {
    public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
      using CppObjectType = Proxy;
      using BaseObjectType = GDBusProxy;
      using BaseClassType = GDBusProxyClass;
      using CppClassParent = glib::Object_Class;
      using BaseClassParent = GObjectClass;

      friend class Proxy;
#endif

      auto
      init () -> const Class&;

      static auto
      class_init_function (void* g_class, void* class_data) -> void;

      static auto
      wrap_new (GObject*) -> glib::ObjectBase*;

    protected:
      static auto
      g_properties_changed_callback (GDBusProxy* self,
                                     GVariant* p0,
                                     const gchar* const* p1) -> void;
      static auto
      g_signal_callback (GDBusProxy* self,
                         const gchar* p0,
                         const gchar* p1,
                         GVariant* p2) -> void;
    };

  } // namespace DBus

} // namespace gio

#endif
