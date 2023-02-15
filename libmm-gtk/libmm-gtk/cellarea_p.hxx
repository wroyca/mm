// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_CELLAREA_P_H
#define _GTKMM_CELLAREA_P_H
#ifndef GTKMM_DISABLE_DEPRECATED

  #include <libmm-gtk/object_p.hxx>

  #include <libmm-glib/class.hxx>

namespace Gtk
{

  class LIBMM_GTK_SYMEXPORT CellArea_Class : public Glib::Class
  {
  public:
  #ifndef DOXYGEN_SHOULD_SKIP_THIS
    using CppObjectType = CellArea;
    using BaseObjectType = GtkCellArea;
    using BaseClassType = GtkCellAreaClass;
    using CppClassParent = Glib::Object_Class;
    using BaseClassParent = GObjectClass;

    friend class CellArea;
  #endif

    auto
    init () -> const Glib::Class&;

    static auto
    class_init_function (void* g_class, void* class_data) -> void;

    static auto
    wrap_new (GObject*) -> Glib::ObjectBase*;

  protected:
    static auto
    apply_attributes_callback (GtkCellArea* self,
                               GtkTreeModel* p0,
                               GtkTreeIter* p1,
                               gboolean p2,
                               gboolean p3) -> void;

    static auto
    snapshot_vfunc_callback (GtkCellArea* self,
                             GtkCellAreaContext* context,
                             GtkWidget* widget,
                             GtkSnapshot* snapshot,
                             const GdkRectangle* background_area,
                             const GdkRectangle* cell_area,
                             GtkCellRendererState flags,
                             gboolean paint_focus) -> void;
    static auto
    get_request_mode_vfunc_callback (GtkCellArea* self) -> GtkSizeRequestMode;
    static auto
    get_preferred_width_vfunc_callback (GtkCellArea* self,
                                        GtkCellAreaContext* context,
                                        GtkWidget* widget,
                                        gint* minimum_width,
                                        gint* natural_width) -> void;
    static auto
    get_preferred_height_for_width_vfunc_callback (GtkCellArea* self,
                                                   GtkCellAreaContext* context,
                                                   GtkWidget* widget,
                                                   gint width,
                                                   gint* minimum_height,
                                                   gint* natural_height)
        -> void;
    static auto
    get_preferred_height_vfunc_callback (GtkCellArea* self,
                                         GtkCellAreaContext* context,
                                         GtkWidget* widget,
                                         gint* minimum_height,
                                         gint* natural_height) -> void;
    static auto
    get_preferred_width_for_height_vfunc_callback (GtkCellArea* self,
                                                   GtkCellAreaContext* context,
                                                   GtkWidget* widget,
                                                   gint height,
                                                   gint* minimum_width,
                                                   gint* natural_width) -> void;
  };

} // namespace Gtk

#endif

#endif
