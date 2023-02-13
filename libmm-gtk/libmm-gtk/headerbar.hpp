
#ifndef _GTKMM_HEADERBAR_H
#define _GTKMM_HEADERBAR_H


#include <libmm-glib/ustring.hpp>
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

#include <libmm-gtk/widget.hpp>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkHeaderBar = struct _GtkHeaderBar;
using GtkHeaderBarClass = struct _GtkHeaderBarClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{ class GTKMM_API HeaderBar_Class; } // namespace Gtk
#endif //DOXYGEN_SHOULD_SKIP_THIS

namespace Gtk
{

/** A box with a centered child.
 *
 * Gtk::HeaderBar is similar to a horizontal Gtk::Box, it allows
 * to place children at the start or the end. In addition,
 * it allows a title to be displayed. The title will be
 * centered with respect to the width of the box, even if the children
 * at either side take up different amounts of space.
 *
 * @ingroup Containers
 * @newin{3,10}
 */

class GTKMM_API HeaderBar
  : public Widget
{
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  typedef HeaderBar CppObjectType;
  typedef HeaderBar_Class CppClassType;
  typedef GtkHeaderBar BaseObjectType;
  typedef GtkHeaderBarClass BaseClassType;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

  HeaderBar(HeaderBar&& src) noexcept;
  auto operator=(HeaderBar&& src) noexcept -> HeaderBar&;

  // noncopyable
  HeaderBar(const HeaderBar&) = delete;
  auto operator=(const HeaderBar&) -> HeaderBar& = delete;

  ~HeaderBar() noexcept override;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

private:
  friend GTKMM_API class HeaderBar_Class;
  static CppClassType headerbar_class_;

protected:
  explicit HeaderBar(const Glib::ConstructParams& construct_params);
  explicit HeaderBar(GtkHeaderBar* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS


  static auto get_base_type() -> GType G_GNUC_CONST;
#endif

  /// Provides access to the underlying C GObject.
  auto       gobj() -> GtkHeaderBar*       { return reinterpret_cast<GtkHeaderBar*>(gobject_); }

  /// Provides access to the underlying C GObject.
  auto gobj() const -> const GtkHeaderBar* { return reinterpret_cast<GtkHeaderBar*>(gobject_); }

private:

public:

  /** Create a new HeaderBar widget.
   */
  HeaderBar();


  /** Sets the title for the `Gtk::HeaderBar`.
   *
   * When set to <tt>nullptr</tt>, the headerbar will display the title of
   * the window it is contained in.
   *
   * The title should help a user identify the current view.
   * To achieve the same style as the builtin title, use the
   * “title” style class.
   *
   * You should set the title widget to <tt>nullptr</tt>, for the window
   * title label to be visible again.
   *
   * @param title_widget A widget to use for a title.
   */
  void set_title_widget(Gtk::Widget& title_widget);

  /** Retrieves the title widget of the header.
   *
   * See set_title_widget().
   *
   * @return The title widget of the header.
   */
  auto get_title_widget() -> Widget*;

  /** Retrieves the title widget of the header.
   *
   * See set_title_widget().
   *
   * @return The title widget of the header.
   */
  auto get_title_widget() const -> const Widget*;


  /** Adds @a child to @a bar, packed with reference to the
   * start of the @a bar.
   *
   * @param child The `Gtk::Widget` to be added to @a bar.
   */
  void pack_start(Gtk::Widget& child);

  /** Adds @a child to @a bar, packed with reference to the
   * end of the @a bar.
   *
   * @param child The `Gtk::Widget` to be added to @a bar.
   */
  void pack_end(Gtk::Widget& child);

  /** Removes a child from the `Gtk::HeaderBar`.
   *
   * The child must have been added with
   * pack_start(),
   * pack_end() or
   * set_title_widget().
   *
   * @param child The child to remove.
   */
  void remove(Gtk::Widget& child);


  /** Sets whether this header bar shows the standard window
   * title buttons.
   *
   * @param setting <tt>true</tt> to show standard title buttons.
   */
  void set_show_title_buttons(bool setting =  true);

  /** Returns whether this header bar shows the standard window
   * title buttons.
   *
   * @return <tt>true</tt> if title buttons are shown.
   */
  auto get_show_title_buttons() const -> bool;


  /** Sets the decoration layout for this header bar.
   *
   * This property overrides the
   * Gtk::Settings::property_gtk_decoration_layout() setting.
   *
   * There can be valid reasons for overriding the setting, such
   * as a header bar design that does not allow for buttons to take
   * room on the right, or only offers room for a single close button.
   * Split header bars are another example for overriding the setting.
   *
   * The format of the string is button names, separated by commas.
   * A colon separates the buttons that should appear on the left
   * from those on the right. Recognized button names are minimize,
   * maximize, close and icon (the window icon).
   *
   * For example, “icon:minimize,maximize,close” specifies a icon
   * on the left, and minimize, maximize and close buttons on the right.
   *
   * @param layout A decoration layout, or <tt>nullptr</tt> to unset the layout.
   */
  void set_decoration_layout(const Glib::ustring& layout);

  /** Unset the decoration layout.
   * See set_decoration_layout().
   */
  void unset_decoration_layout();


  /** Gets the decoration layout of the `Gtk::HeaderBar`.
   *
   * @return The decoration layout.
   */
  auto get_decoration_layout() const -> Glib::ustring;

  /**
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_title_widget() -> Glib::PropertyProxy< Gtk::Widget* > ;

/**
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_title_widget() const -> Glib::PropertyProxy_ReadOnly< Gtk::Widget* >;

  /** Whether to show title buttons like close, minimize, maximize.
   *
   * Which buttons are actually shown and where is determined
   * by the property_decoration_layout() property,
   * and by the state of the window (e.g. a close button will not
   * be shown if the window can't be closed).
   *
   * Default value: <tt>true</tt>
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_show_title_buttons() -> Glib::PropertyProxy< bool > ;

/** Whether to show title buttons like close, minimize, maximize.
   *
   * Which buttons are actually shown and where is determined
   * by the property_decoration_layout() property,
   * and by the state of the window (e.g. a close button will not
   * be shown if the window can't be closed).
   *
   * Default value: <tt>true</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_show_title_buttons() const -> Glib::PropertyProxy_ReadOnly< bool >;

  /** The decoration layout for buttons.
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

/** The decoration layout for buttons.
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


  // Gtk::HeaderBar has no signals nor vfuncs as of 3.12.


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
   * @relates Gtk::HeaderBar
   */
  GTKMM_API
  auto wrap(GtkHeaderBar* object, bool take_copy = false) -> Gtk::HeaderBar*;
} //namespace Glib


#endif /* _GTKMM_HEADERBAR_H */

