

#include <libmm-glib/mm-glib.hxx>

#include <libmm-gtk/bitset.hxx>
#include <libmm-gtk/bitset_p.hxx>

#include <gtk/gtk.h>

namespace Gtk
{

  auto
  Bitset::begin () const -> const_iterator
  {
    return {gobj (), false};
  }

  auto
  Bitset::end () const -> const_iterator
  {
    return {gobj (), true};
  }

} // namespace Gtk

namespace
{
}

namespace Glib
{

  auto
  wrap (GtkBitset* object, const bool take_copy) -> RefPtr<Gtk::Bitset>
  {
    if (take_copy && object)
      gtk_bitset_ref (object);

    return Glib::make_refptr_for_instance<Gtk::Bitset> (
        reinterpret_cast<Gtk::Bitset*> (object));
  }

} // namespace Glib

namespace Gtk
{

  auto
  Bitset::reference () const -> void
  {
    gtk_bitset_ref (reinterpret_cast<GtkBitset*> (const_cast<Bitset*> (this)));
  }

  auto
  Bitset::unreference () const -> void
  {
    gtk_bitset_unref (
        reinterpret_cast<GtkBitset*> (const_cast<Bitset*> (this)));
  }

  auto
  Bitset::gobj () -> GtkBitset*
  {
    return reinterpret_cast<GtkBitset*> (this);
  }

  auto
  Bitset::gobj () const -> const GtkBitset*
  {
    return reinterpret_cast<const GtkBitset*> (this);
  }

  auto
  Bitset::gobj_copy () const -> GtkBitset*
  {
    const auto gobject =
        reinterpret_cast<GtkBitset*> (const_cast<Bitset*> (this));
    gtk_bitset_ref (gobject);
    return gobject;
  }

  auto
  Bitset::create () -> Glib::RefPtr<Bitset>
  {
    return Glib::wrap (gtk_bitset_new_empty ());
  }

  auto
  Bitset::contains (const guint value) const -> bool
  {
    return gtk_bitset_contains (gobj (), value);
  }

  auto
  Bitset::is_empty () const -> bool
  {
    return gtk_bitset_is_empty (gobj ());
  }

  auto
  Bitset::get_size () const -> guint64
  {
    return gtk_bitset_get_size (gobj ());
  }

  auto
  Bitset::get_size (const guint first, const guint last) const -> guint64
  {
    return gtk_bitset_get_size_in_range (gobj (), first, last);
  }

  auto
  Bitset::get_nth (const guint nth) const -> guint
  {
    return gtk_bitset_get_nth (gobj (), nth);
  }

  auto
  Bitset::equals (const Glib::RefPtr<const Bitset>& other) const -> bool
  {
    return gtk_bitset_equals (gobj (), Glib::unwrap (other));
  }

  auto
  Bitset::get_minimum () const -> guint
  {
    return gtk_bitset_get_minimum (gobj ());
  }

  auto
  Bitset::get_maximum () const -> guint
  {
    return gtk_bitset_get_maximum (gobj ());
  }

  auto
  Bitset::copy () const -> Glib::RefPtr<Bitset>
  {
    return Glib::wrap (gtk_bitset_copy (gobj ()));
  }

  auto
  Bitset::remove_all () -> void
  {
    gtk_bitset_remove_all (gobj ());
  }

  auto
  Bitset::add (const guint value) -> bool
  {
    return gtk_bitset_add (gobj (), value);
  }

  auto
  Bitset::remove (const guint value) -> bool
  {
    return gtk_bitset_remove (gobj (), value);
  }

  auto
  Bitset::add_range (const guint start, const guint n_items) -> void
  {
    gtk_bitset_add_range (gobj (), start, n_items);
  }

  auto
  Bitset::remove_range (const guint start, const guint n_items) -> void
  {
    gtk_bitset_remove_range (gobj (), start, n_items);
  }

  auto
  Bitset::add_range_closed (const guint first, const guint last) -> void
  {
    gtk_bitset_add_range_closed (gobj (), first, last);
  }

  auto
  Bitset::remove_range_closed (const guint first, const guint last) -> void
  {
    gtk_bitset_remove_range_closed (gobj (), first, last);
  }

  auto
  Bitset::add_rectangle (const guint start,
                         const guint width,
                         const guint height,
                         const guint stride) -> void
  {
    gtk_bitset_add_rectangle (gobj (), start, width, height, stride);
  }

  auto
  Bitset::remove_rectangle (const guint start,
                            const guint width,
                            const guint height,
                            const guint stride) -> void
  {
    gtk_bitset_remove_rectangle (gobj (), start, width, height, stride);
  }

  auto
  Bitset::join (const Glib::RefPtr<const Bitset>& other) -> void
  {
    gtk_bitset_union (gobj (), Glib::unwrap (other));
  }

  auto
  Bitset::intersect (const Glib::RefPtr<const Bitset>& other) -> void
  {
    gtk_bitset_intersect (gobj (), Glib::unwrap (other));
  }

  auto
  Bitset::subtract (const Glib::RefPtr<const Bitset>& other) -> void
  {
    gtk_bitset_subtract (gobj (), Glib::unwrap (other));
  }

  auto
  Bitset::difference (const Glib::RefPtr<const Bitset>& other) -> void
  {
    gtk_bitset_difference (gobj (), Glib::unwrap (other));
  }

  auto
  Bitset::shift_left (const guint amount) -> void
  {
    gtk_bitset_shift_left (gobj (), amount);
  }

  auto
  Bitset::shift_right (const guint amount) -> void
  {
    gtk_bitset_shift_right (gobj (), amount);
  }

  auto
  Bitset::splice (const guint position, const guint removed, const guint value) -> void
  {
    gtk_bitset_splice (gobj (), position, removed, value);
  }

} // namespace Gtk
