


#include <libmm-glib/mm-glib.hxx>

#include <libmm-gtk/bitset.hxx>
#include <libmm-gtk/bitset_p.hxx>


/* Copyright (C) 2020 The gtkmm Development Team
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

#include <gtk/gtk.h>

namespace Gtk
{

auto Bitset::begin() const -> const_iterator
{
  return {gobj(), false};
}

auto Bitset::end() const -> const_iterator
{
  return {gobj(), true};
}

} // namespace Gtk

namespace
{
} // anonymous namespace


/* Why reinterpret_cast<Bitset*>(gobject) is needed:
 *
 * A Bitset instance is in fact always a GtkBitset instance.
 * Unfortunately, GtkBitset cannot be a member of Bitset,
 * because it is an opaque struct.  Also, the C interface does not provide
 * any hooks to install a destroy notification handler, thus we cannot
 * wrap it dynamically either.
 *
 * The cast works because Bitset does not have any member data, and
 * it is impossible to derive from it.  This is ensured by using final on the
 * class and by using = delete on the default constructor.
 */

namespace Glib
{

auto wrap(GtkBitset* object, const bool take_copy) -> RefPtr<Gtk::Bitset>
{
  if(take_copy && object)
    gtk_bitset_ref(object);

  // See the comment at the top of this file, if you want to know why the cast works.
  return Glib::make_refptr_for_instance<Gtk::Bitset>(reinterpret_cast<Gtk::Bitset*>(object));
}

} // namespace Glib


namespace Gtk
{

auto Bitset::reference () const -> void
{
  // See the comment at the top of this file, if you want to know why the cast works.
  gtk_bitset_ref(reinterpret_cast<GtkBitset*>(const_cast<Bitset*>(this)));
}

auto Bitset::unreference () const -> void
{
  // See the comment at the top of this file, if you want to know why the cast works.
  gtk_bitset_unref(reinterpret_cast<GtkBitset*>(const_cast<Bitset*>(this)));
}

auto Bitset::gobj() -> GtkBitset*
{
  // See the comment at the top of this file, if you want to know why the cast works.
  return reinterpret_cast<GtkBitset*>(this);
}

auto Bitset::gobj() const -> const GtkBitset*
{
  // See the comment at the top of this file, if you want to know why the cast works.
  return reinterpret_cast<const GtkBitset*>(this);
}

auto Bitset::gobj_copy() const -> GtkBitset*
{
  // See the comment at the top of this file, if you want to know why the cast works.
  const auto gobject = reinterpret_cast<GtkBitset*>(const_cast<Bitset*>(this));
  gtk_bitset_ref(gobject);
  return gobject;
}


auto Bitset::create() -> Glib::RefPtr<Bitset>
{
  return Glib::wrap(gtk_bitset_new_empty());
}

auto Bitset::contains(
  const guint value) const -> bool
{
  return gtk_bitset_contains(gobj(), value);
}

auto Bitset::is_empty() const -> bool
{
  return gtk_bitset_is_empty(gobj());
}

auto Bitset::get_size() const -> guint64
{
  return gtk_bitset_get_size(gobj());
}

auto Bitset::get_size(
  const guint first, const guint last) const -> guint64
{
  return gtk_bitset_get_size_in_range(gobj(), first, last);
}

auto Bitset::get_nth(
  const guint nth) const -> guint
{
  return gtk_bitset_get_nth(gobj(), nth);
}

auto Bitset::equals(const Glib::RefPtr<const Bitset>& other) const -> bool
{
  return gtk_bitset_equals(gobj(), Glib::unwrap(other));
}

auto Bitset::get_minimum() const -> guint
{
  return gtk_bitset_get_minimum(gobj());
}

auto Bitset::get_maximum() const -> guint
{
  return gtk_bitset_get_maximum(gobj());
}

auto Bitset::copy() const -> Glib::RefPtr<Bitset>
{
  return Glib::wrap(gtk_bitset_copy(gobj()));
}

auto Bitset::remove_all () -> void
{
  gtk_bitset_remove_all(gobj());
}

auto Bitset::add(
  const guint value) -> bool
{
  return gtk_bitset_add(gobj(), value);
}

auto Bitset::remove(
  const guint value) -> bool
{
  return gtk_bitset_remove(gobj(), value);
}

auto Bitset::add_range (
  const guint start, const guint n_items) -> void
{
  gtk_bitset_add_range(gobj(), start, n_items);
}

auto Bitset::remove_range (
  const guint start, const guint n_items) -> void
{
  gtk_bitset_remove_range(gobj(), start, n_items);
}

auto Bitset::add_range_closed (
  const guint first, const guint last) -> void
{
  gtk_bitset_add_range_closed(gobj(), first, last);
}

auto Bitset::remove_range_closed (
  const guint first, const guint last) -> void
{
  gtk_bitset_remove_range_closed(gobj(), first, last);
}

auto Bitset::add_rectangle (
  const guint start, const guint width, const guint height, const guint stride) -> void
{
  gtk_bitset_add_rectangle(gobj(), start, width, height, stride);
}

auto Bitset::remove_rectangle (
  const guint start, const guint width, const guint height, const guint stride) -> void
{
  gtk_bitset_remove_rectangle(gobj(), start, width, height, stride);
}

auto Bitset::join (const Glib::RefPtr <const Bitset> &other) -> void
{
  gtk_bitset_union(gobj(), Glib::unwrap(other));
}

auto Bitset::intersect (const Glib::RefPtr <const Bitset> &other) -> void
{
  gtk_bitset_intersect(gobj(), Glib::unwrap(other));
}

auto Bitset::subtract (const Glib::RefPtr <const Bitset> &other) -> void
{
  gtk_bitset_subtract(gobj(), Glib::unwrap(other));
}

auto Bitset::difference (const Glib::RefPtr <const Bitset> &other) -> void
{
  gtk_bitset_difference(gobj(), Glib::unwrap(other));
}

auto Bitset::shift_left (
  const guint amount) -> void
{
  gtk_bitset_shift_left(gobj(), amount);
}

auto Bitset::shift_right (
  const guint amount) -> void
{
  gtk_bitset_shift_right(gobj(), amount);
}

auto Bitset::splice (
  const guint position, const guint removed, const guint value) -> void
{
  gtk_bitset_splice(gobj(), position, removed, value);
}


} // namespace Gtk


