// SPDX-License-Identifier: LGPL-2.0-or-later

#ifndef __CAIROMM_WIN32_FONT_H
#define __CAIROMM_WIN32_FONT_H

#include <cairo-features.h>

#ifdef CAIRO_HAS_WIN32_FONT
  #include <cairo-win32.h>
  #include <libmm/cairo/fontface.hxx>
  #include <libmm/cairo/scaledfont.hxx>

namespace Cairo
{

  class LIBMM_CAIRO_SYMEXPORT Win32FontFace : public FontFace
  {
  public:
    static auto
    create (LOGFONTW* logfont) -> RefPtr<Win32FontFace>;

    static auto
    create (HFONT font) -> RefPtr<Win32FontFace>;

    static auto
    create (LOGFONTW* logfont, HFONT font) -> RefPtr<Win32FontFace>;

  protected:
    Win32FontFace (LOGFONTW* logfont);
    Win32FontFace (HFONT font);
    Win32FontFace (LOGFONTW* logfont, HFONT font);
  };

  class LIBMM_CAIRO_SYMEXPORT Win32ScaledFont : public ScaledFont
  {
  public:
    static auto
    create (const RefPtr<Win32FontFace>& font_face,
            const Matrix& font_matrix,
            const Matrix& ctm,
            const FontOptions& options = FontOptions ())
        -> RefPtr<Win32ScaledFont>;

    auto
    select_font (HDC hdc) -> void;

    auto
    done_font () -> void;

    auto
    get_metrics_factor () const -> double;

    auto
    get_logical_to_device (Matrix& logical_to_device) const -> void;

    auto
    get_device_to_logical (Matrix& device_to_logical) const -> void;

  protected:
    Win32ScaledFont (const RefPtr<Win32FontFace>& font_face,
                     const Matrix& font_matrix,
                     const Matrix& ctm,
                     const FontOptions& options = FontOptions ());
  };

} // namespace Cairo

#endif

#endif
