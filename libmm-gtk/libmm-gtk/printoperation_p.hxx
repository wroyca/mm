
#ifndef _GTKMM_PRINTOPERATION_P_H
#define _GTKMM_PRINTOPERATION_P_H

#include <gtk/gtk.h>
#include <libmm-glib/object_p.hxx>

#include <libmm-glib/class.hxx>

namespace Gtk
{

  class GTKMM_API PrintOperation_Class : public Glib::Class
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    using CppObjectType = PrintOperation;
    using BaseObjectType = GtkPrintOperation;
    using BaseClassType = GtkPrintOperationClass;
    using CppClassParent = Glib::Object_Class;
    using BaseClassParent = GObjectClass;

    friend class PrintOperation;
#endif

    auto
    init () -> const Class&;

    static auto
    class_init_function (void* g_class, void* class_data) -> void;

    static auto
    wrap_new (GObject*) -> Glib::ObjectBase*;

  protected:
    static auto
    done_callback (GtkPrintOperation* self, GtkPrintOperationResult p0) -> void;
    static auto
    begin_print_callback (GtkPrintOperation* self, GtkPrintContext* p0) -> void;
    static auto
    paginate_callback (GtkPrintOperation* self, GtkPrintContext* p0)
        -> gboolean;
    static auto
    request_page_setup_callback (GtkPrintOperation* self,
                                 GtkPrintContext* p0,
                                 gint p1,
                                 GtkPageSetup* p2) -> void;
    static auto
    draw_page_callback (GtkPrintOperation* self, GtkPrintContext* p0, gint p1)
        -> void;
    static auto
    end_print_callback (GtkPrintOperation* self, GtkPrintContext* p0) -> void;
    static auto
    status_changed_callback (GtkPrintOperation* self) -> void;
    static auto
    create_custom_widget_callback (GtkPrintOperation* self) -> GtkWidget*;
    static auto
    custom_widget_apply_callback (GtkPrintOperation* self, GtkWidget* p0)
        -> void;
    static auto
    preview_callback (GtkPrintOperation* self,
                      GtkPrintOperationPreview* p0,
                      GtkPrintContext* p1,
                      GtkWindow* p2) -> gboolean;
    static auto
    update_custom_widget_callback (GtkPrintOperation* self,
                                   GtkWidget* p0,
                                   GtkPageSetup* p1,
                                   GtkPrintSettings* p2) -> void;
  };

} // namespace Gtk

#endif
