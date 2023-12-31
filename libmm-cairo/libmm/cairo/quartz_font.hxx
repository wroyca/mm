// SPDX-License-Identifier: LGPL-2.0-or-later

#ifndef __CAIROMM_QUARTZ_FONT_H
#define __CAIROMM_QUARTZ_FONT_H

#include <cairo-features.h>

#ifdef CAIRO_HAS_QUARTZ_FONT
  #include <cairo-quartz.h>
  #include <libmm/cairo/fontface.hxx>
  #include <libmm/cairo/scaledfont.hxx>

namespace cairo
{

  class LIBMM_CAIRO_SYMEXPORT QuartzFontFace : public FontFace
  {
  public:
    static RefPtr<QuartzFontFace>
    create (CGFontRef font);

  #ifndef __LP64__

    static RefPtr<QuartzFontFace>
    create (ATSUFontID font_id);
  #endif

  protected:
    QuartzFontFace (CGFontRef font);
  #ifndef __LP64__
    QuartzFontFace (ATSUFontID font_id);
  #endif
  };

} // namespace cairo

#endif

#endif
