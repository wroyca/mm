
#ifndef _GTKMM_EXPRESSION_H
#define _GTKMM_EXPRESSION_H


#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

/* Copyright (C) 2020 The gtkmm Development Team
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

#include <libmm-gtk/expressionwatch.hxx>


namespace Gtk
{

/** Base class for Gtk::Expression.
 *
 * @see Gtk::Expression
 *
 * @newin{3,98}
 */
class GTKMM_API ExpressionBase
{
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  using CppObjectType = ExpressionBase;
  using BaseObjectType = GtkExpression;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


  /** Increment the reference count for this object.
   * You should never need to do this manually - use the object via a RefPtr instead.
   */
  void reference()   const;

  /** Decrement the reference count for this object.
   * You should never need to do this manually - use the object via a RefPtr instead.
   */
  void unreference() const;

  ///Provides access to the underlying C instance.
  auto       gobj() -> GtkExpression*;

  ///Provides access to the underlying C instance.
  auto gobj() const -> const GtkExpression*;

  ///Provides access to the underlying C instance. The caller is responsible for unrefing it. Use when directly setting fields in structs.
  auto gobj_copy() const -> GtkExpression*;

  ExpressionBase() = delete;

  // noncopyable
  ExpressionBase(const ExpressionBase&) = delete;
  auto operator=(const ExpressionBase&) -> ExpressionBase& = delete;

protected:
  // Do not derive this.  Gtk::ExpressionBase can neither be constructed nor deleted.

  void operator delete(void*, std::size_t);

private:


public:

  /** For instance: void on_notify();
   *
   * Callback called by Gtk::Expression::watch() when the expression
   * value changes.
   */
  using SlotNotify = sigc::slot<void()>;


  /** Gets the `GType` that this expression evaluates to.
   *
   * This type is constant and will not change over the lifetime
   * of this expression.
   *
   * @return The type returned from Gtk::Expression::evaluate().
   */
  auto get_value_type() const -> GType;

  /** Checks if the expression is static.
   *
   * A static expression will never change its result when
   * Gtk::Expression::evaluate() is called on it with the same arguments.
   *
   * That means a call to Gtk::Expression::watch() is not necessary because
   * it will never trigger a notify.
   *
   * @return <tt>true</tt> if the expression is static.
   */
  auto is_static() const -> bool;


};

/** Expressions to values.
 *
 * %Gtk::Expression provides a way to describe references to values.
 *
 * An important aspect of expressions is that the value can be obtained
 * from a source that is several steps away. For example, an expression
 * may describe ‘the value of property A of @a object1, which is itself the
 * value of a property of @a object2’. And @a object1 may not even exist yet
 * at the time that the expression is created. This is contrast to
 * Glib::Binding, which can only create direct connections between
 * the properties of two objects that must both exist for the duration
 * of the binding.
 *
 * An expression needs to be "evaluated" to obtain the value that it currently
 * refers to. An evaluation always happens in the context of a current object
 * called `this` (it mirrors the behavior of object-oriented languages),
 * which may or may not influence the result of the evaluation. Use
 * evaluate() for evaluating an expression.
 *
 * Various methods for defining expressions exist, from simple constants via
 * Gtk::ConstantExpression() to looking up properties in an object (even
 * recursively) via Gtk::PropertyExpression() or providing custom functions
 * to transform and combine expressions via Gtk::ClosureExpression().
 *
 * Here is an example of a complex expression:
 * ~~~
 *   color_expr = Gtk::PropertyExpression<Glib::RefPtr<Glib::ObjectBase>>::create(
 *       Gtk::ListItem::get_type(), "item");
 *   expression = Gtk::PropertyExpression<Glib::ustring>::create(
 *       GTK_TYPE_COLOR, color_expr, "name");
 * ~~~
 * when evaluated with `this` being a Gtk::ListItem, it will obtain the
 * "item" property from the Gtk::ListItem, and then obtain the "name" property
 * from the resulting object (which is assumed to be of type GTK_TYPE_COLOR).
 *
 * A more concise way to describe this would be
 * ~~~
 *   this->item->name
 * ~~~
 *
 * The most likely place where you will encounter expressions is in the context
 * of list models and list widgets using them. For example, Gtk::DropDown is
 * evaluating a %Gtk::Expression to obtain strings from the items in its model
 * that it can then use to match against the contents of its search entry.
 * Gtk::StringFilter is using a %Gtk::Expression for similar reasons.
 *
 * By default, expressions are not paying attention to changes and evaluation is
 * just a snapshot of the current state at a given time. To get informed about
 * changes, an expression needs to be "watched" via a Gtk::ExpressionWatch, which
 * will cause a callback to be called whenever the value of the expression may
 * have changed. watch() starts watching an expression, and
 * Gtk::ExpressionWatch::unwatch() stops.
 *
 * Watches can be created for automatically updating the propery of an object,
 * similar to the Glib::Binding mechanism, by using bind().
 *
 * @newin{3,98}
 */
template<class T>
class Expression : public ExpressionBase
{
public:
  using ValueType = T;

  /** Evaluates the given expression and on success returns the result.
   *
   * It is possible that expressions cannot be evaluated - for example
   * when the expression references objects that have been destroyed or
   * set to <tt>nullptr</tt>. In that case the returned std::optional
   * will not contain a value.
   *
   * @param this_ The this argument for the evaluation.
   * @return The optional result of the evaluation.
   */
  auto evaluate(const Glib::RefPtr<Glib::ObjectBase>& this_) -> std::optional<T>;

  /** Installs a watch for the expression that calls the @a notify function
   * whenever the evaluation of the expression may have changed.
   *
   * GTK cannot guarantee that the evaluation did indeed change when the @a notify
   * gets invoked, but it guarantees the opposite: When it did in fact change,
   * the @a notify will be invoked.
   *
   * @param this_ The `this` argument to watch.
   * @param notify Callback to invoke when the expression changes.
   * @return The newly installed watch.
   */
  auto watch(const Glib::RefPtr<Glib::ObjectBase>& this_,
                                         const SlotNotify& notify) -> Glib::RefPtr<ExpressionWatch<T>>;

  /** Bind a target's @a property to the expression.
   *
   * The value that the expression evaluates to is set on the target.
   * This is repeated whenever the expression changes to ensure that
   * the object's property stays synchronized with the expression.
   *
   * If the expression's evaluation fails, target's @a property is not updated.
   * You can ensure that this doesn't happen by using a fallback
   * expression.
   *
   * @param property Property on the target to bind to.
   * @param this_ The this argument for the evaluation of the expression.
   * @return A Gtk::ExpressionWatch.
   */
  template<class T2>
  auto bind(const Glib::PropertyProxy<T2>& property,
                                        const Glib::RefPtr<Glib::ObjectBase>& this_ = nullptr) -> Glib::RefPtr<ExpressionWatch<T>>;

  /** @copydoc bind(const Glib::PropertyProxy<T2>&,const Glib::RefPtr<Glib::ObjectBase>&)
   */
  template<class T2>
  auto bind(const Glib::PropertyProxy_WriteOnly<T2>& property,
                                        const Glib::RefPtr<Glib::ObjectBase>& this_ = nullptr) -> Glib::RefPtr<ExpressionWatch<T>>;
};

template<class T>
class PropertyExpression final : public Expression<T>
{
public:
  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType G_GNUC_CONST;

  /** Creates an expression that looks up a property via the
   * `this` argument.
   *
   * If the resulting object conforms to @a this_type, its property
   * named @a property_name will be queried.
   * Otherwise, this expression's evaluation will fail.
   *
   * The given @a this_type must have a property with @a property_name.
   *
   * @param this_type The type to expect for the this type.
   * @param property_name Name of the property.
   * @return A new Gtk::Expression.
   */
  static auto create(GType this_type,
                                                 const Glib::ustring& property_name) -> Glib::RefPtr<PropertyExpression>;

  /** Creates an expression that looks up a property via the
   * given @a expression.
   *
   * If the resulting object conforms to @a OT, its property
   * named @a property_name will be queried.
   * Otherwise, this expression's evaluation will fail.
   *
   * The value type of the given @a expression must have a property with
   * @a property_name.
   *
   * @param expression Expression to evaluate to get the object to query.
   * @param property_name Name of the property.
   * @return A new Gtk::Expression.
   */
  template<class OT>
  static auto create(const Glib::RefPtr<OT>& expression,
                                                 const Glib::ustring& property_name) -> Glib::RefPtr<PropertyExpression>;

  /** Creates an expression that looks up a property via the
   * given @a expression.
   *
   * If the resulting object conforms to @a this_type, its property
   * named @a property_name will be queried.
   * Otherwise, this expression's evaluation will fail.
   *
   * The given @a this_type must have a property with @a property_name.
   *
   * @param this_type The type to expect for the this type.
   * @param expression Expression to evaluate to get the object to query.
   * @param property_name Name of the property.
   * @return A new Gtk::Expression.
   */
  template<class OT>
  static auto create(GType this_type,
                                                 const Glib::RefPtr<OT>& expression,
                                                 const Glib::ustring& property_name) -> Glib::RefPtr<PropertyExpression>;
};

template<class T>
class ConstantExpression final : public Expression<T>
{
public:
  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType G_GNUC_CONST;

  /** Creates a Gtk::Expression that evaluates to the object given by
   * the arguments.
   *
   * @param args Arguments to create the object from.
   * @return A new Gtk::Expression.
   */
  template<class... T_Args>
  static auto create(T_Args&&... args) -> Glib::RefPtr<ConstantExpression<T>>;

  /** Creates an expression that always evaluates to the given @a value.
   *
   * @param value A Value.
   * @return A new Gtk::Expression.
   */
  static auto create_for_value(const Glib::Value<T>& value) -> Glib::RefPtr<ConstantExpression<T>>;
};

template<class T>
class ObjectExpression final : public Expression<T>
{
public:
  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType G_GNUC_CONST;

  /** Creates an expression evaluating to the given @a object with a weak reference.
   * Once the @a object is disposed, it will fail to evaluate.
   * This expression is meant to break reference cycles.
   *
   * If you want to keep a reference to @a object, use Gtk::ConstantExpression::create().
   *
   * @param object %Object to watch.
   * @return A new Gtk::Expression.
   */
  static auto create(const T& object) -> Glib::RefPtr<ObjectExpression<T>>;
};

template<class T>
class ClosureExpression final : public Expression<T>
{
public:
  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType G_GNUC_CONST;

  /** Creates a Gtk::Expression that calls @a slot when it is evaluated.
   * @a slot is called with the @a this object and the results of evaluating
   * the @a params expressions.
   *
   * Example:
   * ~~~
   * Glib::ustring get_string(Glib::RefPtr<Glib::ObjectBase> this_, double a, int b)
   * {
   *   return Glib::ustring::sprintf("a is %f, b is %d", a, b);
   * }
   *
   * Glib::RefPtr<Gtk::Expression<double>> expr1 = ...
   * Glib::RefPtr<Gtk::Expression<int>> expr2 = ...
   *
   * Glib::RefPtr<Gtk::Expression<Glib::ustring>> expr3 =
   *   Gtk::ClosureExpression<Glib::ustring>::create(
   *     sigc::ptr_fun(get_string), expr1, expr2);
   * ~~~
   *
   * @param slot Slot to call when evaluating this expression.
   * @param params Expressions for each parameter.
   * @return A new Gtk::Expression.
   */
  template<class S, class... ATs>
  static auto create(S slot, const Glib::RefPtr<ATs>&... params) -> Glib::RefPtr<ClosureExpression<T>>;

private:
  template<class A1, class... ATs>
  static void fill_params(GtkExpression** gparams, const Glib::RefPtr<A1>& a1,
                          const Glib::RefPtr<ATs>&... eas);

  static void fill_params(GtkExpression** gparams);
};

#ifndef DOXYGEN_SHOULD_SKIP_THIS

namespace Expression_Private
{

GTKMM_API
void watch_callback(gpointer data);

template<class T, class... ATs>
class Invoker
{
public:
  explicit Invoker(const sigc::slot<T(ATs...)>& slot);
  void invoke(const GValue* param_values, GValue* return_value);

private:
  sigc::slot<T(ATs...)> the_slot;

  template<class PT>
  auto eval_param(const GValue* gv) -> PT;

  template<std::size_t... I>
  void invoke(const GValue* param_values, GValue* return_value,
              std::index_sequence<I...>);
};


template<class TI>
void closure_marshal(GClosure* closure,
                     GValue* return_value,
                     guint n_param_values,
                     const GValue* param_values,
                     gpointer invocation_hint,
                     gpointer marshal_data);

GTKMM_API
void closure_callback_func();

template<class TI>
void closure_destroy(gpointer data, GClosure* closure);

} // namespace Expression_Private

template<class T>
auto Expression<T>::evaluate(const Glib::RefPtr<Glib::ObjectBase>& this_) -> std::optional<T>
{
  Glib::Value<T> value;
  bool result = gtk_expression_evaluate(gobj(), this_ ? this_->gobj() : nullptr, value.gobj());
  if (!result)
    return {};

  if (!G_VALUE_HOLDS(value.gobj(), Glib::Value<T>::value_type()))
  {
    g_warning("%s: The evaluated expression has type '%s', expected '%s'", G_STRLOC,
      g_type_name(G_VALUE_TYPE(value.gobj())), g_type_name(Glib::Value<T>::value_type()));
    return {};
  }

  return value.get();
}

template<class T>
auto Expression<T>::watch(const Glib::RefPtr<Glib::ObjectBase>& this_,
                                                      const SlotNotify& notify) -> Glib::RefPtr<ExpressionWatch<T>>
{
  auto slot_copy = new SlotNotify(notify);
  return Glib::wrap<T>(gtk_expression_watch(gobj(), this_ ? this_->gobj() : nullptr,
                                            &Expression_Private::watch_callback, slot_copy,
                                            &Glib::destroy_notify_delete<SlotNotify>), true);
}

template<class T>
template<class T2>
auto Expression<T>::bind(const Glib::PropertyProxy<T2>& property,
                                                     const Glib::RefPtr<Glib::ObjectBase>& this_) -> Glib::RefPtr<ExpressionWatch<T>>
{
  return Glib::wrap<T>(gtk_expression_bind(gobj_copy(), property.get_object()->gobj(),
                                           property.get_name(),
                                           this_ ? this_->gobj() : nullptr), true);
}

template<class T>
template<class T2>
auto Expression<T>::bind(
  const Glib::PropertyProxy_WriteOnly<T2>& property,
  const Glib::RefPtr<Glib::ObjectBase>& this_) -> Glib::RefPtr<ExpressionWatch<T>>
{
  return Glib::wrap<T>(gtk_expression_bind(gobj_copy(), property.get_object()->gobj(),
                                           property.get_name(),
                                           this_ ? this_->gobj() : nullptr), true);
}

template<class T>
auto PropertyExpression<T>::get_type() -> GType
{
  return gtk_property_expression_get_type();
}

template<class T>
auto PropertyExpression<T>::create(
  GType this_type, const Glib::ustring& property_name) -> Glib::RefPtr<PropertyExpression<T>>
{
  return Glib::make_refptr_for_instance<Gtk::PropertyExpression<T>>(
    reinterpret_cast<Gtk::PropertyExpression<T>*>(
      gtk_property_expression_new(this_type,
                                  nullptr,
                                  property_name.c_str())));
}

template<class T>
template<class OT>
auto PropertyExpression<T>::create(
  const Glib::RefPtr<OT>& expression, const Glib::ustring& property_name) -> Glib::RefPtr<PropertyExpression<T>>
{
  return Glib::make_refptr_for_instance<Gtk::PropertyExpression<T>>(
    reinterpret_cast<Gtk::PropertyExpression<T>*>(
      gtk_property_expression_new(Glib::Value<typename OT::ValueType>::value_type(),
                                  expression->gobj_copy(),
                                  property_name.c_str())));
}

template<class T>
template<class OT>
auto PropertyExpression<T>::create(
  GType this_type, const Glib::RefPtr<OT>& expression, const Glib::ustring& property_name) -> Glib::RefPtr<PropertyExpression<T>>
{
  return Glib::make_refptr_for_instance<Gtk::PropertyExpression<T>>(
    reinterpret_cast<Gtk::PropertyExpression<T>*>(
      gtk_property_expression_new(this_type,
                                  expression->gobj_copy(),
                                  property_name.c_str())));
}

template<class T>
auto ConstantExpression<T>::get_type() -> GType
{
  return gtk_constant_expression_get_type();
}

template<class T>
template<class... T_Args>
auto ConstantExpression<T>::create(T_Args&&... args) -> Glib::RefPtr<ConstantExpression<T>>
{
  Glib::Value<T> value;
  value.init(Glib::Value<T>::value_type());
  value.set(T(std::forward<T_Args>(args)...));
  return create_for_value(value);
}

template<class T>
auto ConstantExpression<T>::create_for_value(
  const Glib::Value<T>& value) -> Glib::RefPtr<ConstantExpression<T>>
{
  return Glib::make_refptr_for_instance<Gtk::ConstantExpression<T>>(
    reinterpret_cast<Gtk::ConstantExpression<T>*>(
      gtk_constant_expression_new_for_value(value.gobj())));
}

template<class T>
auto ObjectExpression<T>::get_type() -> GType
{
  return gtk_object_expression_get_type();
}

template<class T>
auto ObjectExpression<T>::create(const T& object) -> Glib::RefPtr<ObjectExpression<T>>
{
  return Glib::make_refptr_for_instance<Gtk::ObjectExpression<T>>(
    reinterpret_cast<Gtk::ObjectExpression<T>*>(
      gtk_object_expression_new(G_OBJECT(object->gobj()))));
}

template<class T>
auto ClosureExpression<T>::get_type() -> GType
{
  return gtk_cclosure_expression_get_type();
}

template<class T>
template<class S, class... ATs>
auto ClosureExpression<T>::create(S slot,
                                                                const Glib::RefPtr<ATs>&... params) -> Glib::RefPtr<ClosureExpression<T>>
{
  using TI = Expression_Private::Invoker<T, Glib::RefPtr<Glib::ObjectBase>,
                                         typename ATs::ValueType...>;
  auto invoker = new TI(slot);
  guint n_params = sizeof...(params);
  auto gparams = new GtkExpression*[n_params];
  fill_params(gparams, params...);

  auto object = gtk_cclosure_expression_new(
    Glib::Value<T>::value_type(),
    Expression_Private::closure_marshal<TI>,
    n_params,
    gparams,
    Expression_Private::closure_callback_func,
    invoker,
    Expression_Private::closure_destroy<TI>);
  delete[] gparams;

  return Glib::make_refptr_for_instance<Gtk::ClosureExpression<T>>(
    reinterpret_cast<Gtk::ClosureExpression<T>*>(object));
}

template<class T>
template<class A1, class... ATs>
void ClosureExpression<T>::fill_params(GtkExpression** gparams, const Glib::RefPtr<A1>& a1,
                                       const Glib::RefPtr<ATs>&... eas)
{
  gparams[0] = a1->gobj_copy();
  fill_params(gparams + 1, eas...);
}

template<class T>
void ClosureExpression<T>::fill_params(GtkExpression**)
{}


namespace Expression_Private
{

template<class T, class... ATs>
Invoker<T, ATs...>::Invoker(const sigc::slot<T(ATs...)>& slot)
:
  the_slot(slot)
{}

template<class T, class... ATs>
template<class PT>
auto Invoker<T, ATs...>::eval_param(const GValue* gv) -> PT
{
  Glib::Value<PT> v;
  v.init(gv);
  return v.get();
}

template<class T, class... ATs>
template<std::size_t... I>
void Invoker<T, ATs...>::invoke(const GValue* param_values, GValue* return_value,
                                std::index_sequence<I...>)
{
  T res = the_slot(eval_param<ATs>(&param_values[I])...);
  Glib::Value<T> rv;
  rv.init(Glib::Value<T>::value_type());
  rv.set(res);
  g_value_copy(rv.gobj(), return_value);
}

template<class T, class... ATs>
void Invoker<T, ATs...>::invoke(const GValue* param_values, GValue* return_value)
{
  invoke(param_values, return_value, std::make_index_sequence<sizeof...(ATs)>());
}


template<class TI>
void closure_marshal(GClosure* closure,
                     GValue* return_value,
                     guint,
                     const GValue* param_values,
                     gpointer,
                     gpointer)
{
  static_cast<TI*>(closure->data)->invoke(param_values, return_value);
}


template<class TI>
void closure_destroy(gpointer, GClosure* closure)
{
  delete static_cast<TI*>(closure->data);
}

} // namespace Expression_Private

#endif //DOXYGEN_SHOULD_SKIP_THIS

} // namespace Gtk


namespace Glib
{

template<class T>
auto wrap(GtkExpression* object, bool take_copy = false) -> RefPtr<Gtk::Expression<T>>
{
  if (take_copy && object)
    gtk_expression_ref(object);

  return Glib::make_refptr_for_instance<Gtk::Expression<T>>(
    reinterpret_cast<Gtk::Expression<T>*>(object));
}

template<class T>
class Value<RefPtr<Gtk::Expression<T>>> : public ValueBase
{
public:
  using CppType = RefPtr<Gtk::Expression<T>>;

  static auto value_type() -> GType;

  void set(const CppType& data);
  auto get() const -> CppType;
};

template<class T>
auto Value<RefPtr<Gtk::Expression<T>>>::value_type() -> GType
{
  return gtk_expression_get_type();
}

template<class T>
void Value<RefPtr<Gtk::Expression<T>>>::set(const CppType& data)
{
  gtk_value_set_expression(&gobject_, const_cast<GtkExpression*>(data->gobj()));
}

template<class T>
auto Value<RefPtr<Gtk::Expression<T>>>::get() const -> typename Value<RefPtr<Gtk::Expression<T>>>::CppType
{
  return wrap<T>(gtk_value_get_expression(&gobject_), true);
}

} // namespace Glib


namespace Glib
{

/** A Glib::wrap() method for this object.
 *
 * @param object The C instance.
 * @param take_copy False if the result should take ownership of the C instance. True if it should take a new copy or ref.
 * @result A C++ instance that wraps this C instance.
 *
 * @relates Gtk::ExpressionBase
 */
GTKMM_API
auto wrap(GtkExpression* object, bool take_copy = false) -> Glib::RefPtr<Gtk::ExpressionBase>;

} // namespace Glib


#endif /* _GTKMM_EXPRESSION_H */

