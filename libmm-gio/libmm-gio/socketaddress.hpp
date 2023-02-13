
#ifndef _GIOMM_SOCKETADDRESS_H
#define _GIOMM_SOCKETADDRESS_H


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

#include <mm/gio/asyncresult.hpp>
#include <mm/gio/cancellable.hpp>
#include <mm/gio/socketconnectable.hpp>
#include <mm/gio/enums.hpp>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GSocketAddress = struct _GSocketAddress;
using GSocketAddressClass = struct _GSocketAddressClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gio
{ class GIOMM_API SocketAddress_Class; } // namespace Gio
#endif //DOXYGEN_SHOULD_SKIP_THIS

namespace Gio
{

/** Abstract base class representing endpoints for socket communication
 *
 * @newin{2,24}
 * @ingroup NetworkIO
 */

class GIOMM_API SocketAddress : public Glib::Object,
    public SocketConnectable
{

#ifndef DOXYGEN_SHOULD_SKIP_THIS

public:
  using CppObjectType = SocketAddress;
  using CppClassType = SocketAddress_Class;
  using BaseObjectType = GSocketAddress;
  using BaseClassType = GSocketAddressClass;

  // noncopyable
  SocketAddress(const SocketAddress&) = delete;
  auto operator=(const SocketAddress&) -> SocketAddress& = delete;

private:  friend class SocketAddress_Class;
  static CppClassType socketaddress_class_;

protected:
  explicit SocketAddress(const Glib::ConstructParams& construct_params);
  explicit SocketAddress(GSocketAddress* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  SocketAddress(SocketAddress&& src) noexcept;
  auto operator=(SocketAddress&& src) noexcept -> SocketAddress&;

  ~SocketAddress() noexcept override;

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS


  static auto get_base_type() -> GType G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GObject.
  auto       gobj() -> GSocketAddress*       { return reinterpret_cast<GSocketAddress*>(gobject_); }

  ///Provides access to the underlying C GObject.
  auto gobj() const -> const GSocketAddress* { return reinterpret_cast<GSocketAddress*>(gobject_); }

  ///Provides access to the underlying C instance. The caller is responsible for unrefing it. Use when directly setting fields in structs.
  auto gobj_copy() -> GSocketAddress*;

private:


public:

  // Note that we can't use _WRAP_CTOR() and _WRAP_CREATE() because the C
  // function does more than just call g_object_new():
  // See https://bugzilla.gnome.org/show_bug.cgi?id=766150

  /** Creates a SocketAddress subclass corresponding to the native
   * struct sockaddr @a native.
   *
   * @newin{2,22}
   *
   * @param native A pointer to a struct sockaddr.
   * @param len The size of the memory location pointed to by @a native.
   * @return A new SocketAddress if @a native could successfully
   * be converted, otherwise <tt>nullptr</tt>.
   */
  static auto create(gpointer native, gsize len) -> Glib::RefPtr<SocketAddress>;


  /** Gets the socket family type of @a address.
   *
   * @newin{2,22}
   *
   * @return The socket family type of @a address.
   */
  auto get_family() const -> SocketFamily;

  /** Converts a SocketAddress to a native struct sockaddr, which can
   * be passed to low-level functions like connect() or bind().
   *
   * If not enough space is available, a Gio::Error::NO_SPACE error
   * is returned. If the address type is not known on the system
   * then a Gio::Error::NOT_SUPPORTED error is returned.
   *
   * @newin{2,22}
   *
   * @param dest A pointer to a memory location that will contain the native
   * struct sockaddr.
   * @param destlen The size of @a dest. Must be at least as large as
   * g_socket_address_get_native_size().
   * @return <tt>true</tt> if @a dest was filled in, <tt>false</tt> on error.
   *
   * @throws Glib::Error
   */
  auto to_native(gpointer dest, gsize destlen) -> bool;

  /** Gets the size of @a address's native struct sockaddr.
   * You can use this to allocate memory to pass to
   * g_socket_address_to_native().
   *
   * @newin{2,22}
   *
   * @return The size of the native struct sockaddr that
   *  @a address represents.
   */
  auto get_native_size() const -> gssize;

  /** The family of the socket address.
   *
   * Default value: Gio::SocketFamily::INVALID
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_family() const -> Glib::PropertyProxy_ReadOnly< SocketFamily >;


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
   * @relates Gio::SocketAddress
   */
  GIOMM_API
  auto wrap(GSocketAddress* object, bool take_copy = false) -> Glib::RefPtr<Gio::SocketAddress>;
}


#endif /* _GIOMM_SOCKETADDRESS_H */

