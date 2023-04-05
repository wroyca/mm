// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_ENUMS_H
#define _GTKMM_ENUMS_H

#include <libmm/gtk/mm-gtkconfig.hxx>

#include <libmm/glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <gtk/gtk.h>
#include <libmm/glib/value.hxx>

namespace gtk
{

  enum class Align
  {
    FILL,
    START,
    END,
    CENTER,
    BASELINE
  };

} // namespace gtk

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace glib
{

  template <>
  class LIBMM_GTK_SYMEXPORT Value<gtk::Align> : public glib::Value_Enum<gtk::Align>
  {
  public:
    static auto
    value_type () -> GType G_GNUC_CONST;
  };

} // namespace glib
#endif

namespace gtk
{

  enum class ArrowType
  {
    UP,
    DOWN,
    LEFT,
    RIGHT,
    NONE
  };

} // namespace gtk

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace glib
{

  template <>
  class LIBMM_GTK_SYMEXPORT Value<gtk::ArrowType>
    : public glib::Value_Enum<gtk::ArrowType>
  {
  public:
    static auto
    value_type () -> GType G_GNUC_CONST;
  };

} // namespace glib
#endif

namespace gtk
{

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

} // namespace gtk

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace glib
{

  template <>
  class LIBMM_GTK_SYMEXPORT Value<gtk::DeleteType>
    : public glib::Value_Enum<gtk::DeleteType>
  {
  public:
    static auto
    value_type () -> GType G_GNUC_CONST;
  };

} // namespace glib
#endif

namespace gtk
{

  enum class DirectionType
  {
    TAB_FORWARD,
    TAB_BACKWARD,
    UP,
    DOWN,
    LEFT,
    RIGHT
  };

} // namespace gtk

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace glib
{

  template <>
  class LIBMM_GTK_SYMEXPORT Value<gtk::DirectionType>
    : public glib::Value_Enum<gtk::DirectionType>
  {
  public:
    static auto
    value_type () -> GType G_GNUC_CONST;
  };

} // namespace glib
#endif

namespace gtk
{

  enum class IconSize
  {
    INHERIT,
    NORMAL,
    LARGE
  };

} // namespace gtk

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace glib
{

  template <>
  class LIBMM_GTK_SYMEXPORT Value<gtk::IconSize> : public glib::Value_Enum<gtk::IconSize>
  {
  public:
    static auto
    value_type () -> GType G_GNUC_CONST;
  };

} // namespace glib
#endif

namespace gtk
{

  enum class TextDirection
  {
    NONE,
    LTR,
    RTL
  };

} // namespace gtk

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace glib
{

  template <>
  class LIBMM_GTK_SYMEXPORT Value<gtk::TextDirection>
    : public glib::Value_Enum<gtk::TextDirection>
  {
  public:
    static auto
    value_type () -> GType G_GNUC_CONST;
  };

} // namespace glib
#endif

namespace gtk
{

  enum class Justification
  {
    LEFT,
    RIGHT,
    CENTER,
    FILL
  };

} // namespace gtk

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace glib
{

  template <>
  class LIBMM_GTK_SYMEXPORT Value<gtk::Justification>
    : public glib::Value_Enum<gtk::Justification>
  {
  public:
    static auto
    value_type () -> GType G_GNUC_CONST;
  };

} // namespace glib
#endif

namespace gtk
{

  enum class MessageType
  {
    INFO,
    WARNING,
    QUESTION,
    ERROR,
    OTHER
  };

} // namespace gtk

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace glib
{

  template <>
  class LIBMM_GTK_SYMEXPORT Value<gtk::MessageType>
    : public glib::Value_Enum<gtk::MessageType>
  {
  public:
    static auto
    value_type () -> GType G_GNUC_CONST;
  };

} // namespace glib
#endif

namespace gtk
{

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

} // namespace gtk

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace glib
{

  template <>
  class LIBMM_GTK_SYMEXPORT Value<gtk::MovementStep>
    : public glib::Value_Enum<gtk::MovementStep>
  {
  public:
    static auto
    value_type () -> GType G_GNUC_CONST;
  };

} // namespace glib
#endif

namespace gtk
{

  enum class Orientation
  {
    HORIZONTAL,
    VERTICAL
  };

} // namespace gtk

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace glib
{

  template <>
  class LIBMM_GTK_SYMEXPORT Value<gtk::Orientation>
    : public glib::Value_Enum<gtk::Orientation>
  {
  public:
    static auto
    value_type () -> GType G_GNUC_CONST;
  };

} // namespace glib
#endif

namespace gtk
{

  enum class Overflow
  {
    VISIBLE,
    HIDDEN
  };

} // namespace gtk

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace glib
{

  template <>
  class LIBMM_GTK_SYMEXPORT Value<gtk::Overflow> : public glib::Value_Enum<gtk::Overflow>
  {
  public:
    static auto
    value_type () -> GType G_GNUC_CONST;
  };

} // namespace glib
#endif

namespace gtk
{

  enum class CornerType
  {
    TOP_LEFT,
    BOTTOM_LEFT,
    TOP_RIGHT,
    BOTTOM_RIGHT
  };

} // namespace gtk

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace glib
{

  template <>
  class LIBMM_GTK_SYMEXPORT Value<gtk::CornerType>
    : public glib::Value_Enum<gtk::CornerType>
  {
  public:
    static auto
    value_type () -> GType G_GNUC_CONST;
  };

} // namespace glib
#endif

namespace gtk
{

  enum class PackType
  {
    START,
    END
  };

} // namespace gtk

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace glib
{

  template <>
  class LIBMM_GTK_SYMEXPORT Value<gtk::PackType> : public glib::Value_Enum<gtk::PackType>
  {
  public:
    static auto
    value_type () -> GType G_GNUC_CONST;
  };

} // namespace glib
#endif

namespace gtk
{

  enum class PickFlags
  {
    DEFAULT = 0x0,
    INSENSITIVE = 1 << 0,
    NON_TARGETABLE = 1 << 1
  };

  inline auto
  operator| (PickFlags lhs, PickFlags rhs) -> PickFlags
  {
    return static_cast<PickFlags> (static_cast<unsigned> (lhs) |
                                   static_cast<unsigned> (rhs));
  }

  inline auto
  operator& (PickFlags lhs, PickFlags rhs) -> PickFlags
  {
    return static_cast<PickFlags> (static_cast<unsigned> (lhs) &
                                   static_cast<unsigned> (rhs));
  }

  inline auto
  operator^ (PickFlags lhs, PickFlags rhs) -> PickFlags
  {
    return static_cast<PickFlags> (static_cast<unsigned> (lhs) ^
                                   static_cast<unsigned> (rhs));
  }

  inline auto
  operator~(PickFlags flags) -> PickFlags
  {
    return static_cast<PickFlags> (~static_cast<unsigned> (flags));
  }

  inline auto
  operator|= (PickFlags& lhs, PickFlags rhs) -> PickFlags&
  {
    return (lhs = static_cast<PickFlags> (static_cast<unsigned> (lhs) |
                                          static_cast<unsigned> (rhs)));
  }

  inline auto
  operator&= (PickFlags& lhs, PickFlags rhs) -> PickFlags&
  {
    return (lhs = static_cast<PickFlags> (static_cast<unsigned> (lhs) &
                                          static_cast<unsigned> (rhs)));
  }

  inline auto
  operator^= (PickFlags& lhs, PickFlags rhs) -> PickFlags&
  {
    return (lhs = static_cast<PickFlags> (static_cast<unsigned> (lhs) ^
                                          static_cast<unsigned> (rhs)));
  }

} // namespace gtk

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace glib
{

  template <>
  class LIBMM_GTK_SYMEXPORT Value<gtk::PickFlags>
    : public glib::Value_Flags<gtk::PickFlags>
  {
  public:
    static auto
    value_type () -> GType G_GNUC_CONST;
  };

} // namespace glib
#endif

namespace gtk
{

  enum class PolicyType
  {
    ALWAYS,
    AUTOMATIC,
    NEVER,
    EXTERNAL
  };

} // namespace gtk

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace glib
{

  template <>
  class LIBMM_GTK_SYMEXPORT Value<gtk::PolicyType>
    : public glib::Value_Enum<gtk::PolicyType>
  {
  public:
    static auto
    value_type () -> GType G_GNUC_CONST;
  };

} // namespace glib
#endif

namespace gtk
{

  enum class PositionType
  {
    LEFT,
    RIGHT,
    TOP,
    BOTTOM
  };

} // namespace gtk

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace glib
{

  template <>
  class LIBMM_GTK_SYMEXPORT Value<gtk::PositionType>
    : public glib::Value_Enum<gtk::PositionType>
  {
  public:
    static auto
    value_type () -> GType G_GNUC_CONST;
  };

} // namespace glib
#endif

namespace gtk
{

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

} // namespace gtk

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace glib
{

  template <>
  class LIBMM_GTK_SYMEXPORT Value<gtk::RevealerTransitionType>
    : public glib::Value_Enum<gtk::RevealerTransitionType>
  {
  public:
    static auto
    value_type () -> GType G_GNUC_CONST;
  };

} // namespace glib
#endif

namespace gtk
{

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

} // namespace gtk

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace glib
{

  template <>
  class LIBMM_GTK_SYMEXPORT Value<gtk::ScrollType>
    : public glib::Value_Enum<gtk::ScrollType>
  {
  public:
    static auto
    value_type () -> GType G_GNUC_CONST;
  };

} // namespace glib
#endif

namespace gtk
{

  enum class SelectionMode
  {
    NONE,
    SINGLE,
    BROWSE,
    MULTIPLE
  };

} // namespace gtk

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace glib
{

  template <>
  class LIBMM_GTK_SYMEXPORT Value<gtk::SelectionMode>
    : public glib::Value_Enum<gtk::SelectionMode>
  {
  public:
    static auto
    value_type () -> GType G_GNUC_CONST;
  };

} // namespace glib
#endif

namespace gtk
{

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

} // namespace gtk

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace glib
{

  template <>
  class LIBMM_GTK_SYMEXPORT Value<gtk::StackTransitionType>
    : public glib::Value_Enum<gtk::StackTransitionType>
  {
  public:
    static auto
    value_type () -> GType G_GNUC_CONST;
  };

} // namespace glib
#endif

namespace gtk
{

  enum class WrapMode
  {
    NONE,
    CHAR,
    WORD,
    WORD_CHAR
  };

} // namespace gtk

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace glib
{

  template <>
  class LIBMM_GTK_SYMEXPORT Value<gtk::WrapMode> : public glib::Value_Enum<gtk::WrapMode>
  {
  public:
    static auto
    value_type () -> GType G_GNUC_CONST;
  };

} // namespace glib
#endif

namespace gtk
{

  enum class NaturalWrapMode
  {
    INHERIT,
    NONE,
    WORD
  };

} // namespace gtk

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace glib
{

  template <>
  class LIBMM_GTK_SYMEXPORT Value<gtk::NaturalWrapMode>
    : public glib::Value_Enum<gtk::NaturalWrapMode>
  {
  public:
    static auto
    value_type () -> GType G_GNUC_CONST;
  };

} // namespace glib
#endif

namespace gtk
{

  enum class SortType
  {
    ASCENDING,
    DESCENDING
  };

} // namespace gtk

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace glib
{

  template <>
  class LIBMM_GTK_SYMEXPORT Value<gtk::SortType> : public glib::Value_Enum<gtk::SortType>
  {
  public:
    static auto
    value_type () -> GType G_GNUC_CONST;
  };

} // namespace glib
#endif

namespace gtk
{

  enum class Ordering
  {
    SMALLER = -1,
    EQUAL,
    LARGER
  };

} // namespace gtk

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace glib
{

  template <>
  class LIBMM_GTK_SYMEXPORT Value<gtk::Ordering> : public glib::Value_Enum<gtk::Ordering>
  {
  public:
    static auto
    value_type () -> GType G_GNUC_CONST;
  };

} // namespace glib
#endif

namespace gtk
{

  enum class PageOrientation
  {
    PORTRAIT,
    LANDSCAPE,
    REVERSE_PORTRAIT,
    REVERSE_LANDSCAPE
  };

} // namespace gtk

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace glib
{

  template <>
  class LIBMM_GTK_SYMEXPORT Value<gtk::PageOrientation>
    : public glib::Value_Enum<gtk::PageOrientation>
  {
  public:
    static auto
    value_type () -> GType G_GNUC_CONST;
  };

} // namespace glib
#endif

namespace gtk
{

  enum class SensitivityType
  {
    AUTO,
    ON,
    OFF
  };

} // namespace gtk

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace glib
{

  template <>
  class LIBMM_GTK_SYMEXPORT Value<gtk::SensitivityType>
    : public glib::Value_Enum<gtk::SensitivityType>
  {
  public:
    static auto
    value_type () -> GType G_GNUC_CONST;
  };

} // namespace glib
#endif

namespace gtk
{

  enum class SizeRequestMode
  {
    HEIGHT_FOR_WIDTH,
    WIDTH_FOR_HEIGHT,
    CONSTANT_SIZE
  };

} // namespace gtk

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace glib
{

  template <>
  class LIBMM_GTK_SYMEXPORT Value<gtk::SizeRequestMode>
    : public glib::Value_Enum<gtk::SizeRequestMode>
  {
  public:
    static auto
    value_type () -> GType G_GNUC_CONST;
  };

} // namespace glib
#endif

namespace gtk
{

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

  inline auto
  operator| (StateFlags lhs, StateFlags rhs) -> StateFlags
  {
    return static_cast<StateFlags> (static_cast<unsigned> (lhs) |
                                    static_cast<unsigned> (rhs));
  }

  inline auto
  operator& (StateFlags lhs, StateFlags rhs) -> StateFlags
  {
    return static_cast<StateFlags> (static_cast<unsigned> (lhs) &
                                    static_cast<unsigned> (rhs));
  }

  inline auto
  operator^ (StateFlags lhs, StateFlags rhs) -> StateFlags
  {
    return static_cast<StateFlags> (static_cast<unsigned> (lhs) ^
                                    static_cast<unsigned> (rhs));
  }

  inline auto
  operator~(StateFlags flags) -> StateFlags
  {
    return static_cast<StateFlags> (~static_cast<unsigned> (flags));
  }

  inline auto
  operator|= (StateFlags& lhs, StateFlags rhs) -> StateFlags&
  {
    return (lhs = static_cast<StateFlags> (static_cast<unsigned> (lhs) |
                                           static_cast<unsigned> (rhs)));
  }

  inline auto
  operator&= (StateFlags& lhs, StateFlags rhs) -> StateFlags&
  {
    return (lhs = static_cast<StateFlags> (static_cast<unsigned> (lhs) &
                                           static_cast<unsigned> (rhs)));
  }

  inline auto
  operator^= (StateFlags& lhs, StateFlags rhs) -> StateFlags&
  {
    return (lhs = static_cast<StateFlags> (static_cast<unsigned> (lhs) ^
                                           static_cast<unsigned> (rhs)));
  }

} // namespace gtk

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace glib
{

  template <>
  class LIBMM_GTK_SYMEXPORT Value<gtk::StateFlags>
    : public glib::Value_Flags<gtk::StateFlags>
  {
  public:
    static auto
    value_type () -> GType G_GNUC_CONST;
  };

} // namespace glib
#endif

namespace gtk
{

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

} // namespace gtk

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace glib
{

  template <>
  class LIBMM_GTK_SYMEXPORT Value<gtk::InputPurpose>
    : public glib::Value_Enum<gtk::InputPurpose>
  {
  public:
    static auto
    value_type () -> GType G_GNUC_CONST;
  };

} // namespace glib
#endif

namespace gtk
{

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

  inline auto
  operator| (InputHints lhs, InputHints rhs) -> InputHints
  {
    return static_cast<InputHints> (static_cast<unsigned> (lhs) |
                                    static_cast<unsigned> (rhs));
  }

  inline auto
  operator& (InputHints lhs, InputHints rhs) -> InputHints
  {
    return static_cast<InputHints> (static_cast<unsigned> (lhs) &
                                    static_cast<unsigned> (rhs));
  }

  inline auto
  operator^ (InputHints lhs, InputHints rhs) -> InputHints
  {
    return static_cast<InputHints> (static_cast<unsigned> (lhs) ^
                                    static_cast<unsigned> (rhs));
  }

  inline auto
  operator~(InputHints flags) -> InputHints
  {
    return static_cast<InputHints> (~static_cast<unsigned> (flags));
  }

  inline auto
  operator|= (InputHints& lhs, InputHints rhs) -> InputHints&
  {
    return (lhs = static_cast<InputHints> (static_cast<unsigned> (lhs) |
                                           static_cast<unsigned> (rhs)));
  }

  inline auto
  operator&= (InputHints& lhs, InputHints rhs) -> InputHints&
  {
    return (lhs = static_cast<InputHints> (static_cast<unsigned> (lhs) &
                                           static_cast<unsigned> (rhs)));
  }

  inline auto
  operator^= (InputHints& lhs, InputHints rhs) -> InputHints&
  {
    return (lhs = static_cast<InputHints> (static_cast<unsigned> (lhs) ^
                                           static_cast<unsigned> (rhs)));
  }

} // namespace gtk

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace glib
{

  template <>
  class LIBMM_GTK_SYMEXPORT Value<gtk::InputHints>
    : public glib::Value_Flags<gtk::InputHints>
  {
  public:
    static auto
    value_type () -> GType G_GNUC_CONST;
  };

} // namespace glib
#endif

namespace gtk
{

  enum class BaselinePosition
  {
    TOP,
    CENTER,
    BOTTOM
  };

} // namespace gtk

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace glib
{

  template <>
  class LIBMM_GTK_SYMEXPORT Value<gtk::BaselinePosition>
    : public glib::Value_Enum<gtk::BaselinePosition>
  {
  public:
    static auto
    value_type () -> GType G_GNUC_CONST;
  };

} // namespace glib
#endif

namespace gtk
{

  enum class ShortcutScope
  {
    LOCAL,
    MANAGED,
    GLOBAL
  };

} // namespace gtk

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace glib
{

  template <>
  class LIBMM_GTK_SYMEXPORT Value<gtk::ShortcutScope>
    : public glib::Value_Enum<gtk::ShortcutScope>
  {
  public:
    static auto
    value_type () -> GType G_GNUC_CONST;
  };

} // namespace glib
#endif

namespace gtk
{

  enum class ContentFit
  {
    FILL,
    CONTAIN,
    COVER,
    SCALE_DOWN
  };

} // namespace gtk

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace glib
{

  template <>
  class LIBMM_GTK_SYMEXPORT Value<gtk::ContentFit>
    : public glib::Value_Enum<gtk::ContentFit>
  {
  public:
    static auto
    value_type () -> GType G_GNUC_CONST;
  };

} // namespace glib
#endif

namespace gtk
{

#ifndef DOXYGEN_SHOULD_SKIP_THIS

  auto
  _gtkmm_align_float_from_enum (Align value) -> float;
#endif

} // namespace gtk

#endif
