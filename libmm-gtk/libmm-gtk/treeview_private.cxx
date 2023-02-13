/* Copyright(C) 2001-2002 The gtkmm Development Team
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or(at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 */

#include <libmm-glib/mm-glib.hpp>
#include <libmm-gtk/treeview_private.hpp>


namespace Gtk::TreeView_Private
{

auto SignalProxy_CellData_gtk_callback (
  GtkTreeViewColumn *, GtkCellRenderer *cell,
  GtkTreeModel *model, GtkTreeIter *iter, void *data) -> void
{
  if(!model)
    g_warning("SignalProxy_CellData_gtk_callback(): model is NULL, which is unusual.\n");

  const TreeViewColumn::SlotTreeCellData* the_slot = static_cast<TreeViewColumn::SlotTreeCellData*>(data);

  try
  {
    // use Slot::operator()
    auto cppiter = TreeModel::iterator(model, iter);
    if(!cppiter.get_model_gobject())
    {
      g_warning("SignalProxy_CellData_gtk_callback() The cppiter has no model\n");
      return;
    }

    (*the_slot)(Glib::wrap(cell, false), cppiter);
  }
  catch(...)
  {
    Glib::exception_handlers_invoke();
  }
}

auto SignalProxy_CellData_gtk_callback_destroy (void *data) -> void
{
  delete static_cast<TreeViewColumn::SlotTreeCellData*>(data);
}


auto SignalProxy_RowSeparator_gtk_callback(GtkTreeModel* model, GtkTreeIter* iter, void* data) -> gboolean
{
  const TreeView::SlotRowSeparator* the_slot = static_cast<TreeView::SlotRowSeparator*>(data);

  try
  {
    return (*the_slot)(Glib::wrap(model, true), TreeModel::iterator(model, iter));
  }
  catch(...)
  {
    Glib::exception_handlers_invoke();
  }

  return 0; // arbitrary value
}

auto SignalProxy_RowSeparator_gtk_callback_destroy (void *data) -> void
{
  delete static_cast<TreeView::SlotRowSeparator*>(data);
}

} // namespace Gtk
