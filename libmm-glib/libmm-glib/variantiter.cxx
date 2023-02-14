

#include <libmm-glib/mm-glib.hxx>

#include <libmm-glib/variantiter.hxx>
#include <libmm-glib/variantiter_p.hxx>

#include <glib.h>
#include <libmm-glib/variant.hxx>

namespace Glib
{

  VariantIter::VariantIter (const VariantContainerBase& variant)
    : gobject_ (g_variant_iter_new (const_cast<GVariant*> (variant.gobj ())))
  {
  }

  auto
  VariantIter::next_value (VariantBase& value) -> bool
  {
    const GVariant* const g_value = g_variant_iter_next_value (gobj ());

    if (g_value)
    {
      value.init (g_value);
      return true;
    }
    else
      return false;
  }

} // namespace Glib

namespace
{
}

namespace Glib
{

  auto
  wrap (GVariantIter* object, const bool take_copy) -> VariantIter
  {
    return VariantIter (object, take_copy);
  }

} // namespace Glib

namespace Glib
{

  VariantIter::VariantIter ()
    : gobject_ (nullptr)
  {
  }

  VariantIter::VariantIter (const VariantIter& src)
    : gobject_ (src.gobject_ ? g_variant_iter_copy (src.gobject_) : nullptr)
  {
  }

  VariantIter::VariantIter (GVariantIter* castitem, const bool make_a_copy)
  {
    if (!make_a_copy)
    {
      gobject_ = castitem;
    }
    else
    {
      if (castitem)
        gobject_ = g_variant_iter_copy (castitem);
      else
        gobject_ = nullptr;
    }
  }

  auto
  VariantIter::operator= (const VariantIter& src) -> VariantIter&
  {
    const auto new_gobject = src.gobject_ ? g_variant_iter_copy (src.gobject_) :
                                            nullptr;

    if (gobject_)
      g_variant_iter_free (gobject_);

    gobject_ = new_gobject;

    return *this;
  }

  VariantIter::VariantIter (VariantIter&& other) noexcept
    : gobject_ (other.gobject_)
  {
    other.gobject_ = nullptr;
  }

  auto
  VariantIter::operator= (VariantIter&& other) noexcept -> VariantIter&
  {
    VariantIter temp (std::move (other));
    swap (temp);
    return *this;
  }

  VariantIter::~VariantIter () noexcept
  {
    if (gobject_)
      g_variant_iter_free (gobject_);
  }

  auto
  VariantIter::swap (VariantIter& other) noexcept -> void
  {
    std::swap (gobject_, other.gobject_);
  }

  auto
  VariantIter::gobj_copy () const -> GVariantIter*
  {
    return g_variant_iter_copy (gobject_);
  }

  auto
  VariantIter::init (const VariantContainerBase& value) -> gsize
  {
    return g_variant_iter_init (gobj (), const_cast<GVariant*> (value.gobj ()));
  }

  auto
  VariantIter::get_n_children () const -> gsize
  {
    return g_variant_iter_n_children (const_cast<GVariantIter*> (gobj ()));
  }

} // namespace Glib
