
#ifndef _GIOMM_DBUSCONNECTION_H
#define _GIOMM_DBUSCONNECTION_H

#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <gio/gio.h>
#include <libmm-gio/asyncinitable.hxx>
#include <libmm-gio/asyncresult.hxx>
#include <libmm-gio/credentials.hxx>
#include <libmm-gio/dbusauthobserver.hxx>
#include <libmm-gio/dbusintrospection.hxx>
#include <libmm-gio/dbusmessage.hxx>
#include <libmm-gio/dbusmethodinvocation.hxx>
#include <libmm-gio/dbussubtreevtable.hxx>
#include <libmm-gio/initable.hxx>
#include <libmm-gio/iostream.hxx>
#include <libmm-glib/object.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GDBusConnection = struct _GDBusConnection;
using GDBusConnectionClass = struct _GDBusConnectionClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gio::DBus
{
  class GIOMM_API Connection_Class;
}
#endif

namespace Gio
{

  class GIOMM_API ActionGroup;
  class GIOMM_API MenuModel;
  class GIOMM_API UnixFDList;

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

} // namespace Gio

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

  template <>
  class GIOMM_API Value<Gio::DBus::BusType>
    : public Glib::Value_Enum<Gio::DBus::BusType>
  {
  public:
    static auto
    value_type () -> GType G_GNUC_CONST;
  };

} // namespace Glib
#endif

namespace Gio::DBus
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

} // namespace Gio::DBus

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

  template <>
  class GIOMM_API Value<Gio::DBus::ConnectionFlags>
    : public Glib::Value_Flags<Gio::DBus::ConnectionFlags>
  {
  public:
    static auto
    value_type () -> GType G_GNUC_CONST;
  };

} // namespace Glib
#endif

namespace Gio::DBus
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

  class GIOMM_API Connection : public Glib::Object,
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
    explicit Connection (const Glib::ConstructParams& construct_params);
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
    Connection (const Glib::RefPtr<IOStream>& stream,
                const std::string& guid,
                const Glib::RefPtr<AuthObserver>& observer,
                const SlotAsyncReady& slot,
                const Glib::RefPtr<Cancellable>& cancellable,
                ConnectionFlags flags);

    Connection (const Glib::RefPtr<IOStream>& stream,
                const std::string& guid,
                const SlotAsyncReady& slot,
                const Glib::RefPtr<Cancellable>& cancellable,
                ConnectionFlags flags);

    Connection (const Glib::RefPtr<IOStream>& stream,
                const std::string& guid,
                const Glib::RefPtr<AuthObserver>& observer,
                const SlotAsyncReady& slot,
                ConnectionFlags flags);

    Connection (const Glib::RefPtr<IOStream>& stream,
                const std::string& guid,
                const SlotAsyncReady& slot,
                ConnectionFlags flags);

    Connection (const Glib::RefPtr<IOStream>& stream,
                const std::string& guid,
                const Glib::RefPtr<AuthObserver>& observer,
                const Glib::RefPtr<Cancellable>& cancellable,
                ConnectionFlags flags);

    Connection (const Glib::RefPtr<IOStream>& stream,
                const std::string& guid,
                const Glib::RefPtr<Cancellable>& cancellable,
                ConnectionFlags flags);

    Connection (const Glib::RefPtr<IOStream>& stream,
                const std::string& guid,
                const Glib::RefPtr<AuthObserver>& observer,
                ConnectionFlags flags);

    Connection (const Glib::RefPtr<IOStream>& stream,
                const std::string& guid,
                ConnectionFlags flags);

    Connection (const std::string& address,
                const Glib::RefPtr<AuthObserver>& observer,
                const SlotAsyncReady& slot,
                const Glib::RefPtr<Cancellable>& cancellable,
                ConnectionFlags flags);

    Connection (const std::string& address,
                const SlotAsyncReady& slot,
                const Glib::RefPtr<Cancellable>& cancellable,
                ConnectionFlags flags);

    Connection (const std::string& address,
                const Glib::RefPtr<AuthObserver>& observer,
                const SlotAsyncReady& slot,
                ConnectionFlags flags);

    Connection (const std::string& address,
                const SlotAsyncReady& slot,
                ConnectionFlags flags);

    Connection (const std::string& address,
                const Glib::RefPtr<AuthObserver>& observer,
                const Glib::RefPtr<Cancellable>& cancellable,
                ConnectionFlags flags);

    Connection (const std::string& address,
                const Glib::RefPtr<Cancellable>& cancellable,
                ConnectionFlags flags);

    Connection (const std::string& address,
                const Glib::RefPtr<AuthObserver>& observer,
                ConnectionFlags flags);

    Connection (const std::string& address, ConnectionFlags flags);

  public:
    using SlotSignal = sigc::slot<void (const Glib::RefPtr<Connection>&,
                                        const Glib::ustring&,
                                        const Glib::ustring&,
                                        const Glib::ustring&,
                                        const Glib::ustring&,
                                        const Glib::VariantContainerBase&)>;

    using SlotMessageFilter =
        sigc::slot<Glib::RefPtr<Message> (const Glib::RefPtr<Connection>&,
                                          const Glib::RefPtr<Message>&,
                                          bool)>;

    static void
    get (BusType bus_type,
         const SlotAsyncReady& slot,
         const Glib::RefPtr<Cancellable>& cancellable);

    static void
    get (BusType bus_type, const SlotAsyncReady& slot);

    static auto
    get_finish (const Glib::RefPtr<AsyncResult>& res)
        -> Glib::RefPtr<Connection>;

    static auto
    get_sync (BusType bus_type, const Glib::RefPtr<Cancellable>& cancellable)
        -> Glib::RefPtr<Connection>;

    static auto
    get_sync (BusType bus_type) -> Glib::RefPtr<Connection>;

    static void
    create (const Glib::RefPtr<IOStream>& stream,
            const std::string& guid,
            const Glib::RefPtr<AuthObserver>& observer,
            const SlotAsyncReady& slot,
            const Glib::RefPtr<Cancellable>& cancellable,
            ConnectionFlags flags = Gio::DBus::ConnectionFlags::NONE);

    static void
    create (const Glib::RefPtr<IOStream>& stream,
            const std::string& guid,
            const SlotAsyncReady& slot,
            const Glib::RefPtr<Cancellable>& cancellable,
            ConnectionFlags flags = Gio::DBus::ConnectionFlags::NONE);

    static void
    create (const Glib::RefPtr<IOStream>& stream,
            const std::string& guid,
            const Glib::RefPtr<AuthObserver>& observer,
            const SlotAsyncReady& slot,
            ConnectionFlags flags = Gio::DBus::ConnectionFlags::NONE);

    static void
    create (const Glib::RefPtr<IOStream>& stream,
            const std::string& guid,
            const SlotAsyncReady& slot,
            ConnectionFlags flags = Gio::DBus::ConnectionFlags::NONE);

    static auto
    create_finish (const Glib::RefPtr<AsyncResult>& res)
        -> Glib::RefPtr<Connection>;

    static void
    create_for_address (
        const std::string& address,
        const Glib::RefPtr<AuthObserver>& observer,
        const SlotAsyncReady& slot,
        const Glib::RefPtr<Cancellable>& cancellable,
        ConnectionFlags flags = Gio::DBus::ConnectionFlags::NONE);

    static void
    create_for_address (
        const std::string& address,
        const SlotAsyncReady& slot,
        const Glib::RefPtr<Cancellable>& cancellable,
        ConnectionFlags flags = Gio::DBus::ConnectionFlags::NONE);

    static void
    create_for_address (
        const std::string& address,
        const Glib::RefPtr<AuthObserver>& observer,
        const SlotAsyncReady& slot,
        ConnectionFlags flags = Gio::DBus::ConnectionFlags::NONE);

    static void
    create_for_address (
        const std::string& address,
        const SlotAsyncReady& slot,
        ConnectionFlags flags = Gio::DBus::ConnectionFlags::NONE);

    static auto
    create_for_address_finish (const Glib::RefPtr<AsyncResult>& res)
        -> Glib::RefPtr<Connection>;

    static auto
    create_sync (const Glib::RefPtr<IOStream>& stream,
                 const std::string& guid,
                 const Glib::RefPtr<AuthObserver>& observer,
                 const Glib::RefPtr<Cancellable>& cancellable,
                 ConnectionFlags flags = Gio::DBus::ConnectionFlags::NONE)
        -> Glib::RefPtr<Connection>;

    static auto
    create_sync (const Glib::RefPtr<IOStream>& stream,
                 const std::string& guid,
                 const Glib::RefPtr<Cancellable>& cancellable,
                 ConnectionFlags flags = Gio::DBus::ConnectionFlags::NONE)
        -> Glib::RefPtr<Connection>;

    static auto
    create_sync (const Glib::RefPtr<IOStream>& stream,
                 const std::string& guid,
                 const Glib::RefPtr<AuthObserver>& observer,
                 ConnectionFlags flags = Gio::DBus::ConnectionFlags::NONE)
        -> Glib::RefPtr<Connection>;

    static auto
    create_sync (const Glib::RefPtr<IOStream>& stream,
                 const std::string& guid,
                 ConnectionFlags flags = Gio::DBus::ConnectionFlags::NONE)
        -> Glib::RefPtr<Connection>;

    static auto
    create_for_address_sync (
        const std::string& address,
        const Glib::RefPtr<AuthObserver>& observer,
        const Glib::RefPtr<Cancellable>& cancellable,
        ConnectionFlags flags = Gio::DBus::ConnectionFlags::NONE)
        -> Glib::RefPtr<Connection>;

    static auto
    create_for_address_sync (
        const std::string& address,
        const Glib::RefPtr<Cancellable>& cancellable,
        ConnectionFlags flags = Gio::DBus::ConnectionFlags::NONE)
        -> Glib::RefPtr<Connection>;

    static auto
    create_for_address_sync (
        const std::string& address,
        const Glib::RefPtr<AuthObserver>& observer,
        ConnectionFlags flags = Gio::DBus::ConnectionFlags::NONE)
        -> Glib::RefPtr<Connection>;

    static auto
    create_for_address_sync (
        const std::string& address,
        ConnectionFlags flags = Gio::DBus::ConnectionFlags::NONE)
        -> Glib::RefPtr<Connection>;

    void
    close ();

    void
    close (const SlotAsyncReady& slot,
           const Glib::RefPtr<Cancellable>& cancellable);

    void
    close (const SlotAsyncReady& slot);

    auto
    close_finish (const Glib::RefPtr<AsyncResult>& res) -> bool;

    void
    close_sync (const Glib::RefPtr<Cancellable>& cancellable);

    void
    close_sync ();

    void
    flush ();

    void
    flush (const SlotAsyncReady& slot,
           const Glib::RefPtr<Cancellable>& cancellable);

    void
    flush (const SlotAsyncReady& slot);

    auto
    flush_finish (const Glib::RefPtr<AsyncResult>& res) -> bool;

    void
    flush_sync (const Glib::RefPtr<Cancellable>& cancellable);

    void
    flush_sync ();

    auto
    get_exit_on_close () const -> bool;

    void
    set_exit_on_close (bool exit_on_close = true);

    auto
    send_message (const Glib::RefPtr<Message>& message,
                  SendMessageFlags flags,
                  guint32& out_serial) -> bool;

    auto
    send_message (const Glib::RefPtr<Message>& message,
                  SendMessageFlags flags = Gio::DBus::SendMessageFlags::NONE)
        -> bool;

    void
    send_message_with_reply (const Glib::RefPtr<Message>& message,
                             int timeout_msec,
                             const SlotAsyncReady& slot,
                             const Glib::RefPtr<Cancellable>& cancellable);

    void
    send_message_with_reply (const Glib::RefPtr<Message>& message,
                             int timeout_msec,
                             const SlotAsyncReady& slot);

    auto
    send_message_with_reply_finish (const Glib::RefPtr<AsyncResult>& res)
        -> Glib::RefPtr<Message>;

    auto
    send_message_with_reply_sync (const Glib::RefPtr<Message>& message,
                                  const Glib::RefPtr<Cancellable>& cancellable,
                                  gint timeout_msec) -> Glib::RefPtr<Message>;

    auto
    send_message_with_reply_sync (const Glib::RefPtr<Message>& message,
                                  gint timeout_msec) -> Glib::RefPtr<Message>;

    void
    start_message_processing ();

    auto
    is_closed () const -> bool;

    auto
    get_stream () -> Glib::RefPtr<IOStream>;

    auto
    get_stream () const -> Glib::RefPtr<const IOStream>;

    auto
    get_guid () const -> std::string;

    auto
    get_unique_name () const -> Glib::ustring;

    auto
    get_capabilities () const -> CapabilityFlags;

    auto
    get_flags () const -> ConnectionFlags;

    auto
    get_peer_credentials () -> Glib::RefPtr<Credentials>;

    auto
    get_peer_credentials () const -> Glib::RefPtr<const Credentials>;

    auto
    get_last_serial () const -> guint32;

    void
    call (const Glib::ustring& object_path,
          const Glib::ustring& interface_name,
          const Glib::ustring& method_name,
          const Glib::VariantContainerBase& parameters,
          const SlotAsyncReady& slot,
          const Glib::RefPtr<Cancellable>& cancellable,
          const Glib::ustring& bus_name = {},
          int timeout_msec = -1,
          CallFlags flags = Gio::DBus::CallFlags::NONE,
          const Glib::VariantType& reply_type = {});

    void
    call (const Glib::ustring& object_path,
          const Glib::ustring& interface_name,
          const Glib::ustring& method_name,
          const Glib::VariantContainerBase& parameters,
          const SlotAsyncReady& slot,
          const Glib::ustring& bus_name = {},
          int timeout_msec = -1,
          CallFlags flags = Gio::DBus::CallFlags::NONE,
          const Glib::VariantType& reply_type = {});

    auto
    call_finish (const Glib::RefPtr<AsyncResult>& res)
        -> Glib::VariantContainerBase;

    auto
    call_sync (const Glib::ustring& object_path,
               const Glib::ustring& interface_name,
               const Glib::ustring& method_name,
               const Glib::VariantContainerBase& parameters,
               const Glib::RefPtr<Cancellable>& cancellable,
               const Glib::ustring& bus_name = {},
               int timeout_msec = -1,
               CallFlags flags = Gio::DBus::CallFlags::NONE,
               const Glib::VariantType& reply_type = {})
        -> Glib::VariantContainerBase;

    auto
    call_sync (const Glib::ustring& object_path,
               const Glib::ustring& interface_name,
               const Glib::ustring& method_name,
               const Glib::VariantContainerBase& parameters,
               const Glib::ustring& bus_name = {},
               int timeout_msec = -1,
               CallFlags flags = Gio::DBus::CallFlags::NONE,
               const Glib::VariantType& reply_type = {})
        -> Glib::VariantContainerBase;

#ifdef G_OS_UNIX

    void
    call (const Glib::ustring& object_path,
          const Glib::ustring& interface_name,
          const Glib::ustring& method_name,
          const Glib::VariantContainerBase& parameters,
          const SlotAsyncReady& slot,
          const Glib::RefPtr<Cancellable>& cancellable,
          const Glib::RefPtr<UnixFDList>& fd_list,
          const Glib::ustring& bus_name = {},
          int timeout_msec = -1,
          CallFlags flags = Gio::DBus::CallFlags::NONE,
          const Glib::VariantType& reply_type = {});

    void
    call (const Glib::ustring& object_path,
          const Glib::ustring& interface_name,
          const Glib::ustring& method_name,
          const Glib::VariantContainerBase& parameters,
          const SlotAsyncReady& slot,
          const Glib::RefPtr<UnixFDList>& fd_list,
          const Glib::ustring& bus_name = {},
          int timeout_msec = -1,
          CallFlags flags = Gio::DBus::CallFlags::NONE,
          const Glib::VariantType& reply_type = {});
#endif

#ifdef G_OS_UNIX

    auto
    call_finish (const Glib::RefPtr<AsyncResult>& res,
                 Glib::RefPtr<UnixFDList>& out_fd_list)
        -> Glib::VariantContainerBase;
#endif

#ifdef G_OS_UNIX

    auto
    call_sync (const Glib::ustring& object_path,
               const Glib::ustring& interface_name,
               const Glib::ustring& method_name,
               const Glib::VariantContainerBase& parameters,
               const Glib::RefPtr<Cancellable>& cancellable,
               const Glib::RefPtr<UnixFDList>& fd_list,
               Glib::RefPtr<UnixFDList>& out_fd_list,
               const Glib::ustring& bus_name = {},
               int timeout_msec = -1,
               CallFlags flags = Gio::DBus::CallFlags::NONE,
               const Glib::VariantType& reply_type = {})
        -> Glib::VariantContainerBase;
#endif

#ifdef G_OS_UNIX

    auto
    call_sync (const Glib::ustring& object_path,
               const Glib::ustring& interface_name,
               const Glib::ustring& method_name,
               const Glib::VariantContainerBase& parameters,
               const Glib::RefPtr<UnixFDList>& fd_list,
               Glib::RefPtr<UnixFDList>& out_fd_list,
               const Glib::ustring& bus_name = {},
               int timeout_msec = -1,
               CallFlags flags = Gio::DBus::CallFlags::NONE,
               const Glib::VariantType& reply_type = {})
        -> Glib::VariantContainerBase;
#endif

    void
    emit_signal (const Glib::ustring& object_path,
                 const Glib::ustring& interface_name,
                 const Glib::ustring& signal_name,
                 const Glib::ustring& destination_bus_name = {},
                 const Glib::VariantContainerBase& parameters = {});

    auto
    signal_subscribe (const SlotSignal& slot,
                      const Glib::ustring& sender = {},
                      const Glib::ustring& interface_name = {},
                      const Glib::ustring& member = {},
                      const Glib::ustring& object_path = {},
                      const Glib::ustring& arg0 = {},
                      SignalFlags flags = Gio::DBus::SignalFlags::NONE)
        -> guint;

    void
    signal_unsubscribe (guint subscription_id);

    auto
    add_filter (const SlotMessageFilter& slot) -> guint;

    void
    remove_filter (guint filter_id);

    auto
    register_object (const Glib::ustring& object_path,
                     const Glib::RefPtr<InterfaceInfo>& interface_info,
                     const InterfaceVTable& vtable) -> guint;

    auto
    register_object (const Glib::ustring& object_path,
                     const Glib::RefPtr<InterfaceInfo>& interface_info)
        -> guint;

    auto
    unregister_object (guint registration_id) -> bool;

    auto
    register_subtree (const Glib::ustring& object_path,
                      const SubtreeVTable& vtable,
                      SubtreeFlags flags = Gio::DBus::SubtreeFlags::NONE)
        -> guint;

    auto
    unregister_subtree (guint registration_id) -> bool;

    auto
    export_action_group (const Glib::ustring& object_path,
                         const Glib::RefPtr<ActionGroup>& action_group)
        -> guint;

    void
    unexport_action_group (guint export_id);

    auto
    export_menu_model (const Glib::ustring& object_path,
                       const Glib::RefPtr<MenuModel>& menu) -> guint;

    void
    unexport_menu_model (guint export_id);

    auto
    property_capabilities () const
        -> Glib::PropertyProxy_ReadOnly<CapabilityFlags>;

    auto
    property_closed () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_exit_on_close () -> Glib::PropertyProxy<bool>;

    auto
    property_exit_on_close () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_flags () const -> Glib::PropertyProxy_ReadOnly<ConnectionFlags>;

    auto
    property_guid () const -> Glib::PropertyProxy_ReadOnly<std::string>;

    auto
    property_stream () const
        -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<IOStream>>;

    auto
    property_unique_name () const
        -> Glib::PropertyProxy_ReadOnly<Glib::ustring>;

    auto
    signal_closed () -> Glib::SignalProxy<void (bool, const Glib::Error&)>;

  public:
  public:
  protected:
  };

} // namespace Gio::DBus

namespace Glib
{

  GIOMM_API
  auto
  wrap (GDBusConnection* object, bool take_copy = false) -> Glib::RefPtr<Gio::DBus::Connection>;
} // namespace Glib

#endif
