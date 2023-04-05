// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GIOMM_ACTION_P_H
#define _GIOMM_ACTION_P_H

#include <gio/gio.h>
#include <libmm/glib/interface_p.hxx>

#include <libmm/glib/interface_p.hxx>

namespace gio
{

  class LIBMM_GIO_SYMEXPORT Action_Class : public glib::Interface_Class
  {
  public:
    using CppObjectType = Action;
    using BaseObjectType = GAction;
    using BaseClassType = GActionInterface;
    using CppClassParent = Interface_Class;

    friend class Action;

    auto
    init () -> const Interface_Class&;

    static auto
    iface_init_function (void* g_iface, void* iface_data) -> void;

    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;

  protected:
    static auto
    get_name_vfunc_callback (GAction* self) -> const gchar*;
    static auto
    get_parameter_type_vfunc_callback (GAction* self) -> const GVariantType*;
    static auto
    get_state_type_vfunc_callback (GAction* self) -> const GVariantType*;
    static auto
    get_state_hint_vfunc_callback (GAction* self) -> GVariant*;
    static auto
    get_enabled_vfunc_callback (GAction* self) -> gboolean;
    static auto
    get_state_vfunc_callback (GAction* self) -> GVariant*;
    static auto
    change_state_vfunc_callback (GAction* self, GVariant* value) -> void;
    static auto
    activate_vfunc_callback (GAction* self, GVariant* parameter) -> void;
  };

} // namespace gio

#endif
