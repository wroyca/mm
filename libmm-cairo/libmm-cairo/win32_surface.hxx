

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

    HDC
    get_dc () const;

    RefPtr<ImageSurface>
    get_image ();

    static RefPtr<Win32Surface>
    create (HDC hdc);

    static RefPtr<Win32Surface>
    create_with_dib (Format format, int width, int height);

    static RefPtr<Win32Surface>
    create_with_ddb (HDC hdc, Format format, int width, int height);
  };

  class CAIROMM_API Win32PrintingSurface : public Surface
  {
  public:
    explicit Win32PrintingSurface (cairo_surface_t* cobject,
                                   bool has_reference = false);
    ~Win32PrintingSurface () override;

    static RefPtr<Win32PrintingSurface>
    create (HDC hdc);
  };

} // namespace Cairo

#endif
#endif
