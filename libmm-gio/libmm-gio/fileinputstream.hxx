// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GIOMM_FILEINPUTSTREAM_H
#define _GIOMM_FILEINPUTSTREAM_H

#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm-gio/fileinfo.hxx>
#include <libmm-gio/inputstream.hxx>
#include <libmm-gio/seekable.hxx>
#include <libmm-glib/iochannel.hxx>
#include <libmm-glib/object.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GFileInputStream = struct _GFileInputStream;
using GFileInputStreamClass = struct _GFileInputStreamClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gio
{
  class LIBMM_GIO_SYMEXPORT FileInputStream_Class;
}
#endif

namespace Gio
{

  class LIBMM_GIO_SYMEXPORT FileInputStream : public Gio::InputStream,
                                    public Seekable
  {
#ifndef DOXYGEN_SHOULD_SKIP_THIS

  public:
    using CppObjectType = FileInputStream;
    using CppClassType = FileInputStream_Class;
    using BaseObjectType = GFileInputStream;
    using BaseClassType = GFileInputStreamClass;

    FileInputStream (const FileInputStream&) = delete;
    auto
    operator= (const FileInputStream&) -> FileInputStream& = delete;

  private:
    friend class FileInputStream_Class;
    static CppClassType fileinputstream_class_;

  protected:
    explicit FileInputStream (const Glib::ConstructParams& construct_params);
    explicit FileInputStream (GFileInputStream* castitem);

#endif

  public:
    FileInputStream (FileInputStream&& src) noexcept;
    auto
    operator= (FileInputStream&& src) noexcept -> FileInputStream&;

    ~FileInputStream () noexcept override;

    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GFileInputStream*
    {
      return reinterpret_cast<GFileInputStream*> (gobject_);
    }

    auto
    gobj () const -> const GFileInputStream*
    {
      return reinterpret_cast<GFileInputStream*> (gobject_);
    }

    auto
    gobj_copy () -> GFileInputStream*;

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

  public:
  public:
  protected:
  };

} // namespace Gio

namespace Glib
{

  LIBMM_GIO_SYMEXPORT
  auto
  wrap (GFileInputStream* object, bool take_copy = false) -> Glib::RefPtr<Gio::FileInputStream>;
} // namespace Glib

#endif
