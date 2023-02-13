
#ifndef _GIOMM_TLSSERVERCONNECTION_H
#define _GIOMM_TLSSERVERCONNECTION_H


#include <libmm-glib/ustring.hpp>
#include <sigc++/sigc++.h>

/* Copyright (C) 2013 The giomm Development Team
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

#include <libmm-glib/interface.hpp>
#include <libmm-gio/enums.hpp>
#include <libmm-gio/iostream.hpp>
#include <libmm-gio/tlscertificate.hpp>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
typedef struct _GTlsServerConnectionInterface GTlsServerConnectionInterface;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GTlsServerConnection = struct _GTlsServerConnection;
using GTlsServerConnectionClass = struct _GTlsServerConnectionClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gio
{ class GIOMM_API TlsServerConnection_Class; } // namespace Gio
#endif // DOXYGEN_SHOULD_SKIP_THIS

namespace Gio
{

class GIOMM_API TlsServerConnectionImpl;

// See https://bugzilla.gnome.org/show_bug.cgi?id=776537
// especially the last paragraph of comment 6.

/** TLS server-side connection.
 * %TlsServerConnection is the server-side subclass of TlsConnection,
 * representing a server-side TLS connection.
 * @newin{2,36}
 */

class GIOMM_API TlsServerConnection : public Glib::Interface
{

#ifndef DOXYGEN_SHOULD_SKIP_THIS

public:
  using CppObjectType = TlsServerConnection;
  using CppClassType = TlsServerConnection_Class;
  using BaseObjectType = GTlsServerConnection;
  using BaseClassType = GTlsServerConnectionInterface;

  // noncopyable
  TlsServerConnection(const TlsServerConnection&) = delete;
  auto operator=(const TlsServerConnection&) -> TlsServerConnection& = delete;

private:
  friend class TlsServerConnection_Class;
  static CppClassType tlsserverconnection_class_;

#endif /* DOXYGEN_SHOULD_SKIP_THIS */
protected:
  /**
   * You should derive from this class to use it.
   */
  TlsServerConnection();

#ifndef DOXYGEN_SHOULD_SKIP_THIS
  /** Called by constructors of derived classes. Provide the result of
   * the Class init() function to ensure that it is properly
   * initialized.
   *
   * @param interface_class The Class object for the derived type.
   */
  explicit TlsServerConnection(const Glib::Interface_Class& interface_class);

public:
  // This is public so that C++ wrapper instances can be
  // created for C instances of unwrapped types.
  // For instance, if an unexpected C type implements the C interface.
  explicit TlsServerConnection(GTlsServerConnection* castitem);

protected:
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  TlsServerConnection(TlsServerConnection&& src) noexcept;
  auto operator=(TlsServerConnection&& src) noexcept -> TlsServerConnection&;

  ~TlsServerConnection() noexcept override;

  static void add_interface(GType gtype_implementer);

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS
  static auto get_base_type() -> GType G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GObject.
  auto       gobj() -> GTlsServerConnection*       { return reinterpret_cast<GTlsServerConnection*>(gobject_); }

  ///Provides access to the underlying C GObject.
  auto gobj() const -> const GTlsServerConnection* { return reinterpret_cast<GTlsServerConnection*>(gobject_); }

private:


public:
  // It's not possible to use _WRAP_CTOR/_WRAP_CREATE to wrap the new
  // function because this is an interface.


  /** Creates a new TlsServerConnection wrapping @a base_io_stream (which
   * must have pollable input and output streams).
   *
   * See the documentation for TlsConnection::property_base_io_stream() for restrictions
   * on when application code can run operations on the @a base_io_stream after
   * this function has returned.
   *
   * @newin{2,28}
   *
   * @param base_io_stream The IOStream to wrap.
   * @param certificate The default server certificate, or <tt>nullptr</tt>.
   * @return The new
   * TlsServerConnection, or <tt>nullptr</tt> on error.
   *
   * @throws Glib::Error
   */
  static auto create(const Glib::RefPtr<IOStream>& base_io_stream, const Glib::RefPtr<TlsCertificate>& certificate) -> Glib::RefPtr<TlsServerConnectionImpl>;

  /** The TlsAuthenticationMode for the server. This can be changed
   * before calling g_tls_connection_handshake() if you want to
   * rehandshake with a different mode from the initial handshake.
   *
   * @newin{2,28}
   *
   * Default value: Gio::GTlsAuthenticationMode::NONE
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_authentication_mode() -> Glib::PropertyProxy< TlsAuthenticationMode > ;

/** The TlsAuthenticationMode for the server. This can be changed
   * before calling g_tls_connection_handshake() if you want to
   * rehandshake with a different mode from the initial handshake.
   *
   * @newin{2,28}
   *
   * Default value: Gio::GTlsAuthenticationMode::NONE
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_authentication_mode() const -> Glib::PropertyProxy_ReadOnly< TlsAuthenticationMode >;


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
   * @relates Gio::TlsServerConnection
   */
  GIOMM_API
  auto wrap(GTlsServerConnection* object, bool take_copy = false) -> Glib::RefPtr<Gio::TlsServerConnection>;

} // namespace Glib


#endif /* _GIOMM_TLSSERVERCONNECTION_H */

