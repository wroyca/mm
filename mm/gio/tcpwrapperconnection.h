// Generated by gmmproc 2.74.0 -- DO NOT MODIFY!
#ifndef _GIOMM_TCPWRAPPERCONNECTION_H
#define _GIOMM_TCPWRAPPERCONNECTION_H


#include <mm/glib/ustring.h>
#include <sigc++/sigc++.h>

/* Copyright (C) 2015 The giomm Development Team
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

#include <mm/gio/tcpconnection.h>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GTcpWrapperConnection = struct _GTcpWrapperConnection;
using GTcpWrapperConnectionClass = struct _GTcpWrapperConnectionClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gio
{ class GIOMM_API TcpWrapperConnection_Class; } // namespace Gio
#endif //DOXYGEN_SHOULD_SKIP_THIS

namespace Gio
{

/** Wrapper for non-Gio::SocketConnection-based, Gio::Socket-based Gio::IOStreams.
 *
 * This can be used to wrap a Gio::Stream that is
 * based on a Gio::Socket, but which is not actually a
 * Gio::SocketConnection. This is used by Gio::SocketClient so that it can
 * always return a Gio::SocketConnection, even when the connection it has
 * actually created is not directly a Gio::SocketConnection.
 *
 * @newin{2,44}
 * @ingroup NetworkIO
 */

class GIOMM_API TcpWrapperConnection : public Gio::TcpConnection
{

#ifndef DOXYGEN_SHOULD_SKIP_THIS

public:
  using CppObjectType = TcpWrapperConnection;
  using CppClassType = TcpWrapperConnection_Class;
  using BaseObjectType = GTcpWrapperConnection;
  using BaseClassType = GTcpWrapperConnectionClass;

  // noncopyable
  TcpWrapperConnection(const TcpWrapperConnection&) = delete;
  auto operator=(const TcpWrapperConnection&) -> TcpWrapperConnection& = delete;

private:  friend class TcpWrapperConnection_Class;
  static CppClassType tcpwrapperconnection_class_;

protected:
  explicit TcpWrapperConnection(const Glib::ConstructParams& construct_params);
  explicit TcpWrapperConnection(GTcpWrapperConnection* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  TcpWrapperConnection(TcpWrapperConnection&& src) noexcept;
  auto operator=(TcpWrapperConnection&& src) noexcept -> TcpWrapperConnection&;

  ~TcpWrapperConnection() noexcept override;

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS


  static auto get_base_type() -> GType G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GObject.
  auto       gobj() -> GTcpWrapperConnection*       { return reinterpret_cast<GTcpWrapperConnection*>(gobject_); }

  ///Provides access to the underlying C GObject.
  auto gobj() const -> const GTcpWrapperConnection* { return reinterpret_cast<GTcpWrapperConnection*>(gobject_); }

  ///Provides access to the underlying C instance. The caller is responsible for unrefing it. Use when directly setting fields in structs.
  auto gobj_copy() -> GTcpWrapperConnection*;

private:


public:

    explicit TcpWrapperConnection(const Glib::RefPtr<IOStream>& base_io_stream, const Glib::RefPtr<Socket>& socket);


  /** Gets @a conn's base IOStream
   *
   * @return  @a conn's base IOStream.
   */
  auto get_base_io_stream() -> Glib::RefPtr<IOStream>;

  /** Gets @a conn's base IOStream
   *
   * @return  @a conn's base IOStream.
   */
  auto get_base_io_stream() const -> Glib::RefPtr<const IOStream>;

  /** The wrapped GIOStream.
   *
   * @newin{2,44}
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_base_io_stream() const -> Glib::PropertyProxy_ReadOnly< Glib::RefPtr<IOStream> >;


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
   * @relates Gio::TcpWrapperConnection
   */
  GIOMM_API
  auto wrap(GTcpWrapperConnection* object, bool take_copy = false) -> Glib::RefPtr<Gio::TcpWrapperConnection>;
}


#endif /* _GIOMM_TCPWRAPPERCONNECTION_H */
