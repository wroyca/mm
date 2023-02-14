

#include <libmm-glib/mm-glib.hxx>

#include <libmm-gio/dbusconnection.hxx>
#include <libmm-gio/dbusconnection_p.hxx>

#include <gio/gio.h>
#include <libmm-gio/actiongroup.hxx>
#include <libmm-gio/dbusauthobserver.hxx>
#include <libmm-gio/dbuserror.hxx>
#include <libmm-gio/dbusintrospection.hxx>
#include <libmm-gio/dbusmethodinvocation.hxx>
#include <libmm-gio/menumodel.hxx>
#include <libmm-glib/exceptionhandler.hxx>

#ifdef G_OS_UNIX
  #include <libmm-gio/unixfdlist.hxx>
#endif

#include <libmm-gio/slot_async.hxx>
#include <mutex>

namespace
{

  extern "C"
  {
    static auto
    DBusConnection_Signal_giomm_callback (GDBusConnection* connection,
                                          const char* sender_name,
                                          const char* object_path,
                                          const char* interface_name,
                                          const char* signal_name,
                                          GVariant* parameters,
                                          void* user_data) -> void
    {
      const Gio::DBus::Connection::SlotSignal* the_slot =
          static_cast<Gio::DBus::Connection::SlotSignal*> (user_data);

      try
      {
        (*the_slot) (Glib::wrap (connection, true),
                     sender_name ? sender_name : "",
                     object_path ? object_path : "",
                     interface_name ? interface_name : "",
                     signal_name ? signal_name : "",
                     Glib::VariantContainerBase (parameters, true));
      }
      catch (...)
      {
        Glib::exception_handlers_invoke ();
      }
    }

    static auto
    DBusConnection_Signal_giomm_callback_destroy (void* data) -> void
    {
      delete static_cast<Gio::DBus::Connection::SlotSignal*> (data);
    }

    static auto
    DBusConnection_Message_Filter_giomm_callback (GDBusConnection* connection,
                                                  GDBusMessage* message,
                                                  const gboolean incoming,
                                                  void* user_data)
        -> GDBusMessage*
    {
      const Gio::DBus::Connection::SlotMessageFilter* the_slot =
          static_cast<Gio::DBus::Connection::SlotMessageFilter*> (user_data);

      try
      {
        const auto result = (*the_slot) (Glib::wrap (connection, true),
                                         Glib::wrap (message, true),
                                         static_cast<bool> (incoming));
        return result ? result->gobj_copy () : nullptr;
      }
      catch (...)
      {
        Glib::exception_handlers_invoke ();
      }

      return message;
    }

    static auto
    DBusConnection_Message_Filter_giomm_callback_destroy (void* data) -> void
    {
      delete static_cast<Gio::DBus::Connection::SlotMessageFilter*> (data);
    }
  }

  std::mutex wrap_mutex;

} // namespace

namespace Gio::DBus
{

  Connection::Connection (const Glib::RefPtr<IOStream>& stream,
                          const std::string& guid,
                          const Glib::RefPtr<AuthObserver>& observer,
                          const SlotAsyncReady& slot,
                          const Glib::RefPtr<Cancellable>& cancellable,
                          const ConnectionFlags flags)
    : ObjectBase (nullptr),
      Object (Glib::ConstructParams (connection_class_.init (),
                                     "stream",
                                     Glib::unwrap (stream),
                                     "guid",
                                     Glib::c_str_or_nullptr (guid),
                                     "flags",
                                     flags,
                                     "authentication-observer",
                                     Glib::unwrap (observer),
                                     nullptr))
  {
    init_async (slot, cancellable);
  }

  Connection::Connection (const Glib::RefPtr<IOStream>& stream,
                          const std::string& guid,
                          const SlotAsyncReady& slot,
                          const Glib::RefPtr<Cancellable>& cancellable,
                          const ConnectionFlags flags)
    : ObjectBase (nullptr),
      Object (Glib::ConstructParams (connection_class_.init (),
                                     "stream",
                                     Glib::unwrap (stream),
                                     "guid",
                                     Glib::c_str_or_nullptr (guid),
                                     "flags",
                                     flags,
                                     "authentication-observer",
                                     nullptr,
                                     nullptr))
  {
    init_async (slot, cancellable);
  }

  Connection::Connection (const Glib::RefPtr<IOStream>& stream,
                          const std::string& guid,
                          const Glib::RefPtr<AuthObserver>& observer,
                          const SlotAsyncReady& slot,
                          const ConnectionFlags flags)
    : ObjectBase (nullptr),
      Object (Glib::ConstructParams (connection_class_.init (),
                                     "stream",
                                     Glib::unwrap (stream),
                                     "guid",
                                     Glib::c_str_or_nullptr (guid),
                                     "flags",
                                     flags,
                                     "authentication-observer",
                                     Glib::unwrap (observer),
                                     nullptr))
  {
    init_async (slot);
  }

  Connection::Connection (const Glib::RefPtr<IOStream>& stream,
                          const std::string& guid,
                          const SlotAsyncReady& slot,
                          const ConnectionFlags flags)
    : ObjectBase (nullptr),
      Object (Glib::ConstructParams (connection_class_.init (),
                                     "stream",
                                     Glib::unwrap (stream),
                                     "guid",
                                     Glib::c_str_or_nullptr (guid),
                                     "flags",
                                     flags,
                                     "authentication-observer",
                                     nullptr,
                                     nullptr))
  {
    init_async (slot);
  }

  Connection::Connection (const std::string& address,
                          const Glib::RefPtr<AuthObserver>& observer,
                          const SlotAsyncReady& slot,
                          const Glib::RefPtr<Cancellable>& cancellable,
                          const ConnectionFlags flags)
    : ObjectBase (nullptr),
      Object (Glib::ConstructParams (connection_class_.init (),
                                     "address",
                                     Glib::c_str_or_nullptr (address),
                                     "flags",
                                     flags,
                                     "authentication-observer",
                                     Glib::unwrap (observer),
                                     nullptr))
  {
    init_async (slot, cancellable);
  }

  Connection::Connection (const std::string& address,
                          const SlotAsyncReady& slot,
                          const Glib::RefPtr<Cancellable>& cancellable,
                          const ConnectionFlags flags)
    : ObjectBase (nullptr),
      Object (Glib::ConstructParams (connection_class_.init (),
                                     "address",
                                     Glib::c_str_or_nullptr (address),
                                     "flags",
                                     flags,
                                     "authentication-observer",
                                     nullptr,
                                     nullptr))
  {
    init_async (slot, cancellable);
  }

  Connection::Connection (const std::string& address,
                          const Glib::RefPtr<AuthObserver>& observer,
                          const SlotAsyncReady& slot,
                          const ConnectionFlags flags)
    : ObjectBase (nullptr),
      Object (Glib::ConstructParams (connection_class_.init (),
                                     "address",
                                     Glib::c_str_or_nullptr (address),
                                     "flags",
                                     flags,
                                     "authentication-observer",
                                     Glib::unwrap (observer),
                                     nullptr))
  {
    init_async (slot);
  }

  Connection::Connection (const std::string& address,
                          const SlotAsyncReady& slot,
                          const ConnectionFlags flags)
    : ObjectBase (nullptr),
      Object (Glib::ConstructParams (connection_class_.init (),
                                     "address",
                                     Glib::c_str_or_nullptr (address),
                                     "flags",
                                     flags,
                                     "authentication-observer",
                                     nullptr,
                                     nullptr))
  {
    init_async (slot);
  }

  Connection::Connection (const Glib::RefPtr<IOStream>& stream,
                          const std::string& guid,
                          const Glib::RefPtr<AuthObserver>& observer,
                          const Glib::RefPtr<Cancellable>& cancellable,
                          const ConnectionFlags flags)
    : ObjectBase (nullptr),
      Object (Glib::ConstructParams (connection_class_.init (),
                                     "stream",
                                     Glib::unwrap (stream),
                                     "guid",
                                     Glib::c_str_or_nullptr (guid),
                                     "flags",
                                     flags,
                                     "authentication-observer",
                                     Glib::unwrap (observer),
                                     nullptr))
  {
    init (cancellable);
  }

  Connection::Connection (const Glib::RefPtr<IOStream>& stream,
                          const std::string& guid,
                          const Glib::RefPtr<Cancellable>& cancellable,
                          const ConnectionFlags flags)
    : ObjectBase (nullptr),
      Object (Glib::ConstructParams (connection_class_.init (),
                                     "stream",
                                     Glib::unwrap (stream),
                                     "guid",
                                     Glib::c_str_or_nullptr (guid),
                                     "flags",
                                     flags,
                                     "authentication-observer",
                                     nullptr,
                                     nullptr))
  {
    init (cancellable);
  }

  Connection::Connection (const Glib::RefPtr<IOStream>& stream,
                          const std::string& guid,
                          const Glib::RefPtr<AuthObserver>& observer,
                          const ConnectionFlags flags)
    : ObjectBase (nullptr),
      Object (Glib::ConstructParams (connection_class_.init (),
                                     "stream",
                                     Glib::unwrap (stream),
                                     "guid",
                                     Glib::c_str_or_nullptr (guid),
                                     "flags",
                                     flags,
                                     "authentication-observer",
                                     Glib::unwrap (observer),
                                     nullptr))
  {
    init ();
  }

  Connection::Connection (const Glib::RefPtr<IOStream>& stream,
                          const std::string& guid,
                          const ConnectionFlags flags)
    : ObjectBase (nullptr),
      Object (Glib::ConstructParams (connection_class_.init (),
                                     "stream",
                                     Glib::unwrap (stream),
                                     "guid",
                                     Glib::c_str_or_nullptr (guid),
                                     "flags",
                                     flags,
                                     "authentication-observer",
                                     nullptr,
                                     nullptr))
  {
    init ();
  }

  Connection::Connection (const std::string& address,
                          const Glib::RefPtr<AuthObserver>& observer,
                          const Glib::RefPtr<Cancellable>& cancellable,
                          const ConnectionFlags flags)
    : ObjectBase (nullptr),
      Object (Glib::ConstructParams (connection_class_.init (),
                                     "address",
                                     Glib::c_str_or_nullptr (address),
                                     "flags",
                                     flags,
                                     "authentication-observer",
                                     Glib::unwrap (observer),
                                     nullptr))
  {
    init (cancellable);
  }

  Connection::Connection (const std::string& address,
                          const Glib::RefPtr<Cancellable>& cancellable,
                          const ConnectionFlags flags)
    : ObjectBase (nullptr),
      Object (Glib::ConstructParams (connection_class_.init (),
                                     "address",
                                     Glib::c_str_or_nullptr (address),
                                     "flags",
                                     flags,
                                     "authentication-observer",
                                     nullptr,
                                     nullptr))
  {
    init (cancellable);
  }

  Connection::Connection (const std::string& address,
                          const Glib::RefPtr<AuthObserver>& observer,
                          const ConnectionFlags flags)
    : ObjectBase (nullptr),
      Object (Glib::ConstructParams (connection_class_.init (),
                                     "address",
                                     Glib::c_str_or_nullptr (address),
                                     "flags",
                                     flags,
                                     "authentication-observer",
                                     Glib::unwrap (observer),
                                     nullptr))
  {
    init ();
  }

  Connection::Connection (const std::string& address,
                          const ConnectionFlags flags)
    : ObjectBase (nullptr),
      Object (Glib::ConstructParams (connection_class_.init (),
                                     "address",
                                     Glib::c_str_or_nullptr (address),
                                     "flags",
                                     flags,
                                     "authentication-observer",
                                     nullptr,
                                     nullptr))
  {
    init ();
  }

  auto
  Connection::create (const Glib::RefPtr<IOStream>& stream,
                      const std::string& guid,
                      const Glib::RefPtr<AuthObserver>& observer,
                      const SlotAsyncReady& slot,
                      const Glib::RefPtr<Cancellable>& cancellable,
                      const ConnectionFlags flags) -> void
  {
    Connection (stream, guid, observer, slot, cancellable, flags);
  }

  auto
  Connection::create (const Glib::RefPtr<IOStream>& stream,
                      const std::string& guid,
                      const SlotAsyncReady& slot,
                      const Glib::RefPtr<Cancellable>& cancellable,
                      const ConnectionFlags flags) -> void
  {
    Connection (stream, guid, slot, cancellable, flags);
  }

  auto
  Connection::create (const Glib::RefPtr<IOStream>& stream,
                      const std::string& guid,
                      const Glib::RefPtr<AuthObserver>& observer,
                      const SlotAsyncReady& slot,
                      const ConnectionFlags flags) -> void
  {
    Connection (stream, guid, observer, slot, flags);
  }

  auto
  Connection::create (const Glib::RefPtr<IOStream>& stream,
                      const std::string& guid,
                      const SlotAsyncReady& slot,
                      const ConnectionFlags flags) -> void
  {
    Connection (stream, guid, slot, flags);
  }

  auto
  Connection::create_sync (const Glib::RefPtr<IOStream>& stream,
                           const std::string& guid,
                           const Glib::RefPtr<AuthObserver>& observer,
                           const Glib::RefPtr<Cancellable>& cancellable,
                           const ConnectionFlags flags) -> Glib::RefPtr<Connection>
  {
    return Glib::make_refptr_for_instance<Connection> (
        new Connection (stream, guid, observer, cancellable, flags));
  }

  auto
  Connection::create_sync (const Glib::RefPtr<IOStream>& stream,
                           const std::string& guid,
                           const Glib::RefPtr<Cancellable>& cancellable,
                           const ConnectionFlags flags) -> Glib::RefPtr<Connection>
  {
    return Glib::make_refptr_for_instance<Connection> (
        new Connection (stream, guid, cancellable, flags));
  }

  auto
  Connection::create_sync (const Glib::RefPtr<IOStream>& stream,
                           const std::string& guid,
                           const Glib::RefPtr<AuthObserver>& observer,
                           const ConnectionFlags flags) -> Glib::RefPtr<Connection>
  {
    return Glib::make_refptr_for_instance<Connection> (
        new Connection (stream, guid, observer, flags));
  }

  auto
  Connection::create_sync (const Glib::RefPtr<IOStream>& stream,
                           const std::string& guid,
                           const ConnectionFlags flags) -> Glib::RefPtr<Connection>
  {
    return Glib::make_refptr_for_instance<Connection> (
        new Connection (stream, guid, flags));
  }

  auto
  Connection::create_for_address (const std::string& address,
                                  const Glib::RefPtr<AuthObserver>& observer,
                                  const SlotAsyncReady& slot,
                                  const Glib::RefPtr<Cancellable>& cancellable,
                                  const ConnectionFlags flags) -> void
  {
    Connection (address, observer, slot, cancellable, flags);
  }

  auto
  Connection::create_for_address (const std::string& address,
                                  const SlotAsyncReady& slot,
                                  const Glib::RefPtr<Cancellable>& cancellable,
                                  const ConnectionFlags flags) -> void
  {
    Connection (address, slot, cancellable, flags);
  }

  auto
  Connection::create_for_address (const std::string& address,
                                  const Glib::RefPtr<AuthObserver>& observer,
                                  const SlotAsyncReady& slot,
                                  const ConnectionFlags flags) -> void
  {
    Connection (address, observer, slot, flags);
  }

  auto
  Connection::create_for_address (const std::string& address,
                                  const SlotAsyncReady& slot,
                                  const ConnectionFlags flags) -> void
  {
    Connection (address, slot, flags);
  }

  auto
  Connection::create_for_address_sync (
      const std::string& address,
      const Glib::RefPtr<AuthObserver>& observer,
      const Glib::RefPtr<Cancellable>& cancellable,
      const ConnectionFlags flags) -> Glib::RefPtr<Connection>
  {
    return Glib::make_refptr_for_instance<Connection> (
        new Connection (address, observer, cancellable, flags));
  }

  auto
  Connection::create_for_address_sync (
      const std::string& address,
      const Glib::RefPtr<Cancellable>& cancellable,
      const ConnectionFlags flags) -> Glib::RefPtr<Connection>
  {
    return Glib::make_refptr_for_instance<Connection> (
        new Connection (address, cancellable, flags));
  }

  auto
  Connection::create_for_address_sync (
      const std::string& address,
      const Glib::RefPtr<AuthObserver>& observer,
      const ConnectionFlags flags) -> Glib::RefPtr<Connection>
  {
    return Glib::make_refptr_for_instance<Connection> (
        new Connection (address, observer, flags));
  }

  auto
  Connection::create_for_address_sync (const std::string& address,
                                       const ConnectionFlags flags) -> Glib::RefPtr<Connection>
  {
    return Glib::make_refptr_for_instance<Connection> (
        new Connection (address, flags));
  }

  auto
  Connection::get (BusType bus_type,
                   const SlotAsyncReady& slot,
                   const Glib::RefPtr<Cancellable>& cancellable) -> void
  {
    const auto slot_copy = new SlotAsyncReady (slot);

    g_bus_get (static_cast<GBusType> (bus_type),
               Glib::unwrap (cancellable),
               &SignalProxy_async_callback,
               slot_copy);
  }

  auto
  Connection::get (BusType bus_type, const SlotAsyncReady& slot) -> void
  {
    const auto slot_copy = new SlotAsyncReady (slot);

    g_bus_get (static_cast<GBusType> (bus_type),
               nullptr,
               &SignalProxy_async_callback,
               slot_copy);
  }

  auto
  Connection::close () -> void
  {
    g_dbus_connection_close (gobj (), nullptr, nullptr, nullptr);
  }

  auto
  Connection::close (const SlotAsyncReady& slot,
                     const Glib::RefPtr<Cancellable>& cancellable) -> void
  {
    const auto slot_copy = new SlotAsyncReady (slot);

    g_dbus_connection_close (gobj (),
                             Glib::unwrap (cancellable),
                             &SignalProxy_async_callback,
                             slot_copy);
  }

  auto
  Connection::close (const SlotAsyncReady& slot) -> void
  {
    const auto slot_copy = new SlotAsyncReady (slot);

    g_dbus_connection_close (gobj (),
                             nullptr,
                             &SignalProxy_async_callback,
                             slot_copy);
  }

  auto
  Connection::flush () -> void
  {
    g_dbus_connection_flush (gobj (), nullptr, nullptr, nullptr);
  }

  auto
  Connection::flush (const SlotAsyncReady& slot,
                     const Glib::RefPtr<Cancellable>& cancellable) -> void
  {
    const auto slot_copy = new SlotAsyncReady (slot);

    g_dbus_connection_flush (gobj (),
                             Glib::unwrap (cancellable),
                             &SignalProxy_async_callback,
                             slot_copy);
  }

  auto
  Connection::flush (const SlotAsyncReady& slot) -> void
  {
    const auto slot_copy = new SlotAsyncReady (slot);

    g_dbus_connection_flush (gobj (),
                             nullptr,
                             &SignalProxy_async_callback,
                             slot_copy);
  }

  auto
  Connection::send_message (const Glib::RefPtr<Message>& message,
                            SendMessageFlags flags) -> bool
  {
    GError* gerror = nullptr;

    const bool result = g_dbus_connection_send_message (
        gobj (),
        Glib::unwrap (message),
        static_cast<GDBusSendMessageFlags> (flags),
        nullptr,
        &gerror);

    if (gerror)
      Glib::Error::throw_exception (gerror);

    return result;
  }

  auto
  Connection::send_message_with_reply (
      const Glib::RefPtr<Message>& message,
      const int timeout_msec,
      const SlotAsyncReady& slot,
      const Glib::RefPtr<Cancellable>& cancellable) -> void
  {
    const auto slot_copy = new SlotAsyncReady (slot);
    volatile guint32 out_serial = 0;
    g_dbus_connection_send_message_with_reply (
        gobj (),
        Glib::unwrap (message),
        static_cast<GDBusSendMessageFlags> (message->get_flags ()),
        timeout_msec,
        &out_serial,
        Glib::unwrap (cancellable),
        &SignalProxy_async_callback,
        slot_copy);
    message->set_serial (out_serial);
  }

  auto
  Connection::send_message_with_reply (const Glib::RefPtr<Message>& message,
                                       const int timeout_msec,
                                       const SlotAsyncReady& slot) -> void
  {
    const auto slot_copy = new SlotAsyncReady (slot);
    volatile guint32 out_serial = 0;
    g_dbus_connection_send_message_with_reply (
        gobj (),
        Glib::unwrap (message),
        static_cast<GDBusSendMessageFlags> (message->get_flags ()),
        timeout_msec,
        &out_serial,
        nullptr,
        &SignalProxy_async_callback,
        slot_copy);
    message->set_serial (out_serial);
  }

  auto
  Connection::send_message_with_reply_sync (
      const Glib::RefPtr<Message>& message,
      const Glib::RefPtr<Cancellable>& cancellable,
      const gint timeout_msec) -> Glib::RefPtr<Message>
  {
    volatile guint32 out_serial = 0;
    GError* gerror = nullptr;

    GDBusMessage* result = g_dbus_connection_send_message_with_reply_sync (
        gobj (),
        Glib::unwrap (message),
        static_cast<GDBusSendMessageFlags> (message->get_flags ()),
        timeout_msec,
        &out_serial,
        Glib::unwrap (cancellable),
        &gerror);

    if (gerror)
      Glib::Error::throw_exception (gerror);
    message->set_serial (out_serial);
    return Glib::wrap (result);
  }

  auto
  Connection::send_message_with_reply_sync (
      const Glib::RefPtr<Message>& message,
      const gint timeout_msec) -> Glib::RefPtr<Message>
  {
    volatile guint32 out_serial = 0;
    GError* gerror = nullptr;

    GDBusMessage* result = g_dbus_connection_send_message_with_reply_sync (
        gobj (),
        Glib::unwrap (message),
        static_cast<GDBusSendMessageFlags> (message->get_flags ()),
        timeout_msec,
        &out_serial,
        nullptr,
        &gerror);

    if (gerror)
      Glib::Error::throw_exception (gerror);
    message->set_serial (out_serial);
    return Glib::wrap (result);
  }

  auto
  Connection::call (const Glib::ustring& object_path,
                    const Glib::ustring& interface_name,
                    const Glib::ustring& method_name,
                    const Glib::VariantContainerBase& parameters,
                    const SlotAsyncReady& slot,
                    const Glib::RefPtr<Cancellable>& cancellable,
                    const Glib::ustring& bus_name,
                    const int timeout_msec,
                    CallFlags flags,
                    const Glib::VariantType& reply_type) -> void
  {
    const auto slot_copy = new SlotAsyncReady (slot);

    g_dbus_connection_call (gobj (),
                            c_str_or_nullptr (bus_name),
                            object_path.c_str (),
                            interface_name.c_str (),
                            method_name.c_str (),
                            const_cast<GVariant*> (parameters.gobj ()),
                            reply_type.gobj (),
                            static_cast<GDBusCallFlags> (flags),
                            timeout_msec,
                            Glib::unwrap (cancellable),
                            &SignalProxy_async_callback,
                            slot_copy);
  }

  auto
  Connection::call (const Glib::ustring& object_path,
                    const Glib::ustring& interface_name,
                    const Glib::ustring& method_name,
                    const Glib::VariantContainerBase& parameters,
                    const SlotAsyncReady& slot,
                    const Glib::ustring& bus_name,
                    const int timeout_msec,
                    CallFlags flags,
                    const Glib::VariantType& reply_type) -> void
  {
    const auto slot_copy = new SlotAsyncReady (slot);

    g_dbus_connection_call (gobj (),
                            c_str_or_nullptr (bus_name),
                            object_path.c_str (),
                            interface_name.c_str (),
                            method_name.c_str (),
                            const_cast<GVariant*> (parameters.gobj ()),
                            reply_type.gobj (),
                            static_cast<GDBusCallFlags> (flags),
                            timeout_msec,
                            nullptr,
                            &SignalProxy_async_callback,
                            slot_copy);
  }

  auto
  Connection::call_sync (const Glib::ustring& object_path,
                         const Glib::ustring& interface_name,
                         const Glib::ustring& method_name,
                         const Glib::VariantContainerBase& parameters,
                         const Glib::RefPtr<Cancellable>& cancellable,
                         const Glib::ustring& bus_name,
                         const int timeout_msec,
                         CallFlags flags,
                         const Glib::VariantType& reply_type) -> Glib::VariantContainerBase
  {
    GError* gerror = nullptr;

    GVariant* const gvariant = g_dbus_connection_call_sync (
        gobj (),
        c_str_or_nullptr (bus_name),
        object_path.c_str (),
        interface_name.c_str (),
        method_name.c_str (),
        const_cast<GVariant*> (parameters.gobj ()),
        reply_type.gobj (),
        static_cast<GDBusCallFlags> (flags),
        timeout_msec,
        Glib::unwrap (cancellable),
        &gerror);

    if (gerror)
      Glib::Error::throw_exception (gerror);

    return Glib::VariantContainerBase (gvariant, false);
  }

  auto
  Connection::call_sync (const Glib::ustring& object_path,
                         const Glib::ustring& interface_name,
                         const Glib::ustring& method_name,
                         const Glib::VariantContainerBase& parameters,
                         const Glib::ustring& bus_name,
                         const int timeout_msec,
                         CallFlags flags,
                         const Glib::VariantType& reply_type) -> Glib::VariantContainerBase
  {
    GError* gerror = nullptr;

    GVariant* const gvariant = g_dbus_connection_call_sync (
        gobj (),
        c_str_or_nullptr (bus_name),
        object_path.c_str (),
        interface_name.c_str (),
        method_name.c_str (),
        const_cast<GVariant*> (parameters.gobj ()),
        reply_type.gobj (),
        static_cast<GDBusCallFlags> (flags),
        timeout_msec,
        nullptr,
        &gerror);

    if (gerror)
      Glib::Error::throw_exception (gerror);

    return Glib::VariantContainerBase (gvariant, false);
  }

#ifdef G_OS_UNIX

  void
  Connection::call (const Glib::ustring& object_path,
                    const Glib::ustring& interface_name,
                    const Glib::ustring& method_name,
                    const Glib::VariantContainerBase& parameters,
                    const SlotAsyncReady& slot,
                    const Glib::RefPtr<Cancellable>& cancellable,
                    const Glib::RefPtr<UnixFDList>& fd_list,
                    const Glib::ustring& bus_name,
                    int timeout_msec,
                    CallFlags flags,
                    const Glib::VariantType& reply_type)
  {
    auto slot_copy = new SlotAsyncReady (slot);

    g_dbus_connection_call_with_unix_fd_list (
        gobj (),
        Glib::c_str_or_nullptr (bus_name),
        object_path.c_str (),
        interface_name.c_str (),
        method_name.c_str (),
        const_cast<GVariant*> (parameters.gobj ()),
        reply_type.gobj (),
        static_cast<GDBusCallFlags> (flags),
        timeout_msec,
        Glib::unwrap (fd_list),
        Glib::unwrap (cancellable),
        &SignalProxy_async_callback,
        slot_copy);
  }

  void
  Connection::call (const Glib::ustring& object_path,
                    const Glib::ustring& interface_name,
                    const Glib::ustring& method_name,
                    const Glib::VariantContainerBase& parameters,
                    const SlotAsyncReady& slot,
                    const Glib::RefPtr<UnixFDList>& fd_list,
                    const Glib::ustring& bus_name,
                    int timeout_msec,
                    CallFlags flags,
                    const Glib::VariantType& reply_type)
  {
    auto slot_copy = new SlotAsyncReady (slot);

    g_dbus_connection_call_with_unix_fd_list (
        gobj (),
        Glib::c_str_or_nullptr (bus_name),
        object_path.c_str (),
        interface_name.c_str (),
        method_name.c_str (),
        const_cast<GVariant*> (parameters.gobj ()),
        reply_type.gobj (),
        static_cast<GDBusCallFlags> (flags),
        timeout_msec,
        Glib::unwrap (fd_list),
        nullptr,
        &SignalProxy_async_callback,
        slot_copy);
  }
#endif

  auto
  Connection::emit_signal (const Glib::ustring& object_path,
                           const Glib::ustring& interface_name,
                           const Glib::ustring& signal_name,
                           const Glib::ustring& destination_bus_name,
                           const Glib::VariantContainerBase& parameters) -> void
  {
    GError* gerror = nullptr;

    g_dbus_connection_emit_signal (gobj (),
                                   c_str_or_nullptr (destination_bus_name),
                                   object_path.c_str (),
                                   interface_name.c_str (),
                                   signal_name.c_str (),
                                   const_cast<GVariant*> (parameters.gobj ()),
                                   &gerror);

    if (gerror)
      Glib::Error::throw_exception (gerror);
  }

  auto
  Connection::signal_subscribe (const SlotSignal& slot,
                                const Glib::ustring& sender,
                                const Glib::ustring& interface_name,
                                const Glib::ustring& member,
                                const Glib::ustring& object_path,
                                const Glib::ustring& arg0,
                                SignalFlags flags) -> guint
  {
    const auto slot_copy = new SlotSignal (slot);

    return g_dbus_connection_signal_subscribe (
        gobj (),
        c_str_or_nullptr (sender),
        c_str_or_nullptr (interface_name),
        c_str_or_nullptr (member),
        c_str_or_nullptr (object_path),
        c_str_or_nullptr (arg0),
        static_cast<GDBusSignalFlags> (flags),
        &DBusConnection_Signal_giomm_callback,
        slot_copy,
        &DBusConnection_Signal_giomm_callback_destroy);
  }

  auto
  Connection::add_filter (const SlotMessageFilter& slot) -> guint
  {
    const auto slot_copy = new SlotMessageFilter (slot);

    return g_dbus_connection_add_filter (
        gobj (),
        &DBusConnection_Message_Filter_giomm_callback,
        slot_copy,
        DBusConnection_Message_Filter_giomm_callback_destroy);
  }

  auto
  Connection::register_object (
      const Glib::ustring& object_path,
      const Glib::RefPtr<InterfaceInfo>& interface_info,
      const InterfaceVTable& vtable) -> guint
  {
    GError* gerror = nullptr;

    const guint result = g_dbus_connection_register_object (
        gobj (),
        object_path.c_str (),
        Glib::unwrap (interface_info),
        vtable.gobj (),
        const_cast<InterfaceVTable*> (&vtable),
        nullptr,
        &gerror);

    if (gerror)
      Glib::Error::throw_exception (gerror);

    return result;
  }

  auto
  Connection::register_object (
      const Glib::ustring& object_path,
      const Glib::RefPtr<InterfaceInfo>& interface_info) -> guint
  {
    GError* gerror = nullptr;

    const guint result = g_dbus_connection_register_object (
        gobj (),
        object_path.c_str (),
        Glib::unwrap (interface_info),
        nullptr,
        nullptr,
        nullptr,
        &gerror);

    if (gerror)
      Glib::Error::throw_exception (gerror);

    return result;
  }

  auto
  Connection::register_subtree (const Glib::ustring& object_path,
                                const SubtreeVTable& vtable,
                                SubtreeFlags flags) -> guint
  {
    GError* gerror = nullptr;

    const guint result = g_dbus_connection_register_subtree (
        gobj (),
        object_path.c_str (),
        vtable.gobj (),
        static_cast<GDBusSubtreeFlags> (flags),
        const_cast<SubtreeVTable*> (&vtable),
        nullptr,
        &gerror);

    if (gerror)
      Glib::Error::throw_exception (gerror);

    return result;
  }

} // namespace Gio::DBus

namespace Glib
{

  auto
  wrap (GDBusConnection* object, const bool take_copy) -> RefPtr<Gio::DBus::Connection>
  {
    ObjectBase* pCppObject = nullptr;
    if (!ObjectBase::_get_current_wrapper ((GObject*) object))
    {
      std::lock_guard<std::mutex> lock (wrap_mutex);
      pCppObject = wrap_auto ((GObject*) object, take_copy);
    }
    else
      pCppObject = wrap_auto ((GObject*) object, take_copy);

    return Glib::make_refptr_for_instance<Gio::DBus::Connection> (
        dynamic_cast<Gio::DBus::Connection*> (pCppObject));
  }

} // namespace Glib

namespace
{

  auto
  Connection_signal_closed_callback (GDBusConnection* self,
                                     const gboolean p0,
                                     GError* p1,
                                     void* data) -> void
  {
    using namespace Gio::DBus;
    using SlotType = sigc::slot<void (bool, const Glib::Error&)>;

    const auto obj = dynamic_cast<Connection*> (
        Glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj)
    {
      try
      {
        if (const auto slot = Glib::SignalProxyNormal::data_to_slot (data))
          (*static_cast<SlotType*> (slot)) (p0, Glib::Error (p1, true));
      }
      catch (...)
      {
        Glib::exception_handlers_invoke ();
      }
    }
  }

  const Glib::SignalProxyInfo Connection_signal_closed_info = {
      "closed",
      (GCallback) &Connection_signal_closed_callback,
      (GCallback) &Connection_signal_closed_callback};

} // namespace

auto
Glib::Value<Gio::DBus::BusType>::value_type () -> GType
{
  return g_bus_type_get_type ();
}

auto
Glib::Value<Gio::DBus::ConnectionFlags>::value_type () -> GType
{
  return g_dbus_connection_flags_get_type ();
}

namespace Gio::DBus
{

  auto
  Connection_Class::init () -> const Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &Connection_Class::class_init_function;

      register_derived_type (g_dbus_connection_get_type ());

      Initable::add_interface (get_type ());
      AsyncInitable::add_interface (get_type ());
    }

    return *this;
  }

  auto
  Connection_Class::class_init_function (void* g_class, void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);
  }

  auto
  Connection_Class::wrap_new (GObject* object) -> Glib::ObjectBase*
  {
    return new Connection ((GDBusConnection*) object);
  }

  auto
  Connection::gobj_copy () -> GDBusConnection*
  {
    reference ();
    return gobj ();
  }

  Connection::Connection (const Glib::ConstructParams& construct_params)
    : Object (construct_params)
  {
  }

  Connection::Connection (GDBusConnection* castitem)
    : Object ((GObject*) castitem)
  {
  }

  Connection::Connection (Connection&& src) noexcept
    : Object (std::move (src)),
      Initable (std::move (src)),
      AsyncInitable (std::move (src))
  {
  }

  auto
  Connection::operator= (Connection&& src) noexcept -> Connection&
  {
    Object::operator= (std::move (src));
    Initable::operator= (std::move (src));
    AsyncInitable::operator= (std::move (src));
    return *this;
  }

  Connection::~Connection () noexcept = default;

  Connection::CppClassType Connection::connection_class_;

  auto
  Connection::get_type () -> GType
  {
    return connection_class_.init ().get_type ();
  }

  auto
  Connection::get_base_type () -> GType
  {
    return g_dbus_connection_get_type ();
  }

  auto
  Connection::get_finish (const Glib::RefPtr<AsyncResult>& res) -> Glib::RefPtr<Connection>
  {
    GError* gerror = nullptr;
    auto retvalue = Glib::wrap (g_bus_get_finish (Glib::unwrap (res), &gerror));
    if (gerror)
      Glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  Connection::get_sync (BusType bus_type,
                        const Glib::RefPtr<Cancellable>& cancellable) -> Glib::RefPtr<Connection>
  {
    GError* gerror = nullptr;
    auto retvalue =
        Glib::wrap (g_bus_get_sync (static_cast<GBusType> (bus_type),
                                    Glib::unwrap (cancellable),
                                    &gerror));
    if (gerror)
      Glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  Connection::get_sync (BusType bus_type) -> Glib::RefPtr<Connection>
  {
    GError* gerror = nullptr;
    auto retvalue = Glib::wrap (
        g_bus_get_sync (static_cast<GBusType> (bus_type), nullptr, &gerror));
    if (gerror)
      Glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  Connection::create_finish (const Glib::RefPtr<AsyncResult>& res) -> Glib::RefPtr<Connection>
  {
    GError* gerror = nullptr;
    auto retvalue =
        Glib::wrap (g_dbus_connection_new_finish (Glib::unwrap (res), &gerror));
    if (gerror)
      Glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  Connection::create_for_address_finish (const Glib::RefPtr<AsyncResult>& res) -> Glib::RefPtr<Connection>
  {
    GError* gerror = nullptr;
    auto retvalue = Glib::wrap (
        g_dbus_connection_new_for_address_finish (Glib::unwrap (res), &gerror));
    if (gerror)
      Glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  Connection::close_finish (const Glib::RefPtr<AsyncResult>& res) -> bool
  {
    GError* gerror = nullptr;
    const auto retvalue =
        g_dbus_connection_close_finish (gobj (), Glib::unwrap (res), &gerror);
    if (gerror)
      Glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  Connection::close_sync (const Glib::RefPtr<Cancellable>& cancellable) -> void
  {
    GError* gerror = nullptr;
    g_dbus_connection_close_sync (gobj (), Glib::unwrap (cancellable), &gerror);
    if (gerror)
      Glib::Error::throw_exception (gerror);
  }

  auto
  Connection::close_sync () -> void
  {
    GError* gerror = nullptr;
    g_dbus_connection_close_sync (gobj (), nullptr, &gerror);
    if (gerror)
      Glib::Error::throw_exception (gerror);
  }

  auto
  Connection::flush_finish (const Glib::RefPtr<AsyncResult>& res) -> bool
  {
    GError* gerror = nullptr;
    const auto retvalue =
        g_dbus_connection_flush_finish (gobj (), Glib::unwrap (res), &gerror);
    if (gerror)
      Glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  Connection::flush_sync (const Glib::RefPtr<Cancellable>& cancellable) -> void
  {
    GError* gerror = nullptr;
    g_dbus_connection_flush_sync (gobj (), Glib::unwrap (cancellable), &gerror);
    if (gerror)
      Glib::Error::throw_exception (gerror);
  }

  auto
  Connection::flush_sync () -> void
  {
    GError* gerror = nullptr;
    g_dbus_connection_flush_sync (gobj (), nullptr, &gerror);
    if (gerror)
      Glib::Error::throw_exception (gerror);
  }

  auto
  Connection::get_exit_on_close () const -> bool
  {
    return g_dbus_connection_get_exit_on_close (
        const_cast<GDBusConnection*> (gobj ()));
  }

  auto
  Connection::set_exit_on_close (const bool exit_on_close) -> void
  {
    g_dbus_connection_set_exit_on_close (gobj (), exit_on_close);
  }

  auto
  Connection::send_message (const Glib::RefPtr<Message>& message,
                            SendMessageFlags flags,
                            guint32& out_serial) -> bool
  {
    GError* gerror = nullptr;
    const auto retvalue = g_dbus_connection_send_message (
        gobj (),
        Glib::unwrap (message),
        static_cast<GDBusSendMessageFlags> (flags),
        &out_serial,
        &gerror);
    if (gerror)
      Glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  Connection::send_message_with_reply_finish (
      const Glib::RefPtr<AsyncResult>& res) -> Glib::RefPtr<Message>
  {
    GError* gerror = nullptr;
    auto retvalue = Glib::wrap (
        g_dbus_connection_send_message_with_reply_finish (gobj (),
                                                          Glib::unwrap (res),
                                                          &gerror));
    if (gerror)
      Glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  Connection::start_message_processing () -> void
  {
    g_dbus_connection_start_message_processing (gobj ());
  }

  auto
  Connection::is_closed () const -> bool
  {
    return g_dbus_connection_is_closed (const_cast<GDBusConnection*> (gobj ()));
  }

  auto
  Connection::get_stream () -> Glib::RefPtr<IOStream>
  {
    auto retvalue = Glib::wrap (g_dbus_connection_get_stream (gobj ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  Connection::get_stream () const -> Glib::RefPtr<const IOStream>
  {
    return const_cast<Connection*> (this)->get_stream ();
  }

  auto
  Connection::get_guid () const -> std::string
  {
    return Glib::convert_const_gchar_ptr_to_stdstring (
        g_dbus_connection_get_guid (const_cast<GDBusConnection*> (gobj ())));
  }

  auto
  Connection::get_unique_name () const -> Glib::ustring
  {
    return Glib::convert_const_gchar_ptr_to_ustring (
        g_dbus_connection_get_unique_name (
            const_cast<GDBusConnection*> (gobj ())));
  }

  auto
  Connection::get_capabilities () const -> CapabilityFlags
  {
    return static_cast<CapabilityFlags> (g_dbus_connection_get_capabilities (
        const_cast<GDBusConnection*> (gobj ())));
  }

  auto
  Connection::get_flags () const -> ConnectionFlags
  {
    return static_cast<ConnectionFlags> (
        g_dbus_connection_get_flags (const_cast<GDBusConnection*> (gobj ())));
  }

  auto
  Connection::get_peer_credentials () -> Glib::RefPtr<Credentials>
  {
    auto retvalue =
        Glib::wrap (g_dbus_connection_get_peer_credentials (gobj ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  Connection::get_peer_credentials () const -> Glib::RefPtr<const Credentials>
  {
    return const_cast<Connection*> (this)->get_peer_credentials ();
  }

  auto
  Connection::get_last_serial () const -> guint32
  {
    return g_dbus_connection_get_last_serial (
        const_cast<GDBusConnection*> (gobj ()));
  }

  auto
  Connection::call_finish (const Glib::RefPtr<AsyncResult>& res) -> Glib::VariantContainerBase
  {
    GError* gerror = nullptr;
    auto retvalue = Glib::VariantContainerBase (
        g_dbus_connection_call_finish (gobj (), Glib::unwrap (res), &gerror),
        false);
    if (gerror)
      Glib::Error::throw_exception (gerror);
    return retvalue;
  }

#ifdef G_OS_UNIX
  auto
  Connection::call_finish (const Glib::RefPtr<AsyncResult>& res,
                           Glib::RefPtr<UnixFDList>& out_fd_list) -> Glib::VariantContainerBase
  {
    GError* gerror = nullptr;
    GUnixFDList* g_out_fd_list = nullptr;
    auto retvalue = Glib::VariantContainerBase (
        g_dbus_connection_call_with_unix_fd_list_finish (gobj (),
                                                         &g_out_fd_list,
                                                         Glib::unwrap (res),
                                                         &(gerror)),
        false);
    if (gerror)
      ::Glib::Error::throw_exception (gerror);
    out_fd_list = Glib::wrap (g_out_fd_list);
    return retvalue;
  }
#endif

#ifdef G_OS_UNIX
  auto
  Connection::call_sync (const Glib::ustring& object_path,
                         const Glib::ustring& interface_name,
                         const Glib::ustring& method_name,
                         const Glib::VariantContainerBase& parameters,
                         const Glib::RefPtr<Cancellable>& cancellable,
                         const Glib::RefPtr<UnixFDList>& fd_list,
                         Glib::RefPtr<UnixFDList>& out_fd_list,
                         const Glib::ustring& bus_name,
                         int timeout_msec,
                         CallFlags flags,
                         const Glib::VariantType& reply_type) -> Glib::VariantContainerBase
  {
    GError* gerror = nullptr;
    GUnixFDList* g_out_fd_list = nullptr;
    auto retvalue = Glib::VariantContainerBase (
        g_dbus_connection_call_with_unix_fd_list_sync (
            gobj (),
            bus_name.empty () ? nullptr : bus_name.c_str (),
            object_path.c_str (),
            interface_name.c_str (),
            method_name.c_str (),
            const_cast<GVariant*> ((parameters).gobj ()),
            (reply_type).gobj (),
            static_cast<GDBusCallFlags> (flags),
            timeout_msec,
            Glib::unwrap (fd_list),
            &g_out_fd_list,
            const_cast<GCancellable*> (Glib::unwrap (cancellable)),
            &(gerror)),
        false);
    if (gerror)
      ::Glib::Error::throw_exception (gerror);
    out_fd_list = Glib::wrap (g_out_fd_list);
    return retvalue;
  }
#endif

#ifdef G_OS_UNIX
  auto
  Connection::call_sync (const Glib::ustring& object_path,
                         const Glib::ustring& interface_name,
                         const Glib::ustring& method_name,
                         const Glib::VariantContainerBase& parameters,
                         const Glib::RefPtr<UnixFDList>& fd_list,
                         Glib::RefPtr<UnixFDList>& out_fd_list,
                         const Glib::ustring& bus_name,
                         int timeout_msec,
                         CallFlags flags,
                         const Glib::VariantType& reply_type) -> Glib::VariantContainerBase
  {
    GError* gerror = nullptr;
    GUnixFDList* g_out_fd_list = nullptr;
    auto retvalue = Glib::VariantContainerBase (
        g_dbus_connection_call_with_unix_fd_list_sync (
            gobj (),
            bus_name.empty () ? nullptr : bus_name.c_str (),
            object_path.c_str (),
            interface_name.c_str (),
            method_name.c_str (),
            const_cast<GVariant*> ((parameters).gobj ()),
            (reply_type).gobj (),
            static_cast<GDBusCallFlags> (flags),
            timeout_msec,
            Glib::unwrap (fd_list),
            &g_out_fd_list,
            nullptr,
            &(gerror)),
        false);
    if (gerror)
      ::Glib::Error::throw_exception (gerror);
    out_fd_list = Glib::wrap (g_out_fd_list);
    return retvalue;
  }
#endif

  auto
  Connection::signal_unsubscribe (const guint subscription_id) -> void
  {
    g_dbus_connection_signal_unsubscribe (gobj (), subscription_id);
  }

  auto
  Connection::remove_filter (const guint filter_id) -> void
  {
    g_dbus_connection_remove_filter (gobj (), filter_id);
  }

  auto
  Connection::unregister_object (const guint registration_id) -> bool
  {
    return g_dbus_connection_unregister_object (gobj (), registration_id);
  }

  auto
  Connection::unregister_subtree (const guint registration_id) -> bool
  {
    return g_dbus_connection_unregister_subtree (gobj (), registration_id);
  }

  auto
  Connection::export_action_group (
      const Glib::ustring& object_path,
      const Glib::RefPtr<ActionGroup>& action_group) -> guint
  {
    GError* gerror = nullptr;
    const auto retvalue = g_dbus_connection_export_action_group (
        gobj (),
        object_path.c_str (),
        Glib::unwrap (action_group),
        &gerror);
    if (gerror)
      Glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  Connection::unexport_action_group (const guint export_id) -> void
  {
    g_dbus_connection_unexport_action_group (gobj (), export_id);
  }

  auto
  Connection::export_menu_model (const Glib::ustring& object_path,
                                 const Glib::RefPtr<MenuModel>& menu) -> guint
  {
    GError* gerror = nullptr;
    const auto retvalue = g_dbus_connection_export_menu_model (
        gobj (),
        object_path.c_str (),
        Glib::unwrap (menu),
        &gerror);
    if (gerror)
      Glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  Connection::unexport_menu_model (const guint export_id) -> void
  {
    g_dbus_connection_unexport_menu_model (gobj (), export_id);
  }

  auto
  Connection::signal_closed () -> Glib::SignalProxy<void (bool, const Glib::Error&)>
  {
    return {this, &Connection_signal_closed_info};
  }

  static_assert (
      Glib::Traits::ValueCompatibleWithWrapProperty<CapabilityFlags>::value,
      "Type CapabilityFlags cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  auto
  Connection::property_capabilities () const -> Glib::PropertyProxy_ReadOnly<CapabilityFlags>
  {
    return {this, "capabilities"};
  }

  auto
  Connection::property_closed () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return {this, "closed"};
  }

  auto
  Connection::property_exit_on_close () -> Glib::PropertyProxy<bool>
  {
    return {this, "exit-on-close"};
  }

  auto
  Connection::property_exit_on_close () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return {this, "exit-on-close"};
  }

  static_assert (
      Glib::Traits::ValueCompatibleWithWrapProperty<ConnectionFlags>::value,
      "Type ConnectionFlags cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  auto
  Connection::property_flags () const -> Glib::PropertyProxy_ReadOnly<ConnectionFlags>
  {
    return {this, "flags"};
  }

  auto
  Connection::property_guid () const -> Glib::PropertyProxy_ReadOnly<std::string>
  {
    return {this, "guid"};
  }

  static_assert (
      Glib::Traits::ValueCompatibleWithWrapProperty<
          Glib::RefPtr<IOStream>>::value,
      "Type Glib::RefPtr<IOStream> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  auto
  Connection::property_stream () const -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<IOStream>>
  {
    return {this, "stream"};
  }

  auto
  Connection::property_unique_name () const -> Glib::PropertyProxy_ReadOnly<Glib::ustring>
  {
    return {this, "unique-name"};
  }

} // namespace Gio::DBus
