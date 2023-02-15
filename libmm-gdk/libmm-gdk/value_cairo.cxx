// SPDX-License-Identifier: LGPL-2.1-or-later

#include <cairo-gobject.h>
#include <libmm-gdk/value_cairo.hxx>

namespace Gdk
{
  namespace Cairo
  {

    template <>
    auto
    get_base_type<::Cairo::Region> () -> GType
    {
      return CAIRO_GOBJECT_TYPE_REGION;
    }

    template <>
    auto
    get_base_type<::Cairo::Surface> () -> GType
    {
      return CAIRO_GOBJECT_TYPE_SURFACE;
    }

  } // namespace Cairo

} // namespace Gdk
