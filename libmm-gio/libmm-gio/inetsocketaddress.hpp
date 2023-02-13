
#ifndef _GIOMM_INETSOCKETADDRESS_H
#define _GIOMM_INETSOCKETADDRESS_H


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

#include <libmm-gio/socketaddress.hpp>
#include <libmm-gio/inetaddress.hpp>
#include <libmm-gio/enums.hpp>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GInetSocketAddress = struct _GInetSocketAddress;
using GInetSocketAddressClass = struct _GInetSocketAddressClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gio
{ class GIOMM_API InetSocketAddress_Class; } // namespace Gio
#endif //DOXYGEN_SHOULD_SKIP_THIS

namespace Gio
{

/** Internet SocketAddress
 *
 * An IPv4 or IPv6 socket address; that is, the combination of a
 * InetAddress and a port number.
 *
 * An IPv4 or IPv6 socket address, corresponding to a struct sockaddr_in or
 * struct sockaddr_in6.
 *
 * @newin{2,24}
 * @ingroup NetworkIO
 */

class GIOMM_API InetSocketAddress
: public SocketAddress
{

#ifndef DOXYGEN_SHOULD_SKIP_THIS

public:
  using CppObjectType = InetSocketAddress;
  using CppClassType = InetSocketAddress_Class;
  using BaseObjectType = GInetSocketAddress;
  using BaseClassType = GInetSocketAddressClass;

  // noncopyable
  InetSocketAddress(const InetSocketAddress&) = delete;
  auto operator=(const InetSocketAddress&) -> InetSocketAddress& = delete;

private:  friend class InetSocketAddress_Class;
  static CppClassType inetsocketaddress_class_;

protected:
  explicit InetSocketAddress(const Glib::ConstructParams& construct_params);
  explicit InetSocketAddress(GInetSocketAddress* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  InetSocketAddress(InetSocketAddress&& src) noexcept;
  auto operator=(InetSocketAddress&& src) noexcept -> InetSocketAddress&;

  ~InetSocketAddress() noexcept override;

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS


  static auto get_base_type() -> GType G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GObject.
  auto       gobj() -> GInetSocketAddress*       { return reinterpret_cast<GInetSocketAddress*>(gobject_); }

  ///Provides access to the underlying C GObject.
  auto gobj() const -> const GInetSocketAddress* { return reinterpret_cast<GInetSocketAddress*>(gobject_); }

  ///Provides access to the underlying C instance. The caller is responsible for unrefing it. Use when directly setting fields in structs.
  auto gobj_copy() -> GInetSocketAddress*;

private:


protected:
   explicit InetSocketAddress(const Glib::RefPtr<InetAddress>& address, guint16 port);


public:

  static auto create(const Glib::RefPtr<InetAddress>& address, guint16 port) -> Glib::RefPtr<InetSocketAddress>;


  /** Gets @a address's InetAddress.
   *
   * @newin{2,22}
   *
   * @return The InetAddress for @a address, which must be
   * Glib::object_ref()'d if it will be stored.
   */
  auto get_address() -> Glib::RefPtr<InetAddress>;

  /** Gets @a address's InetAddress.
   *
   * @newin{2,22}
   *
   * @return The InetAddress for @a address, which must be
   * Glib::object_ref()'d if it will be stored.
   */
  auto get_address() const -> Glib::RefPtr<const InetAddress>;


  /** Gets @a address's port.
   *
   * @newin{2,22}
   *
   * @return The port for @a address.
   */
  auto get_port() const -> guint16;


  /** Gets the `sin6_flowinfo` field from @a address,
   * which must be an IPv6 address.
   *
   * @newin{2,32}
   *
   * @return The flowinfo field.
   */
  auto get_flowinfo() const -> guint32;

  /** Gets the `sin6_scope_id` field from @a address,
   * which must be an IPv6 address.
   *
   * @newin{2,32}
   *
   * @return The scope id field.
   */
  auto get_scope_id() const -> guint32;

  /** The address.
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_address() const -> Glib::PropertyProxy_ReadOnly< Glib::RefPtr<InetAddress> >;


  // Don't use guint16 or guint32 in _WRAP_PROPERTY().
  // There are no Glib::Value<> specializations for those types.
  // Glib::Value<unsigned int> exists, and guint is a typedef of unsigned int.
  /** The port.
   *
   * Default value: 0
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_port() const -> Glib::PropertyProxy_ReadOnly< guint >;


  /** The `sin6_flowinfo` field, for IPv6 addresses.
   *
   * @newin{2,32}
   *
   * Default value: 0
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_flowinfo() const -> Glib::PropertyProxy_ReadOnly< guint >;


  /** IPv6 scope ID.
   *
   * Default value: 0
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_scope_id() const -> Glib::PropertyProxy_ReadOnly< guint >;


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
   * @relates Gio::InetSocketAddress
   */
  GIOMM_API
  auto wrap(GInetSocketAddress* object, bool take_copy = false) -> Glib::RefPtr<Gio::InetSocketAddress>;
}


#endif /* _GIOMM_INETSOCKETADDRESS_H */

