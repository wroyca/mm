
#ifndef _GTKMM_NUMERICSORTER_H
#define _GTKMM_NUMERICSORTER_H


#include <libmm-glib/ustring.hpp>
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

#include <libmm-gtk/sorter.hpp>
#include <libmm-gtk/expression.hpp>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{ class GTKMM_API NumericSorterBase_Class; } // namespace Gtk
#endif //DOXYGEN_SHOULD_SKIP_THIS

namespace Gtk
{

/** Base class for Gtk::NumericSorter.
 *
 * @see Gtk::NumericSorter
 *
 * @newin{3,98}
 */

class GTKMM_API NumericSorterBase : public Sorter
{

#ifndef DOXYGEN_SHOULD_SKIP_THIS

public:
  using CppObjectType = NumericSorterBase;
  using CppClassType = NumericSorterBase_Class;
  using BaseObjectType = GtkNumericSorter;
  using BaseClassType = GtkNumericSorterClass;

  // noncopyable
  NumericSorterBase(const NumericSorterBase&) = delete;
  auto operator=(const NumericSorterBase&) -> NumericSorterBase& = delete;

private:  friend class NumericSorterBase_Class;
  static CppClassType numericsorterbase_class_;

protected:
  explicit NumericSorterBase(const Glib::ConstructParams& construct_params);
  explicit NumericSorterBase(GtkNumericSorter* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  NumericSorterBase(NumericSorterBase&& src) noexcept;
  auto operator=(NumericSorterBase&& src) noexcept -> NumericSorterBase&;

  ~NumericSorterBase() noexcept override;

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS


  static auto get_base_type() -> GType G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GObject.
  auto       gobj() -> GtkNumericSorter*       { return reinterpret_cast<GtkNumericSorter*>(gobject_); }

  ///Provides access to the underlying C GObject.
  auto gobj() const -> const GtkNumericSorter* { return reinterpret_cast<GtkNumericSorter*>(gobject_); }

  ///Provides access to the underlying C instance. The caller is responsible for unrefing it. Use when directly setting fields in structs.
  auto gobj_copy() -> GtkNumericSorter*;

private:


protected:


    explicit NumericSorterBase(const Glib::RefPtr<ExpressionBase>& expression);


public:


  /** Gets whether this sorter will sort smaller numbers first.
   *
   * @return The order of the numbers.
   */
  auto get_sort_order() const -> SortType;

  /** Sets whether to sort smaller numbers before larger ones.
   *
   * @param sort_order Whether to sort smaller numbers first.
   */
  void set_sort_order(SortType sort_order);


  /** Whether the sorter will sort smaller numbers first.
   *
   * Default value: Gtk::SortType::ASCENDING
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_sort_order() -> Glib::PropertyProxy< SortType > ;

/** Whether the sorter will sort smaller numbers first.
   *
   * Default value: Gtk::SortType::ASCENDING
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_sort_order() const -> Glib::PropertyProxy_ReadOnly< SortType >;


public:

public:
  //C++ methods used to invoke GTK+ virtual functions:

protected:
  //GTK+ Virtual Functions (override these to change behaviour):

  //Default Signal Handlers::


};

/** Sort by comparing numbers.
 *
 * %Gtk::NumericSorter is a Gtk::Sorter that compares numbers.
 *
 * To obtain the numbers to compare, this sorter evaluates a Gtk::Expression.
 *
 * @see Gtk::Expression
 * @newin{3,98}
 */
template<class T>
class NumericSorter : public NumericSorterBase
{
  static_assert(std::is_arithmetic<T>::value);

protected:
  NumericSorter(const Glib::RefPtr<Expression<T>>& expression);

public:
  static auto create(const Glib::RefPtr<Expression<T>>& expression) -> Glib::RefPtr<NumericSorter>;

  /** Gets the expression that is evaluated to obtain numbers from items.
   *
   * @return A Gtk::Expression, or <tt>nullptr</tt>.
   */
  auto get_expression() -> Glib::RefPtr<Expression<T>>;
  /** @copydoc get_expression()
   */
  auto get_expression() const -> Glib::RefPtr<const Expression<T>>;

  /** Sets the expression that is evaluated to obtain numbers from items.
   *
   * Unless an expression is set on the %Gtk::NumericSorter, the
   * sorter will always compare items as invalid.
   *
   * The expression must have a return type that can be compared
   * numerically, such as int or double.
   *
   * @param expression A Gtk::Expression, or <tt>nullptr</tt>.
   */
  void set_expression(const Glib::RefPtr<Expression<T>>& expression);

  /** The expression to evalute on items to get a number to compare with
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_expression() -> Glib::PropertyProxy<Glib::RefPtr<Expression<T>>>;

  /** The expression to evalute on items to get a number to compare with
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_expression() const -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<Expression<T>>>;
};

#ifndef DOXYGEN_SHOULD_SKIP_THIS

template<class T>
NumericSorter<T>::NumericSorter(const Glib::RefPtr<Expression<T>>& expression)
:
  NumericSorterBase(expression)
{
}

template<class T>
auto NumericSorter<T>::create(
  const Glib::RefPtr<Expression<T>>& expression) -> Glib::RefPtr<NumericSorter<T>>
{
  return Glib::make_refptr_for_instance<NumericSorter>(new NumericSorter(expression));
}

template<class T>
void NumericSorter<T>::set_expression(const Glib::RefPtr<Expression<T>>& expression)
{
  gtk_numeric_sorter_set_expression(gobj(), const_cast<GtkExpression*>(expression->gobj()));
}

template<class T>
auto NumericSorter<T>::get_expression() -> Glib::RefPtr<Expression<T>>
{
  return Glib::wrap<T>(gtk_numeric_sorter_get_expression(gobj()), true);
}

template<class T>
auto NumericSorter<T>::get_expression() const -> Glib::RefPtr<const Expression<T>>
{
  return Glib::wrap<T>(gtk_numeric_sorter_get_expression(const_cast<GtkNumericSorter*>(gobj())),
    true);
}

template<class T>
auto NumericSorter<T>::property_expression() -> Glib::PropertyProxy<Glib::RefPtr<Expression<T>>>
{
  return Glib::PropertyProxy<Glib::RefPtr<Expression<T>>>(this, "expression");
}

template<class T>
auto
NumericSorter<T>::property_expression() const -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<Expression<T>>>
{
  return Glib::PropertyProxy_ReadOnly<Glib::RefPtr<Expression<T>>>(this, "expression");
}

#endif

} // namespace Gtk


namespace Glib
{
  /** A Glib::wrap() method for this object.
   *
   * @param object The C instance.
   * @param take_copy False if the result should take ownership of the C instance. True if it should take a new copy or ref.
   * @result A C++ instance that wraps this C instance.
   *
   * @relates Gtk::NumericSorterBase
   */
  GTKMM_API
  auto wrap(GtkNumericSorter* object, bool take_copy = false) -> Glib::RefPtr<Gtk::NumericSorterBase>;
}


#endif /* _GTKMM_NUMERICSORTER_H */

