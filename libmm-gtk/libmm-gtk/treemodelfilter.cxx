


#include <libmm-glib/mm-glib.hpp>

#include <libmm-gtk/treemodelfilter.hpp>
#include <libmm-gtk/treemodelfilter_p.hpp>


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


static auto SignalProxy_Visible_gtk_callback(GtkTreeModel* model, GtkTreeIter* iter, const gpointer data) -> gboolean
{
  const auto the_slot = static_cast<Gtk::TreeModelFilter::SlotVisible*>(data);

  try
  {
    return (*the_slot)( Gtk::TreeModel::const_iterator(model, iter) );
  }
  catch(...)
  {
    Glib::exception_handlers_invoke();
  }

  return FALSE; //An arbitary default, just to avoid the compiler warning.
}

static auto SignalProxy_Visible_gtk_callback_destroy (void *data) -> void
{
  delete static_cast<Gtk::TreeModelFilter::SlotVisible*>(data);
}


static auto SignalProxy_Modify_gtk_callback (
  GtkTreeModel *model, GtkTreeIter *iter, GValue *value, const int column, const gpointer data) -> void
{
  const auto the_slot = static_cast<Gtk::TreeModelFilter::SlotModify*>(data);

  try
  {
    //Initialize the input parameter with the appropriate type for this column.
    //Then the C++ handler can just use operator==() without calling init on the value output arg:
    Glib::ValueBase cppValue;
    const auto column_type = gtk_tree_model_get_column_type(model, column);
    cppValue.init(column_type);

    (*the_slot)( Gtk::TreeModel::iterator(model, iter), cppValue, column );

    //GTK+ has already done this for us: g_value_init(value, column_type);

    //If the C++ handler has inited value with an inappropriate GType, then this will fail,
    //but they should not do that because it makes no sense.
    g_value_copy(cppValue.gobj() /* source */, value /* destination */);
  }
  catch(...)
  {
    Glib::exception_handlers_invoke();
  }
}

static auto SignalProxy_Modify_gtk_callback_destroy (void *data) -> void
{
  delete static_cast<Gtk::TreeModelFilter::SlotModify*>(data);
}


using Path = Gtk::TreeModel::Path; //So that the generated method implementations can use this as a return type.

namespace Gtk
{

TreeModelFilter::TreeModelFilter(const Glib::RefPtr<TreeModel>& child_model)
:
  // Mark this class as non-derived to allow C++ vfuncs to be skipped.
ObjectBase(nullptr),
Object(Glib::ConstructParams(treemodelfilter_class_.init(), "child_model",child_model->gobj(), nullptr))
{
}

TreeModelFilter::TreeModelFilter(const Glib::RefPtr<TreeModel>& child_model, const Path & virtual_root)
:
  // Mark this class as non-derived to allow C++ vfuncs to be skipped.
ObjectBase(nullptr),
Object(Glib::ConstructParams(treemodelfilter_class_.init(), "child_model",child_model->gobj(),"virtual_root",virtual_root.empty() ? nullptr : const_cast<GtkTreePath*>(virtual_root.gobj()) , nullptr))
{
}

auto TreeModelFilter::set_visible_func (const SlotVisible &slot) -> void
{
  // Create a copy of the slot.  A pointer to this will be passed
  // through the callback's data parameter.  It will be deleted
  // when SignalProxy_Visible_gtk_callback_destroy() is called.
  const auto slot_copy = new SlotVisible(slot);

  gtk_tree_model_filter_set_visible_func(gobj(),
      &SignalProxy_Visible_gtk_callback, slot_copy,
      &SignalProxy_Visible_gtk_callback_destroy);
}


auto TreeModelFilter::convert_child_iter_to_iter(const iterator& child_iter) -> iterator
{
  iterator filter_iter(this);

  gtk_tree_model_filter_convert_child_iter_to_iter(gobj(), filter_iter.gobj(),
      const_cast<GtkTreeIter*>(child_iter.gobj()));

  return filter_iter;
}

auto TreeModelFilter::convert_child_iter_to_iter(const const_iterator& child_iter) const -> const_iterator
{
  const_iterator filter_iter(const_cast<TreeModelFilter*>(this));

  gtk_tree_model_filter_convert_child_iter_to_iter(
      const_cast<GtkTreeModelFilter*>(gobj()), filter_iter.gobj(),
      const_cast<GtkTreeIter*>(child_iter.gobj()));

  return filter_iter;
}

auto TreeModelFilter::convert_iter_to_child_iter(const iterator& filter_iter) -> iterator
{
  const auto child_model = gtk_tree_model_filter_get_model(gobj());

  iterator child_iter(dynamic_cast<TreeModel*>(Glib::wrap_auto((GObject*)child_model, false)));

  gtk_tree_model_filter_convert_iter_to_child_iter(gobj(), child_iter.gobj(),
      const_cast<GtkTreeIter*>(filter_iter.gobj()));

  return child_iter;
}

auto TreeModelFilter::convert_iter_to_child_iter(const const_iterator& filter_iter) const -> const_iterator
{
  const auto child_model = gtk_tree_model_filter_get_model(const_cast<GtkTreeModelFilter*>(gobj()));

  const_iterator child_iter(dynamic_cast<TreeModel*>(Glib::wrap_auto((GObject*)child_model, false)));

  gtk_tree_model_filter_convert_iter_to_child_iter(
      const_cast<GtkTreeModelFilter*>(gobj()), child_iter.gobj(),
      const_cast<GtkTreeIter*>(filter_iter.gobj()));

  return child_iter;
}

auto TreeModelFilter::set_modify_func (
  const TreeModelColumnRecord &columns, const SlotModify &slot) -> void
{
  // Create a copy of the slot.  A pointer to this will be passed
  // through the callback's data parameter.  It will be deleted
  // when SignalProxy_Modify_gtk_callback_destroy() is called.
  const auto slot_copy = new SlotModify(slot);

  gtk_tree_model_filter_set_modify_func(gobj(),
    columns.size(), const_cast<GType*>(columns.types()),
    &SignalProxy_Modify_gtk_callback, slot_copy,
    &SignalProxy_Modify_gtk_callback_destroy);
}

auto TreeModelFilter::set_value_impl (
  const iterator &row, const int column, const Glib::ValueBase &value) -> void
{
  // Avoid two extra ref/unref cycles -- we don't store the child
  // model pointer anywhere, so it's OK to do this _internally_.

  const auto child_model = dynamic_cast<TreeModel*>(
      Glib::wrap_auto((GObject*) gtk_tree_model_filter_get_model(gobj()), false));

  iterator child_iter(child_model);

  gtk_tree_model_filter_convert_iter_to_child_iter(
      gobj(), child_iter.gobj(), const_cast<GtkTreeIter*>(row.gobj()));

  child_model->set_value_impl(child_iter, column, value);
}


} // namespace Gtk

namespace
{
} // anonymous namespace


namespace Glib
{

auto wrap(GtkTreeModelFilter* object, const bool take_copy) -> RefPtr<Gtk::TreeModelFilter>
{
  return Glib::make_refptr_for_instance<Gtk::TreeModelFilter>( dynamic_cast<Gtk::TreeModelFilter*> (wrap_auto((GObject*)object, take_copy)) );
  //We use dynamic_cast<> in case of multiple inheritance.
}

} /* namespace Glib */


namespace Gtk
{


/* The *_Class implementation: */

auto TreeModelFilter_Class::init() -> const Class&
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Class has to know the class init function to clone custom types.
    class_init_func_ = &TreeModelFilter_Class::class_init_function;

    // This is actually just optimized away, apparently with no harm.
    // Make sure that the parent type has been created.
    //CppClassParent::CppObjectType::get_type();

    // Create the wrapper type, with the same class/instance size as the base type.
    register_derived_type(gtk_tree_model_filter_get_type());

    // Add derived versions of interfaces, if the C type implements any interfaces:
  TreeModel::add_interface(get_type());
  TreeDragSource::add_interface(get_type());

  }

  return *this;
}


auto TreeModelFilter_Class::class_init_function (void *g_class, void *class_data) -> void
{
  const auto klass = static_cast<BaseClassType*>(g_class);
  CppClassParent::class_init_function(klass, class_data);


}


auto TreeModelFilter_Class::wrap_new(GObject* object) -> Glib::ObjectBase*
{
  return new TreeModelFilter((GtkTreeModelFilter*)object);
}


/* The implementation: */

auto TreeModelFilter::gobj_copy() -> GtkTreeModelFilter*
{
  reference();
  return gobj();
}

TreeModelFilter::TreeModelFilter(const Glib::ConstructParams& construct_params)
: Object(construct_params)
{

}

TreeModelFilter::TreeModelFilter(GtkTreeModelFilter* castitem)
: Object((GObject*)castitem)
{}


TreeModelFilter::TreeModelFilter(TreeModelFilter&& src) noexcept
: Object(std::move(src))
  , TreeModel(std::move(src))
  , TreeDragSource(std::move(src))
{}

auto TreeModelFilter::operator=(TreeModelFilter&& src) noexcept -> TreeModelFilter&
{
  Object::operator=(std::move(src));
  TreeModel::operator=(std::move(src));
  TreeDragSource::operator=(std::move(src));
  return *this;
}


TreeModelFilter::~TreeModelFilter() noexcept = default;

TreeModelFilter::CppClassType TreeModelFilter::treemodelfilter_class_; // initialize static member

auto TreeModelFilter::get_type() -> GType
{
  return treemodelfilter_class_.init().get_type();
}


auto TreeModelFilter::get_base_type() -> GType
{
  return gtk_tree_model_filter_get_type();
}


auto TreeModelFilter::create(const Glib::RefPtr<TreeModel>& child_model) -> Glib::RefPtr<TreeModelFilter>
{
  return Glib::make_refptr_for_instance<TreeModelFilter>( new TreeModelFilter(child_model) );
}

auto TreeModelFilter::create(const Glib::RefPtr<TreeModel>& child_model, const Path & virtual_root) -> Glib::RefPtr<TreeModelFilter>
{
  return Glib::make_refptr_for_instance<TreeModelFilter>( new TreeModelFilter(child_model, virtual_root) );
}

auto TreeModelFilter::set_visible_column (const TreeModelColumnBase &column) -> void
{
  gtk_tree_model_filter_set_visible_column(gobj(), column.index());
}

auto TreeModelFilter::set_visible_column (
  const int column) -> void
{
  gtk_tree_model_filter_set_visible_column(gobj(), column);
}

auto TreeModelFilter::get_model() -> Glib::RefPtr<TreeModel>
{
  auto retvalue = Glib::wrap(gtk_tree_model_filter_get_model(gobj()));
  if(retvalue)
    retvalue->reference(); //The function does not do a ref for us.
  return retvalue;
}

auto TreeModelFilter::get_model() const -> Glib::RefPtr<const TreeModel>
{
  return const_cast<TreeModelFilter*>(this)->get_model();
}

auto TreeModelFilter::convert_child_path_to_path(const Path& child_path) const -> Path
{
  return TreePath(gtk_tree_model_filter_convert_child_path_to_path(const_cast<GtkTreeModelFilter*>(gobj()), const_cast<GtkTreePath*>(child_path.gobj())), false);
}

auto TreeModelFilter::convert_path_to_child_path(const Path& filter_path) const -> Path
{
  return TreePath(gtk_tree_model_filter_convert_path_to_child_path(const_cast<GtkTreeModelFilter*>(gobj()), const_cast<GtkTreePath*>(filter_path.gobj())), false);
}

auto TreeModelFilter::refilter () -> void
{
  gtk_tree_model_filter_refilter(gobj());
}

auto TreeModelFilter::clear_cache () -> void
{
  gtk_tree_model_filter_clear_cache(gobj());
}


static_assert(Glib::Traits::ValueCompatibleWithWrapProperty<Glib::RefPtr<TreeModel>>::value,
  "Type Glib::RefPtr<TreeModel> cannot be used in _WRAP_PROPERTY. "
  "There is no suitable template specialization of Glib::Value<>.");

auto TreeModelFilter::property_child_model() const -> Glib::PropertyProxy_ReadOnly< Glib::RefPtr<TreeModel> >
{
  return {this, "child-model"};
}

static_assert(Glib::Traits::ValueCompatibleWithWrapProperty<TreeModel::Path>::value,
  "Type TreeModel::Path cannot be used in _WRAP_PROPERTY. "
  "There is no suitable template specialization of Glib::Value<>.");

auto TreeModelFilter::property_virtual_root() const -> Glib::PropertyProxy_ReadOnly<Path>
{
  return {this, "virtual-root"};
}


} // namespace Gtk


