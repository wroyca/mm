
#ifndef _GIOMM_ACTIONGROUP_H
#define _GIOMM_ACTIONGROUP_H

#include <libmm-gio/gioconfig.hxx>


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


#include <libmm-glib/interface.hxx>
#include <libmm-glib/varianttype.hxx>
#include <gio/gio.h> //To declare g_action_group_get_action_state_type().


#ifndef DOXYGEN_SHOULD_SKIP_THIS
typedef struct _GActionGroupInterface GActionGroupInterface;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GActionGroup = struct _GActionGroup;
using GActionGroupClass = struct _GActionGroupClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gio
{ class GIOMM_API ActionGroup_Class; } // namespace Gio
#endif // DOXYGEN_SHOULD_SKIP_THIS

namespace Glib
{

class GIOMM_API VariantBase;
class GIOMM_API VariantContainerBase;
class GIOMM_API VariantType;

}

namespace Gio
{

/** ActionGroup - a group of actions.
 * ActionGroup represents a group of actions.
 *
 * Each action in the group has a unique name (which is a string). All method
 * calls, except list_actions() take the name of an action as an argument.
 *
 * The GActionGroup API is meant to be the 'public' API to the action group.
 * The calls here are exactly the interaction that 'external forces' (eg: UI,
 * incoming D-Bus messages, etc.) are supposed to have with actions.
 * 'Internal' APIs (ie: ones meant only to be accessed by the action group
 * implementation) are found on subclasses. This is why you will find -- for
 * example -- get_action_enabled() but not an equivalent @c set() call.
 *
 * Signals are emitted on the action group in response to state changes on
 * individual actions.
 */

class GIOMM_API ActionGroup : public Glib::Interface
{

#ifndef DOXYGEN_SHOULD_SKIP_THIS

public:
  using CppObjectType = ActionGroup;
  using CppClassType = ActionGroup_Class;
  using BaseObjectType = GActionGroup;
  using BaseClassType = GActionGroupInterface;

  // noncopyable
  ActionGroup(const ActionGroup&) = delete;
  auto operator=(const ActionGroup&) -> ActionGroup& = delete;

private:
  friend class ActionGroup_Class;
  static CppClassType actiongroup_class_;

#endif /* DOXYGEN_SHOULD_SKIP_THIS */
protected:
  /**
   * You should derive from this class to use it.
   */
  ActionGroup();

#ifndef DOXYGEN_SHOULD_SKIP_THIS
  /** Called by constructors of derived classes. Provide the result of
   * the Class init() function to ensure that it is properly
   * initialized.
   *
   * @param interface_class The Class object for the derived type.
   */
  explicit ActionGroup(const Glib::Interface_Class& interface_class);

public:
  // This is public so that C++ wrapper instances can be
  // created for C instances of unwrapped types.
  // For instance, if an unexpected C type implements the C interface.
  explicit ActionGroup(GActionGroup* castitem);

protected:
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  ActionGroup(ActionGroup&& src) noexcept;
  auto operator=(ActionGroup&& src) noexcept -> ActionGroup&;

  ~ActionGroup() noexcept override;

  static void add_interface(GType gtype_implementer);

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS
  static auto get_base_type() -> GType G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GObject.
  auto       gobj() -> GActionGroup*       { return reinterpret_cast<GActionGroup*>(gobject_); }

  ///Provides access to the underlying C GObject.
  auto gobj() const -> const GActionGroup* { return reinterpret_cast<GActionGroup*>(gobject_); }

private:


public:

  /** Checks if the named action exists within @a action_group.
   *
   * @newin{2,28}
   *
   * @param action_name The name of the action to check for.
   * @return Whether the named action exists.
   */
  auto has_action(const Glib::ustring& action_name) const -> bool;


  /** Lists the actions contained within @a action_group.
   *
   * @newin{2,28}
   *
   * @return A <tt>nullptr</tt>-terminated array of the names of the
   * actions in the group.
   */
  auto list_actions() const -> std::vector<Glib::ustring>;

  //TODO: Add templated method, renaming this to query_action_variant).

  /** Queries all aspects of the named action within an @a action_group.
   *
   * This function acquires the information available from
   * g_action_group_has_action(), g_action_group_get_action_enabled(),
   * g_action_group_get_action_parameter_type(),
   * g_action_group_get_action_state_type(),
   * g_action_group_get_action_state_hint() and
   * g_action_group_get_action_state() with a single function call.
   *
   * This provides two main benefits.
   *
   * The first is the improvement in efficiency that comes with not having
   * to perform repeated lookups of the action in order to discover
   * different things about it.  The second is that implementing
   * ActionGroup can now be done by only overriding this one virtual
   * function.
   *
   * The interface provides a default implementation of this function that
   * calls the individual functions, as required, to fetch the
   * information.  The interface also provides default implementations of
   * those functions that call this function.  All implementations,
   * therefore, must override either this function or all of the others.
   *
   * If the action exists, <tt>true</tt> is returned and any of the requested
   * fields (as indicated by having a non-<tt>nullptr</tt> reference passed in) are
   * filled.  If the action doesn't exist, <tt>false</tt> is returned and the
   * fields may or may not have been modified.
   *
   * @newin{2,32}
   *
   * @param action_name The name of an action in the group.
   * @param enabled If the action is presently enabled.
   * @param parameter_type The parameter type, or <tt>nullptr</tt> if none needed.
   * @param state_type The state type, or <tt>nullptr</tt> if stateless.
   * @param state_hint The state hint, or <tt>nullptr</tt> if none.
   * @param state The current state, or <tt>nullptr</tt> if stateless.
   * @return <tt>true</tt> if the action exists, else <tt>false</tt>.
   */
  auto query_action(const Glib::ustring& action_name, bool& enabled, Glib::VariantType& parameter_type, Glib::VariantBase& state_hint, Glib::VariantType& state_type, Glib::VariantBase& state) -> bool;

  /// A query_action() convenience overload.
  auto query_action(const Glib::ustring& action_name, bool& enabled, Glib::VariantType& parameter_type, Glib::VariantBase& state_hint, Glib::VariantType& state_type) -> bool;

  /// A query_action() convenience overload.
  auto query_action(const Glib::ustring& action_name, bool& enabled, Glib::VariantType& parameter_type, Glib::VariantBase& state_hint, Glib::VariantBase& state) -> bool;

  /// A query_action() convenience overload.
  auto query_action(const Glib::ustring& action_name, bool& enabled, Glib::VariantType& parameter_type, Glib::VariantBase& state_hint) -> bool;

  /// A query_action() convenience overload.
  auto query_action(const Glib::ustring& action_name, bool& enabled, Glib::VariantBase& state_hint, Glib::VariantType& state_type, Glib::VariantBase& state) -> bool;

  /// A query_action() convenience overload.
  auto query_action(const Glib::ustring& action_name, bool& enabled, Glib::VariantBase& state_hint, Glib::VariantType& state_type) -> bool;

  /// A query_action() convenience overload.
  auto query_action(const Glib::ustring& action_name, bool& enabled, Glib::VariantBase& state_hint, Glib::VariantBase& state) -> bool;

  /// A query_action() convenience overload.
  auto query_action(const Glib::ustring& action_name, bool& enabled, Glib::VariantBase& state_hint) -> bool;


  /** Checks if the named action within @a action_group is currently enabled.
   *
   * An action must be enabled in order to be activated or in order to
   * have its state changed from outside callers.
   *
   * @newin{2,28}
   *
   * @param action_name The name of the action to query.
   * @return Whether or not the action is currently enabled.
   */
  auto get_action_enabled(const Glib::ustring& action_name) const -> bool;


  /** Queries the type of the parameter that must be given when activating
   * the named action within @a action_group.
   *
   * When activating the action using g_action_group_activate_action(),
   * the Variant given to that function must be of the type returned
   * by this function.
   *
   * In the case that this function returns <tt>nullptr</tt>, you must not give any
   * Variant, but <tt>nullptr</tt> instead.
   *
   * The parameter type of a particular action will never change but it is
   * possible for an action to be removed and for a new action to be added
   * with the same name but a different parameter type.
   *
   * @newin{2,28}
   *
   * @param action_name The name of the action to query.
   * @return The parameter type.
   */
  auto get_action_parameter_type(const Glib::ustring& action_name) const -> Glib::VariantType;

  /** Queries the type of the state of the named action within
   *  @a action_group.
   *
   * If the action is stateful then this function returns the
   * VariantType of the state.  All calls to
   * g_action_group_change_action_state() must give a Variant of this
   * type and g_action_group_get_action_state() will return a Variant
   * of the same type.
   *
   * If the action is not stateful then this function will return <tt>nullptr</tt>.
   * In that case, g_action_group_get_action_state() will return <tt>nullptr</tt>
   * and you must not call g_action_group_change_action_state().
   *
   * The state type of a particular action will never change but it is
   * possible for an action to be removed and for a new action to be added
   * with the same name but a different state type.
   *
   * @newin{2,28}
   *
   * @param action_name The name of the action to query.
   * @return The state type, if the action is stateful.
   */
  auto get_action_state_type(const Glib::ustring& action_name) const -> Glib::VariantType;

  //TODO: How do we check for a nullptr Variant?
  /**
   * Requests a hint about the valid range of values for the state of the
   * named action within the action group
   *
   * If a null Variant is returned it either means that the action is not stateful
   * or that there is no hint about the valid range of values for the
   * state of the action.
   *
   * If a ariant array is returned then each item in the array is a
   * possible value for the state.  If Variant pair (ie: two-tuple) is
   * returned then the tuple specifies the inclusive lower and upper bound
   * of valid values for the state.
   *
   * In any case, the information is merely a hint.  It may be possible to
   * have a state value outside of the hinted range and setting a value
   * within the range may fail.
   *
   * @param action_name The name of the action to query.
   * @param value This will be set to the state range hint.
   */
  template <typename T_Value>
  void get_action_state_hint(const Glib::ustring& action_name, T_Value& value) const;


  /** Requests a hint about the valid range of values for the state of the
   * named action within @a action_group.
   *
   * If <tt>nullptr</tt> is returned it either means that the action is not stateful
   * or that there is no hint about the valid range of values for the
   * state of the action.
   *
   * If a Variant array is returned then each item in the array is a
   * possible value for the state.  If a Variant pair (ie: two-tuple) is
   * returned then the tuple specifies the inclusive lower and upper bound
   * of valid values for the state.
   *
   * In any case, the information is merely a hint.  It may be possible to
   * have a state value outside of the hinted range and setting a value
   * within the range may fail.
   *
   * The return value (if non-<tt>nullptr</tt>) should be freed with
   * Glib::variant_unref() when it is no longer required.
   *
   * @newin{2,28}
   *
   * @param action_name The name of the action to query.
   * @return The state range hint.
   */
  auto get_action_state_hint_variant(const Glib::ustring& action_name) const -> Glib::VariantContainerBase;

  //TODO: How do we check for a nullptr Variant?
  /** Queries the current state of the named action within the action group.
   *
   * If the action is not stateful then a null Variant will be returned.  If the
   * action is stateful then the type of the return value is the type
   * given by get_action_state_type().
   *
   * @param action_name The name of the action to query.
   * @param value This will be set to the current state of the action.
   */
  template <typename T_Value>
  void get_action_state(const Glib::ustring& action_name, T_Value& value) const;


  /** Queries the current state of the named action within @a action_group.
   *
   * If the action is not stateful then <tt>nullptr</tt> will be returned.  If the
   * action is stateful then the type of the return value is the type
   * given by g_action_group_get_action_state_type().
   *
   * The return value (if non-<tt>nullptr</tt>) should be freed with
   * Glib::variant_unref() when it is no longer required.
   *
   * @newin{2,28}
   *
   * @param action_name The name of the action to query.
   * @return The current state of the action.
   */
  auto get_action_state_variant(const Glib::ustring& action_name) const -> Glib::VariantBase;

  //TODO: Add templated method, renaming this to change_action_state_variant().

  /** Request for the state of the named action within @a action_group to be
   * changed to @a value.
   *
   * The action must be stateful and @a value must be of the correct type.
   * See g_action_group_get_action_state_type().
   *
   * This call merely requests a change.  The action may refuse to change
   * its state or may change its state to something other than @a value.
   * See g_action_group_get_action_state_hint().
   *
   * If the @a value GVariant is floating, it is consumed.
   *
   * @newin{2,28}
   *
   * @param action_name The name of the action to request the change on.
   * @param value The new state.
   */
  void change_action_state(const Glib::ustring& action_name, const Glib::VariantBase& value);

  //TODO: Add templated method, renaming this to activate_action_variant().

  /** Activate the named action within @a action_group.
   *
   * If the action is expecting a parameter, then the correct type of
   * parameter must be given as @a parameter.  If the action is expecting no
   * parameters then @a parameter must be <tt>nullptr</tt>.  See
   * g_action_group_get_action_parameter_type().
   *
   * If the ActionGroup implementation supports asynchronous remote
   * activation over D-Bus, this call may return before the relevant
   * D-Bus traffic has been sent, or any replies have been received. In
   * order to block on such asynchronous activation calls,
   * g_dbus_connection_flush() should be called prior to the code, which
   * depends on the result of the action activation. Without flushing
   * the D-Bus connection, there is no guarantee that the action would
   * have been activated.
   *
   * The following code which runs in a remote app instance, shows an
   * example of a "quit" action being activated on the primary app
   * instance over D-Bus. Here g_dbus_connection_flush() is called
   * before `exit()`. Without g_dbus_connection_flush(), the "quit" action
   * may fail to be activated on the primary instance.
   *
   *
   * [C example ellipted]
   *
   * @newin{2,28}
   *
   * @param action_name The name of the action to activate.
   * @param parameter Parameters to the activation.
   */
  void activate_action(const Glib::ustring& action_name, const Glib::VariantBase& parameter);

  /// A activate_action() convenience overload.
  void activate_action(const Glib::ustring& action_name);


  /** Emits the ActionGroup::signal_action_added() signal on @a action_group.
   *
   * This function should only be called by ActionGroup implementations.
   *
   * @newin{2,28}
   *
   * @param action_name The name of an action in the group.
   */
  void action_added(const Glib::ustring& action_name);

  /** Emits the ActionGroup::signal_action_removed() signal on @a action_group.
   *
   * This function should only be called by ActionGroup implementations.
   *
   * @newin{2,28}
   *
   * @param action_name The name of an action in the group.
   */
  void action_removed(const Glib::ustring& action_name);

  /** Emits the ActionGroup::signal_action_enabled_changed() signal on @a action_group.
   *
   * This function should only be called by ActionGroup implementations.
   *
   * @newin{2,28}
   *
   * @param action_name The name of an action in the group.
   * @param enabled Whether or not the action is now enabled.
   */
  void action_enabled_changed(const Glib::ustring& action_name, bool enabled);

  //TODO: Add templated method, renaming this to action_state_changed_variant).

  /** Emits the ActionGroup::signal_action_state_changed() signal on @a action_group.
   *
   * This function should only be called by ActionGroup implementations.
   *
   * @newin{2,28}
   *
   * @param action_name The name of an action in the group.
   * @param state The new state of the named action.
   */
  void action_state_changed(const Glib::ustring& action_name, const Glib::VariantBase& state);


  /**
   * @par Slot Prototype:
   * <tt>void on_my_%action_added(const Glib::ustring& action_name)</tt>
   *
   * Flags: Run Last
   *
   * Signals that a new action was just added to the group.
   * This signal is emitted after the action has been added
   * and is now visible.
   *
   * @newin{2,28}
   *
   * @param action_name The name of the action in @a action_group.
   */

  auto signal_action_added(const Glib::ustring& action_name = {}) -> Glib::SignalProxyDetailed<void(const Glib::ustring&)>;


  /**
   * @par Slot Prototype:
   * <tt>void on_my_%action_enabled_changed(const Glib::ustring& action_name, bool enabled)</tt>
   *
   * Flags: Run Last
   *
   * Signals that the enabled status of the named action has changed.
   *
   * @newin{2,28}
   *
   * @param action_name The name of the action in @a action_group.
   * @param enabled Whether the action is enabled or not.
   */

  auto signal_action_enabled_changed(const Glib::ustring& action_name = {}) -> Glib::SignalProxyDetailed<void(const Glib::ustring&, bool)>;


  /**
   * @par Slot Prototype:
   * <tt>void on_my_%action_removed(const Glib::ustring& action_name)</tt>
   *
   * Flags: Run Last
   *
   * Signals that an action is just about to be removed from the group.
   * This signal is emitted before the action is removed, so the action
   * is still visible and can be queried from the signal handler.
   *
   * @newin{2,28}
   *
   * @param action_name The name of the action in @a action_group.
   */

  auto signal_action_removed(const Glib::ustring& action_name = {}) -> Glib::SignalProxyDetailed<void(const Glib::ustring&)>;


  /**
   * @par Slot Prototype:
   * <tt>void on_my_%action_state_changed(const Glib::ustring& action_name, const Glib::VariantBase& value)</tt>
   *
   * Flags: Run Last, Must Collect
   *
   * Signals that the state of the named action has changed.
   *
   * @newin{2,28}
   *
   * @param action_name The name of the action in @a action_group.
   * @param value The new value of the state.
   */

  auto signal_action_state_changed(const Glib::ustring& action_name = {}) -> Glib::SignalProxyDetailed<void(const Glib::ustring&, const Glib::VariantBase&)>;


protected:
    virtual auto has_action_vfunc(const Glib::ustring& name) const -> bool;


    virtual auto list_actions_vfunc() const -> std::vector<Glib::ustring>;


    virtual auto get_action_enabled_vfunc(const Glib::ustring& name) const -> bool;


    virtual auto get_action_parameter_type_vfunc(const Glib::ustring& name) const -> Glib::VariantType;

    virtual auto get_action_state_type_vfunc(const Glib::ustring& name) const -> Glib::VariantType;


    virtual auto get_action_state_hint_vfunc(const Glib::ustring& name) const -> Glib::VariantBase;

    virtual auto get_action_state_vfunc(const Glib::ustring& name) const -> Glib::VariantBase;


    virtual void change_action_state_vfunc(const Glib::ustring& name, const Glib::VariantBase& value);

    virtual void activate_action_vfunc(const Glib::ustring& name, const Glib::VariantBase& parameter);


public:

public:
  //C++ methods used to invoke GTK+ virtual functions:

protected:
  //GTK+ Virtual Functions (override these to change behaviour):

  //Default Signal Handlers::
  /// This is a default handler for the signal signal_action_added().
  virtual void on_action_added(const Glib::ustring& action_name);
  /// This is a default handler for the signal signal_action_enabled_changed().
  virtual void on_action_enabled_changed(const Glib::ustring& action_name, bool enabled);
  /// This is a default handler for the signal signal_action_removed().
  virtual void on_action_removed(const Glib::ustring& action_name);
  /// This is a default handler for the signal signal_action_state_changed().
  virtual void on_action_state_changed(const Glib::ustring& action_name, const Glib::VariantBase& value);


};

template <typename T_Value>
void ActionGroup::get_action_state(const Glib::ustring& action_name, T_Value& value) const
{
  value = T_Value(); //Make sure that it is initialized.

  using type_glib_variant = Glib::Variant<T_Value>;

  g_return_if_fail(
    g_variant_type_equal(g_action_group_get_action_state_type(const_cast<GActionGroup*>(gobj()), action_name.c_str()), type_glib_variant::variant_type().gobj()));

  const auto variantBase = get_action_state_variant(action_name);

  //TODO: Add a bool return instead of letting a std::bad_cast from the cast_dynamic() be thrown up to the caller?
  const auto variantDerived = variantBase.cast_dynamic<type_glib_variant>(variantBase);
  value = variantDerived.get();
}

template <typename T_Value>
void ActionGroup::get_action_state_hint(const Glib::ustring& action_name, T_Value& value) const
{
  value = T_Value(); //Make sure that it is initialized.

  using type_glib_variant = Glib::Variant<T_Value>;

  const auto variantBase = get_action_state_hint_variant(action_name);

  // We can't check the type (a range) that will be returned before getting the range hint.
  g_return_if_fail(
    variantBase.is_of_type(type_glib_variant::variant_type()) );

  const auto variantDerived = variantBase.cast_dynamic<type_glib_variant>(variantBase);
  value = variantDerived.get();
}

} // namespace Gio


namespace Glib
{
  /** A Glib::wrap() method for this object.
   *
   * @param object The C instance.
   * @param take_copy False if the result should take ownership of the C instance. True if it should take a new copy or ref.
   * @result A C++ instance that wraps this C instance.
   *
   * @relates Gio::ActionGroup
   */
  GIOMM_API
  auto wrap(GActionGroup* object, bool take_copy = false) -> Glib::RefPtr<Gio::ActionGroup>;

} // namespace Glib


#endif /* _GIOMM_ACTIONGROUP_H */

