// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GLIBMM_FILEUTILS_H
#define _GLIBMM_FILEUTILS_H

#ifndef DOXYGEN_SHOULD_SKIP_THIS
extern "C"
{
  typedef struct _GDir GDir;
}
#endif

#include <iterator>
#include <libmm-glib/error.hxx>
#include <string>

namespace Glib
{

  enum class FileTest
  {
    IS_REGULAR = 1 << 0,
    IS_SYMLINK = 1 << 1,
    IS_DIR = 1 << 2,
    IS_EXECUTABLE = 1 << 3,
    EXISTS = 1 << 4
  };

  inline auto
  operator| (FileTest lhs, FileTest rhs) -> FileTest
  {
    return static_cast<FileTest> (static_cast<unsigned> (lhs) |
                                  static_cast<unsigned> (rhs));
  }

  inline auto
  operator& (FileTest lhs, FileTest rhs) -> FileTest
  {
    return static_cast<FileTest> (static_cast<unsigned> (lhs) &
                                  static_cast<unsigned> (rhs));
  }

  inline auto
  operator^ (FileTest lhs, FileTest rhs) -> FileTest
  {
    return static_cast<FileTest> (static_cast<unsigned> (lhs) ^
                                  static_cast<unsigned> (rhs));
  }

  inline auto
  operator~(FileTest flags) -> FileTest
  {
    return static_cast<FileTest> (~static_cast<unsigned> (flags));
  }

  inline auto
  operator|= (FileTest& lhs, FileTest rhs) -> FileTest&
  {
    return (lhs = static_cast<FileTest> (static_cast<unsigned> (lhs) |
                                         static_cast<unsigned> (rhs)));
  }

  inline auto
  operator&= (FileTest& lhs, FileTest rhs) -> FileTest&
  {
    return (lhs = static_cast<FileTest> (static_cast<unsigned> (lhs) &
                                         static_cast<unsigned> (rhs)));
  }

  inline auto
  operator^= (FileTest& lhs, FileTest rhs) -> FileTest&
  {
    return (lhs = static_cast<FileTest> (static_cast<unsigned> (lhs) ^
                                         static_cast<unsigned> (rhs)));
  }

  class FileError : public Glib::Error
  {
  public:
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

    GLIBMM_API
    FileError (Code error_code, const Glib::ustring& error_message);
    GLIBMM_API explicit FileError (GError* gobject);
    GLIBMM_API auto
    code () const -> Code;

#ifndef DOXYGEN_SHOULD_SKIP_THIS
  private:
    GLIBMM_API static auto
    throw_func (GError* gobject) -> void;

    friend GLIBMM_API auto
    wrap_init () -> void;

#endif
  };

  class Dir;

  class GLIBMM_API DirIterator
  {
  public:
    typedef std::input_iterator_tag iterator_category;
    typedef std::string value_type;
    typedef int difference_type;
    typedef value_type reference;
    typedef void pointer;

    DirIterator ();

#ifndef DOXYGEN_SHOULD_SKIP_THIS
    DirIterator (GDir* gobject, const char* current);
#endif

    auto
    operator* () const -> std::string;
    auto
    operator++ () -> DirIterator&;

    auto
    operator++ (int) -> void;

    auto
    operator== (const DirIterator& rhs) const -> bool;
    auto
    operator!= (const DirIterator& rhs) const -> bool;

  private:
    GDir* gobject_;
    const char* current_;
  };

  class GLIBMM_API Dir
  {
  public:
    using iterator = DirIterator;
    using const_iterator = DirIterator;

    explicit Dir (const std::string& path);

#ifndef DOXYGEN_SHOULD_SKIP_THIS
    explicit Dir (GDir* gobject);
#endif

    Dir (const Dir&) = delete;
    auto
    operator= (const Dir&) -> Dir& = delete;

    ~Dir ();

    auto
    read_name () -> std::string;

    auto
    rewind () -> void;

    auto
    close () -> void;

    auto
    begin () -> DirIterator;

    auto
    end () -> DirIterator;

  private:
    GDir* gobject_;
  };

  GLIBMM_API
  auto
  file_test (const std::string& filename, FileTest test) -> bool;

  GLIBMM_API
  auto
  mkstemp (std::string& filename_template) -> int;

  GLIBMM_API
  auto
  file_open_tmp (std::string& name_used, const std::string& prefix) -> int;

  GLIBMM_API
  auto
  file_open_tmp (std::string& name_used) -> int;

  GLIBMM_API
  auto
  file_get_contents (const std::string& filename) -> std::string;

  GLIBMM_API auto
  file_set_contents (const std::string& filename,
                     const gchar* contents,
                     gssize length) -> void;

  GLIBMM_API auto
  file_set_contents (const std::string& filename, const std::string& contents) -> void;

} // namespace Glib

#endif
