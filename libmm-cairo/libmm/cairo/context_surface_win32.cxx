// SPDX-License-Identifier: LGPL-2.0-or-later

#include <libmm/cairo/context_private.hxx>
#include <libmm/cairo/mm-cairoconfig.hxx>
#include <libmm/cairo/win32_surface.hxx>

namespace cairo::Private
{

  auto
  wrap_surface_win32 (cairo_surface_t* surface) -> RefPtr<Surface>
  {
#if CAIRO_HAS_WIN32_SURFACE
    return make_refptr_for_instance<Win32Surface> (
        new Win32Surface (surface, false));
#else
    return make_refptr_for_instance<Surface> (new Surface (surface, false));
#endif
  }

} // namespace cairo::Private
