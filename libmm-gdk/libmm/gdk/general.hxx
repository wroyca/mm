// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GDKMM_GENERAL_H
#define _GDKMM_GENERAL_H

#include <libmm/cairo/context.hxx>
#include <libmm/cairo/region.hxx>
#include <libmm/cairo/surface.hxx>
#include <libmm/gdk/glcontext.hxx>
#include <libmm/gdk/pixbuf.hxx>
#include <libmm/gdk/rectangle.hxx>
#include <libmm/gdk/rgba.hxx>
#include <libmm/gdk/surface.hxx>

namespace gdk
{

  namespace cairo
  {
    LIBMM_GDK_SYMEXPORT auto
    set_source_rgba (const ::cairo::RefPtr<::cairo::Context>& context,
                     const gdk::RGBA& color) -> void;

    LIBMM_GDK_SYMEXPORT auto
    set_source_pixbuf (const ::cairo::RefPtr<::cairo::Context>& context,
                       const glib::RefPtr<const gdk::Pixbuf>& pixbuf,
                       double pixbuf_x = 0,
                       double pixbuf_y = 0) -> void;

    LIBMM_GDK_SYMEXPORT auto
    add_rectangle_to_path (const ::cairo::RefPtr<::cairo::Context>& context,
                           const gdk::Rectangle& rectangle) -> void;

    LIBMM_GDK_SYMEXPORT auto
    add_region_to_path (const ::cairo::RefPtr<::cairo::Context>& context,
                        const ::cairo::RefPtr<::cairo::Region>& region) -> void;

    LIBMM_GDK_SYMEXPORT auto
    create_region_from_surface (
        const ::cairo::RefPtr<::cairo::Surface>& surface)
        -> ::cairo::RefPtr<::cairo::Region>;

#ifndef GDKMM_DISABLE_DEPRECATED

    LIBMM_GDK_SYMEXPORT auto
    draw_from_gl (const ::cairo::RefPtr<::cairo::Context>& context,
                  const glib::RefPtr<gdk::Surface>& surface,
                  int source,
                  int source_type,
                  int buffer_scale,
                  int x,
                  int y,
                  int width,
                  int height) -> void;
#endif

  } // namespace cairo

} // namespace gdk

#endif
