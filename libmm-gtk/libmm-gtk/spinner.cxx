


#include <libmm-glib/mm-glib.hxx>

#include <libmm-gtk/spinner.hxx>
#include <libmm-gtk/spinner_p.hxx>

#include <gtk/gtk.h>

/*
 * Copyright 2009 The gtkmm Development Team
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

namespace
{
} // anonymous namespace


namespace Glib
{

auto wrap(GtkSpinner* object, const bool take_copy) -> Gtk::Spinner*
{
  return dynamic_cast<Gtk::Spinner *> (wrap_auto((GObject*)object, take_copy));
}

} /* namespace Glib */

namespace Gtk
{


/* The *_Class implementation: */

auto Spinner_Class::init() -> const Class&
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Class has to know the class init function to clone custom types.
    class_init_func_ = &Spinner_Class::class_init_function;

    // This is actually just optimized away, apparently with no harm.
    // Make sure that the parent type has been created.
    //CppClassParent::CppObjectType::get_type();

    // Create the wrapper type, with the same class/instance size as the base type.
    register_derived_type(gtk_spinner_get_type());

    // Add derived versions of interfaces, if the C type implements any interfaces:

  }

  return *this;
}


auto Spinner_Class::class_init_function (void *g_class, void *class_data) -> void
{
  const auto klass = static_cast<BaseClassType*>(g_class);
  CppClassParent::class_init_function(klass, class_data);


}


auto Spinner_Class::wrap_new(GObject* o) -> Glib::ObjectBase*
{
  return manage(new Spinner((GtkSpinner*)o));

}


/* The implementation: */

Spinner::Spinner(const Glib::ConstructParams& construct_params)
: Widget(construct_params)
{
  }

Spinner::Spinner(GtkSpinner* castitem)
: Widget((GtkWidget*)castitem)
{
  }


Spinner::Spinner(Spinner&& src) noexcept
: Widget(std::move(src))
{}

auto Spinner::operator=(Spinner&& src) noexcept -> Spinner&
{
  Widget::operator=(std::move(src));
  return *this;
}

Spinner::~Spinner() noexcept
{
  destroy_();
}

Spinner::CppClassType Spinner::spinner_class_; // initialize static member

auto Spinner::get_type() -> GType
{
  return spinner_class_.init().get_type();
}


auto Spinner::get_base_type() -> GType
{
  return gtk_spinner_get_type();
}


Spinner::Spinner()
:
  // Mark this class as non-derived to allow C++ vfuncs to be skipped.
ObjectBase(nullptr),
Widget(Glib::ConstructParams(spinner_class_.init()))
{


}

auto Spinner::start () -> void
{
  gtk_spinner_start(gobj());
}

auto Spinner::stop () -> void
{
  gtk_spinner_stop(gobj());
}

auto Spinner::set_spinning (
  const bool spinning) -> void
{
  gtk_spinner_set_spinning(gobj(), spinning);
}

auto Spinner::get_spinning() const -> bool
{
  return gtk_spinner_get_spinning(const_cast<GtkSpinner*>(gobj()));
}


auto Spinner::property_spinning() -> Glib::PropertyProxy< bool >
{
  return {this, "spinning"};
}

auto Spinner::property_spinning() const -> Glib::PropertyProxy_ReadOnly< bool >
{
  return {this, "spinning"};
}


} // namespace Gtk

