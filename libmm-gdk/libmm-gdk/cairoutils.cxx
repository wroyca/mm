// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm-gdk/cairoutils.hxx>

namespace Gdk
{

  namespace Cairo
  {

    auto
    wrap (cairo_t* cobject, bool has_reference)
        -> ::Cairo::RefPtr<::Cairo::Context>
    {
      return ::Cairo::make_refptr_for_instance<::Cairo::Context> (
          cobject ? new ::Cairo::Context (cobject, has_reference) : nullptr);
    }

    auto
    wrap (cairo_region_t* cobject, bool has_reference)
        -> ::Cairo::RefPtr<::Cairo::Region>
    {
      return ::Cairo::make_refptr_for_instance<::Cairo::Region> (
          cobject ? new ::Cairo::Region (cobject, has_reference) : nullptr);
    }

  } // namespace Cairo

} // namespace Gdk
