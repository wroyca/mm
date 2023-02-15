// SPDX-License-Identifier: LGPL-2.0-or-later

#ifndef __CAIROMM_XLIB_SURFACE_H
#define __CAIROMM_XLIB_SURFACE_H

#include <libmm-cairo/surface.hxx>

#ifdef CAIRO_HAS_XLIB_SURFACE
  #include <cairo-xlib.h>
  #ifdef CAIRO_HAS_XLIB_XRENDER_SURFACE
    #include <cairo-xlib-xrender.h>
  #endif
#endif

namespace Cairo
{

#ifdef CAIRO_HAS_XLIB_SURFACE

  class LIBMM_CAIRO_SYMEXPORT XlibSurface : public Surface
  {
  public:
    explicit XlibSurface (cairo_surface_t* cobject, bool has_reference = false);
    ~XlibSurface () override;

    static auto
    create (Display* dpy,
            Drawable drawable,
            Visual* visual,
            int width,
            int height) -> RefPtr<XlibSurface>;

    static auto
    create (Display* dpy, Pixmap bitmap, Screen* screen, int width, int height)
        -> RefPtr<XlibSurface>;

    void
    set_size (int width, int height);

    void
    set_drawable (Drawable drawable, int width, int height);

    auto
    get_drawable () const -> Drawable;

    auto
    get_display () const -> const Display*;

    auto
    get_display () -> Display*;

    auto
    get_screen () -> Screen*;

    auto
    get_screen () const -> const Screen*;

    auto
    get_visual () -> Visual*;

    auto
    get_visual () const -> const Visual*;

    auto
    get_depth () const -> int;

    auto
    get_height () const -> int;

    auto
    get_width () const -> int;

  #if CAIRO_HAS_XLIB_XRENDER_SURFACE

    static auto
    create_with_xrender_format (Display* dpy,
                                Drawable drawable,
                                Screen* screen,
                                XRenderPictFormat* format,
                                int width,
                                int height)
        -> Cairo::RefPtr<Cairo::XlibSurface>;

    auto
    get_xrender_format () const -> XRenderPictFormat*;

  #endif
  };

#endif

} // namespace Cairo

#endif
