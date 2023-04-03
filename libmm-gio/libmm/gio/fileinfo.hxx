// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GIOMM_FILEINFO_H
#define _GIOMM_FILEINFO_H

#include <libmm/glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm/gio/fileattributeinfolist.hxx>
#include <libmm/gio/icon.hxx>
#include <libmm/glib/datetime.hxx>
#include <libmm/glib/object.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GFileInfo = struct _GFileInfo;
using GFileInfoClass = struct _GFileInfoClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gio
{
  class LIBMM_GIO_SYMEXPORT FileInfo_Class;
}
#endif

namespace Gio
{

  enum class FileType
  {
    UNKNOWN,
    REGULAR,
    DIRECTORY,
    SYMBOLIC_LINK,
    SPECIAL,
    SHORTCUT,
    MOUNTABLE
  };

  class LIBMM_GIO_SYMEXPORT FileAttributeMatcher final
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    using CppObjectType = FileAttributeMatcher;
    using BaseObjectType = GFileAttributeMatcher;
#endif

    auto
    reference () const -> void;

    auto
    unreference () const -> void;

    auto
    gobj () -> GFileAttributeMatcher*;

    auto
    gobj () const -> const GFileAttributeMatcher*;

    auto
    gobj_copy () const -> GFileAttributeMatcher*;

    FileAttributeMatcher () = delete;

    FileAttributeMatcher (const FileAttributeMatcher&) = delete;
    auto
    operator= (const FileAttributeMatcher&) -> FileAttributeMatcher& = delete;

  protected:
    auto
    operator delete (void*, std::size_t) -> void;

  private:
  public:
    static auto
    create (const std::string& attributes = "*")
        -> Glib::RefPtr<FileAttributeMatcher>;

    auto
    create_difference (const Glib::RefPtr<const FileAttributeMatcher>& subtract)
        const -> Glib::RefPtr<FileAttributeMatcher>;

    auto
    matches (const std::string& attribute) const -> bool;

    auto
    matches_only (const std::string& attribute) const -> bool;

    auto
    enumerate_namespace (const std::string& ns) -> bool;

    auto
    enumerate_next () -> std::string;

    auto
    to_string () const -> std::string;
  };

  class LIBMM_GIO_SYMEXPORT FileInfo : public Glib::Object
  {
#ifndef DOXYGEN_SHOULD_SKIP_THIS

  public:
    using CppObjectType = FileInfo;
    using CppClassType = FileInfo_Class;
    using BaseObjectType = GFileInfo;
    using BaseClassType = GFileInfoClass;

    FileInfo (const FileInfo&) = delete;
    auto
    operator= (const FileInfo&) -> FileInfo& = delete;

  private:
    friend class FileInfo_Class;
    static CppClassType fileinfo_class_;

  protected:
    explicit FileInfo (const Glib::ConstructParams& construct_params);
    explicit FileInfo (GFileInfo* castitem);

#endif

  public:
    FileInfo (FileInfo&& src) noexcept;
    auto
    operator= (FileInfo&& src) noexcept -> FileInfo&;

    ~FileInfo () noexcept override;

    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GFileInfo*
    {
      return reinterpret_cast<GFileInfo*> (gobject_);
    }

    auto
    gobj () const -> const GFileInfo*
    {
      return reinterpret_cast<GFileInfo*> (gobject_);
    }

    auto
    gobj_copy () -> GFileInfo*;

  private:
  public:
    FileInfo ();

    auto
    dup () const -> Glib::RefPtr<FileInfo>;

    auto
    copy_into (Glib::RefPtr<FileInfo>& dest_info) const -> void;

    auto
    has_attribute (const std::string& attribute) const -> bool;

    auto
    has_namespace (const std::string& name_space) const -> bool;

    auto
    list_attributes (const std::string& name_space) const
        -> std::vector<Glib::ustring>;

    auto
    list_attributes () const -> std::vector<Glib::ustring>;

    auto
    get_attribute_type (const std::string& attribute) const
        -> FileAttributeType;

    auto
    remove_attribute (const std::string& attribute) -> void;

    auto
    get_attribute_status (const std::string& attribute) const
        -> FileAttributeStatus;

    auto
    get_attribute_string (const std::string& attribute) const -> Glib::ustring;

    auto
    get_attribute_strings (const std::string& attribute) const
        -> std::vector<Glib::ustring>;

    auto
    get_attribute_as_string (const std::string& attribute) const
        -> Glib::ustring;

    auto
    get_attribute_byte_string (const std::string& attribute) const
        -> std::string;

    auto
    get_attribute_boolean (const std::string& attribute) const -> bool;

    auto
    get_attribute_uint32 (const std::string& attribute) const -> guint32;

    auto
    get_attribute_int32 (const std::string& attribute) const -> gint32;

    auto
    get_attribute_uint64 (const std::string& attribute) const -> guint64;

    auto
    get_attribute_int64 (const std::string& attribute) const -> gint64;

    auto
    get_attribute_object (const std::string& attribute) const
        -> Glib::RefPtr<Glib::Object>;

    auto
    set_attribute_status (const std::string& attribute,
                          FileAttributeStatus status) -> bool;

    auto
    set_attribute_string (const std::string& attribute,
                          const Glib::ustring& attr_value) -> void;

    auto
    set_attribute_strings (const std::string& attribute,
                           const std::vector<Glib::ustring>& attr_value)
        -> void;

    auto
    set_attribute_byte_string (const std::string& attribute,
                               const std::string& attr_value) -> void;

    auto
    set_attribute_boolean (const std::string& attribute, bool attr_value)
        -> void;

    auto
    set_attribute_uint32 (const std::string& attribute, guint32 attr_value)
        -> void;

    auto
    set_attribute_int32 (const std::string& attribute, gint32 attr_value)
        -> void;

    auto
    set_attribute_uint64 (const std::string& attribute, guint64 attr_value)
        -> void;

    auto
    set_attribute_int64 (const std::string& attribute, gint64 attr_value)
        -> void;

    auto
    set_attribute_object (const std::string& attribute,
                          const Glib::RefPtr<Glib::Object>& attr_value) -> void;

    auto
    clear_status () -> void;

    auto
    get_deletion_date () const -> Glib::DateTime;

    auto
    get_file_type () const -> FileType;

    auto
    is_hidden () const -> bool;

    auto
    is_backup () const -> bool;

    auto
    is_symlink () const -> bool;

    auto
    get_name () const -> std::string;

    auto
    get_display_name () const -> Glib::ustring;

    auto
    get_edit_name () const -> Glib::ustring;

    auto
    get_icon () -> Glib::RefPtr<Icon>;

    auto
    get_icon () const -> Glib::RefPtr<const Icon>;

    auto
    get_symbolic_icon () -> Glib::RefPtr<Icon>;

    auto
    get_symbolic_icon () const -> Glib::RefPtr<const Icon>;

    auto
    get_content_type () const -> Glib::ustring;

    auto
    get_size () const -> goffset;

    auto
    get_modification_date_time () const -> Glib::DateTime;

    auto
    get_access_date_time () const -> Glib::DateTime;

    auto
    get_creation_date_time () const -> Glib::DateTime;

    auto
    get_symlink_target () const -> std::string;

    auto
    get_etag () const -> Glib::ustring;

    auto
    get_sort_order () const -> gint32;

    auto
    set_attribute_mask (const Glib::RefPtr<FileAttributeMatcher>& mask) -> void;

    auto
    unset_attribute_mask () -> void;

    auto
    set_file_type (FileType type) -> void;

    auto
    set_is_hidden (bool hidden = true) -> void;

    auto
    set_is_symlink (bool symlink = true) -> void;

    auto
    set_name (const std::string& name) -> void;

    auto
    set_display_name (const Glib::ustring& display_name) -> void;

    auto
    set_edit_name (const Glib::ustring& edit_name) -> void;

    auto
    set_icon (const Glib::RefPtr<Icon>& icon) -> void;

    auto
    set_symbolic_icon (const Glib::RefPtr<Icon>& icon) -> void;

    auto
    set_content_type (const Glib::ustring& content_type) -> void;

    auto
    set_size (goffset size) -> void;

    auto
    set_modification_date_time (const Glib::DateTime& mtime) -> void;

    auto
    set_access_date_time (const Glib::DateTime& atime) -> void;

    auto
    set_creation_date_time (const Glib::DateTime& creation_time) -> void;

    auto
    set_symlink_target (const std::string& symlink_target) -> void;

    auto
    set_sort_order (gint32 sort_order) -> void;

  public:
  public:
  protected:
  };

} // namespace Gio

namespace Glib
{

  LIBMM_GIO_SYMEXPORT
  auto
  wrap (GFileAttributeMatcher* object, bool take_copy = false) -> Glib::RefPtr<Gio::FileAttributeMatcher>;

} // namespace Glib

namespace Glib
{

  LIBMM_GIO_SYMEXPORT
  auto
  wrap (GFileInfo* object, bool take_copy = false) -> Glib::RefPtr<Gio::FileInfo>;
} // namespace Glib

#endif
