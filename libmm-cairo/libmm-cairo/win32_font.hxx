// SPDX-License-Identifier: LGPL-2.0-or-later

#ifndef __CAIROMM_WIN32_FONT_H
#define __CAIROMM_WIN32_FONT_H

#include <cairo-features.h>

#ifdef CAIRO_HAS_WIN32_FONT
  #include <cairo-win32.h>
  #include <libmm-cairo/fontface.hxx>
  #include <libmm-cairo/scaledfont.hxx>

namespace Cairo
{

  class CAIROMM_API Win32FontFace : public FontFace
  {
  public:
    static RefPtr<Win32FontFace>
    create (LOGFONTW* logfont);

    static RefPtr<Win32FontFace>
    create (HFONT font);

    static RefPtr<Win32FontFace>
    create (LOGFONTW* logfont, HFONT font);

  protected:
    Win32FontFace (LOGFONTW* logfont);
    Win32FontFace (HFONT font);
    Win32FontFace (LOGFONTW* logfont, HFONT font);
  };

  class CAIROMM_API Win32ScaledFont : public ScaledFont
  {
  public:
    static RefPtr<Win32ScaledFont>
    create (const RefPtr<Win32FontFace>& font_face,
            const Matrix& font_matrix,
            const Matrix& ctm,
            const FontOptions& options = FontOptions ());

    void
    select_font (HDC hdc);

    void
    done_font ();

    double
    get_metrics_factor () const;

    void
    get_logical_to_device (Matrix& logical_to_device) const;

    void
    get_device_to_logical (Matrix& device_to_logical) const;

  protected:
    Win32ScaledFont (const RefPtr<Win32FontFace>& font_face,
                     const Matrix& font_matrix,
                     const Matrix& ctm,
                     const FontOptions& options = FontOptions ());
  };

} // namespace Cairo

#endif

#endif
