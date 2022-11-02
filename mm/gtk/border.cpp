// Generated by gmmproc 2.74.0 -- DO NOT MODIFY!


#include <mm/glib/mm-glib.hpp>

#include <mm/gtk/border.hpp>
#include <mm/gtk/private/border_p.hpp>


/*
 * Copyright 2009 The gtkmm Development Team
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

#include <gtk/gtk.h>

namespace
{
} // anonymous namespace


namespace Glib
{

auto wrap(GtkBorder* object, bool take_copy) -> Gtk::Border
{
  return Gtk::Border(object, take_copy);
}

} // namespace Glib


namespace Gtk
{


// static
auto Border::get_type() -> GType
{
  return gtk_border_get_type();
}

Border::Border()
:
  gobject_ (gtk_border_new())
{}

Border::Border(const Border& other)
:
  gobject_ ((other.gobject_) ? gtk_border_copy(other.gobject_) : nullptr)
{}

Border::Border(Border&& other) noexcept
:
  gobject_(other.gobject_)
{
  other.gobject_ = nullptr;
}

auto Border::operator=(Border&& other) noexcept -> Border&
{
  Border temp (std::move(other));
  swap(temp);
  return *this;
}

Border::Border(GtkBorder* gobject, bool make_a_copy)
:
  // For BoxedType wrappers, make_a_copy is true by default.  The static
  // BoxedType wrappers must always take a copy, thus make_a_copy = true
  // ensures identical behaviour if the default argument is used.
  gobject_ ((make_a_copy && gobject) ? gtk_border_copy(gobject) : gobject)
{}

auto Border::operator=(const Border& other) -> Border&
{
  Border temp (other);
  swap(temp);
  return *this;
}

Border::~Border() noexcept
{
  if(gobject_)
    gtk_border_free(gobject_);
}

void Border::swap(Border& other) noexcept
{
  std::swap(gobject_, other.gobject_);
}

auto Border::gobj_copy() const -> GtkBorder*
{
  return gtk_border_copy(gobject_);
}


auto Border::get_left() const -> int
{
  return gobj()->left;
}

void Border::set_left(const int& value)
{
  gobj()->left = value;
}

auto Border::get_right() const -> int
{
  return gobj()->right;
}

void Border::set_right(const int& value)
{
  gobj()->right = value;
}

auto Border::get_top() const -> int
{
  return gobj()->top;
}

void Border::set_top(const int& value)
{
  gobj()->top = value;
}

auto Border::get_bottom() const -> int
{
  return gobj()->bottom;
}

void Border::set_bottom(const int& value)
{
  gobj()->bottom = value;
}


} // namespace Gtk


