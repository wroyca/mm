// Generated by gmmproc 2.74.0 -- DO NOT MODIFY!


#include <mm/glib/mm-glib.h>

#include <mm/gtk/treesortable.h>
#include <mm/gtk/private/treesortable_p.h>


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

static auto SignalProxy_Compare_gtk_callback(GtkTreeModel* model, GtkTreeIter* lhs, GtkTreeIter* rhs, void* data) -> int
{
  auto the_slot = static_cast<Gtk::TreeSortable::SlotCompare*>(data);

  try
  {
    // use Slot::operator()
    return (*the_slot)(Gtk::TreeModel::const_iterator(model, lhs), Gtk::TreeModel::const_iterator(model, rhs));
  }
  catch(...)
  {
    Glib::exception_handlers_invoke();
  }

  return 0;
}

static void SignalProxy_Compare_gtk_callback_destroy(void* data)
{
  delete static_cast<Gtk::TreeSortable::SlotCompare*>(data);
}

namespace Gtk
{

void TreeSortable::set_sort_func(int sort_column_id, const SlotCompare& slot)
{
  auto slot_copy = new SlotCompare(slot);

  gtk_tree_sortable_set_sort_func(
      gobj(), sort_column_id,
      &SignalProxy_Compare_gtk_callback, slot_copy,
      &SignalProxy_Compare_gtk_callback_destroy);
}

void TreeSortable::set_sort_func(const Gtk::TreeModelColumnBase& sort_column, const SlotCompare& slot)
{
  set_sort_func(sort_column.index(), slot);
}

void TreeSortable::set_default_sort_func(const SlotCompare& slot)
{
  auto slot_copy = new SlotCompare(slot);

  gtk_tree_sortable_set_default_sort_func(
      gobj(),
      &SignalProxy_Compare_gtk_callback, slot_copy,
      &SignalProxy_Compare_gtk_callback_destroy);
}

void TreeSortable::unset_default_sort_func()
{
  gtk_tree_sortable_set_default_sort_func(
      gobj(), nullptr, nullptr, nullptr); /* See GTK+ docs about the nullptrs. */
}

} // namespace Gtk

namespace
{


const Glib::SignalProxyInfo TreeSortable_signal_sort_column_changed_info =
{
  "sort_column_changed",
  (GCallback) &Glib::SignalProxyNormal::slot0_void_callback,
  (GCallback) &Glib::SignalProxyNormal::slot0_void_callback
};


} // anonymous namespace


namespace Glib
{

auto wrap(GtkTreeSortable* object, bool take_copy) -> Glib::RefPtr<Gtk::TreeSortable>
{
  return Glib::make_refptr_for_instance<Gtk::TreeSortable>( dynamic_cast<Gtk::TreeSortable*> (Glib::wrap_auto_interface<Gtk::TreeSortable> ((GObject*)(object), take_copy)) );
  //We use dynamic_cast<> in case of multiple inheritance.
}

} // namespace Glib


namespace Gtk
{


/* The *_Class implementation: */

auto TreeSortable_Class::init() -> const Glib::Interface_Class&
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Interface_Class has to know the interface init function
    // in order to add interfaces to implementing types.
    class_init_func_ = &TreeSortable_Class::iface_init_function;

    // We can not derive from another interface, and it is not necessary anyway.
    gtype_ = gtk_tree_sortable_get_type();
  }

  return *this;
}

void TreeSortable_Class::iface_init_function(void* g_iface, void*)
{
  const auto klass = static_cast<BaseClassType*>(g_iface);

  //This is just to avoid an "unused variable" warning when there are no vfuncs or signal handlers to connect.
  //This is a temporary fix until I find out why I can not seem to derive a GtkFileChooser interface. murrayc
  g_assert(klass != nullptr);

  klass->get_sort_column_id = &get_sort_column_id_vfunc_callback;
  klass->set_sort_column_id = &set_sort_column_id_vfunc_callback;
  klass->set_sort_func = &set_sort_func_vfunc_callback;
  klass->set_default_sort_func = &set_default_sort_func_vfunc_callback;
  klass->has_default_sort_func = &has_default_sort_func_vfunc_callback;
  klass->sort_column_changed = &sort_column_changed_vfunc_callback;

  klass->sort_column_changed = &sort_column_changed_callback;
}

auto TreeSortable_Class::get_sort_column_id_vfunc_callback(GtkTreeSortable* self, int* sort_column_id, GtkSortType* order) -> gboolean
{
  const auto obj_base = static_cast<Glib::ObjectBase*>(
      Glib::ObjectBase::_get_current_wrapper((GObject*)self));

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
        return static_cast<int>(obj->get_sort_column_id_vfunc(sort_column_id, ((SortType*) (order))
));
      }
      catch(...)
      {
        Glib::exception_handlers_invoke();
      }
    }
  }

  BaseClassType *const base = static_cast<BaseClassType*>(
      g_type_interface_peek_parent( // Get the parent interface of the interface (The original underlying C interface).
g_type_interface_peek(G_OBJECT_GET_CLASS(self), CppObjectType::get_type()) // Get the interface.
)  );

  // Call the original underlying C function:
  if(base && base->get_sort_column_id)
    return (*base->get_sort_column_id)(self, sort_column_id, order);

  using RType = gboolean;
  return RType();
}
void TreeSortable_Class::set_sort_column_id_vfunc_callback(GtkTreeSortable* self, int sort_column_id, GtkSortType order)
{
  const auto obj_base = static_cast<Glib::ObjectBase*>(
      Glib::ObjectBase::_get_current_wrapper((GObject*)self));

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
        obj->set_sort_column_id_vfunc(sort_column_id, static_cast<SortType>(order)
);
        return;
      }
      catch(...)
      {
        Glib::exception_handlers_invoke();
      }
    }
  }

  BaseClassType *const base = static_cast<BaseClassType*>(
      g_type_interface_peek_parent( // Get the parent interface of the interface (The original underlying C interface).
g_type_interface_peek(G_OBJECT_GET_CLASS(self), CppObjectType::get_type()) // Get the interface.
)  );

  // Call the original underlying C function:
  if(base && base->set_sort_column_id)
    (*base->set_sort_column_id)(self, sort_column_id, order);
}
void TreeSortable_Class::set_sort_func_vfunc_callback(GtkTreeSortable* self, int sort_column_id, GtkTreeIterCompareFunc func, gpointer data, GDestroyNotify destroy)
{
  const auto obj_base = static_cast<Glib::ObjectBase*>(
      Glib::ObjectBase::_get_current_wrapper((GObject*)self));

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
        obj->set_sort_func_vfunc(sort_column_id, func, data
, destroy);
        return;
      }
      catch(...)
      {
        Glib::exception_handlers_invoke();
      }
    }
  }

  BaseClassType *const base = static_cast<BaseClassType*>(
      g_type_interface_peek_parent( // Get the parent interface of the interface (The original underlying C interface).
g_type_interface_peek(G_OBJECT_GET_CLASS(self), CppObjectType::get_type()) // Get the interface.
)  );

  // Call the original underlying C function:
  if(base && base->set_sort_func)
    (*base->set_sort_func)(self, sort_column_id, func, data, destroy);
}
void TreeSortable_Class::set_default_sort_func_vfunc_callback(GtkTreeSortable* self, GtkTreeIterCompareFunc func, gpointer data, GDestroyNotify destroy)
{
  const auto obj_base = static_cast<Glib::ObjectBase*>(
      Glib::ObjectBase::_get_current_wrapper((GObject*)self));

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
        obj->set_default_sort_func_vfunc(func, data
, destroy);
        return;
      }
      catch(...)
      {
        Glib::exception_handlers_invoke();
      }
    }
  }

  BaseClassType *const base = static_cast<BaseClassType*>(
      g_type_interface_peek_parent( // Get the parent interface of the interface (The original underlying C interface).
g_type_interface_peek(G_OBJECT_GET_CLASS(self), CppObjectType::get_type()) // Get the interface.
)  );

  // Call the original underlying C function:
  if(base && base->set_default_sort_func)
    (*base->set_default_sort_func)(self, func, data, destroy);
}
auto TreeSortable_Class::has_default_sort_func_vfunc_callback(GtkTreeSortable* self) -> gboolean
{
  const auto obj_base = static_cast<Glib::ObjectBase*>(
      Glib::ObjectBase::_get_current_wrapper((GObject*)self));

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
        return static_cast<int>(obj->has_default_sort_func_vfunc());
      }
      catch(...)
      {
        Glib::exception_handlers_invoke();
      }
    }
  }

  BaseClassType *const base = static_cast<BaseClassType*>(
      g_type_interface_peek_parent( // Get the parent interface of the interface (The original underlying C interface).
g_type_interface_peek(G_OBJECT_GET_CLASS(self), CppObjectType::get_type()) // Get the interface.
)  );

  // Call the original underlying C function:
  if(base && base->has_default_sort_func)
    return (*base->has_default_sort_func)(self);

  using RType = gboolean;
  return RType();
}
void TreeSortable_Class::sort_column_changed_vfunc_callback(GtkTreeSortable* self)
{
  const auto obj_base = static_cast<Glib::ObjectBase*>(
      Glib::ObjectBase::_get_current_wrapper((GObject*)self));

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
        obj->sort_column_changed_vfunc();
        return;
      }
      catch(...)
      {
        Glib::exception_handlers_invoke();
      }
    }
  }

  BaseClassType *const base = static_cast<BaseClassType*>(
      g_type_interface_peek_parent( // Get the parent interface of the interface (The original underlying C interface).
g_type_interface_peek(G_OBJECT_GET_CLASS(self), CppObjectType::get_type()) // Get the interface.
)  );

  // Call the original underlying C function:
  if(base && base->sort_column_changed)
    (*base->sort_column_changed)(self);
}

void TreeSortable_Class::sort_column_changed_callback(GtkTreeSortable* self)
{
  const auto obj_base = static_cast<Glib::ObjectBase*>(
      Glib::ObjectBase::_get_current_wrapper((GObject*)self));

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
        obj->on_sort_column_changed();
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
  if(base && base->sort_column_changed)
    (*base->sort_column_changed)(self);
}


auto TreeSortable_Class::wrap_new(GObject* object) -> Glib::ObjectBase*
{
  return new TreeSortable((GtkTreeSortable*)(object));
}


/* The implementation: */

TreeSortable::TreeSortable()
:
  Glib::Interface(treesortable_class_.init())
{}

TreeSortable::TreeSortable(GtkTreeSortable* castitem)
:
  Glib::Interface((GObject*)(castitem))
{}

TreeSortable::TreeSortable(const Glib::Interface_Class& interface_class)
: Glib::Interface(interface_class)
{
}

TreeSortable::TreeSortable(TreeSortable&& src) noexcept
: Glib::Interface(std::move(src))
{}

auto TreeSortable::operator=(TreeSortable&& src) noexcept -> TreeSortable&
{
  Glib::Interface::operator=(std::move(src));
  return *this;
}

TreeSortable::~TreeSortable() noexcept
{}

// static
void TreeSortable::add_interface(GType gtype_implementer)
{
  treesortable_class_.init().add_interface(gtype_implementer);
}

TreeSortable::CppClassType TreeSortable::treesortable_class_; // initialize static member

auto TreeSortable::get_type() -> GType
{
  return treesortable_class_.init().get_type();
}


auto TreeSortable::get_base_type() -> GType
{
  return gtk_tree_sortable_get_type();
}


auto TreeSortable::get_sort_column_id(int& sort_column_id, SortType& order) const -> bool
{
  return gtk_tree_sortable_get_sort_column_id(const_cast<GtkTreeSortable*>(gobj()), &(sort_column_id), ((GtkSortType*) &(order)));
}

void TreeSortable::set_sort_column(const TreeModelColumnBase& sort_column_id, SortType order)
{
  gtk_tree_sortable_set_sort_column_id(gobj(), (sort_column_id).index(), static_cast<GtkSortType>(order));
}

void TreeSortable::set_sort_column(int sort_column_id, SortType order)
{
  gtk_tree_sortable_set_sort_column_id(gobj(), sort_column_id, static_cast<GtkSortType>(order));
}

auto TreeSortable::has_default_sort_func() const -> bool
{
  return gtk_tree_sortable_has_default_sort_func(const_cast<GtkTreeSortable*>(gobj()));
}

void TreeSortable::sort_column_changed()
{
  gtk_tree_sortable_sort_column_changed(gobj());
}


auto TreeSortable::signal_sort_column_changed() -> Glib::SignalProxy<void()>
{
  return Glib::SignalProxy<void() >(this, &TreeSortable_signal_sort_column_changed_info);
}


void Gtk::TreeSortable::on_sort_column_changed()
{
  const auto base = static_cast<BaseClassType*>(
      g_type_interface_peek_parent( // Get the parent interface of the interface (The original underlying C interface).
g_type_interface_peek(G_OBJECT_GET_CLASS(gobject_), CppObjectType::get_type()) // Get the interface.
)  );

  if(base && base->sort_column_changed)
    (*base->sort_column_changed)(gobj());
}

auto Gtk::TreeSortable::get_sort_column_id_vfunc(int* sort_column_id, SortType* order) const -> bool
{
  const auto base = static_cast<BaseClassType*>(
      g_type_interface_peek_parent( // Get the parent interface of the interface (The original underlying C interface).
g_type_interface_peek(G_OBJECT_GET_CLASS(gobject_), CppObjectType::get_type()) // Get the interface.
)  );

  if(base && base->get_sort_column_id)
  {
    bool retval((*base->get_sort_column_id)(const_cast<GtkTreeSortable*>(gobj()),sort_column_id,((GtkSortType*) (order))));
    return retval;
  }

  using RType = bool;
  return RType();
}
void Gtk::TreeSortable::set_sort_column_id_vfunc(int sort_column_id, SortType order)
{
  const auto base = static_cast<BaseClassType*>(
      g_type_interface_peek_parent( // Get the parent interface of the interface (The original underlying C interface).
g_type_interface_peek(G_OBJECT_GET_CLASS(gobject_), CppObjectType::get_type()) // Get the interface.
)  );

  if(base && base->set_sort_column_id)
  {
    (*base->set_sort_column_id)(gobj(),sort_column_id,static_cast<GtkSortType>(order));
  }
}
void Gtk::TreeSortable::set_sort_func_vfunc(int sort_column_id, GtkTreeIterCompareFunc func, void* data, GDestroyNotify destroy)
{
  const auto base = static_cast<BaseClassType*>(
      g_type_interface_peek_parent( // Get the parent interface of the interface (The original underlying C interface).
g_type_interface_peek(G_OBJECT_GET_CLASS(gobject_), CppObjectType::get_type()) // Get the interface.
)  );

  if(base && base->set_sort_func)
  {
    (*base->set_sort_func)(gobj(),sort_column_id,func,data,destroy);
  }
}
void Gtk::TreeSortable::set_default_sort_func_vfunc(GtkTreeIterCompareFunc func, void* data, GDestroyNotify destroy)
{
  const auto base = static_cast<BaseClassType*>(
      g_type_interface_peek_parent( // Get the parent interface of the interface (The original underlying C interface).
g_type_interface_peek(G_OBJECT_GET_CLASS(gobject_), CppObjectType::get_type()) // Get the interface.
)  );

  if(base && base->set_default_sort_func)
  {
    (*base->set_default_sort_func)(gobj(),func,data,destroy);
  }
}
auto Gtk::TreeSortable::has_default_sort_func_vfunc() const -> bool
{
  const auto base = static_cast<BaseClassType*>(
      g_type_interface_peek_parent( // Get the parent interface of the interface (The original underlying C interface).
g_type_interface_peek(G_OBJECT_GET_CLASS(gobject_), CppObjectType::get_type()) // Get the interface.
)  );

  if(base && base->has_default_sort_func)
  {
    bool retval((*base->has_default_sort_func)(const_cast<GtkTreeSortable*>(gobj())));
    return retval;
  }

  using RType = bool;
  return RType();
}
void Gtk::TreeSortable::sort_column_changed_vfunc() const
{
  const auto base = static_cast<BaseClassType*>(
      g_type_interface_peek_parent( // Get the parent interface of the interface (The original underlying C interface).
g_type_interface_peek(G_OBJECT_GET_CLASS(gobject_), CppObjectType::get_type()) // Get the interface.
)  );

  if(base && base->sort_column_changed)
  {
    (*base->sort_column_changed)(const_cast<GtkTreeSortable*>(gobj()));
  }
}


} // namespace Gtk


