// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_WIDGET_P_H
#define _GTKMM_WIDGET_P_H

#include <libmm/gtk/object_p.hxx>

#include <libmm/glib/class.hxx>

namespace gtk
{

  class LIBMM_GTK_SYMEXPORT Widget_Class : public glib::Class
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    using CppObjectType = Widget;
    using BaseObjectType = GtkWidget;
    using BaseClassType = GtkWidgetClass;
    using CppClassParent = Object_Class;
    using BaseClassParent = GObjectClass;

    friend class Widget;
#endif

    auto
    init () -> const glib::Class&;

    static auto
    class_init_function (void* g_class, void* class_data) -> void;

    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;

  protected:
    static auto
    show_callback (GtkWidget* self) -> void;
    static auto
    hide_callback (GtkWidget* self) -> void;
    static auto
    map_callback (GtkWidget* self) -> void;
    static auto
    unmap_callback (GtkWidget* self) -> void;
    static auto
    realize_callback (GtkWidget* self) -> void;
    static auto
    unrealize_callback (GtkWidget* self) -> void;
    static auto
    state_flags_changed_callback (GtkWidget* self, GtkStateFlags p0) -> void;
    static auto
    direction_changed_callback (GtkWidget* self, GtkTextDirection p0) -> void;
    static auto
    mnemonic_activate_callback (GtkWidget* self, gboolean p0) -> gboolean;
    static auto
    query_tooltip_callback (GtkWidget* self,
                            gint p0,
                            gint p1,
                            gboolean p2,
                            GtkTooltip* p3) -> gboolean;

    static auto
    dispose_vfunc_callback (GObject* self) -> void;
    static auto
    root_vfunc_callback (GtkWidget* self) -> void;
    static auto
    unroot_vfunc_callback (GtkWidget* self) -> void;
    static auto
    size_allocate_vfunc_callback (GtkWidget* self,
                                  int width,
                                  int height,
                                  int baseline) -> void;
    static auto
    get_request_mode_vfunc_callback (GtkWidget* self) -> GtkSizeRequestMode;
    static auto
    measure_vfunc_callback (GtkWidget* self,
                            GtkOrientation orientation,
                            int for_size,
                            int* minimum,
                            int* natural,
                            int* minimum_baseline,
                            int* natural_baseline) -> void;
    static auto
    grab_focus_vfunc_callback (GtkWidget* self) -> gboolean;
    static auto
    set_focus_child_vfunc_callback (GtkWidget* self, GtkWidget* child) -> void;
    static auto
    compute_expand_vfunc_callback (GtkWidget* self,
                                   gboolean* hexpand_p,
                                   gboolean* vexpand_p) -> void;
    static auto
    contains_vfunc_callback (GtkWidget* self, gdouble x, gdouble y) -> gboolean;
    static auto
    snapshot_vfunc_callback (GtkWidget* self, GtkSnapshot* snapshot) -> void;
  };

} // namespace gtk

#endif
