
#ifndef _GTKMM_CELLRENDERERACCEL_H
#define _GTKMM_CELLRENDERERACCEL_H


#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

/*
 * Copyright (C) 2005 The gtkmm Development Team
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

#include <libmm-gtk/cellrenderertext.hxx>
#include <libmm-gtk/accelkey.hxx>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkCellRendererAccel = struct _GtkCellRendererAccel;
using GtkCellRendererAccelClass = struct _GtkCellRendererAccelClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{ class GTKMM_API CellRendererAccel_Class; } // namespace Gtk
#endif //DOXYGEN_SHOULD_SKIP_THIS

namespace Gtk
{

/**
 * Renders a keyboard accelerator in a cell.
 *
 * Gtk::CellRendererAccel displays a keyboard accelerator
 * (i.e. a key combination like <Control>-a).
 * If the cell renderer is editable, the accelerator can be changed by
 * simply typing the new combination.
 *
 * Key values are the codes which are sent whenever a key is pressed or released.
 * The complete list of key values can be found in the
 * <a href="https://gitlab.gnome.org/GNOME/gtk/tree/main/gdk/gdkkeysyms.h">gdk/gdkkeysyms.h</a>
 * header file. They are prefixed with <tt>GDK_KEY_</tt>.
 *
 * @ingroup TreeView
 * @newin{2,10}
 */

class GTKMM_API CellRendererAccel : public CellRendererText
{
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  typedef CellRendererAccel CppObjectType;
  typedef CellRendererAccel_Class CppClassType;
  typedef GtkCellRendererAccel BaseObjectType;
  typedef GtkCellRendererAccelClass BaseClassType;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

  CellRendererAccel(CellRendererAccel&& src) noexcept;
  auto operator=(CellRendererAccel&& src) noexcept -> CellRendererAccel&;

  // noncopyable
  CellRendererAccel(const CellRendererAccel&) = delete;
  auto operator=(const CellRendererAccel&) -> CellRendererAccel& = delete;

  ~CellRendererAccel() noexcept override;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

private:
  friend GTKMM_API class CellRendererAccel_Class;
  static CppClassType cellrendereraccel_class_;

protected:
  explicit CellRendererAccel(const Glib::ConstructParams& construct_params);
  explicit CellRendererAccel(GtkCellRendererAccel* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS


  static auto get_base_type() -> GType G_GNUC_CONST;
#endif

  /// Provides access to the underlying C GObject.
  auto       gobj() -> GtkCellRendererAccel*       { return reinterpret_cast<GtkCellRendererAccel*>(gobject_); }

  /// Provides access to the underlying C GObject.
  auto gobj() const -> const GtkCellRendererAccel* { return reinterpret_cast<GtkCellRendererAccel*>(gobject_); }

private:

public:

  /** @addtogroup gtkmmEnums gtkmm Enums and Flags */

  /**
   *  @var Mode GTK
   * GTK accelerators mode.
   *
   *  @var Mode OTHER
   * Other accelerator mode.
   *
   *  @enum Mode
   *
   * The available modes for Gtk::CellRendererAccel::property_accel_mode().
   *
   * @ingroup gtkmmEnums
   */
  enum class Mode
  {
    GTK,
    OTHER
  };


  CellRendererAccel();


  //TODO: Wrap accel_key and accel_mods in an AccelKey?
  // no_default_handler because GtkCellRendererAccelClass is private.

  /**
   * @par Slot Prototype:
   * <tt>void on_my_%accel_edited(const Glib::ustring& path_string, guint accel_key, Gdk::ModifierType accel_mods, guint hardware_keycode)</tt>
   *
   * Flags: Run Last
   *
   * Gets emitted when the user has selected a new accelerator.
   *
   * @param path_string The path identifying the row of the edited cell.
   * @param accel_key The new accelerator keyval.
   * @param accel_mods The new acclerator modifier mask.
   * @param hardware_keycode The keycode of the new accelerator.
   */

  auto signal_accel_edited() -> Glib::SignalProxy<void(const Glib::ustring&, guint, Gdk::ModifierType, guint)>;


  /**
   * @par Slot Prototype:
   * <tt>void on_my_%accel_cleared(const Glib::ustring& path_string)</tt>
   *
   * Flags: Run Last
   *
   * Gets emitted when the user has removed the accelerator.
   *
   * @param path_string The path identifying the row of the edited cell.
   */

  auto signal_accel_cleared() -> Glib::SignalProxy<void(const Glib::ustring&)>;


  /** The keyval of the accelerator.
   *
   * Default value: 0
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_accel_key() -> Glib::PropertyProxy< guint > ;

/** The keyval of the accelerator.
   *
   * Default value: 0
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_accel_key() const -> Glib::PropertyProxy_ReadOnly< guint >;

  /** The modifier mask of the accelerator.
   *
   * Default value: 0
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_accel_mods() -> Glib::PropertyProxy< Gdk::ModifierType > ;

/** The modifier mask of the accelerator.
   *
   * Default value: 0
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_accel_mods() const -> Glib::PropertyProxy_ReadOnly< Gdk::ModifierType >;

  /** The hardware keycode of the accelerator. Note that the hardware keycode is
   * only relevant if the key does not have a keyval. Normally, the keyboard
   * configuration should assign keyvals to all keys.
   *
   * Default value: 0
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_keycode() -> Glib::PropertyProxy< guint > ;

/** The hardware keycode of the accelerator. Note that the hardware keycode is
   * only relevant if the key does not have a keyval. Normally, the keyboard
   * configuration should assign keyvals to all keys.
   *
   * Default value: 0
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_keycode() const -> Glib::PropertyProxy_ReadOnly< guint >;

  /** Determines if the edited accelerators are GTK accelerators. If
   * they are, consumed modifiers are suppressed, only accelerators
   * accepted by GTK are allowed, and the accelerators are rendered
   * in the same way as they are in menus.
   *
   * Default value: Gtk::CellRendererAccel::Mode::GTK
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_accel_mode() -> Glib::PropertyProxy< Mode > ;

/** Determines if the edited accelerators are GTK accelerators. If
   * they are, consumed modifiers are suppressed, only accelerators
   * accepted by GTK are allowed, and the accelerators are rendered
   * in the same way as they are in menus.
   *
   * Default value: Gtk::CellRendererAccel::Mode::GTK
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_accel_mode() const -> Glib::PropertyProxy_ReadOnly< Mode >;


  auto _property_renderable() -> Glib::PropertyProxy_Base override;


public:

public:
  //C++ methods used to invoke GTK+ virtual functions:

protected:
  //GTK+ Virtual Functions (override these to change behaviour):

  //Default Signal Handlers::


};

} //namespace Gtk


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

template <>
class GTKMM_API Value<Gtk::CellRendererAccel::Mode> : public Glib::Value_Enum<Gtk::CellRendererAccel::Mode>
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
   * @relates Gtk::CellRendererAccel
   */
  GTKMM_API
  auto wrap(GtkCellRendererAccel* object, bool take_copy = false) -> Gtk::CellRendererAccel*;
} //namespace Glib


#endif /* _GTKMM_CELLRENDERERACCEL_H */

