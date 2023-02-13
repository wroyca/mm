
#ifndef _GIOMM_ACTIONMAP_P_H
#define _GIOMM_ACTIONMAP_P_H


#include <mm/glib/private/interface_p.hpp>
#include <gio/gio.h>

#include <mm/glib/private/interface_p.hpp>

namespace Gio
{

class GIOMM_API ActionMap_Class : public Glib::Interface_Class
{
public:
  using CppObjectType = ActionMap;
  using BaseObjectType = GActionMap;
  using BaseClassType = GActionMapInterface;
  using CppClassParent = Interface_Class;

  friend class ActionMap;

  auto init () -> const Interface_Class&;

  static auto iface_init_function (void *g_iface, void *iface_data) -> void;

  static auto wrap_new (GObject *) -> Glib::ObjectBase*;

protected:

  //Callbacks (default signal handlers):
  //These will call the *_impl member methods, which will then call the existing default signal callbacks, if any.
  //You could prevent the original default signal handlers being called by overriding the *_impl method.

  //Callbacks (virtual functions):
  static auto lookup_action_vfunc_callback (GActionMap *self, const gchar *action_name) -> GAction*;
  static auto add_action_vfunc_callback (GActionMap *self, GAction *action) -> void;
  static auto remove_action_vfunc_callback (GActionMap *self, const gchar *action_name) -> void;
};


} // namespace Gio


#endif /* _GIOMM_ACTIONMAP_P_H */

