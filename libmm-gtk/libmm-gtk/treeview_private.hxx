#ifndef _GTKMM_TREEVIEW_PRIVATE_H
#define _GTKMM_TREEVIEW_PRIVATE_H

#include <libmm-gtk/treeview.hxx>
#include <libmm-gtk/treeviewcolumn.hxx>

namespace Gtk::TreeView_Private
{

  GTKMM_API
  void
  SignalProxy_CellData_gtk_callback (GtkTreeViewColumn*,
                                     GtkCellRenderer* cell,
                                     GtkTreeModel* model,
                                     GtkTreeIter* iter,
                                     void* data);
  GTKMM_API
  void
  SignalProxy_CellData_gtk_callback_destroy (void* data);

  GTKMM_API
  auto
  SignalProxy_RowSeparator_gtk_callback (GtkTreeModel* model,
                                         GtkTreeIter* iter,
                                         void* data) -> gboolean;
  GTKMM_API
  void
  SignalProxy_RowSeparator_gtk_callback_destroy (void* data);

} // namespace Gtk::TreeView_Private

#endif
