
#ifndef _GIOMM_FILE_H
#define _GIOMM_FILE_H


#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

/* Copyright (C) 2007 The gtkmm Development Team
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

#include <libmm-glib/error.hxx>
#include <libmm-glib/interface.hxx>
#include <libmm-gio/appinfo.hxx>
#include <libmm-gio/asyncresult.hxx>
#include <libmm-gio/fileattributeinfolist.hxx>
#include <libmm-gio/fileenumerator.hxx>
#include <libmm-gio/fileinfo.hxx>
#include <libmm-gio/fileinputstream.hxx>
#include <libmm-gio/fileiostream.hxx>
#include <libmm-gio/filemonitor.hxx>
#include <libmm-gio/fileoutputstream.hxx>
#include <libmm-gio/mountoperation.hxx>
#include <libmm-gio/drive.hxx>
#include <libmm-gio/error.hxx> //Because this is thrown by some of these methods.
#include <utility>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
typedef struct _GFileIface GFileIface;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GFile = struct _GFile;
using GFileClass = struct _GFileClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gio
{ class GIOMM_API File_Class; } // namespace Gio
#endif // DOXYGEN_SHOULD_SKIP_THIS

namespace Gio
{

class GIOMM_API Mount;
class GIOMM_API Volume;

/** @addtogroup giommEnums giomm Enums and Flags */

/**
 *  @var FileQueryInfoFlags NONE
 * No flags set.
 *
 *  @var FileQueryInfoFlags NOFOLLOW_SYMLINKS
 * Don't follow symlinks.
 *
 *  @enum FileQueryInfoFlags
 *
 * Flags used when querying a FileInfo.
 *
 * @ingroup giommEnums
 * @par Bitwise operators:
 * <tt>FileQueryInfoFlags operator|(FileQueryInfoFlags, FileQueryInfoFlags)</tt><br>
 * <tt>FileQueryInfoFlags operator&(FileQueryInfoFlags, FileQueryInfoFlags)</tt><br>
 * <tt>FileQueryInfoFlags operator^(FileQueryInfoFlags, FileQueryInfoFlags)</tt><br>
 * <tt>FileQueryInfoFlags operator~(FileQueryInfoFlags)</tt><br>
 * <tt>FileQueryInfoFlags& operator|=(FileQueryInfoFlags&, FileQueryInfoFlags)</tt><br>
 * <tt>FileQueryInfoFlags& operator&=(FileQueryInfoFlags&, FileQueryInfoFlags)</tt><br>
 * <tt>FileQueryInfoFlags& operator^=(FileQueryInfoFlags&, FileQueryInfoFlags)</tt><br>
 */
enum class FileQueryInfoFlags
{
  NONE = 0x0,
  NOFOLLOW_SYMLINKS = (1 << 0)
};

/** @ingroup giommEnums */
inline auto operator|(FileQueryInfoFlags lhs, FileQueryInfoFlags rhs) -> FileQueryInfoFlags
  { return static_cast<FileQueryInfoFlags>(static_cast<unsigned>(lhs) | static_cast<unsigned>(rhs)); }

/** @ingroup giommEnums */
inline auto operator&(FileQueryInfoFlags lhs, FileQueryInfoFlags rhs) -> FileQueryInfoFlags
  { return static_cast<FileQueryInfoFlags>(static_cast<unsigned>(lhs) & static_cast<unsigned>(rhs)); }

/** @ingroup giommEnums */
inline auto operator^(FileQueryInfoFlags lhs, FileQueryInfoFlags rhs) -> FileQueryInfoFlags
  { return static_cast<FileQueryInfoFlags>(static_cast<unsigned>(lhs) ^ static_cast<unsigned>(rhs)); }

/** @ingroup giommEnums */
inline auto operator~(FileQueryInfoFlags flags) -> FileQueryInfoFlags
  { return static_cast<FileQueryInfoFlags>(~static_cast<unsigned>(flags)); }

/** @ingroup giommEnums */
inline auto operator|=(FileQueryInfoFlags& lhs, FileQueryInfoFlags rhs) -> FileQueryInfoFlags&
  { return (lhs = static_cast<FileQueryInfoFlags>(static_cast<unsigned>(lhs) | static_cast<unsigned>(rhs))); }

/** @ingroup giommEnums */
inline auto operator&=(FileQueryInfoFlags& lhs, FileQueryInfoFlags rhs) -> FileQueryInfoFlags&
  { return (lhs = static_cast<FileQueryInfoFlags>(static_cast<unsigned>(lhs) & static_cast<unsigned>(rhs))); }

/** @ingroup giommEnums */
inline auto operator^=(FileQueryInfoFlags& lhs, FileQueryInfoFlags rhs) -> FileQueryInfoFlags&
  { return (lhs = static_cast<FileQueryInfoFlags>(static_cast<unsigned>(lhs) ^ static_cast<unsigned>(rhs))); }


/**
 *  @var FileMonitorFlags NONE
 * No flags set.
 *
 *  @var FileMonitorFlags WATCH_MOUNTS
 * Watch for mount events.
 *
 *  @var FileMonitorFlags SEND_MOVED
 * Pair DELETED and CREATED events caused
 * by file renames (moves) and send a single G_FILE_MONITOR_EVENT_MOVED
 * event instead (NB: not supported on all backends; the default
 * behaviour -without specifying this flag- is to send single DELETED
 * and CREATED events).  Deprecated since 2.46: use
 * Gio::FileMonitorFlags::WATCH_MOVES instead.
 *
 *  @var FileMonitorFlags WATCH_HARD_LINKS
 * Watch for changes to the file made
 * via another hard link. @newin{2,36}
 *
 *  @var FileMonitorFlags WATCH_MOVES
 * Watch for rename operations on a
 * monitored directory.  This causes Gio::FileMonitor::Event::RENAMED,
 * Gio::FileMonitor::Event::MOVED_IN and Gio::FileMonitor::Event::MOVED_OUT
 * events to be emitted when possible.  @newin{2,46}
 *
 *  @enum FileMonitorFlags
 *
 * Flags used to set what a FileMonitor will watch for.
 *
 * @ingroup giommEnums
 * @par Bitwise operators:
 * <tt>FileMonitorFlags operator|(FileMonitorFlags, FileMonitorFlags)</tt><br>
 * <tt>FileMonitorFlags operator&(FileMonitorFlags, FileMonitorFlags)</tt><br>
 * <tt>FileMonitorFlags operator^(FileMonitorFlags, FileMonitorFlags)</tt><br>
 * <tt>FileMonitorFlags operator~(FileMonitorFlags)</tt><br>
 * <tt>FileMonitorFlags& operator|=(FileMonitorFlags&, FileMonitorFlags)</tt><br>
 * <tt>FileMonitorFlags& operator&=(FileMonitorFlags&, FileMonitorFlags)</tt><br>
 * <tt>FileMonitorFlags& operator^=(FileMonitorFlags&, FileMonitorFlags)</tt><br>
 */
enum class FileMonitorFlags
{
  NONE = 0x0,
  WATCH_MOUNTS = (1 << 0),
  SEND_MOVED = (1 << 1),
  WATCH_HARD_LINKS = (1 << 2),
  WATCH_MOVES = (1 << 3)
};

/** @ingroup giommEnums */
inline auto operator|(FileMonitorFlags lhs, FileMonitorFlags rhs) -> FileMonitorFlags
  { return static_cast<FileMonitorFlags>(static_cast<unsigned>(lhs) | static_cast<unsigned>(rhs)); }

/** @ingroup giommEnums */
inline auto operator&(FileMonitorFlags lhs, FileMonitorFlags rhs) -> FileMonitorFlags
  { return static_cast<FileMonitorFlags>(static_cast<unsigned>(lhs) & static_cast<unsigned>(rhs)); }

/** @ingroup giommEnums */
inline auto operator^(FileMonitorFlags lhs, FileMonitorFlags rhs) -> FileMonitorFlags
  { return static_cast<FileMonitorFlags>(static_cast<unsigned>(lhs) ^ static_cast<unsigned>(rhs)); }

/** @ingroup giommEnums */
inline auto operator~(FileMonitorFlags flags) -> FileMonitorFlags
  { return static_cast<FileMonitorFlags>(~static_cast<unsigned>(flags)); }

/** @ingroup giommEnums */
inline auto operator|=(FileMonitorFlags& lhs, FileMonitorFlags rhs) -> FileMonitorFlags&
  { return (lhs = static_cast<FileMonitorFlags>(static_cast<unsigned>(lhs) | static_cast<unsigned>(rhs))); }

/** @ingroup giommEnums */
inline auto operator&=(FileMonitorFlags& lhs, FileMonitorFlags rhs) -> FileMonitorFlags&
  { return (lhs = static_cast<FileMonitorFlags>(static_cast<unsigned>(lhs) & static_cast<unsigned>(rhs))); }

/** @ingroup giommEnums */
inline auto operator^=(FileMonitorFlags& lhs, FileMonitorFlags rhs) -> FileMonitorFlags&
  { return (lhs = static_cast<FileMonitorFlags>(static_cast<unsigned>(lhs) ^ static_cast<unsigned>(rhs))); }


/** %File and directory handling.
 * %Gio::File is a high level abstraction for manipulating files on a virtual file system. Gio::Files are lightweight, immutable objects that do no
 * I/O upon creation. It is necessary to understand that a %Gio::File object does not represent a file, merely a handle to a file. All file I/O is
 * implemented as streaming operations (see Gio::InputStream and Gio::OutputStream).
 *
 * A %Gio::File can be constructed from a path, URI, or a command line argument.
 *
 * You can move through the filesystem with %Gio::File handles with get_parent() to get a handle to the parent directory,
 * get_child() to get a handle to a child within a directory, and resolve_relative_path() to resolve a relative path between two Gio::Files.
 *
 * Many %Gio::File operations have both synchronous and asynchronous versions to suit your application. Asynchronous versions of synchronous
 * functions simply have _async() appended to their function names. The asynchronous I/O functions call a SlotAsyncReady callback slot which is
 * then used to finalize the operation, producing a AsyncResult which is then passed to the function's matching _finish() operation.
 *
 * Some %Gio::File operations do not have synchronous analogs, as they may take a very long time to finish, and blocking may leave an application
 * unusable. Notable cases include: mount_mountable() to mount a mountable file, unmount_mountable() to unmount a mountable file,
 * and eject_mountable() to eject a mountable file.
 *
 * One notable feature of Gio::Files are entity tags, or "etags" for short. Entity tags are somewhat like a more abstract version of the
 * traditional mtime, and can be used to quickly determine if the file has been modified from the version on the file system.
 * See the HTTP 1.1 specification for HTTP Etag headers, which are a very similar concept.
 *
 * @newin{2,16}
 */

class File : public Glib::Interface
{

#ifndef DOXYGEN_SHOULD_SKIP_THIS

public:
  using CppObjectType = File;
  using CppClassType = File_Class;
  using BaseObjectType = GFile;
  using BaseClassType = GFileIface;

  // noncopyable
  File(const File&) = delete;
  auto operator=(const File&) -> File& = delete;

private:
  friend class File_Class;
  static CppClassType file_class_;

#endif /* DOXYGEN_SHOULD_SKIP_THIS */
protected:
  /**
   * You should derive from this class to use it.
   */
  File();

#ifndef DOXYGEN_SHOULD_SKIP_THIS
  /** Called by constructors of derived classes. Provide the result of
   * the Class init() function to ensure that it is properly
   * initialized.
   *
   * @param interface_class The Class object for the derived type.
   */
  explicit File(const Glib::Interface_Class& interface_class);

public:
  // This is public so that C++ wrapper instances can be
  // created for C instances of unwrapped types.
  // For instance, if an unexpected C type implements the C interface.
  explicit File(GFile* castitem);

protected:
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  File(File&& src) noexcept;
  auto operator=(File&& src) noexcept -> File&;

  ~File() noexcept override;

  static void add_interface(GType gtype_implementer);

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS
  static auto get_base_type() -> GType G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GObject.
  auto       gobj() -> GFile*       { return reinterpret_cast<GFile*>(gobject_); }

  ///Provides access to the underlying C GObject.
  auto gobj() const -> const GFile* { return reinterpret_cast<GFile*>(gobject_); }

private:


public:
  /**
   *  @var CreateFlags NONE
   * No flags set.
   *
   *  @var CreateFlags PRIVATE
   * Create a file that can only be
   * accessed by the current user.
   *
   *  @var CreateFlags REPLACE_DESTINATION
   * Replace the destination
   * as if it didn't exist before. Don't try to keep any old
   * permissions, replace instead of following links. This
   * is generally useful if you're doing a "copy over"
   * rather than a "save new version of" replace operation.
   * You can think of it as "unlink destination" before
   * writing to it, although the implementation may not
   * be exactly like that. This flag can only be used with
   * g_file_replace() and its variants, including g_file_replace_contents().
   * @newin{2,20}
   *
   *  @enum CreateFlags
   *
   * Flags used when an operation may create a file.
   *
   * @ingroup giommEnums
   * @par Bitwise operators:
   * <tt>File::CreateFlags operator|(File::CreateFlags, File::CreateFlags)</tt><br>
   * <tt>File::CreateFlags operator&(File::CreateFlags, File::CreateFlags)</tt><br>
   * <tt>File::CreateFlags operator^(File::CreateFlags, File::CreateFlags)</tt><br>
   * <tt>File::CreateFlags operator~(File::CreateFlags)</tt><br>
   * <tt>File::CreateFlags& operator|=(File::CreateFlags&, File::CreateFlags)</tt><br>
   * <tt>File::CreateFlags& operator&=(File::CreateFlags&, File::CreateFlags)</tt><br>
   * <tt>File::CreateFlags& operator^=(File::CreateFlags&, File::CreateFlags)</tt><br>
   */
  enum class CreateFlags
  {
    NONE = 0x0,
    PRIVATE = (1 << 0),
    REPLACE_DESTINATION = (1 << 1)
  };


  /**
   *  @var CopyFlags NONE
   * No flags set.
   *
   *  @var CopyFlags OVERWRITE
   * Overwrite any existing files.
   *
   *  @var CopyFlags BACKUP
   * Make a backup of any existing files.
   *
   *  @var CopyFlags NOFOLLOW_SYMLINKS
   * Don't follow symlinks.
   *
   *  @var CopyFlags ALL_METADATA
   * Copy all file metadata instead of just default set used for copy (see FileInfo).
   *
   *  @var CopyFlags NO_FALLBACK_FOR_MOVE
   * Don't use copy and delete fallback if native move not supported.
   *
   *  @var CopyFlags TARGET_DEFAULT_PERMS
   * Leaves target file with default perms, instead of setting the source file perms.
   *
   *  @enum CopyFlags
   *
   * Flags used when copying or moving files.
   *
   * @ingroup giommEnums
   * @par Bitwise operators:
   * <tt>File::CopyFlags operator|(File::CopyFlags, File::CopyFlags)</tt><br>
   * <tt>File::CopyFlags operator&(File::CopyFlags, File::CopyFlags)</tt><br>
   * <tt>File::CopyFlags operator^(File::CopyFlags, File::CopyFlags)</tt><br>
   * <tt>File::CopyFlags operator~(File::CopyFlags)</tt><br>
   * <tt>File::CopyFlags& operator|=(File::CopyFlags&, File::CopyFlags)</tt><br>
   * <tt>File::CopyFlags& operator&=(File::CopyFlags&, File::CopyFlags)</tt><br>
   * <tt>File::CopyFlags& operator^=(File::CopyFlags&, File::CopyFlags)</tt><br>
   */
  enum class CopyFlags
  {
    NONE = 0x0,
    OVERWRITE = (1 << 0),
    BACKUP = (1 << 1),
    NOFOLLOW_SYMLINKS = (1 << 2),
    ALL_METADATA = (1 << 3),
    NO_FALLBACK_FOR_MOVE = (1 << 4),
    TARGET_DEFAULT_PERMS = (1 << 5)
  };


  /**
   *  @var MeasureFlags NONE
   * No flags set.
   *
   *  @var MeasureFlags REPORT_ANY_ERROR
   * Report any error encountered
   * while traversing the directory tree.  Normally errors are only
   * reported for the toplevel file.
   *
   *  @var MeasureFlags APPARENT_SIZE
   * Tally usage based on apparent file
   * sizes.  Normally, the block-size is used, if available, as this is a
   * more accurate representation of disk space used.
   * Compare with `du --apparent-size`.
   *
   *  @var MeasureFlags NO_XDEV
   * Do not cross mount point boundaries.
   * Compare with `du -x`.
   *
   *  @enum MeasureFlags
   *
   * Flags that can be used with g_file_measure_disk_usage().
   *
   * @newin{2,38}
   *
   * @ingroup giommEnums
   * @par Bitwise operators:
   * <tt>File::MeasureFlags operator|(File::MeasureFlags, File::MeasureFlags)</tt><br>
   * <tt>File::MeasureFlags operator&(File::MeasureFlags, File::MeasureFlags)</tt><br>
   * <tt>File::MeasureFlags operator^(File::MeasureFlags, File::MeasureFlags)</tt><br>
   * <tt>File::MeasureFlags operator~(File::MeasureFlags)</tt><br>
   * <tt>File::MeasureFlags& operator|=(File::MeasureFlags&, File::MeasureFlags)</tt><br>
   * <tt>File::MeasureFlags& operator&=(File::MeasureFlags&, File::MeasureFlags)</tt><br>
   * <tt>File::MeasureFlags& operator^=(File::MeasureFlags&, File::MeasureFlags)</tt><br>
   */
  enum class MeasureFlags
  {
    NONE = 0x0,
    REPORT_ANY_ERROR = (1 << 1),
    APPARENT_SIZE = (1 << 2),
    NO_XDEV = (1 << 3)
  };


   //g_file_icon_new is not a GFile method.

  // Although this is an interface, it is possible to create objects using
  // its static create* members. In the implementation, these would lead
  // to functions of the default GVfs implementation, which, in case of
  // this class' create methods, would rely on concrete GFile implementations
  // such as GLocalFile and GDummyFile.

  /** Constructs a File for a given path.
   * This operation never fails, but the returned object might not support any I/O operation if path is malformed.
   *
   * @param path A string containing a relative or absolute path.
   * @result A new instantiation of an appropriate Gio::File class.
   */
  static auto create_for_path(const std::string& path) -> Glib::RefPtr<File>;


  /** Constructs a File for a given URI.
   * This operation never fails, but the returned object might not support any I/O operation if path is malformed.
   *
   * @param uri A string containing a URI.
   * @result A new instantiation of an appropriate Gio::File class.
   */
  static auto create_for_uri(const std::string& uri) -> Glib::RefPtr<File>;


  /** Constructs a File for a given argument from the command line.
   * The value of @a arg can be either a URI, an absolute path or a relative path resolved relative to the current working directory.
   * This operation never fails, but the returned object might not support any I/O operation if arg points to a malformed path.
   *
   * @param arg A string containing a relative or absolute path.
   * @result A new instantiation of an appropriate Gio::File class.
   */
  static auto create_for_commandline_arg(const std::string& arg) -> Glib::RefPtr<File>;


  /** Constructs a file in the preferred directory for temporary files.
   *
   * The file is created in the directory returned by Glib::get_tmp_dir().
   * A FileIOStream pointing to the file is also created.
   *
   * @a tmpl should be a string in the GLib file name encoding
   * containing a sequence of six 'X' characters, and containing no
   * directory components. If it is an empty string, a default template is used.
   *
   * Unlike the other %File constructors, this will throw an exception if
   * a temporary file could not be created.
   *
   * @newin{2,74}
   *
   * @param tmpl Template for the file name, as in Glib::file_open_tmp(),
   *             or an empty string for a default template.
   * @return {file, iostream} A new %File and a FileIOStream for the created file.
   *
   * @throws Glib::FileError
   */
  static auto create_tmp(const std::string& tmpl = {}) -> std::pair<Glib::RefPtr<File>, Glib::RefPtr<FileIOStream>>;


  // parse_name is a UTF8-guaranteed "nice" string that can both
  // be resolved to a GFile (via create_for_parse_name) and put in
  // e.g. a GtkEntry. In practice, it is either a UTF8-only absolute
  // filename (if it starts with a /), or an IRI (i.e. a URI that allows
  // UTF8-encoded unicode chars instead of escaping them).
  /** Constructs a %File with the given @a parse_name.
   *
   * The @a parse_name is something given by get_parse_name().
   * This operation never fails, but the returned object might not support any
   * I/O operation if the @a parse_name cannot be parsed.
   *
   * @param parse_name A UTF-8 encoded file name or path to be parsed.
   * @return A new %File.
   */
  static auto create_for_parse_name(const Glib::ustring& parse_name) -> Glib::RefPtr<File>;


  /** Duplicates a File handle. This operation does not duplicate
   * the actual file or directory represented by the File; see
   * g_file_copy() if attempting to copy a file.
   *
   * g_file_dup() is useful when a second handle is needed to the same underlying
   * file, for use in a separate thread (File is not thread-safe). For use
   * within the same thread, use Glib::object_ref() to increment the existing object’s
   * reference count.
   *
   * This call does no blocking I/O.
   *
   * @return A new File that is a duplicate
   * of the given File.
   */
  auto dup() const -> Glib::RefPtr<File>;

  // The method intended to be used for making hash tables
  // (g_hash_table_new in C).

  /** Creates a hash value for a File.
   *
   * This call does no blocking I/O.
   *
   * Virtual: hash
   *
   * @return 0 if @a file is not a valid File, otherwise an
   * integer that can be used as hash value for the File.
   * This function is intended for easily hashing a File to
   * add to a HashTable or similar data structure.
   */
  auto hash() const -> guint;

  //Note that the implementation of equal() is already virtual via equal_vfunc().

  /** Checks equality of two given Files.
   *
   * Note that two Files that differ can still refer to the same
   * file on the filesystem due to various forms of filename
   * aliasing.
   *
   * This call does no blocking I/O.
   * @param other The other File.
   * @return <tt>true</tt> if @a *this and @a other are equal.
   * <tt>false</tt> if either is not a File.
   */
  auto equal(const Glib::RefPtr<const File>& other) const -> bool;


  /** Gets the base name (the last component of the path) for a given File.
   *
   * If called for the top level of a system (such as the filesystem root
   * or a uri like sftp://host/) it will return a single directory separator
   * (and on Windows, possibly a drive letter).
   *
   * The base name is a byte string (not UTF-8). It has no defined encoding
   * or rules other than it may not contain zero bytes.  If you want to use
   * filenames in a user interface you should use the display name that you
   * can get by requesting the G_FILE_ATTRIBUTE_STANDARD_DISPLAY_NAME
   * attribute with g_file_query_info().
   *
   * This call does no blocking I/O.
   *
   * @return String containing the File's
   * base name, or <tt>nullptr</tt> if given File is invalid.
   */
  auto get_basename() const -> std::string;

  /** Gets the local pathname for File, if one exists. If non-<tt>nullptr</tt>, this is
   * guaranteed to be an absolute, canonical path. It might contain symlinks.
   *
   * This call does no blocking I/O.
   *
   * @return String containing the File's path,
   * or <tt>nullptr</tt> if no such path exists.
   */
  auto get_path() const -> std::string;


  /** Gets the URI for the @a file.
   *
   * This call does no blocking I/O.
   *
   * @return A string containing the File's URI. If the File was constructed
   * with an invalid URI, an invalid URI is returned.
   */
  auto get_uri() const -> std::string;

  /** Gets the parse name of the @a file.
   * A parse name is a UTF-8 string that describes the
   * file such that one can get the File back using
   * g_file_parse_name().
   *
   * This is generally used to show the File as a nice
   * full-pathname kind of string in a user interface,
   * like in a location entry.
   *
   * For local files with names that can safely be converted
   * to UTF-8 the pathname is used, otherwise the IRI is used
   * (a form of URI that allows UTF-8 characters unescaped).
   *
   * This call does no blocking I/O.
   *
   * @return A string containing the File's parse name.
   */
  auto get_parse_name() const -> Glib::ustring;

  //Note that these return a reference (usually new instances),
  //so we don't need to use refreturn.

  //TODO: Do we need const and unconst versions of these get_*() methods,
  //or do we consider that the returned File cannot be used to change "this".
  //murrayc.

  /** Gets the parent directory for the @a file.
   * If the @a file represents the root directory of the
   * file system, then <tt>nullptr</tt> will be returned.
   *
   * This call does no blocking I/O.
   *
   * @return A File structure to the
   * parent of the given File or <tt>nullptr</tt> if there is no parent. Free
   * the returned object with Glib::object_unref().
   */
  auto get_parent() const -> Glib::RefPtr<File>;


  /** Checks if @a file has a parent, and optionally, if it is @a parent.
   *
   * If @a parent is <tt>nullptr</tt> then this function returns <tt>true</tt> if @a file has any
   * parent at all.  If @a parent is non-<tt>nullptr</tt> then <tt>true</tt> is only returned
   * if @a file is an immediate child of @a parent.
   *
   * @newin{2,24}
   *
   * @param parent The parent to check for, or <tt>nullptr</tt>.
   * @return <tt>true</tt> if @a file is an immediate child of @a parent (or any parent in
   * the case that @a parent is <tt>nullptr</tt>).
   */
  auto has_parent(const Glib::RefPtr<File>& parent) const -> bool;

  /** Checks if the file has any parent at all.
   * @result true if the file is a child of any parent.
   *
   * @newin{2,24}
   */
  auto has_parent() const -> bool;


  /** Gets a child of @a file with basename equal to @a name.
   *
   * Note that the file with that specific name might not exist, but
   * you can still have a File that points to it. You can use this
   * for instance to create that file.
   *
   * This call does no blocking I/O.
   *
   * @param name String containing the child's basename.
   * @return A File to a child specified by @a name.
   * Free the returned object with Glib::object_unref().
   */
  auto get_child(const std::string& name) const -> Glib::RefPtr<File>;


  /** Gets the child of @a file for a given @a display_name (i.e.\ a UTF-8
   * version of the name). If this function fails, it returns <tt>nullptr</tt>
   * and @a error will be set. This is very useful when constructing a
   * File for a new file and the user entered the filename in the
   * user interface, for instance when you select a directory and
   * type a filename in the file selector.
   *
   * This call does no blocking I/O.
   *
   * @param display_name String to a possible child.
   * @return A File to the specified child, or
   * <tt>nullptr</tt> if the display name couldn't be converted.
   * Free the returned object with Glib::object_unref().
   *
   * @throws Glib::Error
   */
  auto get_child_for_display_name(const Glib::ustring& display_name) const -> Glib::RefPtr<File>;


  /** Checks whether @a file has the prefix specified by @a prefix.
   *
   * In other words, if the names of initial elements of @a file's
   * pathname match @a prefix. Only full pathname elements are matched,
   * so a path like /foo is not considered a prefix of /foobar, only
   * of /foo/bar.
   *
   * A File is not a prefix of itself. If you want to check for
   * equality, use g_file_equal().
   *
   * This call does no I/O, as it works purely on names. As such it can
   * sometimes return <tt>false</tt> even if @a file is inside a @a prefix (from a
   * filesystem point of view), because the prefix of @a file is an alias
   * of @a prefix.
   *
   * Virtual: prefix_matches
   *
   * @param prefix Input File.
   * @return <tt>true</tt> if the @a file's parent, grandparent, etc is @a prefix,
   * <tt>false</tt> otherwise.
   */
  auto has_prefix(const Glib::RefPtr<const File>& prefix) const -> bool;

  /** Gets the path for @a descendant relative to @a parent.
   *
   * This call does no blocking I/O.
   *
   * @param descendant Input File.
   * @return String with the relative path from
   *  @a descendant to @a parent, or <tt>nullptr</tt> if @a descendant doesn't have @a parent as
   * prefix.
   */
  auto get_relative_path(const Glib::RefPtr<const File>& descendant) const -> std::string;

  /** Resolves a relative path for @a file to an absolute path.
   *
   * This call does no blocking I/O.
   *
   * If the @a relative_path is an absolute path name, the resolution
   * is done absolutely (without taking @a file path as base).
   *
   * @param relative_path A given relative path string.
   * @return A File for the resolved path.
   */
  auto resolve_relative_path(const std::string& relative_path) const -> Glib::RefPtr<File>;

  /** Checks to see if a file is native to the platform.
   *
   * A native file is one expressed in the platform-native filename format,
   * e.g. "C:\\Windows" or "/usr/bin/". This does not mean the file is local,
   * as it might be on a locally mounted remote filesystem.
   *
   * On some systems non-native files may be available using the native
   * filesystem via a userspace filesystem (FUSE), in these cases this call
   * will return <tt>false</tt>, but g_file_get_path() will still return a native path.
   *
   * This call does no blocking I/O.
   *
   * @return <tt>true</tt> if @a file is native.
   */
  auto is_native() const -> bool;

  /** Checks to see if a File has a given URI scheme.
   *
   * This call does no blocking I/O.
   *
   * @param uri_scheme A string containing a URI scheme.
   * @return <tt>true</tt> if File's backend supports the
   * given URI scheme, <tt>false</tt> if URI scheme is <tt>nullptr</tt>,
   * not supported, or File is invalid.
   */
  auto has_uri_scheme(const std::string& uri_scheme) const -> bool;


  /** Gets the URI scheme for a File.
   * RFC 3986 decodes the scheme as:
   *
   * [C example ellipted]
   * Common schemes include "file", "http", "ftp", etc.
   *
   * The scheme can be different from the one used to construct the File,
   * in that it might be replaced with one that is logically equivalent to the File.
   *
   * This call does no blocking I/O.
   *
   * @return A string containing the URI scheme for the given
   * File or <tt>nullptr</tt> if the File was constructed with an invalid URI.
   */
  auto get_uri_scheme() const -> std::string;

  //TODO: We don't have both const and unconst versions because a FileInputStream can't really change the File.

  /** Opens a file for reading. The result is a FileInputStream that
   * can be used to read the contents of the file.
   *
   * The operation can be cancelled by
   * triggering the cancellable object from another thread. If the operation
   * was cancelled, a Gio::Error will be thrown with CANCELLED.
   *
   * If the file does not exist, a Gio::Error with NOT_FOUND will be thrown.
   * If the file is a directory, a Gio::Error with IS_DIRECTORY will be thrown.
   * Other errors are possible too, and depend on what kind of filesystem the file is on.
   *
   * @param cancellable A Cancellable.
   * @return FileInputStream or <tt>nullptr</tt> on error.
   *
   * @throws Glib::Error
   */
  auto read(const Glib::RefPtr<Cancellable>& cancellable) -> Glib::RefPtr<FileInputStream>;

  /// A read() convenience overload.
  auto read() -> Glib::RefPtr<FileInputStream>;

  /** Asynchronously opens the file for reading.
   * For more details, see read() which is the synchronous version of this call.
   * When the operation is finished, @a slot will be called. You can then call read_finish() to get the result of the operation.
   *
   * @param slot A callback slot which will be called when the request is satisfied.
   * @param cancellable A Cancellable object which can be used to cancel the operation.
   * @param io_priority The I/O priority of the request.
   */
  void read_async(const SlotAsyncReady& slot, const Glib::RefPtr<Cancellable>& cancellable, int io_priority = Glib::PRIORITY_DEFAULT);

  /** Asynchronously opens the file for reading.
   * For more details, see read() which is the synchronous version of this call.
   * When the operation is finished, @a slot will be called. You can then call read_finish() to get the result of the operation.
   *
   * @param slot A callback slot which will be called when the request is satisfied.
   * @param io_priority The I/O priority of the request.
   */
  void read_async(const SlotAsyncReady& slot, int io_priority = Glib::PRIORITY_DEFAULT);


  /** Finishes an asynchronous file read operation started with
   * g_file_read_async().
   *
   * @param res A AsyncResult.
   * @return A FileInputStream or <tt>nullptr</tt> on error.
   * Free the returned object with Glib::object_unref().
   *
   * @throws Glib::Error
   */
  auto read_finish(const Glib::RefPtr<AsyncResult>& res) -> Glib::RefPtr<FileInputStream>;


  /** Gets an output stream for appending data to the file. If
   * the file doesn't already exist it is created.
   *
   * By default files created are generally readable by everyone,
   * but if you pass CreateFlags::PRIVATE in @a flags the file
   * will be made readable only to the current user, to the level that
   * is supported on the target filesystem.
   *
   * The operation can be cancelled by
   * triggering the cancellable object from another thread. If the operation
   * was cancelled, a Gio::Error with CANCELLED will be thrown.
   *
   * Some filesystems don't allow all filenames, and may
   * throw a Gio::Error with INVALID_FILENAME.
   * If the file is a directory a Gio::Error with IS_DIRECTORY will be
   * thrown. Other errors are possible too, and depend on what kind of
   * filesystem the file is on.
   * @param flags A set of CreateFlags.
   * @param cancellable Optional Cancellable object.
   * @return A FileOutputStream.
   *
   * @throws Gio::Error
   */
  auto append_to(const Glib::RefPtr<Cancellable>& cancellable, CreateFlags flags = CreateFlags::NONE) -> Glib::RefPtr<FileOutputStream>;

  /** Gets an output stream for appending data to the file. If
   * the file doesn't already exist it is created.
   *
   * By default files created are generally readable by everyone,
   * but if you pass CreateFlags::PRIVATE in @a flags the file
   * will be made readable only to the current user, to the level that
   * is supported on the target filesystem.
   *
   * Some filesystems don't allow all filenames, and may
   * throw a Gio::Error with INVALID_FILENAME.
   * If the file is a directory a Gio::Error with IS_DIRECTORY will be
   * thrown. Other errors are possible too, and depend on what kind of
   * filesystem the file is on.
   * @param flags A set of CreateFlags.
   * @return A FileOutputStream.
   *
   * @throws Gio::Error
   */
  auto append_to(CreateFlags flags = CreateFlags::NONE) -> Glib::RefPtr<FileOutputStream>;


  //We renamed this to create_file from (g_file_create() and g_file_create_readwrite), to avoid confusion with static create() methods,
  //but I would still like to choose a different word, but can't think of a good one. murrayc.

  /** Creates a new file and returns an output stream for writing to it.
   * The file must not already exist.
   *
   * By default files created are generally readable by everyone,
   * but if you pass CreateFlags::PRIVATE in @a flags the file
   * will be made readable only to the current user, to the level that
   * is supported on the target filesystem.
   *
   * The operation can be cancelled by triggering the cancellable object from another thread.
   * If the operation was cancelled, a Gio::Error with CANCELLED will be thrown.
   *
   * If a file with this name already exists a Gio::Error with EXISTS
   * will be thrown. If the file is a directory a Gio::Error with IS_DIRECTORY
   * will be thrown.
   *
   * Some filesystems don't allow all filenames, and may
   * throw a Gio::Error with INVALID_FILENAME, and if the name
   * is to longa Gio::Error with FILENAME_TOO_LONG will be thrown.
   * Other errors are possible too, and depend on what kind of
   * filesystem the file is on.
   *
   * @param cancellable A Cancellable object which can be used to cancel the operation.
   * @param flags a set of CreateFlags.
   * @return A FileOutputStream for the newly created file.
   *
   * @throws Gio::Error
   */
  auto create_file(const Glib::RefPtr<Cancellable>& cancellable, CreateFlags flags = CreateFlags::NONE) -> Glib::RefPtr<FileOutputStream>;

  /** Creates a new file and returns an output stream for writing to it.
   * The file must not already exist.
   *
   * By default files created are generally readable by everyone,
   * but if you pass CreateFlags::PRIVATE in @a flags the file
   * will be made readable only to the current user, to the level that
   * is supported on the target filesystem.
   *
   * If a file with this name already exists a Gio::Error with EXISTS
   * will be thrown. If the file is a directory a Gio::Error with IS_DIRECTORY
   * will be thrown.
   *
   * Some filesystems don't allow all filenames, and may
   * throw a Gio::Error with INVALID_FILENAME, and if the name
   * is to longa Gio::Error with FILENAME_TOO_LONG will be thrown.
   * Other errors are possible too, and depend on what kind of
   * filesystem the file is on.
   *
   * @param flags a set of CreateFlags.
   * @return A FileOutputStream for the newly created file.
   *
   * @throws Gio::Error
   */
  auto create_file(CreateFlags flags = CreateFlags::NONE) -> Glib::RefPtr<FileOutputStream>;


  /** Creates a new file and returns a stream for reading and writing to it.
   * The file must not already exist.
   *
   * By default files created are generally readable by everyone,
   * but if you pass CreateFlags::PRIVATE in @a flags the file
   * will be made readable only to the current user, to the level that
   * is supported on the target filesystem.
   *
   * The operation can be cancelled by triggering the cancellable object from another thread.
   * If the operation was cancelled, a Gio::Error with CANCELLED will be thrown.
   *
   * If a file with this name already exists a Gio::Error with EXISTS
   * will be thrown. If the file is a directory a Gio::Error with IS_DIRECTORY
   * will be thrown.
   *
   * Some filesystems don't allow all filenames, and may
   * throw a Gio::Error with INVALID_FILENAME, and if the name
   * is to longa Gio::Error with FILENAME_TOO_LONG will be thrown.
   * Other errors are possible too, and depend on what kind of
   * filesystem the file is on.
   *
   * Note that in many non-local file cases read and write streams are not
   * supported, so make sure you really need to do read and write streaming,
   * rather than just opening for reading or writing.
   *
   * @param cancellable A Cancellable object which can be used to cancel the operation.
   * @param flags a set of CreateFlags.
   * @return A FileOutputStream for the newly created file.
   *
   * @throws Gio::Error
   */
  auto create_file_readwrite(const Glib::RefPtr<Cancellable>& cancellable, CreateFlags flags = CreateFlags::NONE) -> Glib::RefPtr<FileIOStream>;

  /** Creates a new file and returns a stream for reading and writing to it.
   * The file must not already exist.
   *
   * By default files created are generally readable by everyone,
   * but if you pass CreateFlags::PRIVATE in @a flags the file
   * will be made readable only to the current user, to the level that
   * is supported on the target filesystem.
   *
   * If a file with this name already exists a Gio::Error with EXISTS
   * will be thrown. If the file is a directory a Gio::Error with IS_DIRECTORY
   * will be thrown.
   *
   * Some filesystems don't allow all filenames, and may
   * throw a Gio::Error with INVALID_FILENAME, and if the name
   * is to longa Gio::Error with FILENAME_TOO_LONG will be thrown.
   * Other errors are possible too, and depend on what kind of
   * filesystem the file is on.
   *
   * Note that in many non-local file cases read and write streams are not
   * supported, so make sure you really need to do read and write streaming,
   * rather than just opening for reading or writing.
   *
   * @param flags a set of CreateFlags.
   * @return A FileOutputStream for the newly created file.
   *
   * @throws Gio::Error
   */
  auto create_file_readwrite(CreateFlags flags = CreateFlags::NONE) -> Glib::RefPtr<FileIOStream>;


  /** Returns an output stream for overwriting the file, possibly creating a backup copy of the file first.
   * This will try to replace the file in the safest way possible so that any errors during the writing will
   * not affect an already existing copy of the file. For instance, for local files it may write to a
   * temporary file and then atomically rename over the destination when the stream is closed.
   *
   * By default files created are generally readable by everyone, but if you pass CreateFlags::PRIVATE in
   * @a flags the file will be made readable only to the current user, to the level that is supported on the
   * target filesystem.
   *
   * The operation can be cancelled by triggering the cancellable object from another thread.
   * If the operation was cancelled, a Gio::Error with CANCELLED will be thrown.
   *
   * If you pass in an etag value, then this value is compared to the current entity tag of the file,
   * and if they differ a Gio::Error with WRONG_ETAG will be thrown. This generally means that the file has
   * been changed since you last read it. You can get the new etag from FileOutputStream::get_etag()
   * after you've finished writing and closed the FileOutputStream. When you load a new file you can
   * use FileInputStream::query_info() to get the etag of the file.
   *
   * If @a make_backup is true, this function will attempt to make a backup of the current file before
   * overwriting it. If this fails aa Gio::Error with CANT_CREATE_BACKUP will be thrown. If you want to replace
   * anyway, try again with @a make_backup set to false.
   *
   * If the file is a directory a Gio::Error with IS_DIRECTORY will be thrown, and if the file is some
   * other form of non-regular file then aa Gio::Error with NOT_REGULAR_FILE will be thrown. Some file
   * systems don't allow all file names, and may throw a Gio::Error with INVALID_FILENAME, and if the
   * name is to longa Gio::Error with FILENAME_TOO_LONG will be thrown. Other errors are possible too, and
   * depend on what kind of filesystem the file is on.
   *
   * @param cancellable A Cancellable object which can be used to cancel the operation.
   * @param etag An optional entity tag for the current Glib::File.
   * @param make_backup <tt>true</tt> if a backup should be created.
   * @param flags A set of CreateFlags.
   * @return A FileOutputStream.
   *
   * @throws Gio::Error
   */
  auto replace(const Glib::RefPtr<Cancellable>& cancellable, const std::string& etag = {}, bool make_backup = false, CreateFlags flags = CreateFlags::NONE) -> Glib::RefPtr<FileOutputStream>;

  /** Returns an output stream for overwriting the file, possibly creating a backup copy of the file first.
   * This will try to replace the file in the safest way possible so that any errors during the writing will
   * not affect an already existing copy of the file. For instance, for local files it may write to a
   * temporary file and then atomically rename over the destination when the stream is closed.
   *
   * By default files created are generally readable by everyone, but if you pass CreateFlags::PRIVATE in
   * @a flags the file will be made readable only to the current user, to the level that is supported on the
   * target filesystem.
   *
   * If you pass in an etag value, then this value is compared to the current entity tag of the file,
   * and if they differ a Gio::Error with WRONG_ETAG will be thrown. This generally means that the file has
   * been changed since you last read it. You can get the new etag from FileOutputStream::get_etag()
   * after you've finished writing and closed the FileOutputStream. When you load a new file you can
   * use FileInputStream::query_info() to get the etag of the file.
   *
   * If @a make_backup is true, this function will attempt to make a backup of the current file before
   * overwriting it. If this fails aa Gio::Error with CANT_CREATE_BACKUP will be thrown. If you want to replace
   * anyway, try again with @a make_backup set to false.
   *
   * If the file is a directory a Gio::Error with IS_DIRECTORY will be thrown, and if the file is some
   * other form of non-regular file then aa Gio::Error with NOT_REGULAR_FILE will be thrown. Some file
   * systems don't allow all file names, and may throw a Gio::Error with INVALID_FILENAME, and if the
   * name is to longa Gio::Error with FILENAME_TOO_LONG will be thrown. Other errors are possible too, and
   * depend on what kind of filesystem the file is on.
   *
   * @param etag An optional entity tag for the current Glib::File.
   * @param make_backup <tt>true</tt> if a backup should be created.
   * @param flags A set of CreateFlags.
   * @return A FileOutputStream.
   *
   * @throws Gio::Error
   */
  auto replace(const std::string& etag = {}, bool make_backup = false, CreateFlags flags = CreateFlags::NONE) -> Glib::RefPtr<FileOutputStream>;


  /** Asynchronously opens the file for appending.
   * For more details, see append_to() which is the synchronous version of this call.
   *
   * When the operation is finished, @a slot will be called. You can then call append_to_finish() to get the result of the operation.
   * @param slot A callback slot which will be called when the request is satisfied.
   * @param cancellable A Cancellable object which can be used to cancel the operation.
   * @param flags a set of CreateFlags.
   * @param io_priority The I/O priority of the request.
   */
  void append_to_async(const SlotAsyncReady& slot, const Glib::RefPtr<Cancellable>& cancellable, CreateFlags flags = CreateFlags::NONE, int io_priority = Glib::PRIORITY_DEFAULT);

  /** Asynchronously opens the file for appending.
   * For more details, see append_to() which is the synchronous version of this call.
   *
   * When the operation is finished, @a slot will be called. You can then call append_to_finish() to get the result of the operation.
   * @param slot A callback slot which will be called when the request is satisfied.
   * @param flags a set of CreateFlags.
   * @param io_priority The I/O priority of the request.
   */
  void append_to_async(const SlotAsyncReady& slot, CreateFlags flags = CreateFlags::NONE, int io_priority = Glib::PRIORITY_DEFAULT);


  /** Finishes an asynchronous file append operation started with
   * g_file_append_to_async().
   *
   * @param res AsyncResult.
   * @return A valid FileOutputStream
   * or <tt>nullptr</tt> on error.
   * Free the returned object with Glib::object_unref().
   *
   * @throws Glib::Error
   */
  auto append_to_finish(const Glib::RefPtr<AsyncResult>& res) -> Glib::RefPtr<FileOutputStream>;

  //We renamed this to create_file_async from (g_file_create_async() and g_file_create_readwrite_async), to avoid confusion with static create() methods,
  //but I would still like to choose a different word, but can't think of a good one. murrayc. See also create_file().

  /** Asynchronously creates a new file and returns an output stream for writing to it. The file must not already exist.
   * For more details, see create_file() which is the synchronous version of this call.
   *
   * When the operation is finished, @a slot will be called. You can then call create_file_finish() to get the result of the operation.
   *
   * @param slot A callback slot which will be called when the request is satisfied.
   * @param cancellable A Cancellable object which can be used to cancel the operation.
   * @param flags a set of CreateFlags.
   * @param io_priority The I/O priority of the request.
   */
  void create_file_async(const SlotAsyncReady& slot, const Glib::RefPtr<Cancellable>& cancellable, CreateFlags flags = CreateFlags::NONE, int io_priority = Glib::PRIORITY_DEFAULT);

  /** Asynchronously creates a new file and returns an output stream for writing to it. The file must not already exist.
   * For more details, see create_file() which is the synchronous version of this call.
   *
   * When the operation is finished, @a slot will be called. You can then call create_file_finish() to get the result of the operation.
   *
   * @param slot A callback slot which will be called when the request is satisfied.
   * @param flags a set of CreateFlags.
   * @param io_priority The I/O priority of the request.
   */
  void create_file_async(const SlotAsyncReady& slot, CreateFlags flags = CreateFlags::NONE, int io_priority = Glib::PRIORITY_DEFAULT);


  /** Finishes an asynchronous file create operation started with
   * g_file_create_async().
   *
   * @param res A AsyncResult.
   * @return A FileOutputStream or <tt>nullptr</tt> on error.
   * Free the returned object with Glib::object_unref().
   *
   * @throws Glib::Error
   */
  auto create_file_finish(const Glib::RefPtr<AsyncResult>& res) -> Glib::RefPtr<FileOutputStream>;


  /** Asynchronously creates a new file and returns a stream for reading and
   * writing to it. The file must not already exist.
   *
   * For more details, see create_file_readwrite() which is the synchronous version of this call.
   *
   * When the operation is finished, @a slot will be called. You can then call create_file_readwrite_finish() to get the result of the operation.
   *
   * @param slot A callback slot which will be called when the request is satisfied.
   * @param cancellable A Cancellable object which can be used to cancel the operation.
   * @param flags a set of CreateFlags.
   * @param io_priority The I/O priority of the request.
   *
   * @newin{2,24}
   */
  void create_file_readwrite_async(const SlotAsyncReady& slot, const Glib::RefPtr<Cancellable>& cancellable, CreateFlags flags = CreateFlags::NONE, int io_priority = Glib::PRIORITY_DEFAULT);

  /** Asynchronously creates a new file and returns a stream for reading and
   * writing to it. The file must not already exist.
   *
   * For more details, see create_file_readwrite() which is the synchronous version of this call.
   *
   * When the operation is finished, @a slot will be called. You can then call create_file_readwrite_finish() to get the result of the operation.
   *
   * @param slot A callback slot which will be called when the request is satisfied.
   * @param flags a set of CreateFlags.
   * @param io_priority The I/O priority of the request.
   *
   * @newin{2,24}
   */
  void create_file_readwrite_async(const SlotAsyncReady& slot, CreateFlags flags = CreateFlags::NONE, int io_priority = Glib::PRIORITY_DEFAULT);


  /** Finishes an asynchronous file create operation started with
   * g_file_create_readwrite_async().
   *
   * @newin{2,22}
   *
   * @param res A AsyncResult.
   * @return A FileIOStream or <tt>nullptr</tt> on error.
   * Free the returned object with Glib::object_unref().
   *
   * @throws Glib::Error
   */
  auto create_file_readwrite_finish(const Glib::RefPtr<AsyncResult>& res) -> Glib::RefPtr<FileIOStream>;

  /** Asyncronously overwrites the file, replacing the contents, possibly creating a backup copy of the file first.
   * For more details, see replace() which is the synchronous version of this call.
   * When the operation is finished, @a slot will be called. You can then call replace_finish() to get the result of the operation.
   *
   * @param slot A callback slot which will be called when the request is satisfied.
   * @param cancellable A Cancellable object which can be used to cancel the operation.
   * @param etag An entity tag for the current Gio::File.
   * @param make_backup true if a backup of the existing file should be made.
   * @param flags A set of CreateFlags.
   * @param io_priority The I/O priority of the request.
   */
  void replace_async(const SlotAsyncReady& slot, const Glib::RefPtr<Cancellable>& cancellable, const std::string& etag = {}, bool make_backup = false, CreateFlags flags = CreateFlags::NONE, int io_priority = Glib::PRIORITY_DEFAULT);

  /** Asyncronously overwrites the file, replacing the contents, possibly creating a backup copy of the file first.
   * For more details, see replace() which is the synchronous version of this call.
   * When the operation is finished, @a slot will be called. You can then call replace_finish() to get the result of the operation.
   *
   * @param slot A callback slot which will be called when the request is satisfied.
   * @param etag An entity tag for the current Gio::File.
   * @param make_backup true if a backup of the existing file should be made.
   * @param flags A set of CreateFlags.
   * @param io_priority The I/O priority of the request.
   */
  void replace_async(const SlotAsyncReady& slot, const std::string& etag = {}, bool make_backup = false, CreateFlags flags = CreateFlags::NONE, int io_priority = Glib::PRIORITY_DEFAULT);


  /** Finishes an asynchronous file replace operation started with
   * g_file_replace_async().
   *
   * @param res A AsyncResult.
   * @return A FileOutputStream, or <tt>nullptr</tt> on error.
   * Free the returned object with Glib::object_unref().
   *
   * @throws Glib::Error
   */
  auto replace_finish(const Glib::RefPtr<AsyncResult>& res) -> Glib::RefPtr<FileOutputStream>;


  /** Opens an existing file for reading and writing. The result is
   * a FileIOStream that can be used to read and write the contents
   * of the file.
   *
   * If @a cancellable is not <tt>nullptr</tt>, then the operation can be cancelled
   * by triggering the cancellable object from another thread. If the
   * operation was cancelled, the error Gio::Error::CANCELLED will be
   * returned.
   *
   * If the file does not exist, the Gio::Error::NOT_FOUND error will
   * be returned. If the file is a directory, the Gio::Error::IS_DIRECTORY
   * error will be returned. Other errors are possible too, and depend on
   * what kind of filesystem the file is on. Note that in many non-local
   * file cases read and write streams are not supported, so make sure you
   * really need to do read and write streaming, rather than just opening
   * for reading or writing.
   *
   * @newin{2,22}
   *
   * @param cancellable A Cancellable.
   * @return FileIOStream or <tt>nullptr</tt> on error.
   * Free the returned object with Glib::object_unref().
   *
   * @throws Glib::Error
   */
  auto open_readwrite(const Glib::RefPtr<Cancellable>& cancellable) -> Glib::RefPtr<FileIOStream>;

  /// A open_readwrite() convenience overload.
  auto open_readwrite() -> Glib::RefPtr<FileIOStream>;

  /** Opens an existing file for reading and writing.
   * The result is a FileIOStream that can be used to read and write the contents of the file.
   *
   * For more details, see open_readwrite() which is the synchronous version of this call.
   * When the operation is finished, @a slot will be called. You can then call open_readwrite_finish() to get the result of the operation.
   * If the file does not exist, a Gio::Error with NOT_FOUND will be thrown.
   * If the file is a directory, a Gio::Error with IS_DIRECTORY will be thrown.
   * Other errors are possible too, and depend on what kind of filesystem the file is on.
   *
   * Note that in many non-local file cases read and write streams are not supported,
   * so make sure you really need to do read and write streaming, rather than
   * just opening for reading or writing.
   *
   * @param slot A callback slot which will be called when the request is satisfied.
   * @param cancellable A Cancellable object which can be used to cancel the operation.
   * @param io_priority The I/O priority of the request.
   *
   * @newin{2,24}
   */
  void open_readwrite_async(const SlotAsyncReady& slot, const Glib::RefPtr<Cancellable>& cancellable, int io_priority = Glib::PRIORITY_DEFAULT);

  /** Opens an existing file for reading and writing.
   * The result is a FileIOStream that can be used to read and write the contents of the file.
   *
   * For more details, see open_readwrite() which is the synchronous version of this call.
   * When the operation is finished, @a slot will be called. You can then call open_readwrite_finish() to get the result of the operation.
   * If the file does not exist, a Gio::Error with NOT_FOUND will be thrown.
   * If the file is a directory, a Gio::Error with IS_DIRECTORY will be thrown.
   * Other errors are possible too, and depend on what kind of filesystem the file is on.
   *
   * Note that in many non-local file cases read and write streams are not supported,
   * so make sure you really need to do read and write streaming, rather than
   * just opening for reading or writing.
   *
   * @param slot A callback slot which will be called when the request is satisfied.
   * @param io_priority The I/O priority of the request.
   *
   * @newin{2,24}
   */
  void open_readwrite_async(const SlotAsyncReady& slot, int io_priority = Glib::PRIORITY_DEFAULT);


  /** Finishes an asynchronous file read operation started with
   * g_file_open_readwrite_async().
   *
   * @newin{2,22}
   *
   * @param res A AsyncResult.
   * @return A FileIOStream or <tt>nullptr</tt> on error.
   * Free the returned object with Glib::object_unref().
   *
   * @throws Glib::Error
   */
  auto open_readwrite_finish(const Glib::RefPtr<AsyncResult>& res) -> Glib::RefPtr<FileIOStream>;

  /** Returns an output stream for overwriting the file in readwrite mode, possibly creating a backup copy of the file first.
   *
   * If the file doesn't exist, it will be created.
   *
   * For details about the behaviour, see replace() which does the same thing but returns an output stream only.
   *
   * Note that in many non-local file cases read and write streams are not supported,
   * so make sure you really need to do read and write streaming,
   * rather than just opening for reading or writing.
   *
   * @param cancellable A Cancellable object which can be used to cancel the operation.
   * @param etag An optional entity tag for the current Glib::File.
   * @param make_backup <tt>true</tt> if a backup should be created.
   * @param flags A set of CreateFlags.
   * @return A FileOutputStream.
   *
   * @throws Gio::Error
   *
   * @newin{2,24}
   */
  auto replace_readwrite(const Glib::RefPtr<Cancellable>& cancellable, const std::string& etag = {}, bool make_backup = false, CreateFlags flags = CreateFlags::NONE) -> Glib::RefPtr<FileIOStream>;


  /** Returns an output stream for overwriting the file in readwrite mode, possibly creating a backup copy of the file first.
   *
   * If the file doesn't exist, it will be created.
   *
   * For details about the behaviour, see replace() which does the same thing but returns an output stream only.
   *
   * Note that in many non-local file cases read and write streams are not supported,
   * so make sure you really need to do read and write streaming,
   * rather than just opening for reading or writing.
   *
   * @param etag An optional entity tag for the current Glib::File.
   * @param make_backup <tt>true</tt> if a backup should be created.
   * @param flags A set of CreateFlags.
   * @return A FileOutputStream.
   *
   * @throws Gio::Error
   *
   * @newin{2,24}
   */
  auto replace_readwrite(const std::string& etag = {}, bool make_backup = false, CreateFlags flags = CreateFlags::NONE) -> Glib::RefPtr<FileIOStream>;


  /** Asyncronously overwrites the file in read-write mode, replacing the contents, possibly creating a backup copy of the file first.
   *
   * For more details, see replace_readwrite() which is the synchronous version of this call.
   *
   * When the operation is finished, @a slot will be called. You can then call replace_readwrite_finish() to get the result of the operation.
   *
   * @param slot A callback slot which will be called when the request is satisfied.
   * @param cancellable A Cancellable object which can be used to cancel the operation.
   * @param etag An entity tag for the current Gio::File.
   * @param make_backup true if a backup of the existing file should be made.
   * @param flags A set of CreateFlags.
   * @param io_priority The I/O priority of the request.
   *
   * @newin{2,24}
   */
  void replace_readwrite_async(const SlotAsyncReady& slot, const Glib::RefPtr<Cancellable>& cancellable, const std::string& etag = {}, bool make_backup = false, CreateFlags flags = CreateFlags::NONE, int io_priority = Glib::PRIORITY_DEFAULT);

  /** Asyncronously overwrites the file in read-write mode, replacing the contents, possibly creating a backup copy of the file first.
   *
   * For more details, see replace_readwrite() which is the synchronous version of this call.
   * When the operation is finished, @a slot will be called. You can then call replace_readwrite_finish() to get the result of the operation.
   *
   * @param slot A callback slot which will be called when the request is satisfied.
   * @param etag An entity tag for the current Gio::File.
   * @param make_backup true if a backup of the existing file should be made.
   * @param flags A set of CreateFlags.
   * @param io_priority The I/O priority of the request.
   *
   * @newin{2,24}
   */
  void replace_readwrite_async(const SlotAsyncReady& slot, const std::string& etag = {}, bool make_backup = false, CreateFlags flags = CreateFlags::NONE, int io_priority = Glib::PRIORITY_DEFAULT);


  /** Finishes an asynchronous file replace operation started with
   * g_file_replace_readwrite_async().
   *
   * @newin{2,22}
   *
   * @param res A AsyncResult.
   * @return A FileIOStream, or <tt>nullptr</tt> on error.
   * Free the returned object with Glib::object_unref().
   *
   * @throws Glib::Error
   */
  auto replace_readwrite_finish(const Glib::RefPtr<AsyncResult>& res) -> Glib::RefPtr<FileIOStream>;

  /** Gets the requested information about the file. The result
   * is a FileInfo object that contains key-value attributes (such as the  type or size
   * of the file).
   *
   * The @a attribute value is a string that specifies the file attributes that
   * should be gathered. It is not an error if it's not possible to read a particular
   * requested attribute from a file - it just won't be set. @a attribute should
   * be a comma-separated list of attribute or attribute wildcards. The wildcard "*"
   * means all attributes, and a wildcard like "standard::*" means all attributes in the standard
   * namespace. An example attribute query be "standard::*,owner::user".
   * The standard attributes are available as defines, like G_FILE_ATTRIBUTE_STANDARD_NAME.
   *
   * The operation can be cancelled by
   * triggering the cancellable object from another thread. If the operation
   * was cancelled, a Gio::Error with CANCELLED will be thrown.
   *
   * For symlinks, normally the information about the target of the
   * symlink is returned, rather than information about the symlink itself.
   * However if you pass FileQueryInfoFlags::NOFOLLOW_SYMLINKS in @a flags the
   * information about the symlink itself will be returned. Also, for symlinks
   * that point to non-existing files the information about the symlink itself
   * will be returned.
   *
   * If the file does not exist, a Gio::Error with NOT_FOUND will be thrown.
   * Other errors are possible too, and depend on what kind of filesystem the file is on.
   *
   * @param cancellable A Cancellable object.
   * @param attributes: An attribute query string.
   * @param flags: A set of FileQueryInfoFlags.
   * @result a FileInfo for the file, or an empty RefPtr on error.
   *
   * @throws Gio::Error
   */
  auto query_info(const Glib::RefPtr<Cancellable>& cancellable, const std::string& attributes = "*", FileQueryInfoFlags flags = FileQueryInfoFlags::NONE) const -> Glib::RefPtr<FileInfo>;

  /** Gets the requested information about the file. The result
   * is a FileInfo object that contains key-value attributes (such as the  type or size
   * of the file).
   *
   * The @a attribute value is a string that specifies the file attributes that
   * should be gathered. It is not an error if it's not possible to read a particular
   * requested attribute from a file - it just won't be set. @a attribute should
   * be a comma-separated list of attribute or attribute wildcards. The wildcard "*"
   * means all attributes, and a wildcard like "standard::*" means all attributes in the standard
   * namespace. An example attribute query be "standard::*,owner::user".
   * The standard attributes are available as defines, like G_FILE_ATTRIBUTE_STANDARD_NAME.
   *
   * For symlinks, normally the information about the target of the
   * symlink is returned, rather than information about the symlink itself.
   * However if you pass FileQueryInfoFlags::NOFOLLOW_SYMLINKS in @a flags the
   * information about the symlink itself will be returned. Also, for symlinks
   * that point to non-existing files the information about the symlink itself
   * will be returned.
   *
   * If the file does not exist, a Gio::Error with NOT_FOUND will be thrown.
   * Other errors are possible too, and depend on what kind of filesystem the file is on.
   *
   * @param attributes: An attribute query string.
   * @param flags: A set of FileQueryInfoFlags.
   * @result a FileInfo for the file, or an empty RefPtr on error.
   *
   * @throws Gio::Error
   */
  auto query_info(const std::string& attributes = "*", FileQueryInfoFlags flags = FileQueryInfoFlags::NONE) const -> Glib::RefPtr<FileInfo>;


  /** Utility function to check if a particular file exists. This is
   * implemented using query_info() and as such does blocking I/O.
   *
   * Note that in many cases it is racy to first check for file existence
   * and then execute something based on the outcome of that, because the
   * file might have been created or removed in between the operations. The
   * general approach to handling that is to not check, but just do the
   * operation and handle the errors as they come.
   *
   * As an example of race-free checking, take the case of reading a file, and
   * if it doesn't exist, creating it. There are two racy versions: read it, and
   * on error create it; and: check if it exists, if not create it. These
   * can both result in two processes creating the file (with perhaps a partially
   * written file as the result). The correct approach is to always try to create
   * the file with File::create() which will either atomically create the file
   * or fail with a Gio::Error exception with EXISTS.
   *
   * However, in many cases an existence check is useful in a user
   * interface, for instance to make a menu item sensitive/insensitive, so that
   * you don't have to fool users that something is possible and then just show
   * and error dialog. If you do this, you should make sure to also handle the
   * errors that can happen due to races when you execute the operation.
   *
   * @param cancellable Optional Cancellable object, <tt>nullptr</tt> to ignore.
   * @return <tt>true</tt> if the file exists (and can be detected without error), <tt>false</tt> otherwise (or if cancelled).
   */
  auto query_exists(const Glib::RefPtr<Cancellable>& cancellable) const -> bool;

  /// A query_exists() convenience overload.
  auto query_exists() const -> bool;

  //We cannot use the {?} format here because we want a default value for flags, but gmmproc then generates a method with a default value for flags when it is not the last parameter.

  /** Utility function to inspect the FileType of a file. This is
   * implemented using g_file_query_info() and as such does blocking I/O.
   *
   * The primary use case of this method is to check if a file is
   * a regular file, directory, or symlink.
   *
   * @newin{2,18}
   *
   * @param flags A set of FileQueryInfoFlags passed to g_file_query_info().
   * @param cancellable Optional Cancellable object,
   * <tt>nullptr</tt> to ignore.
   * @return The FileType of the file and Gio::FileType::UNKNOWN
   * if the file does not exist.
   */
  auto query_file_type(FileQueryInfoFlags flags, const Glib::RefPtr<Cancellable>& cancellable) const -> FileType;

  /** Utility function to inspect the FileType of a file. This is
   * implemented using query_info() and as such does blocking I/O.
   *
   * The primary use case of this method is to check if a file is a regular file,
   * directory, or symlink.
   *
   * @param flags: a set of FileQueryInfoFlags passed to query_info().
   * @result The FileType of the file, or FileType::UNKNOWN if the file does not exist.
   *
   * @newin{2,18}
   */
   auto query_file_type(FileQueryInfoFlags flags = FileQueryInfoFlags::NONE) const -> FileType;

  /** Asynchronously gets the requested information about specified file. The result is a FileInfo object that contains key-value attributes (such as type or size for the file).
   *
   * For more details, see query_info() which is the synchronous version of this call.
   * When the operation is finished, @a slot will be called. You can then call query_info_finish() to get the result of the operation.
   *
   * @param slot A callback slot which will be called when the request is satisfied.
   * @param cancellable A Cancellable object which can be used to cancel the operation.
   * @param attributes An attribute query string.
   * @param flags A set of FileQueryInfoFlags.
   * @param io_priority The I/O priority of the request.
   */
  void query_info_async(const SlotAsyncReady& slot, const Glib::RefPtr<Cancellable>& cancellable, const std::string& attributes = "*", FileQueryInfoFlags flags = FileQueryInfoFlags::NONE, int io_priority = Glib::PRIORITY_DEFAULT) const;

  /** Asynchronously gets the requested information about specified file. The result is a FileInfo object that contains key-value attributes (such as type or size for the file).
   *
   * For more details, see query_info() which is the synchronous version of this call.
   * When the operation is finished, @a slot will be called. You can then call query_info_finish() to get the result of the operation.
   *
   * @param slot A callback slot which will be called when the request is satisfied.
   * @param attributes An attribute query string.
   * @param flags A set of FileQueryInfoFlags.
   * @param io_priority The I/O priority of the request.
   */
  void query_info_async(const SlotAsyncReady& slot, const std::string& attributes = "*", FileQueryInfoFlags flags = FileQueryInfoFlags::NONE, int io_priority = Glib::PRIORITY_DEFAULT) const;


  /** Finishes an asynchronous file info query.
   * See g_file_query_info_async().
   *
   * @param res A AsyncResult.
   * @return FileInfo for given @a file
   * or <tt>nullptr</tt> on error. Free the returned object with
   * Glib::object_unref().
   *
   * @throws Glib::Error
   */
  auto query_info_finish(const Glib::RefPtr<AsyncResult>& res) -> Glib::RefPtr<FileInfo>;

  /** Similar to query_info(), but obtains information
   * about the filesystem the file is on, rather than the file itself.
   * For instance the amount of space availible and the type of
   * the filesystem.
   *
   * The @a attribute  value is a string that specifies the file attributes that
   * should be gathered. It is not an error if its not possible to read a particular
   * requested attribute from a file, it just won't be set. @a attribute  should
   * be a comma-separated list of attribute or attribute wildcards. The wildcard "*"
   * means all attributes, and a wildcard like "fs:*" means all attributes in the fs
   * namespace. The standard namespace for filesystem attributes is "fs".
   * Common attributes of interest are FILE_ATTRIBUTE_FILESYSTEM_SIZE
   * (the total size of the filesystem in bytes), FILE_ATTRIBUTE_FILESYSTEM_FREE (number of
   * bytes availible), and FILE_ATTRIBUTE_FILESYSTEM_TYPE (type of the filesystem).
   *
   * The operation can be cancelled by
   * triggering the cancellable object from another thread. If the operation
   * was cancelled, a Gio::Error with CANCELLED will be thrown.
   *
   * If the file does not exist, a Gio::Error with NOT_FOUND will be thrown.
   * Other errors are possible too, and depend on what kind of filesystem the file is on.
   *
   * @param cancellable A Cancellable object.
   * @param attributes An attribute query string.
   * @return A FileInfo or an empty RefPtr if there was an error.
   *
   * @throws Gio::Error
   */
  auto query_filesystem_info(const Glib::RefPtr<Cancellable>& cancellable, const std::string& attributes = "*") -> Glib::RefPtr<FileInfo>;

  /** Similar to query_info(), but obtains information
   * about the filesystem the file is on, rather than the file itself.
   * For instance the amount of space availible and the type of
   * the filesystem.
   *
   * The @a attribute  value is a string that specifies the file attributes that
   * should be gathered. It is not an error if its not possible to read a particular
   * requested attribute from a file, it just won't be set. @a attribute  should
   * be a comma-separated list of attribute or attribute wildcards. The wildcard "*"
   * means all attributes, and a wildcard like "fs:*" means all attributes in the fs
   * namespace. The standard namespace for filesystem attributes is "fs".
   * Common attributes of interest are FILE_ATTRIBUTE_FILESYSTEM_SIZE
   * (the total size of the filesystem in bytes), FILE_ATTRIBUTE_FILESYSTEM_FREE (number of
   * bytes availible), and FILE_ATTRIBUTE_FILESYSTEM_TYPE (type of the filesystem).
   *
   * If the file does not exist, a Gio::Error with NOT_FOUND will be thrown.
   * Other errors are possible too, and depend on what kind of filesystem the file is on.
   *
   * @param attributes An attribute query string.
   * @return A FileInfo or an empty RefPtr if there was an error.
   *
   * @throws Gio::Error
   */
  auto query_filesystem_info(const std::string& attributes = "*") -> Glib::RefPtr<FileInfo>;


  /** Gets a Mount for the File.
   *
   * If the FileIface for @a file does not have a mount (e.g. possibly a
   * remote share), a Gio::Error will be thrown with NOT_FOUND and <tt>nullptr</tt>
   * will be returned.
   *
   * The operation can be cancelled by
   * triggering the cancellable object from another thread. If the operation
   * was cancelled, a Gio::Error will be thrown with CANCELLED.
   *
   * @param cancellable Cancellable object.
   * @return A Mount where the @a file is located or <tt>nullptr</tt> on error.
   *
   * @throws Glib::Error
   */
  auto find_enclosing_mount(const Glib::RefPtr<Cancellable>& cancellable) -> Glib::RefPtr<Mount>;

  /// A find_enclosing_mount() convenience overload.
  auto find_enclosing_mount() -> Glib::RefPtr<Mount>;

  /** Asynchronously gets the requested information about the filesystem
   * that the file is on. The result is a FileInfo object
   * that contains key-value attributes (such as type or size for the
   * file).
   *
   * For more details, see query_filesystem_info() which is the synchronous version of this call.
   *
   * When the operation is finished, @a slot will be called. You can then call query_filesystem_info_finish() to get the result of the operation.
   *
   * @param slot A callback slot which will be called when the request is satisfied.
   * @param cancellable A Cancellable object which can be used to cancel the operation.
   * @param attributes An attribute query string.
   * @param io_priority The I/O priority of the request.
   */
  void query_filesystem_info_async(const SlotAsyncReady& slot, const Glib::RefPtr<Cancellable>& cancellable, const std::string& attributes = "*", int io_priority = Glib::PRIORITY_DEFAULT) const;

  /** Asynchronously gets the requested information about the filesystem
   * that the file is on. The result is a FileInfo object
   * that contains key-value attributes (such as type or size for the
   * file).
   *
   * For more details, see query_filesystem_info() which is the synchronous version of this call.
   *
   * When the operation is finished, @a slot will be called. You can then call query_filesystem_info_finish() to get the result of the operation.
   *
   * @param slot A callback slot which will be called when the request is satisfied.
   * @param attributes An attribute query string.
   * @param io_priority The I/O priority of the request.
   */
  void query_filesystem_info_async(const SlotAsyncReady& slot, const std::string& attributes = "*", int io_priority = Glib::PRIORITY_DEFAULT) const;


  /** Finishes an asynchronous filesystem info query.
   * See g_file_query_filesystem_info_async().
   *
   * @param res A AsyncResult.
   * @return FileInfo for given @a file
   * or <tt>nullptr</tt> on error.
   * Free the returned object with Glib::object_unref().
   *
   * @throws Glib::Error
   */
  auto query_filesystem_info_finish(const Glib::RefPtr<AsyncResult>& res) -> Glib::RefPtr<FileInfo>;

  /** Asynchronously gets the mount for the file.
   *
   * For more details, see find_enclosing_mount() which is
   * the synchronous version of this call.
   *
   * When the operation is finished, @a slot will be called. You can then call
   * find_enclosing_mount_finish() to get the result of the operation.
   *
   * @param slot A callback slot which will be called when the request is satisfied.
   * @param cancellable A Cancellable object.
   * @param io_priority The I/O priority of the request.
   */
  void find_enclosing_mount_async(const SlotAsyncReady& slot, const Glib::RefPtr<Cancellable>& cancellable, int io_priority = Glib::PRIORITY_DEFAULT);

  /** Asynchronously gets the mount for the file.
   *
   * For more details, see find_enclosing_mount() which is
   * the synchronous version of this call.
   *
   * When the operation is finished, @a slot will be called. You can then call
   * find_enclosing_mount_finish() to get the result of the operation.
   *
   * @param slot A callback slot which will be called when the request is satisfied.
   * @param io_priority The I/O priority of the request.
   */
  void find_enclosing_mount_async(const SlotAsyncReady& slot, int io_priority = Glib::PRIORITY_DEFAULT);


  /** Finishes an asynchronous find mount request.
   * See g_file_find_enclosing_mount_async().
   *
   * @param res A AsyncResult.
   * @return Mount for given @a file or <tt>nullptr</tt> on error.
   * Free the returned object with Glib::object_unref().
   *
   * @throws Glib::Error
   */
  auto find_enclosing_mount_finish(const Glib::RefPtr<AsyncResult>& res) -> Glib::RefPtr<Mount>;

  /** Gets the requested information about the files in a directory. The result
   * is a FileEnumerator object that will give out FileInfo objects for
   * all the files in the directory.
   *
   * The @a attribute  value is a string that specifies the file attributes that
   * should be gathered. It is not an error if its not possible to read a particular
   * requested attribute from a file, it just won't be set. @a attribute  should
   * be a comma-separated list of attribute or attribute wildcards. The wildcard "*"
   * means all attributes, and a wildcard like "standard::*" means all attributes in the standard
   * namespace. An example attribute query be "standard::*,owner::user".
   * The standard attributes are availible as defines, like FILE_ATTRIBUTE_STANDARD_NAME.
   *
   * The operation can be cancelled by
   * triggering the cancellable object from another thread. If the operation
   * was cancelled, a Gio::Error with CANCELLED will be thrown.
   *
   * If the file does not exist, a Gio::Error with NOT_FOUND will be thrown.
   * If the file is not a directory, a Gio::Error with NOT_DIRECTORY will be thrown.
   * Other errors are possible too.
   *
   * @param cancellable A Cancellable object.
   * @param attributes An attribute query string.
   * @param flags A set of FileQueryInfoFlags.
   * @return A FileEnumerator if successful.
   *
   * @throws Gio::Error
   */
  auto enumerate_children(const Glib::RefPtr<Cancellable>& cancellable, const std::string& attributes = "*", FileQueryInfoFlags flags = FileQueryInfoFlags::NONE) -> Glib::RefPtr<FileEnumerator>;


  /** Gets the requested information about the files in a directory. The result
   * is a FileEnumerator object that will give out FileInfo objects for
   * all the files in the directory.
   *
   * The @a attribute  value is a string that specifies the file attributes that
   * should be gathered. It is not an error if its not possible to read a particular
   * requested attribute from a file, it just won't be set. @a attribute  should
   * be a comma-separated list of attribute or attribute wildcards. The wildcard "*"
   * means all attributes, and a wildcard like "standard::*" means all attributes in the standard
   * namespace. An example attribute query be "standard::*,owner::user".
   * The standard attributes are availible as defines, like FILE_ATTRIBUTE_STANDARD_NAME.
   *
   * If the file does not exist, a Gio::Error with NOT_FOUND will be thrown.
   * If the file is not a directory, a Gio::Error with NOT_DIRECTORY will be thrown.
   * Other errors are possible too.
   *
   * @param attributes An attribute query string.
   * @param flags A set of FileQueryInfoFlags.
   * @return A FileEnumerator if successful.
   *
   * @throws Gio::Error
   */
  auto enumerate_children(const std::string& attributes = "*", FileQueryInfoFlags flags = FileQueryInfoFlags::NONE) -> Glib::RefPtr<FileEnumerator>;


  /** Asynchronously gets the requested information about the files in a directory. The result is a GFileEnumerator object that will give out GFileInfo objects for all the files in the directory.
   *
   * For more details, see enumerate_children() which is the synchronous version of this call.
   * When the operation is finished, @a slot will be called. You can then call enumerate_children_finish() to get the result of the operation.
   *
   * @param slot A callback slot which will be called when the request is satisfied.
   * @param cancellable A Cancellable object which can be used to cancel the operation.
   * @param attributes An attribute query string.
   * @param flags A set of FileQueryInfoFlags.
   * @param io_priority The I/O priority of the request.
   */
  void enumerate_children_async(const SlotAsyncReady& slot, const Glib::RefPtr<Cancellable>& cancellable, const std::string& attributes = "*", FileQueryInfoFlags flags = FileQueryInfoFlags::NONE, int io_priority = Glib::PRIORITY_DEFAULT);

  /** Asynchronously gets the requested information about the files in a directory. The result is a GFileEnumerator object that will give out GFileInfo objects for all the files in the directory.
   *
   * For more details, see enumerate_children() which is the synchronous version of this call.
   * When the operation is finished, @a slot will be called. You can then call enumerate_children_finish() to get the result of the operation.
   *
   * @param slot A callback slot which will be called when the request is satisfied.
   * @param attributes An attribute query string.
   * @param flags A set of FileQueryInfoFlags.
   * @param io_priority The I/O priority of the request.
   */
  void enumerate_children_async(const SlotAsyncReady& slot, const std::string& attributes = "*", FileQueryInfoFlags flags = FileQueryInfoFlags::NONE, int io_priority = Glib::PRIORITY_DEFAULT);


  /** Finishes an async enumerate children operation.
   * See g_file_enumerate_children_async().
   *
   * @param res A AsyncResult.
   * @return A FileEnumerator or <tt>nullptr</tt>
   * if an error occurred.
   * Free the returned object with Glib::object_unref().
   *
   * @throws Glib::Error
   */
  auto enumerate_children_finish(const Glib::RefPtr<AsyncResult>& res) -> Glib::RefPtr<FileEnumerator>;


  /** Renames @a file to the specified display name.
   *
   * The display name is converted from UTF8 to the correct encoding for the target
   * filesystem if possible and the @a file is renamed to this.
   *
   * If you want to implement a rename operation in the user interface the edit name
   * (G_FILE_ATTRIBUTE_STANDARD_EDIT_NAME) should be used as the initial value in the rename
   * widget, and then the result after editing should be passed to g_file_set_display_name().
   *
   * On success the resulting converted filename is returned.
   *
   * The operation can be cancelled by
   * triggering the cancellable object from another thread. If the operation
   * was cancelled, a Gio::Error will be thrown with CANCELLED.
   *
   * @param display_name A string.
   * @param cancellable Cancellable object.
   * @return A File specifying what @a file was renamed to, or <tt>nullptr</tt> if there was an error.
   *
   * @throws Glib::Error
   */
  auto set_display_name(const Glib::ustring& display_name, const Glib::RefPtr<Cancellable>& cancellable) -> Glib::RefPtr<File>;

  /// A set_display_name() convenience overload.
  auto set_display_name(const Glib::ustring& display_name) -> Glib::RefPtr<File>;

  /** Asynchronously sets the display name for a given Gio::File. For the synchronous version of this function, see set_display_name().
   * When the operation is finished, @a slot will be called. You can then call set_display_name_finish() to get the result of the operation.
   *
   * @param display_name A string.
   * @param slot A callback slot which will be called when the request is satisfied.
   * @param cancellable A Cancellable object which can be used to cancel the operation.
   * @param io_priority The I/O priority of the request.
   */
  void set_display_name_async(const Glib::ustring& display_name, const SlotAsyncReady& slot, const Glib::RefPtr<Cancellable>& cancellable, int io_priority = Glib::PRIORITY_DEFAULT);

  /** Asynchronously sets the display name for a given Gio::File. For the synchronous version of this function, see set_display_name().
   * When the operation is finished, @a slot will be called. You can then call set_display_name_finish() to get the result of the operation.
   *
   * @param display_name A string.
   * @param slot A callback slot which will be called when the request is satisfied.
   * @param io_priority The I/O priority of the request.
   */
  void set_display_name_async(const Glib::ustring& display_name, const SlotAsyncReady& slot, int io_priority = Glib::PRIORITY_DEFAULT);


  /** Finishes setting a display name started with
   * g_file_set_display_name_async().
   *
   * @param res A AsyncResult.
   * @return A File or <tt>nullptr</tt> on error.
   * Free the returned object with Glib::object_unref().
   *
   * @throws Glib::Error
   */
  auto set_display_name_finish(const Glib::RefPtr<AsyncResult>& res) -> Glib::RefPtr<File>;

  //TODO: Remove the bool results from this and other methods that throw an exception.


  /** Deletes a file.
   * If the file is a directory, it will only be deleted if it is empty.
   * The operation can be cancelled by triggering the cancellable object from another thread.
   * If the operation was cancelled, a Gio::Error with CANCELLED will be thrown.
   *
   * @param cancellable A Cancellable object which can be used to cancel the operation.
   * @return <tt>true</tt> if the file was deleted. <tt>false</tt> otherwise.
   */
  auto remove(const Glib::RefPtr<Cancellable>& cancellable) -> bool;

  /// A remove() convenience overload.
  auto remove() -> bool;

   /** Asynchronously delete a file.
    * If the file is a directory, it will
    * only be deleted if it is empty.  This has the same semantics as
    * g_unlink().
    *
    * @param slot_ready A SlotAsyncReady to call when the request is satisfied
    * @param cancellable A Cancellable object which can be used to cancel the operation
    * @param io_priority The I/O priority of the request
    * @newin{2,34}
    */
  void remove_async(const SlotAsyncReady& slot_ready, const Glib::RefPtr<Cancellable>& cancellable, int io_priority = Glib::PRIORITY_DEFAULT);

   /** Asynchronously delete a file.
    * If the file is a directory, it will
    * only be deleted if it is empty.  This has the same semantics as
    * g_unlink().
    *
    * @param slot_ready A SlotAsyncReady to call when the request is satisfied
    * @param io_priority The I/O priority of the request
    * @newin{2,34}
    */
  void remove_async(const SlotAsyncReady& slot_ready, int io_priority = Glib::PRIORITY_DEFAULT);


  /** Finishes deleting a file started with g_file_delete_async().
   *
   * Virtual: delete_file_finish
   * @newin{2,34}
   *
   * @param result A AsyncResult.
   * @return <tt>true</tt> if the file was deleted. <tt>false</tt> otherwise.
   *
   * @throws Glib::Error
   */
  auto remove_finish(const Glib::RefPtr<AsyncResult>& result) -> bool;


  /** Sends @a file to the "Trashcan", if possible. This is similar to
   * deleting it, but the user can recover it before emptying the trashcan.
   * Not all file systems support trashing, so this call can throw a Gio::Error with
   *  NOT_SUPPORTED.
   *
   *
   * The operation can be cancelled by
   * triggering the cancellable object from another thread. If the operation
   * was cancelled, a Gio::Error will be thrown with CANCELLED.
   *
   * @param cancellable Cancellable object.
   * @return <tt>true</tt> on successful trash, <tt>false</tt> otherwise.
   *
   * @throws Glib::Error
   */
  auto trash(const Glib::RefPtr<Cancellable>& cancellable) -> bool;

  /// A trash() convenience overload.
  auto trash() -> bool;

   /** Asynchronously sends the file to the Trash location, if possible.
    *
    * @param slot_ready A SlotAsyncReady to call when the request is satisfied
    * @param cancellable A Cancellable object which can be used to cancel the operation
    * @param io_priority The I/O priority of the request
    * @newin{2,38}
    */
  void trash_async(const SlotAsyncReady& slot_ready, const Glib::RefPtr<Cancellable>& cancellable, int io_priority = Glib::PRIORITY_DEFAULT);

   /** Asynchronously sends the file to the Trash location, if possible.
    *
    * @param slot_ready A SlotAsyncReady to call when the request is satisfied
    * @param io_priority The I/O priority of the request
    * @newin{2,38}
    */
  void trash_async(const SlotAsyncReady& slot_ready, int io_priority = Glib::PRIORITY_DEFAULT);


  /** Finishes an asynchronous file trashing operation, started with
   * g_file_trash_async().
   *
   * Virtual: trash_finish
   * @newin{2,38}
   *
   * @param result A AsyncResult.
   * @return <tt>true</tt> on successful trash, <tt>false</tt> otherwise.
   *
   * @throws Glib::Error
   */
  auto trash_finish(const Glib::RefPtr<AsyncResult>& result) -> bool;


  /** A signal handler would be, for instance:
   * void on_file_progress(goffset current_num_bytes, goffset total_num_bytes);
   */
  using SlotFileProgress = sigc::slot<void(goffset, goffset)>;

  /** Copies the file source to the location specified by destination. Can not handle recursive copies of directories.
   * If the flag CopyFlags::OVERWRITE is specified an already existing destination file is overwritten.
   * If the flag CopyFlags::NOFOLLOW_SYMLINKS is specified then symlinks will be copied as symlinks, otherwise the target of the source symlink will be copied.
   *
   * The operation can be cancelled by triggering the cancellable object from another thread. If the operation was cancelled, a Gio::Error with CANCELLED will be thrown.
   *
   * The operation can be monitored via the @a slot callback.
   *
   * If the source file does not exist then a Gio::Error with NOT_FOUND will be thrown, independent on the status of the destination.
   *
   * If CopyFlags::OVERWRITE is not specified and the target exists, then a Gio::Error with EXISTS will be thrown.
   *
   * If trying to overwrite a file over a directory a Gio::Error with IS_DIRECTORY will be thrown.
   * If trying to overwrite a directory with a directory a Gio::Error with WOULD_MERGE will be thrown.
   *
   * If the source is a directory and the target does not exist, or CopyFlags::OVERWRITE is specified and the target is a file,
   * then a Gio::Error with WOULD_RECURSE will be thrown.
   *
   * If you are interested in copying the Gio::File object itself (not the on-disk file), see File::dup().
   *
   * @throws Gio::Error
   */
  auto copy(const Glib::RefPtr<File>& destination, const SlotFileProgress& slot, const Glib::RefPtr<Cancellable>& cancellable, CopyFlags flags = CopyFlags::NONE) -> bool;

  /** Copies the file source to the location specified by destination. Can not handle recursive copies of directories.
   * If the flag CopyFlags::OVERWRITE is specified an already existing destination file is overwritten.
   * If the flag CopyFlags::NOFOLLOW_SYMLINKS is specified then symlinks will be copied as symlinks, otherwise the target of the source symlink will be copied.
   *
   * The operation can be monitored via the @a slot callback.
   *
   * If the source file does not exist then a Gio::Error with NOT_FOUND will be thrown, independent on the status of the destination.
   *
   * If CopyFlags::OVERWRITE is not specified and the target exists, then a Gio::Error with EXISTS will be thrown.
   *
   * If trying to overwrite a file over a directory a Gio::Error with IS_DIRECTORY will be thrown.
   * If trying to overwrite a directory with a directory a Gio::Error with WOULD_MERGE will be thrown.
   *
   * If the source is a directory and the target does not exist, or CopyFlags::OVERWRITE is specified and the target is a file,
   * then a Gio::Error with WOULD_RECURSE will be thrown.
   *
   * If you are interested in copying the Gio::File object itself (not the on-disk file), see File::dup().
   *
   * @throws Gio::Error
   */
  auto copy(const Glib::RefPtr<File>& destination, const SlotFileProgress& slot, CopyFlags flags = CopyFlags::NONE) -> bool;

  /** Copies the file source to the location specified by destination. Can not handle recursive copies of directories.
   * If the flag CopyFlags::OVERWRITE is specified an already existing destination file is overwritten.
   * If the flag CopyFlags::NOFOLLOW_SYMLINKS is specified then symlinks will be copied as symlinks, otherwise the target of the source symlink will be copied.
   *
   * If the source file does not exist then a Gio::Error with NOT_FOUND will be thrown, independent on the status of the destination.
   *
   * If CopyFlags::OVERWRITE is not specified and the target exists, then a Gio::Error with EXISTS will be thrown.
   *
   * If trying to overwrite a file over a directory a Gio::Error with IS_DIRECTORY will be thrown.
   * If trying to overwrite a directory with a directory a Gio::Error with WOULD_MERGE will be thrown.
   *
   * If the source is a directory and the target does not exist, or CopyFlags::OVERWRITE is specified and the target is a file,
   * then a Gio::Error with WOULD_RECURSE will be thrown.
   *
   * If you are interested in copying the Gio::File object itself (not the on-disk file), see File::dup().
   *
   * @throws Gio::Error
   */
  auto copy(const Glib::RefPtr<File>& destination, CopyFlags flags = CopyFlags::NONE) -> bool;


  /** Copies the file to the location specified by @a destination asynchronously.
   * For details of the behaviour, see copy().
   *
   * When the operation is finished, @a slot_ready will be called.
   * You can then call copy_finish() to get the result of the operation.
   *
   * The function specified by @a slot_progress will be called just like
   * in copy(), however the callback will run in the main loop, not in
   * the thread that is doing the I/O operation.
   *
   * @param destination Destination File
   * @param slot_progress The callback slot to be called with progress information
   * @param slot_ready A SlotAsyncReady to call when the request is satisfied
   * @param cancellable A Cancellable object which can be used to cancel the operation
   * @param flags Set of CopyFlags
   * @param io_priority The I/O priority of the request
   */
  void copy_async(const Glib::RefPtr<File>& destination, const SlotFileProgress& slot_progress, const SlotAsyncReady& slot_ready, const Glib::RefPtr<Cancellable>& cancellable, CopyFlags flags = CopyFlags::NONE, int io_priority = Glib::PRIORITY_DEFAULT);

  /** Copies the file to the location specified by @a destination asynchronously.
   * For details of the behaviour, see copy().
   *
   * When the operation is finished, @a slot_ready will be called.
   * You can then call copy_finish() to get the result of the operation.
   *
   * @param destination Destination File
   * @param slot_ready A SlotAsyncReady to call when the request is satisfied
   * @param cancellable A Cancellable object which can be used to cancel the operation
   * @param flags Set of CopyFlags
   * @param io_priority The I/O priority of the request
   */
  void copy_async(const Glib::RefPtr<File>& destination, const SlotAsyncReady& slot_ready, const Glib::RefPtr<Cancellable>& cancellable, CopyFlags flags = CopyFlags::NONE, int io_priority = Glib::PRIORITY_DEFAULT);

  /** Copies the file to the location specified by @a destination asynchronously.
   * For details of the behaviour, see copy().
   *
   * When the operation is finished, @a slot_ready will be called.
   * You can then call copy_finish() to get the result of the operation.
   *
   * The function specified by @a slot_progress will be called just like
   * in copy(), however the callback will run in the main loop, not in
   * the thread that is doing the I/O operation.
   *
   * @param destination Destination File
   * @param slot_progress The callback slot to be called with progress information
   * @param slot_ready A SlotAsyncReady to call when the request is satisfied
   * @param flags Set of CopyFlags
   * @param io_priority The I/O priority of the request
   */
  void copy_async(const Glib::RefPtr<File>& destination, const SlotFileProgress& slot_progress, const SlotAsyncReady& slot_ready, CopyFlags flags = CopyFlags::NONE, int io_priority = Glib::PRIORITY_DEFAULT);

  /** Copies the file to the location specified by @a destination asynchronously.
   * For details of the behaviour, see copy().
   *
   * When the operation is finished, @a slot_ready will be called.
   * You can then call copy_finish() to get the result of the operation.
   *
   * @param destination Destination File
   * @param slot_ready A SlotAsyncReady to call when the request is satisfied
   * @param flags Set of CopyFlags
   * @param io_priority The I/O priority of the request
   */
  void copy_async(const Glib::RefPtr<File>& destination, const SlotAsyncReady& slot_ready, CopyFlags flags = CopyFlags::NONE, int io_priority = Glib::PRIORITY_DEFAULT);


  /** Finishes copying the file started with g_file_copy_async().
   *
   * @param res A AsyncResult.
   * @return A <tt>true</tt> on success, <tt>false</tt> on error.
   *
   * @throws Glib::Error
   */
  auto copy_finish(const Glib::RefPtr<AsyncResult>& res) -> bool;

  /** Tries to move the file or directory source to the location specified by destination. If native move operations are supported then this is
   * used, otherwise a copy and delete fallback is used. The native implementation may support moving directories (for instance on moves inside
   * the same filesystem), but the fallback code does not.
   *
   * If the flag CopyFlags::OVERWRITE is specified an already existing destination file is overwritten.
   *
   * If the flag CopyFlags::NOFOLLOW_SYMLINKS is specified then symlinks will be copied as symlinks, otherwise the target of the source symlink will be copied.
   *
   * The operation can be cancelled by triggering the cancellable object from another thread. If the operation was cancelled, a Gio::Error with CANCELLED will be thrown.
   *
   * The operation can be monitored via the @a slot callback.
   * If the source file does not exist then a Gio::Error with NOT_FOUND will be thrown, independent on the status of the destination.
   *
   * If G_CopyFlags::OVERWRITE is not specified and the target exists, then a Gio::Error with EXISTS will be thrown.
   *
   * If trying to overwrite a file over a directory a Gio::Error with IS_DIRECTORY will be thrown.
   * If trying to overwrite a directory with a directory a Gio::Error with WOULD_MERGE will be thrown.
   *
   * If the source is a directory and the target does not exist, or CopyFlags::OVERWRITE is specified and the target is a file,
   * then a Gio::Error with WOULD_RECURSE may be thrown (if the native move operation isn't available).
   *
   * @throws Gio::Error
   */
  auto move(const Glib::RefPtr<File>& destination, const SlotFileProgress& slot, const Glib::RefPtr<Cancellable>& cancellable, CopyFlags flags = CopyFlags::NONE) -> bool;

  auto move(const Glib::RefPtr<File>& destination, const SlotFileProgress& slot, CopyFlags flags = CopyFlags::NONE) -> bool;

  auto move(const Glib::RefPtr<File>& destination, CopyFlags flags = CopyFlags::NONE) -> bool;


  /** Asynchronously moves a file source to the location of @a destination.
   *
   * For details of the behaviour, see move().
   *
   * If @a slot_progress is not empty, then that slot will be called just like
   * in move(). The callback will run in the default main context of the thread
   * calling %move_async() — the same context as @a slot_ready is run in.
   *
   * When the operation is finished, @a slot_ready will be called. You can then call
   * move_finish() to get the result of the operation.
   *
   * @newin{2,72}
   *
   * @param destination File pointing to the destination location.
   * @param slot_progress The callback slot to be called with progress information.
   * @param slot_ready A SlotAsyncReady to call when the request is satisfied.
   * @param cancellable A Cancellable object which can be used to cancel the operation.
   * @param flags Set of Gio::File::CopyFlags.
   * @param io_priority The I/O priority of the request.
   */
  void move_async(const Glib::RefPtr<File>& destination, const SlotFileProgress& slot_progress,
    const SlotAsyncReady& slot_ready, const Glib::RefPtr<Cancellable>& cancellable,
    CopyFlags flags = CopyFlags::NONE, int io_priority = Glib::PRIORITY_DEFAULT);

  void move_async(const Glib::RefPtr<File>& destination,
    const SlotAsyncReady& slot_ready, const Glib::RefPtr<Cancellable>& cancellable,
    CopyFlags flags = CopyFlags::NONE, int io_priority = Glib::PRIORITY_DEFAULT);

  void move_async(const Glib::RefPtr<File>& destination, const SlotFileProgress& slot_progress,
    const SlotAsyncReady& slot_ready,
    CopyFlags flags = CopyFlags::NONE, int io_priority = Glib::PRIORITY_DEFAULT);

  void move_async(const Glib::RefPtr<File>& destination,
    const SlotAsyncReady& slot_ready,
    CopyFlags flags = CopyFlags::NONE, int io_priority = Glib::PRIORITY_DEFAULT);


  /** Finishes an asynchronous file movement, started with
   * g_file_move_async().
   *
   * @newin{2,72}
   *
   * @param res A AsyncResult.
   * @return <tt>true</tt> on successful file move, <tt>false</tt> otherwise.
   *
   * @throws Glib::Error
   */
  auto move_finish(const Glib::RefPtr<AsyncResult>& res) -> bool;


  /** Creates a directory.
   *
   * The operation can be cancelled by
   * triggering the cancellable object from another thread. If the operation
   * was cancelled, a Gio::Error will be thrown with CANCELLED.
   *
   * @param cancellable Cancellable object.
   * @return <tt>true</tt> on successful creation, <tt>false</tt> otherwise.
   *
   * @throws Glib::Error
   */
  auto make_directory(const Glib::RefPtr<Cancellable>& cancellable) -> bool;

  /// A make_directory() convenience overload.
  auto make_directory() -> bool;

   /** Asynchronously creates a directory.
    *
    * @param slot_ready A SlotAsyncReady to call when the request is satisfied
    * @param cancellable A Cancellable object which can be used to cancel the operation
    * @param io_priority The I/O priority of the request
    * @newin{2,38}
    */
  void make_directory_async(const SlotAsyncReady& slot_ready, const Glib::RefPtr<Cancellable>& cancellable, int io_priority = Glib::PRIORITY_DEFAULT);

   /** Asynchronously creates a directory.
    *
    * @param slot_ready A SlotAsyncReady to call when the request is satisfied
    * @param io_priority The I/O priority of the request
    * @newin{2,38}
    */
  void make_directory_async(const SlotAsyncReady& slot_ready, int io_priority = Glib::PRIORITY_DEFAULT);


  /** Finishes an asynchronous directory creation, started with
   * g_file_make_directory_async().
   *
   * Virtual: make_directory_finish
   * @newin{2,38}
   *
   * @param result A AsyncResult.
   * @return <tt>true</tt> on successful directory creation, <tt>false</tt> otherwise.
   *
   * @throws Glib::Error
   */
  auto make_directory_finish(const Glib::RefPtr<AsyncResult>& result) -> bool;


  /** Creates a directory and any parent directories that may not
   * exist similar to 'mkdir -p'. If the file system does not support
   * creating directories, this function will fail, setting @a error to
   * Gio::Error::NOT_SUPPORTED. If the directory itself already exists,
   * this function will fail setting @a error to Gio::Error::EXISTS, unlike
   * the similar Glib::mkdir_with_parents().
   *
   * For a local File the newly created directories will have the default
   * (current) ownership and permissions of the current process.
   *
   * If @a cancellable is not <tt>nullptr</tt>, then the operation can be cancelled by
   * triggering the cancellable object from another thread. If the operation
   * was cancelled, the error Gio::Error::CANCELLED will be returned.
   *
   * @newin{2,18}
   *
   * @param cancellable Optional Cancellable object,
   * <tt>nullptr</tt> to ignore.
   * @return <tt>true</tt> if all directories have been successfully created, <tt>false</tt>
   * otherwise.
   *
   * @throws Glib::Error
   */
  auto make_directory_with_parents(const Glib::RefPtr<Cancellable>& cancellable) -> bool;

  /// A make_directory_with_parents() convenience overload.
  auto make_directory_with_parents() -> bool;


  /** Creates a symbolic link.
   *
   * The operation can be cancelled by
   * triggering the cancellable object from another thread. If the operation
   * was cancelled, a Gio::Error will be thrown with CANCELLED.
   *
   * @param symlink_value A string with the value of the new symlink.
   * @param cancellable Cancellable object.
   * @return <tt>true</tt> on the creation of a new symlink, <tt>false</tt> otherwise.
   *
   * @throws Glib::Error
   */
  auto make_symbolic_link(const std::string& symlink_value, const Glib::RefPtr<Cancellable>& cancellable) -> bool;

  /// A make_symbolic_link() convenience overload.
  auto make_symbolic_link(const std::string& symlink_value) -> bool;


  /** Asynchronously creates a symbolic link named @a file which contains the
   * string @a symlink_value.
   *
   * Virtual: make_symbolic_link_async
   * @newin{2,74}
   *
   * @param symlink_value A string with the path for the target
   * of the new symlink.
   * @param io_priority The [I/O priority][io-priority] of the request.
   * @param cancellable Optional Cancellable object,
   * <tt>nullptr</tt> to ignore.
   * @param slot A SlotAsyncReady to call
   * when the request is satisfied.
   */
  void make_symbolic_link_async(const std::string& symlink_value, const SlotAsyncReady& slot, const Glib::RefPtr<Cancellable>& cancellable =  {}, int io_priority =  Glib::PRIORITY_DEFAULT);


  /** Finishes an asynchronous symbolic link creation, started with
   * g_file_make_symbolic_link_async().
   *
   * Virtual: make_symbolic_link_finish
   * @newin{2,74}
   *
   * @param result A AsyncResult.
   * @return <tt>true</tt> on successful directory creation, <tt>false</tt> otherwise.
   *
   * @throws Glib::Error
   */
  auto make_symbolic_link_finish(const Glib::RefPtr<AsyncResult>& result) -> bool;


  /** Obtain the list of settable attributes for the file.
   *
   * @param cancellable Optional Cancellable object,
   * <tt>nullptr</tt> to ignore.
   * @return A FileAttributeInfoList describing the settable attributes.
   * When you are done with it, release it with
   * g_file_attribute_info_list_unref().
   *
   * @throws Glib::Error
   */
  auto query_settable_attributes(const Glib::RefPtr<Cancellable>& cancellable) -> Glib::RefPtr<FileAttributeInfoList>;

  /// A query_settable_attributes() convenience overload.
  auto query_settable_attributes() -> Glib::RefPtr<FileAttributeInfoList>;


  /** Obtain the list of attribute namespaces where new attributes
   * can be created by a user. An example of this is extended
   * attributes (in the "xattr" namespace).
   *
   * The operation can be cancelled by
   * triggering the cancellable object from another thread. If the operation
   * was cancelled, a Gio::Error will be thrown with CANCELLED.
   *
   * @param cancellable Cancellable object.
   * @return A FileAttributeInfoList describing the writable namespaces.
   * When you are done with it, release it with g_file_attribute_info_list_unref().
   *
   * @throws Glib::Error
   */
  auto query_writable_namespaces(const Glib::RefPtr<Cancellable>& cancellable) -> Glib::RefPtr<FileAttributeInfoList>;

  /// A query_writable_namespaces() convenience overload.
  auto query_writable_namespaces() -> Glib::RefPtr<FileAttributeInfoList>;

  /* This seems to be very generic (see the gpointer parameter),
     in a C kind of way. Hopefully we don't need it. murrayc
     gboolean                g_file_set_attribute              (GFile                      *file,
							   const char                 *attribute,
							   GFileAttributeType          type,
							   gpointer                    value_p,
							   GFileQueryInfoFlags         flags,
							   GCancellable               *cancellable,
							   GError                    **error);
   */

  /** Tries to set all attributes in the FileInfo on the target values,
   * not stopping on the first error.
   *
   * If there is any error during this operation then a Gio::Error will be thrown.
   * Error on particular fields are flagged by setting
   * the "status" field in the attribute value to
   * FILE_ATTRIBUTE_STATUS_ERROR_SETTING, which means you can also detect
   * further errors.
   *
   * The operation can be cancelled by triggering the cancellable object from another thread. If the operation was cancelled,
   * a Gio::Error with CANCELLED will be thrown.
   *
   * @param info A FileInfo.
   * @param cancellable A Cancellable object which can be used to cancel the operation.
   * @param flags A set of FileQueryInfoFlags.
   * @return <tt>true</tt> if there was any error, <tt>false</tt> otherwise.
   *
   * @throws Gio::Error
   */
  auto set_attributes_from_info(const Glib::RefPtr<FileInfo>& info, const Glib::RefPtr<Cancellable>& cancellable, FileQueryInfoFlags flags = FileQueryInfoFlags::NONE) -> bool;

  /** Tries to set all attributes in the FileInfo on the target values,
   * not stopping on the first error.
   *
   * If there is any error during this operation then a Gio::Error will be thrown.
   * Error on particular fields are flagged by setting
   * the "status" field in the attribute value to
   * FILE_ATTRIBUTE_STATUS_ERROR_SETTING, which means you can also detect
   * further errors.
   *
   * The operation can be cancelled by triggering the cancellable object from another thread. If the operation was cancelled,
   * a Gio::Error with CANCELLED will be thrown.
   *
   * @param info A FileInfo.
   * @param flags A set of FileQueryInfoFlags.
   * @return <tt>true</tt> if there was any error, <tt>false</tt> otherwise.
   *
   * @throws Gio::Error
   */
  auto set_attributes_from_info(const Glib::RefPtr<FileInfo>& info, FileQueryInfoFlags flags = FileQueryInfoFlags::NONE) -> bool;


  /** Asynchronously sets the attributes of file with info.
   *
   * For more details, see set_attributes_from_info() which is the synchronous version of this call.
   * When the operation is finished, @a slot will be called. You can then call set_attributes_finish() to get the result of the operation.
   *
   * @param info A FileInfo.
   * @param slot A callback slot which will be called when the request is satisfied.
   * @param cancellable A Cancellable object which can be used to cancel the operation.
   * @param flags A set of FileQueryInfoFlags.
   * @param io_priority The I/O priority of the request.
   */
  void set_attributes_async(const Glib::RefPtr<FileInfo>& info, const SlotAsyncReady& slot, const Glib::RefPtr<Cancellable>& cancellable, FileQueryInfoFlags flags = FileQueryInfoFlags::NONE, int io_priority = Glib::PRIORITY_DEFAULT);

  /** Asynchronously sets the attributes of file with info.
   *
   * For more details, see set_attributes_from_info() which is the synchronous version of this call.
   * When the operation is finished, @a slot will be called. You can then call set_attributes_finish() to get the result of the operation.
   *
   * @param info A FileInfo.
   * @param slot A callback slot which will be called when the request is satisfied.
   * @param flags A set of FileQueryInfoFlags.
   * @param io_priority The I/O priority of the request.
   */
  void set_attributes_async(const Glib::RefPtr<FileInfo>& info, const SlotAsyncReady& slot, FileQueryInfoFlags flags = FileQueryInfoFlags::NONE, int io_priority = Glib::PRIORITY_DEFAULT);

   // takes GFileInfo**

  auto set_attributes_finish(const Glib::RefPtr<AsyncResult>& result, const Glib::RefPtr<FileInfo>& info) -> bool;


  /** Sets @a attribute of type G_FILE_ATTRIBUTE_TYPE_STRING to @a value.
   * If @a attribute is of a different type, this operation will fail.
   *
   * The operation can be cancelled by
   * triggering the cancellable object from another thread. If the operation
   * was cancelled, a Gio::Error will be thrown with CANCELLED.
   *
   * @param attribute A string containing the attribute's name.
   * @param value A string containing the attribute's value.
   * @param flags FileQueryInfoFlags.
   * @param cancellable Cancellable object.
   * @return <tt>true</tt> if the @a attribute was successfully set, <tt>false</tt> otherwise.
   *
   * @throws Glib::Error
   */
  auto set_attribute_string(const std::string& attribute, const Glib::ustring& value, FileQueryInfoFlags flags, const Glib::RefPtr<Cancellable>& cancellable) -> bool;

  /// A set_attribute_string() convenience overload.
  auto set_attribute_string(const std::string& attribute, const Glib::ustring& value, FileQueryInfoFlags flags) -> bool;


  /** Sets @a attribute of type G_FILE_ATTRIBUTE_TYPE_BYTE_STRING to @a value.
   * If @a attribute is of a different type, this operation will fail,
   * returning <tt>false</tt>.
   *
   * The operation can be cancelled by
   * triggering the cancellable object from another thread. If the operation
   * was cancelled, a Gio::Error will be thrown with CANCELLED.
   *
   * @param attribute A string containing the attribute's name.
   * @param value A string containing the attribute's new value.
   * @param flags A FileQueryInfoFlags.
   * @param cancellable Cancellable object.
   * @return <tt>true</tt> if the @a attribute was successfully set to @a value
   * in the @a file, <tt>false</tt> otherwise.
   *
   * @throws Glib::Error
   */
  auto set_attribute_byte_string(const std::string& attribute, const std::string& value, FileQueryInfoFlags flags, const Glib::RefPtr<Cancellable>& cancellable) -> bool;

  /// A set_attribute_byte_string() convenience overload.
  auto set_attribute_byte_string(const std::string& attribute, const std::string& value, FileQueryInfoFlags flags) -> bool;


  /** Sets @a attribute of type G_FILE_ATTRIBUTE_TYPE_UINT32 to @a value.
   * If @a attribute is of a different type, this operation will fail.
   *
   * The operation can be cancelled by
   * triggering the cancellable object from another thread. If the operation
   * was cancelled, a Gio::Error will be thrown with CANCELLED.
   *
   * @param attribute A string containing the attribute's name.
   * @param value A #guint32 containing the attribute's new value.
   * @param flags A FileQueryInfoFlags.
   * @param cancellable Cancellable object.
   * @return <tt>true</tt> if the @a attribute was successfully set to @a value
   * in the @a file, <tt>false</tt> otherwise.
   *
   * @throws Glib::Error
   */
  auto set_attribute_uint32(const std::string& attribute, guint32 value, FileQueryInfoFlags flags, const Glib::RefPtr<Cancellable>& cancellable) -> bool;

  /// A set_attribute_uint32() convenience overload.
  auto set_attribute_uint32(const std::string& attribute, guint32 value, FileQueryInfoFlags flags) -> bool;


  /** Sets @a attribute of type G_FILE_ATTRIBUTE_TYPE_INT32 to @a value.
   * If @a attribute is of a different type, this operation will fail.
   *
   * The operation can be cancelled by
   * triggering the cancellable object from another thread. If the operation
   * was cancelled, a Gio::Error will be thrown with CANCELLED.
   *
   * @param attribute A string containing the attribute's name.
   * @param value A #gint32 containing the attribute's new value.
   * @param flags A FileQueryInfoFlags.
   * @param cancellable Cancellable object.
   * @return <tt>true</tt> if the @a attribute was successfully set to @a value
   * in the @a file, <tt>false</tt> otherwise.
   *
   * @throws Glib::Error
   */
  auto set_attribute_int32(const std::string& attribute, gint32 value, FileQueryInfoFlags flags, const Glib::RefPtr<Cancellable>& cancellable) -> bool;

  /// A set_attribute_int32() convenience overload.
  auto set_attribute_int32(const std::string& attribute, gint32 value, FileQueryInfoFlags flags) -> bool;


  /** Sets @a attribute of type G_FILE_ATTRIBUTE_TYPE_UINT64 to @a value.
   * If @a attribute is of a different type, this operation will fail.
   *
   * The operation can be cancelled by
   * triggering the cancellable object from another thread. If the operation
   * was cancelled, a Gio::Error will be thrown with CANCELLED.
   *
   * @param attribute A string containing the attribute's name.
   * @param value A #guint64 containing the attribute's new value.
   * @param flags A FileQueryInfoFlags.
   * @param cancellable Cancellable object.
   * @return <tt>true</tt> if the @a attribute was successfully set to @a value
   * in the @a file, <tt>false</tt> otherwise.
   *
   * @throws Glib::Error
   */
  auto set_attribute_uint64(const std::string& attribute, guint64 value, FileQueryInfoFlags flags, const Glib::RefPtr<Cancellable>& cancellable) -> bool;

  /// A set_attribute_uint64() convenience overload.
  auto set_attribute_uint64(const std::string& attribute, guint64 value, FileQueryInfoFlags flags) -> bool;


  /** Sets @a attribute of type G_FILE_ATTRIBUTE_TYPE_INT64 to @a value.
   * If @a attribute is of a different type, this operation will fail.
   *
   * The operation can be cancelled by
   * triggering the cancellable object from another thread. If the operation
   * was cancelled, a Gio::Error will be thrown with CANCELLED.
   *
   * @param attribute A string containing the attribute's name.
   * @param value A #guint64 containing the attribute's new value.
   * @param flags A FileQueryInfoFlags.
   * @param cancellable Cancellable object.
   * @return <tt>true</tt> if the @a attribute was successfully set, <tt>false</tt> otherwise.
   *
   * @throws Glib::Error
   */
  auto set_attribute_int64(const std::string& attribute, gint64 value, FileQueryInfoFlags flags, const Glib::RefPtr<Cancellable>& cancellable) -> bool;

  /// A set_attribute_int64() convenience overload.
  auto set_attribute_int64(const std::string& attribute, gint64 value, FileQueryInfoFlags flags) -> bool;

  /** Starts a @a mount_operation, mounting the volume that contains the file.
   *
   * When this operation has completed, @a slot will be called with,
   * and the operation can be finalized with mount_enclosing_volume_finish().
   *
   * The operation can be cancelled by triggering the cancellable object from another thread. If the operation was cancelled,
   * a Gio::Error with CANCELLED will be thrown.
   *
   * @param mount_operation A MountOperation.
   * @param slot A callback slot which will be called when the request is satisfied.
   * @param cancellable A Cancellable object.
   * @param flags Flags affecting the operation.
   */
  void mount_enclosing_volume(const Glib::RefPtr<MountOperation>& mount_operation, const SlotAsyncReady& slot, const Glib::RefPtr<Cancellable>& cancellable, Mount::MountFlags flags = Mount::MountFlags::NONE);

  /** Starts a @a mount_operation, mounting the volume that contains the file.
   *
   * When this operation has completed, @a slot will be called with,
   * and the operation can be finalized with mount_enclosing_volume_finish().
   *
   * @param mount_operation A MountOperation.
   * @param slot A callback slot which will be called when the request is satisfied.
   * @param flags Flags affecting the operation.
   */
  void mount_enclosing_volume(const Glib::RefPtr<MountOperation>& mount_operation, const SlotAsyncReady& slot, Mount::MountFlags flags = Mount::MountFlags::NONE);

  /** Starts a @a mount_operation, mounting the volume that contains the file.
   *
   * When this operation has completed, @a slot will be called with,
   * and the operation can be finalized with mount_enclosing_volume_finish().
   *
   * @param slot A callback slot which will be called when the request is satisfied.
   * @param flags Flags affecting the operation.
   */
  void mount_enclosing_volume(const SlotAsyncReady& slot, Mount::MountFlags flags = Mount::MountFlags::NONE);


  /** Starts a @a mount_operation, mounting the volume that contains the file.
   *
   * @param flags Flags affecting the operation.
   */
  void mount_enclosing_volume(Mount::MountFlags flags = Mount::MountFlags::NONE);


  /** Finishes a mount operation started by g_file_mount_enclosing_volume().
   *
   * @param result A AsyncResult.
   * @return <tt>true</tt> if successful. If an error has occurred,
   * this function will return <tt>false</tt> and set @a error
   * appropriately if present.
   *
   * @throws Glib::Error
   */
  auto mount_enclosing_volume_finish(const Glib::RefPtr<AsyncResult>& result) -> bool;

  /** Mounts a file of type FileType::MOUNTABLE. Using @a mount_operation, you can request callbacks when, for instance,
   * passwords are needed during authentication.
   *
   * The operation can be cancelled by triggering the cancellable object from another thread. If the operation was cancelled,
   * a Gio::Error with CANCELLED will be thrown.
   *
   * When the operation is finished, @a slot will be called. You can then call mount_mountable_finish() to get the result of the operation.
   *
   * @param mount_operation A MountOperation.
   * @param cancellable A Cancellable object which can be used to cancel the operation.
   * @param slot A callback slot which will be called when the request is satisfied.
   * @param flags Flags affecting the operation.
   */
  void mount_mountable(const Glib::RefPtr<MountOperation>& mount_operation, const SlotAsyncReady& slot, const Glib::RefPtr<Cancellable>& cancellable, Mount::MountFlags flags = Mount::MountFlags::NONE);

  /** Mounts a file of type FileType::MOUNTABLE. Using @a mount_operation, you can request callbacks when, for instance,
   * passwords are needed during authentication.
   *
   * When the operation is finished, @a slot will be called. You can then call mount_mountable_finish() to get the result of the operation.
   *
   * @param mount_operation A MountOperation.
   * @param slot A callback slot which will be called when the request is satisfied.
   * @param flags Flags affecting the operation.
   */
  void mount_mountable(const Glib::RefPtr<MountOperation>& mount_operation, const SlotAsyncReady& slot, Mount::MountFlags flags = Mount::MountFlags::NONE);

  /** Mounts a file of type FileType::MOUNTABLE without user interaction.
   *
   * When the operation is finished, @a slot will be called. You can then call mount_mountable_finish() to get the result of the operation.
   *
   * @param slot A callback slot which will be called when the request is satisfied.
   * @param flags Flags affecting the operation.
   */
  void mount_mountable(const SlotAsyncReady& slot, Mount::MountFlags flags = Mount::MountFlags::NONE);

  /** Mounts a file of type FileType::MOUNTABLE without user interaction.
   *
   * @param flags Flags affecting the operation.
   */
  void mount_mountable(Mount::MountFlags flags = Mount::MountFlags::NONE);


  /** Finishes a mount operation. See g_file_mount_mountable() for details.
   *
   * Finish an asynchronous mount operation that was started
   * with g_file_mount_mountable().
   *
   * @param result A AsyncResult.
   * @return A File or <tt>nullptr</tt> on error.
   * Free the returned object with Glib::object_unref().
   *
   * @throws Glib::Error
   */
  auto mount_mountable_finish(const Glib::RefPtr<AsyncResult>& result) -> Glib::RefPtr<File>;

  /** Unmounts a file of type FileType::MOUNTABLE.
   *
   * The operation can be cancelled by triggering the cancellable object from another thread. If the operation was cancelled,
   * a Gio::Error with CANCELLED will be thrown.
   *
   * When the operation is finished, @a slot will be called. You can then call unmount_mountable_finish() to get the result of the operation.
   *
   * @param slot A callback slot which will be called when the request is satisfied.
   * @param cancellable A Cancellable object which can be used to cancel the operation.
   * @param flags Flags affecting the operation.
   */
  void unmount_mountable(const SlotAsyncReady& slot, const Glib::RefPtr<Cancellable>& cancellable, Mount::UnmountFlags flags = Mount::UnmountFlags::NONE);

  /** Unmounts a file of type FileType::MOUNTABLE.
   *
   * When the operation is finished, @a slot will be called. You can then call unmount_mountable_finish() to get the result of the operation.
   *
   * @param slot A callback slot which will be called when the request is satisfied.
   * @param flags Flags affecting the operation.
   */
  void unmount_mountable(const SlotAsyncReady& slot, Mount::UnmountFlags flags = Mount::UnmountFlags::NONE);

  /** Unmounts a file of type FileType::MOUNTABLE.
   *
   * @param flags Flags affecting the operation.
   */
  void unmount_mountable(Mount::UnmountFlags flags = Mount::UnmountFlags::NONE);

  /** Unmounts a file of type FileType::MOUNTABLE.
   *
   * The operation can be cancelled by triggering the cancellable object from another thread. If the operation was cancelled,
   * a Gio::Error with CANCELLED will be thrown.
   *
   * When the operation is finished, @a slot will be called. You can then call unmount_mountable_finish() to get the result of the operation.
   *
   * @param slot A callback slot which will be called when the request is satisfied.
   * @param cancellable A Cancellable object which can be used to cancel the operation.
   * @param mount_operation A MountOperation
   * @param flags Flags affecting the operation.
   *
   * @newin{2,24}
   */
  void unmount_mountable(const SlotAsyncReady& slot, const Glib::RefPtr<Cancellable>& cancellable, const Glib::RefPtr<MountOperation>& mount_operation, Mount::UnmountFlags flags = Mount::UnmountFlags::NONE);

  /** Unmounts a file of type FileType::MOUNTABLE.
   *
   * When the operation is finished, @a slot will be called. You can then call unmount_mountable_finish() to get the result of the operation.
   *
   * @param slot A callback slot which will be called when the request is satisfied.
   * @param mount_operation A MountOperation
   * @param flags Flags affecting the operation.
   *
   * @newin{2,24}
   */
  void unmount_mountable(const SlotAsyncReady& slot, const Glib::RefPtr<MountOperation>& mount_operation, Mount::UnmountFlags flags = Mount::UnmountFlags::NONE);

  /** Unmounts a file of type FileType::MOUNTABLE.
   *
   * @param mount_operation A MountOperation
   * @param flags Flags affecting the operation.
   *
   * @newin{2,24}
   */
  void unmount_mountable(const Glib::RefPtr<MountOperation>& mount_operation, Mount::UnmountFlags flags = Mount::UnmountFlags::NONE);


  /** Finishes an unmount operation,
   * see g_file_unmount_mountable_with_operation() for details.
   *
   * Finish an asynchronous unmount operation that was started
   * with g_file_unmount_mountable_with_operation().
   *
   * @newin{2,22}
   *
   * @param result A AsyncResult.
   * @return <tt>true</tt> if the operation finished successfully.
   * <tt>false</tt> otherwise.
   *
   * @throws Glib::Error
   */
  auto unmount_mountable_finish(const Glib::RefPtr<AsyncResult>& result) -> bool;

  /** Starts an asynchronous eject on a mountable.
   *
   * The operation can be cancelled by triggering the cancellable object from another thread. If the operation was cancelled,
   * a Gio::Error with CANCELLED will be thrown.
   *
   * When the operation is finished, @a slot will be called. You can then call eject_mountable_finish() to get the result of the operation.
   *
   * @param slot A callback slot which will be called when the request is satisfied.
   * @param cancellable A Cancellable object which can be used to cancel the operation.
   * @param flags Flags affecting the operation.
   */
  void eject_mountable(const SlotAsyncReady& slot, const Glib::RefPtr<Cancellable>& cancellable, Mount::UnmountFlags flags = Mount::UnmountFlags::NONE);

  /** Starts an asynchronous eject on a mountable.
   *
   * When the operation is finished, @a slot will be called. You can then call eject_mountable_finish() to get the result of the operation.
   *
   * @param slot A callback slot which will be called when the request is satisfied.
   * @param flags Flags affecting the operation.
   */
  void eject_mountable(const SlotAsyncReady& slot, Mount::UnmountFlags flags = Mount::UnmountFlags::NONE);

  /** Starts an asynchronous eject on a mountable.
   *
   * @param flags Flags affecting the operation.
   */
  void eject_mountable(Mount::UnmountFlags flags = Mount::UnmountFlags::NONE);

  /** Starts an asynchronous eject on a mountable.
   *
   * The operation can be cancelled by triggering the cancellable object from another thread. If the operation was cancelled,
   * a Gio::Error with CANCELLED will be thrown.
   *
   * When the operation is finished, @a slot will be called. You can then call eject_mountable_finish() to get the result of the operation.
   *
   * @param slot A callback slot which will be called when the request is satisfied.
   * @param cancellable A Cancellable object which can be used to cancel the operation.
   * @param mount_operation A MountOperation
   * @param flags Flags affecting the operation.
   *
   * @newin{2,24}
   */
  void eject_mountable(const SlotAsyncReady& slot, const Glib::RefPtr<Cancellable>& cancellable, const Glib::RefPtr<MountOperation>& mount_operation, Mount::UnmountFlags flags = Mount::UnmountFlags::NONE);

  /** Starts an asynchronous eject on a mountable.
   *
   * When the operation is finished, @a slot will be called. You can then call eject_mountable_finish() to get the result of the operation.
   *
   * @param slot A callback slot which will be called when the request is satisfied.
   * @param mount_operation A MountOperation
   * @param flags Flags affecting the operation.
   *
   * @newin{2,24}
   */
  void eject_mountable(const SlotAsyncReady& slot, const Glib::RefPtr<MountOperation>& mount_operation, Mount::UnmountFlags flags = Mount::UnmountFlags::NONE);

  /** Starts an asynchronous eject on a mountable.
   *
   * @param mount_operation A MountOperation
   * @param flags Flags affecting the operation.
   *
   * @newin{2,24}
   */
  void eject_mountable(const Glib::RefPtr<MountOperation>& mount_operation, Mount::UnmountFlags flags = Mount::UnmountFlags::NONE);


  /** Finishes an asynchronous eject operation started by
   * g_file_eject_mountable_with_operation().
   *
   * @newin{2,22}
   *
   * @param result A AsyncResult.
   * @return <tt>true</tt> if the @a file was ejected successfully.
   * <tt>false</tt> otherwise.
   *
   * @throws Glib::Error
   */
  auto eject_mountable_finish(const Glib::RefPtr<AsyncResult>& result) -> bool;


  /** Copies the file attributes from @a source to @a destination.
   *
   * Normally only a subset of the file attributes are copied,
   * those that are copies in a normal file copy operation
   * (which for instance does not include e.g. mtime). However
   * if CopyFlags::ALL_METADATA is specified in @a flags, then
   * all the metadata that is possible to copy is copied.
   *
   * @param destination A File to copy attributes to.
   * @param cancellable A Cancellable object.
   * @param flags A set of FileMonitorFlags.
   * @result true if the attributes were copied successfully, false otherwise.
   *
   * @throws Gio::Error
   */
  auto copy_attributes(const Glib::RefPtr<File>& destination, const Glib::RefPtr<Cancellable>& cancellable, CopyFlags flags = CopyFlags::NONE) -> bool;

  /** Copies the file attributes from @a source to @a destination.
   *
   * Normally only a subset of the file attributes are copied,
   * those that are copies in a normal file copy operation
   * (which for instance does not include e.g. mtime). However
   * if CopyFlags::ALL_METADATA is specified in @a flags, then
   * all the metadata that is possible to copy is copied.
   *
   * @param destination A File to copy attributes to.
   * @param flags A set of FileMonitorFlags.
   * @result true if the attributes were copied successfully, false otherwise.
   *
   * @throws Gio::Error
   */
  auto copy_attributes(const Glib::RefPtr<File>& destination, CopyFlags flags = CopyFlags::NONE) -> bool;


  /** Obtains a directory monitor for the given file.
   * This may fail if directory monitoring is not supported.
   *
   * The operation can be cancelled by triggering the cancellable object from another thread. If the operation
   * was cancelled, a Gio::Error with CANCELLED will be thrown.
   *
   * @param cancellable A Cancellable object.
   * @param flags A set of FileMonitorFlags.
   * @return A FileMonitor for the file.
   *
   * @throws Gio::Error
   */
  auto monitor_directory(const Glib::RefPtr<Cancellable>& cancellable, FileMonitorFlags flags = FileMonitorFlags::NONE) -> Glib::RefPtr<FileMonitor>;

  /** Obtains a directory monitor for the given file.
   * This may fail if directory monitoring is not supported.
   *
   * @param flags A set of FileMonitorFlags.
   * @return A FileMonitor for the file.
   *
   * @throws Gio::Error
   */
  auto monitor_directory(FileMonitorFlags flags = FileMonitorFlags::NONE) -> Glib::RefPtr<FileMonitor>;


  /** Obtains a file monitor for the given file. If no file notification
   * mechanism exists, then regular polling of the file is used.
   *
   * The operation can be cancelled by triggering the cancellable object from another thread. If the operation
   * was cancelled, a Gio::Error with CANCELLED will be thrown.
   *
   * @param cancellable A Cancellable object.
   * @param flags A set of FileMonitorFlags.
   * @return A FileMonitor for the file.
   *
   * @throws Gio::Error
   */
  auto monitor_file(const Glib::RefPtr<Cancellable>& cancellable, FileMonitorFlags flags = FileMonitorFlags::NONE) -> Glib::RefPtr<FileMonitor>;

  /** Obtains a file monitor for the given file. If no file notification
   * mechanism exists, then regular polling of the file is used.
   *
   * The operation can be cancelled by triggering the cancellable object from another thread. If the operation
   * was cancelled, a Gio::Error with CANCELLED will be thrown.
   *
   * @param flags A set of FileMonitorFlags.
   * @return A FileMonitor for the file.
   *
   * @throws Gio::Error
   */
  auto monitor_file(FileMonitorFlags flags = FileMonitorFlags::NONE) -> Glib::RefPtr<FileMonitor>;


  /** Obtains a file monitor for the given file. If no file notification
   * mechanism exists, then regular polling of the file is used.
   *
   * The operation can be cancelled by triggering the cancellable object from another thread. If the operation
   * was cancelled, a Gio::Error with CANCELLED will be thrown.
   *
   * @param cancellable A Cancellable object.
   * @param flags A set of FileMonitorFlags.
   * @return A FileMonitor for the file.
   *
   * @throws Gio::Error
   *
   * @newin{2,18}
   */
  auto monitor(const Glib::RefPtr<Cancellable>& cancellable, FileMonitorFlags flags = FileMonitorFlags::NONE) -> Glib::RefPtr<FileMonitor>;

  /** Obtains a file monitor for the given file. If no file notification
   * mechanism exists, then regular polling of the file is used.
   *
   * The operation can be cancelled by triggering the cancellable object from another thread. If the operation
   * was cancelled, a Gio::Error with CANCELLED will be thrown.
   *
   * @param flags A set of FileMonitorFlags.
   * @return A FileMonitor for the file.
   *
   * @throws Gio::Error
   *
   * @newin{2,18}
   */
  auto monitor(FileMonitorFlags flags = FileMonitorFlags::NONE) -> Glib::RefPtr<FileMonitor>;


 /** This slot type is used by measure_disk_usage() to make
  * periodic progress reports when measuring the amount of disk spaced
  * used by a directory.
  *
  * These calls are made on a best-effort basis and not all types of
  * GFile will support them.  At the minimum, however, one call will
  * always be made immediately.
  *
  * In the case that there is no support, @a reporting will be set to
  * false (and the other values undefined) and no further calls will be
  * made.  Otherwise, the @a reporting will be true and the other values
  * all-zeros during the first (immediate) call.  In this way, you can
  * know which type of progress UI to show without a delay.
  *
  * For measure_disk_usage() the callback is made directly.  For
  * measure_disk_usage_async() the callback is made via the
  * default main context of the calling thread (ie: the same way that the
  * final async result would be reported).
  *
  * @a current_size is in the same units as requested by the operation (see
  * FILE_DISK_USAGE_APPARENT_SIZE).
  *
  * The frequency of the updates is implementation defined, but is
  * ideally about once every 200ms.
  *
  * The last progress callback may or may not be equal to the final
  * result.  Always check the async result to get the final value.
  *
  * For instance,
  * void on_file_measure_progress(bool reporting, guint64 current_size, guint64 num_dirs, guint64 num_files);
  *
  * @param reporting true if more reports will come.
  * @param current_size The current cumulative size measurement.
  * @param num_dirs The number of directories visited so far.
  * @param num_files The number of non-directory files encountered.
  *
  * @newin{2,38}
  */
 using SlotFileMeasureProgress = sigc::slot<void(bool, guint64, guint64, guint64)>;

  //We do not use the {callback} syntax with _WRAP_METHOD here, because it expects to use user_data rather than progress_data.
  //We ignore the gboolean result, because we throw an exception if it is false.
  /** Recursively measures the disk usage of the file.
   *
   * This is essentially an analog of the '<tt>du</tt>' command,
   * but it also reports the number of directories and non-directory files
   * encountered (including things like symbolic links).
   *
   * By default, errors are only reported against the toplevel file
   * itself.  Errors found while recursing are silently ignored, unless
   * MeasureFlags::REPORT_ANY_ERROR is given in @a flags.
   *
   * The returned size, @a disk_usage, is in bytes and should be formatted
   * with g_format_size() in order to get something reasonable for showing
   * in a user interface.
   *
   * @a slot_progress can be given to request periodic progress updates while scanning.
   * See the documentation for SlotFileMeasureProgress for information about when and how the
   * callback will be invoked.
   *
   * The operation can be cancelled by triggering the cancellable object from another thread.
   * If the operation was cancelled, a Gio::Error with CANCELLED will be thrown.
   *
   * @param cancellable A Cancellable object which can be used to cancel the operation
   * @param slot_progress A SlotFileMeasureProgress to call periodically while scanning.
   * @param disk_usage The number of bytes of disk space used.
   * @param num_dirs The number of directories encountered.
   * @param num_files The number of non-directories encountered.
   * @param flags Set of MeasureFlags.
   *
   * @throws Gio::Error
   */
  void measure_disk_usage(const Glib::RefPtr<Cancellable>& cancellable, const SlotFileMeasureProgress& slot_progress, guint64& disk_usage, guint64& num_dirs, guint64& num_files, MeasureFlags flags = MeasureFlags::NONE);


  /** Recursively measures the disk usage of the file.
   *
   * This is the asynchronous version of measure_disk_usage().  See
   * there for more information.
   *
   * When the operation is finished, @a slot_ready will be called.
   * You can then call measure_disk_usage_finish() to get the result of the operation.
   *
   * @param slot_ready A SlotAsyncReady to call when the request is satisfied
   * @param cancellable A Cancellable object which can be used to cancel the operation
   * @param slot_progress The callback slot to be called with progress information
   * @param flags Set of MeasureFlags
   * @param io_priority The I/O priority of the request
   */
  void measure_disk_usage_async(const SlotAsyncReady& slot_ready, const Glib::RefPtr<Cancellable>& cancellable, const SlotFileMeasureProgress& slot_progress, MeasureFlags flags = MeasureFlags::NONE, int io_priority = Glib::PRIORITY_DEFAULT);


  /** Collects the results from an earlier call to
   * g_file_measure_disk_usage_async().  See g_file_measure_disk_usage() for
   * more information.
   *
   * @newin{2,38}
   *
   * @param result The AsyncResult passed to your SlotAsyncReady.
   * @param disk_usage The number of bytes of disk space used.
   * @param num_dirs The number of directories encountered.
   * @param num_files The number of non-directories encountered.
   * @return <tt>true</tt> if successful, with the out parameters set.
   * <tt>false</tt> otherwise, with @a error set.
   *
   * @throws Glib::Error
   */
  auto measure_disk_usage_finish(const Glib::RefPtr<AsyncResult>& result, guint64& disk_usage, guint64& num_dirs, guint64& num_files) -> bool;


 //TODO: The documentation for these start/stop/poll_mountable functions needs to be improved once we've figured out what they do and what the C documentation means. murrayc.

 /** Starts a file of type Mountable.
  * Using @a start_operation, you can request callbacks when, for instance,
  * passwords are needed during authentication.
  *
  * When this operation has completed, @a slot will be called
  * and the operation can be finalized with start_mountable_finish().
  *
  * The operation can be cancelled by
  * triggering the cancellable object from another thread. If the operation
  * was cancelled, a Gio::Error with CANCELLED will be thrown.
  *
  * @param slot A callback to call when the request is satisfied.
  * @param cancellable A Cancellable object.
  * @param start_operation A MountOperation, or <tt>nullptr</tt> to avoid user interaction.
  * @param flags Flags affecting the operation
  *
  * @newin{2,24}
  */
  void start_mountable(const SlotAsyncReady& slot, const Glib::RefPtr<Cancellable>& cancellable, const Glib::RefPtr<MountOperation>& start_operation, Drive::StartFlags flags = Drive::StartFlags::NONE);

 /** Starts a file of type Mountable.
  * Using @a start_operation, you can request callbacks when, for instance,
  * passwords are needed during authentication.
  *
  * When this operation has completed, @a slot will be called
  * and the operation can be finalized with start_mountable_finish().
  *
  * The operation can be cancelled by
  * triggering the cancellable object from another thread. If the operation
  * was cancelled, a Gio::Error with CANCELLED will be thrown.
  *
  * @param slot A callback to call when the request is satisfied.
  * @param start_operation A MountOperation, or <tt>nullptr</tt> to avoid user interaction.
  * @param flags Flags affecting the operation
  *
  * @newin{2,24}
  */
  void start_mountable(const SlotAsyncReady& slot, const Glib::RefPtr<MountOperation>& start_operation, Drive::StartFlags flags =  Drive::StartFlags::NONE);


  /** Finishes a start operation. See g_file_start_mountable() for details.
   *
   * Finish an asynchronous start operation that was started
   * with g_file_start_mountable().
   *
   * @newin{2,22}
   *
   * @param result A AsyncResult.
   * @return <tt>true</tt> if the operation finished successfully. <tt>false</tt>
   * otherwise.
   *
   * @throws Glib::Error
   */
  auto start_mountable_finish(const Glib::RefPtr<AsyncResult>& result) -> bool;


 /** Stops a file of type Mountable.
  * Using @a start_operation, you can request callbacks when, for instance,
  * passwords are needed during authentication.
  *
  * When this operation has completed, @a slot will be called
  * and the operation can be finalized with stop_mountable_finish().
  *
  * The operation can be cancelled by
  * triggering the cancellable object from another thread. If the operation
  * was cancelled, a Gio::Error with CANCELLED will be thrown.
  *
  * @param slot A callback to call when the request is satisfied.
  * @param cancellable A Cancellable object.
  * @param start_operation A MountOperation, or <tt>nullptr</tt> to avoid user interaction.
  * @param flags Flags affecting the operation
  *
  * @newin{2,24}
  */
  void stop_mountable(const SlotAsyncReady& slot, const Glib::RefPtr<Cancellable>& cancellable, const Glib::RefPtr<MountOperation>& start_operation, Mount::UnmountFlags flags = Mount::UnmountFlags::NONE);


 /** Stops a file of type Mountable.
  * Using @a start_operation, you can request callbacks when, for instance,
  * passwords are needed during authentication.
  *
  * When this operation has completed, @a slot will be called
  * and the operation can be finalized with stop_mountable_finish().
  *
  * The operation can be cancelled by
  * triggering the cancellable object from another thread. If the operation
  * was cancelled, a Gio::Error with CANCELLED will be thrown.
  *
  * @param slot A callback to call when the request is satisfied.
  * @param start_operation A MountOperation, or <tt>nullptr</tt> to avoid user interaction.
  * @param flags Flags affecting the operation
  *
  * @newin{2,24}
  */
  void stop_mountable(const SlotAsyncReady& slot, const Glib::RefPtr<MountOperation>& start_operation, Mount::UnmountFlags flags = Mount::UnmountFlags::NONE);


  /** Finishes a stop operation, see g_file_stop_mountable() for details.
   *
   * Finish an asynchronous stop operation that was started
   * with g_file_stop_mountable().
   *
   * @newin{2,22}
   *
   * @param result A AsyncResult.
   * @return <tt>true</tt> if the operation finished successfully.
   * <tt>false</tt> otherwise.
   *
   * @throws Glib::Error
   */
  auto stop_mountable_finish(const Glib::RefPtr<AsyncResult>& result) -> bool;


 /** Polls a file of type Mountable.
  * Using @a start_operation, you can request callbacks when, for instance,
  * passwords are needed during authentication.
  *
  * When this operation has completed, @a slot will be called
  * and the operation can be finalized with stop_mountable_finish().
  *
  * The operation can be cancelled by
  * triggering the cancellable object from another thread. If the operation
  * was cancelled, a Gio::Error with CANCELLED will be thrown.
  *
  * @param slot: A callback to call when the request is satisfied.
  * @param cancellable A Cancellable object.
  *
  * @newin{2,24}
  */
  void poll_mountable(const SlotAsyncReady& slot, const Glib::RefPtr<Cancellable>& cancellable);


 /** Polls a file of type Mountable.
  * Using @a start_operation, you can request callbacks when, for instance,
  * passwords are needed during authentication.
  *
  * When this operation has completed, @a slot will be called
  * and the operation can be finalized with stop_mountable_finish().
  *
  * The operation can be cancelled by
  * triggering the cancellable object from another thread. If the operation
  * was cancelled, a Gio::Error with CANCELLED will be thrown.
  *
  * @param slot: A callback to call when the request is satisfied.
  *
  * @newin{2,24}
  */
  void poll_mountable(const SlotAsyncReady& slot);


  /** Finishes a poll operation. See g_file_poll_mountable() for details.
   *
   * Finish an asynchronous poll operation that was polled
   * with g_file_poll_mountable().
   *
   * @newin{2,22}
   *
   * @param result A AsyncResult.
   * @return <tt>true</tt> if the operation finished successfully. <tt>false</tt>
   * otherwise.
   *
   * @throws Glib::Error
   */
  auto poll_mountable_finish(const Glib::RefPtr<AsyncResult>& result) -> bool;


  /** Returns the AppInfo that is registered as the default
   * application to handle the file specified by @a file.
   *
   * If @a cancellable is not <tt>nullptr</tt>, then the operation can be cancelled by
   * triggering the cancellable object from another thread. If the operation
   * was cancelled, the error Gio::Error::CANCELLED will be returned.
   *
   * @param cancellable Optional Cancellable object, <tt>nullptr</tt> to ignore.
   * @return A AppInfo if the handle was found,
   * <tt>nullptr</tt> if there were errors.
   * When you are done with it, release it with Glib::object_unref().
   *
   * @throws Glib::Error
   */
  auto query_default_handler(const Glib::RefPtr<Cancellable>& cancellable) -> Glib::RefPtr<AppInfo>;

  /// A query_default_handler() convenience overload.
  auto query_default_handler() -> Glib::RefPtr<AppInfo>;

  //TODO: Something better than char*& for contents?
  /** Loads the content of the file into memory, returning the size of the data.
   * The data is always zero terminated, but this is not included in the resultant @a length.
   *
   * The operation can be cancelled by triggering the cancellable object from another thread.
   * If the operation was cancelled, a Gio::Error exception with CANCELLED will be returned.
   *
   * @param cancellable A cancellable object.
   * @param contents A location to place the contents of the file.
   * @param length A location to place the length of the contents of the file.
   * @param etag_out A location to place the current entity tag for the file.
   *
   * @throws Gio::Error
   */
  auto load_contents(const Glib::RefPtr<Cancellable>& cancellable, char*& contents, gsize& length, std::string& etag_out) -> bool;

  /** Loads the content of the file into memory, returning the size of the data.
   * The data is always zero terminated, but this is not included in the resultant @a length.
   *
   * The operation can be cancelled by triggering the cancellable object from another thread.
   * If the operation was cancelled, a Gio::Error exception with CANCELLED will be returned.
   *
   * @param cancellable A cancellable object.
   * @param contents A location to place the contents of the file.
   * @param length A location to place the length of the contents of the file.
   * @newin{2,22}
   *
   * @throws Gio::Error
   */
  auto load_contents(const Glib::RefPtr<Cancellable>& cancellable, char*& contents, gsize& length) -> bool;

  //TODO: Something better than char*& for contents?
  /** Loads the content of the file into memory, returning the size of the data.
   * The data is always zero terminated, but this is not included in the resultant @a length.
   *
   * @param contents A location to place the contents of the file.
   * @param length A location to place the length of the contents of the file.
   * @param etag_out A location to place the current entity tag for the file.
   *
   * @throws Gio::Error
   */
  auto load_contents(char*& contents, gsize& length, std::string& etag_out) -> bool;

  /** Loads the content of the file into memory, returning the size of the data.
   * The data is always zero terminated, but this is not included in the resultant @a length.
   *
   * @param contents A location to place the contents of the file.
   * @param length A location to place the length of the contents of the file.
   * @newin{2,22}
   *
   * @throws Gio::Error
   */
  auto load_contents(char*& contents, gsize& length) -> bool;


  /** Starts an asynchronous load of the file's contents.
   * For more details, see load_contents() which is the synchronous version of this call.
   *
   * When the load operation has completed, the @a slot will be called. To finish the operation,
   * call load_contents_finish() with the AsyncResult provided to the @a slot.
   *
   * The operation can be cancelled by triggering the cancellable object from another thread.
   * If the operation was cancelled, a Gio::Error with CANCELLED will be thrown.
   *
   * @param slot A callback slot which will be called when the request is satisfied.
   * @param cancellable A Cancellable object.
   */
  void load_contents_async(const SlotAsyncReady& slot, const Glib::RefPtr<Cancellable>& cancellable);

  /** Starts an asynchronous load of the file's contents.
   * For more details, see load_contents() which is the synchronous version of this call.
   *
   * When the load operation has completed, the @a slot will be called. To finish the operation,
   * call load_contents_finish() with the AsyncResult provided to the @a slot.
   *
   * @param slot A callback slot which will be called when the request is satisfied.
   */
  void load_contents_async(const SlotAsyncReady& slot);


  /** Finishes an asynchronous load of the @a file's contents.
   * The contents are placed in @a contents, and @a length is set to the
   * size of the @a contents string. If @a etag_out is present, it will be
   * set to the new entity tag for the @a file.
   * @param result A AsyncResult.
   * @param contents A location to place the contents of the file.
   * @param length A location to place the length of the contents of the file.
   * @param etag_out A location to place the current entity tag for the file.
   * @return <tt>true</tt> if the load was successful. If <tt>false</tt> and @a error is
   * present, it will be set appropriately.
   *
   * @throws Gio::Error
   */
  auto load_contents_finish(const Glib::RefPtr<AsyncResult>& result, char*& contents, gsize& length, std::string& etag_out) -> bool;

  /** Finishes an asynchronous load of the @a file's contents.
   * The contents are placed in @a contents, and @a length is set to the
   * size of the @a contents string. If @a etag_out is present, it will be
   * set to the new entity tag for the @a file.
   * @param result A AsyncResult.
   * @param contents A location to place the contents of the file.
   * @param length A location to place the length of the contents of the file.
   * @return <tt>true</tt> if the load was successful. If <tt>false</tt> and @a error is
   * present, it will be set appropriately.
   * @newin{2,22}
   *
   * @throws Gio::Error
   */
  auto load_contents_finish(const Glib::RefPtr<AsyncResult>& result, char*& contents, gsize& length) -> bool;


  /** A signal handler would be, for instance:
   * bool on_read_more(const char* file_contents, goffset file_size);
   */
  using SlotReadMore = sigc::slot<bool(const char*, goffset)>;

  //Note that slot_read_more can be nullptr but that would not be a useful method overload, because the documentation says that it would
  //then be equivalent to load_contents_async.

  /** Reads the partial contents of a file.
   * The @a slot_read_more callback slot should be used to stop reading from the file when appropriate. This operation can be finished by load_partial_contents_finish().
   *
   * The operation can be cancelled by triggering the cancellable object from another thread. If the operation was cancelled,
   * a Gio::Error with CANCELLED will be thrown.
   *
   * When the operation is finished, @a slot will be called. You can then call load_partial_contents_finish() to get the result of the operation.
   *
   * @param slot_read_more A callback to receive partial data and to specify whether further data should be read.
   * @param slot_async_ready A callback slot which will be called when the request is satisfied.
   * @param cancellable A Cancellable object which can be used to cancel the operation.
   */
  void load_partial_contents_async(const SlotReadMore& slot_read_more, const SlotAsyncReady& slot_async_ready, const Glib::RefPtr<Cancellable>& cancellable);

  /** Reads the partial contents of a file.
   * The @a slot_read_more callback slot should be used to stop reading from the file when appropriate. This operation can be finished by load_partial_contents_finish().
   *
   * The operation can be cancelled by triggering the cancellable object from another thread. If the operation was cancelled,
   * a Gio::Error with CANCELLED will be thrown.
   *
   * When the operation is finished, @a slot will be called. You can then call load_partial_contents_finish() to get the result of the operation.
   *
   * @param slot_read_more A callback to receive partial data and to specify whether further data should be read.
   * @param slot_async_ready A callback slot which will be called when the request is satisfied.
   */
  void load_partial_contents_async(const SlotReadMore& slot_read_more, const SlotAsyncReady& slot_async_ready);


  /** Finishes an asynchronous partial load operation that was started
   * with load_partial_contents_async().
   * @param result A AsyncResult.
   * @param contents A location to place the contents of the file.
   * @param length A location to place the length of the contents of the file.
   * @param etag_out A location to place the current entity tag for the file.
   * @return <tt>true</tt> if the load was successful. If <tt>false</tt> and @a error is
   * present, it will be set appropriately.
   *
   * @throws Gio::Error
   */
  auto load_partial_contents_finish(const Glib::RefPtr<AsyncResult>& result, char*& contents, gsize& length, std::string& etag_out) -> bool;

  /** Finishes an asynchronous partial load operation that was started
   * with load_partial_contents_async().
   * @param result A AsyncResult.
   * @param contents A location to place the contents of the file.
   * @param length A location to place the length of the contents of the file.
   * @return <tt>true</tt> if the load was successful. If <tt>false</tt> and @a error is
   * present, it will be set appropriately.
   * @newin{2,22}
   *
   * @throws Gio::Error
   */
  auto load_partial_contents_finish(const Glib::RefPtr<AsyncResult>& result, char*& contents, gsize& length) -> bool;


  /** Replaces the contents of the file with @a contents of @a length bytes.
   *
   * If @a etag is specified (not an empty string) any existing file must have that etag, or
   * a Gio::Error with WRONG_ETAG will be thrown.
   *
   * If @a make_backup is <tt>true</tt>, this function will attempt to make a backup of the file.
   *
   * The operation can be cancelled by
   * triggering the cancellable object from another thread. If the operation
   * was cancelled, a Gio::Error with CANCELLED will be thrown.
   *
   * The returned @a new_etag  can be used to verify that the file hasn't changed the
   * next time it is saved over.
   *
   * @param contents A string containing the new contents for the file.
   * @param length The length of @a contents in bytes.
   * @param etag The old entity tag
   * for the document.
   * @param make_backup <tt>true</tt> if a backup should be created.
   * @param flags A set of CreateFlags.
   * @param new_etag A location to a new entity tag for the document.
   * @param cancellable A Cancellable object.
   *
   * @throws Gio::Error
   */
  void replace_contents(const char* contents, gsize length, const std::string& etag, std::string& new_etag, const Glib::RefPtr<Cancellable>& cancellable, bool make_backup = false, CreateFlags flags = CreateFlags::NONE);

  /** Replaces the contents of the file with @a contents of @a length bytes.
   *
   * If @a etag is specified (not an empty string) any existing file must have that etag, or
   * a Gio::Error with WRONG_ETAG will be thrown.
   *
   * If @a make_backup is <tt>true</tt>, this function will attempt to make a backup of the file.
   *
   * The returned @a new_etag  can be used to verify that the file hasn't changed the
   * next time it is saved over.
   *
   * @param contents A string containing the new contents for the file.
   * @param length The length of @a contents in bytes.
   * @param etag The old entity tag
   * for the document.
   * @param make_backup <tt>true</tt> if a backup should be created.
   * @param flags A set of CreateFlags.
   * @param new_etag A location to a new entity tag for the document.
   *
   * @throws Gio::Error
   */
  void replace_contents(const char* contents, gsize length, const std::string& etag, std::string& new_etag, bool make_backup = false, CreateFlags flags = CreateFlags::NONE);

  /** Replaces the contents of the file with @a contents.
   *
   * If @a etag is specified (not an empty string) any existing file must have that etag, or
   * a Gio::Error with WRONG_ETAG will be thrown.
   *
   * If @a make_backup is <tt>true</tt>, this function will attempt to make a backup of the file.
   *
   * The operation can be cancelled by
   * triggering the cancellable object from another thread. If the operation
   * was cancelled, a Gio::Error with CANCELLED will be thrown.
   *
   * The returned @a new_etag  can be used to verify that the file hasn't changed the
   * next time it is saved over.
   *
   * @param contents A string containing the new contents for the file.
   * @param etag The old entity tag
   * for the document.
   * @param make_backup <tt>true</tt> if a backup should be created.
   * @param flags A set of CreateFlags.
   * @param new_etag A location to a new entity tag for the document.
   * @param cancellable A Cancellable object.
   *
   * @throws Gio::Error
   */
  void replace_contents(const std::string& contents, const std::string& etag, std::string& new_etag, const Glib::RefPtr<Cancellable>& cancellable, bool make_backup = false, CreateFlags flags = CreateFlags::NONE);

  /** Replaces the contents of the file with @a contents.
   *
   * If @a etag is specified (not an empty string) any existing file must have that etag, or
   * a Gio::Error with WRONG_ETAG will be thrown.
   *
   * If @a make_backup is <tt>true</tt>, this function will attempt to make a backup of the file.
   *
   * The returned @a new_etag  can be used to verify that the file hasn't changed the
   * next time it is saved over.
   *
   * @param contents A string containing the new contents for the file.
   * @param etag The old entity tag
   * for the document.
   * @param make_backup <tt>true</tt> if a backup should be created.
   * @param flags A set of CreateFlags.
   * @param new_etag A location to a new entity tag for the document.
   *
   * @throws Gio::Error
   */
  void replace_contents(const std::string& contents, const std::string& etag, std::string& new_etag, bool make_backup = false, CreateFlags flags = CreateFlags::NONE);


  //TODO: Add replace_contents() without the etags?


 /** Starts an asynchronous replacement of the file with the given
  * @a contents of @a length bytes. @a etag will replace the document's
  * current entity tag.
  *
  * When this operation has completed, @a slot will be called
  * and the operation can be finalized with replace_contents_finish().
  *
  * The operation can be cancelled by
  * triggering the cancellable object from another thread. If the operation
  * was cancelled, a Gio::Error with CANCELLED will be thrown.
  *
  * If @a make_backup is true, this function will attempt to
  * make a backup of the file.
  *
  * @param slot: A callback to call when the request is satisfied.
  * @param cancellable A Cancellable object.
  * @param contents String of contents to replace the file with.
  * @param length The length of @a contents in bytes.
  * @param etag a new entity tag for the file.
  * @param make_backup true if a backup should be created.
  * @param flags A set of CreateFlags.
  */
  void replace_contents_async(const SlotAsyncReady& slot, const Glib::RefPtr<Cancellable>& cancellable, const char* contents, gsize length, const std::string& etag, bool make_backup = false, CreateFlags flags = CreateFlags::NONE);

 /** Starts an asynchronous replacement of the file with the given
  * @a contents of @a length bytes. @a etag will replace the document's
  * current entity tag.
  *
  * When this operation has completed, @a slot will be called
  * and the operation can be finalized with replace_contents_finish().
  *
  * If @a make_backup is true, this function will attempt to
  * make a backup of the file.
  *
  * @param slot: A callback to call when the request is satisfied.
  * @param contents String of contents to replace the file with.
  * @param length The length of @a contents in bytes.
  * @param etag a new entity tag for the file.
  * @param make_backup true if a backup should be created.
  * @param flags A set of CreateFlags.
  */
  void replace_contents_async(const SlotAsyncReady& slot, const char* contents, gsize length, const std::string& etag, bool make_backup = false, CreateFlags flags = CreateFlags::NONE);

 /** Starts an asynchronous replacement of the file with the given
  * @a contents of @a length bytes. @a etag will replace the document's
  * current entity tag.
  *
  * When this operation has completed, @a slot will be called
  * and the operation can be finalized with replace_contents_finish().
  *
  * The operation can be cancelled by
  * triggering the cancellable object from another thread. If the operation
  * was cancelled, a Gio::Error with CANCELLED will be thrown.
  *
  * If @a make_backup is true, this function will attempt to
  * make a backup of the file.
  *
  * @param slot: A callback to call when the request is satisfied.
  * @param cancellable A Cancellable object.
  * @param contents String of contents to replace the file with.
  * @param etag a new entity tag for the file.
  * @param make_backup true if a backup should be created.
  * @param flags A set of CreateFlags.
  */
  void replace_contents_async(const SlotAsyncReady& slot, const Glib::RefPtr<Cancellable>& cancellable, const std::string& contents, const std::string& etag, bool make_backup = false, CreateFlags flags = CreateFlags::NONE);

 /** Starts an asynchronous replacement of the file with the given
  * @a contents. @a etag will replace the document's
  * current entity tag.
  *
  * When this operation has completed, @a slot will be called
  * and the operation can be finalized with replace_contents_finish().
  *
  * The operation can be cancelled by
  * triggering the cancellable object from another thread. If the operation
  * was cancelled, a Gio::Error with CANCELLED will be thrown.
  *
  * If @a make_backup is true, this function will attempt to
  * make a backup of the file.
  *
  * @param slot: A callback to call when the request is satisfied.
  * @param contents String of contents to replace the file with.
  * @param etag a new entity tag for the file.
  * @param make_backup true if a backup should be created.
  * @param flags A set of CreateFlags.
  */
  void replace_contents_async(const SlotAsyncReady& slot, const std::string& contents, const std::string& etag, bool make_backup = false, CreateFlags flags = CreateFlags::NONE);


  /** Finishes an asynchronous replace of the given file . See
   * replace_contents_async(). Sets @a new_etag to the new entity
   * tag for the document.
   * @param result A AsyncResult.
   * @param new_etag A location of a new entity tag for the document.
   *
   * @throws Gio::Error
   */
  void replace_contents_finish(const Glib::RefPtr<AsyncResult>& result, std::string& new_etag);

  /** Finishes an asynchronous replace of the given file . See
   * replace_contents_async(). Sets @a new_etag to the new entity
   * tag for the document.
   * @param result A AsyncResult.
   *
   * @throws Gio::Error
   */
  void replace_contents_finish(const Glib::RefPtr<AsyncResult>& result);


 /** Same as replace_contents_async() but takes a Gio::Bytes input instead.
  *
  * When this operation has completed, @a slot will be called
  * and the operation can be finalized with replace_contents_finish().
  *
  * The operation can be cancelled by
  * triggering the cancellable object from another thread. If the operation
  * was cancelled, a Gio::Error with CANCELLED will be thrown.
  *
  * If @a make_backup is true, this function will attempt to
  * make a backup of the file.
  *
  * @param slot: A callback to call when the request is satisfied.
  * @param cancellable A Cancellable object.
  * @param contents Bytes of contents to replace the file with.
  * @param etag a new entity tag for the file.
  * @param make_backup true if a backup should be created.
  * @param flags A set of CreateFlags.
  */
  void replace_contents_bytes_async(const SlotAsyncReady& slot, const Glib::RefPtr<Cancellable>& cancellable, const Glib::RefPtr<const Glib::Bytes>& contents, const std::string& etag, bool make_backup = false, CreateFlags flags = CreateFlags::NONE);

 /** Same as replace_contents_async() but takes a Gio::Bytes input instead.
  *
  * When this operation has completed, @a slot will be called
  * and the operation can be finalized with replace_contents_finish().
  *
  * The operation can be cancelled by
  * triggering the cancellable object from another thread. If the operation
  * was cancelled, a Gio::Error with CANCELLED will be thrown.
  *
  * If @a make_backup is true, this function will attempt to
  * make a backup of the file.
  *
  * @param slot: A callback to call when the request is satisfied.
  * @param contents Bytes of contents to replace the file with.
  * @param etag a new entity tag for the file.
  * @param make_backup true if a backup should be created.
  * @param flags A set of CreateFlags.
  */
  void replace_contents_bytes_async(const SlotAsyncReady& slot, const Glib::RefPtr<const Glib::Bytes>& contents, const std::string& etag, bool make_backup = false, CreateFlags flags = CreateFlags::NONE);


  /** Checks if @a file supports
   * [thread-default contexts][g-main-context-push-thread-default-context].
   * If this returns <tt>false</tt>, you cannot perform asynchronous operations on
   *  @a file in a thread that has a thread-default context.
   *
   * @newin{2,22}
   *
   * @return Whether or not @a file supports thread-default contexts.
   */
  auto supports_thread_contexts() const -> bool;

protected:
  // *** vfuncs ***

  //_WRAP_VFUNC(Glib::RefPtr<File> dup() const, "dup")
  //_WRAP_VFUNC(guint hash() const, "hash")
  //TODO: equal() vfunc

  //_WRAP_VFUNC(std::string get_basename() const, "get_basename")
  //_WRAP_VFUNC(std::string get_path() const, "get_path")
  //_WRAP_VFUNC(std::string get_uri() const, "get_uri")
  //_WRAP_VFUNC(std::string get_parse_name() const, "get_parse_name")

  //Careful of refcounting: //_WRAP_VFUNC(Glib::RefPtr<File> get_parent() const, "get_parent")

  // GFileIface does not define get_child(). Perhaps it's not intentional.
  //  //_WRAP_VFUNC(Glib::RefPtr<File> get_child(const std::string& name) const, "get_child")

  // howto wrap a vfunc that takes a GError**
//   //_WRAP_VFUNC(Glib::RefPtr<File> get_child_for_display_name(const Glib::ustring& display_name) const,
//               "get_child_for_display_name",
//               errthrow)


  //_WRAP_VFUNC(bool has_prefix(const Glib::RefPtr<const File>& prefix) const, "has_prefix")

  //_WRAP_VFUNC(std::string get_relative_path(const Glib::RefPtr<const File>& descendant) const, "get_relative_path")

  //Careful of refcounting:   //_WRAP_VFUNC(Glib::RefPtr<const File> resolve_relative_path(const std::string& relative_path) const, "resolve_relative_path")

  //_WRAP_VFUNC(bool is_native() const, "is_native")
  //_WRAP_VFUNC(bool has_uri_scheme(const std::string& uri_scheme) const, "has_uri_scheme")


public:

public:
  //C++ methods used to invoke GTK+ virtual functions:

protected:
  //GTK+ Virtual Functions (override these to change behaviour):

  //Default Signal Handlers::


};


} // namespace Gio

namespace Glib
{

//Pre-declare this so we can use it in TypeTrait:
GIOMM_API
auto wrap(GFile* object, bool take_copy) -> Glib::RefPtr<Gio::File>;

namespace Container_Helpers
{

/** This specialization of TypeTraits exists
 * because the default use of Glib::wrap(GObject*),
 * instead of a specific Glib::wrap(GSomeInterface*),
 * would not return a wrapper for an interface.
 */
template <>
struct TypeTraits< Glib::RefPtr<Gio::File> >
{
  using CppType = Glib::RefPtr<Gio::File>;
  using CType = GFile*;
  using CTypeNonConst = GFile*;

  static auto   to_c_type      (const CppType& item) -> CType
  { return Glib::unwrap (item); }

  static auto to_cpp_type    (const CType& item) -> CppType
  {
    //Use a specific Glib::wrap() function,
    //because CType has the specific type (not just GObject):
    return Glib::wrap(item, true /* take_copy */);
  }

  static void    release_c_type (CType item)
  {
    GLIBMM_DEBUG_UNREFERENCE(nullptr, item);
    g_object_unref(item);
  }
};

} // Container_Helpers
} // Glib

namespace Gio
{

/** @ingroup giommEnums */
inline auto operator|(File::CreateFlags lhs, File::CreateFlags rhs) -> File::CreateFlags
  { return static_cast<File::CreateFlags>(static_cast<unsigned>(lhs) | static_cast<unsigned>(rhs)); }

/** @ingroup giommEnums */
inline auto operator&(File::CreateFlags lhs, File::CreateFlags rhs) -> File::CreateFlags
  { return static_cast<File::CreateFlags>(static_cast<unsigned>(lhs) & static_cast<unsigned>(rhs)); }

/** @ingroup giommEnums */
inline auto operator^(File::CreateFlags lhs, File::CreateFlags rhs) -> File::CreateFlags
  { return static_cast<File::CreateFlags>(static_cast<unsigned>(lhs) ^ static_cast<unsigned>(rhs)); }

/** @ingroup giommEnums */
inline auto operator~(File::CreateFlags flags) -> File::CreateFlags
  { return static_cast<File::CreateFlags>(~static_cast<unsigned>(flags)); }

/** @ingroup giommEnums */
inline auto operator|=(File::CreateFlags& lhs, File::CreateFlags rhs) -> File::CreateFlags&
  { return (lhs = static_cast<File::CreateFlags>(static_cast<unsigned>(lhs) | static_cast<unsigned>(rhs))); }

/** @ingroup giommEnums */
inline auto operator&=(File::CreateFlags& lhs, File::CreateFlags rhs) -> File::CreateFlags&
  { return (lhs = static_cast<File::CreateFlags>(static_cast<unsigned>(lhs) & static_cast<unsigned>(rhs))); }

/** @ingroup giommEnums */
inline auto operator^=(File::CreateFlags& lhs, File::CreateFlags rhs) -> File::CreateFlags&
  { return (lhs = static_cast<File::CreateFlags>(static_cast<unsigned>(lhs) ^ static_cast<unsigned>(rhs))); }
} // namespace Gio
namespace Gio
{

/** @ingroup giommEnums */
inline auto operator|(File::CopyFlags lhs, File::CopyFlags rhs) -> File::CopyFlags
  { return static_cast<File::CopyFlags>(static_cast<unsigned>(lhs) | static_cast<unsigned>(rhs)); }

/** @ingroup giommEnums */
inline auto operator&(File::CopyFlags lhs, File::CopyFlags rhs) -> File::CopyFlags
  { return static_cast<File::CopyFlags>(static_cast<unsigned>(lhs) & static_cast<unsigned>(rhs)); }

/** @ingroup giommEnums */
inline auto operator^(File::CopyFlags lhs, File::CopyFlags rhs) -> File::CopyFlags
  { return static_cast<File::CopyFlags>(static_cast<unsigned>(lhs) ^ static_cast<unsigned>(rhs)); }

/** @ingroup giommEnums */
inline auto operator~(File::CopyFlags flags) -> File::CopyFlags
  { return static_cast<File::CopyFlags>(~static_cast<unsigned>(flags)); }

/** @ingroup giommEnums */
inline auto operator|=(File::CopyFlags& lhs, File::CopyFlags rhs) -> File::CopyFlags&
  { return (lhs = static_cast<File::CopyFlags>(static_cast<unsigned>(lhs) | static_cast<unsigned>(rhs))); }

/** @ingroup giommEnums */
inline auto operator&=(File::CopyFlags& lhs, File::CopyFlags rhs) -> File::CopyFlags&
  { return (lhs = static_cast<File::CopyFlags>(static_cast<unsigned>(lhs) & static_cast<unsigned>(rhs))); }

/** @ingroup giommEnums */
inline auto operator^=(File::CopyFlags& lhs, File::CopyFlags rhs) -> File::CopyFlags&
  { return (lhs = static_cast<File::CopyFlags>(static_cast<unsigned>(lhs) ^ static_cast<unsigned>(rhs))); }
} // namespace Gio
namespace Gio
{

/** @ingroup giommEnums */
inline auto operator|(File::MeasureFlags lhs, File::MeasureFlags rhs) -> File::MeasureFlags
  { return static_cast<File::MeasureFlags>(static_cast<unsigned>(lhs) | static_cast<unsigned>(rhs)); }

/** @ingroup giommEnums */
inline auto operator&(File::MeasureFlags lhs, File::MeasureFlags rhs) -> File::MeasureFlags
  { return static_cast<File::MeasureFlags>(static_cast<unsigned>(lhs) & static_cast<unsigned>(rhs)); }

/** @ingroup giommEnums */
inline auto operator^(File::MeasureFlags lhs, File::MeasureFlags rhs) -> File::MeasureFlags
  { return static_cast<File::MeasureFlags>(static_cast<unsigned>(lhs) ^ static_cast<unsigned>(rhs)); }

/** @ingroup giommEnums */
inline auto operator~(File::MeasureFlags flags) -> File::MeasureFlags
  { return static_cast<File::MeasureFlags>(~static_cast<unsigned>(flags)); }

/** @ingroup giommEnums */
inline auto operator|=(File::MeasureFlags& lhs, File::MeasureFlags rhs) -> File::MeasureFlags&
  { return (lhs = static_cast<File::MeasureFlags>(static_cast<unsigned>(lhs) | static_cast<unsigned>(rhs))); }

/** @ingroup giommEnums */
inline auto operator&=(File::MeasureFlags& lhs, File::MeasureFlags rhs) -> File::MeasureFlags&
  { return (lhs = static_cast<File::MeasureFlags>(static_cast<unsigned>(lhs) & static_cast<unsigned>(rhs))); }

/** @ingroup giommEnums */
inline auto operator^=(File::MeasureFlags& lhs, File::MeasureFlags rhs) -> File::MeasureFlags&
  { return (lhs = static_cast<File::MeasureFlags>(static_cast<unsigned>(lhs) ^ static_cast<unsigned>(rhs))); }
} // namespace Gio

namespace Glib
{
  /** A Glib::wrap() method for this object.
   *
   * @param object The C instance.
   * @param take_copy False if the result should take ownership of the C instance. True if it should take a new copy or ref.
   * @result A C++ instance that wraps this C instance.
   *
   * @relates Gio::File
   */
  GIOMM_API
  auto wrap(GFile* object, bool take_copy = false) -> Glib::RefPtr<Gio::File>;

} // namespace Glib


#endif /* _GIOMM_FILE_H */
