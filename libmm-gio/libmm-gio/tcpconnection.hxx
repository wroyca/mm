
#ifndef _GIOMM_TCPCONNECTION_H
#define _GIOMM_TCPCONNECTION_H


#include <libmm-glib/ustring.hxx>
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

#include <libmm-glib/object.hxx>
#include <libmm-gio/socketconnection.hxx>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GTcpConnection = struct _GTcpConnection;
using GTcpConnectionClass = struct _GTcpConnectionClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gio
{ class GIOMM_API TcpConnection_Class; } // namespace Gio
#endif //DOXYGEN_SHOULD_SKIP_THIS

namespace Gio
{

/**
 * A TCP SocketConnection
 *
 * This is the subclass of SocketConnection that is created
 * for TCP/IP sockets.
 *
 * @newin{2,24}
 * @ingroup NetworkIO
 */

class GIOMM_API TcpConnection : public Gio::SocketConnection
{

#ifndef DOXYGEN_SHOULD_SKIP_THIS

public:
  using CppObjectType = TcpConnection;
  using CppClassType = TcpConnection_Class;
  using BaseObjectType = GTcpConnection;
  using BaseClassType = GTcpConnectionClass;

  // noncopyable
  TcpConnection(const TcpConnection&) = delete;
  auto operator=(const TcpConnection&) -> TcpConnection& = delete;

private:  friend class TcpConnection_Class;
  static CppClassType tcpconnection_class_;

protected:
  explicit TcpConnection(const Glib::ConstructParams& construct_params);
  explicit TcpConnection(GTcpConnection* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  TcpConnection(TcpConnection&& src) noexcept;
  auto operator=(TcpConnection&& src) noexcept -> TcpConnection&;

  ~TcpConnection() noexcept override;

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS


  static auto get_base_type() -> GType G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GObject.
  auto       gobj() -> GTcpConnection*       { return reinterpret_cast<GTcpConnection*>(gobject_); }

  ///Provides access to the underlying C GObject.
  auto gobj() const -> const GTcpConnection* { return reinterpret_cast<GTcpConnection*>(gobject_); }

  ///Provides access to the underlying C instance. The caller is responsible for unrefing it. Use when directly setting fields in structs.
  auto gobj_copy() -> GTcpConnection*;

private:


public:

  /** This enables graceful disconnects on close. A graceful disconnect
   * means that we signal the receiving end that the connection is terminated
   * and wait for it to close the connection before closing the connection.
   *
   * A graceful disconnect means that we can be sure that we successfully sent
   * all the outstanding data to the other end, or get an error reported.
   * However, it also means we have to wait for all the data to reach the
   * other side and for it to acknowledge this by closing the socket, which may
   * take a while. For this reason it is disabled by default.
   *
   * @newin{2,22}
   *
   * @param graceful_disconnect Whether to do graceful disconnects or not.
   */
  void set_graceful_disconnect(bool graceful_disconnect);

  /** Checks if graceful disconnects are used. See
   * g_tcp_connection_set_graceful_disconnect().
   *
   * @newin{2,22}
   *
   * @return <tt>true</tt> if graceful disconnect is used on close, <tt>false</tt> otherwise.
   */
  auto get_graceful_disconnect() const -> bool;

    /** Whether or not close does a graceful disconnect.
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_graceful_disconnect() -> Glib::PropertyProxy< bool > ;

/** Whether or not close does a graceful disconnect.
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_graceful_disconnect() const -> Glib::PropertyProxy_ReadOnly< bool >;


public:

public:
  //C++ methods used to invoke GTK+ virtual functions:

protected:
  //GTK+ Virtual Functions (override these to change behaviour):

  //Default Signal Handlers::


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
   * @relates Gio::TcpConnection
   */
  GIOMM_API
  auto wrap(GTcpConnection* object, bool take_copy = false) -> Glib::RefPtr<Gio::TcpConnection>;
}


#endif /* _GIOMM_TCPCONNECTION_H */

