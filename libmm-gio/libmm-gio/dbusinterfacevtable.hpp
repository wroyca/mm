
#ifndef _GIOMM_DBUSINTERFACEVTABLE_H
#define _GIOMM_DBUSINTERFACEVTABLE_H


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

#include <mm/gio/dbusmethodinvocation.hpp>
#include <gio/gio.h>


namespace Gio::DBus
{

/**This represents a virtual table for
 * handling properties and method calls for a D-Bus interface.
 *
 * If you want to handle getting/setting D-Bus properties asynchronously,
 * simply register an object with the org.freedesktop.DBus.Properties D-Bus
 * interface using Gio::DBus::Connection::register_object().
 *
 * The only correct use of this class is to declare a global instance of it
 * (or an instance local to the main function) and pass pointers to the
 * instance to the methods that require such a parameter.  The instance can be
 * used for multiple registrations and the memory it uses will be freed at the
 * end of execution.  Any other use (like creating an instance local to a
 * function and using that) may cause memory leaks or errors (if the instance
 * is destroyed too early).
 *
 * @newin{2,28}
 * @ingroup DBus
 */
class GIOMM_API InterfaceVTable
{
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  using CppObjectType = InterfaceVTable;
  using BaseObjectType = GDBusInterfaceVTable;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

private:


public:
  /** The type for a slot which handles a method call for a D-Bus interface.
   * for example,
   * @code
   * void on_interface_method_call(const Glib::RefPtr<Gio::DBus::Connection>&
   * connection, const Glib::ustring& sender, const Glib::ustring&
   * object_path, const Glib::ustring& interface_name, const Glib::ustring&
   * method_name, const Glib::VariantContainerBase& parameters, const
   * Glib::RefPtr<Gio::DBus::MethodInvocation>& invocation);
   * @endcode
   */
  using SlotInterfaceMethodCall = sigc::slot<
    void(
    const Glib::RefPtr<Connection>&,
    const Glib::ustring&,
    const Glib::ustring&,
    const Glib::ustring&,
    const Glib::ustring&,
    const Glib::VariantContainerBase&,
    const Glib::RefPtr<MethodInvocation>&)
    >;

  /** The type for a slot which handles getting a property for a D-Bus
   * interface.
   * for example,
   * @code
   * void on_interface_get_property(Glib::VariantBase& property, const
   * Glib::RefPtr<Gio::DBus::Connection>& connection, const Glib::ustring&
   * sender, const Glib::ustring& object_path, const Glib::ustring&
   * interface_name, const Glib::ustring& property_name);
   * @endcode
   * @throw Glib::Error.
   */
  using SlotInterfaceGetProperty = sigc::slot<
    void(
    Glib::VariantBase&,
    const Glib::RefPtr<Connection>&,
    const Glib::ustring&,
    const Glib::ustring&,
    const Glib::ustring&,
    const Glib::ustring&)
    >;

  /** The type for a slot which handles setting a property for a D-Bus
   * interface.
   * for example,
   * @code
   * bool on_interface_set_property(const Glib::RefPtr<Gio::DBus::Connection>&
   * connection, const Glib::ustring& sender, const Glib::ustring&
   * object_path, const Glib::ustring& interface_name, const Glib::ustring&
   * property_name, const Glib::VariantBase& value);
   * @endcode
   * @throw Glib::Error.
   */
  using SlotInterfaceSetProperty = sigc::slot<
    bool(
    const Glib::RefPtr<Connection>&,
    const Glib::ustring&,
    const Glib::ustring&,
    const Glib::ustring&,
    const Glib::ustring&,
    const Glib::VariantBase&)
    >;

  /** Constructs a new InterfaceVTable using the specified slots.
   * @param slot_method_call The slot for handling incoming method calls.
   * @param slot_get_property The slot for getting a property.
   * @param slot_set_property The slot for setting a property.
   */
  explicit InterfaceVTable(
   const SlotInterfaceMethodCall& slot_method_call,
   const SlotInterfaceGetProperty& slot_get_property = {},
   const SlotInterfaceSetProperty& slot_set_property = {}
  );

  InterfaceVTable(const InterfaceVTable& other) = delete;
  auto operator=(const InterfaceVTable& other) -> InterfaceVTable& = delete;

  InterfaceVTable(InterfaceVTable&& other) noexcept;
  auto operator=(InterfaceVTable&& other) noexcept -> InterfaceVTable&;

  /// Destructor.
  virtual ~InterfaceVTable();

  /// Provides access to the underlying C object.
  auto gobj() -> GDBusInterfaceVTable*
    { return reinterpret_cast<GDBusInterfaceVTable*>(&gobject_); }

  /// Provides access to the underlying C object.
  auto gobj() const -> const GDBusInterfaceVTable*
    { return reinterpret_cast<const GDBusInterfaceVTable*>(&gobject_); }

#ifndef DOXYGEN_SHOULD_SKIP_THIS
  // These are so the C callbacks and the
  // Gio::DBus::Connection::register_object() method can have access to the
  // copies of the slots used for creation when registering.
  auto      get_slot_method_call() const -> SlotInterfaceMethodCall*;
  auto     get_slot_get_property() const -> SlotInterfaceGetProperty*;
  auto     get_slot_set_property() const -> SlotInterfaceSetProperty*;
#endif

protected:
  // The underlying C instance.
  GDBusInterfaceVTable          gobject_;

  // Pointers to copies of the slots used to create an instance.
  SlotInterfaceMethodCall*      slot_method_call_;
  SlotInterfaceGetProperty*     slot_get_property_;
  SlotInterfaceSetProperty*     slot_set_property_;


};


} // namespace Gio


#endif /* _GIOMM_DBUSINTERFACEVTABLE_H */

