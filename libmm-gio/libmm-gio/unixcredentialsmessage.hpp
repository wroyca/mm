
#ifndef _GIOMM_UNIXCREDENTIALSMESSAGE_H
#define _GIOMM_UNIXCREDENTIALSMESSAGE_H


#include <mm/glib/ustring.hpp>
#include <sigc++/sigc++.h>

/* Copyright (C) 2010 The giomm Development Team
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

#include <mm/gio/socketcontrolmessage.hpp>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GUnixCredentialsMessage = struct _GUnixCredentialsMessage;
using GUnixCredentialsMessageClass = struct _GUnixCredentialsMessageClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gio
{ class GIOMM_API UnixCredentialsMessage_Class; } // namespace Gio
#endif //DOXYGEN_SHOULD_SKIP_THIS

namespace Gio
{

class GIOMM_API Credentials;

/** UnixCredentialsMessage - A SocketControlMessage containing credentials.
 * This SocketControlMessage contains a Credentials instance. It may be sent
 * using Gio::Socket::send() and received using Gio::Socket::receive()
 * over UNIX sockets (ie: sockets in the Gio::SOCKET_FAMILY_UNIX family).
 *
 * For an easier way to send and receive credentials over stream-oriented UNIX
 * sockets, see Gio::UnixConnection::send_credentials() and
 * Gio::UnixConnection::receive_credentials(). To receive credentials of a
 * foreign process connected to a socket, use Gio::Socket::get_credentials().
 *
 * @ingroup NetworkIO
 * @newin{2,28}
 */

class GIOMM_API UnixCredentialsMessage : public SocketControlMessage
{

#ifndef DOXYGEN_SHOULD_SKIP_THIS

public:
  using CppObjectType = UnixCredentialsMessage;
  using CppClassType = UnixCredentialsMessage_Class;
  using BaseObjectType = GUnixCredentialsMessage;
  using BaseClassType = GUnixCredentialsMessageClass;

  // noncopyable
  UnixCredentialsMessage(const UnixCredentialsMessage&) = delete;
  auto operator=(const UnixCredentialsMessage&) -> UnixCredentialsMessage& = delete;

private:  friend class UnixCredentialsMessage_Class;
  static CppClassType unixcredentialsmessage_class_;

protected:
  explicit UnixCredentialsMessage(const Glib::ConstructParams& construct_params);
  explicit UnixCredentialsMessage(GUnixCredentialsMessage* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  UnixCredentialsMessage(UnixCredentialsMessage&& src) noexcept;
  auto operator=(UnixCredentialsMessage&& src) noexcept -> UnixCredentialsMessage&;

  ~UnixCredentialsMessage() noexcept override;

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS


  static auto get_base_type() -> GType G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GObject.
  auto       gobj() -> GUnixCredentialsMessage*       { return reinterpret_cast<GUnixCredentialsMessage*>(gobject_); }

  ///Provides access to the underlying C GObject.
  auto gobj() const -> const GUnixCredentialsMessage* { return reinterpret_cast<GUnixCredentialsMessage*>(gobject_); }

  ///Provides access to the underlying C instance. The caller is responsible for unrefing it. Use when directly setting fields in structs.
  auto gobj_copy() -> GUnixCredentialsMessage*;

private:

  //This is not available on Win32.
//This source file will not be compiled on Win32,
//and no class defined in it will be registered by wrap_init().


protected:
  UnixCredentialsMessage();
    explicit UnixCredentialsMessage(const Glib::RefPtr<Credentials>& credentials);


public:

  /** Creates a new UnixCredentialsMessage with credentials matching the current processes.
   *
   * @newin{2,26}
   *
   * @return A new UnixCredentialsMessage.
   */


  static auto create() -> Glib::RefPtr<UnixCredentialsMessage>;


  /** Creates a new UnixCredentialsMessage holding @a credentials.
   *
   * @newin{2,26}
   *
   * @param credentials A Credentials object.
   * @return A new UnixCredentialsMessage.
   */


  static auto create(const Glib::RefPtr<Credentials>& credentials) -> Glib::RefPtr<UnixCredentialsMessage>;


  /** Gets the credentials stored in @a message.
   *
   * @newin{2,26}
   *
   * @return A Credentials instance. Do not free, it is owned by @a message.
   */
  auto get_credentials() -> Glib::RefPtr<Credentials>;

  /** Gets the credentials stored in @a message.
   *
   * @newin{2,26}
   *
   * @return A Credentials instance. Do not free, it is owned by @a message.
   */
  auto get_credentials() const -> Glib::RefPtr<const Credentials>;

  /** Checks if passing Credentials on a Socket is supported on this platform.
   *
   * @newin{2,26}
   *
   * @return <tt>true</tt> if supported, <tt>false</tt> otherwise.
   */
  static auto is_supported() -> bool;

  /** The credentials stored in the message.
   *
   * @newin{2,26}
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_credentials() const -> Glib::PropertyProxy_ReadOnly< Glib::RefPtr<Credentials> >;


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
   * @relates Gio::UnixCredentialsMessage
   */
  GIOMM_API
  auto wrap(GUnixCredentialsMessage* object, bool take_copy = false) -> Glib::RefPtr<Gio::UnixCredentialsMessage>;
}


#endif /* _GIOMM_UNIXCREDENTIALSMESSAGE_H */

