// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GLIBMM_OPTIONENTRY_H
#define _GLIBMM_OPTIONENTRY_H

#include <libmm-glib/ustring.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
extern "C"
{
  typedef struct _GOptionEntry GOptionEntry;
}
#endif

namespace Glib
{

  class GLIBMM_API OptionEntry
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    using CppObjectType = OptionEntry;
    using BaseObjectType = GOptionEntry;
#endif

  private:
  public:
    enum class Flags
    {
      NONE = 0x0,
      HIDDEN = 1 << 0,
      IN_MAIN = 1 << 1,
      REVERSE = 1 << 2,
      NO_ARG = 1 << 3,
      FILENAME = 1 << 4,
      OPTIONAL_ARG = 1 << 5,
      NOALIAS = 1 << 6
    };

    OptionEntry ();
    OptionEntry (const OptionEntry& src);

    OptionEntry (OptionEntry&& other) noexcept;
    auto
    operator= (OptionEntry&& other) noexcept -> OptionEntry&;

    virtual ~OptionEntry ();

    auto
    operator= (const OptionEntry& src) -> OptionEntry&;

    auto
    get_long_name () const -> Glib::ustring;
    auto
    set_long_name (const Glib::ustring& value) -> void;

    auto
    get_short_name () const -> gchar;
    auto
    set_short_name (const gchar& value) -> void;

    auto
    get_flags () const -> Flags;

    auto
    set_flags (const Flags& value) -> void;

    auto
    get_description () const -> Glib::ustring;
    auto
    set_description (const Glib::ustring& value) -> void;

    auto
    get_arg_description () const -> Glib::ustring;
    auto
    set_arg_description (const Glib::ustring& value) -> void;

    auto
    gobj () -> GOptionEntry*
    {
      return gobject_;
    }

    auto
    gobj () const -> const GOptionEntry*
    {
      return gobject_;
    }

  private:
    auto
    release_gobject () noexcept -> void;

  protected:
    GOptionEntry* gobject_;
  };

} // namespace Glib

namespace Glib
{

  inline auto
  operator| (OptionEntry::Flags lhs, OptionEntry::Flags rhs) -> OptionEntry::Flags
  {
    return static_cast<OptionEntry::Flags> (static_cast<unsigned> (lhs) |
                                            static_cast<unsigned> (rhs));
  }

  inline auto
  operator& (OptionEntry::Flags lhs, OptionEntry::Flags rhs) -> OptionEntry::Flags
  {
    return static_cast<OptionEntry::Flags> (static_cast<unsigned> (lhs) &
                                            static_cast<unsigned> (rhs));
  }

  inline auto
  operator^ (OptionEntry::Flags lhs, OptionEntry::Flags rhs) -> OptionEntry::Flags
  {
    return static_cast<OptionEntry::Flags> (static_cast<unsigned> (lhs) ^
                                            static_cast<unsigned> (rhs));
  }

  inline auto
  operator~(OptionEntry::Flags flags) -> OptionEntry::Flags
  {
    return static_cast<OptionEntry::Flags> (~static_cast<unsigned> (flags));
  }

  inline auto
  operator|= (OptionEntry::Flags& lhs, OptionEntry::Flags rhs) -> OptionEntry::Flags&
  {
    return (lhs = static_cast<OptionEntry::Flags> (
                static_cast<unsigned> (lhs) | static_cast<unsigned> (rhs)));
  }

  inline auto
  operator&= (OptionEntry::Flags& lhs, OptionEntry::Flags rhs) -> OptionEntry::Flags&
  {
    return (lhs = static_cast<OptionEntry::Flags> (
                static_cast<unsigned> (lhs) & static_cast<unsigned> (rhs)));
  }

  inline auto
  operator^= (OptionEntry::Flags& lhs, OptionEntry::Flags rhs) -> OptionEntry::Flags&
  {
    return (lhs = static_cast<OptionEntry::Flags> (
                static_cast<unsigned> (lhs) ^ static_cast<unsigned> (rhs)));
  }
} // namespace Glib

#endif
