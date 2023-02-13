
#ifndef _GTKMM_TREEITER_H
#define _GTKMM_TREEITER_H

#include <mm/gtk/mm-gtkconfig.hpp>


#include <mm/glib/ustring.hpp>
#include <sigc++/sigc++.h>

/* Copyright(C) 1998-2002 The gtkmm Development Team
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


#include <mm/gtk/treemodelcolumn.hpp>
#include <iterator>
#include <type_traits>
#include <gtk/gtk.h> /* for GtkTreeIter */

namespace Gtk
{

class GTKMM_API TreeModel;
template <typename T>
class TreeIter;
class GTKMM_API TreeConstRow;
class GTKMM_API TreeRow;
class GTKMM_API TreeNodeConstChildren;
class GTKMM_API TreeNodeChildren;

// Why all the base classes?
//
// TreeIterBase2 contains data members that can't be declared in TreeIterBase,
// because a _CLASS_BOXEDTYPE_STATIC can't contain data members other than
// the gmmproc-generated GtkTreeIter gobject_.
//
// TreeIterBase3 contains those parts of TreeIter<> that does not have to be in
// the template class.

/** Base of TreeIter, TreeRow and TreeNodeChildren.
 *
 * @ingroup TreeView
 */
class GTKMM_API TreeIterBase
{
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  using CppObjectType = TreeIterBase;
  using BaseObjectType = GtkTreeIter;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

  TreeIterBase(const TreeIterBase& other) noexcept;
  auto operator=(const TreeIterBase& other) noexcept -> TreeIterBase&;

  TreeIterBase(TreeIterBase&& other) noexcept;
  auto operator=(TreeIterBase&& other) noexcept -> TreeIterBase&;

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType G_GNUC_CONST;

  TreeIterBase();

  explicit TreeIterBase(const GtkTreeIter* gobject); // always takes a copy

  ///Provides access to the underlying C instance.
  auto       gobj() -> GtkTreeIter*       { return &gobject_; }

  ///Provides access to the underlying C instance.
  auto gobj() const -> const GtkTreeIter* { return &gobject_; }

protected:
  GtkTreeIter gobject_;

private:


   // A wrap() for TreeIterBase* wouldn't be very helpful.


};

/** Base of TreeIter, TreeRow and TreeNodeChildren.
 *
 * @ingroup TreeView
 */
class GTKMM_API TreeIterBase2 : public TreeIterBase
{
protected:

#ifndef DOXYGEN_SHOULD_SKIP_THIS
  TreeIterBase2();
  explicit TreeIterBase2(TreeModel* model); // used in TreeModel methods
  TreeIterBase2(GtkTreeModel* model, const GtkTreeIter* iter); // used by signal proxies

  // Yes, using a simple TreeModel* rather than Glib::RefPtr<TreeModel>
  // violates the general policy. But Gtk::TreeIter should have a trivial
  // copy constructor and assignment operator, i.e. it must contain only
  // POD (plain old data).
  //
  // Gtk::TreeIter is copied a lot, particularly often as return value from
  // methods. Postfix ++ must return by value, and STL algorithms usually
  // pass iterators by value, too. With a RefPtr<> as member data, copying
  // would no longer be trivial, and even cause frequent calls to reference()
  // and unreference(). That usually doesn't matter much for GUI stuff, but
  // Gtk::TreeModel is used as a generic container. Imagine a for-loop that
  // checks whether iter != children.end() on each iteration.

  TreeModel* model_;
  bool       is_end_;

  // For the conversion and assignment from iterator to const_iterator
  friend class Gtk::TreeIter<Gtk::TreeConstRow>;

  friend class Gtk::TreeConstRow;
  friend class Gtk::TreeRow;
  friend class Gtk::TreeNodeConstChildren;
  friend class Gtk::TreeNodeChildren;
#endif // DOXYGEN_SHOULD_SKIP_THIS

}; // class TreeIterBase2

/** Base of TreeIter.
 *
 * Contains the common parts of TreeIter<TreeRow> and TreeIter<TreeConstRow>.
 *
 * @ingroup TreeView
 */
class GTKMM_API TreeIterBase3 : public TreeIterBase2
{
public:

  auto equal(const TreeIterBase3& other) const -> bool;

  /** This is only useful when implementing a custom Gtk::TreeModel class.
   * Compare the iterator's stamp with your model's stamp to discover whether it is valid.
   * @see set_stamp().
   * @result The iterator's stamp.
   */
  auto get_stamp() const -> int;

  /** This is only useful when implementing a custom Gtk::TreeModel class.
   * Set the stamp to be equal to your model's stamp, to mark the iterator as valid.
   * When your model's structure changes, you should increment your model's stamp
   * to mark all older iterators as invalid. They will be recognised as invalid because
   * they will then have an incorrect stamp.
   */
  void set_stamp(int stamp);

#ifndef DOXYGEN_SHOULD_SKIP_THIS

  void set_model_refptr(const Glib::RefPtr<TreeModel>& model);
  void set_model_gobject(GtkTreeModel* model);
  auto get_model_gobject() -> GtkTreeModel*;
  auto get_model_gobject() const -> const GtkTreeModel*;

  void setup_end_iterator(const TreeIterBase3& last_valid);

  auto get_gobject_if_not_end() const -> const GtkTreeIter*
  { return (!is_end_) ? &gobject_ : nullptr; }

  auto get_parent_gobject_if_end() const -> const GtkTreeIter*
  { return (is_end_ && gobject_.stamp) ? &gobject_ : nullptr; }

protected:
  TreeIterBase3();
  explicit TreeIterBase3(TreeModel* model); // used in TreeModel methods
  TreeIterBase3(GtkTreeModel* model, const GtkTreeIter* iter); // used by signal proxies

  // Common part of operator++() and operator++(int).
  void plus_plus();
  // Common part of operator--() and operator--(int).
  void minus_minus();
#endif // DOXYGEN_SHOULD_SKIP_THIS

}; // class TreeIterBase3

// In order to offer STL-like iterator functionality, we cannot wrap
// GtkTreeIter directly. Most GTK+ functions that operate on GtkTreeIter
// are virtual functions in GtkTreeModel. Therefore, the C++ TreeIter
// must store a pointer to the Gtk::TreeModel to which it belongs.
//
// Another problem, which is much worse, is that the GTK+ tree iterator
// doesn't support the STL-style half-open interval [begin,end). Instead,
// it uses a [first,last] interval, and functions return FALSE to indicate
// the end was reached. Also, some functions accept a NULL GtkTreeIter*,
// which will be interpreted as the end() iterator.
//
// Most of the immense complexity in the Gtk::TreeIter implementation is
// needed for proper emulation of [begin,end) intervals. Unfortunately,
// it's not even possible to encapsulate everything in the TreeIter
// class. Almost all wrapper methods dealing with GtkTreeIter must be
// carefully implemented by hand.
//TODO: document implementation details.

/** Typedefed as TreeModel::iterator and TreeModel::const_iterator.
 *
 * A Gtk::TreeModel::iterator is a reference to a specific node on a specific model.
 * It is a generic structure with an integer and three generic pointers.
 * These are filled in by the model in a model-specific way.
 *
 * One can convert a path to an iterator by calling Gtk::TreeModel::get_iter().
 *
 * These iterators are the primary way of accessing a model and are similar to the iterators
 * used by Gtk::TextBuffer. The model interface defines a set of operations
 * using them for navigating the model.
 *
 * The lifecycle of an iterator can be a little confusing at first. Iterators
 * are expected to always be valid for as long as the model is unchanged (and
 * doesn't emit a signal).
 * Additionally, some models guarantee that an iterator is valid for as
 * long as the node it refers to is valid (most notably the Gtk::TreeStore and
 * Gtk::ListStore).
 *
 * Although generally uninteresting, as one always has to
 * allow for the case where iterators do not persist beyond a signal, some very
 * important performance enhancements were made in the sort model. As a result,
 * the Gtk::TreeModel::Flags::ITERS_PERSIST flag was added to indicate this behaviour -
 * see Gtk::TreeModel::get_flags().
 *
 * @tparam T TreeRow for an iterator, TreeConstRow for a const_iterator.
 *
 * @ingroup TreeView
 */
template <typename T>
class TreeIter : public TreeIterBase3
{
  static_assert(std::is_same<T, TreeRow>::value || std::is_same<T, TreeConstRow>::value,
                "TreeIter can only iterate over TreeRow or TreeConstRow");

public:
  using iterator_category = std::bidirectional_iterator_tag;
  using value_type        = T;
  using difference_type   = int;
  using reference         = T&;
  using pointer           = T*;

  TreeIter();

  /// iterator to const_iterator conversion.
  template <typename T2, typename = typename std::enable_if<
    std::is_same<T, TreeConstRow>::value && std::is_same<T2, TreeRow>::value, T2>::type>
  TreeIter(const TreeIter<T2>& src);

  /// iterator to const_iterator assignment.
  template <typename T2, typename = typename std::enable_if<
    std::is_same<T, TreeConstRow>::value && std::is_same<T2, TreeRow>::value, T2>::type>
  auto operator=(const TreeIter<T2>& src) -> TreeIter&;

#ifndef DOXYGEN_SHOULD_SKIP_THIS
  explicit TreeIter(TreeModel* model); // used in TreeModel methods
  TreeIter(GtkTreeModel* model, const GtkTreeIter* iter); // used by signal proxies
#endif // DOXYGEN_SHOULD_SKIP_THIS

  auto operator++() -> TreeIter&;
  auto  operator++(int) -> TreeIter;

  /** Note that this is very slow compared to operator++().
   */
  auto operator--() -> TreeIter&;

  /** Note that this is very slow compared to operator++(int).
   */
  auto operator--(int) -> TreeIter;

  inline auto operator*()  const -> reference;
  inline auto   operator->() const -> pointer;

  /** Discover whether the iterator is valid, and not equal to end().
   * For instance,
   * @code
   * if (treeiter)
   *   do_something();
   * @endcode
   *
   * @newin{3,22}
   */
  inline explicit operator bool() const;

}; // class TreeIter<>

/** @relates Gtk::TreeIter */
inline auto operator==(const TreeIterBase3& lhs, const TreeIterBase3& rhs) -> bool
{ return lhs.equal(rhs); }

/** @relates Gtk::TreeIter */
inline auto operator!=(const TreeIterBase3& lhs, const TreeIterBase3& rhs) -> bool
{ return !lhs.equal(rhs); }

template <typename RowType, typename ColumnType>
class TreeValueProxy
{
public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  inline TreeValueProxy(const RowType& row, const TreeModelColumn<ColumnType>& column);
#endif

  inline auto operator=(const ColumnType& data) -> TreeValueProxy&;
  inline operator ColumnType() const;

private:
  RowType& row_;
  const TreeModelColumn<ColumnType>& column_;

  // no copy assignment
  auto operator=(const TreeValueProxy&) -> TreeValueProxy& = delete;
};


/** Typedefed as TreeModel::ConstRow.
 *
 * %TreeConstRow is a const version of %TreeRow. %TreeConstRow does not contain
 * methods for modifying the underlying TreeModel.
 *
 * @see TreeRow
 * @ingroup TreeView
 */
class GTKMM_API TreeConstRow : public TreeIterBase2
{
public:

  /** Use this to get the value of this @a column of this row.
   * This is a templated method, so the compiler will not allow you to provide an inappropriate type
   * of data for the model column.
   *
   * This is just a more convenient syntax that does the same thing as get_value().
   *
   * @param column The model column.
   */
  template <typename ColumnType> inline
  auto operator[](const TreeModelColumn<ColumnType>& column) const -> const TreeValueProxy<TreeConstRow, ColumnType>;

  /** Gets the value of this @a column of this row.
   *
   * See also operator[]().
   *
   * @param column The model column.
   * @result The value of this column of this row.
   */
  template <typename ColumnType>
  auto get_value(const TreeModelColumn<ColumnType>& column) const -> ColumnType;

  /** Use get_value(const TreeModelColumn<>& column) unless
   * you do not know the column type at compile-time.
   * If the @a data output argument is of an inappropriate C++ type then this might fail at runtime.
   * @param column The number of the column whose value you want to query.
   * @param[out] data An output argument which will contain the value of this column of this row.
   */
  template <typename ColumnType>
  void get_value(int column, ColumnType& data) const;

  /** This returns an STL-like container API, for iterating over the rows.
   * See also Gtk::TreeModel::children() for the top-level children.
   */
  auto children() const -> const TreeNodeConstChildren&;

  /** Gets a const_iterator to the parent row of this row.
   * @result A const_iterator to the parent row.
   */
  auto parent() const -> TreeIter<TreeConstRow>;

  /** Gets a const_iterator to this row.
   * @result A const_iterator to this row.
   */
  auto get_iter() const -> TreeIter<TreeConstRow>;

  /** Discover whether this is a valid row.
   * For instance,
   * @code
   * if (treerow)
   *   do_something();
   * @endcode
   *
   * @newin{3,22}
   */
  explicit operator bool() const;

private:
  // Forwarders to Gtk::TreeModel virtual methods.
  void get_value_impl(int column, Glib::ValueBase& value) const;

}; // class TreeConstRow

/** Typedefed as TreeModel::Row.
 *
 * Dereference a TreeModel::iterator to get the Row. Use operator[] or set_value()
 * and get_value() to access the values in the columns of this row.
 *
 * If the model contains a hierarchy of rows (such as Gtk::TreeStore), then you
 * can access the child rows with children().
 *
 * You can use get_iter() to get an iterator that points to the Row, e.g. for use
 * in a parameter that takes a const&nbsp;TreeModel::iterator& or a
 * const&nbsp;TreeModel::const_iterator&.
 *
 * @ingroup TreeView
 */
class GTKMM_API TreeRow : public TreeConstRow
{
public:

  // Inherit the const versions
  using TreeConstRow::operator[];
  using TreeConstRow::children;
  using TreeConstRow::parent;
  using TreeConstRow::get_iter;

  /** Use this to set and get the value of this @a column of this row.
   * This is a templated method, so the compiler will not allow you to provide an inappropriate type
   * of data for the model column.
   *
   * This is just a more convenient syntax that does the same thing as set_value() and get_value().
   *
   * @param column The model column.
   */
  template <typename ColumnType> inline
  auto operator[](const TreeModelColumn<ColumnType>& column) -> TreeValueProxy<TreeRow, ColumnType>;

  /** Sets the value of this @a column of this row.
   * This is a templated method, so the compiler will not allow you to provide an inappropriate type
   * of @a data for the model column.
   *
   * See also operator[]().
   *
   * @param column The model column.
   * @param data The new value to use for this column of this row.
   */
  template <typename ColumnType>
  void set_value(const TreeModelColumn<ColumnType>& column, const ColumnType& data);

  /** Use set_value(const TreeModelColumn<>& column, const ColumnType& data) unless
   * you do not know the column type at compile-time.
   * If the @a data is of an inappropriate C++ type then this might fail at runtime.
   * @param column The number of the column whose value you want to change.
   * @param data The new value to use for this column of this row.
   */
  template <typename ColumnType>
  void set_value(int column, const ColumnType& data);

  /** This returns an STL-like container API, for iterating over the rows.
   * See also Gtk::TreeModel::children() for the top-level children.
   */
  auto children() -> TreeNodeChildren&;

  /** Gets an iterator to the parent row of this row.
   * @result An iterator to the parent row.
   */
  auto parent() -> TreeIter<TreeRow>;

  /** Gets an iterator to this row.
   * @result An iterator to this row.
   */
  auto get_iter() -> TreeIter<TreeRow>;

private:
  // Forwarders to Gtk::TreeModel virtual methods.
  void set_value_impl(int column, const Glib::ValueBase& value);
  void get_value_impl(int column, Glib::ValueBase& value) const;

}; // class TreeRow


//TODO: Document begin(), end(), size(), etc, in an STL-style way. murrayc.

/** Typedefed as TreeModel::ConstChildren.
 *
 * Virtual container of TreeModel::ConstRow items.
 *
 * %TreeNodeConstChildren is a const version of %TreeNodeChildren.
 * %TreeNodeConstChildren does not contain methods for modifying the underlying TreeModel.
 *
 * @see TreeNodeChildren
 * @ingroup TreeView
 */
class GTKMM_API TreeNodeConstChildren : public TreeIterBase2
{
public:
  using value_type      = Gtk::TreeConstRow;
  using size_type       = unsigned int;
  using difference_type = int;
  using const_iterator  = Gtk::TreeIter<Gtk::TreeConstRow>;

  auto begin() const -> const_iterator;
  auto end()   const -> const_iterator;

  auto operator[](size_type index) const -> const value_type;

  auto size() const -> size_type;
  auto empty() const -> bool;

  /** Discover whether this is a valid container.
   * For instance,
   * @code
   * if (children)
   *   do_something();
   * @endcode
   *
   * @newin{3,22}
   */
  explicit operator bool() const
  {
    return !empty();
  }

#ifndef DOXYGEN_SHOULD_SKIP_THIS

  explicit TreeNodeConstChildren(const TreeModel* model)
    : TreeIterBase2(const_cast<TreeModel*>(model)) {}

  auto get_parent_gobject() const -> const GtkTreeIter*
  { return (gobject_.stamp != 0) ? &gobject_ : nullptr; }

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

}; // class TreeNodeConstChildren

/** Typedefed as TreeModel::Children.
 *
 * Virtual container of TreeModel::Row items.
 *
 * @ingroup TreeView
 */
class GTKMM_API TreeNodeChildren : public TreeNodeConstChildren
{
public:
  using value_type      = Gtk::TreeRow;
  using iterator        = Gtk::TreeIter<Gtk::TreeRow>;

  // Inherit the const versions
  using TreeNodeConstChildren::begin;
  using TreeNodeConstChildren::end;
  using TreeNodeConstChildren::operator[];

  auto begin() -> iterator;
  auto end() -> iterator;

  auto operator[](size_type index) -> value_type;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

  explicit TreeNodeChildren(TreeModel* model)
    : TreeNodeConstChildren(model) {}

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

}; // class TreeNodeChildren


#ifndef DOXYGEN_SHOULD_SKIP_THIS

/**** Gtk::TreeIter ********************************************************/

template <typename T>
TreeIter<T>::TreeIter()
:
  TreeIterBase3()
{}

template <typename T>
template <typename T2, typename>
TreeIter<T>::TreeIter(const TreeIter<T2>& src)
:
  TreeIterBase3()
{
  gobject_ = src.gobject_;
  model_   = src.model_;
  is_end_  = src.is_end_;
}

template <typename T>
template <typename T2, typename>
auto TreeIter<T>::operator=(const TreeIter<T2>& src) -> TreeIter<T>&
{
  gobject_ = src.gobject_;
  model_   = src.model_;
  is_end_  = src.is_end_;
}

template <typename T>
TreeIter<T>::TreeIter(TreeModel* model)
:
  TreeIterBase3(model)
{}

template <typename T>
TreeIter<T>::TreeIter(GtkTreeModel* model, const GtkTreeIter* iter)
:
  TreeIterBase3(model, iter)
{}

template <typename T> inline
auto TreeIter<T>::operator++() -> TreeIter<T>&
{
  plus_plus();
  return *this;
}

template <typename T> inline
auto TreeIter<T>::operator++(int) -> TreeIter<T>
{
  TreeIter previous(*this);
  plus_plus();
  return previous;
}

template <typename T> inline
auto TreeIter<T>::operator--() -> TreeIter<T>&
{
  minus_minus();
  return *this;
}

template <typename T> inline
auto TreeIter<T>::operator--(int) -> TreeIter<T>
{
  TreeIter next(*this);
  minus_minus();
  return next;
}

template <typename T> inline
auto TreeIter<T>::operator*() const -> typename TreeIter<T>::reference
{
  return static_cast<reference>(static_cast<TreeIterBase2&>(const_cast<TreeIter&>(*this)));
}

template <typename T> inline
auto TreeIter<T>::operator->() const -> typename TreeIter<T>::pointer
{
  return static_cast<pointer>(static_cast<TreeIterBase2*>(const_cast<TreeIter*>(this)));
}

template <typename T> inline
TreeIter<T>::operator bool() const
{
  // Test whether the GtkTreeIter is valid and not an end iterator. This check
  // is almost the same as the private VALID_ITER() macro in gtkliststore.c and
  // gtktreestore.c.
  return !is_end_ && gobject_.stamp;
}

/**** Gtk::TreeValueProxy<> ************************************************/

template <typename RowType, typename ColumnType> inline
TreeValueProxy<RowType, ColumnType>::TreeValueProxy(const RowType& row, const TreeModelColumn<ColumnType>& column)
:
  row_    (const_cast<RowType&>(row)),
  column_ (column)
{}

template <typename RowType, typename ColumnType> inline
auto TreeValueProxy<RowType, ColumnType>::operator=(const ColumnType& data) -> TreeValueProxy<RowType, ColumnType>&
{
  // If row_ is a TreeConstRow and TreeValueProxy::operator=() is actually used,
  // this will fail at compile time. TreeConstRow has no set_value() method.
  // This failure is deliberate.
  row_.set_value(column_, data);
  return *this;
}

template <typename RowType, typename ColumnType> inline
TreeValueProxy<RowType, ColumnType>::operator ColumnType() const
{
  return row_.get_value(column_);
}


/**** Gtk::TreeConstRow and Gtk::TreeRow **************************************/

template <typename ColumnType> inline
auto TreeConstRow::operator[](const TreeModelColumn<ColumnType>& column) const -> const TreeValueProxy<TreeConstRow, ColumnType>
{
  return TreeValueProxy<TreeConstRow, ColumnType>(*this, column);
}

template <typename ColumnType> inline
auto TreeRow::operator[](const TreeModelColumn<ColumnType>& column) -> TreeValueProxy<TreeRow, ColumnType>
{
  return TreeValueProxy<TreeRow, ColumnType>(*this, column);
}

template <typename ColumnType>
void TreeRow::set_value(const TreeModelColumn<ColumnType>& column, const ColumnType& data)
{
  using ValueType = typename Gtk::TreeModelColumn<ColumnType>::ValueType;

  ValueType value;
  value.init(column.type());

  value.set(data);
  this->set_value_impl(column.index(), value);
}

template <typename ColumnType>
void TreeRow::set_value(int column, const ColumnType& data)
{
  // This could fail at run-time, because the wrong ColumnType might be used.
  // It's only for dynamically generated model columns.

  using ValueType = typename Gtk::TreeModelColumn<ColumnType>::ValueType;

  ValueType value;
  value.init(ValueType::value_type());

  value.set(data);
  this->set_value_impl(column, value);
}

template <typename ColumnType>
auto TreeConstRow::get_value(const TreeModelColumn<ColumnType>& column) const -> ColumnType
{
  using ValueType = typename Gtk::TreeModelColumn<ColumnType>::ValueType;

  ValueType value;
  this->get_value_impl(column.index(), value);

  return value.get();
}

template <typename ColumnType>
void TreeConstRow::get_value(int column, ColumnType& data) const
{
  // This could fail at run-time, because the wrong ColumnType might be used.
  // It's only for dynamically generated model columns.

  using ValueType = typename Gtk::TreeModelColumn<ColumnType>::ValueType;

  ValueType value;
  this->get_value_impl(column, value);

  data = value.get();
}

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

} // namespace Gtk


namespace Glib
{

#ifndef DOXYGEN_SHOULD_SKIP_THIS
template <>
class GTKMM_API Value<Gtk::TreeIterBase> : public Glib::Value_Boxed<Gtk::TreeIterBase>
{};
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

} // namespace Glib


#endif /* _GTKMM_TREEITER_H */

