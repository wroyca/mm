// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GIOMM_VOLUME_P_H
#define _GIOMM_VOLUME_P_H

#include <libmm/glib/interface_p.hxx>

#include <libmm/glib/interface_p.hxx>

namespace Gio
{

  class LIBMM_GIO_SYMEXPORT Volume_Class : public Glib::Interface_Class
  {
  public:
    using CppObjectType = Volume;
    using BaseObjectType = GVolume;
    using BaseClassType = GVolumeIface;
    using CppClassParent = Interface_Class;

    friend class Volume;

    auto
    init () -> const Interface_Class&;

    static auto
    iface_init_function (void* g_iface, void* iface_data) -> void;

    static auto
    wrap_new (GObject*) -> Glib::ObjectBase*;

  protected:
    static auto
    changed_callback (GVolume* self) -> void;
    static auto
    removed_callback (GVolume* self) -> void;
  };

} // namespace Gio

#endif
