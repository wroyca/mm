
#ifndef _GIOMM_POLLABLEINPUTSTREAM_H
#define _GIOMM_POLLABLEINPUTSTREAM_H

#include <libmm-gio/gioconfig.hxx>

#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm-glib/interface.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
typedef struct _GPollableInputStreamInterface GPollableInputStreamInterface;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GPollableInputStream = struct _GPollableInputStream;
using GPollableInputStreamClass = struct _GPollableInputStreamClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gio
{
  class GIOMM_API PollableInputStream_Class;
}
#endif

namespace Gio
{

  class GIOMM_API Cancellable;

  class GIOMM_API PollableInputStream : public Glib::Interface
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

    explicit PollableInputStream (const Glib::Interface_Class& interface_class);

  public:
    explicit PollableInputStream (GPollableInputStream* castitem);

  protected:
#endif

  public:
    PollableInputStream (PollableInputStream&& src) noexcept;
    auto
    operator= (PollableInputStream&& src) noexcept -> PollableInputStream&;

    ~PollableInputStream () noexcept override;

    static void
    add_interface (GType gtype_implementer);

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
                      const Glib::RefPtr<Cancellable>& cancellable) -> gssize;

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

} // namespace Gio

namespace Glib
{

  GIOMM_API
  auto
  wrap (GPollableInputStream* object, bool take_copy = false) -> Glib::RefPtr<Gio::PollableInputStream>;

} // namespace Glib

#endif
