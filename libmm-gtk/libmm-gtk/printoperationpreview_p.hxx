// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_PRINTOPERATIONPREVIEW_P_H
#define _GTKMM_PRINTOPERATIONPREVIEW_P_H

#include <libmm-glib/interface_p.hxx>

#include <libmm-glib/interface_p.hxx>

namespace Gtk
{

  class LIBMM_GTK_SYMEXPORT PrintOperationPreview_Class : public Glib::Interface_Class
  {
  public:
    using CppObjectType = PrintOperationPreview;
    using BaseObjectType = GtkPrintOperationPreview;
    using BaseClassType = GtkPrintOperationPreviewIface;
    using CppClassParent = Glib::Interface_Class;

    friend class PrintOperationPreview;

    auto
    init () -> const Glib::Interface_Class&;

    static auto
    iface_init_function (void* g_iface, void* iface_data) -> void;

    static auto
    wrap_new (GObject*) -> Glib::ObjectBase*;

  protected:
    static auto
    ready_callback (GtkPrintOperationPreview* self, GtkPrintContext* p0)
        -> void;
    static auto
    got_page_size_callback (GtkPrintOperationPreview* self,
                            GtkPrintContext* p0,
                            GtkPageSetup* p1) -> void;

    static auto
    render_page_vfunc_callback (GtkPrintOperationPreview* self, gint page_nr)
        -> void;
    static auto
    end_preview_vfunc_callback (GtkPrintOperationPreview* self) -> void;
    static auto
    is_selected_vfunc_callback (GtkPrintOperationPreview* self, gint page_nr)
        -> gboolean;
  };

} // namespace Gtk

#endif
