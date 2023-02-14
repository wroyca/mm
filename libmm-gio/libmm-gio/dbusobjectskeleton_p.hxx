
#ifndef _GIOMM_DBUSOBJECTSKELETON_P_H
#define _GIOMM_DBUSOBJECTSKELETON_P_H

#include <libmm-glib/object_p.hxx>

#include <libmm-glib/class.hxx>

namespace Gio
{

  namespace DBus
  {

    class GIOMM_API ObjectSkeleton_Class : public Glib::Class
    {
    public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
      using CppObjectType = ObjectSkeleton;
      using BaseObjectType = GDBusObjectSkeleton;
      using BaseClassType = GDBusObjectSkeletonClass;
      using CppClassParent = Glib::Object_Class;
      using BaseClassParent = GObjectClass;

      friend class ObjectSkeleton;
#endif

      auto
      init () -> const Class&;

      static auto
      class_init_function (void* g_class, void* class_data) -> void;

      static auto
      wrap_new (GObject*) -> Glib::ObjectBase*;

    protected:
      static auto
      authorize_method_callback (GDBusObjectSkeleton* self,
                                 GDBusInterfaceSkeleton* p0,
                                 GDBusMethodInvocation* p1) -> gboolean;
    };

  } // namespace DBus

} // namespace Gio

#endif
