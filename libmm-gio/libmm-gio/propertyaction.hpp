
#ifndef _GIOMM_PROPERTYACTION_H
#define _GIOMM_PROPERTYACTION_H


#include <libmm-glib/ustring.hpp>
#include <sigc++/sigc++.h>

/* Copyright (C) 2017 The giomm Development Team
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
 * License along with this library. If not, see <http://www.gnu.org/licenses/>.
 */

#include <libmm-glib/object.hpp>
#include <libmm-glib/refptr.hpp>
#include <libmm-gio/action.hpp>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GPropertyAction = struct _GPropertyAction;
using GPropertyActionClass = struct _GPropertyActionClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gio
{ class GIOMM_API PropertyAction_Class; } // namespace Gio
#endif //DOXYGEN_SHOULD_SKIP_THIS

namespace Gio
{
/** An Action reflecting a Glib::Object property.
 *
 * A %PropertyAction is a way to get an Action with a state value
 * reflecting and controlling the value of a Glib::Object property.
 *
 * The state of the action will correspond to the value of the property.
 * Changing it will change the property (assuming the requested value
 * matches the requirements as specified in the GParamSpec, used when the
 * property was installed).
 *
 * Only the most common types are presently supported. Booleans are
 * mapped to booleans, strings to strings, signed/unsigned integers to
 * int32/uint32 and floats and doubles to doubles.
 *
 * If the property is an enum then the state will be string-typed and
 * conversion will automatically be performed between the enum value and
 * "nick" string as per the GEnumValue table.
 *
 * Flags types are not currently supported.
 *
 * Properties of object types, boxed types and pointer types are not
 * supported and probably never will be.
 *
 * Properties of Glib::Variant types are not currently supported.
 *
 * If the property is boolean-valued then the action will have a nullptr
 * parameter type, and activating the action (with no parameter) will
 * toggle the value of the property.
 *
 * In all other cases, the parameter type will correspond to the type of
 * the property.
 *
 * The general idea here is to reduce the number of locations where a
 * particular piece of state is kept (and therefore has to be synchronised
 * between). %PropertyAction does not have a separate state that is kept
 * in sync with the property value -- its state is the property value.
 *
 * For example, it might be useful to create an Action corresponding to
 * property_visible_child_name() of a Gtk::Stack so that the current
 * page can be switched from a menu. The active radio indication in the
 * menu is then directly determined from the active page of the Gtk::Stack.
 *
 * An anti-example would be binding property_active_id() on a Gtk::ComboBox.
 * This is because the state of the combobox itself is probably uninteresting
 * and is actually being used to control something else.
 *
 * Another anti-example would be to bind to property_visible_child_name()
 * of a Gtk::Stack if this value is actually stored in Gio::Settings.
 * In that case, the real source of the value is
 * Gio::Settings. If you want an Action to control a setting stored in
 * Gio::Settings, see Gio::Settings::create_action() instead, and possibly
 * combine its use with Gio::Settings::bind().
 *
 * @newin{2,58}
 */

class GIOMM_API PropertyAction : public Glib::Object, public Action
{

#ifndef DOXYGEN_SHOULD_SKIP_THIS

public:
  using CppObjectType = PropertyAction;
  using CppClassType = PropertyAction_Class;
  using BaseObjectType = GPropertyAction;
  using BaseClassType = GPropertyActionClass;

  // noncopyable
  PropertyAction(const PropertyAction&) = delete;
  auto operator=(const PropertyAction&) -> PropertyAction& = delete;

private:  friend class PropertyAction_Class;
  static CppClassType propertyaction_class_;

protected:
  explicit PropertyAction(const Glib::ConstructParams& construct_params);
  explicit PropertyAction(GPropertyAction* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  PropertyAction(PropertyAction&& src) noexcept;
  auto operator=(PropertyAction&& src) noexcept -> PropertyAction&;

  ~PropertyAction() noexcept override;

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS


  static auto get_base_type() -> GType G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GObject.
  auto       gobj() -> GPropertyAction*       { return reinterpret_cast<GPropertyAction*>(gobject_); }

  ///Provides access to the underlying C GObject.
  auto gobj() const -> const GPropertyAction* { return reinterpret_cast<GPropertyAction*>(gobject_); }

  ///Provides access to the underlying C instance. The caller is responsible for unrefing it. Use when directly setting fields in structs.
  auto gobj_copy() -> GPropertyAction*;

private:


protected:
  PropertyAction(const Glib::ustring& name, const Glib::PropertyProxy_Base& property_proxy,
    bool invert_boolean = false);

public:
  /** Creates an Action corresponding to the value of property @a property_proxy.
   *
   * The property must be existent and readable and writable (and not construct-only).
   *
   * This function takes a reference on the property's object and doesn't
   * release it until the action is destroyed.
   *
   * @param name The name of the action to create.
   * @param property_proxy The property to bind.
   * @param invert_boolean If <tt>true</tt>, the state of the action will be
   *        the negation of the property value, provided the property is boolean.
   * @return A new %PropertyAction.
   *
   * @newin{2,58}
   */

  static auto create(const Glib::ustring& name, const Glib::PropertyProxy_Base& property_proxy, bool invert_boolean =  false) -> Glib::RefPtr<PropertyAction>;


  /** The name of the action.  This is mostly meaningful for identifying
   * the action once it has been added to a ActionMap.
   *
   * @newin{2,58}
   *
   * Default value: ""
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_name() const -> Glib::PropertyProxy_ReadOnly< Glib::ustring >;


  /** The type of the parameter that must be given when activating the
   * action.
   *
   * @newin{2,58}
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_parameter_type() const -> Glib::PropertyProxy_ReadOnly< Glib::VariantType >;


  /** If @a action is currently enabled.
   *
   * If the action is disabled then calls to g_action_activate() and
   * g_action_change_state() have no effect.
   *
   * @newin{2,58}
   *
   * Default value: <tt>true</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_enabled() const -> Glib::PropertyProxy_ReadOnly< bool >;


  /** The VariantType of the state that the action has, or <tt>nullptr</tt> if the
   * action is stateless.
   *
   * @newin{2,58}
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_state_type() const -> Glib::PropertyProxy_ReadOnly< Glib::VariantType >;


  /** The state of the action, or <tt>nullptr</tt> if the action is stateless.
   *
   * @newin{2,58}
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_state() const -> Glib::PropertyProxy_ReadOnly< Glib::VariantBase >;


  //_WRAP_PROPERTY("object", Glib::ObjectBase) // write-only, construct-only
  //_WRAP_PROPERTY("property-name", Glib::ustring) // write-only, construct-only
  /** If <tt>true</tt>, the state of the action will be the negation of the
   * property value, provided the property is boolean.
   *
   * @newin{2,58}
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_invert_boolean() const -> Glib::PropertyProxy_ReadOnly< bool >;


  // There are no methods (apart from ctor and create), signals or vfuncs.


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
   * @relates Gio::PropertyAction
   */
  GIOMM_API
  auto wrap(GPropertyAction* object, bool take_copy = false) -> Glib::RefPtr<Gio::PropertyAction>;
}


#endif /* _GIOMM_PROPERTYACTION_H */

