
#ifndef _GTKMM_CONSTRAINTGUIDE_H
#define _GTKMM_CONSTRAINTGUIDE_H


#include <mm/glib/ustring.hpp>
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

#include <mm/glib/object.hpp>
#include <mm/gtk/constrainttarget.hpp>
#include <mm/gtk/constraint.hpp>
#include <gtk/gtk.h>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{ class GTKMM_API ConstraintGuide_Class; } // namespace Gtk
#endif //DOXYGEN_SHOULD_SKIP_THIS

namespace Gtk
{

 /** An invisible constraint target.
 *
 * A %ConstraintGuide is an invisible layout element that can be
 * used by widgets inside a Gtk::ConstraintLayout as a source or a target
 * of a Gtk::Constraint. Guides can be used like guidelines or as
 * flexible space.
 *
 * Unlike a Gtk::Widget, a %Gtk::ConstraintGuide will not be drawn.
 *
 * @newin{3,96}
 */

class GTKMM_API ConstraintGuide : public Glib::Object, public ConstraintTarget
{

#ifndef DOXYGEN_SHOULD_SKIP_THIS

public:
  using CppObjectType = ConstraintGuide;
  using CppClassType = ConstraintGuide_Class;
  using BaseObjectType = GtkConstraintGuide;
  using BaseClassType = GtkConstraintGuideClass;

  // noncopyable
  ConstraintGuide(const ConstraintGuide&) = delete;
  auto operator=(const ConstraintGuide&) -> ConstraintGuide& = delete;

private:  friend class ConstraintGuide_Class;
  static CppClassType constraintguide_class_;

protected:
  explicit ConstraintGuide(const Glib::ConstructParams& construct_params);
  explicit ConstraintGuide(GtkConstraintGuide* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  ConstraintGuide(ConstraintGuide&& src) noexcept;
  auto operator=(ConstraintGuide&& src) noexcept -> ConstraintGuide&;

  ~ConstraintGuide() noexcept override;

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS


  static auto get_base_type() -> GType G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GObject.
  auto       gobj() -> GtkConstraintGuide*       { return reinterpret_cast<GtkConstraintGuide*>(gobject_); }

  ///Provides access to the underlying C GObject.
  auto gobj() const -> const GtkConstraintGuide* { return reinterpret_cast<GtkConstraintGuide*>(gobject_); }

  ///Provides access to the underlying C instance. The caller is responsible for unrefing it. Use when directly setting fields in structs.
  auto gobj_copy() -> GtkConstraintGuide*;

private:


protected:
  ConstraintGuide();

public:

  static auto create() -> Glib::RefPtr<ConstraintGuide>;


  /** Sets the minimum size of @a guide.
   *
   * If @a guide is attached to a `Gtk::ConstraintLayout`,
   * the constraints will be updated to reflect the new size.
   *
   * @param width The new minimum width, or -1 to not change it.
   * @param height The new minimum height, or -1 to not change it.
   */
  void set_min_size(int width, int height);

  /** Gets the minimum size of @a guide.
   *
   * @param width Return location for the minimum width.
   * @param height Return location for the minimum height.
   */
  void get_min_size(int& width, int& height) const;

  /** Sets the natural size of @a guide.
   *
   * If @a guide is attached to a `Gtk::ConstraintLayout`,
   * the constraints will be updated to reflect the new size.
   *
   * @param width The new natural width, or -1 to not change it.
   * @param height The new natural height, or -1 to not change it.
   */
  void set_nat_size(int width, int height);

  /** Gets the natural size of @a guide.
   *
   * @param width Return location for the natural width.
   * @param height Return location for the natural height.
   */
  void get_nat_size(int& width, int& height) const;

  /** Sets the maximum size of @a guide.
   *
   * If @a guide is attached to a `Gtk::ConstraintLayout`,
   * the constraints will be updated to reflect the new size.
   *
   * @param width The new maximum width, or -1 to not change it.
   * @param height The new maximum height, or -1 to not change it.
   */
  void set_max_size(int width, int height);

  /** Gets the maximum size of @a guide.
   *
   * @param width Return location for the maximum width.
   * @param height Return location for the maximum height.
   */
  void get_max_size(int& width, int& height) const;

  /** Sets the strength of the constraint on the natural size of the
   * given `Gtk::ConstraintGuide`.
   *
   * @param strength The strength of the constraint.
   */
  void set_strength(Constraint::Strength strength);

  /** Retrieves the strength set using set_strength().
   *
   * @return The strength of the constraint on the natural size.
   */
  auto get_strength() const -> Constraint::Strength;

  /** Sets a name for the given `Gtk::ConstraintGuide`.
   *
   * The name is useful for debugging purposes.
   *
   * @param name A name for the @a guide.
   */
  void set_name(const Glib::ustring& name);

  /** Retrieves the name set using set_name().
   *
   * @return The name of the guide.
   */
  auto get_name() const -> Glib::ustring;

  /** The minimum width of the guide.
   *
   * Default value: 0
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_min_width() -> Glib::PropertyProxy< int > ;

/** The minimum width of the guide.
   *
   * Default value: 0
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_min_width() const -> Glib::PropertyProxy_ReadOnly< int >;

  /** The minimum height of the guide.
   *
   * Default value: 0
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_min_height() -> Glib::PropertyProxy< int > ;

/** The minimum height of the guide.
   *
   * Default value: 0
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_min_height() const -> Glib::PropertyProxy_ReadOnly< int >;

  /** The preferred, or natural, width of the guide.
   *
   * Default value: 0
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_nat_width() -> Glib::PropertyProxy< int > ;

/** The preferred, or natural, width of the guide.
   *
   * Default value: 0
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_nat_width() const -> Glib::PropertyProxy_ReadOnly< int >;

  /** The preferred, or natural, height of the guide.
   *
   * Default value: 0
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_nat_height() -> Glib::PropertyProxy< int > ;

/** The preferred, or natural, height of the guide.
   *
   * Default value: 0
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_nat_height() const -> Glib::PropertyProxy_ReadOnly< int >;

  /** The maximum width of the guide.
   *
   * Default value: 2147483647
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_max_width() -> Glib::PropertyProxy< int > ;

/** The maximum width of the guide.
   *
   * Default value: 2147483647
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_max_width() const -> Glib::PropertyProxy_ReadOnly< int >;

  /** The maximum height of the guide.
   *
   * Default value: 2147483647
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_max_height() -> Glib::PropertyProxy< int > ;

/** The maximum height of the guide.
   *
   * Default value: 2147483647
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_max_height() const -> Glib::PropertyProxy_ReadOnly< int >;

  /** The `Gtk::ConstraintStrength` to be used for the constraint on
   * the natural size of the guide.
   *
   * Default value: Gtk::Constraint::Strength::MEDIUM
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_strength() -> Glib::PropertyProxy< Constraint::Strength > ;

/** The `Gtk::ConstraintStrength` to be used for the constraint on
   * the natural size of the guide.
   *
   * Default value: Gtk::Constraint::Strength::MEDIUM
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_strength() const -> Glib::PropertyProxy_ReadOnly< Constraint::Strength >;

  /** A name that identifies the `Gtk::ConstraintGuide`, for debugging.
   *
   * Default value: ""
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_name() -> Glib::PropertyProxy< Glib::ustring > ;

/** A name that identifies the `Gtk::ConstraintGuide`, for debugging.
   *
   * Default value: ""
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_name() const -> Glib::PropertyProxy_ReadOnly< Glib::ustring >;


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
   * @relates Gtk::ConstraintGuide
   */
  GTKMM_API
  auto wrap(GtkConstraintGuide* object, bool take_copy = false) -> Glib::RefPtr<Gtk::ConstraintGuide>;
}


#endif /* _GTKMM_CONSTRAINTGUIDE_H */

