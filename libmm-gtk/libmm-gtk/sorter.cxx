


#include <libmm-glib/mm-glib.hxx>

#include <libmm-gtk/sorter.hxx>
#include <libmm-gtk/sorter_p.hxx>


/* Copyright (C) 2020 The gtkmm Development Team
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

using Order = Gtk::Sorter::Order;
using Change = Gtk::Sorter::Change;

namespace
{


auto Sorter_signal_changed_callback (GtkSorter *self, GtkSorterChange p0, void *data) -> void
{
  using namespace Gtk;
  using SlotType = sigc::slot<void(Change)>;

  const auto obj = dynamic_cast<Sorter*>(Glib::ObjectBase::_get_current_wrapper((GObject*) self));
  // Do not try to call a signal on a disassociated wrapper.
  if(obj)
  {
    try
    {
      if(const auto slot = Glib::SignalProxyNormal::data_to_slot(data))
        (*static_cast<SlotType*>(slot))(static_cast<Change>(p0)
);
    }
    catch(...)
    {
       Glib::exception_handlers_invoke();
    }
  }
}

const Glib::SignalProxyInfo Sorter_signal_changed_info =
{
  "changed",
  (GCallback) &Sorter_signal_changed_callback,
  (GCallback) &Sorter_signal_changed_callback
};


} // anonymous namespace

// static
auto Glib::Value<Gtk::Sorter::Order>::value_type() -> GType
{
  return gtk_sorter_order_get_type();
}

// static
auto Glib::Value<Gtk::Sorter::Change>::value_type() -> GType
{
  return gtk_sorter_change_get_type();
}


namespace Glib
{

auto wrap(GtkSorter* object, const bool take_copy) -> RefPtr<Gtk::Sorter>
{
  return Glib::make_refptr_for_instance<Gtk::Sorter>( dynamic_cast<Gtk::Sorter*> (wrap_auto((GObject*)object, take_copy)) );
  //We use dynamic_cast<> in case of multiple inheritance.
}

} /* namespace Glib */


namespace Gtk
{


/* The *_Class implementation: */

auto Sorter_Class::init() -> const Class&
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Class has to know the class init function to clone custom types.
    class_init_func_ = &Sorter_Class::class_init_function;

    // This is actually just optimized away, apparently with no harm.
    // Make sure that the parent type has been created.
    //CppClassParent::CppObjectType::get_type();

    // Create the wrapper type, with the same class/instance size as the base type.
    register_derived_type(gtk_sorter_get_type());

    // Add derived versions of interfaces, if the C type implements any interfaces:

  }

  return *this;
}


auto Sorter_Class::class_init_function (void *g_class, void *class_data) -> void
{
  const auto klass = static_cast<BaseClassType*>(g_class);
  CppClassParent::class_init_function(klass, class_data);

  klass->compare = &compare_vfunc_callback;
  klass->get_order = &get_order_vfunc_callback;

}

auto Sorter_Class::compare_vfunc_callback(GtkSorter* self, const gpointer item1, const gpointer item2) -> GtkOrdering
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
        return static_cast<GtkOrdering>(obj->compare_vfunc(item1, item2));
      }
      catch(...)
      {
        Glib::exception_handlers_invoke();
      }
    }
  }

  const BaseClassType *const base = static_cast<BaseClassType*>(
      g_type_class_peek_parent(G_OBJECT_GET_CLASS(self)) // Get the parent class of the object class (The original underlying C class).
  );

  // Call the original underlying C function:
  if(base && base->compare)
    return (*base->compare)(self, item1, item2);

  using RType = GtkOrdering;
  return RType();
}
auto Sorter_Class::get_order_vfunc_callback(GtkSorter* self) -> GtkSorterOrder
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
        return static_cast<GtkSorterOrder>(obj->get_order_vfunc());
      }
      catch(...)
      {
        Glib::exception_handlers_invoke();
      }
    }
  }

  const BaseClassType *const base = static_cast<BaseClassType*>(
      g_type_class_peek_parent(G_OBJECT_GET_CLASS(self)) // Get the parent class of the object class (The original underlying C class).
  );

  // Call the original underlying C function:
  if(base && base->get_order)
    return (*base->get_order)(self);

  using RType = GtkSorterOrder;
  return RType();
}


auto Sorter_Class::wrap_new(GObject* object) -> Glib::ObjectBase*
{
  return new Sorter((GtkSorter*)object);
}


/* The implementation: */

auto Sorter::gobj_copy() -> GtkSorter*
{
  reference();
  return gobj();
}

Sorter::Sorter(const Glib::ConstructParams& construct_params)
: Object(construct_params)
{

}

Sorter::Sorter(GtkSorter* castitem)
: Object((GObject*)castitem)
{}


Sorter::Sorter(Sorter&& src) noexcept
: Object(std::move(src))
{}

auto Sorter::operator=(Sorter&& src) noexcept -> Sorter&
{
  Object::operator=(std::move(src));
  return *this;
}


Sorter::~Sorter() noexcept = default;

Sorter::CppClassType Sorter::sorter_class_; // initialize static member

auto Sorter::get_type() -> GType
{
  return sorter_class_.init().get_type();
}


auto Sorter::get_base_type() -> GType
{
  return gtk_sorter_get_type();
}


Sorter::Sorter()
:
  // Mark this class as non-derived to allow C++ vfuncs to be skipped.
ObjectBase(nullptr),
Object(Glib::ConstructParams(sorter_class_.init()))
{


}

auto Sorter::compare(
  const gpointer item1, const gpointer item2) -> Ordering
{
  return static_cast<Ordering>(gtk_sorter_compare(gobj(), item1, item2));
}

auto Sorter::get_order() const -> Order
{
  return static_cast<Order>(gtk_sorter_get_order(const_cast<GtkSorter*>(gobj())));
}

auto Sorter::changed (Change change) -> void
{
  gtk_sorter_changed(gobj(), static_cast<GtkSorterChange>(change));
}


auto Sorter::signal_changed() -> Glib::SignalProxy<void(Change)>
{
  return {this, &Sorter_signal_changed_info};
}


auto Sorter::compare_vfunc(
  const gpointer item1, const gpointer item2) -> Ordering
{
  const auto base = static_cast<BaseClassType*>(
      g_type_class_peek_parent(G_OBJECT_GET_CLASS(gobject_)) // Get the parent class of the object class (The original underlying C class).
  );

  if(base && base->compare)
  {
    const Ordering retval(static_cast<Ordering>((*base->compare)(gobj(),item1,item2)));
    return retval;
  }

  using RType = Ordering;
  return RType();
}
auto Sorter::get_order_vfunc() -> Order
{
  const auto base = static_cast<BaseClassType*>(
      g_type_class_peek_parent(G_OBJECT_GET_CLASS(gobject_)) // Get the parent class of the object class (The original underlying C class).
  );

  if(base && base->get_order)
  {
    const Order retval(static_cast<Order>((*base->get_order)(gobj())));
    return retval;
  }

  using RType = Order;
  return RType();
}


} // namespace Gtk


