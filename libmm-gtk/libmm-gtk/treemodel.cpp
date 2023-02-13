


#include <mm/glib/mm-glib.hpp>

#include <mm/gtk/treemodel.hpp>
#include <mm/gtk/private/treemodel_p.hpp>

#include <gtk/gtk.h>

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

#include <mm/glib/vectorutils.hpp>

#include <mm/gtk/treeiter.hpp>
#include <mm/gtk/treepath.hpp>
#include <gtk/gtk.h>

using Flags = Gtk::TreeModel::Flags;

namespace
{

auto proxy_foreach_iter_callback(GtkTreeModel* model, GtkTreePath*, GtkTreeIter* iter, void* data) -> gboolean
{
  typedef Gtk::TreeModel::SlotForeachIter SlotType;
  const auto& slot = *static_cast<SlotType*>(data);

  try
  {
    return slot(Gtk::TreeModel::iterator(model, iter));
  }
  catch(...)
  {
    Glib::exception_handlers_invoke();
  }

  return 1;
}

auto proxy_foreach_path_callback(GtkTreeModel*, GtkTreePath* path, GtkTreeIter*, void* data) -> gboolean
{
  typedef Gtk::TreeModel::SlotForeachPath SlotType;
  const auto& slot = *static_cast<SlotType*>(data);

  try
  {
    return slot(Gtk::TreeModel::Path(path, true));
  }
  catch(...)
  {
    Glib::exception_handlers_invoke();
  }

  return 1;
}

auto proxy_foreach_path_and_iter_callback(GtkTreeModel* model, GtkTreePath* path,
                                              GtkTreeIter* iter, void* data) -> gboolean
{
  typedef Gtk::TreeModel::SlotForeachPathAndIter SlotType;
  const auto& slot = *static_cast<SlotType*>(data);

  try
  {
    return slot(Gtk::TreeModel::Path(path, true), Gtk::TreeModel::iterator(model, iter));
  }
  catch(...)
  {
    Glib::exception_handlers_invoke();
  }

  return 1;
}

} //anonymous namespace


//Help the code generator, so that it doesn't have to fully qualify this type:
typedef Gtk::TreeModel::iterator iterator;

namespace Gtk
{

auto TreeModel::get_iter(const Path& path) -> iterator
{
  iterator iter(this);
  gtk_tree_model_get_iter(gobj(), iter.gobj(), const_cast<GtkTreePath*>(path.gobj()));
  return iter;
}

auto TreeModel::get_iter(const Path& path) const -> const_iterator
{
  return const_cast<TreeModel*>(this)->get_iter(path);
}

auto TreeModel::get_iter(const Glib::ustring& path_string) -> iterator
{
  iterator iter (this);
  gtk_tree_model_get_iter_from_string(gobj(), iter.gobj(), path_string.c_str());
  return iter;
}

auto TreeModel::get_iter(const Glib::ustring& path_string) const -> const_iterator
{
  return const_cast<TreeModel*>(this)->get_iter(path_string);
}

auto TreeModel::children() -> Children
{
  return TreeNodeChildren(this);
}

auto TreeModel::children() const -> const ConstChildren
{
  return TreeNodeConstChildren(this);
}

auto TreeModel::set_value_impl (const iterator &, int, const Glib::ValueBase &) -> void
{
  g_assert_not_reached();
}

auto TreeModel::get_value_impl (
  const const_iterator &iter, const int column, Glib::ValueBase &value) const -> void
{
  gtk_tree_model_get_value(
      const_cast<GtkTreeModel*>(gobj()),
      const_cast<GtkTreeIter*>(iter.gobj()),
      column, value.gobj());
}

auto TreeModel::foreach_iter (const SlotForeachIter &slot) -> void
{
  SlotForeachIter slot_copy (slot);
  gtk_tree_model_foreach(gobj(), &proxy_foreach_iter_callback, &slot_copy);
}

auto TreeModel::foreach_path (const SlotForeachPath &slot) -> void
{
  SlotForeachPath slot_copy (slot);
  gtk_tree_model_foreach(gobj(), &proxy_foreach_path_callback, &slot_copy);
}

auto TreeModel::foreach (const SlotForeachPathAndIter &slot) -> void
{
  SlotForeachPathAndIter slot_copy (slot);
  gtk_tree_model_foreach(gobj(), &proxy_foreach_path_and_iter_callback, &slot_copy);
}

// Custom vfunc callbacks, because the C++ vfuncs have different parameters and return types
// that can not be generated automatically:
auto TreeModel_Class::iter_next_vfunc_callback(GtkTreeModel* self, GtkTreeIter* iter) -> gboolean
{
  const auto obj = dynamic_cast<CppObjectType*>(
      Glib::ObjectBase::_get_current_wrapper((GObject*)self));

  // Non-gtkmmproc-generated custom classes implicitly call the default
  // Glib::ObjectBase constructor, which sets is_derived_. But gtkmmproc-
  // generated classes can use this optimisation, which avoids the unnecessary
  // parameter conversions if there is no possibility of the virtual function
  // being overridden:
  if(obj && obj->is_derived_())
  {
    try // Trap C++ exceptions which would normally be lost because this is a C callback.
    {
      // Call the virtual member method, which derived classes might override.
      const auto iter_input = TreeModel::iterator(self, iter);
      TreeModel::iterator iter_next( self, iter ); //Copies iter by value.
      const gboolean test = obj->iter_next_vfunc(iter_input, iter_next);

      //Copy the new iter value to the C output parameter:
      if(test)
        *iter = *iter_next.gobj();

      return test;
    }
    catch(...)
    {
      Glib::exception_handlers_invoke();
    }
  }
  else
  {
    const auto base = static_cast<BaseClassType*>(
      g_type_interface_peek_parent( // Get the parent interface of the interface (The original underlying C interface).
        g_type_interface_peek(G_OBJECT_GET_CLASS(self), CppObjectType::get_type()) // Get the interface.
      )
    );

    // Call the original underlying C function:
    if(base && base->iter_next)
      return (*base->iter_next)(self, iter);
  }

  typedef gboolean RType;
  return RType();
}


auto TreeModel::iter_next_vfunc(const iterator& iter, iterator& iter_next) const -> bool
{
  //Call the default C implementation:

  const auto base = static_cast<BaseClassType*>(
    g_type_interface_peek_parent(                                     // Get the parent interface of the interface (The original underlying C interface).
      g_type_interface_peek(G_OBJECT_GET_CLASS(gobject_), get_type()) // Get the interface.
    )
  );

  if(base && base->iter_next)
  {
    auto iter_copy = iter;
    const gboolean test = (*base->iter_next)(const_cast<GtkTreeModel*>(gobj()), iter_copy.gobj());
    if(test)
      iter_next = iter_copy;

    return test;
  }

  return bool();
}

auto TreeModel_Class::get_iter_vfunc_callback(GtkTreeModel* self, GtkTreeIter* iter, GtkTreePath* path) -> gboolean
{
  const auto obj = dynamic_cast<CppObjectType*>(
      Glib::ObjectBase::_get_current_wrapper((GObject*)self));

  // Non-gtkmmproc-generated custom classes implicitly call the default
  // Glib::ObjectBase constructor, which sets is_derived_. But gtkmmproc-
  // generated classes can use this optimisation, which avoids the unnecessary
  // parameter conversions if there is no possibility of the virtual function
  // being overridden:
  if(obj && obj->is_derived_())
  {
    try // Trap C++ exceptions which would normally be lost because this is a C callback.
    {
      // Call the virtual member method, which derived classes might override.
      TreeModel::iterator iter_out(self, iter); //copies the iter by value.
      const gboolean test = obj->get_iter_vfunc(TreePath(path, true), iter_out);

      //Copy the new iter value to the C output parameter:
      if(test)
        *iter = *iter_out.gobj();

      return test;
    }
    catch(...)
    {
      Glib::exception_handlers_invoke();
    }
  }
  else
  {
    const auto base = static_cast<BaseClassType*>(
        g_type_interface_peek_parent( // Get the parent interface of the interface (The original underlying C interface).
g_type_interface_peek(G_OBJECT_GET_CLASS(self), CppObjectType::get_type()) // Get the interface.
)    );

    // Call the original underlying C function:
    if(base && base->get_iter)
      return (*base->get_iter)(self, iter, path);
  }

  typedef gboolean RType;
  return RType();
}

auto TreeModel::get_iter_vfunc(const Path& path, iterator& iter) const -> bool
{
  //Call the default C implementation:

  const auto base = static_cast<BaseClassType*>(
    g_type_interface_peek_parent(                                     // Get the parent interface of the interface (The original underlying C interface).
      g_type_interface_peek(G_OBJECT_GET_CLASS(gobject_), get_type()) // Get the interface.
    )
  );

  if(base && base->get_iter)
  {
    return (*base->get_iter)( const_cast<GtkTreeModel*>(gobj()), iter.gobj(), const_cast<GtkTreePath*>(path.gobj()) );
  }

  return bool();
}

auto TreeModel_Class::iter_children_vfunc_callback(GtkTreeModel* self, GtkTreeIter* iter, GtkTreeIter* parent) -> gboolean
{
  const auto obj = dynamic_cast<CppObjectType*>(
      Glib::ObjectBase::_get_current_wrapper((GObject*)self));

  // Non-gtkmmproc-generated custom classes implicitly call the default
  // Glib::ObjectBase constructor, which sets is_derived_. But gtkmmproc-
  // generated classes can use this optimisation, which avoids the unnecessary
  // parameter conversions if there is no possibility of the virtual function
  // being overridden:
  if(obj && obj->is_derived_())
  {
    try // Trap C++ exceptions which would normally be lost because this is a C callback.
    {
      // Call the virtual member method, which derived classes might override.
      TreeModel::iterator iter_out(self, iter); //copies the iter by value.

      gboolean test = false;
      if(!parent)
      {
        //Deal with this case, which is documented in the C docs as:
        //" If @parent is %NULL returns the first node, equivalent to
        //  <literal>gtk_tree_model_get_iter_first (tree_model, iter);</literal> "
        test = obj->iter_nth_root_child_vfunc(0, iter_out);
      }
      else
      {
        //Normal case:
        const TreeModel::iterator parent_cpp(self, parent);
         test = obj->iter_children_vfunc(parent_cpp, iter_out);
      }

      //Copy the new iter value to the C output parameter:
      if(test)
        *iter = *iter_out.gobj();

      return test;
    }
    catch(...)
    {
      Glib::exception_handlers_invoke();
    }
  }
  else
  {
    const auto base = static_cast<BaseClassType*>(
        g_type_interface_peek_parent( // Get the parent interface of the interface (The original underlying C interface).
g_type_interface_peek(G_OBJECT_GET_CLASS(self), CppObjectType::get_type()) // Get the interface.
)    );

    // Call the original underlying C function:
    if(base && base->iter_children)
      return (*base->iter_children)(self, iter, parent);
  }

  typedef gboolean RType;
  return RType();
}

auto TreeModel::iter_children_vfunc(const iterator& parent, iterator& iter) const -> bool
{
  //Call the default C implementation:

  const auto base = static_cast<BaseClassType*>(
    g_type_interface_peek_parent(                                     // Get the parent interface of the interface (The original underlying C interface).
      g_type_interface_peek(G_OBJECT_GET_CLASS(gobject_), get_type()) // Get the interface.
    )
  );

  if(base && base->iter_children)
  {
    return (*base->iter_children)( const_cast<GtkTreeModel*>(gobj()), iter.gobj(), const_cast<GtkTreeIter*>(parent.gobj()) );
  }

  return bool();
}

auto TreeModel_Class::iter_parent_vfunc_callback(GtkTreeModel* self, GtkTreeIter* iter, GtkTreeIter* child) -> gboolean
{
  const auto obj = dynamic_cast<CppObjectType*>(
      Glib::ObjectBase::_get_current_wrapper((GObject*)self));

  // Non-gtkmmproc-generated custom classes implicitly call the default
  // Glib::ObjectBase constructor, which sets is_derived_. But gtkmmproc-
  // generated classes can use this optimisation, which avoids the unnecessary
  // parameter conversions if there is no possibility of the virtual function
  // being overridden:
  if(obj && obj->is_derived_())
  {
    try // Trap C++ exceptions which would normally be lost because this is a C callback.
    {
      // Call the virtual member method, which derived classes might override.
      TreeModel::iterator iter_out(self, iter);
      const TreeModel::iterator child_cpp(self, child);
      const gboolean test = obj->iter_parent_vfunc(child_cpp, iter_out);

      //Copy the new iter value to the C output parameter:
      if(test)
        *iter = *iter_out.gobj();

      return test;
    }
    catch(...)
    {
      Glib::exception_handlers_invoke();
    }
  }
  else
  {
    const auto base = static_cast<BaseClassType*>(
        g_type_interface_peek_parent( // Get the parent interface of the interface (The original underlying C interface).
g_type_interface_peek(G_OBJECT_GET_CLASS(self), CppObjectType::get_type()) // Get the interface.
)    );

    // Call the original underlying C function:
    if(base && base->iter_parent)
      return (*base->iter_parent)(self, iter, child);
  }

  typedef gboolean RType;
  return RType();
}

auto TreeModel::iter_parent_vfunc(const iterator& child, iterator& iter) const -> bool
{
  //Call the default C implementation:

  const auto base = static_cast<BaseClassType*>(
    g_type_interface_peek_parent(                                     // Get the parent interface of the interface (The original underlying C interface).
      g_type_interface_peek(G_OBJECT_GET_CLASS(gobject_), get_type()) // Get the interface.
    )
  );

  if(base && base->iter_parent)
  {
    return (*base->iter_parent)( const_cast<GtkTreeModel*>(gobj()), iter.gobj(), const_cast<GtkTreeIter*>(child.gobj()) );
  }

  return bool();
}

auto TreeModel_Class::iter_nth_child_vfunc_callback(GtkTreeModel* self, GtkTreeIter* iter, GtkTreeIter* parent, const int n) -> gboolean
{
  const auto obj = dynamic_cast<CppObjectType*>(
      Glib::ObjectBase::_get_current_wrapper((GObject*)self));

  // Non-gtkmmproc-generated custom classes implicitly call the default
  // Glib::ObjectBase constructor, which sets is_derived_. But gtkmmproc-
  // generated classes can use this optimisation, which avoids the unnecessary
  // parameter conversions if there is no possibility of the virtual function
  // being overridden:
  if(obj && obj->is_derived_())
  {
    try // Trap C++ exceptions which would normally be lost because this is a C callback.
    {
      // Call the virtual member method, which derived classes might override.
      TreeModel::iterator iter_out(self, iter);

      gboolean test = false;
      if(!parent)
      {
        // Deal with this special case, docuemnted in the C docs as:
        // "As a special case, if @parent is %NULL, then the nth root node is set.":
        test = obj->iter_nth_root_child_vfunc(n, iter_out);
      }
      else
      {
        //The normal case:
        const TreeModel::iterator parent_cpp(self, parent);
        test = obj->iter_nth_child_vfunc(parent_cpp, n, iter_out);
      }

      //Copy the new iter value to the C output parameter:
      if(test)
        *iter = *iter_out.gobj();

      return test;
    }
    catch(...)
    {
      Glib::exception_handlers_invoke();
    }
  }
  else
  {
    const auto base = static_cast<BaseClassType*>(
        g_type_interface_peek_parent( // Get the parent interface of the interface (The original underlying C interface).
g_type_interface_peek(G_OBJECT_GET_CLASS(self), CppObjectType::get_type()) // Get the interface.
)    );

    // Call the original underlying C function:
    if(base && base->iter_nth_child)
      return (*base->iter_nth_child)(self, iter, parent, n);
  }

  typedef gboolean RType;
  return RType();
}

auto TreeModel::iter_nth_child_vfunc(const iterator& parent, const int n, iterator& iter) const -> bool
{
  //Call the default C implementation:

  const auto base = static_cast<BaseClassType*>(
    g_type_interface_peek_parent(                                     // Get the parent interface of the interface (The original underlying C interface).
      g_type_interface_peek(G_OBJECT_GET_CLASS(gobject_), get_type()) // Get the interface.
    )
  );

  if(base && base->iter_nth_child)
  {
    return (*base->iter_nth_child)( const_cast<GtkTreeModel*>(gobj()), iter.gobj(), const_cast<GtkTreeIter*>(parent.gobj()), n );
  }

  return bool();
}

//See the implementation of iter_children_vfunc_callback() and iter_nth_child_vfunc_callback()
//to find out why this virtual function exists:
auto TreeModel::iter_nth_root_child_vfunc(
  const int n, iterator& iter) const -> bool
{
  //Call the default C implementation:

  const auto base = static_cast<BaseClassType*>(
    g_type_interface_peek_parent(                                     // Get the parent interface of the interface (The original underlying C interface).
      g_type_interface_peek(G_OBJECT_GET_CLASS(gobject_), get_type()) // Get the interface.
    )
  );

  if(base && base->iter_nth_child)
  {
    //This means that iter_nth_child(0) might be called by iter_children_vfunc_callback(),
    //but hopefully that's exactly the same thing. TODO: Ask why both vfuncs exist. murrayc.
    return (*base->iter_nth_child)( const_cast<GtkTreeModel*>(gobj()), iter.gobj(), nullptr /* the null parent */, n );
  }

  return bool();
}

auto TreeModel_Class::iter_n_children_vfunc_callback(GtkTreeModel* self, GtkTreeIter* iter) -> gboolean
{
  const auto obj = dynamic_cast<CppObjectType*>(
      Glib::ObjectBase::_get_current_wrapper((GObject*)self));

  // Non-gtkmmproc-generated custom classes implicitly call the default
  // Glib::ObjectBase constructor, which sets is_derived_. But gtkmmproc-
  // generated classes can use this optimisation, which avoids the unnecessary
  // parameter conversions if there is no possibility of the virtual function
  // being overridden:
  if(obj && obj->is_derived_())
  {
    try // Trap C++ exceptions which would normally be lost because this is a C callback.
    {
      // Call the virtual member method, which derived classes might override.

      //Deal with the case that iter is null, as described in the C docs:
      if(iter)
        return obj->iter_n_children_vfunc(TreeModel::iterator(self, iter) );
      else
        return obj->iter_n_root_children_vfunc();
    }
    catch(...)
    {
      Glib::exception_handlers_invoke();
    }
  }
  else
  {
    const auto base = static_cast<BaseClassType*>(
        g_type_interface_peek_parent( // Get the parent interface of the interface (The original underlying C interface).
g_type_interface_peek(G_OBJECT_GET_CLASS(self), CppObjectType::get_type()) // Get the interface.
)    );

    // Call the original underlying C function:
    if(base && base->iter_n_children)
      return (*base->iter_n_children)(self, iter);
  }

  typedef gboolean RType;
  return RType();
}

auto TreeModel::iter_n_children_vfunc(const const_iterator& iter) const -> int
{
  const auto base = static_cast<BaseClassType*>(
      g_type_interface_peek_parent(                             // Get the parent interface of the interface (The original underlying C interface).
g_type_interface_peek(G_OBJECT_GET_CLASS(gobject_), get_type()) // Get the interface.
)  );

  if(base && base->iter_n_children)
    return (*base->iter_n_children)(const_cast<GtkTreeModel*>(gobj()), const_cast<GtkTreeIter*>(iter.gobj()));

  typedef int RType;
  return RType();
}

auto TreeModel::iter_n_root_children_vfunc() const -> int
{
  const auto base = static_cast<BaseClassType*>(
      g_type_interface_peek_parent(                             // Get the parent interface of the interface (The original underlying C interface).
g_type_interface_peek(G_OBJECT_GET_CLASS(gobject_), get_type()) // Get the interface.
)  );

  if(base && base->iter_n_children)
    return (*base->iter_n_children)(const_cast<GtkTreeModel*>(gobj()), nullptr /* null iter to mean root node, as described in C docs */);

  typedef int RType;
  return RType();
}


auto TreeModel::rows_reordered (
  const Path &path, const const_iterator &iter, const std::vector <int> &new_order) -> void
{
  //The size of the array seems to be based on the known number of children. murrayc.
  gtk_tree_model_rows_reordered(gobj(),
                                const_cast<GtkTreePath*>(path.gobj()),
                                const_cast<GtkTreeIter*>(iter.gobj()),
                                Glib::ArrayHandler<int>::vector_to_array(new_order).data ());
}

auto TreeModel::rows_reordered (const Path &path, const std::vector <int> &new_order) -> void
{
  //The size of the array seems to be based on the known number of children. murrayc.
  gtk_tree_model_rows_reordered(gobj(),
                                const_cast<GtkTreePath*>(path.gobj()),
                                nullptr,
                                Glib::ArrayHandler<int>::vector_to_array(new_order).data ());
}

} // namespace Gtk

namespace
{


auto TreeModel_signal_row_changed_callback (
  GtkTreeModel *self, GtkTreePath *p0, GtkTreeIter *p1, void *data) -> void
{
  using namespace Gtk;
  using SlotType = sigc::slot<void(const TreeModel::Path&, const TreeModel::iterator&)>;

  const auto obj = dynamic_cast<TreeModel*>(Glib::ObjectBase::_get_current_wrapper((GObject*) self));
  // Do not try to call a signal on a disassociated wrapper.
  if(obj)
  {
    try
    {
      if(const auto slot = Glib::SignalProxyNormal::data_to_slot(data))
        (*static_cast<SlotType*>(slot))(
          TreePath(p0, true)
, TreeModel::iterator(self, p1)
);
    }
    catch(...)
    {
       Glib::exception_handlers_invoke();
    }
  }
}

const Glib::SignalProxyInfo TreeModel_signal_row_changed_info =
{
  "row_changed",
  (GCallback) &TreeModel_signal_row_changed_callback,
  (GCallback) &TreeModel_signal_row_changed_callback
};


auto TreeModel_signal_row_inserted_callback (
  GtkTreeModel *self, GtkTreePath *p0, GtkTreeIter *p1, void *data) -> void
{
  using namespace Gtk;
  using SlotType = sigc::slot<void(const TreeModel::Path&, const TreeModel::iterator&)>;

  const auto obj = dynamic_cast<TreeModel*>(Glib::ObjectBase::_get_current_wrapper((GObject*) self));
  // Do not try to call a signal on a disassociated wrapper.
  if(obj)
  {
    try
    {
      if(const auto slot = Glib::SignalProxyNormal::data_to_slot(data))
        (*static_cast<SlotType*>(slot))(
          TreePath(p0, true)
, TreeModel::iterator(self, p1)
);
    }
    catch(...)
    {
       Glib::exception_handlers_invoke();
    }
  }
}

const Glib::SignalProxyInfo TreeModel_signal_row_inserted_info =
{
  "row_inserted",
  (GCallback) &TreeModel_signal_row_inserted_callback,
  (GCallback) &TreeModel_signal_row_inserted_callback
};


auto TreeModel_signal_row_has_child_toggled_callback (
  GtkTreeModel *self, GtkTreePath *p0, GtkTreeIter *p1, void *data) -> void
{
  using namespace Gtk;
  using SlotType = sigc::slot<void(const TreeModel::Path&, const TreeModel::iterator&)>;

  const auto obj = dynamic_cast<TreeModel*>(Glib::ObjectBase::_get_current_wrapper((GObject*) self));
  // Do not try to call a signal on a disassociated wrapper.
  if(obj)
  {
    try
    {
      if(const auto slot = Glib::SignalProxyNormal::data_to_slot(data))
        (*static_cast<SlotType*>(slot))(
          TreePath(p0, true)
, TreeModel::iterator(self, p1)
);
    }
    catch(...)
    {
       Glib::exception_handlers_invoke();
    }
  }
}

const Glib::SignalProxyInfo TreeModel_signal_row_has_child_toggled_info =
{
  "row_has_child_toggled",
  (GCallback) &TreeModel_signal_row_has_child_toggled_callback,
  (GCallback) &TreeModel_signal_row_has_child_toggled_callback
};


auto TreeModel_signal_row_deleted_callback (GtkTreeModel *self, GtkTreePath *p0, void *data) -> void
{
  using namespace Gtk;
  using SlotType = sigc::slot<void(const TreeModel::Path&)>;

  const auto obj = dynamic_cast<TreeModel*>(Glib::ObjectBase::_get_current_wrapper((GObject*) self));
  // Do not try to call a signal on a disassociated wrapper.
  if(obj)
  {
    try
    {
      if(const auto slot = Glib::SignalProxyNormal::data_to_slot(data))
        (*static_cast<SlotType*>(slot))(
          TreePath(p0, true)
);
    }
    catch(...)
    {
       Glib::exception_handlers_invoke();
    }
  }
}

const Glib::SignalProxyInfo TreeModel_signal_row_deleted_info =
{
  "row_deleted",
  (GCallback) &TreeModel_signal_row_deleted_callback,
  (GCallback) &TreeModel_signal_row_deleted_callback
};


auto TreeModel_signal_rows_reordered_callback (
  GtkTreeModel *self, GtkTreePath *p0, GtkTreeIter *p1, gint *p2, void *data) -> void
{
  using namespace Gtk;
  using SlotType = sigc::slot<void(const TreeModel::Path&, const TreeModel::iterator&, int*)>;

  const auto obj = dynamic_cast<TreeModel*>(Glib::ObjectBase::_get_current_wrapper((GObject*) self));
  // Do not try to call a signal on a disassociated wrapper.
  if(obj)
  {
    try
    {
      if(const auto slot = Glib::SignalProxyNormal::data_to_slot(data))
        (*static_cast<SlotType*>(slot))(
          TreePath(p0, true)
, TreeModel::iterator(self, p1)
, p2
);
    }
    catch(...)
    {
       Glib::exception_handlers_invoke();
    }
  }
}

const Glib::SignalProxyInfo TreeModel_signal_rows_reordered_info =
{
  "rows_reordered",
  (GCallback) &TreeModel_signal_rows_reordered_callback,
  (GCallback) &TreeModel_signal_rows_reordered_callback
};


} // anonymous namespace

// static
auto Glib::Value<Gtk::TreeModel::Flags>::value_type() -> GType
{
  return gtk_tree_model_flags_get_type();
}


namespace Glib
{

auto wrap(GtkTreeModel* object, const bool take_copy) -> RefPtr<Gtk::TreeModel>
{
  return Glib::make_refptr_for_instance<Gtk::TreeModel>( Glib::wrap_auto_interface<Gtk::TreeModel> ((GObject*)object, take_copy) );
  //We use dynamic_cast<> in case of multiple inheritance.
}

} // namespace Glib


namespace Gtk
{


/* The *_Class implementation: */

auto TreeModel_Class::init() -> const Interface_Class&
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Interface_Class has to know the interface init function
    // in order to add interfaces to implementing types.
    class_init_func_ = &TreeModel_Class::iface_init_function;

    // We can not derive from another interface, and it is not necessary anyway.
    gtype_ = gtk_tree_model_get_type();
  }

  return *this;
}

auto TreeModel_Class::iface_init_function (void *g_iface, void *) -> void
{
  const auto klass = static_cast<BaseClassType*>(g_iface);

  //This is just to avoid an "unused variable" warning when there are no vfuncs or signal handlers to connect.
  //This is a temporary fix until I find out why I can not seem to derive a GtkFileChooser interface. murrayc
  g_assert(klass != nullptr);

  klass->get_flags = &get_flags_vfunc_callback;
  klass->get_n_columns = &get_n_columns_vfunc_callback;
  klass->get_column_type = &get_column_type_vfunc_callback;
    klass->iter_next = &iter_next_vfunc_callback;
    klass->get_iter = &get_iter_vfunc_callback;
    klass->iter_children = &iter_children_vfunc_callback;
    klass->iter_parent = &iter_parent_vfunc_callback;
    klass->iter_nth_child = &iter_nth_child_vfunc_callback;
    klass->iter_n_children = &iter_n_children_vfunc_callback;
    klass->iter_has_child = &iter_has_child_vfunc_callback;
  klass->ref_node = &ref_node_vfunc_callback;
  klass->unref_node = &unref_node_vfunc_callback;
  klass->get_path = &get_path_vfunc_callback;
  klass->get_value = &get_value_vfunc_callback;

  klass->row_changed = &row_changed_callback;
  klass->row_inserted = &row_inserted_callback;
  klass->row_has_child_toggled = &row_has_child_toggled_callback;
  klass->row_deleted = &row_deleted_callback;
  klass->rows_reordered = &rows_reordered_callback;
}

auto TreeModel_Class::get_flags_vfunc_callback(GtkTreeModel* self) -> GtkTreeModelFlags
{
  const auto obj_base = Glib::ObjectBase::_get_current_wrapper((GObject*)self);

  // Non-gtkmmproc-generated custom classes implicitly call the default
  // Glib::ObjectBase constructor, which sets is_derived_. But gtkmmproc-
  // generated classes can use this optimisation, which avoids the unnecessary
  // parameter conversions if there is no possibility of the virtual function
  // being overridden:
  if(obj_base && obj_base->is_derived_())
  {
    const auto obj = dynamic_cast<CppObjectType* const>(obj_base);
    if(obj) // This can be NULL during destruction.
    {
      try // Trap C++ exceptions which would normally be lost because this is a C callback.
      {
        // Call the virtual member method, which derived classes might override.
        return static_cast<GtkTreeModelFlags>(obj->get_flags_vfunc());
      }
      catch(...)
      {
        Glib::exception_handlers_invoke();
      }
    }
  }

  const BaseClassType *const base = static_cast<BaseClassType*>(
      g_type_interface_peek_parent( // Get the parent interface of the interface (The original underlying C interface).
g_type_interface_peek(G_OBJECT_GET_CLASS(self), CppObjectType::get_type()) // Get the interface.
)  );

  // Call the original underlying C function:
  if(base && base->get_flags)
    return (*base->get_flags)(self);

  using RType = GtkTreeModelFlags;
  return RType();
}
auto TreeModel_Class::get_n_columns_vfunc_callback(GtkTreeModel* self) -> gint
{
  const auto obj_base = Glib::ObjectBase::_get_current_wrapper((GObject*)self);

  // Non-gtkmmproc-generated custom classes implicitly call the default
  // Glib::ObjectBase constructor, which sets is_derived_. But gtkmmproc-
  // generated classes can use this optimisation, which avoids the unnecessary
  // parameter conversions if there is no possibility of the virtual function
  // being overridden:
  if(obj_base && obj_base->is_derived_())
  {
    const auto obj = dynamic_cast<CppObjectType* const>(obj_base);
    if(obj) // This can be NULL during destruction.
    {
      try // Trap C++ exceptions which would normally be lost because this is a C callback.
      {
        // Call the virtual member method, which derived classes might override.
        return obj->get_n_columns_vfunc();
      }
      catch(...)
      {
        Glib::exception_handlers_invoke();
      }
    }
  }

  const BaseClassType *const base = static_cast<BaseClassType*>(
      g_type_interface_peek_parent( // Get the parent interface of the interface (The original underlying C interface).
g_type_interface_peek(G_OBJECT_GET_CLASS(self), CppObjectType::get_type()) // Get the interface.
)  );

  // Call the original underlying C function:
  if(base && base->get_n_columns)
    return (*base->get_n_columns)(self);

  using RType = gint;
  return RType();
}
auto TreeModel_Class::get_column_type_vfunc_callback(GtkTreeModel* self, const gint index) -> GType
{
  const auto obj_base = Glib::ObjectBase::_get_current_wrapper((GObject*)self);

  // Non-gtkmmproc-generated custom classes implicitly call the default
  // Glib::ObjectBase constructor, which sets is_derived_. But gtkmmproc-
  // generated classes can use this optimisation, which avoids the unnecessary
  // parameter conversions if there is no possibility of the virtual function
  // being overridden:
  if(obj_base && obj_base->is_derived_())
  {
    const auto obj = dynamic_cast<CppObjectType* const>(obj_base);
    if(obj) // This can be NULL during destruction.
    {
      try // Trap C++ exceptions which would normally be lost because this is a C callback.
      {
        // Call the virtual member method, which derived classes might override.
        return obj->get_column_type_vfunc(index
);
      }
      catch(...)
      {
        Glib::exception_handlers_invoke();
      }
    }
  }

  const BaseClassType *const base = static_cast<BaseClassType*>(
      g_type_interface_peek_parent( // Get the parent interface of the interface (The original underlying C interface).
g_type_interface_peek(G_OBJECT_GET_CLASS(self), CppObjectType::get_type()) // Get the interface.
)  );

  // Call the original underlying C function:
  if(base && base->get_column_type)
    return (*base->get_column_type)(self, index);

  using RType = GType;
  return RType();
}
auto TreeModel_Class::iter_has_child_vfunc_callback(GtkTreeModel* self, GtkTreeIter* iter) -> gboolean
{
  const auto obj_base = Glib::ObjectBase::_get_current_wrapper((GObject*)self);

  // Non-gtkmmproc-generated custom classes implicitly call the default
  // Glib::ObjectBase constructor, which sets is_derived_. But gtkmmproc-
  // generated classes can use this optimisation, which avoids the unnecessary
  // parameter conversions if there is no possibility of the virtual function
  // being overridden:
  if(obj_base && obj_base->is_derived_())
  {
    const auto obj = dynamic_cast<CppObjectType* const>(obj_base);
    if(obj) // This can be NULL during destruction.
    {
      try // Trap C++ exceptions which would normally be lost because this is a C callback.
      {
        // Call the virtual member method, which derived classes might override.
        return obj->iter_has_child_vfunc(
          TreeModel::const_iterator(self, iter)
        );
      }
      catch(...)
      {
        Glib::exception_handlers_invoke();
      }
    }
  }

  const BaseClassType *const base = static_cast<BaseClassType*>(
      g_type_interface_peek_parent( // Get the parent interface of the interface (The original underlying C interface).
g_type_interface_peek(G_OBJECT_GET_CLASS(self), CppObjectType::get_type()) // Get the interface.
)  );

  // Call the original underlying C function:
  if(base && base->iter_has_child)
    return (*base->iter_has_child)(self, iter);

  using RType = gboolean;
  return RType();
}
auto TreeModel_Class::ref_node_vfunc_callback (GtkTreeModel *self, GtkTreeIter *iter) -> void
{
  const auto obj_base = Glib::ObjectBase::_get_current_wrapper((GObject*)self);

  // Non-gtkmmproc-generated custom classes implicitly call the default
  // Glib::ObjectBase constructor, which sets is_derived_. But gtkmmproc-
  // generated classes can use this optimisation, which avoids the unnecessary
  // parameter conversions if there is no possibility of the virtual function
  // being overridden:
  if(obj_base && obj_base->is_derived_())
  {
    const auto obj = dynamic_cast<CppObjectType* const>(obj_base);
    if(obj) // This can be NULL during destruction.
    {
      try // Trap C++ exceptions which would normally be lost because this is a C callback.
      {
        // Call the virtual member method, which derived classes might override.
        obj->ref_node_vfunc(
          TreeModel::iterator(self, iter)
);
        return;
      }
      catch(...)
      {
        Glib::exception_handlers_invoke();
      }
    }
  }

  const BaseClassType *const base = static_cast<BaseClassType*>(
      g_type_interface_peek_parent( // Get the parent interface of the interface (The original underlying C interface).
g_type_interface_peek(G_OBJECT_GET_CLASS(self), CppObjectType::get_type()) // Get the interface.
)  );

  // Call the original underlying C function:
  if(base && base->ref_node)
    (*base->ref_node)(self, iter);
}
auto TreeModel_Class::unref_node_vfunc_callback (GtkTreeModel *self, GtkTreeIter *iter) -> void
{
  const auto obj_base = Glib::ObjectBase::_get_current_wrapper((GObject*)self);

  // Non-gtkmmproc-generated custom classes implicitly call the default
  // Glib::ObjectBase constructor, which sets is_derived_. But gtkmmproc-
  // generated classes can use this optimisation, which avoids the unnecessary
  // parameter conversions if there is no possibility of the virtual function
  // being overridden:
  if(obj_base && obj_base->is_derived_())
  {
    const auto obj = dynamic_cast<CppObjectType* const>(obj_base);
    if(obj) // This can be NULL during destruction.
    {
      try // Trap C++ exceptions which would normally be lost because this is a C callback.
      {
        // Call the virtual member method, which derived classes might override.
        obj->unref_node_vfunc(
          TreeModel::iterator(self, iter)
);
        return;
      }
      catch(...)
      {
        Glib::exception_handlers_invoke();
      }
    }
  }

  const BaseClassType *const base = static_cast<BaseClassType*>(
      g_type_interface_peek_parent( // Get the parent interface of the interface (The original underlying C interface).
g_type_interface_peek(G_OBJECT_GET_CLASS(self), CppObjectType::get_type()) // Get the interface.
)  );

  // Call the original underlying C function:
  if(base && base->unref_node)
    (*base->unref_node)(self, iter);
}
auto TreeModel_Class::get_path_vfunc_callback(GtkTreeModel* self, GtkTreeIter* iter) -> GtkTreePath*
{
  const auto obj_base = Glib::ObjectBase::_get_current_wrapper((GObject*)self);

  // Non-gtkmmproc-generated custom classes implicitly call the default
  // Glib::ObjectBase constructor, which sets is_derived_. But gtkmmproc-
  // generated classes can use this optimisation, which avoids the unnecessary
  // parameter conversions if there is no possibility of the virtual function
  // being overridden:
  if(obj_base && obj_base->is_derived_())
  {
    const auto obj = dynamic_cast<CppObjectType* const>(obj_base);
    if(obj) // This can be NULL during destruction.
    {
      try // Trap C++ exceptions which would normally be lost because this is a C callback.
      {
        // Call the virtual member method, which derived classes might override.
        return obj->get_path_vfunc(
          TreeModel::const_iterator(self, iter)
        ).gobj_copy();
      }
      catch(...)
      {
        Glib::exception_handlers_invoke();
      }
    }
  }

  const BaseClassType *const base = static_cast<BaseClassType*>(
      g_type_interface_peek_parent( // Get the parent interface of the interface (The original underlying C interface).
g_type_interface_peek(G_OBJECT_GET_CLASS(self), CppObjectType::get_type()) // Get the interface.
)  );

  // Call the original underlying C function:
  if(base && base->get_path)
    return (*base->get_path)(self, iter);

  using RType = GtkTreePath*;
  return RType();
}
auto TreeModel_Class::get_value_vfunc_callback (
  GtkTreeModel *self, GtkTreeIter *iter, const gint column, GValue *value) -> void
{
  const auto obj_base = Glib::ObjectBase::_get_current_wrapper((GObject*)self);

  // Non-gtkmmproc-generated custom classes implicitly call the default
  // Glib::ObjectBase constructor, which sets is_derived_. But gtkmmproc-
  // generated classes can use this optimisation, which avoids the unnecessary
  // parameter conversions if there is no possibility of the virtual function
  // being overridden:
  if(obj_base && obj_base->is_derived_())
  {
    const auto obj = dynamic_cast<CppObjectType* const>(obj_base);
    if(obj) // This can be NULL during destruction.
    {
      try // Trap C++ exceptions which would normally be lost because this is a C callback.
      {
        // Call the virtual member method, which derived classes might override.
        obj->get_value_vfunc(
          TreeModel::const_iterator(self, iter)
, column
, *reinterpret_cast<Glib::ValueBase*>(value)
);
        return;
      }
      catch(...)
      {
        Glib::exception_handlers_invoke();
      }
    }
  }

  const BaseClassType *const base = static_cast<BaseClassType*>(
      g_type_interface_peek_parent( // Get the parent interface of the interface (The original underlying C interface).
g_type_interface_peek(G_OBJECT_GET_CLASS(self), CppObjectType::get_type()) // Get the interface.
)  );

  // Call the original underlying C function:
  if(base && base->get_value)
    (*base->get_value)(self, iter, column, value);
}

auto TreeModel_Class::row_changed_callback (
  GtkTreeModel *self, GtkTreePath *p0, GtkTreeIter *p1) -> void
{
  const auto obj_base = Glib::ObjectBase::_get_current_wrapper((GObject*)self);

  // Non-gtkmmproc-generated custom classes implicitly call the default
  // Glib::ObjectBase constructor, which sets is_derived_. But gtkmmproc-
  // generated classes can use this optimisation, which avoids the unnecessary
  // parameter conversions if there is no possibility of the virtual function
  // being overridden:
  if(obj_base && obj_base->is_derived_())
  {
    const auto obj = dynamic_cast<CppObjectType* const>(obj_base);
    if(obj) // This can be NULL during destruction.
    {
      try // Trap C++ exceptions which would normally be lost because this is a C callback.
      {
        // Call the virtual member method, which derived classes might override.
        obj->on_row_changed(
          TreePath(p0, true)
, TreeModel::iterator(self, p1)
);
        return;
      }
      catch(...)
      {
        Glib::exception_handlers_invoke();
      }
    }
  }

  const auto base = static_cast<BaseClassType*>(
        g_type_interface_peek_parent( // Get the parent interface of the interface (The original underlying C interface).
g_type_interface_peek(G_OBJECT_GET_CLASS(self), CppObjectType::get_type()) // Get the interface.
)    );

  // Call the original underlying C function:
  if(base && base->row_changed)
    (*base->row_changed)(self, p0, p1);
}
auto TreeModel_Class::row_inserted_callback (
  GtkTreeModel *self, GtkTreePath *p0, GtkTreeIter *p1) -> void
{
  const auto obj_base = Glib::ObjectBase::_get_current_wrapper((GObject*)self);

  // Non-gtkmmproc-generated custom classes implicitly call the default
  // Glib::ObjectBase constructor, which sets is_derived_. But gtkmmproc-
  // generated classes can use this optimisation, which avoids the unnecessary
  // parameter conversions if there is no possibility of the virtual function
  // being overridden:
  if(obj_base && obj_base->is_derived_())
  {
    const auto obj = dynamic_cast<CppObjectType* const>(obj_base);
    if(obj) // This can be NULL during destruction.
    {
      try // Trap C++ exceptions which would normally be lost because this is a C callback.
      {
        // Call the virtual member method, which derived classes might override.
        obj->on_row_inserted(
          TreePath(p0, true)
, TreeModel::iterator(self, p1)
);
        return;
      }
      catch(...)
      {
        Glib::exception_handlers_invoke();
      }
    }
  }

  const auto base = static_cast<BaseClassType*>(
        g_type_interface_peek_parent( // Get the parent interface of the interface (The original underlying C interface).
g_type_interface_peek(G_OBJECT_GET_CLASS(self), CppObjectType::get_type()) // Get the interface.
)    );

  // Call the original underlying C function:
  if(base && base->row_inserted)
    (*base->row_inserted)(self, p0, p1);
}
auto TreeModel_Class::row_has_child_toggled_callback (
  GtkTreeModel *self, GtkTreePath *p0, GtkTreeIter *p1) -> void
{
  const auto obj_base = Glib::ObjectBase::_get_current_wrapper((GObject*)self);

  // Non-gtkmmproc-generated custom classes implicitly call the default
  // Glib::ObjectBase constructor, which sets is_derived_. But gtkmmproc-
  // generated classes can use this optimisation, which avoids the unnecessary
  // parameter conversions if there is no possibility of the virtual function
  // being overridden:
  if(obj_base && obj_base->is_derived_())
  {
    const auto obj = dynamic_cast<CppObjectType* const>(obj_base);
    if(obj) // This can be NULL during destruction.
    {
      try // Trap C++ exceptions which would normally be lost because this is a C callback.
      {
        // Call the virtual member method, which derived classes might override.
        obj->on_row_has_child_toggled(
          TreePath(p0, true)
, TreeModel::iterator(self, p1)
);
        return;
      }
      catch(...)
      {
        Glib::exception_handlers_invoke();
      }
    }
  }

  const auto base = static_cast<BaseClassType*>(
        g_type_interface_peek_parent( // Get the parent interface of the interface (The original underlying C interface).
g_type_interface_peek(G_OBJECT_GET_CLASS(self), CppObjectType::get_type()) // Get the interface.
)    );

  // Call the original underlying C function:
  if(base && base->row_has_child_toggled)
    (*base->row_has_child_toggled)(self, p0, p1);
}
auto TreeModel_Class::row_deleted_callback (GtkTreeModel *self, GtkTreePath *p0) -> void
{
  const auto obj_base = Glib::ObjectBase::_get_current_wrapper((GObject*)self);

  // Non-gtkmmproc-generated custom classes implicitly call the default
  // Glib::ObjectBase constructor, which sets is_derived_. But gtkmmproc-
  // generated classes can use this optimisation, which avoids the unnecessary
  // parameter conversions if there is no possibility of the virtual function
  // being overridden:
  if(obj_base && obj_base->is_derived_())
  {
    const auto obj = dynamic_cast<CppObjectType* const>(obj_base);
    if(obj) // This can be NULL during destruction.
    {
      try // Trap C++ exceptions which would normally be lost because this is a C callback.
      {
        // Call the virtual member method, which derived classes might override.
        obj->on_row_deleted(
          TreePath(p0, true)
);
        return;
      }
      catch(...)
      {
        Glib::exception_handlers_invoke();
      }
    }
  }

  const auto base = static_cast<BaseClassType*>(
        g_type_interface_peek_parent( // Get the parent interface of the interface (The original underlying C interface).
g_type_interface_peek(G_OBJECT_GET_CLASS(self), CppObjectType::get_type()) // Get the interface.
)    );

  // Call the original underlying C function:
  if(base && base->row_deleted)
    (*base->row_deleted)(self, p0);
}
auto TreeModel_Class::rows_reordered_callback (
  GtkTreeModel *self, GtkTreePath *p0, GtkTreeIter *p1, gint *p2) -> void
{
  const auto obj_base = Glib::ObjectBase::_get_current_wrapper((GObject*)self);

  // Non-gtkmmproc-generated custom classes implicitly call the default
  // Glib::ObjectBase constructor, which sets is_derived_. But gtkmmproc-
  // generated classes can use this optimisation, which avoids the unnecessary
  // parameter conversions if there is no possibility of the virtual function
  // being overridden:
  if(obj_base && obj_base->is_derived_())
  {
    const auto obj = dynamic_cast<CppObjectType* const>(obj_base);
    if(obj) // This can be NULL during destruction.
    {
      try // Trap C++ exceptions which would normally be lost because this is a C callback.
      {
        // Call the virtual member method, which derived classes might override.
        obj->on_rows_reordered(
          TreePath(p0, true)
, TreeModel::iterator(self, p1)
, p2
);
        return;
      }
      catch(...)
      {
        Glib::exception_handlers_invoke();
      }
    }
  }

  const auto base = static_cast<BaseClassType*>(
        g_type_interface_peek_parent( // Get the parent interface of the interface (The original underlying C interface).
g_type_interface_peek(G_OBJECT_GET_CLASS(self), CppObjectType::get_type()) // Get the interface.
)    );

  // Call the original underlying C function:
  if(base && base->rows_reordered)
    (*base->rows_reordered)(self, p0, p1, p2);
}


auto TreeModel_Class::wrap_new(GObject* object) -> Glib::ObjectBase*
{
  return new TreeModel((GtkTreeModel*)object);
}


/* The implementation: */

TreeModel::TreeModel()
: Interface(treemodel_class_.init())
{}

TreeModel::TreeModel(GtkTreeModel* castitem)
: Interface((GObject*)castitem)
{}

TreeModel::TreeModel(const Glib::Interface_Class& interface_class)
: Interface(interface_class)
{
}

TreeModel::TreeModel(TreeModel&& src) noexcept
: Interface(std::move(src))
{}

auto TreeModel::operator=(TreeModel&& src) noexcept -> TreeModel&
{
  Interface::operator=(std::move(src));
  return *this;
}

TreeModel::~TreeModel() noexcept = default;

// static
auto TreeModel::add_interface (
  const GType gtype_implementer) -> void
{
  treemodel_class_.init().add_interface(gtype_implementer);
}

TreeModel::CppClassType TreeModel::treemodel_class_; // initialize static member

auto TreeModel::get_type() -> GType
{
  return treemodel_class_.init().get_type();
}


auto TreeModel::get_base_type() -> GType
{
  return gtk_tree_model_get_type();
}


auto TreeModel::get_flags() const -> Flags
{
  return static_cast<Flags>(gtk_tree_model_get_flags(const_cast<GtkTreeModel*>(gobj())));
}

auto TreeModel::get_n_columns() const -> int
{
  return gtk_tree_model_get_n_columns(const_cast<GtkTreeModel*>(gobj()));
}

auto TreeModel::get_column_type(
  const int index) const -> GType
{
  return gtk_tree_model_get_column_type(const_cast<GtkTreeModel*>(gobj()), index);
}

auto TreeModel::get_path(const const_iterator& iter) const -> Path
{
  return TreePath(gtk_tree_model_get_path(const_cast<GtkTreeModel*>(gobj()), const_cast<GtkTreeIter*>(iter.gobj())), false);
}

auto TreeModel::row_changed (const Path &path, const const_iterator &iter) -> void
{
  gtk_tree_model_row_changed(gobj(), const_cast<GtkTreePath*>(path.gobj()), const_cast<GtkTreeIter*>(iter.gobj()));
}

auto TreeModel::row_inserted (const Path &path, const const_iterator &iter) -> void
{
  gtk_tree_model_row_inserted(gobj(), const_cast<GtkTreePath*>(path.gobj()), const_cast<GtkTreeIter*>(iter.gobj()));
}

auto TreeModel::row_has_child_toggled (const Path &path, const const_iterator &iter) -> void
{
  gtk_tree_model_row_has_child_toggled(gobj(), const_cast<GtkTreePath*>(path.gobj()), const_cast<GtkTreeIter*>(iter.gobj()));
}

auto TreeModel::row_deleted (const Path &path) -> void
{
  gtk_tree_model_row_deleted(gobj(), const_cast<GtkTreePath*>(path.gobj()));
}

auto TreeModel::rows_reordered (
  const Path &path, const const_iterator &iter, int *new_order) -> void
{
  gtk_tree_model_rows_reordered(gobj(), const_cast<GtkTreePath*>(path.gobj()), const_cast<GtkTreeIter*>(iter.gobj()), new_order);
}

auto TreeModel::get_string(const const_iterator& iter) const -> Glib::ustring
{
  return Glib::convert_return_gchar_ptr_to_ustring(gtk_tree_model_get_string_from_iter(const_cast<GtkTreeModel*>(gobj()), const_cast<GtkTreeIter*>(iter.gobj())));
}


auto TreeModel::signal_row_changed() -> Glib::SignalProxy<void(const Path &, const iterator &)>
{
  return {this, &TreeModel_signal_row_changed_info};
}


auto TreeModel::signal_row_inserted() -> Glib::SignalProxy<void(const Path &, const iterator &)>
{
  return {this, &TreeModel_signal_row_inserted_info};
}


auto TreeModel::signal_row_has_child_toggled() -> Glib::SignalProxy<void(const Path &, const iterator &)>
{
  return {this, &TreeModel_signal_row_has_child_toggled_info};
}


auto TreeModel::signal_row_deleted() -> Glib::SignalProxy<void(const Path &)>
{
  return {this, &TreeModel_signal_row_deleted_info};
}


auto TreeModel::signal_rows_reordered() -> Glib::SignalProxy<void(const Path &, const iterator &, int*)>
{
  return {this, &TreeModel_signal_rows_reordered_info};
}


auto TreeModel::on_row_changed (
  const Path &path, const iterator &iter) -> void
{
  const auto base = static_cast<BaseClassType*>(
      g_type_interface_peek_parent(                             // Get the parent interface of the interface (The original underlying C interface).
g_type_interface_peek(G_OBJECT_GET_CLASS(gobject_), get_type()) // Get the interface.
)  );

  if(base && base->row_changed)
    (*base->row_changed)(gobj(),const_cast<GtkTreePath*>(path.gobj()),const_cast<GtkTreeIter*>(iter.gobj()));
}
auto TreeModel::on_row_inserted (
  const Path &path, const iterator &iter) -> void
{
  const auto base = static_cast<BaseClassType*>(
      g_type_interface_peek_parent(                             // Get the parent interface of the interface (The original underlying C interface).
g_type_interface_peek(G_OBJECT_GET_CLASS(gobject_), get_type()) // Get the interface.
)  );

  if(base && base->row_inserted)
    (*base->row_inserted)(gobj(),const_cast<GtkTreePath*>(path.gobj()),const_cast<GtkTreeIter*>(iter.gobj()));
}
auto TreeModel::on_row_has_child_toggled (
  const Path &path, const iterator &iter) -> void
{
  const auto base = static_cast<BaseClassType*>(
      g_type_interface_peek_parent(                             // Get the parent interface of the interface (The original underlying C interface).
g_type_interface_peek(G_OBJECT_GET_CLASS(gobject_), get_type()) // Get the interface.
)  );

  if(base && base->row_has_child_toggled)
    (*base->row_has_child_toggled)(gobj(),const_cast<GtkTreePath*>(path.gobj()),const_cast<GtkTreeIter*>(iter.gobj()));
}
auto TreeModel::on_row_deleted (const Path &path) -> void
{
  const auto base = static_cast<BaseClassType*>(
      g_type_interface_peek_parent(                             // Get the parent interface of the interface (The original underlying C interface).
g_type_interface_peek(G_OBJECT_GET_CLASS(gobject_), get_type()) // Get the interface.
)  );

  if(base && base->row_deleted)
    (*base->row_deleted)(gobj(),const_cast<GtkTreePath*>(path.gobj()));
}
auto TreeModel::on_rows_reordered (
  const Path &path, const iterator &iter, int *new_order) -> void
{
  const auto base = static_cast<BaseClassType*>(
      g_type_interface_peek_parent(                             // Get the parent interface of the interface (The original underlying C interface).
g_type_interface_peek(G_OBJECT_GET_CLASS(gobject_), get_type()) // Get the interface.
)  );

  if(base && base->rows_reordered)
    (*base->rows_reordered)(gobj(),const_cast<GtkTreePath*>(path.gobj()),const_cast<GtkTreeIter*>(iter.gobj()),new_order);
}

auto TreeModel::get_flags_vfunc() const -> Flags
{
  const auto base = static_cast<BaseClassType*>(
      g_type_interface_peek_parent(                             // Get the parent interface of the interface (The original underlying C interface).
g_type_interface_peek(G_OBJECT_GET_CLASS(gobject_), get_type()) // Get the interface.
)  );

  if(base && base->get_flags)
  {
    const Flags retval(static_cast<Flags>((*base->get_flags)(const_cast<GtkTreeModel*>(gobj()))));
    return retval;
  }

  using RType = Flags;
  return RType();
}
auto TreeModel::get_n_columns_vfunc() const -> int
{
  const auto base = static_cast<BaseClassType*>(
      g_type_interface_peek_parent(                             // Get the parent interface of the interface (The original underlying C interface).
g_type_interface_peek(G_OBJECT_GET_CLASS(gobject_), get_type()) // Get the interface.
)  );

  if(base && base->get_n_columns)
  {
    const int retval((*base->get_n_columns)(const_cast<GtkTreeModel*>(gobj())));
    return retval;
  }

  using RType = int;
  return RType();
}
auto TreeModel::get_column_type_vfunc(
  const int index) const -> GType
{
  const auto base = static_cast<BaseClassType*>(
      g_type_interface_peek_parent(                             // Get the parent interface of the interface (The original underlying C interface).
g_type_interface_peek(G_OBJECT_GET_CLASS(gobject_), get_type()) // Get the interface.
)  );

  if(base && base->get_column_type)
  {
    const GType retval((*base->get_column_type)(const_cast<GtkTreeModel*>(gobj()),index));
    return retval;
  }

  using RType = GType;
  return RType();
}
auto TreeModel::iter_has_child_vfunc(const const_iterator& iter) const -> bool
{
  const auto base = static_cast<BaseClassType*>(
      g_type_interface_peek_parent(                             // Get the parent interface of the interface (The original underlying C interface).
g_type_interface_peek(G_OBJECT_GET_CLASS(gobject_), get_type()) // Get the interface.
)  );

  if(base && base->iter_has_child)
  {
    const bool retval((*base->iter_has_child)(const_cast<GtkTreeModel*>(gobj()),const_cast<GtkTreeIter*>(iter.gobj())));
    return retval;
  }

  using RType = bool;
  return RType();
}
auto TreeModel::ref_node_vfunc (const iterator &iter) const -> void
{
  const auto base = static_cast<BaseClassType*>(
      g_type_interface_peek_parent(                             // Get the parent interface of the interface (The original underlying C interface).
g_type_interface_peek(G_OBJECT_GET_CLASS(gobject_), get_type()) // Get the interface.
)  );

  if(base && base->ref_node)
  {
    (*base->ref_node)(const_cast<GtkTreeModel*>(gobj()),const_cast<GtkTreeIter*>(iter.gobj()));
  }
}
auto TreeModel::unref_node_vfunc (const iterator &iter) const -> void
{
  const auto base = static_cast<BaseClassType*>(
      g_type_interface_peek_parent(                             // Get the parent interface of the interface (The original underlying C interface).
g_type_interface_peek(G_OBJECT_GET_CLASS(gobject_), get_type()) // Get the interface.
)  );

  if(base && base->unref_node)
  {
    (*base->unref_node)(const_cast<GtkTreeModel*>(gobj()),const_cast<GtkTreeIter*>(iter.gobj()));
  }
}
auto TreeModel::get_path_vfunc(const const_iterator& iter) const -> Path
{
  const auto base = static_cast<BaseClassType*>(
      g_type_interface_peek_parent(                             // Get the parent interface of the interface (The original underlying C interface).
g_type_interface_peek(G_OBJECT_GET_CLASS(gobject_), get_type()) // Get the interface.
)  );

  if(base && base->get_path)
  {
    Path retval(TreePath((*base->get_path)(const_cast<GtkTreeModel*>(gobj()),const_cast<GtkTreeIter*>(iter.gobj())), false));
    return retval;
  }

  using RType = Path;
  return {};
}
auto TreeModel::get_value_vfunc (
  const const_iterator &iter, const int column, Glib::ValueBase &value) const -> void
{
  const auto base = static_cast<BaseClassType*>(
      g_type_interface_peek_parent(                             // Get the parent interface of the interface (The original underlying C interface).
g_type_interface_peek(G_OBJECT_GET_CLASS(gobject_), get_type()) // Get the interface.
)  );

  if(base && base->get_value)
  {
    (*base->get_value)(const_cast<GtkTreeModel*>(gobj()),const_cast<GtkTreeIter*>(iter.gobj()),column,value.gobj());
  }
}


} // namespace Gtk


