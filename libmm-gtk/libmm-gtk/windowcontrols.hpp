
#ifndef _GTKMM_WINDOWCONTROLS_H
#define _GTKMM_WINDOWCONTROLS_H


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

#include <libmm-gtk/widget.hpp>
#include <libmm-gtk/enums.hpp>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{ class GTKMM_API WindowControls_Class; } // namespace Gtk
#endif //DOXYGEN_SHOULD_SKIP_THIS

namespace Gtk
{

/** A widget displaying window buttons.
 *
 * %Gtk::WindowControls shows window frame controls, such as minimize, maximize
 * and close buttons, and the window icon.
 *
 * %Gtk::WindowControls only displays start or end side of the controls (see
 * property_side()), so it's intended to be always used in pair with
 * another %Gtk::WindowControls using the opposite side, for example:
 *
 * @code
 * <object class="GtkBox">
 *   <child>
 *     <object class="GtkWindowControls">
 *       <property name="side">start</property>
 *     </object>
 *   </child>
 *
 *   ...
 *
 *   <child>
 *     <object class="GtkWindowControls">
 *       <property name="side">end</property>
 *     </object>
 *   </child>
 * </object>
 * @endcode
 *
 * @see Gtk::HeaderBar
 *
 * @ingroup Widgets
 * @newin{3,98}
 */

class GTKMM_API WindowControls : public Widget
{
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  typedef WindowControls CppObjectType;
  typedef WindowControls_Class CppClassType;
  typedef GtkWindowControls BaseObjectType;
  typedef GtkWindowControlsClass BaseClassType;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

  WindowControls(WindowControls&& src) noexcept;
  auto operator=(WindowControls&& src) noexcept -> WindowControls&;

  // noncopyable
  WindowControls(const WindowControls&) = delete;
  auto operator=(const WindowControls&) -> WindowControls& = delete;

  ~WindowControls() noexcept override;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

private:
  friend GTKMM_API class WindowControls_Class;
  static CppClassType windowcontrols_class_;

protected:
  explicit WindowControls(const Glib::ConstructParams& construct_params);
  explicit WindowControls(GtkWindowControls* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS


  static auto get_base_type() -> GType G_GNUC_CONST;
#endif

  /// Provides access to the underlying C GObject.
  auto       gobj() -> GtkWindowControls*       { return reinterpret_cast<GtkWindowControls*>(gobject_); }

  /// Provides access to the underlying C GObject.
  auto gobj() const -> const GtkWindowControls* { return reinterpret_cast<GtkWindowControls*>(gobject_); }

private:


public:
  /** Create a new %WindowControls widget.
   */
    explicit WindowControls(PackType side);


  /** Determines which part of decoration layout the `Gtk::WindowControls` uses.
   *
   * See property_decoration_layout().
   *
   * @param side A side.
   */
  void set_side(PackType side);

  /** Gets the side to which this `Gtk::WindowControls` instance belongs.
   *
   * @return The side.
   */
  auto get_side() const -> PackType;


  /** Sets the decoration layout for the title buttons, overriding
   * the Gtk::Settings::property_gtk_decoration_layout() setting.
   *
   * The format of the string is button names, separated by commas.
   * A colon separates the buttons that should appear on the left
   * from those on the right. Recognized button names are minimize,
   * maximize, close and icon (the window icon).
   *
   * For example, “icon:minimize,maximize,close” specifies an icon
   * on the left, and minimize, maximize and close buttons on the right.
   *
   * If the property_side() value is @a Gtk::PackType::START, this %WindowControls
   * will display the part before the colon, otherwise after that.
   *
   * To unset the layout, call unset_decoration_layout().
   *
   * @param layout A decoration layout.
   */
  void set_decoration_layout(const Glib::ustring& layout);

  /** Unset the decoration layout.
   * See set_decoration_layout().
   */
  void unset_decoration_layout();


  /** Gets the decoration layout of this `Gtk::WindowControls`.
   *
   * @return The decoration layout or <tt>nullptr</tt> if it is unset.
   */
  auto get_decoration_layout() const -> Glib::ustring;


  /** Gets whether the widget has any window buttons.
   *
   * @return <tt>true</tt> if the widget has window buttons, otherwise <tt>false</tt>.
   */
  auto get_empty() const -> bool;

  /** Whether the widget shows start or end side of the decoration layout.
   *
   * See [property@Gtk.WindowControls:decoration_layout].
   *
   * Default value: Gtk::PackType::START
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_side() -> Glib::PropertyProxy< PackType > ;

/** Whether the widget shows start or end side of the decoration layout.
   *
   * See [property@Gtk.WindowControls:decoration_layout].
   *
   * Default value: Gtk::PackType::START
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_side() const -> Glib::PropertyProxy_ReadOnly< PackType >;

  /** The decoration layout for window buttons.
   *
   * If this property is not set, the
   * Gtk::Settings::property_gtk_decoration_layout() setting is used.
   *
   * Default value: ""
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_decoration_layout() -> Glib::PropertyProxy< Glib::ustring > ;

/** The decoration layout for window buttons.
   *
   * If this property is not set, the
   * Gtk::Settings::property_gtk_decoration_layout() setting is used.
   *
   * Default value: ""
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_decoration_layout() const -> Glib::PropertyProxy_ReadOnly< Glib::ustring >;

  /** Whether the widget has any window buttons.
   *
   * Default value: <tt>true</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_empty() const -> Glib::PropertyProxy_ReadOnly< bool >;


  // Gtk::WindowControls has no signals nor vfuncs.


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
   * @relates Gtk::WindowControls
   */
  GTKMM_API
  auto wrap(GtkWindowControls* object, bool take_copy = false) -> Gtk::WindowControls*;
} //namespace Glib


#endif /* _GTKMM_WINDOWCONTROLS_H */

