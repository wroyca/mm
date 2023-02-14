
#ifndef _GLIBMM_ENUMS_H
#define _GLIBMM_ENUMS_H

#include <glib.h>

namespace Glib
{

  enum class MainContextFlags
  {
    NONE = 0x0,
    OWNERLESS_POLLING = 0x1
  };

  inline auto
  operator| (MainContextFlags lhs, MainContextFlags rhs) -> MainContextFlags
  {
    return static_cast<MainContextFlags> (static_cast<unsigned> (lhs) |
                                          static_cast<unsigned> (rhs));
  }

  inline auto
  operator& (MainContextFlags lhs, MainContextFlags rhs) -> MainContextFlags
  {
    return static_cast<MainContextFlags> (static_cast<unsigned> (lhs) &
                                          static_cast<unsigned> (rhs));
  }

  inline auto
  operator^ (MainContextFlags lhs, MainContextFlags rhs) -> MainContextFlags
  {
    return static_cast<MainContextFlags> (static_cast<unsigned> (lhs) ^
                                          static_cast<unsigned> (rhs));
  }

  inline auto
  operator~(MainContextFlags flags) -> MainContextFlags
  {
    return static_cast<MainContextFlags> (~static_cast<unsigned> (flags));
  }

  inline auto
  operator|= (MainContextFlags& lhs, MainContextFlags rhs) -> MainContextFlags&
  {
    return (lhs = static_cast<MainContextFlags> (static_cast<unsigned> (lhs) |
                                                 static_cast<unsigned> (rhs)));
  }

  inline auto
  operator&= (MainContextFlags& lhs, MainContextFlags rhs) -> MainContextFlags&
  {
    return (lhs = static_cast<MainContextFlags> (static_cast<unsigned> (lhs) &
                                                 static_cast<unsigned> (rhs)));
  }

  inline auto
  operator^= (MainContextFlags& lhs, MainContextFlags rhs) -> MainContextFlags&
  {
    return (lhs = static_cast<MainContextFlags> (static_cast<unsigned> (lhs) ^
                                                 static_cast<unsigned> (rhs)));
  }

  enum class ParamFlags
  {
    READABLE = 1 << 0,
    WRITABLE = 1 << 1,
    READWRITE = 0x3,
    CONSTRUCT = 1 << 2,
    CONSTRUCT_ONLY = 1 << 3,
    LAX_VALIDATION = 1 << 4,
    STATIC_NAME = 1 << 5,
    PRIVATE = 0x20,
    STATIC_NICK = 1 << 6,
    STATIC_BLURB = 1 << 7,
    EXPLICIT_NOTIFY = 1 << 30,
    DEPRECATED = (gint) (1u << 31)
  };

  inline auto
  operator| (ParamFlags lhs, ParamFlags rhs) -> ParamFlags
  {
    return static_cast<ParamFlags> (static_cast<unsigned> (lhs) |
                                    static_cast<unsigned> (rhs));
  }

  inline auto
  operator& (ParamFlags lhs, ParamFlags rhs) -> ParamFlags
  {
    return static_cast<ParamFlags> (static_cast<unsigned> (lhs) &
                                    static_cast<unsigned> (rhs));
  }

  inline auto
  operator^ (ParamFlags lhs, ParamFlags rhs) -> ParamFlags
  {
    return static_cast<ParamFlags> (static_cast<unsigned> (lhs) ^
                                    static_cast<unsigned> (rhs));
  }

  inline auto
  operator~(ParamFlags flags) -> ParamFlags
  {
    return static_cast<ParamFlags> (~static_cast<unsigned> (flags));
  }

  inline auto
  operator|= (ParamFlags& lhs, ParamFlags rhs) -> ParamFlags&
  {
    return (lhs = static_cast<ParamFlags> (static_cast<unsigned> (lhs) |
                                           static_cast<unsigned> (rhs)));
  }

  inline auto
  operator&= (ParamFlags& lhs, ParamFlags rhs) -> ParamFlags&
  {
    return (lhs = static_cast<ParamFlags> (static_cast<unsigned> (lhs) &
                                           static_cast<unsigned> (rhs)));
  }

  inline auto
  operator^= (ParamFlags& lhs, ParamFlags rhs) -> ParamFlags&
  {
    return (lhs = static_cast<ParamFlags> (static_cast<unsigned> (lhs) ^
                                           static_cast<unsigned> (rhs)));
  }

} // namespace Glib

#endif
