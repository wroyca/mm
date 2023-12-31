// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GIOMM_POLLABLEINPUTSTREAM_H
#define _GIOMM_POLLABLEINPUTSTREAM_H

#include <libmm/gio/mm-gioconfig.hxx>

#include <libmm/glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm/glib/interface.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
typedef struct _GPollableInputStreamInterface GPollableInputStreamInterface;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GPollableInputStream = struct _GPollableInputStream;
using GPollableInputStreamClass = struct _GPollableInputStreamClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace gio
{
  class LIBMM_GIO_SYMEXPORT PollableInputStream_Class;
}
#endif

namespace gio
{

  class LIBMM_GIO_SYMEXPORT Cancellable;

  class LIBMM_GIO_SYMEXPORT PollableInputStream : public glib::Interface
  {
#ifndef DOXYGEN_SHOULD_SKIP_THIS

  public:
    using CppObjectType = PollableInputStream;
    using CppClassType = PollableInputStream_Class;
    using BaseObjectType = GPollableInputStream;
    using BaseClassType = GPollableInputStreamInterface;

    PollableInputStream (const PollableInputStream&) = delete;
    auto
    operator= (const PollableInputStream&) -> PollableInputStream& = delete;

  private:
    friend class PollableInputStream_Class;
    static CppClassType pollableinputstream_class_;

#endif
  protected:
    PollableInputStream ();

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    explicit PollableInputStream (const glib::Interface_Class& interface_class);

  public:
    explicit PollableInputStream (GPollableInputStream* castitem);

  protected:
#endif

  public:
    PollableInputStream (PollableInputStream&& src) noexcept;
    auto
    operator= (PollableInputStream&& src) noexcept -> PollableInputStream&;

    ~PollableInputStream () noexcept override;

    static auto
    add_interface (GType gtype_implementer) -> void;

    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS
    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GPollableInputStream*
    {
      return reinterpret_cast<GPollableInputStream*> (gobject_);
    }

    auto
    gobj () const -> const GPollableInputStream*
    {
      return reinterpret_cast<GPollableInputStream*> (gobject_);
    }

  private:
  public:
    auto
    can_poll () const -> bool;

    auto
    is_readable () const -> bool;

    auto
    read_nonblocking (void* buffer,
                      gsize count,
                      const glib::RefPtr<Cancellable>& cancellable) -> gssize;

    auto
    read_nonblocking (void* buffer, gsize count) -> gssize;

  protected:
    virtual auto
    can_poll_vfunc () const -> bool;

    virtual auto
    is_readable_vfunc () const -> bool;

    virtual auto
    read_nonblocking_vfunc (void* buffer, gsize count) -> gssize;

  public:
  public:
  protected:
  };

} // namespace gio

namespace glib
{

  LIBMM_GIO_SYMEXPORT
  auto
  wrap (GPollableInputStream* object, bool take_copy = false) -> glib::RefPtr<gio::PollableInputStream>;

} // namespace glib

#endif
