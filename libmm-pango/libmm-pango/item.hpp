
#ifndef _PANGOMM_ITEM_H
#define _PANGOMM_ITEM_H


#include <libmm-glib/ustring.hpp>
#include <sigc++/sigc++.h>

/* Copyright (C) 2002 The gtkmm Development Team
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

#include <libmm-pango/attributes.hpp>
#include <libmm-pango/language.hpp>
#include <pango/pango.h>


namespace Pango
{
/** @addtogroup pangommEnums pangomm Enums and Flags */

/**
 *  @var ShapeFlags NONE
 * Default value.
 *
 *  @var ShapeFlags ROUND_POSITIONS
 * Round glyph positions
 * and widths to whole device units. This option should
 * be set if the target renderer can't do subpixel
 * positioning of glyphs.
 *
 *  @enum ShapeFlags
 *
 * Flags influencing the shaping process.
 *
 * `Pango::ShapeFlags` can be passed to pango_shape_with_flags().
 *
 * @newin{2,44}
 *
 * @ingroup pangommEnums
 * @par Bitwise operators:
 * <tt>ShapeFlags operator|(ShapeFlags, ShapeFlags)</tt><br>
 * <tt>ShapeFlags operator&(ShapeFlags, ShapeFlags)</tt><br>
 * <tt>ShapeFlags operator^(ShapeFlags, ShapeFlags)</tt><br>
 * <tt>ShapeFlags operator~(ShapeFlags)</tt><br>
 * <tt>ShapeFlags& operator|=(ShapeFlags&, ShapeFlags)</tt><br>
 * <tt>ShapeFlags& operator&=(ShapeFlags&, ShapeFlags)</tt><br>
 * <tt>ShapeFlags& operator^=(ShapeFlags&, ShapeFlags)</tt><br>
 */
enum class ShapeFlags
{
  NONE = 0x0,
  ROUND_POSITIONS = 1 << 0
};

/** @ingroup pangommEnums */
inline auto operator|(ShapeFlags lhs, ShapeFlags rhs) -> ShapeFlags
  { return static_cast<ShapeFlags>(static_cast<unsigned>(lhs) | static_cast<unsigned>(rhs)); }

/** @ingroup pangommEnums */
inline auto operator&(ShapeFlags lhs, ShapeFlags rhs) -> ShapeFlags
  { return static_cast<ShapeFlags>(static_cast<unsigned>(lhs) & static_cast<unsigned>(rhs)); }

/** @ingroup pangommEnums */
inline auto operator^(ShapeFlags lhs, ShapeFlags rhs) -> ShapeFlags
  { return static_cast<ShapeFlags>(static_cast<unsigned>(lhs) ^ static_cast<unsigned>(rhs)); }

/** @ingroup pangommEnums */
inline auto operator~(ShapeFlags flags) -> ShapeFlags
  { return static_cast<ShapeFlags>(~static_cast<unsigned>(flags)); }

/** @ingroup pangommEnums */
inline auto operator|=(ShapeFlags& lhs, ShapeFlags rhs) -> ShapeFlags&
  { return (lhs = static_cast<ShapeFlags>(static_cast<unsigned>(lhs) | static_cast<unsigned>(rhs))); }

/** @ingroup pangommEnums */
inline auto operator&=(ShapeFlags& lhs, ShapeFlags rhs) -> ShapeFlags&
  { return (lhs = static_cast<ShapeFlags>(static_cast<unsigned>(lhs) & static_cast<unsigned>(rhs))); }

/** @ingroup pangommEnums */
inline auto operator^=(ShapeFlags& lhs, ShapeFlags rhs) -> ShapeFlags&
  { return (lhs = static_cast<ShapeFlags>(static_cast<unsigned>(lhs) ^ static_cast<unsigned>(rhs))); }


} // namespace Pango

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

template <>
class PANGOMM_API Value<Pango::ShapeFlags> : public Glib::Value_Flags<Pango::ShapeFlags>
{
public:
  static auto value_type() -> GType G_GNUC_CONST;
};

} // namespace Glib
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

namespace Pango
{


class Font;
class GlyphString;

/** A %Pango::Analysis stores information about the properties of a segment of text.
 * %Pango::Analysis is used as an output type only so there is no public default constructor.
 * You can retrieve an object of this type from an object of type Pango::Item by
 * calling Pango::Item::get_analysis(). Objects of this class can be used for some
 * calculations in Pango::GlyphString.
 */
class PANGOMM_API Analysis
{
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  using CppObjectType = Analysis;
  using BaseObjectType = PangoAnalysis;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

private:


protected:
  // This class is only used as an output type.
  Analysis();

public:
  explicit Analysis(const PangoAnalysis* src);

public:
//  _MEMBER_GET_PTR(engine_shape, shape_engine, EngineShape*, PangoEngineShape*) //We don't wrap the Engine* stuff.
//  _MEMBER_GET_PTR(engine_lang, lang_engine, EngineLang*, PangoEngineLang*)

  /** Gets the font used to render this segment.
   * @return The font used to render this segment.
   */
  auto get_font() -> Glib::RefPtr<Font>;
  auto get_font() const -> Glib::RefPtr<const Font>;

  /** Gets the bidrectional level for this segment.
   * @return The bidirectional level for this segment.
   */
  auto get_level() const -> guint8;

  /** Gets the language of this segment.
   * @return The language of this segment.
   */
  auto get_language() const -> Language;

  /** Gets a list of non-font attributes for this segment.
   * @return A list of non-font attributes for this segment.
   */
  auto get_extra_attrs() const -> std::vector<Attribute>;

  /// Provides access to the underlying C GObject.
  auto       gobj() -> PangoAnalysis*       { return &gobject_; }
  /// Provides access to the underlying C GObject.
  auto gobj() const -> const PangoAnalysis* { return &gobject_; }

protected:
  PangoAnalysis gobject_;


};


/** A Pango::Item stores information about a segment of text.
 * Pango::Item is used as an output type only so there is no public default constructor.
 * You retrieve objects of this type by calling Pango::Context::itemize() with some text.
 * The actual rendering of the segment of text that corresponds to a particular Pango::Item
 * (or some sub-string) into a string of glyphs is done with shape().
 * The segment of text that corresponds to a Pango::Item can be computed from the
 * text passed into Pango::Context::itemize() with get_segment(). Together with
 * the Pango::Analysis data member that can be accessed with get_analysis()
 * it is needed for further calculations in Pango::GlyphString.
 */
class PANGOMM_API Item
{
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  using CppObjectType = Item;
  using BaseObjectType = PangoItem;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

private:
 //There is the whole set of functions for _CLASS_BOXEDTYPE but unfortunately PangoItem is not registered as a boxed type and lacks pango_item_get_type...


public:
  // There is no default constructor. This class is only used as an output type.
  explicit Item(PangoItem* castitem, bool make_a_copy = true);

  Item(const Item& src);
  auto operator=(const Item& src) -> Item&;

  ~Item();

  /// Provides access to the underlying C GObject. The caller is responsible for freeing it. Use when directly setting fields in structs.
  auto gobj_copy() const -> PangoItem*;

public:

  /** Modifies @a orig to cover only the text after @a split_index, and
   * returns a new item that covers the text before @a split_index that
   * used to be in @a orig.
   *
   * You can think of @a split_index as the length of the returned item.
   *  @a split_index may not be 0, and it may not be greater than or equal
   * to the length of @a orig (that is, there must be at least one byte
   * assigned to each item, you can't create a zero-length item).
   *  @a split_offset is the length of the first item in chars, and must be
   * provided because the text used to generate the item isn't available,
   * so `split()` can't count the char length of the split items
   * itself.
   *
   * @param split_index Byte index of position to split item, relative to the
   * start of the item.
   * @param split_offset Number of chars between start of @a orig and @a split_index.
   * @return New item representing text before @a split_index, which
   * should be freed with free().
   */
  auto split(int split_index, int split_offset) -> Item;

  /** Gets the offset of the segment from the beginning of the string in bytes.
   * @return The offset of the segment from the beginning of the string in bytes.
   */
  auto get_offset() const -> int;

  /** Gets the length of the segment in bytes.
   * @return The length of the segment in bytes.
   */
  auto get_length() const -> int;

  /** Gets the length of the segment in characters.
   * @return The length of the semgment in characters.
   */
  auto get_num_chars() const -> int;

  /** Gets the properties of the segment.
   * @return The properties of the segment.
   */
  auto get_analysis() const -> Analysis;

  /** Computes the segment of text that is represented by the item.
   * @param text The text that has been passed into Pango::Context::itemize().
   * @return The sub-string of @a text that corresponds to the item.
   */
  auto get_segment(const Glib::ustring& text) const -> Glib::ustring;

  /** Converts a segment of text into a string of glyphs.
   *
   * @param text The text to process. This must either be the whole segment of text
   *             that corresponds to the item as returned by get_segment() or a
   *             substring of that segment. You need to pass the same text to
   *             the member functions of Pango::GlyphString for further calculations.
   * @return A Pango::GlyphString object that can be measured or drawn.
   */
  auto shape(const Glib::ustring& text) const -> GlyphString;

  /** Converts a segment of text into a string of glyphs.
   *
   * @newin{2,44}
   *
   * @param item_text The text to process. This must either be the whole segment of text
   *             that corresponds to the item as returned by get_segment() or a
   *             substring of that segment. You need to pass the same text to
   *             the member functions of Pango::GlyphString for further calculations.
   * @param paragraph_text Text of the paragraph. See GlyphString::GlyphString(
   *        const Glib::ustring& item_text, const Glib::ustring& paragraph_text,
   *        const Analysis& analysis, ShapeFlags flags).
   * @param flags Flags influencing the shaping process.
   * @return A Pango::GlyphString object that can be measured or drawn.
   */
  auto shape(const Glib::ustring& item_text, const Glib::ustring& paragraph_text,
    ShapeFlags flags = ShapeFlags::NONE) const -> GlyphString;

  /// Provides access to the underlying C GObject.
  auto       gobj() -> PangoItem*       { return gobject_; }
  /// Provides access to the underlying C GObject.
  auto gobj() const -> const PangoItem* { return gobject_; }

protected:
  PangoItem* gobject_;


};

} // namespace Pango

namespace Glib
{

/** @relates Pango::Analysis */
PANGOMM_API
auto wrap(PangoAnalysis* object) -> Pango::Analysis&;

/** @relates Pango::Analysis */
PANGOMM_API
auto wrap(const PangoAnalysis* object) -> const Pango::Analysis&;

/** @relates Pango::Item */
PANGOMM_API
auto wrap(PangoItem* object, bool take_copy=true) -> Pango::Item;

} // namespace Glib


#endif /* _PANGOMM_ITEM_H */

