


#include <libmm-glib/mm-glib.hpp>

#include <libmm-gtk/stackswitcher.hpp>
#include <libmm-gtk/stackswitcher_p.hpp>


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

#include <gtk/gtk.h>

namespace Gtk
{

auto StackSwitcher::unset_stack () -> void
{
  gtk_stack_switcher_set_stack(gobj(), nullptr);
}

} //namespace Gtk

namespace
{
} // anonymous namespace


namespace Glib
{

auto wrap(GtkStackSwitcher* object, const bool take_copy) -> Gtk::StackSwitcher*
{
  return dynamic_cast<Gtk::StackSwitcher *> (wrap_auto((GObject*)object, take_copy));
}

} /* namespace Glib */

namespace Gtk
{


/* The *_Class implementation: */

auto StackSwitcher_Class::init() -> const Class&
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Class has to know the class init function to clone custom types.
    class_init_func_ = &StackSwitcher_Class::class_init_function;

    // This is actually just optimized away, apparently with no harm.
    // Make sure that the parent type has been created.
    //CppClassParent::CppObjectType::get_type();

    // Create the wrapper type, with the same class/instance size as the base type.
    register_derived_type(gtk_stack_switcher_get_type());

    // Add derived versions of interfaces, if the C type implements any interfaces:

  }

  return *this;
}


auto StackSwitcher_Class::class_init_function (void *g_class, void *class_data) -> void
{
  const auto klass = static_cast<BaseClassType*>(g_class);
  CppClassParent::class_init_function(klass, class_data);


}


auto StackSwitcher_Class::wrap_new(GObject* o) -> Glib::ObjectBase*
{
  return manage(new StackSwitcher((GtkStackSwitcher*)o));

}


/* The implementation: */

StackSwitcher::StackSwitcher(const Glib::ConstructParams& construct_params)
: Widget(construct_params)
{
  }

StackSwitcher::StackSwitcher(GtkStackSwitcher* castitem)
: Widget((GtkWidget*)castitem)
{
  }


StackSwitcher::StackSwitcher(StackSwitcher&& src) noexcept
: Widget(std::move(src))
{}

auto StackSwitcher::operator=(StackSwitcher&& src) noexcept -> StackSwitcher&
{
  Widget::operator=(std::move(src));
  return *this;
}

StackSwitcher::~StackSwitcher() noexcept
{
  destroy_();
}

StackSwitcher::CppClassType StackSwitcher::stackswitcher_class_; // initialize static member

auto StackSwitcher::get_type() -> GType
{
  return stackswitcher_class_.init().get_type();
}


auto StackSwitcher::get_base_type() -> GType
{
  return gtk_stack_switcher_get_type();
}


StackSwitcher::StackSwitcher()
:
  // Mark this class as non-derived to allow C++ vfuncs to be skipped.
ObjectBase(nullptr),
Widget(Glib::ConstructParams(stackswitcher_class_.init()))
{


}

auto StackSwitcher::set_stack (Stack &stack) -> void
{
  gtk_stack_switcher_set_stack(gobj(), stack.gobj());
}

auto StackSwitcher::get_stack() -> Stack*
{
  return Glib::wrap(gtk_stack_switcher_get_stack(gobj()));
}

auto StackSwitcher::get_stack() const -> const Stack*
{
  return const_cast<StackSwitcher*>(this)->get_stack();
}


static_assert(Glib::Traits::ValueCompatibleWithWrapProperty<Stack*>::value,
  "Type Stack* cannot be used in _WRAP_PROPERTY. "
  "There is no suitable template specialization of Glib::Value<>.");

auto StackSwitcher::property_stack() -> Glib::PropertyProxy< Stack* >
{
  return {this, "stack"};
}

auto StackSwitcher::property_stack() const -> Glib::PropertyProxy_ReadOnly< Stack* >
{
  return {this, "stack"};
}


} // namespace Gtk


