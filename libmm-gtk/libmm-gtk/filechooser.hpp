
#ifndef _GTKMM_FILECHOOSER_H
#define _GTKMM_FILECHOOSER_H


#include <mm/glib/ustring.hpp>
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

#include <vector>

#include <mm/gtk/widget.hpp>
#include <mm/gtk/filefilter.hpp>
#include <mm/gio/file.hpp>
#include <mm/gio/listmodel.hpp>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkFileChooser = struct _GtkFileChooser;
using GtkFileChooserClass = struct _GtkFileChooserClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{ class GTKMM_API FileChooser_Class; } // namespace Gtk
#endif // DOXYGEN_SHOULD_SKIP_THIS

namespace Gtk
{

//Note that GTK_FILE_SYSTEM_ERROR is not currently public GTK+ API and should
//never be instantiated by the GTK+ C API.

/**  %Exception class for Gdk::FileChooser errors.
 */
class FileChooserError : public Glib::Error
{
public:
  /**  @var Code NONEXISTENT
   * Indicates that a file does not exist.
   *
   *  @var Code BAD_FILENAME
   * Indicates a malformed filename.
   *
   *  @var Code ALREADY_EXISTS
   * Indicates a duplicate path (e.g. when
   * adding a bookmark).
   *
   *  @var Code INCOMPLETE_HOSTNAME
   * Indicates an incomplete hostname
   * (e.g. "http://foo" without a slash after that).
   *
   *  @enum Code
   *
   * These identify the various errors that can occur while calling
   * `Gtk::FileChooser` functions.
   */
  enum Code
  {
    NONEXISTENT,
    BAD_FILENAME,
    ALREADY_EXISTS,
    INCOMPLETE_HOSTNAME
  };

  GTKMM_API FileChooserError(Code error_code, const Glib::ustring& error_message);
  GTKMM_API explicit FileChooserError(GError* gobject);
  GTKMM_API auto code() const -> Code;

#ifndef DOXYGEN_SHOULD_SKIP_THIS
private:

  GTKMM_API static void throw_func(GError* gobject);

  friend GTKMM_API void wrap_init(); // uses throw_func()

  #endif //DOXYGEN_SHOULD_SKIP_THIS
};

} // namespace Gtk

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

template <>
class GTKMM_API Value<Gtk::FileChooserError::Code> : public Glib::Value_Enum<Gtk::FileChooserError::Code>
{
public:
  static auto value_type() -> GType G_GNUC_CONST;
};

} // namespace Glib
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

namespace Gtk
{


/** File chooser interface used by %Gtk::FileChooserWidget and %Gtk::FileChooserDialog.
 *
 * %Gtk::FileChooser is an interface that can be implemented by file selection
 * widgets. In gtkmm, the main objects that implement this interface are
 * FileChooserWidget and FileChooserDialog. You do not need to write an
 * object that implements the %FileChooser interface unless you are trying to
 * adapt an existing file selector to expose a standard programming interface.
 *
 * %Gtk::FileChooser allows for shortcuts to various places in the filesystem.
 * In the default implementation these are displayed in the left pane. It
 * may be a bit confusing at first that these shortcuts come from various
 * sources and in various flavours, so lets explain the terminology here:
 *
 * - Bookmarks: are created by the user, by dragging folders from the
 *   right pane to the left pane, or by using the “Add”. Bookmarks
 *   can be renamed and deleted by the user.
 *
 * - Shortcuts: can be provided by the application. For example, a Paint
 *   program may want to add a shortcut for a Clipart folder. Shortcuts
 *   cannot be modified by the user.
 *
 * - Volumes: are provided by the underlying filesystem abstraction. They are
 *   the “roots” of the filesystem.
 *
 * @par File Names
 * When the user is finished selecting files in a %Gtk::FileChooser,
 * your program can get the selected filenames as Gio::File objects.
 *
 * @par Adding Options
 * You can add extra widgets to a file chooser to provide options
 * that are not present in the default design, by using
 * add_choice(). Each choice has an identifier and
 * a user visible label; additionally, each choice can have multiple
 * options. If a choice has no option, it will be rendered as a
 * check button with the given label; if a choice has options, it will
 * be rendered as a combo box.
 */

class GTKMM_API FileChooser : public Glib::Interface
{

#ifndef DOXYGEN_SHOULD_SKIP_THIS

public:
  using CppObjectType = FileChooser;
  using CppClassType = FileChooser_Class;
  using BaseObjectType = GtkFileChooser;
  using BaseClassType = GtkFileChooserClass;

  // noncopyable
  FileChooser(const FileChooser&) = delete;
  auto operator=(const FileChooser&) -> FileChooser& = delete;

private:
  friend class FileChooser_Class;
  static CppClassType filechooser_class_;

#endif /* DOXYGEN_SHOULD_SKIP_THIS */
protected:
  /**
   * You should derive from this class to use it.
   */
  FileChooser();

#ifndef DOXYGEN_SHOULD_SKIP_THIS
  /** Called by constructors of derived classes. Provide the result of
   * the Class init() function to ensure that it is properly
   * initialized.
   *
   * @param interface_class The Class object for the derived type.
   */
  explicit FileChooser(const Glib::Interface_Class& interface_class);

public:
  // This is public so that C++ wrapper instances can be
  // created for C instances of unwrapped types.
  // For instance, if an unexpected C type implements the C interface.
  explicit FileChooser(GtkFileChooser* castitem);

protected:
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  FileChooser(FileChooser&& src) noexcept;
  auto operator=(FileChooser&& src) noexcept -> FileChooser&;

  ~FileChooser() noexcept override;

  static void add_interface(GType gtype_implementer);

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS
  static auto get_base_type() -> GType G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GObject.
  auto       gobj() -> GtkFileChooser*       { return reinterpret_cast<GtkFileChooser*>(gobject_); }

  ///Provides access to the underlying C GObject.
  auto gobj() const -> const GtkFileChooser* { return reinterpret_cast<GtkFileChooser*>(gobject_); }

private:

public:
  /** @addtogroup gtkmmEnums gtkmm Enums and Flags */

  /**
   *  @var Action OPEN
   * Indicates open mode.  The file chooser
   * will only let the user pick an existing file.
   *
   *  @var Action SAVE
   * Indicates save mode.  The file chooser
   * will let the user pick an existing file, or type in a new
   * filename.
   *
   *  @var Action SELECT_FOLDER
   * Indicates an Open mode for
   * selecting folders.  The file chooser will let the user pick an
   * existing folder.
   *
   *  @enum Action
   *
   * Describes whether a `Gtk::FileChooser` is being used to open existing files
   * or to save to a possibly new file.
   *
   * @ingroup gtkmmEnums
   */
  enum class Action
  {
    OPEN,
    SAVE,
    SELECT_FOLDER
  };


  /** Sets the type of operation that the chooser is performing.
   *
   * The user interface is adapted to suit the selected action.
   *
   * For example, an option to create a new folder might be shown
   * if the action is Gtk::FileChooser::Action::SAVE but not if the
   * action is Gtk::FileChooser::Action::OPEN.
   *
   * @param action The action that the file selector is performing.
   */
  void set_action(Action action);

  /** Gets the type of operation that the file chooser is performing.
   *
   * @return The action that the file selector is performing.
   */
  auto get_action() const -> Action;

  /** Sets whether multiple files can be selected in the file chooser.
   *
   * This is only relevant if the action is set to be
   * Gtk::FileChooser::Action::OPEN or
   * Gtk::FileChooser::Action::SELECT_FOLDER.
   *
   * @param select_multiple <tt>true</tt> if multiple files can be selected.
   */
  void set_select_multiple(bool select_multiple =  true);

  /** Gets whether multiple files can be selected in the file
   * chooser.
   *
   * @return <tt>true</tt> if multiple files can be selected.
   */
  auto get_select_multiple() const -> bool;


  /** Sets whether file chooser will offer to create new folders.
   *
   * This is only relevant if the action is not set to be
   * Gtk::FileChooser::Action::OPEN.
   *
   * @param create_folders <tt>true</tt> if the Create Folder button should be displayed.
   */
  void set_create_folders(bool create_folders =  true);

  /** Gets whether file chooser will offer to create new folders.
   *
   * @return <tt>true</tt> if the Create Folder button should be displayed.
   */
  auto get_create_folders() const -> bool;


  /** Sets the current name in the file selector, as if entered
   * by the user.
   *
   * Note that the name passed in here is a UTF-8 string rather
   * than a filename. This function is meant for such uses as a
   * suggested name in a “Save As...” dialog.  You can pass
   * “Untitled.doc” or a similarly suitable suggestion for the @a name.
   *
   * If you want to preselect a particular existing file, you should
   * use set_file() instead.
   *
   * Please see the documentation for those functions for an example
   * of using set_current_name() as well.
   *
   * @param name The filename to use, as a UTF-8 string.
   */
  void set_current_name(const Glib::ustring& name);

  /** Gets the current name in the file selector, as entered by the user.
   *
   * This is meant to be used in save dialogs, to get the currently typed
   * filename when the file itself does not exist yet.
   *
   * @return The raw text from the file chooser’s “Name” entry. Note that this string is not a full pathname or URI; it is
   * whatever the contents of the entry are. Note also that this string is
   * in UTF-8 encoding, which is not necessarily the system’s encoding for
   * filenames.
   */
  auto get_current_name() const -> Glib::ustring;


  /** Sets @a file as the current filename for the file chooser.
   *
   * This includes changing to the file’s parent folder and actually selecting
   * the file in list. If the @a chooser is in Gtk::FileChooser::Action::SAVE mode,
   * the file’s base name will also appear in the dialog’s file name entry.
   *
   * If the file name isn’t in the current folder of @a chooser, then the current
   * folder of @a chooser will be changed to the folder containing @a file.
   *
   * Note that the file must exist, or nothing will be done except
   * for the directory change.
   *
   * If you are implementing a save dialog, you should use this function if
   * you already have a file name to which the user may save; for example,
   * when the user opens an existing file and then does “Save As…”. If you
   * don’t have a file name already — for example, if the user just created
   * a new file and is saving it for the first time, do not call this function.
   *
   * Instead, use something similar to this:
   *
   *
   * [C example ellipted]
   *
   * @param file The `Gio::File` to set as current.
   * @return Not useful.
   *
   * @throws Glib::Error
   */
  auto set_file(const Glib::RefPtr<const Gio::File>& file) -> bool;

  //No refreturn is needed here, because the C function provides a reference:

  /** Lists all the selected files and subfolders in the current folder
   * of @a chooser as `Gio::File`.
   *
   * @return A list model containing a `Gio::File` for each
   * selected file and subfolder in the current folder. Free the returned
   * list with Glib::object_unref().
   */
  auto get_files() -> Glib::RefPtr<Gio::ListModel>;

  /** Lists all the selected files and subfolders in the current folder
   * of @a chooser as `Gio::File`.
   *
   * @return A list model containing a `Gio::File` for each
   * selected file and subfolder in the current folder. Free the returned
   * list with Glib::object_unref().
   */
  auto get_files() const -> Glib::RefPtr<const Gio::ListModel>;


  /** Sets the current folder for @a chooser from a `Gio::File`.
   *
   * @param file The `Gio::File` for the new folder.
   * @return <tt>true</tt> if the folder could be changed successfully, <tt>false</tt>
   * otherwise.
   *
   * @throws Glib::Error
   */
  auto set_current_folder(const Glib::RefPtr<const Gio::File>& file) -> bool;

  //No refreturn is needed here, because the C function provides a reference:

  /** Gets the current folder of @a chooser as `Gio::File`.
   *
   * @return The full path of the current folder, possibly empty if the current
   * path cannot be represented as a local filename.  This function may also return
   * an empty string if the file chooser was unable to load the last folder that was
   * requested from it; for example, as would be for calling
   * set_current_folder() on a nonexistent folder.
   */
  auto get_current_folder() -> Glib::RefPtr<Gio::File>;

  /** Gets the current folder of @a chooser as `Gio::File`.
   *
   * @return The full path of the current folder, possibly empty if the current
   * path cannot be represented as a local filename.  This function may also return
   * an empty string if the file chooser was unable to load the last folder that was
   * requested from it; for example, as would be for calling
   * set_current_folder() on a nonexistent folder.
   */
  auto get_current_folder() const -> Glib::RefPtr<const Gio::File>;

  //No refreturn is needed here, because the C function provides a reference:

  /** Gets the `Gio::File` for the currently selected file in
   * the file selector.
   *
   * If multiple files are selected, one of the files will be
   * returned at random.
   *
   * If the file chooser is in folder mode, this function returns
   * the selected folder.
   *
   * @return A selected `Gio::File`. You own the
   * returned file; use Glib::object_unref() to release it.
   */
  auto get_file() -> Glib::RefPtr<Gio::File>;

  /** Gets the `Gio::File` for the currently selected file in
   * the file selector.
   *
   * If multiple files are selected, one of the files will be
   * returned at random.
   *
   * If the file chooser is in folder mode, this function returns
   * the selected folder.
   *
   * @return A selected `Gio::File`. You own the
   * returned file; use Glib::object_unref() to release it.
   */
  auto get_file() const -> Glib::RefPtr<const Gio::File>;

/* List of user selectable filters
 */

  /** Adds @a filter to the list of filters that the user can select between.
   *
   * When a filter is selected, only files that are passed by that
   * filter are displayed.
   *
   * Note that the @a chooser takes ownership of the filter if it is floating,
   * so you have to ref and sink it if you want to keep a reference.
   *
   * @param filter A `Gtk::FileFilter`.
   */
  void add_filter(const Glib::RefPtr<FileFilter>& filter);

  /** Removes @a filter from the list of filters that the user can select between.
   *
   * @param filter A `Gtk::FileFilter`.
   */
  void remove_filter(const Glib::RefPtr<FileFilter>& filter);

  //No refreturn is needed here, because the C function provides a reference:

  /** Gets the current set of user-selectable filters, as a list model.
   *
   * See add_filter() and
   * remove_filter() for changing individual filters.
   *
   * You should not modify the returned list model. Future changes to
   *  @a chooser may or may not affect the returned model.
   *
   * @return A `Gio::ListModel` containing the current set
   * of user-selectable filters.
   */
  auto get_filters() const -> Glib::RefPtr<const Gio::ListModel>;

/* Current filter
 */

  /** Sets the current filter.
   *
   * Only the files that pass the filter will be displayed.
   * If the user-selectable list of filters is non-empty, then
   * the filter should be one of the filters in that list.
   *
   * Setting the current filter when the list of filters is
   * empty is useful if you want to restrict the displayed
   * set of files without letting the user change it.
   *
   * @param filter A `Gtk::FileFilter`.
   */
  void set_filter(const Glib::RefPtr<FileFilter>& filter);

  /** Gets the current filter.
   *
   * @return The current filter.
   */
  auto get_filter() -> Glib::RefPtr<FileFilter>;

  /** Gets the current filter.
   *
   * @return The current filter.
   */
  auto get_filter() const -> Glib::RefPtr<const FileFilter>;

/* Per-application shortcut folders */


  /** Adds a folder to be displayed with the shortcut folders
   * in a file chooser.
   *
   * @param folder A `Gio::File` for the folder to add.
   * @return <tt>true</tt> if the folder could be added successfully,
   * <tt>false</tt> otherwise.
   *
   * @throws Glib::Error
   */
  auto add_shortcut_folder(const Glib::RefPtr<Gio::File>& folder) -> bool;

  /** Removes a folder from the shortcut folders in a file chooser.
   *
   * @param folder A `Gio::File` for the folder to remove.
   * @return <tt>true</tt> if the folder could be removed successfully,
   * <tt>false</tt> otherwise.
   *
   * @throws Glib::Error
   */
  auto remove_shortcut_folder(const Glib::RefPtr<Gio::File>& folder) -> bool;

  //No refreturn is needed here, because the C function provides a reference:

  /** Queries the list of shortcut folders in the file chooser.
   *
   * You should not modify the returned list model. Future changes to
   *  @a chooser may or may not affect the returned model.
   *
   * @return A list model of `Gio::File`s.
   */
  auto get_shortcut_folders() const -> Glib::RefPtr<const Gio::ListModel>;


  /** Adds a 'choice' to the file chooser.
   *
   * This is typically implemented as a combobox or, for boolean choices,
   * as a checkbutton. You can select a value using
   * set_choice() before the dialog is shown,
   * and you can obtain the user-selected value in the
   * Gtk::Dialog::signal_response() signal handler using
   * get_choice().
   *
   * @param id Id for the added choice.
   * @param label User-visible label for the added choice.
   * @param options Ids for the options of the choice, or <tt>nullptr</tt> for a boolean choice.
   * @param option_labels User-visible labels for the options, must be the same length as @a options.
   */
  void add_choice(const Glib::ustring& id, const Glib::ustring& label, const std::vector<Glib::ustring>& options, const std::vector<Glib::ustring>& option_labels);

  /** Adds a boolean 'choice' to the file chooser.
   * This is typically implemented as a checkbutton. You can select
   * a value using set_boolean_choice() before the dialog is shown,
   * and you can obtain the user-selected value in the signal_response() signal handler
   * using get_choice().
   *
   * Compare set_extra_widget().
   *
   * @newin{3,22}
   *
   * @param id Id for the added choice.
   * @param label User-visible label for the added choice.
   */
  void add_choice(const Glib::ustring& id, const Glib::ustring& label);


  /** Removes a 'choice' that has been added with add_choice().
   *
   * @param id The ID of the choice to remove.
   */
  void remove_choice(const Glib::ustring& id);

  /** Selects an option in a 'choice' that has been added with
   * add_choice().
   *
   * For a boolean choice, the possible options are "true" and "false".
   *
   * @param id The ID of the choice to set.
   * @param option The ID of the option to select.
   */
  void set_choice(const Glib::ustring& id, const Glib::ustring& option);

  /** Gets the currently selected option in the 'choice' with the given ID.
   *
   * @param id The ID of the choice to get.
   * @return The ID of the currently selected option.
   */
  auto get_choice(const Glib::ustring& id) const -> Glib::ustring;

  /** The type of operation that the file chooser is performing.
   *
   * Default value: Gtk::FileChooser::Action::OPEN
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_action() -> Glib::PropertyProxy< Action > ;

/** The type of operation that the file chooser is performing.
   *
   * Default value: Gtk::FileChooser::Action::OPEN
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_action() const -> Glib::PropertyProxy_ReadOnly< Action >;

  /** The current filter for selecting files that are displayed.
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_filter() -> Glib::PropertyProxy< Glib::RefPtr<FileFilter> > ;

/** The current filter for selecting files that are displayed.
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_filter() const -> Glib::PropertyProxy_ReadOnly< Glib::RefPtr<FileFilter> >;

  /** Whether to allow multiple files to be selected.
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_select_multiple() -> Glib::PropertyProxy< bool > ;

/** Whether to allow multiple files to be selected.
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_select_multiple() const -> Glib::PropertyProxy_ReadOnly< bool >;

  /** A `Gio::ListModel` containing the filters that have been
   * added with Gtk::FileChooser::add_filter().
   *
   * The returned object should not be modified. It may
   * or may not be updated for later changes.
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_filters() const -> Glib::PropertyProxy_ReadOnly< Glib::RefPtr<Gio::ListModel> >;


  /** A `Gio::ListModel` containing the shortcut folders that have been
   * added with Gtk::FileChooser::add_shortcut_folder().
   *
   * The returned object should not be modified. It may
   * or may not be updated for later changes.
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_shortcut_folders() const -> Glib::PropertyProxy_ReadOnly< Glib::RefPtr<Gio::ListModel> >;


  /** Whether a file chooser not in Gtk::FileChooser::Action::OPEN mode
   * will offer the user to create new folders.
   *
   * Default value: <tt>true</tt>
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_create_folders() -> Glib::PropertyProxy< bool > ;

/** Whether a file chooser not in Gtk::FileChooser::Action::OPEN mode
   * will offer the user to create new folders.
   *
   * Default value: <tt>true</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_create_folders() const -> Glib::PropertyProxy_ReadOnly< bool >;


public:

public:
  //C++ methods used to invoke GTK+ virtual functions:

protected:
  //GTK+ Virtual Functions (override these to change behaviour):

  //Default Signal Handlers::


};

} // namespace Gtk


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

template <>
class GTKMM_API Value<Gtk::FileChooser::Action> : public Glib::Value_Enum<Gtk::FileChooser::Action>
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
   * @relates Gtk::FileChooser
   */
  GTKMM_API
  auto wrap(GtkFileChooser* object, bool take_copy = false) -> Glib::RefPtr<Gtk::FileChooser>;

} // namespace Glib


#endif /* _GTKMM_FILECHOOSER_H */

