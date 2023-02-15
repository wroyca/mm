// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GDKMM_GENERAL_H
#define _GDKMM_GENERAL_H

#include <libmm-cairo/context.hxx>
#include <libmm-cairo/region.hxx>
#include <libmm-cairo/surface.hxx>
#include <libmm-gdk/glcontext.hxx>
#include <libmm-gdk/pixbuf.hxx>
#include <libmm-gdk/rectangle.hxx>
#include <libmm-gdk/rgba.hxx>
#include <libmm-gdk/surface.hxx>

namespace Gdk
{

  namespace Cairo
  {
    GDKMM_API auto
    set_source_rgba (const ::Cairo::RefPtr<::Cairo::Context>& context,
                     const Gdk::RGBA& color) -> void;

    GDKMM_API auto
    set_source_pixbuf (const ::Cairo::RefPtr<::Cairo::Context>& context,
                       const Glib::RefPtr<const Gdk::Pixbuf>& pixbuf,
                       double pixbuf_x = 0,
                       double pixbuf_y = 0) -> void;

    GDKMM_API auto
    add_rectangle_to_path (const ::Cairo::RefPtr<::Cairo::Context>& context,
                           const Gdk::Rectangle& rectangle) -> void;

    GDKMM_API auto
    add_region_to_path (const ::Cairo::RefPtr<::Cairo::Context>& context,
                        const ::Cairo::RefPtr<::Cairo::Region>& region) -> void;

    GDKMM_API auto
    create_region_from_surface (
        const ::Cairo::RefPtr<::Cairo::Surface>& surface)
        -> ::Cairo::RefPtr<::Cairo::Region>;

#ifndef GDKMM_DISABLE_DEPRECATED

    GDKMM_API auto
    draw_from_gl (const ::Cairo::RefPtr<::Cairo::Context>& context,
                  const Glib::RefPtr<Gdk::Surface>& surface,
                  int source,
                  int source_type,
                  int buffer_scale,
                  int x,
                  int y,
                  int width,
                  int height) -> void;
#endif

  } // namespace Cairo

} // namespace Gdk

#endif
