// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_TREEVIEW_PRIVATE_H
#define _GTKMM_TREEVIEW_PRIVATE_H

#ifndef GTKMM_DISABLE_DEPRECATED

  #include <libmm-gtk/treeview.hxx>
  #include <libmm-gtk/treeviewcolumn.hxx>

namespace Gtk
{

  #ifndef DOXYGEN_SHOULD_SKIP_THIS
  namespace TreeView_Private
  {
    LIBMM_GTK_SYMEXPORT auto
    SignalProxy_CellData_gtk_callback (GtkTreeViewColumn*,
                                       GtkCellRenderer* cell,
                                       GtkTreeModel* model,
                                       GtkTreeIter* iter,
                                       void* data) -> void;
    LIBMM_GTK_SYMEXPORT auto
    SignalProxy_CellData_gtk_callback_destroy (void* data) -> void;

    LIBMM_GTK_SYMEXPORT auto
    SignalProxy_RowSeparator_gtk_callback (GtkTreeModel* model,
                                           GtkTreeIter* iter,
                                           void* data) -> gboolean;
    LIBMM_GTK_SYMEXPORT auto
    SignalProxy_RowSeparator_gtk_callback_destroy (void* data) -> void;

  } // namespace TreeView_Private
  #endif

} // namespace Gtk

#endif

#endif
