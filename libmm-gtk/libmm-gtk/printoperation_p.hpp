
#ifndef _GTKMM_PRINTOPERATION_P_H
#define _GTKMM_PRINTOPERATION_P_H


#include <mm/glib/private/object_p.hpp>
#include <gtk/gtk.h>

#include <mm/glib/class.hpp>

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
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

  auto init () -> const Class&;


  static auto class_init_function (void *g_class, void *class_data) -> void;

  static auto wrap_new (GObject *) -> Glib::ObjectBase*;

protected:

  //Callbacks (default signal handlers):
  //These will call the *_impl member methods, which will then call the existing default signal callbacks, if any.
  //You could prevent the original default signal handlers being called by overriding the *_impl method.
  static auto done_callback (GtkPrintOperation *self, GtkPrintOperationResult p0) -> void;
  static auto begin_print_callback (GtkPrintOperation *self, GtkPrintContext *p0) -> void;
  static auto paginate_callback (GtkPrintOperation *self, GtkPrintContext *p0) -> gboolean;
  static auto request_page_setup_callback (
    GtkPrintOperation *self, GtkPrintContext *p0, gint p1, GtkPageSetup *p2) -> void;
  static auto draw_page_callback (GtkPrintOperation *self, GtkPrintContext *p0, gint p1) -> void;
  static auto end_print_callback (GtkPrintOperation *self, GtkPrintContext *p0) -> void;
  static auto status_changed_callback (GtkPrintOperation *self) -> void;
  static auto create_custom_widget_callback (GtkPrintOperation *self) -> GtkWidget*;
  static auto custom_widget_apply_callback (GtkPrintOperation *self, GtkWidget *p0) -> void;
  static auto preview_callback (
    GtkPrintOperation *self, GtkPrintOperationPreview *p0, GtkPrintContext *p1,
    GtkWindow *p2) -> gboolean;
  static auto update_custom_widget_callback (
    GtkPrintOperation *self, GtkWidget *p0, GtkPageSetup *p1, GtkPrintSettings *p2) -> void;

  //Callbacks (virtual functions):
};


} // namespace Gtk


#endif /* _GTKMM_PRINTOPERATION_P_H */

