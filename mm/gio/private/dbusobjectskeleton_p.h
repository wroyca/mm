// Generated by gmmproc 2.74.0 -- DO NOT MODIFY!
#ifndef _GIOMM_DBUSOBJECTSKELETON_P_H
#define _GIOMM_DBUSOBJECTSKELETON_P_H


#include <mm/glib/private/object_p.h>

#include <mm/glib/class.h>

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
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

  const Glib::Class& init();


  static void class_init_function(void* g_class, void* class_data);

  static Glib::ObjectBase* wrap_new(GObject*);

protected:

  //Callbacks (default signal handlers):
  //These will call the *_impl member methods, which will then call the existing default signal callbacks, if any.
  //You could prevent the original default signal handlers being called by overriding the *_impl method.
  static gboolean authorize_method_callback(GDBusObjectSkeleton* self, GDBusInterfaceSkeleton* p0, GDBusMethodInvocation* p1);

  //Callbacks (virtual functions):
};


} // namespace DBus

} // namespace Gio


#endif /* _GIOMM_DBUSOBJECTSKELETON_P_H */

