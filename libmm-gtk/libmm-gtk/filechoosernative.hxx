
#ifndef _GTKMM_FILECHOOSERNATIVE_H
#define _GTKMM_FILECHOOSERNATIVE_H


#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

/* Copyright (C) 2017 The gtkmm Development Team
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

#include <libmm-gtk/nativedialog.hxx>
#include <libmm-gtk/filechooser.hxx>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{ class GTKMM_API FileChooserNative_Class; } // namespace Gtk
#endif //DOXYGEN_SHOULD_SKIP_THIS

namespace Gtk
{
class GTKMM_API Window;

/** A native file chooser dialog, suitable for “File/Open” or “File/Save” commands.
 *
 * %FileChooserNative is an abstraction of a dialog box suitable
 * for use with “File/Open” or “File/Save as” commands. By default, this
 * just uses a Gtk::FileChooserDialog to implement the actual dialog.
 * However, on certain platforms, such as Windows, the native platform
 * file chooser is used instead. When the application is running in a
 * sandboxed environment without direct filesystem access (such as Flatpak),
 * %FileChooserNative may call the proper APIs (portals) to let the user
 * choose a file and make it available to the application.
 *
 * While the API of %FileChooserNative closely mirrors FileChooserDialog, the main
 * difference is that there is no access to any Gtk::Window or Gtk::Widget for the dialog.
 * This is required, as there may not be one in the case of a platform native dialog.
 * Showing, hiding and running the dialog is handled by the NativeDialog functions.
 *
 * <h2>Response Codes</h2>
 *
 * %FileChooserNative inherits from NativeDialog, which means it
 * will return Gtk::ResponseType::ACCEPT if the user accepted, and
 * Gtk::ResponseType::CANCEL if he pressed cancel. It can also return
 * Gtk::ResponseType::DELETE_EVENT if the window was unexpectedly closed.
 *
 * <h2>Differences from FileChooserDialog</h2>
 *
 * There are a few things in the FileChooser API that are not
 * possible to use with %FileChooserNative, as such use would
 * prohibit the use of a native dialog.
 *
 * There is no support for the signals that are emitted when the user
 * navigates in the dialog, including:
 * * FileChooser::signal_current_folder_changed()
 * * FileChooser::signal_selection_changed()
 * * FileChooser::signal_file_activated()
 * * FileChooser::signal_confirm_overwrite()
 *
 * You can also not use the methods that directly control user navigation:
 * * FileChooser::unselect_filename()
 * * FileChooser::select_all()
 * * FileChooser::unselect_all()
 *
 * If you need any of the above you will have to use FileChooserDialog directly.
 *
 * No operations that change the dialog work while the dialog is
 * visible. Set all the properties that are required before showing the dialog.
 *
 * <h2>Win32 details</h2>
 *
 * On windows the IFileDialog implementation (added in Windows Vista) is
 * used. It supports many of the features that FileChooserDialog
 * does, but there are some things it does not handle:
 *
 * * Extra widgets added with FileChooser::set_extra_widget().
 *
 * * Use of custom previews by connecting to FileChooser::signal_update_preview().
 *
 * * Any Gtk::FileFilter added using a mimetype or custom filter.
 *
 * If any of these features are used the regular FileChooserDialog
 * will be used in place of the native one.
 *
 * <h2>Portal details</h2>
 *
 * When the org.freedesktop.portal.FileChooser portal is available on the
 * session bus, it is used to bring up an out-of-process file chooser. Depending
 * on the kind of session the application is running in, this may or may not
 * be a GTK+ file chooser. In this situation, the following things are not
 * supported and will be silently ignored:
 *
 * * Extra widgets added with FileChooser::set_extra_widget().
 *
 * * Use of custom previews by connecting to FileChooser::signal_update_preview().
 *
 * * Any Gtk::FileFilter added with a custom filter.
 *
 * @see Gtk::FileChooser, Gtk::NativeDialog, Gtk::FileChooserDialog
 * @newin{3,24}
 */

class GTKMM_API FileChooserNative : public NativeDialog, public FileChooser
{

#ifndef DOXYGEN_SHOULD_SKIP_THIS

public:
  using CppObjectType = FileChooserNative;
  using CppClassType = FileChooserNative_Class;
  using BaseObjectType = GtkFileChooserNative;
  using BaseClassType = GtkFileChooserNativeClass;

  // noncopyable
  FileChooserNative(const FileChooserNative&) = delete;
  auto operator=(const FileChooserNative&) -> FileChooserNative& = delete;

private:  friend class FileChooserNative_Class;
  static CppClassType filechoosernative_class_;

protected:
  explicit FileChooserNative(const Glib::ConstructParams& construct_params);
  explicit FileChooserNative(GtkFileChooserNative* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  FileChooserNative(FileChooserNative&& src) noexcept;
  auto operator=(FileChooserNative&& src) noexcept -> FileChooserNative&;

  ~FileChooserNative() noexcept override;

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS


  static auto get_base_type() -> GType G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GObject.
  auto       gobj() -> GtkFileChooserNative*       { return reinterpret_cast<GtkFileChooserNative*>(gobject_); }

  ///Provides access to the underlying C GObject.
  auto gobj() const -> const GtkFileChooserNative* { return reinterpret_cast<GtkFileChooserNative*>(gobject_); }

  ///Provides access to the underlying C instance. The caller is responsible for unrefing it. Use when directly setting fields in structs.
  auto gobj_copy() -> GtkFileChooserNative*;

private:


protected:
  /** There is no create() method that corresponds to this constructor,
   * because this constructor shall only be used by derived classes.
   */
  FileChooserNative();

  /** Constructs a %FileChooserNative.
   */
  FileChooserNative(const Glib::ustring& title, Window& parent, FileChooser::Action action,
    const Glib::ustring& accept_label, const Glib::ustring& cancel_label);

  /** Constructs a %FileChooserNative.
   */
  FileChooserNative(const Glib::ustring& title, FileChooser::Action action,
    const Glib::ustring& accept_label, const Glib::ustring& cancel_label);


public:
  /** Creates a %FileChooserNative.
   *
   * @newin{3,24}
   *
   * @param title Title of the native.
   * @param parent Transient parent of the native.
   * @param action Open or save mode for the dialog.
   * @param accept_label Text to go in the accept button, or empty string for the default.
   * @param cancel_label Text to go in the cancel button, or empty string for the default.
   * @return A Glib::RefPtr to a new %FileChooserNative.
   */

  static auto create(const Glib::ustring& title, Window& parent, FileChooser::Action action, const Glib::ustring& accept_label =  {}, const Glib::ustring& cancel_label =  {}) -> Glib::RefPtr<FileChooserNative>;

  /// A create() convenience overload.
  static auto create(const Glib::ustring& title, FileChooser::Action action, const Glib::ustring& accept_label =  {}, const Glib::ustring& cancel_label =  {}) -> Glib::RefPtr<FileChooserNative>;


  /** Retrieves the custom label text for the accept button.
   *
   * @newin{3,24}
   *
   * @return The custom label.
   */
  auto get_accept_label() const -> Glib::ustring;

  /** Sets the custom label text for the accept button.
   *
   * If characters in @a label are preceded by an underscore, they are
   * underlined. If you need a literal underscore character in a label,
   * use “__” (two underscores). The first underlined character represents
   * a keyboard accelerator called a mnemonic.
   *
   * Pressing Alt and that key should activate the button.
   *
   * @newin{3,24}
   *
   * @param accept_label Custom label.
   */
  void set_accept_label(const Glib::ustring& accept_label =  {});

  /** Retrieves the custom label text for the cancel button.
   *
   * @newin{3,24}
   *
   * @return The custom label.
   */
  auto get_cancel_label() const -> Glib::ustring;

  /** Sets the custom label text for the cancel button.
   *
   * If characters in @a label are preceded by an underscore, they are
   * underlined. If you need a literal underscore character in a label,
   * use “__” (two underscores). The first underlined character represents
   * a keyboard accelerator called a mnemonic.
   *
   * Pressing Alt and that key should activate the button.
   *
   * @newin{3,24}
   *
   * @param cancel_label Custom label.
   */
  void set_cancel_label(const Glib::ustring& cancel_label =  {});

  /** The text used for the label on the accept button in the dialog, or
   * <tt>nullptr</tt> to use the default text.
   *
   * @newin{3,24}
   *
   * Default value: ""
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_accept_label() -> Glib::PropertyProxy< Glib::ustring > ;

/** The text used for the label on the accept button in the dialog, or
   * <tt>nullptr</tt> to use the default text.
   *
   * @newin{3,24}
   *
   * Default value: ""
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_accept_label() const -> Glib::PropertyProxy_ReadOnly< Glib::ustring >;

  /** The text used for the label on the cancel button in the dialog, or
   * <tt>nullptr</tt> to use the default text.
   *
   * @newin{3,24}
   *
   * Default value: ""
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_cancel_label() -> Glib::PropertyProxy< Glib::ustring > ;

/** The text used for the label on the cancel button in the dialog, or
   * <tt>nullptr</tt> to use the default text.
   *
   * @newin{3,24}
   *
   * Default value: ""
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_cancel_label() const -> Glib::PropertyProxy_ReadOnly< Glib::ustring >;


  // FileChooserNative has no signals


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
   * @relates Gtk::FileChooserNative
   */
  GTKMM_API
  auto wrap(GtkFileChooserNative* object, bool take_copy = false) -> Glib::RefPtr<Gtk::FileChooserNative>;
}


#endif /* _GTKMM_FILECHOOSERNATIVE_H */

