// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GIOMM_LOADABLEICON_P_H
#define _GIOMM_LOADABLEICON_P_H

#include <libmm-glib/interface_p.hxx>

#include <libmm-glib/interface_p.hxx>

namespace Gio
{

  class GIOMM_API LoadableIcon_Class : public Glib::Interface_Class
  {
  public:
    using CppObjectType = LoadableIcon;
    using BaseObjectType = GLoadableIcon;
    using BaseClassType = GLoadableIconIface;
    using CppClassParent = Interface_Class;

    friend class LoadableIcon;

    auto
    init () -> const Interface_Class&;

    static auto
    iface_init_function (void* g_iface, void* iface_data) -> void;

    static auto
    wrap_new (GObject*) -> Glib::ObjectBase*;

  protected:
  };

} // namespace Gio

#endif
