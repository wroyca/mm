


#include <mm/glib/mm-glib.hpp>

#include <mm/gtk/selectionmodel.hpp>
#include <mm/gtk/private/selectionmodel_p.hpp>


/* Copyright (C) 2019 The gtkmm Development Team
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
 * License along with this library. If not, see <http://www.gnu.org/licenses/>.
 */

#include <gtk/gtk.h>

namespace
{


auto SelectionModel_signal_selection_changed_callback (
  GtkSelectionModel *self, const guint p0, const guint p1, void *data) -> void
{
  using namespace Gtk;
  using SlotType = sigc::slot<void(guint, guint)>;

  const auto obj = dynamic_cast<SelectionModel*>(Glib::ObjectBase::_get_current_wrapper((GObject*) self));
  // Do not try to call a signal on a disassociated wrapper.
  if(obj)
  {
    try
    {
      if(const auto slot = Glib::SignalProxyNormal::data_to_slot(data))
        (*static_cast<SlotType*>(slot))(p0, p1);
    }
    catch(...)
    {
       Glib::exception_handlers_invoke();
    }
  }
}

const Glib::SignalProxyInfo SelectionModel_signal_selection_changed_info =
{
  "selection-changed",
  (GCallback) &SelectionModel_signal_selection_changed_callback,
  (GCallback) &SelectionModel_signal_selection_changed_callback
};


} // anonymous namespace


namespace Glib
{

auto wrap(GtkSelectionModel* object, const bool take_copy) -> RefPtr<Gtk::SelectionModel>
{
  return Glib::make_refptr_for_instance<Gtk::SelectionModel>( Glib::wrap_auto_interface<Gtk::SelectionModel> ((GObject*)object, take_copy) );
  //We use dynamic_cast<> in case of multiple inheritance.
}

} // namespace Glib


namespace Gtk
{


/* The *_Class implementation: */

auto SelectionModel_Class::init() -> const Interface_Class&
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Interface_Class has to know the interface init function
    // in order to add interfaces to implementing types.
    class_init_func_ = &SelectionModel_Class::iface_init_function;

    // We can not derive from another interface, and it is not necessary anyway.
    gtype_ = gtk_selection_model_get_type();
  }

  return *this;
}

auto SelectionModel_Class::iface_init_function (void *g_iface, void *) -> void
{
  const auto klass = static_cast<BaseClassType*>(g_iface);

  //This is just to avoid an "unused variable" warning when there are no vfuncs or signal handlers to connect.
  //This is a temporary fix until I find out why I can not seem to derive a GtkFileChooser interface. murrayc
  g_assert(klass != nullptr);

  klass->is_selected = &is_selected_vfunc_callback;
  klass->get_selection_in_range = &get_selection_in_range_vfunc_callback;
  klass->select_item = &select_item_vfunc_callback;
  klass->unselect_item = &unselect_item_vfunc_callback;
  klass->select_range = &select_range_vfunc_callback;
  klass->unselect_range = &unselect_range_vfunc_callback;
  klass->select_all = &select_all_vfunc_callback;
  klass->unselect_all = &unselect_all_vfunc_callback;
  klass->set_selection = &set_selection_vfunc_callback;

}

auto SelectionModel_Class::is_selected_vfunc_callback(GtkSelectionModel* self, const guint position) -> gboolean
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
        return obj->is_selected_vfunc(position);
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
  if(base && base->is_selected)
    return (*base->is_selected)(self, position);

  using RType = gboolean;
  return RType();
}
auto SelectionModel_Class::get_selection_in_range_vfunc_callback(GtkSelectionModel* self, const guint position, const guint n_items) -> GtkBitset*
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
        return Glib::unwrap_copy(std::const_pointer_cast<Bitset>(obj->get_selection_vfunc(position, n_items)));
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
  if(base && base->get_selection_in_range)
    return (*base->get_selection_in_range)(self, position, n_items);

  using RType = GtkBitset*;
  return RType();
}
auto SelectionModel_Class::select_item_vfunc_callback(GtkSelectionModel* self, const guint position, const gboolean unselect_rest) -> gboolean
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
        return obj->select_item_vfunc(position, unselect_rest
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
  if(base && base->select_item)
    return (*base->select_item)(self, position, unselect_rest);

  using RType = gboolean;
  return RType();
}
auto SelectionModel_Class::unselect_item_vfunc_callback(GtkSelectionModel* self, const guint position) -> gboolean
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
        return obj->unselect_item_vfunc(position);
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
  if(base && base->unselect_item)
    return (*base->unselect_item)(self, position);

  using RType = gboolean;
  return RType();
}
auto SelectionModel_Class::select_range_vfunc_callback(GtkSelectionModel* self, const guint position, const guint n_items, const gboolean unselect_rest) -> gboolean
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
        return obj->select_range_vfunc(position, n_items, unselect_rest
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
  if(base && base->select_range)
    return (*base->select_range)(self, position, n_items, unselect_rest);

  using RType = gboolean;
  return RType();
}
auto SelectionModel_Class::unselect_range_vfunc_callback(GtkSelectionModel* self, const guint position, const guint n_items) -> gboolean
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
        return obj->unselect_range_vfunc(position, n_items);
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
  if(base && base->unselect_range)
    return (*base->unselect_range)(self, position, n_items);

  using RType = gboolean;
  return RType();
}
auto SelectionModel_Class::select_all_vfunc_callback(GtkSelectionModel* self) -> gboolean
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
        return obj->select_all_vfunc();
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
  if(base && base->select_all)
    return (*base->select_all)(self);

  using RType = gboolean;
  return RType();
}
auto SelectionModel_Class::unselect_all_vfunc_callback(GtkSelectionModel* self) -> gboolean
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
        return obj->unselect_all_vfunc();
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
  if(base && base->unselect_all)
    return (*base->unselect_all)(self);

  using RType = gboolean;
  return RType();
}
auto SelectionModel_Class::set_selection_vfunc_callback(GtkSelectionModel* self, GtkBitset* selected, GtkBitset* mask) -> gboolean
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
        return obj->set_selection_vfunc(Glib::wrap(selected, true)
                                        , Glib::wrap(mask, true)
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
  if(base && base->set_selection)
    return (*base->set_selection)(self, selected, mask);

  using RType = gboolean;
  return RType();
}


auto SelectionModel_Class::wrap_new(GObject* object) -> Glib::ObjectBase*
{
  return new SelectionModel((GtkSelectionModel*)object);
}


/* The implementation: */

SelectionModel::SelectionModel()
: Interface(selectionmodel_class_.init())
{}

SelectionModel::SelectionModel(GtkSelectionModel* castitem)
: Interface((GObject*)castitem)
{}

SelectionModel::SelectionModel(const Glib::Interface_Class& interface_class)
: Interface(interface_class)
{
}

SelectionModel::SelectionModel(SelectionModel&& src) noexcept
: Interface(std::move(src))
{}

auto SelectionModel::operator=(SelectionModel&& src) noexcept -> SelectionModel&
{
  Interface::operator=(std::move(src));
  return *this;
}

SelectionModel::~SelectionModel() noexcept = default;

// static
auto SelectionModel::add_interface (
  const GType gtype_implementer) -> void
{
  selectionmodel_class_.init().add_interface(gtype_implementer);
}

SelectionModel::CppClassType SelectionModel::selectionmodel_class_; // initialize static member

auto SelectionModel::get_type() -> GType
{
  return selectionmodel_class_.init().get_type();
}


auto SelectionModel::get_base_type() -> GType
{
  return gtk_selection_model_get_type();
}


auto SelectionModel::is_selected(
  const guint position) const -> bool
{
  return gtk_selection_model_is_selected(const_cast<GtkSelectionModel*>(gobj()), position);
}

auto SelectionModel::get_selection() const -> Glib::RefPtr<const Bitset>
{
  return Glib::wrap(gtk_selection_model_get_selection(const_cast<GtkSelectionModel*>(gobj())));
}

auto SelectionModel::get_selection(
  const guint position, const guint n_items) const -> Glib::RefPtr<const Bitset>
{
  return Glib::wrap(gtk_selection_model_get_selection_in_range(const_cast<GtkSelectionModel*>(gobj()), position, n_items));
}

auto SelectionModel::select_item(
  const guint position, const bool unselect_rest) -> bool
{
  return gtk_selection_model_select_item(gobj(), position, unselect_rest);
}

auto SelectionModel::unselect_item(
  const guint position) -> bool
{
  return gtk_selection_model_unselect_item(gobj(), position);
}

auto SelectionModel::select_range(
  const guint position, const guint n_items, const bool unselect_rest) -> bool
{
  return gtk_selection_model_select_range(gobj(), position, n_items, unselect_rest);
}

auto SelectionModel::unselect_range(
  const guint position, const guint n_items) -> bool
{
  return gtk_selection_model_unselect_range(gobj(), position, n_items);
}

auto SelectionModel::select_all() -> bool
{
  return gtk_selection_model_select_all(gobj());
}

auto SelectionModel::unselect_all() -> bool
{
  return gtk_selection_model_unselect_all(gobj());
}

auto SelectionModel::set_selection(const Glib::RefPtr<const Bitset>& selected, const Glib::RefPtr<const Bitset>& mask) -> bool
{
  return gtk_selection_model_set_selection(gobj(), const_cast<GtkBitset*>(Glib::unwrap(selected)), const_cast<GtkBitset*>(Glib::unwrap(mask)));
}

auto SelectionModel::selection_changed (
  const guint position, const guint n_items) -> void
{
  gtk_selection_model_selection_changed(gobj(), position, n_items);
}


auto SelectionModel::signal_selection_changed() -> Glib::SignalProxy<void(guint, guint)>
{
  return {this, &SelectionModel_signal_selection_changed_info};
}


auto SelectionModel::is_selected_vfunc(
  const guint position) const -> bool
{
  const auto base = static_cast<BaseClassType*>(
      g_type_interface_peek_parent(                             // Get the parent interface of the interface (The original underlying C interface).
g_type_interface_peek(G_OBJECT_GET_CLASS(gobject_), get_type()) // Get the interface.
)  );

  if(base && base->is_selected)
  {
    const bool retval((*base->is_selected)(const_cast<GtkSelectionModel*>(gobj()),position));
    return retval;
  }

  using RType = bool;
  return RType();
}
auto SelectionModel::get_selection_vfunc(
  const guint position, const guint n_items) -> Glib::RefPtr<const Bitset>
{
  const auto base = static_cast<BaseClassType*>(
      g_type_interface_peek_parent(                             // Get the parent interface of the interface (The original underlying C interface).
g_type_interface_peek(G_OBJECT_GET_CLASS(gobject_), get_type()) // Get the interface.
)  );

  if(base && base->get_selection_in_range)
  {
    Glib::RefPtr<const Bitset> retval(Glib::wrap((*base->get_selection_in_range)(gobj(),position,n_items)));
    return retval;
  }

  using RType = Glib::RefPtr<const Bitset>;
  return {};
}
auto SelectionModel::select_item_vfunc(
  const guint position, const bool unselect_rest) -> bool
{
  const auto base = static_cast<BaseClassType*>(
      g_type_interface_peek_parent(                             // Get the parent interface of the interface (The original underlying C interface).
g_type_interface_peek(G_OBJECT_GET_CLASS(gobject_), get_type()) // Get the interface.
)  );

  if(base && base->select_item)
  {
    const bool retval((*base->select_item)(gobj(),position,static_cast<int>(unselect_rest)));
    return retval;
  }

  using RType = bool;
  return RType();
}
auto SelectionModel::unselect_item_vfunc(
  const guint position) -> bool
{
  const auto base = static_cast<BaseClassType*>(
      g_type_interface_peek_parent(                             // Get the parent interface of the interface (The original underlying C interface).
g_type_interface_peek(G_OBJECT_GET_CLASS(gobject_), get_type()) // Get the interface.
)  );

  if(base && base->unselect_item)
  {
    const bool retval((*base->unselect_item)(gobj(),position));
    return retval;
  }

  using RType = bool;
  return RType();
}
auto SelectionModel::select_range_vfunc(
  const guint position, const guint n_items, const bool unselect_rest) -> bool
{
  const auto base = static_cast<BaseClassType*>(
      g_type_interface_peek_parent(                             // Get the parent interface of the interface (The original underlying C interface).
g_type_interface_peek(G_OBJECT_GET_CLASS(gobject_), get_type()) // Get the interface.
)  );

  if(base && base->select_range)
  {
    const bool retval((*base->select_range)(gobj(),position,n_items,static_cast<int>(unselect_rest)));
    return retval;
  }

  using RType = bool;
  return RType();
}
auto SelectionModel::unselect_range_vfunc(
  const guint position, const guint n_items) -> bool
{
  const auto base = static_cast<BaseClassType*>(
      g_type_interface_peek_parent(                             // Get the parent interface of the interface (The original underlying C interface).
g_type_interface_peek(G_OBJECT_GET_CLASS(gobject_), get_type()) // Get the interface.
)  );

  if(base && base->unselect_range)
  {
    const bool retval((*base->unselect_range)(gobj(),position,n_items));
    return retval;
  }

  using RType = bool;
  return RType();
}
auto SelectionModel::select_all_vfunc() -> bool
{
  const auto base = static_cast<BaseClassType*>(
      g_type_interface_peek_parent(                             // Get the parent interface of the interface (The original underlying C interface).
g_type_interface_peek(G_OBJECT_GET_CLASS(gobject_), get_type()) // Get the interface.
)  );

  if(base && base->select_all)
  {
    const bool retval((*base->select_all)(gobj()));
    return retval;
  }

  using RType = bool;
  return RType();
}
auto SelectionModel::unselect_all_vfunc() -> bool
{
  const auto base = static_cast<BaseClassType*>(
      g_type_interface_peek_parent(                             // Get the parent interface of the interface (The original underlying C interface).
g_type_interface_peek(G_OBJECT_GET_CLASS(gobject_), get_type()) // Get the interface.
)  );

  if(base && base->unselect_all)
  {
    const bool retval((*base->unselect_all)(gobj()));
    return retval;
  }

  using RType = bool;
  return RType();
}
auto SelectionModel::set_selection_vfunc(const Glib::RefPtr<const Bitset>& selected, const Glib::RefPtr<const Bitset>& mask) -> bool
{
  const auto base = static_cast<BaseClassType*>(
      g_type_interface_peek_parent(                             // Get the parent interface of the interface (The original underlying C interface).
g_type_interface_peek(G_OBJECT_GET_CLASS(gobject_), get_type()) // Get the interface.
)  );

  if(base && base->set_selection)
  {
    const bool retval((*base->set_selection)(gobj(),const_cast<GtkBitset*>(Glib::unwrap(selected)),const_cast<GtkBitset*>(Glib::unwrap(mask))));
    return retval;
  }

  using RType = bool;
  return RType();
}


} // namespace Gtk


