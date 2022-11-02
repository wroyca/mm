// Generated by gmmproc 2.74.0 -- DO NOT MODIFY!
#ifndef _GTKMM_RECENTMANAGER_H
#define _GTKMM_RECENTMANAGER_H

#include <mm/gtk/mm-gtkconfig.hpp>


#include <mm/glib/ustring.hpp>
#include <sigc++/sigc++.h>

/* Copyright (C) 2006 The gtkmm Development Team
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
#include <mm/gdk/pixbuf.hpp>
#include <mm/gtk/recentinfo.hpp>
#include <mm/glib/object.hpp>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkRecentManager = struct _GtkRecentManager;
using GtkRecentManagerClass = struct _GtkRecentManagerClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{ class GTKMM_API RecentManager_Class; } // namespace Gtk
#endif //DOXYGEN_SHOULD_SKIP_THIS

namespace Gtk
{

/**  %Exception class for Gtk::RecentManager errors.
 */
class RecentManagerError : public Glib::Error
{
public:
  /**  @var Code NOT_FOUND
   * The URI specified does not exists in
   * the recently used resources list.
   *
   *  @var Code INVALID_URI
   * The URI specified is not valid.
   *
   *  @var Code INVALID_ENCODING
   * The supplied string is not
   * UTF-8 encoded.
   *
   *  @var Code NOT_REGISTERED
   * No application has registered
   * the specified item.
   *
   *  @var Code READ
   * Failure while reading the recently used
   * resources file.
   *
   *  @var Code WRITE
   * Failure while writing the recently used
   * resources file.
   *
   *  @var Code UNKNOWN
   * Unspecified error.
   *
   *  @enum Code
   *
   * %Error codes for `Gtk::RecentManager` operations
   */
  enum Code
  {
    NOT_FOUND,
    INVALID_URI,
    INVALID_ENCODING,
    NOT_REGISTERED,
    READ,
    WRITE,
    UNKNOWN
  };

  GTKMM_API RecentManagerError(Code error_code, const Glib::ustring& error_message);
  GTKMM_API explicit RecentManagerError(GError* gobject);
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
class GTKMM_API Value<Gtk::RecentManagerError::Code> : public Glib::Value_Enum<Gtk::RecentManagerError::Code>
{
public:
  static auto value_type() -> GType G_GNUC_CONST;
};

} // namespace Glib
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

namespace Gtk
{


/** @defgroup RecentFiles RecentFiles
 */

/** RecentManager provides a facility for adding, removing and
 * looking up recently used files.  Each recently used file is
 * identified by its URI, and has meta-data associated to it, like
 * the names and command lines of the applications that have
 * registered it, the number of time each application has registered
 * the same file, the mime type of the file and whether the file
 * should be displayed only by the applications that have
 * registered it.
 *
 * The RecentManager acts like a database of all the recently
 * used files.  You can create new RecentManager objects, but
 * it is more efficient to use the default manager created by GTK+.
 *
 * @newin{2,10}
 *
 * @ingroup RecentFiles
 */

class GTKMM_API RecentManager : public Glib::Object
{

#ifndef DOXYGEN_SHOULD_SKIP_THIS

public:
  using CppObjectType = RecentManager;
  using CppClassType = RecentManager_Class;
  using BaseObjectType = GtkRecentManager;
  using BaseClassType = GtkRecentManagerClass;

  // noncopyable
  RecentManager(const RecentManager&) = delete;
  auto operator=(const RecentManager&) -> RecentManager& = delete;

private:  friend class RecentManager_Class;
  static CppClassType recentmanager_class_;

protected:
  explicit RecentManager(const Glib::ConstructParams& construct_params);
  explicit RecentManager(GtkRecentManager* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  RecentManager(RecentManager&& src) noexcept;
  auto operator=(RecentManager&& src) noexcept -> RecentManager&;

  ~RecentManager() noexcept override;

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS


  static auto get_base_type() -> GType G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GObject.
  auto       gobj() -> GtkRecentManager*       { return reinterpret_cast<GtkRecentManager*>(gobject_); }

  ///Provides access to the underlying C GObject.
  auto gobj() const -> const GtkRecentManager* { return reinterpret_cast<GtkRecentManager*>(gobject_); }

  ///Provides access to the underlying C instance. The caller is responsible for unrefing it. Use when directly setting fields in structs.
  auto gobj_copy() -> GtkRecentManager*;

private:


protected:
  RecentManager();

public:

  static auto create() -> Glib::RefPtr<RecentManager>;


  /** Gets a unique instance of `Gtk::RecentManager` that you can share
   * in your application without caring about memory management.
   *
   * @return A unique `Gtk::RecentManager`. Do not ref or
   * unref it.
   */
  static auto get_default() -> Glib::RefPtr<RecentManager>;

  /** Meta-data passed to add_item().  You should
   * use RecentManager::Data if you want to control the meta-data associated
   * to an entry of the recently used files list when you are adding
   * a new file to it.
   *
   * - display_name: the string to be used when displaying the file inside a RecentChooser
   * - description: a user readable description of the file
   * - mime_type: the mime type of the file
   * - app_name: the name of the application that is registering the file
   * - app_exec: the command line that should be used when launching the file
   * - groups: the list of group names to which the file belongs to
   * - is_private: whether the file should be displayed only by the applications that have registered it
  */
  class Data
  {
  public:
    Glib::ustring display_name;
    Glib::ustring description;

    Glib::ustring mime_type;

    Glib::ustring app_name;
    Glib::ustring app_exec;

    std::vector<Glib::ustring> groups;

    bool is_private;
  };


  /** Adds a new resource into the recently used resources list. This function
   * will try and guess some of the meta-data associated to a URI. If you
   * know some of meta-data about the document yourself, set the desired
   * fields of a RecentManager::Data structure and pass it to add_item().
   */
  auto add_item(const Glib::ustring& uri) -> bool;

  /** Adds a new resource into the recently used resources list, taking
   * meta data from the given Data instead of guessing it from the URI.
   */
  auto add_item(const Glib::ustring& uri, const Data& recent_data) -> bool;


  /** Removes a resource pointed by @a uri from the recently used resources
   * list handled by a recent manager.
   *
   * @param uri The URI of the item you wish to remove.
   * @return <tt>true</tt> if the item pointed by @a uri has been successfully
   * removed by the recently used resources list, and <tt>false</tt> otherwise.
   *
   * @throws Glib::Error
   */
  auto remove_item(const Glib::ustring& uri) -> bool;

  /** Searches for a URI inside the recently used resources list, and
   * returns a `Gtk::RecentInfo` containing information about the resource
   * like its MIME type, or its display name.
   *
   * @param uri A URI.
   * @return A `Gtk::RecentInfo` containing information
   * about the resource pointed by @a uri, or <tt>nullptr</tt> if the URI was
   * not registered in the recently used resources list. Free with
   * Gtk::RecentInfo::unref().
   *
   * @throws Glib::Error
   */
  auto lookup_item(const Glib::ustring& uri) -> Glib::RefPtr<RecentInfo>;

  /** Searches for a URI inside the recently used resources list, and
   * returns a `Gtk::RecentInfo` containing information about the resource
   * like its MIME type, or its display name.
   *
   * @param uri A URI.
   * @return A `Gtk::RecentInfo` containing information
   * about the resource pointed by @a uri, or <tt>nullptr</tt> if the URI was
   * not registered in the recently used resources list. Free with
   * Gtk::RecentInfo::unref().
   *
   * @throws Glib::Error
   */
  auto lookup_item(const Glib::ustring& uri) const -> Glib::RefPtr<const RecentInfo>;

  /** Checks whether there is a recently used resource registered
   * with @a uri inside the recent manager.
   *
   * @param uri A URI.
   * @return <tt>true</tt> if the resource was found, <tt>false</tt> otherwise.
   */
  auto has_item(const Glib::ustring& uri) const -> bool;

  /** Changes the location of a recently used resource from @a uri to @a new_uri.
   *
   * Please note that this function will not affect the resource pointed
   * by the URIs, but only the URI used in the recently used resources list.
   *
   * @param uri The URI of a recently used resource.
   * @param new_uri The new URI of the recently used resource, or
   * <tt>nullptr</tt> to remove the item pointed by @a uri in the list.
   * @return <tt>true</tt> on success.
   *
   * @throws Glib::Error
   */
  auto move_item(const Glib::ustring& uri, const Glib::ustring& new_uri) -> bool;


  /** Gets the list of recently used resources.
   *
   * @return A list of
   * newly allocated `GtkRecentInfo objects`. Use
   * [method @a Gtk.RecentInfo.
   */
  auto get_items() const -> std::vector<Glib::RefPtr<RecentInfo> >;


  /** Purges every item from the recently used resources list.
   *
   * @return The number of items that have been removed from the
   * recently used resources list.
   *
   * @throws Glib::Error
   */
  auto purge_items() -> int;


  /**
   * @par Slot Prototype:
   * <tt>void on_my_%changed()</tt>
   *
   * Flags: Run First
   *
   * Emitted when the current recently used resources manager changes
   * its contents.
   *
   * This can happen either by calling Gtk::RecentManager::add_item()
   * or by another application.
   */

  auto signal_changed() -> Glib::SignalProxy<void()>;


  /** The full path to the file to be used to store and read the
   * recently used resources list
   *
   * Default value: ""
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_filename() const -> Glib::PropertyProxy_ReadOnly< Glib::ustring >;


  /** The size of the recently used resources list.
   *
   * Default value: 0
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_size() const -> Glib::PropertyProxy_ReadOnly< int >;


public:

public:
  //C++ methods used to invoke GTK+ virtual functions:

protected:
  //GTK+ Virtual Functions (override these to change behaviour):

  //Default Signal Handlers::
  /// This is a default handler for the signal signal_changed().
  virtual void on_changed();


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
   * @relates Gtk::RecentManager
   */
  GTKMM_API
  auto wrap(GtkRecentManager* object, bool take_copy = false) -> Glib::RefPtr<Gtk::RecentManager>;
}


#endif /* _GTKMM_RECENTMANAGER_H */

