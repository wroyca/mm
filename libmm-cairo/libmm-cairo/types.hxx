// SPDX-License-Identifier: LGPL-2.0-or-later

#ifndef __CAIROMM_TYPES_H
#define __CAIROMM_TYPES_H

#include <libmm-cairo/mm-cairoconfig.hxx>

#include <cairo.h>

namespace Cairo
{

  typedef cairo_rectangle_t Rectangle;

  typedef cairo_rectangle_int_t RectangleInt;

  typedef cairo_font_extents_t FontExtents;

  typedef cairo_text_extents_t TextExtents;

  typedef cairo_text_cluster_t TextCluster;

  typedef cairo_glyph_t Glyph;

} // namespace Cairo

#endif
