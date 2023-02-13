


#include <libmm-glib/mm-glib.hxx>

#include <libmm-gtk/styleprovider.hxx>
#include <libmm-gtk/styleprovider_p.hxx>


/* Copyright (C) 2010 The gtkmm Development Team
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

auto wrap(GtkStyleProvider* object, const bool take_copy) -> RefPtr<Gtk::StyleProvider>
{
  return Glib::make_refptr_for_instance<Gtk::StyleProvider>( Glib::wrap_auto_interface<Gtk::StyleProvider> ((GObject*)object, take_copy) );
  //We use dynamic_cast<> in case of multiple inheritance.
}

} // namespace Glib


namespace Gtk
{


/* The *_Class implementation: */

auto StyleProvider_Class::init() -> const Interface_Class&
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Interface_Class has to know the interface init function
    // in order to add interfaces to implementing types.
    class_init_func_ = &StyleProvider_Class::iface_init_function;

    // We can not derive from another interface, and it is not necessary anyway.
    gtype_ = gtk_style_provider_get_type();
  }

  return *this;
}

auto StyleProvider_Class::iface_init_function (void *g_iface, void *) -> void
{
  const auto klass = static_cast<BaseClassType*>(g_iface);

  //This is just to avoid an "unused variable" warning when there are no vfuncs or signal handlers to connect.
  //This is a temporary fix until I find out why I can not seem to derive a GtkFileChooser interface. murrayc
  g_assert(klass != nullptr);


}


auto StyleProvider_Class::wrap_new(GObject* object) -> Glib::ObjectBase*
{
  return new StyleProvider((GtkStyleProvider*)object);
}


/* The implementation: */

StyleProvider::StyleProvider()
: Interface(styleprovider_class_.init())
{}

StyleProvider::StyleProvider(GtkStyleProvider* castitem)
: Interface((GObject*)castitem)
{}

StyleProvider::StyleProvider(const Glib::Interface_Class& interface_class)
: Interface(interface_class)
{
}

StyleProvider::StyleProvider(StyleProvider&& src) noexcept
: Interface(std::move(src))
{}

auto StyleProvider::operator=(StyleProvider&& src) noexcept -> StyleProvider&
{
  Interface::operator=(std::move(src));
  return *this;
}

StyleProvider::~StyleProvider() noexcept = default;

// static
auto StyleProvider::add_interface (
  const GType gtype_implementer) -> void
{
  styleprovider_class_.init().add_interface(gtype_implementer);
}

StyleProvider::CppClassType StyleProvider::styleprovider_class_; // initialize static member

auto StyleProvider::get_type() -> GType
{
  return styleprovider_class_.init().get_type();
}


auto StyleProvider::get_base_type() -> GType
{
  return gtk_style_provider_get_type();
}


} // namespace Gtk

