
#ifndef _GTKMM_ICONPAINTABLE_H
#define _GTKMM_ICONPAINTABLE_H

#include <libmm-gtk/mm-gtkconfig.hxx>


#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

/* Copyright (C) 2003 The gtkmm Development Team
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


#include <libmm-glib/object.hxx>
#include <libmm-gdk/paintable.hxx>
#include <libmm-gio/file.hxx>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkIconPaintable = struct _GtkIconPaintable;
using GtkIconPaintableClass = struct _GtkIconPaintableClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{ class GTKMM_API IconPaintable_Class; } // namespace Gtk
#endif //DOXYGEN_SHOULD_SKIP_THIS

namespace Gtk
{

/** An icon, used with Gtk::IconTheme.
 */

class GTKMM_API IconPaintable : public Glib::Object, public Gdk::Paintable
{

#ifndef DOXYGEN_SHOULD_SKIP_THIS

public:
  using CppObjectType = IconPaintable;
  using CppClassType = IconPaintable_Class;
  using BaseObjectType = GtkIconPaintable;
  using BaseClassType = GtkIconPaintableClass;

  // noncopyable
  IconPaintable(const IconPaintable&) = delete;
  auto operator=(const IconPaintable&) -> IconPaintable& = delete;

private:  friend class IconPaintable_Class;
  static CppClassType iconpaintable_class_;

protected:
  explicit IconPaintable(const Glib::ConstructParams& construct_params);
  explicit IconPaintable(GtkIconPaintable* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  IconPaintable(IconPaintable&& src) noexcept;
  auto operator=(IconPaintable&& src) noexcept -> IconPaintable&;

  ~IconPaintable() noexcept override;

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS


  static auto get_base_type() -> GType G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GObject.
  auto       gobj() -> GtkIconPaintable*       { return reinterpret_cast<GtkIconPaintable*>(gobject_); }

  ///Provides access to the underlying C GObject.
  auto gobj() const -> const GtkIconPaintable* { return reinterpret_cast<GtkIconPaintable*>(gobject_); }

  ///Provides access to the underlying C instance. The caller is responsible for unrefing it. Use when directly setting fields in structs.
  auto gobj_copy() -> GtkIconPaintable*;

private:


public:
  // gtk_icon_paintable_new_for_file() does more than call g_object_new().

  /** Creates a `Gtk::IconPaintable` for a file with a given size and scale.
   *
   * The icon can then be rendered by using it as a `Gdk::Paintable`.
   *
   * @param file A `Gio::File`.
   * @param size Desired icon size.
   * @param scale The desired scale.
   * @return A `Gtk::IconPaintable` containing
   * for the icon. Unref with Glib::object_unref().
   */
  static auto create(const Glib::RefPtr<Gio::File>& file, int size, int scale =  1) -> Glib::RefPtr<IconPaintable>;

  // The const get_file() can return a non-const Gio::File.
  // gtk_icon_paintable_get_file() returns a newly created GFile.

  /** Gets the `Gio::File` that was used to load the icon.
   *
   * @return The `Gio::File` for the icon.
   */
  auto get_file() const -> Glib::RefPtr<Gio::File>;

  /** Get the icon name being used for this icon.
   *
   * When an icon looked up in the icon theme was not available, the
   * icon theme may use fallback icons - either those specified to
   * Gtk::IconTheme::lookup_icon() or the always-available
   * "image-missing". The icon chosen is returned by this function.
   *
   * If the icon was created without an icon theme, this function
   * returns <tt>nullptr</tt>.
   *
   * @return The themed icon-name for the
   * icon, or <tt>nullptr</tt> if its not a themed icon.
   */
  auto get_icon_name() const -> Glib::ustring;

  /** Checks if the icon is symbolic or not.
   *
   * This currently uses only the file name and not the file contents
   * for determining this. This behaviour may change in the future.
   *
   * Note that to render a symbolic `Gtk::IconPaintable` properly (with
   * recoloring), you have to set its icon name on a `Gtk::Image`.
   *
   * @return <tt>true</tt> if the icon is symbolic, <tt>false</tt> otherwise.
   */
  auto is_symbolic() const -> bool;

  /** The file representing the icon, if any.
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_file() const -> Glib::PropertyProxy_ReadOnly< Glib::RefPtr<Gio::File> >;


  /** The icon name that was chosen during lookup.
   *
   * Default value: ""
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_icon_name() const -> Glib::PropertyProxy_ReadOnly< Glib::ustring >;


  /** Whether the icon is symbolic or not.
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_is_symbolic() const -> Glib::PropertyProxy_ReadOnly< bool >;


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
   * @relates Gtk::IconPaintable
   */
  GTKMM_API
  auto wrap(GtkIconPaintable* object, bool take_copy = false) -> Glib::RefPtr<Gtk::IconPaintable>;
}


#endif /* _GTKMM_ICONPAINTABLE_H */

