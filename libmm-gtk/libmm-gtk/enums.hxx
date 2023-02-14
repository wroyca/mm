// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_ENUMS_H
#define _GTKMM_ENUMS_H

#include <libmm-gtk/mm-gtkconfig.hxx>

#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <gtk/gtk.h>
#include <libmm-glib/value.hxx>

namespace Gtk
{

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
    static auto
    value_type () -> GType G_GNUC_CONST;
  };

} // namespace Glib
#endif

namespace Gtk
{

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
  class GTKMM_API Value<Gtk::ArrowType>
    : public Glib::Value_Enum<Gtk::ArrowType>
  {
  public:
    static auto
    value_type () -> GType G_GNUC_CONST;
  };

} // namespace Glib
#endif

namespace Gtk
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

} // namespace Gtk

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

  template <>
  class GTKMM_API Value<Gtk::DeleteType>
    : public Glib::Value_Enum<Gtk::DeleteType>
  {
  public:
    static auto
    value_type () -> GType G_GNUC_CONST;
  };

} // namespace Glib
#endif

namespace Gtk
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

} // namespace Gtk

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

  template <>
  class GTKMM_API Value<Gtk::DirectionType>
    : public Glib::Value_Enum<Gtk::DirectionType>
  {
  public:
    static auto
    value_type () -> GType G_GNUC_CONST;
  };

} // namespace Glib
#endif

namespace Gtk
{

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
    static auto
    value_type () -> GType G_GNUC_CONST;
  };

} // namespace Glib
#endif

namespace Gtk
{

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
  class GTKMM_API Value<Gtk::TextDirection>
    : public Glib::Value_Enum<Gtk::TextDirection>
  {
  public:
    static auto
    value_type () -> GType G_GNUC_CONST;
  };

} // namespace Glib
#endif

namespace Gtk
{

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
  class GTKMM_API Value<Gtk::Justification>
    : public Glib::Value_Enum<Gtk::Justification>
  {
  public:
    static auto
    value_type () -> GType G_GNUC_CONST;
  };

} // namespace Glib
#endif

namespace Gtk
{

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
  class GTKMM_API Value<Gtk::MessageType>
    : public Glib::Value_Enum<Gtk::MessageType>
  {
  public:
    static auto
    value_type () -> GType G_GNUC_CONST;
  };

} // namespace Glib
#endif

namespace Gtk
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

} // namespace Gtk

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

  template <>
  class GTKMM_API Value<Gtk::MovementStep>
    : public Glib::Value_Enum<Gtk::MovementStep>
  {
  public:
    static auto
    value_type () -> GType G_GNUC_CONST;
  };

} // namespace Glib
#endif

namespace Gtk
{

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
  class GTKMM_API Value<Gtk::Orientation>
    : public Glib::Value_Enum<Gtk::Orientation>
  {
  public:
    static auto
    value_type () -> GType G_GNUC_CONST;
  };

} // namespace Glib
#endif

namespace Gtk
{

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
    static auto
    value_type () -> GType G_GNUC_CONST;
  };

} // namespace Glib
#endif

namespace Gtk
{

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
  class GTKMM_API Value<Gtk::CornerType>
    : public Glib::Value_Enum<Gtk::CornerType>
  {
  public:
    static auto
    value_type () -> GType G_GNUC_CONST;
  };

} // namespace Glib
#endif

namespace Gtk
{

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
    static auto
    value_type () -> GType G_GNUC_CONST;
  };

} // namespace Glib
#endif

namespace Gtk
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

} // namespace Gtk

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

  template <>
  class GTKMM_API Value<Gtk::PickFlags>
    : public Glib::Value_Flags<Gtk::PickFlags>
  {
  public:
    static auto
    value_type () -> GType G_GNUC_CONST;
  };

} // namespace Glib
#endif

namespace Gtk
{

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
  class GTKMM_API Value<Gtk::PolicyType>
    : public Glib::Value_Enum<Gtk::PolicyType>
  {
  public:
    static auto
    value_type () -> GType G_GNUC_CONST;
  };

} // namespace Glib
#endif

namespace Gtk
{

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
  class GTKMM_API Value<Gtk::PositionType>
    : public Glib::Value_Enum<Gtk::PositionType>
  {
  public:
    static auto
    value_type () -> GType G_GNUC_CONST;
  };

} // namespace Glib
#endif

namespace Gtk
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

} // namespace Gtk

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

  template <>
  class GTKMM_API Value<Gtk::RevealerTransitionType>
    : public Glib::Value_Enum<Gtk::RevealerTransitionType>
  {
  public:
    static auto
    value_type () -> GType G_GNUC_CONST;
  };

} // namespace Glib
#endif

namespace Gtk
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

} // namespace Gtk

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

  template <>
  class GTKMM_API Value<Gtk::ScrollType>
    : public Glib::Value_Enum<Gtk::ScrollType>
  {
  public:
    static auto
    value_type () -> GType G_GNUC_CONST;
  };

} // namespace Glib
#endif

namespace Gtk
{

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
  class GTKMM_API Value<Gtk::SelectionMode>
    : public Glib::Value_Enum<Gtk::SelectionMode>
  {
  public:
    static auto
    value_type () -> GType G_GNUC_CONST;
  };

} // namespace Glib
#endif

namespace Gtk
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

} // namespace Gtk

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

  template <>
  class GTKMM_API Value<Gtk::StackTransitionType>
    : public Glib::Value_Enum<Gtk::StackTransitionType>
  {
  public:
    static auto
    value_type () -> GType G_GNUC_CONST;
  };

} // namespace Glib
#endif

namespace Gtk
{

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
    static auto
    value_type () -> GType G_GNUC_CONST;
  };

} // namespace Glib
#endif

namespace Gtk
{

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
  class GTKMM_API Value<Gtk::NaturalWrapMode>
    : public Glib::Value_Enum<Gtk::NaturalWrapMode>
  {
  public:
    static auto
    value_type () -> GType G_GNUC_CONST;
  };

} // namespace Glib
#endif

namespace Gtk
{

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
    static auto
    value_type () -> GType G_GNUC_CONST;
  };

} // namespace Glib
#endif

namespace Gtk
{

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
    static auto
    value_type () -> GType G_GNUC_CONST;
  };

} // namespace Glib
#endif

namespace Gtk
{

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
  class GTKMM_API Value<Gtk::PageOrientation>
    : public Glib::Value_Enum<Gtk::PageOrientation>
  {
  public:
    static auto
    value_type () -> GType G_GNUC_CONST;
  };

} // namespace Glib
#endif

namespace Gtk
{

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
  class GTKMM_API Value<Gtk::SensitivityType>
    : public Glib::Value_Enum<Gtk::SensitivityType>
  {
  public:
    static auto
    value_type () -> GType G_GNUC_CONST;
  };

} // namespace Glib
#endif

namespace Gtk
{

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
  class GTKMM_API Value<Gtk::SizeRequestMode>
    : public Glib::Value_Enum<Gtk::SizeRequestMode>
  {
  public:
    static auto
    value_type () -> GType G_GNUC_CONST;
  };

} // namespace Glib
#endif

namespace Gtk
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

} // namespace Gtk

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

  template <>
  class GTKMM_API Value<Gtk::StateFlags>
    : public Glib::Value_Flags<Gtk::StateFlags>
  {
  public:
    static auto
    value_type () -> GType G_GNUC_CONST;
  };

} // namespace Glib
#endif

namespace Gtk
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

} // namespace Gtk

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

  template <>
  class GTKMM_API Value<Gtk::InputPurpose>
    : public Glib::Value_Enum<Gtk::InputPurpose>
  {
  public:
    static auto
    value_type () -> GType G_GNUC_CONST;
  };

} // namespace Glib
#endif

namespace Gtk
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

} // namespace Gtk

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

  template <>
  class GTKMM_API Value<Gtk::InputHints>
    : public Glib::Value_Flags<Gtk::InputHints>
  {
  public:
    static auto
    value_type () -> GType G_GNUC_CONST;
  };

} // namespace Glib
#endif

namespace Gtk
{

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
  class GTKMM_API Value<Gtk::BaselinePosition>
    : public Glib::Value_Enum<Gtk::BaselinePosition>
  {
  public:
    static auto
    value_type () -> GType G_GNUC_CONST;
  };

} // namespace Glib
#endif

namespace Gtk
{

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
  class GTKMM_API Value<Gtk::ShortcutScope>
    : public Glib::Value_Enum<Gtk::ShortcutScope>
  {
  public:
    static auto
    value_type () -> GType G_GNUC_CONST;
  };

} // namespace Glib
#endif

namespace Gtk
{

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
  class GTKMM_API Value<Gtk::ContentFit>
    : public Glib::Value_Enum<Gtk::ContentFit>
  {
  public:
    static auto
    value_type () -> GType G_GNUC_CONST;
  };

} // namespace Glib
#endif

namespace Gtk
{

#ifndef DOXYGEN_SHOULD_SKIP_THIS

  auto
  _gtkmm_align_float_from_enum (Align value) -> float;
#endif

} // namespace Gtk

#endif
