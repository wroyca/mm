


#include <libmm-glib/mm-glib.hpp>

#include <libmm-gtk/celllayout.hpp>
#include <libmm-gtk/celllayout_p.hpp>


/* Copyright 2003 The gtkmm Development Team
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

#include <libmm-gtk/cellarea.hpp>
#include <gtk/gtk.h>


static auto SignalProxy_CellData_gtk_callback (
  GtkCellLayout * /* cell_layout */, GtkCellRenderer * /* cell */, GtkTreeModel *tree_model,
  GtkTreeIter *iter, const gpointer data) -> void
{
  const auto the_slot = static_cast<Gtk::CellLayout::SlotCellData*>(data);

  try
  {
    //We ignore the cell, because that was given as an argument to the connecting method, so the caller should know which one it is already.
    //And we ignore the tree_model because that can be obtained from the iter or from the CellLayout itself.
    (*the_slot)(Gtk::TreeModel::const_iterator(tree_model, iter));
  }
  catch(...)
  {
    Glib::exception_handlers_invoke();
  }
}

static auto SignalProxy_CellData_gtk_callback_destroy (void *data) -> void
{
  delete static_cast<Gtk::CellLayout::SlotCellData*>(data);
}

namespace Gtk
{

auto CellLayout::add_attribute (
  const Glib::PropertyProxy_Base &property, const TreeModelColumnBase &column) -> void
{
  gtk_cell_layout_add_attribute(gobj(),
      (GtkCellRenderer*) property.get_object()->gobj(), property.get_name(), column.index());
}

auto CellLayout::add_attribute (
  CellRenderer &cell, const Glib::ustring &attribute, const TreeModelColumnBase &column) -> void
{
  gtk_cell_layout_add_attribute(gobj(),
      cell.gobj(), attribute.c_str(), column.index());
}

auto CellLayout::set_cell_data_func (CellRenderer &cell, const SlotCellData &slot) -> void
{
  // Create a copy of the slot object.  A pointer to this will be passed
  // through the callback's data parameter.  It will be deleted
  // when SignalProxy_CellData_gtk_callback_destroy() is called.
  const auto slot_copy = new SlotCellData(slot);

  gtk_cell_layout_set_cell_data_func(gobj(), cell.gobj(),
      &SignalProxy_CellData_gtk_callback, slot_copy,
      &SignalProxy_CellData_gtk_callback_destroy);
}

auto CellLayout::get_first_cell() -> CellRenderer*
{
  const auto vecCellRenderers = get_cells();
  if(!vecCellRenderers.empty())
    return vecCellRenderers[0];
  else
    return nullptr;
}

auto CellLayout::get_first_cell() const -> const CellRenderer*
{
  //Do some const_cast-ing to avoid repetition of code:
  return const_cast<CellLayout*>(this)->get_first_cell();
}


} //namespace Gtk


namespace
{
} // anonymous namespace


namespace Glib
{

auto wrap(GtkCellLayout* object, const bool take_copy) -> RefPtr<Gtk::CellLayout>
{
  return Glib::make_refptr_for_instance<Gtk::CellLayout>( Glib::wrap_auto_interface<Gtk::CellLayout> ((GObject*)object, take_copy) );
  //We use dynamic_cast<> in case of multiple inheritance.
}

} // namespace Glib


namespace Gtk
{


/* The *_Class implementation: */

auto CellLayout_Class::init() -> const Interface_Class&
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Interface_Class has to know the interface init function
    // in order to add interfaces to implementing types.
    class_init_func_ = &CellLayout_Class::iface_init_function;

    // We can not derive from another interface, and it is not necessary anyway.
    gtype_ = gtk_cell_layout_get_type();
  }

  return *this;
}

auto CellLayout_Class::iface_init_function (void *g_iface, void *) -> void
{
  const auto klass = static_cast<BaseClassType*>(g_iface);

  //This is just to avoid an "unused variable" warning when there are no vfuncs or signal handlers to connect.
  //This is a temporary fix until I find out why I can not seem to derive a GtkFileChooser interface. murrayc
  g_assert(klass != nullptr);

  klass->pack_start = &pack_start_vfunc_callback;
  klass->pack_end = &pack_end_vfunc_callback;
  klass->clear = &clear_vfunc_callback;
  klass->add_attribute = &add_attribute_vfunc_callback;
  klass->clear_attributes = &clear_attributes_vfunc_callback;
  klass->reorder = &reorder_vfunc_callback;

}

auto CellLayout_Class::pack_start_vfunc_callback (
  GtkCellLayout *self, GtkCellRenderer *cell, const gboolean expand) -> void
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
        obj->pack_start_vfunc(Glib::wrap(cell)
, expand
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
  if(base && base->pack_start)
    (*base->pack_start)(self, cell, expand);
}
auto CellLayout_Class::pack_end_vfunc_callback (
  GtkCellLayout *self, GtkCellRenderer *cell, const gboolean expand) -> void
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
        obj->pack_end_vfunc(Glib::wrap(cell)
, expand
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
  if(base && base->pack_end)
    (*base->pack_end)(self, cell, expand);
}
auto CellLayout_Class::clear_vfunc_callback (GtkCellLayout *self) -> void
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
        obj->clear_vfunc();
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
  if(base && base->clear)
    (*base->clear)(self);
}
auto CellLayout_Class::add_attribute_vfunc_callback (
  GtkCellLayout *self, GtkCellRenderer *cell, const gchar *attribute, const gint column) -> void
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
        obj->add_attribute_vfunc(Glib::wrap(cell)
, Glib::convert_const_gchar_ptr_to_ustring(attribute)
, column
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
  if(base && base->add_attribute)
    (*base->add_attribute)(self, cell, attribute, column);
}
auto CellLayout_Class::clear_attributes_vfunc_callback (
  GtkCellLayout *self, GtkCellRenderer *cell) -> void
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
        obj->clear_attributes_vfunc(Glib::wrap(cell)
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
  if(base && base->clear_attributes)
    (*base->clear_attributes)(self, cell);
}
auto CellLayout_Class::reorder_vfunc_callback (
  GtkCellLayout *self, GtkCellRenderer *cell, const gint position) -> void
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
        obj->reorder_vfunc(Glib::wrap(cell)
, position
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
  if(base && base->reorder)
    (*base->reorder)(self, cell, position);
}


auto CellLayout_Class::wrap_new(GObject* object) -> Glib::ObjectBase*
{
  return new CellLayout((GtkCellLayout*)object);
}


/* The implementation: */

CellLayout::CellLayout()
: Interface(celllayout_class_.init())
{}

CellLayout::CellLayout(GtkCellLayout* castitem)
: Interface((GObject*)castitem)
{}

CellLayout::CellLayout(const Glib::Interface_Class& interface_class)
: Interface(interface_class)
{
}

CellLayout::CellLayout(CellLayout&& src) noexcept
: Interface(std::move(src))
{}

auto CellLayout::operator=(CellLayout&& src) noexcept -> CellLayout&
{
  Interface::operator=(std::move(src));
  return *this;
}

CellLayout::~CellLayout() noexcept = default;

// static
auto CellLayout::add_interface (
  const GType gtype_implementer) -> void
{
  celllayout_class_.init().add_interface(gtype_implementer);
}

CellLayout::CppClassType CellLayout::celllayout_class_; // initialize static member

auto CellLayout::get_type() -> GType
{
  return celllayout_class_.init().get_type();
}


auto CellLayout::get_base_type() -> GType
{
  return gtk_cell_layout_get_type();
}


auto CellLayout::pack_start (CellRenderer &cell, const bool expand) -> void
{
  gtk_cell_layout_pack_start(gobj(), cell.gobj(), expand);
}

auto CellLayout::pack_end (CellRenderer &cell, const bool expand) -> void
{
  gtk_cell_layout_pack_end(gobj(), cell.gobj(), expand);
}

auto CellLayout::get_cells() -> std::vector<CellRenderer*>
{
  return Glib::ListHandler<CellRenderer*>::list_to_vector(gtk_cell_layout_get_cells(gobj()), Glib::OWNERSHIP_SHALLOW);
}

auto CellLayout::get_cells() const -> std::vector<const CellRenderer*>
{
  return Glib::ListHandler<const CellRenderer*>::list_to_vector(gtk_cell_layout_get_cells(const_cast<GtkCellLayout*>(gobj())), Glib::OWNERSHIP_SHALLOW);
}

auto CellLayout::clear () -> void
{
  gtk_cell_layout_clear(gobj());
}

auto CellLayout::add_attribute (
  CellRenderer &cell, const Glib::ustring &attribute, const int column) -> void
{
  gtk_cell_layout_add_attribute(gobj(), cell.gobj(), attribute.c_str(), column);
}

auto CellLayout::clear_attributes (CellRenderer &cell) -> void
{
  gtk_cell_layout_clear_attributes(gobj(), cell.gobj());
}

auto CellLayout::reorder (CellRenderer &cell, const int position) -> void
{
  gtk_cell_layout_reorder(gobj(), cell.gobj(), position);
}

auto CellLayout::get_area() -> Glib::RefPtr<CellArea>
{
  auto retvalue = Glib::wrap(gtk_cell_layout_get_area(gobj()));
  if(retvalue)
    retvalue->reference(); //The function does not do a ref for us.
  return retvalue;
}

auto CellLayout::get_area() const -> Glib::RefPtr<const CellArea>
{
  return const_cast<CellLayout*>(this)->get_area();
}


auto CellLayout::pack_start_vfunc (CellRenderer *cell, const bool expand) -> void
{
  const auto base = static_cast<BaseClassType*>(
      g_type_interface_peek_parent(                             // Get the parent interface of the interface (The original underlying C interface).
g_type_interface_peek(G_OBJECT_GET_CLASS(gobject_), get_type()) // Get the interface.
)  );

  if(base && base->pack_start)
  {
    (*base->pack_start)(gobj(),Glib::unwrap(cell),static_cast<int>(expand));
  }
}
auto CellLayout::pack_end_vfunc (CellRenderer *cell, const bool expand) -> void
{
  const auto base = static_cast<BaseClassType*>(
      g_type_interface_peek_parent(                             // Get the parent interface of the interface (The original underlying C interface).
g_type_interface_peek(G_OBJECT_GET_CLASS(gobject_), get_type()) // Get the interface.
)  );

  if(base && base->pack_end)
  {
    (*base->pack_end)(gobj(),Glib::unwrap(cell),static_cast<int>(expand));
  }
}
auto CellLayout::clear_vfunc () -> void
{
  const auto base = static_cast<BaseClassType*>(
      g_type_interface_peek_parent(                             // Get the parent interface of the interface (The original underlying C interface).
g_type_interface_peek(G_OBJECT_GET_CLASS(gobject_), get_type()) // Get the interface.
)  );

  if(base && base->clear)
  {
    (*base->clear)(gobj());
  }
}
auto CellLayout::add_attribute_vfunc (
  CellRenderer *cell, const Glib::ustring &attribute, const int column) -> void
{
  const auto base = static_cast<BaseClassType*>(
      g_type_interface_peek_parent(                             // Get the parent interface of the interface (The original underlying C interface).
g_type_interface_peek(G_OBJECT_GET_CLASS(gobject_), get_type()) // Get the interface.
)  );

  if(base && base->add_attribute)
  {
    (*base->add_attribute)(gobj(),Glib::unwrap(cell),attribute.c_str(),column);
  }
}
auto CellLayout::clear_attributes_vfunc (CellRenderer *cell) -> void
{
  const auto base = static_cast<BaseClassType*>(
      g_type_interface_peek_parent(                             // Get the parent interface of the interface (The original underlying C interface).
g_type_interface_peek(G_OBJECT_GET_CLASS(gobject_), get_type()) // Get the interface.
)  );

  if(base && base->clear_attributes)
  {
    (*base->clear_attributes)(gobj(),Glib::unwrap(cell));
  }
}
auto CellLayout::reorder_vfunc (CellRenderer *cell, const int position) -> void
{
  const auto base = static_cast<BaseClassType*>(
      g_type_interface_peek_parent(                             // Get the parent interface of the interface (The original underlying C interface).
g_type_interface_peek(G_OBJECT_GET_CLASS(gobject_), get_type()) // Get the interface.
)  );

  if(base && base->reorder)
  {
    (*base->reorder)(gobj(),Glib::unwrap(cell),position);
  }
}


} // namespace Gtk


