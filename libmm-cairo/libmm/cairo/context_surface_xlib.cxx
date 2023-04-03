// SPDX-License-Identifier: LGPL-2.0-or-later

#include <libmm/cairo/context_private.hxx>
#include <libmm/cairo/mm-cairoconfig.hxx>
#include <libmm/cairo/xlib_surface.hxx>

namespace Cairo::Private
{

  auto
  wrap_surface_xlib (cairo_surface_t* surface) -> RefPtr<Surface>
  {
#if CAIRO_HAS_XLIB_SURFACE
    return make_refptr_for_instance<XlibSurface> (
        new XlibSurface (surface, false));
#else
    return make_refptr_for_instance<Surface> (new Surface (surface, false));
#endif
  }

} // namespace Cairo::Private
