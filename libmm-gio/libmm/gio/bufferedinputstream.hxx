// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GIOMM_BUFFEREDINPUTSTREAM_H
#define _GIOMM_BUFFEREDINPUTSTREAM_H

#include <libmm/glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm/gio/filterinputstream.hxx>
#include <libmm/gio/seekable.hxx>
#include <libmm/glib/object.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GBufferedInputStream = struct _GBufferedInputStream;
using GBufferedInputStreamClass = struct _GBufferedInputStreamClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gio
{
  class LIBMM_GIO_SYMEXPORT BufferedInputStream_Class;
}
#endif

namespace Gio
{

  class LIBMM_GIO_SYMEXPORT BufferedInputStream : public Gio::FilterInputStream,
                                        public Gio::Seekable
  {
#ifndef DOXYGEN_SHOULD_SKIP_THIS

  public:
    using CppObjectType = BufferedInputStream;
    using CppClassType = BufferedInputStream_Class;
    using BaseObjectType = GBufferedInputStream;
    using BaseClassType = GBufferedInputStreamClass;

    BufferedInputStream (const BufferedInputStream&) = delete;
    auto
    operator= (const BufferedInputStream&) -> BufferedInputStream& = delete;

  private:
    friend class BufferedInputStream_Class;
    static CppClassType bufferedinputstream_class_;

  protected:
    explicit BufferedInputStream (
        const Glib::ConstructParams& construct_params);
    explicit BufferedInputStream (GBufferedInputStream* castitem);

#endif

  public:
    BufferedInputStream (BufferedInputStream&& src) noexcept;
    auto
    operator= (BufferedInputStream&& src) noexcept -> BufferedInputStream&;

    ~BufferedInputStream () noexcept override;

    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GBufferedInputStream*
    {
      return reinterpret_cast<GBufferedInputStream*> (gobject_);
    }

    auto
    gobj () const -> const GBufferedInputStream*
    {
      return reinterpret_cast<GBufferedInputStream*> (gobject_);
    }

    auto
    gobj_copy () -> GBufferedInputStream*;

  private:
  protected:
    explicit BufferedInputStream (const Glib::RefPtr<InputStream>& base_stream);

    explicit BufferedInputStream (const Glib::RefPtr<InputStream>& base_stream,
                                  gsize buffer_size);

  public:
    static auto
    create (const Glib::RefPtr<InputStream>& base_stream)
        -> Glib::RefPtr<BufferedInputStream>;

    static auto
    create_sized (const Glib::RefPtr<InputStream>& base_stream,
                  gsize buffer_size) -> Glib::RefPtr<BufferedInputStream>;

    auto
    get_buffer_size () const -> gsize;

    auto
    set_buffer_size (gsize size) -> void;

    auto
    get_available () const -> gsize;

    auto
    peek (void* buffer, gsize offset, gsize count) const -> gsize;

    auto
    peek_buffer (gsize& count) const -> const void*;

    auto
    fill (gssize count, const Glib::RefPtr<Cancellable>& cancellable) -> gssize;

    auto
    fill (gssize count) -> gssize;

    auto
    fill_async (const SlotAsyncReady& slot,
                gssize count,
                const Glib::RefPtr<Cancellable>& cancellable,
                int io_priority = Glib::PRIORITY_DEFAULT) -> void;

    auto
    fill_async (const SlotAsyncReady& slot,
                gssize count,
                int io_priority = Glib::PRIORITY_DEFAULT) -> void;

    auto
    fill_finish (const Glib::RefPtr<AsyncResult>& result) -> gssize;

    auto
    read_byte (const Glib::RefPtr<Cancellable>& cancellable) -> int;

    auto
    read_byte () -> int;

    auto
    property_buffer_size () -> Glib::PropertyProxy<guint>;

    auto
    property_buffer_size () const -> Glib::PropertyProxy_ReadOnly<guint>;

  protected:
    virtual auto
    fill_vfunc (gssize count, const Glib::RefPtr<Cancellable>& cancellable)
        -> gssize;

  public:
  public:
  protected:
  };

} // namespace Gio

namespace Glib
{

  LIBMM_GIO_SYMEXPORT
  auto
  wrap (GBufferedInputStream* object, bool take_copy = false) -> Glib::RefPtr<Gio::BufferedInputStream>;
} // namespace Glib

#endif
