


#include <libmm-glib/mm-glib.hpp>

#include <libmm-gtk/flowboxchild.hpp>
#include <libmm-gtk/flowboxchild_p.hpp>


/* Copyright (C) 2014 The gtkmm Development Team
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

namespace Gtk
{

auto FlowBoxChild::unset_child () -> void
{
  gtk_flow_box_child_set_child(gobj(), nullptr);
}

} // namespace Gtk

namespace
{


const Glib::SignalProxyInfo FlowBoxChild_signal_activate_info =
{
  "activate",
  (GCallback) &Glib::SignalProxyNormal::slot0_void_callback,
  (GCallback) &Glib::SignalProxyNormal::slot0_void_callback
};


} // anonymous namespace


namespace Glib
{

auto wrap(GtkFlowBoxChild* object, const bool take_copy) -> Gtk::FlowBoxChild*
{
  return dynamic_cast<Gtk::FlowBoxChild *> (wrap_auto((GObject*)object, take_copy));
}

} /* namespace Glib */

namespace Gtk
{


/* The *_Class implementation: */

auto FlowBoxChild_Class::init() -> const Class&
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Class has to know the class init function to clone custom types.
    class_init_func_ = &FlowBoxChild_Class::class_init_function;

    // This is actually just optimized away, apparently with no harm.
    // Make sure that the parent type has been created.
    //CppClassParent::CppObjectType::get_type();

    // Create the wrapper type, with the same class/instance size as the base type.
    register_derived_type(gtk_flow_box_child_get_type());

    // Add derived versions of interfaces, if the C type implements any interfaces:

  }

  return *this;
}


auto FlowBoxChild_Class::class_init_function (void *g_class, void *class_data) -> void
{
  const auto klass = static_cast<BaseClassType*>(g_class);
  CppClassParent::class_init_function(klass, class_data);


  klass->activate = &activate_callback;
}


auto FlowBoxChild_Class::activate_callback (GtkFlowBoxChild *self) -> void
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
        obj->on_activate();
        return;
      }
      catch(...)
      {
        Glib::exception_handlers_invoke();
      }
    }
  }

  const auto base = static_cast<BaseClassType*>(
        g_type_class_peek_parent(G_OBJECT_GET_CLASS(self)) // Get the parent class of the object class (The original underlying C class).
    );

  // Call the original underlying C function:
  if(base && base->activate)
    (*base->activate)(self);
}


auto FlowBoxChild_Class::wrap_new(GObject* o) -> Glib::ObjectBase*
{
  return manage(new FlowBoxChild((GtkFlowBoxChild*)o));

}


/* The implementation: */

FlowBoxChild::FlowBoxChild(const Glib::ConstructParams& construct_params)
: Widget(construct_params)
{
  }

FlowBoxChild::FlowBoxChild(GtkFlowBoxChild* castitem)
: Widget((GtkWidget*)castitem)
{
  }


FlowBoxChild::FlowBoxChild(FlowBoxChild&& src) noexcept
: Widget(std::move(src))
{}

auto FlowBoxChild::operator=(FlowBoxChild&& src) noexcept -> FlowBoxChild&
{
  Widget::operator=(std::move(src));
  return *this;
}

FlowBoxChild::~FlowBoxChild() noexcept
{
  destroy_();
}

FlowBoxChild::CppClassType FlowBoxChild::flowboxchild_class_; // initialize static member

auto FlowBoxChild::get_type() -> GType
{
  return flowboxchild_class_.init().get_type();
}


auto FlowBoxChild::get_base_type() -> GType
{
  return gtk_flow_box_child_get_type();
}


FlowBoxChild::FlowBoxChild()
:
  // Mark this class as non-derived to allow C++ vfuncs to be skipped.
ObjectBase(nullptr),
Widget(Glib::ConstructParams(flowboxchild_class_.init()))
{


}

auto FlowBoxChild::set_child (Widget &child) -> void
{
  gtk_flow_box_child_set_child(gobj(), child.gobj());
}

auto FlowBoxChild::get_child() -> Widget*
{
  return Glib::wrap(gtk_flow_box_child_get_child(gobj()));
}

auto FlowBoxChild::get_child() const -> const Widget*
{
  return const_cast<FlowBoxChild*>(this)->get_child();
}

auto FlowBoxChild::get_index() const -> int
{
  return gtk_flow_box_child_get_index(const_cast<GtkFlowBoxChild*>(gobj()));
}

auto FlowBoxChild::is_selected() const -> bool
{
  return gtk_flow_box_child_is_selected(const_cast<GtkFlowBoxChild*>(gobj()));
}

auto FlowBoxChild::changed () -> void
{
  gtk_flow_box_child_changed(gobj());
}


auto FlowBoxChild::signal_activate() -> Glib::SignalProxy<void()>
{
  return {this, &FlowBoxChild_signal_activate_info};
}


auto FlowBoxChild::property_child() -> Glib::PropertyProxy< Widget* >
{
  return {this, "child"};
}

auto FlowBoxChild::property_child() const -> Glib::PropertyProxy_ReadOnly< Widget* >
{
  return {this, "child"};
}


auto FlowBoxChild::on_activate () -> void
{
  const auto base = static_cast<BaseClassType*>(
      g_type_class_peek_parent(G_OBJECT_GET_CLASS(gobject_)) // Get the parent class of the object class (The original underlying C class).
  );

  if(base && base->activate)
    (*base->activate)(gobj());
}


} // namespace Gtk


