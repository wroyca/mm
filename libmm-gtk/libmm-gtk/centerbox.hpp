
#ifndef _GTKMM_CENTERBOX_H
#define _GTKMM_CENTERBOX_H


#include <mm/glib/ustring.hpp>
#include <sigc++/sigc++.h>

/* Copyright (C) 2017 The gtkmm Development Team
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

#include <mm/gtk/widget.hpp>
#include <mm/gtk/orientable.hpp>
#include <mm/gtk/enums.hpp>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkCenterBox = struct _GtkCenterBox;
using GtkCenterBoxClass = struct _GtkCenterBoxClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{ class GTKMM_API CenterBox_Class; } // namespace Gtk
#endif //DOXYGEN_SHOULD_SKIP_THIS

namespace Gtk
{

/** A centering container.
 *
 * The %CenterBox widget arranges three children in a horizontal
 * or vertical arrangement, keeping the middle child centered as well
 * as possible.
 *
 * To add children to a %CenterBox, use set_start_widget(),
 * set_center_widget() and set_end_widget().
 *
 * The sizing and positioning of children can be influenced with the
 * align and expand properties of the children.
 *
 * In horizontal orientation, the nodes of the children are always arranged
 * from left to right regardless of text direction. In vertical orientation,
 * the nodes of the children are arranged from top to bottom.
 *
 * @newin{3,92}
 *
 * @see Box
 * @ingroup Widgets
 * @ingroup Containers
 */

class GTKMM_API CenterBox : public Widget, public Orientable
{
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  typedef CenterBox CppObjectType;
  typedef CenterBox_Class CppClassType;
  typedef GtkCenterBox BaseObjectType;
  typedef GtkCenterBoxClass BaseClassType;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

  CenterBox(CenterBox&& src) noexcept;
  auto operator=(CenterBox&& src) noexcept -> CenterBox&;

  // noncopyable
  CenterBox(const CenterBox&) = delete;
  auto operator=(const CenterBox&) -> CenterBox& = delete;

  ~CenterBox() noexcept override;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

private:
  friend GTKMM_API class CenterBox_Class;
  static CppClassType centerbox_class_;

protected:
  explicit CenterBox(const Glib::ConstructParams& construct_params);
  explicit CenterBox(GtkCenterBox* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS


  static auto get_base_type() -> GType G_GNUC_CONST;
#endif

  /// Provides access to the underlying C GObject.
  auto       gobj() -> GtkCenterBox*       { return reinterpret_cast<GtkCenterBox*>(gobject_); }

  /// Provides access to the underlying C GObject.
  auto gobj() const -> const GtkCenterBox* { return reinterpret_cast<GtkCenterBox*>(gobject_); }

private:


public:
  CenterBox();


  /** Sets the start widget.
   *
   * To remove the existing start widget, pass <tt>nullptr</tt>.
   *
   * @param child The new start widget.
   */
  void set_start_widget(Widget& child);

  /** Gets the start widget, or <tt>nullptr</tt> if there is none.
   *
   * @return The start widget.
   */
  auto get_start_widget() -> Widget*;

  /** Gets the start widget, or <tt>nullptr</tt> if there is none.
   *
   * @return The start widget.
   */
  auto get_start_widget() const -> const Widget*;
  /** Removes the start widget.
   * @newin{3,92}
   */
  void unset_start_widget();


  /** Sets the center widget.
   *
   * To remove the existing center widget, pas <tt>nullptr</tt>.
   *
   * @param child The new center widget.
   */
  void set_center_widget(Widget& child);

  /** Gets the center widget, or <tt>nullptr</tt> if there is none.
   *
   * @return The center widget.
   */
  auto get_center_widget() -> Widget*;

  /** Gets the center widget, or <tt>nullptr</tt> if there is none.
   *
   * @return The center widget.
   */
  auto get_center_widget() const -> const Widget*;
  /** Removes the center widget.
   * @newin{3,92}
   */
  void unset_center_widget();


  /** Sets the end widget.
   *
   * To remove the existing end widget, pass <tt>nullptr</tt>.
   *
   * @param child The new end widget.
   */
  void set_end_widget(Widget& child);

  /** Gets the end widget, or <tt>nullptr</tt> if there is none.
   *
   * @return The end widget.
   */
  auto get_end_widget() -> Widget*;

  /** Gets the end widget, or <tt>nullptr</tt> if there is none.
   *
   * @return The end widget.
   */
  auto get_end_widget() const -> const Widget*;
  /** Removes the end widget.
   * @newin{3,92}
   */
  void unset_end_widget();


  /** Sets the baseline position of a center box.
   *
   * This affects only horizontal boxes with at least one baseline
   * aligned child. If there is more vertical space available than
   * requested, and the baseline is not allocated by the parent then
   *  @a position is used to allocate the baseline wrt. the extra space
   * available.
   *
   * @param position A `Gtk::BaselinePosition`.
   */
  void set_baseline_position(BaselinePosition position);

  /** Gets the value set by set_baseline_position().
   *
   * @return The baseline position.
   */
  auto get_baseline_position() -> BaselinePosition;

  /** The position of the baseline aligned widget if extra space is available.
   *
   * Default value: Gtk::BaselinePosition::CENTER
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_baseline_position() -> Glib::PropertyProxy< BaselinePosition > ;

/** The position of the baseline aligned widget if extra space is available.
   *
   * Default value: Gtk::BaselinePosition::CENTER
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_baseline_position() const -> Glib::PropertyProxy_ReadOnly< BaselinePosition >;


  // There are no signals or vfuncs.


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
   * @relates Gtk::CenterBox
   */
  GTKMM_API
  auto wrap(GtkCenterBox* object, bool take_copy = false) -> Gtk::CenterBox*;
} //namespace Glib


#endif /* _GTKMM_CENTERBOX_H */

