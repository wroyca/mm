// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GIOMM_UNIXINPUTSTREAM_H
#define _GIOMM_UNIXINPUTSTREAM_H

#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm-gio/filedescriptorbased.hxx>
#include <libmm-gio/inputstream.hxx>
#include <libmm-gio/pollableinputstream.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GUnixInputStream = struct _GUnixInputStream;
using GUnixInputStreamClass = struct _GUnixInputStreamClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gio
{
  class GIOMM_API UnixInputStream_Class;
}
#endif

namespace Gio
{

  class GIOMM_API UnixInputStream : public Gio::InputStream,
                                    public PollableInputStream,
                                    public FileDescriptorBased
  {
#ifndef DOXYGEN_SHOULD_SKIP_THIS

  public:
    using CppObjectType = UnixInputStream;
    using CppClassType = UnixInputStream_Class;
    using BaseObjectType = GUnixInputStream;
    using BaseClassType = GUnixInputStreamClass;

    UnixInputStream (const UnixInputStream&) = delete;
    auto
    operator= (const UnixInputStream&) -> UnixInputStream& = delete;

  private:
    friend class UnixInputStream_Class;
    static CppClassType unixinputstream_class_;

  protected:
    explicit UnixInputStream (const Glib::ConstructParams& construct_params);
    explicit UnixInputStream (GUnixInputStream* castitem);

#endif

  public:
    UnixInputStream (UnixInputStream&& src) noexcept;
    auto
    operator= (UnixInputStream&& src) noexcept -> UnixInputStream&;

    ~UnixInputStream () noexcept override;

    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GUnixInputStream*
    {
      return reinterpret_cast<GUnixInputStream*> (gobject_);
    }

    auto
    gobj () const -> const GUnixInputStream*
    {
      return reinterpret_cast<GUnixInputStream*> (gobject_);
    }

    auto
    gobj_copy () -> GUnixInputStream*;

  private:
  protected:
    explicit UnixInputStream (int fd, bool close_fd);

  public:
    static auto
    create (int fd, bool close_fd) -> Glib::RefPtr<UnixInputStream>;

    void
    set_close_fd (bool close_fd = true);

    auto
    get_close_fd () const -> bool;

    auto
    get_fd () const -> int;

    auto
    property_fd () const -> Glib::PropertyProxy_ReadOnly<int>;

    auto
    property_close_fd () -> Glib::PropertyProxy<bool>;

    auto
    property_close_fd () const -> Glib::PropertyProxy_ReadOnly<bool>;

  public:
  public:
  protected:
  };

} // namespace Gio

namespace Glib
{

  GIOMM_API
  auto
  wrap (GUnixInputStream* object, bool take_copy = false) -> Glib::RefPtr<Gio::UnixInputStream>;
} // namespace Glib

#endif
