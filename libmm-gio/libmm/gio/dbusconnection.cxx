// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/gio/dbusconnection.hxx>
#include <libmm/gio/dbusconnection_p.hxx>

#include <gio/gio.h>
#include <libmm/gio/actiongroup.hxx>
#include <libmm/gio/dbusauthobserver.hxx>
#include <libmm/gio/dbuserror.hxx>
#include <libmm/gio/dbusintrospection.hxx>
#include <libmm/gio/dbusmethodinvocation.hxx>
#include <libmm/gio/menumodel.hxx>
#include <libmm/glib/exceptionhandler.hxx>

#ifdef G_OS_UNIX
  #include <libmm/gio/unixfdlist.hxx>
#endif

#include <libmm/gio/slot_async.hxx>
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
      const gio::DBus::Connection::SlotSignal* the_slot =
          static_cast<gio::DBus::Connection::SlotSignal*> (user_data);

      try
      {
        (*the_slot) (glib::wrap (connection, true),
                     sender_name ? sender_name : "",
                     object_path ? object_path : "",
                     interface_name ? interface_name : "",
                     signal_name ? signal_name : "",
                     glib::VariantContainerBase (parameters, true));
      }
      catch (...)
      {
        glib::exception_handlers_invoke ();
      }
    }

    static auto
    DBusConnection_Signal_giomm_callback_destroy (void* data) -> void
    {
      delete static_cast<gio::DBus::Connection::SlotSignal*> (data);
    }

    static auto
    DBusConnection_Message_Filter_giomm_callback (GDBusConnection* connection,
                                                  GDBusMessage* message,
                                                  const gboolean incoming,
                                                  void* user_data)
        -> GDBusMessage*
    {
      const gio::DBus::Connection::SlotMessageFilter* the_slot =
          static_cast<gio::DBus::Connection::SlotMessageFilter*> (user_data);

      try
      {
        const auto result = (*the_slot) (glib::wrap (connection, true),
                                         glib::wrap (message, true),
                                         static_cast<bool> (incoming));
        return result ? result->gobj_copy () : nullptr;
      }
      catch (...)
      {
        glib::exception_handlers_invoke ();
      }

      return message;
    }

    static auto
    DBusConnection_Message_Filter_giomm_callback_destroy (void* data) -> void
    {
      delete static_cast<gio::DBus::Connection::SlotMessageFilter*> (data);
    }
  }

  std::mutex wrap_mutex;

} // namespace

namespace gio::DBus
{

  Connection::Connection (const glib::RefPtr<IOStream>& stream,
                          const std::string& guid,
                          const glib::RefPtr<AuthObserver>& observer,
                          const SlotAsyncReady& slot,
                          const glib::RefPtr<Cancellable>& cancellable,
                          const ConnectionFlags flags)
    : ObjectBase (nullptr),
      Object (glib::ConstructParams (connection_class_.init (),
                                     "stream",
                                     glib::unwrap (stream),
                                     "guid",
                                     glib::c_str_or_nullptr (guid),
                                     "flags",
                                     flags,
                                     "authentication-observer",
                                     glib::unwrap (observer),
                                     nullptr))
  {
    init_async (slot, cancellable);
  }

  Connection::Connection (const glib::RefPtr<IOStream>& stream,
                          const std::string& guid,
                          const SlotAsyncReady& slot,
                          const glib::RefPtr<Cancellable>& cancellable,
                          const ConnectionFlags flags)
    : ObjectBase (nullptr),
      Object (glib::ConstructParams (connection_class_.init (),
                                     "stream",
                                     glib::unwrap (stream),
                                     "guid",
                                     glib::c_str_or_nullptr (guid),
                                     "flags",
                                     flags,
                                     "authentication-observer",
                                     nullptr,
                                     nullptr))
  {
    init_async (slot, cancellable);
  }

  Connection::Connection (const glib::RefPtr<IOStream>& stream,
                          const std::string& guid,
                          const glib::RefPtr<AuthObserver>& observer,
                          const SlotAsyncReady& slot,
                          const ConnectionFlags flags)
    : ObjectBase (nullptr),
      Object (glib::ConstructParams (connection_class_.init (),
                                     "stream",
                                     glib::unwrap (stream),
                                     "guid",
                                     glib::c_str_or_nullptr (guid),
                                     "flags",
                                     flags,
                                     "authentication-observer",
                                     glib::unwrap (observer),
                                     nullptr))
  {
    init_async (slot);
  }

  Connection::Connection (const glib::RefPtr<IOStream>& stream,
                          const std::string& guid,
                          const SlotAsyncReady& slot,
                          const ConnectionFlags flags)
    : ObjectBase (nullptr),
      Object (glib::ConstructParams (connection_class_.init (),
                                     "stream",
                                     glib::unwrap (stream),
                                     "guid",
                                     glib::c_str_or_nullptr (guid),
                                     "flags",
                                     flags,
                                     "authentication-observer",
                                     nullptr,
                                     nullptr))
  {
    init_async (slot);
  }

  Connection::Connection (const std::string& address,
                          const glib::RefPtr<AuthObserver>& observer,
                          const SlotAsyncReady& slot,
                          const glib::RefPtr<Cancellable>& cancellable,
                          const ConnectionFlags flags)
    : ObjectBase (nullptr),
      Object (glib::ConstructParams (connection_class_.init (),
                                     "address",
                                     glib::c_str_or_nullptr (address),
                                     "flags",
                                     flags,
                                     "authentication-observer",
                                     glib::unwrap (observer),
                                     nullptr))
  {
    init_async (slot, cancellable);
  }

  Connection::Connection (const std::string& address,
                          const SlotAsyncReady& slot,
                          const glib::RefPtr<Cancellable>& cancellable,
                          const ConnectionFlags flags)
    : ObjectBase (nullptr),
      Object (glib::ConstructParams (connection_class_.init (),
                                     "address",
                                     glib::c_str_or_nullptr (address),
                                     "flags",
                                     flags,
                                     "authentication-observer",
                                     nullptr,
                                     nullptr))
  {
    init_async (slot, cancellable);
  }

  Connection::Connection (const std::string& address,
                          const glib::RefPtr<AuthObserver>& observer,
                          const SlotAsyncReady& slot,
                          const ConnectionFlags flags)
    : ObjectBase (nullptr),
      Object (glib::ConstructParams (connection_class_.init (),
                                     "address",
                                     glib::c_str_or_nullptr (address),
                                     "flags",
                                     flags,
                                     "authentication-observer",
                                     glib::unwrap (observer),
                                     nullptr))
  {
    init_async (slot);
  }

  Connection::Connection (const std::string& address,
                          const SlotAsyncReady& slot,
                          const ConnectionFlags flags)
    : ObjectBase (nullptr),
      Object (glib::ConstructParams (connection_class_.init (),
                                     "address",
                                     glib::c_str_or_nullptr (address),
                                     "flags",
                                     flags,
                                     "authentication-observer",
                                     nullptr,
                                     nullptr))
  {
    init_async (slot);
  }

  Connection::Connection (const glib::RefPtr<IOStream>& stream,
                          const std::string& guid,
                          const glib::RefPtr<AuthObserver>& observer,
                          const glib::RefPtr<Cancellable>& cancellable,
                          const ConnectionFlags flags)
    : ObjectBase (nullptr),
      Object (glib::ConstructParams (connection_class_.init (),
                                     "stream",
                                     glib::unwrap (stream),
                                     "guid",
                                     glib::c_str_or_nullptr (guid),
                                     "flags",
                                     flags,
                                     "authentication-observer",
                                     glib::unwrap (observer),
                                     nullptr))
  {
    init (cancellable);
  }

  Connection::Connection (const glib::RefPtr<IOStream>& stream,
                          const std::string& guid,
                          const glib::RefPtr<Cancellable>& cancellable,
                          const ConnectionFlags flags)
    : ObjectBase (nullptr),
      Object (glib::ConstructParams (connection_class_.init (),
                                     "stream",
                                     glib::unwrap (stream),
                                     "guid",
                                     glib::c_str_or_nullptr (guid),
                                     "flags",
                                     flags,
                                     "authentication-observer",
                                     nullptr,
                                     nullptr))
  {
    init (cancellable);
  }

  Connection::Connection (const glib::RefPtr<IOStream>& stream,
                          const std::string& guid,
                          const glib::RefPtr<AuthObserver>& observer,
                          const ConnectionFlags flags)
    : ObjectBase (nullptr),
      Object (glib::ConstructParams (connection_class_.init (),
                                     "stream",
                                     glib::unwrap (stream),
                                     "guid",
                                     glib::c_str_or_nullptr (guid),
                                     "flags",
                                     flags,
                                     "authentication-observer",
                                     glib::unwrap (observer),
                                     nullptr))
  {
    init ();
  }

  Connection::Connection (const glib::RefPtr<IOStream>& stream,
                          const std::string& guid,
                          const ConnectionFlags flags)
    : ObjectBase (nullptr),
      Object (glib::ConstructParams (connection_class_.init (),
                                     "stream",
                                     glib::unwrap (stream),
                                     "guid",
                                     glib::c_str_or_nullptr (guid),
                                     "flags",
                                     flags,
                                     "authentication-observer",
                                     nullptr,
                                     nullptr))
  {
    init ();
  }

  Connection::Connection (const std::string& address,
                          const glib::RefPtr<AuthObserver>& observer,
                          const glib::RefPtr<Cancellable>& cancellable,
                          const ConnectionFlags flags)
    : ObjectBase (nullptr),
      Object (glib::ConstructParams (connection_class_.init (),
                                     "address",
                                     glib::c_str_or_nullptr (address),
                                     "flags",
                                     flags,
                                     "authentication-observer",
                                     glib::unwrap (observer),
                                     nullptr))
  {
    init (cancellable);
  }

  Connection::Connection (const std::string& address,
                          const glib::RefPtr<Cancellable>& cancellable,
                          const ConnectionFlags flags)
    : ObjectBase (nullptr),
      Object (glib::ConstructParams (connection_class_.init (),
                                     "address",
                                     glib::c_str_or_nullptr (address),
                                     "flags",
                                     flags,
                                     "authentication-observer",
                                     nullptr,
                                     nullptr))
  {
    init (cancellable);
  }

  Connection::Connection (const std::string& address,
                          const glib::RefPtr<AuthObserver>& observer,
                          const ConnectionFlags flags)
    : ObjectBase (nullptr),
      Object (glib::ConstructParams (connection_class_.init (),
                                     "address",
                                     glib::c_str_or_nullptr (address),
                                     "flags",
                                     flags,
                                     "authentication-observer",
                                     glib::unwrap (observer),
                                     nullptr))
  {
    init ();
  }

  Connection::Connection (const std::string& address,
                          const ConnectionFlags flags)
    : ObjectBase (nullptr),
      Object (glib::ConstructParams (connection_class_.init (),
                                     "address",
                                     glib::c_str_or_nullptr (address),
                                     "flags",
                                     flags,
                                     "authentication-observer",
                                     nullptr,
                                     nullptr))
  {
    init ();
  }

  auto
  Connection::create (const glib::RefPtr<IOStream>& stream,
                      const std::string& guid,
                      const glib::RefPtr<AuthObserver>& observer,
                      const SlotAsyncReady& slot,
                      const glib::RefPtr<Cancellable>& cancellable,
                      const ConnectionFlags flags) -> void
  {
    Connection (stream, guid, observer, slot, cancellable, flags);
  }

  auto
  Connection::create (const glib::RefPtr<IOStream>& stream,
                      const std::string& guid,
                      const SlotAsyncReady& slot,
                      const glib::RefPtr<Cancellable>& cancellable,
                      const ConnectionFlags flags) -> void
  {
    Connection (stream, guid, slot, cancellable, flags);
  }

  auto
  Connection::create (const glib::RefPtr<IOStream>& stream,
                      const std::string& guid,
                      const glib::RefPtr<AuthObserver>& observer,
                      const SlotAsyncReady& slot,
                      const ConnectionFlags flags) -> void
  {
    Connection (stream, guid, observer, slot, flags);
  }

  auto
  Connection::create (const glib::RefPtr<IOStream>& stream,
                      const std::string& guid,
                      const SlotAsyncReady& slot,
                      const ConnectionFlags flags) -> void
  {
    Connection (stream, guid, slot, flags);
  }

  auto
  Connection::create_sync (const glib::RefPtr<IOStream>& stream,
                           const std::string& guid,
                           const glib::RefPtr<AuthObserver>& observer,
                           const glib::RefPtr<Cancellable>& cancellable,
                           const ConnectionFlags flags) -> glib::RefPtr<Connection>
  {
    return glib::make_refptr_for_instance<Connection> (
        new Connection (stream, guid, observer, cancellable, flags));
  }

  auto
  Connection::create_sync (const glib::RefPtr<IOStream>& stream,
                           const std::string& guid,
                           const glib::RefPtr<Cancellable>& cancellable,
                           const ConnectionFlags flags) -> glib::RefPtr<Connection>
  {
    return glib::make_refptr_for_instance<Connection> (
        new Connection (stream, guid, cancellable, flags));
  }

  auto
  Connection::create_sync (const glib::RefPtr<IOStream>& stream,
                           const std::string& guid,
                           const glib::RefPtr<AuthObserver>& observer,
                           const ConnectionFlags flags) -> glib::RefPtr<Connection>
  {
    return glib::make_refptr_for_instance<Connection> (
        new Connection (stream, guid, observer, flags));
  }

  auto
  Connection::create_sync (const glib::RefPtr<IOStream>& stream,
                           const std::string& guid,
                           const ConnectionFlags flags) -> glib::RefPtr<Connection>
  {
    return glib::make_refptr_for_instance<Connection> (
        new Connection (stream, guid, flags));
  }

  auto
  Connection::create_for_address (const std::string& address,
                                  const glib::RefPtr<AuthObserver>& observer,
                                  const SlotAsyncReady& slot,
                                  const glib::RefPtr<Cancellable>& cancellable,
                                  const ConnectionFlags flags) -> void
  {
    Connection (address, observer, slot, cancellable, flags);
  }

  auto
  Connection::create_for_address (const std::string& address,
                                  const SlotAsyncReady& slot,
                                  const glib::RefPtr<Cancellable>& cancellable,
                                  const ConnectionFlags flags) -> void
  {
    Connection (address, slot, cancellable, flags);
  }

  auto
  Connection::create_for_address (const std::string& address,
                                  const glib::RefPtr<AuthObserver>& observer,
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
      const glib::RefPtr<AuthObserver>& observer,
      const glib::RefPtr<Cancellable>& cancellable,
      const ConnectionFlags flags) -> glib::RefPtr<Connection>
  {
    return glib::make_refptr_for_instance<Connection> (
        new Connection (address, observer, cancellable, flags));
  }

  auto
  Connection::create_for_address_sync (
      const std::string& address,
      const glib::RefPtr<Cancellable>& cancellable,
      const ConnectionFlags flags) -> glib::RefPtr<Connection>
  {
    return glib::make_refptr_for_instance<Connection> (
        new Connection (address, cancellable, flags));
  }

  auto
  Connection::create_for_address_sync (
      const std::string& address,
      const glib::RefPtr<AuthObserver>& observer,
      const ConnectionFlags flags) -> glib::RefPtr<Connection>
  {
    return glib::make_refptr_for_instance<Connection> (
        new Connection (address, observer, flags));
  }

  auto
  Connection::create_for_address_sync (const std::string& address,
                                       const ConnectionFlags flags) -> glib::RefPtr<Connection>
  {
    return glib::make_refptr_for_instance<Connection> (
        new Connection (address, flags));
  }

  auto
  Connection::get (BusType bus_type,
                   const SlotAsyncReady& slot,
                   const glib::RefPtr<Cancellable>& cancellable) -> void
  {
    const auto slot_copy = new SlotAsyncReady (slot);

    g_bus_get (static_cast<GBusType> (bus_type),
               glib::unwrap (cancellable),
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
                     const glib::RefPtr<Cancellable>& cancellable) -> void
  {
    const auto slot_copy = new SlotAsyncReady (slot);

    g_dbus_connection_close (gobj (),
                             glib::unwrap (cancellable),
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
                     const glib::RefPtr<Cancellable>& cancellable) -> void
  {
    const auto slot_copy = new SlotAsyncReady (slot);

    g_dbus_connection_flush (gobj (),
                             glib::unwrap (cancellable),
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
  Connection::send_message (const glib::RefPtr<Message>& message,
                            SendMessageFlags flags) -> bool
  {
    GError* gerror = nullptr;

    const bool result = g_dbus_connection_send_message (
        gobj (),
        glib::unwrap (message),
        static_cast<GDBusSendMessageFlags> (flags),
        nullptr,
        &gerror);

    if (gerror)
      glib::Error::throw_exception (gerror);

    return result;
  }

  auto
  Connection::send_message_with_reply (
      const glib::RefPtr<Message>& message,
      const int timeout_msec,
      const SlotAsyncReady& slot,
      const glib::RefPtr<Cancellable>& cancellable) -> void
  {
    const auto slot_copy = new SlotAsyncReady (slot);
    volatile guint32 out_serial = 0;
    g_dbus_connection_send_message_with_reply (
        gobj (),
        glib::unwrap (message),
        static_cast<GDBusSendMessageFlags> (message->get_flags ()),
        timeout_msec,
        &out_serial,
        glib::unwrap (cancellable),
        &SignalProxy_async_callback,
        slot_copy);
    message->set_serial (out_serial);
  }

  auto
  Connection::send_message_with_reply (const glib::RefPtr<Message>& message,
                                       const int timeout_msec,
                                       const SlotAsyncReady& slot) -> void
  {
    const auto slot_copy = new SlotAsyncReady (slot);
    volatile guint32 out_serial = 0;
    g_dbus_connection_send_message_with_reply (
        gobj (),
        glib::unwrap (message),
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
      const glib::RefPtr<Message>& message,
      const glib::RefPtr<Cancellable>& cancellable,
      const gint timeout_msec) -> glib::RefPtr<Message>
  {
    volatile guint32 out_serial = 0;
    GError* gerror = nullptr;

    GDBusMessage* result = g_dbus_connection_send_message_with_reply_sync (
        gobj (),
        glib::unwrap (message),
        static_cast<GDBusSendMessageFlags> (message->get_flags ()),
        timeout_msec,
        &out_serial,
        glib::unwrap (cancellable),
        &gerror);

    if (gerror)
      glib::Error::throw_exception (gerror);
    message->set_serial (out_serial);
    return glib::wrap (result);
  }

  auto
  Connection::send_message_with_reply_sync (
      const glib::RefPtr<Message>& message,
      const gint timeout_msec) -> glib::RefPtr<Message>
  {
    volatile guint32 out_serial = 0;
    GError* gerror = nullptr;

    GDBusMessage* result = g_dbus_connection_send_message_with_reply_sync (
        gobj (),
        glib::unwrap (message),
        static_cast<GDBusSendMessageFlags> (message->get_flags ()),
        timeout_msec,
        &out_serial,
        nullptr,
        &gerror);

    if (gerror)
      glib::Error::throw_exception (gerror);
    message->set_serial (out_serial);
    return glib::wrap (result);
  }

  auto
  Connection::call (const glib::ustring& object_path,
                    const glib::ustring& interface_name,
                    const glib::ustring& method_name,
                    const glib::VariantContainerBase& parameters,
                    const SlotAsyncReady& slot,
                    const glib::RefPtr<Cancellable>& cancellable,
                    const glib::ustring& bus_name,
                    const int timeout_msec,
                    CallFlags flags,
                    const glib::VariantType& reply_type) -> void
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
                            glib::unwrap (cancellable),
                            &SignalProxy_async_callback,
                            slot_copy);
  }

  auto
  Connection::call (const glib::ustring& object_path,
                    const glib::ustring& interface_name,
                    const glib::ustring& method_name,
                    const glib::VariantContainerBase& parameters,
                    const SlotAsyncReady& slot,
                    const glib::ustring& bus_name,
                    const int timeout_msec,
                    CallFlags flags,
                    const glib::VariantType& reply_type) -> void
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
  Connection::call_sync (const glib::ustring& object_path,
                         const glib::ustring& interface_name,
                         const glib::ustring& method_name,
                         const glib::VariantContainerBase& parameters,
                         const glib::RefPtr<Cancellable>& cancellable,
                         const glib::ustring& bus_name,
                         const int timeout_msec,
                         CallFlags flags,
                         const glib::VariantType& reply_type) -> glib::VariantContainerBase
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
        glib::unwrap (cancellable),
        &gerror);

    if (gerror)
      glib::Error::throw_exception (gerror);

    return glib::VariantContainerBase (gvariant, false);
  }

  auto
  Connection::call_sync (const glib::ustring& object_path,
                         const glib::ustring& interface_name,
                         const glib::ustring& method_name,
                         const glib::VariantContainerBase& parameters,
                         const glib::ustring& bus_name,
                         const int timeout_msec,
                         CallFlags flags,
                         const glib::VariantType& reply_type) -> glib::VariantContainerBase
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
      glib::Error::throw_exception (gerror);

    return glib::VariantContainerBase (gvariant, false);
  }

#ifdef G_OS_UNIX

  void
  Connection::call (const glib::ustring& object_path,
                    const glib::ustring& interface_name,
                    const glib::ustring& method_name,
                    const glib::VariantContainerBase& parameters,
                    const SlotAsyncReady& slot,
                    const glib::RefPtr<Cancellable>& cancellable,
                    const glib::RefPtr<UnixFDList>& fd_list,
                    const glib::ustring& bus_name,
                    int timeout_msec,
                    CallFlags flags,
                    const glib::VariantType& reply_type)
  {
    auto slot_copy = new SlotAsyncReady (slot);

    g_dbus_connection_call_with_unix_fd_list (
        gobj (),
        glib::c_str_or_nullptr (bus_name),
        object_path.c_str (),
        interface_name.c_str (),
        method_name.c_str (),
        const_cast<GVariant*> (parameters.gobj ()),
        reply_type.gobj (),
        static_cast<GDBusCallFlags> (flags),
        timeout_msec,
        glib::unwrap (fd_list),
        glib::unwrap (cancellable),
        &SignalProxy_async_callback,
        slot_copy);
  }

  void
  Connection::call (const glib::ustring& object_path,
                    const glib::ustring& interface_name,
                    const glib::ustring& method_name,
                    const glib::VariantContainerBase& parameters,
                    const SlotAsyncReady& slot,
                    const glib::RefPtr<UnixFDList>& fd_list,
                    const glib::ustring& bus_name,
                    int timeout_msec,
                    CallFlags flags,
                    const glib::VariantType& reply_type)
  {
    auto slot_copy = new SlotAsyncReady (slot);

    g_dbus_connection_call_with_unix_fd_list (
        gobj (),
        glib::c_str_or_nullptr (bus_name),
        object_path.c_str (),
        interface_name.c_str (),
        method_name.c_str (),
        const_cast<GVariant*> (parameters.gobj ()),
        reply_type.gobj (),
        static_cast<GDBusCallFlags> (flags),
        timeout_msec,
        glib::unwrap (fd_list),
        nullptr,
        &SignalProxy_async_callback,
        slot_copy);
  }
#endif

  auto
  Connection::emit_signal (const glib::ustring& object_path,
                           const glib::ustring& interface_name,
                           const glib::ustring& signal_name,
                           const glib::ustring& destination_bus_name,
                           const glib::VariantContainerBase& parameters) -> void
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
      glib::Error::throw_exception (gerror);
  }

  auto
  Connection::signal_subscribe (const SlotSignal& slot,
                                const glib::ustring& sender,
                                const glib::ustring& interface_name,
                                const glib::ustring& member,
                                const glib::ustring& object_path,
                                const glib::ustring& arg0,
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
      const glib::ustring& object_path,
      const glib::RefPtr<InterfaceInfo>& interface_info,
      const InterfaceVTable& vtable) -> guint
  {
    GError* gerror = nullptr;

    const guint result = g_dbus_connection_register_object (
        gobj (),
        object_path.c_str (),
        glib::unwrap (interface_info),
        vtable.gobj (),
        const_cast<InterfaceVTable*> (&vtable),
        nullptr,
        &gerror);

    if (gerror)
      glib::Error::throw_exception (gerror);

    return result;
  }

  auto
  Connection::register_object (
      const glib::ustring& object_path,
      const glib::RefPtr<InterfaceInfo>& interface_info) -> guint
  {
    GError* gerror = nullptr;

    const guint result = g_dbus_connection_register_object (
        gobj (),
        object_path.c_str (),
        glib::unwrap (interface_info),
        nullptr,
        nullptr,
        nullptr,
        &gerror);

    if (gerror)
      glib::Error::throw_exception (gerror);

    return result;
  }

  auto
  Connection::register_subtree (const glib::ustring& object_path,
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
      glib::Error::throw_exception (gerror);

    return result;
  }

} // namespace gio::DBus

namespace glib
{

  auto
  wrap (GDBusConnection* object, const bool take_copy) -> RefPtr<gio::DBus::Connection>
  {
    ObjectBase* pCppObject = nullptr;
    if (!ObjectBase::_get_current_wrapper ((GObject*) object))
    {
      std::lock_guard<std::mutex> lock (wrap_mutex);
      pCppObject = wrap_auto ((GObject*) object, take_copy);
    }
    else
      pCppObject = wrap_auto ((GObject*) object, take_copy);

    return glib::make_refptr_for_instance<gio::DBus::Connection> (
        dynamic_cast<gio::DBus::Connection*> (pCppObject));
  }

} // namespace glib

namespace
{

  auto
  Connection_signal_closed_callback (GDBusConnection* self,
                                     const gboolean p0,
                                     GError* p1,
                                     void* data) -> void
  {
    using namespace gio::DBus;
    using SlotType = sigc::slot<void (bool, const glib::Error&)>;

    const auto obj = dynamic_cast<Connection*> (
        glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj)
    {
      try
      {
        if (const auto slot = glib::SignalProxyNormal::data_to_slot (data))
          (*static_cast<SlotType*> (slot)) (p0, glib::Error (p1, true));
      }
      catch (...)
      {
        glib::exception_handlers_invoke ();
      }
    }
  }

  const glib::SignalProxyInfo Connection_signal_closed_info = {
      "closed",
      (GCallback) &Connection_signal_closed_callback,
      (GCallback) &Connection_signal_closed_callback};

} // namespace

auto
glib::Value<gio::DBus::BusType>::value_type () -> GType
{
  return g_bus_type_get_type ();
}

auto
glib::Value<gio::DBus::ConnectionFlags>::value_type () -> GType
{
  return g_dbus_connection_flags_get_type ();
}

namespace gio::DBus
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
  Connection_Class::wrap_new (GObject* object) -> glib::ObjectBase*
  {
    return new Connection ((GDBusConnection*) object);
  }

  auto
  Connection::gobj_copy () -> GDBusConnection*
  {
    reference ();
    return gobj ();
  }

  Connection::Connection (const glib::ConstructParams& construct_params)
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
  Connection::get_finish (const glib::RefPtr<AsyncResult>& res) -> glib::RefPtr<Connection>
  {
    GError* gerror = nullptr;
    auto retvalue = glib::wrap (g_bus_get_finish (glib::unwrap (res), &gerror));
    if (gerror)
      glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  Connection::get_sync (BusType bus_type,
                        const glib::RefPtr<Cancellable>& cancellable) -> glib::RefPtr<Connection>
  {
    GError* gerror = nullptr;
    auto retvalue =
        glib::wrap (g_bus_get_sync (static_cast<GBusType> (bus_type),
                                    glib::unwrap (cancellable),
                                    &gerror));
    if (gerror)
      glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  Connection::get_sync (BusType bus_type) -> glib::RefPtr<Connection>
  {
    GError* gerror = nullptr;
    auto retvalue = glib::wrap (
        g_bus_get_sync (static_cast<GBusType> (bus_type), nullptr, &gerror));
    if (gerror)
      glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  Connection::create_finish (const glib::RefPtr<AsyncResult>& res) -> glib::RefPtr<Connection>
  {
    GError* gerror = nullptr;
    auto retvalue =
        glib::wrap (g_dbus_connection_new_finish (glib::unwrap (res), &gerror));
    if (gerror)
      glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  Connection::create_for_address_finish (const glib::RefPtr<AsyncResult>& res) -> glib::RefPtr<Connection>
  {
    GError* gerror = nullptr;
    auto retvalue = glib::wrap (
        g_dbus_connection_new_for_address_finish (glib::unwrap (res), &gerror));
    if (gerror)
      glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  Connection::close_finish (const glib::RefPtr<AsyncResult>& res) -> bool
  {
    GError* gerror = nullptr;
    const auto retvalue =
        g_dbus_connection_close_finish (gobj (), glib::unwrap (res), &gerror);
    if (gerror)
      glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  Connection::close_sync (const glib::RefPtr<Cancellable>& cancellable) -> void
  {
    GError* gerror = nullptr;
    g_dbus_connection_close_sync (gobj (), glib::unwrap (cancellable), &gerror);
    if (gerror)
      glib::Error::throw_exception (gerror);
  }

  auto
  Connection::close_sync () -> void
  {
    GError* gerror = nullptr;
    g_dbus_connection_close_sync (gobj (), nullptr, &gerror);
    if (gerror)
      glib::Error::throw_exception (gerror);
  }

  auto
  Connection::flush_finish (const glib::RefPtr<AsyncResult>& res) -> bool
  {
    GError* gerror = nullptr;
    const auto retvalue =
        g_dbus_connection_flush_finish (gobj (), glib::unwrap (res), &gerror);
    if (gerror)
      glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  Connection::flush_sync (const glib::RefPtr<Cancellable>& cancellable) -> void
  {
    GError* gerror = nullptr;
    g_dbus_connection_flush_sync (gobj (), glib::unwrap (cancellable), &gerror);
    if (gerror)
      glib::Error::throw_exception (gerror);
  }

  auto
  Connection::flush_sync () -> void
  {
    GError* gerror = nullptr;
    g_dbus_connection_flush_sync (gobj (), nullptr, &gerror);
    if (gerror)
      glib::Error::throw_exception (gerror);
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
  Connection::send_message (const glib::RefPtr<Message>& message,
                            SendMessageFlags flags,
                            guint32& out_serial) -> bool
  {
    GError* gerror = nullptr;
    const auto retvalue = g_dbus_connection_send_message (
        gobj (),
        glib::unwrap (message),
        static_cast<GDBusSendMessageFlags> (flags),
        &out_serial,
        &gerror);
    if (gerror)
      glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  Connection::send_message_with_reply_finish (
      const glib::RefPtr<AsyncResult>& res) -> glib::RefPtr<Message>
  {
    GError* gerror = nullptr;
    auto retvalue = glib::wrap (
        g_dbus_connection_send_message_with_reply_finish (gobj (),
                                                          glib::unwrap (res),
                                                          &gerror));
    if (gerror)
      glib::Error::throw_exception (gerror);
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
  Connection::get_stream () -> glib::RefPtr<IOStream>
  {
    auto retvalue = glib::wrap (g_dbus_connection_get_stream (gobj ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  Connection::get_stream () const -> glib::RefPtr<const IOStream>
  {
    return const_cast<Connection*> (this)->get_stream ();
  }

  auto
  Connection::get_guid () const -> std::string
  {
    return glib::convert_const_gchar_ptr_to_stdstring (
        g_dbus_connection_get_guid (const_cast<GDBusConnection*> (gobj ())));
  }

  auto
  Connection::get_unique_name () const -> glib::ustring
  {
    return glib::convert_const_gchar_ptr_to_ustring (
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
  Connection::get_peer_credentials () -> glib::RefPtr<Credentials>
  {
    auto retvalue =
        glib::wrap (g_dbus_connection_get_peer_credentials (gobj ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  Connection::get_peer_credentials () const -> glib::RefPtr<const Credentials>
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
  Connection::call_finish (const glib::RefPtr<AsyncResult>& res) -> glib::VariantContainerBase
  {
    GError* gerror = nullptr;
    auto retvalue = glib::VariantContainerBase (
        g_dbus_connection_call_finish (gobj (), glib::unwrap (res), &gerror),
        false);
    if (gerror)
      glib::Error::throw_exception (gerror);
    return retvalue;
  }

#ifdef G_OS_UNIX
  auto
  Connection::call_finish (const glib::RefPtr<AsyncResult>& res,
                           glib::RefPtr<UnixFDList>& out_fd_list) -> glib::VariantContainerBase
  {
    GError* gerror = nullptr;
    GUnixFDList* g_out_fd_list = nullptr;
    auto retvalue = glib::VariantContainerBase (
        g_dbus_connection_call_with_unix_fd_list_finish (gobj (),
                                                         &g_out_fd_list,
                                                         glib::unwrap (res),
                                                         &(gerror)),
        false);
    if (gerror)
      ::glib::Error::throw_exception (gerror);
    out_fd_list = glib::wrap (g_out_fd_list);
    return retvalue;
  }
#endif

#ifdef G_OS_UNIX
  auto
  Connection::call_sync (const glib::ustring& object_path,
                         const glib::ustring& interface_name,
                         const glib::ustring& method_name,
                         const glib::VariantContainerBase& parameters,
                         const glib::RefPtr<Cancellable>& cancellable,
                         const glib::RefPtr<UnixFDList>& fd_list,
                         glib::RefPtr<UnixFDList>& out_fd_list,
                         const glib::ustring& bus_name,
                         int timeout_msec,
                         CallFlags flags,
                         const glib::VariantType& reply_type) -> glib::VariantContainerBase
  {
    GError* gerror = nullptr;
    GUnixFDList* g_out_fd_list = nullptr;
    auto retvalue = glib::VariantContainerBase (
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
            glib::unwrap (fd_list),
            &g_out_fd_list,
            const_cast<GCancellable*> (glib::unwrap (cancellable)),
            &(gerror)),
        false);
    if (gerror)
      ::glib::Error::throw_exception (gerror);
    out_fd_list = glib::wrap (g_out_fd_list);
    return retvalue;
  }
#endif

#ifdef G_OS_UNIX
  auto
  Connection::call_sync (const glib::ustring& object_path,
                         const glib::ustring& interface_name,
                         const glib::ustring& method_name,
                         const glib::VariantContainerBase& parameters,
                         const glib::RefPtr<UnixFDList>& fd_list,
                         glib::RefPtr<UnixFDList>& out_fd_list,
                         const glib::ustring& bus_name,
                         int timeout_msec,
                         CallFlags flags,
                         const glib::VariantType& reply_type) -> glib::VariantContainerBase
  {
    GError* gerror = nullptr;
    GUnixFDList* g_out_fd_list = nullptr;
    auto retvalue = glib::VariantContainerBase (
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
            glib::unwrap (fd_list),
            &g_out_fd_list,
            nullptr,
            &(gerror)),
        false);
    if (gerror)
      ::glib::Error::throw_exception (gerror);
    out_fd_list = glib::wrap (g_out_fd_list);
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
      const glib::ustring& object_path,
      const glib::RefPtr<ActionGroup>& action_group) -> guint
  {
    GError* gerror = nullptr;
    const auto retvalue = g_dbus_connection_export_action_group (
        gobj (),
        object_path.c_str (),
        glib::unwrap (action_group),
        &gerror);
    if (gerror)
      glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  Connection::unexport_action_group (const guint export_id) -> void
  {
    g_dbus_connection_unexport_action_group (gobj (), export_id);
  }

  auto
  Connection::export_menu_model (const glib::ustring& object_path,
                                 const glib::RefPtr<MenuModel>& menu) -> guint
  {
    GError* gerror = nullptr;
    const auto retvalue = g_dbus_connection_export_menu_model (
        gobj (),
        object_path.c_str (),
        glib::unwrap (menu),
        &gerror);
    if (gerror)
      glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  Connection::unexport_menu_model (const guint export_id) -> void
  {
    g_dbus_connection_unexport_menu_model (gobj (), export_id);
  }

  auto
  Connection::signal_closed () -> glib::SignalProxy<void (bool, const glib::Error&)>
  {
    return {this, &Connection_signal_closed_info};
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<CapabilityFlags>::value,
      "Type CapabilityFlags cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  Connection::property_capabilities () const -> glib::PropertyProxy_ReadOnly<CapabilityFlags>
  {
    return {this, "capabilities"};
  }

  auto
  Connection::property_closed () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return {this, "closed"};
  }

  auto
  Connection::property_exit_on_close () -> glib::PropertyProxy<bool>
  {
    return {this, "exit-on-close"};
  }

  auto
  Connection::property_exit_on_close () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return {this, "exit-on-close"};
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<ConnectionFlags>::value,
      "Type ConnectionFlags cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  Connection::property_flags () const -> glib::PropertyProxy_ReadOnly<ConnectionFlags>
  {
    return {this, "flags"};
  }

  auto
  Connection::property_guid () const -> glib::PropertyProxy_ReadOnly<std::string>
  {
    return {this, "guid"};
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<
          glib::RefPtr<IOStream>>::value,
      "Type glib::RefPtr<IOStream> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  Connection::property_stream () const -> glib::PropertyProxy_ReadOnly<glib::RefPtr<IOStream>>
  {
    return {this, "stream"};
  }

  auto
  Connection::property_unique_name () const -> glib::PropertyProxy_ReadOnly<glib::ustring>
  {
    return {this, "unique-name"};
  }

} // namespace gio::DBus
