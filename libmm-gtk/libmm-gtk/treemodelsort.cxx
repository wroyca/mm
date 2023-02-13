


#include <libmm-glib/mm-glib.hxx>

#include <libmm-gtk/treemodelsort.hxx>
#include <libmm-gtk/treemodelsort_p.hxx>


/*
 * Copyright 1998-2002 The gtkmm Development Team
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

using Path = Gtk::TreeModel::Path; //So that the generated method implementations can use this as a return type.

namespace Gtk
{

auto TreeModelSort::convert_child_iter_to_iter(const iterator& child_iter) -> iterator
{
  iterator sorted_iter(this);

  gtk_tree_model_sort_convert_child_iter_to_iter(gobj(), sorted_iter.gobj(),
      const_cast<GtkTreeIter*>(child_iter.gobj()));

  return sorted_iter;
}

auto TreeModelSort::convert_child_iter_to_iter(const const_iterator& child_iter) const -> const_iterator
{
  const_iterator sorted_iter(const_cast<TreeModelSort*>(this));

  gtk_tree_model_sort_convert_child_iter_to_iter(
      const_cast<GtkTreeModelSort*>(gobj()), sorted_iter.gobj(),
      const_cast<GtkTreeIter*>(child_iter.gobj()));

  return sorted_iter;
}

auto TreeModelSort::convert_iter_to_child_iter(const iterator& sorted_iter) -> iterator
{
  const auto child_model = gtk_tree_model_sort_get_model(gobj());

  iterator child_iter(dynamic_cast<TreeModel*>(Glib::wrap_auto((GObject*) child_model, false)));

  gtk_tree_model_sort_convert_iter_to_child_iter(gobj(), child_iter.gobj(),
      const_cast<GtkTreeIter*>(sorted_iter.gobj()));

  return child_iter;
}

auto TreeModelSort::convert_iter_to_child_iter(const const_iterator& sorted_iter) const -> const_iterator
{
  const auto child_model = gtk_tree_model_sort_get_model(const_cast<GtkTreeModelSort*>(gobj()));

  const_iterator child_iter(dynamic_cast<TreeModel*>(Glib::wrap_auto((GObject*) child_model, false)));

  gtk_tree_model_sort_convert_iter_to_child_iter(
      const_cast<GtkTreeModelSort*>(gobj()), child_iter.gobj(),
      const_cast<GtkTreeIter*>(sorted_iter.gobj()));

  return child_iter;
}

auto TreeModelSort::set_value_impl (
  const iterator &row, const int column, const Glib::ValueBase &value) -> void
{
  // Avoid two extra ref/unref cycles -- we don't store the child
  // model pointer anywhere, so it's OK to do this _internally_.

  const auto child_model = dynamic_cast<TreeModel*>(
      Glib::wrap_auto((GObject*) gtk_tree_model_sort_get_model(gobj()), false));

  iterator child_iter(child_model);

  gtk_tree_model_sort_convert_iter_to_child_iter(
      gobj(), child_iter.gobj(), const_cast<GtkTreeIter*>(row.gobj()));

  child_model->set_value_impl(child_iter, column, value);
}

} // namespace Gtk

namespace
{
} // anonymous namespace


namespace Glib
{

auto wrap(GtkTreeModelSort* object, const bool take_copy) -> RefPtr<Gtk::TreeModelSort>
{
  return Glib::make_refptr_for_instance<Gtk::TreeModelSort>( dynamic_cast<Gtk::TreeModelSort*> (wrap_auto((GObject*)object, take_copy)) );
  //We use dynamic_cast<> in case of multiple inheritance.
}

} /* namespace Glib */


namespace Gtk
{


/* The *_Class implementation: */

auto TreeModelSort_Class::init() -> const Class&
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Class has to know the class init function to clone custom types.
    class_init_func_ = &TreeModelSort_Class::class_init_function;

    // This is actually just optimized away, apparently with no harm.
    // Make sure that the parent type has been created.
    //CppClassParent::CppObjectType::get_type();

    // Create the wrapper type, with the same class/instance size as the base type.
    register_derived_type(gtk_tree_model_sort_get_type());

    // Add derived versions of interfaces, if the C type implements any interfaces:
  TreeModel::add_interface(get_type());
  TreeSortable::add_interface(get_type());
  TreeDragSource::add_interface(get_type());

  }

  return *this;
}


auto TreeModelSort_Class::class_init_function (void *g_class, void *class_data) -> void
{
  const auto klass = static_cast<BaseClassType*>(g_class);
  CppClassParent::class_init_function(klass, class_data);


}


auto TreeModelSort_Class::wrap_new(GObject* object) -> Glib::ObjectBase*
{
  return new TreeModelSort((GtkTreeModelSort*)object);
}


/* The implementation: */

auto TreeModelSort::gobj_copy() -> GtkTreeModelSort*
{
  reference();
  return gobj();
}

TreeModelSort::TreeModelSort(const Glib::ConstructParams& construct_params)
: Object(construct_params)
{

}

TreeModelSort::TreeModelSort(GtkTreeModelSort* castitem)
: Object((GObject*)castitem)
{}


TreeModelSort::TreeModelSort(TreeModelSort&& src) noexcept
: Object(std::move(src))
  , TreeModel(std::move(src))
  , TreeSortable(std::move(src))
  , TreeDragSource(std::move(src))
{}

auto TreeModelSort::operator=(TreeModelSort&& src) noexcept -> TreeModelSort&
{
  Object::operator=(std::move(src));
  TreeModel::operator=(std::move(src));
  TreeSortable::operator=(std::move(src));
  TreeDragSource::operator=(std::move(src));
  return *this;
}


TreeModelSort::~TreeModelSort() noexcept = default;

TreeModelSort::CppClassType TreeModelSort::treemodelsort_class_; // initialize static member

auto TreeModelSort::get_type() -> GType
{
  return treemodelsort_class_.init().get_type();
}


auto TreeModelSort::get_base_type() -> GType
{
  return gtk_tree_model_sort_get_type();
}


TreeModelSort::TreeModelSort(const Glib::RefPtr<TreeModel>& model)
:
  // Mark this class as non-derived to allow C++ vfuncs to be skipped.
ObjectBase(nullptr),
Object(Glib::ConstructParams(treemodelsort_class_.init(), "model", Glib::unwrap(model), nullptr))
{


}

auto TreeModelSort::create(const Glib::RefPtr<TreeModel>& model) -> Glib::RefPtr<TreeModelSort>
{
  return Glib::make_refptr_for_instance<TreeModelSort>( new TreeModelSort(model) );
}

auto TreeModelSort::get_model() -> Glib::RefPtr<TreeModel>
{
  auto retvalue = Glib::wrap(gtk_tree_model_sort_get_model(gobj()));
  if(retvalue)
    retvalue->reference(); //The function does not do a ref for us.
  return retvalue;
}

auto TreeModelSort::get_model() const -> Glib::RefPtr<const TreeModel>
{
  return const_cast<TreeModelSort*>(this)->get_model();
}

auto TreeModelSort::convert_child_path_to_path(const Path& child_path) const -> Path
{
  return TreePath(gtk_tree_model_sort_convert_child_path_to_path(const_cast<GtkTreeModelSort*>(gobj()), const_cast<GtkTreePath*>(child_path.gobj())), false);
}

auto TreeModelSort::convert_path_to_child_path(const Path& sorted_path) const -> Path
{
  return TreePath(gtk_tree_model_sort_convert_path_to_child_path(const_cast<GtkTreeModelSort*>(gobj()), const_cast<GtkTreePath*>(sorted_path.gobj())), false);
}

auto TreeModelSort::reset_default_sort_func () -> void
{
  gtk_tree_model_sort_reset_default_sort_func(gobj());
}

auto TreeModelSort::clear_cache () -> void
{
  gtk_tree_model_sort_clear_cache(gobj());
}

auto TreeModelSort::iter_is_valid(const const_iterator& iter) const -> bool
{
  return gtk_tree_model_sort_iter_is_valid(const_cast<GtkTreeModelSort*>(gobj()), const_cast<GtkTreeIter*>(iter.gobj()));
}


static_assert(Glib::Traits::ValueCompatibleWithWrapProperty<Glib::RefPtr<TreeModel>>::value,
  "Type Glib::RefPtr<TreeModel> cannot be used in _WRAP_PROPERTY. "
  "There is no suitable template specialization of Glib::Value<>.");

auto TreeModelSort::property_model() const -> Glib::PropertyProxy_ReadOnly< Glib::RefPtr<TreeModel> >
{
  return {this, "model"};
}


} // namespace Gtk


