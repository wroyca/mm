// SPDX-License-Identifier: LGPL-2.1-or-later

#include <cairo-gobject.h>
#include <libmm/gdk/value_cairo.hxx>

namespace gdk
{
  namespace cairo
  {

    template <>
    auto
    get_base_type<::cairo::Region> () -> GType
    {
      return CAIRO_GOBJECT_TYPE_REGION;
    }

    template <>
    auto
    get_base_type<::cairo::Surface> () -> GType
    {
      return CAIRO_GOBJECT_TYPE_SURFACE;
    }

  } // namespace cairo

} // namespace gdk
