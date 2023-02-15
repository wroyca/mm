// SPDX-License-Identifier: LGPL-2.1-or-later

#include <gio/gio.h>
#include <libmm-gio/socket.hxx>
#include <libmm-gio/socketsource.hxx>
#include <libmm-glib/exceptionhandler.hxx>
#include <libmm-glib/wrap.hxx>

namespace
{

  auto
  giomm_generic_socket_callback (sigc::slot_base* slot, GIOCondition condition) -> gboolean
  {
    g_return_val_if_fail (slot != nullptr, FALSE);

    try
    {
      return (*static_cast<sigc::slot<bool (Glib::IOCondition)>*> (slot)) (
          (Glib::IOCondition) condition);
    }
    catch (...)
    {
      Glib::exception_handlers_invoke ();
    }
    return 0;
  }

  auto
  giomm_signalsocket_callback (GSocket*,
                               const GIOCondition condition,
                               void* user_data) -> gboolean
  {
    sigc::slot_base* const slot =
        Glib::Source::get_slot_from_connection_node (user_data);
    return giomm_generic_socket_callback (slot, condition);
  }

  auto
  giomm_socketsource_callback (GSocket*,
                               const GIOCondition condition,
                               void* user_data) -> gboolean
  {
    sigc::slot_base* const slot =
        Glib::Source::get_slot_from_callback_data (user_data);
    return giomm_generic_socket_callback (slot, condition);
  }

} // namespace

namespace Gio
{

  inline SignalSocket::SignalSocket (GMainContext* context)
    : context_ (context)
  {
  }

  auto
  SignalSocket::connect (const sigc::slot<bool (Glib::IOCondition)>& slot,
                         const Glib::RefPtr<Socket>& socket,
                         Glib::IOCondition condition,
                         const Glib::RefPtr<Cancellable>& cancellable,
                         const int priority) -> sigc::connection
  {
    GSource* const source = g_socket_create_source (socket->gobj (),
                                                    (GIOCondition) condition,
                                                    Glib::unwrap (cancellable));
    return Glib::Source::attach_signal_source (
        slot,
        priority,
        source,
        context_,
        Glib::function_pointer_cast<GSourceFunc> (
            &giomm_signalsocket_callback));
  }

  auto
  signal_socket (const Glib::RefPtr<Glib::MainContext>& context) -> SignalSocket
  {
    return SignalSocket (unwrap (context));
  }

  auto
  SocketSource::create (const Glib::RefPtr<Socket>& socket,
                        const Glib::IOCondition condition,
                        const Glib::RefPtr<Cancellable>& cancellable) -> Glib::RefPtr<SocketSource>
  {
    return Glib::make_refptr_for_instance<SocketSource> (
        new SocketSource (socket, condition, cancellable));
  }

  auto
  SocketSource::create (GSocket* socket,
                        const Glib::IOCondition condition,
                        const Glib::RefPtr<Cancellable>& cancellable) -> Glib::RefPtr<SocketSource>
  {
    return Glib::make_refptr_for_instance<SocketSource> (
        new SocketSource (socket, condition, cancellable));
  }

  SocketSource::SocketSource (const Glib::RefPtr<Socket>& socket,
                              Glib::IOCondition condition,
                              const Glib::RefPtr<Cancellable>& cancellable)
    : IOSource (g_socket_create_source (socket->gobj (),
                                        (GIOCondition) condition,
                                        Glib::unwrap (cancellable)),
                Glib::function_pointer_cast<GSourceFunc> (
                    &giomm_socketsource_callback))
  {
  }

  SocketSource::SocketSource (GSocket* socket,
                              Glib::IOCondition condition,
                              const Glib::RefPtr<Cancellable>& cancellable)
    : IOSource (g_socket_create_source (socket,
                                        (GIOCondition) condition,
                                        Glib::unwrap (cancellable)),
                Glib::function_pointer_cast<GSourceFunc> (
                    &giomm_socketsource_callback))
  {
  }

  SocketSource::~SocketSource () noexcept = default;
} // namespace Gio
