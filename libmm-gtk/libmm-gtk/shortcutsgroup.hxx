
#ifndef _GTKMM_SHORTCUTSGROUP_H
#define _GTKMM_SHORTCUTSGROUP_H


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

#include <libmm-gtk/box.hxx>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkShortcutsGroup = struct _GtkShortcutsGroup;
using GtkShortcutsGroupClass = struct _GtkShortcutsGroupClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{ class GTKMM_API ShortcutsGroup_Class; } // namespace Gtk
#endif //DOXYGEN_SHOULD_SKIP_THIS

namespace Gtk
{

/** Represents a group of shortcuts in a ShortcutsWindow.
 *
 * A ShortcutsGroup represents a group of related keyboard shortcuts
 * or gestures. The group has a title. It may optionally be associated with
 * a view of the application, which can be used to show only relevant shortcuts
 * depending on the application context.
 *
 * This widget is only meant to be used with ShortcutsWindow.
 *
 * @newin{3,20}
 *
 * @ingroup Widgets
 */

class GTKMM_API ShortcutsGroup : public Box
{
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  typedef ShortcutsGroup CppObjectType;
  typedef ShortcutsGroup_Class CppClassType;
  typedef GtkShortcutsGroup BaseObjectType;
  typedef GtkShortcutsGroupClass BaseClassType;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

  ShortcutsGroup(ShortcutsGroup&& src) noexcept;
  auto operator=(ShortcutsGroup&& src) noexcept -> ShortcutsGroup&;

  // noncopyable
  ShortcutsGroup(const ShortcutsGroup&) = delete;
  auto operator=(const ShortcutsGroup&) -> ShortcutsGroup& = delete;

  ~ShortcutsGroup() noexcept override;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

private:
  friend GTKMM_API class ShortcutsGroup_Class;
  static CppClassType shortcutsgroup_class_;

protected:
  explicit ShortcutsGroup(const Glib::ConstructParams& construct_params);
  explicit ShortcutsGroup(GtkShortcutsGroup* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS


  static auto get_base_type() -> GType G_GNUC_CONST;
#endif

  /// Provides access to the underlying C GObject.
  auto       gobj() -> GtkShortcutsGroup*       { return reinterpret_cast<GtkShortcutsGroup*>(gobject_); }

  /// Provides access to the underlying C GObject.
  auto gobj() const -> const GtkShortcutsGroup* { return reinterpret_cast<GtkShortcutsGroup*>(gobject_); }

private:


public:
  ShortcutsGroup();

  /** Unsets the property_view() of this shortcuts group.
   * The group will then always be visible, regardless of the value of
   * Gtk::ShortcutsWindow::property_view_name().
   *
   * This is a convenience method that calls property_view().reset_value().
   */
  void unset_view();

  /** The title for this group of shortcuts.
   *
   * Default value: ""
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_title() -> Glib::PropertyProxy< Glib::ustring > ;

/** The title for this group of shortcuts.
   *
   * Default value: ""
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_title() const -> Glib::PropertyProxy_ReadOnly< Glib::ustring >;

  /** An optional view that the shortcuts in this group are relevant for.
   *
   * The group will be hidden if the Gtk::ShortcutsWindow::property_view_name()
   * property does not match the view of this group.
   *
   * Set this to <tt>nullptr</tt> to make the group always visible.
   *
   * Default value: ""
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_view() -> Glib::PropertyProxy< Glib::ustring > ;

/** An optional view that the shortcuts in this group are relevant for.
   *
   * The group will be hidden if the Gtk::ShortcutsWindow::property_view_name()
   * property does not match the view of this group.
   *
   * Set this to <tt>nullptr</tt> to make the group always visible.
   *
   * Default value: ""
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_view() const -> Glib::PropertyProxy_ReadOnly< Glib::ustring >;


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
   * @relates Gtk::ShortcutsGroup
   */
  GTKMM_API
  auto wrap(GtkShortcutsGroup* object, bool take_copy = false) -> Gtk::ShortcutsGroup*;
} //namespace Glib


#endif /* _GTKMM_SHORTCUTSGROUP_H */

