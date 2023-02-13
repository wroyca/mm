
#ifndef _GIOMM_INETADDRESS_H
#define _GIOMM_INETADDRESS_H

#include <libmm-gio/gioconfig.hpp>


#include <libmm-glib/ustring.hpp>
#include <sigc++/sigc++.h>

/* Copyright (C) 2009 jonathon jongsma
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
#include <libmm-gio/enums.hpp>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GInetAddress = struct _GInetAddress;
using GInetAddressClass = struct _GInetAddressClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gio
{ class GIOMM_API InetAddress_Class; } // namespace Gio
#endif //DOXYGEN_SHOULD_SKIP_THIS

namespace Gio
{

/** An IPv4/IPv6 address
 *
 * InetAddress represents an IPv4 or IPv6 internet address. Use
 * Resolver::lookup_by_name() or Resolver::lookup_by_name_async() to look up
 * the InetAddress for a hostname. Use Resolver::lookup_by_address() or
 * Resolver::lookup_by_address_async() to look up the hostname for a
 * InetAddress.
 *
 * To actually connect to a remote host, you will need a InetSocketAddress
 * (which includes a InetAddress as well as a port number).
 *
 * @newin{2,24}
 * @ingroup NetworkIO
 */

class GIOMM_API InetAddress
: public Glib::Object
{

#ifndef DOXYGEN_SHOULD_SKIP_THIS

public:
  using CppObjectType = InetAddress;
  using CppClassType = InetAddress_Class;
  using BaseObjectType = GInetAddress;
  using BaseClassType = GInetAddressClass;

  // noncopyable
  InetAddress(const InetAddress&) = delete;
  auto operator=(const InetAddress&) -> InetAddress& = delete;

private:  friend class InetAddress_Class;
  static CppClassType inetaddress_class_;

protected:
  explicit InetAddress(const Glib::ConstructParams& construct_params);
  explicit InetAddress(GInetAddress* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  InetAddress(InetAddress&& src) noexcept;
  auto operator=(InetAddress&& src) noexcept -> InetAddress&;

  ~InetAddress() noexcept override;

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS


  static auto get_base_type() -> GType G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GObject.
  auto       gobj() -> GInetAddress*       { return reinterpret_cast<GInetAddress*>(gobject_); }

  ///Provides access to the underlying C GObject.
  auto gobj() const -> const GInetAddress* { return reinterpret_cast<GInetAddress*>(gobject_); }

  ///Provides access to the underlying C instance. The caller is responsible for unrefing it. Use when directly setting fields in structs.
  auto gobj_copy() -> GInetAddress*;

private:


protected:
   explicit InetAddress(const guint8 * bytes, SocketFamily family);


public:
  static auto create(const Glib::ustring& string) -> Glib::RefPtr<InetAddress>;

  static auto create(const guint8 * bytes, SocketFamily family) -> Glib::RefPtr<InetAddress>;

  static auto create_any(SocketFamily family) -> Glib::RefPtr<InetAddress>;
  static auto create_loopback(SocketFamily family) -> Glib::RefPtr<InetAddress>;


  /** Checks if two InetAddress instances are equal, e.g.\ the same address.
   *
   * @newin{2,30}
   *
   * @param other_address Another InetAddress.
   * @return <tt>true</tt> if @a address and @a other_address are equal, <tt>false</tt> otherwise.
   */
  auto address_equal(const Glib::RefPtr<const InetAddress>& other_address) const -> bool;


  /** Gets the raw binary address data from @a address.
   *
   * @newin{2,22}
   *
   * @return A pointer to an internal array of the bytes in @a address,
   * which should not be modified, stored, or freed. The size of this
   * array can be gotten with g_inet_address_get_native_size().
   */
  auto to_bytes() const -> const guint8*;

  /** Converts @a address to string form.
   *
   * @newin{2,22}
   *
   * @return A representation of @a address as a string, which should be
   * freed after use.
   */
  auto to_string() const -> Glib::ustring;

  /** Gets @a address's family
   *
   * @newin{2,22}
   *
   * @return  @a address's family.
   */
  auto get_family() const -> SocketFamily;

  /** Tests whether @a address is the "any" address for its family.
   *
   * @newin{2,22}
   *
   * @return <tt>true</tt> if @a address is the "any" address for its family.
   */
  auto get_is_any() const -> bool;

  /** Tests whether @a address is a link-local address (that is, if it
   * identifies a host on a local network that is not connected to the
   * Internet).
   *
   * @newin{2,22}
   *
   * @return <tt>true</tt> if @a address is a link-local address.
   */
  auto get_is_link_local() const -> bool;

  /** Tests whether @a address is the loopback address for its family.
   *
   * @newin{2,22}
   *
   * @return <tt>true</tt> if @a address is the loopback address for its family.
   */
  auto get_is_loopback() const -> bool;

  /** Tests whether @a address is a global multicast address.
   *
   * @newin{2,22}
   *
   * @return <tt>true</tt> if @a address is a global multicast address.
   */
  auto get_is_mc_global() const -> bool;

  /** Tests whether @a address is a link-local multicast address.
   *
   * @newin{2,22}
   *
   * @return <tt>true</tt> if @a address is a link-local multicast address.
   */
  auto get_is_mc_link_local() const -> bool;

  /** Tests whether @a address is a node-local multicast address.
   *
   * @newin{2,22}
   *
   * @return <tt>true</tt> if @a address is a node-local multicast address.
   */
  auto get_is_mc_node_local() const -> bool;

  /** Tests whether @a address is an organization-local multicast address.
   *
   * @newin{2,22}
   *
   * @return <tt>true</tt> if @a address is an organization-local multicast address.
   */
  auto get_is_mc_org_local() const -> bool;

  /** Tests whether @a address is a site-local multicast address.
   *
   * @newin{2,22}
   *
   * @return <tt>true</tt> if @a address is a site-local multicast address.
   */
  auto get_is_mc_site_local() const -> bool;

  /** Tests whether @a address is a multicast address.
   *
   * @newin{2,22}
   *
   * @return <tt>true</tt> if @a address is a multicast address.
   */
  auto get_is_multicast() const -> bool;

  /** Tests whether @a address is a site-local address such as 10.0.0.1
   * (that is, the address identifies a host on a local network that can
   * not be reached directly from the Internet, but which may have
   * outgoing Internet connectivity via a NAT or firewall).
   *
   * @newin{2,22}
   *
   * @return <tt>true</tt> if @a address is a site-local address.
   */
  auto get_is_site_local() const -> bool;

  /** Gets the size of the native raw binary address for @a address. This
   * is the size of the data that you get from g_inet_address_to_bytes().
   *
   * @newin{2,22}
   *
   * @return The number of bytes used for the native version of @a address.
   */
  auto get_native_size() const -> gsize;

  /** The raw address data.
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_bytes() const -> Glib::PropertyProxy_ReadOnly< void* >;


  /** The address family (IPv4 or IPv6).
   *
   * Default value: Gio::SocketFamily::INVALID
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_family() const -> Glib::PropertyProxy_ReadOnly< SocketFamily >;


  /** Whether this is the "any" address for its family.
   * See g_inet_address_get_is_any().
   *
   * @newin{2,22}
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_is_any() const -> Glib::PropertyProxy_ReadOnly< bool >;


  /** Whether this is a link-local address.
   * See g_inet_address_get_is_link_local().
   *
   * @newin{2,22}
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_is_link_local() const -> Glib::PropertyProxy_ReadOnly< bool >;


  /** Whether this is the loopback address for its family.
   * See g_inet_address_get_is_loopback().
   *
   * @newin{2,22}
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_is_loopback() const -> Glib::PropertyProxy_ReadOnly< bool >;


  /** Whether this is a global multicast address.
   * See g_inet_address_get_is_mc_global().
   *
   * @newin{2,22}
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_is_mc_global() const -> Glib::PropertyProxy_ReadOnly< bool >;


  /** Whether this is a link-local multicast address.
   * See g_inet_address_get_is_mc_link_local().
   *
   * @newin{2,22}
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_is_mc_link_local() const -> Glib::PropertyProxy_ReadOnly< bool >;


  /** Whether this is a node-local multicast address.
   * See g_inet_address_get_is_mc_node_local().
   *
   * @newin{2,22}
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_is_mc_node_local() const -> Glib::PropertyProxy_ReadOnly< bool >;


  /** Whether this is an organization-local multicast address.
   * See g_inet_address_get_is_mc_org_local().
   *
   * @newin{2,22}
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_is_mc_org_local() const -> Glib::PropertyProxy_ReadOnly< bool >;


  /** Whether this is a site-local multicast address.
   * See g_inet_address_get_is_mc_site_local().
   *
   * @newin{2,22}
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_is_mc_site_local() const -> Glib::PropertyProxy_ReadOnly< bool >;


  /** Whether this is a multicast address.
   * See g_inet_address_get_is_multicast().
   *
   * @newin{2,22}
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_is_multicast() const -> Glib::PropertyProxy_ReadOnly< bool >;


  /** Whether this is a site-local address.
   * See g_inet_address_get_is_loopback().
   *
   * @newin{2,22}
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_is_site_local() const -> Glib::PropertyProxy_ReadOnly< bool >;


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
   * @relates Gio::InetAddress
   */
  GIOMM_API
  auto wrap(GInetAddress* object, bool take_copy = false) -> Glib::RefPtr<Gio::InetAddress>;
}


#endif /* _GIOMM_INETADDRESS_H */

