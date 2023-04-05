// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GDKMM_ENUMS_H
#define _GDKMM_ENUMS_H

#include <libmm/gdk/mm-gdkconfig.hxx>

#include <libmm/glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <gdk/gdk.h>
#include <libmm/glib/value.hxx>

namespace gdk
{

  enum class AxisFlags
  {
    X = 0x2,
    Y = 0x4,
    DELTA_X = 0x8,
    DELTA_Y = 0x10,
    PRESSURE = 0x20,
    XTILT = 0x40,
    YTILT = 0x80,
    WHEEL = 0x100,
    DISTANCE = 0x200,
    ROTATION = 0x400,
    SLIDER = 0x800
  };

  inline auto
  operator| (AxisFlags lhs, AxisFlags rhs) -> AxisFlags
  {
    return static_cast<AxisFlags> (static_cast<unsigned> (lhs) |
                                   static_cast<unsigned> (rhs));
  }

  inline auto
  operator& (AxisFlags lhs, AxisFlags rhs) -> AxisFlags
  {
    return static_cast<AxisFlags> (static_cast<unsigned> (lhs) &
                                   static_cast<unsigned> (rhs));
  }

  inline auto
  operator^ (AxisFlags lhs, AxisFlags rhs) -> AxisFlags
  {
    return static_cast<AxisFlags> (static_cast<unsigned> (lhs) ^
                                   static_cast<unsigned> (rhs));
  }

  inline auto
  operator~(AxisFlags flags) -> AxisFlags
  {
    return static_cast<AxisFlags> (~static_cast<unsigned> (flags));
  }

  inline auto
  operator|= (AxisFlags& lhs, AxisFlags rhs) -> AxisFlags&
  {
    return (lhs = static_cast<AxisFlags> (static_cast<unsigned> (lhs) |
                                          static_cast<unsigned> (rhs)));
  }

  inline auto
  operator&= (AxisFlags& lhs, AxisFlags rhs) -> AxisFlags&
  {
    return (lhs = static_cast<AxisFlags> (static_cast<unsigned> (lhs) &
                                          static_cast<unsigned> (rhs)));
  }

  inline auto
  operator^= (AxisFlags& lhs, AxisFlags rhs) -> AxisFlags&
  {
    return (lhs = static_cast<AxisFlags> (static_cast<unsigned> (lhs) ^
                                          static_cast<unsigned> (rhs)));
  }

} // namespace gdk

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace glib
{

  template <>
  class LIBMM_GDK_SYMEXPORT Value<gdk::AxisFlags>
    : public glib::Value_Flags<gdk::AxisFlags>
  {
  public:
    static auto
    value_type () -> GType G_GNUC_CONST;
  };

} // namespace glib
#endif

namespace gdk
{

  enum class AxisUse
  {
    IGNORE,
    X,
    Y,
    DELTA_X,
    DELTA_Y,
    PRESSURE,
    XTILT,
    YTILT,
    WHEEL,
    DISTANCE,
    ROTATION,
    SLIDER,
    LAST
  };

} // namespace gdk

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace glib
{

  template <>
  class LIBMM_GDK_SYMEXPORT Value<gdk::AxisUse> : public glib::Value_Enum<gdk::AxisUse>
  {
  public:
    static auto
    value_type () -> GType G_GNUC_CONST;
  };

} // namespace glib
#endif

namespace gdk
{

  enum class CrossingMode
  {
    NORMAL,
    GRAB,
    UNGRAB,
    GTK_GRAB,
    GTK_UNGRAB,
    STATE_CHANGED,
    TOUCH_BEGIN,
    TOUCH_END,
    DEVICE_SWITCH
  };

} // namespace gdk

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace glib
{

  template <>
  class LIBMM_GDK_SYMEXPORT Value<gdk::CrossingMode>
    : public glib::Value_Enum<gdk::CrossingMode>
  {
  public:
    static auto
    value_type () -> GType G_GNUC_CONST;
  };

} // namespace glib
#endif

namespace gdk
{

  enum class DragAction
  {
    COPY = 1 << 0,
    MOVE = 1 << 1,
    LINK = 1 << 2,
    ASK = 1 << 3
  };

  inline auto
  operator| (DragAction lhs, DragAction rhs) -> DragAction
  {
    return static_cast<DragAction> (static_cast<unsigned> (lhs) |
                                    static_cast<unsigned> (rhs));
  }

  inline auto
  operator& (DragAction lhs, DragAction rhs) -> DragAction
  {
    return static_cast<DragAction> (static_cast<unsigned> (lhs) &
                                    static_cast<unsigned> (rhs));
  }

  inline auto
  operator^ (DragAction lhs, DragAction rhs) -> DragAction
  {
    return static_cast<DragAction> (static_cast<unsigned> (lhs) ^
                                    static_cast<unsigned> (rhs));
  }

  inline auto
  operator~(DragAction flags) -> DragAction
  {
    return static_cast<DragAction> (~static_cast<unsigned> (flags));
  }

  inline auto
  operator|= (DragAction& lhs, DragAction rhs) -> DragAction&
  {
    return (lhs = static_cast<DragAction> (static_cast<unsigned> (lhs) |
                                           static_cast<unsigned> (rhs)));
  }

  inline auto
  operator&= (DragAction& lhs, DragAction rhs) -> DragAction&
  {
    return (lhs = static_cast<DragAction> (static_cast<unsigned> (lhs) &
                                           static_cast<unsigned> (rhs)));
  }

  inline auto
  operator^= (DragAction& lhs, DragAction rhs) -> DragAction&
  {
    return (lhs = static_cast<DragAction> (static_cast<unsigned> (lhs) ^
                                           static_cast<unsigned> (rhs)));
  }

} // namespace gdk

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace glib
{

  template <>
  class LIBMM_GDK_SYMEXPORT Value<gdk::DragAction>
    : public glib::Value_Flags<gdk::DragAction>
  {
  public:
    static auto
    value_type () -> GType G_GNUC_CONST;
  };

} // namespace glib
#endif

namespace gdk
{

  enum class Gravity
  {
    NORTH_WEST = 1,
    NORTH,
    NORTH_EAST,
    WEST,
    CENTER,
    EAST,
    SOUTH_WEST,
    SOUTH,
    SOUTH_EAST,
    STATIC
  };

} // namespace gdk

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace glib
{

  template <>
  class LIBMM_GDK_SYMEXPORT Value<gdk::Gravity> : public glib::Value_Enum<gdk::Gravity>
  {
  public:
    static auto
    value_type () -> GType G_GNUC_CONST;
  };

} // namespace glib
#endif

namespace gdk
{

  enum class ModifierType
  {
    SHIFT_MASK = 1 << 0,
    LOCK_MASK = 1 << 1,
    CONTROL_MASK = 1 << 2,
    ALT_MASK = 1 << 3,
    BUTTON1_MASK = 1 << 8,
    BUTTON2_MASK = 1 << 9,
    BUTTON3_MASK = 1 << 10,
    BUTTON4_MASK = 1 << 11,
    BUTTON5_MASK = 1 << 12,
    SUPER_MASK = 1 << 26,
    HYPER_MASK = 1 << 27,
    META_MASK = 1 << 28
  };

  inline auto
  operator| (ModifierType lhs, ModifierType rhs) -> ModifierType
  {
    return static_cast<ModifierType> (static_cast<unsigned> (lhs) |
                                      static_cast<unsigned> (rhs));
  }

  inline auto
  operator& (ModifierType lhs, ModifierType rhs) -> ModifierType
  {
    return static_cast<ModifierType> (static_cast<unsigned> (lhs) &
                                      static_cast<unsigned> (rhs));
  }

  inline auto
  operator^ (ModifierType lhs, ModifierType rhs) -> ModifierType
  {
    return static_cast<ModifierType> (static_cast<unsigned> (lhs) ^
                                      static_cast<unsigned> (rhs));
  }

  inline auto
  operator~(ModifierType flags) -> ModifierType
  {
    return static_cast<ModifierType> (~static_cast<unsigned> (flags));
  }

  inline auto
  operator|= (ModifierType& lhs, ModifierType rhs) -> ModifierType&
  {
    return (lhs = static_cast<ModifierType> (static_cast<unsigned> (lhs) |
                                             static_cast<unsigned> (rhs)));
  }

  inline auto
  operator&= (ModifierType& lhs, ModifierType rhs) -> ModifierType&
  {
    return (lhs = static_cast<ModifierType> (static_cast<unsigned> (lhs) &
                                             static_cast<unsigned> (rhs)));
  }

  inline auto
  operator^= (ModifierType& lhs, ModifierType rhs) -> ModifierType&
  {
    return (lhs = static_cast<ModifierType> (static_cast<unsigned> (lhs) ^
                                             static_cast<unsigned> (rhs)));
  }

} // namespace gdk

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace glib
{

  template <>
  class LIBMM_GDK_SYMEXPORT Value<gdk::ModifierType>
    : public glib::Value_Flags<gdk::ModifierType>
  {
  public:
    static auto
    value_type () -> GType G_GNUC_CONST;
  };

} // namespace glib
#endif

namespace gdk
{

  enum class NotifyType
  {
    ANCESTOR,
    VIRTUAL,
    INFERIOR,
    NONLINEAR,
    NONLINEAR_VIRTUAL,
    UNKNOWN
  };

} // namespace gdk

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace glib
{

  template <>
  class LIBMM_GDK_SYMEXPORT Value<gdk::NotifyType>
    : public glib::Value_Enum<gdk::NotifyType>
  {
  public:
    static auto
    value_type () -> GType G_GNUC_CONST;
  };

} // namespace glib
#endif

namespace gdk
{

  enum class ScrollDirection
  {
    UP,
    DOWN,
    LEFT,
    RIGHT,
    SMOOTH
  };

} // namespace gdk

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace glib
{

  template <>
  class LIBMM_GDK_SYMEXPORT Value<gdk::ScrollDirection>
    : public glib::Value_Enum<gdk::ScrollDirection>
  {
  public:
    static auto
    value_type () -> GType G_GNUC_CONST;
  };

} // namespace glib
#endif

namespace gdk
{

  enum class TouchpadGesturePhase
  {
    BEGIN,
    UPDATE,
    END,
    CANCEL
  };

} // namespace gdk

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace glib
{

  template <>
  class LIBMM_GDK_SYMEXPORT Value<gdk::TouchpadGesturePhase>
    : public glib::Value_Enum<gdk::TouchpadGesturePhase>
  {
  public:
    static auto
    value_type () -> GType G_GNUC_CONST;
  };

} // namespace glib
#endif

namespace gdk
{

  enum class ScrollUnit
  {
    WHEEL,
    SURFACE
  };

} // namespace gdk

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace glib
{

  template <>
  class LIBMM_GDK_SYMEXPORT Value<gdk::ScrollUnit>
    : public glib::Value_Enum<gdk::ScrollUnit>
  {
  public:
    static auto
    value_type () -> GType G_GNUC_CONST;
  };

} // namespace glib
#endif

namespace gdk
{

}

#endif
