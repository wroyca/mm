// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GIOMM_IOSTREAM_H
#define _GIOMM_IOSTREAM_H

#include <libmm/glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm/glib/object.hxx>

#include <libmm/gio/asyncresult.hxx>
#include <libmm/gio/cancellable.hxx>
#include <libmm/gio/inputstream.hxx>
#include <libmm/gio/outputstream.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GIOStream = struct _GIOStream;
using GIOStreamClass = struct _GIOStreamClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace gio
{
  class LIBMM_GIO_SYMEXPORT IOStream_Class;
}
#endif

namespace gio
{

  class LIBMM_GIO_SYMEXPORT IOStream : public glib::Object
  {
#ifndef DOXYGEN_SHOULD_SKIP_THIS

  public:
    using CppObjectType = IOStream;
    using CppClassType = IOStream_Class;
    using BaseObjectType = GIOStream;
    using BaseClassType = GIOStreamClass;

    IOStream (const IOStream&) = delete;
    auto
    operator= (const IOStream&) -> IOStream& = delete;

  private:
    friend class IOStream_Class;
    static CppClassType iostream_class_;

  protected:
    explicit IOStream (const glib::ConstructParams& construct_params);
    explicit IOStream (GIOStream* castitem);

#endif

  public:
    IOStream (IOStream&& src) noexcept;
    auto
    operator= (IOStream&& src) noexcept -> IOStream&;

    ~IOStream () noexcept override;

    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GIOStream*
    {
      return reinterpret_cast<GIOStream*> (gobject_);
    }

    auto
    gobj () const -> const GIOStream*
    {
      return reinterpret_cast<GIOStream*> (gobject_);
    }

    auto
    gobj_copy () -> GIOStream*;

  private:
  public:
    enum class SpliceFlags
    {
      NONE = 0x0,
      CLOSE_STREAM1 = (1 << 0),
      CLOSE_STREAM2 = (1 << 1),
      WAIT_FOR_BOTH = (1 << 2)
    };

    auto
    splice_async (const glib::RefPtr<IOStream>& stream2,
                  const SlotAsyncReady& slot,
                  const glib::RefPtr<Cancellable>& cancellable,
                  SpliceFlags flags = SpliceFlags::NONE,
                  int io_priority = glib::PRIORITY_DEFAULT) -> void;

    auto
    splice_async (const glib::RefPtr<IOStream>& stream2,
                  const SlotAsyncReady& slot,
                  SpliceFlags flags = SpliceFlags::NONE,
                  int io_priority = glib::PRIORITY_DEFAULT) -> void;

    static auto
    splice_finish (const glib::RefPtr<AsyncResult>& result) -> bool;

    auto
    get_input_stream () -> glib::RefPtr<InputStream>;

    auto
    get_output_stream () -> glib::RefPtr<OutputStream>;

    auto
    close (const glib::RefPtr<Cancellable>& cancellable) -> bool;

    auto
    close () -> bool;

    auto
    close_async (const SlotAsyncReady& slot,
                 const glib::RefPtr<Cancellable>& cancellable,
                 int io_priority = glib::PRIORITY_DEFAULT) -> void;
    auto
    close_async (const SlotAsyncReady& slot,
                 int io_priority = glib::PRIORITY_DEFAULT) -> void;

    auto
    close_finish (const glib::RefPtr<AsyncResult>& result) -> bool;

    auto
    is_closed () const -> bool;

    auto
    has_pending () const -> bool;

    auto
    set_pending () -> bool;

    auto
    clear_pending () -> void;

  public:
  public:
  protected:
  };

} // namespace gio

namespace gio
{

  inline auto
  operator| (IOStream::SpliceFlags lhs, IOStream::SpliceFlags rhs) -> IOStream::SpliceFlags
  {
    return static_cast<IOStream::SpliceFlags> (static_cast<unsigned> (lhs) |
                                               static_cast<unsigned> (rhs));
  }

  inline auto
  operator& (IOStream::SpliceFlags lhs, IOStream::SpliceFlags rhs) -> IOStream::SpliceFlags
  {
    return static_cast<IOStream::SpliceFlags> (static_cast<unsigned> (lhs) &
                                               static_cast<unsigned> (rhs));
  }

  inline auto
  operator^ (IOStream::SpliceFlags lhs, IOStream::SpliceFlags rhs) -> IOStream::SpliceFlags
  {
    return static_cast<IOStream::SpliceFlags> (static_cast<unsigned> (lhs) ^
                                               static_cast<unsigned> (rhs));
  }

  inline auto
  operator~(IOStream::SpliceFlags flags) -> IOStream::SpliceFlags
  {
    return static_cast<IOStream::SpliceFlags> (~static_cast<unsigned> (flags));
  }

  inline auto
  operator|= (IOStream::SpliceFlags& lhs, IOStream::SpliceFlags rhs) -> IOStream::SpliceFlags&
  {
    return (lhs = static_cast<IOStream::SpliceFlags> (
                static_cast<unsigned> (lhs) | static_cast<unsigned> (rhs)));
  }

  inline auto
  operator&= (IOStream::SpliceFlags& lhs, IOStream::SpliceFlags rhs) -> IOStream::SpliceFlags&
  {
    return (lhs = static_cast<IOStream::SpliceFlags> (
                static_cast<unsigned> (lhs) & static_cast<unsigned> (rhs)));
  }

  inline auto
  operator^= (IOStream::SpliceFlags& lhs, IOStream::SpliceFlags rhs) -> IOStream::SpliceFlags&
  {
    return (lhs = static_cast<IOStream::SpliceFlags> (
                static_cast<unsigned> (lhs) ^ static_cast<unsigned> (rhs)));
  }
} // namespace gio

namespace glib
{

  LIBMM_GIO_SYMEXPORT
  auto
  wrap (GIOStream* object, bool take_copy = false) -> glib::RefPtr<gio::IOStream>;
} // namespace glib

#endif
