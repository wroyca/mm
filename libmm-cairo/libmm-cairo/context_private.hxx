// SPDX-License-Identifier: LGPL-2.0-or-later

#ifndef __CAIROMM_CONTEXT_PRIVATE_H
#define __CAIROMM_CONTEXT_PRIVATE_H

#include <libmm-cairo/refptr.hxx>
#include <libmm-cairo/surface.hxx>

namespace Cairo::Private
{

  auto
  wrap_surface_quartz (cairo_surface_t*) -> RefPtr<Surface>;
  auto
  wrap_surface_win32 (cairo_surface_t*) -> RefPtr<Surface>;
  auto
  wrap_surface_xlib (cairo_surface_t*) -> RefPtr<Surface>;

} // namespace Cairo::Private

#endif
