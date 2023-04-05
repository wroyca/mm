// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GIOMM_DBUSCONNECTION_H
#define _GIOMM_DBUSCONNECTION_H

#include <libmm/glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <gio/gio.h>
#include <libmm/gio/asyncinitable.hxx>
#include <libmm/gio/asyncresult.hxx>
#include <libmm/gio/credentials.hxx>
#include <libmm/gio/dbusauthobserver.hxx>
#include <libmm/gio/dbusintrospection.hxx>
#include <libmm/gio/dbusmessage.hxx>
#include <libmm/gio/dbusmethodinvocation.hxx>
#include <libmm/gio/dbussubtreevtable.hxx>
#include <libmm/gio/initable.hxx>
#include <libmm/gio/iostream.hxx>
#include <libmm/glib/object.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GDBusConnection = struct _GDBusConnection;
using GDBusConnectionClass = struct _GDBusConnectionClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace gio::DBus
{
  class LIBMM_GIO_SYMEXPORT Connection_Class;
}
#endif

namespace gio
{

  class LIBMM_GIO_SYMEXPORT ActionGroup;
  class LIBMM_GIO_SYMEXPORT MenuModel;
  class LIBMM_GIO_SYMEXPORT UnixFDList;

  namespace DBus
  {

    enum class BusType
    {
      STARTER = -1,
      NONE,
      SYSTEM,
      SESSION
    };

  } // namespace DBus

} // namespace gio

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace glib
{

  template <>
  class LIBMM_GIO_SYMEXPORT Value<gio::DBus::BusType>
    : public glib::Value_Enum<gio::DBus::BusType>
  {
  public:
    static auto
    value_type () -> GType G_GNUC_CONST;
  };

} // namespace glib
#endif

namespace gio::DBus
{

  enum class CallFlags
  {
    NONE = 0x0,
    NO_AUTO_START = (1 << 0),
    ALLOW_INTERACTIVE_AUTHORIZATION = (1 << 1)
  };

  inline auto
  operator| (CallFlags lhs, CallFlags rhs) -> CallFlags
  {
    return static_cast<CallFlags> (static_cast<unsigned> (lhs) |
                                   static_cast<unsigned> (rhs));
  }

  inline auto
  operator& (CallFlags lhs, CallFlags rhs) -> CallFlags
  {
    return static_cast<CallFlags> (static_cast<unsigned> (lhs) &
                                   static_cast<unsigned> (rhs));
  }

  inline auto
  operator^ (CallFlags lhs, CallFlags rhs) -> CallFlags
  {
    return static_cast<CallFlags> (static_cast<unsigned> (lhs) ^
                                   static_cast<unsigned> (rhs));
  }

  inline auto
  operator~(CallFlags flags) -> CallFlags
  {
    return static_cast<CallFlags> (~static_cast<unsigned> (flags));
  }

  inline auto
  operator|= (CallFlags& lhs, CallFlags rhs) -> CallFlags&
  {
    return (lhs = static_cast<CallFlags> (static_cast<unsigned> (lhs) |
                                          static_cast<unsigned> (rhs)));
  }

  inline auto
  operator&= (CallFlags& lhs, CallFlags rhs) -> CallFlags&
  {
    return (lhs = static_cast<CallFlags> (static_cast<unsigned> (lhs) &
                                          static_cast<unsigned> (rhs)));
  }

  inline auto
  operator^= (CallFlags& lhs, CallFlags rhs) -> CallFlags&
  {
    return (lhs = static_cast<CallFlags> (static_cast<unsigned> (lhs) ^
                                          static_cast<unsigned> (rhs)));
  }

  enum class ConnectionFlags
  {
    NONE = 0x0,
    AUTHENTICATION_CLIENT = (1 << 0),
    AUTHENTICATION_SERVER = (1 << 1),
    AUTHENTICATION_ALLOW_ANONYMOUS = (1 << 2),
    MESSAGE_BUS_CONNECTION = (1 << 3),
    DELAY_MESSAGE_PROCESSING = (1 << 4),
    AUTHENTICATION_REQUIRE_SAME_USER = (1 << 5),
    CROSS_NAMESPACE = (1 << 6)
  };

  inline auto
  operator| (ConnectionFlags lhs, ConnectionFlags rhs) -> ConnectionFlags
  {
    return static_cast<ConnectionFlags> (static_cast<unsigned> (lhs) |
                                         static_cast<unsigned> (rhs));
  }

  inline auto
  operator& (ConnectionFlags lhs, ConnectionFlags rhs) -> ConnectionFlags
  {
    return static_cast<ConnectionFlags> (static_cast<unsigned> (lhs) &
                                         static_cast<unsigned> (rhs));
  }

  inline auto
  operator^ (ConnectionFlags lhs, ConnectionFlags rhs) -> ConnectionFlags
  {
    return static_cast<ConnectionFlags> (static_cast<unsigned> (lhs) ^
                                         static_cast<unsigned> (rhs));
  }

  inline auto
  operator~(ConnectionFlags flags) -> ConnectionFlags
  {
    return static_cast<ConnectionFlags> (~static_cast<unsigned> (flags));
  }

  inline auto
  operator|= (ConnectionFlags& lhs, ConnectionFlags rhs) -> ConnectionFlags&
  {
    return (lhs = static_cast<ConnectionFlags> (static_cast<unsigned> (lhs) |
                                                static_cast<unsigned> (rhs)));
  }

  inline auto
  operator&= (ConnectionFlags& lhs, ConnectionFlags rhs) -> ConnectionFlags&
  {
    return (lhs = static_cast<ConnectionFlags> (static_cast<unsigned> (lhs) &
                                                static_cast<unsigned> (rhs)));
  }

  inline auto
  operator^= (ConnectionFlags& lhs, ConnectionFlags rhs) -> ConnectionFlags&
  {
    return (lhs = static_cast<ConnectionFlags> (static_cast<unsigned> (lhs) ^
                                                static_cast<unsigned> (rhs)));
  }

} // namespace gio::DBus

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace glib
{

  template <>
  class LIBMM_GIO_SYMEXPORT Value<gio::DBus::ConnectionFlags>
    : public glib::Value_Flags<gio::DBus::ConnectionFlags>
  {
  public:
    static auto
    value_type () -> GType G_GNUC_CONST;
  };

} // namespace glib
#endif

namespace gio::DBus
{

  enum class SendMessageFlags
  {
    NONE = 0x0,
    PRESERVE_SERIAL = (1 << 0)
  };

  inline auto
  operator| (SendMessageFlags lhs, SendMessageFlags rhs) -> SendMessageFlags
  {
    return static_cast<SendMessageFlags> (static_cast<unsigned> (lhs) |
                                          static_cast<unsigned> (rhs));
  }

  inline auto
  operator& (SendMessageFlags lhs, SendMessageFlags rhs) -> SendMessageFlags
  {
    return static_cast<SendMessageFlags> (static_cast<unsigned> (lhs) &
                                          static_cast<unsigned> (rhs));
  }

  inline auto
  operator^ (SendMessageFlags lhs, SendMessageFlags rhs) -> SendMessageFlags
  {
    return static_cast<SendMessageFlags> (static_cast<unsigned> (lhs) ^
                                          static_cast<unsigned> (rhs));
  }

  inline auto
  operator~(SendMessageFlags flags) -> SendMessageFlags
  {
    return static_cast<SendMessageFlags> (~static_cast<unsigned> (flags));
  }

  inline auto
  operator|= (SendMessageFlags& lhs, SendMessageFlags rhs) -> SendMessageFlags&
  {
    return (lhs = static_cast<SendMessageFlags> (static_cast<unsigned> (lhs) |
                                                 static_cast<unsigned> (rhs)));
  }

  inline auto
  operator&= (SendMessageFlags& lhs, SendMessageFlags rhs) -> SendMessageFlags&
  {
    return (lhs = static_cast<SendMessageFlags> (static_cast<unsigned> (lhs) &
                                                 static_cast<unsigned> (rhs)));
  }

  inline auto
  operator^= (SendMessageFlags& lhs, SendMessageFlags rhs) -> SendMessageFlags&
  {
    return (lhs = static_cast<SendMessageFlags> (static_cast<unsigned> (lhs) ^
                                                 static_cast<unsigned> (rhs)));
  }

  enum class SignalFlags
  {
    NONE = 0x0,
    NO_MATCH_RULE = (1 << 0),
    MATCH_ARG0_NAMESPACE = (1 << 1),
    MATCH_ARG0_PATH = (1 << 2)
  };

  inline auto
  operator| (SignalFlags lhs, SignalFlags rhs) -> SignalFlags
  {
    return static_cast<SignalFlags> (static_cast<unsigned> (lhs) |
                                     static_cast<unsigned> (rhs));
  }

  inline auto
  operator& (SignalFlags lhs, SignalFlags rhs) -> SignalFlags
  {
    return static_cast<SignalFlags> (static_cast<unsigned> (lhs) &
                                     static_cast<unsigned> (rhs));
  }

  inline auto
  operator^ (SignalFlags lhs, SignalFlags rhs) -> SignalFlags
  {
    return static_cast<SignalFlags> (static_cast<unsigned> (lhs) ^
                                     static_cast<unsigned> (rhs));
  }

  inline auto
  operator~(SignalFlags flags) -> SignalFlags
  {
    return static_cast<SignalFlags> (~static_cast<unsigned> (flags));
  }

  inline auto
  operator|= (SignalFlags& lhs, SignalFlags rhs) -> SignalFlags&
  {
    return (lhs = static_cast<SignalFlags> (static_cast<unsigned> (lhs) |
                                            static_cast<unsigned> (rhs)));
  }

  inline auto
  operator&= (SignalFlags& lhs, SignalFlags rhs) -> SignalFlags&
  {
    return (lhs = static_cast<SignalFlags> (static_cast<unsigned> (lhs) &
                                            static_cast<unsigned> (rhs)));
  }

  inline auto
  operator^= (SignalFlags& lhs, SignalFlags rhs) -> SignalFlags&
  {
    return (lhs = static_cast<SignalFlags> (static_cast<unsigned> (lhs) ^
                                            static_cast<unsigned> (rhs)));
  }

  enum class SubtreeFlags
  {
    NONE = 0x0,
    DISPATCH_TO_UNENUMERATED_NODES = (1 << 0)
  };

  inline auto
  operator| (SubtreeFlags lhs, SubtreeFlags rhs) -> SubtreeFlags
  {
    return static_cast<SubtreeFlags> (static_cast<unsigned> (lhs) |
                                      static_cast<unsigned> (rhs));
  }

  inline auto
  operator& (SubtreeFlags lhs, SubtreeFlags rhs) -> SubtreeFlags
  {
    return static_cast<SubtreeFlags> (static_cast<unsigned> (lhs) &
                                      static_cast<unsigned> (rhs));
  }

  inline auto
  operator^ (SubtreeFlags lhs, SubtreeFlags rhs) -> SubtreeFlags
  {
    return static_cast<SubtreeFlags> (static_cast<unsigned> (lhs) ^
                                      static_cast<unsigned> (rhs));
  }

  inline auto
  operator~(SubtreeFlags flags) -> SubtreeFlags
  {
    return static_cast<SubtreeFlags> (~static_cast<unsigned> (flags));
  }

  inline auto
  operator|= (SubtreeFlags& lhs, SubtreeFlags rhs) -> SubtreeFlags&
  {
    return (lhs = static_cast<SubtreeFlags> (static_cast<unsigned> (lhs) |
                                             static_cast<unsigned> (rhs)));
  }

  inline auto
  operator&= (SubtreeFlags& lhs, SubtreeFlags rhs) -> SubtreeFlags&
  {
    return (lhs = static_cast<SubtreeFlags> (static_cast<unsigned> (lhs) &
                                             static_cast<unsigned> (rhs)));
  }

  inline auto
  operator^= (SubtreeFlags& lhs, SubtreeFlags rhs) -> SubtreeFlags&
  {
    return (lhs = static_cast<SubtreeFlags> (static_cast<unsigned> (lhs) ^
                                             static_cast<unsigned> (rhs)));
  }

  class LIBMM_GIO_SYMEXPORT Connection : public glib::Object,
                               public Initable,
                               public AsyncInitable
  {
  protected:
#ifndef DOXYGEN_SHOULD_SKIP_THIS

  public:
    using CppObjectType = Connection;
    using CppClassType = Connection_Class;
    using BaseObjectType = GDBusConnection;
    using BaseClassType = GDBusConnectionClass;

    Connection (const Connection&) = delete;
    auto
    operator= (const Connection&) -> Connection& = delete;

  private:
    friend class Connection_Class;
    static CppClassType connection_class_;

  protected:
    explicit Connection (const glib::ConstructParams& construct_params);
    explicit Connection (GDBusConnection* castitem);

#endif

  public:
    Connection (Connection&& src) noexcept;
    auto
    operator= (Connection&& src) noexcept -> Connection&;

    ~Connection () noexcept override;

    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GDBusConnection*
    {
      return reinterpret_cast<GDBusConnection*> (gobject_);
    }

    auto
    gobj () const -> const GDBusConnection*
    {
      return reinterpret_cast<GDBusConnection*> (gobject_);
    }

    auto
    gobj_copy () -> GDBusConnection*;

  private:
  protected:
    Connection (const glib::RefPtr<IOStream>& stream,
                const std::string& guid,
                const glib::RefPtr<AuthObserver>& observer,
                const SlotAsyncReady& slot,
                const glib::RefPtr<Cancellable>& cancellable,
                ConnectionFlags flags);

    Connection (const glib::RefPtr<IOStream>& stream,
                const std::string& guid,
                const SlotAsyncReady& slot,
                const glib::RefPtr<Cancellable>& cancellable,
                ConnectionFlags flags);

    Connection (const glib::RefPtr<IOStream>& stream,
                const std::string& guid,
                const glib::RefPtr<AuthObserver>& observer,
                const SlotAsyncReady& slot,
                ConnectionFlags flags);

    Connection (const glib::RefPtr<IOStream>& stream,
                const std::string& guid,
                const SlotAsyncReady& slot,
                ConnectionFlags flags);

    Connection (const glib::RefPtr<IOStream>& stream,
                const std::string& guid,
                const glib::RefPtr<AuthObserver>& observer,
                const glib::RefPtr<Cancellable>& cancellable,
                ConnectionFlags flags);

    Connection (const glib::RefPtr<IOStream>& stream,
                const std::string& guid,
                const glib::RefPtr<Cancellable>& cancellable,
                ConnectionFlags flags);

    Connection (const glib::RefPtr<IOStream>& stream,
                const std::string& guid,
                const glib::RefPtr<AuthObserver>& observer,
                ConnectionFlags flags);

    Connection (const glib::RefPtr<IOStream>& stream,
                const std::string& guid,
                ConnectionFlags flags);

    Connection (const std::string& address,
                const glib::RefPtr<AuthObserver>& observer,
                const SlotAsyncReady& slot,
                const glib::RefPtr<Cancellable>& cancellable,
                ConnectionFlags flags);

    Connection (const std::string& address,
                const SlotAsyncReady& slot,
                const glib::RefPtr<Cancellable>& cancellable,
                ConnectionFlags flags);

    Connection (const std::string& address,
                const glib::RefPtr<AuthObserver>& observer,
                const SlotAsyncReady& slot,
                ConnectionFlags flags);

    Connection (const std::string& address,
                const SlotAsyncReady& slot,
                ConnectionFlags flags);

    Connection (const std::string& address,
                const glib::RefPtr<AuthObserver>& observer,
                const glib::RefPtr<Cancellable>& cancellable,
                ConnectionFlags flags);

    Connection (const std::string& address,
                const glib::RefPtr<Cancellable>& cancellable,
                ConnectionFlags flags);

    Connection (const std::string& address,
                const glib::RefPtr<AuthObserver>& observer,
                ConnectionFlags flags);

    Connection (const std::string& address, ConnectionFlags flags);

  public:
    using SlotSignal = sigc::slot<void (const glib::RefPtr<Connection>&,
                                        const glib::ustring&,
                                        const glib::ustring&,
                                        const glib::ustring&,
                                        const glib::ustring&,
                                        const glib::VariantContainerBase&)>;

    using SlotMessageFilter =
        sigc::slot<glib::RefPtr<Message> (const glib::RefPtr<Connection>&,
                                          const glib::RefPtr<Message>&,
                                          bool)>;

    static auto
    get (BusType bus_type,
         const SlotAsyncReady& slot,
         const glib::RefPtr<Cancellable>& cancellable) -> void;

    static auto
    get (BusType bus_type, const SlotAsyncReady& slot) -> void;

    static auto
    get_finish (const glib::RefPtr<AsyncResult>& res)
        -> glib::RefPtr<Connection>;

    static auto
    get_sync (BusType bus_type, const glib::RefPtr<Cancellable>& cancellable)
        -> glib::RefPtr<Connection>;

    static auto
    get_sync (BusType bus_type) -> glib::RefPtr<Connection>;

    static auto
    create (const glib::RefPtr<IOStream>& stream,
            const std::string& guid,
            const glib::RefPtr<AuthObserver>& observer,
            const SlotAsyncReady& slot,
            const glib::RefPtr<Cancellable>& cancellable,
            ConnectionFlags flags = gio::DBus::ConnectionFlags::NONE) -> void;

    static auto
    create (const glib::RefPtr<IOStream>& stream,
            const std::string& guid,
            const SlotAsyncReady& slot,
            const glib::RefPtr<Cancellable>& cancellable,
            ConnectionFlags flags = gio::DBus::ConnectionFlags::NONE) -> void;

    static auto
    create (const glib::RefPtr<IOStream>& stream,
            const std::string& guid,
            const glib::RefPtr<AuthObserver>& observer,
            const SlotAsyncReady& slot,
            ConnectionFlags flags = gio::DBus::ConnectionFlags::NONE) -> void;

    static auto
    create (const glib::RefPtr<IOStream>& stream,
            const std::string& guid,
            const SlotAsyncReady& slot,
            ConnectionFlags flags = gio::DBus::ConnectionFlags::NONE) -> void;

    static auto
    create_finish (const glib::RefPtr<AsyncResult>& res)
        -> glib::RefPtr<Connection>;

    static auto
    create_for_address (
        const std::string& address,
        const glib::RefPtr<AuthObserver>& observer,
        const SlotAsyncReady& slot,
        const glib::RefPtr<Cancellable>& cancellable,
        ConnectionFlags flags = gio::DBus::ConnectionFlags::NONE) -> void;

    static auto
    create_for_address (
        const std::string& address,
        const SlotAsyncReady& slot,
        const glib::RefPtr<Cancellable>& cancellable,
        ConnectionFlags flags = gio::DBus::ConnectionFlags::NONE) -> void;

    static auto
    create_for_address (
        const std::string& address,
        const glib::RefPtr<AuthObserver>& observer,
        const SlotAsyncReady& slot,
        ConnectionFlags flags = gio::DBus::ConnectionFlags::NONE) -> void;

    static auto
    create_for_address (
        const std::string& address,
        const SlotAsyncReady& slot,
        ConnectionFlags flags = gio::DBus::ConnectionFlags::NONE) -> void;

    static auto
    create_for_address_finish (const glib::RefPtr<AsyncResult>& res)
        -> glib::RefPtr<Connection>;

    static auto
    create_sync (const glib::RefPtr<IOStream>& stream,
                 const std::string& guid,
                 const glib::RefPtr<AuthObserver>& observer,
                 const glib::RefPtr<Cancellable>& cancellable,
                 ConnectionFlags flags = gio::DBus::ConnectionFlags::NONE)
        -> glib::RefPtr<Connection>;

    static auto
    create_sync (const glib::RefPtr<IOStream>& stream,
                 const std::string& guid,
                 const glib::RefPtr<Cancellable>& cancellable,
                 ConnectionFlags flags = gio::DBus::ConnectionFlags::NONE)
        -> glib::RefPtr<Connection>;

    static auto
    create_sync (const glib::RefPtr<IOStream>& stream,
                 const std::string& guid,
                 const glib::RefPtr<AuthObserver>& observer,
                 ConnectionFlags flags = gio::DBus::ConnectionFlags::NONE)
        -> glib::RefPtr<Connection>;

    static auto
    create_sync (const glib::RefPtr<IOStream>& stream,
                 const std::string& guid,
                 ConnectionFlags flags = gio::DBus::ConnectionFlags::NONE)
        -> glib::RefPtr<Connection>;

    static auto
    create_for_address_sync (
        const std::string& address,
        const glib::RefPtr<AuthObserver>& observer,
        const glib::RefPtr<Cancellable>& cancellable,
        ConnectionFlags flags = gio::DBus::ConnectionFlags::NONE)
        -> glib::RefPtr<Connection>;

    static auto
    create_for_address_sync (
        const std::string& address,
        const glib::RefPtr<Cancellable>& cancellable,
        ConnectionFlags flags = gio::DBus::ConnectionFlags::NONE)
        -> glib::RefPtr<Connection>;

    static auto
    create_for_address_sync (
        const std::string& address,
        const glib::RefPtr<AuthObserver>& observer,
        ConnectionFlags flags = gio::DBus::ConnectionFlags::NONE)
        -> glib::RefPtr<Connection>;

    static auto
    create_for_address_sync (
        const std::string& address,
        ConnectionFlags flags = gio::DBus::ConnectionFlags::NONE)
        -> glib::RefPtr<Connection>;

    auto
    close () -> void;

    auto
    close (const SlotAsyncReady& slot,
           const glib::RefPtr<Cancellable>& cancellable) -> void;

    auto
    close (const SlotAsyncReady& slot) -> void;

    auto
    close_finish (const glib::RefPtr<AsyncResult>& res) -> bool;

    auto
    close_sync (const glib::RefPtr<Cancellable>& cancellable) -> void;

    auto
    close_sync () -> void;

    auto
    flush () -> void;

    auto
    flush (const SlotAsyncReady& slot,
           const glib::RefPtr<Cancellable>& cancellable) -> void;

    auto
    flush (const SlotAsyncReady& slot) -> void;

    auto
    flush_finish (const glib::RefPtr<AsyncResult>& res) -> bool;

    auto
    flush_sync (const glib::RefPtr<Cancellable>& cancellable) -> void;

    auto
    flush_sync () -> void;

    auto
    get_exit_on_close () const -> bool;

    auto
    set_exit_on_close (bool exit_on_close = true) -> void;

    auto
    send_message (const glib::RefPtr<Message>& message,
                  SendMessageFlags flags,
                  guint32& out_serial) -> bool;

    auto
    send_message (const glib::RefPtr<Message>& message,
                  SendMessageFlags flags = gio::DBus::SendMessageFlags::NONE)
        -> bool;

    auto
    send_message_with_reply (const glib::RefPtr<Message>& message,
                             int timeout_msec,
                             const SlotAsyncReady& slot,
                             const glib::RefPtr<Cancellable>& cancellable)
        -> void;

    auto
    send_message_with_reply (const glib::RefPtr<Message>& message,
                             int timeout_msec,
                             const SlotAsyncReady& slot) -> void;

    auto
    send_message_with_reply_finish (const glib::RefPtr<AsyncResult>& res)
        -> glib::RefPtr<Message>;

    auto
    send_message_with_reply_sync (const glib::RefPtr<Message>& message,
                                  const glib::RefPtr<Cancellable>& cancellable,
                                  gint timeout_msec) -> glib::RefPtr<Message>;

    auto
    send_message_with_reply_sync (const glib::RefPtr<Message>& message,
                                  gint timeout_msec) -> glib::RefPtr<Message>;

    auto
    start_message_processing () -> void;

    auto
    is_closed () const -> bool;

    auto
    get_stream () -> glib::RefPtr<IOStream>;

    auto
    get_stream () const -> glib::RefPtr<const IOStream>;

    auto
    get_guid () const -> std::string;

    auto
    get_unique_name () const -> glib::ustring;

    auto
    get_capabilities () const -> CapabilityFlags;

    auto
    get_flags () const -> ConnectionFlags;

    auto
    get_peer_credentials () -> glib::RefPtr<Credentials>;

    auto
    get_peer_credentials () const -> glib::RefPtr<const Credentials>;

    auto
    get_last_serial () const -> guint32;

    auto
    call (const glib::ustring& object_path,
          const glib::ustring& interface_name,
          const glib::ustring& method_name,
          const glib::VariantContainerBase& parameters,
          const SlotAsyncReady& slot,
          const glib::RefPtr<Cancellable>& cancellable,
          const glib::ustring& bus_name = {},
          int timeout_msec = -1,
          CallFlags flags = gio::DBus::CallFlags::NONE,
          const glib::VariantType& reply_type = {}) -> void;

    auto
    call (const glib::ustring& object_path,
          const glib::ustring& interface_name,
          const glib::ustring& method_name,
          const glib::VariantContainerBase& parameters,
          const SlotAsyncReady& slot,
          const glib::ustring& bus_name = {},
          int timeout_msec = -1,
          CallFlags flags = gio::DBus::CallFlags::NONE,
          const glib::VariantType& reply_type = {}) -> void;

    auto
    call_finish (const glib::RefPtr<AsyncResult>& res)
        -> glib::VariantContainerBase;

    auto
    call_sync (const glib::ustring& object_path,
               const glib::ustring& interface_name,
               const glib::ustring& method_name,
               const glib::VariantContainerBase& parameters,
               const glib::RefPtr<Cancellable>& cancellable,
               const glib::ustring& bus_name = {},
               int timeout_msec = -1,
               CallFlags flags = gio::DBus::CallFlags::NONE,
               const glib::VariantType& reply_type = {})
        -> glib::VariantContainerBase;

    auto
    call_sync (const glib::ustring& object_path,
               const glib::ustring& interface_name,
               const glib::ustring& method_name,
               const glib::VariantContainerBase& parameters,
               const glib::ustring& bus_name = {},
               int timeout_msec = -1,
               CallFlags flags = gio::DBus::CallFlags::NONE,
               const glib::VariantType& reply_type = {})
        -> glib::VariantContainerBase;

#ifdef G_OS_UNIX

    void
    call (const glib::ustring& object_path,
          const glib::ustring& interface_name,
          const glib::ustring& method_name,
          const glib::VariantContainerBase& parameters,
          const SlotAsyncReady& slot,
          const glib::RefPtr<Cancellable>& cancellable,
          const glib::RefPtr<UnixFDList>& fd_list,
          const glib::ustring& bus_name = {},
          int timeout_msec = -1,
          CallFlags flags = gio::DBus::CallFlags::NONE,
          const glib::VariantType& reply_type = {});

    void
    call (const glib::ustring& object_path,
          const glib::ustring& interface_name,
          const glib::ustring& method_name,
          const glib::VariantContainerBase& parameters,
          const SlotAsyncReady& slot,
          const glib::RefPtr<UnixFDList>& fd_list,
          const glib::ustring& bus_name = {},
          int timeout_msec = -1,
          CallFlags flags = gio::DBus::CallFlags::NONE,
          const glib::VariantType& reply_type = {});
#endif

#ifdef G_OS_UNIX

    auto
    call_finish (const glib::RefPtr<AsyncResult>& res,
                 glib::RefPtr<UnixFDList>& out_fd_list)
        -> glib::VariantContainerBase;
#endif

#ifdef G_OS_UNIX

    auto
    call_sync (const glib::ustring& object_path,
               const glib::ustring& interface_name,
               const glib::ustring& method_name,
               const glib::VariantContainerBase& parameters,
               const glib::RefPtr<Cancellable>& cancellable,
               const glib::RefPtr<UnixFDList>& fd_list,
               glib::RefPtr<UnixFDList>& out_fd_list,
               const glib::ustring& bus_name = {},
               int timeout_msec = -1,
               CallFlags flags = gio::DBus::CallFlags::NONE,
               const glib::VariantType& reply_type = {})
        -> glib::VariantContainerBase;
#endif

#ifdef G_OS_UNIX

    auto
    call_sync (const glib::ustring& object_path,
               const glib::ustring& interface_name,
               const glib::ustring& method_name,
               const glib::VariantContainerBase& parameters,
               const glib::RefPtr<UnixFDList>& fd_list,
               glib::RefPtr<UnixFDList>& out_fd_list,
               const glib::ustring& bus_name = {},
               int timeout_msec = -1,
               CallFlags flags = gio::DBus::CallFlags::NONE,
               const glib::VariantType& reply_type = {})
        -> glib::VariantContainerBase;
#endif

    auto
    emit_signal (const glib::ustring& object_path,
                 const glib::ustring& interface_name,
                 const glib::ustring& signal_name,
                 const glib::ustring& destination_bus_name = {},
                 const glib::VariantContainerBase& parameters = {}) -> void;

    auto
    signal_subscribe (const SlotSignal& slot,
                      const glib::ustring& sender = {},
                      const glib::ustring& interface_name = {},
                      const glib::ustring& member = {},
                      const glib::ustring& object_path = {},
                      const glib::ustring& arg0 = {},
                      SignalFlags flags = gio::DBus::SignalFlags::NONE)
        -> guint;

    auto
    signal_unsubscribe (guint subscription_id) -> void;

    auto
    add_filter (const SlotMessageFilter& slot) -> guint;

    auto
    remove_filter (guint filter_id) -> void;

    auto
    register_object (const glib::ustring& object_path,
                     const glib::RefPtr<InterfaceInfo>& interface_info,
                     const InterfaceVTable& vtable) -> guint;

    auto
    register_object (const glib::ustring& object_path,
                     const glib::RefPtr<InterfaceInfo>& interface_info)
        -> guint;

    auto
    unregister_object (guint registration_id) -> bool;

    auto
    register_subtree (const glib::ustring& object_path,
                      const SubtreeVTable& vtable,
                      SubtreeFlags flags = gio::DBus::SubtreeFlags::NONE)
        -> guint;

    auto
    unregister_subtree (guint registration_id) -> bool;

    auto
    export_action_group (const glib::ustring& object_path,
                         const glib::RefPtr<ActionGroup>& action_group)
        -> guint;

    auto
    unexport_action_group (guint export_id) -> void;

    auto
    export_menu_model (const glib::ustring& object_path,
                       const glib::RefPtr<MenuModel>& menu) -> guint;

    auto
    unexport_menu_model (guint export_id) -> void;

    auto
    property_capabilities () const
        -> glib::PropertyProxy_ReadOnly<CapabilityFlags>;

    auto
    property_closed () const -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_exit_on_close () -> glib::PropertyProxy<bool>;

    auto
    property_exit_on_close () const -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_flags () const -> glib::PropertyProxy_ReadOnly<ConnectionFlags>;

    auto
    property_guid () const -> glib::PropertyProxy_ReadOnly<std::string>;

    auto
    property_stream () const
        -> glib::PropertyProxy_ReadOnly<glib::RefPtr<IOStream>>;

    auto
    property_unique_name () const
        -> glib::PropertyProxy_ReadOnly<glib::ustring>;

    auto
    signal_closed () -> glib::SignalProxy<void (bool, const glib::Error&)>;

  public:
  public:
  protected:
  };

} // namespace gio::DBus

namespace glib
{

  LIBMM_GIO_SYMEXPORT
  auto
  wrap (GDBusConnection* object, bool take_copy = false) -> glib::RefPtr<gio::DBus::Connection>;
} // namespace glib

#endif
