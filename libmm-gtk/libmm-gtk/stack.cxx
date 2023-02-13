


#include <libmm-glib/mm-glib.hxx>

#include <libmm-gtk/stack.hxx>
#include <libmm-gtk/stack_p.hxx>

#include <gtk/gtk.h>

/*
 * Copyright 2013 The gtkmm Development Team
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

#include <libmm-gtk/selectionlistmodelimpl.hxx>
#include <gtk/gtk.h>

namespace Gtk
{

auto Stack::get_pages() -> Glib::RefPtr<SelectionModel>
{
  // gtk_stack_get_pages() returns a pointer to a private GObject class that
  // implements GListModel and GtkSelectionModel.
  // Such an instance is wrapped in a Gtk::SelectionListModelImpl.
  // gtk_stack_get_pages() gives us a ref (transfer full).
  GtkSelectionModel* stack_pages = gtk_stack_get_pages(gobj());
  if (G_IS_LIST_MODEL(stack_pages))
  {
    // Look up current C++ wrapper instance:
    ObjectBase * pCppObject = _get_current_wrapper((GObject*)stack_pages);
    if (!pCppObject)
      pCppObject = new SelectionListModelImpl((GObject*)stack_pages);
    return Glib::make_refptr_for_instance<SelectionModel>(dynamic_cast<SelectionModel*>(pCppObject));
  }
  return Glib::wrap(stack_pages);
}

} //namespace Gtk

namespace
{
} // anonymous namespace


namespace Glib
{

auto wrap(GtkStack* object, const bool take_copy) -> Gtk::Stack*
{
  return dynamic_cast<Gtk::Stack *> (wrap_auto((GObject*)object, take_copy));
}

} /* namespace Glib */

namespace Gtk
{


/* The *_Class implementation: */

auto Stack_Class::init() -> const Class&
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Class has to know the class init function to clone custom types.
    class_init_func_ = &Stack_Class::class_init_function;

    // This is actually just optimized away, apparently with no harm.
    // Make sure that the parent type has been created.
    //CppClassParent::CppObjectType::get_type();

    // Create the wrapper type, with the same class/instance size as the base type.
    register_derived_type(gtk_stack_get_type());

    // Add derived versions of interfaces, if the C type implements any interfaces:

  }

  return *this;
}


auto Stack_Class::class_init_function (void *g_class, void *class_data) -> void
{
  const auto klass = static_cast<BaseClassType*>(g_class);
  CppClassParent::class_init_function(klass, class_data);


}


auto Stack_Class::wrap_new(GObject* o) -> Glib::ObjectBase*
{
  return manage(new Stack((GtkStack*)o));

}


/* The implementation: */

Stack::Stack(const Glib::ConstructParams& construct_params)
: Widget(construct_params)
{
  }

Stack::Stack(GtkStack* castitem)
: Widget((GtkWidget*)castitem)
{
  }


Stack::Stack(Stack&& src) noexcept
: Widget(std::move(src))
{}

auto Stack::operator=(Stack&& src) noexcept -> Stack&
{
  Widget::operator=(std::move(src));
  return *this;
}

Stack::~Stack() noexcept
{
  destroy_();
}

Stack::CppClassType Stack::stack_class_; // initialize static member

auto Stack::get_type() -> GType
{
  return stack_class_.init().get_type();
}


auto Stack::get_base_type() -> GType
{
  return gtk_stack_get_type();
}


Stack::Stack()
:
  // Mark this class as non-derived to allow C++ vfuncs to be skipped.
ObjectBase(nullptr),
Widget(Glib::ConstructParams(stack_class_.init()))
{


}

auto Stack::add(Widget& child) -> Glib::RefPtr<StackPage>
{
  auto retvalue = Glib::wrap(gtk_stack_add_child(gobj(), child.gobj()));
  if(retvalue)
    retvalue->reference(); //The function does not do a ref for us.
  return retvalue;
}

auto Stack::add(Widget& child, const Glib::ustring& name) -> Glib::RefPtr<StackPage>
{
  auto retvalue = Glib::wrap(gtk_stack_add_named(gobj(), child.gobj(), name.c_str()));
  if(retvalue)
    retvalue->reference(); //The function does not do a ref for us.
  return retvalue;
}

auto Stack::add(Widget& child, const Glib::ustring& name, const Glib::ustring& title) -> Glib::RefPtr<StackPage>
{
  auto retvalue = Glib::wrap(gtk_stack_add_titled(gobj(), child.gobj(), name.c_str(), title.c_str()));
  if(retvalue)
    retvalue->reference(); //The function does not do a ref for us.
  return retvalue;
}

auto Stack::remove (Widget &child) -> void
{
  gtk_stack_remove(gobj(), child.gobj());
}

auto Stack::get_page(Widget& child) -> Glib::RefPtr<StackPage>
{
  auto retvalue = Glib::wrap(gtk_stack_get_page(gobj(), child.gobj()));
  if(retvalue)
    retvalue->reference(); //The function does not do a ref for us.
  return retvalue;
}

auto Stack::get_page(const Widget& child) const -> Glib::RefPtr<const StackPage>
{
  auto retvalue = Glib::wrap(gtk_stack_get_page(const_cast<GtkStack*>(gobj()), const_cast<GtkWidget*>(child.gobj())));
  if(retvalue)
    retvalue->reference(); //The function does not do a ref for us.
  return retvalue;
}

auto Stack::set_visible_child (Widget &child) -> void
{
  gtk_stack_set_visible_child(gobj(), child.gobj());
}

auto Stack::get_visible_child() -> Widget*
{
  return Glib::wrap(gtk_stack_get_visible_child(gobj()));
}

auto Stack::get_visible_child() const -> const Widget*
{
  return const_cast<Stack*>(this)->get_visible_child();
}

auto Stack::set_visible_child (const Glib::ustring &name) -> void
{
  gtk_stack_set_visible_child_name(gobj(), name.c_str());
}

auto Stack::set_visible_child (const Glib::ustring &name, StackTransitionType transition) -> void
{
  gtk_stack_set_visible_child_full(gobj(), name.c_str(), static_cast<GtkStackTransitionType>(transition));
}

auto Stack::get_visible_child_name() const -> Glib::ustring
{
  return Glib::convert_const_gchar_ptr_to_ustring(gtk_stack_get_visible_child_name(const_cast<GtkStack*>(gobj())));
}

auto Stack::set_hhomogeneous (
  const bool hhomogeneous) -> void
{
  gtk_stack_set_hhomogeneous(gobj(), hhomogeneous);
}

auto Stack::get_hhomogeneous() const -> bool
{
  return gtk_stack_get_hhomogeneous(const_cast<GtkStack*>(gobj()));
}

auto Stack::set_vhomogeneous (
  const bool vhomogeneous) -> void
{
  gtk_stack_set_vhomogeneous(gobj(), vhomogeneous);
}

auto Stack::get_vhomogeneous() const -> bool
{
  return gtk_stack_get_vhomogeneous(const_cast<GtkStack*>(gobj()));
}

auto Stack::set_transition_duration (
  const guint duration) -> void
{
  gtk_stack_set_transition_duration(gobj(), duration);
}

auto Stack::get_transition_duration() const -> guint
{
  return gtk_stack_get_transition_duration(const_cast<GtkStack*>(gobj()));
}

auto Stack::set_transition_type (StackTransitionType transition) -> void
{
  gtk_stack_set_transition_type(gobj(), static_cast<GtkStackTransitionType>(transition));
}

auto Stack::get_transition_type() const -> StackTransitionType
{
  return static_cast<StackTransitionType>(gtk_stack_get_transition_type(const_cast<GtkStack*>(gobj())));
}

auto Stack::get_transition_running() const -> bool
{
  return gtk_stack_get_transition_running(const_cast<GtkStack*>(gobj()));
}

auto Stack::get_child_by_name(const Glib::ustring& name) -> Widget*
{
  return Glib::wrap(gtk_stack_get_child_by_name(gobj(), name.c_str()));
}

auto Stack::get_child_by_name(const Glib::ustring& name) const -> const Widget*
{
  return const_cast<Stack*>(this)->get_child_by_name(name);
}

auto Stack::set_interpolate_size (
  const bool interpolate_size) -> void
{
  gtk_stack_set_interpolate_size(gobj(), interpolate_size);
}

auto Stack::get_interpolate_size() const -> bool
{
  return gtk_stack_get_interpolate_size(const_cast<GtkStack*>(gobj()));
}

auto Stack::get_pages() const -> Glib::RefPtr<const SelectionModel>
{
  return const_cast<Stack*>(this)->get_pages();
}


auto Stack::property_hhomogeneous() -> Glib::PropertyProxy< bool >
{
  return {this, "hhomogeneous"};
}

auto Stack::property_hhomogeneous() const -> Glib::PropertyProxy_ReadOnly< bool >
{
  return {this, "hhomogeneous"};
}

auto Stack::property_transition_duration() -> Glib::PropertyProxy< unsigned int >
{
  return {this, "transition-duration"};
}

auto Stack::property_transition_duration() const -> Glib::PropertyProxy_ReadOnly< unsigned int >
{
  return {this, "transition-duration"};
}

auto Stack::property_transition_running() const -> Glib::PropertyProxy_ReadOnly< bool >
{
  return {this, "transition-running"};
}

static_assert(Glib::Traits::ValueCompatibleWithWrapProperty<StackTransitionType>::value,
  "Type StackTransitionType cannot be used in _WRAP_PROPERTY. "
  "There is no suitable template specialization of Glib::Value<>.");

auto Stack::property_transition_type() -> Glib::PropertyProxy< StackTransitionType >
{
  return {this, "transition-type"};
}

auto Stack::property_transition_type() const -> Glib::PropertyProxy_ReadOnly< StackTransitionType >
{
  return {this, "transition-type"};
}

auto Stack::property_vhomogeneous() -> Glib::PropertyProxy< bool >
{
  return {this, "vhomogeneous"};
}

auto Stack::property_vhomogeneous() const -> Glib::PropertyProxy_ReadOnly< bool >
{
  return {this, "vhomogeneous"};
}

auto Stack::property_visible_child() -> Glib::PropertyProxy< Widget* >
{
  return {this, "visible-child"};
}

auto Stack::property_visible_child() const -> Glib::PropertyProxy_ReadOnly< Widget* >
{
  return {this, "visible-child"};
}

auto Stack::property_visible_child_name() -> Glib::PropertyProxy< Glib::ustring >
{
  return {this, "visible-child-name"};
}

auto Stack::property_visible_child_name() const -> Glib::PropertyProxy_ReadOnly< Glib::ustring >
{
  return {this, "visible-child-name"};
}

auto Stack::property_interpolate_size() -> Glib::PropertyProxy< bool >
{
  return {this, "interpolate-size"};
}

auto Stack::property_interpolate_size() const -> Glib::PropertyProxy_ReadOnly< bool >
{
  return {this, "interpolate-size"};
}

static_assert(Glib::Traits::ValueCompatibleWithWrapProperty<Glib::RefPtr<SelectionModel>>::value,
  "Type Glib::RefPtr<SelectionModel> cannot be used in _WRAP_PROPERTY. "
  "There is no suitable template specialization of Glib::Value<>.");

auto Stack::property_pages() const -> Glib::PropertyProxy_ReadOnly< Glib::RefPtr<SelectionModel> >
{
  return {this, "pages"};
}


} // namespace Gtk

