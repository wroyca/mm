
#ifndef _GTKMM_CONSTRAINT_H
#define _GTKMM_CONSTRAINT_H


#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

/* Copyright (C) 2019 The gtkmm Development Team
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

#include <libmm-glib/object.hxx>
#include <libmm-gtk/constrainttarget.hxx>
#include <gtk/gtk.h>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{ class GTKMM_API Constraint_Class; } // namespace Gtk
#endif //DOXYGEN_SHOULD_SKIP_THIS

namespace Gtk
{

/** The description of a constraint.
 *
 * %Gtk::Constraint describes a constraint between an attribute on a widget
 * and another attribute on another widget, expressed as a linear equation like:
 *
 *   target.attr1 = source.attr2 × multiplier + constant
 *
 * Each %Constraint is part of a system that will be solved by a
 * Gtk::ConstraintLayout in order to allocate and position each child widget.
 *
 * A %Constraint is immutable once it's created.
 *
 * @newin{3,96}
 */

class GTKMM_API Constraint : public Glib::Object
{

#ifndef DOXYGEN_SHOULD_SKIP_THIS

public:
  using CppObjectType = Constraint;
  using CppClassType = Constraint_Class;
  using BaseObjectType = GtkConstraint;
  using BaseClassType = GtkConstraintClass;

  // noncopyable
  Constraint(const Constraint&) = delete;
  auto operator=(const Constraint&) -> Constraint& = delete;

private:  friend class Constraint_Class;
  static CppClassType constraint_class_;

protected:
  explicit Constraint(const Glib::ConstructParams& construct_params);
  explicit Constraint(GtkConstraint* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  Constraint(Constraint&& src) noexcept;
  auto operator=(Constraint&& src) noexcept -> Constraint&;

  ~Constraint() noexcept override;

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS


  static auto get_base_type() -> GType G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GObject.
  auto       gobj() -> GtkConstraint*       { return reinterpret_cast<GtkConstraint*>(gobject_); }

  ///Provides access to the underlying C GObject.
  auto gobj() const -> const GtkConstraint* { return reinterpret_cast<GtkConstraint*>(gobject_); }

  ///Provides access to the underlying C instance. The caller is responsible for unrefing it. Use when directly setting fields in structs.
  auto gobj_copy() -> GtkConstraint*;

private:


public:
  /** @addtogroup gtkmmEnums gtkmm Enums and Flags */

  /**
   *  @var Attribute NONE
   * No attribute, used for constant
   * relations.
   *
   *  @var Attribute LEFT
   * The left edge of a widget, regardless of
   * text direction.
   *
   *  @var Attribute RIGHT
   * The right edge of a widget, regardless
   * of text direction.
   *
   *  @var Attribute TOP
   * The top edge of a widget.
   *
   *  @var Attribute BOTTOM
   * The bottom edge of a widget.
   *
   *  @var Attribute START
   * The leading edge of a widget, depending
   * on text direction; equivalent to Gtk::Constraint::Attribute::LEFT for LTR
   * languages, and Gtk::Constraint::Attribute::RIGHT for RTL ones.
   *
   *  @var Attribute END
   * The trailing edge of a widget, depending
   * on text direction; equivalent to Gtk::Constraint::Attribute::RIGHT for LTR
   * languages, and Gtk::Constraint::Attribute::LEFT for RTL ones.
   *
   *  @var Attribute WIDTH
   * The width of a widget.
   *
   *  @var Attribute HEIGHT
   * The height of a widget.
   *
   *  @var Attribute CENTER_X
   * The center of a widget, on the
   * horizontal axis.
   *
   *  @var Attribute CENTER_Y
   * The center of a widget, on the
   * vertical axis.
   *
   *  @var Attribute BASELINE
   * The baseline of a widget.
   *
   *  @enum Attribute
   *
   * The widget attributes that can be used when creating a Gtk::Constraint.
   *
   * @ingroup gtkmmEnums
   */
  enum class Attribute
  {
    NONE,
    LEFT,
    RIGHT,
    TOP,
    BOTTOM,
    START,
    END,
    WIDTH,
    HEIGHT,
    CENTER_X,
    CENTER_Y,
    BASELINE
  };


  /**
   *  @var Relation EQ
   * Equal.
   *
   *  @var Relation LE
   * Less than, or equal.
   *
   *  @var Relation GE
   * Greater than, or equal.
   *
   *  @enum Relation
   *
   * The relation between two terms of a constraint.
   *
   * @ingroup gtkmmEnums
   */
  enum class Relation
  {
    LE = -1,
    EQ,
    GE
  };


  /** Wrapper for enum Strength.
   * Strength enumerators are scoped and can be implicitly converted to int.
   * The scope is Gtk::Constraint::Strength::
   *
   * @ingroup gtkmmEnums
   */
  class Strength_Wrapper final
  {
  public:
    /**
     *  @var Strength REQUIRED
     * The constraint is required towards solving the layout.
     *
     *  @var Strength STRONG
     * A strong constraint.
     *
     *  @var Strength MEDIUM
     * A medium constraint.
     *
     *  @var Strength WEAK
     * A weak constraint.
     *
     *  @enum Strength
     *
     * The strength of a constraint, expressed as a symbolic constant.
     *
     * The strength of a Gtk::Constraint can be expressed with any positive
     * integer; the values of this enumeration can be used for readability.
     *
     * @ingroup gtkmmEnums
     */
    enum Strength
    {
      REQUIRED = 1001001000,
      STRONG = 1000000000,
      MEDIUM = 1000,
      WEAK = 1
    };
    #ifndef DOXYGEN_SHOULD_SKIP_THIS
    Strength_Wrapper() = delete;
    #endif
  };
  /** Strength enumerators are scoped by the wrapper class
   * and can be implicitly converted to int.
   *
   * @ingroup gtkmmEnums
   */
  using Strength = Strength_Wrapper::Strength;


protected:
    explicit Constraint(const Glib::RefPtr<ConstraintTarget>& target, Attribute target_attribute, Relation relation, const Glib::RefPtr<ConstraintTarget>& source, Attribute source_attribute, double multiplier, double constant, int strength);

    explicit Constraint(const Glib::RefPtr<ConstraintTarget>& target, Attribute target_attribute, Relation relation, double constant, int strength);


public:
  /** Creates a new %Gtk::Constraint representing a relation between a layout
   * attribute on a source and a layout attribute on a target.
   *
   * @param target A Gtk::ConstraintTarget or an empty Glib::RefPtr.
   * @param target_attribute The attribute of @a target to be set.
   * @param relation The relation equivalence between @a target_attribute and @a source_attribute.
   * @param source A Gtk::ConstraintTarget or an empty Glib::RefPtr.
   * @param source_attribute The attribute of @a source to be read.
   * @param multiplier A multiplication factor to be applied to @a source_attribute.
   * @param constant A constant to be added to @a source_attribute.
   * @param strength The strength of the constraint.
   * @return The newly created %Gtk::Constraint.
   */

  static auto create(const Glib::RefPtr<ConstraintTarget>& target, Attribute target_attribute, Relation relation, const Glib::RefPtr<ConstraintTarget>& source, Attribute source_attribute, double multiplier, double constant, int strength) -> Glib::RefPtr<Constraint>;


  /** Creates a new %Gtk::Constraint representing a relation between a layout
   * attribute on a target and a constant value.
   *
   * @param target A Gtk::ConstraintTarget or an empty Glib::RefPtr.
   * @param target_attribute The attribute of @a target to be set.
   * @param relation The relation equivalence between @a target_attribute and @a constant.
   * @param constant A constant to be set on @a target_attribute.
   * @param strength The strength of the constraint.
   * @return The newly created %Gtk::Constraint.
   */

  static auto create(const Glib::RefPtr<ConstraintTarget>& target, Attribute target_attribute, Relation relation, double constant, int strength) -> Glib::RefPtr<Constraint>;


  /** Retrieves the Gtk::ConstraintTarget used as the target for
   * the constraint.
   *
   * If the targe is set to <tt>nullptr</tt> at creation, the constraint will use
   * the widget using the Gtk::ConstraintLayout as the target.
   *
   * @return A `Gtk::ConstraintTarget`.
   */
  auto get_target() -> Glib::RefPtr<ConstraintTarget>;

  /** Retrieves the Gtk::ConstraintTarget used as the target for
   * the constraint.
   *
   * If the targe is set to <tt>nullptr</tt> at creation, the constraint will use
   * the widget using the Gtk::ConstraintLayout as the target.
   *
   * @return A `Gtk::ConstraintTarget`.
   */
  auto get_target() const -> Glib::RefPtr<const ConstraintTarget>;

  /** Retrieves the attribute of the target to be set by the constraint.
   *
   * @return The target's attribute.
   */
  auto get_target_attribute() const -> Attribute;

  /** Retrieves the Gtk::ConstraintTarget used as the source for the
   * constraint.
   *
   * If the source is set to <tt>nullptr</tt> at creation, the constraint will use
   * the widget using the Gtk::ConstraintLayout as the source.
   *
   * @return The source of the constraint.
   */
  auto get_source() -> Glib::RefPtr<ConstraintTarget>;

  /** Retrieves the Gtk::ConstraintTarget used as the source for the
   * constraint.
   *
   * If the source is set to <tt>nullptr</tt> at creation, the constraint will use
   * the widget using the Gtk::ConstraintLayout as the source.
   *
   * @return The source of the constraint.
   */
  auto get_source() const -> Glib::RefPtr<const ConstraintTarget>;

  /** Retrieves the attribute of the source to be read by the constraint.
   *
   * @return The source's attribute.
   */
  auto get_source_attribute() const -> Attribute;

  /** The order relation between the terms of the constraint.
   *
   * @return A relation type.
   */
  auto get_relation() const -> Relation;

  /** Retrieves the multiplication factor applied to the source
   * attribute's value.
   *
   * @return A multiplication factor.
   */
  auto get_multiplier() const -> double;

  /** Retrieves the constant factor added to the source attributes' value.
   *
   * @return A constant factor.
   */
  auto get_constant() const -> double;

  /** Retrieves the strength of the constraint.
   *
   * @return The strength value.
   */
  auto get_strength() const -> int;

  /** Checks whether the constraint is a required relation for solving the
   * constraint layout.
   *
   * @return <tt>true</tt> if the constraint is required.
   */
  auto is_required() const -> bool;

  /** Checks whether the constraint is attached to a Gtk::ConstraintLayout,
   * and it is contributing to the layout.
   *
   * @return <tt>true</tt> if the constraint is attached.
   */
  auto is_attached() const -> bool;

  /** Checks whether the constraint describes a relation between an attribute
   * on the property_target() and a constant value.
   *
   * @return <tt>true</tt> if the constraint is a constant relation.
   */
  auto is_constant() const -> bool;

  /** The target of the constraint.
   *
   * The constraint will set the property_target_attribute()
   * property of the target using the property_source_attribute()
   * property of the source widget.
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_target() const -> Glib::PropertyProxy_ReadOnly< Glib::RefPtr<ConstraintTarget> >;


  /** The attribute of the property_target() set by the constraint.
   *
   * Default value: Gtk::Constraint::Attribute::NONE
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_target_attribute() const -> Glib::PropertyProxy_ReadOnly< Attribute >;


  /** The order relation between the terms of the constraint.
   *
   * Default value: Gtk::Constraint::Relation::EQ
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_relation() const -> Glib::PropertyProxy_ReadOnly< Relation >;


  /** The source of the constraint.
   *
   * The constraint will set the property_target_attribute()
   * property of the target using the property_source_attribute()
   * property of the source.
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_source() const -> Glib::PropertyProxy_ReadOnly< Glib::RefPtr<ConstraintTarget> >;


  /** The attribute of the property_source() read by the
   * constraint.
   *
   * Default value: Gtk::Constraint::Attribute::NONE
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_source_attribute() const -> Glib::PropertyProxy_ReadOnly< Attribute >;


  /** The multiplication factor to be applied to
   * the property_source_attribute().
   *
   * Default value: 1
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_multiplier() const -> Glib::PropertyProxy_ReadOnly< double >;


  /** The constant value to be added to the property_source_attribute().
   *
   * Default value: 0
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_constant() const -> Glib::PropertyProxy_ReadOnly< double >;


  /** The strength of the constraint.
   *
   * The strength can be expressed either using one of the symbolic values
   * of the Gtk::ConstraintStrength enumeration, or any positive integer
   * value.
   *
   * Default value: 1001001000
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_strength() const -> Glib::PropertyProxy_ReadOnly< int >;


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
class GTKMM_API Value<Gtk::Constraint::Attribute> : public Glib::Value_Enum<Gtk::Constraint::Attribute>
{
public:
  static auto value_type() -> GType G_GNUC_CONST;
};

} // namespace Glib
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

template <>
class GTKMM_API Value<Gtk::Constraint::Relation> : public Glib::Value_Enum<Gtk::Constraint::Relation>
{
public:
  static auto value_type() -> GType G_GNUC_CONST;
};

} // namespace Glib
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

template <>
class GTKMM_API Value<Gtk::Constraint::Strength> : public Glib::Value_Enum<Gtk::Constraint::Strength>
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
   * @relates Gtk::Constraint
   */
  GTKMM_API
  auto wrap(GtkConstraint* object, bool take_copy = false) -> Glib::RefPtr<Gtk::Constraint>;
}


#endif /* _GTKMM_CONSTRAINT_H */

