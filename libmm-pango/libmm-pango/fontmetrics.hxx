// SPDX-License-Identifier: LGPL-2.0-or-later

#ifndef _PANGOMM_FONTMETRICS_H
#define _PANGOMM_FONTMETRICS_H

#include <libmm-pango/mm-pangoconfig.hxx>

#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm-glib/value.hxx>
#include <pango/pango.h>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
extern "C"
{
  typedef struct _PangoFontMetrics PangoFontMetrics;
}
#endif

namespace Pango
{

  class PANGOMM_API FontMetrics
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    using CppObjectType = FontMetrics;
    using BaseObjectType = PangoFontMetrics;
#endif

    static auto
    get_type () -> GType G_GNUC_CONST;

    FontMetrics ();

    explicit FontMetrics (PangoFontMetrics* gobject, bool make_a_copy = true);

    FontMetrics (const FontMetrics& other);
    auto
    operator= (const FontMetrics& other) -> FontMetrics&;

    FontMetrics (FontMetrics&& other) noexcept;
    auto
    operator= (FontMetrics&& other) noexcept -> FontMetrics&;

    ~FontMetrics () noexcept;

    auto
    swap (FontMetrics& other) noexcept -> void;

    auto
    gobj () -> PangoFontMetrics*
    {
      return gobject_;
    }

    auto
    gobj () const -> const PangoFontMetrics*
    {
      return gobject_;
    }

    auto
    gobj_copy () const -> PangoFontMetrics*;

  protected:
    PangoFontMetrics* gobject_;

  private:
  public:
    auto
    get_ascent () const -> int;

    auto
    get_descent () const -> int;

    auto
    get_height () const -> int;

    auto
    get_approximate_char_width () const -> int;

    auto
    get_approximate_digit_width () const -> int;

    auto
    get_underline_position () const -> int;

    auto
    get_underline_thickness () const -> int;

    auto
    get_strikethrough_position () const -> int;

    auto
    get_strikethrough_thickness () const -> int;
  };

} // namespace Pango

namespace Pango
{

  inline auto
  swap (FontMetrics& lhs, FontMetrics& rhs) noexcept -> void
  {
    lhs.swap (rhs);
  }

} // namespace Pango

namespace Glib
{

  PANGOMM_API
  auto
  wrap (PangoFontMetrics* object, bool take_copy = false) -> Pango::FontMetrics;

#ifndef DOXYGEN_SHOULD_SKIP_THIS
  template <>
  class PANGOMM_API Value<Pango::FontMetrics>
    : public Glib::Value_Boxed<Pango::FontMetrics>
  {
  };
#endif

} // namespace Glib

#endif
