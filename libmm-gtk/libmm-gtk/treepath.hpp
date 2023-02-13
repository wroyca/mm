
#ifndef _GTKMM_TREEPATH_H
#define _GTKMM_TREEPATH_H

#include <libmm-gtk/mm-gtkconfig.hpp>


#include <libmm-glib/ustring.hpp>
#include <sigc++/sigc++.h>

/*
 * Copyright(C) 1998-2002 The gtkmm Development Team
 *
 * This library is free software, ) you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation, ) either
 * version 2.1 of the License, or(at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY, ) without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library, ) if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 */

// This is for including the config header before any code (such as
// the #ifndef GTKMM_DISABLE_DEPRECATED in deprecated classes) is generated:


#include <libmm-gtk/treemodel.hpp>
#include <libmm-gdk/contentprovider.hpp>
#ifdef GLIBMM_HAVE_SUN_REVERSE_ITERATOR
#include <cstddef> /* for std::ptrdiff_t */
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
extern "C" { typedef struct _GtkTreePath GtkTreePath; }
#endif

namespace Gtk
{

/** A path is essentially a potential node. It is a location on a model that may
 * or may not actually correspond to a node on a specific model.
 *
 * A Path can be converted into either an array of unsigned integers or a string. The string
 * form is a list of numbers separated by a colon. Each number refers to the
 * offset at that level. Thus, the path "0" refers to the root node and the
 * path "2:4" refers to the fifth child of the third node.
 *
 * Typedefed as Gtk::TreeModel::Path.
 * @ingroup TreeView
 */
class GTKMM_API TreePath
{
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  using CppObjectType = TreePath;
  using BaseObjectType = GtkTreePath;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType G_GNUC_CONST;

  TreePath();


  TreePath(const TreePath& other);
  auto operator=(const TreePath& other) -> TreePath&;

  TreePath(TreePath&& other) noexcept;
  auto operator=(TreePath&& other) noexcept -> TreePath&;

  ~TreePath() noexcept;

  void swap(TreePath& other) noexcept;

  ///Provides access to the underlying C instance.
  auto       gobj() -> GtkTreePath*       { return gobject_; }

  ///Provides access to the underlying C instance.
  auto gobj() const -> const GtkTreePath* { return gobject_; }

  ///Provides access to the underlying C instance. The caller is responsible for freeing it. Use when directly setting fields in structs.
  auto gobj_copy() const -> GtkTreePath*;

protected:
  GtkTreePath* gobject_;

private:


public:
  typedef unsigned int  size_type;
  typedef int           difference_type;

  typedef int           value_type;
  typedef int&          reference;
  typedef const int&    const_reference;

  // Use plain pointers for simplicity.
  typedef int*          iterator;
  typedef const int*    const_iterator;

#ifndef GLIBMM_HAVE_SUN_REVERSE_ITERATOR

  typedef std::reverse_iterator<iterator>       reverse_iterator;
  typedef std::reverse_iterator<const_iterator> const_reverse_iterator;

#else

  typedef std::reverse_iterator<iterator, std::random_access_iterator_tag,
                                int, int&, int*, std::ptrdiff_t> reverse_iterator;

  typedef std::reverse_iterator<const_iterator, std::random_access_iterator_tag,
                                int, const int&, const int*, std::ptrdiff_t> const_reverse_iterator;

#endif /* GLIBMM_HAVE_SUN_REVERSE_ITERATOR */


  explicit TreePath(GtkTreePath* gobject, bool make_a_copy = true);
  explicit TreePath(size_type n, value_type value = 0);
  explicit TreePath(const Glib::ustring& path);
  explicit TreePath(const TreeModel::iterator& iter);

  template <class In> inline TreePath(In pbegin, In pend);

  void clear();

  // I think it's OK for this assignment to be implicit.  It's very useful.
  auto operator=(const TreeModel::iterator& iter) -> TreePath&;

  /** Checks that the path is not empty, by calling empty().
   * For instance,
   * @code
   * if(treepath)
   *   do_something()
   * @endcode
   *
   * @newin{3,22}
   */
  explicit operator bool() const;

  template <class In> inline void assign(In pbegin, In pend);
  template <class In>        void append(In pbegin, In pend);


  /** Appends a new index to a path.
   *
   * As a result, the depth of the path is increased.
   *
   * @param index The index.
   */
  void push_back(int index);

  /** Prepends a new index to a path.
   *
   * As a result, the depth of the path is increased.
   *
   * @param index The index.
   */
  void push_front(int index);

  auto size() const -> size_type;
  auto empty() const -> bool;

  auto       operator[](size_type i) -> reference;
  auto operator[](size_type i) const -> const_reference;


  auto begin() -> iterator;
  auto end() -> iterator;
  auto begin() const -> const_iterator;
  auto end()   const -> const_iterator;

  // Note: there is no advantage in not inlining these methods.
  // We can't change them without breaking ABI anyway.
  auto       rbegin() -> reverse_iterator       { return reverse_iterator(end());         }
  auto       rend() -> reverse_iterator         { return reverse_iterator(begin());       }
  auto rbegin() const -> const_reverse_iterator { return const_reverse_iterator(end());   }
  auto rend()   const -> const_reverse_iterator { return const_reverse_iterator(begin()); }

  auto       front() -> reference       { return *begin();  }
  auto front() const -> const_reference { return *begin();  }
  auto       back() -> reference        { return *rbegin(); }
  auto back()  const -> const_reference { return *rbegin(); }


  /** Moves the @a path to point to the next node at the current depth.
   */
  void next();

  /** Moves the @a path to point to the previous node at the
   * current depth, if it exists.
   *
   * @return <tt>true</tt> if @a path has a previous node, and
   * the move was made.
   */
  auto prev() -> bool;

  /** Moves the @a path to point to its parent node, if it has a parent.
   *
   * @return <tt>true</tt> if @a path has a parent, and the move was made.
   */
  auto up() -> bool;

  /** Moves @a path to point to the first child of the current path.
   */
  void down();


  /** Returns <tt>true</tt> if @a descendant is a descendant of @a path.
   *
   * @param descendant Another `Gtk::TreePath`.
   * @return <tt>true</tt> if @a descendant is contained inside @a path.
   */
  auto is_ancestor(const TreePath& descendant) const -> bool;

  /** Returns <tt>true</tt> if @a path is a descendant of @a ancestor.
   *
   * @param ancestor Another `Gtk::TreePath`.
   * @return <tt>true</tt> if @a ancestor contains @a path somewhere below it.
   */
  auto is_descendant(const TreePath& ancestor) const -> bool;


  /** Generates a string representation of the path.
   *
   * This string is a “:” separated list of numbers.
   * For example, “4:10:0:3” would be an acceptable
   * return value for this string. If the path has
   * depth 0, <tt>nullptr</tt> is returned.
   *
   * @return The string.
   */
  auto to_string() const -> Glib::ustring;


   //replaced by push_back()
   //replaced by push_front()
   //replaced by size()


  /** Obtains a Gtk::TreeModel and Gtk::TreeModel::Path from @a value of target type
   * GTK_TYPE_TREE_ROW_DATA.
   *
   * @param value A Glib::ValueBase
   * @param[out] model A Gtk::TreeModel
   * @param[out] path A row in @a model
   * @return <tt>true</tt> if the @a value had target type GTK_TYPE_TREE_ROW_DATA
   *         and is otherwise valid.
   */
  static auto get_row_drag_data(const Glib::ValueBase& value, Glib::RefPtr<const TreeModel>& model, TreePath& path) -> bool;

  /// See description in the other overload.
  static auto get_row_drag_data(const Glib::ValueBase& value, TreePath& path) -> bool;

  /** Creates a content provider for dragging the path from @a model.
   *
   * @param model A Gtk::TreeModel.
   * @return A Gdk::ContentProvider.
   */
  auto create_row_drag_content(const Glib::RefPtr<const TreeModel>& model) const -> Glib::RefPtr<Gdk::ContentProvider>;


};

#ifndef DOXYGEN_SHOULD_SKIP_THIS

template <class In>
void TreePath::append(In pbegin, In pend)
{
  // push_back() can't throw -- if it could, this code wouldn't be strongly exception-safe.
  for(; pbegin != pend; ++pbegin)
    this->push_back(*pbegin);
}

template <class In> inline
TreePath::TreePath(In pbegin, In pend)
{
  this->append(pbegin, pend);
}

template <class In> inline
void TreePath::assign(In pbegin, In pend)
{
  TreePath temp (pbegin, pend);
  this->swap(temp);
}

struct TreePathTraits
{
  typedef TreePath            CppType;
  typedef const GtkTreePath*  CType;
  typedef GtkTreePath*        CTypeNonConst;

  static auto to_c_type(const CppType& item) -> CType
    { return item.gobj(); }

  static auto to_c_type(CType item) -> CType
    { return item; }

  static auto to_cpp_type(CType item) -> CppType
    { return CppType(const_cast<CTypeNonConst>(item)); }

  static void release_c_type(CType item)
    { gtk_tree_path_free(const_cast<CTypeNonConst>(item)); }
};

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

} // namespace Gtk


namespace Gtk
{

/** @relates Gtk::TreePath
 * @param lhs The left-hand side
 * @param rhs The right-hand side
 * @result The result
 */
GTKMM_API
auto operator==(const TreePath& lhs, const TreePath& rhs) -> bool;

/** @relates Gtk::TreePath
 * @param lhs The left-hand side
 * @param rhs The right-hand side
 * @result The result
 */
GTKMM_API
auto operator!=(const TreePath& lhs, const TreePath& rhs) -> bool;

/** @relates Gtk::TreePath
 * @param lhs The left-hand side
 * @param rhs The right-hand side
 * @result The result
 */
GTKMM_API
auto operator<(const TreePath& lhs, const TreePath& rhs) -> bool;

/** @relates Gtk::TreePath
 * @param lhs The left-hand side
 * @param rhs The right-hand side
 * @result The result
 */
GTKMM_API
auto operator>(const TreePath& lhs, const TreePath& rhs) -> bool;

/** @relates Gtk::TreePath
 * @param lhs The left-hand side
 * @param rhs The right-hand side
 * @result The result
 */
GTKMM_API
auto operator<=(const TreePath& lhs, const TreePath& rhs) -> bool;

/** @relates Gtk::TreePath
 * @param lhs The left-hand side
 * @param rhs The right-hand side
 * @result The result
 */
GTKMM_API
auto operator>=(const TreePath& lhs, const TreePath& rhs) -> bool;


} // namespace Gtk


namespace Gtk
{

/** @relates Gtk::TreePath
 * @param lhs The left-hand side
 * @param rhs The right-hand side
 */
inline void swap(TreePath& lhs, TreePath& rhs) noexcept
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
 * @relates Gtk::TreePath
 */
GTKMM_API
auto wrap(GtkTreePath* object, bool take_copy = false) -> Gtk::TreePath;

#ifndef DOXYGEN_SHOULD_SKIP_THIS
template <>
class GTKMM_API Value<Gtk::TreePath> : public Glib::Value_Boxed<Gtk::TreePath>
{};
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

} // namespace Glib


#endif /* _GTKMM_TREEPATH_H */

