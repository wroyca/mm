
#ifndef _GIOMM_DBUSINTERFACE_H
#define _GIOMM_DBUSINTERFACE_H

#include <libmm-gio/gioconfig.hxx>


#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

/* Copyright (C) 2012 The giomm Development Team
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


#include <libmm-glib/interface.hxx>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
typedef struct _GDBusInterfaceIface GDBusInterfaceIface;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GDBusInterface = struct _GDBusInterface;
using GDBusInterfaceClass = struct _GDBusInterfaceClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gio::DBus
{ class GIOMM_API Interface_Class; } // namespace Gio
#endif // DOXYGEN_SHOULD_SKIP_THIS

namespace Gio::DBus
{

class GIOMM_API InterfaceInfo;
class GIOMM_API Object;


/** Interface - Base type for D-Bus interfaces.
 * The Interface type is the base type for D-Bus interfaces both on the service
 * side (see InterfaceSkeleton) and client side (see Proxy).
 * @newin{2,34}
 */


class GIOMM_API Interface : public Glib::Interface
{

#ifndef DOXYGEN_SHOULD_SKIP_THIS

public:
  using CppObjectType = Interface;
  using CppClassType = Interface_Class;
  using BaseObjectType = GDBusInterface;
  using BaseClassType = GDBusInterfaceIface;

  // noncopyable
  Interface(const Interface&) = delete;
  auto operator=(const Interface&) -> Interface& = delete;

private:
  friend class Interface_Class;
  static CppClassType interface_class_;

#endif /* DOXYGEN_SHOULD_SKIP_THIS */
protected:
  /**
   * You should derive from this class to use it.
   */
  Interface();

#ifndef DOXYGEN_SHOULD_SKIP_THIS
  /** Called by constructors of derived classes. Provide the result of
   * the Class init() function to ensure that it is properly
   * initialized.
   *
   * @param interface_class The Class object for the derived type.
   */
  explicit Interface(const Glib::Interface_Class& interface_class);

public:
  // This is public so that C++ wrapper instances can be
  // created for C instances of unwrapped types.
  // For instance, if an unexpected C type implements the C interface.
  explicit Interface(GDBusInterface* castitem);

protected:
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  Interface(Interface&& src) noexcept;
  auto operator=(Interface&& src) noexcept -> Interface&;

  ~Interface() noexcept override;

  static void add_interface(GType gtype_implementer);

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS
  static auto get_base_type() -> GType G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GObject.
  auto       gobj() -> GDBusInterface*       { return reinterpret_cast<GDBusInterface*>(gobject_); }

  ///Provides access to the underlying C GObject.
  auto gobj() const -> const GDBusInterface* { return reinterpret_cast<GDBusInterface*>(gobject_); }

private:


public:

  /** Gets D-Bus introspection information for the D-Bus interface
   * implemented by @a interface.
   *
   * @newin{2,30}
   *
   * @return A Gio::DBus::InterfaceInfo. Do not free.
   */
  auto get_info() -> Glib::RefPtr<InterfaceInfo>;

  /** Gets D-Bus introspection information for the D-Bus interface
   * implemented by @a interface.
   *
   * @newin{2,30}
   *
   * @return A Gio::DBus::InterfaceInfo. Do not free.
   */
  auto get_info() const -> Glib::RefPtr<const InterfaceInfo>;


  /** Gets the DBusObject that @a interface belongs to, if any.
   *
   * It is not safe to use the returned object if @a interface or
   * the returned object is being used from other threads. See
   * g_dbus_interface_dup_object() for a thread-safe alternative.
   *
   * @newin{2,30}
   *
   * @return A DBusObject or <tt>nullptr</tt>. The returned
   * reference belongs to @a interface and should not be freed.
   */
  auto get_object() -> Glib::RefPtr<Gio::DBus::Object>;

  /** Gets the DBusObject that @a interface belongs to, if any.
   *
   * It is not safe to use the returned object if @a interface or
   * the returned object is being used from other threads. See
   * g_dbus_interface_dup_object() for a thread-safe alternative.
   *
   * @newin{2,30}
   *
   * @return A DBusObject or <tt>nullptr</tt>. The returned
   * reference belongs to @a interface and should not be freed.
   */
  auto get_object() const -> Glib::RefPtr<const Gio::DBus::Object>;


  /** Gets the DBusObject that @a interface belongs to, if any.
   *
   * @newin{2,32}
   *
   * @return A DBusObject or <tt>nullptr</tt>. The returned
   * reference should be freed with Glib::object_unref().
   */
  auto dup_object() -> Glib::RefPtr<Gio::DBus::Object>;

  /** Gets the DBusObject that @a interface belongs to, if any.
   *
   * @newin{2,32}
   *
   * @return A DBusObject or <tt>nullptr</tt>. The returned
   * reference should be freed with Glib::object_unref().
   */
  auto dup_object() const -> Glib::RefPtr<const Gio::DBus::Object>;


  /** Sets the DBusObject for @a interface to @a object.
   *
   * Note that @a interface will hold a weak reference to @a object.
   *
   * @newin{2,30}
   *
   * @param object A DBusObject or <tt>nullptr</tt>.
   */
  void set_object(const Glib::RefPtr<Gio::DBus::Object>& object);

protected:
    virtual auto get_info_vfunc() const -> Glib::RefPtr<InterfaceInfo>;

    virtual auto get_object_vfunc() const -> Glib::RefPtr<Gio::DBus::Object>;


    virtual void set_object_vfunc(const Glib::RefPtr<Gio::DBus::Object>& object);


    virtual auto dup_object_vfunc() const -> Glib::RefPtr<Gio::DBus::Object>;


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
   * @relates Gio::DBus::Interface
   */
  GIOMM_API
  auto wrap(GDBusInterface* object, bool take_copy = false) -> Glib::RefPtr<Gio::DBus::Interface>;

} // namespace Glib


#endif /* _GIOMM_DBUSINTERFACE_H */

