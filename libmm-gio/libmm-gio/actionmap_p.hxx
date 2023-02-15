// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GIOMM_ACTIONMAP_P_H
#define _GIOMM_ACTIONMAP_P_H

#include <gio/gio.h>
#include <libmm-glib/interface_p.hxx>

#include <libmm-glib/interface_p.hxx>

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

    auto
    init () -> const Interface_Class&;

    static auto
    iface_init_function (void* g_iface, void* iface_data) -> void;

    static auto
    wrap_new (GObject*) -> Glib::ObjectBase*;

  protected:
    static auto
    lookup_action_vfunc_callback (GActionMap* self, const gchar* action_name)
        -> GAction*;
    static auto
    add_action_vfunc_callback (GActionMap* self, GAction* action) -> void;
    static auto
    remove_action_vfunc_callback (GActionMap* self, const gchar* action_name)
        -> void;
  };

} // namespace Gio

#endif
