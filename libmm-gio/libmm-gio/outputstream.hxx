// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GIOMM_OUTPUTSTREAM_H
#define _GIOMM_OUTPUTSTREAM_H

#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm-gio/asyncresult.hxx>
#include <libmm-gio/cancellable.hxx>
#include <libmm-gio/inputstream.hxx>
#include <libmm-glib/object.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GOutputStream = struct _GOutputStream;
using GOutputStreamClass = struct _GOutputStreamClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gio
{
  class GIOMM_API OutputStream_Class;
}
#endif

namespace Gio
{

  class GIOMM_API OutputStream : public Glib::Object
  {
#ifndef DOXYGEN_SHOULD_SKIP_THIS

  public:
    using CppObjectType = OutputStream;
    using CppClassType = OutputStream_Class;
    using BaseObjectType = GOutputStream;
    using BaseClassType = GOutputStreamClass;

    OutputStream (const OutputStream&) = delete;
    auto
    operator= (const OutputStream&) -> OutputStream& = delete;

  private:
    friend class OutputStream_Class;
    static CppClassType outputstream_class_;

  protected:
    explicit OutputStream (const Glib::ConstructParams& construct_params);
    explicit OutputStream (GOutputStream* castitem);

#endif

  public:
    OutputStream (OutputStream&& src) noexcept;
    auto
    operator= (OutputStream&& src) noexcept -> OutputStream&;

    ~OutputStream () noexcept override;

    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GOutputStream*
    {
      return reinterpret_cast<GOutputStream*> (gobject_);
    }

    auto
    gobj () const -> const GOutputStream*
    {
      return reinterpret_cast<GOutputStream*> (gobject_);
    }

    auto
    gobj_copy () -> GOutputStream*;

  private:
  protected:
    OutputStream ();

  public:
    enum class SpliceFlags
    {
      NONE = 0x0,
      CLOSE_SOURCE = (1 << 0),
      CLOSE_TARGET = (1 << 1)
    };

    auto
    write (const void* buffer,
           gsize count,
           const Glib::RefPtr<Cancellable>& cancellable) -> gssize;

    auto
    write (const void* buffer, gsize count) -> gssize;

    auto
    write (const std::string& buffer,
           const Glib::RefPtr<Cancellable>& cancellable) -> gssize;

    auto
    write (const std::string& buffer) -> gssize;

    auto
    write_all (const void* buffer,
               gsize count,
               gsize& bytes_written,
               const Glib::RefPtr<Cancellable>& cancellable) -> bool;

    auto
    write_all (const void* buffer, gsize count, gsize& bytes_written) -> bool;

    auto
    write_all (const std::string& buffer,
               gsize& bytes_written,
               const Glib::RefPtr<Cancellable>& cancellable) -> bool;

    auto
    write_all (const std::string& buffer, gsize& bytes_written) -> bool;

    auto
    write_bytes (const Glib::RefPtr<const Glib::Bytes>& bytes,
                 const Glib::RefPtr<Cancellable>& cancellable) -> gssize;

    auto
    write_bytes (const Glib::RefPtr<const Glib::Bytes>& bytes) -> gssize;

    auto
    write_bytes_async (const Glib::RefPtr<const Glib::Bytes>& bytes,
                       const SlotAsyncReady& slot,
                       const Glib::RefPtr<Cancellable>& cancellable,
                       int io_priority = Glib::PRIORITY_DEFAULT) -> void;

    auto
    write_bytes_async (const Glib::RefPtr<const Glib::Bytes>& bytes,
                       const SlotAsyncReady& slot,
                       int io_priority = Glib::PRIORITY_DEFAULT) -> void;

    auto
    write_bytes_finish (const Glib::RefPtr<AsyncResult>& result) -> gssize;

    auto
    splice (const Glib::RefPtr<InputStream>& source,
            const Glib::RefPtr<Cancellable>& cancellable,
            SpliceFlags flags = SpliceFlags::NONE) -> gssize;

    auto
    splice (const Glib::RefPtr<InputStream>& source,
            SpliceFlags flags = SpliceFlags::NONE) -> gssize;

    auto
    flush (const Glib::RefPtr<Cancellable>& cancellable) -> bool;

    auto
    flush () -> bool;

    auto
    close (const Glib::RefPtr<Cancellable>& cancellable) -> bool;

    auto
    close () -> bool;

    auto
    write_async (const void* buffer,
                 gsize count,
                 const SlotAsyncReady& slot,
                 const Glib::RefPtr<Cancellable>& cancellable,
                 int io_priority = Glib::PRIORITY_DEFAULT) -> void;

    auto
    write_async (const void* buffer,
                 gsize count,
                 const SlotAsyncReady& slot,
                 int io_priority = Glib::PRIORITY_DEFAULT) -> void;

    auto
    write_finish (const Glib::RefPtr<AsyncResult>& result) -> gssize;

    auto
    write_all_async (const void* buffer,
                     gsize count,
                     const SlotAsyncReady& slot,
                     const Glib::RefPtr<Cancellable>& cancellable,
                     int io_priority = Glib::PRIORITY_DEFAULT) -> void;

    auto
    write_all_async (const void* buffer,
                     gsize count,
                     const SlotAsyncReady& slot,
                     int io_priority = Glib::PRIORITY_DEFAULT) -> void;

    auto
    write_all_finish (const Glib::RefPtr<AsyncResult>& result,
                      gsize& bytes_written) -> bool;

    auto
    splice_async (const Glib::RefPtr<InputStream>& source,
                  const SlotAsyncReady& slot,
                  const Glib::RefPtr<Cancellable>& cancellable,
                  SpliceFlags flags = SpliceFlags::NONE,
                  int io_priority = Glib::PRIORITY_DEFAULT) -> void;

    auto
    splice_async (const Glib::RefPtr<InputStream>& source,
                  const SlotAsyncReady& slot,
                  SpliceFlags flags = SpliceFlags::NONE,
                  int io_priority = Glib::PRIORITY_DEFAULT) -> void;

    auto
    splice_finish (const Glib::RefPtr<AsyncResult>& result) -> gssize;

    auto
    flush_async (const SlotAsyncReady& slot,
                 const Glib::RefPtr<Cancellable>& cancellable,
                 int io_priority = Glib::PRIORITY_DEFAULT) -> void;

    auto
    flush_async (const SlotAsyncReady& slot,
                 int io_priority = Glib::PRIORITY_DEFAULT) -> void;

    auto
    flush_finish (const Glib::RefPtr<AsyncResult>& result) -> bool;

    auto
    close_async (const SlotAsyncReady& slot,
                 const Glib::RefPtr<Cancellable>& cancellable,
                 int io_priority = Glib::PRIORITY_DEFAULT) -> void;

    auto
    close_async (const SlotAsyncReady& slot,
                 int io_priority = Glib::PRIORITY_DEFAULT) -> void;

    auto
    close_finish (const Glib::RefPtr<AsyncResult>& result) -> bool;

    auto
    is_closed () const -> bool;

    auto
    is_closing () const -> bool;

    auto
    has_pending () const -> bool;

  protected:
    auto
    set_pending () -> bool;

    auto
    clear_pending () -> void;

    virtual auto
    write_vfunc (const void* buffer,
                 gsize count,
                 const Glib::RefPtr<Cancellable>& cancellable) -> gssize;

    virtual auto
    splice_vfunc (const Glib::RefPtr<InputStream>& source,
                  const Glib::RefPtr<Cancellable>& cancellable,
                  SpliceFlags flags) -> gssize;

    virtual auto
    flush_vfunc (const Glib::RefPtr<Cancellable>& cancellable) -> bool;

    virtual auto
    close_vfunc (const Glib::RefPtr<Cancellable>& cancellable) -> bool;

  public:
  public:
  protected:
  };

} // namespace Gio

namespace Gio
{

  inline auto
  operator| (OutputStream::SpliceFlags lhs, OutputStream::SpliceFlags rhs) -> OutputStream::SpliceFlags
  {
    return static_cast<OutputStream::SpliceFlags> (static_cast<unsigned> (lhs) |
                                                   static_cast<unsigned> (rhs));
  }

  inline auto
  operator& (OutputStream::SpliceFlags lhs, OutputStream::SpliceFlags rhs) -> OutputStream::SpliceFlags
  {
    return static_cast<OutputStream::SpliceFlags> (static_cast<unsigned> (lhs) &
                                                   static_cast<unsigned> (rhs));
  }

  inline auto
  operator^ (OutputStream::SpliceFlags lhs, OutputStream::SpliceFlags rhs) -> OutputStream::SpliceFlags
  {
    return static_cast<OutputStream::SpliceFlags> (static_cast<unsigned> (lhs) ^
                                                   static_cast<unsigned> (rhs));
  }

  inline auto
  operator~(OutputStream::SpliceFlags flags) -> OutputStream::SpliceFlags
  {
    return static_cast<OutputStream::SpliceFlags> (
        ~static_cast<unsigned> (flags));
  }

  inline auto
  operator|= (OutputStream::SpliceFlags& lhs, OutputStream::SpliceFlags rhs) -> OutputStream::SpliceFlags&
  {
    return (lhs = static_cast<OutputStream::SpliceFlags> (
                static_cast<unsigned> (lhs) | static_cast<unsigned> (rhs)));
  }

  inline auto
  operator&= (OutputStream::SpliceFlags& lhs, OutputStream::SpliceFlags rhs) -> OutputStream::SpliceFlags&
  {
    return (lhs = static_cast<OutputStream::SpliceFlags> (
                static_cast<unsigned> (lhs) & static_cast<unsigned> (rhs)));
  }

  inline auto
  operator^= (OutputStream::SpliceFlags& lhs, OutputStream::SpliceFlags rhs) -> OutputStream::SpliceFlags&
  {
    return (lhs = static_cast<OutputStream::SpliceFlags> (
                static_cast<unsigned> (lhs) ^ static_cast<unsigned> (rhs)));
  }
} // namespace Gio

namespace Glib
{

  GIOMM_API
  auto
  wrap (GOutputStream* object, bool take_copy = false) -> Glib::RefPtr<Gio::OutputStream>;
} // namespace Glib

#endif
