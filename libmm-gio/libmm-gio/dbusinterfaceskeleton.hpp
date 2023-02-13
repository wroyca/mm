
#ifndef _GIOMM_DBUSINTERFACESKELETON_H
#define _GIOMM_DBUSINTERFACESKELETON_H


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

#include <libmm-glib/object.hpp>
#include <libmm-gio/dbusinterface.hpp>


 //For the GDBusMethodInvocation type in the *_p.h file.

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GDBusInterfaceSkeleton = struct _GDBusInterfaceSkeleton;
using GDBusInterfaceSkeletonClass = struct _GDBusInterfaceSkeletonClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gio::DBus
{ class GIOMM_API InterfaceSkeleton_Class; } // namespace Gio
#endif //DOXYGEN_SHOULD_SKIP_THIS

namespace Gio::DBus
{

class GIOMM_API InterfaceInfo;
class GIOMM_API Connection;
class GIOMM_API MethodInvocation;


/** Abstract base class for D-Bus interfaces on the service side.
 * @newin{2,38}
 */

class GIOMM_API InterfaceSkeleton
: public Glib::Object,
  public Interface
{

#ifndef DOXYGEN_SHOULD_SKIP_THIS

public:
  using CppObjectType = InterfaceSkeleton;
  using CppClassType = InterfaceSkeleton_Class;
  using BaseObjectType = GDBusInterfaceSkeleton;
  using BaseClassType = GDBusInterfaceSkeletonClass;

  // noncopyable
  InterfaceSkeleton(const InterfaceSkeleton&) = delete;
  auto operator=(const InterfaceSkeleton&) -> InterfaceSkeleton& = delete;

private:  friend class InterfaceSkeleton_Class;
  static CppClassType interfaceskeleton_class_;

protected:
  explicit InterfaceSkeleton(const Glib::ConstructParams& construct_params);
  explicit InterfaceSkeleton(GDBusInterfaceSkeleton* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  InterfaceSkeleton(InterfaceSkeleton&& src) noexcept;
  auto operator=(InterfaceSkeleton&& src) noexcept -> InterfaceSkeleton&;

  ~InterfaceSkeleton() noexcept override;

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS


  static auto get_base_type() -> GType G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GObject.
  auto       gobj() -> GDBusInterfaceSkeleton*       { return reinterpret_cast<GDBusInterfaceSkeleton*>(gobject_); }

  ///Provides access to the underlying C GObject.
  auto gobj() const -> const GDBusInterfaceSkeleton* { return reinterpret_cast<GDBusInterfaceSkeleton*>(gobject_); }

  ///Provides access to the underlying C instance. The caller is responsible for unrefing it. Use when directly setting fields in structs.
  auto gobj_copy() -> GDBusInterfaceSkeleton*;

private:


public:
  /** @addtogroup giommEnums giomm Enums and Flags */

  /**
   *  @var Flags NONE
   * No flags set.
   *
   *  @var Flags HANDLE_METHOD_INVOCATIONS_IN_THREAD
   * Each method invocation is handled in
   * a thread dedicated to the invocation. This means that the method implementation can use blocking IO
   * without blocking any other part of the process. It also means that the method implementation must
   * use locking to access data structures used by other threads.
   *
   *  @enum Flags
   *
   * Flags describing the behavior of a DBusInterfaceSkeleton instance.
   *
   * @newin{2,30}
   *
   * @ingroup giommEnums
   * @par Bitwise operators:
   * <tt>InterfaceSkeleton::Flags operator|(InterfaceSkeleton::Flags, InterfaceSkeleton::Flags)</tt><br>
   * <tt>InterfaceSkeleton::Flags operator&(InterfaceSkeleton::Flags, InterfaceSkeleton::Flags)</tt><br>
   * <tt>InterfaceSkeleton::Flags operator^(InterfaceSkeleton::Flags, InterfaceSkeleton::Flags)</tt><br>
   * <tt>InterfaceSkeleton::Flags operator~(InterfaceSkeleton::Flags)</tt><br>
   * <tt>InterfaceSkeleton::Flags& operator|=(InterfaceSkeleton::Flags&, InterfaceSkeleton::Flags)</tt><br>
   * <tt>InterfaceSkeleton::Flags& operator&=(InterfaceSkeleton::Flags&, InterfaceSkeleton::Flags)</tt><br>
   * <tt>InterfaceSkeleton::Flags& operator^=(InterfaceSkeleton::Flags&, InterfaceSkeleton::Flags)</tt><br>
   */
  enum class Flags
  {
    NONE = 0x0,
    HANDLE_METHOD_INVOCATIONS_IN_THREAD = (1<<0)
  };


  /** If @a interface has outstanding changes, request for these changes to be
   * emitted immediately.
   *
   * For example, an exported D-Bus interface may queue up property
   * changes and emit the
   * `org.freedesktop.DBus.Properties.PropertiesChanged`
   * signal later (e.g. in an idle handler). This technique is useful
   * for collapsing multiple property changes into one.
   *
   * @newin{2,30}
   */
  void flush();


  /** Gets D-Bus introspection information for the D-Bus interface
   * implemented by @a interface.
   *
   * @newin{2,30}
   *
   * @return A Gio::DBus::InterfaceInfo (never <tt>nullptr</tt>). Do not free.
   */
  auto get_info() -> Glib::RefPtr<InterfaceInfo>;

  /** Gets D-Bus introspection information for the D-Bus interface
   * implemented by @a interface.
   *
   * @newin{2,30}
   *
   * @return A Gio::DBus::InterfaceInfo (never <tt>nullptr</tt>). Do not free.
   */
  auto get_info() const -> Glib::RefPtr<const InterfaceInfo>;

  //TODO: _WRAP_METHOD(GDBusInterfaceVTable* get_vtable(), g_dbus_interface_skeleton_get_vtable)


  /** Gets all D-Bus properties for @a interface.
   *
   * @newin{2,30}
   *
   * @return A Variant of type
   * ['a{sv}'][G-VARIANT-TYPE-VARDICT:CAPS].
   * Free with Glib::variant_unref().
   */
  auto get_properties() const -> Glib::VariantBase;

  /** Exports @a interface at @a object_path on @a connection.
   *
   * This can be called multiple times to export the same @a interface
   * onto multiple connections however the @a object_path provided must be
   * the same for all connections.
   *
   * Use g_dbus_interface_skeleton_unexport() to unexport the object.
   *
   * @newin{2,30}
   *
   * @param connection A Gio::DBus::Connection to export @a interface on.
   * @param object_path The path to export the interface at.
   *
   * @throws Glib::Error
   */
  void export_interface_skeleton(const Glib::RefPtr<Connection>& connection, const Glib::ustring& object_path);

  /** Stops exporting @a interface on all connections it is exported on.
   *
   * To unexport @a interface from only a single connection, use
   * g_dbus_interface_skeleton_unexport_from_connection()
   *
   * @newin{2,30}
   */
  void unexport();

  /** Stops exporting @a interface on @a connection.
   *
   * To stop exporting on all connections the interface is exported on,
   * use g_dbus_interface_skeleton_unexport().
   *
   * @newin{2,32}
   *
   * @param connection A Gio::DBus::Connection.
   */
  void unexport_from_connection(const Glib::RefPtr<Connection>& connection);


  /** Gets the first connection that @a interface is exported on, if any.
   *
   * @newin{2,30}
   *
   * @return A Gio::DBus::Connection or <tt>nullptr</tt> if @a interface is
   * not exported anywhere. Do not free, the object belongs to @a interface.
   */
  auto get_connection() -> Glib::RefPtr<Connection>;

  /** Gets the first connection that @a interface is exported on, if any.
   *
   * @newin{2,30}
   *
   * @return A Gio::DBus::Connection or <tt>nullptr</tt> if @a interface is
   * not exported anywhere. Do not free, the object belongs to @a interface.
   */
  auto get_connection() const -> Glib::RefPtr<const Connection>;


  /** Gets a list of the connections that @a interface is exported on.
   *
   * @newin{2,32}
   *
   * @return A list of
   * all the connections that @a interface is exported on.
   */
  auto get_connections() -> std::vector< Glib::RefPtr<Connection> >;


  /** Gets a list of the connections that @a interface is exported on.
   *
   * @newin{2,32}
   *
   * @return A list of
   * all the connections that @a interface is exported on.
   */
  auto get_connections() const -> std::vector< Glib::RefPtr<const Connection> >;


  /** Checks if @a interface is exported on @a connection.
   *
   * @newin{2,32}
   *
   * @param connection A Gio::DBus::Connection.
   * @return <tt>true</tt> if @a interface is exported on @a connection, <tt>false</tt> otherwise.
   */
  auto has_connection(const Glib::RefPtr<const Connection>& connection) const -> bool;


  /** Gets the object path that @a interface is exported on, if any.
   *
   * @newin{2,30}
   *
   * @return A string owned by @a interface or <tt>nullptr</tt> if @a interface is not exported
   * anywhere. Do not free, the string belongs to @a interface.
   */
  auto get_object_path() const -> Glib::ustring;


  /** Gets the Gio::DBus::InterfaceSkeleton::Flags that describes what the behavior
   * of @a interface
   *
   * @newin{2,30}
   *
   * @return One or more flags from the Gio::DBus::InterfaceSkeleton::Flags enumeration.
   */
  auto get_flags() const -> Flags;

  /** Sets flags describing what the behavior of @a skeleton should be.
   *
   * @newin{2,30}
   *
   * @param flags Flags from the Gio::DBus::InterfaceSkeleton::Flags enumeration.
   */
  void set_flags(Flags flags);

  /** Flags from the Gio::DBus::InterfaceSkeleton::Flags enumeration.
   *
   * @newin{2,30}
   *
   * Default value: Gio::DBus::InterfaceSkeleton::Flags::NONE
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_g_flags() -> Glib::PropertyProxy< Flags > ;

/** Flags from the Gio::DBus::InterfaceSkeleton::Flags enumeration.
   *
   * @newin{2,30}
   *
   * Default value: Gio::DBus::InterfaceSkeleton::Flags::NONE
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_g_flags() const -> Glib::PropertyProxy_ReadOnly< Flags >;


  /**
   * @par Slot Prototype:
   * <tt>bool on_my_%authorize_method(const Glib::RefPtr<MethodInvocation>& invocation)</tt>
   *
   * Flags: Run Last
   *
   * Emitted when a method is invoked by a remote caller and used to
   * determine if the method call is authorized.
   *
   * Note that this signal is emitted in a thread dedicated to
   * handling the method call so handlers are allowed to perform
   * blocking IO. This means that it is appropriate to call e.g.
   * [polkit_authority_check_authorization_sync()](http://hal.freedesktop.org/docs/polkit/PolkitAuthority.html#polkit-authority-check-authorization-sync)
   * with the
   * [POLKIT_CHECK_AUTHORIZATION_FLAGS_ALLOW_USER_INTERACTION](http://hal.freedesktop.org/docs/polkit/PolkitAuthority.htmlP::OLKIT-CHECK-AUTHORIZATION-FLAGS-ALLOW-USER-INTERACTION:CAPS)
   * flag set.
   *
   * If <tt>false</tt> is returned then no further handlers are run and the
   * signal handler must take a reference to @a invocation and finish
   * handling the call (e.g. return an error via
   * g_dbus_method_invocation_return_error()).
   *
   * Otherwise, if <tt>true</tt> is returned, signal emission continues. If no
   * handlers return <tt>false</tt>, then the method is dispatched. If
   *  @a interface has an enclosing DBusObjectSkeleton, then the
   * DBusObjectSkeleton::signal_authorize_method() signal handlers run before
   * the handlers for this signal.
   *
   * The default class handler just returns <tt>true</tt>.
   *
   * Please note that the common case is optimized: if no signals
   * handlers are connected and the default class handler isn't
   * overridden (for both @a interface and the enclosing
   * DBusObjectSkeleton, if any) and DBusInterfaceSkeleton::property_g_flags() does
   * not have the
   * Gio::DBus::InterfaceSkeleton::Flags::HANDLE_METHOD_INVOCATIONS_IN_THREAD
   * flags set, no dedicated thread is ever used and the call will be
   * handled in the same thread as the object that @a interface belongs
   * to was exported in.
   *
   * @newin{2,30}
   *
   * @param invocation A DBusMethodInvocation.
   * @return <tt>true</tt> if the call is authorized, <tt>false</tt> otherwise.
   */

  auto signal_authorize_method() -> Glib::SignalProxy<bool(const Glib::RefPtr<MethodInvocation>&)>;


  //TODO: The virtual functions.


public:

public:
  //C++ methods used to invoke GTK+ virtual functions:

protected:
  //GTK+ Virtual Functions (override these to change behaviour):

  //Default Signal Handlers::
  /// This is a default handler for the signal signal_authorize_method().
  virtual auto on_authorize_method(const Glib::RefPtr<MethodInvocation>& invocation) -> bool;


};

} // namespace Gio

namespace Gio::DBus
{

/** @ingroup giommEnums */
inline auto operator|(InterfaceSkeleton::Flags lhs, InterfaceSkeleton::Flags rhs) -> InterfaceSkeleton::Flags
  { return static_cast<InterfaceSkeleton::Flags>(static_cast<unsigned>(lhs) | static_cast<unsigned>(rhs)); }

/** @ingroup giommEnums */
inline auto operator&(InterfaceSkeleton::Flags lhs, InterfaceSkeleton::Flags rhs) -> InterfaceSkeleton::Flags
  { return static_cast<InterfaceSkeleton::Flags>(static_cast<unsigned>(lhs) & static_cast<unsigned>(rhs)); }

/** @ingroup giommEnums */
inline auto operator^(InterfaceSkeleton::Flags lhs, InterfaceSkeleton::Flags rhs) -> InterfaceSkeleton::Flags
  { return static_cast<InterfaceSkeleton::Flags>(static_cast<unsigned>(lhs) ^ static_cast<unsigned>(rhs)); }

/** @ingroup giommEnums */
inline auto operator~(InterfaceSkeleton::Flags flags) -> InterfaceSkeleton::Flags
  { return static_cast<InterfaceSkeleton::Flags>(~static_cast<unsigned>(flags)); }

/** @ingroup giommEnums */
inline auto operator|=(InterfaceSkeleton::Flags& lhs, InterfaceSkeleton::Flags rhs) -> InterfaceSkeleton::Flags&
  { return (lhs = static_cast<InterfaceSkeleton::Flags>(static_cast<unsigned>(lhs) | static_cast<unsigned>(rhs))); }

/** @ingroup giommEnums */
inline auto operator&=(InterfaceSkeleton::Flags& lhs, InterfaceSkeleton::Flags rhs) -> InterfaceSkeleton::Flags&
  { return (lhs = static_cast<InterfaceSkeleton::Flags>(static_cast<unsigned>(lhs) & static_cast<unsigned>(rhs))); }

/** @ingroup giommEnums */
inline auto operator^=(InterfaceSkeleton::Flags& lhs, InterfaceSkeleton::Flags rhs) -> InterfaceSkeleton::Flags&
  { return (lhs = static_cast<InterfaceSkeleton::Flags>(static_cast<unsigned>(lhs) ^ static_cast<unsigned>(rhs))); }
} // namespace Gio

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

template <>
class GIOMM_API Value<Gio::DBus::InterfaceSkeleton::Flags> : public Glib::Value_Flags<Gio::DBus::InterfaceSkeleton::Flags>
{
public:
  static auto value_type() -> GType G_GNUC_CONST;
};

} // namespace Glib
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


namespace Glib
{
  /** A Glib::wrap() method for this object.
   *
   * @param object The C instance.
   * @param take_copy False if the result should take ownership of the C instance. True if it should take a new copy or ref.
   * @result A C++ instance that wraps this C instance.
   *
   * @relates Gio::DBus::InterfaceSkeleton
   */
  GIOMM_API
  auto wrap(GDBusInterfaceSkeleton* object, bool take_copy = false) -> Glib::RefPtr<Gio::DBus::InterfaceSkeleton>;
}


#endif /* _GIOMM_DBUSINTERFACESKELETON_H */

