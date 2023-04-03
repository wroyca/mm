// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GIOMM_UNIXOUTPUTSTREAM_H
#define _GIOMM_UNIXOUTPUTSTREAM_H

#include <libmm/glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm/gio/filedescriptorbased.hxx>
#include <libmm/gio/outputstream.hxx>
#include <libmm/gio/pollableoutputstream.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GUnixOutputStream = struct _GUnixOutputStream;
using GUnixOutputStreamClass = struct _GUnixOutputStreamClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gio
{
  class LIBMM_GIO_SYMEXPORT UnixOutputStream_Class;
}
#endif

namespace Gio
{

  class LIBMM_GIO_SYMEXPORT UnixOutputStream : public Gio::OutputStream,
                                     public PollableOutputStream,
                                     public FileDescriptorBased
  {
#ifndef DOXYGEN_SHOULD_SKIP_THIS

  public:
    using CppObjectType = UnixOutputStream;
    using CppClassType = UnixOutputStream_Class;
    using BaseObjectType = GUnixOutputStream;
    using BaseClassType = GUnixOutputStreamClass;

    UnixOutputStream (const UnixOutputStream&) = delete;
    auto
    operator= (const UnixOutputStream&) -> UnixOutputStream& = delete;

  private:
    friend class UnixOutputStream_Class;
    static CppClassType unixoutputstream_class_;

  protected:
    explicit UnixOutputStream (const Glib::ConstructParams& construct_params);
    explicit UnixOutputStream (GUnixOutputStream* castitem);

#endif

  public:
    UnixOutputStream (UnixOutputStream&& src) noexcept;
    auto
    operator= (UnixOutputStream&& src) noexcept -> UnixOutputStream&;

    ~UnixOutputStream () noexcept override;

    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GUnixOutputStream*
    {
      return reinterpret_cast<GUnixOutputStream*> (gobject_);
    }

    auto
    gobj () const -> const GUnixOutputStream*
    {
      return reinterpret_cast<GUnixOutputStream*> (gobject_);
    }

    auto
    gobj_copy () -> GUnixOutputStream*;

  private:
  protected:
    explicit UnixOutputStream (int fd, bool close_fd);

  public:
    static auto
    create (int fd, bool close_fd) -> Glib::RefPtr<UnixOutputStream>;

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

  LIBMM_GIO_SYMEXPORT
  auto
  wrap (GUnixOutputStream* object, bool take_copy = false) -> Glib::RefPtr<Gio::UnixOutputStream>;
} // namespace Glib

#endif
