
#ifndef _GTKMM_STRINGFILTER_H
#define _GTKMM_STRINGFILTER_H


#include <mm/glib/ustring.hpp>
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

#include <mm/gtk/filter.hpp>
#include <mm/gtk/expression.hpp>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{ class GTKMM_API StringFilter_Class; } // namespace Gtk
#endif //DOXYGEN_SHOULD_SKIP_THIS

namespace Gtk
{

/** Filtering by strings.
 *
 * %Gtk::StringFilter determines whether to include items by looking
 * at strings and comparing them to a fixed search term. The strings
 * are obtained from the items by evaluating a Gtk::Expression.
 *
 * %Gtk::StringFilter has several different modes of comparison - it
 * can match the whole string, just a prefix, or any substring.
 *
 * @newin{3,98}
 */

class GTKMM_API StringFilter : public Filter
{

#ifndef DOXYGEN_SHOULD_SKIP_THIS

public:
  using CppObjectType = StringFilter;
  using CppClassType = StringFilter_Class;
  using BaseObjectType = GtkStringFilter;
  using BaseClassType = GtkStringFilterClass;

  // noncopyable
  StringFilter(const StringFilter&) = delete;
  auto operator=(const StringFilter&) -> StringFilter& = delete;

private:  friend class StringFilter_Class;
  static CppClassType stringfilter_class_;

protected:
  explicit StringFilter(const Glib::ConstructParams& construct_params);
  explicit StringFilter(GtkStringFilter* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  StringFilter(StringFilter&& src) noexcept;
  auto operator=(StringFilter&& src) noexcept -> StringFilter&;

  ~StringFilter() noexcept override;

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS


  static auto get_base_type() -> GType G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GObject.
  auto       gobj() -> GtkStringFilter*       { return reinterpret_cast<GtkStringFilter*>(gobject_); }

  ///Provides access to the underlying C GObject.
  auto gobj() const -> const GtkStringFilter* { return reinterpret_cast<GtkStringFilter*>(gobject_); }

  ///Provides access to the underlying C instance. The caller is responsible for unrefing it. Use when directly setting fields in structs.
  auto gobj_copy() -> GtkStringFilter*;

private:


protected:
    explicit StringFilter(const Glib::RefPtr<Expression<Glib::ustring>>& expression);


public:
  /** @addtogroup gtkmmEnums gtkmm Enums and Flags */

  /**
   *  @var MatchMode EXACT
   * The search string and
   * text must match exactly.
   *
   *  @var MatchMode SUBSTRING
   * The search string
   * must be contained as a substring inside the text.
   *
   *  @var MatchMode PREFIX
   * The text must begin
   * with the search string.
   *
   *  @enum MatchMode
   *
   * Specifies how search strings are matched inside text.
   *
   * @ingroup gtkmmEnums
   */
  enum class MatchMode
  {
    EXACT,
    SUBSTRING,
    PREFIX
  };


  static auto create(const Glib::RefPtr<Expression<Glib::ustring>>& expression) -> Glib::RefPtr<StringFilter>;


  /** Gets the search term.
   *
   * @return The search term.
   */
  auto get_search() const -> Glib::ustring;

  /** Sets the string to search for.
   *
   * @param search The string to search for
   * or <tt>nullptr</tt> to clear the search.
   */
  void set_search(const Glib::ustring& search);

  /** Gets the expression that the string filter uses to
   * obtain strings from items.
   *
   * @return A `Gtk::Expression`.
   */
  auto get_expression() -> Glib::RefPtr<Expression<Glib::ustring>>;

  /** Gets the expression that the string filter uses to
   * obtain strings from items.
   *
   * @return A `Gtk::Expression`.
   */
  auto get_expression() const -> Glib::RefPtr<const Expression<Glib::ustring>>;

  /** Sets the expression that the string filter uses to
   * obtain strings from items.
   *
   * The expression must have a value type of G_TYPE_STRING.
   *
   * @param expression A `Gtk::Expression`.
   */
  void set_expression(const Glib::RefPtr<Expression<Glib::ustring>>& expression);

  /** Returns whether the filter ignores case differences.
   *
   * @return <tt>true</tt> if the filter ignores case.
   */
  auto get_ignore_case() const -> bool;

  /** Sets whether the filter ignores case differences.
   *
   * @param ignore_case <tt>true</tt> to ignore case.
   */
  void set_ignore_case(bool ignore_case =  true);

  /** Returns the match mode that the filter is using.
   *
   * @return The match mode of the filter.
   */
  auto get_match_mode() const -> MatchMode;

  /** Sets the match mode for the filter.
   *
   * @param mode The new match mode.
   */
  void set_match_mode(MatchMode mode);

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

  /** If exact matches are necessary or if substrings are allowed.
   *
   * Default value: Gtk::StringFilter::MatchMode::SUBSTRING
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_match_mode() -> Glib::PropertyProxy< MatchMode > ;

/** If exact matches are necessary or if substrings are allowed.
   *
   * Default value: Gtk::StringFilter::MatchMode::SUBSTRING
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_match_mode() const -> Glib::PropertyProxy_ReadOnly< MatchMode >;

  /** The search term.
   *
   * Default value: ""
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_search() -> Glib::PropertyProxy< Glib::ustring > ;

/** The search term.
   *
   * Default value: ""
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_search() const -> Glib::PropertyProxy_ReadOnly< Glib::ustring >;


public:

public:
  //C++ methods used to invoke GTK+ virtual functions:

protected:
  //GTK+ Virtual Functions (override these to change behaviour):

  //Default Signal Handlers::


};

} // namespace Gtk


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

template <>
class GTKMM_API Value<Gtk::StringFilter::MatchMode> : public Glib::Value_Enum<Gtk::StringFilter::MatchMode>
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
   * @relates Gtk::StringFilter
   */
  GTKMM_API
  auto wrap(GtkStringFilter* object, bool take_copy = false) -> Glib::RefPtr<Gtk::StringFilter>;
}


#endif /* _GTKMM_STRINGFILTER_H */

