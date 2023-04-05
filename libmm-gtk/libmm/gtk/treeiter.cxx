// SPDX-License-Identifier: LGPL-2.1-or-later

#undef GTK_DISABLE_DEPRECATED
#define GDK_DISABLE_DEPRECATION_WARNINGS 1

#include <libmm/gtk/mm-gtkconfig.hxx>
#ifndef GTKMM_DISABLE_DEPRECATED

  #include <libmm/glib/mm-glib.hxx>

  #include <libmm/gtk/treeiter.hxx>
  #include <libmm/gtk/treeiter_p.hxx>

  #include <cstring>

  #include <gtk/gtk.h>
  #include <libmm/gtk/treemodel.hxx>

namespace gtk
{

  TreeIterBase2::TreeIterBase2 ()
    : TreeIterBase (),
      model_ (nullptr),
      is_end_ (false)
  {
  }

  TreeIterBase2::TreeIterBase2 (TreeModel* model)
    : TreeIterBase (),
      model_ (model),
      is_end_ (false)
  {
  }

  TreeIterBase2::TreeIterBase2 (GtkTreeModel* model, const GtkTreeIter* iter)
    : TreeIterBase (iter),
      model_ (dynamic_cast<TreeModel*> (glib::wrap_auto ((GObject*) model))),
      is_end_ (iter == nullptr)
  {
  }

  TreeIterBase3::TreeIterBase3 ()
    : TreeIterBase2 ()
  {
  }

  TreeIterBase3::TreeIterBase3 (TreeModel* model)
    : TreeIterBase2 (model)
  {
  }

  TreeIterBase3::TreeIterBase3 (GtkTreeModel* model, const GtkTreeIter* iter)
    : TreeIterBase2 (model, iter)
  {
  }

  auto
  TreeIterBase3::plus_plus () -> void
  {
    g_assert (!is_end_);

    auto previous = gobject_;

    if (!gtk_tree_model_iter_next (model_->gobj (), &gobject_))
    {
      is_end_ = true;
      gtk_tree_model_iter_parent (glib::unwrap (model_), &gobject_, &previous);
    }
  }

  auto
  TreeIterBase3::minus_minus () -> void
  {
    if (!is_end_)
    {
      gtk_tree_model_iter_previous (glib::unwrap (model_), &gobject_);
    }
    else
    {
      auto next = gobject_;
      const auto parent = (next.stamp != 0) ? &next : nullptr;

      const int index =
          gtk_tree_model_iter_n_children (glib::unwrap (model_), parent) - 1;
      is_end_ = !gtk_tree_model_iter_nth_child (glib::unwrap (model_),
                                                &gobject_,
                                                parent,
                                                index);

      g_assert (!is_end_);
    }
  }

  auto
  TreeIterBase3::equal (const TreeIterBase3& other) const -> bool
  {
    g_assert (model_ == other.model_);

    g_assert (gobject_.stamp == other.gobject_.stamp || is_end_ ||
              other.is_end_);

    return (is_end_ == other.is_end_) &&
           (gobject_.user_data == other.gobject_.user_data) &&
           (gobject_.user_data2 == other.gobject_.user_data2) &&
           (gobject_.user_data3 == other.gobject_.user_data3);
  }

  auto
  TreeIterBase3::setup_end_iterator (const TreeIterBase3& last_valid) -> void
  {
    g_assert (model_ == last_valid.model_);

    if (last_valid.is_end_)
      gobject_ = last_valid.gobject_;
    else
      gtk_tree_model_iter_parent (
          model_->gobj (),
          &gobject_,
          const_cast<GtkTreeIter*> (&last_valid.gobject_));

    is_end_ = true;
  }

  auto
  TreeIterBase3::set_model_refptr (const glib::RefPtr<TreeModel>& model) -> void
  {
    model_ = model.operator->();
  }

  auto
  TreeIterBase3::set_model_gobject (GtkTreeModel* model) -> void
  {
    model_ = dynamic_cast<TreeModel*> (glib::wrap_auto ((GObject*) model));
  }

  auto
  TreeIterBase3::get_model_gobject () -> GtkTreeModel*
  {
    return (model_) ? model_->gobj () : nullptr;
  }

  auto
  TreeIterBase3::get_model_gobject () const -> const GtkTreeModel*
  {
    return (model_) ? model_->gobj () : nullptr;
  }

  auto
  TreeIterBase3::get_stamp () const -> int
  {
    return gobj ()->stamp;
  }

  auto
  TreeIterBase3::set_stamp (int stamp) -> void
  {
    gobj ()->stamp = stamp;
  }

  auto
  TreeRow::children () -> TreeNodeChildren&
  {
    g_assert (!is_end_);

    return static_cast<TreeNodeChildren&> (static_cast<TreeIterBase2&> (*this));
  }

  auto
  TreeConstRow::children () const -> const TreeNodeConstChildren&
  {
    g_assert (!is_end_);

    return static_cast<const TreeNodeConstChildren&> (
        static_cast<const TreeIterBase2&> (*this));
  }

  auto
  TreeRow::parent () -> TreeIter<TreeRow>
  {
    TreeIter<TreeRow> iter (model_);

    if (is_end_)
      iter.gobject_ = gobject_;
    else
      gtk_tree_model_iter_parent (model_->gobj (), iter.gobj (), &gobject_);

    return iter;
  }

  auto
  TreeConstRow::parent () const -> TreeIter<TreeConstRow>
  {
    TreeIter<TreeConstRow> iter (model_);

    if (is_end_)
      iter.gobject_ = gobject_;
    else
      gtk_tree_model_iter_parent (model_->gobj (),
                                  iter.gobj (),
                                  const_cast<GtkTreeIter*> (&gobject_));

    return iter;
  }

  auto
  TreeRow::get_iter () -> TreeIter<TreeRow>
  {
    return static_cast<TreeIter<TreeRow>&> (
        static_cast<TreeIterBase2&> (*this));
  }

  auto
  TreeConstRow::get_iter () const -> TreeIter<TreeConstRow>
  {
    return static_cast<const TreeIter<TreeConstRow>&> (
        static_cast<const TreeIterBase2&> (*this));
  }

  auto
  TreeRow::set_value_impl (int column, const glib::ValueBase& value) -> void
  {
    model_->set_value_impl (
        static_cast<TreeIter<TreeRow>&> (static_cast<TreeIterBase2&> (*this)),
        column,
        value);
  }

  auto
  TreeRow::get_value_impl (int column, glib::ValueBase& value) const -> void
  {
    model_->get_value_impl (static_cast<const TreeIter<TreeConstRow>&> (
                                static_cast<const TreeIterBase2&> (*this)),
                            column,
                            value);
  }

  auto
  TreeConstRow::get_value_impl (int column, glib::ValueBase& value) const -> void
  {
    model_->get_value_impl (static_cast<const TreeIter<TreeConstRow>&> (
                                static_cast<const TreeIterBase2&> (*this)),
                            column,
                            value);
  }

  TreeConstRow::operator bool () const
  {
    return !is_end_ && gobject_.stamp;
  }

  auto
  TreeNodeChildren::begin () -> TreeNodeChildren::iterator
  {
    iterator iter (model_);

    if (gobject_.stamp != 0)
    {
      if (!gtk_tree_model_iter_children (model_->gobj (),
                                         iter.gobj (),
                                         &gobject_))
      {
        iter.gobject_ = gobject_;
        iter.is_end_ = true;
      }
    }
    else
    {
      if (!gtk_tree_model_get_iter_first (model_->gobj (), iter.gobj ()))
      {
        iter.is_end_ = true;
      }
    }

    return iter;
  }

  auto
  TreeNodeConstChildren::begin () const -> TreeNodeConstChildren::const_iterator
  {
    return const_cast<TreeNodeChildren*> (
               static_cast<const TreeNodeChildren*> (this))
        ->begin ();
  }

  auto
  TreeNodeChildren::end () -> TreeNodeChildren::iterator
  {
    iterator iter (model_);
    iter.gobject_ = gobject_;
    iter.is_end_ = true;
    return iter;
  }

  auto
  TreeNodeConstChildren::end () const -> TreeNodeConstChildren::const_iterator
  {
    return const_cast<TreeNodeChildren*> (
               static_cast<const TreeNodeChildren*> (this))
        ->end ();
  }

  auto
  TreeNodeChildren::operator[] (TreeNodeChildren::size_type index) -> TreeNodeChildren::value_type
  {
    iterator iter (model_);

    const auto parent = const_cast<GtkTreeIter*> (get_parent_gobject ());

    if (!gtk_tree_model_iter_nth_child (model_->gobj (),
                                        iter.gobj (),
                                        parent,
                                        index))
    {
      iter.gobject_ = gobject_;
      iter.is_end_ = true;
    }

    return *iter;
  }

  auto
  TreeNodeConstChildren::operator[] (TreeNodeChildren::size_type index) const -> const TreeNodeConstChildren::value_type
  {
    const_iterator iter (model_);

    const auto parent = const_cast<GtkTreeIter*> (get_parent_gobject ());

    if (!gtk_tree_model_iter_nth_child (model_->gobj (),
                                        iter.gobj (),
                                        parent,
                                        index))
    {
      iter.gobject_ = gobject_;
      iter.is_end_ = true;
    }

    return *iter;
  }

  auto
  TreeNodeConstChildren::size () const -> TreeNodeConstChildren::size_type
  {
    const auto parent = const_cast<GtkTreeIter*> (get_parent_gobject ());

    return gtk_tree_model_iter_n_children (model_->gobj (), parent);
  }

  auto
  TreeNodeConstChildren::empty () const -> bool
  {
    if (gobject_.stamp == 0)
    {
      GtkTreeIter dummy;
      return !gtk_tree_model_get_iter_first (model_->gobj (), &dummy);
    }

    return !gtk_tree_model_iter_has_child (
        model_->gobj (),
        const_cast<GtkTreeIter*> (&gobject_));
  }

} // namespace gtk

namespace
{
}

namespace gtk
{

  TreeIterBase::TreeIterBase (const TreeIterBase& other) noexcept
    : gobject_ (other.gobject_)
  {
  }

  auto
  TreeIterBase::operator= (const TreeIterBase& other) noexcept -> TreeIterBase&
  {
    gobject_ = other.gobject_;
    return *this;
  }

  TreeIterBase::TreeIterBase (TreeIterBase&& other) noexcept
    : gobject_ (std::move (other.gobject_))
  {
  }

  auto
  TreeIterBase::operator= (TreeIterBase&& other) noexcept -> TreeIterBase&
  {
    gobject_ = std::move (other.gobject_);
    return *this;
  }

  auto
  TreeIterBase::get_type () -> GType
  {
    return gtk_tree_iter_get_type ();
  }

  TreeIterBase::TreeIterBase ()
  {
    std::memset (&gobject_, 0, sizeof (GtkTreeIter));
  }

  TreeIterBase::TreeIterBase (const GtkTreeIter* gobject)
  {
    if (gobject)
      gobject_ = *gobject;
    else
      std::memset (&gobject_, 0, sizeof (GtkTreeIter));
  }

} // namespace gtk

#endif
