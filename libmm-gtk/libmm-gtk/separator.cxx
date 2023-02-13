


#include <libmm-glib/mm-glib.hxx>

#include <libmm-gtk/separator.hxx>
#include <libmm-gtk/separator_p.hxx>


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

namespace
{
} // anonymous namespace


namespace Glib
{

auto wrap(GtkSeparator* object, const bool take_copy) -> Gtk::Separator*
{
  return dynamic_cast<Gtk::Separator *> (wrap_auto((GObject*)object, take_copy));
}

} /* namespace Glib */

namespace Gtk
{


/* The *_Class implementation: */

auto Separator_Class::init() -> const Class&
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Class has to know the class init function to clone custom types.
    class_init_func_ = &Separator_Class::class_init_function;

    // This is actually just optimized away, apparently with no harm.
    // Make sure that the parent type has been created.
    //CppClassParent::CppObjectType::get_type();

    // Create the wrapper type, with the same class/instance size as the base type.
    register_derived_type(gtk_separator_get_type());

    // Add derived versions of interfaces, if the C type implements any interfaces:
  Orientable::add_interface(get_type());

  }

  return *this;
}


auto Separator_Class::class_init_function (void *g_class, void *class_data) -> void
{
  const auto klass = static_cast<BaseClassType*>(g_class);
  CppClassParent::class_init_function(klass, class_data);


}


auto Separator_Class::wrap_new(GObject* o) -> Glib::ObjectBase*
{
  return manage(new Separator((GtkSeparator*)o));

}


/* The implementation: */

Separator::Separator(const Glib::ConstructParams& construct_params)
: Widget(construct_params)
{
  }

Separator::Separator(GtkSeparator* castitem)
: Widget((GtkWidget*)castitem)
{
  }


Separator::Separator(Separator&& src) noexcept
: Widget(std::move(src))
  , Orientable(std::move(src))
{}

auto Separator::operator=(Separator&& src) noexcept -> Separator&
{
  Widget::operator=(std::move(src));
  Orientable::operator=(std::move(src));
  return *this;
}

Separator::~Separator() noexcept
{
  destroy_();
}

Separator::CppClassType Separator::separator_class_; // initialize static member

auto Separator::get_type() -> GType
{
  return separator_class_.init().get_type();
}


auto Separator::get_base_type() -> GType
{
  return gtk_separator_get_type();
}


Separator::Separator(const Orientation orientation)
:
  // Mark this class as non-derived to allow C++ vfuncs to be skipped.
ObjectBase(nullptr),
Widget(Glib::ConstructParams(separator_class_.init(), "orientation", orientation, nullptr))
{


}


} // namespace Gtk


