// Generated by gmmproc 2.74.0 -- DO NOT MODIFY!
#ifndef _GIOMM_SOCKETSERVICE_H
#define _GIOMM_SOCKETSERVICE_H


#include <mm/glib/ustring.hpp>
#include <sigc++/sigc++.h>

/* Copyright (C) 2010 Jonathon Jongsma
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <mm/gio/socketlistener.hpp>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GSocketService = struct _GSocketService;
using GSocketServiceClass = struct _GSocketServiceClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gio
{ class GIOMM_API SocketService_Class; } // namespace Gio
#endif //DOXYGEN_SHOULD_SKIP_THIS

namespace Gio
{

/** Make it easy to implement a network service.
 *
 * @see ThreadedSocketService, SocketListener.
 *
 * A %SocketService is an object that represents a service that is
 * provided to the network or over local sockets.  When a new
 * connection is made to the service signal_incoming() is emitted.
 *
 * A %SocketService is a subclass of SocketListener and you need
 * to add the addresses you want to accept connections on with the
 * SocketListener APIs.
 *
 * There are two options for implementing a network service based on
 * %SocketService. The first is to create the service using
 * create() and to connect to signal_incoming().
 * The second is to subclass %SocketService and override the
 * default signal handler implementation, on_incoming().
 *
 * In either case, the handler must immediately return, or else it
 * will block additional incoming connections from being serviced.
 * If you are interested in writing connection handlers that contain
 * blocking code then see ThreadedSocketService.
 *
 * The socket service runs on the main loop of the thread-default context
 * of the thread it is created in, and is not
 * threadsafe in general. However, the calls to start and stop
 * the service are threadsafe so these can be used from threads that
 * handle incoming clients.
 *
 * @newin{2,24}
 * @ingroup NetworkIO
 */

class GIOMM_API SocketService : public Gio::SocketListener
{

#ifndef DOXYGEN_SHOULD_SKIP_THIS

public:
  using CppObjectType = SocketService;
  using CppClassType = SocketService_Class;
  using BaseObjectType = GSocketService;
  using BaseClassType = GSocketServiceClass;

  // noncopyable
  SocketService(const SocketService&) = delete;
  auto operator=(const SocketService&) -> SocketService& = delete;

private:  friend class SocketService_Class;
  static CppClassType socketservice_class_;

protected:
  explicit SocketService(const Glib::ConstructParams& construct_params);
  explicit SocketService(GSocketService* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  SocketService(SocketService&& src) noexcept;
  auto operator=(SocketService&& src) noexcept -> SocketService&;

  ~SocketService() noexcept override;

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS


  static auto get_base_type() -> GType G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GObject.
  auto       gobj() -> GSocketService*       { return reinterpret_cast<GSocketService*>(gobject_); }

  ///Provides access to the underlying C GObject.
  auto gobj() const -> const GSocketService* { return reinterpret_cast<GSocketService*>(gobject_); }

  ///Provides access to the underlying C instance. The caller is responsible for unrefing it. Use when directly setting fields in structs.
  auto gobj_copy() -> GSocketService*;

private:


protected:
  SocketService();

public:

  static auto create() -> Glib::RefPtr<SocketService>;


  /** Restarts the service, i.e.\ start accepting connections
   * from the added sockets when the mainloop runs. This only needs
   * to be called after the service has been stopped from
   * g_socket_service_stop().
   *
   * This call is thread-safe, so it may be called from a thread
   * handling an incoming client request.
   *
   * @newin{2,22}
   */
  void start();

  /** Stops the service, i.e.\ stops accepting connections
   * from the added sockets when the mainloop runs.
   *
   * This call is thread-safe, so it may be called from a thread
   * handling an incoming client request.
   *
   * Note that this only stops accepting new connections; it does not
   * close the listening sockets, and you can call
   * g_socket_service_start() again later to begin listening again. To
   * close the listening sockets, call g_socket_listener_close(). (This
   * will happen automatically when the SocketService is finalized.)
   *
   * This must be called before calling g_socket_listener_close() as
   * the socket service will start accepting connections immediately
   * when a new socket is added.
   *
   * @newin{2,22}
   */
  void stop();

  /** Check whether the service is active or not. An active
   * service will accept new clients that connect, while
   * a non-active service will let connecting clients queue
   * up until the service is started.
   *
   * @newin{2,22}
   *
   * @return <tt>true</tt> if the service is active, <tt>false</tt> otherwise.
   */
  auto is_active() -> bool;


  /**
   * @par Slot Prototype:
   * <tt>bool on_my_%incoming(const Glib::RefPtr<SocketConnection>& connection, const Glib::RefPtr<Glib::Object>& source_object)</tt>
   *
   * Flags: Run Last
   *
   * The signal_incoming() signal is emitted when a new incoming connection
   * to @a service needs to be handled. The handler must initiate the
   * handling of @a connection, but may not block; in essence,
   * asynchronous operations must be used.
   *
   *  @a connection will be unreffed once the signal handler returns,
   * so you need to ref it yourself if you are planning to use it.
   *
   * @newin{2,22}
   *
   * @param connection A new SocketConnection object.
   * @param source_object The source_object passed to
   * g_socket_listener_add_address().
   * @return <tt>true</tt> to stop other handlers from being called.
   */

  auto signal_incoming() -> Glib::SignalProxy<bool(const Glib::RefPtr<SocketConnection>&, const Glib::RefPtr<Glib::Object>&)>;


  /** Whether the service is currently accepting connections.
   *
   * @newin{2,46}
   *
   * Default value: <tt>true</tt>
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_active() -> Glib::PropertyProxy< bool > ;

/** Whether the service is currently accepting connections.
   *
   * @newin{2,46}
   *
   * Default value: <tt>true</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_active() const -> Glib::PropertyProxy_ReadOnly< bool >;


public:

public:
  //C++ methods used to invoke GTK+ virtual functions:

protected:
  //GTK+ Virtual Functions (override these to change behaviour):

  //Default Signal Handlers::
  /// This is a default handler for the signal signal_incoming().
  virtual auto on_incoming(const Glib::RefPtr<SocketConnection>& connection, const Glib::RefPtr<Glib::Object>& source_object) -> bool;


};

} // namespace Gio


namespace Glib
{
  /** A Glib::wrap() method for this object.
   *
   * @param object The C instance.
   * @param take_copy False if the result should take ownership of the C instance. True if it should take a new copy or ref.
   * @result A C++ instance that wraps this C instance.
   *
   * @relates Gio::SocketService
   */
  GIOMM_API
  auto wrap(GSocketService* object, bool take_copy = false) -> Glib::RefPtr<Gio::SocketService>;
}


#endif /* _GIOMM_SOCKETSERVICE_H */

