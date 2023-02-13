
#ifndef _GIOMM_DBUSSUBTREEVTABLE_H
#define _GIOMM_DBUSSUBTREEVTABLE_H


#include <libmm-glib/ustring.hxx>
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

#include <libmm-gio/dbusmethodinvocation.hxx>
#include <libmm-gio/dbusinterfacevtable.hxx>
#include <gio/gio.h>


namespace Gio::DBus
{

/** This represents a virtual table for
 * subtrees registered with Gio::DBus::Connection::register_subtree().
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
class GIOMM_API SubtreeVTable
{
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  using CppObjectType = SubtreeVTable;
  using BaseObjectType = GDBusSubtreeVTable;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

private:


public:
  /** The type for a slot which handles enumerating child nodes.
   *
   * This slot is called when generating introspection data and also when
   * preparing to dispatch incoming messages in the event that the
   * Gio::DBus::SUBTREE_FLAGS_DISPATCH_TO_UNENUMERATED_NODES flag is not
   * specified (ie: to verify that the object path is valid).
   *
   * Hierarchies are not supported; the items that you return should not
   * contain the '/' character.
   *
   * For example,
   * @code
   * std::vector<Glib::ustring> on_subtree_enumerate(const
   * Glib::RefPtr<Gio::DBus::Connection>& connection, const Glib::ustring&
   * sender, const Glib::ustring& object_path);
   * @endcode
   */
  using SlotSubtreeEnumerate = sigc::slot<
    std::vector<Glib::ustring>(
    const Glib::RefPtr<Connection>&,
    const Glib::ustring&,
    const Glib::ustring&)
    >;

  /** The type for a slot which handles introspecting a child node.
   *
   * Subtrees are flat. @a node, if non-<tt>0</tt>, is always exactly one
   * segment of the object path (ie: it never contains a slash).
   *
   * This function should return an empty vector to indicate that there is no
   * object at this node.
   *
   * If this function returns a non-empty vector, the return value is expected
   * to be a list of InterfaceInfo structures describing the interfaces
   * implemented by node.
   *
   * for example,
   * @code
   * std::vector< Glib::RefPtr<Gio::DBus::InterFaceInfo> >
   * on_subtree_introspect(const Glib::RefPtr<Gio::DBus::Connection>&
   * connection, const Glib::ustring& sender, const Glib::ustring&
   * object_path, const Glib::ustring& node);
   * @endcode
   */
  using SlotSubtreeIntrospect = sigc::slot<
    std::vector< Glib::RefPtr<Gio::DBus::InterfaceInfo> >(
    const Glib::RefPtr<Connection>&,
    const Glib::ustring&,
    const Glib::ustring&,
    const Glib::ustring&)
    >;

  /** The type for a slot which handles dispatching a remote call on a child
   * node.
   *
   * Subtrees are flat. @a node, if non-<tt>0</tt>, is always exactly one
   * segment of the object path (ie: it never contains a slash).
   *
   * for example,
   * @code
   * const Gio::DBus::InterfaceVTable* on_subtree_dispatch(const
   * Glib::RefPtr<Gio::DBus::Connection>& connection, const Glib::ustring&
   * sender, const Glib::ustring& object_path, const Glib::ustring&
   * interface_name, const Glib::ustring& node);
   * @endcode
   */
  using SlotSubtreeDispatch = sigc::slot<
    const InterfaceVTable*(
    const Glib::RefPtr<Connection>&,
    const Glib::ustring&,
    const Glib::ustring&,
    const Glib::ustring&,
    const Glib::ustring&)
    >;

  /** Constructs a new SubtreeVTable using specified slots.
   * @param slot_enumerate The slot for handling incoming method calls.
   * @param slot_introspect The slot for getting a property.
   * @param slot_dispatch The slot for setting a property.
   */
  explicit SubtreeVTable(
   const SlotSubtreeEnumerate& slot_enumerate,
   const SlotSubtreeIntrospect& slot_introspect = {},
   const SlotSubtreeDispatch& slot_dispatch = {}
  );

  SubtreeVTable(const SubtreeVTable& other) = delete;
  auto operator=(const SubtreeVTable& other) -> SubtreeVTable& = delete;

  SubtreeVTable(SubtreeVTable&& other) noexcept;
  auto operator=(SubtreeVTable&& other) noexcept -> SubtreeVTable&;

  /// Destructor.
  virtual ~SubtreeVTable();

  /// Provides access to the underlying C object.
  auto gobj() -> GDBusSubtreeVTable*
    { return reinterpret_cast<GDBusSubtreeVTable*>(&gobject_); }

  /// Provides access to the underlying C object.
  auto gobj() const -> const GDBusSubtreeVTable*
    { return reinterpret_cast<const GDBusSubtreeVTable*>(&gobject_); }

public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  // These are so the C callbacks and the
  // Gio::DBus::Connection::register_subtreee() method can have access to the
  // copies of the slots used for creation when registering.
  auto         get_slot_enumerate() const -> SlotSubtreeEnumerate*;
  auto        get_slot_introspect() const -> SlotSubtreeIntrospect*;
  auto          get_slot_dispatch() const -> SlotSubtreeDispatch*;
#endif

protected:
  // The underlying C instance.
  GDBusSubtreeVTable          gobject_;

  // Pointers to copies of the slots used to create an instance.
  SlotSubtreeEnumerate*         slot_enumerate_;
  SlotSubtreeIntrospect*        slot_introspect_;
  SlotSubtreeDispatch*          slot_dispatch_;


};


} // namespace Gio


#endif /* _GIOMM_DBUSSUBTREEVTABLE_H */

