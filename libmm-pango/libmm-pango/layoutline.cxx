

#include <libmm-glib/mm-glib.hxx>

#include <libmm-pango/layoutline.hxx>
#include <libmm-pango/layoutline_p.hxx>

#include <libmm-pango/layout.hxx>
#include <pango/pangocairo.h>

namespace Pango
{

  auto
  LayoutLine::get_ink_extents () const -> Rectangle
  {
    Rectangle ink_rect;
    pango_layout_line_get_extents (const_cast<PangoLayoutLine*> (gobj ()),
                                   ink_rect.gobj (),
                                   0);
    return ink_rect;
  }

  auto
  LayoutLine::get_logical_extents () const -> Rectangle
  {
    Rectangle logical_rect;
    pango_layout_line_get_extents (const_cast<PangoLayoutLine*> (gobj ()),
                                   0,
                                   logical_rect.gobj ());
    return logical_rect;
  }

  auto
  LayoutLine::get_pixel_ink_extents () const -> Rectangle
  {
    Rectangle ink_rect;
    pango_layout_line_get_pixel_extents (const_cast<PangoLayoutLine*> (gobj ()),
                                         ink_rect.gobj (),
                                         0);
    return ink_rect;
  }

  auto
  LayoutLine::get_pixel_logical_extents () const -> Rectangle
  {
    Rectangle logical_rect;
    pango_layout_line_get_pixel_extents (const_cast<PangoLayoutLine*> (gobj ()),
                                         0,
                                         logical_rect.gobj ());
    return logical_rect;
  }

  auto
  LayoutLine::index_to_x (const int index, const bool trailing) const -> int
  {
    int x_pos;
    pango_layout_line_index_to_x (const_cast<PangoLayoutLine*> (gobj ()),
                                  index,
                                  trailing,
                                  &x_pos);
    return x_pos;
  }

  auto
  LayoutLine::get_x_ranges (const int start_index, const int end_index) const -> std::vector<std::pair<int, int>>
  {
    int* ranges = nullptr;
    int n_ranges = 0;
    pango_layout_line_get_x_ranges (const_cast<PangoLayoutLine*> (gobj ()),
                                    start_index,
                                    end_index,
                                    &ranges,
                                    &n_ranges);
    return Glib::ArrayHandler<std::pair<int, int>>::array_to_vector (
        reinterpret_cast<std::pair<int, int>*> (ranges),
        n_ranges,
        Glib::OWNERSHIP_SHALLOW);
  }

  auto
  LayoutLine::show_in_cairo_context (
      const Cairo::RefPtr<Cairo::Context>& context) -> void
  {
    pango_cairo_show_layout_line (context->cobj (), gobj ());
  }

  auto
  LayoutLine::add_to_cairo_context (
      const Cairo::RefPtr<Cairo::Context>& context) -> void
  {
    pango_cairo_layout_line_path (context->cobj (), gobj ());
  }

} // namespace Pango

namespace
{
}

namespace Glib
{

  auto
  wrap (PangoLayoutLine* object, const bool take_copy) -> RefPtr<Pango::LayoutLine>
  {
    if (take_copy && object)
      pango_layout_line_ref (object);

    return Glib::make_refptr_for_instance<Pango::LayoutLine> (
        reinterpret_cast<Pango::LayoutLine*> (object));
  }

} // namespace Glib

namespace Pango
{

  auto
  LayoutLine::reference () const -> void
  {
    pango_layout_line_ref (
        reinterpret_cast<PangoLayoutLine*> (const_cast<LayoutLine*> (this)));
  }

  auto
  LayoutLine::unreference () const -> void
  {
    pango_layout_line_unref (
        reinterpret_cast<PangoLayoutLine*> (const_cast<LayoutLine*> (this)));
  }

  auto
  LayoutLine::gobj () -> PangoLayoutLine*
  {
    return reinterpret_cast<PangoLayoutLine*> (this);
  }

  auto
  LayoutLine::gobj () const -> const PangoLayoutLine*
  {
    return reinterpret_cast<const PangoLayoutLine*> (this);
  }

  auto
  LayoutLine::gobj_copy () const -> PangoLayoutLine*
  {
    const auto gobject =
        reinterpret_cast<PangoLayoutLine*> (const_cast<LayoutLine*> (this));
    pango_layout_line_ref (gobject);
    return gobject;
  }

  auto
  LayoutLine::x_to_index (const int x_pos, int& index, int& trailing) const -> bool
  {
    return pango_layout_line_x_to_index (const_cast<PangoLayoutLine*> (gobj ()),
                                         x_pos,
                                         &index,
                                         &trailing);
  }

  auto
  LayoutLine::get_extents (Rectangle& ink_rect, Rectangle& logical_rect) const -> void
  {
    pango_layout_line_get_extents (const_cast<PangoLayoutLine*> (gobj ()),
                                   ink_rect.gobj (),
                                   logical_rect.gobj ());
  }

  auto
  LayoutLine::get_pixel_extents (Rectangle& ink_rect,
                                 Rectangle& logical_rect) const -> void
  {
    pango_layout_line_get_pixel_extents (const_cast<PangoLayoutLine*> (gobj ()),
                                         ink_rect.gobj (),
                                         logical_rect.gobj ());
  }

  auto
  LayoutLine::get_layout () -> Glib::RefPtr<Layout>
  {
    Glib::RefPtr<Layout> ref_ptr (Glib::wrap (gobj ()->layout));

    if (ref_ptr)
      ref_ptr->reference ();

    return ref_ptr;
  }

  auto
  LayoutLine::get_layout () const -> Glib::RefPtr<const Layout>
  {
    Glib::RefPtr<const Layout> ref_ptr (Glib::wrap (gobj ()->layout));

    if (ref_ptr)
      ref_ptr->reference ();

    return ref_ptr;
  }

  auto
  LayoutLine::get_length () const -> int
  {
    return gobj ()->length;
  }

  auto
  LayoutLine::get_start_index () const -> int
  {
    return gobj ()->start_index;
  }

} // namespace Pango
