// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_BITSETCONSTITER_H
#define _GTKMM_BITSETCONSTITER_H

#include <gtk/gtk.h>
#include <iterator>
#include <libmm-gtk/mm-gtkconfig.hxx>
#include <memory>

namespace Gtk
{

  class BitsetConstIter
  {
  public:
    using iterator_category = std::bidirectional_iterator_tag;
    using value_type = guint;
    using difference_type = int;
    using reference = value_type;
    using pointer = void;

#ifndef DOXYGEN_SHOULD_SKIP_THIS
    GTKMM_API
    BitsetConstIter () {}

    GTKMM_API
    BitsetConstIter (const GtkBitset* bitset, bool is_end);
#endif

    GTKMM_API
    BitsetConstIter (const BitsetConstIter& other);
    GTKMM_API auto
    operator= (const BitsetConstIter& other) -> BitsetConstIter&;
    GTKMM_API
    BitsetConstIter (BitsetConstIter&& other) noexcept;
    GTKMM_API auto
    operator= (BitsetConstIter&& other) noexcept -> BitsetConstIter&;

    GTKMM_API auto
    operator++ () -> BitsetConstIter&;
    GTKMM_API auto
    operator++ (int) -> BitsetConstIter;
    GTKMM_API auto
    operator-- () -> BitsetConstIter&;
    GTKMM_API auto
    operator-- (int) -> BitsetConstIter;
    GTKMM_API auto
    operator* () const -> reference;

    GTKMM_API explicit operator bool () const noexcept;

    GTKMM_API auto
    equal (const BitsetConstIter& other) const noexcept -> bool;

  private:
    std::unique_ptr<GtkBitsetIter> gobject_;

    const GtkBitset* bitset_ = nullptr;
    bool is_end_ = true;
  };

  inline auto
  operator== (const BitsetConstIter& lhs, const BitsetConstIter& rhs) -> bool
  {
    return lhs.equal (rhs);
  }

  inline auto
  operator!= (const BitsetConstIter& lhs, const BitsetConstIter& rhs) -> bool
  {
    return !lhs.equal (rhs);
  }

} // namespace Gtk

#endif
