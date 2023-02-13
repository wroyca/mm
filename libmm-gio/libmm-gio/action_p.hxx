
#ifndef _GIOMM_ACTION_P_H
#define _GIOMM_ACTION_P_H


#include <libmm-glib/interface_p.hxx>
#include <gio/gio.h>

#include <libmm-glib/interface_p.hxx>

namespace Gio
{

class GIOMM_API Action_Class : public Glib::Interface_Class
{
public:
  using CppObjectType = Action;
  using BaseObjectType = GAction;
  using BaseClassType = GActionInterface;
  using CppClassParent = Interface_Class;

  friend class Action;

  auto init () -> const Interface_Class&;

  static auto iface_init_function (void *g_iface, void *iface_data) -> void;

  static auto wrap_new (GObject *) -> Glib::ObjectBase*;

protected:

  //Callbacks (default signal handlers):
  //These will call the *_impl member methods, which will then call the existing default signal callbacks, if any.
  //You could prevent the original default signal handlers being called by overriding the *_impl method.

  //Callbacks (virtual functions):
  static auto get_name_vfunc_callback (GAction *self) -> const gchar*;
  static auto get_parameter_type_vfunc_callback (GAction *self) -> const GVariantType*;
  static auto get_state_type_vfunc_callback (GAction *self) -> const GVariantType*;
  static auto get_state_hint_vfunc_callback (GAction *self) -> GVariant*;
  static auto get_enabled_vfunc_callback (GAction *self) -> gboolean;
  static auto get_state_vfunc_callback (GAction *self) -> GVariant*;
  static auto change_state_vfunc_callback (GAction *self, GVariant *value) -> void;
  static auto activate_vfunc_callback (GAction *self, GVariant *parameter) -> void;
};


} // namespace Gio


#endif /* _GIOMM_ACTION_P_H */

