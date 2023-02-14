// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm-glib/mm-glib.hxx>
#include <libmm-gtk/treeview_private.hxx>

namespace Gtk::TreeView_Private
{

  auto
  SignalProxy_CellData_gtk_callback (GtkTreeViewColumn*,
                                     GtkCellRenderer* cell,
                                     GtkTreeModel* model,
                                     GtkTreeIter* iter,
                                     void* data) -> void
  {
    if (!model)
      g_warning ("SignalProxy_CellData_gtk_callback(): model is NULL, which is "
                 "unusual.\n");

    const TreeViewColumn::SlotTreeCellData* the_slot =
        static_cast<TreeViewColumn::SlotTreeCellData*> (data);

    try
    {
      auto cppiter = TreeModel::iterator (model, iter);
      if (!cppiter.get_model_gobject ())
      {
        g_warning (
            "SignalProxy_CellData_gtk_callback() The cppiter has no model\n");
        return;
      }

      (*the_slot) (Glib::wrap (cell, false), cppiter);
    }
    catch (...)
    {
      Glib::exception_handlers_invoke ();
    }
  }

  auto
  SignalProxy_CellData_gtk_callback_destroy (void* data) -> void
  {
    delete static_cast<TreeViewColumn::SlotTreeCellData*> (data);
  }

  auto
  SignalProxy_RowSeparator_gtk_callback (GtkTreeModel* model,
                                         GtkTreeIter* iter,
                                         void* data) -> gboolean
  {
    const TreeView::SlotRowSeparator* the_slot =
        static_cast<TreeView::SlotRowSeparator*> (data);

    try
    {
      return (*the_slot) (Glib::wrap (model, true),
                          TreeModel::iterator (model, iter));
    }
    catch (...)
    {
      Glib::exception_handlers_invoke ();
    }

    return 0;
  }

  auto
  SignalProxy_RowSeparator_gtk_callback_destroy (void* data) -> void
  {
    delete static_cast<TreeView::SlotRowSeparator*> (data);
  }

} // namespace Gtk::TreeView_Private
