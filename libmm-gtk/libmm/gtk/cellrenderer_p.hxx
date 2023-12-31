// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_CELLRENDERER_P_H
#define _GTKMM_CELLRENDERER_P_H
#ifndef GTKMM_DISABLE_DEPRECATED

  #include <gtk/gtk.h>
  #include <libmm/gtk/object_p.hxx>

  #include <libmm/glib/class.hxx>

namespace gtk
{

  class LIBMM_GTK_SYMEXPORT CellRenderer_Class : public glib::Class
  {
  public:
  #ifndef DOXYGEN_SHOULD_SKIP_THIS
    using CppObjectType = CellRenderer;
    using BaseObjectType = GtkCellRenderer;
    using BaseClassType = GtkCellRendererClass;
    using CppClassParent = gtk::Object_Class;
    using BaseClassParent = GObjectClass;

    friend class CellRenderer;
  #endif

    auto
    init () -> const glib::Class&;

    static auto
    class_init_function (void* g_class, void* class_data) -> void;

    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;

  protected:
    static auto
    editing_canceled_callback (GtkCellRenderer* self) -> void;
    static auto
    editing_started_callback (GtkCellRenderer* self,
                              GtkCellEditable* p0,
                              const gchar* p1) -> void;

    static auto
    get_request_mode_vfunc_callback (GtkCellRenderer* self)
        -> GtkSizeRequestMode;
    static auto
    get_preferred_width_vfunc_callback (GtkCellRenderer* self,
                                        GtkWidget* widget,
                                        gint* minimum_width,
                                        gint* natural_width) -> void;
    static auto
    get_preferred_height_for_width_vfunc_callback (GtkCellRenderer* self,
                                                   GtkWidget* widget,
                                                   gint width,
                                                   gint* minimum_height,
                                                   gint* natural_height)
        -> void;
    static auto
    get_preferred_height_vfunc_callback (GtkCellRenderer* self,
                                         GtkWidget* widget,
                                         gint* minimum_height,
                                         gint* natural_height) -> void;
    static auto
    get_preferred_width_for_height_vfunc_callback (GtkCellRenderer* self,
                                                   GtkWidget* widget,
                                                   gint height,
                                                   gint* minimum_width,
                                                   gint* natural_width) -> void;
    static auto
    snapshot_vfunc_callback (GtkCellRenderer* self,
                             GtkSnapshot* snapshot,
                             GtkWidget* widget,
                             const GdkRectangle* background_area,
                             const GdkRectangle* cell_area,
                             GtkCellRendererState flags) -> void;
    static auto
    activate_vfunc_callback (GtkCellRenderer* self,
                             GdkEvent* event,
                             GtkWidget* widget,
                             const gchar* path,
                             const GdkRectangle* background_area,
                             const GdkRectangle* cell_area,
                             GtkCellRendererState flags) -> gboolean;
    static auto
    start_editing_vfunc_callback (GtkCellRenderer* self,
                                  GdkEvent* event,
                                  GtkWidget* widget,
                                  const gchar* path,
                                  const GdkRectangle* background_area,
                                  const GdkRectangle* cell_area,
                                  GtkCellRendererState flags)
        -> GtkCellEditable*;
  };

} // namespace gtk

#endif

#endif
