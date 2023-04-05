// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GIOMM_UNIXCONNECTION_H
#define _GIOMM_UNIXCONNECTION_H

#include <libmm/glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm/gio/socketconnection.hxx>
#include <libmm/glib/object.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GUnixConnection = struct _GUnixConnection;
using GUnixConnectionClass = struct _GUnixConnectionClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace gio
{
  class LIBMM_GIO_SYMEXPORT UnixConnection_Class;
}
#endif

namespace gio
{

  class LIBMM_GIO_SYMEXPORT UnixConnection : public gio::SocketConnection
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
    explicit UnixConnection (const glib::ConstructParams& construct_params);
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
    send_fd (int fd, const glib::RefPtr<Cancellable>& cancellable) -> bool;

    auto
    send_fd (int fd) -> bool;

    auto
    receive_fd (const glib::RefPtr<Cancellable>& cancellable) -> int;

    auto
    receive_fd () -> int;

    auto
    receive_credentials (const glib::RefPtr<Cancellable>& cancellable)
        -> glib::RefPtr<Credentials>;

    auto
    receive_credentials () -> glib::RefPtr<Credentials>;

    auto
    receive_credentials (const glib::RefPtr<Cancellable>& cancellable) const
        -> glib::RefPtr<const Credentials>;

    auto
    receive_credentials () const -> glib::RefPtr<const Credentials>;

    auto
    receive_credentials_async (const SlotAsyncReady& slot,
                               const glib::RefPtr<Cancellable>& cancellable)
        -> void;

    auto
    receive_credentials_async (const SlotAsyncReady& slot) -> void;

    auto
    receive_credentials_finish (const glib::RefPtr<AsyncResult>& result)
        -> glib::RefPtr<Credentials>;

    auto
    send_credentials (const glib::RefPtr<Cancellable>& cancellable) -> bool;

    auto
    send_credentials () -> bool;

    auto
    send_credentials_async (const SlotAsyncReady& slot,
                            const glib::RefPtr<Cancellable>& cancellable)
        -> void;

    auto
    send_credentials_async (const SlotAsyncReady& slot) -> void;

    auto
    send_credentials_finish (const glib::RefPtr<AsyncResult>& result) -> bool;

  public:
  public:
  protected:
  };

} // namespace gio

namespace glib
{

  LIBMM_GIO_SYMEXPORT
  auto
  wrap (GUnixConnection* object, bool take_copy = false) -> glib::RefPtr<gio::UnixConnection>;
} // namespace glib

#endif
