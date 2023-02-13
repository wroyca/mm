
#ifndef _GIOMM_NETWORKADDRESS_H
#define _GIOMM_NETWORKADDRESS_H


#include <mm/glib/ustring.hpp>
#include <sigc++/sigc++.h>

/* Copyright (C) 2007 The giomm Development Team
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

#include <mm/glib/object.hpp>
#include <mm/gio/socketconnectable.hpp>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GNetworkAddress = struct _GNetworkAddress;
using GNetworkAddressClass = struct _GNetworkAddressClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gio
{ class GIOMM_API NetworkAddress_Class; } // namespace Gio
#endif //DOXYGEN_SHOULD_SKIP_THIS

namespace Gio
{

/** A SocketConnectable for resolving hostnames
 *
 * NetworkAddress provides an easy way to resolve a hostname and then attempt to
 * connect to that host, handling the possibility of multiple IP addresses and
 * multiple address families.
 *
 * @newin{2,24}
 * @ingroup NetworkIO
 */

class GIOMM_API NetworkAddress : public Glib::Object,
    public SocketConnectable
{

#ifndef DOXYGEN_SHOULD_SKIP_THIS

public:
  using CppObjectType = NetworkAddress;
  using CppClassType = NetworkAddress_Class;
  using BaseObjectType = GNetworkAddress;
  using BaseClassType = GNetworkAddressClass;

  // noncopyable
  NetworkAddress(const NetworkAddress&) = delete;
  auto operator=(const NetworkAddress&) -> NetworkAddress& = delete;

private:  friend class NetworkAddress_Class;
  static CppClassType networkaddress_class_;

protected:
  explicit NetworkAddress(const Glib::ConstructParams& construct_params);
  explicit NetworkAddress(GNetworkAddress* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  NetworkAddress(NetworkAddress&& src) noexcept;
  auto operator=(NetworkAddress&& src) noexcept -> NetworkAddress&;

  ~NetworkAddress() noexcept override;

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS


  static auto get_base_type() -> GType G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GObject.
  auto       gobj() -> GNetworkAddress*       { return reinterpret_cast<GNetworkAddress*>(gobject_); }

  ///Provides access to the underlying C GObject.
  auto gobj() const -> const GNetworkAddress* { return reinterpret_cast<GNetworkAddress*>(gobject_); }

  ///Provides access to the underlying C instance. The caller is responsible for unrefing it. Use when directly setting fields in structs.
  auto gobj_copy() -> GNetworkAddress*;

private:


    explicit NetworkAddress(const std::string& hostname, guint16 port);


public:

  static auto create(const std::string& hostname, guint16 port) -> Glib::RefPtr<NetworkAddress>;


  /** Gets @a addr's hostname. This might be either UTF-8 or ASCII-encoded,
   * depending on what @a addr was created with.
   *
   * @newin{2,22}
   *
   * @return  @a addr's hostname.
   */
  auto get_hostname() const -> std::string;

  /** Gets @a addr's port number
   *
   * @newin{2,22}
   *
   * @return  @a addr's port (which may be 0).
   */
  auto get_port() const -> guint16;

  /** Gets @a addr's scheme
   *
   * @newin{2,26}
   *
   * @return  @a addr's scheme (<tt>nullptr</tt> if not built from URI).
   */
  auto get_scheme() const -> std::string;

  static auto parse(const std::string& host_and_port, guint16 default_port) -> Glib::RefPtr<NetworkAddress>;

  /** Hostname to resolve.
   *
   * Default value: ""
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_hostname() const -> Glib::PropertyProxy_ReadOnly< std::string >;


  /** Network port.
   *
   * Default value: 0
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_port() const -> Glib::PropertyProxy_ReadOnly< guint >;


  /** URI Scheme.
   *
   * Default value: ""
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_scheme() const -> Glib::PropertyProxy_ReadOnly< std::string >;


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
   * @relates Gio::NetworkAddress
   */
  GIOMM_API
  auto wrap(GNetworkAddress* object, bool take_copy = false) -> Glib::RefPtr<Gio::NetworkAddress>;
}


#endif /* _GIOMM_NETWORKADDRESS_H */

