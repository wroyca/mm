
#ifndef _GIOMM_ACTION_H
#define _GIOMM_ACTION_H

#include <libmm-gio/gioconfig.hxx>


#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

/* Copyright (C) 2011 The giomm Development Team
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
#include <libmm-glib/variant.hxx>
#include <libmm-glib/varianttype.hxx>
#include <gio/gio.h>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
typedef struct _GActionInterface GActionInterface;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GAction = struct _GAction;
using GActionClass = struct _GActionClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gio
{ class GIOMM_API Action_Class; } // namespace Gio
#endif // DOXYGEN_SHOULD_SKIP_THIS

namespace Gio
{

/** %Action - An action interface.
 * %Action represents a single named action.
 *
 * The main interface to an action is that it can be activated with activate().
 * This results in the signal_activate() signal being emitted. An activation
 * may optionally have a parameter, activate(const T_Value& parameter).
 * The correct type for the parameter is determined by a static parameter type
 * (which is given at construction time).
 *
 * An action may optionally have a state, in which case the state may be set
 * with change_state(). The correct type for the state is determined by a static
 * state type (which is given at construction time).
 *
 * An %Action can have a state, but no parameter, or vice versa. If it has both,
 * the parameter type can differ from the state type.
 *
 * The state may have a hint associated with it, specifying its valid range.
 *
 * %Action is merely the interface to the concept of an action, as described
 * above. Various implementations of actions exist, including SimpleAction.
 *
 * In all cases, the implementing class is responsible for storing the name of
 * the action, the parameter type, the enabled state, the optional state type
 * and the state and emitting the appropriate signals when these change. The
 * implementor is responsible for filtering calls to activate() and change_state()
 * for type safety and for the state being enabled.
 *
 * Probably the only useful thing to do with an %Action is to put it inside of a
 * SimpleActionGroup.
 *
 * @newin{2,32}
 */

class GIOMM_API Action : public Glib::Interface
{

#ifndef DOXYGEN_SHOULD_SKIP_THIS

public:
  using CppObjectType = Action;
  using CppClassType = Action_Class;
  using BaseObjectType = GAction;
  using BaseClassType = GActionInterface;

  // noncopyable
  Action(const Action&) = delete;
  auto operator=(const Action&) -> Action& = delete;

private:
  friend class Action_Class;
  static CppClassType action_class_;

#endif /* DOXYGEN_SHOULD_SKIP_THIS */
protected:
  /**
   * You should derive from this class to use it.
   */
  Action();

#ifndef DOXYGEN_SHOULD_SKIP_THIS
  /** Called by constructors of derived classes. Provide the result of
   * the Class init() function to ensure that it is properly
   * initialized.
   *
   * @param interface_class The Class object for the derived type.
   */
  explicit Action(const Glib::Interface_Class& interface_class);

public:
  // This is public so that C++ wrapper instances can be
  // created for C instances of unwrapped types.
  // For instance, if an unexpected C type implements the C interface.
  explicit Action(GAction* castitem);

protected:
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  Action(Action&& src) noexcept;
  auto operator=(Action&& src) noexcept -> Action&;

  ~Action() noexcept override;

  static void add_interface(GType gtype_implementer);

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS
  static auto get_base_type() -> GType G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GObject.
  auto       gobj() -> GAction*       { return reinterpret_cast<GAction*>(gobject_); }

  ///Provides access to the underlying C GObject.
  auto gobj() const -> const GAction* { return reinterpret_cast<GAction*>(gobject_); }

private:


public:

  /** Queries the name of @a action.
   *
   * @newin{2,28}
   *
   * @return The name of the action.
   */
  auto get_name() const -> Glib::ustring;

  /** Queries the type of the parameter that must be given when activating
   *  @a action.
   *
   * When activating the action using g_action_activate(), the Variant
   * given to that function must be of the type returned by this function.
   *
   * In the case that this function returns <tt>nullptr</tt>, you must not give any
   * Variant, but <tt>nullptr</tt> instead.
   *
   * @newin{2,28}
   *
   * @return The parameter type.
   */
  auto get_parameter_type() const -> Glib::VariantType;

  /** Queries the type of the state of @a action.
   *
   * If the action is stateful (e.g. created with
   * g_simple_action_new_stateful()) then this function returns the
   * VariantType of the state.  This is the type of the initial value
   * given as the state. All calls to g_action_change_state() must give a
   * Variant of this type and g_action_get_state() will return a
   * Variant of the same type.
   *
   * If the action is not stateful (e.g. created with g_simple_action_new())
   * then this function will return <tt>nullptr</tt>. In that case, g_action_get_state()
   * will return <tt>nullptr</tt> and you must not call g_action_change_state().
   *
   * @newin{2,28}
   *
   * @return The state type, if the action is stateful.
   */
  auto get_state_type() const -> Glib::VariantType;

  //TODO: Is there any specific type that can really be used with this? A std::list<>. We must test this.
  //  See also ActionGroup:::get_action_state_hint().
  /** Requests a hint about the valid range of values for the state of
   * the action.
   *
   * If a null Variant is returned it either means that the action is not stateful
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
   * @param value This will be set to the state range hint.
   */
  template <typename T_Value>
  void get_state_hint(T_Value& value) const;


  /** Requests a hint about the valid range of values for the state of
   *  @a action.
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
   * @return The state range hint.
   */
  auto get_state_hint_variant() const -> Glib::VariantContainerBase;


  /** Checks if @a action is currently enabled.
   *
   * An action must be enabled in order to be activated or in order to
   * have its state changed from outside callers.
   *
   * @newin{2,28}
   *
   * @return Whether the action is enabled.
   */
  auto get_enabled() const -> bool;

  /** Request for the state of @a action to be changed to @a value,
   * assuming that the action has the expected state type.
   *
   * See get_state_type().
   *
   * This call merely requests a change.  The action may refuse to change
   * its state or may change its state to something other than @a value.
   * See get_state_hint().
   *
   * @newin{2,38}
   *
   * @param value The new state.
   */
  template <typename T_Value>
  void change_state(const T_Value& value);

  //This is just here to maintain API compatibility,
  //by stopping the compiler from calling the
  //regular change_state() with a Variant,
  //if the application code previously called change_state(VariantBase).
  template <typename T_Value>
  void change_state(const Glib::Variant<T_Value>& value);


  /** Request for the state of @a action to be changed to @a value.
   *
   * The action must be stateful and @a value must be of the correct type.
   * See g_action_get_state_type().
   *
   * This call merely requests a change.  The action may refuse to change
   * its state or may change its state to something other than @a value.
   * See g_action_get_state_hint().
   *
   * If the @a value GVariant is floating, it is consumed.
   *
   * @newin{2,30}
   *
   * @param value The new state.
   */
  void change_state_variant(const Glib::VariantBase& value);

  /** Queries the current state of the action.
   *
   * If the action is not stateful then a null Variant will be returned.  If the
   * action is stateful then the type of the return value is the type
   * given by get_state_type().
   *
   * @param value This will be set to the current state of the action.
   */
  template <typename T_Value>
  void get_state(T_Value& value) const;


  /** Queries the current state of @a action.
   *
   * If the action is not stateful then <tt>nullptr</tt> will be returned.  If the
   * action is stateful then the type of the return value is the type
   * given by g_action_get_state_type().
   *
   * The return value (if non-<tt>nullptr</tt>) should be freed with
   * Glib::variant_unref() when it is no longer required.
   *
   * @newin{2,28}
   *
   * @return The current state of the action.
   */
  auto get_state_variant() const -> Glib::VariantBase;

  /** Activates the action without a parameter.
   */
  void activate();

  /** Activates the action with a parameter.
   *
   * The @a parameter must be the correct type of parameter for the action (ie:
   * the parameter type given at construction time).
   *
   * @param parameter The parameter to the activation
   */
  template <typename T_Value>
  void activate(const T_Value& parameter);

  //This is just here to maintain API compatibility,
  //by stopping the compiler from calling the
  //regular activate() with a Variant,
  //if the application code previously called activate(VariantBase).
  template <typename T_Value>
  void activate(const Glib::Variant<T_Value>& parameter);


  /** Activates the action.
   *
   *  @a parameter must be the correct type of parameter for the action (ie:
   * the parameter type given at construction time).  If the parameter
   * type was <tt>nullptr</tt> then @a parameter must also be <tt>nullptr</tt>.
   *
   * If the @a parameter GVariant is floating, it is consumed.
   *
   * @newin{2,28}
   *
   * @param parameter The parameter to the activation.
   */
  void activate_variant(const Glib::VariantBase& parameter);


  /** Checks if @a action_name is valid.
   *
   *  @a action_name is valid if it consists only of alphanumeric characters,
   * plus '-' and '.'.  The empty string is not a valid action name.
   *
   * It is an error to call this function with a non-utf8 @a action_name.
   *  @a action_name must not be <tt>nullptr</tt>.
   *
   * @newin{2,38}
   *
   * @param action_name A potential action name.
   * @return <tt>true</tt> if @a action_name is valid.
   */
  static auto name_is_valid(const Glib::ustring& action_name) -> bool;

  /** Parses a detailed action name into its separate name and target components.
   *
   * Detailed action names can have three formats. See parse_detailed_name_variant().
   *
   * @newin{2,40}
   *
   * @param detailed_name A detailed action name.
   * @param[out] action_name The action name.
   * @param[out] target_value The target value.
   * @throw Glib::VariantParseError if @a detailed_name has an invalid format or a target of an unexpected type.
   */
  template <typename T_Value>
  static void parse_detailed_name(const Glib::ustring& detailed_name, Glib::ustring& action_name, T_Value& target_value);


  /** Parses a detailed action name into its separate name and target
   * components.
   *
   * Detailed action names can have three formats.
   *
   * The first format is used to represent an action name with no target
   * value and consists of just an action name containing no whitespace
   * nor the characters ':', '(' or ')'.  For example: "app.action".
   *
   * The second format is used to represent an action with a target value
   * that is a non-empty string consisting only of alphanumerics, plus '-'
   * and '.'.  In that case, the action name and target value are
   * separated by a double colon ("::").  For example:
   * "app.action::target".
   *
   * The third format is used to represent an action with any type of
   * target value, including strings.  The target value follows the action
   * name, surrounded in parens.  For example: "app.action(42)".  The
   * target value is parsed using Glib::variant_parse().  If a tuple-typed
   * value is desired, it must be specified in the same way, resulting in
   * two sets of parens, for example: "app.action((1,2,3))".  A string
   * target can be specified this way as well: "app.action('target')".
   * For strings, this third format must be used if * target value is
   * empty or contains characters other than alphanumerics, '-' and '.'.
   *
   * @newin{2,38}
   *
   * @param detailed_name A detailed action name.
   * @param action_name The action name.
   * @param target_value The target value, or <tt>nullptr</tt> for no target.
   *
   * @throws Glib::VariantParseError
   */
  static void parse_detailed_name_variant(const Glib::ustring& detailed_name, Glib::ustring& action_name, Glib::VariantBase& target_value);

  /** Formats a detailed action name from the action's action_name and @a target_value.
   *
   * This function is the opposite of parse_detailed_action_name().
   * It will produce a string that can be parsed back to the @a action_name
   * and @a target_value by that function.
   *
   * See that function for the types of strings that will be printed by
   * this function.
   *
   * @param target_value A Variant target value.
   * @result A detailed format string.
   */
  template <typename T_Value>
  auto print_detailed_name(const T_Value& target_value) -> Glib::ustring;


  /** Formats a detailed action name from @a action_name and @a target_value.
   *
   * It is an error to call this function with an invalid action name.
   *
   * This function is the opposite of g_action_parse_detailed_name().
   * It will produce a string that can be parsed back to the @a action_name
   * and @a target_value by that function.
   *
   * See that function for the types of strings that will be printed by
   * this function.
   *
   * @newin{2,38}
   *
   * @param action_name A valid action name.
   * @param target_value A Variant target value, or <tt>nullptr</tt>.
   * @return A detailed format string.
   */
  static auto print_detailed_name_variant(const Glib::ustring& action_name, const Glib::VariantBase& target_value) -> Glib::ustring;

  /** If @a action is currently enabled.
   *
   * If the action is disabled then calls to g_action_activate() and
   * g_action_change_state() have no effect.
   *
   * @newin{2,28}
   *
   * Default value: <tt>true</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_enabled() const -> Glib::PropertyProxy_ReadOnly< bool >;


  /** The name of the action.  This is mostly meaningful for identifying
   * the action once it has been added to a ActionGroup. It is immutable.
   *
   * @newin{2,28}
   *
   * Default value: ""
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_name() const -> Glib::PropertyProxy_ReadOnly< Glib::ustring >;


  /** The type of the parameter that must be given when activating the
   * action. This is immutable, and may be <tt>nullptr</tt> if no parameter is needed when
   * activating the action.
   *
   * @newin{2,28}
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_parameter_type() const -> Glib::PropertyProxy_ReadOnly< Glib::VariantType >;


  /** The state of the action, or <tt>nullptr</tt> if the action is stateless.
   *
   * @newin{2,28}
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_state() const -> Glib::PropertyProxy_ReadOnly< Glib::VariantBase >;


  /** The VariantType of the state that the action has, or <tt>nullptr</tt> if the
   * action is stateless. This is immutable.
   *
   * @newin{2,28}
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_state_type() const -> Glib::PropertyProxy_ReadOnly< Glib::VariantType >;


protected:


    virtual auto get_name_vfunc() const -> Glib::ustring;


    virtual auto get_parameter_type_vfunc() const -> Glib::VariantType;

    virtual auto get_state_type_vfunc() const -> Glib::VariantType;


    virtual auto get_state_hint_vfunc() const -> Glib::VariantBase;


    virtual auto get_enabled_vfunc() const -> bool;


    virtual auto get_state_vfunc() const -> Glib::VariantBase;


    virtual void change_state_vfunc(const Glib::VariantBase& value);

    virtual void activate_vfunc(const Glib::VariantBase& parameter);


public:

public:
  //C++ methods used to invoke GTK+ virtual functions:

protected:
  //GTK+ Virtual Functions (override these to change behaviour):

  //Default Signal Handlers::


};

template <typename T_Value>
void Action::get_state(T_Value& value) const
{
  value = T_Value(); //Make sure that it is initialized.

  using type_glib_variant = Glib::Variant<T_Value>;

  g_return_if_fail(
    g_variant_type_equal(g_action_get_state_type(const_cast<GAction*>(gobj())), type_glib_variant::variant_type().gobj()));

  const auto variantBase = get_state_variant();
  const auto variantDerived = variantBase.cast_dynamic<type_glib_variant>(variantBase);
  value = variantDerived.get();
}

template <typename T_Value>
void Action::get_state_hint(T_Value& value) const
{
  value = T_Value(); //Make sure that it is initialized.

  using type_glib_variant = Glib::Variant<T_Value>;

  const auto variantBase = get_state_hint_variant();

  // We can't check the type (a range) that will be returned before getting the range hint.
  g_return_if_fail(
    variantBase.is_of_type(type_glib_variant::variant_type()) );

  const auto variantDerived = variantBase.cast_dynamic<type_glib_variant>(variantBase);
  value = variantDerived.get();
}

#ifndef DOXYGEN_SHOULD_SKIP_THIS
// Doxygen 1.8.4 does not understand that this is the static function previously declared.
template <typename T_Value>
//static
void Action::parse_detailed_name(const Glib::ustring& detailed_name, Glib::ustring& action_name, T_Value& target_value)
{
  action_name.clear(); //Make sure the output arguments are initialized.
  target_value = T_Value();

  using type_glib_variant = Glib::Variant<T_Value>;

  Glib::VariantBase target_value_variantBase;
  parse_detailed_name_variant(detailed_name, action_name, target_value_variantBase);

  if (!target_value_variantBase)
    throw Glib::VariantParseError(Glib::VariantParseError::TYPE_ERROR,
      "Detailed action name '" + detailed_name + "' has no target. Expected a target of type " +
      type_glib_variant::variant_type().get_string());

  if (!target_value_variantBase.is_of_type(type_glib_variant::variant_type()))
    throw Glib::VariantParseError(Glib::VariantParseError::TYPE_ERROR,
      "Detailed action name '" + detailed_name + "' has a target of type " +
      target_value_variantBase.get_type_string() + ". Expected " + type_glib_variant::variant_type().get_string());

  const type_glib_variant target_value_variantDerived =
    target_value_variantBase.cast_dynamic<type_glib_variant>(target_value_variantBase);
  target_value = target_value_variantDerived.get();
}
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

template <typename T_Value>
auto Action::print_detailed_name(const T_Value& target_value) -> Glib::ustring
{
  using type_glib_variant = Glib::Variant<T_Value>;

  g_return_val_if_fail(
    g_variant_type_equal(g_action_get_parameter_type(const_cast<GAction*>(gobj())), type_glib_variant::variant_type().gobj()),
    Glib::ustring());
  return print_detailed_name_variant(get_name(), type_glib_variant::create(target_value));
}

template <typename T_Value>
void Action::change_state(const T_Value& value)
{
  using type_glib_variant = Glib::Variant<T_Value>;

  g_return_if_fail(
    g_variant_type_equal(g_action_get_state_type(const_cast<GAction*>(gobj())), type_glib_variant::variant_type().gobj()));

  change_state_variant(type_glib_variant::create(value));
}

template <typename T_Value>
void Action::change_state(const Glib::Variant<T_Value>& value)
{
  change_state_variant(value);
}

template <typename T_Value>
void Action::activate(const T_Value& parameter)
{
  using type_glib_variant = Glib::Variant<T_Value>;

  g_return_if_fail(
    g_variant_type_equal(g_action_get_parameter_type(const_cast<GAction*>(gobj())), type_glib_variant::variant_type().gobj()));

  activate_variant(type_glib_variant::create(parameter));
}


template <typename T_Value>
void Action::activate(const Glib::Variant<T_Value>& value)
{
  activate_variant(value);
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
   * @relates Gio::Action
   */
  GIOMM_API
  auto wrap(GAction* object, bool take_copy = false) -> Glib::RefPtr<Gio::Action>;

} // namespace Glib


#endif /* _GIOMM_ACTION_H */

