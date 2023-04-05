// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_BITSETCONSTITER_H
#define _GTKMM_BITSETCONSTITER_H

#include <gtk/gtk.h>
#include <iterator>
#include <libmm/gtk/mm-gtkconfig.hxx>
#include <memory>

namespace gtk
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
    LIBMM_GTK_SYMEXPORT
    BitsetConstIter () {}

    LIBMM_GTK_SYMEXPORT
    BitsetConstIter (const GtkBitset* bitset, bool is_end);
#endif

    LIBMM_GTK_SYMEXPORT
    BitsetConstIter (const BitsetConstIter& other);
    LIBMM_GTK_SYMEXPORT auto
    operator= (const BitsetConstIter& other) -> BitsetConstIter&;
    LIBMM_GTK_SYMEXPORT
    BitsetConstIter (BitsetConstIter&& other) noexcept;
    LIBMM_GTK_SYMEXPORT auto
    operator= (BitsetConstIter&& other) noexcept -> BitsetConstIter&;

    LIBMM_GTK_SYMEXPORT auto
    operator++ () -> BitsetConstIter&;
    LIBMM_GTK_SYMEXPORT auto
    operator++ (int) -> BitsetConstIter;
    LIBMM_GTK_SYMEXPORT auto
    operator-- () -> BitsetConstIter&;
    LIBMM_GTK_SYMEXPORT auto
    operator-- (int) -> BitsetConstIter;
    LIBMM_GTK_SYMEXPORT auto
    operator* () const -> reference;

    LIBMM_GTK_SYMEXPORT explicit operator bool () const noexcept;

    LIBMM_GTK_SYMEXPORT auto
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

} // namespace gtk

#endif
