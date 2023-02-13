
#ifndef _GTKMM_BOOLFILTER_H
#define _GTKMM_BOOLFILTER_H


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

#include <libmm-gtk/filter.hpp>
#include <libmm-gtk/expression.hpp>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{ class GTKMM_API BoolFilter_Class; } // namespace Gtk
#endif //DOXYGEN_SHOULD_SKIP_THIS

namespace Gtk
{

/** Filtering by boolean expressions.
 *
 * %Gtk::BoolFilter is a simple filter that takes a boolean Gtk::Expression
 * to determine whether to include items.
 *
 * @newin{3,98}
 */

class GTKMM_API BoolFilter : public Filter
{

#ifndef DOXYGEN_SHOULD_SKIP_THIS

public:
  using CppObjectType = BoolFilter;
  using CppClassType = BoolFilter_Class;
  using BaseObjectType = GtkBoolFilter;
  using BaseClassType = GtkBoolFilterClass;

  // noncopyable
  BoolFilter(const BoolFilter&) = delete;
  auto operator=(const BoolFilter&) -> BoolFilter& = delete;

private:  friend class BoolFilter_Class;
  static CppClassType boolfilter_class_;

protected:
  explicit BoolFilter(const Glib::ConstructParams& construct_params);
  explicit BoolFilter(GtkBoolFilter* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  BoolFilter(BoolFilter&& src) noexcept;
  auto operator=(BoolFilter&& src) noexcept -> BoolFilter&;

  ~BoolFilter() noexcept override;

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS


  static auto get_base_type() -> GType G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GObject.
  auto       gobj() -> GtkBoolFilter*       { return reinterpret_cast<GtkBoolFilter*>(gobject_); }

  ///Provides access to the underlying C GObject.
  auto gobj() const -> const GtkBoolFilter* { return reinterpret_cast<GtkBoolFilter*>(gobject_); }

  ///Provides access to the underlying C instance. The caller is responsible for unrefing it. Use when directly setting fields in structs.
  auto gobj_copy() -> GtkBoolFilter*;

private:


protected:
    explicit BoolFilter(const Glib::RefPtr<Expression<bool>>& expression);


public:

  static auto create(const Glib::RefPtr<Expression<bool>>& expression) -> Glib::RefPtr<BoolFilter>;


  /** Gets the expression that the filter uses to evaluate if
   * an item should be filtered.
   *
   * @return A `Gtk::Expression`.
   */
  auto get_expression() -> Glib::RefPtr<Expression<bool>>;

  /** Gets the expression that the filter uses to evaluate if
   * an item should be filtered.
   *
   * @return A `Gtk::Expression`.
   */
  auto get_expression() const -> Glib::RefPtr<const Expression<bool>>;

  /** Sets the expression that the filter uses to check if items
   * should be filtered.
   *
   * The expression must have a value type of G_TYPE_BOOLEAN.
   *
   * @param expression A `Gtk::Expression`.
   */
  void set_expression(const Glib::RefPtr<Expression<bool>>& expression);

  /** Returns whether the filter inverts the expression.
   *
   * @return <tt>true</tt> if the filter inverts.
   */
  auto get_invert() const -> bool;

  /** Sets whether the filter should invert the expression.
   *
   * @param invert <tt>true</tt> to invert.
   */
  void set_invert(bool invert =  true);

  /** The boolean expression to evaluate on item.
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_expression() -> Glib::PropertyProxy< Glib::RefPtr<Expression<bool>> > ;

/** The boolean expression to evaluate on item.
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_expression() const -> Glib::PropertyProxy_ReadOnly< Glib::RefPtr<Expression<bool>> >;

  /** If the expression result should be inverted.
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_invert() -> Glib::PropertyProxy< bool > ;

/** If the expression result should be inverted.
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_invert() const -> Glib::PropertyProxy_ReadOnly< bool >;


public:

public:
  //C++ methods used to invoke GTK+ virtual functions:

protected:
  //GTK+ Virtual Functions (override these to change behaviour):

  //Default Signal Handlers::


};

} // namespace Gtk


namespace Glib
{
  /** A Glib::wrap() method for this object.
   *
   * @param object The C instance.
   * @param take_copy False if the result should take ownership of the C instance. True if it should take a new copy or ref.
   * @result A C++ instance that wraps this C instance.
   *
   * @relates Gtk::BoolFilter
   */
  GTKMM_API
  auto wrap(GtkBoolFilter* object, bool take_copy = false) -> Glib::RefPtr<Gtk::BoolFilter>;
}


#endif /* _GTKMM_BOOLFILTER_H */

