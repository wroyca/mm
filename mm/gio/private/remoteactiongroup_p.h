// Generated by gmmproc 2.74.0 -- DO NOT MODIFY!
#ifndef _GIOMM_REMOTEACTIONGROUP_P_H
#define _GIOMM_REMOTEACTIONGROUP_P_H


#include <mm/glib/private/interface_p.h>
#include <gio/gio.h>

#include <mm/glib/private/interface_p.h>

namespace Gio
{

class GIOMM_API RemoteActionGroup_Class : public Glib::Interface_Class
{
public:
  using CppObjectType = RemoteActionGroup;
  using BaseObjectType = GRemoteActionGroup;
  using BaseClassType = GRemoteActionGroupInterface;
  using CppClassParent = Glib::Interface_Class;

  friend class RemoteActionGroup;

  const Glib::Interface_Class& init();

  static void iface_init_function(void* g_iface, void* iface_data);

  static Glib::ObjectBase* wrap_new(GObject*);

protected:

  //Callbacks (default signal handlers):
  //These will call the *_impl member methods, which will then call the existing default signal callbacks, if any.
  //You could prevent the original default signal handlers being called by overriding the *_impl method.

  //Callbacks (virtual functions):
  static void activate_action_full_vfunc_callback(GRemoteActionGroup* self, const gchar* action_name, GVariant* parameter, GVariant* platform_data);
  static void change_action_state_full_vfunc_callback(GRemoteActionGroup* self, const gchar* action_name, GVariant* value, GVariant* platform_data);
};


} // namespace Gio


#endif /* _GIOMM_REMOTEACTIONGROUP_P_H */

