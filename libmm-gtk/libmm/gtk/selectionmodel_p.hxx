// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_SELECTIONMODEL_P_H
#define _GTKMM_SELECTIONMODEL_P_H

#include <gtk/gtk.h>
#include <libmm/glib/interface_p.hxx>

#include <libmm/glib/interface_p.hxx>

namespace gtk
{

  class LIBMM_GTK_SYMEXPORT SelectionModel_Class : public glib::Interface_Class
  {
  public:
    using CppObjectType = SelectionModel;
    using BaseObjectType = GtkSelectionModel;
    using BaseClassType = GtkSelectionModelInterface;
    using CppClassParent = glib::Interface_Class;

    friend class SelectionModel;

    auto
    init () -> const glib::Interface_Class&;

    static auto
    iface_init_function (void* g_iface, void* iface_data) -> void;

    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;

  protected:
    static auto
    is_selected_vfunc_callback (GtkSelectionModel* self, guint position)
        -> gboolean;
    static auto
    get_selection_in_range_vfunc_callback (GtkSelectionModel* self,
                                           guint position,
                                           guint n_items) -> GtkBitset*;
    static auto
    select_item_vfunc_callback (GtkSelectionModel* self,
                                guint position,
                                gboolean unselect_rest) -> gboolean;
    static auto
    unselect_item_vfunc_callback (GtkSelectionModel* self, guint position)
        -> gboolean;
    static auto
    select_range_vfunc_callback (GtkSelectionModel* self,
                                 guint position,
                                 guint n_items,
                                 gboolean unselect_rest) -> gboolean;
    static auto
    unselect_range_vfunc_callback (GtkSelectionModel* self,
                                   guint position,
                                   guint n_items) -> gboolean;
    static auto
    select_all_vfunc_callback (GtkSelectionModel* self) -> gboolean;
    static auto
    unselect_all_vfunc_callback (GtkSelectionModel* self) -> gboolean;
    static auto
    set_selection_vfunc_callback (GtkSelectionModel* self,
                                  GtkBitset* selected,
                                  GtkBitset* mask) -> gboolean;
  };

} // namespace gtk

#endif
