// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/gdk/cairoutils.hxx>

namespace gdk
{

  namespace cairo
  {

    auto
    wrap (cairo_t* cobject, bool has_reference)
        -> ::cairo::RefPtr<::cairo::Context>
    {
      return ::cairo::make_refptr_for_instance<::cairo::Context> (
          cobject ? new ::cairo::Context (cobject, has_reference) : nullptr);
    }

    auto
    wrap (cairo_region_t* cobject, bool has_reference)
        -> ::cairo::RefPtr<::cairo::Region>
    {
      return ::cairo::make_refptr_for_instance<::cairo::Region> (
          cobject ? new ::cairo::Region (cobject, has_reference) : nullptr);
    }

  } // namespace cairo

} // namespace gdk
