
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
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

  auto init () -> const Class&;


  static auto class_init_function (void *g_class, void *class_data) -> void;

  static auto wrap_new (GObject *) -> Glib::ObjectBase*;

protected:

  //Callbacks (default signal handlers):
  //These will call the *_impl member methods, which will then call the existing default signal callbacks, if any.
  //You could prevent the original default signal handlers being called by overriding the *_impl method.
  static auto authorize_method_callback (
    GDBusObjectSkeleton *self, GDBusInterfaceSkeleton *p0, GDBusMethodInvocation *p1) -> gboolean;

  //Callbacks (virtual functions):
};


} // namespace DBus

} // namespace Gio


#endif /* _GIOMM_DBUSOBJECTSKELETON_P_H */

