// SPDX-License-Identifier: LGPL-2.0-or-later

#ifndef __CAIROMM_QUARTZ_SURFACE_H
#define __CAIROMM_QUARTZ_SURFACE_H

#include <libmm/cairo/surface.hxx>

#ifdef CAIRO_HAS_QUARTZ_SURFACE
  #include <cairo-quartz.h>
#endif

namespace cairo
{

#ifdef CAIRO_HAS_QUARTZ_SURFACE

  class LIBMM_CAIRO_SYMEXPORT QuartzSurface : public Surface
  {
  public:
    explicit QuartzSurface (cairo_surface_t* cobject,
                            bool has_reference = false);
    ~QuartzSurface () override;

    CGContextRef
    get_cg_context () const;

    static RefPtr<QuartzSurface>
    create (CGContextRef cg_context, int width, int height);

    static RefPtr<QuartzSurface>
    create (Format format, int width, int height);
  };

#endif

} // namespace cairo

#endif
