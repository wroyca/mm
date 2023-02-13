
#ifndef _GIOMM_FILEICON_H
#define _GIOMM_FILEICON_H


#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

/* Copyright (C) 2007 The gtkmm Development Team
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
 * License along with this library.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <libmm-glib/object.hxx>
#include <libmm-gio/file.hxx>
#include <libmm-gio/icon.hxx>
#include <libmm-gio/loadableicon.hxx>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GFileIcon = struct _GFileIcon;
using GFileIconClass = struct _GFileIconClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gio
{ class GIOMM_API FileIcon_Class; } // namespace Gio
#endif //DOXYGEN_SHOULD_SKIP_THIS

namespace Gio
{

/** FileIcon specifies an icon by pointing to an image file to be used as icon.
 *
 * @newin{2,16}
 */

class GIOMM_API FileIcon
: public Glib::Object,
  public Icon,
  public LoadableIcon
{

#ifndef DOXYGEN_SHOULD_SKIP_THIS

public:
  using CppObjectType = FileIcon;
  using CppClassType = FileIcon_Class;
  using BaseObjectType = GFileIcon;
  using BaseClassType = GFileIconClass;

  // noncopyable
  FileIcon(const FileIcon&) = delete;
  auto operator=(const FileIcon&) -> FileIcon& = delete;

private:  friend class FileIcon_Class;
  static CppClassType fileicon_class_;

protected:
  explicit FileIcon(const Glib::ConstructParams& construct_params);
  explicit FileIcon(GFileIcon* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  FileIcon(FileIcon&& src) noexcept;
  auto operator=(FileIcon&& src) noexcept -> FileIcon&;

  ~FileIcon() noexcept override;

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS


  static auto get_base_type() -> GType G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GObject.
  auto       gobj() -> GFileIcon*       { return reinterpret_cast<GFileIcon*>(gobject_); }

  ///Provides access to the underlying C GObject.
  auto gobj() const -> const GFileIcon* { return reinterpret_cast<GFileIcon*>(gobject_); }

  ///Provides access to the underlying C instance. The caller is responsible for unrefing it. Use when directly setting fields in structs.
  auto gobj_copy() -> GFileIcon*;

private:


protected:
  FileIcon();

public:

  static auto create() -> Glib::RefPtr<FileIcon>;


  /** Gets the File associated with the given @a icon.
   *
   * @return A File.
   */
  auto get_file() -> Glib::RefPtr<File>;

  /** Gets the File associated with the given @a icon.
   *
   * @return A File.
   */
  auto get_file() const -> Glib::RefPtr<const File>;

  /** The file containing the icon.
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_file() const -> Glib::PropertyProxy_ReadOnly< Glib::RefPtr<File> >;


public:

public:
  //C++ methods used to invoke GTK+ virtual functions:

protected:
  //GTK+ Virtual Functions (override these to change behaviour):

  //Default Signal Handlers::


};

} // namespace Gio


namespace Glib
{
  /** A Glib::wrap() method for this object.
   *
   * @param object The C instance.
   * @param take_copy False if the result should take ownership of the C instance. True if it should take a new copy or ref.
   * @result A C++ instance that wraps this C instance.
   *
   * @relates Gio::FileIcon
   */
  GIOMM_API
  auto wrap(GFileIcon* object, bool take_copy = false) -> Glib::RefPtr<Gio::FileIcon>;
}


#endif /* _GIOMM_FILEICON_H */

