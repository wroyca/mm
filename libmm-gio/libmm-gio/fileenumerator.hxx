// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GIOMM_FILEENUMERATOR_H
#define _GIOMM_FILEENUMERATOR_H

#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm-gio/asyncresult.hxx>
#include <libmm-gio/cancellable.hxx>
#include <libmm-gio/fileinfo.hxx>
#include <libmm-glib/object.hxx>
#include <libmm-glib/priorities.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GFileEnumerator = struct _GFileEnumerator;
using GFileEnumeratorClass = struct _GFileEnumeratorClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gio
{
  class GIOMM_API FileEnumerator_Class;
}
#endif

namespace Gio
{

  class GIOMM_API File;

  class GIOMM_API FileEnumerator : public Glib::Object
  {
#ifndef DOXYGEN_SHOULD_SKIP_THIS

  public:
    using CppObjectType = FileEnumerator;
    using CppClassType = FileEnumerator_Class;
    using BaseObjectType = GFileEnumerator;
    using BaseClassType = GFileEnumeratorClass;

    FileEnumerator (const FileEnumerator&) = delete;
    auto
    operator= (const FileEnumerator&) -> FileEnumerator& = delete;

  private:
    friend class FileEnumerator_Class;
    static CppClassType fileenumerator_class_;

  protected:
    explicit FileEnumerator (const Glib::ConstructParams& construct_params);
    explicit FileEnumerator (GFileEnumerator* castitem);

#endif

  public:
    FileEnumerator (FileEnumerator&& src) noexcept;
    auto
    operator= (FileEnumerator&& src) noexcept -> FileEnumerator&;

    ~FileEnumerator () noexcept override;

    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GFileEnumerator*
    {
      return reinterpret_cast<GFileEnumerator*> (gobject_);
    }

    auto
    gobj () const -> const GFileEnumerator*
    {
      return reinterpret_cast<GFileEnumerator*> (gobject_);
    }

    auto
    gobj_copy () -> GFileEnumerator*;

  private:
  public:
    auto
    next_file (const Glib::RefPtr<Cancellable>& cancellable)
        -> Glib::RefPtr<FileInfo>;

    auto
    next_file () -> Glib::RefPtr<FileInfo>;

    auto
    close (const Glib::RefPtr<Cancellable>& cancellable) -> bool;

    auto
    close () -> bool;

    auto
    next_files_async (const SlotAsyncReady& slot,
                      const Glib::RefPtr<Cancellable>& cancellable,
                      int num_files = 1,
                      int io_priority = Glib::PRIORITY_DEFAULT) -> void;

    auto
    next_files_async (const SlotAsyncReady& slot,
                      int num_files = 1,
                      int io_priority = Glib::PRIORITY_DEFAULT) -> void;

    auto
    next_files_finish (const Glib::RefPtr<AsyncResult>& result)
        -> std::vector<Glib::RefPtr<FileInfo>>;

    auto
    close_async (int io_priority,
                 const Glib::RefPtr<Cancellable>& cancellable,
                 const SlotAsyncReady& slot) -> void;

    auto
    close_async (int io_priority, const SlotAsyncReady& slot) -> void;

    auto
    close_finish (const Glib::RefPtr<AsyncResult>& result) -> bool;

    auto
    is_closed () const -> bool;

    auto
    has_pending () const -> bool;

    auto
    set_pending (bool pending = true) -> void;

    auto
    get_container () -> Glib::RefPtr<File>;

    auto
    get_container () const -> Glib::RefPtr<const File>;

    auto
    get_child (const Glib::RefPtr<FileInfo>& info) -> Glib::RefPtr<File>;

    auto
    get_child (const Glib::RefPtr<FileInfo>& info) const
        -> Glib::RefPtr<const File>;

  public:
  public:
  protected:
  };

} // namespace Gio

namespace Glib
{

  GIOMM_API
  auto
  wrap (GFileEnumerator* object, bool take_copy = false) -> Glib::RefPtr<Gio::FileEnumerator>;
} // namespace Glib

#endif
