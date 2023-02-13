
#ifndef _GIOMM_ACTIONMAP_H
#define _GIOMM_ACTIONMAP_H


#include <mm/glib/ustring.hpp>
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

#include <mm/glib/interface.hpp>
#include <mm/gio/simpleaction.hpp>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
typedef struct _GActionMapInterface GActionMapInterface;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GActionMap = struct _GActionMap;
using GActionMapClass = struct _GActionMapClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gio
{ class GIOMM_API ActionMap_Class; } // namespace Gio
#endif // DOXYGEN_SHOULD_SKIP_THIS

namespace Gio
{

class GIOMM_API Action;

/** ActionMap - Interface for action containers.
 * The ActionMap interface is implemented by ActionGroup implementations that
 * operate by containing a number of named Action instances, such as
 * SimpleActionGroup.
 *
 * One useful application of this interface is to map the names of actions from
 * various action groups to unique, prefixed names (e.g. by prepending "app."
 * or "win."). This is the motivation for the 'Map' part of the interface name.
 * @newin{2,32}
 */

class GIOMM_API ActionMap : public Glib::Interface
{

#ifndef DOXYGEN_SHOULD_SKIP_THIS

public:
  using CppObjectType = ActionMap;
  using CppClassType = ActionMap_Class;
  using BaseObjectType = GActionMap;
  using BaseClassType = GActionMapInterface;

  // noncopyable
  ActionMap(const ActionMap&) = delete;
  auto operator=(const ActionMap&) -> ActionMap& = delete;

private:
  friend class ActionMap_Class;
  static CppClassType actionmap_class_;

#endif /* DOXYGEN_SHOULD_SKIP_THIS */
protected:
  /**
   * You should derive from this class to use it.
   */
  ActionMap();

#ifndef DOXYGEN_SHOULD_SKIP_THIS
  /** Called by constructors of derived classes. Provide the result of
   * the Class init() function to ensure that it is properly
   * initialized.
   *
   * @param interface_class The Class object for the derived type.
   */
  explicit ActionMap(const Glib::Interface_Class& interface_class);

public:
  // This is public so that C++ wrapper instances can be
  // created for C instances of unwrapped types.
  // For instance, if an unexpected C type implements the C interface.
  explicit ActionMap(GActionMap* castitem);

protected:
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  ActionMap(ActionMap&& src) noexcept;
  auto operator=(ActionMap&& src) noexcept -> ActionMap&;

  ~ActionMap() noexcept override;

  static void add_interface(GType gtype_implementer);

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS
  static auto get_base_type() -> GType G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GObject.
  auto       gobj() -> GActionMap*       { return reinterpret_cast<GActionMap*>(gobject_); }

  ///Provides access to the underlying C GObject.
  auto gobj() const -> const GActionMap* { return reinterpret_cast<GActionMap*>(gobject_); }

private:


  // The various add_action...() methods are our equivalent for g_action_map_add_action_entries().


public:

  /** Adds an action to the @a action_map.
   *
   * If the action map already contains an action with the same name
   * as @a action then the old action is dropped from the action map.
   *
   * The action map takes its own reference on @a action.
   *
   * @newin{2,32}
   *
   * @param action A Action.
   */
  void add_action(const Glib::RefPtr<Action>& action);

  /** Removes the named action from the action map.
   *
   * If no action of this name is in the map then nothing happens.
   *
   * @newin{2,32}
   *
   * @param action_name The name of the action.
   */
  void remove_action(const Glib::ustring& action_name);


  /** Looks up the action with the name @a action_name in @a action_map.
   *
   * If no such action exists, returns <tt>nullptr</tt>.
   *
   * @newin{2,32}
   *
   * @param action_name The name of an action.
   * @return A Action, or <tt>nullptr</tt>.
   */
  auto lookup_action(const Glib::ustring& action_name) -> Glib::RefPtr<Action>;

  /** Looks up the action with the name @a action_name in @a action_map.
   *
   * If no such action exists, returns <tt>nullptr</tt>.
   *
   * @newin{2,32}
   *
   * @param action_name The name of an action.
   * @return A Action, or <tt>nullptr</tt>.
   */
  auto lookup_action(const Glib::ustring& action_name) const -> Glib::RefPtr<const Action>;


  /** A convenience method for creating a SimpleAction instance
   * and adding it to the ActionMap.
   *
   * @param name The name of the Action.
   * @return The Action.
   */
  auto add_action(const Glib::ustring& name) -> Glib::RefPtr<SimpleAction>;

  /** A Slot to be called when an action has been activated,
   * without passing a parameter to the slot.
   * See add_action() and add_action_bool().
   *
   * For instance,
   * void on_slot_activated();
   */
  using ActivateSlot = sigc::slot<void()>;

  /** A convenience method for creating a SimpleAction instance
   * and adding it to the ActionMap.
   *
   * @param name The name of the Action.
   * @param slot The callback method to be called when the action is activated.
   * @return The Action.
   */
  auto add_action(const Glib::ustring& name, const ActivateSlot& slot) -> Glib::RefPtr<SimpleAction>;


  /** A Slot to be called when an action has been activated,
   * passing a parameter of a specified type.
   * See add_action_with_parameter().
   *
   * For instance,
   * void on_slot_activated(const Glib::VariantBase& parameter);
   */
  using ActivateWithParameterSlot = sigc::slot<void(const Glib::VariantBase&)>;

  /** A convenience method for creating a SimpleAction instance, which when
   * activated will call a slot receiving a given type of parameter, and adding
   * that SimpleAction to the ActionMap.
   *
   * @param name The name of the Action.
   * @param parameter_type The type of parameter to be passed to the slot.
   * @param slot The callback method to be called when the action is activated.
   * @return The Action.
   */
  auto add_action_with_parameter(const Glib::ustring& name, const Glib::VariantType& parameter_type, const ActivateWithParameterSlot& slot) -> Glib::RefPtr<SimpleAction>;


  /** A convenience method for creating a boolean-stateful SimpleAction instance
   * and adding it to the ActionMap.
   *
   * @param name The name of the Action.
   * @param state The initial state.
   * @return The Action.
   */
  auto add_action_bool(const Glib::ustring& name, bool state = false) -> Glib::RefPtr<SimpleAction>;

  /** A convenience method for creating a boolean-stateful (toggle) SimpleAction instance
   * and adding it to the ActionMap.
   *
   * @param name The name of the Action.
   * @param slot The callback method to be called when the action is activated.
   * @param state The initial state.
   * @return The Action.
   */
  auto add_action_bool(const Glib::ustring& name, const ActivateSlot& slot, bool state = false) -> Glib::RefPtr<SimpleAction>;


//TODO: Docs: Add hints about how to specify the various possible states in the GtkBuilder XML.
  /** A convenience method for creating a string-based radio SimpleAction instance
   * and adding it to the ActionMap.
   *
   * @param name The name of the Action.
   * @param state The initial state.
   * @return The Action.
   */
  auto add_action_radio_string(const Glib::ustring& name, const Glib::ustring& state) -> Glib::RefPtr<SimpleAction>;

  /** A Slot to be called when an action has been activated.
   * See add_action_radio_string().
   *
   * For instance,
   * void on_slot_activated(const Glib::ustring& parameter);
   */
  using ActivateWithStringParameterSlot = sigc::slot<void(const Glib::ustring&)>;

//TODO: Docs: Add hints about how to specify the various possible states in the GtkBuilder XML.
  /** A convenience method for creating a string-based radio SimpleAction instance
   * and adding it to the ActionMap.
   *
   * @param name The name of the Action.
   * @param slot The callback method to be called when the action is activated.
   * @param state The initial state.
   * @return The Action.
   */
  auto add_action_radio_string(const Glib::ustring& name, const ActivateWithStringParameterSlot& slot, const Glib::ustring& state) -> Glib::RefPtr<SimpleAction>;


//TODO: Docs: Add hints about how to specify the various possible states in the GtkBuilder XML.
  /** A convenience method for creating an integer-based radio SimpleAction instance
   * and adding it to the ActionMap.
   *
   * @param name The name of the Action.
   * @param state The initial state.
   * @return The Action.
   */
  auto add_action_radio_integer(const Glib::ustring& name, gint32 state) -> Glib::RefPtr<SimpleAction>;

  /** A Slot to be called when an action has been activated.
   * See add_action_radio_integer().
   *
   * For instance,
   * void on_slot_activated(int parameter);
   */
  using ActivateWithIntParameterSlot = sigc::slot<void(int)>;

//TODO: Docs: Add hints about how to specify the various possible states in the GtkBuilder XML.
  /** A convenience method for creating an integer-based radio SimpleAction instance
   * and adding it to the ActionMap.
   *
   * @param name The name of the Action.
   * @param slot The callback method to be called when the action is activated.
   * @param state The initial state.
   * @return The Action.
   */
  auto add_action_radio_integer(const Glib::ustring& name, const ActivateWithIntParameterSlot& slot, gint32 state) -> Glib::RefPtr<SimpleAction>;

protected:


    virtual auto lookup_action_vfunc(const Glib::ustring& name) const -> Glib::RefPtr<Action>;


    virtual void add_action_vfunc(const Glib::RefPtr<Action>& action) const;


    virtual void remove_action_vfunc(const Glib::ustring& name);


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
   * @relates Gio::ActionMap
   */
  GIOMM_API
  auto wrap(GActionMap* object, bool take_copy = false) -> Glib::RefPtr<Gio::ActionMap>;

} // namespace Glib


#endif /* _GIOMM_ACTIONMAP_H */

