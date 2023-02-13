
#ifndef _GTKMM_TREEROWREFERENCE_H
#define _GTKMM_TREEROWREFERENCE_H


#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

/*
 * Copyright (C) 2002 The gtkmm Development Team
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


#include <libmm-gtk/treemodel.hxx>
#include <libmm-gtk/treepath.hxx>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
extern "C" { typedef struct _GtkTreeRowReference GtkTreeRowReference; }
#endif

namespace Gtk
{

/** Typedefed as Gtk::TreeModel::RowReference.
 * This reference will keep pointing to
 * the node pointed to by the Path, so long as it exists.  It listens to all
 * signals emitted by the Model, and updates its Path appropriately.
 * @ingroup TreeView
*/
class GTKMM_API TreeRowReference
{
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  using CppObjectType = TreeRowReference;
  using BaseObjectType = GtkTreeRowReference;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType G_GNUC_CONST;

  TreeRowReference();

  explicit TreeRowReference(GtkTreeRowReference* gobject, bool make_a_copy = true);

  TreeRowReference(const TreeRowReference& other);
  auto operator=(const TreeRowReference& other) -> TreeRowReference&;

  TreeRowReference(TreeRowReference&& other) noexcept;
  auto operator=(TreeRowReference&& other) noexcept -> TreeRowReference&;

  ~TreeRowReference() noexcept;

  void swap(TreeRowReference& other) noexcept;

  ///Provides access to the underlying C instance.
  auto       gobj() -> GtkTreeRowReference*       { return gobject_; }

  ///Provides access to the underlying C instance.
  auto gobj() const -> const GtkTreeRowReference* { return gobject_; }

  ///Provides access to the underlying C instance. The caller is responsible for freeing it. Use when directly setting fields in structs.
  auto gobj_copy() const -> GtkTreeRowReference*;

protected:
  GtkTreeRowReference* gobject_;

private:


public:
  TreeRowReference(const Glib::RefPtr<TreeModel>& model, const TreeModel::Path& path);

  /** The same as is_valid().
   * For instance,
   * @code
   * if(treerowreference)
   *   do_something()
   * @endcode
   *
   * @newin{3,22}
   */
  explicit operator bool() const;


  /** Returns a path that the row reference currently points to,
   * or <tt>nullptr</tt> if the path pointed to is no longer valid.
   *
   * @return A current path.
   */
  auto get_path() const -> TreeModel::Path;


  /** Returns the model that the row reference is monitoring.
   *
   * @return The model.
   */
  auto get_model() -> Glib::RefPtr<TreeModel>;

  /** Returns the model that the row reference is monitoring.
   *
   * @return The model.
   */
  auto get_model() const -> Glib::RefPtr<const TreeModel>;


  /** Returns <tt>true</tt> if the @a reference is non-<tt>nullptr</tt> and refers to
   * a current valid path.
   *
   * @return <tt>true</tt> if @a reference points to a valid path.
   */
  auto is_valid() const -> bool;


};

} // namespace Gtk


namespace Gtk
{

/** @relates Gtk::TreeRowReference
 * @param lhs The left-hand side
 * @param rhs The right-hand side
 */
inline void swap(TreeRowReference& lhs, TreeRowReference& rhs) noexcept
  { lhs.swap(rhs); }

} // namespace Gtk

namespace Glib
{

/** A Glib::wrap() method for this object.
 *
 * @param object The C instance.
 * @param take_copy False if the result should take ownership of the C instance. True if it should take a new copy or ref.
 * @result A C++ instance that wraps this C instance.
 *
 * @relates Gtk::TreeRowReference
 */
GTKMM_API
auto wrap(GtkTreeRowReference* object, bool take_copy = false) -> Gtk::TreeRowReference;

#ifndef DOXYGEN_SHOULD_SKIP_THIS
template <>
class GTKMM_API Value<Gtk::TreeRowReference> : public Glib::Value_Boxed<Gtk::TreeRowReference>
{};
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

} // namespace Glib


#endif /* _GTKMM_TREEROWREFERENCE_H */
