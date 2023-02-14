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

  class GTKMM_API Bitset final
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    using CppObjectType = Bitset;
    using BaseObjectType = GtkBitset;
#endif

    void
    reference () const;

    void
    unreference () const;

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
    void
    operator delete (void*, std::size_t);

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

    void
    remove_all ();

    auto
    add (guint value) -> bool;

    auto
    remove (guint value) -> bool;

    void
    add_range (guint start, guint n_items);

    void
    remove_range (guint start, guint n_items);

    void
    add_range_closed (guint first, guint last);

    void
    remove_range_closed (guint first, guint last);

    void
    add_rectangle (guint start, guint width, guint height, guint stride);

    void
    remove_rectangle (guint start, guint width, guint height, guint stride);

    void
    join (const Glib::RefPtr<const Bitset>& other);

    void
    intersect (const Glib::RefPtr<const Bitset>& other);

    void
    subtract (const Glib::RefPtr<const Bitset>& other);

    void
    difference (const Glib::RefPtr<const Bitset>& other);

    void
    shift_left (guint amount);

    void
    shift_right (guint amount);

    void
    splice (guint position, guint removed, guint value);
  };

} // namespace Gtk

namespace Glib
{

  GTKMM_API
  auto
  wrap (GtkBitset* object, bool take_copy = false) -> Glib::RefPtr<Gtk::Bitset>;

} // namespace Glib

#endif
