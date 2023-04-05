// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GIOMM_ACTIONGROUP_P_H
#define _GIOMM_ACTIONGROUP_P_H

#include <gio/gio.h>
#include <libmm/glib/interface_p.hxx>

#include <libmm/glib/interface_p.hxx>

namespace gio
{

  class LIBMM_GIO_SYMEXPORT ActionGroup_Class : public glib::Interface_Class
  {
  public:
    using CppObjectType = ActionGroup;
    using BaseObjectType = GActionGroup;
    using BaseClassType = GActionGroupInterface;
    using CppClassParent = Interface_Class;

    friend class ActionGroup;

    auto
    init () -> const Interface_Class&;

    static auto
    iface_init_function (void* g_iface, void* iface_data) -> void;

    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;

  protected:
    static auto
    action_added_callback (GActionGroup* self, const gchar* p0) -> void;
    static auto
    action_enabled_changed_callback (GActionGroup* self,
                                     const gchar* p0,
                                     gboolean p1) -> void;
    static auto
    action_removed_callback (GActionGroup* self, const gchar* p0) -> void;
    static auto
    action_state_changed_callback (GActionGroup* self,
                                   const gchar* p0,
                                   GVariant* p1) -> void;

    static auto
    has_action_vfunc_callback (GActionGroup* self, const gchar* action_name)
        -> gboolean;
    static auto
    list_actions_vfunc_callback (GActionGroup* self) -> gchar**;
    static auto
    get_action_enabled_vfunc_callback (GActionGroup* self,
                                       const gchar* action_name) -> gboolean;
    static auto
    get_action_parameter_type_vfunc_callback (GActionGroup* self,
                                              const gchar* action_name)
        -> const GVariantType*;
    static auto
    get_action_state_type_vfunc_callback (GActionGroup* self,
                                          const gchar* action_name)
        -> const GVariantType*;
    static auto
    get_action_state_hint_vfunc_callback (GActionGroup* self,
                                          const gchar* action_name)
        -> GVariant*;
    static auto
    get_action_state_vfunc_callback (GActionGroup* self,
                                     const gchar* action_name) -> GVariant*;
    static auto
    change_action_state_vfunc_callback (GActionGroup* self,
                                        const gchar* action_name,
                                        GVariant* value) -> void;
    static auto
    activate_action_vfunc_callback (GActionGroup* self,
                                    const gchar* action_name,
                                    GVariant* parameter) -> void;
  };

} // namespace gio

#endif
