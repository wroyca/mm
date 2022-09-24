// Generated by gmmproc 2.74.0 -- DO NOT MODIFY!
#ifndef _GTKMM_FONTBUTTON_H
#define _GTKMM_FONTBUTTON_H


#include <mm/glib/ustring.h>
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

#include <mm/gtk/widget.h>
#include <mm/gtk/fontchooser.h>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkFontButton = struct _GtkFontButton;
using GtkFontButtonClass = struct _GtkFontButtonClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{ class GTKMM_API FontButton_Class; } // namespace Gtk
#endif //DOXYGEN_SHOULD_SKIP_THIS

namespace Gtk
{

/** A button to launch a font selection dialog.
 *
 * The Gtk::FontButton is a button which displays the currently selected font and
 * allows to open a font selection dialog to change the font. It is suitable widget
 * for selecting a font in a preference dialog.
 *
 * The FontButton widget looks like this:
 * @image html fontbutton1.png
 *
 * @ingroup Widgets
 */

class GTKMM_API FontButton
  : public Widget,
    public FontChooser
{
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  typedef FontButton CppObjectType;
  typedef FontButton_Class CppClassType;
  typedef GtkFontButton BaseObjectType;
  typedef GtkFontButtonClass BaseClassType;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

  FontButton(FontButton&& src) noexcept;
  auto operator=(FontButton&& src) noexcept -> FontButton&;

  // noncopyable
  FontButton(const FontButton&) = delete;
  auto operator=(const FontButton&) -> FontButton& = delete;

  ~FontButton() noexcept override;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

private:
  friend GTKMM_API class FontButton_Class;
  static CppClassType fontbutton_class_;

protected:
  explicit FontButton(const Glib::ConstructParams& construct_params);
  explicit FontButton(GtkFontButton* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS


  static auto get_base_type() -> GType G_GNUC_CONST;
#endif

  /// Provides access to the underlying C GObject.
  auto       gobj() -> GtkFontButton*       { return reinterpret_cast<GtkFontButton*>(gobject_); }

  /// Provides access to the underlying C GObject.
  auto gobj() const -> const GtkFontButton* { return reinterpret_cast<GtkFontButton*>(gobject_); }

private:


public:
  FontButton();
    explicit FontButton(const Glib::ustring& font);


  /** Retrieves the title of the font chooser dialog.
   *
   * @return An internal copy of the title string
   * which must not be freed.
   */
  auto get_title() const -> Glib::ustring;

  /** Sets the title for the font chooser dialog.
   *
   * @param title A string containing the font chooser dialog title.
   */
  void set_title(const Glib::ustring& title);

  /** Gets whether the dialog is modal.
   *
   * @return <tt>true</tt> if the dialog is modal.
   */
  auto get_modal() const -> bool;

  /** Sets whether the dialog should be modal.
   *
   * @param modal <tt>true</tt> to make the dialog modal.
   */
  void set_modal(bool modal =  true);

  /** Returns whether the selected font is used in the label.
   *
   * @return Whether the selected font is used in the label.
   */
  auto get_use_font() const -> bool;

  /** If @a use_font is <tt>true</tt>, the font name will be written
   * using the selected font.
   *
   * @param use_font If <tt>true</tt>, font name will be written using font chosen.
   */
  void set_use_font(bool use_font =  true);

  /** Returns whether the selected size is used in the label.
   *
   * @return Whether the selected size is used in the label.
   */
  auto get_use_size() const -> bool;

  /** If @a use_size is <tt>true</tt>, the font name will be written using
   * the selected size.
   *
   * @param use_size If <tt>true</tt>, font name will be written using the
   * selected size.
   */
  void set_use_size(bool use_size =  true);

  /** The title of the font chooser dialog.
   *
   * Default value: "Pick a Font"
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_title() -> Glib::PropertyProxy< Glib::ustring > ;

/** The title of the font chooser dialog.
   *
   * Default value: "Pick a Font"
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_title() const -> Glib::PropertyProxy_ReadOnly< Glib::ustring >;

  /** Whether the font chooser dialog should be modal.
   *
   * Default value: <tt>true</tt>
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_modal() -> Glib::PropertyProxy< bool > ;

/** Whether the font chooser dialog should be modal.
   *
   * Default value: <tt>true</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_modal() const -> Glib::PropertyProxy_ReadOnly< bool >;

  /** Whether the buttons label will be drawn in the selected font.
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_use_font() -> Glib::PropertyProxy< bool > ;

/** Whether the buttons label will be drawn in the selected font.
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_use_font() const -> Glib::PropertyProxy_ReadOnly< bool >;

  /** Whether the buttons label will use the selected font size.
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_use_size() -> Glib::PropertyProxy< bool > ;

/** Whether the buttons label will use the selected font size.
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_use_size() const -> Glib::PropertyProxy_ReadOnly< bool >;


  // no_default_handler because GtkFontButtonClass is private.

  /**
   * @par Slot Prototype:
   * <tt>void on_my_%font_set()</tt>
   *
   * Flags: Run First
   *
   * Emitted when the user selects a font.
   *
   * When handling this signal, use Gtk::FontChooser::get_font()
   * to find out which font was just selected.
   *
   * Note that this signal is only emitted when the user changes the font.
   * If you need to react to programmatic font changes as well, use
   * the notify::font signal.
   */

  auto signal_font_set() -> Glib::SignalProxy<void()>;


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
   * @relates Gtk::FontButton
   */
  GTKMM_API
  auto wrap(GtkFontButton* object, bool take_copy = false) -> Gtk::FontButton*;
} //namespace Glib


#endif /* _GTKMM_FONTBUTTON_H */

