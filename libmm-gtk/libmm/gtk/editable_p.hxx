// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_EDITABLE_P_H
#define _GTKMM_EDITABLE_P_H

#include <libmm/glib/interface_p.hxx>

#include <libmm/glib/interface_p.hxx>

namespace gtk
{

  class LIBMM_GTK_SYMEXPORT Editable_Class : public glib::Interface_Class
  {
  public:
    using CppObjectType = Editable;
    using BaseObjectType = GtkEditable;
    using BaseClassType = GtkEditableInterface;
    using CppClassParent = glib::Interface_Class;

    friend class Editable;

    auto
    init () -> const glib::Interface_Class&;

    static auto
    iface_init_function (void* g_iface, void* iface_data) -> void;

    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;

  protected:
    static auto
    insert_text_callback (GtkEditable* self,
                          const char* text,
                          int length,
                          int* position) -> void;
    static auto
    delete_text_callback (GtkEditable* self, gint p0, gint p1) -> void;
    static auto
    changed_callback (GtkEditable* self) -> void;

    static auto
    do_insert_text_vfunc_callback (GtkEditable* self,
                                   const char* text,
                                   int length,
                                   int* position) -> void;
    static auto
    do_delete_text_vfunc_callback (GtkEditable* self,
                                   int start_pos,
                                   int end_pos) -> void;
    static auto
    get_text_vfunc_callback (GtkEditable* self) -> const char*;
    static auto
    set_selection_bounds_vfunc_callback (GtkEditable* self,
                                         int start_pos,
                                         int end_pos) -> void;
    static auto
    get_selection_bounds_vfunc_callback (GtkEditable* self,
                                         int* start_pos,
                                         int* end_pos) -> gboolean;
  };

} // namespace gtk

#endif
