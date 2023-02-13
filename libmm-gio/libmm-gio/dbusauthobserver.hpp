
#ifndef _GIOMM_DBUSAUTHOBSERVER_H
#define _GIOMM_DBUSAUTHOBSERVER_H


#include <libmm-glib/ustring.hpp>
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

#include <libmm-glib/object.hpp>
#include <libmm-gio/credentials.hpp>
#include <libmm-gio/iostream.hpp>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GDBusAuthObserver = struct _GDBusAuthObserver;
using GDBusAuthObserverClass = struct _GDBusAuthObserverClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gio::DBus
{ class GIOMM_API AuthObserver_Class; } // namespace Gio
#endif //DOXYGEN_SHOULD_SKIP_THIS

namespace Gio::DBus
{


/** AuthObserver - An object used for authenticating connections.
 * The AuthObserver type provides a mechanism for participating in how a
 * Server (or a Connection) authenticates remote peers.  Simply
 * instantiate an AuthObserver and connect to the signals you are
 * interested in. Note that new signals may be added in the future.
 *
 * For example, if you only want to allow D-Bus connections from
 * processes owned by the same uid as the server, you would use a
 * signal handler like the following:
 * @code
 * bool on_authorize_authenticated_peer(
 *   const Glib::RefPtr<const Gio::IOStream>&,
 *   const Glib::RefPtr<const Gio::Credentials>& credentials)
 * {
 *   bool authorized = false;
 *
 *   if (credentials)
 *   {
 *     Glib::RefPtr<Gio::Credentials> own_credentials = Gio::Credentials::create();
 *     try
 *     {
 *       if (credentials->is_same_user(own_credentials))
 *         authorized = true;
 *     }
 *     catch (const Gio::Error& ex)
 *     {
 *       std::cerr << "Gio::Error: " << ex.what() << std::endl;
 *     }
 *   }
 *
 *   return authorized;
 * }
 * @endcode
 *
 * @newin{2,28}
 * @ingroup DBus
 */

class GIOMM_API AuthObserver : public Glib::Object
{

#ifndef DOXYGEN_SHOULD_SKIP_THIS

public:
  using CppObjectType = AuthObserver;
  using CppClassType = AuthObserver_Class;
  using BaseObjectType = GDBusAuthObserver;
  using BaseClassType = GDBusAuthObserverClass;

  // noncopyable
  AuthObserver(const AuthObserver&) = delete;
  auto operator=(const AuthObserver&) -> AuthObserver& = delete;

private:  friend class AuthObserver_Class;
  static CppClassType authobserver_class_;

protected:
  explicit AuthObserver(const Glib::ConstructParams& construct_params);
  explicit AuthObserver(GDBusAuthObserver* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  AuthObserver(AuthObserver&& src) noexcept;
  auto operator=(AuthObserver&& src) noexcept -> AuthObserver&;

  ~AuthObserver() noexcept override;

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS


  static auto get_base_type() -> GType G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GObject.
  auto       gobj() -> GDBusAuthObserver*       { return reinterpret_cast<GDBusAuthObserver*>(gobject_); }

  ///Provides access to the underlying C GObject.
  auto gobj() const -> const GDBusAuthObserver* { return reinterpret_cast<GDBusAuthObserver*>(gobject_); }

  ///Provides access to the underlying C instance. The caller is responsible for unrefing it. Use when directly setting fields in structs.
  auto gobj_copy() -> GDBusAuthObserver*;

private:


protected:
  AuthObserver();


public:

  static auto create() -> Glib::RefPtr<AuthObserver>;


  /** Emits the Gio::DBus::AuthObserver::signal_authorize_authenticated_peer() signal on @a observer.
   *
   * @newin{2,26}
   *
   * @param stream A IOStream for the Gio::DBus::Connection.
   * @param credentials Credentials received from the peer or <tt>nullptr</tt>.
   * @return <tt>true</tt> if the peer is authorized, <tt>false</tt> if not.
   */
  auto authorize_authenticated_peer(const Glib::RefPtr<const IOStream>& stream, const Glib::RefPtr<const Credentials>& credentials) -> bool;

  /** Emits the Gio::DBus::AuthObserver::signal_allow_mechanism() signal on @a observer.
   *
   * @newin{2,34}
   *
   * @param mechanism The name of the mechanism, e.g. `DBUS_COOKIE_SHA1`.
   * @return <tt>true</tt> if @a mechanism can be used to authenticate the other peer, <tt>false</tt> if not.
   */
  auto allow_mechanism(const std::string& mechanism) -> bool;


  /**
   * @par Slot Prototype:
   * <tt>bool on_my_%authorize_authenticated_peer(const Glib::RefPtr<const IOStream>& stream, const Glib::RefPtr<const Credentials>& credentials)</tt>
   *
   * Flags: Run Last
   *
   * Emitted to check if a peer that is successfully authenticated
   * is authorized.
   *
   * @newin{2,26}
   *
   * @param stream A IOStream for the Gio::DBus::Connection.
   * @param credentials Credentials received from the peer or <tt>nullptr</tt>.
   * @return <tt>true</tt> if the peer is authorized, <tt>false</tt> if not.
   */

  auto signal_authorize_authenticated_peer() -> Glib::SignalProxy<bool(const Glib::RefPtr<const IOStream>&, const Glib::RefPtr<const Credentials>&)>;


  /**
   * @par Slot Prototype:
   * <tt>bool on_my_%allow_mechanism(const std::string& mechanism)</tt>
   *
   * Flags: Run Last
   *
   * Emitted to check if @a mechanism is allowed to be used.
   *
   * @newin{2,34}
   *
   * @param mechanism The name of the mechanism, e.g. `DBUS_COOKIE_SHA1`.
   * @return <tt>true</tt> if @a mechanism can be used to authenticate the other peer, <tt>false</tt> if not.
   */

  auto signal_allow_mechanism() -> Glib::SignalProxy<bool(const std::string&)>;


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
   * @relates Gio::DBus::AuthObserver
   */
  GIOMM_API
  auto wrap(GDBusAuthObserver* object, bool take_copy = false) -> Glib::RefPtr<Gio::DBus::AuthObserver>;
}


#endif /* _GIOMM_DBUSAUTHOBSERVER_H */

