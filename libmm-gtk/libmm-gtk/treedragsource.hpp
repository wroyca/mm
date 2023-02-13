
#ifndef _GTKMM_TREEDRAGSOURCE_H
#define _GTKMM_TREEDRAGSOURCE_H


#include <libmm-glib/ustring.hpp>
#include <sigc++/sigc++.h>

/* Copyright (C) 1998-2002 The gtkmm Development Team
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

#include <libmm-glib/interface.hpp>
#include <libmm-gtk/treemodel.hpp>
#include <libmm-gdk/contentprovider.hpp>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
extern "C"
{
typedef struct _GtkTreeDragSourceIface GtkTreeDragSourceIface;
}
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkTreeDragSource = struct _GtkTreeDragSource;
using GtkTreeDragSourceClass = struct _GtkTreeDragSourceClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{ class GTKMM_API TreeDragSource_Class; } // namespace Gtk
#endif // DOXYGEN_SHOULD_SKIP_THIS

namespace Gtk
{

/**
 * @ingroup TreeView
*/

class GTKMM_API TreeDragSource : public Glib::Interface
{

#ifndef DOXYGEN_SHOULD_SKIP_THIS

public:
  using CppObjectType = TreeDragSource;
  using CppClassType = TreeDragSource_Class;
  using BaseObjectType = GtkTreeDragSource;
  using BaseClassType = GtkTreeDragSourceIface;

  // noncopyable
  TreeDragSource(const TreeDragSource&) = delete;
  auto operator=(const TreeDragSource&) -> TreeDragSource& = delete;

private:
  friend class TreeDragSource_Class;
  static CppClassType treedragsource_class_;

#endif /* DOXYGEN_SHOULD_SKIP_THIS */
protected:
  /**
   * You should derive from this class to use it.
   */
  TreeDragSource();

#ifndef DOXYGEN_SHOULD_SKIP_THIS
  /** Called by constructors of derived classes. Provide the result of
   * the Class init() function to ensure that it is properly
   * initialized.
   *
   * @param interface_class The Class object for the derived type.
   */
  explicit TreeDragSource(const Glib::Interface_Class& interface_class);

public:
  // This is public so that C++ wrapper instances can be
  // created for C instances of unwrapped types.
  // For instance, if an unexpected C type implements the C interface.
  explicit TreeDragSource(GtkTreeDragSource* castitem);

protected:
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  TreeDragSource(TreeDragSource&& src) noexcept;
  auto operator=(TreeDragSource&& src) noexcept -> TreeDragSource&;

  ~TreeDragSource() noexcept override;

  static void add_interface(GType gtype_implementer);

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS
  static auto get_base_type() -> GType G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GObject.
  auto       gobj() -> GtkTreeDragSource*       { return reinterpret_cast<GtkTreeDragSource*>(gobject_); }

  ///Provides access to the underlying C GObject.
  auto gobj() const -> const GtkTreeDragSource* { return reinterpret_cast<GtkTreeDragSource*>(gobject_); }

private:


public:

  /** Asks the `Gtk::TreeDragSource` whether a particular row can be used as
   * the source of a DND operation. If the source doesn’t implement
   * this interface, the row is assumed draggable.
   *
   * @param path Row on which user is initiating a drag.
   * @return <tt>true</tt> if the row can be dragged.
   */
  auto row_draggable(const TreeModel::Path& path) const -> bool;

  // gtk_tree_drag_source_drag_data_get() returns a newly created GdkContentProvider.

  /** Asks the `Gtk::TreeDragSource` to return a `Gdk::ContentProvider` representing
   * the row at @a path. Should robustly handle a @a path no
   * longer found in the model!
   *
   * @param path Row that was dragged.
   * @return A `Gdk::ContentProvider` for the
   * given @a path.
   */
  auto drag_data_get(const TreeModel::Path& path) const -> Glib::RefPtr<Gdk::ContentProvider>;


  /** Asks the `Gtk::TreeDragSource` to delete the row at @a path, because
   * it was moved somewhere else via drag-and-drop. Returns <tt>false</tt>
   * if the deletion fails because @a path no longer exists, or for
   * some model-specific reason. Should robustly handle a @a path no
   * longer found in the model!
   *
   * @param path Row that was being dragged.
   * @return <tt>true</tt> if the row was successfully deleted.
   */
  auto drag_data_delete(const TreeModel::Path& path) -> bool;

protected:

    virtual auto row_draggable_vfunc(const TreeModel::Path& path) const -> bool;


    virtual auto drag_data_get_vfunc(const TreeModel::Path& path) const -> Glib::RefPtr<Gdk::ContentProvider>;

    virtual auto drag_data_delete_vfunc(const TreeModel::Path& path) -> bool;


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
   * @relates Gtk::TreeDragSource
   */
  GTKMM_API
  auto wrap(GtkTreeDragSource* object, bool take_copy = false) -> Glib::RefPtr<Gtk::TreeDragSource>;

} // namespace Glib


#endif /* _GTKMM_TREEDRAGSOURCE_H */

