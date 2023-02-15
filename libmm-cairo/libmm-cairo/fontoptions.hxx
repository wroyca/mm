// SPDX-License-Identifier: LGPL-2.0-or-later

#ifndef __CAIROMM_FONTOPTIONS_H
#define __CAIROMM_FONTOPTIONS_H

#include <libmm-cairo/mm-cairoconfig.hxx>

#include <libmm-cairo/enums.hxx>
#include <string>

#ifdef CAIRO_HAS_FT_FONT
  #include <cairo-ft.h>
#endif

namespace Cairo
{

  class CAIROMM_API FontOptions
  {
  public:
    enum class HintStyle
    {
      DEFAULT = CAIRO_HINT_STYLE_DEFAULT,

      NONE = CAIRO_HINT_STYLE_NONE,

      SLIGHT = CAIRO_HINT_STYLE_SLIGHT,

      MEDIUM = CAIRO_HINT_STYLE_MEDIUM,

      FULL = CAIRO_HINT_STYLE_FULL
    };

    enum class HintMetrics
    {
      DEFAULT = CAIRO_HINT_METRICS_DEFAULT,

      OFF = CAIRO_HINT_METRICS_OFF,

      ON = CAIRO_HINT_METRICS_ON
    };

    FontOptions ();
    explicit FontOptions (cairo_font_options_t* cobject,
                          bool take_ownership = false);
    FontOptions (const FontOptions& src);

    virtual ~FontOptions ();

    auto
    operator= (const FontOptions& src) -> FontOptions&;

    auto
    operator== (const FontOptions& src) const -> bool;

    auto
    merge (const FontOptions& other) -> void;

    auto
    hash () const -> unsigned long;

    auto
    set_antialias (Antialias antialias) -> void;

    auto
    get_antialias () const -> Antialias;

    auto
    set_subpixel_order (SubpixelOrder subpixel_order) -> void;

    auto
    get_subpixel_order () const -> SubpixelOrder;

    auto
    set_hint_style (HintStyle hint_style) -> void;

    auto
    get_hint_style () const -> HintStyle;

    auto
    set_hint_metrics (HintMetrics hint_metrics) -> void;

    auto
    get_hint_metrics () const -> HintMetrics;

#ifdef CAIRO_HAS_FT_FONT
  #ifdef CAIRO_HAS_FC_FONT

    auto
    substitute (FcPattern* pattern) -> void;
  #endif
#endif

    typedef cairo_font_options_t cobject;

    inline auto
    cobj () -> cobject*
    {
      return m_cobject;
    }

    inline auto
    cobj () const -> const cobject*
    {
      return m_cobject;
    }

#ifndef DOXYGEN_IGNORE_THIS

    inline auto
    get_status () const -> ErrorStatus
    {
      return cairo_font_options_status (
          const_cast<cairo_font_options_t*> (cobj ()));
    }
#endif

  protected:
    cobject* m_cobject;
  };

} // namespace Cairo

#endif
