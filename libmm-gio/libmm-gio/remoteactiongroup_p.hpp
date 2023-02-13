
#ifndef _GIOMM_REMOTEACTIONGROUP_P_H
#define _GIOMM_REMOTEACTIONGROUP_P_H


#include <libmm-glib/interface_p.hpp>
#include <gio/gio.h>

#include <libmm-glib/interface_p.hpp>

namespace Gio
{

class GIOMM_API RemoteActionGroup_Class : public Glib::Interface_Class
{
public:
  using CppObjectType = RemoteActionGroup;
  using BaseObjectType = GRemoteActionGroup;
  using BaseClassType = GRemoteActionGroupInterface;
  using CppClassParent = Interface_Class;

  friend class RemoteActionGroup;

  auto init () -> const Interface_Class&;

  static auto iface_init_function (void *g_iface, void *iface_data) -> void;

  static auto wrap_new (GObject *) -> Glib::ObjectBase*;

protected:

  //Callbacks (default signal handlers):
  //These will call the *_impl member methods, which will then call the existing default signal callbacks, if any.
  //You could prevent the original default signal handlers being called by overriding the *_impl method.

  //Callbacks (virtual functions):
  static auto activate_action_full_vfunc_callback (
    GRemoteActionGroup *self, const gchar *action_name, GVariant *parameter,
    GVariant *platform_data) -> void;
  static auto change_action_state_full_vfunc_callback (
    GRemoteActionGroup *self, const gchar *action_name, GVariant *value,
    GVariant *platform_data) -> void;
};


} // namespace Gio


#endif /* _GIOMM_REMOTEACTIONGROUP_P_H */

