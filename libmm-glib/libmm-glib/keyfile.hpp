
#ifndef _GLIBMM_KEYFILE_H
#define _GLIBMM_KEYFILE_H


/* Copyright(C) 2006 The gtkmm Development Team
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
 * License along with this library.  If not, see <http://www.gnu.org/licenses/>.
 */


#include <mm/glib/mm-glibconfig.hpp>
#include <mm/glib/ustring.hpp>
#include <mm/glib/error.hpp>
#include <mm/glib/utility.hpp>
#include <mm/glib/refptr.hpp>
#include <glib.h>
#include <vector>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
extern "C" { typedef struct _GKeyFile GKeyFile; }
#endif

namespace Glib
{

/**  %Exception class for KeyFile errors.
 */
class KeyFileError : public Glib::Error
{
public:
  /**  @var Code UNKNOWN_ENCODING
   * The text being parsed was in
   * an unknown encoding.
   *
   *  @var Code PARSE
   * Document was ill-formed.
   *
   *  @var Code NOT_FOUND
   * The file was not found.
   *
   *  @var Code KEY_NOT_FOUND
   * A requested key was not found.
   *
   *  @var Code GROUP_NOT_FOUND
   * A requested group was not found.
   *
   *  @var Code INVALID_VALUE
   * A value could not be parsed.
   *
   *  @enum Code
   *
   * %Error codes returned by key file parsing.
   */
  enum Code
  {
    UNKNOWN_ENCODING,
    PARSE,
    NOT_FOUND,
    KEY_NOT_FOUND,
    GROUP_NOT_FOUND,
    INVALID_VALUE
  };

  GLIBMM_API KeyFileError(Code error_code, const Glib::ustring& error_message);
  GLIBMM_API explicit KeyFileError(GError* gobject);
  GLIBMM_API auto code() const -> Code;

#ifndef DOXYGEN_SHOULD_SKIP_THIS
private:

  GLIBMM_API static void throw_func(GError* gobject);

  friend GLIBMM_API void wrap_init(); // uses throw_func()

  #endif //DOXYGEN_SHOULD_SKIP_THIS
};


/** This class lets you parse, edit or create files containing groups of key-value pairs, which we call key files
 * for lack of a better name. Several freedesktop.org specifications use key files now, e.g the Desktop Entry
 * Specification and the Icon Theme Specification.
 *
 * The syntax of key files is described in detail in the Desktop Entry Specification, here is a quick summary: Key
 * files consists of groups of key-value pairs, interspersed with comments.
 *
 * @code
 * # this is just an example
 * # there can be comments before the first group
 *
 * [First Group]
 *
 * Name=Key File Example\tthis value shows\nescaping
 *
 * # localized strings are stored in multiple key-value pairs
 * Welcome=Hello
 * Welcome[de]=Hallo
 * Welcome[fr]=Bonjour
 * Welcome[it]=Ciao
 *
 * [Another Group]
 *
 * Numbers=2;20;-200;0
 *
 * Booleans=true;false;true;true
 * @endcode
 *
 * Lines beginning with a '#' and blank lines are considered comments.
 *
 * Groups are started by a header line containing the group name enclosed in '[' and ']', and ended implicitly by
 * the start of the next group or the end of the file. Each key-value pair must be contained in a group.
 *
 * Key-value pairs generally have the form key=value, with the exception of localized strings, which have the form
 * key[locale]=value. Space before and after the '=' character are ignored. Newline, tab, carriage return and
 * backslash characters in value are escaped as \\n, \\t, \\r, and \\\\, respectively. To preserve leading spaces in
 * values, these can also be escaped as \\s.
 *
 * Key files can store strings (possibly with localized variants), integers, booleans and lists of these. Lists are
 * separated by a separator character, typically ';' or ','. To use the list separator character in a value in a
 * list, it has to be escaped by prefixing it with a backslash.
 *
 * This syntax is obviously inspired by the .ini files commonly met on Windows, but there are some important
 * differences:
 * - .ini files use the ';' character to begin comments, key files use the '#' character.
 * - Key files allow only comments before the first group.
 * - Key files are always encoded in UTF-8.
 * - Key and Group names are case-sensitive, for example a group called [GROUP] is a different group from [group].
 *
 * Note that in contrast to the Desktop Entry Specification, groups in key files may contain the same key multiple
 * times; the last entry wins. Key files may also contain multiple groups with the same name; they are merged
 * together. Another difference is that keys and group names in key files are not restricted to ASCII characters.
 *
 * @newin{2,14}
 */
class GLIBMM_API KeyFile final
{
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  using CppObjectType = KeyFile;
  using BaseObjectType = GKeyFile;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

  static auto create() -> Glib::RefPtr<KeyFile>;

  /** Increment the reference count for this object.
   * You should never need to do this manually - use the object via a RefPtr instead.
   */
  void reference()   const;

  /** Decrement the reference count for this object.
   * You should never need to do this manually - use the object via a RefPtr instead.
   */
  void unreference() const;

  ///Provides access to the underlying C instance.
  auto       gobj() -> GKeyFile*;

  ///Provides access to the underlying C instance.
  auto gobj() const -> const GKeyFile*;

  ///Provides access to the underlying C instance. The caller is responsible for unrefing it. Use when directly setting fields in structs.
  auto gobj_copy() const -> GKeyFile*;

  KeyFile() = delete;

  // noncopyable
  KeyFile(const KeyFile&) = delete;
  auto operator=(const KeyFile&) -> KeyFile& = delete;

protected:
  // Do not derive this.  Glib::KeyFile can neither be constructed nor deleted.

  void operator delete(void*, std::size_t);

private:


public:

  /** @addtogroup glibmmEnums glibmm Enums and Flags */

  /**
   *  @var Flags NONE
   * No flags, default behaviour.
   *
   *  @var Flags KEEP_COMMENTS
   * Use this flag if you plan to write the
   * (possibly modified) contents of the key file back to a file;
   * otherwise all comments will be lost when the key file is
   * written back.
   *
   *  @var Flags KEEP_TRANSLATIONS
   * Use this flag if you plan to write the
   * (possibly modified) contents of the key file back to a file;
   * otherwise only the translations for the current language will be
   * written back.
   *
   *  @enum Flags
   *
   * Flags which influence the parsing.
   *
   * @ingroup glibmmEnums
   * @par Bitwise operators:
   * <tt>KeyFile::Flags operator|(KeyFile::Flags, KeyFile::Flags)</tt><br>
   * <tt>KeyFile::Flags operator&(KeyFile::Flags, KeyFile::Flags)</tt><br>
   * <tt>KeyFile::Flags operator^(KeyFile::Flags, KeyFile::Flags)</tt><br>
   * <tt>KeyFile::Flags operator~(KeyFile::Flags)</tt><br>
   * <tt>KeyFile::Flags& operator|=(KeyFile::Flags&, KeyFile::Flags)</tt><br>
   * <tt>KeyFile::Flags& operator&=(KeyFile::Flags&, KeyFile::Flags)</tt><br>
   * <tt>KeyFile::Flags& operator^=(KeyFile::Flags&, KeyFile::Flags)</tt><br>
   */
  enum class Flags
  {
    NONE = 0x0,
    KEEP_COMMENTS = 1 << 0,
    KEEP_TRANSLATIONS = 1 << 1
  };


  //TODO: Maybe replace all the get_*/set_* methods with some generic get/set
  //methods when it is possible.


  /** Loads a key file into an empty KeyFile instance.
   * If the file could not be loaded then a FileError or KeyFileError exception is thrown.
   *
   * @newin{2,6}
   *
   * \throw Glib::FileError
   * \throw Glib::KeyFileError
   *
   * @param file The path of a filename to load, in the GLib filename encoding.
   * @param flags Flags from Glib::KeyFile::Flags.
   * @return <tt>true</tt> if a key file could be loaded, <tt>false</tt> otherwise.
   */
  auto load_from_file(const std::string& file, Flags flags =  Flags::NONE) -> bool;

  /** Loads a KeyFile from memory
   * @param data The data to use as a KeyFile
   * @param flags Bitwise combination of the flags to use for the KeyFile
   * @return true if the KeyFile was successfully loaded, false otherwise
   * @throw Glib::KeyFileError
   */
  auto load_from_data(const Glib::ustring& data, Flags flags = Flags::NONE) -> bool;


  /** This function looks for a key file named @a file in the paths
   * specified in @a search_dirs, loads the file into @a key_file and
   * returns the file's full path in @a full_path.
   *
   * If the file could not be found in any of the @a search_dirs,
   * Glib::KeyFileError::NOT_FOUND is returned. If
   * the file is found but the OS returns an error when opening or reading the
   * file, a Glib::FileError is returned. If there is a problem parsing the file, a
   * Glib::KeyFileError is returned.
   *
   * @newin{2,14}
   *
   * @param file A relative path to a filename to open and parse.
   * @param search_dirs <tt>nullptr</tt>-terminated array of directories to search.
   * @param full_path Return location for a string containing the full path
   * of the file, or <tt>nullptr</tt>.
   * @param flags Flags from Glib::KeyFile::Flags.
   * @return <tt>true</tt> if a key file could be loaded, <tt>false</tt> otherwise.
   *
   * @throws Glib::KeyFileError
   * @throws Glib::FileError
   */

  auto load_from_dirs(const std::string& file, const std::vector<std::string>&  search_dirs, std::string& full_path, Flags flags = Flags::NONE) -> bool;

  /** Looks for a KeyFile named @a file in the paths returned from
   * g_get_user_data_dir() and g_get_system_data_dirs() and loads them
   * into the keyfile object, placing the full path to the file in
   * @a full_path.
   * @param file The file to search for
   * @param[out] full_path Return location for a string containing the full path of the file
   * @param flags Bitwise combination of the flags to use for the KeyFile
   * @return true if the KeyFile was successfully loaded, false otherwise
   * @throw Glib::KeyFileError
   * @throw Glib::FileError
   */
  auto load_from_data_dirs(const std::string& file, std::string& full_path, Flags flags = Flags::NONE) -> bool;


  /** Outputs the KeyFile as a string
   * @return A string object holding the contents of KeyFile
   * @throw Glib::KeyFileError
   */
  auto to_data() -> Glib::ustring;


  /** Writes the contents of @a key_file to @a filename using
   * g_file_set_contents(). If you need stricter guarantees about durability of
   * the written file than are provided by g_file_set_contents(), use
   * g_file_set_contents_full() with the return value of g_key_file_to_data().
   *
   * This function can fail for any of the reasons that
   * g_file_set_contents() may fail.
   *
   * @newin{2,40}
   *
   * @param filename The name of the file to write to.
   * @return <tt>true</tt> if successful, else <tt>false</tt> with @a error set.
   *
   * @throws Glib::FileError
   */
  auto save_to_file(const std::string& filename) -> bool;


  /** Returns the name of the start group of the file.
   *
   * @newin{2,6}
   *
   * @return The start group of the key file.
   */
  auto get_start_group() const -> Glib::ustring;

  /** Gets a list of all groups in the KeyFile
   * @returns A list containing the names of the groups
   */
  auto get_groups() const -> std::vector<Glib::ustring>;


  /** Gets a list of all keys from the group @a group_name.
   * @param group_name The name of a group
   * @returns A list containing the names of the keys in @a group_name
   * @throw Glib::KeyFileError
   */
  auto get_keys(const Glib::ustring& group_name) const -> std::vector<Glib::ustring>;


  /** Looks whether the key file has the group @a group_name.
   *
   * @newin{2,6}
   *
   * @param group_name A group name.
   * @return <tt>true</tt> if @a group_name is a part of @a key_file, <tt>false</tt>
   * otherwise.
   */
  auto has_group(const Glib::ustring& group_name) const -> bool;

  /** Looks whether the key file has the key @a key in the group
   *  @a group_name.
   *
   * @newin{2,6}
   *
   * \throw Glib::KeyFileError
   *
   * @param group_name A group name.
   * @param key A key name.
   * @return <tt>true</tt> if @a key is a part of @a group_name, <tt>false</tt> otherwise.
   */
  auto has_key(const Glib::ustring& group_name, const Glib::ustring& key) const -> bool;


  /** Returns the value associated with @a key under @a group_name.
   *
   * @newin{2,6}
   *
   * \throw Glib::KeyFileError in the event the key cannot be found (with the Glib::KeyFileError::KEY_NOT_FOUND code).
   * \throw Glib::KeyFileError in the event that the @a group_name cannot be found (with the Glib::KeyFileError::GROUP_NOT_FOUND code).
   *
   * @param group_name A group name.
   * @param key A key.
   * @return The value as a string.
   */
  auto get_value(const Glib::ustring& group_name, const Glib::ustring& key) const -> Glib::ustring;

  /** Return value: a newly allocated string or <tt>nullptr</tt>.
   *
   * @newin{2,6}
   *
   * \throw Glib::KeyFileError
   *
   * @param group_name A group name.
   * @param key A key.
   * @return A newly allocated string or <tt>nullptr</tt> if the specified
   * key cannot be found.
   */
  auto get_string(const Glib::ustring& group_name, const Glib::ustring& key) const -> Glib::ustring;


  /** Returns the actual locale which the result of
   * g_key_file_get_locale_string() or g_key_file_get_locale_string_list()
   * came from.
   *
   * If calling g_key_file_get_locale_string() or
   * g_key_file_get_locale_string_list() with exactly the same @a key_file,
   *  @a group_name, @a key and @a locale, the result of those functions will
   * have originally been tagged with the locale that is the result of
   * this function.
   *
   * @newin{2,60}
   *
   * @param group_name A group name.
   * @param key A key.
   * @param locale A locale identifier or <tt>nullptr</tt>.
   * @return The locale from the file, or <tt>nullptr</tt> if the key was not
   * found or the entry in the file was was untranslated.
   */
  auto get_locale_for_key(const Glib::ustring& group_name, const Glib::ustring& key, const Glib::ustring& locale =  {}) const -> Glib::ustring;

  /** Gets the value associated with @a key under @a group_name translated
   * into the current locale.
   * @return the value as a Glib::ustring
   * @throw Glib::KeyFileError
  */
  auto get_locale_string(const Glib::ustring& group_name, const Glib::ustring& key) const -> Glib::ustring;


  /** Return value: a newly allocated string or <tt>nullptr</tt>.
   *
   * @newin{2,6}
   *
   * \throw Glib::KeyFileError
   *
   * @param group_name A group name.
   * @param key A key.
   * @param locale A locale identifier or <tt>nullptr</tt>.
   * @return A newly allocated string or <tt>nullptr</tt> if the specified
   * key cannot be found.
   */
  auto get_locale_string(const Glib::ustring& group_name, const Glib::ustring& key, const Glib::ustring& locale) const -> Glib::ustring;

  /** Gets the value in the first group, under @a key, interpreting it as
   * a boolean.
   * @param key The name of the key.
   * @return The value of @a key as a boolean.
   * @throw Glib::KeyFileError.
   * @newin{2,6}
   */
  auto get_boolean(const Glib::ustring& key) const -> bool;


  /** Return value: the value associated with the key as a boolean.
   *
   * @newin{2,6}
   *
   * \throw Glib::KeyFileError
   *
   * @param group_name A group name.
   * @param key A key.
   * @return The value associated with the key as a boolean,
   * or <tt>false</tt> if the key was not found or could not be parsed.
   */
  auto get_boolean(const Glib::ustring& group_name, const Glib::ustring& key) const -> bool;

  /** Gets the value in the first group, under @a key, interpreting it as
   * an integer.
   * @param key The name of the key
   * @return The value of @a key as an integer
   * @throw Glib::KeyFileError
   * @newin{2,6}
   */
  auto get_integer(const Glib::ustring& key) const -> int;


  /** Return value: the value associated with the key as an integer.
   *
   * @newin{2,6}
   *
   * \throw Glib::KeyFileError
   *
   * @param group_name A group name.
   * @param key A key.
   * @return The value associated with the key as an integer, or
   * 0 if the key was not found or could not be parsed.
   */
  auto get_integer(const Glib::ustring& group_name, const Glib::ustring& key) const -> int;

  /** Gets the value in the first group, under @a key, interpreting it as
   * a signed 64-bit integer. This is similar to get_integer() but can return
   * 64-bit results without truncation.
   * @param key The name of the key.
   * @return The value of @a key as a signed 64-bit integer, or <tt>0</tt> if
   * the key was not found or could not be parsed.
   * @throw Glib::KeyFileError.
   * @newin{2,28}
   */
  auto get_int64(const Glib::ustring& key) const -> gint64;


  /** Returns the value associated with @a key under @a group_name as a signed
   * 64-bit integer. This is similar to g_key_file_get_integer() but can return
   * 64-bit results without truncation.
   *
   * @newin{2,26}
   *
   * @param group_name A non-<tt>nullptr</tt> group name.
   * @param key A non-<tt>nullptr</tt> key.
   * @return The value associated with the key as a signed 64-bit integer, or
   * 0 if the key was not found or could not be parsed.
   *
   * @throws Glib::KeyFileError
   */
  auto get_int64(const Glib::ustring& group_name, const Glib::ustring& key) const -> gint64;

  /** Gets the value in the first group, under @a key, interpreting it as
   * an unsigned 64-bit integer. This is similar to get_integer() but can
   * return large positive results without truncation.
   * @param key The name of the key.
   * @return The value of @a key as an unsigned 64-bit integer, or <tt>0</tt>
   * if the key was not found or could not be parsed.
   * @throw Glib::KeyFileError.
   * @newin{2,28}
   */
  auto get_uint64(const Glib::ustring& key) const -> guint64;


  /** Returns the value associated with @a key under @a group_name as an unsigned
   * 64-bit integer. This is similar to g_key_file_get_integer() but can return
   * large positive results without truncation.
   *
   * @newin{2,26}
   *
   * @param group_name A non-<tt>nullptr</tt> group name.
   * @param key A non-<tt>nullptr</tt> key.
   * @return The value associated with the key as an unsigned 64-bit integer,
   * or 0 if the key was not found or could not be parsed.
   *
   * @throws Glib::KeyFileError
   */
  auto get_uint64(const Glib::ustring& group_name, const Glib::ustring& key) const -> guint64;

  /** Gets the value in the first group, under @a key, interpreting it as
   * a double.
   * @param key The name of the key
   * @return The value of @a key as an double
   * @throw Glib::KeyFileError
   *
   * @newin{2,14}
   */
  auto get_double(const Glib::ustring& key) const -> double;


  /** Return value: the value associated with the key as a double.
   *
   * @newin{2,14}
   *
   * \throw Glib::KeyFileError
   *
   * @param group_name A group name.
   * @param key A key.
   * @return The value associated with the key as a double, or
   * 0.0 if the key was not found or could not be parsed.
   */
  auto get_double(const Glib::ustring& group_name, const Glib::ustring& key) const -> double;


  /** Associates a new double value with @a key under @a group_name.
   * If @a key cannot be found then it is created.
   *
   * @newin{2,12}
   *
   * @param group_name A group name.
   * @param key A key.
   * @param value A double value.
   */
  void set_double(const Glib::ustring& group_name, const Glib::ustring& key, double value);

  /** Associates a new double value with @a key under the start group.
   * If @a key  cannot be found then it is created.
   *
   * @newin{2,12}
   *
   * @param key A key.
   * @param value An double value.
   */
  void set_double(const Glib::ustring& key, double value);

  /** Returns the values associated with @a key under @a group_name
   * @param group_name The name of a group
   * @param key The name of a key
   * @return A list containing the values requested
   * @throw Glib::KeyFileError
   */
  auto get_string_list(const Glib::ustring& group_name, const Glib::ustring& key) const -> std::vector<Glib::ustring>;


  /** Returns the values associated with @a key under @a group_name
   * translated into the current locale, if available.
   * @param group_name The name of a group
   * @param key The name of a key
   * @return A list containing the values requested
   * @throw Glib::KeyFileError
   */
  auto get_locale_string_list(const Glib::ustring& group_name, const Glib::ustring& key) const -> std::vector<Glib::ustring>;

  /** Returns the values associated with @a key under @a group_name
   * translated into @a locale, if available.
   * @param group_name The name of a group
   * @param key The name of a key
   * @param locale The name of a locale
   * @return A list containing the values requested
   * @throw Glib::KeyFileError
   */
  auto get_locale_string_list(const Glib::ustring& group_name, const Glib::ustring& key, const Glib::ustring& locale) const -> std::vector<Glib::ustring>;


  /** Returns the values associated with @a key under @a group_name
   * @param group_name The name of a group
   * @param key The name of a key
   * @return A list of booleans
   * @throw Glib::KeyFileError
   */
  auto get_boolean_list(const Glib::ustring& group_name, const Glib::ustring& key) const -> std::vector<bool>;


  /** Returns the values associated with @a key under @a group_name
   * @param group_name The name of a group
   * @param key The name of a key
   * @return A list of integers
   * @throw Glib::KeyFileError
   */
  auto get_integer_list(const Glib::ustring& group_name, const Glib::ustring& key) const -> std::vector<int>;


  /** Returns the values associated with @a key under @a group_name
   * @param group_name The name of a group
   * @param key The name of a key
   * @return A list of doubles
   * @throw Glib::KeyFileError
   */
  auto get_double_list(const Glib::ustring& group_name, const Glib::ustring& key) const -> std::vector<double>;


  /** Get comment from top of file
   * @return The comment
   * @throw Glib::KeyFileError
   */
  auto get_comment() const -> Glib::ustring;

  /** Get comment from above a group
   * @param group_name The group
   * @return The comment
   * @throw Glib::KeyFileError
   */
  auto get_comment(const Glib::ustring& group_name) const -> Glib::ustring;


  /** Retrieves a comment above @a key from @a group_name.
   * If @a key is <tt>nullptr</tt> then @a comment will be read from above
   *  @a group_name. If both @a key and @a group_name are <tt>nullptr</tt>, then
   *  @a comment will be read from above the first group in the file.
   * Use the overrides for a <tt>nullptr</tt> @a key or @a group.
   *
   * @newin{2,6}
   *
   * \throw Glib::KeyFileError
   *
   * @param group_name A group name.
   * @param key A key.
   * @return The comment.
   */
  auto get_comment(const Glib::ustring& group_name, const Glib::ustring& key) const -> Glib::ustring;


  /** Sets the character which is used to separate
   * values in lists. Typically ';' or ',' are used
   * as separators. The default list separator is ';'.
   *
   * @newin{2,6}
   *
   * @param separator The separator.
   */
  void set_list_separator(gchar separator);

  /** Associates a new value with @a key under @a group_name.
   *
   * If @a key cannot be found then it is created. If @a group_name cannot
   * be found then it is created. To set an UTF-8 string which may contain
   * characters that need escaping (such as newlines or spaces), use
   * g_key_file_set_string().
   *
   * @newin{2,6}
   *
   * @param group_name A group name.
   * @param key A key.
   * @param value A string.
   */
  void set_value(const Glib::ustring& group_name, const Glib::ustring& key, const Glib::ustring& value);

  /** Associates a new string value with @a key under @a group_name.
   * If @a key cannot be found then it is created.
   * If @a group_name cannot be found then it is created.
   * Unlike g_key_file_set_value(), this function handles characters
   * that need escaping, such as newlines.
   *
   * @newin{2,6}
   *
   * @param group_name A group name.
   * @param key A key.
   * @param string A string.
   */
  void set_string(const Glib::ustring& group_name, const Glib::ustring& key, const Glib::ustring& string);

  /** Associates a string value for @a key and @a locale under @a group_name.
   * If the translation for @a key cannot be found then it is created.
   *
   * @newin{2,6}
   *
   * @param group_name A group name.
   * @param key A key.
   * @param locale A locale identifier.
   * @param string A string.
   */
  void set_locale_string(const Glib::ustring& group_name, const Glib::ustring& key, const Glib::ustring& locale, const Glib::ustring& string);

  /** Associates a new boolean value with @a key under @a group_name.
   * If @a key cannot be found then it is created.
   *
   * @newin{2,6}
   *
   * @param group_name A group name.
   * @param key A key.
   * @param value <tt>true</tt> or <tt>false</tt>.
   */
  void set_boolean(const Glib::ustring& group_name, const Glib::ustring& key, bool value);

  /** Associates a new integer value with @a key under @a group_name.
   * If @a key cannot be found then it is created.
   *
   * @newin{2,6}
   *
   * @param group_name A group name.
   * @param key A key.
   * @param value An integer value.
   */
  void set_integer(const Glib::ustring& group_name, const Glib::ustring& key, int value);

  /** Associates a new integer value with @a key under @a group_name.
   * If @a key cannot be found then it is created.
   *
   * @newin{2,26}
   *
   * @param group_name A group name.
   * @param key A key.
   * @param value An integer value.
   */
  void set_int64(const Glib::ustring& group_name, const Glib::ustring& key, gint64 value);

  /** Associates a new integer value with @a key under @a group_name.
   * If @a key cannot be found then it is created.
   *
   * @newin{2,26}
   *
   * @param group_name A group name.
   * @param key A key.
   * @param value An integer value.
   */
  void set_uint64(const Glib::ustring& group_name, const Glib::ustring& key, guint64 value);

  /** Sets a list of string values for @a key under @a group_name. If
   * key cannot be found it is created. If @a group_name cannot be found
   * it is created.
   * @param group_name The name of a group
   * @param key The name of a key
   * @param list A list holding objects of type Glib::ustring
   */
  void set_string_list(const Glib::ustring& group_name, const Glib::ustring& key, const std::vector<Glib::ustring>&  list);


  /** Sets a list of string values for the @a key under @a group_name and marks
   * them as being for @a locale. If the @a key or @a group_name cannot be
   * found, they are created.
   * @param group_name The name of a group
   * @param key The name of a key
   * @param locale A locale
   * @param list A list holding objects of type Glib::ustring
   */
  void set_locale_string_list(const Glib::ustring& group_name, const Glib::ustring& key, const Glib::ustring& locale, const std::vector<Glib::ustring>&  list);


  /** Sets a list of booleans for the @a key under @a group_name.
   * If either the @a key or @a group_name cannot be found they are created.
   * @param group_name The name of a group
   * @param key The name of a key
   * @param list A list holding object of type bool
   */
  void set_boolean_list(const Glib::ustring& group_name, const Glib::ustring& key, const std::vector<bool>&  list);


  /** Sets a list of integers for the @a key under @a group_name.
   * If either the @a key or @a group_name cannot be found they are created.
   * @param group_name The name of a group
   * @param key The name of a key
   * @param list A list holding object of type int
   */
  void set_integer_list(const Glib::ustring& group_name, const Glib::ustring& key, const std::vector<int>&  list);


  /** Sets a list of doubles for the @a key under @a group_name.
   * If either the @a key or @a group_name cannot be found they are created.
   * @param group_name The name of a group
   * @param key The name of a key
   * @param list A list holding object of type int
   *
   * @newin{2,14}
   */
  void set_double_list(const Glib::ustring& group_name, const Glib::ustring& key, const std::vector<double>&  list);


  /** Places @a comment at the start of the file, before the first group.
   * @param comment The Comment
   * @throw Glib::KeyFileError
   */
  void set_comment(const Glib::ustring& comment);

  /** Places @a comment above @a group_name.
   * @param group_name The Group the comment should be above
   * @param comment The comment
   * @throw Glib::KeyFileError
   */
  void set_comment(const Glib::ustring& group_name, const Glib::ustring& comment);


  /** Places a comment above @a key from @a group_name.
   * If @a key is <tt>nullptr</tt> then @a comment will be written above @a group_name.
   * If both @a key and @a group_name  are <tt>nullptr</tt>, then @a comment will be
   * written above the first group in the file.
   *
   * \throw Glib::KeyFileError
   *
   * @param group_name A group name, or <tt>nullptr</tt>.
   * @param key A key.
   * @param comment A comment.
   */
  void set_comment(const Glib::ustring& group_name, const Glib::ustring& key, const Glib::ustring& comment);


  /** Removes a comment above @a key from @a group_name.
   * If @a key is <tt>nullptr</tt> then @a comment will be removed above @a group_name.
   * If both @a key and @a group_name are <tt>nullptr</tt>, then @a comment will
   * be removed above the first group in the file.
   *
   * \throw Glib::KeyFileError
   *
   * @param group_name A group name, or <tt>nullptr</tt>.
   * @param key A key.
   */
  void remove_comment(const Glib::ustring& group_name, const Glib::ustring& key);

  /** Removes @a key in @a group_name from the key file.
   *
   * \throw Glib::KeyFileError
   *
   * @param group_name A group name.
   * @param key A key name to remove.
   */
  void remove_key(const Glib::ustring& group_name, const Glib::ustring& key);

  /** Removes the specified group, @a group_name,
   * from the key file.
   *
   * \throw Glib::KeyFileError
   *
   * @param group_name A group name.
   */
  void remove_group(const Glib::ustring& group_name);


};

} // namespace Glib

namespace Glib
{

/** @ingroup glibmmEnums */
inline auto operator|(KeyFile::Flags lhs, KeyFile::Flags rhs) -> KeyFile::Flags
  { return static_cast<KeyFile::Flags>(static_cast<unsigned>(lhs) | static_cast<unsigned>(rhs)); }

/** @ingroup glibmmEnums */
inline auto operator&(KeyFile::Flags lhs, KeyFile::Flags rhs) -> KeyFile::Flags
  { return static_cast<KeyFile::Flags>(static_cast<unsigned>(lhs) & static_cast<unsigned>(rhs)); }

/** @ingroup glibmmEnums */
inline auto operator^(KeyFile::Flags lhs, KeyFile::Flags rhs) -> KeyFile::Flags
  { return static_cast<KeyFile::Flags>(static_cast<unsigned>(lhs) ^ static_cast<unsigned>(rhs)); }

/** @ingroup glibmmEnums */
inline auto operator~(KeyFile::Flags flags) -> KeyFile::Flags
  { return static_cast<KeyFile::Flags>(~static_cast<unsigned>(flags)); }

/** @ingroup glibmmEnums */
inline auto operator|=(KeyFile::Flags& lhs, KeyFile::Flags rhs) -> KeyFile::Flags&
  { return (lhs = static_cast<KeyFile::Flags>(static_cast<unsigned>(lhs) | static_cast<unsigned>(rhs))); }

/** @ingroup glibmmEnums */
inline auto operator&=(KeyFile::Flags& lhs, KeyFile::Flags rhs) -> KeyFile::Flags&
  { return (lhs = static_cast<KeyFile::Flags>(static_cast<unsigned>(lhs) & static_cast<unsigned>(rhs))); }

/** @ingroup glibmmEnums */
inline auto operator^=(KeyFile::Flags& lhs, KeyFile::Flags rhs) -> KeyFile::Flags&
  { return (lhs = static_cast<KeyFile::Flags>(static_cast<unsigned>(lhs) ^ static_cast<unsigned>(rhs))); }
} // namespace Glib

namespace Glib
{

/** A Glib::wrap() method for this object.
 *
 * @param object The C instance.
 * @param take_copy False if the result should take ownership of the C instance. True if it should take a new copy or ref.
 * @result A C++ instance that wraps this C instance.
 *
 * @relates Glib::KeyFile
 */
GLIBMM_API
auto wrap(GKeyFile* object, bool take_copy = false) -> Glib::RefPtr<Glib::KeyFile>;

} // namespace Glib


#endif /* _GLIBMM_KEYFILE_H */

