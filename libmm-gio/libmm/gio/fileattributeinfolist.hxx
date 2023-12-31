// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GIOMM_FILEATTRIBUTEINFOLIST_H
#define _GIOMM_FILEATTRIBUTEINFOLIST_H

#include <libmm/glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm/gio/fileattributeinfo.hxx>

namespace gio
{

  class LIBMM_GIO_SYMEXPORT FileAttributeInfoList final
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    using CppObjectType = FileAttributeInfoList;
    using BaseObjectType = GFileAttributeInfoList;
#endif

    static auto
    create () -> glib::RefPtr<FileAttributeInfoList>;

    auto
    reference () const -> void;

    auto
    unreference () const -> void;

    auto
    gobj () -> GFileAttributeInfoList*;

    auto
    gobj () const -> const GFileAttributeInfoList*;

    auto
    gobj_copy () const -> GFileAttributeInfoList*;

    FileAttributeInfoList () = delete;

    FileAttributeInfoList (const FileAttributeInfoList&) = delete;
    auto
    operator= (const FileAttributeInfoList&) -> FileAttributeInfoList& = delete;

  protected:
    auto
    operator delete (void*, std::size_t) -> void;

  private:
  public:
    explicit operator bool () const;

    auto
    empty () const -> bool;

    auto
    lookup (const std::string& name) const -> FileAttributeInfo;

    auto
    dup () const -> glib::RefPtr<FileAttributeInfoList>;

    auto
    add (const std::string& name,
         FileAttributeType type,
         FileAttributeInfo::Flags flags = FileAttributeInfo::Flags::NONE)
        -> void;
  };

} // namespace gio

namespace glib
{

  LIBMM_GIO_SYMEXPORT
  auto
  wrap (GFileAttributeInfoList* object, bool take_copy = false) -> glib::RefPtr<gio::FileAttributeInfoList>;

} // namespace glib

#endif
