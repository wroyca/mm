// SPDX-License-Identifier: LGPL-2.0-or-later

#include <libmm/cairo/quartz_font.hxx>

#ifdef CAIRO_HAS_QUARTZ_FONT
  #include <libmm/cairo/private.hxx>

namespace cairo
{

  QuartzFontFace::QuartzFontFace (CGFontRef font)
    : FontFace (cairo_quartz_font_face_create_for_cgfont (font), true)
  {
    check_object_status_and_throw_exception (*this);
  }

  RefPtr<QuartzFontFace>
  QuartzFontFace::create (CGFontRef font)
  {
    return make_refptr_for_instance<QuartzFontFace> (new QuartzFontFace (font));
  }

  #ifndef __LP64__
  QuartzFontFace::QuartzFontFace (ATSUFontID font_id)
    : FontFace (cairo_quartz_font_face_create_for_atsu_font_id (font_id), true)
  {
    check_object_status_and_throw_exception (*this);
  }

  RefPtr<QuartzFontFace>
  QuartzFontFace::create (ATSUFontID font_id)
  {
    return make_refptr_for_instance<QuartzFontFace> (
        new QuartzFontFace (font_id));
  }
  #endif

} // namespace cairo

#endif
