


#include <libmm-glib/mm-glib.hpp>

#include <libmm-gtk/stacksidebar.hpp>
#include <libmm-gtk/stacksidebar_p.hpp>


/* Copyright (C) 2015 The gtkmm Development Team
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

auto StackSidebar::unset_stack () -> void
{
  gtk_stack_sidebar_set_stack(gobj(), nullptr);
}

} //namespace Gtk

namespace
{
} // anonymous namespace


namespace Glib
{

auto wrap(GtkStackSidebar* object, const bool take_copy) -> Gtk::StackSidebar*
{
  return dynamic_cast<Gtk::StackSidebar *> (wrap_auto((GObject*)object, take_copy));
}

} /* namespace Glib */

namespace Gtk
{


/* The *_Class implementation: */

auto StackSidebar_Class::init() -> const Class&
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Class has to know the class init function to clone custom types.
    class_init_func_ = &StackSidebar_Class::class_init_function;

    // This is actually just optimized away, apparently with no harm.
    // Make sure that the parent type has been created.
    //CppClassParent::CppObjectType::get_type();

    // Create the wrapper type, with the same class/instance size as the base type.
    register_derived_type(gtk_stack_sidebar_get_type());

    // Add derived versions of interfaces, if the C type implements any interfaces:

  }

  return *this;
}


auto StackSidebar_Class::class_init_function (void *g_class, void *class_data) -> void
{
  const auto klass = static_cast<BaseClassType*>(g_class);
  CppClassParent::class_init_function(klass, class_data);


}


auto StackSidebar_Class::wrap_new(GObject* o) -> Glib::ObjectBase*
{
  return manage(new StackSidebar((GtkStackSidebar*)o));

}


/* The implementation: */

StackSidebar::StackSidebar(const Glib::ConstructParams& construct_params)
: Widget(construct_params)
{
  }

StackSidebar::StackSidebar(GtkStackSidebar* castitem)
: Widget((GtkWidget*)castitem)
{
  }


StackSidebar::StackSidebar(StackSidebar&& src) noexcept
: Widget(std::move(src))
{}

auto StackSidebar::operator=(StackSidebar&& src) noexcept -> StackSidebar&
{
  Widget::operator=(std::move(src));
  return *this;
}

StackSidebar::~StackSidebar() noexcept
{
  destroy_();
}

StackSidebar::CppClassType StackSidebar::stacksidebar_class_; // initialize static member

auto StackSidebar::get_type() -> GType
{
  return stacksidebar_class_.init().get_type();
}


auto StackSidebar::get_base_type() -> GType
{
  return gtk_stack_sidebar_get_type();
}


StackSidebar::StackSidebar()
:
  // Mark this class as non-derived to allow C++ vfuncs to be skipped.
ObjectBase(nullptr),
Widget(Glib::ConstructParams(stacksidebar_class_.init()))
{


}

auto StackSidebar::set_stack (Stack &stack) -> void
{
  gtk_stack_sidebar_set_stack(gobj(), stack.gobj());
}

auto StackSidebar::get_stack() -> Stack*
{
  return Glib::wrap(gtk_stack_sidebar_get_stack(gobj()));
}

auto StackSidebar::get_stack() const -> const Stack*
{
  return const_cast<StackSidebar*>(this)->get_stack();
}


static_assert(Glib::Traits::ValueCompatibleWithWrapProperty<Stack*>::value,
  "Type Stack* cannot be used in _WRAP_PROPERTY. "
  "There is no suitable template specialization of Glib::Value<>.");

auto StackSidebar::property_stack() -> Glib::PropertyProxy< Stack* >
{
  return {this, "stack"};
}

auto StackSidebar::property_stack() const -> Glib::PropertyProxy_ReadOnly< Stack* >
{
  return {this, "stack"};
}


} // namespace Gtk


