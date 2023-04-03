// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_CELLEDITABLE_P_H
#define _GTKMM_CELLEDITABLE_P_H

#include <libmm/glib/interface_p.hxx>

#include <libmm/glib/interface_p.hxx>

namespace Gtk
{

  class LIBMM_GTK_SYMEXPORT CellEditable_Class : public Glib::Interface_Class
  {
  public:
    using CppObjectType = CellEditable;
    using BaseObjectType = GtkCellEditable;
    using BaseClassType = GtkCellEditableIface;
    using CppClassParent = Glib::Interface_Class;

    friend class CellEditable;

    auto
    init () -> const Glib::Interface_Class&;

    static auto
    iface_init_function (void* g_iface, void* iface_data) -> void;

    static auto
    wrap_new (GObject*) -> Glib::ObjectBase*;

  protected:
#ifndef GTKMM_DISABLE_DEPRECATED

    static auto
    editing_done_callback (GtkCellEditable* self) -> void;
#endif

#ifndef GTKMM_DISABLE_DEPRECATED

    static auto
    remove_widget_callback (GtkCellEditable* self) -> void;
#endif

    static auto
    start_editing_vfunc_callback (GtkCellEditable* self, GdkEvent* event)
        -> void;
  };

} // namespace Gtk

#endif
