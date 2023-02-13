
#ifndef _GLIBMM_OPTIONENTRY_H
#define _GLIBMM_OPTIONENTRY_H


/* Copyright (C) 2004 The glibmm Development Team
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
 * License along with this library.  If not, see <http://www.gnu.org/licenses/>.
 */


#include <libmm-glib/ustring.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
extern "C" { typedef struct _GOptionEntry GOptionEntry; }
#endif

namespace Glib
{

/** An OptionEntry defines a single option. To have an effect, it must be added to an OptionGroup with
 * OptionGroup::add_entry().
 *
 * The long name of an option can be used to specify it in a commandline as --long_name.
 * Every option must have a long name. To resolve conflicts if multiple option groups contain the same long name, it is also
 * possible to specify the option as --groupname-long_name.
 *
 * If an option has a short name, it can be specified as -short_name in a commandline.
 *
 * The description for the option is shown in the --help  output.
 *
 * The arg_descripton is the placeholder to use for the extra argument parsed by the option in --help  output.
 */
class GLIBMM_API OptionEntry
{
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  using CppObjectType = OptionEntry;
  using BaseObjectType = GOptionEntry;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

private:

public:

  /** @addtogroup glibmmEnums glibmm Enums and Flags */

  /**
   *  @var Flags NONE
   * No flags. @newin{2,42}
   *
   *  @var Flags HIDDEN
   * The option doesn't appear in `--help` output.
   *
   *  @var Flags IN_MAIN
   * The option appears in the main section of the
   * `--help` output, even if it is defined in a group.
   *
   *  @var Flags REVERSE
   * For options of the G_OPTION_ARG_NONE kind, this
   * flag indicates that the sense of the option is reversed. i.e. <tt>false</tt> will
   * be stored into the argument rather than <tt>true</tt>.
   *
   *  @var Flags NO_ARG
   * For options of the G_OPTION_ARG_CALLBACK kind,
   * this flag indicates that the callback does not take any argument
   * (like a G_OPTION_ARG_NONE option). @newin{2,8}
   *
   *  @var Flags FILENAME
   * For options of the G_OPTION_ARG_CALLBACK
   * kind, this flag indicates that the argument should be passed to the
   * callback in the GLib filename encoding rather than UTF-8. @newin{2,8}
   *
   *  @var Flags OPTIONAL_ARG
   * For options of the G_OPTION_ARG_CALLBACK
   * kind, this flag indicates that the argument supply is optional.
   * If no argument is given then data of OptionParseFunc will be
   * set to <tt>nullptr</tt>. @newin{2,8}
   *
   *  @var Flags NOALIAS
   * This flag turns off the automatic conflict
   * resolution which prefixes long option names with `groupname-` if
   * there is a conflict. This option should only be used in situations
   * where aliasing is necessary to model some legacy commandline interface.
   * It is not safe to use this option, unless all option groups are under
   * your direct control. @newin{2,8}
   *
   *  @enum Flags
   *
   * Flags which modify individual options.
   *
   * @ingroup glibmmEnums
   * @par Bitwise operators:
   * <tt>OptionEntry::Flags operator|(OptionEntry::Flags, OptionEntry::Flags)</tt><br>
   * <tt>OptionEntry::Flags operator&(OptionEntry::Flags, OptionEntry::Flags)</tt><br>
   * <tt>OptionEntry::Flags operator^(OptionEntry::Flags, OptionEntry::Flags)</tt><br>
   * <tt>OptionEntry::Flags operator~(OptionEntry::Flags)</tt><br>
   * <tt>OptionEntry::Flags& operator|=(OptionEntry::Flags&, OptionEntry::Flags)</tt><br>
   * <tt>OptionEntry::Flags& operator&=(OptionEntry::Flags&, OptionEntry::Flags)</tt><br>
   * <tt>OptionEntry::Flags& operator^=(OptionEntry::Flags&, OptionEntry::Flags)</tt><br>
   */
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


  OptionEntry();
  OptionEntry(const OptionEntry& src);

  OptionEntry(OptionEntry&& other) noexcept;
  auto operator=(OptionEntry&& other) noexcept -> OptionEntry&;

  virtual ~OptionEntry();

  auto operator=(const OptionEntry& src) -> OptionEntry&;

  // We do not use nullptr for an empty string in set_long_name(),
  // because G_OPTION_REMAINING is actually a "", so it has a distinct meaning.
  // TODO: Wrap G_OPTION_REMAINING in C++ somehow, maybe as an overloaded
  // set_long_name(void) or set_is_remaining()? murrayc.


  auto get_long_name() const -> Glib::ustring;
  void set_long_name(const Glib::ustring& value);

  auto get_short_name() const -> gchar;
  void set_short_name(const gchar& value);


  auto get_flags() const -> Flags;


  /** Set one or more OptionEntry::Flags.
   * Do not set Flags::FILENAME. Character encoding is chosen when the OptionEntry
   * is added to an OptionGroup.
   */
  void set_flags(const Flags& value);

  // We use nullptr for an empty string in set_description() and set_arg_description().


  auto get_description() const -> Glib::ustring;
  void set_description(const Glib::ustring& value);

  auto get_arg_description() const -> Glib::ustring;
  void set_arg_description(const Glib::ustring& value);

  auto       gobj() -> GOptionEntry*       { return gobject_; }
  auto gobj() const -> const GOptionEntry* { return gobject_; }

private:
  void release_gobject() noexcept;

protected:
  GOptionEntry* gobject_;


};

} // namespace Glib

namespace Glib
{

/** @ingroup glibmmEnums */
inline auto operator|(OptionEntry::Flags lhs, OptionEntry::Flags rhs) -> OptionEntry::Flags
  { return static_cast<OptionEntry::Flags>(static_cast<unsigned>(lhs) | static_cast<unsigned>(rhs)); }

/** @ingroup glibmmEnums */
inline auto operator&(OptionEntry::Flags lhs, OptionEntry::Flags rhs) -> OptionEntry::Flags
  { return static_cast<OptionEntry::Flags>(static_cast<unsigned>(lhs) & static_cast<unsigned>(rhs)); }

/** @ingroup glibmmEnums */
inline auto operator^(OptionEntry::Flags lhs, OptionEntry::Flags rhs) -> OptionEntry::Flags
  { return static_cast<OptionEntry::Flags>(static_cast<unsigned>(lhs) ^ static_cast<unsigned>(rhs)); }

/** @ingroup glibmmEnums */
inline auto operator~(OptionEntry::Flags flags) -> OptionEntry::Flags
  { return static_cast<OptionEntry::Flags>(~static_cast<unsigned>(flags)); }

/** @ingroup glibmmEnums */
inline auto operator|=(OptionEntry::Flags& lhs, OptionEntry::Flags rhs) -> OptionEntry::Flags&
  { return (lhs = static_cast<OptionEntry::Flags>(static_cast<unsigned>(lhs) | static_cast<unsigned>(rhs))); }

/** @ingroup glibmmEnums */
inline auto operator&=(OptionEntry::Flags& lhs, OptionEntry::Flags rhs) -> OptionEntry::Flags&
  { return (lhs = static_cast<OptionEntry::Flags>(static_cast<unsigned>(lhs) & static_cast<unsigned>(rhs))); }

/** @ingroup glibmmEnums */
inline auto operator^=(OptionEntry::Flags& lhs, OptionEntry::Flags rhs) -> OptionEntry::Flags&
  { return (lhs = static_cast<OptionEntry::Flags>(static_cast<unsigned>(lhs) ^ static_cast<unsigned>(rhs))); }
} // namespace Glib


#endif /* _GLIBMM_OPTIONENTRY_H */

