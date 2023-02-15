// SPDX-License-Identifier: LGPL-2.0-or-later

#ifndef _PANGOMM_FONTDESCRIPTION_H
#define _PANGOMM_FONTDESCRIPTION_H

#include <libmm-pango/mm-pangoconfig.hxx>

#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm-glib/value.hxx>
#include <pango/pango.h>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
extern "C"
{
  typedef struct _PangoFontDescription PangoFontDescription;
}
#endif

namespace Pango
{

  enum class Style
  {
    NORMAL,
    OBLIQUE,
    ITALIC
  };

} // namespace Pango

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

  template <>
  class PANGOMM_API Value<Pango::Style> : public Glib::Value_Enum<Pango::Style>
  {
  public:
    static auto
    value_type () -> GType G_GNUC_CONST;
  };

} // namespace Glib
#endif

namespace Pango
{

  enum class Variant
  {
    NORMAL,
    SMALL_CAPS,
    ALL_SMALL_CAPS,
    PETITE_CAPS,
    ALL_PETITE_CAPS,
    UNICASE,
    TITLE_CAPS
  };

} // namespace Pango

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

  template <>
  class PANGOMM_API Value<Pango::Variant>
    : public Glib::Value_Enum<Pango::Variant>
  {
  public:
    static auto
    value_type () -> GType G_GNUC_CONST;
  };

} // namespace Glib
#endif

namespace Pango
{

  enum class Stretch
  {
    ULTRA_CONDENSED,
    EXTRA_CONDENSED,
    CONDENSED,
    SEMI_CONDENSED,
    NORMAL,
    SEMI_EXPANDED,
    EXPANDED,
    EXTRA_EXPANDED,
    ULTRA_EXPANDED
  };

} // namespace Pango

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

  template <>
  class PANGOMM_API Value<Pango::Stretch>
    : public Glib::Value_Enum<Pango::Stretch>
  {
  public:
    static auto
    value_type () -> GType G_GNUC_CONST;
  };

} // namespace Glib
#endif

namespace Pango
{

  class Weight_Wrapper final
  {
  public:
    enum Weight
    {
      THIN = 100,
      ULTRALIGHT = 200,
      LIGHT = 300,
      SEMILIGHT = 350,
      BOOK = 380,
      NORMAL = 400,
      MEDIUM = 500,
      SEMIBOLD = 600,
      BOLD = 700,
      ULTRABOLD = 800,
      HEAVY = 900,
      ULTRAHEAVY = 1000
    };
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    Weight_Wrapper () = delete;
#endif
  };

  using Weight = Weight_Wrapper::Weight;

} // namespace Pango

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

  template <>
  class PANGOMM_API Value<Pango::Weight>
    : public Glib::Value_Enum<Pango::Weight>
  {
  public:
    static auto
    value_type () -> GType G_GNUC_CONST;
  };

} // namespace Glib
#endif

namespace Pango
{

  enum class FontMask
  {
    FAMILY = 1 << 0,
    STYLE = 1 << 1,
    VARIANT = 1 << 2,
    WEIGHT = 1 << 3,
    STRETCH = 1 << 4,
    SIZE = 1 << 5,
    GRAVITY = 1 << 6,
    VARIATIONS = 1 << 7
  };

  inline auto
  operator| (FontMask lhs, FontMask rhs) -> FontMask
  {
    return static_cast<FontMask> (static_cast<unsigned> (lhs) |
                                  static_cast<unsigned> (rhs));
  }

  inline auto
  operator& (FontMask lhs, FontMask rhs) -> FontMask
  {
    return static_cast<FontMask> (static_cast<unsigned> (lhs) &
                                  static_cast<unsigned> (rhs));
  }

  inline auto
  operator^ (FontMask lhs, FontMask rhs) -> FontMask
  {
    return static_cast<FontMask> (static_cast<unsigned> (lhs) ^
                                  static_cast<unsigned> (rhs));
  }

  inline auto
  operator~(FontMask flags) -> FontMask
  {
    return static_cast<FontMask> (~static_cast<unsigned> (flags));
  }

  inline auto
  operator|= (FontMask& lhs, FontMask rhs) -> FontMask&
  {
    return (lhs = static_cast<FontMask> (static_cast<unsigned> (lhs) |
                                         static_cast<unsigned> (rhs)));
  }

  inline auto
  operator&= (FontMask& lhs, FontMask rhs) -> FontMask&
  {
    return (lhs = static_cast<FontMask> (static_cast<unsigned> (lhs) &
                                         static_cast<unsigned> (rhs)));
  }

  inline auto
  operator^= (FontMask& lhs, FontMask rhs) -> FontMask&
  {
    return (lhs = static_cast<FontMask> (static_cast<unsigned> (lhs) ^
                                         static_cast<unsigned> (rhs)));
  }

} // namespace Pango

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

  template <>
  class PANGOMM_API Value<Pango::FontMask>
    : public Glib::Value_Flags<Pango::FontMask>
  {
  public:
    static auto
    value_type () -> GType G_GNUC_CONST;
  };

} // namespace Glib
#endif

namespace Pango
{

  enum class Gravity
  {
    SOUTH,
    EAST,
    NORTH,
    WEST,
    AUTO
  };

} // namespace Pango

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

  template <>
  class PANGOMM_API Value<Pango::Gravity>
    : public Glib::Value_Enum<Pango::Gravity>
  {
  public:
    static auto
    value_type () -> GType G_GNUC_CONST;
  };

} // namespace Glib
#endif

namespace Pango
{

  class PANGOMM_API FontDescription
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    using CppObjectType = FontDescription;
    using BaseObjectType = PangoFontDescription;
#endif

    static auto
    get_type () -> GType G_GNUC_CONST;

    FontDescription ();

    explicit FontDescription (PangoFontDescription* gobject,
                              bool make_a_copy = true);

    FontDescription (const FontDescription& other);
    auto
    operator= (const FontDescription& other) -> FontDescription&;

    FontDescription (FontDescription&& other) noexcept;
    auto
    operator= (FontDescription&& other) noexcept -> FontDescription&;

    ~FontDescription () noexcept;

    auto
    swap (FontDescription& other) noexcept -> void;

    auto
    gobj () -> PangoFontDescription*
    {
      return gobject_;
    }

    auto
    gobj () const -> const PangoFontDescription*
    {
      return gobject_;
    }

    auto
    gobj_copy () const -> PangoFontDescription*;

  protected:
    PangoFontDescription* gobject_;

  private:
  public:
    explicit FontDescription (const Glib::ustring& font_name);

    auto
    hash () const -> guint;

    auto
    set_family (const Glib::ustring& family) -> void;

    auto
    get_family () const -> Glib::ustring;

    auto
    set_style (Style style) -> void;

    auto
    get_style () const -> Style;

    auto
    set_variant (Variant variant) -> void;

    auto
    get_variant () const -> Variant;

    auto
    set_weight (Weight weight) -> void;

    auto
    get_weight () const -> Weight;

    auto
    set_stretch (Stretch stretch) -> void;

    auto
    get_stretch () const -> Stretch;

    auto
    set_size (int size) -> void;

    auto
    get_size () const -> int;

    auto
    set_absolute_size (double size) -> void;

    auto
    get_size_is_absolute () const -> bool;

    auto
    set_gravity (Gravity gravity) -> void;

    auto
    get_gravity () const -> Gravity;

    auto
    set_variations (const Glib::ustring& settings) -> void;

    auto
    get_variations () const -> Glib::ustring;

    auto
    get_set_fields () const -> FontMask;

    auto
    unset_fields (FontMask to_unset) -> void;

    auto
    merge (const FontDescription& desc_to_merge, bool replace_existing) -> void;

    auto
    better_match (const FontDescription& old_match,
                  const FontDescription& new_match) const -> bool;

    auto
    to_string () const -> Glib::ustring;

    auto
    to_filename () const -> Glib::ustring;
  };

} // namespace Pango

namespace Pango
{

  PANGOMM_API
  auto
  operator== (const FontDescription& lhs, const FontDescription& rhs) -> bool;

  PANGOMM_API
  auto
  operator!= (const FontDescription& lhs, const FontDescription& rhs) -> bool;

} // namespace Pango

namespace Pango
{

  inline auto
  swap (FontDescription& lhs, FontDescription& rhs) noexcept -> void
  {
    lhs.swap (rhs);
  }

} // namespace Pango

namespace Glib
{

  PANGOMM_API
  auto
  wrap (PangoFontDescription* object, bool take_copy = false) -> Pango::FontDescription;

#ifndef DOXYGEN_SHOULD_SKIP_THIS
  template <>
  class PANGOMM_API Value<Pango::FontDescription>
    : public Glib::Value_Boxed<Pango::FontDescription>
  {
  };
#endif

} // namespace Glib

#endif
