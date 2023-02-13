


#include <libmm-glib/mm-glib.hxx>

#include <libmm-gtk/treerowreference.hxx>
#include <libmm-gtk/treerowreference_p.hxx>


/* Copyright (C) 2002 The gtkmm Development Team
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

#include <gtk/gtk.h>


namespace Gtk
{

TreeRowReference::TreeRowReference(const Glib::RefPtr<TreeModel>& model, const TreeModel::Path& path)
:
  gobject_ ( gtk_tree_row_reference_new(model->gobj(), const_cast<GtkTreePath*>(path.gobj())) )
{}

TreeRowReference::operator bool() const
{
  return is_valid();
}

} // namespace Gtk


namespace
{
} // anonymous namespace


namespace Glib
{

auto wrap(GtkTreeRowReference* object, const bool take_copy) -> Gtk::TreeRowReference
{
  return Gtk::TreeRowReference(object, take_copy);
}

} // namespace Glib


namespace Gtk
{


// static
auto TreeRowReference::get_type() -> GType
{
  return gtk_tree_row_reference_get_type();
}

TreeRowReference::TreeRowReference()
:
  gobject_ (nullptr) // Allows creation of invalid wrapper, e.g. for output arguments to methods.
{}

TreeRowReference::TreeRowReference(const TreeRowReference& other)
:
  gobject_ (other.gobject_ ? gtk_tree_row_reference_copy(other.gobject_) : nullptr)
{}

TreeRowReference::TreeRowReference(TreeRowReference&& other) noexcept
:
  gobject_(other.gobject_)
{
  other.gobject_ = nullptr;
}

auto TreeRowReference::operator=(TreeRowReference&& other) noexcept -> TreeRowReference&
{
  TreeRowReference temp (std::move(other));
  swap(temp);
  return *this;
}

TreeRowReference::TreeRowReference(GtkTreeRowReference* gobject, const bool make_a_copy)
:
  // For BoxedType wrappers, make_a_copy is true by default.  The static
  // BoxedType wrappers must always take a copy, thus make_a_copy = true
  // ensures identical behaviour if the default argument is used.
  gobject_ (make_a_copy && gobject ? gtk_tree_row_reference_copy(gobject) : gobject)
{}

auto TreeRowReference::operator=(const TreeRowReference& other) -> TreeRowReference&
{
  TreeRowReference temp (other);
  swap(temp);
  return *this;
}

TreeRowReference::~TreeRowReference() noexcept
{
  if(gobject_)
    gtk_tree_row_reference_free(gobject_);
}

auto TreeRowReference::swap (TreeRowReference &other) noexcept -> void
{
  std::swap(gobject_, other.gobject_);
}

auto TreeRowReference::gobj_copy() const -> GtkTreeRowReference*
{
  return gtk_tree_row_reference_copy(gobject_);
}


auto TreeRowReference::get_path() const -> TreeModel::Path
{
  return TreePath(gtk_tree_row_reference_get_path(const_cast<GtkTreeRowReference*>(gobj())), false);
}

auto TreeRowReference::get_model() -> Glib::RefPtr<TreeModel>
{
  auto retvalue = Glib::wrap(gtk_tree_row_reference_get_model(gobj()));
  if(retvalue)
    retvalue->reference(); //The function does not do a ref for us.
  return retvalue;
}

auto TreeRowReference::get_model() const -> Glib::RefPtr<const TreeModel>
{
  return const_cast<TreeRowReference*>(this)->get_model();
}

auto TreeRowReference::is_valid() const -> bool
{
  return gtk_tree_row_reference_valid(const_cast<GtkTreeRowReference*>(gobj()));
}


} // namespace Gtk

