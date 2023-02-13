


#include <libmm-glib/mm-glib.hxx>

#include <libmm-glib/variantiter.hxx>
#include <libmm-glib/variantiter_p.hxx>


/* Copyright(C) 2010 The glibmm Development Team
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
 * License along with this library.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <libmm-glib/variant.hxx>
#include <glib.h>

namespace Glib
{

VariantIter::VariantIter(const VariantContainerBase& variant)
: gobject_(g_variant_iter_new(const_cast<GVariant*>(variant.gobj())))
{
}

auto
VariantIter::next_value(VariantBase& value) -> bool
{
  const GVariant* const g_value = g_variant_iter_next_value(gobj());

  if (g_value)
  {
    value.init(g_value); // g_value is already referenced.
    return true;
  }
  else
    return false;
}

} // namespace Glib

namespace
{
} // anonymous namespace


namespace Glib
{

auto wrap(GVariantIter* object, const bool take_copy /* = false */) -> VariantIter
{
  return VariantIter(object, take_copy);
}

} // namespace Glib


namespace Glib
{


VariantIter::VariantIter()
:
  gobject_ (nullptr) // Allows creation of invalid wrapper, e.g. for output arguments to methods.
{}

VariantIter::VariantIter(const VariantIter& src)
:
  gobject_ (src.gobject_ ? g_variant_iter_copy(src.gobject_) : nullptr)
{}

VariantIter::VariantIter(GVariantIter* castitem, const bool make_a_copy /* = false */)
{
  if(!make_a_copy)
  {
    // It was given to us by a function which has already made a copy for us to keep.
    gobject_ = castitem;
  }
  else
  {
    // We are probably getting it via direct access to a struct,
    // so we can not just take it - we have to take a copy of it.
    if(castitem)
      gobject_ = g_variant_iter_copy(castitem);
    else
      gobject_ = nullptr;
  }
}


auto VariantIter::operator=(const VariantIter& src) -> VariantIter&
{
  const auto new_gobject = src.gobject_ ? g_variant_iter_copy(src.gobject_) : nullptr;

  if(gobject_)
    g_variant_iter_free(gobject_);

  gobject_ = new_gobject;

  return *this;
}

VariantIter::VariantIter(VariantIter&& other) noexcept
:
  gobject_(other.gobject_)
{
  other.gobject_ = nullptr;
}

auto VariantIter::operator=(VariantIter&& other) noexcept -> VariantIter&
{
  VariantIter temp (std::move(other));
  swap(temp);
  return *this;
}

VariantIter::~VariantIter() noexcept
{
  if(gobject_)
    g_variant_iter_free(gobject_);
}

auto VariantIter::swap (VariantIter &other) noexcept -> void
{
  std::swap(gobject_, other.gobject_);
}

auto VariantIter::gobj_copy() const -> GVariantIter*
{
  return g_variant_iter_copy(gobject_);
}


auto VariantIter::init(const VariantContainerBase& value) -> gsize
{
  return g_variant_iter_init(gobj(), const_cast<GVariant*>(value.gobj()));
}

auto VariantIter::get_n_children() const -> gsize
{
  return g_variant_iter_n_children(const_cast<GVariantIter*>(gobj()));
}


} // namespace Glib

