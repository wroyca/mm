// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GIOMM_FILEATTRIBUTEINFO_H
#define _GIOMM_FILEATTRIBUTEINFO_H

#include <libmm/gio/mm-gioconfig.hxx>

#include <libmm/glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <gio/gio.h>
#include <libmm/glib/object.hxx>
#include <string>

namespace gio
{

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

} // namespace gio

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace glib
{

  template <>
  class LIBMM_GIO_SYMEXPORT Value<gio::FileAttributeType>
    : public glib::Value_Enum<gio::FileAttributeType>
  {
  public:
    static auto
    value_type () -> GType G_GNUC_CONST;
  };

} // namespace glib
#endif

namespace gio
{

  enum class FileAttributeStatus
  {
    UNSET,
    SET,
    ERROR_SETTING
  };

} // namespace gio

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace glib
{

  template <>
  class LIBMM_GIO_SYMEXPORT Value<gio::FileAttributeStatus>
    : public glib::Value_Enum<gio::FileAttributeStatus>
  {
  public:
    static auto
    value_type () -> GType G_GNUC_CONST;
  };

} // namespace glib
#endif

namespace gio
{

  class FileAttributeInfo
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    using CppObjectType = FileAttributeInfo;
    using BaseObjectType = GFileAttributeInfo;
#endif

  private:
  public:
    enum class Flags
    {
      NONE = 0x0,
      COPY_WITH_FILE = (1 << 0),
      COPY_WHEN_MOVED = (1 << 1)
    };

    LIBMM_GIO_SYMEXPORT explicit FileAttributeInfo (const GFileAttributeInfo* ginfo);

    LIBMM_GIO_SYMEXPORT
    FileAttributeInfo (const FileAttributeInfo& other);
    LIBMM_GIO_SYMEXPORT auto
    operator= (const FileAttributeInfo& other) -> FileAttributeInfo&;

    LIBMM_GIO_SYMEXPORT
    FileAttributeInfo (FileAttributeInfo&& other) noexcept;
    LIBMM_GIO_SYMEXPORT auto
    operator= (FileAttributeInfo&& other) noexcept -> FileAttributeInfo&;

    LIBMM_GIO_SYMEXPORT ~FileAttributeInfo ();

    LIBMM_GIO_SYMEXPORT auto
    get_name () const -> std::string;
    LIBMM_GIO_SYMEXPORT auto
    get_type () const -> FileAttributeType;
    LIBMM_GIO_SYMEXPORT auto
    get_flags () const -> Flags;

  protected:
    std::string m_name;
    FileAttributeType m_type;
    Flags m_flags;
  };

} // namespace gio

namespace gio
{

  inline auto
  operator| (FileAttributeInfo::Flags lhs, FileAttributeInfo::Flags rhs) -> FileAttributeInfo::Flags
  {
    return static_cast<FileAttributeInfo::Flags> (static_cast<unsigned> (lhs) |
                                                  static_cast<unsigned> (rhs));
  }

  inline auto
  operator& (FileAttributeInfo::Flags lhs, FileAttributeInfo::Flags rhs) -> FileAttributeInfo::Flags
  {
    return static_cast<FileAttributeInfo::Flags> (static_cast<unsigned> (lhs) &
                                                  static_cast<unsigned> (rhs));
  }

  inline auto
  operator^ (FileAttributeInfo::Flags lhs, FileAttributeInfo::Flags rhs) -> FileAttributeInfo::Flags
  {
    return static_cast<FileAttributeInfo::Flags> (static_cast<unsigned> (lhs) ^
                                                  static_cast<unsigned> (rhs));
  }

  inline auto
  operator~(FileAttributeInfo::Flags flags) -> FileAttributeInfo::Flags
  {
    return static_cast<FileAttributeInfo::Flags> (
        ~static_cast<unsigned> (flags));
  }

  inline auto
  operator|= (FileAttributeInfo::Flags& lhs, FileAttributeInfo::Flags rhs) -> FileAttributeInfo::Flags&
  {
    return (lhs = static_cast<FileAttributeInfo::Flags> (
                static_cast<unsigned> (lhs) | static_cast<unsigned> (rhs)));
  }

  inline auto
  operator&= (FileAttributeInfo::Flags& lhs, FileAttributeInfo::Flags rhs) -> FileAttributeInfo::Flags&
  {
    return (lhs = static_cast<FileAttributeInfo::Flags> (
                static_cast<unsigned> (lhs) & static_cast<unsigned> (rhs)));
  }

  inline auto
  operator^= (FileAttributeInfo::Flags& lhs, FileAttributeInfo::Flags rhs) -> FileAttributeInfo::Flags&
  {
    return (lhs = static_cast<FileAttributeInfo::Flags> (
                static_cast<unsigned> (lhs) ^ static_cast<unsigned> (rhs)));
  }
} // namespace gio

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace glib
{

  template <>
  class Value<gio::FileAttributeInfo::Flags>
    : public glib::Value_Flags<gio::FileAttributeInfo::Flags>
  {
  public:
    static auto
    value_type () -> GType G_GNUC_CONST;
  };

} // namespace glib
#endif

#endif
