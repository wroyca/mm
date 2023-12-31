// SPDX-License-Identifier: LGPL-2.0-or-later

#include <libmm/cairo/private.hxx>
#include <libmm/cairo/xlib_surface.hxx>

namespace cairo
{

#ifdef CAIRO_HAS_XLIB_SURFACE

  XlibSurface::XlibSurface (cairo_surface_t* cobject, bool has_reference)
    : Surface (cobject, has_reference)
  {
  }

  XlibSurface::~XlibSurface () {}

  auto
  XlibSurface::create (Display* dpy,
                       Drawable drawable,
                       Visual* visual,
                       int width,
                       int height) -> RefPtr<XlibSurface>
  {
    auto cobject =
        cairo_xlib_surface_create (dpy, drawable, visual, width, height);
    check_status_and_throw_exception (cairo_surface_status (cobject));
    return make_refptr_for_instance<XlibSurface> (
        new XlibSurface (cobject, true));
  }

  auto
  XlibSurface::create (Display* dpy,
                       Pixmap bitmap,
                       Screen* screen,
                       int width,
                       int height) -> RefPtr<XlibSurface>
  {
    auto cobject = cairo_xlib_surface_create_for_bitmap (dpy,
                                                         bitmap,
                                                         screen,
                                                         width,
                                                         height);
    check_status_and_throw_exception (cairo_surface_status (cobject));
    return make_refptr_for_instance<XlibSurface> (
        new XlibSurface (cobject, true));
  }

  void
  XlibSurface::set_size (int width, int height)
  {
    cairo_xlib_surface_set_size (m_cobject, width, height);
    check_object_status_and_throw_exception (*this);
  }

  void
  XlibSurface::set_drawable (Drawable drawable, int width, int height)
  {
    cairo_xlib_surface_set_drawable (m_cobject, drawable, width, height);
    check_object_status_and_throw_exception (*this);
  }

  auto
  XlibSurface::get_drawable () const -> Drawable
  {
    auto drawable = cairo_xlib_surface_get_drawable (m_cobject);
    check_object_status_and_throw_exception (*this);
    return drawable;
  }

  auto
  XlibSurface::get_display () const -> const Display*
  {
    const auto dpy = cairo_xlib_surface_get_display (m_cobject);
    check_object_status_and_throw_exception (*this);
    return dpy;
  }

  auto
  XlibSurface::get_display () -> Display*
  {
    auto dpy = cairo_xlib_surface_get_display (m_cobject);
    check_object_status_and_throw_exception (*this);
    return dpy;
  }

  auto
  XlibSurface::get_screen () -> Screen*
  {
    auto screen = cairo_xlib_surface_get_screen (m_cobject);
    check_object_status_and_throw_exception (*this);
    return screen;
  }

  auto
  XlibSurface::get_screen () const -> const Screen*
  {
    const auto screen = cairo_xlib_surface_get_screen (m_cobject);
    check_object_status_and_throw_exception (*this);
    return screen;
  }

  auto
  XlibSurface::get_visual () -> Visual*
  {
    auto visual = cairo_xlib_surface_get_visual (m_cobject);
    check_object_status_and_throw_exception (*this);
    return visual;
  }

  auto
  XlibSurface::get_visual () const -> const Visual*
  {
    const auto visual = cairo_xlib_surface_get_visual (m_cobject);
    check_object_status_and_throw_exception (*this);
    return visual;
  }

  auto
  XlibSurface::get_depth () const -> int
  {
    auto depth = cairo_xlib_surface_get_depth (m_cobject);
    check_object_status_and_throw_exception (*this);
    return depth;
  }

  auto
  XlibSurface::get_height () const -> int
  {
    auto h = cairo_xlib_surface_get_height (m_cobject);
    check_object_status_and_throw_exception (*this);
    return h;
  }

  auto
  XlibSurface::get_width () const -> int
  {
    auto w = cairo_xlib_surface_get_width (m_cobject);
    check_object_status_and_throw_exception (*this);
    return w;
  }

  #if CAIRO_HAS_XLIB_XRENDER_SURFACE
  auto
  XlibSurface::create_with_xrender_format (Display* dpy,
                                           Drawable drawable,
                                           Screen* screen,
                                           XRenderPictFormat* format,
                                           int width,
                                           int height) -> cairo::RefPtr<cairo::XlibSurface>
  {
    auto cobject = cairo_xlib_surface_create_with_xrender_format (dpy,
                                                                  drawable,
                                                                  screen,
                                                                  format,
                                                                  width,
                                                                  height);
    check_status_and_throw_exception (cairo_surface_status (cobject));
    return make_refptr_for_instance<XlibSurface> (
        new XlibSurface (cobject, true));
  }

  auto
  XlibSurface::get_xrender_format () const -> XRenderPictFormat*
  {
    XRenderPictFormat* format =
        cairo_xlib_surface_get_xrender_format (m_cobject);
    check_object_status_and_throw_exception (*this);
    return format;
  }

  #endif

#endif

} // namespace cairo
