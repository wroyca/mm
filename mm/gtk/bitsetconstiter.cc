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

#include <mm/gtk/bitsetconstiter.h>

namespace Gtk
{

BitsetConstIter::BitsetConstIter(const GtkBitset* bitset, bool is_end)
: gobject_(std::make_unique<GtkBitsetIter>()),
  bitset_(bitset),
  is_end_(is_end)
{
  if (is_end_)
  {
    // Initialize gobject_.get() to an invalid iterator.
    if (gtk_bitset_iter_init_last(gobject_.get(), bitset_, nullptr))
      gtk_bitset_iter_next(gobject_.get(), nullptr);
  }
  else
    // Point to the first element in the bitset.
    if (!gtk_bitset_iter_init_first(gobject_.get(), bitset_, nullptr))
      // The bitset is empty.
      is_end_ = true;
}

BitsetConstIter::BitsetConstIter(const BitsetConstIter& other)
: gobject_(other.gobject_ ? std::make_unique<GtkBitsetIter>() : nullptr),
  bitset_(other.bitset_),
  is_end_(other.is_end_)
{
  if (other.gobject_)
  {
    if (gtk_bitset_iter_is_valid(other.gobject_.get()))
      gtk_bitset_iter_init_at(gobject_.get(), bitset_,
        gtk_bitset_iter_get_value(other.gobject_.get()), nullptr);
    else
      // other.gobject_.get() exists, but is invalid.
      // Initialize gobject_.get() to an invalid iterator.
      if (gtk_bitset_iter_init_last(gobject_.get(), bitset_, nullptr))
        gtk_bitset_iter_next(gobject_.get(), nullptr);
  }
}

auto BitsetConstIter::operator=(const BitsetConstIter& other) -> BitsetConstIter&
{
  if (&other == this)
    return *this;

  gobject_ = other.gobject_ ? std::make_unique<GtkBitsetIter>() : nullptr;
  bitset_ = other.bitset_;
  is_end_ = other.is_end_;

  if (other.gobject_)
  {
    if (gtk_bitset_iter_is_valid(other.gobject_.get()))
      gtk_bitset_iter_init_at(gobject_.get(), bitset_,
        gtk_bitset_iter_get_value(other.gobject_.get()), nullptr);
    else
      // other.gobject_.get() exists, but is invalid.
      // Initialize gobject_.get() to an invalid iterator.
      if (gtk_bitset_iter_init_last(gobject_.get(), bitset_, nullptr))
        gtk_bitset_iter_next(gobject_.get(), nullptr);
  }
  return *this;
}

BitsetConstIter::BitsetConstIter(BitsetConstIter&& other) noexcept
: gobject_(std::move(other.gobject_)),
  bitset_(other.bitset_),
  is_end_(other.is_end_)
{
  other.bitset_ = nullptr;
  other.is_end_ = true;
}

auto BitsetConstIter::operator=(BitsetConstIter&& other) noexcept -> BitsetConstIter&
{
  gobject_ = std::move(other.gobject_);
  bitset_ = other.bitset_;
  is_end_ = other.is_end_;
  other.bitset_ = nullptr;
  other.is_end_ = true;
  return *this;
}

auto BitsetConstIter::operator++() -> BitsetConstIter&
{
  if (!(gobject_ && bitset_ && !is_end_))
    return *this;

  if (!gtk_bitset_iter_next(gobject_.get(), nullptr))
    is_end_ = true;

  return *this;
}

auto BitsetConstIter::operator++(int) -> BitsetConstIter
{
  if (!(gobject_ && bitset_ && !is_end_))
    return *this;

  BitsetConstIter orig(*this);

  if (!gtk_bitset_iter_next(gobject_.get(), nullptr))
    is_end_ = true;

  return orig;
}

auto BitsetConstIter::operator--() -> BitsetConstIter&
{
  if (!(gobject_ && bitset_))
    return *this;

  if (is_end_)
  {
    if (gtk_bitset_iter_init_last(gobject_.get(), bitset_, nullptr))
      is_end_ = false;
  }
  else
    gtk_bitset_iter_previous(gobject_.get(), nullptr);

  return *this;
}

auto BitsetConstIter::operator--(int) -> BitsetConstIter
{
  if (!(gobject_ && bitset_))
    return *this;

  BitsetConstIter orig(*this);

  if (is_end_)
  {
    if (gtk_bitset_iter_init_last(gobject_.get(), bitset_, nullptr))
      is_end_ = false;
  }
  else
    gtk_bitset_iter_previous(gobject_.get(), nullptr);

  return orig;
}

auto BitsetConstIter::operator*() const -> BitsetConstIter::reference
{
  if (!(gobject_ && bitset_ && !is_end_))
    return 0;

  return gtk_bitset_iter_get_value(gobject_.get());
}

BitsetConstIter::operator bool() const noexcept
{
  if (!(gobject_ && bitset_ && !is_end_))
    return false;

  return gtk_bitset_iter_is_valid(gobject_.get());
}

auto BitsetConstIter::equal(const BitsetConstIter& other) const noexcept -> bool
{
  // By far the most common test for equality or unequality between
  // iterators is a comparison where one iterator is an end iterator.
  // First test if the iterators are unequal because one is an end iterator
  // and the other is not.
  if (is_end_ != other.is_end_ || bitset_ != other.bitset_)
    return false;

  if (!gobject_ && !other.gobject_)
    return true;

  if (!gobject_ || !other.gobject_)
    return false;

  if (gtk_bitset_iter_is_valid(gobject_.get()) !=
      gtk_bitset_iter_is_valid(other.gobject_.get()))
    return false;

  // There is no function that checks the equality of two GtkBitsetIters.
  // The iterators iterate over a set where no two elements have the
  // same value. If two iterators point to elements with the same value,
  // the iterators are equal.
  return gtk_bitset_iter_get_value(gobject_.get()) ==
    gtk_bitset_iter_get_value(other.gobject_.get());
}

} // namespace Gtk
