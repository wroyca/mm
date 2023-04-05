// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/gtk/bitsetconstiter.hxx>

namespace gtk
{

  BitsetConstIter::BitsetConstIter (const GtkBitset* bitset, bool is_end)
    : gobject_ (std::make_unique<GtkBitsetIter> ()),
      bitset_ (bitset),
      is_end_ (is_end)
  {
    if (is_end_)
    {
      if (gtk_bitset_iter_init_last (gobject_.get (), bitset_, nullptr))
        gtk_bitset_iter_next (gobject_.get (), nullptr);
    }
    else

        if (!gtk_bitset_iter_init_first (gobject_.get (), bitset_, nullptr))

      is_end_ = true;
  }

  BitsetConstIter::BitsetConstIter (const BitsetConstIter& other)
    : gobject_ (other.gobject_ ? std::make_unique<GtkBitsetIter> () : nullptr),
      bitset_ (other.bitset_),
      is_end_ (other.is_end_)
  {
    if (other.gobject_)
    {
      if (gtk_bitset_iter_is_valid (other.gobject_.get ()))
        gtk_bitset_iter_init_at (
            gobject_.get (),
            bitset_,
            gtk_bitset_iter_get_value (other.gobject_.get ()),
            nullptr);
      else

          if (gtk_bitset_iter_init_last (gobject_.get (), bitset_, nullptr))
        gtk_bitset_iter_next (gobject_.get (), nullptr);
    }
  }

  auto
  BitsetConstIter::operator= (const BitsetConstIter& other) -> BitsetConstIter&
  {
    if (&other == this)
      return *this;

    gobject_ = other.gobject_ ? std::make_unique<GtkBitsetIter> () : nullptr;
    bitset_ = other.bitset_;
    is_end_ = other.is_end_;

    if (other.gobject_)
    {
      if (gtk_bitset_iter_is_valid (other.gobject_.get ()))
        gtk_bitset_iter_init_at (
            gobject_.get (),
            bitset_,
            gtk_bitset_iter_get_value (other.gobject_.get ()),
            nullptr);
      else

          if (gtk_bitset_iter_init_last (gobject_.get (), bitset_, nullptr))
        gtk_bitset_iter_next (gobject_.get (), nullptr);
    }
    return *this;
  }

  BitsetConstIter::BitsetConstIter (BitsetConstIter&& other) noexcept
    : gobject_ (std::move (other.gobject_)),
      bitset_ (other.bitset_),
      is_end_ (other.is_end_)
  {
    other.bitset_ = nullptr;
    other.is_end_ = true;
  }

  auto
  BitsetConstIter::operator= (BitsetConstIter&& other) noexcept -> BitsetConstIter&
  {
    gobject_ = std::move (other.gobject_);
    bitset_ = other.bitset_;
    is_end_ = other.is_end_;
    other.bitset_ = nullptr;
    other.is_end_ = true;
    return *this;
  }

  auto
  BitsetConstIter::operator++ () -> BitsetConstIter&
  {
    if (!(gobject_ && bitset_ && !is_end_))
      return *this;

    if (!gtk_bitset_iter_next (gobject_.get (), nullptr))
      is_end_ = true;

    return *this;
  }

  auto
  BitsetConstIter::operator++ (int) -> BitsetConstIter
  {
    if (!(gobject_ && bitset_ && !is_end_))
      return *this;

    BitsetConstIter orig (*this);

    if (!gtk_bitset_iter_next (gobject_.get (), nullptr))
      is_end_ = true;

    return orig;
  }

  auto
  BitsetConstIter::operator-- () -> BitsetConstIter&
  {
    if (!(gobject_ && bitset_))
      return *this;

    if (is_end_)
    {
      if (gtk_bitset_iter_init_last (gobject_.get (), bitset_, nullptr))
        is_end_ = false;
    }
    else
      gtk_bitset_iter_previous (gobject_.get (), nullptr);

    return *this;
  }

  auto
  BitsetConstIter::operator-- (int) -> BitsetConstIter
  {
    if (!(gobject_ && bitset_))
      return *this;

    BitsetConstIter orig (*this);

    if (is_end_)
    {
      if (gtk_bitset_iter_init_last (gobject_.get (), bitset_, nullptr))
        is_end_ = false;
    }
    else
      gtk_bitset_iter_previous (gobject_.get (), nullptr);

    return orig;
  }

  auto
  BitsetConstIter::operator* () const -> BitsetConstIter::reference
  {
    if (!(gobject_ && bitset_ && !is_end_))
      return 0;

    return gtk_bitset_iter_get_value (gobject_.get ());
  }

  BitsetConstIter::operator bool () const noexcept
  {
    if (!(gobject_ && bitset_ && !is_end_))
      return false;

    return gtk_bitset_iter_is_valid (gobject_.get ());
  }

  auto
  BitsetConstIter::equal (const BitsetConstIter& other) const noexcept -> bool
  {
    if (is_end_ != other.is_end_ || bitset_ != other.bitset_)
      return false;

    if (!gobject_ && !other.gobject_)
      return true;

    if (!gobject_ || !other.gobject_)
      return false;

    if (gtk_bitset_iter_is_valid (gobject_.get ()) !=
        gtk_bitset_iter_is_valid (other.gobject_.get ()))
      return false;

    return gtk_bitset_iter_get_value (gobject_.get ()) ==
           gtk_bitset_iter_get_value (other.gobject_.get ());
  }

} // namespace gtk
