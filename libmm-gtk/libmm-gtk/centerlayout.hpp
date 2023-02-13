
#ifndef _GTKMM_CENTERLAYOUT_H
#define _GTKMM_CENTERLAYOUT_H


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

#include <mm/gtk/layoutmanager.hpp>
#include <mm/gtk/enums.hpp>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{ class GTKMM_API CenterLayout_Class; } // namespace Gtk
#endif //DOXYGEN_SHOULD_SKIP_THIS

namespace Gtk
{
class GTKMM_API Widget;

/** A centering layout.
 *
 * A %Gtk::CenterLayout is a layout manager that manages up to three children.
 * The start widget is allocated at the start of the layout (left in LRT
 * layouts and right in RTL ones), and the end widget at the end.
 *
 * The center widget is centered regarding the full width of the layout.
 *
 * @newin{3,96}
 */

class GTKMM_API CenterLayout : public LayoutManager
{

#ifndef DOXYGEN_SHOULD_SKIP_THIS

public:
  using CppObjectType = CenterLayout;
  using CppClassType = CenterLayout_Class;
  using BaseObjectType = GtkCenterLayout;
  using BaseClassType = GtkCenterLayoutClass;

  // noncopyable
  CenterLayout(const CenterLayout&) = delete;
  auto operator=(const CenterLayout&) -> CenterLayout& = delete;

private:  friend class CenterLayout_Class;
  static CppClassType centerlayout_class_;

protected:
  explicit CenterLayout(const Glib::ConstructParams& construct_params);
  explicit CenterLayout(GtkCenterLayout* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  CenterLayout(CenterLayout&& src) noexcept;
  auto operator=(CenterLayout&& src) noexcept -> CenterLayout&;

  ~CenterLayout() noexcept override;

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS


  static auto get_base_type() -> GType G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GObject.
  auto       gobj() -> GtkCenterLayout*       { return reinterpret_cast<GtkCenterLayout*>(gobject_); }

  ///Provides access to the underlying C GObject.
  auto gobj() const -> const GtkCenterLayout* { return reinterpret_cast<GtkCenterLayout*>(gobject_); }

  ///Provides access to the underlying C instance. The caller is responsible for unrefing it. Use when directly setting fields in structs.
  auto gobj_copy() -> GtkCenterLayout*;

private:


protected:
  CenterLayout();

public:

  static auto create() -> Glib::RefPtr<CenterLayout>;


  /** Sets the orientation of @a self.
   *
   * @param orientation The new orientation.
   */
  void set_orientation(Orientation orientation);

  /** Gets the current orienration of the layout manager.
   *
   * @return The current orientation of @a self.
   */
  auto get_orientation() const -> Orientation;


  /** Sets the new baseline position of @a self
   *
   * @param baseline_position The new baseline position.
   */
  void set_baseline_position(BaselinePosition baseline_position);

  /** Returns the baseline position of the layout.
   *
   * @return The current baseline position of @a self.
   */
  auto get_baseline_position() const -> BaselinePosition;


  /** Sets the new start widget of @a self.
   *
   * To remove the existing start widget, pass <tt>nullptr</tt>.
   *
   * @param widget The new start widget.
   */
  void set_start_widget(Widget* widget);

  /** Returns the start widget fo the layout.
   *
   * @return The current start widget of @a self.
   */
  auto get_start_widget() -> Widget*;

  /** Returns the start widget fo the layout.
   *
   * @return The current start widget of @a self.
   */
  auto get_start_widget() const -> const Widget*;


  /** Sets the new center widget of @a self.
   *
   * To remove the existing center widget, pass <tt>nullptr</tt>.
   *
   * @param widget The new center widget.
   */
  void set_center_widget(Widget* widget);

  /** Returns the center widget of the layout.
   *
   * @return The current center widget of @a self.
   */
  auto get_center_widget() -> Widget*;

  /** Returns the center widget of the layout.
   *
   * @return The current center widget of @a self.
   */
  auto get_center_widget() const -> const Widget*;


  /** Sets the new end widget of @a self.
   *
   * To remove the existing center widget, pass <tt>nullptr</tt>.
   *
   * @param widget The new end widget.
   */
  void set_end_widget(Widget* widget);

  /** Returns the end widget of the layout.
   *
   * @return The current end widget of @a self.
   */
  auto get_end_widget() -> Widget*;

  /** Returns the end widget of the layout.
   *
   * @return The current end widget of @a self.
   */
  auto get_end_widget() const -> const Widget*;

  // There are no signals, properties or vfuncs.


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
   * @relates Gtk::CenterLayout
   */
  GTKMM_API
  auto wrap(GtkCenterLayout* object, bool take_copy = false) -> Glib::RefPtr<Gtk::CenterLayout>;
}


#endif /* _GTKMM_CENTERLAYOUT_H */

