// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GDKMM_PAINTABLE_P_H
#define _GDKMM_PAINTABLE_P_H

#include <gdk/gdk.h>
#include <libmm-glib/interface_p.hxx>

#include <libmm-glib/interface_p.hxx>

namespace Gdk
{

  class LIBMM_GDK_SYMEXPORT Paintable_Class : public Glib::Interface_Class
  {
  public:
    using CppObjectType = Paintable;
    using BaseObjectType = GdkPaintable;
    using BaseClassType = GdkPaintableInterface;
    using CppClassParent = Glib::Interface_Class;

    friend class Paintable;

    auto
    init () -> const Glib::Interface_Class&;

    static auto
    iface_init_function (void* g_iface, void* iface_data) -> void;

    static auto
    wrap_new (GObject*) -> Glib::ObjectBase*;

  protected:
    static auto
    snapshot_vfunc_callback (GdkPaintable* self,
                             GdkSnapshot* snapshot,
                             double width,
                             double height) -> void;
    static auto
    get_current_image_vfunc_callback (GdkPaintable* self) -> GdkPaintable*;
    static auto
    get_flags_vfunc_callback (GdkPaintable* self) -> GdkPaintableFlags;
    static auto
    get_intrinsic_width_vfunc_callback (GdkPaintable* self) -> int;
    static auto
    get_intrinsic_height_vfunc_callback (GdkPaintable* self) -> int;
    static auto
    get_intrinsic_aspect_ratio_vfunc_callback (GdkPaintable* self) -> double;
  };

} // namespace Gdk

#endif
