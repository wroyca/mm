
#ifndef _GTKMM_TREEDRAGDEST_H
#define _GTKMM_TREEDRAGDEST_H


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
#include <libmm-glib/value.hpp>
#include <libmm-gtk/treemodel.hpp>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
extern "C"
{
typedef struct _GtkTreeDragDestIface GtkTreeDragDestIface;
}
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkTreeDragDest = struct _GtkTreeDragDest;
using GtkTreeDragDestClass = struct _GtkTreeDragDestClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{ class GTKMM_API TreeDragDest_Class; } // namespace Gtk
#endif // DOXYGEN_SHOULD_SKIP_THIS

namespace Gtk
{

/**
 * @ingroup TreeView
 */

class GTKMM_API TreeDragDest : public Glib::Interface
{

#ifndef DOXYGEN_SHOULD_SKIP_THIS

public:
  using CppObjectType = TreeDragDest;
  using CppClassType = TreeDragDest_Class;
  using BaseObjectType = GtkTreeDragDest;
  using BaseClassType = GtkTreeDragDestIface;

  // noncopyable
  TreeDragDest(const TreeDragDest&) = delete;
  auto operator=(const TreeDragDest&) -> TreeDragDest& = delete;

private:
  friend class TreeDragDest_Class;
  static CppClassType treedragdest_class_;

#endif /* DOXYGEN_SHOULD_SKIP_THIS */
protected:
  /**
   * You should derive from this class to use it.
   */
  TreeDragDest();

#ifndef DOXYGEN_SHOULD_SKIP_THIS
  /** Called by constructors of derived classes. Provide the result of
   * the Class init() function to ensure that it is properly
   * initialized.
   *
   * @param interface_class The Class object for the derived type.
   */
  explicit TreeDragDest(const Glib::Interface_Class& interface_class);

public:
  // This is public so that C++ wrapper instances can be
  // created for C instances of unwrapped types.
  // For instance, if an unexpected C type implements the C interface.
  explicit TreeDragDest(GtkTreeDragDest* castitem);

protected:
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  TreeDragDest(TreeDragDest&& src) noexcept;
  auto operator=(TreeDragDest&& src) noexcept -> TreeDragDest&;

  ~TreeDragDest() noexcept override;

  static void add_interface(GType gtype_implementer);

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS
  static auto get_base_type() -> GType G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GObject.
  auto       gobj() -> GtkTreeDragDest*       { return reinterpret_cast<GtkTreeDragDest*>(gobject_); }

  ///Provides access to the underlying C GObject.
  auto gobj() const -> const GtkTreeDragDest* { return reinterpret_cast<GtkTreeDragDest*>(gobject_); }

private:


public:


  /** Asks the `Gtk::TreeDragDest` to insert a row before the path @a dest,
   * deriving the contents of the row from @a value. If @a dest is
   * outside the tree so that inserting before it is impossible, <tt>false</tt>
   * will be returned. Also, <tt>false</tt> may be returned if the new row is
   * not created for some model-specific reason.  Should robustly handle
   * a @a dest no longer found in the model!
   *
   * @param dest Row to drop in front of.
   * @param value Data to drop.
   * @return Whether a new row was created before position @a dest.
   */
  auto drag_data_received(const TreeModel::Path& dest, const Glib::ValueBase& value) -> bool;

  /** Determines whether a drop is possible before the given @a dest_path,
   * at the same depth as @a dest_path. i.e., can we drop the data in
   *  @a value at that location. @a dest_path does not have to
   * exist; the return value will almost certainly be <tt>false</tt> if the
   * parent of @a dest_path doesn’t exist, though.
   *
   * @param dest_path Destination row.
   * @param value The data being dropped.
   * @return <tt>true</tt> if a drop is possible before @a dest_path.
   */
  auto row_drop_possible(const TreeModel::Path& dest_path, const Glib::ValueBase& value) const -> bool;

protected:
    virtual auto drag_data_received_vfunc(const TreeModel::Path& dest, const Glib::ValueBase& value) -> bool;

    virtual auto row_drop_possible_vfunc(const TreeModel::Path& dest, const Glib::ValueBase& value) const -> bool;


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
   * @relates Gtk::TreeDragDest
   */
  GTKMM_API
  auto wrap(GtkTreeDragDest* object, bool take_copy = false) -> Glib::RefPtr<Gtk::TreeDragDest>;

} // namespace Glib


#endif /* _GTKMM_TREEDRAGDEST_H */

