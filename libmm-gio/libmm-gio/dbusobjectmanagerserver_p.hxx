
#ifndef _GIOMM_DBUSOBJECTMANAGERSERVER_P_H
#define _GIOMM_DBUSOBJECTMANAGERSERVER_P_H


#include <libmm-glib/object_p.hxx>

#include <libmm-glib/class.hxx>

namespace Gio
{

namespace DBus
{

class GIOMM_API ObjectManagerServer_Class : public Glib::Class
{
public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  using CppObjectType = ObjectManagerServer;
  using BaseObjectType = GDBusObjectManagerServer;
  using BaseClassType = GDBusObjectManagerServerClass;
  using CppClassParent = Glib::Object_Class;
  using BaseClassParent = GObjectClass;

  friend class ObjectManagerServer;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

  auto init () -> const Class&;


  static auto class_init_function (void *g_class, void *class_data) -> void;

  static auto wrap_new (GObject *) -> Glib::ObjectBase*;

protected:

  //Callbacks (default signal handlers):
  //These will call the *_impl member methods, which will then call the existing default signal callbacks, if any.
  //You could prevent the original default signal handlers being called by overriding the *_impl method.

  //Callbacks (virtual functions):
};


} // namespace DBus

} // namespace Gio


#endif /* _GIOMM_DBUSOBJECTMANAGERSERVER_P_H */

