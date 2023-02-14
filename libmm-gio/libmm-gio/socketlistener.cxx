

#include <libmm-glib/mm-glib.hxx>

#include <libmm-gio/socketlistener.hxx>
#include <libmm-gio/socketlistener_p.hxx>

#include <gio/gio.h>
#include <libmm-gio/slot_async.hxx>

namespace Gio
{

  auto
  SocketListener::add_socket (const Glib::RefPtr<Socket>& socket) -> bool
  {
    GError* gerror = nullptr;
    const bool retval = g_socket_listener_add_socket (gobj (),
                                                      Glib::unwrap (socket),
                                                      nullptr,
                                                      &gerror);

    if (gerror)
      Glib::Error::throw_exception (gerror);

    return retval;
  }

  auto
  SocketListener::add_address (const Glib::RefPtr<SocketAddress>& address,
                               Socket::Type type,
                               Socket::Protocol protocol,
                               const Glib::RefPtr<Object>& source_object,
                               Glib::RefPtr<SocketAddress>& effective_address) -> bool
  {
    GError* gerror = nullptr;
    GSocketAddress* retaddr = nullptr;
    const bool retval = g_socket_listener_add_address (
        gobj (),
        Glib::unwrap (address),
        static_cast<GSocketType> (type),
        static_cast<GSocketProtocol> (protocol),
        Glib::unwrap (source_object),
        &retaddr,
        &gerror);
    if (gerror)
      Glib::Error::throw_exception (gerror);

    if (retaddr)
      effective_address = Glib::wrap (retaddr);

    return retval;
  }

  auto
  SocketListener::add_address (const Glib::RefPtr<SocketAddress>& address,
                               Socket::Type type,
                               Socket::Protocol protocol,
                               Glib::RefPtr<SocketAddress>& effective_address) -> bool
  {
    GError* gerror = nullptr;
    GSocketAddress* retaddr = nullptr;
    const bool retval = g_socket_listener_add_address (
        gobj (),
        Glib::unwrap (address),
        static_cast<GSocketType> (type),
        static_cast<GSocketProtocol> (protocol),
        nullptr,
        &retaddr,
        &gerror);
    if (gerror)
      Glib::Error::throw_exception (gerror);

    if (retaddr)
      effective_address = Glib::wrap (retaddr);

    return retval;
  }

  auto
  SocketListener::add_inet_port (const guint16 port) -> bool
  {
    GError* gerror = nullptr;
    const bool retvalue =
        g_socket_listener_add_inet_port (gobj (), port, nullptr, &gerror);
    if (gerror)
      Glib::Error::throw_exception (gerror);

    return retvalue;
  }

  auto
  SocketListener::add_any_inet_port () -> guint16
  {
    GError* gerror = nullptr;
    const auto retvalue =
        g_socket_listener_add_any_inet_port (gobj (), nullptr, &gerror);
    if (gerror)
      Glib::Error::throw_exception (gerror);

    return retvalue;
  }

  auto
  SocketListener::accept_socket (Glib::RefPtr<Object>& source_object,
                                 const Glib::RefPtr<Cancellable>& cancellable) -> Glib::RefPtr<Socket>
  {
    GError* gerror = nullptr;
    GObject* retobj = nullptr;
    const auto retvalue = g_socket_listener_accept_socket (
        gobj (),
        &retobj,
        Glib::unwrap (cancellable),
        &gerror);
    if (gerror)
      Glib::Error::throw_exception (gerror);

    if (retobj)
      source_object = Glib::wrap (retobj);

    return Glib::wrap (retvalue);
  }

  auto
  SocketListener::accept_socket (Glib::RefPtr<Object>& source_object) -> Glib::RefPtr<Socket>
  {
    GError* gerror = nullptr;
    GObject* retobj = nullptr;
    const auto retvalue =
        g_socket_listener_accept_socket (gobj (), &retobj, nullptr, &gerror);
    if (gerror)
      Glib::Error::throw_exception (gerror);

    if (retobj)
      source_object = Glib::wrap (retobj);

    return Glib::wrap (retvalue);
  }

  auto
  SocketListener::accept_socket (const Glib::RefPtr<Cancellable>& cancellable) -> Glib::RefPtr<Socket>
  {
    GError* gerror = nullptr;
    const auto retvalue = g_socket_listener_accept_socket (
        gobj (),
        nullptr,
        Glib::unwrap (cancellable),
        &gerror);
    if (gerror)
      Glib::Error::throw_exception (gerror);

    return Glib::wrap (retvalue);
  }

  auto
  SocketListener::accept_socket () -> Glib::RefPtr<Socket>
  {
    GError* gerror = nullptr;
    const auto retvalue =
        g_socket_listener_accept_socket (gobj (), nullptr, nullptr, &gerror);
    if (gerror)
      Glib::Error::throw_exception (gerror);

    return Glib::wrap (retvalue);
  }

  auto
  SocketListener::accept_socket_async (
      const Glib::RefPtr<Cancellable>& cancellable,
      const SlotAsyncReady& slot) -> void
  {
    const auto slot_copy = new SlotAsyncReady (slot);

    g_socket_listener_accept_socket_async (gobj (),
                                           Glib::unwrap (cancellable),
                                           &SignalProxy_async_callback,
                                           slot_copy);
  }

  auto
  SocketListener::accept_socket_async (const SlotAsyncReady& slot) -> void
  {
    const auto slot_copy = new SlotAsyncReady (slot);

    g_socket_listener_accept_socket_async (gobj (),
                                           nullptr,
                                           &SignalProxy_async_callback,
                                           slot_copy);
  }

  auto
  SocketListener::accept_socket_finish (const Glib::RefPtr<AsyncResult>& result,
                                        Glib::RefPtr<Object>& source_object) -> Glib::RefPtr<Socket>
  {
    GError* gerror = nullptr;
    GObject* retobj = nullptr;
    const auto retvalue = g_socket_listener_accept_socket_finish (
        gobj (),
        Glib::unwrap (result),
        &retobj,
        &gerror);
    if (gerror)
      Glib::Error::throw_exception (gerror);
    if (retobj)
      source_object = Glib::wrap (retobj);

    return Glib::wrap (retvalue);
  }

  auto
  SocketListener::accept_socket_finish (const Glib::RefPtr<AsyncResult>& result) -> Glib::RefPtr<Socket>
  {
    GError* gerror = nullptr;
    const auto retvalue = g_socket_listener_accept_socket_finish (
        gobj (),
        Glib::unwrap (result),
        nullptr,
        &gerror);
    if (gerror)
      Glib::Error::throw_exception (gerror);

    return Glib::wrap (retvalue);
  }

  auto
  SocketListener::accept (Glib::RefPtr<Object>& source_object,
                          const Glib::RefPtr<Cancellable>& cancellable) -> Glib::RefPtr<SocketConnection>
  {
    GError* gerror = nullptr;
    GObject* retobj = nullptr;
    const auto retvalue = g_socket_listener_accept (gobj (),
                                                    &retobj,
                                                    Glib::unwrap (cancellable),
                                                    &gerror);
    if (gerror)
      Glib::Error::throw_exception (gerror);

    if (retobj)
      source_object = Glib::wrap (retobj);

    return Glib::wrap (retvalue);
  }

  auto
  SocketListener::accept (Glib::RefPtr<Object>& source_object) -> Glib::RefPtr<SocketConnection>
  {
    GError* gerror = nullptr;
    GObject* retobj = nullptr;
    const auto retvalue =
        g_socket_listener_accept (gobj (), &retobj, nullptr, &gerror);
    if (gerror)
      Glib::Error::throw_exception (gerror);

    if (retobj)
      source_object = Glib::wrap (retobj);

    return Glib::wrap (retvalue);
  }

  auto
  SocketListener::accept (const Glib::RefPtr<Cancellable>& cancellable) -> Glib::RefPtr<SocketConnection>
  {
    GError* gerror = nullptr;
    const auto retvalue = g_socket_listener_accept (gobj (),
                                                    nullptr,
                                                    Glib::unwrap (cancellable),
                                                    &gerror);
    if (gerror)
      Glib::Error::throw_exception (gerror);

    return Glib::wrap (retvalue);
  }

  auto
  SocketListener::accept () -> Glib::RefPtr<SocketConnection>
  {
    GError* gerror = nullptr;
    const auto retvalue =
        g_socket_listener_accept (gobj (), nullptr, nullptr, &gerror);
    if (gerror)
      Glib::Error::throw_exception (gerror);

    return Glib::wrap (retvalue);
  }

  auto
  SocketListener::accept_async (const SlotAsyncReady& slot) -> void
  {
    const auto slot_copy = new SlotAsyncReady (slot);

    g_socket_listener_accept_async (gobj (),
                                    nullptr,
                                    &SignalProxy_async_callback,
                                    slot_copy);
  }

  auto
  SocketListener::accept_async (const Glib::RefPtr<Cancellable>& cancellable,
                                const SlotAsyncReady& slot) -> void
  {
    const auto slot_copy = new SlotAsyncReady (slot);

    g_socket_listener_accept_async (gobj (),
                                    Glib::unwrap (cancellable),
                                    &SignalProxy_async_callback,
                                    slot_copy);
  }

  auto
  SocketListener::accept_finish (const Glib::RefPtr<AsyncResult>& result,
                                 Glib::RefPtr<Object>& source_object) -> Glib::RefPtr<SocketConnection>
  {
    GError* gerror = nullptr;
    GObject* retobj = nullptr;
    const auto retvalue = g_socket_listener_accept_finish (
        gobj (),
        Glib::unwrap (result),
        &retobj,
        &gerror);
    if (gerror)
      Glib::Error::throw_exception (gerror);
    if (retobj)
      source_object = Glib::wrap (retobj);

    return Glib::wrap (retvalue);
  }

  auto
  SocketListener::accept_finish (const Glib::RefPtr<AsyncResult>& result) -> Glib::RefPtr<SocketConnection>
  {
    GError* gerror = nullptr;
    const auto retvalue = g_socket_listener_accept_finish (
        gobj (),
        Glib::unwrap (result),
        nullptr,
        &gerror);
    if (gerror)
      Glib::Error::throw_exception (gerror);

    return Glib::wrap (retvalue);
  }

} // namespace Gio

namespace
{
}

namespace Glib
{

  auto
  wrap (GSocketListener* object, const bool take_copy) -> RefPtr<Gio::SocketListener>
  {
    return Glib::make_refptr_for_instance<Gio::SocketListener> (
        dynamic_cast<Gio::SocketListener*> (
            wrap_auto ((GObject*) object, take_copy)));
  }

} // namespace Glib

namespace Gio
{

  auto
  SocketListener_Class::init () -> const Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &SocketListener_Class::class_init_function;

      register_derived_type (g_socket_listener_get_type ());
    }

    return *this;
  }

  auto
  SocketListener_Class::class_init_function (void* g_class, void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);
  }

  auto
  SocketListener_Class::wrap_new (GObject* object) -> Glib::ObjectBase*
  {
    return new SocketListener ((GSocketListener*) object);
  }

  auto
  SocketListener::gobj_copy () -> GSocketListener*
  {
    reference ();
    return gobj ();
  }

  SocketListener::SocketListener (const Glib::ConstructParams& construct_params)
    : Object (construct_params)
  {
  }

  SocketListener::SocketListener (GSocketListener* castitem)
    : Object ((GObject*) castitem)
  {
  }

  SocketListener::SocketListener (SocketListener&& src) noexcept
    : Object (std::move (src))
  {
  }

  auto
  SocketListener::operator= (SocketListener&& src) noexcept -> SocketListener&
  {
    Object::operator= (std::move (src));
    return *this;
  }

  SocketListener::~SocketListener () noexcept = default;

  SocketListener::CppClassType SocketListener::socketlistener_class_;

  auto
  SocketListener::get_type () -> GType
  {
    return socketlistener_class_.init ().get_type ();
  }

  auto
  SocketListener::get_base_type () -> GType
  {
    return g_socket_listener_get_type ();
  }

  SocketListener::SocketListener ()
    : ObjectBase (nullptr),
      Object (Glib::ConstructParams (socketlistener_class_.init ()))
  {
  }

  auto
  SocketListener::create () -> Glib::RefPtr<SocketListener>
  {
    return Glib::make_refptr_for_instance<SocketListener> (
        new SocketListener ());
  }

  auto
  SocketListener::set_backlog (const int listen_backlog) -> void
  {
    g_socket_listener_set_backlog (gobj (), listen_backlog);
  }

  auto
  SocketListener::add_socket (const Glib::RefPtr<Socket>& socket,
                              const Glib::RefPtr<Object>& source_object) -> bool
  {
    GError* gerror = nullptr;
    const auto retvalue = g_socket_listener_add_socket (
        gobj (),
        Glib::unwrap (socket),
        Glib::unwrap (source_object),
        &gerror);
    if (gerror)
      Glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  SocketListener::add_inet_port (const guint16 port,
                                 const Glib::RefPtr<Object>& source_object) -> bool
  {
    GError* gerror = nullptr;
    const auto retvalue = g_socket_listener_add_inet_port (
        gobj (),
        port,
        Glib::unwrap (source_object),
        &gerror);
    if (gerror)
      Glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  SocketListener::add_any_inet_port (const Glib::RefPtr<Object>& source_object) -> guint16
  {
    GError* gerror = nullptr;
    const auto retvalue = g_socket_listener_add_any_inet_port (
        gobj (),
        Glib::unwrap (source_object),
        &gerror);
    if (gerror)
      Glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  SocketListener::close () -> void
  {
    g_socket_listener_close (gobj ());
  }

  auto
  SocketListener::property_listen_backlog () -> Glib::PropertyProxy<int>
  {
    return {this, "listen-backlog"};
  }

  auto
  SocketListener::property_listen_backlog () const -> Glib::PropertyProxy_ReadOnly<int>
  {
    return {this, "listen-backlog"};
  }

} // namespace Gio
