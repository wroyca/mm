// SPDX-License-Identifier: LGPL-2.0-or-later

#include <libmm-cairo/win32_font.hxx>

#ifdef CAIRO_HAS_WIN32_FONT
  #include <libmm-cairo/private.hxx>

namespace Cairo
{

  Win32FontFace::Win32FontFace (LOGFONTW* logfont)
    : FontFace (cairo_win32_font_face_create_for_logfontw (logfont), true)
  {
    check_object_status_and_throw_exception (*this);
  }

  Win32FontFace::Win32FontFace (const HFONT font)
    : FontFace (cairo_win32_font_face_create_for_hfont (font), true)
  {
    check_object_status_and_throw_exception (*this);
  }

  Win32FontFace::Win32FontFace (LOGFONTW* logfont, const HFONT font)
    : FontFace (cairo_win32_font_face_create_for_logfontw_hfont (logfont, font),
                true)
  {
    check_object_status_and_throw_exception (*this);
  }

  auto
  Win32FontFace::create (LOGFONTW* logfont) -> RefPtr<Win32FontFace>
  {
    return make_refptr_for_instance<Win32FontFace> (
        new Win32FontFace (logfont));
  }

  auto
  Win32FontFace::create (const HFONT font) -> RefPtr<Win32FontFace>
  {
    return make_refptr_for_instance<Win32FontFace> (new Win32FontFace (font));
  }

  auto
  Win32FontFace::create (LOGFONTW* logfont, const HFONT font) -> RefPtr<Win32FontFace>
  {
    return make_refptr_for_instance<Win32FontFace> (
        new Win32FontFace (logfont, font));
  }

  Win32ScaledFont::Win32ScaledFont (const RefPtr<Win32FontFace>& font_face,
                                    const Matrix& font_matrix,
                                    const Matrix& ctm,
                                    const FontOptions& options)
    : ScaledFont (font_face, font_matrix, ctm, options)
  {
    check_object_status_and_throw_exception (*this);
  }

  auto
  Win32ScaledFont::create (const RefPtr<Win32FontFace>& font_face,
                           const Matrix& font_matrix,
                           const Matrix& ctm,
                           const FontOptions& options) -> RefPtr<Win32ScaledFont>
  {
    return make_refptr_for_instance<Win32ScaledFont> (
        new Win32ScaledFont (font_face, font_matrix, ctm, options));
  }

  auto
  Win32ScaledFont::select_font (const HDC hdc) -> void
  {
    const auto status = cairo_win32_scaled_font_select_font (cobj (), hdc);
    check_status_and_throw_exception (status);
    check_object_status_and_throw_exception (*this);
  }

  auto
  Win32ScaledFont::done_font () -> void
  {
    cairo_win32_scaled_font_done_font (cobj ());
    check_object_status_and_throw_exception (*this);
  }

  auto
  Win32ScaledFont::get_metrics_factor () const -> double
  {
    const auto val = cairo_win32_scaled_font_get_metrics_factor (
        const_cast<cairo_scaled_font_t*> (cobj ()));
    check_object_status_and_throw_exception (*this);
    return val;
  }

  auto
  Win32ScaledFont::get_logical_to_device (Matrix& logical_to_device) const -> void
  {
    cairo_win32_scaled_font_get_logical_to_device (
        const_cast<cairo_scaled_font_t*> (cobj ()),
        &logical_to_device);
    check_object_status_and_throw_exception (*this);
  }

  auto
  Win32ScaledFont::get_device_to_logical (Matrix& device_to_logical) const -> void
  {
    cairo_win32_scaled_font_get_device_to_logical (
        const_cast<cairo_scaled_font_t*> (cobj ()),
        &device_to_logical);
    check_object_status_and_throw_exception (*this);
  }

} // namespace Cairo

#endif
