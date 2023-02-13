


#include <mm/glib/mm-glib.hpp>

#include <mm/gio/listmodel.hpp>
#include <mm/gio/private/listmodel_p.hpp>


/* Copyright (C) 2016 The giomm Development Team
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
 * License along with this library.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <gio/gio.h>

namespace Gio
{

} // namespace Gio

namespace
{


auto ListModel_signal_items_changed_callback (
  GListModel *self, const guint p0, const guint p1, const guint p2, void *data) -> void
{
  using namespace Gio;
  using SlotType = sigc::slot<void(guint, guint, guint)>;

  const auto obj = dynamic_cast<ListModel*>(Glib::ObjectBase::_get_current_wrapper((GObject*) self));
  // Do not try to call a signal on a disassociated wrapper.
  if(obj)
  {
    try
    {
      if(const auto slot = Glib::SignalProxyNormal::data_to_slot(data))
        (*static_cast<SlotType*>(slot))(p0, p1, p2);
    }
    catch(...)
    {
       Glib::exception_handlers_invoke();
    }
  }
}

const Glib::SignalProxyInfo ListModel_signal_items_changed_info =
{
  "items-changed",
  (GCallback) &ListModel_signal_items_changed_callback,
  (GCallback) &ListModel_signal_items_changed_callback
};


} // anonymous namespace


namespace Glib
{

auto wrap(GListModel* object, const bool take_copy) -> RefPtr<Gio::ListModel>
{
  return Glib::make_refptr_for_instance<Gio::ListModel>( Glib::wrap_auto_interface<Gio::ListModel> ((GObject*)object, take_copy) );
  //We use dynamic_cast<> in case of multiple inheritance.
}

} // namespace Glib


namespace Gio
{


/* The *_Class implementation: */

auto ListModel_Class::init() -> const Interface_Class&
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Interface_Class has to know the interface init function
    // in order to add interfaces to implementing types.
    class_init_func_ = &ListModel_Class::iface_init_function;

    // We can not derive from another interface, and it is not necessary anyway.
    gtype_ = g_list_model_get_type();
  }

  return *this;
}

auto ListModel_Class::iface_init_function (void *g_iface, void *) -> void
{
  const auto klass = static_cast<BaseClassType*>(g_iface);

  //This is just to avoid an "unused variable" warning when there are no vfuncs or signal handlers to connect.
  //This is a temporary fix until I find out why I can not seem to derive a GtkFileChooser interface. murrayc
  g_assert(klass != nullptr);

  klass->get_item_type = &get_item_type_vfunc_callback;
  klass->get_n_items = &get_n_items_vfunc_callback;
  klass->get_item = &get_item_vfunc_callback;

}

auto ListModel_Class::get_item_type_vfunc_callback(GListModel* self) -> GType
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
        return obj->get_item_type_vfunc();
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
  if(base && base->get_item_type)
    return (*base->get_item_type)(self);

  using RType = GType;
  return RType();
}
auto ListModel_Class::get_n_items_vfunc_callback(GListModel* self) -> guint
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
        return obj->get_n_items_vfunc();
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
  if(base && base->get_n_items)
    return (*base->get_n_items)(self);

  using RType = guint;
  return RType();
}
auto ListModel_Class::get_item_vfunc_callback(GListModel* self, const guint position) -> gpointer
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
        return obj->get_item_vfunc(position);
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
  if(base && base->get_item)
    return (*base->get_item)(self, position);

  using RType = gpointer;
  return RType();
}


auto ListModel_Class::wrap_new(GObject* object) -> Glib::ObjectBase*
{
  return new ListModel((GListModel*)object);
}


/* The implementation: */

ListModel::ListModel()
: Interface(listmodel_class_.init())
{}

ListModel::ListModel(GListModel* castitem)
: Interface((GObject*)castitem)
{}

ListModel::ListModel(const Glib::Interface_Class& interface_class)
: Interface(interface_class)
{
}

ListModel::ListModel(ListModel&& src) noexcept
: Interface(std::move(src))
{}

auto ListModel::operator=(ListModel&& src) noexcept -> ListModel&
{
  Interface::operator=(std::move(src));
  return *this;
}

ListModel::~ListModel() noexcept = default;

// static
auto ListModel::add_interface (
  const GType gtype_implementer) -> void
{
  listmodel_class_.init().add_interface(gtype_implementer);
}

ListModel::CppClassType ListModel::listmodel_class_; // initialize static member

auto ListModel::get_type() -> GType
{
  return listmodel_class_.init().get_type();
}


auto ListModel::get_base_type() -> GType
{
  return g_list_model_get_type();
}


auto ListModel::items_changed (
  const guint position, const guint removed, const guint added) -> void
{
  g_list_model_items_changed(gobj(), position, removed, added);
}

auto ListModel::get_item_type() const -> GType
{
  return g_list_model_get_item_type(const_cast<GListModel*>(gobj()));
}

auto ListModel::get_n_items() const -> guint
{
  return g_list_model_get_n_items(const_cast<GListModel*>(gobj()));
}

auto ListModel::get_object(
  const guint position) -> Glib::RefPtr<ObjectBase>
{
  return Glib::make_refptr_for_instance<ObjectBase>(Glib::wrap_auto(g_list_model_get_object(gobj(), position)));
}

auto ListModel::get_object(
  const guint position) const -> Glib::RefPtr<const ObjectBase>
{
  return const_cast<ListModel*>(this)->get_object(position);
}


auto ListModel::signal_items_changed() -> Glib::SignalProxy<void(guint, guint, guint)>
{
  return {this, &ListModel_signal_items_changed_info};
}


auto ListModel::get_item_type_vfunc() -> GType
{
  const auto base = static_cast<BaseClassType*>(
      g_type_interface_peek_parent(                             // Get the parent interface of the interface (The original underlying C interface).
g_type_interface_peek(G_OBJECT_GET_CLASS(gobject_), get_type()) // Get the interface.
)  );

  if(base && base->get_item_type)
  {
    const GType retval((*base->get_item_type)(gobj()));
    return retval;
  }

  using RType = GType;
  return RType();
}
auto ListModel::get_n_items_vfunc() -> guint
{
  const auto base = static_cast<BaseClassType*>(
      g_type_interface_peek_parent(                             // Get the parent interface of the interface (The original underlying C interface).
g_type_interface_peek(G_OBJECT_GET_CLASS(gobject_), get_type()) // Get the interface.
)  );

  if(base && base->get_n_items)
  {
    const guint retval((*base->get_n_items)(gobj()));
    return retval;
  }

  using RType = guint;
  return RType();
}
auto ListModel::get_item_vfunc(
  const guint position) -> gpointer
{
  const auto base = static_cast<BaseClassType*>(
      g_type_interface_peek_parent(                             // Get the parent interface of the interface (The original underlying C interface).
g_type_interface_peek(G_OBJECT_GET_CLASS(gobject_), get_type()) // Get the interface.
)  );

  if(base && base->get_item)
  {
    const gpointer retval((*base->get_item)(gobj(),position));
    return retval;
  }

  using RType = gpointer;
  return RType();
}


} // namespace Gio


