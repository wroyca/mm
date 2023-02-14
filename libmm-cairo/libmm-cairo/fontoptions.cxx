// SPDX-License-Identifier: LGPL-2.0-or-later

#include <libmm-cairo/fontoptions.hxx>
#include <libmm-cairo/private.hxx>

namespace Cairo
{

  FontOptions::FontOptions ()
    : m_cobject (nullptr)
  {
    m_cobject = cairo_font_options_create ();
    check_object_status_and_throw_exception (*this);
  }

  FontOptions::FontOptions (cairo_font_options_t* cobject,
                            const bool take_ownership)
    : m_cobject (nullptr)
  {
    if (take_ownership)
      m_cobject = cobject;
    else
      m_cobject = cairo_font_options_copy (cobject);

    check_object_status_and_throw_exception (*this);
  }

  FontOptions::FontOptions (const FontOptions& src)
    : m_cobject (nullptr)
  {
    if (!src.m_cobject)
      m_cobject = nullptr;
    else
      m_cobject = cairo_font_options_copy (src.m_cobject);

    check_object_status_and_throw_exception (*this);
  }

  FontOptions::~FontOptions ()
  {
    if (m_cobject)
      cairo_font_options_destroy (m_cobject);
  }

  auto
  FontOptions::operator= (const FontOptions& src) -> FontOptions&
  {
    if (this == &src)
      return *this;

    if (m_cobject == src.m_cobject)
      return *this;

    if (m_cobject)
    {
      cairo_font_options_destroy (m_cobject);
      m_cobject = nullptr;
    }

    if (!src.m_cobject)
      return *this;

    m_cobject = cairo_font_options_copy (src.m_cobject);

    return *this;
  }

  auto
  FontOptions::operator== (const FontOptions& src) const -> bool
  {
    return cairo_font_options_equal (m_cobject, src.cobj ());
  }

  auto
  FontOptions::merge (const FontOptions& src) -> void
  {
    cairo_font_options_merge (m_cobject, src.cobj ());
    check_object_status_and_throw_exception (*this);
  }

  auto
  FontOptions::hash () const -> unsigned long
  {
    const auto result = cairo_font_options_hash (m_cobject);
    check_object_status_and_throw_exception (*this);
    return result;
  }

  auto
  FontOptions::set_antialias (Antialias antialias) -> void
  {
    cairo_font_options_set_antialias (
        m_cobject,
        static_cast<cairo_antialias_t> (antialias));
    check_object_status_and_throw_exception (*this);
  }

  auto
  FontOptions::get_antialias () const -> Antialias
  {
    const auto result =
        static_cast<Antialias> (cairo_font_options_get_antialias (m_cobject));
    check_object_status_and_throw_exception (*this);
    return result;
  }

  auto
  FontOptions::set_subpixel_order (SubpixelOrder subpixel_order) -> void
  {
    cairo_font_options_set_subpixel_order (
        m_cobject,
        static_cast<cairo_subpixel_order_t> (subpixel_order));
    check_object_status_and_throw_exception (*this);
  }

  auto
  FontOptions::get_subpixel_order () const -> SubpixelOrder
  {
    const auto result = static_cast<SubpixelOrder> (
        cairo_font_options_get_subpixel_order (m_cobject));
    check_object_status_and_throw_exception (*this);
    return result;
  }

  auto
  FontOptions::set_hint_style (HintStyle hint_style) -> void
  {
    cairo_font_options_set_hint_style (
        m_cobject,
        static_cast<cairo_hint_style_t> (hint_style));
    check_object_status_and_throw_exception (*this);
  }

  auto
  FontOptions::get_hint_style () const -> HintStyle
  {
    const auto result =
        static_cast<HintStyle> (cairo_font_options_get_hint_style (m_cobject));
    check_object_status_and_throw_exception (*this);
    return result;
  }

  auto
  FontOptions::set_hint_metrics (HintMetrics hint_metrics) -> void
  {
    cairo_font_options_set_hint_metrics (
        m_cobject,
        static_cast<cairo_hint_metrics_t> (hint_metrics));
    check_object_status_and_throw_exception (*this);
  }

  auto
  FontOptions::get_hint_metrics () const -> HintMetrics
  {
    const auto result = static_cast<HintMetrics> (
        cairo_font_options_get_hint_metrics (m_cobject));
    check_object_status_and_throw_exception (*this);
    return result;
  }

#ifdef CAIRO_HAS_FT_FONT
  #ifdef CAIRO_HAS_FC_FONT
  auto
  FontOptions::substitute (FcPattern* pattern) -> void
  {
    cairo_ft_font_options_substitute (cobj (), pattern);
    check_object_status_and_throw_exception (*this);
  }
  #endif
#endif

} // namespace Cairo
