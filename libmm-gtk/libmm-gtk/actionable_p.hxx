
#ifndef _GTKMM_ACTIONABLE_P_H
#define _GTKMM_ACTIONABLE_P_H

#include <libmm-glib/interface_p.hxx>

#include <libmm-glib/interface_p.hxx>

namespace Gtk
{

  class GTKMM_API Actionable_Class : public Glib::Interface_Class
  {
  public:
    using CppObjectType = Actionable;
    using BaseObjectType = GtkActionable;
    using BaseClassType = GtkActionableInterface;
    using CppClassParent = Interface_Class;

    friend class Actionable;

    auto
    init () -> const Interface_Class&;

    static auto
    iface_init_function (void* g_iface, void* iface_data) -> void;

    static auto
    wrap_new (GObject*) -> Glib::ObjectBase*;

  protected:
    static auto
    get_action_name_vfunc_callback (GtkActionable* self) -> const gchar*;
    static auto
    set_action_name_vfunc_callback (GtkActionable* self,
                                    const gchar* action_name) -> void;
    static auto
    get_action_target_value_vfunc_callback (GtkActionable* self) -> GVariant*;
    static auto
    set_action_target_value_vfunc_callback (GtkActionable* self,
                                            GVariant* action_target_value)
        -> void;
  };

} // namespace Gtk

#endif
