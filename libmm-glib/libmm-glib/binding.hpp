
#ifndef _GLIBMM_BINDING_H
#define _GLIBMM_BINDING_H


/* Copyright (C) 2014 The glibmm Development Team
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
#include <libmm-glib/ustring.hpp>
#include <libmm-glib/value.hpp>

#include <optional>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GBinding = struct _GBinding;
using GBindingClass = struct _GBindingClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{ class GLIBMM_API Binding_Class; } // namespace Glib
#endif //DOXYGEN_SHOULD_SKIP_THIS

namespace Glib
{

/** Bind two object properties.
 *
 * %Glib::Binding is the representation of a binding between a property on a
 * Glib::ObjectBase instance (or source) and another property on another Glib::ObjectBase
 * instance (or target). Whenever the source property changes, the same
 * value is applied to the target property; for instance, the following binding:
 *
 * @code
 * Glib::Binding::bind_property(object1->property_a(), object2->property_b());
 * @endcode
 *
 * will cause property_b() of @a object2 to be updated
 * every time the value of property_a() of @a object1 changes.
 *
 * It is possible to create a bidirectional binding between two properties
 * of two Glib::ObjectBase instances, so that if either property changes, the
 * other is updated as well, for instance:
 *
 * @code
 * Glib::Binding::bind_property(object1->property_a(), object2->property_b(),
 *   Glib::Binding::Flags::BIDIRECTIONAL);
 * @endcode
 *
 * will keep the two properties in sync.
 *
 * It is also possible to set a custom transformation function (in both
 * directions, in case of a bidirectional binding) to apply a custom
 * transformation from the source value to the target value before
 * applying it; for instance, the following binding:
 *
 * @code
 * bool celsius_to_fahrenheit(const double& celsius, double& fahrenheit);
 * bool fahrenheit_to_celsius(const double& fahrenheit, double& celsius);
 * Glib::Binding::bind_property(adjustment1->property_value(),
 *   adjustment2->property_value(), Glib::Binding::Flags::BIDIRECTIONAL,
 *   sigc::ptr_fun(celsius_to_fahrenheit), sigc::ptr_fun(fahrenheit_to_celsius));
 * @endcode
 *
 * will keep property_value() of the two adjustments in sync; the
 * celsius_to_fahrenheit() function will be called whenever
 * property_value() of @a adjustment1 changes and will transform the current value
 * of the property before applying it to property_value() of @a adjustment2.
 *
 * Vice versa, the fahrenheit_to_celsius() function will be called whenever
 * property_value() of @a adjustment2 changes, and will transform the
 * current value of the property before applying it to property_value()
 * of @a adjustment1.
 *
 * Note that Glib::Binding does not resolve cycles by itself; a cycle like
 *
 * @code
 *   object1->property_A() -> object2->property_B()
 *   object2->property_B() -> object3->property_C()
 *   object3->property_C() -> object1->property_A()
 * @endcode
 *
 * might lead to an infinite loop. The loop, in this particular case,
 * can be avoided if the objects emit the GObject::notify signal only
 * if the value has effectively been changed. A binding is implemented
 * using the GObject::notify signal, so it is susceptible to all the
 * various ways of blocking a signal emission, like Glib::SignalProxyNormal::emission_stop()
 * or g_signal_handler_block().
 *
 * The binding between the two properties is broken whenever either one of the
 * Glib::ObjectBase instances it refers to is deleted or when unbind() is called.
 * If a RefPtr<Binding> remains after the binding has been broken, get_source()
 * and get_target() return a <tt>nullptr</tt>, and dup_source() and dup_target()
 * return an empty RefPtr. It's not necessary to keep a RefPtr<Binding>
 * in order to keep the binding alive.
 *
 * @newin{2,44}
 */

class GLIBMM_API Binding : public Glib::Object
{

#ifndef DOXYGEN_SHOULD_SKIP_THIS

public:
  using CppObjectType = Binding;
  using CppClassType = Binding_Class;
  using BaseObjectType = GBinding;
  using BaseClassType = GBindingClass;

  // noncopyable
  Binding(const Binding&) = delete;
  auto operator=(const Binding&) -> Binding& = delete;

private:  friend class Binding_Class;
  static CppClassType binding_class_;

protected:
  explicit Binding(const Glib::ConstructParams& construct_params);
  explicit Binding(GBinding* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  Binding(Binding&& src) noexcept;
  auto operator=(Binding&& src) noexcept -> Binding&;

  ~Binding() noexcept override;

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS


  static auto get_base_type() -> GType G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GObject.
  auto       gobj() -> GBinding*       { return reinterpret_cast<GBinding*>(gobject_); }

  ///Provides access to the underlying C GObject.
  auto gobj() const -> const GBinding* { return reinterpret_cast<GBinding*>(gobject_); }

  ///Provides access to the underlying C instance. The caller is responsible for unrefing it. Use when directly setting fields in structs.
  auto gobj_copy() -> GBinding*;

private:


public:
  /** @addtogroup glibmmEnums glibmm Enums and Flags */

  /**
   *  @var Flags DEFAULT
   * The default binding; if the source property
   * changes, the target property is updated with its value.
   *
   *  @var Flags BIDIRECTIONAL
   * Bidirectional binding; if either the
   * property of the source or the property of the target changes,
   * the other is updated.
   *
   *  @var Flags SYNC_CREATE
   * Synchronize the values of the source and
   * target properties when creating the binding; the direction of
   * the synchronization is always from the source to the target.
   *
   *  @var Flags INVERT_BOOLEAN
   * If the two properties being bound are
   * booleans, setting one to <tt>true</tt> will result in the other being
   * set to <tt>false</tt> and vice versa. This flag will only work for
   * boolean properties, and cannot be used when passing custom
   * transformation functions to g_object_bind_property_full().
   *
   *  @enum Flags
   *
   * Flags to be passed to g_object_bind_property() or
   * g_object_bind_property_full().
   *
   * This enumeration can be extended at later date.
   *
   * @newin{2,44}
   *
   * @ingroup glibmmEnums
   * @par Bitwise operators:
   * <tt>Binding::Flags operator|(Binding::Flags, Binding::Flags)</tt><br>
   * <tt>Binding::Flags operator&(Binding::Flags, Binding::Flags)</tt><br>
   * <tt>Binding::Flags operator^(Binding::Flags, Binding::Flags)</tt><br>
   * <tt>Binding::Flags operator~(Binding::Flags)</tt><br>
   * <tt>Binding::Flags& operator|=(Binding::Flags&, Binding::Flags)</tt><br>
   * <tt>Binding::Flags& operator&=(Binding::Flags&, Binding::Flags)</tt><br>
   * <tt>Binding::Flags& operator^=(Binding::Flags&, Binding::Flags)</tt><br>
   */
  enum class Flags
  {
    DEFAULT = 0x0,
    BIDIRECTIONAL = 1 << 0,
    SYNC_CREATE = 1 << 1,
    INVERT_BOOLEAN = 1 << 2
  };


  /** A slot to be called to transform values in a binding created by
   * bind_property_value().
   *
   * For instance:
   * @code
   *   bool on_transform_to(const GValue* from_value, GValue* to_value);
   * @endcode
   *
   * @return <tt>true</tt> if the transformation was successful, and <tt>false</tt> otherwise.
   */
  using SlotTransform = sigc::slot<bool(const GValue*, GValue*)>;

  /** A slot to be called to transform values in a binding created by
   * bind_property().
   *
   * For instance:
   * @code
   *   std::optional<int> on_transform_to(const Glib::ustring& from_string);
   * @endcode
   *
   * @return a value of type <tt>T_to</tt> if the transformation was successful,
   * and an empty optional with no value (i.e. <tt>std::nullopt</tt>) otherwise.
   */
  template <typename T_from, typename T_to>
  using SlotTypedTransform = sigc::slot<std::optional<T_to> (const T_from&)>;

  // GValue* or Glib::ValueBase& in SlotTransform?
  // Binding_transform_callback_common() is simpler and faster with GValue*.
  // No need to copy between GValue and Glib::ValueBase. ValueBase would only
  // be marginally better for users of bind_property_value(). Users would want
  // Value<T_source> and Value<T_target>, meaning that bind_property_value()
  // would have to be a template function. Most users would probably still
  // prefer bind_property(). bind_property_value() is public partly because
  // it's a good place to present documentation common to all the
  // bind_property() overloads.
  // See also https://gitlab.gnome.org/GNOME/glibmm/issues/61
  /** Creates a binding between @a source_property and @a target_property,
   * allowing you to set the transformation functions to be used by the binding.
   *
   * If @a flags contains Glib::Binding::Flags::BIDIRECTIONAL then the binding will be mutual:
   * if @a target_property changes then the @a source_property
   * will be updated as well. The @a transform_from function is only used in case
   * of bidirectional bindings, otherwise it will be ignored.
   *
   * The binding will automatically be removed when either the source or the
   * target instance is deleted. To remove the binding without affecting the
   * source and the target you can call unbind() on the returned Binding instance.
   *
   * A Glib::ObjectBase instance can have multiple bindings.
   *
   * If you supply transformation functions, it is usually easier to use one of the
   * bind_property() overloads, to avoid the use of GValue in the transformation functions.
   *
   * @param source_property The source property to bind.
   * @param target_property The target property to bind.
   * @param flags Flags to pass to Binding.
   * @param transform_to The transformation function from the source to the target,
   *        or an empty slot to use the default.
   * @param transform_from The transformation function from the target to the source,
   *        or an empty slot to use the default.
   * @return The Binding instance representing the binding between the two
   *         Glib::ObjectBase instances, or <tt>nullptr</tt> in case of error.
   *
   * @newin{2,44}
   */
  static auto bind_property_value(
    const PropertyProxy_Base& source_property,
    const PropertyProxy_Base& target_property,
    Flags flags = Flags::DEFAULT,
    const SlotTransform& transform_to = {},
    const SlotTransform& transform_from = {}) -> Glib::RefPtr<Binding>;


  /** Creates a binding between @a source_property and @a target_property.
   *
   * @param source_property The source property to bind.
   * @param target_property The target property to bind.
   * @param flags Flags to pass to Binding.
   * @return The Binding instance representing the binding between the two
   *         Glib::ObjectBase instances, or <tt>nullptr</tt> in case of error.
   *
   * @see bind_property_value()
   *
   * @newin{2,44}
   */
  static auto bind_property(
    const PropertyProxy_Base& source_property,
    const PropertyProxy_Base& target_property,
    Flags flags = Flags::DEFAULT) -> Glib::RefPtr<Binding>
  {
    return bind_property_value(source_property, target_property, flags);
  }

  /** Creates a binding between @a source_property and @a target_property,
   * allowing you to set a transformation function to be used by the binding.
   *
   * @param source_property The source property to bind.
   * @param target_property The target property to bind.
   * @param flags Flags to pass to Binding.
   * @param transform_to The transformation function from the source to the target,
   *        or an empty slot to use the default.
   * @return The Binding instance representing the binding between the two
   *         Glib::ObjectBase instances, or <tt>nullptr</tt> in case of error.
   *
   * @tparam T_source Type of the source property. Must be a type that can be
   *         stored in a Glib::Value<T_source> object.
   * @tparam T_target Type of the target property. Must be a type that can be
   *         stored in a Glib::Value<T_target> object.
   * @tparam T_functor_to Type of functor that translates from the source to the target.
   *         Must be convertible to SlotTypedTransform<T_source, T_target>.
   *
   * @see bind_property_value()
   *
   * @newin{2,44}
   */
  template <typename T_source, typename T_target, typename T_functor_to>
  static auto bind_property(
    const PropertyProxy<T_source>& source_property,
    const PropertyProxy<T_target>& target_property,
    Flags flags,
    const T_functor_to& transform_to) -> Glib::RefPtr<Binding>
  {
    SlotTypedTransform<T_source, T_target> slot_transform_to = transform_to;

    return bind_property_value(source_property, target_property, flags,
      slot_transform_to.empty() ? SlotTransform() : TransformProp<T_source, T_target>(slot_transform_to));
  }

  /** Creates a binding between @a source_property and @a target_property,
   * allowing you to set a transformation function to be used by the binding.
   *
   * @param source_property The source property to bind.
   * @param target_property The target property to bind.
   * @param flags Flags to pass to Binding.
   * @param transform_to The transformation function from the source to the target,
   *        or an empty slot to use the default.
   * @return The Binding instance representing the binding between the two
   *         Glib::ObjectBase instances, or <tt>nullptr</tt> in case of error.
   *
   * @tparam T_source Type of the source property. Must be a type that can be
   *         stored in a Glib::Value<T_source> object.
   * @tparam T_target Type of the target property. Must be a type that can be
   *         stored in a Glib::Value<T_target> object.
   * @tparam T_functor_to Type of functor that translates from the source to the target.
   *         Must be convertible to SlotTypedTransform<T_source, T_target>.
   *
   * @see bind_property_value()
   *
   * @newin{2,44}
   */
  template <typename T_source, typename T_target, typename T_functor_to>
  static auto bind_property(
    const PropertyProxy<T_source>& source_property,
    const PropertyProxy_WriteOnly<T_target>& target_property,
    Flags flags,
    const T_functor_to& transform_to) -> Glib::RefPtr<Binding>
  {
    SlotTypedTransform<T_source, T_target> slot_transform_to = transform_to;

    return bind_property_value(source_property, target_property, flags,
      slot_transform_to.empty() ? SlotTransform() : TransformProp<T_source, T_target>(slot_transform_to));
  }

  /** Creates a binding between @a source_property and @a target_property,
   * allowing you to set a transformation function to be used by the binding.
   *
   * @param source_property The source property to bind.
   * @param target_property The target property to bind.
   * @param flags Flags to pass to Binding.
   * @param transform_to The transformation function from the source to the target,
   *        or an empty slot to use the default.
   * @return The Binding instance representing the binding between the two
   *         Glib::ObjectBase instances, or <tt>nullptr</tt> in case of error.
   *
   * @tparam T_source Type of the source property. Must be a type that can be
   *         stored in a Glib::Value<T_source> object.
   * @tparam T_target Type of the target property. Must be a type that can be
   *         stored in a Glib::Value<T_target> object.
   * @tparam T_functor_to Type of functor that translates from the source to the target.
   *         Must be convertible to SlotTypedTransform<T_source, T_target>.
   *
   * @see bind_property_value()
   *
   * @newin{2,44}
   */
  template <typename T_source, typename T_target, typename T_functor_to>
  static auto bind_property(
    const PropertyProxy_ReadOnly<T_source>& source_property,
    const PropertyProxy<T_target>& target_property,
    Flags flags,
    const T_functor_to& transform_to) -> Glib::RefPtr<Binding>
  {
    SlotTypedTransform<T_source, T_target> slot_transform_to = transform_to;

    return bind_property_value(source_property, target_property, flags,
      slot_transform_to.empty() ? SlotTransform() : TransformProp<T_source, T_target>(slot_transform_to));
  }

  /** Creates a binding between @a source_property and @a target_property,
   * allowing you to set a transformation function to be used by the binding.
   *
   * @param source_property The source property to bind.
   * @param target_property The target property to bind.
   * @param flags Flags to pass to Binding.
   * @param transform_to The transformation function from the source to the target,
   *        or an empty slot to use the default.
   * @return The Binding instance representing the binding between the two
   *         Glib::ObjectBase instances, or <tt>nullptr</tt> in case of error.
   *
   * @tparam T_source Type of the source property. Must be a type that can be
   *         stored in a Glib::Value<T_source> object.
   * @tparam T_target Type of the target property. Must be a type that can be
   *         stored in a Glib::Value<T_target> object.
   * @tparam T_functor_to Type of functor that translates from the source to the target.
   *         Must be convertible to SlotTypedTransform<T_source, T_target>.
   *
   * @see bind_property_value()
   *
   * @newin{2,44}
   */
  template <typename T_source, typename T_target, typename T_functor_to>
  static auto bind_property(
    const PropertyProxy_ReadOnly<T_source>& source_property,
    const PropertyProxy_WriteOnly<T_target>& target_property,
    Flags flags,
    const T_functor_to& transform_to) -> Glib::RefPtr<Binding>
  {
    SlotTypedTransform<T_source, T_target> slot_transform_to = transform_to;

    return bind_property_value(source_property, target_property, flags,
      slot_transform_to.empty() ? SlotTransform() : TransformProp<T_source, T_target>(slot_transform_to));
  }

  /** Creates a binding between @a source_property and @a target_property,
   * allowing you to set the transformation functions to be used by the binding.
   *
   * @param source_property The source property to bind.
   * @param target_property The target property to bind.
   * @param flags Flags to pass to Binding.
   * @param transform_to The transformation function from the source to the target,
   *        or an empty slot to use the default.
   * @param transform_from The transformation function from the target to the source,
   *        or an empty slot to use the default.
   * @return The Binding instance representing the binding between the two
   *         Glib::ObjectBase instances, or <tt>nullptr</tt> in case of error.
   *
   * @tparam T_source Type of the source property. Must be a type that can be
   *         stored in a Glib::Value<T_source> object.
   * @tparam T_target Type of the target property. Must be a type that can be
   *         stored in a Glib::Value<T_target> object.
   * @tparam T_functor_to Type of functor that translates from the source to the target.
   *         Must be convertible to SlotTypedTransform<T_source, T_target>.
   * @tparam T_functor_from Type of functor that translates from the target to the source.
   *         Must be convertible to SlotTypedTransform<T_target, T_source>.
   *
   * @see bind_property_value()
   *
   * @newin{2,44}
   */
  template <typename T_source, typename T_target, typename T_functor_to, typename T_functor_from>
  static auto bind_property(
    const PropertyProxy<T_source>& source_property,
    const PropertyProxy<T_target>& target_property,
    Flags flags,
    const T_functor_to& transform_to,
    const T_functor_from& transform_from) -> Glib::RefPtr<Binding>
  {
    SlotTypedTransform<T_source, T_target> slot_transform_from = transform_from;
    SlotTypedTransform<T_target, T_source> slot_transform_to = transform_to;

    return bind_property_value(source_property, target_property, flags,
      slot_transform_to.empty() ? SlotTransform() : TransformProp<T_source, T_target>(slot_transform_to),
      slot_transform_from.empty() ? SlotTransform() : TransformProp<T_target, T_source>(slot_transform_from));
  }


#ifndef GLIBMM_DISABLE_DEPRECATED

  /** Retrieves the Object instance used as the source of the binding.
   *
   * A Binding can outlive the source Object as the binding does not hold a
   * strong reference to the source. If the source is destroyed before the
   * binding then this function will return <tt>nullptr</tt>.
   *
   * Use g_binding_dup_source() if the source or binding are used from different
   * threads as otherwise the pointer returned from this function might become
   * invalid if the source is finalized from another thread in the meantime.
   *
   * Deprecated: 2.68: Use g_binding_dup_source() for a safer version of this
   * function.
   *
   * @newin{2,44}
   *
   * @deprecated Use dup_source() instead.
   *
   * @return The source Object, or <tt>nullptr</tt> if the
   * source does not exist any more.
   */
  auto get_source() -> Glib::ObjectBase*;
#endif // GLIBMM_DISABLE_DEPRECATED


#ifndef GLIBMM_DISABLE_DEPRECATED

  /** Retrieves the Object instance used as the source of the binding.
   *
   * A Binding can outlive the source Object as the binding does not hold a
   * strong reference to the source. If the source is destroyed before the
   * binding then this function will return <tt>nullptr</tt>.
   *
   * Use g_binding_dup_source() if the source or binding are used from different
   * threads as otherwise the pointer returned from this function might become
   * invalid if the source is finalized from another thread in the meantime.
   *
   * Deprecated: 2.68: Use g_binding_dup_source() for a safer version of this
   * function.
   *
   * @newin{2,44}
   *
   * @deprecated Use dup_source() instead.
   *
   * @return The source Object, or <tt>nullptr</tt> if the
   * source does not exist any more.
   */
  auto get_source() const -> const Glib::ObjectBase*;
#endif // GLIBMM_DISABLE_DEPRECATED


  // Don't use Glib::RefPtr<Glib::Object> Glib::wrap(GObject* object, bool take_copy).
  // The object may be an interface object, e.g. Gio::Action. Such an object can't be
  // cast to Glib::Object. https://gitlab.gnome.org/GNOME/glibmm/-/issues/93


  /** Retrieves the Object instance used as the source of the binding.
   *
   * A Binding can outlive the source Object as the binding does not hold a
   * strong reference to the source. If the source is destroyed before the
   * binding then this function will return <tt>nullptr</tt>.
   *
   * @newin{2,70}
   *
   * @return The source Object, or <tt>nullptr</tt> if the
   * source does not exist any more.
   */
  auto dup_source() -> Glib::RefPtr<Glib::ObjectBase>;

  /** Retrieves the Object instance used as the source of the binding.
   *
   * A Binding can outlive the source Object as the binding does not hold a
   * strong reference to the source. If the source is destroyed before the
   * binding then this function will return <tt>nullptr</tt>.
   *
   * @newin{2,70}
   *
   * @return The source Object, or <tt>nullptr</tt> if the
   * source does not exist any more.
   */
  auto dup_source() const -> Glib::RefPtr<const Glib::ObjectBase>;


  /** Retrieves the name of the property of Binding::property_source() used as the source
   * of the binding.
   *
   * @newin{2,44}
   *
   * @return The name of the source property.
   */
  auto get_source_property() const -> Glib::ustring;


#ifndef GLIBMM_DISABLE_DEPRECATED

  /** Retrieves the Object instance used as the target of the binding.
   *
   * A Binding can outlive the target Object as the binding does not hold a
   * strong reference to the target. If the target is destroyed before the
   * binding then this function will return <tt>nullptr</tt>.
   *
   * Use g_binding_dup_target() if the target or binding are used from different
   * threads as otherwise the pointer returned from this function might become
   * invalid if the target is finalized from another thread in the meantime.
   *
   * Deprecated: 2.68: Use g_binding_dup_target() for a safer version of this
   * function.
   *
   * @newin{2,44}
   *
   * @deprecated Use dup_target() instead.
   *
   * @return The target Object, or <tt>nullptr</tt> if the
   * target does not exist any more.
   */
  auto get_target() -> Glib::ObjectBase*;
#endif // GLIBMM_DISABLE_DEPRECATED


#ifndef GLIBMM_DISABLE_DEPRECATED

  /** Retrieves the Object instance used as the target of the binding.
   *
   * A Binding can outlive the target Object as the binding does not hold a
   * strong reference to the target. If the target is destroyed before the
   * binding then this function will return <tt>nullptr</tt>.
   *
   * Use g_binding_dup_target() if the target or binding are used from different
   * threads as otherwise the pointer returned from this function might become
   * invalid if the target is finalized from another thread in the meantime.
   *
   * Deprecated: 2.68: Use g_binding_dup_target() for a safer version of this
   * function.
   *
   * @newin{2,44}
   *
   * @deprecated Use dup_target() instead.
   *
   * @return The target Object, or <tt>nullptr</tt> if the
   * target does not exist any more.
   */
  auto get_target() const -> const Glib::ObjectBase*;
#endif // GLIBMM_DISABLE_DEPRECATED


  /** Retrieves the Object instance used as the target of the binding.
   *
   * A Binding can outlive the target Object as the binding does not hold a
   * strong reference to the target. If the target is destroyed before the
   * binding then this function will return <tt>nullptr</tt>.
   *
   * @newin{2,70}
   *
   * @return The target Object, or <tt>nullptr</tt> if the
   * target does not exist any more.
   */
  auto dup_target() -> Glib::RefPtr<Glib::ObjectBase>;

  /** Retrieves the Object instance used as the target of the binding.
   *
   * A Binding can outlive the target Object as the binding does not hold a
   * strong reference to the target. If the target is destroyed before the
   * binding then this function will return <tt>nullptr</tt>.
   *
   * @newin{2,70}
   *
   * @return The target Object, or <tt>nullptr</tt> if the
   * target does not exist any more.
   */
  auto dup_target() const -> Glib::RefPtr<const Glib::ObjectBase>;


  /** Retrieves the name of the property of Binding::property_target() used as the target
   * of the binding.
   *
   * @newin{2,44}
   *
   * @return The name of the target property.
   */
  auto get_target_property() const -> Glib::ustring;

  /** Retrieves the flags passed when constructing the Binding.
   *
   * @newin{2,44}
   *
   * @return The Glib::Binding::Flags used by the Binding.
   */
  auto get_flags() const -> Flags;

  /** Explicitly releases the binding between the source and the target
   * property expressed by this Binding instance.
   *
   * The binding is also released if either the source object or the target
   * object is deleted, or this Binding instance loses its last reference,
   * i.e. there is no more Glib::RefPtr that holds a pointer to it.
   *
   * @newin{2,44}
   */
  void unbind();


  /** Flags to be used to control the Binding
   *
   * @newin{2,44}
   *
   * Default value: Glib::Binding::Flags::DEFAULT
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_flags() const -> Glib::PropertyProxy_ReadOnly< Flags >;


  /** The Object that should be used as the source of the binding
   *
   * @newin{2,44}
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_source() const -> Glib::PropertyProxy_ReadOnly< Glib::RefPtr<Glib::ObjectBase> >;


  /** The name of the property of Binding::property_source() that should be used
   * as the source of the binding.
   *
   * This should be in [canonical form][canonical-parameter-names] to get the
   * best performance.
   *
   * @newin{2,44}
   *
   * Default value: ""
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_source_property() const -> Glib::PropertyProxy_ReadOnly< Glib::ustring >;


  /** The Object that should be used as the target of the binding
   *
   * @newin{2,44}
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_target() const -> Glib::PropertyProxy_ReadOnly< Glib::RefPtr<Glib::ObjectBase> >;


  /** The name of the property of Binding::property_target() that should be used
   * as the target of the binding.
   *
   * This should be in [canonical form][canonical-parameter-names] to get the
   * best performance.
   *
   * @newin{2,44}
   *
   * Default value: ""
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_target_property() const -> Glib::PropertyProxy_ReadOnly< Glib::ustring >;


private:
  // The functor TransformProp can be implicitly converted to a SlotTransform
  // and used in a call to bind_property_value().
  template <typename T_from, typename T_to>
  class TransformProp
  {
  public:
    explicit TransformProp(const SlotTypedTransform<T_from, T_to>& slot) : typed_transform(slot) {}

    // g++-10 with optimization level -O1 or higher warns about possible use of
    // an uninitialized variable when tests/glibmm_binding/main.cc is compiled.
    // I don't understand why. Don't optimize this function. /Kjell 2020-12-08
    //   sigc++-3.0/sigc++/functors/slot.h:226:21: warning: ‘<anonymous>’ may be
    //   used uninitialized in this function [-Wmaybe-uninitialized]
    //   226 |     return T_return();
#if __GNUC__ >= 10
  __attribute__ ((optimize(0)))
#endif
    auto operator()(const GValue* from_value, GValue* to_value) -> bool
    {
      Glib::Value<T_from> from_glib_value;
      from_glib_value.init(from_value);
      const auto to = typed_transform(from_glib_value.get());

      if (!to.has_value())
        return false;

      Glib::Value<T_to> to_glib_value;
      to_glib_value.init(to_value);
      to_glib_value.set(*to);
      g_value_copy(to_glib_value.gobj(), to_value);
      return true;
    }

  private:
    SlotTypedTransform<T_from, T_to> typed_transform;
  };


public:

public:
  //C++ methods used to invoke GTK+ virtual functions:

protected:
  //GTK+ Virtual Functions (override these to change behaviour):

  //Default Signal Handlers::


};

} // namespace Glib

namespace Glib
{

/** @ingroup glibmmEnums */
inline auto operator|(Binding::Flags lhs, Binding::Flags rhs) -> Binding::Flags
  { return static_cast<Binding::Flags>(static_cast<unsigned>(lhs) | static_cast<unsigned>(rhs)); }

/** @ingroup glibmmEnums */
inline auto operator&(Binding::Flags lhs, Binding::Flags rhs) -> Binding::Flags
  { return static_cast<Binding::Flags>(static_cast<unsigned>(lhs) & static_cast<unsigned>(rhs)); }

/** @ingroup glibmmEnums */
inline auto operator^(Binding::Flags lhs, Binding::Flags rhs) -> Binding::Flags
  { return static_cast<Binding::Flags>(static_cast<unsigned>(lhs) ^ static_cast<unsigned>(rhs)); }

/** @ingroup glibmmEnums */
inline auto operator~(Binding::Flags flags) -> Binding::Flags
  { return static_cast<Binding::Flags>(~static_cast<unsigned>(flags)); }

/** @ingroup glibmmEnums */
inline auto operator|=(Binding::Flags& lhs, Binding::Flags rhs) -> Binding::Flags&
  { return (lhs = static_cast<Binding::Flags>(static_cast<unsigned>(lhs) | static_cast<unsigned>(rhs))); }

/** @ingroup glibmmEnums */
inline auto operator&=(Binding::Flags& lhs, Binding::Flags rhs) -> Binding::Flags&
  { return (lhs = static_cast<Binding::Flags>(static_cast<unsigned>(lhs) & static_cast<unsigned>(rhs))); }

/** @ingroup glibmmEnums */
inline auto operator^=(Binding::Flags& lhs, Binding::Flags rhs) -> Binding::Flags&
  { return (lhs = static_cast<Binding::Flags>(static_cast<unsigned>(lhs) ^ static_cast<unsigned>(rhs))); }
} // namespace Glib

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

template <>
class GLIBMM_API Value<Glib::Binding::Flags> : public Glib::Value_Flags<Glib::Binding::Flags>
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
   * @relates Glib::Binding
   */
  GLIBMM_API
  auto wrap(GBinding* object, bool take_copy = false) -> Glib::RefPtr<Glib::Binding>;
}


#endif /* _GLIBMM_BINDING_H */

