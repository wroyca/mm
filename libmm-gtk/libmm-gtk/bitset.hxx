// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_BITSET_H
#define _GTKMM_BITSET_H

#include <libmm-gtk/mm-gtkconfig.hxx>

#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm-glib/refptr.hxx>
#include <libmm-gtk/bitsetconstiter.hxx>

extern "C" typedef struct _GtkBitset GtkBitset;

namespace Gtk
{

  class LIBMM_GTK_SYMEXPORT Bitset final
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    using CppObjectType = Bitset;
    using BaseObjectType = GtkBitset;
#endif

    auto
    reference () const -> void;

    auto
    unreference () const -> void;

    auto
    gobj () -> GtkBitset*;

    auto
    gobj () const -> const GtkBitset*;

    auto
    gobj_copy () const -> GtkBitset*;

    Bitset () = delete;

    Bitset (const Bitset&) = delete;
    auto
    operator= (const Bitset&) -> Bitset& = delete;

  protected:
    auto
    operator delete (void*, std::size_t) -> void;

  private:
  public:
    using const_iterator = BitsetConstIter;

    auto
    begin () const -> const_iterator;
    auto
    end () const -> const_iterator;

    auto
    cbegin () const -> const_iterator
    {
      return begin ();
    }

    auto
    cend () const -> const_iterator
    {
      return end ();
    }

    static auto
    create () -> Glib::RefPtr<Bitset>;

    auto
    contains (guint value) const -> bool;

    auto
    is_empty () const -> bool;

    auto
    get_size () const -> guint64;

    auto
    get_size (guint first, guint last) const -> guint64;

    auto
    get_nth (guint nth) const -> guint;

    auto
    equals (const Glib::RefPtr<const Bitset>& other) const -> bool;

    auto
    get_minimum () const -> guint;

    auto
    get_maximum () const -> guint;

    auto
    copy () const -> Glib::RefPtr<Bitset>;

    auto
    remove_all () -> void;

    auto
    add (guint value) -> bool;

    auto
    remove (guint value) -> bool;

    auto
    add_range (guint start, guint n_items) -> void;

    auto
    remove_range (guint start, guint n_items) -> void;

    auto
    add_range_closed (guint first, guint last) -> void;

    auto
    remove_range_closed (guint first, guint last) -> void;

    auto
    add_rectangle (guint start, guint width, guint height, guint stride)
        -> void;

    auto
    remove_rectangle (guint start, guint width, guint height, guint stride)
        -> void;

    auto
    join (const Glib::RefPtr<const Bitset>& other) -> void;

    auto
    intersect (const Glib::RefPtr<const Bitset>& other) -> void;

    auto
    subtract (const Glib::RefPtr<const Bitset>& other) -> void;

    auto
    difference (const Glib::RefPtr<const Bitset>& other) -> void;

    auto
    shift_left (guint amount) -> void;

    auto
    shift_right (guint amount) -> void;

    auto
    splice (guint position, guint removed, guint value) -> void;
  };

} // namespace Gtk

namespace Glib
{
  LIBMM_GTK_SYMEXPORT auto
  wrap (GtkBitset* object, bool take_copy = false) -> Glib::RefPtr<Gtk::Bitset>;

} // namespace Glib

#endif
