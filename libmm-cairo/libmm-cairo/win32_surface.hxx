// SPDX-License-Identifier: LGPL-2.0-or-later

#ifndef __CAIROMM_WIN32_SURFACE_H
#define __CAIROMM_WIN32_SURFACE_H

#include <cairo-features.h>
#include <libmm-cairo/enums.hxx>
#include <libmm-cairo/surface.hxx>

#ifdef CAIRO_HAS_WIN32_SURFACE
  #include <cairo-win32.h>

namespace Cairo
{

  class CAIROMM_API Win32Surface : public Surface
  {
  public:
    explicit Win32Surface (cairo_surface_t* cobject,
                           bool has_reference = false);
    ~Win32Surface () override;

    auto
    get_dc () const -> HDC;

    auto
    get_image () -> RefPtr<ImageSurface>;

    static auto
    create (HDC hdc) -> RefPtr<Win32Surface>;

    static auto
    create_with_dib (Format format, int width, int height)
        -> RefPtr<Win32Surface>;

    static auto
    create_with_ddb (HDC hdc, Format format, int width, int height)
        -> RefPtr<Win32Surface>;
  };

  class CAIROMM_API Win32PrintingSurface : public Surface
  {
  public:
    explicit Win32PrintingSurface (cairo_surface_t* cobject,
                                   bool has_reference = false);
    ~Win32PrintingSurface () override;

    static auto
    create (HDC hdc) -> RefPtr<Win32PrintingSurface>;
  };

} // namespace Cairo

#endif
#endif
