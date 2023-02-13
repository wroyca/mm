
#ifndef _GTKMM_DIRECTORYLIST_H
#define _GTKMM_DIRECTORYLIST_H

#include <libmm-gtk/mm-gtkconfig.hxx>


#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

/* Copyright (C) 2020 The gtkmm Development Team
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


#include <libmm-gio/listmodel.hxx>
#include <libmm-gio/file.hxx>
#include <gtk/gtk.h>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{ class GTKMM_API DirectoryList_Class; } // namespace Gtk
#endif //DOXYGEN_SHOULD_SKIP_THIS

namespace Gtk
{

/** A list model for directory listings.
 *
 * %Gtk::DirectoryList is a list model that wraps Gio::File::enumerate_children_async().
 * It presents a Gio::ListModel and fills it asynchronously with the Gio::FileInfo%s
 * returned from that function.
 *
 * Enumeration will start automatically when the property_file() property
 * is set.
 *
 * While the %Gtk::DirectoryList is being filled, the property_loading()
 * property will be set to <tt>true</tt>. You can listen to that property if you want
 * to show information like a Gtk::Spinner or a "Loading..." text.
 *
 * If loading fails at any point, the property_error() property will be
 * set to give more indication about the failure.
 *
 * The Gio::FileInfo%s returned from a %Gtk::DirectoryList have the "standard::file"
 * attribute set to the Gio::File they refer to. This way you can get at the file
 * that is referred to in the same way you would via Gio::File::enumerator_get_child().
 * This means you do not need access to the %Gtk::DirectoryList but can access
 * the Gio::File directly from the Gio::FileInfo when operating with a Gtk::ListView
 * or similar.
 *
 * @see Gio::ListModel, Gio::File::enumerate_children()
 * @newin{3,98}
 */

class GTKMM_API DirectoryList : public Glib::Object, public Gio::ListModel
{

#ifndef DOXYGEN_SHOULD_SKIP_THIS

public:
  using CppObjectType = DirectoryList;
  using CppClassType = DirectoryList_Class;
  using BaseObjectType = GtkDirectoryList;
  using BaseClassType = GtkDirectoryListClass;

  // noncopyable
  DirectoryList(const DirectoryList&) = delete;
  auto operator=(const DirectoryList&) -> DirectoryList& = delete;

private:  friend class DirectoryList_Class;
  static CppClassType directorylist_class_;

protected:
  explicit DirectoryList(const Glib::ConstructParams& construct_params);
  explicit DirectoryList(GtkDirectoryList* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  DirectoryList(DirectoryList&& src) noexcept;
  auto operator=(DirectoryList&& src) noexcept -> DirectoryList&;

  ~DirectoryList() noexcept override;

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS


  static auto get_base_type() -> GType G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GObject.
  auto       gobj() -> GtkDirectoryList*       { return reinterpret_cast<GtkDirectoryList*>(gobject_); }

  ///Provides access to the underlying C GObject.
  auto gobj() const -> const GtkDirectoryList* { return reinterpret_cast<GtkDirectoryList*>(gobject_); }

  ///Provides access to the underlying C instance. The caller is responsible for unrefing it. Use when directly setting fields in structs.
  auto gobj_copy() -> GtkDirectoryList*;

private:


protected:
    explicit DirectoryList(const std::string& attributes, const Glib::RefPtr<Gio::File>& file =  {});


public:

  static auto create(const std::string& attributes, const Glib::RefPtr<Gio::File>& file =  {}) -> Glib::RefPtr<DirectoryList>;


  /** Sets the @a file to be enumerated and starts the enumeration.
   *
   * If @a file is <tt>nullptr</tt>, the result will be an empty list.
   *
   * @param file The `Gio::File` to be enumerated.
   */
  void set_file(const Glib::RefPtr<Gio::File>& file);

  /** Gets the file whose children are currently enumerated.
   *
   * @return The file whose children are enumerated.
   */
  auto get_file() -> Glib::RefPtr<Gio::File>;

  /** Gets the file whose children are currently enumerated.
   *
   * @return The file whose children are enumerated.
   */
  auto get_file() const -> Glib::RefPtr<const Gio::File>;

  /** Sets the @a attributes to be enumerated and starts the enumeration.
   *
   * If @a attributes is <tt>nullptr</tt>, no attributes will be queried, but a list
   * of `Gio::FileInfo`s will still be created.
   *
   * @param attributes The attributes to enumerate.
   */
  void set_attributes(const std::string& attributes);

  /** Gets the attributes queried on the children.
   *
   * @return The queried attributes.
   */
  auto get_attributes() const -> std::string;

  /** Sets the IO priority to use while loading directories.
   *
   * Setting the priority while @a self is loading will reprioritize the
   * ongoing load as soon as possible.
   *
   * The default IO priority is Glib::PRIORITY_DEFAULT, which is higher than
   * the GTK redraw priority. If you are loading a lot of directories in
   * parallel, lowering it to something like Glib::PRIORITY_DEFAULT_IDLE
   * may increase responsiveness.
   *
   * @param io_priority IO priority to use.
   */
  void set_io_priority(int io_priority);

  /** Gets the IO priority set via set_io_priority().
   *
   * @return The IO priority.
   */
  auto get_io_priority() const -> int;


  /** Returns <tt>true</tt> if the children enumeration is currently in
   * progress.
   *
   * Files will be added to @a self from time to time while loading is
   * going on. The order in which are added is undefined and may change
   * in between runs.
   *
   * @return <tt>true</tt> if @a self is loading.
   */
  auto is_loading() const -> bool;


  /** Gets the loading error, if any.
   *
   * If an error occurs during the loading process, the loading process
   * will finish and this property allows querying the error that happened.
   * This error will persist until a file is loaded again.
   *
   * An error being set does not mean that no files were loaded, and all
   * successfully queried files will remain in the list.
   *
   * @return The loading error or <tt>nullptr</tt> if
   * loading finished successfully.
   */
  auto get_error() const -> Glib::Error;


  /** Sets whether the directory list will monitor the directory
   * for changes.
   *
   * If monitoring is enabled, the signal_items_changed() signal will
   * be emitted when the directory contents change.
   *
   *
   * When monitoring is turned on after the initial creation
   * of the directory list, the directory is reloaded to avoid
   * missing files that appeared between the initial loading
   * and when monitoring was turned on.
   *
   * @param monitored <tt>true</tt> to monitor the directory for changes.
   */
  void set_monitored(bool monitored =  true);

  /** Returns whether the directory list is monitoring
   * the directory for changes.
   *
   * @return <tt>true</tt> if the directory is monitored.
   */
  auto get_monitored() const -> bool;

  /** The attributes to query.
   *
   * Default value: ""
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_attributes() -> Glib::PropertyProxy< std::string > ;

/** The attributes to query.
   *
   * Default value: ""
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_attributes() const -> Glib::PropertyProxy_ReadOnly< std::string >;

  /** Error encountered while loading files.
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_error() const -> Glib::PropertyProxy_ReadOnly< Glib::Error >;


  /** File to query.
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_file() -> Glib::PropertyProxy< Glib::RefPtr<Gio::File> > ;

/** File to query.
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_file() const -> Glib::PropertyProxy_ReadOnly< Glib::RefPtr<Gio::File> >;

  /** Priority used when loading.
   *
   * Default value: 0
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_io_priority() -> Glib::PropertyProxy< int > ;

/** Priority used when loading.
   *
   * Default value: 0
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_io_priority() const -> Glib::PropertyProxy_ReadOnly< int >;

  /** The type of items. See Gio::ListModel::get_item_type().
   *
   * @newin{4,8}
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_item_type() const -> Glib::PropertyProxy_ReadOnly< GType >;


  /** <tt>true</tt> if files are being loaded.
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_loading() const -> Glib::PropertyProxy_ReadOnly< bool >;


  /** <tt>true</tt> if the directory is monitored for changed.
   *
   * Default value: <tt>true</tt>
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_monitored() -> Glib::PropertyProxy< bool > ;

/** <tt>true</tt> if the directory is monitored for changed.
   *
   * Default value: <tt>true</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_monitored() const -> Glib::PropertyProxy_ReadOnly< bool >;

  /** The number of items. See Gio::ListModel::get_n_items().
   *
   * @newin{4,8}
   *
   * Default value: 0
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_n_items() const -> Glib::PropertyProxy_ReadOnly< unsigned int >;


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
   * @relates Gtk::DirectoryList
   */
  GTKMM_API
  auto wrap(GtkDirectoryList* object, bool take_copy = false) -> Glib::RefPtr<Gtk::DirectoryList>;
}


#endif /* _GTKMM_DIRECTORYLIST_H */

