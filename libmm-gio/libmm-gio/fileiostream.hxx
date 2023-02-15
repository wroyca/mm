// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GIOMM_FILEIOSTREAM_H
#define _GIOMM_FILEIOSTREAM_H

#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm-gio/fileinfo.hxx>
#include <libmm-gio/iostream.hxx>
#include <libmm-gio/seekable.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GFileIOStream = struct _GFileIOStream;
using GFileIOStreamClass = struct _GFileIOStreamClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gio
{
  class GIOMM_API FileIOStream_Class;
}
#endif

namespace Gio
{

  class GIOMM_API FileIOStream : public Gio::IOStream,
                                 public Gio::Seekable
  {
#ifndef DOXYGEN_SHOULD_SKIP_THIS

  public:
    using CppObjectType = FileIOStream;
    using CppClassType = FileIOStream_Class;
    using BaseObjectType = GFileIOStream;
    using BaseClassType = GFileIOStreamClass;

    FileIOStream (const FileIOStream&) = delete;
    auto
    operator= (const FileIOStream&) -> FileIOStream& = delete;

  private:
    friend class FileIOStream_Class;
    static CppClassType fileiostream_class_;

  protected:
    explicit FileIOStream (const Glib::ConstructParams& construct_params);
    explicit FileIOStream (GFileIOStream* castitem);

#endif

  public:
    FileIOStream (FileIOStream&& src) noexcept;
    auto
    operator= (FileIOStream&& src) noexcept -> FileIOStream&;

    ~FileIOStream () noexcept override;

    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GFileIOStream*
    {
      return reinterpret_cast<GFileIOStream*> (gobject_);
    }

    auto
    gobj () const -> const GFileIOStream*
    {
      return reinterpret_cast<GFileIOStream*> (gobject_);
    }

    auto
    gobj_copy () -> GFileIOStream*;

  private:
  public:
    auto
    query_info (const Glib::RefPtr<Cancellable>& cancellable,
                const std::string& attributes = "*") -> Glib::RefPtr<FileInfo>;

    auto
    query_info (const std::string& attributes = "*") -> Glib::RefPtr<FileInfo>;

    auto
    query_info_async (const SlotAsyncReady& slot,
                      const Glib::RefPtr<Cancellable>& cancellable,
                      const std::string& attributes = "*",
                      int io_priority = Glib::PRIORITY_DEFAULT) -> void;

    auto
    query_info_async (const SlotAsyncReady& slot,
                      const std::string& attributes = "*",
                      int io_priority = Glib::PRIORITY_DEFAULT) -> void;

    auto
    query_info_finish (const Glib::RefPtr<AsyncResult>& result)
        -> Glib::RefPtr<FileInfo>;

    auto
    get_etag () const -> Glib::ustring;

  public:
  public:
  protected:
  };

} // namespace Gio

namespace Glib
{

  GIOMM_API
  auto
  wrap (GFileIOStream* object, bool take_copy = false) -> Glib::RefPtr<Gio::FileIOStream>;
} // namespace Glib

#endif
