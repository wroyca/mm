// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GLIBMM_VARIANTITER_H
#define _GLIBMM_VARIANTITER_H

#include <glib.h>
#include <libmm/glib/mm-glibconfig.hxx>

namespace Glib
{

  class LIBMM_GLIB_SYMEXPORT VariantBase;
  class LIBMM_GLIB_SYMEXPORT VariantContainerBase;

  class LIBMM_GLIB_SYMEXPORT VariantIter
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    using CppObjectType = VariantIter;
    using BaseObjectType = GVariantIter;
#endif

    VariantIter ();

    explicit VariantIter (GVariantIter* castitem, bool make_a_copy = false);

    VariantIter (const VariantIter& src);
    auto
    operator= (const VariantIter& src) -> VariantIter&;

    VariantIter (VariantIter&& other) noexcept;
    auto
    operator= (VariantIter&& other) noexcept -> VariantIter&;

    ~VariantIter () noexcept;

    auto
    swap (VariantIter& other) noexcept -> void;

    auto
    gobj () -> GVariantIter*
    {
      return gobject_;
    }

    auto
    gobj () const -> const GVariantIter*
    {
      return gobject_;
    }

    auto
    gobj_copy () const -> GVariantIter*;

  protected:
    GVariantIter* gobject_;

  private:
  public:
    explicit VariantIter (const VariantContainerBase& variant);

    auto
    init (const VariantContainerBase& value) -> gsize;

    auto
    get_n_children () const -> gsize;

    auto
    next_value (VariantBase& value) -> bool;
  };

} // namespace Glib

namespace Glib
{

  inline auto
  swap (VariantIter& lhs, VariantIter& rhs) noexcept -> void
  {
    lhs.swap (rhs);
  }

} // namespace Glib

namespace Glib
{

  LIBMM_GLIB_SYMEXPORT
  auto
  wrap (GVariantIter* object, bool take_copy = false) -> Glib::VariantIter;

} // namespace Glib

#endif
