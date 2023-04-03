// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GIOMM_REMOTEACTIONGROUP_P_H
#define _GIOMM_REMOTEACTIONGROUP_P_H

#include <gio/gio.h>
#include <libmm/glib/interface_p.hxx>

#include <libmm/glib/interface_p.hxx>

namespace Gio
{

  class LIBMM_GIO_SYMEXPORT RemoteActionGroup_Class : public Glib::Interface_Class
  {
  public:
    using CppObjectType = RemoteActionGroup;
    using BaseObjectType = GRemoteActionGroup;
    using BaseClassType = GRemoteActionGroupInterface;
    using CppClassParent = Interface_Class;

    friend class RemoteActionGroup;

    auto
    init () -> const Interface_Class&;

    static auto
    iface_init_function (void* g_iface, void* iface_data) -> void;

    static auto
    wrap_new (GObject*) -> Glib::ObjectBase*;

  protected:
    static auto
    activate_action_full_vfunc_callback (GRemoteActionGroup* self,
                                         const gchar* action_name,
                                         GVariant* parameter,
                                         GVariant* platform_data) -> void;
    static auto
    change_action_state_full_vfunc_callback (GRemoteActionGroup* self,
                                             const gchar* action_name,
                                             GVariant* value,
                                             GVariant* platform_data) -> void;
  };

} // namespace Gio

#endif
