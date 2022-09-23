// Generated by gmmproc 2.74.0 -- DO NOT MODIFY!


#include <glibmm.h>

#include <gtkmm/bitset.h>
#include <gtkmm/private/bitset_p.h>


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

Bitset::const_iterator Bitset::begin() const
{
  return BitsetConstIter(gobj(), false);
}

Bitset::const_iterator Bitset::end() const
{
  return BitsetConstIter(gobj(), true);
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

Glib::RefPtr<Gtk::Bitset> wrap(GtkBitset* object, bool take_copy)
{
  if(take_copy && object)
    gtk_bitset_ref(object);

  // See the comment at the top of this file, if you want to know why the cast works.
  return Glib::make_refptr_for_instance<Gtk::Bitset>(reinterpret_cast<Gtk::Bitset*>(object));
}

} // namespace Glib


namespace Gtk
{

void Bitset::reference() const
{
  // See the comment at the top of this file, if you want to know why the cast works.
  gtk_bitset_ref(reinterpret_cast<GtkBitset*>(const_cast<Bitset*>(this)));
}

void Bitset::unreference() const
{
  // See the comment at the top of this file, if you want to know why the cast works.
  gtk_bitset_unref(reinterpret_cast<GtkBitset*>(const_cast<Bitset*>(this)));
}

GtkBitset* Bitset::gobj()
{
  // See the comment at the top of this file, if you want to know why the cast works.
  return reinterpret_cast<GtkBitset*>(this);
}

const GtkBitset* Bitset::gobj() const
{
  // See the comment at the top of this file, if you want to know why the cast works.
  return reinterpret_cast<const GtkBitset*>(this);
}

GtkBitset* Bitset::gobj_copy() const
{
  // See the comment at the top of this file, if you want to know why the cast works.
  const auto gobject = reinterpret_cast<GtkBitset*>(const_cast<Bitset*>(this));
  gtk_bitset_ref(gobject);
  return gobject;
}


Glib::RefPtr<Bitset> Bitset::create()
{
  return Glib::wrap(gtk_bitset_new_empty());
}

bool Bitset::contains(guint value) const
{
  return gtk_bitset_contains(const_cast<GtkBitset*>(gobj()), value);
}

bool Bitset::is_empty() const
{
  return gtk_bitset_is_empty(const_cast<GtkBitset*>(gobj()));
}

guint64 Bitset::get_size() const
{
  return gtk_bitset_get_size(const_cast<GtkBitset*>(gobj()));
}

guint64 Bitset::get_size(guint first, guint last) const
{
  return gtk_bitset_get_size_in_range(const_cast<GtkBitset*>(gobj()), first, last);
}

guint Bitset::get_nth(guint nth) const
{
  return gtk_bitset_get_nth(const_cast<GtkBitset*>(gobj()), nth);
}

bool Bitset::equals(const Glib::RefPtr<const Bitset>& other) const
{
  return gtk_bitset_equals(const_cast<GtkBitset*>(gobj()), Glib::unwrap(other));
}

guint Bitset::get_minimum() const
{
  return gtk_bitset_get_minimum(const_cast<GtkBitset*>(gobj()));
}

guint Bitset::get_maximum() const
{
  return gtk_bitset_get_maximum(const_cast<GtkBitset*>(gobj()));
}

Glib::RefPtr<Bitset> Bitset::copy() const
{
  return Glib::wrap(gtk_bitset_copy(const_cast<GtkBitset*>(gobj())));
}

void Bitset::remove_all()
{
  gtk_bitset_remove_all(gobj());
}

bool Bitset::add(guint value)
{
  return gtk_bitset_add(gobj(), value);
}

bool Bitset::remove(guint value)
{
  return gtk_bitset_remove(gobj(), value);
}

void Bitset::add_range(guint start, guint n_items)
{
  gtk_bitset_add_range(gobj(), start, n_items);
}

void Bitset::remove_range(guint start, guint n_items)
{
  gtk_bitset_remove_range(gobj(), start, n_items);
}

void Bitset::add_range_closed(guint first, guint last)
{
  gtk_bitset_add_range_closed(gobj(), first, last);
}

void Bitset::remove_range_closed(guint first, guint last)
{
  gtk_bitset_remove_range_closed(gobj(), first, last);
}

void Bitset::add_rectangle(guint start, guint width, guint height, guint stride)
{
  gtk_bitset_add_rectangle(gobj(), start, width, height, stride);
}

void Bitset::remove_rectangle(guint start, guint width, guint height, guint stride)
{
  gtk_bitset_remove_rectangle(gobj(), start, width, height, stride);
}

void Bitset::join(const Glib::RefPtr<const Bitset>& other)
{
  gtk_bitset_union(gobj(), Glib::unwrap(other));
}

void Bitset::intersect(const Glib::RefPtr<const Bitset>& other)
{
  gtk_bitset_intersect(gobj(), Glib::unwrap(other));
}

void Bitset::subtract(const Glib::RefPtr<const Bitset>& other)
{
  gtk_bitset_subtract(gobj(), Glib::unwrap(other));
}

void Bitset::difference(const Glib::RefPtr<const Bitset>& other)
{
  gtk_bitset_difference(gobj(), Glib::unwrap(other));
}

void Bitset::shift_left(guint amount)
{
  gtk_bitset_shift_left(gobj(), amount);
}

void Bitset::shift_right(guint amount)
{
  gtk_bitset_shift_right(gobj(), amount);
}

void Bitset::splice(guint position, guint removed, guint value)
{
  gtk_bitset_splice(gobj(), position, removed, value);
}


} // namespace Gtk


