// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GIOMM_FILE_H
#define _GIOMM_FILE_H

#include <libmm/glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm/gio/appinfo.hxx>
#include <libmm/gio/asyncresult.hxx>
#include <libmm/gio/drive.hxx>
#include <libmm/gio/error.hxx>
#include <libmm/gio/fileattributeinfolist.hxx>
#include <libmm/gio/fileenumerator.hxx>
#include <libmm/gio/fileinfo.hxx>
#include <libmm/gio/fileinputstream.hxx>
#include <libmm/gio/fileiostream.hxx>
#include <libmm/gio/filemonitor.hxx>
#include <libmm/gio/fileoutputstream.hxx>
#include <libmm/gio/mountoperation.hxx>
#include <libmm/glib/error.hxx>
#include <libmm/glib/interface.hxx>
#include <utility>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
typedef struct _GFileIface GFileIface;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GFile = struct _GFile;
using GFileClass = struct _GFileClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gio
{
  class LIBMM_GIO_SYMEXPORT File_Class;
}
#endif

namespace Gio
{

  class LIBMM_GIO_SYMEXPORT Mount;
  class LIBMM_GIO_SYMEXPORT Volume;

  enum class FileQueryInfoFlags
  {
    NONE = 0x0,
    NOFOLLOW_SYMLINKS = (1 << 0)
  };

  inline auto
  operator| (FileQueryInfoFlags lhs, FileQueryInfoFlags rhs) -> FileQueryInfoFlags
  {
    return static_cast<FileQueryInfoFlags> (static_cast<unsigned> (lhs) |
                                            static_cast<unsigned> (rhs));
  }

  inline auto
  operator& (FileQueryInfoFlags lhs, FileQueryInfoFlags rhs) -> FileQueryInfoFlags
  {
    return static_cast<FileQueryInfoFlags> (static_cast<unsigned> (lhs) &
                                            static_cast<unsigned> (rhs));
  }

  inline auto
  operator^ (FileQueryInfoFlags lhs, FileQueryInfoFlags rhs) -> FileQueryInfoFlags
  {
    return static_cast<FileQueryInfoFlags> (static_cast<unsigned> (lhs) ^
                                            static_cast<unsigned> (rhs));
  }

  inline auto
  operator~(FileQueryInfoFlags flags) -> FileQueryInfoFlags
  {
    return static_cast<FileQueryInfoFlags> (~static_cast<unsigned> (flags));
  }

  inline auto
  operator|= (FileQueryInfoFlags& lhs, FileQueryInfoFlags rhs) -> FileQueryInfoFlags&
  {
    return (lhs = static_cast<FileQueryInfoFlags> (
                static_cast<unsigned> (lhs) | static_cast<unsigned> (rhs)));
  }

  inline auto
  operator&= (FileQueryInfoFlags& lhs, FileQueryInfoFlags rhs) -> FileQueryInfoFlags&
  {
    return (lhs = static_cast<FileQueryInfoFlags> (
                static_cast<unsigned> (lhs) & static_cast<unsigned> (rhs)));
  }

  inline auto
  operator^= (FileQueryInfoFlags& lhs, FileQueryInfoFlags rhs) -> FileQueryInfoFlags&
  {
    return (lhs = static_cast<FileQueryInfoFlags> (
                static_cast<unsigned> (lhs) ^ static_cast<unsigned> (rhs)));
  }

  enum class FileMonitorFlags
  {
    NONE = 0x0,
    WATCH_MOUNTS = (1 << 0),
    SEND_MOVED = (1 << 1),
    WATCH_HARD_LINKS = (1 << 2),
    WATCH_MOVES = (1 << 3)
  };

  inline auto
  operator| (FileMonitorFlags lhs, FileMonitorFlags rhs) -> FileMonitorFlags
  {
    return static_cast<FileMonitorFlags> (static_cast<unsigned> (lhs) |
                                          static_cast<unsigned> (rhs));
  }

  inline auto
  operator& (FileMonitorFlags lhs, FileMonitorFlags rhs) -> FileMonitorFlags
  {
    return static_cast<FileMonitorFlags> (static_cast<unsigned> (lhs) &
                                          static_cast<unsigned> (rhs));
  }

  inline auto
  operator^ (FileMonitorFlags lhs, FileMonitorFlags rhs) -> FileMonitorFlags
  {
    return static_cast<FileMonitorFlags> (static_cast<unsigned> (lhs) ^
                                          static_cast<unsigned> (rhs));
  }

  inline auto
  operator~(FileMonitorFlags flags) -> FileMonitorFlags
  {
    return static_cast<FileMonitorFlags> (~static_cast<unsigned> (flags));
  }

  inline auto
  operator|= (FileMonitorFlags& lhs, FileMonitorFlags rhs) -> FileMonitorFlags&
  {
    return (lhs = static_cast<FileMonitorFlags> (static_cast<unsigned> (lhs) |
                                                 static_cast<unsigned> (rhs)));
  }

  inline auto
  operator&= (FileMonitorFlags& lhs, FileMonitorFlags rhs) -> FileMonitorFlags&
  {
    return (lhs = static_cast<FileMonitorFlags> (static_cast<unsigned> (lhs) &
                                                 static_cast<unsigned> (rhs)));
  }

  inline auto
  operator^= (FileMonitorFlags& lhs, FileMonitorFlags rhs) -> FileMonitorFlags&
  {
    return (lhs = static_cast<FileMonitorFlags> (static_cast<unsigned> (lhs) ^
                                                 static_cast<unsigned> (rhs)));
  }

  class File : public Glib::Interface
  {
#ifndef DOXYGEN_SHOULD_SKIP_THIS

  public:
    using CppObjectType = File;
    using CppClassType = File_Class;
    using BaseObjectType = GFile;
    using BaseClassType = GFileIface;

    File (const File&) = delete;
    auto
    operator= (const File&) -> File& = delete;

  private:
    friend class File_Class;
    static CppClassType file_class_;

#endif
  protected:
    File ();

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    explicit File (const Glib::Interface_Class& interface_class);

  public:
    explicit File (GFile* castitem);

  protected:
#endif

  public:
    File (File&& src) noexcept;
    auto
    operator= (File&& src) noexcept -> File&;

    ~File () noexcept override;

    static auto
    add_interface (GType gtype_implementer) -> void;

    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS
    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GFile*
    {
      return reinterpret_cast<GFile*> (gobject_);
    }

    auto
    gobj () const -> const GFile*
    {
      return reinterpret_cast<GFile*> (gobject_);
    }

  private:
  public:
    enum class CreateFlags
    {
      NONE = 0x0,
      PRIVATE = (1 << 0),
      REPLACE_DESTINATION = (1 << 1)
    };

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

    enum class MeasureFlags
    {
      NONE = 0x0,
      REPORT_ANY_ERROR = (1 << 1),
      APPARENT_SIZE = (1 << 2),
      NO_XDEV = (1 << 3)
    };

    static auto
    create_for_path (const std::string& path) -> Glib::RefPtr<File>;

    static auto
    create_for_uri (const std::string& uri) -> Glib::RefPtr<File>;

    static auto
    create_for_commandline_arg (const std::string& arg) -> Glib::RefPtr<File>;

    static auto
    create_tmp (const std::string& tmpl = {})
        -> std::pair<Glib::RefPtr<File>, Glib::RefPtr<FileIOStream>>;

    static auto
    create_for_parse_name (const Glib::ustring& parse_name)
        -> Glib::RefPtr<File>;

    auto
    dup () const -> Glib::RefPtr<File>;

    auto
    hash () const -> guint;

    auto
    equal (const Glib::RefPtr<const File>& other) const -> bool;

    auto
    get_basename () const -> std::string;

    auto
    get_path () const -> std::string;

    auto
    get_uri () const -> std::string;

    auto
    get_parse_name () const -> Glib::ustring;

    auto
    get_parent () const -> Glib::RefPtr<File>;

    auto
    has_parent (const Glib::RefPtr<File>& parent) const -> bool;

    auto
    has_parent () const -> bool;

    auto
    get_child (const std::string& name) const -> Glib::RefPtr<File>;

    auto
    get_child_for_display_name (const Glib::ustring& display_name) const
        -> Glib::RefPtr<File>;

    auto
    has_prefix (const Glib::RefPtr<const File>& prefix) const -> bool;

    auto
    get_relative_path (const Glib::RefPtr<const File>& descendant) const
        -> std::string;

    auto
    resolve_relative_path (const std::string& relative_path) const
        -> Glib::RefPtr<File>;

    auto
    is_native () const -> bool;

    auto
    has_uri_scheme (const std::string& uri_scheme) const -> bool;

    auto
    get_uri_scheme () const -> std::string;

    auto
    read (const Glib::RefPtr<Cancellable>& cancellable)
        -> Glib::RefPtr<FileInputStream>;

    auto
    read () -> Glib::RefPtr<FileInputStream>;

    auto
    read_async (const SlotAsyncReady& slot,
                const Glib::RefPtr<Cancellable>& cancellable,
                int io_priority = Glib::PRIORITY_DEFAULT) -> void;

    auto
    read_async (const SlotAsyncReady& slot,
                int io_priority = Glib::PRIORITY_DEFAULT) -> void;

    auto
    read_finish (const Glib::RefPtr<AsyncResult>& res)
        -> Glib::RefPtr<FileInputStream>;

    auto
    append_to (const Glib::RefPtr<Cancellable>& cancellable,
               CreateFlags flags = CreateFlags::NONE)
        -> Glib::RefPtr<FileOutputStream>;

    auto
    append_to (CreateFlags flags = CreateFlags::NONE)
        -> Glib::RefPtr<FileOutputStream>;

    auto
    create_file (const Glib::RefPtr<Cancellable>& cancellable,
                 CreateFlags flags = CreateFlags::NONE)
        -> Glib::RefPtr<FileOutputStream>;

    auto
    create_file (CreateFlags flags = CreateFlags::NONE)
        -> Glib::RefPtr<FileOutputStream>;

    auto
    create_file_readwrite (const Glib::RefPtr<Cancellable>& cancellable,
                           CreateFlags flags = CreateFlags::NONE)
        -> Glib::RefPtr<FileIOStream>;

    auto
    create_file_readwrite (CreateFlags flags = CreateFlags::NONE)
        -> Glib::RefPtr<FileIOStream>;

    auto
    replace (const Glib::RefPtr<Cancellable>& cancellable,
             const std::string& etag = {},
             bool make_backup = false,
             CreateFlags flags = CreateFlags::NONE)
        -> Glib::RefPtr<FileOutputStream>;

    auto
    replace (const std::string& etag = {},
             bool make_backup = false,
             CreateFlags flags = CreateFlags::NONE)
        -> Glib::RefPtr<FileOutputStream>;

    auto
    append_to_async (const SlotAsyncReady& slot,
                     const Glib::RefPtr<Cancellable>& cancellable,
                     CreateFlags flags = CreateFlags::NONE,
                     int io_priority = Glib::PRIORITY_DEFAULT) -> void;

    auto
    append_to_async (const SlotAsyncReady& slot,
                     CreateFlags flags = CreateFlags::NONE,
                     int io_priority = Glib::PRIORITY_DEFAULT) -> void;

    auto
    append_to_finish (const Glib::RefPtr<AsyncResult>& res)
        -> Glib::RefPtr<FileOutputStream>;

    auto
    create_file_async (const SlotAsyncReady& slot,
                       const Glib::RefPtr<Cancellable>& cancellable,
                       CreateFlags flags = CreateFlags::NONE,
                       int io_priority = Glib::PRIORITY_DEFAULT) -> void;

    auto
    create_file_async (const SlotAsyncReady& slot,
                       CreateFlags flags = CreateFlags::NONE,
                       int io_priority = Glib::PRIORITY_DEFAULT) -> void;

    auto
    create_file_finish (const Glib::RefPtr<AsyncResult>& res)
        -> Glib::RefPtr<FileOutputStream>;

    auto
    create_file_readwrite_async (const SlotAsyncReady& slot,
                                 const Glib::RefPtr<Cancellable>& cancellable,
                                 CreateFlags flags = CreateFlags::NONE,
                                 int io_priority = Glib::PRIORITY_DEFAULT)
        -> void;

    auto
    create_file_readwrite_async (const SlotAsyncReady& slot,
                                 CreateFlags flags = CreateFlags::NONE,
                                 int io_priority = Glib::PRIORITY_DEFAULT)
        -> void;

    auto
    create_file_readwrite_finish (const Glib::RefPtr<AsyncResult>& res)
        -> Glib::RefPtr<FileIOStream>;

    auto
    replace_async (const SlotAsyncReady& slot,
                   const Glib::RefPtr<Cancellable>& cancellable,
                   const std::string& etag = {},
                   bool make_backup = false,
                   CreateFlags flags = CreateFlags::NONE,
                   int io_priority = Glib::PRIORITY_DEFAULT) -> void;

    auto
    replace_async (const SlotAsyncReady& slot,
                   const std::string& etag = {},
                   bool make_backup = false,
                   CreateFlags flags = CreateFlags::NONE,
                   int io_priority = Glib::PRIORITY_DEFAULT) -> void;

    auto
    replace_finish (const Glib::RefPtr<AsyncResult>& res)
        -> Glib::RefPtr<FileOutputStream>;

    auto
    open_readwrite (const Glib::RefPtr<Cancellable>& cancellable)
        -> Glib::RefPtr<FileIOStream>;

    auto
    open_readwrite () -> Glib::RefPtr<FileIOStream>;

    auto
    open_readwrite_async (const SlotAsyncReady& slot,
                          const Glib::RefPtr<Cancellable>& cancellable,
                          int io_priority = Glib::PRIORITY_DEFAULT) -> void;

    auto
    open_readwrite_async (const SlotAsyncReady& slot,
                          int io_priority = Glib::PRIORITY_DEFAULT) -> void;

    auto
    open_readwrite_finish (const Glib::RefPtr<AsyncResult>& res)
        -> Glib::RefPtr<FileIOStream>;

    auto
    replace_readwrite (const Glib::RefPtr<Cancellable>& cancellable,
                       const std::string& etag = {},
                       bool make_backup = false,
                       CreateFlags flags = CreateFlags::NONE)
        -> Glib::RefPtr<FileIOStream>;

    auto
    replace_readwrite (const std::string& etag = {},
                       bool make_backup = false,
                       CreateFlags flags = CreateFlags::NONE)
        -> Glib::RefPtr<FileIOStream>;

    auto
    replace_readwrite_async (const SlotAsyncReady& slot,
                             const Glib::RefPtr<Cancellable>& cancellable,
                             const std::string& etag = {},
                             bool make_backup = false,
                             CreateFlags flags = CreateFlags::NONE,
                             int io_priority = Glib::PRIORITY_DEFAULT) -> void;

    auto
    replace_readwrite_async (const SlotAsyncReady& slot,
                             const std::string& etag = {},
                             bool make_backup = false,
                             CreateFlags flags = CreateFlags::NONE,
                             int io_priority = Glib::PRIORITY_DEFAULT) -> void;

    auto
    replace_readwrite_finish (const Glib::RefPtr<AsyncResult>& res)
        -> Glib::RefPtr<FileIOStream>;

    auto
    query_info (const Glib::RefPtr<Cancellable>& cancellable,
                const std::string& attributes = "*",
                FileQueryInfoFlags flags = FileQueryInfoFlags::NONE) const
        -> Glib::RefPtr<FileInfo>;

    auto
    query_info (const std::string& attributes = "*",
                FileQueryInfoFlags flags = FileQueryInfoFlags::NONE) const
        -> Glib::RefPtr<FileInfo>;

    auto
    query_exists (const Glib::RefPtr<Cancellable>& cancellable) const -> bool;

    auto
    query_exists () const -> bool;

    auto
    query_file_type (FileQueryInfoFlags flags,
                     const Glib::RefPtr<Cancellable>& cancellable) const
        -> FileType;

    auto
    query_file_type (FileQueryInfoFlags flags = FileQueryInfoFlags::NONE) const
        -> FileType;

    auto
    query_info_async (const SlotAsyncReady& slot,
                      const Glib::RefPtr<Cancellable>& cancellable,
                      const std::string& attributes = "*",
                      FileQueryInfoFlags flags = FileQueryInfoFlags::NONE,
                      int io_priority = Glib::PRIORITY_DEFAULT) const -> void;

    auto
    query_info_async (const SlotAsyncReady& slot,
                      const std::string& attributes = "*",
                      FileQueryInfoFlags flags = FileQueryInfoFlags::NONE,
                      int io_priority = Glib::PRIORITY_DEFAULT) const -> void;

    auto
    query_info_finish (const Glib::RefPtr<AsyncResult>& res)
        -> Glib::RefPtr<FileInfo>;

    auto
    query_filesystem_info (const Glib::RefPtr<Cancellable>& cancellable,
                           const std::string& attributes = "*")
        -> Glib::RefPtr<FileInfo>;

    auto
    query_filesystem_info (const std::string& attributes = "*")
        -> Glib::RefPtr<FileInfo>;

    auto
    find_enclosing_mount (const Glib::RefPtr<Cancellable>& cancellable)
        -> Glib::RefPtr<Mount>;

    auto
    find_enclosing_mount () -> Glib::RefPtr<Mount>;

    auto
    query_filesystem_info_async (const SlotAsyncReady& slot,
                                 const Glib::RefPtr<Cancellable>& cancellable,
                                 const std::string& attributes = "*",
                                 int io_priority = Glib::PRIORITY_DEFAULT) const
        -> void;

    auto
    query_filesystem_info_async (const SlotAsyncReady& slot,
                                 const std::string& attributes = "*",
                                 int io_priority = Glib::PRIORITY_DEFAULT) const
        -> void;

    auto
    query_filesystem_info_finish (const Glib::RefPtr<AsyncResult>& res)
        -> Glib::RefPtr<FileInfo>;

    auto
    find_enclosing_mount_async (const SlotAsyncReady& slot,
                                const Glib::RefPtr<Cancellable>& cancellable,
                                int io_priority = Glib::PRIORITY_DEFAULT)
        -> void;

    auto
    find_enclosing_mount_async (const SlotAsyncReady& slot,
                                int io_priority = Glib::PRIORITY_DEFAULT)
        -> void;

    auto
    find_enclosing_mount_finish (const Glib::RefPtr<AsyncResult>& res)
        -> Glib::RefPtr<Mount>;

    auto
    enumerate_children (const Glib::RefPtr<Cancellable>& cancellable,
                        const std::string& attributes = "*",
                        FileQueryInfoFlags flags = FileQueryInfoFlags::NONE)
        -> Glib::RefPtr<FileEnumerator>;

    auto
    enumerate_children (const std::string& attributes = "*",
                        FileQueryInfoFlags flags = FileQueryInfoFlags::NONE)
        -> Glib::RefPtr<FileEnumerator>;

    auto
    enumerate_children_async (
        const SlotAsyncReady& slot,
        const Glib::RefPtr<Cancellable>& cancellable,
        const std::string& attributes = "*",
        FileQueryInfoFlags flags = FileQueryInfoFlags::NONE,
        int io_priority = Glib::PRIORITY_DEFAULT) -> void;

    auto
    enumerate_children_async (
        const SlotAsyncReady& slot,
        const std::string& attributes = "*",
        FileQueryInfoFlags flags = FileQueryInfoFlags::NONE,
        int io_priority = Glib::PRIORITY_DEFAULT) -> void;

    auto
    enumerate_children_finish (const Glib::RefPtr<AsyncResult>& res)
        -> Glib::RefPtr<FileEnumerator>;

    auto
    set_display_name (const Glib::ustring& display_name,
                      const Glib::RefPtr<Cancellable>& cancellable)
        -> Glib::RefPtr<File>;

    auto
    set_display_name (const Glib::ustring& display_name) -> Glib::RefPtr<File>;

    auto
    set_display_name_async (const Glib::ustring& display_name,
                            const SlotAsyncReady& slot,
                            const Glib::RefPtr<Cancellable>& cancellable,
                            int io_priority = Glib::PRIORITY_DEFAULT) -> void;

    auto
    set_display_name_async (const Glib::ustring& display_name,
                            const SlotAsyncReady& slot,
                            int io_priority = Glib::PRIORITY_DEFAULT) -> void;

    auto
    set_display_name_finish (const Glib::RefPtr<AsyncResult>& res)
        -> Glib::RefPtr<File>;

    auto
    remove (const Glib::RefPtr<Cancellable>& cancellable) -> bool;

    auto
    remove () -> bool;

    auto
    remove_async (const SlotAsyncReady& slot_ready,
                  const Glib::RefPtr<Cancellable>& cancellable,
                  int io_priority = Glib::PRIORITY_DEFAULT) -> void;

    auto
    remove_async (const SlotAsyncReady& slot_ready,
                  int io_priority = Glib::PRIORITY_DEFAULT) -> void;

    auto
    remove_finish (const Glib::RefPtr<AsyncResult>& result) -> bool;

    auto
    trash (const Glib::RefPtr<Cancellable>& cancellable) -> bool;

    auto
    trash () -> bool;

    auto
    trash_async (const SlotAsyncReady& slot_ready,
                 const Glib::RefPtr<Cancellable>& cancellable,
                 int io_priority = Glib::PRIORITY_DEFAULT) -> void;

    auto
    trash_async (const SlotAsyncReady& slot_ready,
                 int io_priority = Glib::PRIORITY_DEFAULT) -> void;

    auto
    trash_finish (const Glib::RefPtr<AsyncResult>& result) -> bool;

    using SlotFileProgress = sigc::slot<void (goffset, goffset)>;

    auto
    copy (const Glib::RefPtr<File>& destination,
          const SlotFileProgress& slot,
          const Glib::RefPtr<Cancellable>& cancellable,
          CopyFlags flags = CopyFlags::NONE) -> bool;

    auto
    copy (const Glib::RefPtr<File>& destination,
          const SlotFileProgress& slot,
          CopyFlags flags = CopyFlags::NONE) -> bool;

    auto
    copy (const Glib::RefPtr<File>& destination,
          CopyFlags flags = CopyFlags::NONE) -> bool;

    auto
    copy_async (const Glib::RefPtr<File>& destination,
                const SlotFileProgress& slot_progress,
                const SlotAsyncReady& slot_ready,
                const Glib::RefPtr<Cancellable>& cancellable,
                CopyFlags flags = CopyFlags::NONE,
                int io_priority = Glib::PRIORITY_DEFAULT) -> void;

    auto
    copy_async (const Glib::RefPtr<File>& destination,
                const SlotAsyncReady& slot_ready,
                const Glib::RefPtr<Cancellable>& cancellable,
                CopyFlags flags = CopyFlags::NONE,
                int io_priority = Glib::PRIORITY_DEFAULT) -> void;

    auto
    copy_async (const Glib::RefPtr<File>& destination,
                const SlotFileProgress& slot_progress,
                const SlotAsyncReady& slot_ready,
                CopyFlags flags = CopyFlags::NONE,
                int io_priority = Glib::PRIORITY_DEFAULT) -> void;

    auto
    copy_async (const Glib::RefPtr<File>& destination,
                const SlotAsyncReady& slot_ready,
                CopyFlags flags = CopyFlags::NONE,
                int io_priority = Glib::PRIORITY_DEFAULT) -> void;

    auto
    copy_finish (const Glib::RefPtr<AsyncResult>& res) -> bool;

    auto
    move (const Glib::RefPtr<File>& destination,
          const SlotFileProgress& slot,
          const Glib::RefPtr<Cancellable>& cancellable,
          CopyFlags flags = CopyFlags::NONE) -> bool;

    auto
    move (const Glib::RefPtr<File>& destination,
          const SlotFileProgress& slot,
          CopyFlags flags = CopyFlags::NONE) -> bool;

    auto
    move (const Glib::RefPtr<File>& destination,
          CopyFlags flags = CopyFlags::NONE) -> bool;

    auto
    move_async (const Glib::RefPtr<File>& destination,
                const SlotFileProgress& slot_progress,
                const SlotAsyncReady& slot_ready,
                const Glib::RefPtr<Cancellable>& cancellable,
                CopyFlags flags = CopyFlags::NONE,
                int io_priority = Glib::PRIORITY_DEFAULT) -> void;

    auto
    move_async (const Glib::RefPtr<File>& destination,
                const SlotAsyncReady& slot_ready,
                const Glib::RefPtr<Cancellable>& cancellable,
                CopyFlags flags = CopyFlags::NONE,
                int io_priority = Glib::PRIORITY_DEFAULT) -> void;

    auto
    move_async (const Glib::RefPtr<File>& destination,
                const SlotFileProgress& slot_progress,
                const SlotAsyncReady& slot_ready,
                CopyFlags flags = CopyFlags::NONE,
                int io_priority = Glib::PRIORITY_DEFAULT) -> void;

    auto
    move_async (const Glib::RefPtr<File>& destination,
                const SlotAsyncReady& slot_ready,
                CopyFlags flags = CopyFlags::NONE,
                int io_priority = Glib::PRIORITY_DEFAULT) -> void;

    auto
    move_finish (const Glib::RefPtr<AsyncResult>& res) -> bool;

    auto
    make_directory (const Glib::RefPtr<Cancellable>& cancellable) -> bool;

    auto
    make_directory () -> bool;

    auto
    make_directory_async (const SlotAsyncReady& slot_ready,
                          const Glib::RefPtr<Cancellable>& cancellable,
                          int io_priority = Glib::PRIORITY_DEFAULT) -> void;

    auto
    make_directory_async (const SlotAsyncReady& slot_ready,
                          int io_priority = Glib::PRIORITY_DEFAULT) -> void;

    auto
    make_directory_finish (const Glib::RefPtr<AsyncResult>& result) -> bool;

    auto
    make_directory_with_parents (const Glib::RefPtr<Cancellable>& cancellable)
        -> bool;

    auto
    make_directory_with_parents () -> bool;

    auto
    make_symbolic_link (const std::string& symlink_value,
                        const Glib::RefPtr<Cancellable>& cancellable) -> bool;

    auto
    make_symbolic_link (const std::string& symlink_value) -> bool;

    auto
    make_symbolic_link_async (const std::string& symlink_value,
                              const SlotAsyncReady& slot,
                              const Glib::RefPtr<Cancellable>& cancellable = {},
                              int io_priority = Glib::PRIORITY_DEFAULT) -> void;

    auto
    make_symbolic_link_finish (const Glib::RefPtr<AsyncResult>& result) -> bool;

    auto
    query_settable_attributes (const Glib::RefPtr<Cancellable>& cancellable)
        -> Glib::RefPtr<FileAttributeInfoList>;

    auto
    query_settable_attributes () -> Glib::RefPtr<FileAttributeInfoList>;

    auto
    query_writable_namespaces (const Glib::RefPtr<Cancellable>& cancellable)
        -> Glib::RefPtr<FileAttributeInfoList>;

    auto
    query_writable_namespaces () -> Glib::RefPtr<FileAttributeInfoList>;

    auto
    set_attributes_from_info (
        const Glib::RefPtr<FileInfo>& info,
        const Glib::RefPtr<Cancellable>& cancellable,
        FileQueryInfoFlags flags = FileQueryInfoFlags::NONE) -> bool;

    auto
    set_attributes_from_info (
        const Glib::RefPtr<FileInfo>& info,
        FileQueryInfoFlags flags = FileQueryInfoFlags::NONE) -> bool;

    auto
    set_attributes_async (const Glib::RefPtr<FileInfo>& info,
                          const SlotAsyncReady& slot,
                          const Glib::RefPtr<Cancellable>& cancellable,
                          FileQueryInfoFlags flags = FileQueryInfoFlags::NONE,
                          int io_priority = Glib::PRIORITY_DEFAULT) -> void;

    auto
    set_attributes_async (const Glib::RefPtr<FileInfo>& info,
                          const SlotAsyncReady& slot,
                          FileQueryInfoFlags flags = FileQueryInfoFlags::NONE,
                          int io_priority = Glib::PRIORITY_DEFAULT) -> void;

    auto
    set_attributes_finish (const Glib::RefPtr<AsyncResult>& result,
                           const Glib::RefPtr<FileInfo>& info) -> bool;

    auto
    set_attribute_string (const std::string& attribute,
                          const Glib::ustring& value,
                          FileQueryInfoFlags flags,
                          const Glib::RefPtr<Cancellable>& cancellable) -> bool;

    auto
    set_attribute_string (const std::string& attribute,
                          const Glib::ustring& value,
                          FileQueryInfoFlags flags) -> bool;

    auto
    set_attribute_byte_string (const std::string& attribute,
                               const std::string& value,
                               FileQueryInfoFlags flags,
                               const Glib::RefPtr<Cancellable>& cancellable)
        -> bool;

    auto
    set_attribute_byte_string (const std::string& attribute,
                               const std::string& value,
                               FileQueryInfoFlags flags) -> bool;

    auto
    set_attribute_uint32 (const std::string& attribute,
                          guint32 value,
                          FileQueryInfoFlags flags,
                          const Glib::RefPtr<Cancellable>& cancellable) -> bool;

    auto
    set_attribute_uint32 (const std::string& attribute,
                          guint32 value,
                          FileQueryInfoFlags flags) -> bool;

    auto
    set_attribute_int32 (const std::string& attribute,
                         gint32 value,
                         FileQueryInfoFlags flags,
                         const Glib::RefPtr<Cancellable>& cancellable) -> bool;

    auto
    set_attribute_int32 (const std::string& attribute,
                         gint32 value,
                         FileQueryInfoFlags flags) -> bool;

    auto
    set_attribute_uint64 (const std::string& attribute,
                          guint64 value,
                          FileQueryInfoFlags flags,
                          const Glib::RefPtr<Cancellable>& cancellable) -> bool;

    auto
    set_attribute_uint64 (const std::string& attribute,
                          guint64 value,
                          FileQueryInfoFlags flags) -> bool;

    auto
    set_attribute_int64 (const std::string& attribute,
                         gint64 value,
                         FileQueryInfoFlags flags,
                         const Glib::RefPtr<Cancellable>& cancellable) -> bool;

    auto
    set_attribute_int64 (const std::string& attribute,
                         gint64 value,
                         FileQueryInfoFlags flags) -> bool;

    auto
    mount_enclosing_volume (const Glib::RefPtr<MountOperation>& mount_operation,
                            const SlotAsyncReady& slot,
                            const Glib::RefPtr<Cancellable>& cancellable,
                            Mount::MountFlags flags = Mount::MountFlags::NONE)
        -> void;

    auto
    mount_enclosing_volume (const Glib::RefPtr<MountOperation>& mount_operation,
                            const SlotAsyncReady& slot,
                            Mount::MountFlags flags = Mount::MountFlags::NONE)
        -> void;

    auto
    mount_enclosing_volume (const SlotAsyncReady& slot,
                            Mount::MountFlags flags = Mount::MountFlags::NONE)
        -> void;

    auto
    mount_enclosing_volume (Mount::MountFlags flags = Mount::MountFlags::NONE)
        -> void;

    auto
    mount_enclosing_volume_finish (const Glib::RefPtr<AsyncResult>& result)
        -> bool;

    auto
    mount_mountable (const Glib::RefPtr<MountOperation>& mount_operation,
                     const SlotAsyncReady& slot,
                     const Glib::RefPtr<Cancellable>& cancellable,
                     Mount::MountFlags flags = Mount::MountFlags::NONE) -> void;

    auto
    mount_mountable (const Glib::RefPtr<MountOperation>& mount_operation,
                     const SlotAsyncReady& slot,
                     Mount::MountFlags flags = Mount::MountFlags::NONE) -> void;

    auto
    mount_mountable (const SlotAsyncReady& slot,
                     Mount::MountFlags flags = Mount::MountFlags::NONE) -> void;

    auto
    mount_mountable (Mount::MountFlags flags = Mount::MountFlags::NONE) -> void;

    auto
    mount_mountable_finish (const Glib::RefPtr<AsyncResult>& result)
        -> Glib::RefPtr<File>;

    auto
    unmount_mountable (const SlotAsyncReady& slot,
                       const Glib::RefPtr<Cancellable>& cancellable,
                       Mount::UnmountFlags flags = Mount::UnmountFlags::NONE)
        -> void;

    auto
    unmount_mountable (const SlotAsyncReady& slot,
                       Mount::UnmountFlags flags = Mount::UnmountFlags::NONE)
        -> void;

    auto
    unmount_mountable (Mount::UnmountFlags flags = Mount::UnmountFlags::NONE)
        -> void;

    auto
    unmount_mountable (const SlotAsyncReady& slot,
                       const Glib::RefPtr<Cancellable>& cancellable,
                       const Glib::RefPtr<MountOperation>& mount_operation,
                       Mount::UnmountFlags flags = Mount::UnmountFlags::NONE)
        -> void;

    auto
    unmount_mountable (const SlotAsyncReady& slot,
                       const Glib::RefPtr<MountOperation>& mount_operation,
                       Mount::UnmountFlags flags = Mount::UnmountFlags::NONE)
        -> void;

    auto
    unmount_mountable (const Glib::RefPtr<MountOperation>& mount_operation,
                       Mount::UnmountFlags flags = Mount::UnmountFlags::NONE)
        -> void;

    auto
    unmount_mountable_finish (const Glib::RefPtr<AsyncResult>& result) -> bool;

    auto
    eject_mountable (const SlotAsyncReady& slot,
                     const Glib::RefPtr<Cancellable>& cancellable,
                     Mount::UnmountFlags flags = Mount::UnmountFlags::NONE)
        -> void;

    auto
    eject_mountable (const SlotAsyncReady& slot,
                     Mount::UnmountFlags flags = Mount::UnmountFlags::NONE)
        -> void;

    auto
    eject_mountable (Mount::UnmountFlags flags = Mount::UnmountFlags::NONE)
        -> void;

    auto
    eject_mountable (const SlotAsyncReady& slot,
                     const Glib::RefPtr<Cancellable>& cancellable,
                     const Glib::RefPtr<MountOperation>& mount_operation,
                     Mount::UnmountFlags flags = Mount::UnmountFlags::NONE)
        -> void;

    auto
    eject_mountable (const SlotAsyncReady& slot,
                     const Glib::RefPtr<MountOperation>& mount_operation,
                     Mount::UnmountFlags flags = Mount::UnmountFlags::NONE)
        -> void;

    auto
    eject_mountable (const Glib::RefPtr<MountOperation>& mount_operation,
                     Mount::UnmountFlags flags = Mount::UnmountFlags::NONE)
        -> void;

    auto
    eject_mountable_finish (const Glib::RefPtr<AsyncResult>& result) -> bool;

    auto
    copy_attributes (const Glib::RefPtr<File>& destination,
                     const Glib::RefPtr<Cancellable>& cancellable,
                     CopyFlags flags = CopyFlags::NONE) -> bool;

    auto
    copy_attributes (const Glib::RefPtr<File>& destination,
                     CopyFlags flags = CopyFlags::NONE) -> bool;

    auto
    monitor_directory (const Glib::RefPtr<Cancellable>& cancellable,
                       FileMonitorFlags flags = FileMonitorFlags::NONE)
        -> Glib::RefPtr<FileMonitor>;

    auto
    monitor_directory (FileMonitorFlags flags = FileMonitorFlags::NONE)
        -> Glib::RefPtr<FileMonitor>;

    auto
    monitor_file (const Glib::RefPtr<Cancellable>& cancellable,
                  FileMonitorFlags flags = FileMonitorFlags::NONE)
        -> Glib::RefPtr<FileMonitor>;

    auto
    monitor_file (FileMonitorFlags flags = FileMonitorFlags::NONE)
        -> Glib::RefPtr<FileMonitor>;

    auto
    monitor (const Glib::RefPtr<Cancellable>& cancellable,
             FileMonitorFlags flags = FileMonitorFlags::NONE)
        -> Glib::RefPtr<FileMonitor>;

    auto
    monitor (FileMonitorFlags flags = FileMonitorFlags::NONE)
        -> Glib::RefPtr<FileMonitor>;

    using SlotFileMeasureProgress =
        sigc::slot<void (bool, guint64, guint64, guint64)>;

    auto
    measure_disk_usage (const Glib::RefPtr<Cancellable>& cancellable,
                        const SlotFileMeasureProgress& slot_progress,
                        guint64& disk_usage,
                        guint64& num_dirs,
                        guint64& num_files,
                        MeasureFlags flags = MeasureFlags::NONE) -> void;

    auto
    measure_disk_usage_async (const SlotAsyncReady& slot_ready,
                              const Glib::RefPtr<Cancellable>& cancellable,
                              const SlotFileMeasureProgress& slot_progress,
                              MeasureFlags flags = MeasureFlags::NONE,
                              int io_priority = Glib::PRIORITY_DEFAULT) -> void;

    auto
    measure_disk_usage_finish (const Glib::RefPtr<AsyncResult>& result,
                               guint64& disk_usage,
                               guint64& num_dirs,
                               guint64& num_files) -> bool;

    auto
    start_mountable (const SlotAsyncReady& slot,
                     const Glib::RefPtr<Cancellable>& cancellable,
                     const Glib::RefPtr<MountOperation>& start_operation,
                     Drive::StartFlags flags = Drive::StartFlags::NONE) -> void;

    auto
    start_mountable (const SlotAsyncReady& slot,
                     const Glib::RefPtr<MountOperation>& start_operation,
                     Drive::StartFlags flags = Drive::StartFlags::NONE) -> void;

    auto
    start_mountable_finish (const Glib::RefPtr<AsyncResult>& result) -> bool;

    auto
    stop_mountable (const SlotAsyncReady& slot,
                    const Glib::RefPtr<Cancellable>& cancellable,
                    const Glib::RefPtr<MountOperation>& start_operation,
                    Mount::UnmountFlags flags = Mount::UnmountFlags::NONE)
        -> void;

    auto
    stop_mountable (const SlotAsyncReady& slot,
                    const Glib::RefPtr<MountOperation>& start_operation,
                    Mount::UnmountFlags flags = Mount::UnmountFlags::NONE)
        -> void;

    auto
    stop_mountable_finish (const Glib::RefPtr<AsyncResult>& result) -> bool;

    auto
    poll_mountable (const SlotAsyncReady& slot,
                    const Glib::RefPtr<Cancellable>& cancellable) -> void;

    auto
    poll_mountable (const SlotAsyncReady& slot) -> void;

    auto
    poll_mountable_finish (const Glib::RefPtr<AsyncResult>& result) -> bool;

    auto
    query_default_handler (const Glib::RefPtr<Cancellable>& cancellable)
        -> Glib::RefPtr<AppInfo>;

    auto
    query_default_handler () -> Glib::RefPtr<AppInfo>;

    auto
    load_contents (const Glib::RefPtr<Cancellable>& cancellable,
                   char*& contents,
                   gsize& length,
                   std::string& etag_out) -> bool;

    auto
    load_contents (const Glib::RefPtr<Cancellable>& cancellable,
                   char*& contents,
                   gsize& length) -> bool;

    auto
    load_contents (char*& contents, gsize& length, std::string& etag_out)
        -> bool;

    auto
    load_contents (char*& contents, gsize& length) -> bool;

    auto
    load_contents_async (const SlotAsyncReady& slot,
                         const Glib::RefPtr<Cancellable>& cancellable) -> void;

    auto
    load_contents_async (const SlotAsyncReady& slot) -> void;

    auto
    load_contents_finish (const Glib::RefPtr<AsyncResult>& result,
                          char*& contents,
                          gsize& length,
                          std::string& etag_out) -> bool;

    auto
    load_contents_finish (const Glib::RefPtr<AsyncResult>& result,
                          char*& contents,
                          gsize& length) -> bool;

    using SlotReadMore = sigc::slot<bool (const char*, goffset)>;

    auto
    load_partial_contents_async (const SlotReadMore& slot_read_more,
                                 const SlotAsyncReady& slot_async_ready,
                                 const Glib::RefPtr<Cancellable>& cancellable)
        -> void;

    auto
    load_partial_contents_async (const SlotReadMore& slot_read_more,
                                 const SlotAsyncReady& slot_async_ready)
        -> void;

    auto
    load_partial_contents_finish (const Glib::RefPtr<AsyncResult>& result,
                                  char*& contents,
                                  gsize& length,
                                  std::string& etag_out) -> bool;

    auto
    load_partial_contents_finish (const Glib::RefPtr<AsyncResult>& result,
                                  char*& contents,
                                  gsize& length) -> bool;

    auto
    replace_contents (const char* contents,
                      gsize length,
                      const std::string& etag,
                      std::string& new_etag,
                      const Glib::RefPtr<Cancellable>& cancellable,
                      bool make_backup = false,
                      CreateFlags flags = CreateFlags::NONE) -> void;

    auto
    replace_contents (const char* contents,
                      gsize length,
                      const std::string& etag,
                      std::string& new_etag,
                      bool make_backup = false,
                      CreateFlags flags = CreateFlags::NONE) -> void;

    auto
    replace_contents (const std::string& contents,
                      const std::string& etag,
                      std::string& new_etag,
                      const Glib::RefPtr<Cancellable>& cancellable,
                      bool make_backup = false,
                      CreateFlags flags = CreateFlags::NONE) -> void;

    auto
    replace_contents (const std::string& contents,
                      const std::string& etag,
                      std::string& new_etag,
                      bool make_backup = false,
                      CreateFlags flags = CreateFlags::NONE) -> void;

    auto
    replace_contents_async (const SlotAsyncReady& slot,
                            const Glib::RefPtr<Cancellable>& cancellable,
                            const char* contents,
                            gsize length,
                            const std::string& etag,
                            bool make_backup = false,
                            CreateFlags flags = CreateFlags::NONE) -> void;

    auto
    replace_contents_async (const SlotAsyncReady& slot,
                            const char* contents,
                            gsize length,
                            const std::string& etag,
                            bool make_backup = false,
                            CreateFlags flags = CreateFlags::NONE) -> void;

    auto
    replace_contents_async (const SlotAsyncReady& slot,
                            const Glib::RefPtr<Cancellable>& cancellable,
                            const std::string& contents,
                            const std::string& etag,
                            bool make_backup = false,
                            CreateFlags flags = CreateFlags::NONE) -> void;

    auto
    replace_contents_async (const SlotAsyncReady& slot,
                            const std::string& contents,
                            const std::string& etag,
                            bool make_backup = false,
                            CreateFlags flags = CreateFlags::NONE) -> void;

    auto
    replace_contents_finish (const Glib::RefPtr<AsyncResult>& result,
                             std::string& new_etag) -> void;

    auto
    replace_contents_finish (const Glib::RefPtr<AsyncResult>& result) -> void;

    auto
    replace_contents_bytes_async (
        const SlotAsyncReady& slot,
        const Glib::RefPtr<Cancellable>& cancellable,
        const Glib::RefPtr<const Glib::Bytes>& contents,
        const std::string& etag,
        bool make_backup = false,
        CreateFlags flags = CreateFlags::NONE) -> void;

    auto
    replace_contents_bytes_async (
        const SlotAsyncReady& slot,
        const Glib::RefPtr<const Glib::Bytes>& contents,
        const std::string& etag,
        bool make_backup = false,
        CreateFlags flags = CreateFlags::NONE) -> void;

    auto
    supports_thread_contexts () const -> bool;

  protected:
  public:
  public:
  protected:
  };

} // namespace Gio

namespace Glib
{

  LIBMM_GIO_SYMEXPORT
  auto
  wrap (GFile* object, bool take_copy) -> Glib::RefPtr<Gio::File>;

  namespace Container_Helpers
  {

    template <>
    struct TypeTraits<Glib::RefPtr<Gio::File>>
    {
      using CppType = Glib::RefPtr<Gio::File>;
      using CType = GFile*;
      using CTypeNonConst = GFile*;

      static auto
      to_c_type (const CppType& item) -> CType
      {
        return Glib::unwrap (item);
      }

      static auto
      to_cpp_type (const CType& item) -> CppType
      {
        return Glib::wrap (item, true);
      }

      static auto
      release_c_type (CType item) -> void
      {
        GLIBMM_DEBUG_UNREFERENCE (nullptr, item);
        g_object_unref (item);
      }
    };

  } // namespace Container_Helpers
} // namespace Glib

namespace Gio
{

  inline auto
  operator| (File::CreateFlags lhs, File::CreateFlags rhs) -> File::CreateFlags
  {
    return static_cast<File::CreateFlags> (static_cast<unsigned> (lhs) |
                                           static_cast<unsigned> (rhs));
  }

  inline auto
  operator& (File::CreateFlags lhs, File::CreateFlags rhs) -> File::CreateFlags
  {
    return static_cast<File::CreateFlags> (static_cast<unsigned> (lhs) &
                                           static_cast<unsigned> (rhs));
  }

  inline auto
  operator^ (File::CreateFlags lhs, File::CreateFlags rhs) -> File::CreateFlags
  {
    return static_cast<File::CreateFlags> (static_cast<unsigned> (lhs) ^
                                           static_cast<unsigned> (rhs));
  }

  inline auto
  operator~(File::CreateFlags flags) -> File::CreateFlags
  {
    return static_cast<File::CreateFlags> (~static_cast<unsigned> (flags));
  }

  inline auto
  operator|= (File::CreateFlags& lhs, File::CreateFlags rhs) -> File::CreateFlags&
  {
    return (lhs = static_cast<File::CreateFlags> (static_cast<unsigned> (lhs) |
                                                  static_cast<unsigned> (rhs)));
  }

  inline auto
  operator&= (File::CreateFlags& lhs, File::CreateFlags rhs) -> File::CreateFlags&
  {
    return (lhs = static_cast<File::CreateFlags> (static_cast<unsigned> (lhs) &
                                                  static_cast<unsigned> (rhs)));
  }

  inline auto
  operator^= (File::CreateFlags& lhs, File::CreateFlags rhs) -> File::CreateFlags&
  {
    return (lhs = static_cast<File::CreateFlags> (static_cast<unsigned> (lhs) ^
                                                  static_cast<unsigned> (rhs)));
  }
} // namespace Gio

namespace Gio
{

  inline auto
  operator| (File::CopyFlags lhs, File::CopyFlags rhs) -> File::CopyFlags
  {
    return static_cast<File::CopyFlags> (static_cast<unsigned> (lhs) |
                                         static_cast<unsigned> (rhs));
  }

  inline auto
  operator& (File::CopyFlags lhs, File::CopyFlags rhs) -> File::CopyFlags
  {
    return static_cast<File::CopyFlags> (static_cast<unsigned> (lhs) &
                                         static_cast<unsigned> (rhs));
  }

  inline auto
  operator^ (File::CopyFlags lhs, File::CopyFlags rhs) -> File::CopyFlags
  {
    return static_cast<File::CopyFlags> (static_cast<unsigned> (lhs) ^
                                         static_cast<unsigned> (rhs));
  }

  inline auto
  operator~(File::CopyFlags flags) -> File::CopyFlags
  {
    return static_cast<File::CopyFlags> (~static_cast<unsigned> (flags));
  }

  inline auto
  operator|= (File::CopyFlags& lhs, File::CopyFlags rhs) -> File::CopyFlags&
  {
    return (lhs = static_cast<File::CopyFlags> (static_cast<unsigned> (lhs) |
                                                static_cast<unsigned> (rhs)));
  }

  inline auto
  operator&= (File::CopyFlags& lhs, File::CopyFlags rhs) -> File::CopyFlags&
  {
    return (lhs = static_cast<File::CopyFlags> (static_cast<unsigned> (lhs) &
                                                static_cast<unsigned> (rhs)));
  }

  inline auto
  operator^= (File::CopyFlags& lhs, File::CopyFlags rhs) -> File::CopyFlags&
  {
    return (lhs = static_cast<File::CopyFlags> (static_cast<unsigned> (lhs) ^
                                                static_cast<unsigned> (rhs)));
  }
} // namespace Gio

namespace Gio
{

  inline auto
  operator| (File::MeasureFlags lhs, File::MeasureFlags rhs) -> File::MeasureFlags
  {
    return static_cast<File::MeasureFlags> (static_cast<unsigned> (lhs) |
                                            static_cast<unsigned> (rhs));
  }

  inline auto
  operator& (File::MeasureFlags lhs, File::MeasureFlags rhs) -> File::MeasureFlags
  {
    return static_cast<File::MeasureFlags> (static_cast<unsigned> (lhs) &
                                            static_cast<unsigned> (rhs));
  }

  inline auto
  operator^ (File::MeasureFlags lhs, File::MeasureFlags rhs) -> File::MeasureFlags
  {
    return static_cast<File::MeasureFlags> (static_cast<unsigned> (lhs) ^
                                            static_cast<unsigned> (rhs));
  }

  inline auto
  operator~(File::MeasureFlags flags) -> File::MeasureFlags
  {
    return static_cast<File::MeasureFlags> (~static_cast<unsigned> (flags));
  }

  inline auto
  operator|= (File::MeasureFlags& lhs, File::MeasureFlags rhs) -> File::MeasureFlags&
  {
    return (lhs = static_cast<File::MeasureFlags> (
                static_cast<unsigned> (lhs) | static_cast<unsigned> (rhs)));
  }

  inline auto
  operator&= (File::MeasureFlags& lhs, File::MeasureFlags rhs) -> File::MeasureFlags&
  {
    return (lhs = static_cast<File::MeasureFlags> (
                static_cast<unsigned> (lhs) & static_cast<unsigned> (rhs)));
  }

  inline auto
  operator^= (File::MeasureFlags& lhs, File::MeasureFlags rhs) -> File::MeasureFlags&
  {
    return (lhs = static_cast<File::MeasureFlags> (
                static_cast<unsigned> (lhs) ^ static_cast<unsigned> (rhs)));
  }
} // namespace Gio

namespace Glib
{

  LIBMM_GIO_SYMEXPORT
  auto
  wrap (GFile* object, bool take_copy = false) -> Glib::RefPtr<Gio::File>;

} // namespace Glib

#endif
