
#ifndef _GLIBMM_FILEUTILS_H
#define _GLIBMM_FILEUTILS_H


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


#ifndef DOXYGEN_SHOULD_SKIP_THIS
extern "C" { typedef struct _GDir GDir; }
#endif

#include <libmm-glib/error.hxx>
#include <iterator>
#include <string>

namespace Glib
{

/** @addtogroup glibmmEnums glibmm Enums and Flags */

/**
 *  @var FileTest IS_REGULAR
 * <tt>true</tt> if the file is a regular file
 * (not a directory). Note that this test will also return <tt>true</tt>
 * if the tested file is a symlink to a regular file.
 *
 *  @var FileTest IS_SYMLINK
 * <tt>true</tt> if the file is a symlink.
 *
 *  @var FileTest IS_DIR
 * <tt>true</tt> if the file is a directory.
 *
 *  @var FileTest IS_EXECUTABLE
 * <tt>true</tt> if the file is executable.
 *
 *  @var FileTest EXISTS
 * <tt>true</tt> if the file exists. It may or may not
 * be a regular file.
 *
 *  @enum FileTest
 *
 * A test to perform on a file using g_file_test().
 *
 * @ingroup glibmmEnums
 * @par Bitwise operators:
 * <tt>FileTest operator|(FileTest, FileTest)</tt><br>
 * <tt>FileTest operator&(FileTest, FileTest)</tt><br>
 * <tt>FileTest operator^(FileTest, FileTest)</tt><br>
 * <tt>FileTest operator~(FileTest)</tt><br>
 * <tt>FileTest& operator|=(FileTest&, FileTest)</tt><br>
 * <tt>FileTest& operator&=(FileTest&, FileTest)</tt><br>
 * <tt>FileTest& operator^=(FileTest&, FileTest)</tt><br>
 */
enum class FileTest
{
  IS_REGULAR = 1 << 0,
  IS_SYMLINK = 1 << 1,
  IS_DIR = 1 << 2,
  IS_EXECUTABLE = 1 << 3,
  EXISTS = 1 << 4
};

/** @ingroup glibmmEnums */
inline auto operator|(FileTest lhs, FileTest rhs) -> FileTest
  { return static_cast<FileTest>(static_cast<unsigned>(lhs) | static_cast<unsigned>(rhs)); }

/** @ingroup glibmmEnums */
inline auto operator&(FileTest lhs, FileTest rhs) -> FileTest
  { return static_cast<FileTest>(static_cast<unsigned>(lhs) & static_cast<unsigned>(rhs)); }

/** @ingroup glibmmEnums */
inline auto operator^(FileTest lhs, FileTest rhs) -> FileTest
  { return static_cast<FileTest>(static_cast<unsigned>(lhs) ^ static_cast<unsigned>(rhs)); }

/** @ingroup glibmmEnums */
inline auto operator~(FileTest flags) -> FileTest
  { return static_cast<FileTest>(~static_cast<unsigned>(flags)); }

/** @ingroup glibmmEnums */
inline auto operator|=(FileTest& lhs, FileTest rhs) -> FileTest&
  { return (lhs = static_cast<FileTest>(static_cast<unsigned>(lhs) | static_cast<unsigned>(rhs))); }

/** @ingroup glibmmEnums */
inline auto operator&=(FileTest& lhs, FileTest rhs) -> FileTest&
  { return (lhs = static_cast<FileTest>(static_cast<unsigned>(lhs) & static_cast<unsigned>(rhs))); }

/** @ingroup glibmmEnums */
inline auto operator^=(FileTest& lhs, FileTest rhs) -> FileTest&
  { return (lhs = static_cast<FileTest>(static_cast<unsigned>(lhs) ^ static_cast<unsigned>(rhs))); }


/** @defgroup FileUtils File Utilities
 * Various file-related classes and functions.
 */

/**  %Exception class for file-related errors.
 * @ingroup FileUtils
 */
class FileError : public Glib::Error
{
public:
  /**  @var Code EXISTS
   * Operation not permitted; only the owner of
   * the file (or other resource) or processes with special privileges
   * can perform the operation.
   *
   *  @var Code IS_DIRECTORY
   * File is a directory; you cannot open a directory
   * for writing, or create or remove hard links to it.
   *
   *  @var Code ACCESS_DENIED
   * Permission denied; the file permissions do not
   * allow the attempted operation.
   *
   *  @var Code NAME_TOO_LONG
   * Filename too long.
   *
   *  @var Code NO_SUCH_ENTITY
   * No such file or directory. This is a "file
   * doesn't exist" error for ordinary files that are referenced in
   * contexts where they are expected to already exist.
   *
   *  @var Code NOT_DIRECTORY
   * A file that isn't a directory was specified when
   * a directory is required.
   *
   *  @var Code NO_SUCH_DEVICE
   * No such device or address. The system tried to
   * use the device represented by a file you specified, and it
   * couldn't find the device. This can mean that the device file was
   * installed incorrectly, or that the physical device is missing or
   * not correctly attached to the computer.
   *
   *  @var Code NOT_DEVICE
   * The underlying file system of the specified file
   * does not support memory mapping.
   *
   *  @var Code READONLY_FILESYSTEM
   * The directory containing the new link can't be
   * modified because it's on a read-only file system.
   *
   *  @var Code TEXT_FILE_BUSY
   * Text file busy.
   *
   *  @var Code FAULTY_ADDRESS
   * You passed in a pointer to bad memory.
   * (GLib won't reliably return this, don't pass in pointers to bad
   * memory.).
   *
   *  @var Code SYMLINK_LOOP
   * Too many levels of symbolic links were encountered
   * in looking up a file name. This often indicates a cycle of symbolic
   * links.
   *
   *  @var Code NO_SPACE_LEFT
   * No space left on device; write operation on a
   * file failed because the disk is full.
   *
   *  @var Code NOT_ENOUGH_MEMORY
   * No memory available. The system cannot allocate
   * more virtual memory because its capacity is full.
   *
   *  @var Code TOO_MANY_OPEN_FILES
   * The current process has too many files open and
   * can't open any more. Duplicate descriptors do count toward this
   * limit.
   *
   *  @var Code FILE_TABLE_OVERFLOW
   * There are too many distinct file openings in the
   * entire system.
   *
   *  @var Code BAD_FILE_DESCRIPTOR
   * Bad file descriptor; for example, I/O on a
   * descriptor that has been closed or reading from a descriptor open
   * only for writing (or vice versa).
   *
   *  @var Code INVALID_ARGUMENT
   * Invalid argument. This is used to indicate
   * various kinds of problems with passing the wrong argument to a
   * library function.
   *
   *  @var Code BROKEN_PIPE
   * Broken pipe; there is no process reading from the
   * other end of a pipe. Every library function that returns this
   * error code also generates a 'SIGPIPE' signal; this signal
   * terminates the program if not handled or blocked. Thus, your
   * program will never actually see this code unless it has handled
   * or blocked 'SIGPIPE'.
   *
   *  @var Code TRYAGAIN
   * Resource temporarily unavailable; the call might
   * work if you try again later.
   *
   *  @var Code INTERRUPTED
   * Interrupted function call; an asynchronous signal
   * occurred and prevented completion of the call. When this
   * happens, you should try the call again.
   *
   *  @var Code IO_ERROR
   * Input/output error; usually used for physical read
   * or write errors. i.e. the disk or other physical device hardware
   * is returning errors.
   *
   *  @var Code NOT_OWNER
   * Operation not permitted; only the owner of the
   * file (or other resource) or processes with special privileges can
   * perform the operation.
   *
   *  @var Code NOSYS
   * Function not implemented; this indicates that
   * the system is missing some functionality.
   *
   *  @var Code FAILED
   * Does not correspond to a UNIX error code; this
   * is the standard "failed for unspecified reason" error code present
   * in all Error error code enumerations. Returned if no specific
   * code applies.
   *
   *  @enum Code
   *
   * Values corresponding to @a errno codes returned from file operations
   * on UNIX. Unlike @a errno codes, GFileError values are available on
   * all systems, even Windows. The exact meaning of each code depends
   * on what sort of file operation you were performing; the UNIX
   * documentation gives more details. The following error code descriptions
   * come from the GNU C Library manual, and are under the copyright
   * of that manual.
   *
   * It's not very portable to make detailed assumptions about exactly
   * which errors will be returned from a given operation. Some errors
   * don't occur on some systems, etc., sometimes there are subtle
   * differences in when a system will report a given error, etc.
   */
  enum Code
  {
    EXISTS,
    IS_DIRECTORY,
    ACCESS_DENIED,
    NAME_TOO_LONG,
    NO_SUCH_ENTITY,
    NOT_DIRECTORY,
    NO_SUCH_DEVICE,
    NOT_DEVICE,
    READONLY_FILESYSTEM,
    TEXT_FILE_BUSY,
    FAULTY_ADDRESS,
    SYMLINK_LOOP,
    NO_SPACE_LEFT,
    NOT_ENOUGH_MEMORY,
    TOO_MANY_OPEN_FILES,
    FILE_TABLE_OVERFLOW,
    BAD_FILE_DESCRIPTOR,
    INVALID_ARGUMENT,
    BROKEN_PIPE,
    TRYAGAIN,
    INTERRUPTED,
    IO_ERROR,
    NOT_OWNER,
    NOSYS,
    FAILED
  };

  GLIBMM_API FileError(Code error_code, const Glib::ustring& error_message);
  GLIBMM_API explicit FileError(GError* gobject);
  GLIBMM_API auto code() const -> Code;

#ifndef DOXYGEN_SHOULD_SKIP_THIS
private:

  GLIBMM_API static void throw_func(GError* gobject);

  friend GLIBMM_API void wrap_init(); // uses throw_func()

  #endif //DOXYGEN_SHOULD_SKIP_THIS
};


/** @var FileError::Code FileError::EXISTS
 * <tt>(EEXIST)</tt>
 *
 * @var FileError::Code FileError::IS_DIRECTORY
 * <tt>(EISDIR)</tt>
 *
 * @var FileError::Code FileError::ACCESS_DENIED
 * <tt>(EACCES)</tt>
 *
 * @var FileError::Code FileError::NAME_TOO_LONG
 * <tt>(ENAMETOOLONG)</tt>
 *
 * @var FileError::Code FileError::NO_SUCH_ENTITY
 * <tt>(ENOENT)</tt>
 *
 * @var FileError::Code FileError::NOT_DIRECTORY
 * <tt>(ENOTDIR)</tt>
 *
 * @var FileError::Code FileError::NO_SUCH_DEVICE
 * <tt>(ENXIO)</tt>
 *
 * @var FileError::Code FileError::NOT_DEVICE
 * <tt>(ENODEV)</tt>
 *
 * @var FileError::Code FileError::READONLY_FILESYSTEM
 * <tt>(EROFS)</tt>
 *
 * @var FileError::Code FileError::TEXT_FILE_BUSY
 * <tt>(ETXTBSY)</tt>
 *
 * @var FileError::Code FileError::FAULTY_ADDRESS
 * <tt>(EFAULT)</tt>
 *
 * @var FileError::Code FileError::SYMLINK_LOOP
 * <tt>(ELOOP)</tt>
 *
 * @var FileError::Code FileError::NO_SPACE_LEFT
 * <tt>(ENOSPC)</tt>
 *
 * @var FileError::Code FileError::NOT_ENOUGH_MEMORY
 * <tt>(ENOMEM)</tt>
 *
 * @var FileError::Code FileError::TOO_MANY_OPEN_FILES
 * <tt>(EMFILE)</tt>
 *
 * @var FileError::Code FileError::FILE_TABLE_OVERFLOW
 * <tt>(ENFILE)</tt>
 *
 * @var FileError::Code FileError::BAD_FILE_DESCRIPTOR
 * <tt>(EBADF)</tt>
 *
 * @var FileError::Code FileError::INVALID_ARGUMENT
 * <tt>(EINVAL)</tt>
 *
 * @var FileError::Code FileError::BROKEN_PIPE
 * <tt>(EPIPE)</tt>
 *
 * @var FileError::Code FileError::TRYAGAIN
 * <tt>(EAGAIN)</tt>
 *
 * We use TRYAGAIN instead of TRY_AGAIN, because that is defined as a macro by a Unix header.
 *
 * @var FileError::Code FileError::INTERRUPTED
 * <tt>(EINTR)</tt>
 *
 * @var FileError::Code FileError::IO_ERROR
 * <tt>(EIO)</tt>
 *
 * @var FileError::Code FileError::NOT_OWNER
 * <tt>(EPERM)</tt>
 *
 * @var FileError::Code FileError::FAILED
 * Returned if no specific code applies.
 */

class Dir;

/** The iterator type of Glib::Dir.
 * @ingroup FileUtils
 */
class GLIBMM_API DirIterator
{
public:
  typedef std::input_iterator_tag   iterator_category;
  typedef std::string               value_type;
  typedef int                       difference_type;
  typedef value_type                reference;
  typedef void                      pointer;

  DirIterator();

#ifndef DOXYGEN_SHOULD_SKIP_THIS
  DirIterator(GDir* gobject, const char* current);
#endif

  auto  operator*() const -> std::string;
  auto operator++() -> DirIterator&;

  /** @note DirIterator has input iterator semantics, which means real
   * postfix increment is impossible. The return type is @c void to
   * prevent surprising behaviour.
   */
  void operator++(int);

  auto operator==(const DirIterator& rhs) const -> bool;
  auto operator!=(const DirIterator& rhs) const -> bool;

private:
  GDir*       gobject_;
  const char* current_;
};


/** Utility class representing an open directory.
 * @ingroup FileUtils
 * It's highly recommended to use the iterator interface.  With iterators,
 * reading an entire directory into a STL container is really easy:
 * @code
 * Glib::Dir dir (directory_path);
 * std::list<std::string> entries (dir.begin(), dir.end());
 * @endcode
 * @note The encoding of the directory entries isn't necessarily UTF-8.
 * Use Glib::filename_to_utf8() if you need to display them.
 */
class GLIBMM_API Dir
{
public:
  using iterator = DirIterator;
  using const_iterator = DirIterator;

  /** Opens a directory for reading. The names of the files in the
   * directory can then be retrieved using read_name().
   * @param path The path to the directory you are interested in.
   * @throw Glib::FileError
   */
  explicit Dir(const std::string& path);

#ifndef DOXYGEN_SHOULD_SKIP_THIS
  explicit Dir(GDir* gobject);
#endif

  Dir(const Dir&) = delete;
  auto operator=(const Dir&) -> Dir& = delete;

  /** Closes the directory and deallocates all related resources.
   */
  ~Dir();

  /** Retrieves the name of the next entry in the directory.
   * The <tt>'.'</tt> and <tt>'..'</tt> entries are omitted.
   * @return The entry's name or <tt>""</tt> if there are no more entries.
   * @see begin(), end()
   */
  auto read_name() -> std::string;

  /** Resets the directory.  The next call to
   * read_name() will return the first entry again.
   */
  void rewind();

  /** Closes the directory and deallocates all related resources.
   * Note that close() is implicitely called by ~Dir().  Thus you don't
   * need to call close() yourself unless you want to close the directory
   * before the destructor runs.
   */
  void close();

  /** Get the begin of an input iterator sequence.
   * @return An input iterator pointing to the first directory entry.
   */
  auto begin() -> DirIterator;

  /** Get the end of an input iterator sequence.
   * @return An input iterator pointing behind the last directory entry.
   */
  auto end() -> DirIterator;

private:
  GDir* gobject_;
};


/** Returns @c true if any of the tests in the bitfield @a test are true.
 * @ingroup FileUtils
 * For example, <tt>(Glib::FILE_TEST_EXISTS | Glib::FILE_TEST_IS_DIR)</tt> will
 * return @c true if the file exists; the check whether it's a directory
 * doesn't matter since the existence test is true. With the current set of
 * available tests, there's no point passing in more than one test at a time.
 *
 * Apart from <tt>Glib::FILE_TEST_IS_SYMLINK</tt> all tests follow symbolic
 * links, so for a symbolic link to a regular file file_test() will return
 * @c true for both <tt>Glib::FILE_TEST_IS_SYMLINK</tt> and
 * <tt>Glib::FILE_TEST_IS_REGULAR</tt>.
 *
 * @note For a dangling symbolic link file_test() will return @c true for
 * <tt>Glib::FILE_TEST_IS_SYMLINK</tt> and @c false for all other flags.
 *
 * @param filename A filename to test.
 * @param test Bitfield of Glib::FileTest flags.
 * @return Whether a test was true.
 */
GLIBMM_API
auto file_test(const std::string& filename, FileTest test) -> bool;

/** Opens a temporary file.
 * @ingroup FileUtils
 * See the %mkstemp() documentation on most UNIX-like systems. This is a
 * portability wrapper, which simply calls %mkstemp() on systems that have
 * it, and implements it in GLib otherwise.
 * @param filename_template A string that should match the rules for
 *   %mkstemp(), i.e. end in <tt>"XXXXXX"</tt>. The <tt>X</tt> string
 *   will be modified to form the name of a file that didn't exist.
 * @return A file handle (as from open()) to the file opened for reading
 *   and writing. The file is opened in binary mode on platforms where there
 *   is a difference. The file handle should be closed with close(). In
 *   case of errors, <tt>-1</tt> is returned.
 */
GLIBMM_API
auto mkstemp(std::string& filename_template) -> int;

/** Opens a file for writing in the preferred directory for temporary files
 * (as returned by Glib::get_tmp_dir()).
 * @ingroup FileUtils
 * @a prefix should a basename template; it'll be suffixed by 6 characters
 * in order to form a unique filename.  No directory components are allowed.
 *
 * The actual name used is returned in @a name_used.
 *
 * @param[out] name_used The actual name used.
 * @param prefix Template for file name, basename only.
 * @return A file handle (as from <tt>open()</tt>) to the file opened for reading
 * and writing. The file is opened in binary mode on platforms where there is a
 * difference. The file handle should be closed with <tt>close()</tt>.
 * @throw Glib::FileError
 */
GLIBMM_API
auto file_open_tmp(std::string& name_used, const std::string& prefix) -> int;

/** Opens a file for writing in the preferred directory for temporary files
 * (as returned by Glib::get_tmp_dir()).
 * @ingroup FileUtils
 * This function works like file_open_tmp(std::string&, const std::string&)
 * but uses a default basename prefix.
 *
 * @param[out] name_used The actual name used.
 * @return A file handle (as from <tt>open()</tt>) to the file opened for reading
 * and writing. The file is opened in binary mode on platforms where there is a
 * difference. The file handle should be closed with <tt>close()</tt>.
 * @throw Glib::FileError
 */
GLIBMM_API
auto file_open_tmp(std::string& name_used) -> int;

/** Reads an entire file into a string, with good error checking.
 * @ingroup FileUtils
 * @param filename A file to read contents from.
 * @return The file contents.
 * @throw Glib::FileError
 */
GLIBMM_API
auto file_get_contents(const std::string& filename) -> std::string;

/** Writes all of @a contents to a file named @a filename, with good error checking.
 *
 * @param filename name of a file to write @a contents to, in the GLib file name
 *   encoding
 * @param contents string to write to the file
 * @param length length of @a contents, or -1 if @a contents is a nul-terminated string
 *
 * If a file called @a filename already exists it will be overwritten.
 *
 * This write is atomic in the sense that it is first written to a temporary
 * file which is then renamed to the final name. Notes:
 * <ol>
 * <li>
 *    On Unix, if @a filename already exists hard links to @a filename will break.
 *    Also since the file is recreated, existing permissions, access control
 *    lists, metadata etc. may be lost. If @a filename is a symbolic link,
 *    the link itself will be replaced, not the linked file.
 * </li>
 * <li>
 *   On Windows renaming a file will not remove an existing file with the
 *   new name, so on Windows there is a race condition between the existing
 *   file being removed and the temporary file being renamed.
 * </li>
 * <li>
 *   On Windows there is no way to remove a file that is open to some
 *   process, or mapped into memory. Thus, this function will fail if
 *   @a filename already exists and is open.
 * </li>
 * </ol>
 *
 * If the call was not successful, an exception is thrown.
 * Possible error codes are those in the FileError enumeration.
 *
 * @newin{2,22}
 **/
GLIBMM_API
void file_set_contents (const std::string& filename, const gchar *contents, gssize length);
/** A variant of file_set_contents which accepts a standard C++ string
 *
 * @newin{2,22}
 * */
GLIBMM_API
void file_set_contents (const std::string& filename, const std::string& contents);

} // namespace Glib


#endif /* _GLIBMM_FILEUTILS_H */

