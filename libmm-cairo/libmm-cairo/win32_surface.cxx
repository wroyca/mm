

#include <libmm-cairo/private.hxx>
#include <libmm-cairo/win32_surface.hxx>

namespace Cairo
{

#ifdef CAIRO_HAS_WIN32_SURFACE

  Win32Surface::Win32Surface (cairo_surface_t* cobject,
                              const bool has_reference)
    : Surface (cobject, has_reference)
  {
  }

  Win32Surface::~Win32Surface () {}

  auto
  Win32Surface::get_dc () const -> HDC
  {
    return cairo_win32_surface_get_dc (m_cobject);
  }

  auto
  Win32Surface::get_image () -> RefPtr<ImageSurface>
  {
    RefPtr<ImageSurface> surface (
        new ImageSurface (cairo_win32_surface_get_image (cobj ()), false));
    check_object_status_and_throw_exception (*this);
    return surface;
  }

  auto
  Win32Surface::create (const HDC hdc) -> RefPtr<Win32Surface>
  {
    const auto cobject = cairo_win32_surface_create (hdc);
    check_status_and_throw_exception (cairo_surface_status (cobject));
    return make_refptr_for_instance<Win32Surface> (
        new Win32Surface (cobject, true));
  }

  auto
  Win32Surface::create_with_dib (Format format,
                                 const int width,
                                 const int height) -> RefPtr<Win32Surface>
  {
    const auto cobject = cairo_win32_surface_create_with_dib (
        (cairo_format_t) format,
        width,
        height);
    check_status_and_throw_exception (cairo_surface_status (cobject));
    return make_refptr_for_instance<Win32Surface> (
        new Win32Surface (cobject, true));
  }

  auto
  Win32Surface::create_with_ddb (const HDC hdc,
                                 Format format,
                                 const int width,
                                 const int height) -> RefPtr<Win32Surface>
  {
    const auto cobject = cairo_win32_surface_create_with_ddb (
        hdc,
        (cairo_format_t) format,
        width,
        height);
    check_status_and_throw_exception (cairo_surface_status (cobject));
    return make_refptr_for_instance<Win32Surface> (
        new Win32Surface (cobject, true));
  }

  Win32PrintingSurface::Win32PrintingSurface (cairo_surface_t* cobject,
                                              const bool has_reference)
    : Surface (cobject, has_reference)
  {
  }

  Win32PrintingSurface::~Win32PrintingSurface () {}

  auto
  Win32PrintingSurface::create (const HDC hdc) -> RefPtr<Win32PrintingSurface>
  {
    const auto cobject = cairo_win32_surface_create (hdc);
    check_status_and_throw_exception (cairo_surface_status (cobject));
    return make_refptr_for_instance<Win32PrintingSurface> (
        new Win32PrintingSurface (cobject, true));
  }

#endif

} // namespace Cairo
