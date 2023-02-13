
#ifndef _GTKMM_COLORCHOOSER_H
#define _GTKMM_COLORCHOOSER_H


#include <mm/glib/ustring.hpp>
#include <sigc++/sigc++.h>

/* Copyright (C) 2012 The gtkmm Development Team
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

#include <mm/glib/interface.hpp>
#include <mm/gtk/enums.hpp> //For Orientation.
#include <mm/gdk/rgba.hpp>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
extern "C"
{
typedef struct _GtkColorChooserInterface GtkColorChooserInterface;
}
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkColorChooser = struct _GtkColorChooser;
using GtkColorChooserClass = struct _GtkColorChooserClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{ class GTKMM_API ColorChooser_Class; } // namespace Gtk
#endif // DOXYGEN_SHOULD_SKIP_THIS

namespace Gtk
{

/** This interface can be implemented by widgets which allow the user to choose
 * a color. Depending on the situation, colors may be
 * allowed to have alpha (translucency).
 * The main widgets that implement this interface are ColorChooserWidget, ColorChooserDialog
 * and ColorChooserButton.
 *
 * @newin{3,4}
 */

class GTKMM_API ColorChooser : public Glib::Interface
{

#ifndef DOXYGEN_SHOULD_SKIP_THIS

public:
  using CppObjectType = ColorChooser;
  using CppClassType = ColorChooser_Class;
  using BaseObjectType = GtkColorChooser;
  using BaseClassType = GtkColorChooserInterface;

  // noncopyable
  ColorChooser(const ColorChooser&) = delete;
  auto operator=(const ColorChooser&) -> ColorChooser& = delete;

private:
  friend class ColorChooser_Class;
  static CppClassType colorchooser_class_;

#endif /* DOXYGEN_SHOULD_SKIP_THIS */
protected:
  /**
   * You should derive from this class to use it.
   */
  ColorChooser();

#ifndef DOXYGEN_SHOULD_SKIP_THIS
  /** Called by constructors of derived classes. Provide the result of
   * the Class init() function to ensure that it is properly
   * initialized.
   *
   * @param interface_class The Class object for the derived type.
   */
  explicit ColorChooser(const Glib::Interface_Class& interface_class);

public:
  // This is public so that C++ wrapper instances can be
  // created for C instances of unwrapped types.
  // For instance, if an unexpected C type implements the C interface.
  explicit ColorChooser(GtkColorChooser* castitem);

protected:
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  ColorChooser(ColorChooser&& src) noexcept;
  auto operator=(ColorChooser&& src) noexcept -> ColorChooser&;

  ~ColorChooser() noexcept override;

  static void add_interface(GType gtype_implementer);

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS
  static auto get_base_type() -> GType G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GObject.
  auto       gobj() -> GtkColorChooser*       { return reinterpret_cast<GtkColorChooser*>(gobject_); }

  ///Provides access to the underlying C GObject.
  auto gobj() const -> const GtkColorChooser* { return reinterpret_cast<GtkColorChooser*>(gobject_); }

private:


public:
  /** Gets the currently selected color.
   * @return The currently selected color.
   * @newin{3,4}
   */
  auto get_rgba() const -> Gdk::RGBA;


  /** Sets the color.
   *
   * @param color The new color.
   */
  void set_rgba(const Gdk::RGBA& color);

  /** Returns whether the color chooser shows the alpha channel.
   *
   * @return <tt>true</tt> if the color chooser uses the alpha channel,
   * <tt>false</tt> if not.
   */
  auto get_use_alpha() const -> bool;

  /** Sets whether or not the color chooser should use the alpha channel.
   *
   * @param use_alpha <tt>true</tt> if color chooser should use alpha channel, <tt>false</tt> if not.
   */
  void set_use_alpha(bool use_alpha =  true);

 /** Adds a palette to the color chooser. If @a orientation is horizontal,
  * the colors are grouped in rows, with @a colors_per_line colors
  * in each row. If @a orientation is vertical, the colors are grouped
  * in columns instead.
  *
  * The default color palette of ColorChooserWidget has
  * 27 colors, organized in columns of 3 colors. The default gray
  * palette has 9 grays in a single row.
  *
  * The layout of the color chooser widget works best when the
  * palettes have 9-10 columns.
  *
  * Calling this function for the first time has the
  * side effect of removing the default color and gray palettes
  * from the color chooser.
  *
  * @param orientation Orientation::HORIZONTAL if the palette should be displayed in rows, or Orientation::VERTICAL for columns
  * @param colors_per_line The number of colors to show in each row/column.
  * @param colors The colors of the palette.
  *
  * @newin{3,4}
  */
  void add_palette(Orientation orientation, int colors_per_line, const std::vector<Gdk::RGBA>& colors);


//#m4 __CONVERSION(`const Gdk::RGBA&',`const GdkRGBA*',`const_cast<GdkRGBA*>(($3).gobj())')

  /**
   * @par Slot Prototype:
   * <tt>void on_my_%color_activated(const Gdk::RGBA& color)</tt>
   *
   * Flags: Run First
   *
   * Emitted when a color is activated from the color chooser.
   *
   * This usually happens when the user clicks a color swatch,
   * or a color is selected and the user presses one of the keys
   * Space, Shift+Space, Return or Enter.
   *
   * @param color The color.
   */

  auto signal_color_activated() -> Glib::SignalProxy<void(const Gdk::RGBA&)>;


  /** The currently selected color, as a `GdkRGBA` struct.
   *
   * The property can be set to change the current selection
   * programmatically.
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_rgba() -> Glib::PropertyProxy< Gdk::RGBA > ;

/** The currently selected color, as a `GdkRGBA` struct.
   *
   * The property can be set to change the current selection
   * programmatically.
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_rgba() const -> Glib::PropertyProxy_ReadOnly< Gdk::RGBA >;

  /** Whether colors may have alpha (translucency).
   *
   * When signal_use_alpha() is <tt>false</tt>, the `GdkRGBA` struct obtained
   * via the property_rgba() property will be
   * forced to have alpha == 1.
   *
   * Implementations are expected to show alpha by rendering the color
   * over a non-uniform background (like a checkerboard pattern).
   *
   * Default value: <tt>true</tt>
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_use_alpha() -> Glib::PropertyProxy< bool > ;

/** Whether colors may have alpha (translucency).
   *
   * When signal_use_alpha() is <tt>false</tt>, the `GdkRGBA` struct obtained
   * via the property_rgba() property will be
   * forced to have alpha == 1.
   *
   * Implementations are expected to show alpha by rendering the color
   * over a non-uniform background (like a checkerboard pattern).
   *
   * Default value: <tt>true</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_use_alpha() const -> Glib::PropertyProxy_ReadOnly< bool >;


public:

public:
  //C++ methods used to invoke GTK+ virtual functions:

protected:
  //GTK+ Virtual Functions (override these to change behaviour):

  //Default Signal Handlers::
  /// This is a default handler for the signal signal_color_activated().
  virtual void on_color_activated(const Gdk::RGBA& color);


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
   * @relates Gtk::ColorChooser
   */
  GTKMM_API
  auto wrap(GtkColorChooser* object, bool take_copy = false) -> Glib::RefPtr<Gtk::ColorChooser>;

} // namespace Glib


#endif /* _GTKMM_COLORCHOOSER_H */

