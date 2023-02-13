
#ifndef _GTKMM_STRINGSORTER_H
#define _GTKMM_STRINGSORTER_H


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
{ class GTKMM_API StringSorter_Class; } // namespace Gtk
#endif //DOXYGEN_SHOULD_SKIP_THIS

namespace Gtk
{

/** Sort by comparing strings.
 *
 * %Gtk::StringSorter is a Gtk::Sorter that compares strings. It does the
 * comparison in a linguistically correct way using the current locale by
 * normalizing Unicode strings and possibly case-folding them before
 * performing the comparison.
 *
 * To obtain the strings to compare, this sorter evaluates a Gtk::Expression.
 *
 * @see Gtk::Expression
 * @newin{3,98}
 */

class GTKMM_API StringSorter : public Sorter
{

#ifndef DOXYGEN_SHOULD_SKIP_THIS

public:
  using CppObjectType = StringSorter;
  using CppClassType = StringSorter_Class;
  using BaseObjectType = GtkStringSorter;
  using BaseClassType = GtkStringSorterClass;

  // noncopyable
  StringSorter(const StringSorter&) = delete;
  auto operator=(const StringSorter&) -> StringSorter& = delete;

private:  friend class StringSorter_Class;
  static CppClassType stringsorter_class_;

protected:
  explicit StringSorter(const Glib::ConstructParams& construct_params);
  explicit StringSorter(GtkStringSorter* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  StringSorter(StringSorter&& src) noexcept;
  auto operator=(StringSorter&& src) noexcept -> StringSorter&;

  ~StringSorter() noexcept override;

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS


  static auto get_base_type() -> GType G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GObject.
  auto       gobj() -> GtkStringSorter*       { return reinterpret_cast<GtkStringSorter*>(gobject_); }

  ///Provides access to the underlying C GObject.
  auto gobj() const -> const GtkStringSorter* { return reinterpret_cast<GtkStringSorter*>(gobject_); }

  ///Provides access to the underlying C instance. The caller is responsible for unrefing it. Use when directly setting fields in structs.
  auto gobj_copy() -> GtkStringSorter*;

private:


protected:
    explicit StringSorter(const Glib::RefPtr<Expression<Glib::ustring>>& expression);


public:

  static auto create(const Glib::RefPtr<Expression<Glib::ustring>>& expression) -> Glib::RefPtr<StringSorter>;


  /** Gets the expression that is evaluated to obtain strings from items.
   *
   * @return A `Gtk::Expression`.
   */
  auto get_expression() -> Glib::RefPtr<Expression<Glib::ustring>>;

  /** Gets the expression that is evaluated to obtain strings from items.
   *
   * @return A `Gtk::Expression`.
   */
  auto get_expression() const -> Glib::RefPtr<const Expression<Glib::ustring>>;

  /** Sets the expression that is evaluated to obtain strings from items.
   *
   * The expression must have the type G_TYPE_STRING.
   *
   * @param expression A `Gtk::Expression`.
   */
  void set_expression(const Glib::RefPtr<Expression<Glib::ustring>>& expression);

  /** Gets whether the sorter ignores case differences.
   *
   * @return <tt>true</tt> if @a self is ignoring case differences.
   */
  auto get_ignore_case() const -> bool;

  /** Sets whether the sorter will ignore case differences.
   *
   * @param ignore_case <tt>true</tt> to ignore case differences.
   */
  void set_ignore_case(bool ignore_case =  true);

  /** The expression to evaluate on item to get a string to compare with.
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_expression() -> Glib::PropertyProxy< Glib::RefPtr<Expression<Glib::ustring>> > ;

/** The expression to evaluate on item to get a string to compare with.
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_expression() const -> Glib::PropertyProxy_ReadOnly< Glib::RefPtr<Expression<Glib::ustring>> >;

  /** If matching is case sensitive.
   *
   * Default value: <tt>true</tt>
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_ignore_case() -> Glib::PropertyProxy< bool > ;

/** If matching is case sensitive.
   *
   * Default value: <tt>true</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_ignore_case() const -> Glib::PropertyProxy_ReadOnly< bool >;


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
   * @relates Gtk::StringSorter
   */
  GTKMM_API
  auto wrap(GtkStringSorter* object, bool take_copy = false) -> Glib::RefPtr<Gtk::StringSorter>;
}


#endif /* _GTKMM_STRINGSORTER_H */

