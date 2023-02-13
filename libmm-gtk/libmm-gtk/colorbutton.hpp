
#ifndef _GTKMM_COLORBUTTON_H
#define _GTKMM_COLORBUTTON_H


#include <libmm-glib/ustring.hpp>
#include <sigc++/sigc++.h>

/*
 * Copyright (C) 2003 The gtkmm Development Team
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

#include <libmm-gtk/widget.hpp>
#include <libmm-gtk/colorchooser.hpp>
#include <libmm-gdk/rgba.hpp>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkColorButton = struct _GtkColorButton;
using GtkColorButtonClass = struct _GtkColorButtonClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{ class GTKMM_API ColorButton_Class; } // namespace Gtk
#endif //DOXYGEN_SHOULD_SKIP_THIS

namespace Gtk
{

/** A button to launch a color selection dialog.
 *
 * The GtkColorButton is a button which displays the currently selected color an allows to
 * open a color selection dialog to change the color. It is suitable widget for selecting a
 * color in a preference dialog.
 *
 * The ColorButton widget looks like this:
 * @image html colorbutton1.png
 *
 * @ingroup Widgets
 */

class GTKMM_API ColorButton
: public Widget,
  public ColorChooser
{
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  typedef ColorButton CppObjectType;
  typedef ColorButton_Class CppClassType;
  typedef GtkColorButton BaseObjectType;
  typedef GtkColorButtonClass BaseClassType;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

  ColorButton(ColorButton&& src) noexcept;
  auto operator=(ColorButton&& src) noexcept -> ColorButton&;

  // noncopyable
  ColorButton(const ColorButton&) = delete;
  auto operator=(const ColorButton&) -> ColorButton& = delete;

  ~ColorButton() noexcept override;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

private:
  friend GTKMM_API class ColorButton_Class;
  static CppClassType colorbutton_class_;

protected:
  explicit ColorButton(const Glib::ConstructParams& construct_params);
  explicit ColorButton(GtkColorButton* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS


  static auto get_base_type() -> GType G_GNUC_CONST;
#endif

  /// Provides access to the underlying C GObject.
  auto       gobj() -> GtkColorButton*       { return reinterpret_cast<GtkColorButton*>(gobject_); }

  /// Provides access to the underlying C GObject.
  auto gobj() const -> const GtkColorButton* { return reinterpret_cast<GtkColorButton*>(gobject_); }

private:


public:

  /** Creates a new color button.
   *
   * This creates a widget in the form of a small button containing a swatch representing
   * the current selected color. When the button is clicked, a color-selection dialog will
   * open, allowing the user to select a color. The swatch will be updated to reflect the
   * new color when the user finishes.
   *
   * @newin{2,4}
   */
  ColorButton();


  /** Creates a new color button with a predefined color.
   *
   * Same as Gtk::ColorButton::ColorButton(). Additionally takes a Gdk::RGBA and
   * initializes the button with this color. Equivalent to calling ColorChooser::set_rgba(@a rgba)
   * after the default constructor.
   *
   * @param rgba A Gdk::RGBA to set the current color with.
   *
   * @newin{3,0}
   */
    explicit ColorButton(const Gdk::RGBA& rgba);


  /** Sets the title for the color chooser dialog.
   *
   * @param title String containing new window title.
   */
  void set_title(const Glib::ustring& title);

  /** Gets the title of the color chooser dialog.
   *
   * @return The title.
   */
  auto get_title() const -> Glib::ustring;


  /** Sets whether the dialog should be modal.
   *
   * @param modal <tt>true</tt> to make the dialog modal.
   */
  void set_modal(bool modal =  true);

  /** Gets whether the dialog is modal.
   *
   * @return <tt>true</tt> if the dialog is modal.
   */
  auto get_modal() const -> bool;

  /** The title of the color chooser dialog
   *
   * Default value: "Pick a Color"
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_title() -> Glib::PropertyProxy< Glib::ustring > ;

/** The title of the color chooser dialog
   *
   * Default value: "Pick a Color"
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_title() const -> Glib::PropertyProxy_ReadOnly< Glib::ustring >;

  /** Whether the color chooser should open in editor mode.
   *
   * This property should be used in cases where the palette
   * in the editor would be redundant, such as when the color
   * button is already part of a palette.
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_show_editor() -> Glib::PropertyProxy< bool > ;

/** Whether the color chooser should open in editor mode.
   *
   * This property should be used in cases where the palette
   * in the editor would be redundant, such as when the color
   * button is already part of a palette.
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_show_editor() const -> Glib::PropertyProxy_ReadOnly< bool >;

  /** Whether the color chooser dialog should be modal.
   *
   * Default value: <tt>true</tt>
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_modal() -> Glib::PropertyProxy< bool > ;

/** Whether the color chooser dialog should be modal.
   *
   * Default value: <tt>true</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_modal() const -> Glib::PropertyProxy_ReadOnly< bool >;


  // no_default_handler because GtkColorButtonClass is private.

  /**
   * @par Slot Prototype:
   * <tt>void on_my_%color_set()</tt>
   *
   * Flags: Run First
   *
   * Emitted when the user selects a color.
   *
   * When handling this signal, use Gtk::ColorChooser::get_rgba()
   * to find out which color was just selected.
   *
   * Note that this signal is only emitted when the user changes the color.
   * If you need to react to programmatic color changes as well, use
   * the notify::rgba signal.
   */

  auto signal_color_set() -> Glib::SignalProxy<void()>;


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
   * @relates Gtk::ColorButton
   */
  GTKMM_API
  auto wrap(GtkColorButton* object, bool take_copy = false) -> Gtk::ColorButton*;
} //namespace Glib


#endif /* _GTKMM_COLORBUTTON_H */

