// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef GTKMM_DISABLE_DEPRECATED

  #include <libmm/glib/mm-glib.hxx>
  #include <libmm/gtk/treeview_private.hxx>

namespace gtk
{

  namespace TreeView_Private
  {

    auto
    SignalProxy_CellData_gtk_callback (GtkTreeViewColumn*,
                                       GtkCellRenderer* cell,
                                       GtkTreeModel* model,
                                       GtkTreeIter* iter,
                                       void* data) -> void
    {
      if (!model)
        g_warning ("SignalProxy_CellData_gtk_callback(): model is NULL, which "
                   "is unusual.\n");

      TreeViewColumn::SlotTreeCellData* the_slot =
          static_cast<TreeViewColumn::SlotTreeCellData*> (data);

      try
      {
        auto cppiter = gtk::TreeModel::iterator (model, iter);
        if (!cppiter.get_model_gobject ())
        {
          g_warning (
              "SignalProxy_CellData_gtk_callback() The cppiter has no model\n");
          return;
        }

        (*the_slot) (glib::wrap (cell, false), cppiter);
      }
      catch (...)
      {
        glib::exception_handlers_invoke ();
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
      TreeView::SlotRowSeparator* the_slot =
          static_cast<TreeView::SlotRowSeparator*> (data);

      try
      {
        return (*the_slot) (glib::wrap (model, true),
                            gtk::TreeModel::iterator (model, iter));
      }
      catch (...)
      {
        glib::exception_handlers_invoke ();
      }

      return 0;
    }

    auto
    SignalProxy_RowSeparator_gtk_callback_destroy (void* data) -> void
    {
      delete static_cast<TreeView::SlotRowSeparator*> (data);
    }

  } // namespace TreeView_Private

} // namespace gtk

#endif
