
#ifndef _GTKMM_RECENTINFO_H
#define _GTKMM_RECENTINFO_H

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

#include <mm/gio/icon.hpp>
#include <mm/gio/appinfo.hpp>
#include <mm/glib/datetime.hpp>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
extern "C"
{
typedef struct _GtkRecentInfo GtkRecentInfo;
void gtk_recent_info_unref(GtkRecentInfo* info);
}
#endif /* !DOXYGEN_SHOULD_SKIP_THIS */

namespace Gtk
{

/** Contains information found when looking up an entry of the
 * recently used files list.
 *
 * @newin{2,10}
 *
 * @ingroup RecentFiles
 */
class GTKMM_API RecentInfo final
{
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  using CppObjectType = RecentInfo;
  using BaseObjectType = GtkRecentInfo;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


  /** Increment the reference count for this object.
   * You should never need to do this manually - use the object via a RefPtr instead.
   */
  void reference()   const;

  /** Decrement the reference count for this object.
   * You should never need to do this manually - use the object via a RefPtr instead.
   */
  void unreference() const;

  ///Provides access to the underlying C instance.
  auto       gobj() -> GtkRecentInfo*;

  ///Provides access to the underlying C instance.
  auto gobj() const -> const GtkRecentInfo*;

  ///Provides access to the underlying C instance. The caller is responsible for unrefing it. Use when directly setting fields in structs.
  auto gobj_copy() const -> GtkRecentInfo*;

  RecentInfo() = delete;

  // noncopyable
  RecentInfo(const RecentInfo&) = delete;
  auto operator=(const RecentInfo&) -> RecentInfo& = delete;

protected:
  // Do not derive this.  Gtk::RecentInfo can neither be constructed nor deleted.

  void operator delete(void*, std::size_t);

private:


public:


  /** Gets the URI of the resource.
   *
   * @return The URI of the resource. The returned string is
   * owned by the recent manager, and should not be freed.
   */
  auto get_uri() const -> Glib::ustring;

  /** Gets the name of the resource.
   *
   * If none has been defined, the basename
   * of the resource is obtained.
   *
   * @return The display name of the resource. The returned string
   * is owned by the recent manager, and should not be freed.
   */
  auto get_display_name() const -> Glib::ustring;

  /** Gets the (short) description of the resource.
   *
   * @return The description of the resource. The returned string
   * is owned by the recent manager, and should not be freed.
   */
  auto get_description() const -> Glib::ustring;

  /** Gets the MIME type of the resource.
   *
   * @return The MIME type of the resource. The returned string
   * is owned by the recent manager, and should not be freed.
   */
  auto get_mime_type() const -> Glib::ustring;


  /** Gets the time when the resource
   * was added to the recently used resources list.
   *
   * @return A `Glib::DateTime` for the time
   * when the resource was added.
   */
  auto get_added() const -> Glib::DateTime;

  /** Gets the time when the meta-data
   * for the resource was last modified.
   *
   * @return A `Glib::DateTime` for the time
   * when the resource was last modified.
   */
  auto get_modified() const -> Glib::DateTime;

  /** Gets the time when the meta-data
   * for the resource was last visited.
   *
   * @return A `Glib::DateTime` for the time
   * when the resource was last visited.
   */
  auto get_visited() const -> Glib::DateTime;


  /** Gets the value of the “private” flag.
   *
   * Resources in the recently used list that have this flag
   * set to <tt>true</tt> should only be displayed by the applications
   * that have registered them.
   *
   * @return <tt>true</tt> if the private flag was found, <tt>false</tt> otherwise.
   */
  auto get_private_hint() const -> bool;


  /** Creates a `Gio::AppInfo` for the specified `Gtk::RecentInfo`
   *
   * In case of error, @a error will be set either with a
   * GTK_RECENT_MANAGER_ERROR or a G_IO_ERROR
   *
   * @param app_name The name of the application that should
   * be mapped to a `Gio::AppInfo`; if <tt>nullptr</tt> is used then the default
   * application for the MIME type is used.
   * @return The newly created `Gio::AppInfo`.
   *
   * @throws Glib::Error
   */
  auto create_app_info(const Glib::ustring& app_name) -> Glib::RefPtr<Gio::AppInfo>;


  /** Gets the data regarding the application that has registered the resource
   * pointed by @a info.
   *
   * If the command line contains any escape characters defined inside the
   * storage specification, they will be expanded.
   *
   * @param app_name The name of the application that has registered this item.
   * @param app_exec Return location for the string containing
   * the command line.
   * @param count Return location for the number of times this item was registered.
   * @param stamp Return location for the time this item was last
   * registered for this application.
   * @return <tt>true</tt> if an application with @a app_name has registered this
   * resource inside the recently used list, or <tt>false</tt> otherwise. The
   *  @a app_exec string is owned by the `Gtk::RecentInfo` and should not be
   * modified or freed.
   */

  auto get_application_info(const Glib::ustring& app_name, std::string& app_exec,
                            guint& count, Glib::DateTime& stamp) const -> bool;


  /** Retrieves the list of applications that have registered this resource.
   *
   * @param length Return location for the length of the returned list.
   * @return A newly
   * allocated <tt>nullptr</tt>-terminated array of strings.
   */

  auto get_applications() const -> std::vector<Glib::ustring>;


  /** Gets the name of the last application that have registered the
   * recently used resource represented by @a info.
   *
   * @return An application name.
   */
  auto last_application() const -> Glib::ustring;

  /** Checks whether an application registered this resource using @a app_name.
   *
   * @param app_name A string containing an application name.
   * @return <tt>true</tt> if an application with name @a app_name was found,
   * <tt>false</tt> otherwise.
   */
  auto has_application(const Glib::ustring& app_name) const -> bool;


  /** Returns all groups registered for the recently used item @a info.
   *
   * The array of returned group names will be <tt>nullptr</tt> terminated, so
   * length might optionally be <tt>nullptr</tt>.
   *
   * @param length Return location for the number of groups returned.
   * @return A newly allocated <tt>nullptr</tt> terminated array of strings.
   */

  auto get_groups() const -> std::vector<Glib::ustring>;


  /** Checks whether @a group_name appears inside the groups
   * registered for the recently used item @a info.
   *
   * @param group_name Name of a group.
   * @return <tt>true</tt> if the group was found.
   */
  auto has_group(const Glib::ustring& group_name) const -> bool;


  /** Retrieves the icon associated to the resource MIME type.
   *
   * @return A `Gio::Icon` containing the icon.
   */
  auto get_gicon() -> Glib::RefPtr<Gio::Icon>;

  /** Retrieves the icon associated to the resource MIME type.
   *
   * @return A `Gio::Icon` containing the icon.
   */
  auto get_gicon() const -> Glib::RefPtr<const Gio::Icon>;


  /** Computes a valid UTF-8 string that can be used as the
   * name of the item in a menu or list.
   *
   * For example, calling this function on an item that refers
   * to “file:///foo/bar.txt” will yield “bar.txt”.
   *
   * @return A newly-allocated string in UTF-8 encoding
   * free it with Glib::free().
   */
  auto get_short_name() const -> Glib::ustring;

  /** Gets a displayable version of the resource’s URI.
   *
   * If the resource is local, it returns a local path; if the
   * resource is not local, it returns the UTF-8 encoded content
   * of get_uri().
   *
   * @return A newly allocated UTF-8 string containing the
   * resource’s URI or <tt>nullptr</tt>.
   */
  auto get_uri_display() const -> Glib::ustring;


  /** Gets the number of days elapsed since the last update
   * of the resource pointed by @a info.
   *
   * @return A positive integer containing the number of days
   * elapsed since the time this resource was last modified.
   */
  auto get_age() const -> int;

  /** Checks whether the resource is local or not by looking at the
   * scheme of its URI.
   *
   * @return <tt>true</tt> if the resource is local.
   */
  auto is_local() const -> bool;

  /** Checks whether the resource pointed by @a info still exists.
   * At the moment this check is done only on resources pointing
   * to local files.
   *
   * @return <tt>true</tt> if the resource exists.
   */
  auto exists() const -> bool;

  /** Checks whether two `Gtk::RecentInfo` point to the same resource.
   *
   * @param info_b A `Gtk::RecentInfo`.
   * @return <tt>true</tt> if both `Gtk::RecentInfo` point to the same
   * resource, <tt>false</tt> otherwise.
   */
  auto equal(const Glib::RefPtr<const RecentInfo>& info_b) const -> bool;


};

#ifndef DOXYGEN_SHOULD_SKIP_THIS

struct RecentInfoTraits
{
  typedef Glib::RefPtr<RecentInfo> CppType;
  typedef const GtkRecentInfo* CType;
  typedef GtkRecentInfo* CTypeNonConst;

  static inline auto to_c_type(const CppType& obj) -> CType { return Glib::unwrap(obj); }
  static inline auto to_c_type(const CType& obj) -> CType { return obj; }
  static auto to_cpp_type(const CType& obj) -> CppType;
  static inline void release_c_type(const CType& obj)
    { gtk_recent_info_unref(const_cast<CTypeNonConst>(obj)); }
};
#endif /* !DOXYGEN_SHOULD_SKIP_THIS */

/** @relates Gtk::RecentInfo */
inline auto operator==(const Glib::RefPtr<const RecentInfo>& lhs, const Glib::RefPtr<const RecentInfo>& rhs) -> bool
  { return lhs->equal(rhs); }

/** @relates Gtk::RecentInfo */
inline auto operator!=(const Glib::RefPtr<const RecentInfo>& lhs, const Glib::RefPtr<const RecentInfo>& rhs) -> bool
  { return !lhs->equal(rhs); }

} // namespace Gtk

namespace Glib
{

// This is needed so Glib::RefPtr<Gtk::RecentInfo> can be used with
// Glib::Value and Gtk::TreeModelColumn:
template <>
class GTKMM_API Value< Glib::RefPtr<Gtk::RecentInfo> > : public ValueBase_Boxed
{
public:
  typedef Glib::RefPtr<Gtk::RecentInfo> CppType;
  typedef GtkRecentInfo* CType;

  static auto value_type() -> GType;

  void set(const CppType& data);
  auto get() const -> CppType;
};

} // namespace Glib


namespace Glib
{

/** A Glib::wrap() method for this object.
 *
 * @param object The C instance.
 * @param take_copy False if the result should take ownership of the C instance. True if it should take a new copy or ref.
 * @result A C++ instance that wraps this C instance.
 *
 * @relates Gtk::RecentInfo
 */
GTKMM_API
auto wrap(GtkRecentInfo* object, bool take_copy = false) -> Glib::RefPtr<Gtk::RecentInfo>;

} // namespace Glib


#endif /* _GTKMM_RECENTINFO_H */

