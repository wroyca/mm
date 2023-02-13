


#include <libmm-glib/mm-glib.hpp>

#include <libmm-gtk/appchooser.hpp>
#include <libmm-gtk/appchooser_p.hpp>


/* Copyright 2011 The gtkmm Development Team
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

auto wrap(GtkAppChooser* object, const bool take_copy) -> RefPtr<Gtk::AppChooser>
{
  return Glib::make_refptr_for_instance<Gtk::AppChooser>( Glib::wrap_auto_interface<Gtk::AppChooser> ((GObject*)object, take_copy) );
  //We use dynamic_cast<> in case of multiple inheritance.
}

} // namespace Glib


namespace Gtk
{


/* The *_Class implementation: */

auto AppChooser_Class::init() -> const Interface_Class&
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Interface_Class has to know the interface init function
    // in order to add interfaces to implementing types.
    class_init_func_ = &AppChooser_Class::iface_init_function;

    // We can not derive from another interface, and it is not necessary anyway.
    gtype_ = gtk_app_chooser_get_type();
  }

  return *this;
}

auto AppChooser_Class::iface_init_function (void *g_iface, void *) -> void
{
  const auto klass = static_cast<BaseClassType*>(g_iface);

  //This is just to avoid an "unused variable" warning when there are no vfuncs or signal handlers to connect.
  //This is a temporary fix until I find out why I can not seem to derive a GtkFileChooser interface. murrayc
  g_assert(klass != nullptr);


}


auto AppChooser_Class::wrap_new(GObject* object) -> Glib::ObjectBase*
{
  return new AppChooser((GtkAppChooser*)object);
}


/* The implementation: */

AppChooser::AppChooser()
: Interface(appchooser_class_.init())
{}

AppChooser::AppChooser(GtkAppChooser* castitem)
: Interface((GObject*)castitem)
{}

AppChooser::AppChooser(const Glib::Interface_Class& interface_class)
: Interface(interface_class)
{
}

AppChooser::AppChooser(AppChooser&& src) noexcept
: Interface(std::move(src))
{}

auto AppChooser::operator=(AppChooser&& src) noexcept -> AppChooser&
{
  Interface::operator=(std::move(src));
  return *this;
}

AppChooser::~AppChooser() noexcept = default;

// static
auto AppChooser::add_interface (
  const GType gtype_implementer) -> void
{
  appchooser_class_.init().add_interface(gtype_implementer);
}

AppChooser::CppClassType AppChooser::appchooser_class_; // initialize static member

auto AppChooser::get_type() -> GType
{
  return appchooser_class_.init().get_type();
}


auto AppChooser::get_base_type() -> GType
{
  return gtk_app_chooser_get_type();
}


auto AppChooser::get_app_info() -> Glib::RefPtr<Gio::AppInfo>
{
  auto retvalue = Glib::wrap(gtk_app_chooser_get_app_info(gobj()));
  if(retvalue)
    retvalue->reference(); //The function does not do a ref for us.
  return retvalue;
}

auto AppChooser::get_app_info() const -> Glib::RefPtr<const Gio::AppInfo>
{
  return const_cast<AppChooser*>(this)->get_app_info();
}

auto AppChooser::get_content_type() const -> Glib::ustring
{
  return Glib::convert_return_gchar_ptr_to_ustring(gtk_app_chooser_get_content_type(const_cast<GtkAppChooser*>(gobj())));
}

auto AppChooser::refresh () -> void
{
  gtk_app_chooser_refresh(gobj());
}


auto AppChooser::property_content_type() const -> Glib::PropertyProxy_ReadOnly< Glib::ustring >
{
  return {this, "content-type"};
}


} // namespace Gtk


