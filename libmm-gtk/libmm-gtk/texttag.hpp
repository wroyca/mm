
#ifndef _GTKMM_TEXTTAG_H
#define _GTKMM_TEXTTAG_H

#include <libmm-gtk/mm-gtkconfig.hpp>


#include <libmm-glib/ustring.hpp>
#include <sigc++/sigc++.h>

/*
 * Copyright (C) 1998-2002 The gtkmm Development Team
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
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 */


#include <libmm-glib/object.hpp>
#include <libmm-gtk/enums.hpp>
#include <libmm-gdk/rgba.hpp>
#include <libmm-pango/attributes.hpp>
#include <libmm-pango/fontdescription.hpp>
#include <libmm-pango/tabarray.hpp>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkTextTag = struct _GtkTextTag;
using GtkTextTagClass = struct _GtkTextTagClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{ class GTKMM_API TextTag_Class; } // namespace Gtk
#endif //DOXYGEN_SHOULD_SKIP_THIS

namespace Gtk
{

/** Typedefed as Gtk::TextBuffer::Tag.
 *
 * Text in a buffer can be marked with tags. A tag is an attribute that can be applied to some range of text. For example, a tag
 * might be called "bold" and might make the text inside the tag bold. However, the tag concept is more general than that; tags don't
 * have to affect appearance. They can instead affect the behavior of mouse and key presses, "lock" a range of text so the user
 * can't edit it, or countless other things.
 * One tag can be applied to any number of text ranges in any number of @link Gtk::TextBuffer Gtk::TextBuffers@endlink.
 *
 * Each tag is stored in a @link Gtk::TextTagTable Gtk::TextBuffer::TagTable@endlink, and Tags should be in the
 * @link Gtk::TextTagTable Gtk::TextBuffer::TagTable@endlink for a given Gtk::TextBuffer before using
 * them with that buffer.
 *
 * Tags can have names, which is convenient sometimes (for example, you can name your tag that makes things bold "bold"), but
 * they can also be anonymous (which is convenient if you're creating tags on-the-fly).
 *
 * Gtk::TextBuffer::create_tag() is the best way to create tags. See the demo for numerous examples.
 *
 * @ingroup TextView
 */

class GTKMM_API TextTag : public Glib::Object
{

#ifndef DOXYGEN_SHOULD_SKIP_THIS

public:
  using CppObjectType = TextTag;
  using CppClassType = TextTag_Class;
  using BaseObjectType = GtkTextTag;
  using BaseClassType = GtkTextTagClass;

  // noncopyable
  TextTag(const TextTag&) = delete;
  auto operator=(const TextTag&) -> TextTag& = delete;

private:  friend class TextTag_Class;
  static CppClassType texttag_class_;

protected:
  explicit TextTag(const Glib::ConstructParams& construct_params);
  explicit TextTag(GtkTextTag* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  TextTag(TextTag&& src) noexcept;
  auto operator=(TextTag&& src) noexcept -> TextTag&;

  ~TextTag() noexcept override;

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS


  static auto get_base_type() -> GType G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GObject.
  auto       gobj() -> GtkTextTag*       { return reinterpret_cast<GtkTextTag*>(gobject_); }

  ///Provides access to the underlying C GObject.
  auto gobj() const -> const GtkTextTag* { return reinterpret_cast<GtkTextTag*>(gobject_); }

  ///Provides access to the underlying C instance. The caller is responsible for unrefing it. Use when directly setting fields in structs.
  auto gobj_copy() -> GtkTextTag*;

private:

protected:
  TextTag();
    explicit TextTag(const Glib::ustring& name);


public:

  static auto create() -> Glib::RefPtr<TextTag>;


  static auto create(const Glib::ustring& name) -> Glib::RefPtr<TextTag>;


  /** Get the tag priority.
   *
   * @return The tag’s priority.
   */
  auto get_priority() const -> int;

  /** Sets the priority of a `Gtk::TextTag`.
   *
   * Valid priorities start at 0 and go to one less than
   * Gtk::TextTagTable::get_size(). Each tag in a table
   * has a unique priority; setting the priority of one tag shifts
   * the priorities of all the other tags in the table to maintain
   * a unique priority for each tag.
   *
   * Higher priority tags “win” if two tags both set the same text
   * attribute. When adding a tag to a tag table, it will be assigned
   * the highest priority in the table by default; so normally the
   * precedence of a set of tags is the order in which they were added
   * to the table, or created with Gtk::TextBuffer::create_tag(),
   * which adds the tag to the buffer’s table automatically.
   *
   * @param priority The new priority.
   */
  void set_priority(int priority);

  /** Emits the Gtk::TextTagTable::signal_tag_changed() signal on the
   * `Gtk::TextTagTable` where the tag is included.
   *
   * The signal is already emitted when setting a `Gtk::TextTag` property.
   * This function is useful for a `Gtk::TextTag` subclass.
   *
   * @param size_changed Whether the change affects the `Gtk::TextView` layout.
   */
  void tag_changed(bool size_changed);

  /** The name used to refer to the tag.
   *
   * <tt>nullptr</tt> for anonymous tags.
   *
   * Default value: ""
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_name() const -> Glib::PropertyProxy_ReadOnly< Glib::ustring >;

 //construct-only.
  /** Background color as a string.
   *
   * Default value: ""
   *
   * @return A PropertyProxy_WriteOnly that allows you to set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_background() -> Glib::PropertyProxy_WriteOnly< Glib::ustring > ;


  /** Foreground color as a string.
   *
   * Default value: ""
   *
   * @return A PropertyProxy_WriteOnly that allows you to set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_foreground() -> Glib::PropertyProxy_WriteOnly< Glib::ustring > ;


  /** Background color as a `GdkRGBA`.
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_background_rgba() -> Glib::PropertyProxy< Gdk::RGBA > ;

/** Background color as a `GdkRGBA`.
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_background_rgba() const -> Glib::PropertyProxy_ReadOnly< Gdk::RGBA >;

  /** Foreground color as a `GdkRGBA`.
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_foreground_rgba() -> Glib::PropertyProxy< Gdk::RGBA > ;

/** Foreground color as a `GdkRGBA`.
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_foreground_rgba() const -> Glib::PropertyProxy_ReadOnly< Gdk::RGBA >;

  /** Font description as string, e.g.\ \\"Sans Italic 12\\".
   *
   * Note that the initial value of this property depends on
   * the internals of `Pango::FontDescription`.
   *
   * Default value: ""
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_font() -> Glib::PropertyProxy< Glib::ustring > ;

/** Font description as string, e.g.\ \\"Sans Italic 12\\".
   *
   * Note that the initial value of this property depends on
   * the internals of `Pango::FontDescription`.
   *
   * Default value: ""
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_font() const -> Glib::PropertyProxy_ReadOnly< Glib::ustring >;

  /** Font description as a `Pango::FontDescription`.
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_font_desc() -> Glib::PropertyProxy< Pango::FontDescription > ;

/** Font description as a `Pango::FontDescription`.
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_font_desc() const -> Glib::PropertyProxy_ReadOnly< Pango::FontDescription >;

  /** Name of the font family, e.g.\ Sans, Helvetica, Times, Monospace.
   *
   * Default value: ""
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_family() -> Glib::PropertyProxy< Glib::ustring > ;

/** Name of the font family, e.g.\ Sans, Helvetica, Times, Monospace.
   *
   * Default value: ""
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_family() const -> Glib::PropertyProxy_ReadOnly< Glib::ustring >;

  /** Font style as a `Pango::Style`, e.g.\ Pango::Style::ITALIC.
   *
   * Default value: Pango::Style::NORMAL
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_style() -> Glib::PropertyProxy< Pango::Style > ;

/** Font style as a `Pango::Style`, e.g.\ Pango::Style::ITALIC.
   *
   * Default value: Pango::Style::NORMAL
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_style() const -> Glib::PropertyProxy_ReadOnly< Pango::Style >;

  /** Font variant as a `Pango::Variant`, e.g.\ Pango::Variant::SMALL_CAPS.
   *
   * Default value: Pango::Variant::NORMAL
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_variant() -> Glib::PropertyProxy< Pango::Variant > ;

/** Font variant as a `Pango::Variant`, e.g.\ Pango::Variant::SMALL_CAPS.
   *
   * Default value: Pango::Variant::NORMAL
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_variant() const -> Glib::PropertyProxy_ReadOnly< Pango::Variant >;

  /** Font weight as an integer.
   *
   * Default value: 400
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_weight() -> Glib::PropertyProxy< int > ;

/** Font weight as an integer.
   *
   * Default value: 400
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_weight() const -> Glib::PropertyProxy_ReadOnly< int >;

  /** Font stretch as a `Pango::Stretch`, e.g.\ Pango::Stretch::CONDENSED.
   *
   * Default value: Pango::Stretch::NORMAL
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_stretch() -> Glib::PropertyProxy< Pango::Stretch > ;

/** Font stretch as a `Pango::Stretch`, e.g.\ Pango::Stretch::CONDENSED.
   *
   * Default value: Pango::Stretch::NORMAL
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_stretch() const -> Glib::PropertyProxy_ReadOnly< Pango::Stretch >;

  /** Font size in Pango units.
   *
   * Default value: 0
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_size() -> Glib::PropertyProxy< int > ;

/** Font size in Pango units.
   *
   * Default value: 0
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_size() const -> Glib::PropertyProxy_ReadOnly< int >;

  /** Font size in points.
   *
   * Default value: 0
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_size_points() -> Glib::PropertyProxy< double > ;

/** Font size in points.
   *
   * Default value: 0
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_size_points() const -> Glib::PropertyProxy_ReadOnly< double >;

  /** Font size as a scale factor relative to the default font size.
   *
   * This properly adapts to theme changes, etc. so is recommended.
   * Pango predefines some scales such as Pango::SCALE_X_LARGE.
   *
   * Default value: 1
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_scale() -> Glib::PropertyProxy< double > ;

/** Font size as a scale factor relative to the default font size.
   *
   * This properly adapts to theme changes, etc. so is recommended.
   * Pango predefines some scales such as Pango::SCALE_X_LARGE.
   *
   * Default value: 1
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_scale() const -> Glib::PropertyProxy_ReadOnly< double >;

  /** Pixels of blank space above paragraphs.
   *
   * Default value: 0
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_pixels_above_lines() -> Glib::PropertyProxy< int > ;

/** Pixels of blank space above paragraphs.
   *
   * Default value: 0
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_pixels_above_lines() const -> Glib::PropertyProxy_ReadOnly< int >;

  /** Pixels of blank space below paragraphs.
   *
   * Default value: 0
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_pixels_below_lines() -> Glib::PropertyProxy< int > ;

/** Pixels of blank space below paragraphs.
   *
   * Default value: 0
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_pixels_below_lines() const -> Glib::PropertyProxy_ReadOnly< int >;

  /** Pixels of blank space between wrapped lines in a paragraph.
   *
   * Default value: 0
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_pixels_inside_wrap() -> Glib::PropertyProxy< int > ;

/** Pixels of blank space between wrapped lines in a paragraph.
   *
   * Default value: 0
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_pixels_inside_wrap() const -> Glib::PropertyProxy_ReadOnly< int >;

  /** Whether the text can be modified by the user.
   *
   * Default value: <tt>true</tt>
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_editable() -> Glib::PropertyProxy< bool > ;

/** Whether the text can be modified by the user.
   *
   * Default value: <tt>true</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_editable() const -> Glib::PropertyProxy_ReadOnly< bool >;

  /** Whether to wrap lines never, at word boundaries, or
   * at character boundaries.
   *
   * Default value: Gtk::WrapMode::NONE
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_wrap_mode() -> Glib::PropertyProxy< WrapMode > ;

/** Whether to wrap lines never, at word boundaries, or
   * at character boundaries.
   *
   * Default value: Gtk::WrapMode::NONE
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_wrap_mode() const -> Glib::PropertyProxy_ReadOnly< WrapMode >;

  /** Left, right, or center justification.
   *
   * Default value: Gtk::Justification::LEFT
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_justification() -> Glib::PropertyProxy< Justification > ;

/** Left, right, or center justification.
   *
   * Default value: Gtk::Justification::LEFT
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_justification() const -> Glib::PropertyProxy_ReadOnly< Justification >;

  /** Text direction, e.g.\ right-to-left or left-to-right.
   *
   * Default value: Gtk::TextDirection::NONE
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_direction() -> Glib::PropertyProxy< TextDirection > ;

/** Text direction, e.g.\ right-to-left or left-to-right.
   *
   * Default value: Gtk::TextDirection::NONE
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_direction() const -> Glib::PropertyProxy_ReadOnly< TextDirection >;

  /** Width of the left margin in pixels.
   *
   * Default value: 0
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_left_margin() -> Glib::PropertyProxy< int > ;

/** Width of the left margin in pixels.
   *
   * Default value: 0
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_left_margin() const -> Glib::PropertyProxy_ReadOnly< int >;

  /** Amount to indent the paragraph, in pixels.
   *
   * Default value: 0
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_indent() -> Glib::PropertyProxy< int > ;

/** Amount to indent the paragraph, in pixels.
   *
   * Default value: 0
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_indent() const -> Glib::PropertyProxy_ReadOnly< int >;

  /** Factor to scale line height by.
   *
   * @newin{4,6}
   *
   * Default value: 0
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_line_height() -> Glib::PropertyProxy< float > ;

/** Factor to scale line height by.
   *
   * @newin{4,6}
   *
   * Default value: 0
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_line_height() const -> Glib::PropertyProxy_ReadOnly< float >;

  /** Whether to strike through the text.
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_strikethrough() -> Glib::PropertyProxy< bool > ;

/** Whether to strike through the text.
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_strikethrough() const -> Glib::PropertyProxy_ReadOnly< bool >;

  /** This property modifies the color of strikeouts.
   *
   * If not set, strikeouts will use the foreground color.
   *
   * @newin{3,20}
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_strikethrough_rgba() -> Glib::PropertyProxy< Gdk::RGBA > ;

/** This property modifies the color of strikeouts.
   *
   * If not set, strikeouts will use the foreground color.
   *
   * @newin{3,20}
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_strikethrough_rgba() const -> Glib::PropertyProxy_ReadOnly< Gdk::RGBA >;

  /** Width of the right margin, in pixels.
   *
   * Default value: 0
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_right_margin() -> Glib::PropertyProxy< int > ;

/** Width of the right margin, in pixels.
   *
   * Default value: 0
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_right_margin() const -> Glib::PropertyProxy_ReadOnly< int >;

  /** Style of underline for this text.
   *
   * Default value: Pango::Underline::NONE
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_underline() -> Glib::PropertyProxy< Pango::Underline > ;

/** Style of underline for this text.
   *
   * Default value: Pango::Underline::NONE
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_underline() const -> Glib::PropertyProxy_ReadOnly< Pango::Underline >;

  /** This property modifies the color of underlines.
   *
   * If not set, underlines will use the foreground color.
   *
   * If property_underline() is set to Pango::Underline::ERROR,
   * an alternate color may be applied instead of the foreground. Setting
   * this property will always override those defaults.
   *
   * @newin{3,20}
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_underline_rgba() -> Glib::PropertyProxy< Gdk::RGBA > ;

/** This property modifies the color of underlines.
   *
   * If not set, underlines will use the foreground color.
   *
   * If property_underline() is set to Pango::Underline::ERROR,
   * an alternate color may be applied instead of the foreground. Setting
   * this property will always override those defaults.
   *
   * @newin{3,20}
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_underline_rgba() const -> Glib::PropertyProxy_ReadOnly< Gdk::RGBA >;

  /** Style of overline for this text.
   *
   * Default value: Pango::Overline::NONE
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_overline() -> Glib::PropertyProxy< Pango::Overline > ;

/** Style of overline for this text.
   *
   * Default value: Pango::Overline::NONE
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_overline() const -> Glib::PropertyProxy_ReadOnly< Pango::Overline >;

  /** This property modifies the color of overlines.
   *
   * If not set, overlines will use the foreground color.
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_overline_rgba() -> Glib::PropertyProxy< Gdk::RGBA > ;

/** This property modifies the color of overlines.
   *
   * If not set, overlines will use the foreground color.
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_overline_rgba() const -> Glib::PropertyProxy_ReadOnly< Gdk::RGBA >;

  /** Offset of text above the baseline, in Pango units.
   *
   * Negative values go below the baseline.
   *
   * Default value: 0
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_rise() -> Glib::PropertyProxy< int > ;

/** Offset of text above the baseline, in Pango units.
   *
   * Negative values go below the baseline.
   *
   * Default value: 0
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_rise() const -> Glib::PropertyProxy_ReadOnly< int >;

  /** Whether the background color fills the entire line height
   * or only the height of the tagged characters.
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_background_full_height() -> Glib::PropertyProxy< bool > ;

/** Whether the background color fills the entire line height
   * or only the height of the tagged characters.
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_background_full_height() const -> Glib::PropertyProxy_ReadOnly< bool >;

  /** The language this text is in, as an ISO code.
   *
   * Pango can use this as a hint when rendering the text.
   * If not set, an appropriate default will be used.
   *
   * Note that the initial value of this property depends
   * on the current locale, see also gtk_get_default_language().
   *
   * Default value: ""
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_language() -> Glib::PropertyProxy< Glib::ustring > ;

/** The language this text is in, as an ISO code.
   *
   * Pango can use this as a hint when rendering the text.
   * If not set, an appropriate default will be used.
   *
   * Note that the initial value of this property depends
   * on the current locale, see also gtk_get_default_language().
   *
   * Default value: ""
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_language() const -> Glib::PropertyProxy_ReadOnly< Glib::ustring >;

  /** Custom tabs for this text.
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_tabs() -> Glib::PropertyProxy< Pango::TabArray > ;

/** Custom tabs for this text.
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_tabs() const -> Glib::PropertyProxy_ReadOnly< Pango::TabArray >;

  /** Whether this text is hidden.
   *
   * Note that there may still be problems with the support for invisible
   * text, in particular when navigating programmatically inside a buffer
   * containing invisible segments.
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_invisible() -> Glib::PropertyProxy< bool > ;

/** Whether this text is hidden.
   *
   * Note that there may still be problems with the support for invisible
   * text, in particular when navigating programmatically inside a buffer
   * containing invisible segments.
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_invisible() const -> Glib::PropertyProxy_ReadOnly< bool >;

  /** The paragraph background color as a string.
   *
   * Default value: ""
   *
   * @return A PropertyProxy_WriteOnly that allows you to set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_paragraph_background() -> Glib::PropertyProxy_WriteOnly< Glib::ustring > ;


  /** The paragraph background color as a `GdkRGBA`.
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_paragraph_background_rgba() -> Glib::PropertyProxy< Gdk::RGBA > ;

/** The paragraph background color as a `GdkRGBA`.
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_paragraph_background_rgba() const -> Glib::PropertyProxy_ReadOnly< Gdk::RGBA >;

  /** OpenType font features, as a string.
   *
   * @newin{3,20}
   *
   * Default value: ""
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_font_features() -> Glib::PropertyProxy< Glib::ustring > ;

/** OpenType font features, as a string.
   *
   * @newin{3,20}
   *
   * Default value: ""
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_font_features() const -> Glib::PropertyProxy_ReadOnly< Glib::ustring >;

  /** Whether breaks are allowed.
   *
   * Default value: <tt>true</tt>
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_allow_breaks() -> Glib::PropertyProxy< bool > ;

/** Whether breaks are allowed.
   *
   * Default value: <tt>true</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_allow_breaks() const -> Glib::PropertyProxy_ReadOnly< bool >;

  /** How to render invisible characters.
   *
   * Default value: Pango::ShowFlags::NONE
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_show_spaces() -> Glib::PropertyProxy< Pango::ShowFlags > ;

/** How to render invisible characters.
   *
   * Default value: Pango::ShowFlags::NONE
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_show_spaces() const -> Glib::PropertyProxy_ReadOnly< Pango::ShowFlags >;

  /** Whether to insert hyphens at breaks.
   *
   * Default value: <tt>true</tt>
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_insert_hyphens() -> Glib::PropertyProxy< bool > ;

/** Whether to insert hyphens at breaks.
   *
   * Default value: <tt>true</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_insert_hyphens() const -> Glib::PropertyProxy_ReadOnly< bool >;

  /** How to transform the text for display.
   *
   * @newin{4,6}
   *
   * Default value: Pango::TextTransform::NONE
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_text_transform() -> Glib::PropertyProxy< Pango::TextTransform > ;

/** How to transform the text for display.
   *
   * @newin{4,6}
   *
   * Default value: Pango::TextTransform::NONE
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_text_transform() const -> Glib::PropertyProxy_ReadOnly< Pango::TextTransform >;

  /** Whether this tag represents a single word.
   *
   * This affects line breaks and cursor movement.
   *
   * @newin{4,6}
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_word() -> Glib::PropertyProxy< bool > ;

/** Whether this tag represents a single word.
   *
   * This affects line breaks and cursor movement.
   *
   * @newin{4,6}
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_word() const -> Glib::PropertyProxy_ReadOnly< bool >;

  /** Whether this tag represents a single sentence.
   *
   * This affects cursor movement.
   *
   * @newin{4,6}
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_sentence() -> Glib::PropertyProxy< bool > ;

/** Whether this tag represents a single sentence.
   *
   * This affects cursor movement.
   *
   * @newin{4,6}
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_sentence() const -> Glib::PropertyProxy_ReadOnly< bool >;

  /** Whether the margins accumulate or override each other.
   *
   * When set to <tt>true</tt> the margins of this tag are added to the margins
   * of any other non-accumulative margins present. When set to <tt>false</tt>
   * the margins override one another (the default).
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_accumulative_margin() -> Glib::PropertyProxy< bool > ;

/** Whether the margins accumulate or override each other.
   *
   * When set to <tt>true</tt> the margins of this tag are added to the margins
   * of any other non-accumulative margins present. When set to <tt>false</tt>
   * the margins override one another (the default).
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_accumulative_margin() const -> Glib::PropertyProxy_ReadOnly< bool >;

  /** Default value: <tt>false</tt>
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_background_set() -> Glib::PropertyProxy< bool > ;

/** Default value: <tt>false</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_background_set() const -> Glib::PropertyProxy_ReadOnly< bool >;

  /** Default value: <tt>false</tt>
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_foreground_set() -> Glib::PropertyProxy< bool > ;

/** Default value: <tt>false</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_foreground_set() const -> Glib::PropertyProxy_ReadOnly< bool >;

  /** Default value: <tt>false</tt>
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_family_set() -> Glib::PropertyProxy< bool > ;

/** Default value: <tt>false</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_family_set() const -> Glib::PropertyProxy_ReadOnly< bool >;

  /** Default value: <tt>false</tt>
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_style_set() -> Glib::PropertyProxy< bool > ;

/** Default value: <tt>false</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_style_set() const -> Glib::PropertyProxy_ReadOnly< bool >;

  /** Default value: <tt>false</tt>
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_variant_set() -> Glib::PropertyProxy< bool > ;

/** Default value: <tt>false</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_variant_set() const -> Glib::PropertyProxy_ReadOnly< bool >;

  /** Default value: <tt>false</tt>
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_weight_set() -> Glib::PropertyProxy< bool > ;

/** Default value: <tt>false</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_weight_set() const -> Glib::PropertyProxy_ReadOnly< bool >;

  /** Default value: <tt>false</tt>
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_stretch_set() -> Glib::PropertyProxy< bool > ;

/** Default value: <tt>false</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_stretch_set() const -> Glib::PropertyProxy_ReadOnly< bool >;

  /** Default value: <tt>false</tt>
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_size_set() -> Glib::PropertyProxy< bool > ;

/** Default value: <tt>false</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_size_set() const -> Glib::PropertyProxy_ReadOnly< bool >;

  /** Default value: <tt>false</tt>
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_scale_set() -> Glib::PropertyProxy< bool > ;

/** Default value: <tt>false</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_scale_set() const -> Glib::PropertyProxy_ReadOnly< bool >;

  /** Default value: <tt>false</tt>
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_pixels_above_lines_set() -> Glib::PropertyProxy< bool > ;

/** Default value: <tt>false</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_pixels_above_lines_set() const -> Glib::PropertyProxy_ReadOnly< bool >;

  /** Default value: <tt>false</tt>
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_pixels_below_lines_set() -> Glib::PropertyProxy< bool > ;

/** Default value: <tt>false</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_pixels_below_lines_set() const -> Glib::PropertyProxy_ReadOnly< bool >;

  /** Default value: <tt>false</tt>
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_pixels_inside_wrap_set() -> Glib::PropertyProxy< bool > ;

/** Default value: <tt>false</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_pixels_inside_wrap_set() const -> Glib::PropertyProxy_ReadOnly< bool >;

  /** Default value: <tt>false</tt>
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_editable_set() -> Glib::PropertyProxy< bool > ;

/** Default value: <tt>false</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_editable_set() const -> Glib::PropertyProxy_ReadOnly< bool >;

  /** Default value: <tt>false</tt>
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_wrap_mode_set() -> Glib::PropertyProxy< bool > ;

/** Default value: <tt>false</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_wrap_mode_set() const -> Glib::PropertyProxy_ReadOnly< bool >;

  /** Default value: <tt>false</tt>
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_justification_set() -> Glib::PropertyProxy< bool > ;

/** Default value: <tt>false</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_justification_set() const -> Glib::PropertyProxy_ReadOnly< bool >;

  /** Default value: <tt>false</tt>
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_left_margin_set() -> Glib::PropertyProxy< bool > ;

/** Default value: <tt>false</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_left_margin_set() const -> Glib::PropertyProxy_ReadOnly< bool >;

  /** Default value: <tt>false</tt>
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_indent_set() -> Glib::PropertyProxy< bool > ;

/** Default value: <tt>false</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_indent_set() const -> Glib::PropertyProxy_ReadOnly< bool >;

  /** Default value: <tt>false</tt>
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_line_height_set() -> Glib::PropertyProxy< bool > ;

/** Default value: <tt>false</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_line_height_set() const -> Glib::PropertyProxy_ReadOnly< bool >;

  /** Default value: <tt>false</tt>
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_strikethrough_set() -> Glib::PropertyProxy< bool > ;

/** Default value: <tt>false</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_strikethrough_set() const -> Glib::PropertyProxy_ReadOnly< bool >;

  /** If the `strikethrough-rgba` property has been set.
   *
   * @newin{3,20}
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_strikethrough_rgba_set() -> Glib::PropertyProxy< bool > ;

/** If the `strikethrough-rgba` property has been set.
   *
   * @newin{3,20}
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_strikethrough_rgba_set() const -> Glib::PropertyProxy_ReadOnly< bool >;

  /** Default value: <tt>false</tt>
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_right_margin_set() -> Glib::PropertyProxy< bool > ;

/** Default value: <tt>false</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_right_margin_set() const -> Glib::PropertyProxy_ReadOnly< bool >;

  /** Default value: <tt>false</tt>
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_underline_set() -> Glib::PropertyProxy< bool > ;

/** Default value: <tt>false</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_underline_set() const -> Glib::PropertyProxy_ReadOnly< bool >;

  /** If the `underline-rgba` property has been set.
   *
   * @newin{3,20}
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_underline_rgba_set() -> Glib::PropertyProxy< bool > ;

/** If the `underline-rgba` property has been set.
   *
   * @newin{3,20}
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_underline_rgba_set() const -> Glib::PropertyProxy_ReadOnly< bool >;

  /** Default value: <tt>false</tt>
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_overline_set() -> Glib::PropertyProxy< bool > ;

/** Default value: <tt>false</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_overline_set() const -> Glib::PropertyProxy_ReadOnly< bool >;

  /** Default value: <tt>false</tt>
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_overline_rgba_set() -> Glib::PropertyProxy< bool > ;

/** Default value: <tt>false</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_overline_rgba_set() const -> Glib::PropertyProxy_ReadOnly< bool >;

  /** Default value: <tt>false</tt>
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_rise_set() -> Glib::PropertyProxy< bool > ;

/** Default value: <tt>false</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_rise_set() const -> Glib::PropertyProxy_ReadOnly< bool >;

  /** Default value: <tt>false</tt>
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_background_full_height_set() -> Glib::PropertyProxy< bool > ;

/** Default value: <tt>false</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_background_full_height_set() const -> Glib::PropertyProxy_ReadOnly< bool >;

  /** Default value: <tt>false</tt>
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_language_set() -> Glib::PropertyProxy< bool > ;

/** Default value: <tt>false</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_language_set() const -> Glib::PropertyProxy_ReadOnly< bool >;

  /** Default value: <tt>false</tt>
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_tabs_set() -> Glib::PropertyProxy< bool > ;

/** Default value: <tt>false</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_tabs_set() const -> Glib::PropertyProxy_ReadOnly< bool >;

  /** Default value: <tt>false</tt>
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_invisible_set() -> Glib::PropertyProxy< bool > ;

/** Default value: <tt>false</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_invisible_set() const -> Glib::PropertyProxy_ReadOnly< bool >;

  /** Default value: <tt>false</tt>
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_paragraph_background_set() -> Glib::PropertyProxy< bool > ;

/** Default value: <tt>false</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_paragraph_background_set() const -> Glib::PropertyProxy_ReadOnly< bool >;

  /** Whether font fallback is enabled.
   *
   * When set to <tt>true</tt>, other fonts will be substituted
   * where the current font is missing glyphs.
   *
   * Default value: <tt>true</tt>
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_fallback() -> Glib::PropertyProxy< bool > ;

/** Whether font fallback is enabled.
   *
   * When set to <tt>true</tt>, other fonts will be substituted
   * where the current font is missing glyphs.
   *
   * Default value: <tt>true</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_fallback() const -> Glib::PropertyProxy_ReadOnly< bool >;

  /** Default value: <tt>false</tt>
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_fallback_set() -> Glib::PropertyProxy< bool > ;

/** Default value: <tt>false</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_fallback_set() const -> Glib::PropertyProxy_ReadOnly< bool >;

  /** Extra spacing between graphemes, in Pango units.
   *
   * Default value: 0
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_letter_spacing() -> Glib::PropertyProxy< int > ;

/** Extra spacing between graphemes, in Pango units.
   *
   * Default value: 0
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_letter_spacing() const -> Glib::PropertyProxy_ReadOnly< int >;

  /** Default value: <tt>false</tt>
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_letter_spacing_set() -> Glib::PropertyProxy< bool > ;

/** Default value: <tt>false</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_letter_spacing_set() const -> Glib::PropertyProxy_ReadOnly< bool >;

  /**
   *
   * @newin{3,20}
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_font_features_set() -> Glib::PropertyProxy< bool > ;

/**
   *
   * @newin{3,20}
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_font_features_set() const -> Glib::PropertyProxy_ReadOnly< bool >;

  /** Default value: <tt>false</tt>
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_allow_breaks_set() -> Glib::PropertyProxy< bool > ;

/** Default value: <tt>false</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_allow_breaks_set() const -> Glib::PropertyProxy_ReadOnly< bool >;

  /** Default value: <tt>false</tt>
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_show_spaces_set() -> Glib::PropertyProxy< bool > ;

/** Default value: <tt>false</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_show_spaces_set() const -> Glib::PropertyProxy_ReadOnly< bool >;

  /** Default value: <tt>false</tt>
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_insert_hyphens_set() -> Glib::PropertyProxy< bool > ;

/** Default value: <tt>false</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_insert_hyphens_set() const -> Glib::PropertyProxy_ReadOnly< bool >;

  /** Default value: <tt>false</tt>
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_text_transform_set() -> Glib::PropertyProxy< bool > ;

/** Default value: <tt>false</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_text_transform_set() const -> Glib::PropertyProxy_ReadOnly< bool >;

  /** Default value: <tt>false</tt>
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_word_set() -> Glib::PropertyProxy< bool > ;

/** Default value: <tt>false</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_word_set() const -> Glib::PropertyProxy_ReadOnly< bool >;

  /** Default value: <tt>false</tt>
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_sentence_set() -> Glib::PropertyProxy< bool > ;

/** Default value: <tt>false</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_sentence_set() const -> Glib::PropertyProxy_ReadOnly< bool >;


public:

public:
  //C++ methods used to invoke GTK+ virtual functions:

protected:
  //GTK+ Virtual Functions (override these to change behaviour):

  //Default Signal Handlers::


};

} //namespace Gtk


namespace Glib
{
  /** A Glib::wrap() method for this object.
   *
   * @param object The C instance.
   * @param take_copy False if the result should take ownership of the C instance. True if it should take a new copy or ref.
   * @result A C++ instance that wraps this C instance.
   *
   * @relates Gtk::TextTag
   */
  GTKMM_API
  auto wrap(GtkTextTag* object, bool take_copy = false) -> Glib::RefPtr<Gtk::TextTag>;
}


#endif /* _GTKMM_TEXTTAG_H */

