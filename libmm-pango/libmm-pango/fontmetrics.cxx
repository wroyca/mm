

#include <libmm-glib/mm-glib.hxx>

#include <libmm-pango/fontmetrics.hxx>
#include <libmm-pango/fontmetrics_p.hxx>

namespace
{
}

namespace Glib
{

  auto
  wrap (PangoFontMetrics* object, const bool take_copy) -> Pango::FontMetrics
  {
    return Pango::FontMetrics (object, take_copy);
  }

} // namespace Glib

namespace Pango
{

  auto
  FontMetrics::get_type () -> GType
  {
    return pango_font_metrics_get_type ();
  }

  FontMetrics::FontMetrics ()
    : gobject_ (nullptr)
  {
  }

  FontMetrics::FontMetrics (const FontMetrics& other)
    : gobject_ (other.gobject_ ? pango_font_metrics_ref (other.gobject_) :
                                 nullptr)
  {
  }

  FontMetrics::FontMetrics (FontMetrics&& other) noexcept
    : gobject_ (other.gobject_)
  {
    other.gobject_ = nullptr;
  }

  auto
  FontMetrics::operator= (FontMetrics&& other) noexcept -> FontMetrics&
  {
    FontMetrics temp (std::move (other));
    swap (temp);
    return *this;
  }

  FontMetrics::FontMetrics (PangoFontMetrics* gobject, const bool make_a_copy)
    : gobject_ (make_a_copy && gobject ? pango_font_metrics_ref (gobject) :
                                         gobject)
  {
  }

  auto
  FontMetrics::operator= (const FontMetrics& other) -> FontMetrics&
  {
    FontMetrics temp (other);
    swap (temp);
    return *this;
  }

  FontMetrics::~FontMetrics () noexcept
  {
    if (gobject_)
      pango_font_metrics_unref (gobject_);
  }

  auto
  FontMetrics::swap (FontMetrics& other) noexcept -> void
  {
    std::swap (gobject_, other.gobject_);
  }

  auto
  FontMetrics::gobj_copy () const -> PangoFontMetrics*
  {
    return pango_font_metrics_ref (gobject_);
  }

  auto
  FontMetrics::get_ascent () const -> int
  {
    return pango_font_metrics_get_ascent (
        const_cast<PangoFontMetrics*> (gobj ()));
  }

  auto
  FontMetrics::get_descent () const -> int
  {
    return pango_font_metrics_get_descent (
        const_cast<PangoFontMetrics*> (gobj ()));
  }

  auto
  FontMetrics::get_height () const -> int
  {
    return pango_font_metrics_get_height (
        const_cast<PangoFontMetrics*> (gobj ()));
  }

  auto
  FontMetrics::get_approximate_char_width () const -> int
  {
    return pango_font_metrics_get_approximate_char_width (
        const_cast<PangoFontMetrics*> (gobj ()));
  }

  auto
  FontMetrics::get_approximate_digit_width () const -> int
  {
    return pango_font_metrics_get_approximate_digit_width (
        const_cast<PangoFontMetrics*> (gobj ()));
  }

  auto
  FontMetrics::get_underline_position () const -> int
  {
    return pango_font_metrics_get_underline_position (
        const_cast<PangoFontMetrics*> (gobj ()));
  }

  auto
  FontMetrics::get_underline_thickness () const -> int
  {
    return pango_font_metrics_get_underline_thickness (
        const_cast<PangoFontMetrics*> (gobj ()));
  }

  auto
  FontMetrics::get_strikethrough_position () const -> int
  {
    return pango_font_metrics_get_strikethrough_position (
        const_cast<PangoFontMetrics*> (gobj ()));
  }

  auto
  FontMetrics::get_strikethrough_thickness () const -> int
  {
    return pango_font_metrics_get_strikethrough_thickness (
        const_cast<PangoFontMetrics*> (gobj ()));
  }

} // namespace Pango
