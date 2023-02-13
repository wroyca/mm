
#ifndef _GTKMM_FILEFILTER_H
#define _GTKMM_FILEFILTER_H


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

#include <libmm-gtk/filter.hxx>
#include <libmm-gtk/buildable.hxx>
#include <string>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkFileFilter = struct _GtkFileFilter;
using GtkFileFilterClass = struct _GtkFileFilterClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{ class GTKMM_API FileFilter_Class; } // namespace Gtk
#endif //DOXYGEN_SHOULD_SKIP_THIS

namespace Gtk
{

/** A filter for selecting a file subset.
 *
 * A Gtk::FileFilter can be used to restrict the files being shown in a Gtk::FileChooser.
 * Files can be filtered based on their name (with add_pattern()),
 * on their MIME type (with add_mime_type()), or by a custom filter
 * function (with add_custom()).
 *
 * Filtering by MIME types handles aliasing and subclassing of MIME types;
 * e.g. a filter for <tt>text/plain</tt> also matches a file with MIME type
 * <tt>application/rtf</tt>, since <tt>application/rtf</tt> is a subclass of
 * <tt>text/plain</tt>. Note that Gtk::FileFilter allows wildcards for the
 * subtype of a MIME type, so you can e.g. filter for <tt>image/ *</tt>.
 *
 * Filters are used by adding them to a Gtk::FileChooser. See Gtk::FileChooser::add_filter().
 */

class GTKMM_API FileFilter : public Gtk::Filter, public Buildable
{

#ifndef DOXYGEN_SHOULD_SKIP_THIS

public:
  using CppObjectType = FileFilter;
  using CppClassType = FileFilter_Class;
  using BaseObjectType = GtkFileFilter;
  using BaseClassType = GtkFileFilterClass;

  // noncopyable
  FileFilter(const FileFilter&) = delete;
  auto operator=(const FileFilter&) -> FileFilter& = delete;

private:  friend class FileFilter_Class;
  static CppClassType filefilter_class_;

protected:
  explicit FileFilter(const Glib::ConstructParams& construct_params);
  explicit FileFilter(GtkFileFilter* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  FileFilter(FileFilter&& src) noexcept;
  auto operator=(FileFilter&& src) noexcept -> FileFilter&;

  ~FileFilter() noexcept override;

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS


  static auto get_base_type() -> GType G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GObject.
  auto       gobj() -> GtkFileFilter*       { return reinterpret_cast<GtkFileFilter*>(gobject_); }

  ///Provides access to the underlying C GObject.
  auto gobj() const -> const GtkFileFilter* { return reinterpret_cast<GtkFileFilter*>(gobject_); }

  ///Provides access to the underlying C instance. The caller is responsible for unrefing it. Use when directly setting fields in structs.
  auto gobj_copy() -> GtkFileFilter*;

private:


protected:
  FileFilter();

public:

  static auto create() -> Glib::RefPtr<FileFilter>;


  /** Sets a human-readable name of the filter.
   *
   * This is the string that will be displayed in the file chooser
   * if there is a selectable list of filters.
   *
   * @param name The human-readable-name for the filter, or <tt>nullptr</tt>
   * to remove any existing name.
   */
  void set_name(const Glib::ustring& name);

  /** Gets the human-readable name for the filter.
   *
   * See set_name().
   *
   * @return The human-readable name of the filter.
   */
  auto get_name() const -> Glib::ustring;


  /** Adds a rule allowing a given mime type to @a filter.
   *
   * @param mime_type Name of a MIME type.
   */
  void add_mime_type(const Glib::ustring& mime_type);
  //TODO: When we can change ABI/API: const std::string& pattern.

  /** Adds a rule allowing a shell style glob to a filter.
   *
   * Note that it depends on the platform whether pattern
   * matching ignores case or not. On Windows, it does, on
   * other platforms, it doesn't.
   *
   * @param pattern A shell style glob.
   */
  void add_pattern(const Glib::ustring& pattern);

  /** Adds a suffix match rule to a filter.
   *
   * This is similar to adding a match for the pattern
   * "*. @a suffix".
   *
   * In contrast to pattern matches, suffix matches
   * are *always* case-insensitive.
   *
   * @newin{4,4}
   *
   * @param suffix Filename suffix to match.
   */
  void add_suffix(const std::string& suffix);

  /** Adds a rule allowing image files in the formats supported
   * by GdkPixbuf.
   *
   * This is equivalent to calling add_mime_type()
   * for all the supported mime types.
   */
  void add_pixbuf_formats();

  // This is meant for implementors of FileChooser, so we don’t wrap it.


  /** The human-readable name of the filter.
   *
   * This is the string that will be displayed in the file chooser
   * user interface if there is a selectable list of filters.
   *
   * Default value: ""
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_name() -> Glib::PropertyProxy< Glib::ustring > ;

/** The human-readable name of the filter.
   *
   * This is the string that will be displayed in the file chooser
   * user interface if there is a selectable list of filters.
   *
   * Default value: ""
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_name() const -> Glib::PropertyProxy_ReadOnly< Glib::ustring >;


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
   * @relates Gtk::FileFilter
   */
  GTKMM_API
  auto wrap(GtkFileFilter* object, bool take_copy = false) -> Glib::RefPtr<Gtk::FileFilter>;
}


#endif /* _GTKMM_FILEFILTER_H */

