
#ifndef _GTKMM_APPCHOOSERDIALOG_H
#define _GTKMM_APPCHOOSERDIALOG_H


#include <libmm-glib/ustring.hpp>
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

#include <libmm-gtk/appchooser.hpp>
#include <libmm-gtk/dialog.hpp>
#include <libmm-gio/file.hpp>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkAppChooserDialog = struct _GtkAppChooserDialog;
using GtkAppChooserDialogClass = struct _GtkAppChooserDialogClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{ class GTKMM_API AppChooserDialog_Class; } // namespace Gtk
#endif //DOXYGEN_SHOULD_SKIP_THIS

namespace Gtk
{

/** An application chooser dialog.
 *
 * This dialog shows an AppChooserWidget inside a Dialog.
 *
 * Note that AppChooserDialog does not have any interesting methods of its own.
 * Instead, you should get the embedded AppChooserWidget using get_widget() and
 * call its methods if the generic AppChooser base class API is not sufficient for your needs.
 *
 * To set the heading that is shown above the AppChooserWidget, use set_heading().
 *
 * See @ref giommContentType in glibmm for more information about content types.
 *
 * The AppChooserDialog dialog looks like this:
 * @image html appchooserdialog1.png
 *
 * @ingroup Dialogs
 *
 * @newin{3,0}
 */

class GTKMM_API AppChooserDialog
  : public Dialog,
    public AppChooser
{
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  typedef AppChooserDialog CppObjectType;
  typedef AppChooserDialog_Class CppClassType;
  typedef GtkAppChooserDialog BaseObjectType;
  typedef GtkAppChooserDialogClass BaseClassType;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

  AppChooserDialog(AppChooserDialog&& src) noexcept;
  auto operator=(AppChooserDialog&& src) noexcept -> AppChooserDialog&;

  // noncopyable
  AppChooserDialog(const AppChooserDialog&) = delete;
  auto operator=(const AppChooserDialog&) -> AppChooserDialog& = delete;

  ~AppChooserDialog() noexcept override;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

private:
  friend GTKMM_API class AppChooserDialog_Class;
  static CppClassType appchooserdialog_class_;

protected:
  explicit AppChooserDialog(const Glib::ConstructParams& construct_params);
  explicit AppChooserDialog(GtkAppChooserDialog* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS


  static auto get_base_type() -> GType G_GNUC_CONST;
#endif

  /// Provides access to the underlying C GObject.
  auto       gobj() -> GtkAppChooserDialog*       { return reinterpret_cast<GtkAppChooserDialog*>(gobject_); }

  /// Provides access to the underlying C GObject.
  auto gobj() const -> const GtkAppChooserDialog* { return reinterpret_cast<GtkAppChooserDialog*>(gobject_); }

private:


public:

  explicit AppChooserDialog(const Glib::ustring& content_type);

  AppChooserDialog(const Glib::ustring& content_type, Gtk::Window& parent);


  explicit AppChooserDialog(const Glib::RefPtr<Gio::File>& file);

  AppChooserDialog(const Glib::RefPtr<Gio::File>& file, Gtk::Window& parent);


  /** Returns the `Gtk::AppChooserWidget` of this dialog.
   *
   * @return The `Gtk::AppChooserWidget` of @a self.
   */
  auto get_widget() -> Widget*;

  /** Returns the `Gtk::AppChooserWidget` of this dialog.
   *
   * @return The `Gtk::AppChooserWidget` of @a self.
   */
  auto get_widget() const -> const Widget*;


  /** Sets the text to display at the top of the dialog.
   *
   * If the heading is not set, the dialog displays a default text.
   *
   * @param heading A string containing Pango markup.
   */
  void set_heading(const Glib::ustring& heading);

  /** Returns the text to display at the top of the dialog.
   *
   * @return The text to display at the top of the dialog,
   * or <tt>nullptr</tt>, in which case a default text is displayed.
   */
  auto get_heading() const -> Glib::ustring;

  /** The GFile used by the `Gtk::AppChooserDialog`.
   *
   * The dialog's `Gtk::AppChooserWidget` content type will
   * be guessed from the file, if present.
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_gfile() const -> Glib::PropertyProxy_ReadOnly< Glib::RefPtr<Gio::File> >;


  /** The text to show at the top of the dialog.
   *
   * The string may contain Pango markup.
   *
   * Default value: ""
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_heading() -> Glib::PropertyProxy< Glib::ustring > ;

/** The text to show at the top of the dialog.
   *
   * The string may contain Pango markup.
   *
   * Default value: ""
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_heading() const -> Glib::PropertyProxy_ReadOnly< Glib::ustring >;


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
   * @relates Gtk::AppChooserDialog
   */
  GTKMM_API
  auto wrap(GtkAppChooserDialog* object, bool take_copy = false) -> Gtk::AppChooserDialog*;
} //namespace Glib


#endif /* _GTKMM_APPCHOOSERDIALOG_H */

