// SPDX-License-Identifier: LGPL-2.1-or-later

#include <gdk/gdk.h>
#include <libmm/gdk/cairoutils.hxx>
#include <libmm/gdk/general.hxx>

namespace Gdk
{

  namespace Cairo
  {

    auto
    set_source_rgba (const ::Cairo::RefPtr<::Cairo::Context>& context,
                     const Gdk::RGBA& color) -> void
    {
      gdk_cairo_set_source_rgba (context->cobj (),
                                 const_cast<GdkRGBA*> (color.gobj ()));
    }

    auto
    set_source_pixbuf (const ::Cairo::RefPtr<::Cairo::Context>& context,
                       const Glib::RefPtr<const Gdk::Pixbuf>& pixbuf,
                       double pixbuf_x,
                       double pixbuf_y) -> void
    {
      gdk_cairo_set_source_pixbuf (context->cobj (),
                                   pixbuf->gobj (),
                                   pixbuf_x,
                                   pixbuf_y);
    }

    auto
    add_rectangle_to_path (const ::Cairo::RefPtr<::Cairo::Context>& context,
                           const Gdk::Rectangle& rectangle) -> void
    {
      gdk_cairo_rectangle (context->cobj (),
                           const_cast<GdkRectangle*> (rectangle.gobj ()));
    }

    auto
    add_region_to_path (const ::Cairo::RefPtr<::Cairo::Context>& context,
                        const ::Cairo::RefPtr<::Cairo::Region>& region) -> void
    {
      gdk_cairo_region (context->cobj (), (region ? region->cobj () : nullptr));
    }

    auto
    create_region_from_surface (
        const ::Cairo::RefPtr<::Cairo::Surface>& surface)
        -> ::Cairo::RefPtr<::Cairo::Region>
    {
      return Gdk::Cairo::wrap (
          gdk_cairo_region_create_from_surface (surface->cobj ()),
          true);
    }

#ifndef GDKMM_DISABLE_DEPRECATED
    G_GNUC_BEGIN_IGNORE_DEPRECATIONS
    auto
    draw_from_gl (const ::Cairo::RefPtr<::Cairo::Context>& context,
                  const Glib::RefPtr<Gdk::Surface>& surface,
                  int source,
                  int source_type,
                  int buffer_scale,
                  int x,
                  int y,
                  int width,
                  int height) -> void
    {
      gdk_cairo_draw_from_gl (context->cobj (),
                              surface->gobj (),
                              source,
                              source_type,
                              buffer_scale,
                              x,
                              y,
                              width,
                              height);
    }

    G_GNUC_END_IGNORE_DEPRECATIONS
#endif

  } // namespace Cairo

} // namespace Gdk
