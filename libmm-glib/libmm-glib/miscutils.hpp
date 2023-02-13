
#ifndef _GLIBMM_MISCUTILS_H
#define _GLIBMM_MISCUTILS_H


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
 * License along with this library.  If not, see <http://www.gnu.org/licenses/>.
 */


#include <libmm-glib/ustring.hpp>
#include <libmm-glib/utility.hpp>
#include <vector>

namespace Glib
{
/** @addtogroup glibmmEnums glibmm Enums and Flags */

/**
 *  @var UserDirectory DESKTOP
 * The user's Desktop directory.
 *
 *  @var UserDirectory DOCUMENTS
 * The user's Documents directory.
 *
 *  @var UserDirectory DOWNLOAD
 * The user's Downloads directory.
 *
 *  @var UserDirectory MUSIC
 * The user's Music directory.
 *
 *  @var UserDirectory PICTURES
 * The user's Pictures directory.
 *
 *  @var UserDirectory PUBLIC_SHARE
 * The user's shared directory.
 *
 *  @var UserDirectory TEMPLATES
 * The user's Templates directory.
 *
 *  @var UserDirectory VIDEOS
 * The user's Movies directory.
 *
 *  @var UserDirectory N_DIRECTORIES
 * The number of enum values.
 *
 *  @enum UserDirectory
 *
 * These are logical ids for special directories which are defined
 * depending on the platform used. You should use g_get_user_special_dir()
 * to retrieve the full path associated to the logical id.
 *
 * The UserDirectory enumeration can be extended at later date. Not
 * every platform has a directory for every logical id in this
 * enumeration.
 *
 * @newin{2,14}
 *
 * @ingroup glibmmEnums
 */
enum class UserDirectory
{
  DESKTOP,
  DOCUMENTS,
  DOWNLOAD,
  MUSIC,
  PICTURES,
  PUBLIC_SHARE,
  TEMPLATES,
  VIDEOS,
  N_DIRECTORIES
};


/**
 *  @var FormatSizeFlags DEFAULT
 * Behave the same as g_format_size().
 *
 *  @var FormatSizeFlags LONG_FORMAT
 * Include the exact number of bytes as part
 * of the returned string.  For example, "45.6 kB (45,612 bytes)".
 *
 *  @var FormatSizeFlags IEC_UNITS
 * Use IEC (base 1024) units with "KiB"-style
 * suffixes. IEC units should only be used for reporting things with
 * a strong "power of 2" basis, like RAM sizes or RAID stripe sizes.
 * Network and storage sizes should be reported in the normal SI units.
 *
 *  @var FormatSizeFlags BITS
 * Set the size as a quantity in bits, rather than
 * bytes, and return units in bits. For example, ‘Mb’ rather than ‘MB’.
 *
 *  @var FormatSizeFlags ONLY_VALUE
 * Return only value, without unit; this should
 * not be used together with @a G_FORMAT_SIZE_LONG_FORMAT
 * nor @a G_FORMAT_SIZE_ONLY_UNIT. @newin{2,74}
 *
 *  @var FormatSizeFlags ONLY_UNIT
 * Return only unit, without value; this should
 * not be used together with @a G_FORMAT_SIZE_LONG_FORMAT
 * nor @a G_FORMAT_SIZE_ONLY_VALUE. @newin{2,74}
 *
 *  @enum FormatSizeFlags
 *
 * Flags to modify the format of the string returned by g_format_size_full().
 *
 * @ingroup glibmmEnums
 * @par Bitwise operators:
 * <tt>FormatSizeFlags operator|(FormatSizeFlags, FormatSizeFlags)</tt><br>
 * <tt>FormatSizeFlags operator&(FormatSizeFlags, FormatSizeFlags)</tt><br>
 * <tt>FormatSizeFlags operator^(FormatSizeFlags, FormatSizeFlags)</tt><br>
 * <tt>FormatSizeFlags operator~(FormatSizeFlags)</tt><br>
 * <tt>FormatSizeFlags& operator|=(FormatSizeFlags&, FormatSizeFlags)</tt><br>
 * <tt>FormatSizeFlags& operator&=(FormatSizeFlags&, FormatSizeFlags)</tt><br>
 * <tt>FormatSizeFlags& operator^=(FormatSizeFlags&, FormatSizeFlags)</tt><br>
 */
enum class FormatSizeFlags
{
  DEFAULT = 0x0,
  LONG_FORMAT = 1 << 0,
  IEC_UNITS = 1 << 1,
  BITS = 1 << 2,
  ONLY_VALUE = 1 << 3,
  ONLY_UNIT = 1 << 4
};

/** @ingroup glibmmEnums */
inline auto operator|(FormatSizeFlags lhs, FormatSizeFlags rhs) -> FormatSizeFlags
  { return static_cast<FormatSizeFlags>(static_cast<unsigned>(lhs) | static_cast<unsigned>(rhs)); }

/** @ingroup glibmmEnums */
inline auto operator&(FormatSizeFlags lhs, FormatSizeFlags rhs) -> FormatSizeFlags
  { return static_cast<FormatSizeFlags>(static_cast<unsigned>(lhs) & static_cast<unsigned>(rhs)); }

/** @ingroup glibmmEnums */
inline auto operator^(FormatSizeFlags lhs, FormatSizeFlags rhs) -> FormatSizeFlags
  { return static_cast<FormatSizeFlags>(static_cast<unsigned>(lhs) ^ static_cast<unsigned>(rhs)); }

/** @ingroup glibmmEnums */
inline auto operator~(FormatSizeFlags flags) -> FormatSizeFlags
  { return static_cast<FormatSizeFlags>(~static_cast<unsigned>(flags)); }

/** @ingroup glibmmEnums */
inline auto operator|=(FormatSizeFlags& lhs, FormatSizeFlags rhs) -> FormatSizeFlags&
  { return (lhs = static_cast<FormatSizeFlags>(static_cast<unsigned>(lhs) | static_cast<unsigned>(rhs))); }

/** @ingroup glibmmEnums */
inline auto operator&=(FormatSizeFlags& lhs, FormatSizeFlags rhs) -> FormatSizeFlags&
  { return (lhs = static_cast<FormatSizeFlags>(static_cast<unsigned>(lhs) & static_cast<unsigned>(rhs))); }

/** @ingroup glibmmEnums */
inline auto operator^=(FormatSizeFlags& lhs, FormatSizeFlags rhs) -> FormatSizeFlags&
  { return (lhs = static_cast<FormatSizeFlags>(static_cast<unsigned>(lhs) ^ static_cast<unsigned>(rhs))); }


/** @defgroup MiscUtils Miscellaneous Utility Functions
 * Miscellaneous Utility Functions -- a selection of portable utility functions.
 * @{
 */

/** Gets a human-readable name for the application,
 * as set by Glib::set_application_name().
 *
 * This name should be localized if possible, and is intended for display to
 * the user.  Contrast with Glib::get_prgname(), which gets a non-localized
 * name. If Glib::set_application_name() has not been called, returns the
 * result of Glib::get_prgname() (which may be empty if Glib::set_prgname()
 * has also not been called).
 *
 * @return Human-readable application name. May return <tt>""</tt>.
 */
GLIBMM_API
auto get_application_name() -> Glib::ustring;

/** Sets a human-readable name for the application.
 * This name should be localized if possible, and is intended for display to
 * the user.  Contrast with Glib::set_prgname(), which sets a non-localized
 * name.  Glib::set_prgname() will be called automatically by
 * <tt>gtk_init()</tt>, but Glib::set_application_name() will not.
 *
 * Note that for thread safety reasons, this function can only be called once.
 *
 * The application name will be used in contexts such as error messages,
 * or when displaying an application's name in the task list.
 *
 * @param application_name Localized name of the application.
 */
GLIBMM_API
void set_application_name(UStringView application_name);

/** Gets the name of the program.
 *
 * This name should not be localized, in contrast to get_application_name().
 *
 * If you are using GDK or GTK+ the program name is set in <tt>gdk_init()</tt>,
 * which is called by <tt>gtk_init()</tt> and therefore by the constructors of
 * Gtk::Main and Gtk::Application. The program name is found by taking the last
 * component of <tt>argv[0]</tt>.
 *
 * @return The name of the program.
 */
GLIBMM_API
auto get_prgname() -> std::string;

/** Sets the name of the program.
 * @param prgname The name of the program.
 */
GLIBMM_API
void set_prgname(StdStringView prgname);

/** Returns the value of an environment variable. The name and value
 * are in the GLib file name encoding. On Unix, this means the actual
 * bytes which might or might not be in some consistent character set
 * and encoding. On Windows, it is in UTF-8. On Windows, in case the
 * environment variable's value contains references to other
 * environment variables, they are expanded.
 *
 * @param variable The environment variable to get.
 * @param[out] found Whether the environment variable has been found.
 * @return The value of the environment variable, or <tt>""</tt> if not found.
 */
GLIBMM_API
auto getenv(StdStringView variable, bool& found) -> std::string;

/** Returns the value of an environment variable. The name and value
 * are in the GLib file name encoding. On Unix, this means the actual
 * bytes which might or might not be in some consistent character set
 * and encoding. On Windows, it is in UTF-8. On Windows, in case the
 * environment variable's value contains references to other
 * environment variables, they are expanded.
 *
 * @param variable The environment variable to get.
 * @return The value of the environment variable, or <tt>""</tt> if not found.
 */
GLIBMM_API
auto getenv(StdStringView variable) -> std::string;


/** Sets an environment variable. Both the variable's name and value
 * should be in the GLib file name encoding. On Unix, this means that
 * they can be any sequence of bytes. On Windows, they should be in
 * UTF-8.
 *
 * Note that on some systems, when variables are overwritten, the memory
 * used for the previous variables and its value isn't reclaimed.
 *
 * @param variable The environment variable to set. It must not contain '='.
 * @param value  The value to which the variable should be set.
 * @param overwrite Whether to change the variable if it already exists.
 * @result false if the environment variable couldn't be set.
 */
GLIBMM_API
auto setenv(StdStringView variable, StdStringView value, bool overwrite = true) -> bool;

/** Removes an environment variable from the environment.
 *
 * Note that on some systems, when variables are overwritten, the memory
 * used for the previous variables and its value isn't reclaimed.
 * Furthermore, this function can't be guaranteed to operate in a
 * threadsafe way.
 *
 * @param variable: the environment variable to remove. It  must not contain '='.
 **/
GLIBMM_API
void unsetenv(StdStringView variable);

/** Gets the names of all variables set in the environment.
 *
 * Programs that want to be portable to Windows should typically use this
 * function and getenv() instead of using the environ array from the C library
 * directly. On Windows, the strings in the environ array are in system
 * codepage encoding, while in most of the typical use cases for environment
 * variables in GLib-using programs you want the UTF-8 encoding that this
 * function and getenv() provide.
 *
 * @return Vector of environment names.
 */
GLIBMM_API
auto listenv() -> std::vector<std::string>;

/** Gets the user name of the current user.
 *
 * The encoding of the returned string is system-defined. On UNIX, it might be
 * the preferred file name encoding, or something else, and there is no
 * guarantee that it is ever consistent on a machine. On Windows, it is always
 * UTF-8.
 *
 * @return The name of the current user.
 */
GLIBMM_API
auto get_user_name() -> std::string;

/** Gets the real name of the current user.
 *
 * This usually comes from the user's entry in the <tt>passwd</tt> file. The
 * encoding of the returned string is subject to the same variability as noted
 * for get_user_name(). If the real user name cannot be determined, the string
 * "Unknown" is returned.
 *
 * @return The current user's real name.
 */
GLIBMM_API
auto get_real_name() -> std::string;

/** Return a name for the machine.
 *
 * The returned name is not necessarily a fully-qualified domain name,
 * or even present in DNS or some other name service at all. It need
 * not even be unique on your local network or site, but usually it
 * is. Callers should not rely on the return value having any specific
 * properties like uniqueness for security purposes. Even if the name
 * of the machine is changed while an application is running, the
 * return value from this function does not change. If no name can be
 * determined, a default fixed string "localhost" is returned.
 *
 * @return The host name of the machine.
 *
 * @newin{2,64}
 */
GLIBMM_API
auto get_host_name() -> Glib::ustring;

/** Gets the current user's home directory.
 * @return The current user's home directory or an empty string if not defined.
 */
GLIBMM_API
auto get_home_dir() -> std::string;

/** Gets the directory to use for temporary files.
 * This is found from inspecting the environment variables <tt>TMPDIR</tt>,
 * <tt>TMP</tt>, and <tt>TEMP</tt> in that order.  If none of those are defined
 * <tt>"/tmp"</tt> is returned on UNIX and <tt>"C:\\"</tt> on Windows.
 * @return The directory to use for temporary files.
 */
GLIBMM_API
auto get_tmp_dir() -> std::string;

/** Gets the current directory.
 * @return The current directory.
 */
GLIBMM_API
auto get_current_dir() -> std::string;

/** Returns the full path of a special directory using its logical id.
 *
 * On Unix this is done using the XDG special user directories.
 * For compatibility with existing practise, Glib::USER_DIRECTORY_DESKTOP
 * falls back to `$HOME/Desktop` when XDG special user directories have
 * not been set up.
 *
 * Depending on the platform, the user might be able to change the path
 * of the special directory without requiring the session to restart; GLib
 * will not reflect any change once the special directories are loaded.
 *
 * @param directory The logical id of special directory.
 * @return The path to the specified special directory, or an empty string
 *         if the logical id was not found.
 *
 * @newin{2,46}
 */
GLIBMM_API
auto get_user_special_dir(UserDirectory directory) -> std::string;

/** Returns a base directory in which to access application data such as icons
 * that is customized for a particular user.
 *
 * On UNIX platforms this is determined using the mechanisms described in the
 * XDG Base Directory Specification
 *
 * @newin{2,14}
 */
GLIBMM_API
auto get_user_data_dir() -> std::string;

/** Returns a base directory in which to store user-specific application
 * configuration information such as user preferences and settings.
 *
 * On UNIX platforms this is determined using the mechanisms described in the
 * XDG Base Directory Specification
 *
 * @newin{2,14}
 */
GLIBMM_API
auto get_user_config_dir() -> std::string;

/** Returns an ordered list of base directories in which to access system-wide application data.
 * On Unix platforms this is determined using the mechanisms described in the XDG Base Directory Specification.
 *
 * @newin{2,18}
 */
GLIBMM_API
auto get_system_data_dirs() -> std::vector<std::string>;

/** Returns an ordered list of base directories in which to access system-wide configuration information.
 * On Unix platforms this is determined using the mechanisms described in the XDG Base Directory Specification.
 *
 * @newin{2,18}
 */
GLIBMM_API
auto get_system_config_dirs() -> std::vector<std::string>;

/** Returns a base directory in which to store non-essential, cached data
 * specific to particular user.
 *
 * On UNIX platforms this is determined using the mechanisms described in the
 * XDG Base Directory Specification
 *
 * @newin{2,14}
 */
GLIBMM_API
auto get_user_cache_dir() -> std::string;

/** Returns a directory that is unique to the current user on the local system.
 *
 * This is the directory specified in the XDG_RUNTIME_DIR environment variable.
 * In the case that this variable is not set, we return the value of
 * Glib::get_user_cache_dir(), after verifying that it exists.
 *
 * @newin{2,64}
 */
GLIBMM_API
auto get_user_runtime_dir() -> std::string;

/** Returns @c true if the given @a filename is an absolute file name, i.e.\ it
 * contains a full path from the root directory such as <tt>"/usr/local"</tt>
 * on UNIX or <tt>"C:\\windows"</tt> on Windows systems.
 * @param filename A file name.
 * @return Whether @a filename is an absolute path.
 */
GLIBMM_API
auto path_is_absolute(StdStringView filename) -> bool;

/** Returns the remaining part of @a filename after the root component,
 * i.e.\ after the <tt>"/"</tt> on UNIX or <tt>"C:\\"</tt> on Windows.
 * If @a filename is not an absolute path, <tt>""</tt> will be returned.
 * @param filename A file name.
 * @return The file name without the root component, or <tt>""</tt>.
 */
GLIBMM_API
auto path_skip_root(StdStringView filename) -> std::string;

/** Gets the name of the file without any leading directory components.
 * @param filename The name of the file.
 * @return The name of the file without any leading directory components.
 */
GLIBMM_API
auto path_get_basename(StdStringView filename) -> std::string;

/** Gets the directory components of a file name.
 * If the file name has no directory components <tt>"."</tt> is returned.
 * @param filename The name of the file.
 * @return The directory components of the file.
 */
GLIBMM_API
auto path_get_dirname(StdStringView filename) -> std::string;

/** Gets the canonical file name from @a filename.
 *
 * All triple slashes are turned into single slashes, and all `..` and `.`s
 * resolved against @a relative_to.
 *
 * Symlinks are not followed, and the returned path is guaranteed to be absolute.
 *
 * If @a filename is an absolute path, @a relative_to is ignored. Otherwise,
 * @a relative_to will be prepended to @a filename to make it absolute. @a relative_to
 * must be an absolute path, or <tt>nullptr</tt>. If @a relative_to is <tt>nullptr</tt>,
 * it'll fallback to get_current_dir().
 *
 * This function never fails, and will canonicalize file paths even if they don't exist.
 *
 * No file system I/O is done.
 *
 * @param filename The name of the file.
 * @param relative_to The relative directory, or <tt>nullptr</tt> to use the
 *                    current working directory.
 * @return The canonical file path.
 *
 * @newin{2,64}
 */
GLIBMM_API
auto canonicalize_filename(StdStringView filename, StdStringView relative_to = nullptr) -> std::string;

/** Creates a filename from a series of elements using the correct
 * separator for filenames.
 * This function behaves identically to Glib::build_path(G_DIR_SEPARATOR_S,
 * elements).  No attempt is made to force the resulting filename to be an
 * absolute path.  If the first element is a relative path, the result will
 * be a relative path.
 * @param elements A vector holding the elements of the path to build.
 * @return The resulting path.
 */
GLIBMM_API
auto build_filename(const std::vector<std::string>&  elements) -> std::string;

/** Creates a filename from one or more elements using the correct separator for filenames.
 * No attempt is made to force the resulting filename to be an absolute path.
 * If the first element is a relative path, the result will be a relative path.
 * @tparam Strings std::string or const char*.
 * @param strings The path elements.
 * @return The resulting path.
 */
template <typename... Strings>
auto build_filename(const Strings&... strings) -> std::string
{
  return Glib::convert_return_gchar_ptr_to_stdstring(
    g_build_filename(StdStringView(strings).c_str()..., nullptr));
}

/** Creates a path from a series of elements using @a separator as the
 * separator between elements.
 *
 * At the boundary between two elements, any trailing occurrences of
 * @a separator in the first element, or leading occurrences of @a separator
 * in the second element are removed and exactly one copy of the separator is
 * inserted.
 *
 * Empty elements are ignored.
 *
 * The number of leading copies of the separator on the result is
 * the same as the number of leading copies of the separator on
 * the first non-empty element.
 *
 * The number of trailing copies of the separator on the result is the same
 * as the number of trailing copies of the separator on the last non-empty
 * element. (Determination of the number of trailing copies is done without
 * stripping leading copies, so if the separator is <tt>"ABA"</tt>,
 * <tt>"ABABA"</tt> has 1 trailing copy.)
 *
 * However, if there is only a single non-empty element, and there
 * are no characters in that element not part of the leading or
 * trailing separators, then the result is exactly the original value
 * of that element.
 *
 * Other than for determination of the number of leading and trailing
 * copies of the separator, elements consisting only of copies
 * of the separator are ignored.
 *
 * @param separator A string used to separate the elements of the path.
 * @param elements A vector holding the elements of the path to build.
 * @return The resulting path.
 */
GLIBMM_API
auto build_path(const std::string& separator,
                       const std::vector<std::string>&  elements) -> std::string;

/** Locates the first executable named @a program in the user's path, in the
 * same way that <tt>execvp()</tt> would locate it.
 * Returns a string with the absolute path name, or <tt>""</tt> if the program
 * is not found in the path.  If @a program is already an absolute path,
 * returns a copy of @a program if @a program exists and is executable, and
 * <tt>""</tt> otherwise.
 *
 * On Windows, if @a program does not have a file type suffix, tries to append
 * the suffixes in the <tt>PATHEXT</tt> environment variable (if that doesn't
 * exist, the suffixes .com, .exe, and .bat) in turn, and then look for the
 * resulting file name in the same way as CreateProcess() would.  This means
 * first in the directory where the program was loaded from, then in the
 * current directory, then in the Windows 32-bit system directory, then in the
 * Windows directory, and finally in the directories in the <tt>PATH</tt>
 * environment variable.  If the program is found, the return value contains
 * the full name including the type suffix.
 *
 * @param program A program name.
 * @return An absolute path, or <tt>""</tt>.
 */
GLIBMM_API
auto find_program_in_path(StdStringView program) -> std::string;

/** Formats a size (for example the size of a file) into a human readable string.
 *
 * Sizes are rounded to the nearest size prefix (kB, MB, GB)
 * and are displayed rounded to the nearest tenth. E.g. the file size
 * 3292528 bytes will be converted into the string "3.2 MB".
 *
 * The prefix units base is 1000 (i.e. 1 kB is 1000 bytes), unless the
 * Glib::FormatSizeFlags::IEC_UNITS flag is set.
 *
 * @param size A size in bytes.
 * @param flags Flags to modify the output.
 * @return A formatted string containing a human readable file size.
 *
 * @newin{2,46}
 */
GLIBMM_API
auto format_size(guint64 size, FormatSizeFlags flags = FormatSizeFlags::DEFAULT) -> Glib::ustring;

/** @} group MiscUtils */

} // namespace Glib


#endif /* _GLIBMM_MISCUTILS_H */

