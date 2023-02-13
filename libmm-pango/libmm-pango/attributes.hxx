
#ifndef _PANGOMM_ATTRIBUTES_H
#define _PANGOMM_ATTRIBUTES_H


#include <libmm-glib/ustring.hpp>
#include <sigc++/sigc++.h>

/* attributes.h
 *
 * Copyright (C) 2002 The gtkmm Development Team
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free
 * Software Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 */

#include <libmm-pango/language.hpp>
#include <libmm-pango/rectangle.hpp>
#include <libmm-pango/color.hpp>
#include <libmm-pango/fontdescription.hpp>
#include <pango/pango.h>


namespace Pango
{
/** @addtogroup pangommEnums pangomm Enums and Flags */

/**  Pango::AttrType distinguishes between different types of attributes.
 * Along with the predefined values, it is possible to allocate additional values for
 * custom attributes using Pango::Attribute::register_type(). The predefined values
 * are given below. The type of structure used to store the
 * attribute is listed in parentheses after the description.
 *  @var AttrType INVALID
 * Does not happen.
 *
 *  @var AttrType LANGUAGE
 * Language (Pango::AttrLanguage).
 *
 *  @var AttrType FAMILY
 * Font family name list (Pango::AttrString).
 *
 *  @var AttrType STYLE
 * Font slant style (Pango::AttrInt).
 *
 *  @var AttrType WEIGHT
 * Font weight (Pango::AttrInt).
 *
 *  @var AttrType VARIANT
 * Font variant (normal or small caps) (Pango::AttrInt).
 *
 *  @var AttrType STRETCH
 * Font stretch (Pango::AttrInt).
 *
 *  @var AttrType SIZE
 * Font size in points scaled by Pango::SCALE (Pango::AttrInt).
 *
 *  @var AttrType FONT_DESC
 * Font description (Pango::AttrFontDesc).
 *
 *  @var AttrType FOREGROUND
 * Foreground color (Pango::AttrColor).
 *
 *  @var AttrType BACKGROUND
 * Background color (Pango::AttrColor).
 *
 *  @var AttrType UNDERLINE
 * Whether the text has an underline (Pango::AttrInt).
 *
 *  @var AttrType STRIKETHROUGH
 * Whether the text is struck-through (Pango::AttrInt).
 *
 *  @var AttrType RISE
 * Baseline displacement (Pango::AttrInt).
 *
 *  @var AttrType SHAPE
 * Shape (Pango::AttrShape).
 *
 *  @var AttrType SCALE_FACTOR
 * Font size scale factor (Pango::AttrFloat).
 *
 *  @var AttrType FALLBACK
 * Whether fallback is enabled (Pango::AttrInt).
 *
 *  @var AttrType LETTER_SPACING
 * Letter spacing (Pango::PangoAttrInt).
 *
 *  @var AttrType UNDERLINE_COLOR
 * Underline color (Pango::AttrColor).
 *
 *  @var AttrType STRIKETHROUGH_COLOR
 * Strikethrough color (Pango::AttrColor).
 *
 *  @var AttrType ABSOLUTE_SIZE
 * Font size in pixels scaled by Pango::SCALE (Pango::AttrInt).
 *
 *  @var AttrType GRAVITY
 * Base text gravity (Pango::AttrInt).
 *
 *  @var AttrType GRAVITY_HINT
 * Gravity hint (Pango::AttrInt).
 *
 *  @var AttrType FONT_FEATURES
 * OpenType font features (Pango::AttrFontFeatures). @newin{1,38}
 *
 *  @var AttrType FOREGROUND_ALPHA
 * Foreground alpha (Pango::AttrInt). @newin{1,38}
 *
 *  @var AttrType BACKGROUND_ALPHA
 * Background alpha (Pango::AttrInt). @newin{1,38}
 *
 *  @var AttrType ALLOW_BREAKS
 * Whether breaks are allowed (Pango::AttrInt). @newin{1,44}
 *
 *  @var AttrType SHOW
 * How to render invisible characters (Pango::AttrInt). @newin{1,44}
 *
 *  @var AttrType INSERT_HYPHENS
 * Whether to insert hyphens at intra-word line breaks (Pango::AttrInt). @newin{1,44}
 *
 *  @var AttrType OVERLINE
 * Whether the text has an overline (Pango::AttrInt). @newin{1,46}
 *
 *  @var AttrType OVERLINE_COLOR
 * Overline color (Pango::AttrColor). @newin{1,46}
 *
 *  @var AttrType LINE_HEIGHT
 * Line height factor (Pango::AttrFloat). @newin{1,50}
 *
 *  @var AttrType ABSOLUTE_LINE_HEIGHT
 * Line height (Pango::AttrInt). @newin{1,50}
 *
 *  @var AttrType WORD
 * Override segmentation to classify the range of the attribute as a single word (Pango::AttrInt). @newin{1,50}
 *
 *  @var AttrType SENTENCE
 * Override segmentation to classify the range of the attribute as a single sentence (Pango::AttrInt). @newin{1,50}
 *
 *  @var AttrType BASELINE_SHIFT
 * Baseline displacement (Pango::AttrInt). @newin{1,50}
 *
 *  @var AttrType FONT_SCALE
 * Font-relative size change (Pango::AttrInt). @newin{1,50}
 *
 *  @enum AttrType
 *
 * The `Pango::AttrType` distinguishes between different types of attributes.
 *
 * Along with the predefined values, it is possible to allocate additional
 * values for custom attributes using attr_type_register(). The predefined
 * values are given below. The type of structure used to store the attribute is
 * listed in parentheses after the description.
 *
 * @ingroup pangommEnums
 */
enum class AttrType
{
  INVALID,
  LANGUAGE,
  FAMILY,
  STYLE,
  WEIGHT,
  VARIANT,
  STRETCH,
  SIZE,
  FONT_DESC,
  FOREGROUND,
  BACKGROUND,
  UNDERLINE,
  STRIKETHROUGH,
  RISE,
  SHAPE,
  SCALE_FACTOR,
  FALLBACK,
  LETTER_SPACING,
  UNDERLINE_COLOR,
  STRIKETHROUGH_COLOR,
  ABSOLUTE_SIZE,
  GRAVITY,
  GRAVITY_HINT,
  FONT_FEATURES,
  FOREGROUND_ALPHA,
  BACKGROUND_ALPHA,
  ALLOW_BREAKS,
  SHOW,
  INSERT_HYPHENS,
  OVERLINE,
  OVERLINE_COLOR,
  LINE_HEIGHT,
  ABSOLUTE_LINE_HEIGHT,
  TEXT_TRANSFORM,
  WORD,
  SENTENCE,
  BASELINE_SHIFT,
  FONT_SCALE
};


} // namespace Pango

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

template <>
class PANGOMM_API Value<Pango::AttrType> : public Glib::Value_Enum<Pango::AttrType>
{
public:
  static auto value_type() -> GType G_GNUC_CONST;
};

} // namespace Glib
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

namespace Pango
{

// gcc complains that SCALE shadows the global constant SCALE from font.h.

/**
 *  @var Underline NONE
 * No underline should be drawn.
 *
 *  @var Underline SINGLE
 * A single underline should be drawn.
 *
 *  @var Underline DOUBLE
 * A double underline should be drawn.
 *
 *  @var Underline LOW
 * A single underline should be drawn at a
 * position beneath the ink extents of the text being
 * underlined. This should be used only for underlining
 * single characters, such as for keyboard accelerators.
 * Pango::Underline::SINGLE should be used for extended
 * portions of text.
 *
 *  @var Underline ERROR
 * An underline indicating an error should
 * be drawn below. The exact style of rendering is up to the
 * `Pango::Renderer` in use, but typical styles include wavy
 * or dotted lines.
 * This underline is typically used to indicate an error such
 * as a possible mispelling; in some cases a contrasting color
 * may automatically be used. This type of underlining is
 * available since Pango 1.4.
 *
 *  @var Underline SINGLE_LINE
 * Like @a PANGO_UNDERLINE_SINGLE, but
 * drawn continuously across multiple runs. This type
 * of underlining is available since Pango 1.46.
 *
 *  @var Underline DOUBLE_LINE
 * Like @a PANGO_UNDERLINE_DOUBLE, but
 * drawn continuously across multiple runs. This type
 * of underlining is available since Pango 1.46.
 *
 *  @var Underline ERROR_LINE
 * Like @a PANGO_UNDERLINE_ERROR, but
 * drawn continuously across multiple runs. This type
 * of underlining is available since Pango 1.46.
 *
 *  @enum Underline
 *
 * The `Pango::Underline` enumeration is used to specify whether text
 * should be underlined, and if so, the type of underlining.
 *
 * @ingroup pangommEnums
 */
enum class Underline
{
  NONE,
  SINGLE,
  DOUBLE,
  LOW,
  ERROR,
  SINGLE_LINE,
  DOUBLE_LINE,
  ERROR_LINE
};


} // namespace Pango

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

template <>
class PANGOMM_API Value<Pango::Underline> : public Glib::Value_Enum<Pango::Underline>
{
public:
  static auto value_type() -> GType G_GNUC_CONST;
};

} // namespace Glib
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

namespace Pango
{

/**
 *  @var Overline NONE
 * No overline should be drawn.
 *
 *  @var Overline SINGLE
 * Draw a single line above the ink
 * extents of the text being underlined.
 *
 *  @enum Overline
 *
 * The `Pango::Overline` enumeration is used to specify whether text
 * should be overlined, and if so, the type of line.
 *
 * @newin{1,46}
 *
 * @ingroup pangommEnums
 */
enum class Overline
{
  NONE,
  SINGLE
};


} // namespace Pango

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

template <>
class PANGOMM_API Value<Pango::Overline> : public Glib::Value_Enum<Pango::Overline>
{
public:
  static auto value_type() -> GType G_GNUC_CONST;
};

} // namespace Glib
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

namespace Pango
{

/**
 *  @var ShowFlags NONE
 * No special treatment for invisible characters.
 *
 *  @var ShowFlags SPACES
 * Render spaces, tabs and newlines visibly.
 *
 *  @var ShowFlags LINE_BREAKS
 * Render line breaks visibly.
 *
 *  @var ShowFlags IGNORABLES
 * Render default-ignorable Unicode
 * characters visibly.
 *
 *  @enum ShowFlags
 *
 * These flags affect how Pango treats characters that are normally
 * not visible in the output.
 *
 * @newin{1,44}
 *
 * @ingroup pangommEnums
 * @par Bitwise operators:
 * <tt>ShowFlags operator|(ShowFlags, ShowFlags)</tt><br>
 * <tt>ShowFlags operator&(ShowFlags, ShowFlags)</tt><br>
 * <tt>ShowFlags operator^(ShowFlags, ShowFlags)</tt><br>
 * <tt>ShowFlags operator~(ShowFlags)</tt><br>
 * <tt>ShowFlags& operator|=(ShowFlags&, ShowFlags)</tt><br>
 * <tt>ShowFlags& operator&=(ShowFlags&, ShowFlags)</tt><br>
 * <tt>ShowFlags& operator^=(ShowFlags&, ShowFlags)</tt><br>
 */
enum class ShowFlags
{
  NONE = 0x0,
  SPACES = 1 << 0,
  LINE_BREAKS = 1 << 1,
  IGNORABLES = 1 << 2
};

/** @ingroup pangommEnums */
inline auto operator|(ShowFlags lhs, ShowFlags rhs) -> ShowFlags
  { return static_cast<ShowFlags>(static_cast<unsigned>(lhs) | static_cast<unsigned>(rhs)); }

/** @ingroup pangommEnums */
inline auto operator&(ShowFlags lhs, ShowFlags rhs) -> ShowFlags
  { return static_cast<ShowFlags>(static_cast<unsigned>(lhs) & static_cast<unsigned>(rhs)); }

/** @ingroup pangommEnums */
inline auto operator^(ShowFlags lhs, ShowFlags rhs) -> ShowFlags
  { return static_cast<ShowFlags>(static_cast<unsigned>(lhs) ^ static_cast<unsigned>(rhs)); }

/** @ingroup pangommEnums */
inline auto operator~(ShowFlags flags) -> ShowFlags
  { return static_cast<ShowFlags>(~static_cast<unsigned>(flags)); }

/** @ingroup pangommEnums */
inline auto operator|=(ShowFlags& lhs, ShowFlags rhs) -> ShowFlags&
  { return (lhs = static_cast<ShowFlags>(static_cast<unsigned>(lhs) | static_cast<unsigned>(rhs))); }

/** @ingroup pangommEnums */
inline auto operator&=(ShowFlags& lhs, ShowFlags rhs) -> ShowFlags&
  { return (lhs = static_cast<ShowFlags>(static_cast<unsigned>(lhs) & static_cast<unsigned>(rhs))); }

/** @ingroup pangommEnums */
inline auto operator^=(ShowFlags& lhs, ShowFlags rhs) -> ShowFlags&
  { return (lhs = static_cast<ShowFlags>(static_cast<unsigned>(lhs) ^ static_cast<unsigned>(rhs))); }


} // namespace Pango

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

template <>
class PANGOMM_API Value<Pango::ShowFlags> : public Glib::Value_Flags<Pango::ShowFlags>
{
public:
  static auto value_type() -> GType G_GNUC_CONST;
};

} // namespace Glib
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

namespace Pango
{

/**
 *  @var TextTransform NONE
 * Leave text unchanged.
 *
 *  @var TextTransform LOWERCASE
 * Display letters and numbers as lowercase.
 *
 *  @var TextTransform UPPERCASE
 * Display letters and numbers as uppercase.
 *
 *  @var TextTransform CAPITALIZE
 * Display the first character of a word
 * in titlecase.
 *
 *  @enum TextTransform
 *
 * An enumeration that affects how Pango treats characters during shaping.
 *
 * @newin{2,50}
 *
 * @ingroup pangommEnums
 */
enum class TextTransform
{
  NONE,
  LOWERCASE,
  UPPERCASE,
  CAPITALIZE
};


} // namespace Pango

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

template <>
class PANGOMM_API Value<Pango::TextTransform> : public Glib::Value_Enum<Pango::TextTransform>
{
public:
  static auto value_type() -> GType G_GNUC_CONST;
};

} // namespace Glib
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

namespace Pango
{

/** Wrapper for enum BaselineShift.
 * BaselineShift enumerators are scoped and can be implicitly converted to int.
 * The scope is Pango::BaselineShift::
 *
 * @ingroup pangommEnums
 */
class BaselineShift_Wrapper final
{
public:
  /**
   *  @var BaselineShift NONE
   * Leave the baseline unchanged.
   *
   *  @var BaselineShift SUPERSCRIPT
   * Shift the baseline to the superscript position,
   * relative to the previous run.
   *
   *  @var BaselineShift SUBSCRIPT
   * Shift the baseline to the subscript position,
   * relative to the previous run.
   *
   *  @enum BaselineShift
   *
   * An enumeration that affects baseline shifts between runs.
   *
   * @newin{2,50}
   *
   * @ingroup pangommEnums
   */
  enum BaselineShift
  {
    NONE,
    SUPERSCRIPT,
    SUBSCRIPT
  };
  #ifndef DOXYGEN_SHOULD_SKIP_THIS
  BaselineShift_Wrapper() = delete;
  #endif
};
/** BaselineShift enumerators are scoped by the wrapper class
 * and can be implicitly converted to int.
 *
 * @ingroup pangommEnums
 */
using BaselineShift = BaselineShift_Wrapper::BaselineShift;


} // namespace Pango

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

template <>
class PANGOMM_API Value<Pango::BaselineShift> : public Glib::Value_Enum<Pango::BaselineShift>
{
public:
  static auto value_type() -> GType G_GNUC_CONST;
};

} // namespace Glib
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

namespace Pango
{

/**
 *  @var FontScale NONE
 * Leave the font size unchanged.
 *
 *  @var FontScale SUPERSCRIPT
 * Change the font to a size suitable for superscripts.
 *
 *  @var FontScale SUBSCRIPT
 * Change the font to a size suitable for subscripts.
 *
 *  @var FontScale SMALL_CAPS
 * Change the font to a size suitable for Small Caps. @newin{1,50}
 *
 *  @enum FontScale
 *
 * An enumeration that affects font sizes for superscript
 * and subscript positioning and for (emulated) Small Caps.
 *
 * @newin{2,50}
 *
 * @ingroup pangommEnums
 */
enum class FontScale
{
  NONE,
  SUPERSCRIPT,
  SUBSCRIPT,
  SMALL_CAPS
};


} // namespace Pango

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

template <>
class PANGOMM_API Value<Pango::FontScale> : public Glib::Value_Enum<Pango::FontScale>
{
public:
  static auto value_type() -> GType G_GNUC_CONST;
};

} // namespace Glib
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

namespace Pango
{


/** A Pango::LogAttr stores information about the attributes of a single character.
 */
typedef PangoLogAttr LogAttr;


class PANGOMM_API AttrString;
class PANGOMM_API AttrLanguage;
class PANGOMM_API AttrColor;
class PANGOMM_API AttrInt;
class PANGOMM_API AttrFloat;
class PANGOMM_API AttrFontDesc;
class PANGOMM_API AttrShape;

enum class PANGOMM_API GravityHint;

/** The %Pango::Attribute structure represents the common portions of all attributes.
 * Particular types of attributes derive this class. It holds the range in which the
 * value in the type-specific part of the attribute applies.
 *
 * Attributed text is used in a number of places in pango. It is used as the input to
 * the itemization process and also when creating a Pango::Layout.
 */
class PANGOMM_API Attribute
{
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  using CppObjectType = Attribute;
  using BaseObjectType = PangoAttribute;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

private:


public:
  /** Constructs an invalid attribute.
   */
  Attribute();

  Attribute(const Attribute& src);
  explicit Attribute(PangoAttribute* castitem, bool take_copy=true);
  ~Attribute();

  auto operator=(const Attribute& src) -> Attribute&;

  /** Gets the type ID for this attribute.
   * @return The type ID for this attribute or ATTR_INVALID if the attribute is invalid.
   */
  auto get_type() const -> AttrType;

  /** Allocate a new attribute type ID.
   *
   * The attribute type name can be accessed later by using get_type_name().
   *
   * @param name An identifier for the type.
   * @return The new type ID.
   */
  static auto register_type(const Glib::ustring& name) -> AttrType;

  /** Fetches the attribute type name passed in when registering the type using
   * register_type().
   *
   * @newin{2,46}
   *
   * @param type An attribute type ID to fetch the name for.
   * @return The type ID name (which may be an empty string), or an empty string
   *         if @a type is a built-in Pango attribute type or invalid.
   */
  static auto get_type_name(AttrType type) -> Glib::ustring;
  // _WRAP_METHOD() can't be used here, because glibmm/tools/defs_gen/h2def.py
  // assumes that pango_attr_type_get_name() is a method of a class named PangoAttrType.

  /** Gets the start index of the range.
   * @return The start index of the range.
   */
  auto get_start_index() const -> unsigned int;

  /** Gets the end index of the range. The character at this index is not included in the range.
   * @return The end index of the range.
   */
  auto get_end_index() const -> unsigned int;

  /** Sets the start index of the range.
   * @param value The new start index (in bytes).
   */
  void set_start_index(const unsigned int& value);

  /** Sets the end index of the range. The character at this index is not included in the range.
   * @param value The new end index (in bytes).
   */
  void set_end_index(const unsigned int& value);


  /** Compare two attributes for equality.
   *
   * This compares only the actual value of the two
   * attributes and not the ranges that the attributes
   * apply to.
   *
   * @param attr2 Another `Pango::Attribute`.
   * @return <tt>true</tt> if the two attributes have the same value.
   */
  auto equal(const Attribute& attr2) const -> bool;

  /// Provides access to the underlying C GObject.
  auto       gobj() -> PangoAttribute*       { return gobject_; }
  /// Provides access to the underlying C GObject.
  auto gobj() const -> const PangoAttribute* { return gobject_; }

  /** Create a new font family attribute.
   * @param family The family or comma separated list of families.
   * @return An attribute of type AttrString.
   */
  static auto create_attr_family(const Glib::ustring& family) -> AttrString;

  /** Create a new language tag attribute
   * @param language The language tag.
   * @return An attribute of type AttrLanguage.
   */
  static auto create_attr_language(const Language& language) -> AttrLanguage;

  /** Create a new foreground color attribute.
   * @param red The red value (ranging from 0 to 65535).
   * @param green The green value (ranging from 0 to 65535).
   * @param blue The blue value (ranging from 0 to 65535).
   * @return An attribute of type AttrColor.
   */
  static auto create_attr_foreground(guint16 red, guint16 green, guint16 blue) -> AttrColor;

  /** Create a new background color attribute.
   * @param red The red value (ranging from 0 to 65535).
   * @param green The green value (ranging from 0 to 65535).
   * @param blue The blue value (ranging from 0 to 65535).
   * @return An attribute of type AttrColor.
   */
  static auto create_attr_background(guint16 red, guint16 green, guint16 blue) -> AttrColor;

  /** Create a new foreground alpha attribute.
   * @param alpha The alpha value, between 1 and 65536.
   */
  static auto create_attr_foreground_alpha(guint16 alpha) -> AttrInt;

  /** Create a new background alpha attribute.
   * @param alpha The alpha value, between 1 and 65536.
   */
  static auto create_attr_background_alpha(guint16 alpha) -> AttrInt;

  /** Create a new font-size attribute.
   * @param size The font size, in 1024ths of a point.
   * @return An attribute of type AttrInt.
   */
  static auto create_attr_size(int size) -> AttrInt;

  /** Create a new font-size attribute.
   *
   * @newin{2,42}
   *
   * @param size The font size, in 1024ths of a device unit.
   * @return An attribute of type AttrInt.
   */
  static auto create_attr_size_absolute(int size) -> AttrInt;

  /** Create a new font slant style attribute.
   * @param style The slant style.
   * @return An attribute of type AttrInt.
   */
  static auto create_attr_style(Style style) -> AttrInt;

  /** Create a new font weight attribute.
   * @param weight The weight.
   * @return An attribute of type AttrInt.
   */
  static auto create_attr_weight(Weight weight) -> AttrInt;

  /** Create a new font variant attribute (normal or small caps).
   * @param variant The variant.
   * @return An attribute of type AttrInt.
   */
  static auto create_attr_variant(Variant variant) -> AttrInt;

  /** Create a new font stretch attribute.
   * @param stretch The stretch.
   * @return An attribute of type AttrInt.
   */
  static auto create_attr_stretch(Stretch stretch) -> AttrInt;

  /** Create a new font description attribute.
   * This attribute allows setting family, style, weight, variant, stretch, and size simultaneously.
   * @param desc The font description.
   * @return An attribute of type AttrFontDesc.
   */
  static auto create_attr_font_desc(const FontDescription& desc) -> AttrFontDesc;

  /** Create a new underline-style object.
   * @param underline The underline style.
   * @return An attribute of type AttrInt.
   */
  static auto create_attr_underline(Underline underline) -> AttrInt;

  /** Create a new underline color attribute.
   * This attribute modifies the color of underlines. If not set,
   * underlines will use the foreground color.
   *
   * @newin{2,42}
   *
   * @param red The red value (ranging from 0 to 65535).
   * @param green The green value (ranging from 0 to 65535).
   * @param blue The blue value (ranging from 0 to 65535).
   * @return An attribute of type AttrColor.
   */
  static auto create_attr_underline_color(guint16 red, guint16 green, guint16 blue) -> AttrColor;

  /** Create a new overline-style object.
   *
   * @newin{2,46}
   *
   * @param overline The overline style.
   * @return An attribute of type AttrInt.
   */
  static auto create_attr_overline(Overline overline) -> AttrInt;

  /** Create a new overline color attribute.
   *
   * This attribute modifies the color of overlines. If not set,
   * overlines will use the foreground color.
   *
   * @newin{2,46}
   *
   * @param red The red value (ranging from 0 to 65535).
   * @param green The green value (ranging from 0 to 65535).
   * @param blue The blue value (ranging from 0 to 65535).
   * @return An attribute of type AttrColor.
   */
  static auto create_attr_overline_color(guint16 red, guint16 green, guint16 blue) -> AttrColor;

  /** Create a new font strike-through attribute.
   * @param strikethrough True indicates the text should be struck-through.
   * @return An attribute of type AttrInt.
   */
  static auto create_attr_strikethrough(bool strikethrough) -> AttrInt;

  /** Create a new strikethrough color attribute.
   * This attribute modifies the color of strikethrough lines. If not set,
   * strikethrough lines will use the foreground color.
   *
   * @newin{2,42}
   *
   * @param red The red value (ranging from 0 to 65535).
   * @param green The green value (ranging from 0 to 65535).
   * @param blue The blue value (ranging from 0 to 65535).
   * @return An attribute of type AttrColor.
   */
  static auto create_attr_strikethrough_color(guint16 red, guint16 green, guint16 blue) -> AttrColor;

  /** Create a new baseline displacement attribute.
   * @param rise The amount that the text should be displaced vertically, in 10'000ths of an em. Positive values displace the text upwards.
   * @return An attribute of type AttrInt.
   */
  static auto create_attr_rise(int rise) -> AttrInt;

  /** Create a new baseline displacement attribute.
   *
   * The effect of this attribute is to shift the baseline of a run,
   * relative to the run of preceding run.
   *
   * @newin{2,50}
   *
   * @param shift Either a Pango::BaselineShift enumeration value or an absolute value (> 1024)
   *   in %Pango units, relative to the baseline of the previous run.
   *   Positive values displace the text upwards.
   * @return An attribute of type AttrInt.
   */
  static auto create_attr_baseline_shift(int shift) -> AttrInt;

  /** Create a new font scale attribute.
   *
   * The effect of this attribute is to change the font size of a run,
   * relative to the size of preceding run.
   *
   * @newin{2,50}
   *
   * @param scale A Pango::FontScale value, which indicates font size change relative
   *   to the size of the previous run.
   * @return An attribute of type AttrInt.
   */
  static auto create_attr_font_scale(FontScale scale) -> AttrInt;

  /** Create a new font size scale attribute.
   * The base font for the affected text will have its size multiplied by scale_factor.
   * @param scale_factor Factor to scale the font.
   * @return An attribute of type AttrFloat.
   */
  static auto create_attr_scale(double scale_factor) -> AttrFloat;

  /** Create a new font fallback attribute.
   * If fallback is disabled, characters will only be used from the
   * closest matching font on the system. No fallback will be done to
   * other fonts on the system that might contain the characters in the text.
   *
   * @newin{2,42}
   *
   * @param enable_fallback <tt>true</tt> if we should fall back on other fonts
   *                        for characters the active font is missing.
   * @return An attribute of type AttrInt.
   */
  static auto create_attr_fallback(bool enable_fallback) -> AttrInt;

  /** Create a new letter-spacing attribute.
   *
   * @newin{2,42}
   *
   * @param letter_spacing Amount of extra space to add between graphemes
   *                       of the text, in Pango units.
   * @return An attribute of type AttrInt.
   */
  static auto create_attr_letter_spacing(int letter_spacing) -> AttrInt;

  /** Create a new shape attribute.
   * A shape is used to impose a particular ink and logical rect on the result of shaping a particular glyph.
   * This might be used, for instance, for embedding a picture or a widget inside a PangoLayout.
   * @param ink_rect Ink rectangle to assign to each character.
   * @param logical_rect Logical rectangle assign to each character.
   * @return An attribute of type AttrShape.
   */
  static auto create_attr_shape(const Rectangle& ink_rect, const Rectangle& logical_rect) -> AttrShape;

  /** Create a new gravity attribute.
   *
   * @newin{2,42}
   *
   * @param gravity The gravity value; should not be Pango::Gravity::AUTO.
   * @return An attribute of type AttrInt.
   */
  static auto create_attr_gravity(Gravity gravity) -> AttrInt;

  /** Create a new gravity hint attribute.
   *
   * @newin{2,42}
   *
   * @param hint The gravity hint value.
   * @return An attribute of type AttrInt.
   */
  static auto create_attr_gravity_hint(GravityHint hint) -> AttrInt;

  /** Create a new font features tag attribute.
   *
   * @newin{2,42}
   *
   * @param features A string with OpenType font features, in CSS syntax.
   * @return An attribute of type AttrString.
   */
  static auto create_attr_font_features(const Glib::ustring& features) -> AttrString;

  /** Create a new allow-breaks attribute.
   *
   * If breaks are disabled, the range will be kept in a
   * single run, as far as possible.
   *
   * @newin{2,46}
   *
   * @param allow_breaks <tt>true</tt> if line breaks are allowed.
   * @return An attribute of type AttrInt.
   */
  static auto create_attr_allow_breaks(bool allow_breaks) -> AttrInt;

  /** Marks the range of the attribute as a single word.
   *
   * Note that this may require adjustments to word and
   * sentence classification around the range.
   *
   * @newin{2,50}
   *
   * @return An attribute of type AttrInt.
   */
  static auto create_attr_word() -> AttrInt;

  /** Marks the range of the attribute as a single sentence.
   *
   * Note that this may require adjustments to word and
   * sentence classification around the range.
   *
   * @newin{2,50}
   *
   * @return An attribute of type AttrInt.
   */
  static auto create_attr_sentence() -> AttrInt;

  /** Create a new insert-hyphens attribute.
   *
   * Pangomm will insert hyphens when breaking lines in the middle
   * of a word. This attribute can be used to suppress the hyphen.
   *
   * @newin{2,46}
   *
   * @param insert_hyphens <tt>true</tt> if hyphens should be inserted.
   * @return An attribute of type AttrInt.
   */
  static auto create_attr_insert_hyphens(bool insert_hyphens) -> AttrInt;

  /** Create a new attribute that influences how invisible characters are rendered.
   *
   * @newin{2,46}
   *
   * @param flags Pango::ShowFlags to apply.
   * @return An attribute of type AttrInt.
   */
  static auto create_attr_show(ShowFlags show) -> AttrInt;

  /** Modify the height of logical line extents by a factor.
   *
   * This affects the values returned by Pango::LayoutLine::get_extents(),
   * Pango::LayoutLine::get_pixel_extents() and Pango::LayoutIter::get_line_extents().
   *
   * @newin{2,50}
   *
   * @param factor The scaling factor to apply to the logical height.
   * @return An attribute of type AttrFloat.
   */
  static auto create_attr_line_height(double factor) -> AttrFloat;

  /** Override the height of logical line extents to be @a height.
   *
   * This affects the values returned by Pango::LayoutLine::get_extents(),
   * Pango::LayoutLine::get_pixel_extents() and Pango::LayoutIter::get_line_extents().
   *
   * @newin{2,50}
   *
   * @param height The line height, in Pango::SCALE-ths of a point.
   * @return An attribute of type AttrInt.
   */
  static auto create_attr_line_height_absolute(int height) -> AttrInt;

  /** Create a new attribute that influences how characters are transformed during shaping.
   *
   * @newin{2,50}
   *
   * @param transform Pango::TextTransform to apply.
   * @return An attribute of type AttrInt.
   */
  static auto create_attr_text_transform(TextTransform transform) -> AttrInt;


protected:
  PangoAttribute* gobject_;


};

/** @relates Pango::Attribute */
inline auto operator==(const Attribute& lhs, const Attribute& rhs) -> bool
{
  return lhs.equal(rhs);
}

/** @relates Pango::Attribute */
inline auto operator!=(const Attribute& lhs, const Attribute& rhs) -> bool
{
  return !lhs.equal(rhs);
}


/** A Pango::AttrString is used to represent an attribute with a string value.
 */
class PANGOMM_API AttrString : public Attribute
{
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  using CppObjectType = AttrString;
  using BaseObjectType = PangoAttrString;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

private:


protected:
  AttrString();
public:
  AttrString(const AttrString& src);
  explicit AttrString(PangoAttrString* castitem, bool take_copy=true);

  auto operator=(const AttrString& src) -> AttrString&;

  /** Gets the string which is the value of the attribute.
   * @return The string value of the attribute.
   */
  auto get_string() const -> Glib::ustring;

  /** Sets the string which is the value of the attribute.
   * @param string The new string value for the attribute.
   */
  void set_string(const Glib::ustring& string);

  /// Provides access to the underlying C GObject.
  auto       gobj() -> PangoAttrString*       { return reinterpret_cast<PangoAttrString*>(gobject_); }
  /// Provides access to the underlying C GObject.
  auto gobj() const -> const PangoAttrString* { return reinterpret_cast<const PangoAttrString*>(gobject_); }


};


/** A Pango::AttrLanguage is used to represent an attribute that is a language.
 */
class PANGOMM_API AttrLanguage : public Attribute
{
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  using CppObjectType = AttrLanguage;
  using BaseObjectType = PangoAttrLanguage;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

private:


protected:
  AttrLanguage();
public:
  AttrLanguage(const AttrLanguage& src);
  explicit AttrLanguage(PangoAttrLanguage* castitem, bool take_copy=true);

  auto operator=(const AttrLanguage& src) -> AttrLanguage&;

  /** Gets the language which is the value of the attribute.
   * @return The language tag of the attribute.
   */
  auto get_language() const -> Language;

  /** Sets the language which is the value of the attribute.
   * @param value The new language tag for the attribute.
   */
  void set_language(const Language& value);

  /// Provides access to the underlying C GObject.
  auto       gobj() -> PangoAttrLanguage*       { return reinterpret_cast<PangoAttrLanguage*>(gobject_); }
  /// Provides access to the underlying C GObject.
  auto gobj() const -> const PangoAttrLanguage* { return reinterpret_cast<const PangoAttrLanguage*>(gobject_); }


};


/** A Pango::AttrColor is used to represent an attribute which is a color.
 */
class PANGOMM_API AttrColor : public Attribute
{
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  using CppObjectType = AttrColor;
  using BaseObjectType = PangoAttrColor;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

private:


protected:
  AttrColor();
public:
  AttrColor(const AttrColor& src);
  explicit AttrColor(PangoAttrColor* castitem, bool take_copy=true);

  auto operator=(const AttrColor& src) -> AttrColor&;

  /** Gets the color which is the value of the attribute.
   * @return The color value of the attribute.
   */
  auto get_color() const -> Color;

  /** Sets the color which is the value of the attribute.
   * @param value The new color value for the attribute.
   */
  void set_color(const Color& value);

  /// Provides access to the underlying C GObject.
  auto       gobj() -> PangoAttrColor*       { return reinterpret_cast<PangoAttrColor*>(gobject_); }
  /// Provides access to the underlying C GObject.
  auto gobj() const -> const PangoAttrColor* { return reinterpret_cast<const PangoAttrColor*>(gobject_); }


};


/** A Pango::AttrInt is used to represent an attribute with an integer or enumeration value.
 */
class PANGOMM_API AttrInt : public Attribute
{
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  using CppObjectType = AttrInt;
  using BaseObjectType = PangoAttrInt;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

private:


protected:
  AttrInt();
public:
  AttrInt(const AttrInt& src);
  explicit AttrInt(PangoAttrInt* castitem, bool take_copy=true);

  auto operator=(const AttrInt& src) -> AttrInt&;

  /** Gets the integer value of the attribute.
   * @return The integer value of the attribute.
   */
  auto get_value() const -> int;

  /** Sets the integer value of the attribute.
   * @param value The new integer value for the attribute.
   */
  void set_value(const int& value);

  /// Provides access to the underlying C GObject.
  auto       gobj() -> PangoAttrInt*       { return reinterpret_cast<PangoAttrInt*>(gobject_); }
  /// Provides access to the underlying C GObject.
  auto gobj() const -> const PangoAttrInt* { return reinterpret_cast<const PangoAttrInt*>(gobject_); }


};


/** A Pango::AttrFloat is used to represent an attribute with a float or double value.
 */
class PANGOMM_API AttrFloat : public Attribute
{
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  using CppObjectType = AttrFloat;
  using BaseObjectType = PangoAttrFloat;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

private:


protected:
  AttrFloat();
public:
  AttrFloat(const AttrFloat& src);
  explicit AttrFloat(PangoAttrFloat* castitem, bool take_copy=true);

  auto operator=(const AttrFloat& src) -> AttrFloat&;

  /** Gets the floating point value of the attribute.
   * @return The floating point value of the attribute.
   */
  auto get_value() const -> double;

  /** Sets the floating point value of the attribute.
   * @param value The new floating point value for the attribute.
   */
  void set_value(const double& value);

  /// Provides access to the underlying C GObject.
  auto       gobj() -> PangoAttrFloat*       { return reinterpret_cast<PangoAttrFloat*>(gobject_); }
  /// Provides access to the underlying C GObject.
  auto gobj() const -> const PangoAttrFloat* { return reinterpret_cast<const PangoAttrFloat*>(gobject_); }


};


/** A Pango::AttrFontDesc is used to represent an attribute that sets all aspects of the font description at once.
 */
class PANGOMM_API AttrFontDesc : public Attribute
{
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  using CppObjectType = AttrFontDesc;
  using BaseObjectType = PangoAttrFontDesc;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

private:


protected:
  AttrFontDesc();
public:
  AttrFontDesc(const AttrFontDesc& src);
  explicit AttrFontDesc(PangoAttrFontDesc* castitem, bool take_copy=true);

  auto operator=(const AttrFontDesc& src) -> AttrFontDesc&;

  /** Gets the font description which is the value of the attribute.
   * @return The font description of the attribute.
   */
  auto get_desc() const -> FontDescription;

  /** Sets the font description which is the value of the attribute.
   * @param desc The new font description for the attribute.
   */
  void set_desc(const FontDescription& desc);

  /// Provides access to the underlying C GObject.
  auto       gobj() -> PangoAttrFontDesc*       { return reinterpret_cast<PangoAttrFontDesc*>(gobject_); }
  /// Provides access to the underlying C GObject.
  auto gobj() const -> const PangoAttrFontDesc* { return reinterpret_cast<const PangoAttrFontDesc*>(gobject_); }


};


/** A Pango::AttrShape structure is used to represent an attribute which imposes shape restrictions.
 */
class PANGOMM_API AttrShape : public Attribute
{
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  using CppObjectType = AttrShape;
  using BaseObjectType = PangoAttrShape;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

private:


protected:
  AttrShape();
public:
  AttrShape(const AttrShape& src);
  explicit AttrShape(PangoAttrShape* castitem, bool take_copy=true);

  auto operator=(const AttrShape& src) -> AttrShape&;

  /** Gets the ink rectangle to restrict to.
   * @return The ink rectangle of the attribute.
   */
  auto get_ink_rect() const -> Rectangle;

  /** Gets the logical rectangle to restrict to.
   * @return The logical rectangle of the attribute.
   */
  auto get_logical_rect() const -> Rectangle;

  /** Sets the ink rectangle to restrict to.
   * @param value The new ink rectangle for the attribute.
   */
  void set_ink_rect(const Rectangle& value);

  /** Sets the logical rectangle to restrict to.
   * @param value The new logical rectangle for the attribute.
   */
  void set_logical_rect(const Rectangle& value);

  /// Provides access to the underlying C GObject.
  auto       gobj() -> PangoAttrShape*       { return reinterpret_cast<PangoAttrShape*>(gobject_); }
  /// Provides access to the underlying C GObject.
  auto gobj() const -> const PangoAttrShape* { return reinterpret_cast<const PangoAttrShape*>(gobject_); }


};


struct AttributeTraits
{
  typedef Pango::Attribute      CppType;
  typedef const PangoAttribute* CType;
  typedef PangoAttribute*       CTypeNonConst;

  static auto   to_c_type      (const CppType& obj) -> CType { return obj.gobj(); }
  static auto   to_c_type      (CType ptr) -> CType { return ptr; }
  static auto to_cpp_type    (CType ptr) -> CppType { return CppType(const_cast<CTypeNonConst>(ptr), true); }
  static void    release_c_type (CType ptr) { pango_attribute_destroy(const_cast<CTypeNonConst>(ptr)); }
};

} // namespace Pango


namespace Glib
{

/** @relates Pango::Attribute */
PANGOMM_API
auto wrap(PangoAttribute* object, bool take_copy = false) -> Pango::Attribute;

/** @relates Pango::AttrString */
PANGOMM_API
auto wrap(PangoAttrString* object, bool take_copy = false) -> Pango::AttrString;

/** @relates Pango::AttrLanguage */
PANGOMM_API
auto wrap(PangoAttrLanguage* object, bool take_copy = false) -> Pango::AttrLanguage;

/** @relates Pango::AttrColor */
PANGOMM_API
auto wrap(PangoAttrColor* object, bool take_copy = false) -> Pango::AttrColor;

/** @relates Pango::AttrInt */
PANGOMM_API
auto wrap(PangoAttrInt* object, bool take_copy = false) -> Pango::AttrInt;

/** @relates Pango::AttrFloat */
PANGOMM_API
auto wrap(PangoAttrFloat* object, bool take_copy = false) -> Pango::AttrFloat;

/** @relates Pango::AttrFontDesc */
PANGOMM_API
auto wrap(PangoAttrFontDesc* object, bool take_copy = false) -> Pango::AttrFontDesc;

/** @relates Pango::AttrShape */
PANGOMM_API
auto wrap(PangoAttrShape* object, bool take_copy = false) -> Pango::AttrShape;

} //namespace Glib


#endif /* _PANGOMM_ATTRIBUTES_H */

