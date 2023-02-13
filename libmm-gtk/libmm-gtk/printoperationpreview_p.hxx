
#ifndef _GTKMM_PRINTOPERATIONPREVIEW_P_H
#define _GTKMM_PRINTOPERATIONPREVIEW_P_H


#include <libmm-glib/interface_p.hpp>

#include <libmm-glib/interface_p.hpp>

namespace Gtk
{

class GTKMM_API PrintOperationPreview_Class : public Glib::Interface_Class
{
public:
  using CppObjectType = PrintOperationPreview;
  using BaseObjectType = GtkPrintOperationPreview;
  using BaseClassType = GtkPrintOperationPreviewIface;
  using CppClassParent = Interface_Class;

  friend class PrintOperationPreview;

  auto init () -> const Interface_Class&;

  static auto iface_init_function (void *g_iface, void *iface_data) -> void;

  static auto wrap_new (GObject *) -> Glib::ObjectBase*;

protected:

  //Callbacks (default signal handlers):
  //These will call the *_impl member methods, which will then call the existing default signal callbacks, if any.
  //You could prevent the original default signal handlers being called by overriding the *_impl method.
  static auto ready_callback (GtkPrintOperationPreview *self, GtkPrintContext *p0) -> void;
  static auto got_page_size_callback (
    GtkPrintOperationPreview *self, GtkPrintContext *p0, GtkPageSetup *p1) -> void;

  //Callbacks (virtual functions):
  static auto render_page_vfunc_callback (GtkPrintOperationPreview *self, gint page_nr) -> void;
  static auto end_preview_vfunc_callback (GtkPrintOperationPreview *self) -> void;
  static auto is_selected_vfunc_callback (GtkPrintOperationPreview *self, gint page_nr) -> gboolean;
};


} // namespace Gtk


#endif /* _GTKMM_PRINTOPERATIONPREVIEW_P_H */

