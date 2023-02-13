
#ifndef _GTKMM_ACTIONBAR_H
#define _GTKMM_ACTIONBAR_H


#include <mm/glib/ustring.hpp>
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

#include <mm/gtk/widget.hpp>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkActionBar = struct _GtkActionBar;
using GtkActionBarClass = struct _GtkActionBarClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{ class GTKMM_API ActionBar_Class; } // namespace Gtk
#endif //DOXYGEN_SHOULD_SKIP_THIS

namespace Gtk
{

/** A full width bar for presenting contextual actions.
 *
 * ActionBar is designed to present contextual actions. It is
 * expected to be displayed below the content and expand horizontally
 * to fill the area.
 *
 * It allows placing children at the start or the end. In addition, it
 * contains an internal centered box which is centered with respect to
 * the full width of the box, even if the children at either side take
 * up different amounts of space.
 *
 * @see Box
 * @ingroup Widgets
 * @newin{3,12}
 */

class GTKMM_API ActionBar
  : public Widget
{
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  typedef ActionBar CppObjectType;
  typedef ActionBar_Class CppClassType;
  typedef GtkActionBar BaseObjectType;
  typedef GtkActionBarClass BaseClassType;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

  ActionBar(ActionBar&& src) noexcept;
  auto operator=(ActionBar&& src) noexcept -> ActionBar&;

  // noncopyable
  ActionBar(const ActionBar&) = delete;
  auto operator=(const ActionBar&) -> ActionBar& = delete;

  ~ActionBar() noexcept override;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

private:
  friend GTKMM_API class ActionBar_Class;
  static CppClassType actionbar_class_;

protected:
  explicit ActionBar(const Glib::ConstructParams& construct_params);
  explicit ActionBar(GtkActionBar* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS


  static auto get_base_type() -> GType G_GNUC_CONST;
#endif

  /// Provides access to the underlying C GObject.
  auto       gobj() -> GtkActionBar*       { return reinterpret_cast<GtkActionBar*>(gobject_); }

  /// Provides access to the underlying C GObject.
  auto gobj() const -> const GtkActionBar* { return reinterpret_cast<GtkActionBar*>(gobject_); }

private:

public:

  /** Creates a new ActionBar widget.
   */
  ActionBar();


  /** Adds @a child to @a action_bar, packed with reference to the
   * start of the @a action_bar.
   *
   * @param child The `Gtk::Widget` to be added to @a action_bar.
   */
  void pack_start(Gtk::Widget& child);

  /** Adds @a child to @a action_bar, packed with reference to the
   * end of the @a action_bar.
   *
   * @param child The `Gtk::Widget` to be added to @a action_bar.
   */
  void pack_end(Gtk::Widget& child);

  /** Removes a child from @a action_bar.
   *
   * @param child The `Gtk::Widget` to be removed.
   */
  void remove(Gtk::Widget& child);

  // transfer none

  /** Retrieves the center bar widget of the bar.
   *
   * @return The center `Gtk::Widget`.
   */
  auto get_center_widget() -> Widget*;

  /** Retrieves the center bar widget of the bar.
   *
   * @return The center `Gtk::Widget`.
   */
  auto get_center_widget() const -> const Widget*;

  /** Sets the center widget for the `Gtk::ActionBar`.
   *
   * @param center_widget A widget to use for the center.
   */
  void set_center_widget(Widget& center_widget);

  /** Unset the center widget.
   *
   * See set_center_widget().
   */
  void unset_center_widget();


  /** Reveals or conceals the content of the action bar.
   *
   * @note this does not show or hide @a action_bar in the
   * Gtk::Widget::property_visible() sense, so revealing has
   * no effect if the action bar is hidden.
   *
   * @newin{3,92}
   *
   * @param revealed The new value of the property.
   */
  void set_revealed(bool revealed =  true);

  /** Gets whether the contents of the action bar are revealed.
   *
   * @newin{3,92}
   *
   * @return The current value of the property_revealed()
   * property.
   */
  auto get_revealed() const -> bool;

  /** Controls whether the action bar shows its contents.
   *
   * @newin{3,92}
   *
   * Default value: <tt>true</tt>
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_revealed() -> Glib::PropertyProxy< bool > ;

/** Controls whether the action bar shows its contents.
   *
   * @newin{3,92}
   *
   * Default value: <tt>true</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_revealed() const -> Glib::PropertyProxy_ReadOnly< bool >;


  // Gtk::ActionBar has no signals nor vfuncs as of 3.90.


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
   * @relates Gtk::ActionBar
   */
  GTKMM_API
  auto wrap(GtkActionBar* object, bool take_copy = false) -> Gtk::ActionBar*;
} //namespace Glib


#endif /* _GTKMM_ACTIONBAR_H */

