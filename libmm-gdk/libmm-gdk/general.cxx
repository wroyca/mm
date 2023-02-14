// SPDX-License-Identifier: LGPL-2.1-or-later

#include <gdk/gdk.h>
#include <libmm-gdk/cairoutils.hxx>
#include <libmm-gdk/general.hxx>

namespace Gdk::Cairo
{

  auto
  set_source_rgba (const ::Cairo::RefPtr<::Cairo::Context>& context,
                   const RGBA& color) -> void
  {
    gdk_cairo_set_source_rgba (context->cobj (), color.gobj ());
  }

  auto
  set_source_pixbuf (const ::Cairo::RefPtr<::Cairo::Context>& context,
                     const Glib::RefPtr<const Pixbuf>& pixbuf,
                     const double pixbuf_x,
                     const double pixbuf_y) -> void
  {
    gdk_cairo_set_source_pixbuf (context->cobj (),
                                 pixbuf->gobj (),
                                 pixbuf_x,
                                 pixbuf_y);
  }

  auto
  add_rectangle_to_path (const ::Cairo::RefPtr<::Cairo::Context>& context,
                         const Rectangle& rectangle) -> void
  {
    gdk_cairo_rectangle (context->cobj (), rectangle.gobj ());
  }

  auto
  add_region_to_path (const ::Cairo::RefPtr<::Cairo::Context>& context,
                      const ::Cairo::RefPtr<::Cairo::Region>& region) -> void
  {
    gdk_cairo_region (context->cobj (), region ? region->cobj () : nullptr);
  }

  auto
  create_region_from_surface (const ::Cairo::RefPtr<::Cairo::Surface>& surface) -> ::Cairo::RefPtr<::Cairo::Region>
  {
    return wrap (gdk_cairo_region_create_from_surface (surface->cobj ()), true);
  }

#ifndef GDKMM_DISABLE_DEPRECATED
  G_GNUC_BEGIN_IGNORE_DEPRECATIONS
  auto
  draw_from_gl (const ::Cairo::RefPtr<::Cairo::Context>& context,
                const Glib::RefPtr<Surface>& surface,
                const int source,
                const int source_type,
                const int buffer_scale,
                const int x,
                const int y,
                const int width,
                const int height) -> void
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

} // namespace Gdk::Cairo
