// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GIOMM_DBUSOBJECTSKELETON_P_H
#define _GIOMM_DBUSOBJECTSKELETON_P_H

#include <libmm/glib/object_p.hxx>

#include <libmm/glib/class.hxx>

namespace gio
{

  namespace DBus
  {

    class LIBMM_GIO_SYMEXPORT ObjectSkeleton_Class : public glib::Class
    {
    public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
      using CppObjectType = ObjectSkeleton;
      using BaseObjectType = GDBusObjectSkeleton;
      using BaseClassType = GDBusObjectSkeletonClass;
      using CppClassParent = glib::Object_Class;
      using BaseClassParent = GObjectClass;

      friend class ObjectSkeleton;
#endif

      auto
      init () -> const Class&;

      static auto
      class_init_function (void* g_class, void* class_data) -> void;

      static auto
      wrap_new (GObject*) -> glib::ObjectBase*;

    protected:
      static auto
      authorize_method_callback (GDBusObjectSkeleton* self,
                                 GDBusInterfaceSkeleton* p0,
                                 GDBusMethodInvocation* p1) -> gboolean;
    };

  } // namespace DBus

} // namespace gio

#endif
