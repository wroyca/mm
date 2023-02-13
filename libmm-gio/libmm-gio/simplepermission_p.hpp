
#ifndef _GIOMM_SIMPLEPERMISSION_P_H
#define _GIOMM_SIMPLEPERMISSION_P_H


#include <libmm-gio/permission_p.hpp>

#include <libmm-glib/class.hpp>

namespace Gio
{

class GIOMM_API SimplePermission_Class : public Glib::Class
{
public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  using CppObjectType = SimplePermission;
  using BaseObjectType = GSimplePermission;
  using BaseClassType = GSimplePermissionClass;
  using CppClassParent = Permission_Class;
  using BaseClassParent = GPermissionClass;

  friend class SimplePermission;
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


} // namespace Gio


#endif /* _GIOMM_SIMPLEPERMISSION_P_H */

