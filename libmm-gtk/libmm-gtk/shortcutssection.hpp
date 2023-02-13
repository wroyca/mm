// Generated by gmmproc 2.74.0 -- DO NOT MODIFY!
#ifndef _GTKMM_SHORTCUTSSECTION_H
#define _GTKMM_SHORTCUTSSECTION_H


#include <mm/glib/ustring.hpp>
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

#include <mm/gtk/box.hpp>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkShortcutsSection = struct _GtkShortcutsSection;
using GtkShortcutsSectionClass = struct _GtkShortcutsSectionClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{ class GTKMM_API ShortcutsSection_Class; } // namespace Gtk
#endif //DOXYGEN_SHOULD_SKIP_THIS

namespace Gtk
{

/** Represents an application mode in a ShortcutsWindow.
 *
 * A ShortcutsSection collects all the keyboard shortcuts and gestures
 * for a major application mode. If your application needs multiple sections,
 * you should give each section a unique section_name and
 * a title that can be shown in the section selector of the ShortcutsWindow.
 *
 * The max_height property can be used to influence how
 * the groups in the section are distributed over pages and columns.
 *
 * This widget is only meant to be used with ShortcutsWindow.
 *
 * @newin{3,20}
 *
 * @ingroup Widgets
 */

class GTKMM_API ShortcutsSection : public Box
{
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  typedef ShortcutsSection CppObjectType;
  typedef ShortcutsSection_Class CppClassType;
  typedef GtkShortcutsSection BaseObjectType;
  typedef GtkShortcutsSectionClass BaseClassType;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

  ShortcutsSection(ShortcutsSection&& src) noexcept;
  auto operator=(ShortcutsSection&& src) noexcept -> ShortcutsSection&;

  // noncopyable
  ShortcutsSection(const ShortcutsSection&) = delete;
  auto operator=(const ShortcutsSection&) -> ShortcutsSection& = delete;

  ~ShortcutsSection() noexcept override;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

private:
  friend GTKMM_API class ShortcutsSection_Class;
  static CppClassType shortcutssection_class_;

protected:
  explicit ShortcutsSection(const Glib::ConstructParams& construct_params);
  explicit ShortcutsSection(GtkShortcutsSection* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS


  static auto get_base_type() -> GType G_GNUC_CONST;
#endif

  /// Provides access to the underlying C GObject.
  auto       gobj() -> GtkShortcutsSection*       { return reinterpret_cast<GtkShortcutsSection*>(gobject_); }

  /// Provides access to the underlying C GObject.
  auto gobj() const -> const GtkShortcutsSection* { return reinterpret_cast<GtkShortcutsSection*>(gobject_); }

private:


public:
  ShortcutsSection();


  /** A unique name to identify this section among the sections
   * added to the `Gtk::ShortcutsWindow`.
   *
   * Setting the Gtk::ShortcutsWindow::property_section_name() property
   * to this string will make this section shown in the `Gtk::ShortcutsWindow`.
   *
   * Default value: ""
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_section_name() -> Glib::PropertyProxy< Glib::ustring > ;

/** A unique name to identify this section among the sections
   * added to the `Gtk::ShortcutsWindow`.
   *
   * Setting the Gtk::ShortcutsWindow::property_section_name() property
   * to this string will make this section shown in the `Gtk::ShortcutsWindow`.
   *
   * Default value: ""
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_section_name() const -> Glib::PropertyProxy_ReadOnly< Glib::ustring >;

  /** The string to show in the section selector of the `Gtk::ShortcutsWindow`
   * for this section.
   *
   * If there is only one section, you don't need to set a title,
   * since the section selector will not be shown in this case.
   *
   * Default value: ""
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_title() -> Glib::PropertyProxy< Glib::ustring > ;

/** The string to show in the section selector of the `Gtk::ShortcutsWindow`
   * for this section.
   *
   * If there is only one section, you don't need to set a title,
   * since the section selector will not be shown in this case.
   *
   * Default value: ""
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_title() const -> Glib::PropertyProxy_ReadOnly< Glib::ustring >;

  /** The maximum number of lines to allow per column.
   *
   * This property can be used to influence how the groups in this
   * section are distributed across pages and columns. The default
   * value of 15 should work in most cases.
   *
   * Default value: 15
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_max_height() -> Glib::PropertyProxy< unsigned int > ;

/** The maximum number of lines to allow per column.
   *
   * This property can be used to influence how the groups in this
   * section are distributed across pages and columns. The default
   * value of 15 should work in most cases.
   *
   * Default value: 15
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_max_height() const -> Glib::PropertyProxy_ReadOnly< unsigned int >;


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
   * @relates Gtk::ShortcutsSection
   */
  GTKMM_API
  auto wrap(GtkShortcutsSection* object, bool take_copy = false) -> Gtk::ShortcutsSection*;
} //namespace Glib


#endif /* _GTKMM_SHORTCUTSSECTION_H */

