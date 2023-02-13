
#ifndef _GIOMM_FILEINFO_H
#define _GIOMM_FILEINFO_H


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

#include <libmm-glib/datetime.hxx>
#include <libmm-glib/object.hxx>
#include <libmm-gio/fileattributeinfolist.hxx>
#include <libmm-gio/icon.hxx>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GFileInfo = struct _GFileInfo;
using GFileInfoClass = struct _GFileInfoClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gio
{ class GIOMM_API FileInfo_Class; } // namespace Gio
#endif //DOXYGEN_SHOULD_SKIP_THIS

namespace Gio
{
/** @addtogroup giommEnums giomm Enums and Flags */

/**
 *  @var FileType UNKNOWN
 * File's type is unknown.
 *
 *  @var FileType REGULAR
 * File handle represents a regular file.
 *
 *  @var FileType DIRECTORY
 * File handle represents a directory.
 *
 *  @var FileType SYMBOLIC_LINK
 * File handle represents a symbolic link
 * (Unix systems).
 *
 *  @var FileType SPECIAL
 * File is a "special" file, such as a socket, fifo,
 * block device, or character device.
 *
 *  @var FileType SHORTCUT
 * File is a shortcut (Windows systems).
 *
 *  @var FileType MOUNTABLE
 * File is a mountable location.
 *
 *  @enum FileType
 *
 * Indicates the file's on-disk type.
 *
 * On Windows systems a file will never have Gio::FileType::SYMBOLIC_LINK type;
 * use FileInfo and G_FILE_ATTRIBUTE_STANDARD_IS_SYMLINK to determine
 * whether a file is a symlink or not. This is due to the fact that NTFS does
 * not have a single filesystem object type for symbolic links - it has
 * files that symlink to files, and directories that symlink to directories.
 * FileType enumeration cannot precisely represent this important distinction,
 * which is why all Windows symlinks will continue to be reported as
 * Gio::FileType::REGULAR or Gio::FileType::DIRECTORY.
 *
 * @ingroup giommEnums
 */
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


//TODO: attribute strings

/** FileAttributeMatcher allows for searching through a FileInfo for attributes.
 *
 * @newin{2,16}
 */
class GIOMM_API FileAttributeMatcher final
{
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  using CppObjectType = FileAttributeMatcher;
  using BaseObjectType = GFileAttributeMatcher;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


  /** Increment the reference count for this object.
   * You should never need to do this manually - use the object via a RefPtr instead.
   */
  void reference()   const;

  /** Decrement the reference count for this object.
   * You should never need to do this manually - use the object via a RefPtr instead.
   */
  void unreference() const;

  ///Provides access to the underlying C instance.
  auto       gobj() -> GFileAttributeMatcher*;

  ///Provides access to the underlying C instance.
  auto gobj() const -> const GFileAttributeMatcher*;

  ///Provides access to the underlying C instance. The caller is responsible for unrefing it. Use when directly setting fields in structs.
  auto gobj_copy() const -> GFileAttributeMatcher*;

  FileAttributeMatcher() = delete;

  // noncopyable
  FileAttributeMatcher(const FileAttributeMatcher&) = delete;
  auto operator=(const FileAttributeMatcher&) -> FileAttributeMatcher& = delete;

protected:
  // Do not derive this.  Gio::FileAttributeMatcher can neither be constructed nor deleted.

  void operator delete(void*, std::size_t);

private:


public:
  /** Creates a new file attribute matcher, which matches attributes against a given string.
   * The attribute string should be formatted with specific keys separated from namespaces with a double colon.
   * Several "namespace::key" strings may be concatenated with a single comma (e.g. "standard::type,standard::is-hidden").
   * The wildcard "*" may be used to match all keys and namespaces, or "namespace::*" will match all keys in a given namespace.
   *
   * @param attributes The attributes string.
   * @result a new FileAttributeMatcher.
   */
  static auto create(const std::string& attributes = "*") -> Glib::RefPtr<FileAttributeMatcher>;


  /** Subtracts all attributes of @a subtract from @a matcher and returns
   * a matcher that supports those attributes.
   *
   * Note that currently it is not possible to remove a single
   * attribute when the @a matcher matches the whole namespace - or remove
   * a namespace or attribute when the matcher matches everything. This
   * is a limitation of the current implementation, but may be fixed
   * in the future.
   *
   * @param subtract The matcher to subtract.
   * @return A file attribute matcher matching all attributes of
   *  @a matcher that are not matched by @a subtract.
   */
  auto create_difference(const Glib::RefPtr<const FileAttributeMatcher>& subtract) const -> Glib::RefPtr<FileAttributeMatcher>;


  /** Checks if an attribute will be matched by an attribute matcher. If
   * the matcher was created with the "*" matching string, this function
   * will always return <tt>true</tt>.
   *
   * @param attribute A file attribute key.
   * @return <tt>true</tt> if @a attribute matches @a matcher. <tt>false</tt> otherwise.
   */
  auto matches(const std::string& attribute) const -> bool;

  /** Checks if a attribute matcher only matches a given attribute. Always
   * returns <tt>false</tt> if "*" was used when creating the matcher.
   *
   * @param attribute A file attribute key.
   * @return <tt>true</tt> if the matcher only matches @a attribute. <tt>false</tt> otherwise.
   */
  auto matches_only(const std::string& attribute) const -> bool;

  /** Checks if the matcher will match all of the keys in a given namespace.
   * This will always return <tt>true</tt> if a wildcard character is in use (e.g. if
   * matcher was created with "standard::*" and @a ns is "standard", or if matcher was created
   * using "*" and namespace is anything.)
   *
   * TODO: this is awkwardly worded.
   *
   * @param ns A string containing a file attribute namespace.
   * @return <tt>true</tt> if the matcher matches all of the entries
   * in the given @a ns, <tt>false</tt> otherwise.
   */
  auto enumerate_namespace(const std::string& ns) -> bool;

  /** Gets the next matched attribute from a FileAttributeMatcher.
   *
   * @return A string containing the next attribute or, <tt>nullptr</tt> if
   * no more attribute exist.
   */
  auto enumerate_next() -> std::string;

  /** Prints what the matcher is matching against. The format will be
   * equal to the format passed to g_file_attribute_matcher_new().
   * The output however, might not be identical, as the matcher may
   * decide to use a different order or omit needless parts.
   *
   * @newin{2,32}
   *
   * @return A string describing the attributes the matcher matches
   * against or <tt>nullptr</tt> if @a matcher was <tt>nullptr</tt>.
   */
  auto to_string() const -> std::string;


};

/** FileInfo implements methods for getting information that all files should contain, and allows for manipulation of extended attributes.
 * See FileAttribute for more information on how GIO handles file attributes.
 *
 * To obtain a FileInfo for a File, use File::query_info() (or its async variant).
 * To obtain a FileInfo for a file input or output stream, use FileInput::stream_query_info() or FileOutput::stream_query_info()
 * (or their async variants).
 *
 * FileAttributeMatcher allows for searching through a FileInfo for attributes.
 */

class GIOMM_API FileInfo : public Glib::Object
{

#ifndef DOXYGEN_SHOULD_SKIP_THIS

public:
  using CppObjectType = FileInfo;
  using CppClassType = FileInfo_Class;
  using BaseObjectType = GFileInfo;
  using BaseClassType = GFileInfoClass;

  // noncopyable
  FileInfo(const FileInfo&) = delete;
  auto operator=(const FileInfo&) -> FileInfo& = delete;

private:  friend class FileInfo_Class;
  static CppClassType fileinfo_class_;

protected:
  explicit FileInfo(const Glib::ConstructParams& construct_params);
  explicit FileInfo(GFileInfo* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  FileInfo(FileInfo&& src) noexcept;
  auto operator=(FileInfo&& src) noexcept -> FileInfo&;

  ~FileInfo() noexcept override;

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS


  static auto get_base_type() -> GType G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GObject.
  auto       gobj() -> GFileInfo*       { return reinterpret_cast<GFileInfo*>(gobject_); }

  ///Provides access to the underlying C GObject.
  auto gobj() const -> const GFileInfo* { return reinterpret_cast<GFileInfo*>(gobject_); }

  ///Provides access to the underlying C instance. The caller is responsible for unrefing it. Use when directly setting fields in structs.
  auto gobj_copy() -> GFileInfo*;

private:


public:
  FileInfo();


  /** Duplicates a file info structure.
   *
   * @return A duplicate FileInfo of @a other.
   */
  auto dup() const -> Glib::RefPtr<FileInfo>;

  /** First clears all of the [GFileAttribute][gio-GFileAttribute] of @a dest_info,
   * and then copies all of the file attributes from @a src_info to @a dest_info.
   *
   * @param dest_info Destination to copy attributes to.
   */
  void copy_into(Glib::RefPtr<FileInfo>& dest_info) const;

  /** Checks if a file info structure has an attribute named @a attribute.
   *
   * @param attribute A file attribute key.
   * @return <tt>true</tt> if @a info has an attribute named @a attribute,
   * <tt>false</tt> otherwise.
   */
  auto has_attribute(const std::string& attribute) const -> bool;


  /** Checks if a file info structure has an attribute in the
   * specified @a name_space.
   *
   * @newin{2,22}
   *
   * @param name_space A file attribute namespace.
   * @return <tt>true</tt> if @a info has an attribute in @a name_space,
   * <tt>false</tt> otherwise.
   */
  auto has_namespace(const std::string& name_space) const -> bool;


  /** Lists the file info structure's attributes.
   *
   * @param name_space A file attribute key's namespace, or <tt>nullptr</tt> to list
   * all attributes.
   * @return A
   * null-terminated array of strings of all of the possible attribute
   * types for the given @a name_space, or <tt>nullptr</tt> on error.
   */
  auto list_attributes(const std::string& name_space) const -> std::vector<Glib::ustring>;

  /// A list_attributes() convenience overload.
  auto list_attributes() const -> std::vector<Glib::ustring>;


  /** Gets the attribute type for an attribute key.
   *
   * @param attribute A file attribute key.
   * @return A FileAttributeType for the given @a attribute, or
   * G_FILE_ATTRIBUTE_TYPE_INVALID if the key is not set.
   */
  auto get_attribute_type(const std::string& attribute) const -> FileAttributeType;

  /** Removes all cases of @a attribute from @a info if it exists.
   *
   * @param attribute A file attribute key.
   */
  void remove_attribute(const std::string& attribute);


  /** Gets the attribute status for an attribute key.
   *
   * @param attribute A file attribute key.
   * @return A FileAttributeStatus for the given @a attribute, or
   * G_FILE_ATTRIBUTE_STATUS_UNSET if the key is invalid.
   */
  auto get_attribute_status(const std::string& attribute) const -> FileAttributeStatus;


  /** Gets the value of a string attribute. If the attribute does
   * not contain a string, <tt>nullptr</tt> will be returned.
   *
   * @param attribute A file attribute key.
   * @return The contents of the @a attribute value as a UTF-8 string,
   * or <tt>nullptr</tt> otherwise.
   */
  auto get_attribute_string(const std::string& attribute) const -> Glib::ustring;


  /** Gets the value of a stringv attribute. If the attribute does
   * not contain a stringv, <tt>nullptr</tt> will be returned.
   *
   * @newin{2,22}
   *
   * @param attribute A file attribute key.
   * @return The contents of the @a attribute value as a stringv,
   * or <tt>nullptr</tt> otherwise. Do not free. These returned strings are UTF-8.
   */
  auto get_attribute_strings(const std::string& attribute) const -> std::vector<Glib::ustring>;


  /** Gets the value of a attribute, formatted as a string.
   * This escapes things as needed to make the string valid
   * UTF-8.
   *
   * @param attribute A file attribute key.
   * @return A UTF-8 string associated with the given @a attribute, or
   * <tt>nullptr</tt> if the attribute wasn’t set.
   */
  auto get_attribute_as_string(const std::string& attribute) const -> Glib::ustring;

  /** Gets the value of a byte string attribute. If the attribute does
   * not contain a byte string, <tt>nullptr</tt> will be returned.
   *
   * @param attribute A file attribute key.
   * @return The contents of the @a attribute value as a byte string, or
   * <tt>nullptr</tt> otherwise.
   */
  auto get_attribute_byte_string(const std::string& attribute) const -> std::string;

  /** Gets the value of a boolean attribute. If the attribute does not
   * contain a boolean value, <tt>false</tt> will be returned.
   *
   * @param attribute A file attribute key.
   * @return The boolean value contained within the attribute.
   */
  auto get_attribute_boolean(const std::string& attribute) const -> bool;

  /** Gets an unsigned 32-bit integer contained within the attribute. If the
   * attribute does not contain an unsigned 32-bit integer, or is invalid,
   * 0 will be returned.
   *
   * @param attribute A file attribute key.
   * @return An unsigned 32-bit integer from the attribute.
   */
  auto get_attribute_uint32(const std::string& attribute) const -> guint32;

  /** Gets a signed 32-bit integer contained within the attribute. If the
   * attribute does not contain a signed 32-bit integer, or is invalid,
   * 0 will be returned.
   *
   * @param attribute A file attribute key.
   * @return A signed 32-bit integer from the attribute.
   */
  auto get_attribute_int32(const std::string& attribute) const -> gint32;

  /** Gets a unsigned 64-bit integer contained within the attribute. If the
   * attribute does not contain an unsigned 64-bit integer, or is invalid,
   * 0 will be returned.
   *
   * @param attribute A file attribute key.
   * @return A unsigned 64-bit integer from the attribute.
   */
  auto get_attribute_uint64(const std::string& attribute) const -> guint64;

  /** Gets a signed 64-bit integer contained within the attribute. If the
   * attribute does not contain a signed 64-bit integer, or is invalid,
   * 0 will be returned.
   *
   * @param attribute A file attribute key.
   * @return A signed 64-bit integer from the attribute.
   */
  auto get_attribute_int64(const std::string& attribute) const -> gint64;

  /** Gets the value of a Object attribute. If the attribute does
   * not contain a Object, <tt>nullptr</tt> will be returned.
   *
   * @param attribute A file attribute key.
   * @return A Object associated with the given @a attribute,
   * or <tt>nullptr</tt> otherwise.
   */
  auto get_attribute_object(const std::string& attribute) const -> Glib::RefPtr<Glib::Object>;


  /** Sets the attribute status for an attribute key. This is only
   * needed by external code that implement g_file_set_attributes_from_info()
   * or similar functions.
   *
   * The attribute must exist in @a info for this to work. Otherwise <tt>false</tt>
   * is returned and @a info is unchanged.
   *
   * @newin{2,22}
   *
   * @param attribute A file attribute key.
   * @param status A FileAttributeStatus.
   * @return <tt>true</tt> if the status was changed, <tt>false</tt> if the key was not set.
   */
  auto set_attribute_status(const std::string& attribute, FileAttributeStatus status) -> bool;


  /** Sets the @a attribute to contain the given @a attr_value,
   * if possible.
   *
   * @param attribute A file attribute key.
   * @param attr_value A UTF-8 string.
   */
  void set_attribute_string(const std::string& attribute, const Glib::ustring& attr_value);


  /** Sets the @a attribute to contain the given @a attr_value,
   * if possible.
   *
   * Sinze: 2.22
   *
   * @param attribute A file attribute key.
   * @param attr_value A <tt>nullptr</tt>
   * terminated array of UTF-8 strings.
   */
  void set_attribute_strings(const std::string& attribute, const std::vector<Glib::ustring>& attr_value);


  /** Sets the @a attribute to contain the given @a attr_value,
   * if possible.
   *
   * @param attribute A file attribute key.
   * @param attr_value A byte string.
   */
  void set_attribute_byte_string(const std::string& attribute, const std::string& attr_value);

  /** Sets the @a attribute to contain the given @a attr_value,
   * if possible.
   *
   * @param attribute A file attribute key.
   * @param attr_value A boolean value.
   */
  void set_attribute_boolean(const std::string& attribute, bool attr_value);

  /** Sets the @a attribute to contain the given @a attr_value,
   * if possible.
   *
   * @param attribute A file attribute key.
   * @param attr_value An unsigned 32-bit integer.
   */
  void set_attribute_uint32(const std::string& attribute, guint32 attr_value);

  /** Sets the @a attribute to contain the given @a attr_value,
   * if possible.
   *
   * @param attribute A file attribute key.
   * @param attr_value A signed 32-bit integer.
   */
  void set_attribute_int32(const std::string& attribute, gint32 attr_value);

  /** Sets the @a attribute to contain the given @a attr_value,
   * if possible.
   *
   * @param attribute A file attribute key.
   * @param attr_value An unsigned 64-bit integer.
   */
  void set_attribute_uint64(const std::string& attribute, guint64 attr_value);

  /** Sets the @a attribute to contain the given @a attr_value,
   * if possible.
   *
   * @param attribute Attribute name to set.
   * @param attr_value Int64 value to set attribute to.
   */
  void set_attribute_int64(const std::string& attribute, gint64 attr_value);

  /** Sets the @a attribute to contain the given @a attr_value,
   * if possible.
   *
   * @param attribute A file attribute key.
   * @param attr_value A Object.
   */
  void set_attribute_object(const std::string& attribute, const Glib::RefPtr<Glib::Object>& attr_value);

  /** Clears the status information from @a info.
   */
  void clear_status();

  // helper getters


  /** Returns the DateTime representing the deletion date of the file, as
   * available in G_FILE_ATTRIBUTE_TRASH_DELETION_DATE. If the
   * G_FILE_ATTRIBUTE_TRASH_DELETION_DATE attribute is unset, <tt>nullptr</tt> is returned.
   *
   * @newin{2,36}
   *
   * @return A DateTime, or <tt>nullptr</tt>.
   */
  auto get_deletion_date() const -> Glib::DateTime;

  /** Gets a file's type (whether it is a regular file, symlink, etc).
   * This is different from the file's content type, see g_file_info_get_content_type().
   *
   * @return A FileType for the given file.
   */
  auto get_file_type() const -> FileType;

  /** Checks if a file is hidden.
   *
   * @return <tt>true</tt> if the file is a hidden file, <tt>false</tt> otherwise.
   */
  auto is_hidden() const -> bool;

  /** Checks if a file is a backup file.
   *
   * @return <tt>true</tt> if file is a backup file, <tt>false</tt> otherwise.
   */
  auto is_backup() const -> bool;

  /** Checks if a file is a symlink.
   *
   * @return <tt>true</tt> if the given @a info is a symlink.
   */
  auto is_symlink() const -> bool;

  /** Gets the name for a file. This is guaranteed to always be set.
   *
   * @return A string containing the file name.
   */
  auto get_name() const -> std::string;


  /** Gets a display name for a file. This is guaranteed to always be set.
   *
   * @return A string containing the display name.
   */
  auto get_display_name() const -> Glib::ustring;


  /** Gets the edit name for a file.
   *
   * @return A string containing the edit name.
   */
  auto get_edit_name() const -> Glib::ustring;


  /** Gets the icon for a file.
   *
   * @return Icon for the given @a info.
   */
  auto get_icon() -> Glib::RefPtr<Icon>;

  /** Gets the icon for a file.
   *
   * @return Icon for the given @a info.
   */
  auto get_icon() const -> Glib::RefPtr<const Icon>;


  /** Gets the symbolic icon for a file.
   *
   * @newin{2,34}
   *
   * @return Icon for the given @a info.
   */
  auto get_symbolic_icon() -> Glib::RefPtr<Icon>;

  /** Gets the symbolic icon for a file.
   *
   * @newin{2,34}
   *
   * @return Icon for the given @a info.
   */
  auto get_symbolic_icon() const -> Glib::RefPtr<const Icon>;


  /** Gets the file's content type.
   *
   * @return A string containing the file's content type,
   * or <tt>nullptr</tt> if unknown.
   */
  auto get_content_type() const -> Glib::ustring;


  /** Gets the file's size (in bytes). The size is retrieved through the value of
   * the G_FILE_ATTRIBUTE_STANDARD_SIZE attribute and is converted
   * from #guint64 to #goffset before returning the result.
   *
   * @return A #goffset containing the file's size (in bytes).
   */
  auto get_size() const -> goffset;


  /** Gets the modification time of the current @a info and returns it as a
   * DateTime.
   *
   * This requires the G_FILE_ATTRIBUTE_TIME_MODIFIED attribute. If
   * G_FILE_ATTRIBUTE_TIME_MODIFIED_USEC is provided, the resulting DateTime
   * will have microsecond precision.
   *
   * If nanosecond precision is needed, G_FILE_ATTRIBUTE_TIME_MODIFIED_NSEC must
   * be queried separately using g_file_info_get_attribute_uint32().
   *
   * @newin{2,62}
   *
   * @return Modification time, or <tt>nullptr</tt> if unknown.
   */
  auto get_modification_date_time() const -> Glib::DateTime;

  /** Gets the access time of the current @a info and returns it as a
   * DateTime.
   *
   * This requires the G_FILE_ATTRIBUTE_TIME_ACCESS attribute. If
   * G_FILE_ATTRIBUTE_TIME_ACCESS_USEC is provided, the resulting DateTime
   * will have microsecond precision.
   *
   * If nanosecond precision is needed, G_FILE_ATTRIBUTE_TIME_ACCESS_NSEC must
   * be queried separately using g_file_info_get_attribute_uint32().
   *
   * @newin{2,70}
   *
   * @return Access time, or <tt>nullptr</tt> if unknown.
   */
  auto get_access_date_time() const -> Glib::DateTime;

  /** Gets the creation time of the current @a info and returns it as a
   * DateTime.
   *
   * This requires the G_FILE_ATTRIBUTE_TIME_CREATED attribute. If
   * G_FILE_ATTRIBUTE_TIME_CREATED_USEC is provided, the resulting DateTime
   * will have microsecond precision.
   *
   * If nanosecond precision is needed, G_FILE_ATTRIBUTE_TIME_CREATED_NSEC must
   * be queried separately using g_file_info_get_attribute_uint32().
   *
   * @newin{2,70}
   *
   * @return Creation time, or <tt>nullptr</tt> if unknown.
   */
  auto get_creation_date_time() const -> Glib::DateTime;


  /** Gets the symlink target for a given FileInfo.
   *
   * @return A string containing the symlink target.
   */
  auto get_symlink_target() const -> std::string;


  /** Gets the [entity tag][gfile-etag] for a given
   * FileInfo. See G_FILE_ATTRIBUTE_ETAG_VALUE.
   *
   * @return A string containing the value of the "etag:value" attribute.
   */
  auto get_etag() const -> Glib::ustring;


  /** Gets the value of the sort_order attribute from the FileInfo.
   * See G_FILE_ATTRIBUTE_STANDARD_SORT_ORDER.
   *
   * @return A #gint32 containing the value of the "standard::sort_order" attribute.
   */
  auto get_sort_order() const -> gint32;

  /** Sets @a mask on @a info to match specific attribute types.
   *
   * @param mask A FileAttributeMatcher.
   */
  void set_attribute_mask(const Glib::RefPtr<FileAttributeMatcher>& mask);

  /** Unsets a mask set by g_file_info_set_attribute_mask(), if one
   * is set.
   */
  void unset_attribute_mask();

  // helper setters


  /** Sets the file type in a FileInfo to @a type.
   * See G_FILE_ATTRIBUTE_STANDARD_TYPE.
   *
   * @param type A FileType.
   */
  void set_file_type(FileType type);

  /** Sets the "is_hidden" attribute in a FileInfo according to @a hidden.
   * See G_FILE_ATTRIBUTE_STANDARD_IS_HIDDEN.
   *
   * @param hidden A <tt>bool</tt>.
   */
  void set_is_hidden(bool hidden =  true);

  /** Sets the "is_symlink" attribute in a FileInfo according to @a symlink.
   * See G_FILE_ATTRIBUTE_STANDARD_IS_SYMLINK.
   *
   * @param symlink A <tt>bool</tt>.
   */
  void set_is_symlink(bool symlink =  true);

  /** Sets the name attribute for the current FileInfo.
   * See G_FILE_ATTRIBUTE_STANDARD_NAME.
   *
   * @param name A string containing a name.
   */
  void set_name(const std::string& name);


  /** Sets the display name for the current FileInfo.
   * See G_FILE_ATTRIBUTE_STANDARD_DISPLAY_NAME.
   *
   * @param display_name A string containing a display name.
   */
  void set_display_name(const Glib::ustring& display_name);


  /** Sets the edit name for the current file.
   * See G_FILE_ATTRIBUTE_STANDARD_EDIT_NAME.
   *
   * @param edit_name A string containing an edit name.
   */
  void set_edit_name(const Glib::ustring& edit_name);


  /** Sets the icon for a given FileInfo.
   * See G_FILE_ATTRIBUTE_STANDARD_ICON.
   *
   * @param icon A Icon.
   */
  void set_icon(const Glib::RefPtr<Icon>& icon);

  /** Sets the symbolic icon for a given FileInfo.
   * See G_FILE_ATTRIBUTE_STANDARD_SYMBOLIC_ICON.
   *
   * @newin{2,34}
   *
   * @param icon A Icon.
   */
  void set_symbolic_icon(const Glib::RefPtr<Icon>& icon);


  /** Sets the content type attribute for a given FileInfo.
   * See G_FILE_ATTRIBUTE_STANDARD_CONTENT_TYPE.
   *
   * @param content_type A content type. See [GContentType][gio-GContentType].
   */
  void set_content_type(const Glib::ustring& content_type);


  /** Sets the G_FILE_ATTRIBUTE_STANDARD_SIZE attribute in the file info
   * to the given size.
   *
   * @param size A #goffset containing the file's size.
   */
  void set_size(goffset size);


  /** Sets the G_FILE_ATTRIBUTE_TIME_MODIFIED and
   * G_FILE_ATTRIBUTE_TIME_MODIFIED_USEC attributes in the file info to the
   * given date/time value.
   *
   * G_FILE_ATTRIBUTE_TIME_MODIFIED_NSEC will be cleared.
   *
   * @newin{2,62}
   *
   * @param mtime A DateTime.
   */
  void set_modification_date_time(const Glib::DateTime& mtime);

  /** Sets the G_FILE_ATTRIBUTE_TIME_ACCESS and
   * G_FILE_ATTRIBUTE_TIME_ACCESS_USEC attributes in the file info to the
   * given date/time value.
   *
   * G_FILE_ATTRIBUTE_TIME_ACCESS_NSEC will be cleared.
   *
   * @newin{2,70}
   *
   * @param atime A DateTime.
   */
  void set_access_date_time(const Glib::DateTime& atime);

  /** Sets the G_FILE_ATTRIBUTE_TIME_CREATED and
   * G_FILE_ATTRIBUTE_TIME_CREATED_USEC attributes in the file info to the
   * given date/time value.
   *
   * G_FILE_ATTRIBUTE_TIME_CREATED_NSEC will be cleared.
   *
   * @newin{2,70}
   *
   * @param creation_time A DateTime.
   */
  void set_creation_date_time(const Glib::DateTime& creation_time);


  /** Sets the G_FILE_ATTRIBUTE_STANDARD_SYMLINK_TARGET attribute in the file info
   * to the given symlink target.
   *
   * @param symlink_target A static string containing a path to a symlink target.
   */
  void set_symlink_target(const std::string& symlink_target);

  /** Sets the sort order attribute in the file info structure. See
   * G_FILE_ATTRIBUTE_STANDARD_SORT_ORDER.
   *
   * @param sort_order A sort order integer.
   */
  void set_sort_order(gint32 sort_order);


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

/** A Glib::wrap() method for this object.
 *
 * @param object The C instance.
 * @param take_copy False if the result should take ownership of the C instance. True if it should take a new copy or ref.
 * @result A C++ instance that wraps this C instance.
 *
 * @relates Gio::FileAttributeMatcher
 */
GIOMM_API
auto wrap(GFileAttributeMatcher* object, bool take_copy = false) -> Glib::RefPtr<Gio::FileAttributeMatcher>;

} // namespace Glib


namespace Glib
{
  /** A Glib::wrap() method for this object.
   *
   * @param object The C instance.
   * @param take_copy False if the result should take ownership of the C instance. True if it should take a new copy or ref.
   * @result A C++ instance that wraps this C instance.
   *
   * @relates Gio::FileInfo
   */
  GIOMM_API
  auto wrap(GFileInfo* object, bool take_copy = false) -> Glib::RefPtr<Gio::FileInfo>;
}


#endif /* _GIOMM_FILEINFO_H */
