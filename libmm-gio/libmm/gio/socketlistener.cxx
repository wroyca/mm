// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/gio/socketlistener.hxx>
#include <libmm/gio/socketlistener_p.hxx>

#include <gio/gio.h>
#include <libmm/gio/slot_async.hxx>

namespace gio
{

  auto
  SocketListener::add_socket (const glib::RefPtr<Socket>& socket) -> bool
  {
    GError* gerror = nullptr;
    const bool retval = g_socket_listener_add_socket (gobj (),
                                                      glib::unwrap (socket),
                                                      nullptr,
                                                      &gerror);

    if (gerror)
      glib::Error::throw_exception (gerror);

    return retval;
  }

  auto
  SocketListener::add_address (const glib::RefPtr<SocketAddress>& address,
                               Socket::Type type,
                               Socket::Protocol protocol,
                               const glib::RefPtr<Object>& source_object,
                               glib::RefPtr<SocketAddress>& effective_address) -> bool
  {
    GError* gerror = nullptr;
    GSocketAddress* retaddr = nullptr;
    const bool retval = g_socket_listener_add_address (
        gobj (),
        glib::unwrap (address),
        static_cast<GSocketType> (type),
        static_cast<GSocketProtocol> (protocol),
        glib::unwrap (source_object),
        &retaddr,
        &gerror);
    if (gerror)
      glib::Error::throw_exception (gerror);

    if (retaddr)
      effective_address = glib::wrap (retaddr);

    return retval;
  }

  auto
  SocketListener::add_address (const glib::RefPtr<SocketAddress>& address,
                               Socket::Type type,
                               Socket::Protocol protocol,
                               glib::RefPtr<SocketAddress>& effective_address) -> bool
  {
    GError* gerror = nullptr;
    GSocketAddress* retaddr = nullptr;
    const bool retval = g_socket_listener_add_address (
        gobj (),
        glib::unwrap (address),
        static_cast<GSocketType> (type),
        static_cast<GSocketProtocol> (protocol),
        nullptr,
        &retaddr,
        &gerror);
    if (gerror)
      glib::Error::throw_exception (gerror);

    if (retaddr)
      effective_address = glib::wrap (retaddr);

    return retval;
  }

  auto
  SocketListener::add_inet_port (const guint16 port) -> bool
  {
    GError* gerror = nullptr;
    const bool retvalue =
        g_socket_listener_add_inet_port (gobj (), port, nullptr, &gerror);
    if (gerror)
      glib::Error::throw_exception (gerror);

    return retvalue;
  }

  auto
  SocketListener::add_any_inet_port () -> guint16
  {
    GError* gerror = nullptr;
    const auto retvalue =
        g_socket_listener_add_any_inet_port (gobj (), nullptr, &gerror);
    if (gerror)
      glib::Error::throw_exception (gerror);

    return retvalue;
  }

  auto
  SocketListener::accept_socket (glib::RefPtr<Object>& source_object,
                                 const glib::RefPtr<Cancellable>& cancellable) -> glib::RefPtr<Socket>
  {
    GError* gerror = nullptr;
    GObject* retobj = nullptr;
    const auto retvalue = g_socket_listener_accept_socket (
        gobj (),
        &retobj,
        glib::unwrap (cancellable),
        &gerror);
    if (gerror)
      glib::Error::throw_exception (gerror);

    if (retobj)
      source_object = glib::wrap (retobj);

    return glib::wrap (retvalue);
  }

  auto
  SocketListener::accept_socket (glib::RefPtr<Object>& source_object) -> glib::RefPtr<Socket>
  {
    GError* gerror = nullptr;
    GObject* retobj = nullptr;
    const auto retvalue =
        g_socket_listener_accept_socket (gobj (), &retobj, nullptr, &gerror);
    if (gerror)
      glib::Error::throw_exception (gerror);

    if (retobj)
      source_object = glib::wrap (retobj);

    return glib::wrap (retvalue);
  }

  auto
  SocketListener::accept_socket (const glib::RefPtr<Cancellable>& cancellable) -> glib::RefPtr<Socket>
  {
    GError* gerror = nullptr;
    const auto retvalue = g_socket_listener_accept_socket (
        gobj (),
        nullptr,
        glib::unwrap (cancellable),
        &gerror);
    if (gerror)
      glib::Error::throw_exception (gerror);

    return glib::wrap (retvalue);
  }

  auto
  SocketListener::accept_socket () -> glib::RefPtr<Socket>
  {
    GError* gerror = nullptr;
    const auto retvalue =
        g_socket_listener_accept_socket (gobj (), nullptr, nullptr, &gerror);
    if (gerror)
      glib::Error::throw_exception (gerror);

    return glib::wrap (retvalue);
  }

  auto
  SocketListener::accept_socket_async (
      const glib::RefPtr<Cancellable>& cancellable,
      const SlotAsyncReady& slot) -> void
  {
    const auto slot_copy = new SlotAsyncReady (slot);

    g_socket_listener_accept_socket_async (gobj (),
                                           glib::unwrap (cancellable),
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
  SocketListener::accept_socket_finish (const glib::RefPtr<AsyncResult>& result,
                                        glib::RefPtr<Object>& source_object) -> glib::RefPtr<Socket>
  {
    GError* gerror = nullptr;
    GObject* retobj = nullptr;
    const auto retvalue = g_socket_listener_accept_socket_finish (
        gobj (),
        glib::unwrap (result),
        &retobj,
        &gerror);
    if (gerror)
      glib::Error::throw_exception (gerror);
    if (retobj)
      source_object = glib::wrap (retobj);

    return glib::wrap (retvalue);
  }

  auto
  SocketListener::accept_socket_finish (const glib::RefPtr<AsyncResult>& result) -> glib::RefPtr<Socket>
  {
    GError* gerror = nullptr;
    const auto retvalue = g_socket_listener_accept_socket_finish (
        gobj (),
        glib::unwrap (result),
        nullptr,
        &gerror);
    if (gerror)
      glib::Error::throw_exception (gerror);

    return glib::wrap (retvalue);
  }

  auto
  SocketListener::accept (glib::RefPtr<Object>& source_object,
                          const glib::RefPtr<Cancellable>& cancellable) -> glib::RefPtr<SocketConnection>
  {
    GError* gerror = nullptr;
    GObject* retobj = nullptr;
    const auto retvalue = g_socket_listener_accept (gobj (),
                                                    &retobj,
                                                    glib::unwrap (cancellable),
                                                    &gerror);
    if (gerror)
      glib::Error::throw_exception (gerror);

    if (retobj)
      source_object = glib::wrap (retobj);

    return glib::wrap (retvalue);
  }

  auto
  SocketListener::accept (glib::RefPtr<Object>& source_object) -> glib::RefPtr<SocketConnection>
  {
    GError* gerror = nullptr;
    GObject* retobj = nullptr;
    const auto retvalue =
        g_socket_listener_accept (gobj (), &retobj, nullptr, &gerror);
    if (gerror)
      glib::Error::throw_exception (gerror);

    if (retobj)
      source_object = glib::wrap (retobj);

    return glib::wrap (retvalue);
  }

  auto
  SocketListener::accept (const glib::RefPtr<Cancellable>& cancellable) -> glib::RefPtr<SocketConnection>
  {
    GError* gerror = nullptr;
    const auto retvalue = g_socket_listener_accept (gobj (),
                                                    nullptr,
                                                    glib::unwrap (cancellable),
                                                    &gerror);
    if (gerror)
      glib::Error::throw_exception (gerror);

    return glib::wrap (retvalue);
  }

  auto
  SocketListener::accept () -> glib::RefPtr<SocketConnection>
  {
    GError* gerror = nullptr;
    const auto retvalue =
        g_socket_listener_accept (gobj (), nullptr, nullptr, &gerror);
    if (gerror)
      glib::Error::throw_exception (gerror);

    return glib::wrap (retvalue);
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
  SocketListener::accept_async (const glib::RefPtr<Cancellable>& cancellable,
                                const SlotAsyncReady& slot) -> void
  {
    const auto slot_copy = new SlotAsyncReady (slot);

    g_socket_listener_accept_async (gobj (),
                                    glib::unwrap (cancellable),
                                    &SignalProxy_async_callback,
                                    slot_copy);
  }

  auto
  SocketListener::accept_finish (const glib::RefPtr<AsyncResult>& result,
                                 glib::RefPtr<Object>& source_object) -> glib::RefPtr<SocketConnection>
  {
    GError* gerror = nullptr;
    GObject* retobj = nullptr;
    const auto retvalue = g_socket_listener_accept_finish (
        gobj (),
        glib::unwrap (result),
        &retobj,
        &gerror);
    if (gerror)
      glib::Error::throw_exception (gerror);
    if (retobj)
      source_object = glib::wrap (retobj);

    return glib::wrap (retvalue);
  }

  auto
  SocketListener::accept_finish (const glib::RefPtr<AsyncResult>& result) -> glib::RefPtr<SocketConnection>
  {
    GError* gerror = nullptr;
    const auto retvalue = g_socket_listener_accept_finish (
        gobj (),
        glib::unwrap (result),
        nullptr,
        &gerror);
    if (gerror)
      glib::Error::throw_exception (gerror);

    return glib::wrap (retvalue);
  }

} // namespace gio

namespace
{
}

namespace glib
{

  auto
  wrap (GSocketListener* object, const bool take_copy) -> RefPtr<gio::SocketListener>
  {
    return glib::make_refptr_for_instance<gio::SocketListener> (
        dynamic_cast<gio::SocketListener*> (
            wrap_auto ((GObject*) object, take_copy)));
  }

} // namespace glib

namespace gio
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
  SocketListener_Class::wrap_new (GObject* object) -> glib::ObjectBase*
  {
    return new SocketListener ((GSocketListener*) object);
  }

  auto
  SocketListener::gobj_copy () -> GSocketListener*
  {
    reference ();
    return gobj ();
  }

  SocketListener::SocketListener (const glib::ConstructParams& construct_params)
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
      Object (glib::ConstructParams (socketlistener_class_.init ()))
  {
  }

  auto
  SocketListener::create () -> glib::RefPtr<SocketListener>
  {
    return glib::make_refptr_for_instance<SocketListener> (
        new SocketListener ());
  }

  auto
  SocketListener::set_backlog (const int listen_backlog) -> void
  {
    g_socket_listener_set_backlog (gobj (), listen_backlog);
  }

  auto
  SocketListener::add_socket (const glib::RefPtr<Socket>& socket,
                              const glib::RefPtr<Object>& source_object) -> bool
  {
    GError* gerror = nullptr;
    const auto retvalue = g_socket_listener_add_socket (
        gobj (),
        glib::unwrap (socket),
        glib::unwrap (source_object),
        &gerror);
    if (gerror)
      glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  SocketListener::add_inet_port (const guint16 port,
                                 const glib::RefPtr<Object>& source_object) -> bool
  {
    GError* gerror = nullptr;
    const auto retvalue = g_socket_listener_add_inet_port (
        gobj (),
        port,
        glib::unwrap (source_object),
        &gerror);
    if (gerror)
      glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  SocketListener::add_any_inet_port (const glib::RefPtr<Object>& source_object) -> guint16
  {
    GError* gerror = nullptr;
    const auto retvalue = g_socket_listener_add_any_inet_port (
        gobj (),
        glib::unwrap (source_object),
        &gerror);
    if (gerror)
      glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  SocketListener::close () -> void
  {
    g_socket_listener_close (gobj ());
  }

  auto
  SocketListener::property_listen_backlog () -> glib::PropertyProxy<int>
  {
    return {this, "listen-backlog"};
  }

  auto
  SocketListener::property_listen_backlog () const -> glib::PropertyProxy_ReadOnly<int>
  {
    return {this, "listen-backlog"};
  }

} // namespace gio
