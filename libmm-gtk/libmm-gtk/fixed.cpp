


#include <mm/glib/mm-glib.hpp>

#include <mm/gtk/fixed.hpp>
#include <mm/gtk/private/fixed_p.hpp>


/*
 * Copyright 1998-2002 The gtkmm Development Team
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
}


namespace
{
} // anonymous namespace


namespace Glib
{

auto wrap(GtkFixed* object, const bool take_copy) -> Gtk::Fixed*
{
  return dynamic_cast<Gtk::Fixed *> (wrap_auto((GObject*)object, take_copy));
}

} /* namespace Glib */

namespace Gtk
{


/* The *_Class implementation: */

auto Fixed_Class::init() -> const Class&
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Class has to know the class init function to clone custom types.
    class_init_func_ = &Fixed_Class::class_init_function;

    // This is actually just optimized away, apparently with no harm.
    // Make sure that the parent type has been created.
    //CppClassParent::CppObjectType::get_type();

    // Create the wrapper type, with the same class/instance size as the base type.
    register_derived_type(gtk_fixed_get_type());

    // Add derived versions of interfaces, if the C type implements any interfaces:

  }

  return *this;
}


auto Fixed_Class::class_init_function (void *g_class, void *class_data) -> void
{
  const auto klass = static_cast<BaseClassType*>(g_class);
  CppClassParent::class_init_function(klass, class_data);


}


auto Fixed_Class::wrap_new(GObject* o) -> Glib::ObjectBase*
{
  return manage(new Fixed((GtkFixed*)o));

}


/* The implementation: */

Fixed::Fixed(const Glib::ConstructParams& construct_params)
: Widget(construct_params)
{
  }

Fixed::Fixed(GtkFixed* castitem)
: Widget((GtkWidget*)castitem)
{
  }


Fixed::Fixed(Fixed&& src) noexcept
: Widget(std::move(src))
{}

auto Fixed::operator=(Fixed&& src) noexcept -> Fixed&
{
  Widget::operator=(std::move(src));
  return *this;
}

Fixed::~Fixed() noexcept
{
  destroy_();
}

Fixed::CppClassType Fixed::fixed_class_; // initialize static member

auto Fixed::get_type() -> GType
{
  return fixed_class_.init().get_type();
}


auto Fixed::get_base_type() -> GType
{
  return gtk_fixed_get_type();
}


Fixed::Fixed()
:
  // Mark this class as non-derived to allow C++ vfuncs to be skipped.
ObjectBase(nullptr),
Widget(Glib::ConstructParams(fixed_class_.init()))
{


}

auto Fixed::put (Widget &widget, const double x, const double y) -> void
{
  gtk_fixed_put(gobj(), widget.gobj(), x, y);
}

auto Fixed::remove (Widget &widget) -> void
{
  gtk_fixed_remove(gobj(), widget.gobj());
}

auto Fixed::move (Widget &widget, const double x, const double y) -> void
{
  gtk_fixed_move(gobj(), widget.gobj(), x, y);
}

auto Fixed::get_child_position (Widget &widget, double &x, double &y) const -> void
{
  gtk_fixed_get_child_position(const_cast<GtkFixed*>(gobj()), widget.gobj(), &x, &y);
}


} // namespace Gtk


