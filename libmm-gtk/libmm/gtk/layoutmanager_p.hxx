// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_LAYOUTMANAGER_P_H
#define _GTKMM_LAYOUTMANAGER_P_H

#include <libmm/glib/object_p.hxx>

#include <libmm/glib/class.hxx>

namespace gtk
{

  class LIBMM_GTK_SYMEXPORT LayoutManager_Class : public glib::Class
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    using CppObjectType = LayoutManager;
    using BaseObjectType = GtkLayoutManager;
    using BaseClassType = GtkLayoutManagerClass;
    using CppClassParent = glib::Object_Class;
    using BaseClassParent = GObjectClass;

    friend class LayoutManager;
#endif

    auto
    init () -> const glib::Class&;

    static auto
    class_init_function (void* g_class, void* class_data) -> void;

    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;

  protected:
    static auto
    get_request_mode_vfunc_callback (GtkLayoutManager* self, GtkWidget* widget)
        -> GtkSizeRequestMode;
    static auto
    measure_vfunc_callback (GtkLayoutManager* self,
                            GtkWidget* widget,
                            GtkOrientation orientation,
                            int for_size,
                            int* minimum,
                            int* natural,
                            int* minimum_baseline,
                            int* natural_baseline) -> void;
    static auto
    allocate_vfunc_callback (GtkLayoutManager* self,
                             GtkWidget* widget,
                             int width,
                             int height,
                             int baseline) -> void;
    static auto
    create_layout_child_vfunc_callback (GtkLayoutManager* self,
                                        GtkWidget* widget,
                                        GtkWidget* for_child)
        -> GtkLayoutChild*;
    static auto
    root_vfunc_callback (GtkLayoutManager* self) -> void;
    static auto
    unroot_vfunc_callback (GtkLayoutManager* self) -> void;
  };

} // namespace gtk

#endif
