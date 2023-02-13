


#include <libmm-glib/mm-glib.hpp>

#include <libmm-gtk/treedragdest.hpp>
#include <libmm-gtk/treedragdest_p.hpp>


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

#include <libmm-gtk/treepath.hpp>
#include <gtk/gtk.h>


namespace
{
} // anonymous namespace


namespace Glib
{

auto wrap(GtkTreeDragDest* object, const bool take_copy) -> RefPtr<Gtk::TreeDragDest>
{
  return Glib::make_refptr_for_instance<Gtk::TreeDragDest>( Glib::wrap_auto_interface<Gtk::TreeDragDest> ((GObject*)object, take_copy) );
  //We use dynamic_cast<> in case of multiple inheritance.
}

} // namespace Glib


namespace Gtk
{


/* The *_Class implementation: */

auto TreeDragDest_Class::init() -> const Interface_Class&
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Interface_Class has to know the interface init function
    // in order to add interfaces to implementing types.
    class_init_func_ = &TreeDragDest_Class::iface_init_function;

    // We can not derive from another interface, and it is not necessary anyway.
    gtype_ = gtk_tree_drag_dest_get_type();
  }

  return *this;
}

auto TreeDragDest_Class::iface_init_function (void *g_iface, void *) -> void
{
  const auto klass = static_cast<BaseClassType*>(g_iface);

  //This is just to avoid an "unused variable" warning when there are no vfuncs or signal handlers to connect.
  //This is a temporary fix until I find out why I can not seem to derive a GtkFileChooser interface. murrayc
  g_assert(klass != nullptr);

  klass->drag_data_received = &drag_data_received_vfunc_callback;
  klass->row_drop_possible = &row_drop_possible_vfunc_callback;

}

auto TreeDragDest_Class::drag_data_received_vfunc_callback(GtkTreeDragDest* self, GtkTreePath* dest, const GValue* value) -> gboolean
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
        return obj->drag_data_received_vfunc(
          TreePath(dest, true)
                                             , *reinterpret_cast<const Glib::ValueBase*>(value)
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
  if(base && base->drag_data_received)
    return (*base->drag_data_received)(self, dest, value);

  using RType = gboolean;
  return RType();
}
auto TreeDragDest_Class::row_drop_possible_vfunc_callback(GtkTreeDragDest* self, GtkTreePath* dest_path, const GValue* value) -> gboolean
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
        return obj->row_drop_possible_vfunc(
          TreePath(dest_path, true)
                                            , *reinterpret_cast<const Glib::ValueBase*>(value)
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
  if(base && base->row_drop_possible)
    return (*base->row_drop_possible)(self, dest_path, value);

  using RType = gboolean;
  return RType();
}


auto TreeDragDest_Class::wrap_new(GObject* object) -> Glib::ObjectBase*
{
  return new TreeDragDest((GtkTreeDragDest*)object);
}


/* The implementation: */

TreeDragDest::TreeDragDest()
: Interface(treedragdest_class_.init())
{}

TreeDragDest::TreeDragDest(GtkTreeDragDest* castitem)
: Interface((GObject*)castitem)
{}

TreeDragDest::TreeDragDest(const Glib::Interface_Class& interface_class)
: Interface(interface_class)
{
}

TreeDragDest::TreeDragDest(TreeDragDest&& src) noexcept
: Interface(std::move(src))
{}

auto TreeDragDest::operator=(TreeDragDest&& src) noexcept -> TreeDragDest&
{
  Interface::operator=(std::move(src));
  return *this;
}

TreeDragDest::~TreeDragDest() noexcept = default;

// static
auto TreeDragDest::add_interface (
  const GType gtype_implementer) -> void
{
  treedragdest_class_.init().add_interface(gtype_implementer);
}

TreeDragDest::CppClassType TreeDragDest::treedragdest_class_; // initialize static member

auto TreeDragDest::get_type() -> GType
{
  return treedragdest_class_.init().get_type();
}


auto TreeDragDest::get_base_type() -> GType
{
  return gtk_tree_drag_dest_get_type();
}


auto TreeDragDest::drag_data_received(const TreeModel::Path& dest, const Glib::ValueBase& value) -> bool
{
  return gtk_tree_drag_dest_drag_data_received(gobj(), const_cast<GtkTreePath*>(dest.gobj()), value.gobj());
}

auto TreeDragDest::row_drop_possible(const TreeModel::Path& dest_path, const Glib::ValueBase& value) const -> bool
{
  return gtk_tree_drag_dest_row_drop_possible(const_cast<GtkTreeDragDest*>(gobj()), const_cast<GtkTreePath*>(dest_path.gobj()), value.gobj());
}


auto TreeDragDest::drag_data_received_vfunc(const TreeModel::Path& dest, const Glib::ValueBase& value) -> bool
{
  const auto base = static_cast<BaseClassType*>(
      g_type_interface_peek_parent(                             // Get the parent interface of the interface (The original underlying C interface).
g_type_interface_peek(G_OBJECT_GET_CLASS(gobject_), get_type()) // Get the interface.
)  );

  if(base && base->drag_data_received)
  {
    const bool retval((*base->drag_data_received)(gobj(),const_cast<GtkTreePath*>(dest.gobj()),value.gobj()));
    return retval;
  }

  using RType = bool;
  return RType();
}
auto TreeDragDest::row_drop_possible_vfunc(const TreeModel::Path& dest, const Glib::ValueBase& value) const -> bool
{
  const auto base = static_cast<BaseClassType*>(
      g_type_interface_peek_parent(                             // Get the parent interface of the interface (The original underlying C interface).
g_type_interface_peek(G_OBJECT_GET_CLASS(gobject_), get_type()) // Get the interface.
)  );

  if(base && base->row_drop_possible)
  {
    const bool retval((*base->row_drop_possible)(const_cast<GtkTreeDragDest*>(gobj()),const_cast<GtkTreePath*>(dest.gobj()),value.gobj()));
    return retval;
  }

  using RType = bool;
  return RType();
}


} // namespace Gtk


