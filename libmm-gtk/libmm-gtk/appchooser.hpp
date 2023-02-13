
#ifndef _GTKMM_APPCHOOSER_H
#define _GTKMM_APPCHOOSER_H

#include <mm/gtk/mm-gtkconfig.hpp>


#include <mm/glib/ustring.hpp>
#include <sigc++/sigc++.h>

/* Copyright (C) 2011 The gtkmm Development Team
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
#include <mm/gio/appinfo.hpp>
//#include <mm/gtk/enums.hpp>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
extern "C"
{
typedef struct _GtkAppChooserIface GtkAppChooserIface;
}
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkAppChooser = struct _GtkAppChooser;
using GtkAppChooserClass = struct _GtkAppChooserClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{ class GTKMM_API AppChooser_Class; } // namespace Gtk
#endif // DOXYGEN_SHOULD_SKIP_THIS

namespace Gtk
{

/** Interface implemented by widgets for choosing an application.
 *
 * This interface can be implemented by widgets which allow the user to choose
 * an application (typically for the purpose of opening a file). The main
 * objects that implement this interface are AppChooserWidget, AppChooserDialog
 * and AppChooserButton.
 *
 * Applications are represented by Gio::AppInfo objects here.
 * GIO has a concept of recommended and fallback applications for a
 * given content type. Recommended applications are those that claim
 * to handle the content type itself, while fallback also includes
 * applications that handle a more generic content type. GIO also
 * knows the default and last-used application for a given content
 * type. The AppChooserWidget provides detailed control over
 * whether the shown list of applications should include default,
 * recommended or fallback applications.
 *
 * To obtain the application that has been selected in an AppChooser,
 * use get_app_info().
 *
 * See @ref giommContentType in glibmm for more information about content types.
 *
 * @newin{3,0}
 */

class GTKMM_API AppChooser : public Glib::Interface
{

#ifndef DOXYGEN_SHOULD_SKIP_THIS

public:
  using CppObjectType = AppChooser;
  using CppClassType = AppChooser_Class;
  using BaseObjectType = GtkAppChooser;
  using BaseClassType = GtkAppChooserIface;

  // noncopyable
  AppChooser(const AppChooser&) = delete;
  auto operator=(const AppChooser&) -> AppChooser& = delete;

private:
  friend class AppChooser_Class;
  static CppClassType appchooser_class_;

#endif /* DOXYGEN_SHOULD_SKIP_THIS */
protected:
  /**
   * You should derive from this class to use it.
   */
  AppChooser();

#ifndef DOXYGEN_SHOULD_SKIP_THIS
  /** Called by constructors of derived classes. Provide the result of
   * the Class init() function to ensure that it is properly
   * initialized.
   *
   * @param interface_class The Class object for the derived type.
   */
  explicit AppChooser(const Glib::Interface_Class& interface_class);

public:
  // This is public so that C++ wrapper instances can be
  // created for C instances of unwrapped types.
  // For instance, if an unexpected C type implements the C interface.
  explicit AppChooser(GtkAppChooser* castitem);

protected:
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  AppChooser(AppChooser&& src) noexcept;
  auto operator=(AppChooser&& src) noexcept -> AppChooser&;

  ~AppChooser() noexcept override;

  static void add_interface(GType gtype_implementer);

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS
  static auto get_base_type() -> GType G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GObject.
  auto       gobj() -> GtkAppChooser*       { return reinterpret_cast<GtkAppChooser*>(gobject_); }

  ///Provides access to the underlying C GObject.
  auto gobj() const -> const GtkAppChooser* { return reinterpret_cast<GtkAppChooser*>(gobject_); }

private:


public:

  /** Returns the currently selected application.
   *
   * @return A `Gio::AppInfo` for the
   * currently selected application.
   */
  auto get_app_info() -> Glib::RefPtr<Gio::AppInfo>;

  /** Returns the currently selected application.
   *
   * @return A `Gio::AppInfo` for the
   * currently selected application.
   */
  auto get_app_info() const -> Glib::RefPtr<const Gio::AppInfo>;


  /** Returns the content type for which the `Gtk::AppChooser`
   * shows applications.
   *
   * @return The content type of @a self.
   */
  auto get_content_type() const -> Glib::ustring;

  /** Reloads the list of applications.
   */
  void refresh();

  /** The content type of the `Gtk::AppChooser` object.
   *
   * See `ContentType` for more information about content types.
   *
   * Default value: ""
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_content_type() const -> Glib::PropertyProxy_ReadOnly< Glib::ustring >;


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
   * @relates Gtk::AppChooser
   */
  GTKMM_API
  auto wrap(GtkAppChooser* object, bool take_copy = false) -> Glib::RefPtr<Gtk::AppChooser>;

} // namespace Glib


#endif /* _GTKMM_APPCHOOSER_H */

