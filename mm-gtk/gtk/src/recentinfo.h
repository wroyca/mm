// Generated by gmmproc 2.74.0 -- DO NOT MODIFY!
#ifndef _GTKMM_RECENTINFO_H
#define _GTKMM_RECENTINFO_H

#include <gtkmmconfig.h>


#include <glibmm/ustring.h>
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

#include <giomm/icon.h>
#include <giomm/appinfo.h>
#include <glibmm/datetime.h>


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
  GtkRecentInfo*       gobj();

  ///Provides access to the underlying C instance.
  const GtkRecentInfo* gobj() const;

  ///Provides access to the underlying C instance. The caller is responsible for unrefing it. Use when directly setting fields in structs.
  GtkRecentInfo* gobj_copy() const;

  RecentInfo() = delete;

  // noncopyable
  RecentInfo(const RecentInfo&) = delete;
  RecentInfo& operator=(const RecentInfo&) = delete;

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
  Glib::ustring get_uri() const;
  
  /** Gets the name of the resource.
   * 
   * If none has been defined, the basename
   * of the resource is obtained.
   * 
   * @return The display name of the resource. The returned string
   * is owned by the recent manager, and should not be freed.
   */
  Glib::ustring get_display_name() const;
  
  /** Gets the (short) description of the resource.
   * 
   * @return The description of the resource. The returned string
   * is owned by the recent manager, and should not be freed.
   */
  Glib::ustring get_description() const;
  
  /** Gets the MIME type of the resource.
   * 
   * @return The MIME type of the resource. The returned string
   * is owned by the recent manager, and should not be freed.
   */
  Glib::ustring get_mime_type() const;

  
  /** Gets the time when the resource
   * was added to the recently used resources list.
   * 
   * @return A `Glib::DateTime` for the time
   * when the resource was added.
   */
  Glib::DateTime get_added() const;
  
  /** Gets the time when the meta-data
   * for the resource was last modified.
   * 
   * @return A `Glib::DateTime` for the time
   * when the resource was last modified.
   */
  Glib::DateTime get_modified() const;
  
  /** Gets the time when the meta-data
   * for the resource was last visited.
   * 
   * @return A `Glib::DateTime` for the time
   * when the resource was last visited.
   */
  Glib::DateTime get_visited() const;

  
  /** Gets the value of the “private” flag.
   * 
   * Resources in the recently used list that have this flag
   * set to <tt>true</tt> should only be displayed by the applications
   * that have registered them.
   * 
   * @return <tt>true</tt> if the private flag was found, <tt>false</tt> otherwise.
   */
  bool get_private_hint() const;

   
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
  Glib::RefPtr<Gio::AppInfo> create_app_info(const Glib::ustring& app_name);

  
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

  bool get_application_info(const Glib::ustring& app_name, std::string& app_exec,
                            guint& count, Glib::DateTime& stamp) const;

  
  /** Retrieves the list of applications that have registered this resource.
   * 
   * @param length Return location for the length of the returned list.
   * @return A newly
   * allocated <tt>nullptr</tt>-terminated array of strings.
   */

  std::vector<Glib::ustring> get_applications() const;

  
  /** Gets the name of the last application that have registered the
   * recently used resource represented by @a info.
   * 
   * @return An application name.
   */
  Glib::ustring last_application() const;
  
  /** Checks whether an application registered this resource using @a app_name.
   * 
   * @param app_name A string containing an application name.
   * @return <tt>true</tt> if an application with name @a app_name was found,
   * <tt>false</tt> otherwise.
   */
  bool has_application(const Glib::ustring& app_name) const;

  
  /** Returns all groups registered for the recently used item @a info.
   * 
   * The array of returned group names will be <tt>nullptr</tt> terminated, so
   * length might optionally be <tt>nullptr</tt>.
   * 
   * @param length Return location for the number of groups returned.
   * @return A newly allocated <tt>nullptr</tt> terminated array of strings.
   */

  std::vector<Glib::ustring> get_groups() const;

  
  /** Checks whether @a group_name appears inside the groups
   * registered for the recently used item @a info.
   * 
   * @param group_name Name of a group.
   * @return <tt>true</tt> if the group was found.
   */
  bool has_group(const Glib::ustring& group_name) const;

  
  /** Retrieves the icon associated to the resource MIME type.
   * 
   * @return A `Gio::Icon` containing the icon.
   */
  Glib::RefPtr<Gio::Icon> get_gicon();
  
  /** Retrieves the icon associated to the resource MIME type.
   * 
   * @return A `Gio::Icon` containing the icon.
   */
  Glib::RefPtr<const Gio::Icon> get_gicon() const;

  
  /** Computes a valid UTF-8 string that can be used as the
   * name of the item in a menu or list.
   * 
   * For example, calling this function on an item that refers
   * to “file:///foo/bar.txt” will yield “bar.txt”.
   * 
   * @return A newly-allocated string in UTF-8 encoding
   * free it with Glib::free().
   */
  Glib::ustring get_short_name() const;
  
  /** Gets a displayable version of the resource’s URI.
   * 
   * If the resource is local, it returns a local path; if the
   * resource is not local, it returns the UTF-8 encoded content
   * of get_uri().
   * 
   * @return A newly allocated UTF-8 string containing the
   * resource’s URI or <tt>nullptr</tt>.
   */
  Glib::ustring get_uri_display() const;

  
  /** Gets the number of days elapsed since the last update
   * of the resource pointed by @a info.
   * 
   * @return A positive integer containing the number of days
   * elapsed since the time this resource was last modified.
   */
  int get_age() const;
  
  /** Checks whether the resource is local or not by looking at the
   * scheme of its URI.
   * 
   * @return <tt>true</tt> if the resource is local.
   */
  bool is_local() const;
  
  /** Checks whether the resource pointed by @a info still exists.
   * At the moment this check is done only on resources pointing
   * to local files.
   * 
   * @return <tt>true</tt> if the resource exists.
   */
  bool exists() const;
  
  /** Checks whether two `Gtk::RecentInfo` point to the same resource.
   * 
   * @param info_b A `Gtk::RecentInfo`.
   * @return <tt>true</tt> if both `Gtk::RecentInfo` point to the same
   * resource, <tt>false</tt> otherwise.
   */
  bool equal(const Glib::RefPtr<const RecentInfo>& info_b) const;


};

#ifndef DOXYGEN_SHOULD_SKIP_THIS

struct RecentInfoTraits
{
  typedef Glib::RefPtr<RecentInfo> CppType;
  typedef const GtkRecentInfo* CType;
  typedef GtkRecentInfo* CTypeNonConst;

  static inline CType to_c_type(const CppType& obj) { return Glib::unwrap(obj); }
  static inline CType to_c_type(const CType& obj) { return obj; }
  static CppType to_cpp_type(const CType& obj);
  static inline void release_c_type(const CType& obj)
    { gtk_recent_info_unref(const_cast<CTypeNonConst>(obj)); }
};
#endif /* !DOXYGEN_SHOULD_SKIP_THIS */

/** @relates Gtk::RecentInfo */
inline bool operator==(const Glib::RefPtr<const RecentInfo>& lhs, const Glib::RefPtr<const RecentInfo>& rhs)
  { return lhs->equal(rhs); }

/** @relates Gtk::RecentInfo */
inline bool operator!=(const Glib::RefPtr<const RecentInfo>& lhs, const Glib::RefPtr<const RecentInfo>& rhs)
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

  static GType value_type();

  void set(const CppType& data);
  CppType get() const;
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
Glib::RefPtr<Gtk::RecentInfo> wrap(GtkRecentInfo* object, bool take_copy = false);

} // namespace Glib


#endif /* _GTKMM_RECENTINFO_H */

