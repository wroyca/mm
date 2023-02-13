
#ifndef _GTKMM_REVEALER_H
#define _GTKMM_REVEALER_H


#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

/*
 * Copyright (C) 2013 The gtkmm Development Team
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

#include <libmm-gtk/widget.hxx>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkRevealer = struct _GtkRevealer;
using GtkRevealerClass = struct _GtkRevealerClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{ class GTKMM_API Revealer_Class; } // namespace Gtk
#endif //DOXYGEN_SHOULD_SKIP_THIS

namespace Gtk
{

/** Hide and show with animation.
 *
 * The Gtk::Revealer widget is a container which animates
 * the transition of its child from invisible to visible.
 *
 * The style of transition can be controlled with
 * Gtk::Revealer::set_transition_type().
 *
 * @ingroup Widgets
 * @newin{3,10}
 */

class GTKMM_API Revealer
  : public Widget
{
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  typedef Revealer CppObjectType;
  typedef Revealer_Class CppClassType;
  typedef GtkRevealer BaseObjectType;
  typedef GtkRevealerClass BaseClassType;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

  Revealer(Revealer&& src) noexcept;
  auto operator=(Revealer&& src) noexcept -> Revealer&;

  // noncopyable
  Revealer(const Revealer&) = delete;
  auto operator=(const Revealer&) -> Revealer& = delete;

  ~Revealer() noexcept override;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

private:
  friend GTKMM_API class Revealer_Class;
  static CppClassType revealer_class_;

protected:
  explicit Revealer(const Glib::ConstructParams& construct_params);
  explicit Revealer(GtkRevealer* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS


  static auto get_base_type() -> GType G_GNUC_CONST;
#endif

  /// Provides access to the underlying C GObject.
  auto       gobj() -> GtkRevealer*       { return reinterpret_cast<GtkRevealer*>(gobject_); }

  /// Provides access to the underlying C GObject.
  auto gobj() const -> const GtkRevealer* { return reinterpret_cast<GtkRevealer*>(gobject_); }

private:

public:

  /** Create Gtk::Revealer widget.
   */
  Revealer();


  /** Returns whether the child is currently revealed.
   *
   * This function returns <tt>true</tt> as soon as the transition
   * is to the revealed state is started. To learn whether
   * the child is fully revealed (ie the transition is completed),
   * use get_child_revealed().
   *
   * @return <tt>true</tt> if the child is revealed.
   */
  auto get_reveal_child() const -> bool;

  /** Tells the `Gtk::Revealer` to reveal or conceal its child.
   *
   * The transition will be animated with the current
   * transition type of @a revealer.
   *
   * @param reveal_child <tt>true</tt> to reveal the child.
   */
  void set_reveal_child(bool reveal_child =  true);


  /** Returns whether the child is fully revealed.
   *
   * In other words, this returns whether the transition
   * to the revealed state is completed.
   *
   * @return <tt>true</tt> if the child is fully revealed.
   */
  auto get_child_revealed() const -> bool;


  /** Returns the amount of time (in milliseconds) that
   * transitions will take.
   *
   * @return The transition duration.
   */
  auto get_transition_duration() const -> guint;

  /** Sets the duration that transitions will take.
   *
   * @param duration The new duration, in milliseconds.
   */
  void set_transition_duration(guint duration);


  /** Gets the type of animation that will be used
   * for transitions in @a revealer.
   *
   * @return The current transition type of @a revealer.
   */
  auto get_transition_type() const -> RevealerTransitionType;

  /** Sets the type of animation that will be used for
   * transitions in @a revealer.
   *
   * Available types include various kinds of fades and slides.
   *
   * @param transition The new transition type.
   */
  void set_transition_type(RevealerTransitionType transition);


  /** Sets the child widget of @a revealer.
   *
   * @param child The child widget.
   */
  void set_child(Widget& child);
  void unset_child();

  /** Gets the child widget of @a revealer.
   *
   * @return The child widget of @a revealer.
   */
  auto get_child() -> Widget*;

  /** Gets the child widget of @a revealer.
   *
   * @return The child widget of @a revealer.
   */
  auto get_child() const -> const Widget*;

  /** The type of animation used to transition.
   *
   * Default value: Gtk::RevealerTransitionType::SLIDE_DOWN
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_transition_type() -> Glib::PropertyProxy< RevealerTransitionType > ;

/** The type of animation used to transition.
   *
   * Default value: Gtk::RevealerTransitionType::SLIDE_DOWN
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_transition_type() const -> Glib::PropertyProxy_ReadOnly< RevealerTransitionType >;

  /** The animation duration, in milliseconds.
   *
   * Default value: 250
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_transition_duration() -> Glib::PropertyProxy< guint > ;

/** The animation duration, in milliseconds.
   *
   * Default value: 250
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_transition_duration() const -> Glib::PropertyProxy_ReadOnly< guint >;

  /** Whether the revealer should reveal the child.
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_reveal_child() -> Glib::PropertyProxy< bool > ;

/** Whether the revealer should reveal the child.
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_reveal_child() const -> Glib::PropertyProxy_ReadOnly< bool >;

  /** Whether the child is revealed and the animation target reached.
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_child_revealed() const -> Glib::PropertyProxy_ReadOnly< bool >;


  /** The child widget.
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_child() -> Glib::PropertyProxy< Widget* > ;

/** The child widget.
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_child() const -> Glib::PropertyProxy_ReadOnly< Widget* >;


  // Gtk::Revealer has no signals nor vfuncs as of 3.10.


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
   * @relates Gtk::Revealer
   */
  GTKMM_API
  auto wrap(GtkRevealer* object, bool take_copy = false) -> Gtk::Revealer*;
} //namespace Glib


#endif /* _GTKMM_REVEALER_H */

