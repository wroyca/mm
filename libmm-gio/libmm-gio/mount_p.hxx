// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GIOMM_MOUNT_P_H
#define _GIOMM_MOUNT_P_H

#include <libmm-glib/interface_p.hxx>

#include <libmm-glib/interface_p.hxx>

namespace Gio
{

  class GIOMM_API Mount_Class : public Glib::Interface_Class
  {
  public:
    using CppObjectType = Mount;
    using BaseObjectType = GMount;
    using BaseClassType = GMountIface;
    using CppClassParent = Interface_Class;

    friend class Mount;

    auto
    init () -> const Interface_Class&;

    static auto
    iface_init_function (void* g_iface, void* iface_data) -> void;

    static auto
    wrap_new (GObject*) -> Glib::ObjectBase*;

  protected:
    static auto
    changed_callback (GMount* self) -> void;
    static auto
    unmounted_callback (GMount* self) -> void;
    static auto
    pre_unmount_callback (GMount* self) -> void;
  };

} // namespace Gio

#endif
