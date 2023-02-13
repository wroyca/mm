/* $Id$ */

/* Copyright (c) 2002 The gtkmm Development Team
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

#include <libmm-gtk/treemodelcolumn.hpp>


namespace Gtk
{

/**** Gtk::TreeModelColumnRecord *******************************************/

TreeModelColumnRecord::TreeModelColumnRecord()
:
  column_types_ ()
{}

TreeModelColumnRecord::~TreeModelColumnRecord() noexcept = default;

auto TreeModelColumnRecord::add (TreeModelColumnBase &column) -> void
{
  g_return_if_fail(column.index_ == -1); //Check that it hasn't been set before.

  column.index_ = column_types_.size();
  column_types_.push_back(column.type_);
}

auto TreeModelColumnRecord::size() const -> unsigned int
{
  return column_types_.size();
}

auto TreeModelColumnRecord::types() const -> const GType*
{
  g_return_val_if_fail(!column_types_.empty(), 0);

  // According to Josuttis' book, &vector.front() to get a builtin array is
  // quasi-standard. It should work fine with any std::vector implementation.
  return &column_types_.front();
}


/**** Gtk::TreeModelColumnBase *********************************************/

TreeModelColumnBase::TreeModelColumnBase(const GType g_type)
:
  type_  (g_type),
  index_ (-1) //default to an invalid index.
{}

} // namespace Gtk

