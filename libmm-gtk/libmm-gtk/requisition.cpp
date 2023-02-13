


#include <mm/glib/mm-glib.hpp>

#include <mm/gtk/requisition.hpp>
#include <mm/gtk/private/requisition_p.hpp>

#include <cstring> // std::memset()

/* Copyright (C) 2010 The gtkmm Development Team
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
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 */

namespace Gtk
{

Requisition::Requisition(const int width, const int height)
{
  gobject_.width  = width;
  gobject_.height = height;
}

} // namespace Gtk

namespace
{
} // anonymous namespace


namespace Glib
{

auto wrap(GtkRequisition* object) -> Gtk::Requisition&
{
  return *reinterpret_cast<Gtk::Requisition*>(object);
}

auto wrap(const GtkRequisition* object) -> const Gtk::Requisition&
{
  return *reinterpret_cast<const Gtk::Requisition*>(object);
}

} // namespace Glib


namespace Gtk
{


Requisition::Requisition(const Requisition& other) noexcept = default;

auto Requisition::operator=(const Requisition& other) noexcept -> Requisition& = default;

Requisition::Requisition(Requisition&& other) noexcept
:
  gobject_(std::move(other.gobject_))
{
  //We could wipe other.gobject_ via memset,
  //but that is not really necessary:
  //other.gobject_ = nullptr;
}

auto Requisition::operator=(Requisition&& other) noexcept -> Requisition&
{
  gobject_ = std::move(other.gobject_);
  return *this;
}

// static
auto Requisition::get_type() -> GType
{
  return gtk_requisition_get_type();
}

Requisition::Requisition()
{
  std::memset(&gobject_, 0, sizeof(GtkRequisition));
}

Requisition::Requisition(const GtkRequisition* gobject)
{
  if(gobject)
    gobject_ = *gobject;
  else
    std::memset(&gobject_, 0, sizeof(GtkRequisition));
}


auto Requisition::get_width() const -> int
{
  return gobj()->width;
}

auto Requisition::set_width (const int &value) -> void
{
  gobj()->width = value;
}

auto Requisition::get_height() const -> int
{
  return gobj()->height;
}

auto Requisition::set_height (const int &value) -> void
{
  gobj()->height = value;
}


} // namespace Gtk


