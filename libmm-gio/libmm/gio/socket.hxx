// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GIOMM_SOCKET_H
#define _GIOMM_SOCKET_H

#include <libmm/glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm/gio/credentials.hxx>
#include <libmm/gio/enums.hxx>
#include <libmm/gio/inetaddress.hxx>
#include <libmm/gio/initable.hxx>
#include <libmm/gio/socketaddress.hxx>
#include <libmm/gio/socketconnectable.hxx>
#include <libmm/glib/iochannel.hxx>
#include <libmm/glib/object.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GSocket = struct _GSocket;
using GSocketClass = struct _GSocketClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gio
{
  class LIBMM_GIO_SYMEXPORT Socket_Class;
}
#endif

namespace Gio
{
  class SocketSource;

  class LIBMM_GIO_SYMEXPORT Socket : public Glib::Object,
                           public Initable
  {
#ifndef DOXYGEN_SHOULD_SKIP_THIS

  public:
    using CppObjectType = Socket;
    using CppClassType = Socket_Class;
    using BaseObjectType = GSocket;
    using BaseClassType = GSocketClass;

    Socket (const Socket&) = delete;
    auto
    operator= (const Socket&) -> Socket& = delete;

  private:
    friend class Socket_Class;
    static CppClassType socket_class_;

  protected:
    explicit Socket (const Glib::ConstructParams& construct_params);
    explicit Socket (GSocket* castitem);

#endif

  public:
    Socket (Socket&& src) noexcept;
    auto
    operator= (Socket&& src) noexcept -> Socket&;

    ~Socket () noexcept override;

    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GSocket*
    {
      return reinterpret_cast<GSocket*> (gobject_);
    }

    auto
    gobj () const -> const GSocket*
    {
      return reinterpret_cast<GSocket*> (gobject_);
    }

    auto
    gobj_copy () -> GSocket*;

  private:
  public:
    enum class Type
    {
      INVALID,
      STREAM,
      DATAGRAM,
      SEQPACKET
    };

    enum class Protocol
    {
      UNKNOWN = -1,
      DEFAULT = 0,
      TCP = 6,
      UDP = 17,
      SCTP = 132
    };

    enum class MsgFlags
    {
      NONE = 0x0,
      OOB = GLIB_SYSDEF_MSG_OOB,
      PEEK = GLIB_SYSDEF_MSG_PEEK,
      DONTROUTE = GLIB_SYSDEF_MSG_DONTROUTE
    };

  protected:
    Socket (SocketFamily family,
            Type type,
            Protocol protocol,
            const Glib::RefPtr<Cancellable>& cancellable);

    Socket (int fd, const Glib::RefPtr<Cancellable>& cancellable);

  public:
    static auto
    create (SocketFamily family,
            Type type,
            Protocol protocol,
            const Glib::RefPtr<Cancellable>& cancellable = {})
        -> Glib::RefPtr<Socket>;

    static auto
    create_from_fd (int fd, const Glib::RefPtr<Cancellable>& cancellable = {})
        -> Glib::RefPtr<Socket>;

    auto
    bind (const Glib::RefPtr<SocketAddress>& address, bool allow_reuse) -> void;

    auto
    listen () -> void;

    auto
    accept (const Glib::RefPtr<Cancellable>& cancellable)
        -> Glib::RefPtr<Socket>;

    auto
    accept () -> Glib::RefPtr<Socket>;

    auto
    connect (const Glib::RefPtr<SocketAddress>& address,
             const Glib::RefPtr<Cancellable>& cancellable) -> void;

    auto
    connect (const Glib::RefPtr<SocketAddress>& address) -> void;

    auto
    check_connect_result () -> void;

    auto
    receive (char* buffer,
             gsize size,
             const Glib::RefPtr<Cancellable>& cancellable) -> gssize;

    auto
    receive (char* buffer, gsize size) -> gssize;

    auto
    receive_from (Glib::RefPtr<SocketAddress>& address,
                  char* buffer,
                  gsize size,
                  const Glib::RefPtr<Cancellable>& cancellable) -> gssize;
    auto
    receive_from (Glib::RefPtr<SocketAddress>& address,
                  char* buffer,
                  gsize size) -> gssize;

    auto
    send (const gchar* buffer,
          gsize size,
          const Glib::RefPtr<Cancellable>& cancellable) -> gssize;

    auto
    send (const gchar* buffer, gsize size) -> gssize;

    auto
    send_to (const Glib::RefPtr<SocketAddress>& address,
             const char* buffer,
             gsize size,
             const Glib::RefPtr<Cancellable>& cancellable) -> gssize;

    auto
    send_to (const Glib::RefPtr<SocketAddress>& address,
             const char* buffer,
             gsize size) -> gssize;

    auto
    close () -> void;

    auto
    is_closed () -> bool;

    auto
    create_source (Glib::IOCondition condition,
                   const Glib::RefPtr<Cancellable>& cancellable = {})
        -> Glib::RefPtr<SocketSource>;

    auto
    shutdown (bool shutdown_read, bool shutdown_write) -> void;

    auto
    is_connected () -> bool;

    auto
    get_available_bytes () const -> gssize;

    auto
    condition_check (Glib::IOCondition condition) -> Glib::IOCondition;

    auto
    condition_wait (Glib::IOCondition condition,
                    const Glib::RefPtr<Cancellable>& cancellable) -> void;

    auto
    condition_wait (Glib::IOCondition condition) -> void;

    auto
    condition_timed_wait (Glib::IOCondition condition,
                          gint64 timeout,
                          const Glib::RefPtr<Cancellable>& cancellable) -> void;

    auto
    condition_timed_wait (Glib::IOCondition condition, gint64 timeout) -> void;

    auto
    set_listen_backlog (int backlog) -> void;

    auto
    get_listen_backlog () const -> int;

    auto
    set_blocking (bool blocking) -> void;

    auto
    get_blocking () const -> bool;

    auto
    set_keepalive (bool keepalive) -> void;

    auto
    get_keepalive () const -> bool;

    auto
    get_family () const -> SocketFamily;

    auto
    get_fd () const -> int;

    auto
    get_local_address () const -> Glib::RefPtr<SocketAddress>;

    auto
    get_remote_address () const -> Glib::RefPtr<SocketAddress>;

    auto
    get_protocol () const -> Protocol;

    auto
    get_socket_type () const -> Type;

    auto
    speaks_ipv4 () const -> bool;

    auto
    get_credentials () -> Glib::RefPtr<Credentials>;

    auto
    get_credentials () const -> Glib::RefPtr<const Credentials>;

    auto
    get_timeout () const -> guint;

    auto
    set_timeout (guint timeout) -> void;

    auto
    receive_with_blocking (gchar* buffer,
                           gsize size,
                           bool blocking,
                           const Glib::RefPtr<Cancellable>& cancellable = {})
        -> gssize;

    auto
    send_with_blocking (gchar* buffer,
                        gsize size,
                        bool blocking,
                        const Glib::RefPtr<Cancellable>& cancellable = {})
        -> gssize;

    auto
    get_option (int level, int optname, int& value) const -> bool;

    auto
    set_option (int level, int optname, int value) -> bool;

    auto
    get_ttl () const -> guint;

    auto
    set_ttl (guint ttl) -> void;

    auto
    get_broadcast () const -> bool;

    auto
    set_broadcast (bool broadcast) -> void;

    auto
    get_multicast_loopback () const -> bool;

    auto
    set_multicast_loopback (bool loopback) -> void;

    auto
    get_multicast_ttl () const -> guint;

    auto
    set_multicast_ttl (guint ttl) -> void;

    auto
    join_multicast_group (const Glib::RefPtr<InetAddress>& group,
                          bool source_specific,
                          const std::string& iface) -> bool;

    auto
    join_multicast_group (const Glib::RefPtr<InetAddress>& group,
                          bool source_specific) -> bool;

    auto
    leave_multicast_group (const Glib::RefPtr<InetAddress>& group,
                           bool source_specific,
                           const std::string& iface) -> bool;

    auto
    leave_multicast_group (const Glib::RefPtr<InetAddress>& group,
                           bool source_specific) -> bool;

    auto
    property_blocking () -> Glib::PropertyProxy<bool>;

    auto
    property_blocking () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_family () const -> Glib::PropertyProxy_ReadOnly<SocketFamily>;

    auto
    property_fd () const -> Glib::PropertyProxy_ReadOnly<int>;

    auto
    property_keepalive () -> Glib::PropertyProxy<bool>;

    auto
    property_keepalive () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_listen_backlog () -> Glib::PropertyProxy<int>;

    auto
    property_listen_backlog () const -> Glib::PropertyProxy_ReadOnly<int>;

    auto
    property_local_address () const
        -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<SocketAddress>>;

    auto
    property_remote_address () const
        -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<SocketAddress>>;

    auto
    property_timeout () -> Glib::PropertyProxy<guint>;

    auto
    property_timeout () const -> Glib::PropertyProxy_ReadOnly<guint>;

    auto
    property_protocol () const -> Glib::PropertyProxy_ReadOnly<Protocol>;

    auto
    property_broadcast () -> Glib::PropertyProxy<bool>;

    auto
    property_broadcast () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_type () const -> Glib::PropertyProxy_ReadOnly<Type>;

    auto
    property_ttl () -> Glib::PropertyProxy<guint>;

    auto
    property_ttl () const -> Glib::PropertyProxy_ReadOnly<guint>;

    auto
    property_multicast_loopback () -> Glib::PropertyProxy<bool>;

    auto
    property_multicast_loopback () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_multicast_ttl () -> Glib::PropertyProxy<guint>;

    auto
    property_multicast_ttl () const -> Glib::PropertyProxy_ReadOnly<guint>;

  public:
  public:
  protected:
  };

} // namespace Gio

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

  template <>
  class LIBMM_GIO_SYMEXPORT Value<Gio::Socket::Type>
    : public Glib::Value_Enum<Gio::Socket::Type>
  {
  public:
    static auto
    value_type () -> GType G_GNUC_CONST;
  };

} // namespace Glib
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

  template <>
  class LIBMM_GIO_SYMEXPORT Value<Gio::Socket::Protocol>
    : public Glib::Value_Enum<Gio::Socket::Protocol>
  {
  public:
    static auto
    value_type () -> GType G_GNUC_CONST;
  };

} // namespace Glib
#endif

namespace Gio
{

  inline auto
  operator| (Socket::MsgFlags lhs, Socket::MsgFlags rhs) -> Socket::MsgFlags
  {
    return static_cast<Socket::MsgFlags> (static_cast<unsigned> (lhs) |
                                          static_cast<unsigned> (rhs));
  }

  inline auto
  operator& (Socket::MsgFlags lhs, Socket::MsgFlags rhs) -> Socket::MsgFlags
  {
    return static_cast<Socket::MsgFlags> (static_cast<unsigned> (lhs) &
                                          static_cast<unsigned> (rhs));
  }

  inline auto
  operator^ (Socket::MsgFlags lhs, Socket::MsgFlags rhs) -> Socket::MsgFlags
  {
    return static_cast<Socket::MsgFlags> (static_cast<unsigned> (lhs) ^
                                          static_cast<unsigned> (rhs));
  }

  inline auto
  operator~(Socket::MsgFlags flags) -> Socket::MsgFlags
  {
    return static_cast<Socket::MsgFlags> (~static_cast<unsigned> (flags));
  }

  inline auto
  operator|= (Socket::MsgFlags& lhs, Socket::MsgFlags rhs) -> Socket::MsgFlags&
  {
    return (lhs = static_cast<Socket::MsgFlags> (static_cast<unsigned> (lhs) |
                                                 static_cast<unsigned> (rhs)));
  }

  inline auto
  operator&= (Socket::MsgFlags& lhs, Socket::MsgFlags rhs) -> Socket::MsgFlags&
  {
    return (lhs = static_cast<Socket::MsgFlags> (static_cast<unsigned> (lhs) &
                                                 static_cast<unsigned> (rhs)));
  }

  inline auto
  operator^= (Socket::MsgFlags& lhs, Socket::MsgFlags rhs) -> Socket::MsgFlags&
  {
    return (lhs = static_cast<Socket::MsgFlags> (static_cast<unsigned> (lhs) ^
                                                 static_cast<unsigned> (rhs)));
  }
} // namespace Gio

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

  template <>
  class LIBMM_GIO_SYMEXPORT Value<Gio::Socket::MsgFlags>
    : public Glib::Value_Flags<Gio::Socket::MsgFlags>
  {
  public:
    static auto
    value_type () -> GType G_GNUC_CONST;
  };

} // namespace Glib
#endif

namespace Glib
{

  LIBMM_GIO_SYMEXPORT
  auto
  wrap (GSocket* object, bool take_copy = false) -> Glib::RefPtr<Gio::Socket>;
} // namespace Glib

#endif