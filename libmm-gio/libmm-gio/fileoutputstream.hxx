// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GIOMM_FILEOUTPUTSTREAM_H
#define _GIOMM_FILEOUTPUTSTREAM_H

#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm-gio/fileinfo.hxx>
#include <libmm-gio/outputstream.hxx>
#include <libmm-gio/seekable.hxx>
#include <libmm-glib/iochannel.hxx>
#include <libmm-glib/object.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GFileOutputStream = struct _GFileOutputStream;
using GFileOutputStreamClass = struct _GFileOutputStreamClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gio
{
  class LIBMM_GIO_SYMEXPORT FileOutputStream_Class;
}
#endif

namespace Gio
{

  class LIBMM_GIO_SYMEXPORT FileOutputStream : public OutputStream,
                                     public Seekable
  {
#ifndef DOXYGEN_SHOULD_SKIP_THIS

  public:
    using CppObjectType = FileOutputStream;
    using CppClassType = FileOutputStream_Class;
    using BaseObjectType = GFileOutputStream;
    using BaseClassType = GFileOutputStreamClass;

    FileOutputStream (const FileOutputStream&) = delete;
    auto
    operator= (const FileOutputStream&) -> FileOutputStream& = delete;

  private:
    friend class FileOutputStream_Class;
    static CppClassType fileoutputstream_class_;

  protected:
    explicit FileOutputStream (const Glib::ConstructParams& construct_params);
    explicit FileOutputStream (GFileOutputStream* castitem);

#endif

  public:
    FileOutputStream (FileOutputStream&& src) noexcept;
    auto
    operator= (FileOutputStream&& src) noexcept -> FileOutputStream&;

    ~FileOutputStream () noexcept override;

    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GFileOutputStream*
    {
      return reinterpret_cast<GFileOutputStream*> (gobject_);
    }

    auto
    gobj () const -> const GFileOutputStream*
    {
      return reinterpret_cast<GFileOutputStream*> (gobject_);
    }

    auto
    gobj_copy () -> GFileOutputStream*;

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

  LIBMM_GIO_SYMEXPORT
  auto
  wrap (GFileOutputStream* object, bool take_copy = false) -> Glib::RefPtr<Gio::FileOutputStream>;
} // namespace Glib

#endif
