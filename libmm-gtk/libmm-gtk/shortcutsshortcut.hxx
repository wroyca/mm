
#ifndef _GTKMM_SHORTCUTSSHORTCUT_H
#define _GTKMM_SHORTCUTSSHORTCUT_H


#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

/* Copyright (C) 2016 The gtkmm Development Team
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

#include <libmm-gtk/widget.hxx>
#include <libmm-gtk/enums.hxx>
#include <libmm-gio/icon.hxx>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkShortcutsShortcut = struct _GtkShortcutsShortcut;
using GtkShortcutsShortcutClass = struct _GtkShortcutsShortcutClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{ class GTKMM_API ShortcutsShortcut_Class; } // namespace Gtk
#endif //DOXYGEN_SHOULD_SKIP_THIS

namespace Gtk
{
/** @addtogroup gtkmmEnums gtkmm Enums and Flags */

/**
 *  @var ShortcutType ACCELERATOR
 * The shortcut is a keyboard accelerator. The GtkShortcutsShortcut:accelerator
 * property will be used.
 *
 *  @var ShortcutType GESTURE_PINCH
 * The shortcut is a pinch gesture. GTK provides an icon and subtitle.
 *
 *  @var ShortcutType GESTURE_STRETCH
 * The shortcut is a stretch gesture. GTK provides an icon and subtitle.
 *
 *  @var ShortcutType GESTURE_ROTATE_CLOCKWISE
 * The shortcut is a clockwise rotation gesture. GTK provides an icon and subtitle.
 *
 *  @var ShortcutType GESTURE_ROTATE_COUNTERCLOCKWISE
 * The shortcut is a counterclockwise rotation gesture. GTK provides an icon and subtitle.
 *
 *  @var ShortcutType GESTURE_TWO_FINGER_SWIPE_LEFT
 * The shortcut is a two-finger swipe gesture. GTK provides an icon and subtitle.
 *
 *  @var ShortcutType GESTURE_TWO_FINGER_SWIPE_RIGHT
 * The shortcut is a two-finger swipe gesture. GTK provides an icon and subtitle.
 *
 *  @var ShortcutType GESTURE
 * The shortcut is a gesture. The GtkShortcutsShortcut:icon property will be
 * used.
 *
 *  @var ShortcutType GESTURE_SWIPE_LEFT
 * The shortcut is a swipe gesture. GTK provides an icon and subtitle.
 *
 *  @var ShortcutType GESTURE_SWIPE_RIGHT
 * The shortcut is a swipe gesture. GTK provides an icon and subtitle.
 *
 *  @enum ShortcutType
 *
 * GtkShortcutType specifies the kind of shortcut that is being described.
 *
 * More values may be added to this enumeration over time.
 *
 * @ingroup gtkmmEnums
 */
enum class ShortcutType
{
  ACCELERATOR,
  GESTURE_PINCH,
  GESTURE_STRETCH,
  GESTURE_ROTATE_CLOCKWISE,
  GESTURE_ROTATE_COUNTERCLOCKWISE,
  GESTURE_TWO_FINGER_SWIPE_LEFT,
  GESTURE_TWO_FINGER_SWIPE_RIGHT,
  GESTURE,
  GESTURE_SWIPE_LEFT,
  GESTURE_SWIPE_RIGHT
};


} // namespace Gtk

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

template <>
class GTKMM_API Value<Gtk::ShortcutType> : public Glib::Value_Enum<Gtk::ShortcutType>
{
public:
  static auto value_type() -> GType G_GNUC_CONST;
};

} // namespace Glib
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

namespace Gtk
{


/** Represents a keyboard shortcut in a ShortcutsWindow.
 *
 * A %ShortcutsShortcut represents a single keyboard shortcut or gesture
 * with a short text. This widget is only meant to be used with ShortcutsWindow.
 *
 * @newin{3,20}
 *
 * @ingroup Widgets
 */

class GTKMM_API ShortcutsShortcut : public Widget
{
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  typedef ShortcutsShortcut CppObjectType;
  typedef ShortcutsShortcut_Class CppClassType;
  typedef GtkShortcutsShortcut BaseObjectType;
  typedef GtkShortcutsShortcutClass BaseClassType;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

  ShortcutsShortcut(ShortcutsShortcut&& src) noexcept;
  auto operator=(ShortcutsShortcut&& src) noexcept -> ShortcutsShortcut&;

  // noncopyable
  ShortcutsShortcut(const ShortcutsShortcut&) = delete;
  auto operator=(const ShortcutsShortcut&) -> ShortcutsShortcut& = delete;

  ~ShortcutsShortcut() noexcept override;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

private:
  friend GTKMM_API class ShortcutsShortcut_Class;
  static CppClassType shortcutsshortcut_class_;

protected:
  explicit ShortcutsShortcut(const Glib::ConstructParams& construct_params);
  explicit ShortcutsShortcut(GtkShortcutsShortcut* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS


  static auto get_base_type() -> GType G_GNUC_CONST;
#endif

  /// Provides access to the underlying C GObject.
  auto       gobj() -> GtkShortcutsShortcut*       { return reinterpret_cast<GtkShortcutsShortcut*>(gobject_); }

  /// Provides access to the underlying C GObject.
  auto gobj() const -> const GtkShortcutsShortcut* { return reinterpret_cast<GtkShortcutsShortcut*>(gobject_); }

private:


public:
  ShortcutsShortcut();

  /** The accelerator(s) represented by this object.
   *
   * This property is used if property_shortcut_type()
   * is set to Gtk::ShortcutType::ACCELERATOR.
   *
   * The syntax of this property is (an extension of) the syntax understood
   * by gtk_accelerator_parse(). Multiple accelerators can be specified
   * by separating them with a space, but keep in mind that the available width
   * is limited.
   *
   * It is also possible to specify ranges of shortcuts, using "..." between
   * the keys. Sequences of keys can be specified using a "+" or "&" between
   * the keys.
   *
   * Examples:
   *
   * - A single shortcut: <ctl><alt>delete
   * - Two alternative shortcuts: <shift>a Home
   * - A range of shortcuts: <alt>1...<alt>9
   * - Several keys pressed together: Control_L&Control_R
   * - A sequence of shortcuts or keys: <ctl>c+<ctl>x
   *
   * Use "+" instead of "&" when the keys may (or have to be) pressed
   * sequentially (e.g use "t+t" for 'press the t key twice').
   *
   * Note that <, > and & need to be escaped as <, > and & when used
   * in .ui files.
   *
   * Default value: ""
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_accelerator() -> Glib::PropertyProxy< Glib::ustring > ;

/** The accelerator(s) represented by this object.
   *
   * This property is used if property_shortcut_type()
   * is set to Gtk::ShortcutType::ACCELERATOR.
   *
   * The syntax of this property is (an extension of) the syntax understood
   * by gtk_accelerator_parse(). Multiple accelerators can be specified
   * by separating them with a space, but keep in mind that the available width
   * is limited.
   *
   * It is also possible to specify ranges of shortcuts, using "..." between
   * the keys. Sequences of keys can be specified using a "+" or "&" between
   * the keys.
   *
   * Examples:
   *
   * - A single shortcut: <ctl><alt>delete
   * - Two alternative shortcuts: <shift>a Home
   * - A range of shortcuts: <alt>1...<alt>9
   * - Several keys pressed together: Control_L&Control_R
   * - A sequence of shortcuts or keys: <ctl>c+<ctl>x
   *
   * Use "+" instead of "&" when the keys may (or have to be) pressed
   * sequentially (e.g use "t+t" for 'press the t key twice').
   *
   * Note that <, > and & need to be escaped as <, > and & when used
   * in .ui files.
   *
   * Default value: ""
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_accelerator() const -> Glib::PropertyProxy_ReadOnly< Glib::ustring >;

  /** An icon to represent the shortcut or gesture.
   *
   * This property is used if property_shortcut_type()
   * is set to Gtk::ShortcutType::GESTURE.
   *
   * For the other predefined gesture types, GTK provides an icon on its own.
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_icon() -> Glib::PropertyProxy< Glib::RefPtr<Gio::Icon> > ;

/** An icon to represent the shortcut or gesture.
   *
   * This property is used if property_shortcut_type()
   * is set to Gtk::ShortcutType::GESTURE.
   *
   * For the other predefined gesture types, GTK provides an icon on its own.
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_icon() const -> Glib::PropertyProxy_ReadOnly< Glib::RefPtr<Gio::Icon> >;

  /** <tt>true</tt> if an icon has been set.
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_icon_set() -> Glib::PropertyProxy< bool > ;

/** <tt>true</tt> if an icon has been set.
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_icon_set() const -> Glib::PropertyProxy_ReadOnly< bool >;

  /** The textual description for the shortcut or gesture represented by
   * this object.
   *
   * This should be a short string that can fit in a single line.
   *
   * Default value: ""
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_title() -> Glib::PropertyProxy< Glib::ustring > ;

/** The textual description for the shortcut or gesture represented by
   * this object.
   *
   * This should be a short string that can fit in a single line.
   *
   * Default value: ""
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_title() const -> Glib::PropertyProxy_ReadOnly< Glib::ustring >;

  /** The subtitle for the shortcut or gesture.
   *
   * This is typically used for gestures and should be a short, one-line
   * text that describes the gesture itself. For the predefined gesture
   * types, GTK provides a subtitle on its own.
   *
   * Default value: ""
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_subtitle() -> Glib::PropertyProxy< Glib::ustring > ;

/** The subtitle for the shortcut or gesture.
   *
   * This is typically used for gestures and should be a short, one-line
   * text that describes the gesture itself. For the predefined gesture
   * types, GTK provides a subtitle on its own.
   *
   * Default value: ""
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_subtitle() const -> Glib::PropertyProxy_ReadOnly< Glib::ustring >;

  /** <tt>true</tt> if a subtitle has been set.
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_subtitle_set() -> Glib::PropertyProxy< bool > ;

/** <tt>true</tt> if a subtitle has been set.
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_subtitle_set() const -> Glib::PropertyProxy_ReadOnly< bool >;

  /** The text direction for which this shortcut is active.
   *
   * If the shortcut is used regardless of the text direction,
   * set this property to Gtk::TextDirection::NONE.
   *
   * Default value: Gtk::TextDirection::NONE
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_direction() -> Glib::PropertyProxy< TextDirection > ;

/** The text direction for which this shortcut is active.
   *
   * If the shortcut is used regardless of the text direction,
   * set this property to Gtk::TextDirection::NONE.
   *
   * Default value: Gtk::TextDirection::NONE
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_direction() const -> Glib::PropertyProxy_ReadOnly< TextDirection >;

  /** The type of shortcut that is represented.
   *
   * Default value: Gtk::ShortcutType::ACCELERATOR
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_shortcut_type() -> Glib::PropertyProxy< ShortcutType > ;

/** The type of shortcut that is represented.
   *
   * Default value: Gtk::ShortcutType::ACCELERATOR
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_shortcut_type() const -> Glib::PropertyProxy_ReadOnly< ShortcutType >;

  /** A detailed action name.
   *
   * If this is set for a shortcut of type Gtk::ShortcutType::ACCELERATOR,
   * then GTK will use the accelerators that are associated with the
   * action via Gtk::Application::set_accels_for_action(), and
   * setting property_accelerator() is not necessary.
   *
   * Default value: ""
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_action_name() -> Glib::PropertyProxy< Glib::ustring > ;

/** A detailed action name.
   *
   * If this is set for a shortcut of type Gtk::ShortcutType::ACCELERATOR,
   * then GTK will use the accelerators that are associated with the
   * action via Gtk::Application::set_accels_for_action(), and
   * setting property_accelerator() is not necessary.
   *
   * Default value: ""
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_action_name() const -> Glib::PropertyProxy_ReadOnly< Glib::ustring >;


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
   * @relates Gtk::ShortcutsShortcut
   */
  GTKMM_API
  auto wrap(GtkShortcutsShortcut* object, bool take_copy = false) -> Gtk::ShortcutsShortcut*;
} //namespace Glib


#endif /* _GTKMM_SHORTCUTSSHORTCUT_H */

