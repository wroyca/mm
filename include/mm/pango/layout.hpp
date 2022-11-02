// Generated by gmmproc 2.74.0 -- DO NOT MODIFY!
#ifndef _PANGOMM_LAYOUT_H
#define _PANGOMM_LAYOUT_H


#include <mm/glib/ustring.hpp>
#include <sigc++/sigc++.h>

/* layout.h
 *
 * Copyright(C) 1998-1999 The gtkmm Development Team
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or(at your option) any later version.
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

#include <mm/glib/object.hpp>
#include <mm/pango/font.hpp>
#include <mm/pango/fontdescription.hpp>
#include <mm/pango/context.hpp>
#include <mm/pango/attrlist.hpp>
#include <mm/pango/tabarray.hpp>
#include <mm/pango/layoutline.hpp>
#include <mm/pango/layoutiter.hpp>
#include <pango/pango.h>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
using PangoLayout = struct _PangoLayout;
using PangoLayoutClass = struct _PangoLayoutClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Pango
{ class PANGOMM_API Layout_Class; } // namespace Pango
#endif //DOXYGEN_SHOULD_SKIP_THIS

namespace Pango
{

/** @addtogroup pangommEnums pangomm Enums and Flags */

/**
 *  @var Alignment LEFT
 * Put all available space on the right.
 *
 *  @var Alignment CENTER
 * Center the line within the available space.
 *
 *  @var Alignment RIGHT
 * Put all available space on the left.
 *
 *  @enum Alignment
 *
 * `Pango::Alignment` describes how to align the lines of a `Pango::Layout`
 * within the available space.
 *
 * If the `Pango::Layout` is set to justify using Pango::Layout::set_justify(),
 * this only has effect for partial lines.
 *
 * See Pango::Layout::set_auto_dir() for how text direction affects
 * the interpretation of `PangoAlignment values.
 *
 * @ingroup pangommEnums
 */
enum class Alignment
{
  LEFT,
  CENTER,
  RIGHT
};


} // namespace Pango

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

template <>
class PANGOMM_API Value<Pango::Alignment> : public Glib::Value_Enum<Pango::Alignment>
{
public:
  static auto value_type() -> GType G_GNUC_CONST;
};

} // namespace Glib
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

namespace Pango
{

/**
 *  @var WrapMode WORD
 * Wrap lines at word boundaries.
 *
 *  @var WrapMode CHAR
 * Wrap lines at character boundaries.
 *
 *  @var WrapMode WORD_CHAR
 * Wrap lines at word boundaries, but fall back to
 * character boundaries if there is not enough space for a full word.
 *
 *  @enum WrapMode
 *
 * `Pango::WrapMode` describes how to wrap the lines of a `Pango::Layout`
 * to the desired width.
 *
 * For @a PANGO_WRAP_WORD, Pango uses break opportunities that are determined
 * by the Unicode line breaking algorithm. For @a PANGO_WRAP_CHAR, Pango allows
 * breaking at grapheme boundaries that are determined by the Unicode text
 * segmentation algorithm.
 *
 * @ingroup pangommEnums
 */
enum class WrapMode
{
  WORD,
  CHAR,
  WORD_CHAR
};


} // namespace Pango

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

template <>
class PANGOMM_API Value<Pango::WrapMode> : public Glib::Value_Enum<Pango::WrapMode>
{
public:
  static auto value_type() -> GType G_GNUC_CONST;
};

} // namespace Glib
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

namespace Pango
{

/**
 *  @var EllipsizeMode NONE
 * No ellipsization.
 *
 *  @var EllipsizeMode START
 * Omit characters at the start of the text.
 *
 *  @var EllipsizeMode MIDDLE
 * Omit characters in the middle of the text.
 *
 *  @var EllipsizeMode END
 * Omit characters at the end of the text.
 *
 *  @enum EllipsizeMode
 *
 * `Pango::EllipsizeMode` describes what sort of ellipsization
 * should be applied to text.
 *
 * In the ellipsization process characters are removed from the
 * text in order to make it fit to a given width and replaced
 * with an ellipsis.
 *
 * @ingroup pangommEnums
 */
enum class EllipsizeMode
{
  NONE,
  START,
  MIDDLE,
  END
};


} // namespace Pango

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

template <>
class PANGOMM_API Value<Pango::EllipsizeMode> : public Glib::Value_Enum<Pango::EllipsizeMode>
{
public:
  static auto value_type() -> GType G_GNUC_CONST;
};

} // namespace Glib
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

namespace Pango
{


/** A Pango::Layout represents an entire paragraph of text.
 * It is initialized with a Pango::Context, UTF-8 string and set of attributes for that string.
 * Once that is done, the set of formatted lines can be extracted from the object,
 * the layout can be rendered, and conversion between logical character positions
 * within the layout's text, and the physical position of the resulting glyphs can be made.
 */

class PANGOMM_API Layout : public Glib::Object
{

#ifndef DOXYGEN_SHOULD_SKIP_THIS

public:
  using CppObjectType = Layout;
  using CppClassType = Layout_Class;
  using BaseObjectType = PangoLayout;
  using BaseClassType = PangoLayoutClass;

  // noncopyable
  Layout(const Layout&) = delete;
  auto operator=(const Layout&) -> Layout& = delete;

private:  friend class Layout_Class;
  static CppClassType layout_class_;

protected:
  explicit Layout(const Glib::ConstructParams& construct_params);
  explicit Layout(PangoLayout* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  Layout(Layout&& src) noexcept;
  auto operator=(Layout&& src) noexcept -> Layout&;

  ~Layout() noexcept override;

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS


  static auto get_base_type() -> GType G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GObject.
  auto       gobj() -> PangoLayout*       { return reinterpret_cast<PangoLayout*>(gobject_); }

  ///Provides access to the underlying C GObject.
  auto gobj() const -> const PangoLayout* { return reinterpret_cast<PangoLayout*>(gobject_); }

  ///Provides access to the underlying C instance. The caller is responsible for unrefing it. Use when directly setting fields in structs.
  auto gobj_copy() -> PangoLayout*;

private:


protected:
  explicit Layout(const Glib::RefPtr<Context>& context);

public:

  static auto create(const Glib::RefPtr<Context>& context) -> Glib::RefPtr<Layout>;


 /** Creates a layout object set up to match the current transformation
  * and target surface of the Cairo context.  This layout can then be
  * used for text measurement with functions like
  * get_size() or drawing with methods like show_in_cairo_contet().
  * If you change the transformation or target surface for @a context,
  * you need to call update_from_cairo_context()
  *
  * This is the most convenient way to use Cairo with Pango.
  * However it is slightly inefficient since it creates a separate
  * Pango Context object for each layout. This might matter in an
  * application that is laying out large amounts of text.
  *
  * @param context A Cairo context.
  * @return The newly created Pango Layout.
  */
  static auto create(const Cairo::RefPtr<Cairo::Context>& context) -> Glib::RefPtr<Layout>;

  /** Updates the private Pango Context of a Pango Layout created with
   * create(const Cairo::RefPtr<Cairo::Context>&) to match the current transformation
   * and target surface of a Cairo Context.
   *
   * @param context A Cairo context.
   */
  void update_from_cairo_context(const Cairo::RefPtr<Cairo::Context>& context);


  /** Creates a deep copy-by-value of the layout.
   *
   * The attribute list, tab array, and text from the original layout
   * are all copied by value.
   *
   * @return The newly allocated `Pango::Layout`.
   */
  auto copy() -> Glib::RefPtr<Layout>;

  /** Retrieves the `Pango::Context` used for this layout.
   *
   * @return The `Pango::Context` for the layout.
   */
  auto get_context() const -> Glib::RefPtr<Context>;

  /** Sets the text attributes for a layout object.
   *
   * References @a attrs, so the caller can unref its reference.
   *
   * @param attrs A `Pango::AttrList`.
   */
  void set_attributes(AttrList& attrs);

  /** Gets the attribute list for the layout, if any.
   *
   * @return A `Pango::AttrList`.
   */
  auto get_attributes() const -> AttrList;

  /** Set the text of the layout.
   * @param text The text for the layout.
   */
  void set_text(const Glib::ustring& text);


  /** Gets the text in the layout.
   *
   * The returned text should not be freed or modified.
   *
   * @return The text in the @a layout.
   */
  auto get_text() const -> Glib::ustring;


  /** Returns the number of Unicode characters in the
   * the text of @a layout.
   *
   * @newin{1,30}
   *
   * @return The number of Unicode characters
   * in the text of @a layout.
   */
  auto get_character_count() const -> int;

  /** Sets the layout text and attribute list from marked-up text (see markup format).
   * Replaces the current text and attribute list.
   * @param markup Some marked-up text.
   */
  void set_markup(const Glib::ustring& markup);

  /** Sets the layout text and attribute list from marked-up text (see markup format).
   * Replaces the current text and attribute list.
   *
   * If @a accel_marker is nonzero, the given character will mark the character following
   * it as an accelerator. For example, the accel marker might be an ampersand or
   * underscore. All characters marked as an accelerator will receive a
   * Pango::UNDERLINE_LOW attribute, and the first character so marked will be returned
   * in @a accel_char. Two @a accel_marker characters following each other produce a
   * single literal @a accel_marker character.
   * @param markup Some marked-up text.
   * @param accel_marker Marker for accelerators in the text.
   * @param accel_char Return location for any located accelerators.
   */
  void set_markup(const Glib::ustring& markup, gunichar accel_marker, gunichar& accel_char);


  /** Set the default font description for the layout. If no font
   * description is set on the layout, the font description from
   * the layout's context is used.
   *
   * @param desc The new pango font description.
   */
  void set_font_description(const FontDescription& desc);
  void unset_font_description();


  /** Gets the font description for the layout, if any.
   *
   * @newin{1,8}
   *
   * @return A pointer to the
   * layout's font description, or <tt>nullptr</tt> if the font description
   * from the layout's context is inherited.
   */
  auto get_font_description() const -> FontDescription;


  /** Sets the width to which the lines of the `Pango::Layout` should wrap or
   * ellipsized.
   *
   * The default value is -1: no width set.
   *
   * @param width The desired width in Pango units, or -1 to indicate that no
   * wrapping or ellipsization should be performed.
   */
  void set_width(int width);

  /** Gets the width to which the lines of the `Pango::Layout` should wrap.
   *
   * @return The width in Pango units, or -1 if no width set.
   */
  auto get_width() const -> int;

  /** Sets the height to which the `Pango::Layout` should be ellipsized at.
   *
   * There are two different behaviors, based on whether @a height is positive
   * or negative.
   *
   * If @a height is positive, it will be the maximum height of the layout. Only
   * lines would be shown that would fit, and if there is any text omitted,
   * an ellipsis added. At least one line is included in each paragraph regardless
   * of how small the height value is. A value of zero will render exactly one
   * line for the entire layout.
   *
   * If @a height is negative, it will be the (negative of) maximum number of lines
   * per paragraph. That is, the total number of lines shown may well be more than
   * this value if the layout contains multiple paragraphs of text.
   * The default value of -1 means that the first line of each paragraph is ellipsized.
   * This behavior may be changed in the future to act per layout instead of per
   * paragraph. File a bug against pango at
   * [https://gitlab.gnome.org/gnome/pango](https://gitlab.gnome.org/gnome/pango)
   * if your code relies on this behavior.
   *
   * Height setting only has effect if a positive width is set on
   *  @a layout and ellipsization mode of @a layout is not Pango::EllipsizeMode::NONE.
   * The behavior is undefined if a height other than -1 is set and
   * ellipsization mode is set to Pango::EllipsizeMode::NONE, and may change in the
   * future.
   *
   * @newin{1,20}
   *
   * @param height The desired height of the layout in Pango units if positive,
   * or desired number of lines if negative.
   */
  void set_height(int height);

  /** Gets the height of layout used for ellipsization.
   *
   * See set_height() for details.
   *
   * @newin{1,20}
   *
   * @return The height, in Pango units if positive,
   * or number of lines if negative.
   */
  auto get_height() const -> int;

  /** Sets the wrap mode.
   *
   * The wrap mode only has effect if a width is set on the layout
   * with set_width(). To turn off wrapping,
   * set the width to -1.
   *
   * The default value is Pango::WrapMode::WORD.
   *
   * @param wrap The wrap mode.
   */
  void set_wrap(WrapMode wrap);

  /** Gets the wrap mode for the layout.
   *
   * Use is_wrapped() to query whether
   * any paragraphs were actually wrapped.
   *
   * @return Active wrap mode.
   */
  auto get_wrap() const -> WrapMode;

  /** Queries whether the layout had to wrap any paragraphs.
   *
   * This returns <tt>true</tt> if a positive width is set on @a layout,
   * ellipsization mode of @a layout is set to Pango::EllipsizeMode::NONE,
   * and there are paragraphs exceeding the layout width that have
   * to be wrapped.
   *
   * @newin{1,16}
   *
   * @return <tt>true</tt> if any paragraphs had to be wrapped, <tt>false</tt>
   * otherwise.
   */
  auto is_wrapped() const -> bool;

  /** Sets the width in Pango units to indent each paragraph.
   *
   * A negative value of @a indent will produce a hanging indentation.
   * That is, the first line will have the full width, and subsequent
   * lines will be indented by the absolute value of @a indent.
   *
   * The indent setting is ignored if layout alignment is set to
   * Pango::Alignment::CENTER.
   *
   * The default value is 0.
   *
   * @param indent The amount by which to indent.
   */
  void set_indent(int indent);

  /** Gets the paragraph indent width in Pango units.
   *
   * A negative value indicates a hanging indentation.
   *
   * @return The indent in Pango units.
   */
  auto get_indent() const -> int;

  /** Sets the amount of spacing in Pango units between
   * the lines of the layout.
   *
   * When placing lines with spacing, Pango arranges things so that
   *
   * line2.top = line1.bottom + spacing
   *
   * The default value is 0.
   *
   * @note Since 1.44, Pango is using the line height (as determined
   * by the font) for placing lines when the line spacing factor is set
   * to a non-zero value with set_line_spacing().
   * In that case, the @a spacing set with this function is ignored.
   *
   * @note for semantics that are closer to the CSS line-height
   * property, see pango_attr_line_height_new().
   *
   * @param spacing The amount of spacing.
   */
  void set_spacing(int spacing);

  /** Gets the amount of spacing between the lines of the layout.
   *
   * @return The spacing in Pango units.
   */
  auto get_spacing() const -> int;

  /** Sets a factor for line spacing.
   *
   * Typical values are: 0, 1, 1.5, 2. The default values is 0.
   *
   * If @a factor is non-zero, lines are placed so that
   *
   * baseline2 = baseline1 + factor * height2
   *
   * where height2 is the line height of the second line
   * (as determined by the font(s)). In this case, the spacing
   * set with set_spacing() is ignored.
   *
   * If @a factor is zero (the default), spacing is applied as before.
   *
   * @note for semantics that are closer to the CSS line-height
   * property, see pango_attr_line_height_new().
   *
   * @newin{1,44}
   *
   * @param factor The new line spacing factor.
   */
  void set_line_spacing(float factor);

  /** Gets the line spacing factor of @a layout.
   *
   * See set_line_spacing().
   *
   * @newin{1,44}
   */
  auto get_line_spacing() const -> float;

  /** Sets whether each complete line should be stretched to fill the
   * entire width of the layout.
   *
   * Stretching is typically done by adding whitespace, but for some scripts
   * (such as Arabic), the justification may be done in more complex ways,
   * like extending the characters.
   *
   * Note that this setting is not implemented and so is ignored in
   * Pango older than 1.18.
   *
   * Note that tabs and justification conflict with each other:
   * Justification will move content away from its tab-aligned
   * positions.
   *
   * The default value is <tt>false</tt>.
   *
   * Also see set_justify_last_line().
   *
   * @param justify Whether the lines in the layout should be justified.
   */
  void set_justify(bool justify =  true);

  /** Gets whether each complete line should be stretched to fill the entire
   * width of the layout.
   *
   * @return The justify value.
   */
  auto get_justify() const -> bool;


  /** Gets whether to calculate the base direction for the layout
   * according to its contents.
   *
   * See set_auto_dir().
   *
   * @newin{1,4}
   *
   * @return <tt>true</tt> if the bidirectional base direction
   * is computed from the layout's contents, <tt>false</tt> otherwise.
   */
  auto get_auto_dir() const -> bool;

  /** Sets whether to calculate the base direction
   * for the layout according to its contents.
   *
   * When this flag is on (the default), then paragraphs in @a layout that
   * begin with strong right-to-left characters (Arabic and Hebrew principally),
   * will have right-to-left layout, paragraphs with letters from other scripts
   * will have left-to-right layout. Paragraphs with only neutral characters
   * get their direction from the surrounding paragraphs.
   *
   * When <tt>false</tt>, the choice between left-to-right and right-to-left
   * layout is done according to the base direction of the layout's
   * `Pango::Context`. (See Pango::Context::set_base_dir()).
   *
   * When the auto-computed direction of a paragraph differs from the
   * base direction of the context, the interpretation of
   * Pango::Alignment::LEFT and Pango::Alignment::RIGHT are swapped.
   *
   * @newin{1,4}
   *
   * @param auto_dir If <tt>true</tt>, compute the bidirectional base direction
   * from the layout's contents.
   */
  void set_auto_dir(bool auto_dir =  true);


  /** Sets the alignment for the layout: how partial lines are
   * positioned within the horizontal space available.
   *
   * The default alignment is Pango::Alignment::LEFT.
   *
   * @param alignment The alignment.
   */
  void set_alignment(Alignment alignment);

  /** Gets the alignment for the layout: how partial lines are
   * positioned within the horizontal space available.
   *
   * @return The alignment.
   */
  auto get_alignment() const -> Alignment;


  /** Sets the tabs to use for @a layout, overriding the default tabs.
   *
   * `Pango::Layout` will place content at the next tab position
   * whenever it meets a Tab character (U+0009).
   *
   * By default, tabs are every 8 spaces. If @a tabs is <tt>nullptr</tt>, the
   * default tabs are reinstated. @a tabs is copied into the layout;
   * you must free your copy of @a tabs yourself.
   *
   * Note that tabs and justification conflict with each other:
   * Justification will move content away from its tab-aligned
   * positions. The same is true for alignments other than
   * Pango::Alignment::LEFT.
   *
   * @param tabs A `Pango::TabArray`.
   */
  void set_tabs(TabArray& tabs);

  /** Get the current Pango::TabArray used by this layout. If no
   * Pango::TabArray has been set, then the default tabs are in use
   * and an invalid instance is returned. Default tabs are every 8 spaces.
   *
   * @return A copy of the tabs for this layout.
   */
  auto get_tabs() const -> TabArray;


  /** Sets the single paragraph mode of @a layout.
   *
   * If @a setting is <tt>true</tt>, do not treat newlines and similar characters
   * as paragraph separators; instead, keep all text in a single paragraph,
   * and display a glyph for paragraph separator characters. Used when
   * you want to allow editing of newlines on a single text line.
   *
   * The default value is <tt>false</tt>.
   *
   * @param setting New setting.
   */
  void set_single_paragraph_mode(bool setting =  true);

  /** Obtains whether @a layout is in single paragraph mode.
   *
   * See set_single_paragraph_mode().
   *
   * @return <tt>true</tt> if the layout does not break paragraphs
   * at paragraph separator characters, <tt>false</tt> otherwise.
   */
  auto get_single_paragraph_mode() const -> bool;


  /** Sets the type of ellipsization being performed for @a layout.
   *
   * Depending on the ellipsization mode @a ellipsize text is
   * removed from the start, middle, or end of text so they
   * fit within the width and height of layout set with
   * set_width() and set_height().
   *
   * If the layout contains characters such as newlines that
   * force it to be layed out in multiple paragraphs, then whether
   * each paragraph is ellipsized separately or the entire layout
   * is ellipsized as a whole depends on the set height of the layout.
   *
   * The default value is Pango::EllipsizeMode::NONE.
   *
   * See set_height() for details.
   *
   * @newin{1,6}
   *
   * @param ellipsize The new ellipsization mode for @a layout.
   */
  void set_ellipsize(EllipsizeMode ellipsize);

  /** Gets the type of ellipsization being performed for @a layout.
   *
   * See set_ellipsize().
   *
   * Use is_ellipsized() to query whether any
   * paragraphs were actually ellipsized.
   *
   * @newin{1,6}
   *
   * @return The current ellipsization mode for @a layout.
   */
  auto get_ellipsize() const -> EllipsizeMode;


  /** Queries whether the layout had to ellipsize any paragraphs.
   *
   * This returns <tt>true</tt> if the ellipsization mode for @a layout
   * is not Pango::EllipsizeMode::NONE, a positive width is set on @a layout,
   * and there are paragraphs exceeding that width that have to be
   * ellipsized.
   *
   * @newin{1,16}
   *
   * @return <tt>true</tt> if any paragraphs had to be ellipsized,
   * <tt>false</tt> otherwise.
   */
  auto is_ellipsized() const -> bool;

  /** Counts the number of unknown glyphs in @a layout.
   *
   * This function can be used to determine if there are any fonts
   * available to render all characters in a certain string, or when
   * used in combination with Pango::AttrType::FALLBACK, to check if a
   * certain font supports all the characters in the string.
   *
   * @newin{1,16}
   *
   * @return The number of unknown glyphs in @a layout.
   */
  auto get_unknown_glyphs_count() const -> int;


  /** Forces recomputation of any state in the `Pango::Layout` that
   * might depend on the layout's context.
   *
   * This function should be called if you make changes to the context
   * subsequent to creating the layout.
   */
  void context_changed();


  /** Returns the current serial number of @a layout.
   *
   * The serial number is initialized to an small number larger than zero
   * when a new layout is created and is increased whenever the layout is
   * changed using any of the setter functions, or the `Pango::Context` it
   * uses has changed. The serial may wrap, but will never have the value 0.
   * Since it can wrap, never compare it with "less than", always use "not equals".
   *
   * This can be used to automatically detect changes to a `Pango::Layout`,
   * and is useful for example to decide whether a layout needs redrawing.
   * To force the serial to be increased, use
   * context_changed().
   *
   * @newin{1,32,4}
   *
   * @return The current serial number of @a layout.
   */
  auto get_serial() const -> guint;

  /** Retrieve a vector of logical attributes for each character in the layout.
   *
   * The number of attributes returned will be one more
   * than the total number of characters in the layout, since there
   * need to be attributes corresponding to both the position before
   * the first character and the position after the last character.
   *
   * @return A vector of logical attributes.
   */
  auto get_log_attrs() const -> std::vector<LogAttr>;

  /** Convert from an index within the layout to the onscreen position corresponding to the grapheme at that index, which is represented as rectangle.
   * Note that @a x in the returned rectangle is always the leading edge of the grapheme
   * and @a x + @a width the trailing edge of the grapheme.
   * If the directionality of the grapheme is right-to-left, then @a width will be negative.
   * @param index Byte index within layout.
   * @return The position of the grapheme.
   */
  auto index_to_pos(int index) const -> Rectangle;


  /** Converts from byte @a index within the @a layout to line and X position.
   *
   * The X position is measured from the left edge of the line.
   *
   * @param index The byte index of a grapheme within the layout.
   * @param trailing An integer indicating the edge of the grapheme to retrieve the
   * position of. If > 0, the trailing edge of the grapheme, if 0,
   * the leading of the grapheme.
   * @param line Location to store resulting line index. (which will
   * between 0 and pango_layout_get_line_count(layout) - 1).
   * @param x_pos Location to store resulting position within line
   * (Pango::SCALE units per device unit).
   */
  void index_to_line_x(int index_, bool trailing, int& line, int& x_pos) const;


  /** Given an index within a layout, determines the positions that of the
   * strong and weak cursors if the insertion point is at that index.
   *
   * The position of each cursor is stored as a zero-width rectangle
   * with the height of the run extents.
   *
   * <picture>
   * <source srcset="cursor-positions-dark.png" media="(prefers-color-scheme: dark)">
   * <img alt="Cursor positions" src="cursor-positions-light.png">
   * </picture>
   *
   * The strong cursor location is the location where characters of the
   * directionality equal to the base direction of the layout are inserted.
   * The weak cursor location is the location where characters of the
   * directionality opposite to the base direction of the layout are inserted.
   *
   * The following example shows text with both a strong and a weak cursor.
   *
   * <picture>
   * <source srcset="split-cursor-dark.png" media="(prefers-color-scheme: dark)">
   * <img alt="Strong and weak cursors" src="split-cursor-light.png">
   * </picture>
   *
   * The strong cursor has a little arrow pointing to the right, the weak
   * cursor to the left. Typing a 'c' in this situation will insert the
   * character after the 'b', and typing another Hebrew character, like 'ג',
   * will insert it at the end.
   *
   * @param index The byte index of the cursor.
   * @param strong_pos Location to store the strong cursor position.
   * @param weak_pos Location to store the weak cursor position.
   */
  void get_cursor_pos(int index, Rectangle& strong_pos, Rectangle& weak_pos) const;

  /** Given an index within the layout, determine the positions that of the strong cursors if the insertion point is at that index.
   * @param index The byte index of the cursor.
   * @return The strong cursor position.
   */
  auto get_cursor_strong_pos(int index) const -> Rectangle;

  /** Given an index within the layout, determine the positions that of the weak cursors if the insertion point is at that index.
   * @param index The byte index of the cursor.
   * @return The weak cursor position.
   */
  auto get_cursor_weak_pos(int index) const -> Rectangle;


  /** Computes a new cursor position from an old position and a direction.
   *
   * If @a direction is positive, then the new position will cause the strong
   * or weak cursor to be displayed one position to right of where it was
   * with the old cursor position. If @a direction is negative, it will be
   * moved to the left.
   *
   * In the presence of bidirectional text, the correspondence between
   * logical and visual order will depend on the direction of the current
   * run, and there may be jumps when the cursor is moved off of the end
   * of a run.
   *
   * Motion here is in cursor positions, not in characters, so a single
   * call to this function may move the cursor over multiple characters
   * when multiple characters combine to form a single grapheme.
   *
   * @param strong Whether the moving cursor is the strong cursor or the
   * weak cursor. The strong cursor is the cursor corresponding
   * to text insertion in the base direction for the layout.
   * @param old_index The byte index of the current cursor position.
   * @param old_trailing If 0, the cursor was at the leading edge of the
   * grapheme indicated by @a old_index, if > 0, the cursor
   * was at the trailing edge.
   * @param direction Direction to move cursor. A negative
   * value indicates motion to the left.
   * @param new_index Location to store the new cursor byte index.
   * A value of -1 indicates that the cursor has been moved off the
   * beginning of the layout. A value of G_MAXINT indicates that
   * the cursor has been moved off the end of the layout.
   * @param new_trailing Number of characters to move forward from
   * the location returned for @a new_index to get the position where
   * the cursor should be displayed. This allows distinguishing the
   * position at the beginning of one line from the position at the
   * end of the preceding line. @a new_index is always on the line where
   * the cursor should be displayed.
   */
  void move_cursor_visually(bool strong, int old_index, int old_trailing, int direction, int& new_index, int& new_trailing) const;


  /** Converts from X and Y position within a layout to the byte index to the
   * character at that logical position.
   *
   * If the Y position is not inside the layout, the closest position is
   * chosen (the position will be clamped inside the layout). If the X position
   * is not within the layout, then the start or the end of the line is
   * chosen as described for Pango::LayoutLine::x_to_index(). If either
   * the X or Y positions were not inside the layout, then the function returns
   * <tt>false</tt>; on an exact hit, it returns <tt>true</tt>.
   *
   * @param x The X offset (in Pango units) from the left edge of the layout.
   * @param y The Y offset (in Pango units) from the top edge of the layout.
   * @param index Location to store calculated byte index.
   * @param trailing Location to store a integer indicating where
   * in the grapheme the user clicked. It will either be zero, or the
   * number of characters in the grapheme. 0 represents the leading edge
   * of the grapheme.
   * @return <tt>true</tt> if the coordinates were inside text, <tt>false</tt> otherwise.
   */
  auto xy_to_index(int x, int y, int& index, int& trailing) const -> bool;


  /** Compute the logical and ink extents of @a layout. Logical extents
   * are usually what you want for positioning things. The extents
   * are given in layout coordinates; layout coordinates begin at the
   * top left corner of the layout.
   *
   * @param ink_rect Rectangle used to store the extents of the layout as drawn.
   * @param logical_rect Rectangle used to store the logical extents of the layout.
   */
  void get_extents(Rectangle& ink_rect, Rectangle& logical_rect) const;

  /** Compute the ink extents of layout.
   * @return The extents of the layout as drawn.
   */
  auto get_ink_extents() const -> Rectangle;

  /** Compute the logical extents of layout.
   * @return The logical extents of the layout.
   */
  auto get_logical_extents() const -> Rectangle;


  /** Compute the logical and ink extents of @a layout in device units.
   * See get_extents(); this function just calls
   * get_extents() and then converts the extents to
   * pixels using the Pango::SCALE factor.
   *
   * @param ink_rect Rectangle used to store the extents of the layout as drawn.
   * @param logical_rect Rectangle used to store the logical extents of the
   * layout.
   */
  void get_pixel_extents(Rectangle& ink_rect, Rectangle& logical_rect) const;

  /** Compute the ink extents of the layout in device units.
   * @return The extents of the layout as drawn.
   */
  auto get_pixel_ink_extents() const -> Rectangle;

  /** Compute the logical extents of the layout in device units.
   * @return The logical extents of the layout.
   */
  auto get_pixel_logical_extents() const -> Rectangle;


  /** Determines the logical width and height of a `Pango::Layout` in Pango
   * units.
   *
   * This is simply a convenience function around get_extents().
   *
   * @param width Location to store the logical width.
   * @param height Location to store the logical height.
   */
  void get_size(int& width, int& height) const;

  /** Determines the logical width and height of a `Pango::Layout` in device
   * units.
   *
   * get_size() returns the width and height
   * scaled by Pango::SCALE. This is simply a convenience function
   * around get_pixel_extents().
   *
   * @param width Location to store the logical width.
   * @param height Location to store the logical height.
   */
  void get_pixel_size(int& width, int& height) const;


  /** Gets the Y position of baseline of the first line in @a layout.
   *
   * @newin{1,22}
   *
   * @return Baseline of first line, from top of @a layout.
   */
  auto get_baseline() const -> int;


  /** Retrieves the count of lines for the @a layout.
   *
   * @return The line count.
   */
  auto get_line_count() const -> int;

  //Note that the const version uses a different (faster) C function:

  /** Retrieves a particular line from a Pango::Layout.
   *
   * Use the faster get_const_line() if you do not plan
   * to modify the contents of the line (glyphs, glyph widths, etc.).
   *
   * @param line The index of a line, which must be between 0 and
   * <tt>get_line_count() - 1</tt>, inclusive.
   * @return The requested Pango::LayoutLine, or an empty RefPtr if the index
   * is out of range. This layout line will become invalid if changes are made
   * to the Pango::Layout.
   */
  auto get_line(int line) -> Glib::RefPtr<LayoutLine>;


  /** Retrieves a particular line from a Pango::Layout.
   *
   * @param line The index of a line, which must be between 0 and
   * <tt>get_line_count() - 1</tt>, inclusive.
   * @return The requested Pango::LayoutLine, or an empty RefPtr if the index
   * is out of range. This layout line will become invalid if changes are made
   * to the Pango::Layout. No changes should be made to the line.
   */
  auto get_line(int line) const -> Glib::RefPtr<const LayoutLine>;


  /** Retrieves a particular line from a Pango::Layout.
   *
   * This is a faster alternative to get_line(), but the user is not expected
   * to modify the contents of the line (glyphs, glyph widths, etc.).
   *
   * @newin{2,50}
   *
   * @param line The index of a line, which must be between 0 and
   * <tt>get_line_count() - 1</tt>, inclusive.
   * @return The requested Pango::LayoutLine, or an empty RefPtr if the index
   * is out of range. This layout line will become invalid if changes are made
   * to the Pango::Layout. No changes should be made to the line.
   */
  auto get_const_line(int line) const -> Glib::RefPtr<const LayoutLine>;


  //Note that the const version uses a different (faster) C function:

  /** Returns the lines of the layout as a vector.
   *
   * Use the faster get_const_lines() if you do not plan
   * to modify the contents of the lines (glyphs, glyph widths, etc.).
   *
   * @return A std::vector containing
   * the lines in the layout. This points to internal data of the Pango::Layout
   * and must be used with care. It will become invalid on any change to the layout's
   * text or properties.
   */
  auto get_lines() -> std::vector<Glib::RefPtr<LayoutLine>>;


  /** Returns the lines of the layout as a vector.
   *
   * @return A std::vector containing
   * the lines in the layout. This points to internal data of the Pango::Layout and
   * must be used with care. It will become invalid on any change to the layout's
   * text or properties. No changes should be made to the lines.
   */
  auto get_lines() const -> std::vector<Glib::RefPtr<const LayoutLine>>;


  /** Returns the lines of the layout as a vector.
   *
   * This is a faster alternative to get_lines(), but the user is not expected
   * to modify the contents of the lines (glyphs, glyph widths, etc.).
   *
   * @newin{2,50}
   *
   * @return A std::vector containing
   * the lines in the layout. This points to internal data of the Pango::Layout and
   * must be used with care. It will become invalid on any change to the layout's
   * text or properties. No changes should be made to the lines.
   */
  auto get_const_lines() const -> std::vector<Glib::RefPtr<const LayoutLine>>;

  /** Gets an iterator to iterate over the visual extents of the layout.
   * @return The iterator.
   *
   * @newin{2,28}
   */
  auto get_iter() -> LayoutIter;

  /** Adds the text in this LayoutLine to the current path in the
   * specified Cairo @a context. The origin of the glyphs (the left edge
   * of the line) will be at the current point of the cairo context.
   *
   * @param context A Cairo context.
   */
  void add_to_cairo_context(const Cairo::RefPtr<Cairo::Context>& context);

  /** Draws a Layout in the specified Cairo @a context. The top-left
   *  corner of the Layout will be drawn at the current point of the
   *  cairo context.
   *
   * @param context A Cairo context.
   *
   * @newin{2,16}
   */
  void show_in_cairo_context(const Cairo::RefPtr<Cairo::Context>& context);


public:

public:
  //C++ methods used to invoke GTK+ virtual functions:

protected:
  //GTK+ Virtual Functions (override these to change behaviour):

  //Default Signal Handlers::


};

} /* namespace Pango */


namespace Glib
{
  /** A Glib::wrap() method for this object.
   *
   * @param object The C instance.
   * @param take_copy False if the result should take ownership of the C instance. True if it should take a new copy or ref.
   * @result A C++ instance that wraps this C instance.
   *
   * @relates Pango::Layout
   */
  PANGOMM_API
  auto wrap(PangoLayout* object, bool take_copy = false) -> Glib::RefPtr<Pango::Layout>;
}


#endif /* _PANGOMM_LAYOUT_H */
