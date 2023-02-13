
#ifndef _GTKMM_SCROLLABLE_H
#define _GTKMM_SCROLLABLE_H


#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

/* Copyright (C) 2010 The gtkmm Development Team
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
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 */

#include <libmm-gtk/adjustment.hxx>
#include <libmm-gtk/border.hxx>
#include <libmm-glib/interface.hxx>
#include <libmm-gtk/enums.hxx>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
extern "C"
{
typedef struct _GtkScrollableInterface GtkScrollableInterface;
}
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkScrollable = struct _GtkScrollable;
using GtkScrollableClass = struct _GtkScrollableClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{ class GTKMM_API Scrollable_Class; } // namespace Gtk
#endif // DOXYGEN_SHOULD_SKIP_THIS

namespace Gtk
{

/** This interface is implemented by widgets with native
 * scrolling ability.
 *
 * @newin{3,0}
 */

class GTKMM_API Scrollable : public Glib::Interface
{

#ifndef DOXYGEN_SHOULD_SKIP_THIS

public:
  using CppObjectType = Scrollable;
  using CppClassType = Scrollable_Class;
  using BaseObjectType = GtkScrollable;
  using BaseClassType = GtkScrollableInterface;

  // noncopyable
  Scrollable(const Scrollable&) = delete;
  auto operator=(const Scrollable&) -> Scrollable& = delete;

private:
  friend class Scrollable_Class;
  static CppClassType scrollable_class_;

#endif /* DOXYGEN_SHOULD_SKIP_THIS */
protected:
  /**
   * You should derive from this class to use it.
   */
  Scrollable();

#ifndef DOXYGEN_SHOULD_SKIP_THIS
  /** Called by constructors of derived classes. Provide the result of
   * the Class init() function to ensure that it is properly
   * initialized.
   *
   * @param interface_class The Class object for the derived type.
   */
  explicit Scrollable(const Glib::Interface_Class& interface_class);

public:
  // This is public so that C++ wrapper instances can be
  // created for C instances of unwrapped types.
  // For instance, if an unexpected C type implements the C interface.
  explicit Scrollable(GtkScrollable* castitem);

protected:
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  Scrollable(Scrollable&& src) noexcept;
  auto operator=(Scrollable&& src) noexcept -> Scrollable&;

  ~Scrollable() noexcept override;

  static void add_interface(GType gtype_implementer);

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS
  static auto get_base_type() -> GType G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GObject.
  auto       gobj() -> GtkScrollable*       { return reinterpret_cast<GtkScrollable*>(gobject_); }

  ///Provides access to the underlying C GObject.
  auto gobj() const -> const GtkScrollable* { return reinterpret_cast<GtkScrollable*>(gobject_); }

private:


public:
  /** @addtogroup gtkmmEnums gtkmm Enums and Flags */

  /**
   *  @var Policy MINIMUM
   * Scrollable adjustments are based on the minimum size.
   *
   *  @var Policy NATURAL
   * Scrollable adjustments are based on the natural size.
   *
   *  @enum Policy
   *
   * Defines the policy to be used in a scrollable widget when updating
   * the scrolled window adjustments in a given orientation.
   *
   * @ingroup gtkmmEnums
   */
  enum class Policy
  {
    MINIMUM,
    NATURAL
  };


  /** Retrieves the `Gtk::Adjustment` used for horizontal scrolling.
   *
   * @return Horizontal `Gtk::Adjustment`.
   */
  auto get_hadjustment() -> Glib::RefPtr<Adjustment>;

  /** Retrieves the `Gtk::Adjustment` used for horizontal scrolling.
   *
   * @return Horizontal `Gtk::Adjustment`.
   */
  auto get_hadjustment() const -> Glib::RefPtr<const Adjustment>;


  /** Sets the horizontal adjustment of the `Gtk::Scrollable`.
   *
   * @param hadjustment A `Gtk::Adjustment`.
   */
  void set_hadjustment(const Glib::RefPtr<Adjustment>& hadjustment);

  /** This method removes the hadjustment.
   * @see set_hadjustment().
   */
  void unset_hadjustment();


  /** Retrieves the `Gtk::Adjustment` used for vertical scrolling.
   *
   * @return Vertical `Gtk::Adjustment`.
   */
  auto get_vadjustment() -> Glib::RefPtr<Adjustment>;

  /** Retrieves the `Gtk::Adjustment` used for vertical scrolling.
   *
   * @return Vertical `Gtk::Adjustment`.
   */
  auto get_vadjustment() const -> Glib::RefPtr<const Adjustment>;


  /** Sets the vertical adjustment of the `Gtk::Scrollable`.
   *
   * @param vadjustment A `Gtk::Adjustment`.
   */
  void set_vadjustment(const Glib::RefPtr<Adjustment>& vadjustment);

  /** This method removes the vadjustment.
   * @see set_vadjustment().
   */
  void unset_vadjustment();


  /** Gets the horizontal `Gtk::Scrollable::Policy`.
   *
   * @return The horizontal `Gtk::Scrollable::Policy`.
   */
  auto get_hscroll_policy() const -> Policy;

  /** Sets the `Gtk::Scrollable::Policy`.
   *
   * The policy determines whether horizontal scrolling should start
   * below the minimum width or below the natural width.
   *
   * @param policy The horizontal `Gtk::Scrollable::Policy`.
   */
  void set_hscroll_policy(Policy policy);

  /** Gets the vertical `Gtk::Scrollable::Policy`.
   *
   * @return The vertical `Gtk::Scrollable::Policy`.
   */
  auto get_vscroll_policy() const -> Policy;

  /** Sets the `Gtk::Scrollable::Policy`.
   *
   * The policy determines whether vertical scrolling should start
   * below the minimum height or below the natural height.
   *
   * @param policy The vertical `Gtk::Scrollable::Policy`.
   */
  void set_vscroll_policy(Policy policy);

  /** Returns the size of a non-scrolling border around the
   * outside of the scrollable.
   *
   * An example for this would be treeview headers. GTK can use
   * this information to display overlaid graphics, like the
   * overshoot indication, at the right position.
   *
   * @param border Return location for the results.
   * @return <tt>true</tt> if @a border has been set.
   */
  auto get_border(Border& border) const -> bool;

  /** Horizontal `Gtk::Adjustment` of the scrollable widget.
   *
   * This adjustment is shared between the scrollable widget and its parent.
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_hadjustment() -> Glib::PropertyProxy< Glib::RefPtr<Adjustment> > ;

/** Horizontal `Gtk::Adjustment` of the scrollable widget.
   *
   * This adjustment is shared between the scrollable widget and its parent.
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_hadjustment() const -> Glib::PropertyProxy_ReadOnly< Glib::RefPtr<Adjustment> >;

  /** Vertical `Gtk::Adjustment` of the scrollable widget.
   *
   * This adjustment is shared between the scrollable widget and its parent.
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_vadjustment() -> Glib::PropertyProxy< Glib::RefPtr<Adjustment> > ;

/** Vertical `Gtk::Adjustment` of the scrollable widget.
   *
   * This adjustment is shared between the scrollable widget and its parent.
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_vadjustment() const -> Glib::PropertyProxy_ReadOnly< Glib::RefPtr<Adjustment> >;

  /** Determines when horizontal scrolling should start.
   *
   * Default value: Gtk::Scrollabel::Policy::MINIMUM
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_hscroll_policy() -> Glib::PropertyProxy< Policy > ;

/** Determines when horizontal scrolling should start.
   *
   * Default value: Gtk::Scrollabel::Policy::MINIMUM
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_hscroll_policy() const -> Glib::PropertyProxy_ReadOnly< Policy >;

  /** Determines when vertical scrolling should start.
   *
   * Default value: Gtk::Scrollabel::Policy::MINIMUM
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_vscroll_policy() -> Glib::PropertyProxy< Policy > ;

/** Determines when vertical scrolling should start.
   *
   * Default value: Gtk::Scrollabel::Policy::MINIMUM
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_vscroll_policy() const -> Glib::PropertyProxy_ReadOnly< Policy >;


protected:
    virtual auto get_border_vfunc(Border& border) const -> bool;


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
class GTKMM_API Value<Gtk::Scrollable::Policy> : public Glib::Value_Enum<Gtk::Scrollable::Policy>
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
   * @relates Gtk::Scrollable
   */
  GTKMM_API
  auto wrap(GtkScrollable* object, bool take_copy = false) -> Glib::RefPtr<Gtk::Scrollable>;

} // namespace Glib


#endif /* _GTKMM_SCROLLABLE_H */

