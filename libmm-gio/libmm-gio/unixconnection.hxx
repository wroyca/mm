// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GIOMM_UNIXCONNECTION_H
#define _GIOMM_UNIXCONNECTION_H

#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm-gio/socketconnection.hxx>
#include <libmm-glib/object.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GUnixConnection = struct _GUnixConnection;
using GUnixConnectionClass = struct _GUnixConnectionClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gio
{
  class LIBMM_GIO_SYMEXPORT UnixConnection_Class;
}
#endif

namespace Gio
{

  class LIBMM_GIO_SYMEXPORT UnixConnection : public Gio::SocketConnection
  {
#ifndef DOXYGEN_SHOULD_SKIP_THIS

  public:
    using CppObjectType = UnixConnection;
    using CppClassType = UnixConnection_Class;
    using BaseObjectType = GUnixConnection;
    using BaseClassType = GUnixConnectionClass;

    UnixConnection (const UnixConnection&) = delete;
    auto
    operator= (const UnixConnection&) -> UnixConnection& = delete;

  private:
    friend class UnixConnection_Class;
    static CppClassType unixconnection_class_;

  protected:
    explicit UnixConnection (const Glib::ConstructParams& construct_params);
    explicit UnixConnection (GUnixConnection* castitem);

#endif

  public:
    UnixConnection (UnixConnection&& src) noexcept;
    auto
    operator= (UnixConnection&& src) noexcept -> UnixConnection&;

    ~UnixConnection () noexcept override;

    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GUnixConnection*
    {
      return reinterpret_cast<GUnixConnection*> (gobject_);
    }

    auto
    gobj () const -> const GUnixConnection*
    {
      return reinterpret_cast<GUnixConnection*> (gobject_);
    }

    auto
    gobj_copy () -> GUnixConnection*;

  private:
  public:
    auto
    send_fd (int fd, const Glib::RefPtr<Cancellable>& cancellable) -> bool;

    auto
    send_fd (int fd) -> bool;

    auto
    receive_fd (const Glib::RefPtr<Cancellable>& cancellable) -> int;

    auto
    receive_fd () -> int;

    auto
    receive_credentials (const Glib::RefPtr<Cancellable>& cancellable)
        -> Glib::RefPtr<Credentials>;

    auto
    receive_credentials () -> Glib::RefPtr<Credentials>;

    auto
    receive_credentials (const Glib::RefPtr<Cancellable>& cancellable) const
        -> Glib::RefPtr<const Credentials>;

    auto
    receive_credentials () const -> Glib::RefPtr<const Credentials>;

    auto
    receive_credentials_async (const SlotAsyncReady& slot,
                               const Glib::RefPtr<Cancellable>& cancellable)
        -> void;

    auto
    receive_credentials_async (const SlotAsyncReady& slot) -> void;

    auto
    receive_credentials_finish (const Glib::RefPtr<AsyncResult>& result)
        -> Glib::RefPtr<Credentials>;

    auto
    send_credentials (const Glib::RefPtr<Cancellable>& cancellable) -> bool;

    auto
    send_credentials () -> bool;

    auto
    send_credentials_async (const SlotAsyncReady& slot,
                            const Glib::RefPtr<Cancellable>& cancellable)
        -> void;

    auto
    send_credentials_async (const SlotAsyncReady& slot) -> void;

    auto
    send_credentials_finish (const Glib::RefPtr<AsyncResult>& result) -> bool;

  public:
  public:
  protected:
  };

} // namespace Gio

namespace Glib
{

  LIBMM_GIO_SYMEXPORT
  auto
  wrap (GUnixConnection* object, bool take_copy = false) -> Glib::RefPtr<Gio::UnixConnection>;
} // namespace Glib

#endif
