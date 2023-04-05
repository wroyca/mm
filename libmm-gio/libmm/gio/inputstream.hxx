// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GIOMM_INPUTSTREAM_H
#define _GIOMM_INPUTSTREAM_H

#include <libmm/glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm/glib/bytes.hxx>
#include <libmm/glib/object.hxx>
#include <libmm/glib/priorities.hxx>

#include <libmm/gio/asyncresult.hxx>
#include <libmm/gio/cancellable.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GInputStream = struct _GInputStream;
using GInputStreamClass = struct _GInputStreamClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace gio
{
  class LIBMM_GIO_SYMEXPORT InputStream_Class;
}
#endif

namespace gio
{

  class LIBMM_GIO_SYMEXPORT InputStream : public glib::Object
  {
#ifndef DOXYGEN_SHOULD_SKIP_THIS

  public:
    using CppObjectType = InputStream;
    using CppClassType = InputStream_Class;
    using BaseObjectType = GInputStream;
    using BaseClassType = GInputStreamClass;

    InputStream (const InputStream&) = delete;
    auto
    operator= (const InputStream&) -> InputStream& = delete;

  private:
    friend class InputStream_Class;
    static CppClassType inputstream_class_;

  protected:
    explicit InputStream (const glib::ConstructParams& construct_params);
    explicit InputStream (GInputStream* castitem);

#endif

  public:
    InputStream (InputStream&& src) noexcept;
    auto
    operator= (InputStream&& src) noexcept -> InputStream&;

    ~InputStream () noexcept override;

    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GInputStream*
    {
      return reinterpret_cast<GInputStream*> (gobject_);
    }

    auto
    gobj () const -> const GInputStream*
    {
      return reinterpret_cast<GInputStream*> (gobject_);
    }

    auto
    gobj_copy () -> GInputStream*;

  private:
  protected:
    InputStream ();

  public:
    auto
    read (void* buffer,
          gsize count,
          const glib::RefPtr<Cancellable>& cancellable) -> gssize;

    auto
    read (void* buffer, gsize count) -> gssize;

    auto
    read_all (void* buffer,
              gsize count,
              gsize& bytes_read,
              const glib::RefPtr<Cancellable>& cancellable) -> bool;

    auto
    read_all (void* buffer, gsize count, gsize& bytes_read) -> bool;

    auto
    read_bytes (gsize count, const glib::RefPtr<Cancellable>& cancellable)
        -> glib::RefPtr<glib::Bytes>;

    auto
    read_bytes_async (gsize count,
                      const SlotAsyncReady& slot,
                      const glib::RefPtr<Cancellable>& cancellable,
                      int io_priority = glib::PRIORITY_DEFAULT) -> void;

    auto
    read_bytes_async (gsize count,
                      const SlotAsyncReady& slot,
                      int io_priority = glib::PRIORITY_DEFAULT) -> void;

    auto
    read_bytes_finish (const glib::RefPtr<AsyncResult>& result)
        -> glib::RefPtr<glib::Bytes>;

    auto
    skip (gsize count, const glib::RefPtr<Cancellable>& cancellable) -> gssize;

    auto
    skip (gsize count) -> gssize;

    auto
    close (const glib::RefPtr<Cancellable>& cancellable) -> bool;

    auto
    close () -> bool;

    auto
    read_async (void* buffer,
                gsize count,
                const SlotAsyncReady& slot,
                const glib::RefPtr<Cancellable>& cancellable,
                int io_priority = glib::PRIORITY_DEFAULT) -> void;

    auto
    read_async (void* buffer,
                gsize count,
                const SlotAsyncReady& slot,
                int io_priority = glib::PRIORITY_DEFAULT) -> void;

    auto
    read_finish (const glib::RefPtr<AsyncResult>& result) -> gssize;

    auto
    read_all_async (void* buffer,
                    gsize count,
                    const SlotAsyncReady& slot,
                    const glib::RefPtr<Cancellable>& cancellable,
                    int io_priority = glib::PRIORITY_DEFAULT) -> void;

    auto
    read_all_async (void* buffer,
                    gsize count,
                    const SlotAsyncReady& slot,
                    int io_priority = glib::PRIORITY_DEFAULT) -> void;

    auto
    read_all_finish (const glib::RefPtr<AsyncResult>& result, gsize& bytes_read)
        -> bool;

    auto
    skip_async (gsize count,
                const SlotAsyncReady& slot,
                const glib::RefPtr<Cancellable>& cancellable,
                int io_priority = glib::PRIORITY_DEFAULT) -> void;

    auto
    skip_async (gsize count,
                const SlotAsyncReady& slot,
                int io_priority = glib::PRIORITY_DEFAULT) -> void;

    auto
    skip_finish (const glib::RefPtr<AsyncResult>& result) -> gssize;

    auto
    close_async (const SlotAsyncReady& slot,
                 const glib::RefPtr<Cancellable>& cancellable,
                 int io_priority = glib::PRIORITY_DEFAULT) -> void;

    auto
    close_async (const SlotAsyncReady& slot,
                 int io_priority = glib::PRIORITY_DEFAULT) -> void;

    auto
    close_finish (const glib::RefPtr<AsyncResult>& result) -> gboolean;

    auto
    is_closed () const -> bool;

    auto
    has_pending () const -> bool;

  protected:
    auto
    set_pending () -> bool;

    auto
    clear_pending () -> void;

    virtual auto
    read_vfunc (void* buffer,
                gsize count,
                const glib::RefPtr<Cancellable>& cancellable) -> gssize;

    virtual auto
    skip_vfunc (gsize count, const glib::RefPtr<Cancellable>& cancellable)
        -> gssize;

    virtual auto
    close_vfunc (const glib::RefPtr<Cancellable>& cancellable) -> bool;

  public:
  public:
  protected:
  };

} // namespace gio

namespace glib
{

  LIBMM_GIO_SYMEXPORT
  auto
  wrap (GInputStream* object, bool take_copy = false) -> glib::RefPtr<gio::InputStream>;
} // namespace glib

#endif
