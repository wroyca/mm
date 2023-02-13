/* Copyright (C) 2021 The gtkmm Development Team
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library. If not, see <http://www.gnu.org/licenses/>.
 */

#include <libmm-gtk/selectionlistmodelimpl.hxx>
#include <utility> // std::move()

namespace Gtk
{
SelectionListModelImpl::SelectionListModelImpl(GObject* castitem)
: ObjectBase(nullptr),
  Object(castitem)
{}

SelectionListModelImpl::SelectionListModelImpl(SelectionListModelImpl&& src) noexcept
: ListModel(std::move(src)),
  SelectionModel(std::move(src)),
  Object(std::move(src))
{}

auto SelectionListModelImpl::operator=(SelectionListModelImpl&& src) noexcept -> SelectionListModelImpl&
{
  ListModel::operator=(std::move(src));
  SelectionModel::operator=(std::move(src));
  Object::operator=(std::move(src));
  return *this;
}

SelectionListModelImpl::~SelectionListModelImpl() noexcept = default;
} // namespace Gtk
