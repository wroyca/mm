// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GDKMM_DRAGSURFACE_P_H
#define _GDKMM_DRAGSURFACE_P_H

#include <gdk/gdk.h>
#include <libmm-glib/interface_p.hxx>

#include <libmm-glib/interface_p.hxx>

namespace Gdk
{

  class GDKMM_API DragSurface_Class : public Glib::Interface_Class
  {
  public:
    using CppObjectType = DragSurface;
    using BaseObjectType = GdkDragSurface;
    using BaseClassType = GdkDragSurfaceInterface;
    using CppClassParent = Glib::Interface_Class;

    friend class DragSurface;

    auto
    init () -> const Glib::Interface_Class&;

    static auto
    iface_init_function (void* g_iface, void* iface_data) -> void;

    static auto
    wrap_new (GObject*) -> Glib::ObjectBase*;

  protected:
  };

} // namespace Gdk

#endif
