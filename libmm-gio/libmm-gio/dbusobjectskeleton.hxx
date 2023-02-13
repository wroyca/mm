
#ifndef _GIOMM_DBUSOBJECTSKELETON_H
#define _GIOMM_DBUSOBJECTSKELETON_H


#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

/* Copyright (C) 2019 The giomm Development Team
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

#include <libmm-glib/object.hxx>
#include <libmm-gio/dbusobject.hxx>
#include <libmm-gio/dbusinterfaceskeleton.hxx>
#include <libmm-gio/dbusmethodinvocation.hxx>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GDBusObjectSkeleton = struct _GDBusObjectSkeleton;
using GDBusObjectSkeletonClass = struct _GDBusObjectSkeletonClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gio::DBus
{ class GIOMM_API ObjectSkeleton_Class; } // namespace Gio
#endif //DOXYGEN_SHOULD_SKIP_THIS

namespace Gio::DBus
{
//The GMMPROC_EXTRA_NAMESPACE() macro is a hint to generate_wrap_init.pl to put it in the DBus sub-namespace


/** Service-side D-Bus object.
 *
 * A %Gio::DBus::ObjectSkeleton instance is essentially a group of D-Bus
 * interfaces. The set of exported interfaces on the object may be
 * dynamic and change at runtime.
 *
 * This type is intended to be used with Gio::DBus::ObjectManager.
 *
 * @newin{2,62}
 * @ingroup DBus
 */

class GIOMM_API ObjectSkeleton : public Glib::Object, public Object
{

#ifndef DOXYGEN_SHOULD_SKIP_THIS

public:
  using CppObjectType = ObjectSkeleton;
  using CppClassType = ObjectSkeleton_Class;
  using BaseObjectType = GDBusObjectSkeleton;
  using BaseClassType = GDBusObjectSkeletonClass;

  // noncopyable
  ObjectSkeleton(const ObjectSkeleton&) = delete;
  auto operator=(const ObjectSkeleton&) -> ObjectSkeleton& = delete;

private:  friend class ObjectSkeleton_Class;
  static CppClassType objectskeleton_class_;

protected:
  explicit ObjectSkeleton(const Glib::ConstructParams& construct_params);
  explicit ObjectSkeleton(GDBusObjectSkeleton* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  ObjectSkeleton(ObjectSkeleton&& src) noexcept;
  auto operator=(ObjectSkeleton&& src) noexcept -> ObjectSkeleton&;

  ~ObjectSkeleton() noexcept override;

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS


  static auto get_base_type() -> GType G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GObject.
  auto       gobj() -> GDBusObjectSkeleton*       { return reinterpret_cast<GDBusObjectSkeleton*>(gobject_); }

  ///Provides access to the underlying C GObject.
  auto gobj() const -> const GDBusObjectSkeleton* { return reinterpret_cast<GDBusObjectSkeleton*>(gobject_); }

  ///Provides access to the underlying C instance. The caller is responsible for unrefing it. Use when directly setting fields in structs.
  auto gobj_copy() -> GDBusObjectSkeleton*;

private:


protected:
    explicit ObjectSkeleton(const Glib::ustring& object_path);


public:
  /** Creates a new %Gio::DBus::ObjectSkeleton.
   *
   * @param object_path An object path.
   * @return A new %Gio::DBus::ObjectSkeleton.
   */

  static auto create(const Glib::ustring& object_path) -> Glib::RefPtr<ObjectSkeleton>;


  // The parameter name 'interface' can cause compilation errors with MinGW.
  // See https://bugzilla.gnome.org/show_bug.cgi?id=735137
  // The parameter names in glib are 'interface_' and 'interface'.

  /** This method simply calls g_dbus_interface_skeleton_flush() on all
   * interfaces belonging to @a object. See that method for when flushing
   * is useful.
   *
   * @newin{2,30}
   */
  void flush();

  /** Adds @a iface to @a object.
   *
   * If @a object already contains a DBusInterfaceSkeleton with the same
   * interface name, it is removed before @a iface is added.
   *
   * Note that @a object takes its own reference on @a iface and holds
   * it until removed.
   *
   * @newin{2,30}
   *
   * @param iface A DBusInterfaceSkeleton.
   */
  void add_interface(const Glib::RefPtr<Gio::DBus::InterfaceSkeleton>& iface);

  /** Removes @a iface from @a object.
   *
   * @newin{2,30}
   *
   * @param iface A DBusInterfaceSkeleton.
   */
  void remove_interface(const Glib::RefPtr<Gio::DBus::InterfaceSkeleton>& iface);

  /** Removes the DBusInterface with @a interface_name from @a object.
   *
   * If no D-Bus interface of the given interface exists, this function
   * does nothing.
   *
   * @newin{2,30}
   *
   * @param interface_name A D-Bus interface name.
   */
  void remove_interface(const Glib::ustring& interface_name);

  /** Sets the object path for @a object.
   *
   * @newin{2,30}
   *
   * @param object_path A valid D-Bus object path.
   */
  void set_object_path(const Glib::ustring& object_path);

 /** The object path where the object is exported.
   *
   * @newin{2,30}
   *
   * Default value: ""
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_g_object_path() -> Glib::PropertyProxy< Glib::ustring > ;

/** The object path where the object is exported.
   *
   * @newin{2,30}
   *
   * Default value: ""
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_g_object_path() const -> Glib::PropertyProxy_ReadOnly< Glib::ustring >;


  /**
   * @par Slot Prototype:
   * <tt>bool on_my_%authorize_method(const Glib::RefPtr<Gio::DBus::InterfaceSkeleton>& iface, const Glib::RefPtr<Gio::DBus::MethodInvocation>& invocation)</tt>
   *
   * Flags: Run Last
   *
   * Emitted when a method is invoked by a remote caller and used to
   * determine if the method call is authorized.
   *
   * This signal is like DBusInterfaceSkeleton's
   * DBusInterfaceSkeleton::signal_g_authorize_method() signal,
   * except that it is for the enclosing object.
   *
   * The default class handler just returns <tt>true</tt>.
   *
   * @newin{2,30}
   *
   * @param iface The DBusInterfaceSkeleton that @a invocation is for.
   * @param invocation A DBusMethodInvocation.
   * @return <tt>true</tt> if the call is authorized, <tt>false</tt> otherwise.
   */

  auto signal_authorize_method() -> Glib::SignalProxy<bool(const Glib::RefPtr<Gio::DBus::InterfaceSkeleton>&, const Glib::RefPtr<Gio::DBus::MethodInvocation>&)>;


public:

public:
  //C++ methods used to invoke GTK+ virtual functions:

protected:
  //GTK+ Virtual Functions (override these to change behaviour):

  //Default Signal Handlers::
  /// This is a default handler for the signal signal_authorize_method().
  virtual auto on_authorize_method(const Glib::RefPtr<Gio::DBus::InterfaceSkeleton>& iface, const Glib::RefPtr<Gio::DBus::MethodInvocation>& invocation) -> bool;


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
   * @relates Gio::DBus::ObjectSkeleton
   */
  GIOMM_API
  auto wrap(GDBusObjectSkeleton* object, bool take_copy = false) -> Glib::RefPtr<Gio::DBus::ObjectSkeleton>;
}


#endif /* _GIOMM_DBUSOBJECTSKELETON_H */

