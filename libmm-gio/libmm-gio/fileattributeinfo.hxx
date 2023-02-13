
#ifndef _GIOMM_FILEATTRIBUTEINFO_H
#define _GIOMM_FILEATTRIBUTEINFO_H

#include <libmm-gio/gioconfig.hxx>


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


#include <string>
#include <gio/gio.h>
#include <libmm-glib/object.hxx>


namespace Gio
{

/** @addtogroup giommEnums giomm Enums and Flags */

/**
 *  @var FileAttributeType INVALID
 * Indicates an invalid or uninitialized type.
 *
 *  @var FileAttributeType STRING
 * A null terminated UTF8 string.
 *
 *  @var FileAttributeType BYTE_STRING
 * A zero terminated string of non-zero bytes.
 *
 *  @var FileAttributeType BOOLEAN
 * A boolean value.
 *
 *  @var FileAttributeType UINT32
 * An unsigned 4-byte/32-bit integer.
 *
 *  @var FileAttributeType INT32
 * A signed 4-byte/32-bit integer.
 *
 *  @var FileAttributeType UINT64
 * An unsigned 8-byte/64-bit integer.
 *
 *  @var FileAttributeType INT64
 * A signed 8-byte/64-bit integer.
 *
 *  @var FileAttributeType OBJECT
 * A Object.
 *
 *  @var FileAttributeType STRINGV
 * A <tt>nullptr</tt> terminated char **. @newin{2,22}
 *
 *  @enum FileAttributeType
 *
 * The data types for file attributes.
 *
 * @ingroup giommEnums
 */
enum class FileAttributeType
{
  INVALID,
  STRING,
  BYTE_STRING,
  BOOLEAN,
  UINT32,
  INT32,
  UINT64,
  INT64,
  OBJECT,
  STRINGV
};


} // namespace Gio

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

template <>
class GIOMM_API Value<Gio::FileAttributeType> : public Glib::Value_Enum<Gio::FileAttributeType>
{
public:
  static auto value_type() -> GType G_GNUC_CONST;
};

} // namespace Glib
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

namespace Gio
{

/**
 *  @var FileAttributeStatus UNSET
 * Attribute value is unset (empty).
 *
 *  @var FileAttributeStatus SET
 * Attribute value is set.
 *
 *  @var FileAttributeStatus ERROR_SETTING
 * Indicates an error in setting the value.
 *
 *  @enum FileAttributeStatus
 *
 * Used by g_file_set_attributes_from_info() when setting file attributes.
 *
 * @ingroup giommEnums
 */
enum class FileAttributeStatus
{
  UNSET,
  SET,
  ERROR_SETTING
};


} // namespace Gio

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

template <>
class GIOMM_API Value<Gio::FileAttributeStatus> : public Glib::Value_Enum<Gio::FileAttributeStatus>
{
public:
  static auto value_type() -> GType G_GNUC_CONST;
};

} // namespace Glib
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

namespace Gio
{


/** Information about a specific attribute - see FileAttributeInfoList.
 *
 * @newin{2,16}
 */
class FileAttributeInfo
{
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  using CppObjectType = FileAttributeInfo;
  using BaseObjectType = GFileAttributeInfo;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

private:

public:
  /**
   *  @var Flags NONE
   * No flags set.
   *
   *  @var Flags COPY_WITH_FILE
   * Copy the attribute values when the file is copied.
   *
   *  @var Flags COPY_WHEN_MOVED
   * Copy the attribute values when the file is moved.
   *
   *  @enum Flags
   *
   * Flags specifying the behaviour of an attribute.
   *
   * @ingroup giommEnums
   * @par Bitwise operators:
   * <tt>FileAttributeInfo::Flags operator|(FileAttributeInfo::Flags, FileAttributeInfo::Flags)</tt><br>
   * <tt>FileAttributeInfo::Flags operator&(FileAttributeInfo::Flags, FileAttributeInfo::Flags)</tt><br>
   * <tt>FileAttributeInfo::Flags operator^(FileAttributeInfo::Flags, FileAttributeInfo::Flags)</tt><br>
   * <tt>FileAttributeInfo::Flags operator~(FileAttributeInfo::Flags)</tt><br>
   * <tt>FileAttributeInfo::Flags& operator|=(FileAttributeInfo::Flags&, FileAttributeInfo::Flags)</tt><br>
   * <tt>FileAttributeInfo::Flags& operator&=(FileAttributeInfo::Flags&, FileAttributeInfo::Flags)</tt><br>
   * <tt>FileAttributeInfo::Flags& operator^=(FileAttributeInfo::Flags&, FileAttributeInfo::Flags)</tt><br>
   */
  enum class Flags
  {
    NONE = 0x0,
    COPY_WITH_FILE = (1 << 0),
    COPY_WHEN_MOVED = (1 << 1)
  };


  GIOMM_API explicit FileAttributeInfo(const GFileAttributeInfo* ginfo);

  GIOMM_API FileAttributeInfo(const FileAttributeInfo& other);
  GIOMM_API auto operator=(const FileAttributeInfo& other) -> FileAttributeInfo&;

  GIOMM_API FileAttributeInfo(FileAttributeInfo&& other) noexcept;
  GIOMM_API auto operator=(FileAttributeInfo&& other) noexcept -> FileAttributeInfo&;

  GIOMM_API ~FileAttributeInfo();

  GIOMM_API auto get_name() const -> std::string;
  GIOMM_API auto get_type() const -> FileAttributeType;
  GIOMM_API auto get_flags() const -> Flags;

protected:
  std::string m_name;
  FileAttributeType m_type;
  Flags m_flags;


};

} // namespace Gio


namespace Gio
{

/** @ingroup giommEnums */
inline auto operator|(FileAttributeInfo::Flags lhs, FileAttributeInfo::Flags rhs) -> FileAttributeInfo::Flags
  { return static_cast<FileAttributeInfo::Flags>(static_cast<unsigned>(lhs) | static_cast<unsigned>(rhs)); }

/** @ingroup giommEnums */
inline auto operator&(FileAttributeInfo::Flags lhs, FileAttributeInfo::Flags rhs) -> FileAttributeInfo::Flags
  { return static_cast<FileAttributeInfo::Flags>(static_cast<unsigned>(lhs) & static_cast<unsigned>(rhs)); }

/** @ingroup giommEnums */
inline auto operator^(FileAttributeInfo::Flags lhs, FileAttributeInfo::Flags rhs) -> FileAttributeInfo::Flags
  { return static_cast<FileAttributeInfo::Flags>(static_cast<unsigned>(lhs) ^ static_cast<unsigned>(rhs)); }

/** @ingroup giommEnums */
inline auto operator~(FileAttributeInfo::Flags flags) -> FileAttributeInfo::Flags
  { return static_cast<FileAttributeInfo::Flags>(~static_cast<unsigned>(flags)); }

/** @ingroup giommEnums */
inline auto operator|=(FileAttributeInfo::Flags& lhs, FileAttributeInfo::Flags rhs) -> FileAttributeInfo::Flags&
  { return (lhs = static_cast<FileAttributeInfo::Flags>(static_cast<unsigned>(lhs) | static_cast<unsigned>(rhs))); }

/** @ingroup giommEnums */
inline auto operator&=(FileAttributeInfo::Flags& lhs, FileAttributeInfo::Flags rhs) -> FileAttributeInfo::Flags&
  { return (lhs = static_cast<FileAttributeInfo::Flags>(static_cast<unsigned>(lhs) & static_cast<unsigned>(rhs))); }

/** @ingroup giommEnums */
inline auto operator^=(FileAttributeInfo::Flags& lhs, FileAttributeInfo::Flags rhs) -> FileAttributeInfo::Flags&
  { return (lhs = static_cast<FileAttributeInfo::Flags>(static_cast<unsigned>(lhs) ^ static_cast<unsigned>(rhs))); }
} // namespace Gio

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

template <>
class  Value<Gio::FileAttributeInfo::Flags> : public Glib::Value_Flags<Gio::FileAttributeInfo::Flags>
{
public:
  static auto value_type() -> GType G_GNUC_CONST;
};

} // namespace Glib
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#endif /* _GIOMM_FILEATTRIBUTEINFO_H */

