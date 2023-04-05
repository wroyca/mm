// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GIOMM_DBUSINTERFACESKELETON_P_H
#define _GIOMM_DBUSINTERFACESKELETON_P_H

#include <gio/gio.h>
#include <libmm/glib/object_p.hxx>

#include <libmm/glib/class.hxx>

namespace gio
{

  namespace DBus
  {

    class LIBMM_GIO_SYMEXPORT InterfaceSkeleton_Class : public glib::Class
    {
    public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
      using CppObjectType = InterfaceSkeleton;
      using BaseObjectType = GDBusInterfaceSkeleton;
      using BaseClassType = GDBusInterfaceSkeletonClass;
      using CppClassParent = glib::Object_Class;
      using BaseClassParent = GObjectClass;

      friend class InterfaceSkeleton;
#endif

      auto
      init () -> const Class&;

      static auto
      class_init_function (void* g_class, void* class_data) -> void;

      static auto
      wrap_new (GObject*) -> glib::ObjectBase*;

    protected:
      static auto
      g_authorize_method_callback (GDBusInterfaceSkeleton* self,
                                   GDBusMethodInvocation* p0) -> gboolean;
    };

  } // namespace DBus

} // namespace gio

#endif
