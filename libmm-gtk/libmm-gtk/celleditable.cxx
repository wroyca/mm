


#include <libmm-glib/mm-glib.hxx>

#include <libmm-gtk/celleditable.hxx>
#include <libmm-gtk/celleditable_p.hxx>


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

#include <gtk/gtk.h>


namespace
{


const Glib::SignalProxyInfo CellEditable_signal_editing_done_info =
{
  "editing_done",
  (GCallback) &Glib::SignalProxyNormal::slot0_void_callback,
  (GCallback) &Glib::SignalProxyNormal::slot0_void_callback
};


const Glib::SignalProxyInfo CellEditable_signal_remove_widget_info =
{
  "remove_widget",
  (GCallback) &Glib::SignalProxyNormal::slot0_void_callback,
  (GCallback) &Glib::SignalProxyNormal::slot0_void_callback
};


} // anonymous namespace


namespace Glib
{

auto wrap(GtkCellEditable* object, const bool take_copy) -> RefPtr<Gtk::CellEditable>
{
  return Glib::make_refptr_for_instance<Gtk::CellEditable>( Glib::wrap_auto_interface<Gtk::CellEditable> ((GObject*)object, take_copy) );
  //We use dynamic_cast<> in case of multiple inheritance.
}

} // namespace Glib


namespace Gtk
{


/* The *_Class implementation: */

auto CellEditable_Class::init() -> const Interface_Class&
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Interface_Class has to know the interface init function
    // in order to add interfaces to implementing types.
    class_init_func_ = &CellEditable_Class::iface_init_function;

    // We can not derive from another interface, and it is not necessary anyway.
    gtype_ = gtk_cell_editable_get_type();
  }

  return *this;
}

auto CellEditable_Class::iface_init_function (void *g_iface, void *) -> void
{
  const auto klass = static_cast<BaseClassType*>(g_iface);

  //This is just to avoid an "unused variable" warning when there are no vfuncs or signal handlers to connect.
  //This is a temporary fix until I find out why I can not seem to derive a GtkFileChooser interface. murrayc
  g_assert(klass != nullptr);

  klass->start_editing = &start_editing_vfunc_callback;

  klass->editing_done = &editing_done_callback;
  klass->remove_widget = &remove_widget_callback;
}

auto CellEditable_Class::start_editing_vfunc_callback (
  GtkCellEditable *self, GdkEvent *event) -> void
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
        obj->start_editing_vfunc(Glib::wrap(event, true)
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
  if(base && base->start_editing)
    (*base->start_editing)(self, event);
}

auto CellEditable_Class::editing_done_callback (GtkCellEditable *self) -> void
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
        obj->on_editing_done();
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
  if(base && base->editing_done)
    (*base->editing_done)(self);
}
auto CellEditable_Class::remove_widget_callback (GtkCellEditable *self) -> void
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
        obj->on_remove_widget();
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
  if(base && base->remove_widget)
    (*base->remove_widget)(self);
}


auto CellEditable_Class::wrap_new(GObject* object) -> Glib::ObjectBase*
{
  return new CellEditable((GtkCellEditable*)object);
}


/* The implementation: */

CellEditable::CellEditable()
: Interface(celleditable_class_.init())
{}

CellEditable::CellEditable(GtkCellEditable* castitem)
: Interface((GObject*)castitem)
{}

CellEditable::CellEditable(const Glib::Interface_Class& interface_class)
: Interface(interface_class)
{
}

CellEditable::CellEditable(CellEditable&& src) noexcept
: Interface(std::move(src))
{}

auto CellEditable::operator=(CellEditable&& src) noexcept -> CellEditable&
{
  Interface::operator=(std::move(src));
  return *this;
}

CellEditable::~CellEditable() noexcept = default;

// static
auto CellEditable::add_interface (
  const GType gtype_implementer) -> void
{
  celleditable_class_.init().add_interface(gtype_implementer);
}

CellEditable::CppClassType CellEditable::celleditable_class_; // initialize static member

auto CellEditable::get_type() -> GType
{
  return celleditable_class_.init().get_type();
}


auto CellEditable::get_base_type() -> GType
{
  return gtk_cell_editable_get_type();
}


auto CellEditable::start_editing (const Glib::RefPtr <const Gdk::Event> &event) -> void
{
  gtk_cell_editable_start_editing(gobj(), const_cast<GdkEvent*>(Glib::unwrap(event)));
}

auto CellEditable::editing_done () -> void
{
  gtk_cell_editable_editing_done(gobj());
}

auto CellEditable::remove_widget () -> void
{
  gtk_cell_editable_remove_widget(gobj());
}


auto CellEditable::signal_editing_done() -> Glib::SignalProxy<void()>
{
  return {this, &CellEditable_signal_editing_done_info};
}


auto CellEditable::signal_remove_widget() -> Glib::SignalProxy<void()>
{
  return {this, &CellEditable_signal_remove_widget_info};
}


auto CellEditable::property_editing_canceled() -> Glib::PropertyProxy< bool >
{
  return {this, "editing-canceled"};
}

auto CellEditable::property_editing_canceled() const -> Glib::PropertyProxy_ReadOnly< bool >
{
  return {this, "editing-canceled"};
}


auto CellEditable::on_editing_done () -> void
{
  const auto base = static_cast<BaseClassType*>(
      g_type_interface_peek_parent(                             // Get the parent interface of the interface (The original underlying C interface).
g_type_interface_peek(G_OBJECT_GET_CLASS(gobject_), get_type()) // Get the interface.
)  );

  if(base && base->editing_done)
    (*base->editing_done)(gobj());
}
auto CellEditable::on_remove_widget () -> void
{
  const auto base = static_cast<BaseClassType*>(
      g_type_interface_peek_parent(                             // Get the parent interface of the interface (The original underlying C interface).
g_type_interface_peek(G_OBJECT_GET_CLASS(gobject_), get_type()) // Get the interface.
)  );

  if(base && base->remove_widget)
    (*base->remove_widget)(gobj());
}

auto CellEditable::start_editing_vfunc (const Glib::RefPtr <const Gdk::Event> &event) -> void
{
  const auto base = static_cast<BaseClassType*>(
      g_type_interface_peek_parent(                             // Get the parent interface of the interface (The original underlying C interface).
g_type_interface_peek(G_OBJECT_GET_CLASS(gobject_), get_type()) // Get the interface.
)  );

  if(base && base->start_editing)
  {
    (*base->start_editing)(gobj(),const_cast<GdkEvent*>(Glib::unwrap(event)));
  }
}


} // namespace Gtk


