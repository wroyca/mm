


#include <mm/glib/mm-glib.hpp>

#include <mm/gtk/treeiter.hpp>
#include <mm/gtk/private/treeiter_p.hpp>

#include <cstring> // std::memset()

/* Copyright 1998-2002 The gtkmm Development Team
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

#include <mm/gtk/treemodel.hpp>
#include <gtk/gtk.h>


namespace Gtk
{

/**** Gtk::TreeIterBase2 ***************************************************/

TreeIterBase2::TreeIterBase2()
:
  TreeIterBase(),
  model_      (nullptr),
  is_end_     (false)
{}

TreeIterBase2::TreeIterBase2(TreeModel* model)
:
  TreeIterBase(),
  model_      (model),
  is_end_     (false)
{}

TreeIterBase2::TreeIterBase2(GtkTreeModel* model, const GtkTreeIter* iter)
:
  TreeIterBase(iter),
  model_      (dynamic_cast<TreeModel*>(Glib::wrap_auto((GObject*)model))),
  is_end_     (iter == nullptr)
{}

/**** Gtk::TreeIterBase3 ***************************************************/

TreeIterBase3::TreeIterBase3()
:
  TreeIterBase2()
{}

TreeIterBase3::TreeIterBase3(TreeModel* model)
:
  TreeIterBase2(model)
{}

TreeIterBase3::TreeIterBase3(GtkTreeModel* model, const GtkTreeIter* iter)
:
  TreeIterBase2(model, iter)
{}

auto TreeIterBase3::plus_plus () -> void
{
  g_assert(!is_end_);

  auto previous = gobject_;

  if(!gtk_tree_model_iter_next(model_->gobj(), &gobject_))
  {
    is_end_ = true;
    gtk_tree_model_iter_parent(Glib::unwrap(model_), &gobject_, &previous);
  }
}

auto TreeIterBase3::minus_minus () -> void
{
  if(!is_end_)
  {
    gtk_tree_model_iter_previous(Glib::unwrap(model_), &gobject_);
  }
  else // --end yields last
  {
    auto next = gobject_;
    const auto parent = next.stamp != 0 ? &next : nullptr;

    const int index = gtk_tree_model_iter_n_children(Glib::unwrap(model_), parent) - 1;
    is_end_ = !gtk_tree_model_iter_nth_child(Glib::unwrap(model_), &gobject_, parent, index);

    g_assert(!is_end_);
  }
}

/* There is no public gtk_tree_iter_equal(), so we must write our own.
 */
auto TreeIterBase3::equal(const TreeIterBase3& other) const -> bool
{
  g_assert(model_ == other.model_);

  // A GtkTreeIter has the same stamp value as its model.
  g_assert(gobject_.stamp == other.gobject_.stamp || is_end_ || other.is_end_);

  // If all user_data pointers are equal we can assume the iterators to be
  // equal.  This should be safe since GtkTreeIter lacks destroy notification,
  // thus there is no way to attach more data fields to the iterator.
  return is_end_ == other.is_end_ &&
         gobject_.user_data  == other.gobject_.user_data  &&
         gobject_.user_data2 == other.gobject_.user_data2 &&
         gobject_.user_data3 == other.gobject_.user_data3;
}

auto TreeIterBase3::setup_end_iterator (const TreeIterBase3 &last_valid) -> void
{
  g_assert(model_ == last_valid.model_);

  if(last_valid.is_end_)
    gobject_ = last_valid.gobject_;
  else
    gtk_tree_model_iter_parent(model_->gobj(), &gobject_, const_cast<GtkTreeIter*>(&last_valid.gobject_));

  is_end_ = true;
}

auto TreeIterBase3::set_model_refptr (const Glib::RefPtr <TreeModel> &model) -> void
{
  model_ = model.operator->();
}

auto TreeIterBase3::set_model_gobject (GtkTreeModel *model) -> void
{
  model_ = dynamic_cast<TreeModel*>(Glib::wrap_auto((GObject*) model));
}

auto TreeIterBase3::get_model_gobject() -> GtkTreeModel*
{
  return model_ ? model_->gobj() : nullptr;
}

auto TreeIterBase3::get_model_gobject() const -> const GtkTreeModel*
{
  return model_ ? model_->gobj() : nullptr;
}

auto TreeIterBase3::get_stamp() const -> int
{
  return gobj()->stamp;
}

auto TreeIterBase3::set_stamp (
  const int stamp) -> void
{
  gobj()->stamp = stamp;
}


/**** Gtk::TreeConstRow and Gtk::TreeRow **************************************/

auto TreeRow::children() -> TreeNodeChildren&
{
  g_assert(!is_end_);

  return static_cast<TreeNodeChildren&>(static_cast<TreeIterBase2&>(*this));
}

auto TreeConstRow::children() const -> const TreeNodeConstChildren&
{
  g_assert(!is_end_);

  return static_cast<const TreeNodeConstChildren&>(static_cast<const TreeIterBase2&>(*this));
}

auto TreeRow::parent() -> TreeIter<TreeRow>
{
  TreeIter<TreeRow> iter(model_);

  if(is_end_)
    iter.gobject_ = gobject_;
  else
    gtk_tree_model_iter_parent(model_->gobj(), iter.gobj(), &gobject_);

  return iter;
}

auto TreeConstRow::parent() const -> TreeIter<TreeConstRow>
{
  TreeIter<TreeConstRow> iter(model_);

  if(is_end_)
    iter.gobject_ = gobject_;
  else
    gtk_tree_model_iter_parent(model_->gobj(), iter.gobj(), const_cast<GtkTreeIter*>(&gobject_));

  return iter;
}

auto TreeRow::get_iter() -> TreeIter<TreeRow>
{
  return static_cast<TreeIter<TreeRow>&>(static_cast<TreeIterBase2&>(*this));
}

auto TreeConstRow::get_iter() const -> TreeIter<TreeConstRow>
{
  return static_cast<const TreeIter<TreeConstRow>&>(static_cast<const TreeIterBase2&>(*this));
}

auto TreeRow::set_value_impl (
  const int column, const Glib::ValueBase &value) -> void
{
  model_->set_value_impl(static_cast<TreeIter<TreeRow>&>(static_cast<TreeIterBase2&>(*this)), column, value);
}

auto TreeRow::get_value_impl (
  const int column, Glib::ValueBase &value) const -> void
{
  model_->get_value_impl(static_cast<const TreeIter<TreeConstRow>&>(static_cast<const TreeIterBase2&>(*this)), column, value);
}

auto TreeConstRow::get_value_impl (
  const int column, Glib::ValueBase &value) const -> void
{
  model_->get_value_impl(static_cast<const TreeIter<TreeConstRow>&>(static_cast<const TreeIterBase2&>(*this)), column, value);
}

TreeConstRow::operator bool() const
{
  // Test whether the GtkTreeIter is valid and not an end iterator. This check
  // is almost the same as the private VALID_ITER() macro in gtkliststore.c and
  // gtktreestore.c.
  return !is_end_ && gobject_.stamp;
}

/**** Gtk::TreeNodeConstChildren and Gtk::TreeNodeChildren ********************/

auto TreeNodeChildren::begin() -> iterator
{
  iterator iter(model_);

  // If the iterator is invalid (stamp == 0), assume a 'virtual' toplevel
  // node.  This behaviour is needed to implement Gtk::TreeModel::children().

  if(gobject_.stamp != 0)
  {
    if(!gtk_tree_model_iter_children(model_->gobj(), iter.gobj(), &gobject_))
    {
      // Assign the already known parent, in order to create an end iterator.
      iter.gobject_ = gobject_;
      iter.is_end_ = true;
    }
  }
  else
  {
    if(!gtk_tree_model_get_iter_first(model_->gobj(), iter.gobj()))
    {
      // No need to copy the GtkTreeIter, since iter.gobject_ is already empty.
      iter.is_end_ = true;
    }
  }

  return iter;
}

auto TreeNodeConstChildren::begin() const -> const_iterator
{
  return const_cast<TreeNodeChildren*>(static_cast<const TreeNodeChildren*>(this))->begin();
}

auto TreeNodeChildren::end() -> iterator
{
  // Just copy the parent, and turn it into an end iterator.
  iterator iter(model_);
  iter.gobject_ = gobject_;
  iter.is_end_ = true;
  return iter;
}

auto TreeNodeConstChildren::end() const -> const_iterator
{
  return const_cast<TreeNodeChildren*>(static_cast<const TreeNodeChildren*>(this))->end();
}

auto TreeNodeChildren::operator[](
  const size_type index) -> value_type
{
  iterator iter(model_);

  const auto parent = const_cast<GtkTreeIter*>(get_parent_gobject());

  if (!gtk_tree_model_iter_nth_child(model_->gobj(), iter.gobj(), parent, index))
  {
    // Assign the already known parent, in order to create an end iterator.
    iter.gobject_ = gobject_;
    iter.is_end_ = true;
  }

  return *iter;
}

auto TreeNodeConstChildren::operator[](
  const size_type index) const -> const value_type
{
  const_iterator iter(model_);

  const auto parent = const_cast<GtkTreeIter*>(get_parent_gobject());

  if(!gtk_tree_model_iter_nth_child(model_->gobj(), iter.gobj(), parent, index))
  {
    // Assign the already known parent, in order to create an end iterator.
    iter.gobject_ = gobject_;
    iter.is_end_ = true;
  }

  return *iter;
}

auto TreeNodeConstChildren::size() const -> size_type
{
  const auto parent = const_cast<GtkTreeIter*>(get_parent_gobject());

  return gtk_tree_model_iter_n_children(model_->gobj(), parent);
}

auto TreeNodeConstChildren::empty() const -> bool
{
  // If the iterator is invalid (stamp == 0), assume a 'virtual' toplevel
  // node.  This behaviour is needed to implement Gtk::TreeModel::children().

  if(gobject_.stamp == 0)
  {
    GtkTreeIter dummy;
    return !gtk_tree_model_get_iter_first(model_->gobj(), &dummy);
  }

  return !gtk_tree_model_iter_has_child(model_->gobj(), const_cast<GtkTreeIter*>(&gobject_));
}

} // namespace Gtk

namespace
{
} // anonymous namespace


namespace Gtk
{


TreeIterBase::TreeIterBase(const TreeIterBase& other) noexcept = default;

auto TreeIterBase::operator=(const TreeIterBase& other) noexcept -> TreeIterBase& = default;

TreeIterBase::TreeIterBase(TreeIterBase&& other) noexcept
:
  gobject_(std::move(other.gobject_))
{
  //We could wipe other.gobject_ via memset,
  //but that is not really necessary:
  //other.gobject_ = nullptr;
}

auto TreeIterBase::operator=(TreeIterBase&& other) noexcept -> TreeIterBase&
{
  gobject_ = std::move(other.gobject_);
  return *this;
}

// static
auto TreeIterBase::get_type() -> GType
{
  return gtk_tree_iter_get_type();
}

TreeIterBase::TreeIterBase()
{
  std::memset(&gobject_, 0, sizeof(GtkTreeIter));
}

TreeIterBase::TreeIterBase(const GtkTreeIter* gobject)
{
  if(gobject)
    gobject_ = *gobject;
  else
    std::memset(&gobject_, 0, sizeof(GtkTreeIter));
}


} // namespace Gtk


