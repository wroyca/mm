// SPDX-License-Identifier: LGPL-2.1-or-later

#include <gio/gio.h>
#include <libmm/gio/socket.hxx>
#include <libmm/gio/socketsource.hxx>
#include <libmm/glib/exceptionhandler.hxx>
#include <libmm/glib/wrap.hxx>

namespace
{

  auto
  giomm_generic_socket_callback (sigc::slot_base* slot, GIOCondition condition) -> gboolean
  {
    g_return_val_if_fail (slot != nullptr, FALSE);

    try
    {
      return (*static_cast<sigc::slot<bool (glib::IOCondition)>*> (slot)) (
          (glib::IOCondition) condition);
    }
    catch (...)
    {
      glib::exception_handlers_invoke ();
    }
    return 0;
  }

  auto
  giomm_signalsocket_callback (GSocket*,
                               const GIOCondition condition,
                               void* user_data) -> gboolean
  {
    sigc::slot_base* const slot =
        glib::Source::get_slot_from_connection_node (user_data);
    return giomm_generic_socket_callback (slot, condition);
  }

  auto
  giomm_socketsource_callback (GSocket*,
                               const GIOCondition condition,
                               void* user_data) -> gboolean
  {
    sigc::slot_base* const slot =
        glib::Source::get_slot_from_callback_data (user_data);
    return giomm_generic_socket_callback (slot, condition);
  }

} // namespace

namespace gio
{

  inline SignalSocket::SignalSocket (GMainContext* context)
    : context_ (context)
  {
  }

  auto
  SignalSocket::connect (const sigc::slot<bool (glib::IOCondition)>& slot,
                         const glib::RefPtr<Socket>& socket,
                         glib::IOCondition condition,
                         const glib::RefPtr<Cancellable>& cancellable,
                         const int priority) -> sigc::connection
  {
    GSource* const source = g_socket_create_source (socket->gobj (),
                                                    (GIOCondition) condition,
                                                    glib::unwrap (cancellable));
    return glib::Source::attach_signal_source (
        slot,
        priority,
        source,
        context_,
        glib::function_pointer_cast<GSourceFunc> (
            &giomm_signalsocket_callback));
  }

  auto
  signal_socket (const glib::RefPtr<glib::MainContext>& context) -> SignalSocket
  {
    return SignalSocket (unwrap (context));
  }

  auto
  SocketSource::create (const glib::RefPtr<Socket>& socket,
                        const glib::IOCondition condition,
                        const glib::RefPtr<Cancellable>& cancellable) -> glib::RefPtr<SocketSource>
  {
    return glib::make_refptr_for_instance<SocketSource> (
        new SocketSource (socket, condition, cancellable));
  }

  auto
  SocketSource::create (GSocket* socket,
                        const glib::IOCondition condition,
                        const glib::RefPtr<Cancellable>& cancellable) -> glib::RefPtr<SocketSource>
  {
    return glib::make_refptr_for_instance<SocketSource> (
        new SocketSource (socket, condition, cancellable));
  }

  SocketSource::SocketSource (const glib::RefPtr<Socket>& socket,
                              glib::IOCondition condition,
                              const glib::RefPtr<Cancellable>& cancellable)
    : IOSource (g_socket_create_source (socket->gobj (),
                                        (GIOCondition) condition,
                                        glib::unwrap (cancellable)),
                glib::function_pointer_cast<GSourceFunc> (
                    &giomm_socketsource_callback))
  {
  }

  SocketSource::SocketSource (GSocket* socket,
                              glib::IOCondition condition,
                              const glib::RefPtr<Cancellable>& cancellable)
    : IOSource (g_socket_create_source (socket,
                                        (GIOCondition) condition,
                                        glib::unwrap (cancellable)),
                glib::function_pointer_cast<GSourceFunc> (
                    &giomm_socketsource_callback))
  {
  }

  SocketSource::~SocketSource () noexcept = default;
} // namespace gio
