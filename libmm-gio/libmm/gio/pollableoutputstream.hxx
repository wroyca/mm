// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GIOMM_POLLABLEOUTPUTSTREAM_H
#define _GIOMM_POLLABLEOUTPUTSTREAM_H

#include <libmm/gio/mm-gioconfig.hxx>

#include <libmm/glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm/glib/interface.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
typedef struct _GPollableOutputStreamInterface GPollableOutputStreamInterface;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GPollableOutputStream = struct _GPollableOutputStream;
using GPollableOutputStreamClass = struct _GPollableOutputStreamClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace gio
{
  class LIBMM_GIO_SYMEXPORT PollableOutputStream_Class;
}
#endif

namespace gio
{

  class LIBMM_GIO_SYMEXPORT Cancellable;

  class LIBMM_GIO_SYMEXPORT PollableOutputStream : public glib::Interface
  {
#ifndef DOXYGEN_SHOULD_SKIP_THIS

  public:
    using CppObjectType = PollableOutputStream;
    using CppClassType = PollableOutputStream_Class;
    using BaseObjectType = GPollableOutputStream;
    using BaseClassType = GPollableOutputStreamInterface;

    PollableOutputStream (const PollableOutputStream&) = delete;
    auto
    operator= (const PollableOutputStream&) -> PollableOutputStream& = delete;

  private:
    friend class PollableOutputStream_Class;
    static CppClassType pollableoutputstream_class_;

#endif
  protected:
    PollableOutputStream ();

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    explicit PollableOutputStream (
        const glib::Interface_Class& interface_class);

  public:
    explicit PollableOutputStream (GPollableOutputStream* castitem);

  protected:
#endif

  public:
    PollableOutputStream (PollableOutputStream&& src) noexcept;
    auto
    operator= (PollableOutputStream&& src) noexcept -> PollableOutputStream&;

    ~PollableOutputStream () noexcept override;

    static auto
    add_interface (GType gtype_implementer) -> void;

    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS
    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GPollableOutputStream*
    {
      return reinterpret_cast<GPollableOutputStream*> (gobject_);
    }

    auto
    gobj () const -> const GPollableOutputStream*
    {
      return reinterpret_cast<GPollableOutputStream*> (gobject_);
    }

  private:
  public:
    auto
    can_poll () const -> bool;

    auto
    is_writable () const -> bool;

    auto
    write_nonblocking (const void* buffer,
                       gsize count,
                       const glib::RefPtr<Cancellable>& cancellable) -> gssize;

    auto
    write_nonblocking (const void* buffer, gsize count) -> gssize;

  protected:
    virtual auto
    can_poll_vfunc () const -> bool;

    virtual auto
    is_writable_vfunc () const -> bool;

    virtual auto
    write_nonblocking_vfunc (const void* buffer, gsize count) -> gssize;

  public:
  public:
  protected:
  };

} // namespace gio

namespace glib
{

  LIBMM_GIO_SYMEXPORT
  auto
  wrap (GPollableOutputStream* object, bool take_copy = false) -> glib::RefPtr<gio::PollableOutputStream>;

} // namespace glib

#endif
