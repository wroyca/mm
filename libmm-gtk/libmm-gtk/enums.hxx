
#ifndef _GTKMM_ENUMS_H
#define _GTKMM_ENUMS_H

#include <libmm-gtk/mm-gtkconfig.hxx>


#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

/*
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
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 */


#include <libmm-glib/value.hxx>
#include <gtk/gtk.h>


namespace Gtk
{


/** @addtogroup gtkmmEnums gtkmm Enums and Flags */

/**
 *  @var Align FILL
 * Stretch to fill all space if possible, center if
 * no meaningful way to stretch.
 *
 *  @var Align START
 * Snap to left or top side, leaving space on right or bottom.
 *
 *  @var Align END
 * Snap to right or bottom side, leaving space on left or top.
 *
 *  @var Align CENTER
 * Center natural width of widget inside the allocation.
 *
 *  @var Align BASELINE
 * Align the widget according to the baseline.
 * See Gtk::Widget.
 *
 *  @enum Align
 *
 * Controls how a widget deals with extra space in a single dimension.
 *
 * Alignment only matters if the widget receives a “too large” allocation,
 * for example if you packed the widget with the Gtk::Widget::property_hexpand()
 * property inside a Gtk::Box, then the widget might get extra space.
 * If you have for example a 16x16 icon inside a 32x32 space, the icon
 * could be scaled and stretched, it could be centered, or it could be
 * positioned to one side of the space.
 *
 * Note that in horizontal context Gtk::Align::START and Gtk::Align::END
 * are interpreted relative to text direction.
 *
 * Gtk::Align::BASELINE support is optional for containers and widgets, and
 * it is only supported for vertical alignment.  When it's not supported by
 * a child or a container it is treated as Gtk::Align::FILL.
 *
 * @ingroup gtkmmEnums
 */
enum class Align
{
  FILL,
  START,
  END,
  CENTER,
  BASELINE
};


} // namespace Gtk

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

template <>
class GTKMM_API Value<Gtk::Align> : public Glib::Value_Enum<Gtk::Align>
{
public:
  static auto value_type() -> GType G_GNUC_CONST;
};

} // namespace Glib
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

namespace Gtk
{

/**
 *  @var ArrowType UP
 * Represents an upward pointing arrow.
 *
 *  @var ArrowType DOWN
 * Represents a downward pointing arrow.
 *
 *  @var ArrowType LEFT
 * Represents a left pointing arrow.
 *
 *  @var ArrowType RIGHT
 * Represents a right pointing arrow.
 *
 *  @var ArrowType NONE
 * No arrow.
 *
 *  @enum ArrowType
 *
 * Used to indicate the direction in which an arrow should point.
 *
 * @ingroup gtkmmEnums
 */
enum class ArrowType
{
  UP,
  DOWN,
  LEFT,
  RIGHT,
  NONE
};


} // namespace Gtk

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

template <>
class GTKMM_API Value<Gtk::ArrowType> : public Glib::Value_Enum<Gtk::ArrowType>
{
public:
  static auto value_type() -> GType G_GNUC_CONST;
};

} // namespace Glib
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

namespace Gtk
{

/**
 *  @var DeleteType CHARS
 * Delete characters.
 *
 *  @var DeleteType WORD_ENDS
 * Delete only the portion of the word to the
 * left/right of cursor if we’re in the middle of a word.
 *
 *  @var DeleteType WORDS
 * Delete words.
 *
 *  @var DeleteType DISPLAY_LINES
 * Delete display-lines. Display-lines
 * refers to the visible lines, with respect to the current line
 * breaks. As opposed to paragraphs, which are defined by line
 * breaks in the input.
 *
 *  @var DeleteType DISPLAY_LINE_ENDS
 * Delete only the portion of the
 * display-line to the left/right of cursor.
 *
 *  @var DeleteType PARAGRAPH_ENDS
 * Delete to the end of the
 * paragraph. Like C-k in Emacs (or its reverse).
 *
 *  @var DeleteType PARAGRAPHS
 * Delete entire line. Like C-k in pico.
 *
 *  @var DeleteType WHITESPACE
 * Delete only whitespace. Like M-\\ in Emacs.
 *
 *  @enum DeleteType
 *
 * Passed to various keybinding signals for deleting text.
 *
 * @ingroup gtkmmEnums
 */
enum class DeleteType
{
  CHARS,
  WORD_ENDS,
  WORDS,
  DISPLAY_LINES,
  DISPLAY_LINE_ENDS,
  PARAGRAPH_ENDS,
  PARAGRAPHS,
  WHITESPACE
};


} // namespace Gtk

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

template <>
class GTKMM_API Value<Gtk::DeleteType> : public Glib::Value_Enum<Gtk::DeleteType>
{
public:
  static auto value_type() -> GType G_GNUC_CONST;
};

} // namespace Glib
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

namespace Gtk
{

/**
 *  @var DirectionType TAB_FORWARD
 * Move forward.
 *
 *  @var DirectionType TAB_BACKWARD
 * Move backward.
 *
 *  @var DirectionType UP
 * Move up.
 *
 *  @var DirectionType DOWN
 * Move down.
 *
 *  @var DirectionType LEFT
 * Move left.
 *
 *  @var DirectionType RIGHT
 * Move right.
 *
 *  @enum DirectionType
 *
 * Focus movement types.
 *
 * @ingroup gtkmmEnums
 */
enum class DirectionType
{
  TAB_FORWARD,
  TAB_BACKWARD,
  UP,
  DOWN,
  LEFT,
  RIGHT
};


} // namespace Gtk

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

template <>
class GTKMM_API Value<Gtk::DirectionType> : public Glib::Value_Enum<Gtk::DirectionType>
{
public:
  static auto value_type() -> GType G_GNUC_CONST;
};

} // namespace Glib
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

namespace Gtk
{

/**
 *  @var IconSize INHERIT
 * Keep the size of the parent element.
 *
 *  @var IconSize NORMAL
 * Size similar to text size.
 *
 *  @var IconSize LARGE
 * Large size, for example in an icon view.
 *
 *  @enum IconSize
 *
 * Built-in icon sizes.
 *
 * Icon sizes default to being inherited. Where they cannot be
 * inherited, text size is the default.
 *
 * All widgets which use `Gtk::IconSize` set the normal-icons or
 * large-icons style classes correspondingly, and let themes
 * determine the actual size to be used with the
 * `-gtk-icon-size` CSS property.
 *
 * @ingroup gtkmmEnums
 */
enum class IconSize
{
  INHERIT,
  NORMAL,
  LARGE
};


} // namespace Gtk

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

template <>
class GTKMM_API Value<Gtk::IconSize> : public Glib::Value_Enum<Gtk::IconSize>
{
public:
  static auto value_type() -> GType G_GNUC_CONST;
};

} // namespace Glib
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

namespace Gtk
{

/**
 *  @var TextDirection NONE
 * No direction.
 *
 *  @var TextDirection LTR
 * Left to right text direction.
 *
 *  @var TextDirection RTL
 * Right to left text direction.
 *
 *  @enum TextDirection
 *
 * Reading directions for text.
 *
 * @ingroup gtkmmEnums
 */
enum class TextDirection
{
  NONE,
  LTR,
  RTL
};


} // namespace Gtk

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

template <>
class GTKMM_API Value<Gtk::TextDirection> : public Glib::Value_Enum<Gtk::TextDirection>
{
public:
  static auto value_type() -> GType G_GNUC_CONST;
};

} // namespace Glib
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

namespace Gtk
{

/**
 *  @var Justification LEFT
 * The text is placed at the left edge of the label.
 *
 *  @var Justification RIGHT
 * The text is placed at the right edge of the label.
 *
 *  @var Justification CENTER
 * The text is placed in the center of the label.
 *
 *  @var Justification FILL
 * The text is placed is distributed across the label.
 *
 *  @enum Justification
 *
 * Used for justifying the text inside a Gtk::Label widget.
 *
 * @ingroup gtkmmEnums
 */
enum class Justification
{
  LEFT,
  RIGHT,
  CENTER,
  FILL
};


} // namespace Gtk

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

template <>
class GTKMM_API Value<Gtk::Justification> : public Glib::Value_Enum<Gtk::Justification>
{
public:
  static auto value_type() -> GType G_GNUC_CONST;
};

} // namespace Glib
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

namespace Gtk
{

/**
 *  @var MessageType INFO
 * Informational message.
 *
 *  @var MessageType WARNING
 * Non-fatal warning message.
 *
 *  @var MessageType QUESTION
 * Question requiring a choice.
 *
 *  @var MessageType ERROR
 * Fatal error message.
 *
 *  @var MessageType OTHER
 * None of the above.
 *
 *  @enum MessageType
 *
 * The type of message being displayed in a Gtk::MessageDialog.
 *
 * @ingroup gtkmmEnums
 */
enum class MessageType
{
  INFO,
  WARNING,
  QUESTION,
  ERROR,
  OTHER
};


} // namespace Gtk

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

template <>
class GTKMM_API Value<Gtk::MessageType> : public Glib::Value_Enum<Gtk::MessageType>
{
public:
  static auto value_type() -> GType G_GNUC_CONST;
};

} // namespace Glib
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

namespace Gtk
{

/**
 *  @var MovementStep LOGICAL_POSITIONS
 * Move forward or back by graphemes.
 *
 *  @var MovementStep VISUAL_POSITIONS
 * Move left or right by graphemes.
 *
 *  @var MovementStep WORDS
 * Move forward or back by words.
 *
 *  @var MovementStep DISPLAY_LINES
 * Move up or down lines (wrapped lines).
 *
 *  @var MovementStep DISPLAY_LINE_ENDS
 * Move to either end of a line.
 *
 *  @var MovementStep PARAGRAPHS
 * Move up or down paragraphs (newline-ended lines).
 *
 *  @var MovementStep PARAGRAPH_ENDS
 * Move to either end of a paragraph.
 *
 *  @var MovementStep PAGES
 * Move by pages.
 *
 *  @var MovementStep BUFFER_ENDS
 * Move to ends of the buffer.
 *
 *  @var MovementStep HORIZONTAL_PAGES
 * Move horizontally by pages.
 *
 *  @enum MovementStep
 *
 * Passed as argument to various keybinding signals for moving the
 * cursor position.
 *
 * @ingroup gtkmmEnums
 */
enum class MovementStep
{
  LOGICAL_POSITIONS,
  VISUAL_POSITIONS,
  WORDS,
  DISPLAY_LINES,
  DISPLAY_LINE_ENDS,
  PARAGRAPHS,
  PARAGRAPH_ENDS,
  PAGES,
  BUFFER_ENDS,
  HORIZONTAL_PAGES
};


} // namespace Gtk

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

template <>
class GTKMM_API Value<Gtk::MovementStep> : public Glib::Value_Enum<Gtk::MovementStep>
{
public:
  static auto value_type() -> GType G_GNUC_CONST;
};

} // namespace Glib
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

namespace Gtk
{

/**
 *  @var Orientation HORIZONTAL
 * The element is in horizontal orientation.
 *
 *  @var Orientation VERTICAL
 * The element is in vertical orientation.
 *
 *  @enum Orientation
 *
 * Represents the orientation of widgets and other objects.
 *
 * Typical examples are Gtk::Box or Gtk::GesturePan.
 *
 * @ingroup gtkmmEnums
 */
enum class Orientation
{
  HORIZONTAL,
  VERTICAL
};


} // namespace Gtk

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

template <>
class GTKMM_API Value<Gtk::Orientation> : public Glib::Value_Enum<Gtk::Orientation>
{
public:
  static auto value_type() -> GType G_GNUC_CONST;
};

} // namespace Glib
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

namespace Gtk
{

/**
 *  @var Overflow VISIBLE
 * No change is applied. Content is drawn at the specified
 * position.
 *
 *  @var Overflow HIDDEN
 * Content is clipped to the bounds of the area. Content
 * outside the area is not drawn and cannot be interacted with.
 *
 *  @enum Overflow
 *
 * Defines how content overflowing a given area should be handled.
 *
 * This is used in Gtk::Widget::set_overflow(). The
 * Gtk::Widget::property_overflow() property is modeled after the
 * CSS overflow property, but implements it only partially.
 *
 * @ingroup gtkmmEnums
 */
enum class Overflow
{
  VISIBLE,
  HIDDEN
};


} // namespace Gtk

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

template <>
class GTKMM_API Value<Gtk::Overflow> : public Glib::Value_Enum<Gtk::Overflow>
{
public:
  static auto value_type() -> GType G_GNUC_CONST;
};

} // namespace Glib
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

namespace Gtk
{

/**
 *  @var CornerType TOP_LEFT
 * Place the scrollbars on the right and bottom of the
 * widget (default behaviour).
 *
 *  @var CornerType BOTTOM_LEFT
 * Place the scrollbars on the top and right of the
 * widget.
 *
 *  @var CornerType TOP_RIGHT
 * Place the scrollbars on the left and bottom of the
 * widget.
 *
 *  @var CornerType BOTTOM_RIGHT
 * Place the scrollbars on the top and left of the
 * widget.
 *
 *  @enum CornerType
 *
 * Specifies which corner a child widget should be placed in when packed into
 * a `GtkScrolledWindow.`
 *
 * This is effectively the opposite of where the scroll bars are placed.
 *
 * @ingroup gtkmmEnums
 */
enum class CornerType
{
  TOP_LEFT,
  BOTTOM_LEFT,
  TOP_RIGHT,
  BOTTOM_RIGHT
};


} // namespace Gtk

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

template <>
class GTKMM_API Value<Gtk::CornerType> : public Glib::Value_Enum<Gtk::CornerType>
{
public:
  static auto value_type() -> GType G_GNUC_CONST;
};

} // namespace Glib
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

namespace Gtk
{

/**
 *  @var PackType START
 * The child is packed into the start of the widget.
 *
 *  @var PackType END
 * The child is packed into the end of the widget.
 *
 *  @enum PackType
 *
 * Represents the packing location of a children in its parent.
 *
 * See Gtk::WindowControls for example.
 *
 * @ingroup gtkmmEnums
 */
enum class PackType
{
  START,
  END
};


} // namespace Gtk

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

template <>
class GTKMM_API Value<Gtk::PackType> : public Glib::Value_Enum<Gtk::PackType>
{
public:
  static auto value_type() -> GType G_GNUC_CONST;
};

} // namespace Glib
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

namespace Gtk
{

/**
 *  @var PickFlags DEFAULT
 * The default behavior, include widgets that are receiving events.
 *
 *  @var PickFlags INSENSITIVE
 * Include widgets that are insensitive.
 *
 *  @var PickFlags NON_TARGETABLE
 * Include widgets that are marked as non-targetable. See Gtk::Widget::property_can_target().
 *
 *  @enum PickFlags
 *
 * Flags that influence the behavior of Gtk::Widget::pick().
 *
 * @ingroup gtkmmEnums
 * @par Bitwise operators:
 * <tt>PickFlags operator|(PickFlags, PickFlags)</tt><br>
 * <tt>PickFlags operator&(PickFlags, PickFlags)</tt><br>
 * <tt>PickFlags operator^(PickFlags, PickFlags)</tt><br>
 * <tt>PickFlags operator~(PickFlags)</tt><br>
 * <tt>PickFlags& operator|=(PickFlags&, PickFlags)</tt><br>
 * <tt>PickFlags& operator&=(PickFlags&, PickFlags)</tt><br>
 * <tt>PickFlags& operator^=(PickFlags&, PickFlags)</tt><br>
 */
enum class PickFlags
{
  DEFAULT = 0x0,
  INSENSITIVE = 1 << 0,
  NON_TARGETABLE = 1 << 1
};

/** @ingroup gtkmmEnums */
inline auto operator|(PickFlags lhs, PickFlags rhs) -> PickFlags
  { return static_cast<PickFlags>(static_cast<unsigned>(lhs) | static_cast<unsigned>(rhs)); }

/** @ingroup gtkmmEnums */
inline auto operator&(PickFlags lhs, PickFlags rhs) -> PickFlags
  { return static_cast<PickFlags>(static_cast<unsigned>(lhs) & static_cast<unsigned>(rhs)); }

/** @ingroup gtkmmEnums */
inline auto operator^(PickFlags lhs, PickFlags rhs) -> PickFlags
  { return static_cast<PickFlags>(static_cast<unsigned>(lhs) ^ static_cast<unsigned>(rhs)); }

/** @ingroup gtkmmEnums */
inline auto operator~(PickFlags flags) -> PickFlags
  { return static_cast<PickFlags>(~static_cast<unsigned>(flags)); }

/** @ingroup gtkmmEnums */
inline auto operator|=(PickFlags& lhs, PickFlags rhs) -> PickFlags&
  { return (lhs = static_cast<PickFlags>(static_cast<unsigned>(lhs) | static_cast<unsigned>(rhs))); }

/** @ingroup gtkmmEnums */
inline auto operator&=(PickFlags& lhs, PickFlags rhs) -> PickFlags&
  { return (lhs = static_cast<PickFlags>(static_cast<unsigned>(lhs) & static_cast<unsigned>(rhs))); }

/** @ingroup gtkmmEnums */
inline auto operator^=(PickFlags& lhs, PickFlags rhs) -> PickFlags&
  { return (lhs = static_cast<PickFlags>(static_cast<unsigned>(lhs) ^ static_cast<unsigned>(rhs))); }


} // namespace Gtk

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

template <>
class GTKMM_API Value<Gtk::PickFlags> : public Glib::Value_Flags<Gtk::PickFlags>
{
public:
  static auto value_type() -> GType G_GNUC_CONST;
};

} // namespace Glib
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

namespace Gtk
{

/**
 *  @var PolicyType ALWAYS
 * The scrollbar is always visible. The view size is
 * independent of the content.
 *
 *  @var PolicyType AUTOMATIC
 * The scrollbar will appear and disappear as necessary.
 * For example, when all of a `Gtk::TreeView` can not be seen.
 *
 *  @var PolicyType NEVER
 * The scrollbar should never appear. In this mode the
 * content determines the size.
 *
 *  @var PolicyType EXTERNAL
 * Don't show a scrollbar, but don't force the
 * size to follow the content. This can be used e.g. to make multiple
 * scrolled windows share a scrollbar.
 *
 *  @enum PolicyType
 *
 * Determines how the size should be computed to achieve the one of the
 * visibility mode for the scrollbars.
 *
 * @ingroup gtkmmEnums
 */
enum class PolicyType
{
  ALWAYS,
  AUTOMATIC,
  NEVER,
  EXTERNAL
};


} // namespace Gtk

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

template <>
class GTKMM_API Value<Gtk::PolicyType> : public Glib::Value_Enum<Gtk::PolicyType>
{
public:
  static auto value_type() -> GType G_GNUC_CONST;
};

} // namespace Glib
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

namespace Gtk
{

/**
 *  @var PositionType LEFT
 * The feature is at the left edge.
 *
 *  @var PositionType RIGHT
 * The feature is at the right edge.
 *
 *  @var PositionType TOP
 * The feature is at the top edge.
 *
 *  @var PositionType BOTTOM
 * The feature is at the bottom edge.
 *
 *  @enum PositionType
 *
 * Describes which edge of a widget a certain feature is positioned at.
 *
 * For examples, see the tabs of a Gtk::Notebook, or the label
 * of a Gtk::Scale.
 *
 * @ingroup gtkmmEnums
 */
enum class PositionType
{
  LEFT,
  RIGHT,
  TOP,
  BOTTOM
};


} // namespace Gtk

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

template <>
class GTKMM_API Value<Gtk::PositionType> : public Glib::Value_Enum<Gtk::PositionType>
{
public:
  static auto value_type() -> GType G_GNUC_CONST;
};

} // namespace Glib
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

namespace Gtk
{

/**
 *  @var RevealerTransitionType NONE
 * No transition.
 *
 *  @var RevealerTransitionType CROSSFADE
 * Fade in.
 *
 *  @var RevealerTransitionType SLIDE_RIGHT
 * Slide in from the left.
 *
 *  @var RevealerTransitionType SLIDE_LEFT
 * Slide in from the right.
 *
 *  @var RevealerTransitionType SLIDE_UP
 * Slide in from the bottom.
 *
 *  @var RevealerTransitionType SLIDE_DOWN
 * Slide in from the top.
 *
 *  @var RevealerTransitionType SWING_RIGHT
 * Floop in from the left.
 *
 *  @var RevealerTransitionType SWING_LEFT
 * Floop in from the right.
 *
 *  @var RevealerTransitionType SWING_UP
 * Floop in from the bottom.
 *
 *  @var RevealerTransitionType SWING_DOWN
 * Floop in from the top.
 *
 *  @enum RevealerTransitionType
 *
 * These enumeration values describe the possible transitions
 * when the child of a `Gtk::Revealer` widget is shown or hidden.
 *
 * @ingroup gtkmmEnums
 */
enum class RevealerTransitionType
{
  NONE,
  CROSSFADE,
  SLIDE_RIGHT,
  SLIDE_LEFT,
  SLIDE_UP,
  SLIDE_DOWN,
  SWING_RIGHT,
  SWING_LEFT,
  SWING_UP,
  SWING_DOWN
};


} // namespace Gtk

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

template <>
class GTKMM_API Value<Gtk::RevealerTransitionType> : public Glib::Value_Enum<Gtk::RevealerTransitionType>
{
public:
  static auto value_type() -> GType G_GNUC_CONST;
};

} // namespace Glib
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

namespace Gtk
{

/**
 *  @var ScrollType NONE
 * No scrolling.
 *
 *  @var ScrollType JUMP
 * Jump to new location.
 *
 *  @var ScrollType STEP_BACKWARD
 * Step backward.
 *
 *  @var ScrollType STEP_FORWARD
 * Step forward.
 *
 *  @var ScrollType PAGE_BACKWARD
 * Page backward.
 *
 *  @var ScrollType PAGE_FORWARD
 * Page forward.
 *
 *  @var ScrollType STEP_UP
 * Step up.
 *
 *  @var ScrollType STEP_DOWN
 * Step down.
 *
 *  @var ScrollType PAGE_UP
 * Page up.
 *
 *  @var ScrollType PAGE_DOWN
 * Page down.
 *
 *  @var ScrollType STEP_LEFT
 * Step to the left.
 *
 *  @var ScrollType STEP_RIGHT
 * Step to the right.
 *
 *  @var ScrollType PAGE_LEFT
 * Page to the left.
 *
 *  @var ScrollType PAGE_RIGHT
 * Page to the right.
 *
 *  @var ScrollType START
 * Scroll to start.
 *
 *  @var ScrollType END
 * Scroll to end.
 *
 *  @enum ScrollType
 *
 * Scrolling types.
 *
 * @ingroup gtkmmEnums
 */
enum class ScrollType
{
  NONE,
  JUMP,
  STEP_BACKWARD,
  STEP_FORWARD,
  PAGE_BACKWARD,
  PAGE_FORWARD,
  STEP_UP,
  STEP_DOWN,
  PAGE_UP,
  PAGE_DOWN,
  STEP_LEFT,
  STEP_RIGHT,
  PAGE_LEFT,
  PAGE_RIGHT,
  START,
  END
};


} // namespace Gtk

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

template <>
class GTKMM_API Value<Gtk::ScrollType> : public Glib::Value_Enum<Gtk::ScrollType>
{
public:
  static auto value_type() -> GType G_GNUC_CONST;
};

} // namespace Glib
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

namespace Gtk
{

/**
 *  @var SelectionMode NONE
 * No selection is possible.
 *
 *  @var SelectionMode SINGLE
 * Zero or one element may be selected.
 *
 *  @var SelectionMode BROWSE
 * Exactly one element is selected.
 * In some circumstances, such as initially or during a search
 * operation, it’s possible for no element to be selected with
 * Gtk::SelectionMode::BROWSE. What is really enforced is that the user
 * can’t deselect a currently selected element except by selecting
 * another element.
 *
 *  @var SelectionMode MULTIPLE
 * Any number of elements may be selected.
 * The Ctrl key may be used to enlarge the selection, and Shift
 * key to select between the focus and the child pointed to.
 * Some widgets may also allow Click-drag to select a range of elements.
 *
 *  @enum SelectionMode
 *
 * Used to control what selections users are allowed to make.
 *
 * @ingroup gtkmmEnums
 */
enum class SelectionMode
{
  NONE,
  SINGLE,
  BROWSE,
  MULTIPLE
};


} // namespace Gtk

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

template <>
class GTKMM_API Value<Gtk::SelectionMode> : public Glib::Value_Enum<Gtk::SelectionMode>
{
public:
  static auto value_type() -> GType G_GNUC_CONST;
};

} // namespace Glib
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

namespace Gtk
{

/**
 *  @var StackTransitionType NONE
 * No transition.
 *
 *  @var StackTransitionType CROSSFADE
 * A cross-fade.
 *
 *  @var StackTransitionType SLIDE_RIGHT
 * Slide from left to right.
 *
 *  @var StackTransitionType SLIDE_LEFT
 * Slide from right to left.
 *
 *  @var StackTransitionType SLIDE_UP
 * Slide from bottom up.
 *
 *  @var StackTransitionType SLIDE_DOWN
 * Slide from top down.
 *
 *  @var StackTransitionType SLIDE_LEFT_RIGHT
 * Slide from left or right according to the children order.
 *
 *  @var StackTransitionType SLIDE_UP_DOWN
 * Slide from top down or bottom up according to the order.
 *
 *  @var StackTransitionType OVER_UP
 * Cover the old page by sliding up.
 *
 *  @var StackTransitionType OVER_DOWN
 * Cover the old page by sliding down.
 *
 *  @var StackTransitionType OVER_LEFT
 * Cover the old page by sliding to the left.
 *
 *  @var StackTransitionType OVER_RIGHT
 * Cover the old page by sliding to the right.
 *
 *  @var StackTransitionType UNDER_UP
 * Uncover the new page by sliding up.
 *
 *  @var StackTransitionType UNDER_DOWN
 * Uncover the new page by sliding down.
 *
 *  @var StackTransitionType UNDER_LEFT
 * Uncover the new page by sliding to the left.
 *
 *  @var StackTransitionType UNDER_RIGHT
 * Uncover the new page by sliding to the right.
 *
 *  @var StackTransitionType OVER_UP_DOWN
 * Cover the old page sliding up or uncover the new page sliding down, according to order.
 *
 *  @var StackTransitionType OVER_DOWN_UP
 * Cover the old page sliding down or uncover the new page sliding up, according to order.
 *
 *  @var StackTransitionType OVER_LEFT_RIGHT
 * Cover the old page sliding left or uncover the new page sliding right, according to order.
 *
 *  @var StackTransitionType OVER_RIGHT_LEFT
 * Cover the old page sliding right or uncover the new page sliding left, according to order.
 *
 *  @var StackTransitionType ROTATE_LEFT
 * Pretend the pages are sides of a cube and rotate that cube to the left.
 *
 *  @var StackTransitionType ROTATE_RIGHT
 * Pretend the pages are sides of a cube and rotate that cube to the right.
 *
 *  @var StackTransitionType ROTATE_LEFT_RIGHT
 * Pretend the pages are sides of a cube and rotate that cube to the left or right according to the children order.
 *
 *  @enum StackTransitionType
 *
 * Possible transitions between pages in a `Gtk::Stack` widget.
 *
 * New values may be added to this enumeration over time.
 *
 * @ingroup gtkmmEnums
 */
enum class StackTransitionType
{
  NONE,
  CROSSFADE,
  SLIDE_RIGHT,
  SLIDE_LEFT,
  SLIDE_UP,
  SLIDE_DOWN,
  SLIDE_LEFT_RIGHT,
  SLIDE_UP_DOWN,
  OVER_UP,
  OVER_DOWN,
  OVER_LEFT,
  OVER_RIGHT,
  UNDER_UP,
  UNDER_DOWN,
  UNDER_LEFT,
  UNDER_RIGHT,
  OVER_UP_DOWN,
  OVER_DOWN_UP,
  OVER_LEFT_RIGHT,
  OVER_RIGHT_LEFT,
  ROTATE_LEFT,
  ROTATE_RIGHT,
  ROTATE_LEFT_RIGHT
};


} // namespace Gtk

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

template <>
class GTKMM_API Value<Gtk::StackTransitionType> : public Glib::Value_Enum<Gtk::StackTransitionType>
{
public:
  static auto value_type() -> GType G_GNUC_CONST;
};

} // namespace Glib
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

namespace Gtk
{

/**
 *  @var WrapMode NONE
 * Do not wrap lines; just make the text area wider.
 *
 *  @var WrapMode CHAR
 * Wrap text, breaking lines anywhere the cursor can
 * appear (between characters, usually - if you want to be technical,
 * between graphemes, see pango_get_log_attrs()).
 *
 *  @var WrapMode WORD
 * Wrap text, breaking lines in between words.
 *
 *  @var WrapMode WORD_CHAR
 * Wrap text, breaking lines in between words, or if
 * that is not enough, also between graphemes.
 *
 *  @enum WrapMode
 *
 * Describes a type of line wrapping.
 *
 * @ingroup gtkmmEnums
 */
enum class WrapMode
{
  NONE,
  CHAR,
  WORD,
  WORD_CHAR
};


} // namespace Gtk

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

template <>
class GTKMM_API Value<Gtk::WrapMode> : public Glib::Value_Enum<Gtk::WrapMode>
{
public:
  static auto value_type() -> GType G_GNUC_CONST;
};

} // namespace Glib
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

namespace Gtk
{

/**
 *  @var NaturalWrapMode INHERIT
 * Inherit the minimum size request.
 * In particular, this should be used with Pango::WrapMode::CHAR.
 *
 *  @var NaturalWrapMode NONE
 * Try not to wrap the text. This mode is the
 * closest to GTK3's behavior but can lead to a wide label leaving
 * lots of empty space below the text.
 *
 *  @var NaturalWrapMode WORD
 * Attempt to wrap at word boundaries. This
 * is useful in particular when using Pango::WrapMode::WORD_CHAR as the
 * wrap mode.
 *
 *  @enum NaturalWrapMode
 *
 * Options for selecting a different wrap mode for natural size
 * requests.
 *
 * See for example the Gtk::Label::property_natural_wrap_mode() property.
 *
 * @newin{4,6}
 *
 * @ingroup gtkmmEnums
 */
enum class NaturalWrapMode
{
  INHERIT,
  NONE,
  WORD
};


} // namespace Gtk

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

template <>
class GTKMM_API Value<Gtk::NaturalWrapMode> : public Glib::Value_Enum<Gtk::NaturalWrapMode>
{
public:
  static auto value_type() -> GType G_GNUC_CONST;
};

} // namespace Glib
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

namespace Gtk
{

/**
 *  @var SortType ASCENDING
 * Sorting is in ascending order.
 *
 *  @var SortType DESCENDING
 * Sorting is in descending order.
 *
 *  @enum SortType
 *
 * Determines the direction of a sort.
 *
 * @ingroup gtkmmEnums
 */
enum class SortType
{
  ASCENDING,
  DESCENDING
};


} // namespace Gtk

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

template <>
class GTKMM_API Value<Gtk::SortType> : public Glib::Value_Enum<Gtk::SortType>
{
public:
  static auto value_type() -> GType G_GNUC_CONST;
};

} // namespace Glib
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

namespace Gtk
{

/**
 *  @var Ordering SMALLER
 * The first value is smaller than the second.
 *
 *  @var Ordering EQUAL
 * The two values are equal.
 *
 *  @var Ordering LARGER
 * The first value is larger than the second.
 *
 *  @enum Ordering
 *
 * Describes the way two values can be compared.
 *
 * These values can be used with a [callback@GLib.CompareFunc]. However,
 * a `CompareFunc` is allowed to return any integer values.
 * For converting such a value to a `Gtk::Ordering` value, use
 * gtk_ordering_from_cmpfunc().
 *
 * @ingroup gtkmmEnums
 */
enum class Ordering
{
  SMALLER = -1,
  EQUAL,
  LARGER
};


} // namespace Gtk

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

template <>
class GTKMM_API Value<Gtk::Ordering> : public Glib::Value_Enum<Gtk::Ordering>
{
public:
  static auto value_type() -> GType G_GNUC_CONST;
};

} // namespace Glib
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

namespace Gtk
{

/**
 *  @var PageOrientation PORTRAIT
 * Portrait mode.
 *
 *  @var PageOrientation LANDSCAPE
 * Landscape mode.
 *
 *  @var PageOrientation REVERSE_PORTRAIT
 * Reverse portrait mode.
 *
 *  @var PageOrientation REVERSE_LANDSCAPE
 * Reverse landscape mode.
 *
 *  @enum PageOrientation
 *
 * See also Gtk::PrintSettings::set_orientation().
 *
 * @ingroup gtkmmEnums
 */
enum class PageOrientation
{
  PORTRAIT,
  LANDSCAPE,
  REVERSE_PORTRAIT,
  REVERSE_LANDSCAPE
};


} // namespace Gtk

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

template <>
class GTKMM_API Value<Gtk::PageOrientation> : public Glib::Value_Enum<Gtk::PageOrientation>
{
public:
  static auto value_type() -> GType G_GNUC_CONST;
};

} // namespace Glib
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

namespace Gtk
{

/**
 *  @var SensitivityType AUTO
 * The control is made insensitive if no
 * action can be triggered.
 *
 *  @var SensitivityType ON
 * The control is always sensitive.
 *
 *  @var SensitivityType OFF
 * The control is always insensitive.
 *
 *  @enum SensitivityType
 *
 * Determines how GTK handles the sensitivity of various controls,
 * such as combo box buttons.
 *
 * @ingroup gtkmmEnums
 */
enum class SensitivityType
{
  AUTO,
  ON,
  OFF
};


} // namespace Gtk

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

template <>
class GTKMM_API Value<Gtk::SensitivityType> : public Glib::Value_Enum<Gtk::SensitivityType>
{
public:
  static auto value_type() -> GType G_GNUC_CONST;
};

} // namespace Glib
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

namespace Gtk
{

/**
 *  @var SizeRequestMode HEIGHT_FOR_WIDTH
 * Prefer height-for-width geometry management.
 *
 *  @var SizeRequestMode WIDTH_FOR_HEIGHT
 * Prefer width-for-height geometry management.
 *
 *  @var SizeRequestMode CONSTANT_SIZE
 * Don’t trade height-for-width or width-for-height.
 *
 *  @enum SizeRequestMode
 *
 * Specifies a preference for height-for-width or
 * width-for-height geometry management.
 *
 * @ingroup gtkmmEnums
 */
enum class SizeRequestMode
{
  HEIGHT_FOR_WIDTH,
  WIDTH_FOR_HEIGHT,
  CONSTANT_SIZE
};


} // namespace Gtk

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

template <>
class GTKMM_API Value<Gtk::SizeRequestMode> : public Glib::Value_Enum<Gtk::SizeRequestMode>
{
public:
  static auto value_type() -> GType G_GNUC_CONST;
};

} // namespace Glib
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

namespace Gtk
{

/**
 *  @var StateFlags NORMAL
 * State during normal operation.
 *
 *  @var StateFlags ACTIVE
 * Widget is active.
 *
 *  @var StateFlags PRELIGHT
 * Widget has a mouse pointer over it.
 *
 *  @var StateFlags SELECTED
 * Widget is selected.
 *
 *  @var StateFlags INSENSITIVE
 * Widget is insensitive.
 *
 *  @var StateFlags INCONSISTENT
 * Widget is inconsistent.
 *
 *  @var StateFlags FOCUSED
 * Widget has the keyboard focus.
 *
 *  @var StateFlags BACKDROP
 * Widget is in a background toplevel window.
 *
 *  @var StateFlags DIR_LTR
 * Widget is in left-to-right text direction.
 *
 *  @var StateFlags DIR_RTL
 * Widget is in right-to-left text direction.
 *
 *  @var StateFlags LINK
 * Widget is a link.
 *
 *  @var StateFlags VISITED
 * The location the widget points to has already been visited.
 *
 *  @var StateFlags CHECKED
 * Widget is checked.
 *
 *  @var StateFlags DROP_ACTIVE
 * Widget is highlighted as a drop target for DND.
 *
 *  @var StateFlags FOCUS_VISIBLE
 * Widget has the visible focus.
 *
 *  @var StateFlags FOCUS_WITHIN
 * Widget contains the keyboard focus.
 *
 *  @enum StateFlags
 *
 * Describes a widget state.
 *
 * Widget states are used to match the widget against CSS pseudo-classes.
 * Note that GTK extends the regular CSS classes and sometimes uses
 * different names.
 *
 * @ingroup gtkmmEnums
 * @par Bitwise operators:
 * <tt>StateFlags operator|(StateFlags, StateFlags)</tt><br>
 * <tt>StateFlags operator&(StateFlags, StateFlags)</tt><br>
 * <tt>StateFlags operator^(StateFlags, StateFlags)</tt><br>
 * <tt>StateFlags operator~(StateFlags)</tt><br>
 * <tt>StateFlags& operator|=(StateFlags&, StateFlags)</tt><br>
 * <tt>StateFlags& operator&=(StateFlags&, StateFlags)</tt><br>
 * <tt>StateFlags& operator^=(StateFlags&, StateFlags)</tt><br>
 */
enum class StateFlags
{
  NORMAL = 0x0,
  ACTIVE = 1 << 0,
  PRELIGHT = 1 << 1,
  SELECTED = 1 << 2,
  INSENSITIVE = 1 << 3,
  INCONSISTENT = 1 << 4,
  FOCUSED = 1 << 5,
  BACKDROP = 1 << 6,
  DIR_LTR = 1 << 7,
  DIR_RTL = 1 << 8,
  LINK = 1 << 9,
  VISITED = 1 << 10,
  CHECKED = 1 << 11,
  DROP_ACTIVE = 1 << 12,
  FOCUS_VISIBLE = 1 << 13,
  FOCUS_WITHIN = 1 << 14
};

/** @ingroup gtkmmEnums */
inline auto operator|(StateFlags lhs, StateFlags rhs) -> StateFlags
  { return static_cast<StateFlags>(static_cast<unsigned>(lhs) | static_cast<unsigned>(rhs)); }

/** @ingroup gtkmmEnums */
inline auto operator&(StateFlags lhs, StateFlags rhs) -> StateFlags
  { return static_cast<StateFlags>(static_cast<unsigned>(lhs) & static_cast<unsigned>(rhs)); }

/** @ingroup gtkmmEnums */
inline auto operator^(StateFlags lhs, StateFlags rhs) -> StateFlags
  { return static_cast<StateFlags>(static_cast<unsigned>(lhs) ^ static_cast<unsigned>(rhs)); }

/** @ingroup gtkmmEnums */
inline auto operator~(StateFlags flags) -> StateFlags
  { return static_cast<StateFlags>(~static_cast<unsigned>(flags)); }

/** @ingroup gtkmmEnums */
inline auto operator|=(StateFlags& lhs, StateFlags rhs) -> StateFlags&
  { return (lhs = static_cast<StateFlags>(static_cast<unsigned>(lhs) | static_cast<unsigned>(rhs))); }

/** @ingroup gtkmmEnums */
inline auto operator&=(StateFlags& lhs, StateFlags rhs) -> StateFlags&
  { return (lhs = static_cast<StateFlags>(static_cast<unsigned>(lhs) & static_cast<unsigned>(rhs))); }

/** @ingroup gtkmmEnums */
inline auto operator^=(StateFlags& lhs, StateFlags rhs) -> StateFlags&
  { return (lhs = static_cast<StateFlags>(static_cast<unsigned>(lhs) ^ static_cast<unsigned>(rhs))); }


} // namespace Gtk

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

template <>
class GTKMM_API Value<Gtk::StateFlags> : public Glib::Value_Flags<Gtk::StateFlags>
{
public:
  static auto value_type() -> GType G_GNUC_CONST;
};

} // namespace Glib
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

namespace Gtk
{

/**
 *  @var InputPurpose FREE_FORM
 * Allow any character.
 *
 *  @var InputPurpose ALPHA
 * Allow only alphabetic characters.
 *
 *  @var InputPurpose DIGITS
 * Allow only digits.
 *
 *  @var InputPurpose NUMBER
 * Edited field expects numbers.
 *
 *  @var InputPurpose PHONE
 * Edited field expects phone number.
 *
 *  @var InputPurpose URL
 * Edited field expects URL.
 *
 *  @var InputPurpose EMAIL
 * Edited field expects email address.
 *
 *  @var InputPurpose NAME
 * Edited field expects the name of a person.
 *
 *  @var InputPurpose PASSWORD
 * Like Gtk::InputPurpose::FREE_FORM, but characters are hidden.
 *
 *  @var InputPurpose PIN
 * Like Gtk::InputPurpose::DIGITS, but characters are hidden.
 *
 *  @var InputPurpose TERMINAL
 * Allow any character, in addition to control codes.
 *
 *  @enum InputPurpose
 *
 * Describes primary purpose of the input widget.
 *
 * This information is useful for on-screen keyboards and similar input
 * methods to decide which keys should be presented to the user.
 *
 * Note that the purpose is not meant to impose a totally strict rule
 * about allowed characters, and does not replace input validation.
 * It is fine for an on-screen keyboard to let the user override the
 * character set restriction that is expressed by the purpose. The
 * application is expected to validate the entry contents, even if
 * it specified a purpose.
 *
 * The difference between Gtk::InputPurpose::DIGITS and
 * Gtk::InputPurpose::NUMBER is that the former accepts only digits
 * while the latter also some punctuation (like commas or points, plus,
 * minus) and “e” or “E” as in 3.14E+000.
 *
 * This enumeration may be extended in the future; input methods should
 * interpret unknown values as “free form”.
 *
 * @ingroup gtkmmEnums
 */
enum class InputPurpose
{
  FREE_FORM,
  ALPHA,
  DIGITS,
  NUMBER,
  PHONE,
  URL,
  EMAIL,
  NAME,
  PASSWORD,
  PIN,
  TERMINAL
};


} // namespace Gtk

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

template <>
class GTKMM_API Value<Gtk::InputPurpose> : public Glib::Value_Enum<Gtk::InputPurpose>
{
public:
  static auto value_type() -> GType G_GNUC_CONST;
};

} // namespace Glib
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

namespace Gtk
{

/**
 *  @var InputHints NONE
 * No special behaviour suggested.
 *
 *  @var InputHints SPELLCHECK
 * Suggest checking for typos.
 *
 *  @var InputHints NO_SPELLCHECK
 * Suggest not checking for typos.
 *
 *  @var InputHints WORD_COMPLETION
 * Suggest word completion.
 *
 *  @var InputHints LOWERCASE
 * Suggest to convert all text to lowercase.
 *
 *  @var InputHints UPPERCASE_CHARS
 * Suggest to capitalize all text.
 *
 *  @var InputHints UPPERCASE_WORDS
 * Suggest to capitalize the first
 * character of each word.
 *
 *  @var InputHints UPPERCASE_SENTENCES
 * Suggest to capitalize the
 * first word of each sentence.
 *
 *  @var InputHints INHIBIT_OSK
 * Suggest to not show an onscreen keyboard
 * (e.g for a calculator that already has all the keys).
 *
 *  @var InputHints VERTICAL_WRITING
 * The text is vertical.
 *
 *  @var InputHints EMOJI
 * Suggest offering Emoji support.
 *
 *  @var InputHints NO_EMOJI
 * Suggest not offering Emoji support.
 *
 *  @var InputHints PRIVATE
 * Request that the input method should not
 * update personalized data (like typing history).
 *
 *  @enum InputHints
 *
 * Describes hints that might be taken into account by input methods
 * or applications.
 *
 * Note that input methods may already tailor their behaviour according
 * to the Gtk::InputPurpose of the entry.
 *
 * Some common sense is expected when using these flags - mixing
 * Gtk::InputHints::LOWERCASE with any of the uppercase hints makes no sense.
 *
 * This enumeration may be extended in the future; input methods should
 * ignore unknown values.
 *
 * @ingroup gtkmmEnums
 * @par Bitwise operators:
 * <tt>InputHints operator|(InputHints, InputHints)</tt><br>
 * <tt>InputHints operator&(InputHints, InputHints)</tt><br>
 * <tt>InputHints operator^(InputHints, InputHints)</tt><br>
 * <tt>InputHints operator~(InputHints)</tt><br>
 * <tt>InputHints& operator|=(InputHints&, InputHints)</tt><br>
 * <tt>InputHints& operator&=(InputHints&, InputHints)</tt><br>
 * <tt>InputHints& operator^=(InputHints&, InputHints)</tt><br>
 */
enum class InputHints
{
  NONE = 0x0,
  SPELLCHECK = 1 << 0,
  NO_SPELLCHECK = 1 << 1,
  WORD_COMPLETION = 1 << 2,
  LOWERCASE = 1 << 3,
  UPPERCASE_CHARS = 1 << 4,
  UPPERCASE_WORDS = 1 << 5,
  UPPERCASE_SENTENCES = 1 << 6,
  INHIBIT_OSK = 1 << 7,
  VERTICAL_WRITING = 1 << 8,
  EMOJI = 1 << 9,
  NO_EMOJI = 1 << 10,
  PRIVATE = 1 << 11
};

/** @ingroup gtkmmEnums */
inline auto operator|(InputHints lhs, InputHints rhs) -> InputHints
  { return static_cast<InputHints>(static_cast<unsigned>(lhs) | static_cast<unsigned>(rhs)); }

/** @ingroup gtkmmEnums */
inline auto operator&(InputHints lhs, InputHints rhs) -> InputHints
  { return static_cast<InputHints>(static_cast<unsigned>(lhs) & static_cast<unsigned>(rhs)); }

/** @ingroup gtkmmEnums */
inline auto operator^(InputHints lhs, InputHints rhs) -> InputHints
  { return static_cast<InputHints>(static_cast<unsigned>(lhs) ^ static_cast<unsigned>(rhs)); }

/** @ingroup gtkmmEnums */
inline auto operator~(InputHints flags) -> InputHints
  { return static_cast<InputHints>(~static_cast<unsigned>(flags)); }

/** @ingroup gtkmmEnums */
inline auto operator|=(InputHints& lhs, InputHints rhs) -> InputHints&
  { return (lhs = static_cast<InputHints>(static_cast<unsigned>(lhs) | static_cast<unsigned>(rhs))); }

/** @ingroup gtkmmEnums */
inline auto operator&=(InputHints& lhs, InputHints rhs) -> InputHints&
  { return (lhs = static_cast<InputHints>(static_cast<unsigned>(lhs) & static_cast<unsigned>(rhs))); }

/** @ingroup gtkmmEnums */
inline auto operator^=(InputHints& lhs, InputHints rhs) -> InputHints&
  { return (lhs = static_cast<InputHints>(static_cast<unsigned>(lhs) ^ static_cast<unsigned>(rhs))); }


} // namespace Gtk

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

template <>
class GTKMM_API Value<Gtk::InputHints> : public Glib::Value_Flags<Gtk::InputHints>
{
public:
  static auto value_type() -> GType G_GNUC_CONST;
};

} // namespace Glib
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

namespace Gtk
{

/**
 *  @var BaselinePosition TOP
 * Align the baseline at the top.
 *
 *  @var BaselinePosition CENTER
 * Center the baseline.
 *
 *  @var BaselinePosition BOTTOM
 * Align the baseline at the bottom.
 *
 *  @enum BaselinePosition
 *
 * Baseline position in a row of widgets.
 *
 * Whenever a container has some form of natural row it may align
 * children in that row along a common typographical baseline. If
 * the amount of vertical space in the row is taller than the total
 * requested height of the baseline-aligned children then it can use a
 * `Gtk::BaselinePosition` to select where to put the baseline inside the
 * extra available space.
 *
 * @ingroup gtkmmEnums
 */
enum class BaselinePosition
{
  TOP,
  CENTER,
  BOTTOM
};


} // namespace Gtk

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

template <>
class GTKMM_API Value<Gtk::BaselinePosition> : public Glib::Value_Enum<Gtk::BaselinePosition>
{
public:
  static auto value_type() -> GType G_GNUC_CONST;
};

} // namespace Glib
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

namespace Gtk
{

/**
 *  @var ShortcutScope LOCAL
 * Shortcuts are handled inside
 * the widget the controller belongs to.
 *
 *  @var ShortcutScope MANAGED
 * Shortcuts are handled by
 * the first ancestor that is a Gtk::ShortcutManager.
 *
 *  @var ShortcutScope GLOBAL
 * Shortcuts are handled by
 * the root widget.
 *
 *  @enum ShortcutScope
 *
 * Describes where Gtk::Shortcuts added to a
 * Gtk::ShortcutController get handled.
 *
 * @ingroup gtkmmEnums
 */
enum class ShortcutScope
{
  LOCAL,
  MANAGED,
  GLOBAL
};


} // namespace Gtk

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

template <>
class GTKMM_API Value<Gtk::ShortcutScope> : public Glib::Value_Enum<Gtk::ShortcutScope>
{
public:
  static auto value_type() -> GType G_GNUC_CONST;
};

} // namespace Glib
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

namespace Gtk
{

/**
 *  @var ContentFit FILL
 * Make the content fill the entire allocation,
 * without taking its aspect ratio in consideration. The resulting
 * content will appear as stretched if its aspect ratio is different
 * from the allocation aspect ratio.
 *
 *  @var ContentFit CONTAIN
 * Scale the content to fit the allocation,
 * while taking its aspect ratio in consideration. The resulting
 * content will appear as letterboxed if its aspect ratio is different
 * from the allocation aspect ratio.
 *
 *  @var ContentFit COVER
 * Cover the entire allocation, while taking
 * the content aspect ratio in consideration. The resulting content
 * will appear as clipped if its aspect ratio is different from the
 * allocation aspect ratio.
 *
 *  @var ContentFit SCALE_DOWN
 * The content is scaled down to fit the
 * allocation, if needed, otherwise its original size is used.
 *
 *  @enum ContentFit
 *
 * Controls how a content should be made to fit inside an allocation.
 *
 * @newin{4,8}
 *
 * @ingroup gtkmmEnums
 */
enum class ContentFit
{
  FILL,
  CONTAIN,
  COVER,
  SCALE_DOWN
};


} // namespace Gtk

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

template <>
class GTKMM_API Value<Gtk::ContentFit> : public Glib::Value_Enum<Gtk::ContentFit>
{
public:
  static auto value_type() -> GType G_GNUC_CONST;
};

} // namespace Glib
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

namespace Gtk
{


#ifndef DOXYGEN_SHOULD_SKIP_THIS
//We need this because we can't just use floats for enum value.
auto _gtkmm_align_float_from_enum(Align value) -> float;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

} //namespace Gtk


#endif /* _GTKMM_ENUMS_H */
