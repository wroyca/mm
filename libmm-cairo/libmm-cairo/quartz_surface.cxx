// SPDX-License-Identifier: LGPL-2.0-or-later

#include <libmm-cairo/private.hxx>
#include <libmm-cairo/quartz_surface.hxx>

namespace Cairo
{

#ifdef CAIRO_HAS_QUARTZ_SURFACE

  QuartzSurface::QuartzSurface (cairo_surface_t* cobject, bool has_reference)
    : Surface (cobject, has_reference)
  {
  }

  QuartzSurface::~QuartzSurface () {}

  CGContextRef
  QuartzSurface::get_cg_context () const
  {
    return cairo_quartz_surface_get_cg_context (m_cobject);
  }

  RefPtr<QuartzSurface>
  QuartzSurface::create (CGContextRef cg_context, int width, int height)
  {
    auto cobject =
        cairo_quartz_surface_create_for_cg_context (cg_context, width, height);
    check_status_and_throw_exception (cairo_surface_status (cobject));
    return make_refptr_for_instance<QuartzSurface> (
        new QuartzSurface (cobject, true));
  }

  RefPtr<QuartzSurface>
  QuartzSurface::create (Format format, int width, int height)
  {
    auto cobject =
        cairo_quartz_surface_create ((cairo_format_t) format, width, height);
    check_status_and_throw_exception (cairo_surface_status (cobject));
    return make_refptr_for_instance<QuartzSurface> (
        new QuartzSurface (cobject, true));
  }

#endif

} // namespace Cairo
