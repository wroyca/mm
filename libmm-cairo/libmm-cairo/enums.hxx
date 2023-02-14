

#ifndef __CAIROMM_ENUMS_H
#define __CAIROMM_ENUMS_H

#include <cairo.h>
#ifdef CAIRO_HAS_FT_FONT
  #include <cairo-ft.h>
#endif

namespace Cairo
{

#ifndef DOXYGEN_IGNORE_THIS

  typedef cairo_status_t ErrorStatus;
#endif

  typedef enum
  {
    ANTIALIAS_DEFAULT = CAIRO_ANTIALIAS_DEFAULT,

    ANTIALIAS_NONE = CAIRO_ANTIALIAS_NONE,

    ANTIALIAS_GRAY = CAIRO_ANTIALIAS_GRAY,

    ANTIALIAS_SUBPIXEL = CAIRO_ANTIALIAS_SUBPIXEL
  } Antialias;

  typedef enum
  {
    CONTENT_COLOR = CAIRO_CONTENT_COLOR,

    CONTENT_ALPHA = CAIRO_CONTENT_ALPHA,

    CONTENT_COLOR_ALPHA = CAIRO_CONTENT_COLOR_ALPHA
  } Content;

  typedef enum
  {
    SUBPIXEL_ORDER_DEFAULT = CAIRO_SUBPIXEL_ORDER_DEFAULT,

    SUBPIXEL_ORDER_RGB = CAIRO_SUBPIXEL_ORDER_RGB,

    SUBPIXEL_ORDER_BGR = CAIRO_SUBPIXEL_ORDER_BGR,

    SUBPIXEL_ORDER_VRGB = CAIRO_SUBPIXEL_ORDER_VRGB,

    SUBPIXEL_ORDER_VBGR = CAIRO_SUBPIXEL_ORDER_VBGR
  } SubpixelOrder;

  typedef enum
  {
    FONT_TYPE_TOY = CAIRO_FONT_TYPE_TOY,

    FONT_TYPE_FT = CAIRO_FONT_TYPE_FT,

    FONT_TYPE_WIN32 = CAIRO_FONT_TYPE_WIN32,

    FONT_TYPE_QUARTZ = CAIRO_FONT_TYPE_QUARTZ,

    FONT_TYPE_USER = CAIRO_FONT_TYPE_USER
  } FontType;

  typedef enum
  {
    TEXT_CLUSTER_FLAG_BACKWARD = CAIRO_TEXT_CLUSTER_FLAG_BACKWARD
  } TextClusterFlags;

#ifdef CAIRO_HAS_FT_FONT
  enum FtSynthesize
  {
    FT_SYNTHESIZE_BOLT = CAIRO_FT_SYNTHESIZE_BOLD,

    FT_SYNTHESIZE_OBLIQUE = CAIRO_FT_SYNTHESIZE_OBLIQUE
  };

  inline auto
  operator| (FtSynthesize a, FtSynthesize b) -> FtSynthesize
  {
    return static_cast<FtSynthesize> (static_cast<int> (a) |
                                      static_cast<int> (b));
  }

  inline auto
  operator& (FtSynthesize a, FtSynthesize b) -> FtSynthesize
  {
    return static_cast<FtSynthesize> (static_cast<int> (a) &
                                      static_cast<int> (b));
  }
#endif
} // namespace Cairo

#endif
