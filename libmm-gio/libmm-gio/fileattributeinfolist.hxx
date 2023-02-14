
#ifndef _GIOMM_FILEATTRIBUTEINFOLIST_H
#define _GIOMM_FILEATTRIBUTEINFOLIST_H

#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm-gio/fileattributeinfo.hxx>

namespace Gio
{

  class GIOMM_API FileAttributeInfoList final
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    using CppObjectType = FileAttributeInfoList;
    using BaseObjectType = GFileAttributeInfoList;
#endif

    static auto
    create () -> Glib::RefPtr<FileAttributeInfoList>;

    void
    reference () const;

    void
    unreference () const;

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
    void
    operator delete (void*, std::size_t);

  private:
  public:
    explicit operator bool () const;

    auto
    empty () const -> bool;

    auto
    lookup (const std::string& name) const -> FileAttributeInfo;

    auto
    dup () const -> Glib::RefPtr<FileAttributeInfoList>;

    void
    add (const std::string& name,
         FileAttributeType type,
         FileAttributeInfo::Flags flags = FileAttributeInfo::Flags::NONE);
  };

} // namespace Gio

namespace Glib
{

  GIOMM_API
  auto
  wrap (GFileAttributeInfoList* object, bool take_copy = false) -> Glib::RefPtr<Gio::FileAttributeInfoList>;

} // namespace Glib

#endif
