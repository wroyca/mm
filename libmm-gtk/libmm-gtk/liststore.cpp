


#include <libmm-glib/mm-glib.hpp>

#include <libmm-gtk/liststore.hpp>
#include <libmm-gtk/liststore_p.hpp>


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

#include <libmm-glib/vectorutils.hpp>

#include <gtk/gtk.h>


namespace Gtk
{

ListStore::ListStore(const TreeModelColumnRecord& columns)
:
  // Mark this class as non-derived to allow C++ vfuncs to be skipped.
ObjectBase(nullptr),
Object(Glib::ConstructParams(liststore_class_.init()))
{
  gtk_list_store_set_column_types(gobj(), columns.size(), const_cast<GType*>(columns.types()));
}

auto ListStore::set_column_types (const TreeModelColumnRecord &columns) -> void
{
   gtk_list_store_set_column_types(gobj(), columns.size(), const_cast<GType*>(columns.types()));
}


auto ListStore::erase(const iterator& iter) -> iterator
{
  g_assert(iter.get_gobject_if_not_end() != nullptr);

  iterator next(iter);
  ++next;

  auto tmp = *iter.gobj();
  gtk_list_store_remove(gobj(), &tmp);

  return next;
}

auto ListStore::insert(const iterator& iter) -> iterator
{
  iterator new_pos(this);

  // get_gobject_if_not_end() returns 0 if iter is an end iterator, which
  // is in turn interpreted by gtk_list_store_insert_before() as a request to
  // insert at the end of the list.

  gtk_list_store_insert_before(
      gobj(), new_pos.gobj(),
      const_cast<GtkTreeIter*>(iter.get_gobject_if_not_end()));

  // GtkTreeIter::stamp should always have a value if it's valid.
  // For end iterators, we need to remember the iter's parent, and
  // this is what setup_end_iterator() does.

  if(new_pos.gobj()->stamp == 0)
    new_pos.setup_end_iterator(iter);

  return new_pos;
}

auto ListStore::insert_after(const iterator& iter) -> iterator
{
  iterator new_pos(this);

  // get_gobject_if_not_end() returns 0 if iter is an end iterator, which
  // is in turn interpreted by gtk_list_store_insert_after() as a request to
  // insert at the beginning of the list.

  gtk_list_store_insert_after(
      gobj(), new_pos.gobj(),
      const_cast<GtkTreeIter*>(iter.get_gobject_if_not_end()));

  // GtkTreeIter::stamp should always have a value if it's valid.
  // For end iterators, we need to remember the iter's parent, and
  // this is what setup_end_iterator() does.

  if(new_pos.gobj()->stamp == 0)
    new_pos.setup_end_iterator(iter);

  return new_pos;
}

auto ListStore::prepend() -> iterator
{
  iterator new_pos(this);
  gtk_list_store_prepend(gobj(), new_pos.gobj());
  return new_pos;
}

auto ListStore::append() -> iterator
{
  iterator new_pos(this);
  gtk_list_store_append(gobj(), new_pos.gobj());
  return new_pos;
}

auto ListStore::move (const iterator &source, const iterator &destination) -> void
{
  gtk_list_store_move_before(gobj(),
      const_cast<GtkTreeIter*>(source.get_gobject_if_not_end()),
      const_cast<GtkTreeIter*>(destination.get_gobject_if_not_end()));
}

auto ListStore::reorder (const std::vector <int> &new_order) -> void
{
  gtk_list_store_reorder(gobj(), Glib::ArrayHandler<int>::vector_to_array(new_order).data());
}

auto ListStore::set_value_impl (
  const iterator &row, const int column, const Glib::ValueBase &value) -> void
{
  gtk_list_store_set_value(
      gobj(), const_cast<GtkTreeIter*>(row.gobj()),
      column, const_cast<GValue*>(value.gobj()));
}

} // namespace Gtk


namespace
{
} // anonymous namespace


namespace Glib
{

auto wrap(GtkListStore* object, const bool take_copy) -> RefPtr<Gtk::ListStore>
{
  return Glib::make_refptr_for_instance<Gtk::ListStore>( dynamic_cast<Gtk::ListStore*> (wrap_auto((GObject*)object, take_copy)) );
  //We use dynamic_cast<> in case of multiple inheritance.
}

} /* namespace Glib */


namespace Gtk
{


/* The *_Class implementation: */

auto ListStore_Class::init() -> const Class&
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Class has to know the class init function to clone custom types.
    class_init_func_ = &ListStore_Class::class_init_function;

    // This is actually just optimized away, apparently with no harm.
    // Make sure that the parent type has been created.
    //CppClassParent::CppObjectType::get_type();

    // Create the wrapper type, with the same class/instance size as the base type.
    register_derived_type(gtk_list_store_get_type());

    // Add derived versions of interfaces, if the C type implements any interfaces:
  TreeModel::add_interface(get_type());
  TreeSortable::add_interface(get_type());
  TreeDragSource::add_interface(get_type());
  TreeDragDest::add_interface(get_type());
  Buildable::add_interface(get_type());

  }

  return *this;
}


auto ListStore_Class::class_init_function (void *g_class, void *class_data) -> void
{
  const auto klass = static_cast<BaseClassType*>(g_class);
  CppClassParent::class_init_function(klass, class_data);


}


auto ListStore_Class::wrap_new(GObject* object) -> Glib::ObjectBase*
{
  return new ListStore((GtkListStore*)object);
}


/* The implementation: */

auto ListStore::gobj_copy() -> GtkListStore*
{
  reference();
  return gobj();
}

ListStore::ListStore(const Glib::ConstructParams& construct_params)
: Object(construct_params)
{

}

ListStore::ListStore(GtkListStore* castitem)
: Object((GObject*)castitem)
{}


ListStore::ListStore(ListStore&& src) noexcept
: Object(std::move(src))
  , TreeModel(std::move(src))
  , TreeSortable(std::move(src))
  , TreeDragSource(std::move(src))
  , TreeDragDest(std::move(src))
  , Buildable(std::move(src))
{}

auto ListStore::operator=(ListStore&& src) noexcept -> ListStore&
{
  Object::operator=(std::move(src));
  TreeModel::operator=(std::move(src));
  TreeSortable::operator=(std::move(src));
  TreeDragSource::operator=(std::move(src));
  TreeDragDest::operator=(std::move(src));
  Buildable::operator=(std::move(src));
  return *this;
}


ListStore::~ListStore() noexcept = default;

ListStore::CppClassType ListStore::liststore_class_; // initialize static member

auto ListStore::get_type() -> GType
{
  return liststore_class_.init().get_type();
}


auto ListStore::get_base_type() -> GType
{
  return gtk_list_store_get_type();
}


ListStore::ListStore()
:
  // Mark this class as non-derived to allow C++ vfuncs to be skipped.
ObjectBase(nullptr),
Object(Glib::ConstructParams(liststore_class_.init()))
{


}

auto ListStore::create(const TreeModelColumnRecord& columns) -> Glib::RefPtr<ListStore>
{
  return Glib::make_refptr_for_instance<ListStore>( new ListStore(columns) );
}

auto ListStore::iter_swap (const iterator &a, const iterator &b) -> void
{
  gtk_list_store_swap(gobj(), const_cast<GtkTreeIter*>(a.gobj()), const_cast<GtkTreeIter*>(b.gobj()));
}

auto ListStore::clear () -> void
{
  gtk_list_store_clear(gobj());
}

auto ListStore::iter_is_valid(const const_iterator& iter) const -> bool
{
  return gtk_list_store_iter_is_valid(const_cast<GtkListStore*>(gobj()), const_cast<GtkTreeIter*>(iter.gobj()));
}


} // namespace Gtk


