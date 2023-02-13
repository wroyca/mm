


#include <libmm-glib/mm-glib.hpp>

#include <libmm-gtk/treeselection.hpp>
#include <libmm-gtk/treeselection_p.hpp>


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

#include <libmm-gtk/treeview.hpp>
#include <gtk/gtk.h>

namespace
{

auto proxy_foreach_selection_iter_callback (
  GtkTreeModel *model, GtkTreePath *, GtkTreeIter *iter, void *data) -> void
{
  typedef Gtk::TreeSelection::SlotForeachIter SlotType;
  const auto& slot = *static_cast<SlotType*>(data);

  try
  {
    slot(Gtk::TreeModel::const_iterator(model, iter));
  }
  catch(...)
  {
    Glib::exception_handlers_invoke();
  }
}

auto proxy_foreach_selection_path_callback (
  GtkTreeModel *, GtkTreePath *path, GtkTreeIter *, void *data) -> void
{
  typedef Gtk::TreeSelection::SlotForeachPath SlotType;
  const auto& slot = *static_cast<SlotType*>(data);

  try
  {
    slot(Gtk::TreeModel::Path(path, true));
  }
  catch(...)
  {
    Glib::exception_handlers_invoke();
  }
}

auto proxy_foreach_selection_path_and_iter_callback (
  GtkTreeModel *model, GtkTreePath *path,
  GtkTreeIter *iter, void *data) -> void
{
  typedef Gtk::TreeSelection::SlotForeachPathAndIter SlotType;
  const auto& slot = *static_cast<SlotType*>(data);

  try
  {
    slot(Gtk::TreeModel::Path(path, true), Gtk::TreeModel::const_iterator(model, iter));
  }
  catch(...)
  {
    Glib::exception_handlers_invoke();
  }
}


auto SignalProxy_Select_gtk_callback(GtkTreeSelection*, GtkTreeModel* model, GtkTreePath* path, const gboolean path_currently_selected, void* data) -> gboolean
{
  const auto the_slot = static_cast<Gtk::TreeSelection::SlotSelect*>(data);

  try
  {
    return (*the_slot)(Glib::wrap(model, true),   // take copy
                         Gtk::TreePath(path, true), // take copy
                         path_currently_selected);
  }
  catch(...)
  {
    Glib::exception_handlers_invoke();
  }

  return 0;
}

} // anonymous namespace

static auto SignalProxy_Select_gtk_callback_destroy (void *data) -> void
{
  delete static_cast<Gtk::TreeSelection::SlotSelect*>(data);
}


namespace Gtk
{

auto TreeSelection::set_select_function (const SlotSelect &slot) -> void
{
  // Create a copy of the slot.  A pointer to this will be passed
  // through the callback's data parameter.  It will be deleted
  // when SignalProxy_Select_gtk_callback_destroy() is called.
  const auto slot_copy = new SlotSelect(slot);

  gtk_tree_selection_set_select_function(gobj(),
      &SignalProxy_Select_gtk_callback, slot_copy,
      &SignalProxy_Select_gtk_callback_destroy);
}

auto TreeSelection::get_model() -> Glib::RefPtr<TreeModel>
{
  const auto tree_view = gtk_tree_selection_get_tree_view(gobj());
  return Glib::wrap(gtk_tree_view_get_model(tree_view), true);
}

auto TreeSelection::get_model() const -> Glib::RefPtr<const TreeModel>
{
  const auto tree_view = gtk_tree_selection_get_tree_view(const_cast<GtkTreeSelection*>(gobj()));
  return Glib::wrap(gtk_tree_view_get_model(tree_view), true);
}

auto TreeSelection::get_selected() -> TreeModel::iterator
{
  TreeModel::iterator iter;
  GtkTreeModel* model_gobject = nullptr;

  // If no row is selected, *iter.gobj() is set to an invalid iterator.
  gtk_tree_selection_get_selected(gobj(), &model_gobject, iter.gobj());

  iter.set_model_gobject(model_gobject);
  return iter;
}

auto TreeSelection::get_selected() const -> TreeModel::const_iterator
{
  return const_cast<TreeSelection*>(this)->get_selected();
}

auto TreeSelection::get_selected(Glib::RefPtr<TreeModel>& model) -> TreeModel::iterator
{
  TreeModel::iterator iter;
  GtkTreeModel* model_gobject = nullptr;

  // If no row is selected, *iter.gobj() is set to an invalid iterator.
  gtk_tree_selection_get_selected(gobj(), &model_gobject, iter.gobj());

  model = Glib::wrap(model_gobject, true);

  iter.set_model_refptr(model);
  return iter;
}

auto TreeSelection::get_selected(Glib::RefPtr<const TreeModel>& model) const -> TreeModel::const_iterator
{
  TreeModel::iterator iter;
  GtkTreeModel* model_gobject = nullptr;

  // If no row is selected, *iter.gobj() is set to an invalid iterator.
  gtk_tree_selection_get_selected(const_cast<GtkTreeSelection*>(gobj()), &model_gobject, iter.gobj());

  model = Glib::wrap(model_gobject, true);

  iter.set_model_refptr(std::const_pointer_cast<TreeModel>(model));
  return iter;
}

auto TreeSelection::selected_foreach_iter (const SlotForeachIter &slot) const -> void
{
  SlotForeachIter slot_copy (slot);
  gtk_tree_selection_selected_foreach(const_cast<GtkTreeSelection*>(gobj()), &proxy_foreach_selection_iter_callback, &slot_copy);
}

auto TreeSelection::selected_foreach_path (const SlotForeachPath &slot) const -> void
{
  SlotForeachPath slot_copy (slot);
  gtk_tree_selection_selected_foreach(const_cast<GtkTreeSelection*>(gobj()), &proxy_foreach_selection_path_callback, &slot_copy);
}

auto TreeSelection::selected_foreach (const SlotForeachPathAndIter &slot) const -> void
{
  SlotForeachPathAndIter slot_copy (slot);
  gtk_tree_selection_selected_foreach(const_cast<GtkTreeSelection*>(gobj()), &proxy_foreach_selection_path_and_iter_callback, &slot_copy);
}

auto TreeSelection::get_selected_rows() const -> std::vector<TreeModel::Path>
{
  return Glib::ListHandler<TreeModel::Path, TreePathTraits>::list_to_vector(gtk_tree_selection_get_selected_rows(
      const_cast<GtkTreeSelection*>(gobj()), nullptr), Glib::OWNERSHIP_DEEP);
}

auto TreeSelection::get_selected_rows(Glib::RefPtr<TreeModel>& model) -> std::vector<TreeModel::Path>
{
  GtkTreeModel* model_gobject = nullptr;

  const std::vector<TreeModel::Path> result (Glib::ListHandler<TreeModel::Path, TreePathTraits>::list_to_vector(gtk_tree_selection_get_selected_rows(
      gobj(), &model_gobject), Glib::OWNERSHIP_DEEP));

  model = Glib::wrap(model_gobject, true);
  return result;
}

} // namespace Gtk

namespace
{


const Glib::SignalProxyInfo TreeSelection_signal_changed_info =
{
  "changed",
  (GCallback) &Glib::SignalProxyNormal::slot0_void_callback,
  (GCallback) &Glib::SignalProxyNormal::slot0_void_callback
};


} // anonymous namespace


namespace Glib
{

auto wrap(GtkTreeSelection* object, const bool take_copy) -> RefPtr<Gtk::TreeSelection>
{
  return Glib::make_refptr_for_instance<Gtk::TreeSelection>( dynamic_cast<Gtk::TreeSelection*> (wrap_auto((GObject*)object, take_copy)) );
  //We use dynamic_cast<> in case of multiple inheritance.
}

} /* namespace Glib */


namespace Gtk
{


/* The *_Class implementation: */

auto TreeSelection_Class::init() -> const Class&
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Class has to know the class init function to clone custom types.
    class_init_func_ = &TreeSelection_Class::class_init_function;

    // This is actually just optimized away, apparently with no harm.
    // Make sure that the parent type has been created.
    //CppClassParent::CppObjectType::get_type();

    // Create the wrapper type, with the same class/instance size as the base type.
    register_derived_type(gtk_tree_selection_get_type());

    // Add derived versions of interfaces, if the C type implements any interfaces:

  }

  return *this;
}


auto TreeSelection_Class::class_init_function (void *g_class, void *class_data) -> void
{
  const auto klass = static_cast<BaseClassType*>(g_class);
  CppClassParent::class_init_function(klass, class_data);


}


auto TreeSelection_Class::wrap_new(GObject* object) -> Glib::ObjectBase*
{
  return new TreeSelection((GtkTreeSelection*)object);
}


/* The implementation: */

auto TreeSelection::gobj_copy() -> GtkTreeSelection*
{
  reference();
  return gobj();
}

TreeSelection::TreeSelection(const Glib::ConstructParams& construct_params)
: Object(construct_params)
{

}

TreeSelection::TreeSelection(GtkTreeSelection* castitem)
: Object((GObject*)castitem)
{}


TreeSelection::TreeSelection(TreeSelection&& src) noexcept
: Object(std::move(src))
{}

auto TreeSelection::operator=(TreeSelection&& src) noexcept -> TreeSelection&
{
  Object::operator=(std::move(src));
  return *this;
}


TreeSelection::~TreeSelection() noexcept = default;

TreeSelection::CppClassType TreeSelection::treeselection_class_; // initialize static member

auto TreeSelection::get_type() -> GType
{
  return treeselection_class_.init().get_type();
}


auto TreeSelection::get_base_type() -> GType
{
  return gtk_tree_selection_get_type();
}


auto TreeSelection::set_mode (SelectionMode type) -> void
{
  gtk_tree_selection_set_mode(gobj(), static_cast<GtkSelectionMode>(type));
}

auto TreeSelection::get_mode() const -> SelectionMode
{
  return static_cast<SelectionMode>(gtk_tree_selection_get_mode(const_cast<GtkTreeSelection*>(gobj())));
}

auto TreeSelection::get_tree_view() -> TreeView*
{
  return Glib::wrap(gtk_tree_selection_get_tree_view(gobj()));
}

auto TreeSelection::get_tree_view() const -> const TreeView*
{
  return const_cast<TreeSelection*>(this)->get_tree_view();
}

auto TreeSelection::count_selected_rows() const -> int
{
  return gtk_tree_selection_count_selected_rows(const_cast<GtkTreeSelection*>(gobj()));
}

auto TreeSelection::select (const TreeModel::Path &path) -> void
{
  gtk_tree_selection_select_path(gobj(), const_cast<GtkTreePath*>(path.gobj()));
}

auto TreeSelection::select (
  const TreeModel::Path &start_path, const TreeModel::Path &end_path) -> void
{
  gtk_tree_selection_select_range(gobj(), const_cast<GtkTreePath*>(start_path.gobj()), const_cast<GtkTreePath*>(end_path.gobj()));
}

auto TreeSelection::select (const TreeModel::const_iterator &iter) -> void
{
  gtk_tree_selection_select_iter(gobj(), const_cast<GtkTreeIter*>(iter.gobj()));
}

auto TreeSelection::unselect (const TreeModel::Path &path) -> void
{
  gtk_tree_selection_unselect_path(gobj(), const_cast<GtkTreePath*>(path.gobj()));
}

auto TreeSelection::unselect (
  const TreeModel::Path &start_path, const TreeModel::Path &end_path) -> void
{
  gtk_tree_selection_unselect_range(gobj(), const_cast<GtkTreePath*>(start_path.gobj()), const_cast<GtkTreePath*>(end_path.gobj()));
}

auto TreeSelection::unselect (const TreeModel::const_iterator &iter) -> void
{
  gtk_tree_selection_unselect_iter(gobj(), const_cast<GtkTreeIter*>(iter.gobj()));
}

auto TreeSelection::is_selected(const TreeModel::Path& path) const -> bool
{
  return gtk_tree_selection_path_is_selected(const_cast<GtkTreeSelection*>(gobj()), const_cast<GtkTreePath*>(path.gobj()));
}

auto TreeSelection::is_selected(const TreeModel::const_iterator& iter) const -> bool
{
  return gtk_tree_selection_iter_is_selected(const_cast<GtkTreeSelection*>(gobj()), const_cast<GtkTreeIter*>(iter.gobj()));
}

auto TreeSelection::select_all () -> void
{
  gtk_tree_selection_select_all(gobj());
}

auto TreeSelection::unselect_all () -> void
{
  gtk_tree_selection_unselect_all(gobj());
}


auto TreeSelection::signal_changed() -> Glib::SignalProxy<void()>
{
  return {this, &TreeSelection_signal_changed_info};
}


static_assert(Glib::Traits::ValueCompatibleWithWrapProperty<SelectionMode>::value,
  "Type SelectionMode cannot be used in _WRAP_PROPERTY. "
  "There is no suitable template specialization of Glib::Value<>.");

auto TreeSelection::property_mode() -> Glib::PropertyProxy< SelectionMode >
{
  return {this, "mode"};
}

auto TreeSelection::property_mode() const -> Glib::PropertyProxy_ReadOnly< SelectionMode >
{
  return {this, "mode"};
}


} // namespace Gtk


