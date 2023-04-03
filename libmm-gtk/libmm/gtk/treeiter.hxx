// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_TREEITER_H
#define _GTKMM_TREEITER_H

#include <libmm/gtk/mm-gtkconfig.hxx>

#ifndef GTKMM_DISABLE_DEPRECATED

  #include <libmm/glib/ustring.hxx>
  #include <sigc++/sigc++.h>

  #include <gtk/gtk.h>
  #include <iterator>
  #include <libmm/gtk/treemodelcolumn.hxx>
  #include <type_traits>

namespace Gtk
{

  class LIBMM_GTK_SYMEXPORT TreeModel;
  template <typename T>
  class TreeIter;
  class LIBMM_GTK_SYMEXPORT TreeConstRow;
  class LIBMM_GTK_SYMEXPORT TreeRow;
  class LIBMM_GTK_SYMEXPORT TreeNodeConstChildren;
  class LIBMM_GTK_SYMEXPORT TreeNodeChildren;

  class LIBMM_GTK_SYMEXPORT TreeIterBase
  {
  public:
  #ifndef DOXYGEN_SHOULD_SKIP_THIS
    using CppObjectType = TreeIterBase;
    using BaseObjectType = GtkTreeIter;
  #endif

    TreeIterBase (const TreeIterBase& other) noexcept;
    auto
    operator= (const TreeIterBase& other) noexcept -> TreeIterBase&;

    TreeIterBase (TreeIterBase&& other) noexcept;
    auto
    operator= (TreeIterBase&& other) noexcept -> TreeIterBase&;

    static auto
    get_type () -> GType G_GNUC_CONST;

    TreeIterBase ();

    explicit TreeIterBase (const GtkTreeIter* gobject);

    auto
    gobj () -> GtkTreeIter*
    {
      return &gobject_;
    }

    auto
    gobj () const -> const GtkTreeIter*
    {
      return &gobject_;
    }

  protected:
    GtkTreeIter gobject_;

  private:
  };

  class LIBMM_GTK_SYMEXPORT TreeIterBase2 : public TreeIterBase
  {
  protected:
  #ifndef DOXYGEN_SHOULD_SKIP_THIS
    TreeIterBase2 ();
    explicit TreeIterBase2 (TreeModel* model);
    TreeIterBase2 (GtkTreeModel* model, const GtkTreeIter* iter);

    TreeModel* model_;
    bool is_end_;

    friend class Gtk::TreeIter<Gtk::TreeConstRow>;

    friend class Gtk::TreeConstRow;
    friend class Gtk::TreeRow;
    friend class Gtk::TreeNodeConstChildren;
    friend class Gtk::TreeNodeChildren;
  #endif
  };

  class LIBMM_GTK_SYMEXPORT TreeIterBase3 : public TreeIterBase2
  {
  public:
    auto
    equal (const TreeIterBase3& other) const -> bool;

    auto
    get_stamp () const -> int;

    auto
    set_stamp (int stamp) -> void;

  #ifndef DOXYGEN_SHOULD_SKIP_THIS

    auto
    set_model_refptr (const Glib::RefPtr<TreeModel>& model) -> void;
    auto
    set_model_gobject (GtkTreeModel* model) -> void;
    auto
    get_model_gobject () -> GtkTreeModel*;
    auto
    get_model_gobject () const -> const GtkTreeModel*;

    auto
    setup_end_iterator (const TreeIterBase3& last_valid) -> void;

    auto
    get_gobject_if_not_end () const -> const GtkTreeIter*
    {
      return (!is_end_) ? &gobject_ : nullptr;
    }

    auto
    get_parent_gobject_if_end () const -> const GtkTreeIter*
    {
      return (is_end_ && gobject_.stamp) ? &gobject_ : nullptr;
    }

  protected:
    TreeIterBase3 ();
    explicit TreeIterBase3 (TreeModel* model);
    TreeIterBase3 (GtkTreeModel* model, const GtkTreeIter* iter);

    auto
    plus_plus () -> void;

    auto
    minus_minus () -> void;
  #endif
  };

  template <typename T>
  class TreeIter : public TreeIterBase3
  {
    static_assert (std::is_same<T, TreeRow>::value ||
                       std::is_same<T, TreeConstRow>::value,
                   "TreeIter can only iterate over TreeRow or TreeConstRow");

  public:
    using iterator_category = std::bidirectional_iterator_tag;
    using value_type = T;
    using difference_type = int;
    using reference = T&;
    using pointer = T*;

    TreeIter ();

    template <typename T2,
              typename = typename std::enable_if<
                  std::is_same<T, TreeConstRow>::value &&
                      std::is_same<T2, TreeRow>::value,
                  T2>::type>
    TreeIter (const TreeIter<T2>& src);

    template <typename T2,
              typename = typename std::enable_if<
                  std::is_same<T, TreeConstRow>::value &&
                      std::is_same<T2, TreeRow>::value,
                  T2>::type>
    auto
    operator= (const TreeIter<T2>& src) -> TreeIter&;

  #ifndef DOXYGEN_SHOULD_SKIP_THIS
    explicit TreeIter (TreeModel* model);
    TreeIter (GtkTreeModel* model, const GtkTreeIter* iter);
  #endif

    auto
    operator++ () -> TreeIter&;
    auto
    operator++ (int) -> TreeIter;

    auto
    operator-- () -> TreeIter&;

    auto
    operator-- (int) -> TreeIter;

    inline auto
    operator* () const -> reference;
    inline auto
    operator->() const -> pointer;

    inline explicit operator bool () const;
  };

  inline auto
  operator== (const TreeIterBase3& lhs, const TreeIterBase3& rhs) -> bool
  {
    return lhs.equal (rhs);
  }

  inline auto
  operator!= (const TreeIterBase3& lhs, const TreeIterBase3& rhs) -> bool
  {
    return !lhs.equal (rhs);
  }

  template <typename RowType, typename ColumnType>
  class TreeValueProxy
  {
  public:
  #ifndef DOXYGEN_SHOULD_SKIP_THIS
    inline TreeValueProxy (const RowType& row,
                           const TreeModelColumn<ColumnType>& column);
  #endif

    inline auto
    operator= (const ColumnType& data) -> TreeValueProxy&;
    inline operator ColumnType () const;

  private:
    RowType& row_;
    const TreeModelColumn<ColumnType>& column_;

    auto
    operator= (const TreeValueProxy&) -> TreeValueProxy& = delete;
  };

  class LIBMM_GTK_SYMEXPORT TreeConstRow : public TreeIterBase2
  {
  public:
    template <typename ColumnType>
    inline auto
    operator[] (const TreeModelColumn<ColumnType>& column) const
        -> const TreeValueProxy<TreeConstRow, ColumnType>;

    template <typename ColumnType>
    auto
    get_value (const TreeModelColumn<ColumnType>& column) const -> ColumnType;

    template <typename ColumnType>
    auto
    get_value (int column, ColumnType& data) const -> void;

    auto
    children () const -> const TreeNodeConstChildren&;

    auto
    parent () const -> TreeIter<TreeConstRow>;

    auto
    get_iter () const -> TreeIter<TreeConstRow>;

    explicit operator bool () const;

  private:
    auto
    get_value_impl (int column, Glib::ValueBase& value) const -> void;
  };

  class LIBMM_GTK_SYMEXPORT TreeRow : public TreeConstRow
  {
  public:
    using TreeConstRow::operator[];
    using TreeConstRow::children;
    using TreeConstRow::get_iter;
    using TreeConstRow::parent;

    template <typename ColumnType>
    inline auto
    operator[] (const TreeModelColumn<ColumnType>& column)
        -> TreeValueProxy<TreeRow, ColumnType>;

    template <typename ColumnType>
    auto
    set_value (const TreeModelColumn<ColumnType>& column,
               const ColumnType& data) -> void;

    template <typename ColumnType>
    auto
    set_value (int column, const ColumnType& data) -> void;

    auto
    children () -> TreeNodeChildren&;

    auto
    parent () -> TreeIter<TreeRow>;

    auto
    get_iter () -> TreeIter<TreeRow>;

  private:
    auto
    set_value_impl (int column, const Glib::ValueBase& value) -> void;
    auto
    get_value_impl (int column, Glib::ValueBase& value) const -> void;
  };

  class LIBMM_GTK_SYMEXPORT TreeNodeConstChildren : public TreeIterBase2
  {
  public:
    using value_type = Gtk::TreeConstRow;
    using size_type = unsigned int;
    using difference_type = int;
    using const_iterator = Gtk::TreeIter<Gtk::TreeConstRow>;

    auto
    begin () const -> const_iterator;
    auto
    end () const -> const_iterator;

    auto
    operator[] (size_type index) const -> const value_type;

    auto
    size () const -> size_type;
    auto
    empty () const -> bool;

    explicit operator bool () const
    {
      return !empty ();
    }

  #ifndef DOXYGEN_SHOULD_SKIP_THIS

    explicit TreeNodeConstChildren (const TreeModel* model)
      : TreeIterBase2 (const_cast<TreeModel*> (model))
    {
    }

    auto
    get_parent_gobject () const -> const GtkTreeIter*
    {
      return (gobject_.stamp != 0) ? &gobject_ : nullptr;
    }

  #endif
  };

  class LIBMM_GTK_SYMEXPORT TreeNodeChildren : public TreeNodeConstChildren
  {
  public:
    using value_type = Gtk::TreeRow;
    using iterator = Gtk::TreeIter<Gtk::TreeRow>;

    using TreeNodeConstChildren::begin;
    using TreeNodeConstChildren::end;
    using TreeNodeConstChildren::operator[];

    auto
    begin () -> iterator;
    auto
    end () -> iterator;

    auto
    operator[] (size_type index) -> value_type;

  #ifndef DOXYGEN_SHOULD_SKIP_THIS

    explicit TreeNodeChildren (TreeModel* model)
      : TreeNodeConstChildren (model)
    {
    }

  #endif
  };

  #ifndef DOXYGEN_SHOULD_SKIP_THIS

  template <typename T>
  TreeIter<T>::TreeIter ()
    : TreeIterBase3 ()
  {
  }

  template <typename T>
  template <typename T2, typename>
  TreeIter<T>::TreeIter (const TreeIter<T2>& src)
    : TreeIterBase3 ()
  {
    gobject_ = src.gobject_;
    model_ = src.model_;
    is_end_ = src.is_end_;
  }

  template <typename T>
  template <typename T2, typename>
  auto
  TreeIter<T>::operator= (const TreeIter<T2>& src) -> TreeIter<T>&
  {
    gobject_ = src.gobject_;
    model_ = src.model_;
    is_end_ = src.is_end_;
  }

  template <typename T>
  TreeIter<T>::TreeIter (TreeModel* model)
    : TreeIterBase3 (model)
  {
  }

  template <typename T>
  TreeIter<T>::TreeIter (GtkTreeModel* model, const GtkTreeIter* iter)
    : TreeIterBase3 (model, iter)
  {
  }

  template <typename T>
  inline auto
  TreeIter<T>::operator++ () -> TreeIter<T>&
  {
    plus_plus ();
    return *this;
  }

  template <typename T>
  inline auto
  TreeIter<T>::operator++ (int) -> TreeIter<T>
  {
    TreeIter previous (*this);
    plus_plus ();
    return previous;
  }

  template <typename T>
  inline auto
  TreeIter<T>::operator-- () -> TreeIter<T>&
  {
    minus_minus ();
    return *this;
  }

  template <typename T>
  inline auto
  TreeIter<T>::operator-- (int) -> TreeIter<T>
  {
    TreeIter next (*this);
    minus_minus ();
    return next;
  }

  template <typename T>
  inline auto
  TreeIter<T>::operator* () const -> typename TreeIter<T>::reference
  {
    return static_cast<reference> (
        static_cast<TreeIterBase2&> (const_cast<TreeIter&> (*this)));
  }

  template <typename T>
  inline auto
  TreeIter<T>::operator->() const -> typename TreeIter<T>::pointer
  {
    return static_cast<pointer> (
        static_cast<TreeIterBase2*> (const_cast<TreeIter*> (this)));
  }

  template <typename T>
  inline TreeIter<T>::operator bool () const
  {
    return !is_end_ && gobject_.stamp;
  }

  template <typename RowType, typename ColumnType>
  inline TreeValueProxy<RowType, ColumnType>::TreeValueProxy (
      const RowType& row,
      const TreeModelColumn<ColumnType>& column)
    : row_ (const_cast<RowType&> (row)),
      column_ (column)
  {
  }

  template <typename RowType, typename ColumnType>
  inline auto
  TreeValueProxy<RowType, ColumnType>::operator= (const ColumnType& data) -> TreeValueProxy<RowType, ColumnType>&
  {
    row_.set_value (column_, data);
    return *this;
  }

  template <typename RowType, typename ColumnType>
  inline TreeValueProxy<RowType, ColumnType>::operator ColumnType () const
  {
    return row_.get_value (column_);
  }

  template <typename ColumnType>
  inline auto
  TreeConstRow::operator[] (const TreeModelColumn<ColumnType>& column) const -> const TreeValueProxy<TreeConstRow, ColumnType>
  {
    return TreeValueProxy<TreeConstRow, ColumnType> (*this, column);
  }

  template <typename ColumnType>
  inline auto
  TreeRow::operator[] (const TreeModelColumn<ColumnType>& column) -> TreeValueProxy<TreeRow, ColumnType>
  {
    return TreeValueProxy<TreeRow, ColumnType> (*this, column);
  }

  template <typename ColumnType>
  auto
  TreeRow::set_value (const TreeModelColumn<ColumnType>& column,
                      const ColumnType& data) -> void
  {
    using ValueType = typename Gtk::TreeModelColumn<ColumnType>::ValueType;

    ValueType value;
    value.init (column.type ());

    value.set (data);
    this->set_value_impl (column.index (), value);
  }

  template <typename ColumnType>
  auto
  TreeRow::set_value (int column, const ColumnType& data) -> void
  {
    using ValueType = typename Gtk::TreeModelColumn<ColumnType>::ValueType;

    ValueType value;
    value.init (ValueType::value_type ());

    value.set (data);
    this->set_value_impl (column, value);
  }

  template <typename ColumnType>
  auto
  TreeConstRow::get_value (const TreeModelColumn<ColumnType>& column) const -> ColumnType
  {
    using ValueType = typename Gtk::TreeModelColumn<ColumnType>::ValueType;

    ValueType value;
    this->get_value_impl (column.index (), value);

    return value.get ();
  }

  template <typename ColumnType>
  auto
  TreeConstRow::get_value (int column, ColumnType& data) const -> void
  {
    using ValueType = typename Gtk::TreeModelColumn<ColumnType>::ValueType;

    ValueType value;
    this->get_value_impl (column, value);

    data = value.get ();
  }

  #endif

} // namespace Gtk

namespace Glib
{

  #ifndef DOXYGEN_SHOULD_SKIP_THIS
  template <>
  class LIBMM_GTK_SYMEXPORT Value<Gtk::TreeIterBase>
    : public Glib::Value_Boxed<Gtk::TreeIterBase>
  {
  };
  #endif

} // namespace Glib

#endif

#endif
