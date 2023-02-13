#ifndef _GTKMM_TREEVIEW_PRIVATE_H
#define _GTKMM_TREEVIEW_PRIVATE_H
/* $Id$ */


/* treeview.h
 *
 * Copyright(C) 2001-2002 The gtkmm Development Team
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

#include <libmm-gtk/treeviewcolumn.hxx>
#include <libmm-gtk/treeview.hxx>

namespace Gtk::TreeView_Private
{

GTKMM_API
void SignalProxy_CellData_gtk_callback(GtkTreeViewColumn*, GtkCellRenderer* cell,
                           GtkTreeModel* model, GtkTreeIter* iter, void* data);
GTKMM_API
void SignalProxy_CellData_gtk_callback_destroy(void* data);

GTKMM_API
auto SignalProxy_RowSeparator_gtk_callback(GtkTreeModel* model, GtkTreeIter* iter, void* data) -> gboolean;
GTKMM_API
void SignalProxy_RowSeparator_gtk_callback_destroy(void* data);


} /* namespace Gtk */


#endif /* _GTKMM_TREEVIEW_PRIVATE_H */