/* $Id$ */

/* Copyright(C) 2003 The gtkmm Development Team
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

#include <libmm-gtk/cellrenderer_generation.hxx>


//template specializations:

namespace Gtk::CellRenderer_Generation
{

template<>
auto generate_cellrenderer< Glib::RefPtr<Gdk::Pixbuf> >(bool /*editable*/) -> CellRenderer*
{
  //Ignore editable because there is no way for the user to edit a Pixbuf.
  return new CellRendererPixbuf();
}

template<>
auto generate_cellrenderer<bool>(
  const bool editable) -> CellRenderer*
{
  CellRendererToggle* pCellRenderer = new CellRendererToggle();

  //GTK+'s "activatable" really means "editable":
  pCellRenderer->property_activatable() = editable;

  return pCellRenderer;
}

template<>
auto generate_cellrenderer<AccelKey>(
  const bool editable) -> CellRenderer*
{
  CellRendererAccel* pCellRenderer = new CellRendererAccel();

  //GTK+'s "editable" really means "editable":
  pCellRenderer->property_editable() = editable;

  return pCellRenderer;
}

} //namespace Gtk
