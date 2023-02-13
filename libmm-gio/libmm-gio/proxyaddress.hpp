
#ifndef _GIOMM_PROXYADDRESS_H
#define _GIOMM_PROXYADDRESS_H


#include <mm/glib/ustring.hpp>
#include <sigc++/sigc++.h>

/* Copyright (C) 2009 The glibmm Development Team
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

#include <mm/gio/inetsocketaddress.hpp>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GProxyAddress = struct _GProxyAddress;
using GProxyAddressClass = struct _GProxyAddressClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gio
{ class GIOMM_API ProxyAddress_Class; } // namespace Gio
#endif //DOXYGEN_SHOULD_SKIP_THIS

namespace Gio
{

/** ProxyAddress - An internet address with proxy information.
 * Support for proxied InetSocketAddress.
 *
 * @ingroup NetworkIO
 * @newin{2,28}
 */

class GIOMM_API ProxyAddress
: public InetSocketAddress
{

#ifndef DOXYGEN_SHOULD_SKIP_THIS

public:
  using CppObjectType = ProxyAddress;
  using CppClassType = ProxyAddress_Class;
  using BaseObjectType = GProxyAddress;
  using BaseClassType = GProxyAddressClass;

  // noncopyable
  ProxyAddress(const ProxyAddress&) = delete;
  auto operator=(const ProxyAddress&) -> ProxyAddress& = delete;

private:  friend class ProxyAddress_Class;
  static CppClassType proxyaddress_class_;

protected:
  explicit ProxyAddress(const Glib::ConstructParams& construct_params);
  explicit ProxyAddress(GProxyAddress* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  ProxyAddress(ProxyAddress&& src) noexcept;
  auto operator=(ProxyAddress&& src) noexcept -> ProxyAddress&;

  ~ProxyAddress() noexcept override;

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS


  static auto get_base_type() -> GType G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GObject.
  auto       gobj() -> GProxyAddress*       { return reinterpret_cast<GProxyAddress*>(gobject_); }

  ///Provides access to the underlying C GObject.
  auto gobj() const -> const GProxyAddress* { return reinterpret_cast<GProxyAddress*>(gobject_); }

  ///Provides access to the underlying C instance. The caller is responsible for unrefing it. Use when directly setting fields in structs.
  auto gobj_copy() -> GProxyAddress*;

private:


protected:
    explicit ProxyAddress(const Glib::RefPtr<InetAddress>& address, guint16 port, const Glib::ustring& protocol, const Glib::ustring& destination_hostname, guint16 destination_port, const Glib::ustring& username =  {}, const Glib::ustring& password =  {});


public:

  static auto create(const Glib::RefPtr<InetAddress>& address, guint16 port, const Glib::ustring& protocol, const Glib::ustring& destination_hostname, guint16 destination_port, const Glib::ustring& username =  {}, const Glib::ustring& password =  {}) -> Glib::RefPtr<ProxyAddress>;


  /** Gets @a proxy's protocol. eg, "socks" or "http"
   *
   * @newin{2,26}
   *
   * @return The @a proxy's protocol.
   */
  auto get_protocol() const -> Glib::ustring;

  /** Gets the protocol that is being spoken to the destination
   * server; eg, "http" or "ftp".
   *
   * @newin{2,34}
   *
   * @return The @a proxy's destination protocol.
   */
  auto get_destination_protocol() const -> Glib::ustring;

  /** Gets @a proxy's destination hostname; that is, the name of the host
   * that will be connected to via the proxy, not the name of the proxy
   * itself.
   *
   * @newin{2,26}
   *
   * @return The @a proxy's destination hostname.
   */
  auto get_destination_hostname() const -> Glib::ustring;

  /** Gets @a proxy's destination port; that is, the port on the
   * destination host that will be connected to via the proxy, not the
   * port number of the proxy itself.
   *
   * @newin{2,26}
   *
   * @return The @a proxy's destination port.
   */
  auto get_destination_port() const -> guint16;


  /** Gets @a proxy's username.
   *
   * @newin{2,26}
   *
   * @return The @a proxy's username.
   */
  auto get_username() const -> Glib::ustring;

  /** Gets @a proxy's password.
   *
   * @newin{2,26}
   *
   * @return The @a proxy's password.
   */
  auto get_password() const -> Glib::ustring;


  /** Gets the proxy URI that @a proxy was constructed from.
   *
   * @newin{2,34}
   *
   * @return The @a proxy's URI, or <tt>nullptr</tt> if unknown.
   */
  auto get_uri() const -> Glib::ustring;


  /** The proxy protocol.
   *
   * Default value: ""
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_protocol() const -> Glib::PropertyProxy_ReadOnly< Glib::ustring >;


  /** The protocol being spoke to the destination host, or <tt>nullptr</tt> if
   * the ProxyAddress doesn't know.
   *
   * @newin{2,34}
   *
   * Default value: ""
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_destination_protocol() const -> Glib::PropertyProxy_ReadOnly< Glib::ustring >;


  /** The proxy destination hostname.
   *
   * Default value: ""
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_destination_hostname() const -> Glib::PropertyProxy_ReadOnly< Glib::ustring >;


  // Don't use guint16 in _WRAP_PROPERTY().
  // There is no Glib::Value<> specialization for guint16.
  // Glib::Value<unsigned int> exists, and guint is a typedef of unsigned int.
  /** The proxy destination port.
   *
   * Default value: 0
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_destination_port() const -> Glib::PropertyProxy_ReadOnly< guint >;


  /** The proxy username.
   *
   * Default value: ""
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_username() const -> Glib::PropertyProxy_ReadOnly< Glib::ustring >;


  /** The proxy password.
   *
   * Default value: ""
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_password() const -> Glib::PropertyProxy_ReadOnly< Glib::ustring >;


  /** The URI string that the proxy was constructed from (or <tt>nullptr</tt>
   * if the creator didn't specify this).
   *
   * @newin{2,34}
   *
   * Default value: ""
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_uri() const -> Glib::PropertyProxy_ReadOnly< Glib::ustring >;


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
   * @relates Gio::ProxyAddress
   */
  GIOMM_API
  auto wrap(GProxyAddress* object, bool take_copy = false) -> Glib::RefPtr<Gio::ProxyAddress>;
}


#endif /* _GIOMM_PROXYADDRESS_H */

