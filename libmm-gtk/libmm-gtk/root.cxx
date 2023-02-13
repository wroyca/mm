


#include <libmm-glib/mm-glib.hxx>

#include <libmm-gtk/root.hxx>
#include <libmm-gtk/root_p.hxx>


/* Copyright (C) 2019 The gtkmm Development Team
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
#include <libmm-gdk/display.hxx>
#include <libmm-gdk/surface.hxx>
#include <libmm-gtk/widget.hxx>

namespace Gtk
{
auto Root::unset_focus () -> void
{
  gtk_root_set_focus(gobj(), nullptr);
}

} // namespace Gtk

namespace
{
} // anonymous namespace


namespace Glib
{

auto wrap(GtkRoot* object, const bool take_copy) -> RefPtr<Gtk::Root>
{
  return Glib::make_refptr_for_instance<Gtk::Root>( Glib::wrap_auto_interface<Gtk::Root> ((GObject*)object, take_copy) );
  //We use dynamic_cast<> in case of multiple inheritance.
}

} // namespace Glib


namespace Gtk
{


/* The *_Class implementation: */

auto Root_Class::init() -> const Interface_Class&
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Interface_Class has to know the interface init function
    // in order to add interfaces to implementing types.
    class_init_func_ = &Root_Class::iface_init_function;

    // We can not derive from another interface, and it is not necessary anyway.
    gtype_ = gtk_root_get_type();
  }

  return *this;
}

auto Root_Class::iface_init_function (void *g_iface, void *) -> void
{
  const auto klass = static_cast<BaseClassType*>(g_iface);

  //This is just to avoid an "unused variable" warning when there are no vfuncs or signal handlers to connect.
  //This is a temporary fix until I find out why I can not seem to derive a GtkFileChooser interface. murrayc
  g_assert(klass != nullptr);


}


auto Root_Class::wrap_new(GObject* object) -> Glib::ObjectBase*
{
  return new Root((GtkRoot*)object);
}


/* The implementation: */

Root::Root()
: Interface(root_class_.init())
{}

Root::Root(GtkRoot* castitem)
: Interface((GObject*)castitem)
{}

Root::Root(const Glib::Interface_Class& interface_class)
: Interface(interface_class)
{
}

Root::Root(Root&& src) noexcept
: Interface(std::move(src))
{}

auto Root::operator=(Root&& src) noexcept -> Root&
{
  Interface::operator=(std::move(src));
  return *this;
}

Root::~Root() noexcept = default;

// static
auto Root::add_interface (
  const GType gtype_implementer) -> void
{
  root_class_.init().add_interface(gtype_implementer);
}

Root::CppClassType Root::root_class_; // initialize static member

auto Root::get_type() -> GType
{
  return root_class_.init().get_type();
}


auto Root::get_base_type() -> GType
{
  return gtk_root_get_type();
}


auto Root::get_display() -> Glib::RefPtr<Gdk::Display>
{
  auto retvalue = Glib::wrap(gtk_root_get_display(gobj()));
  if(retvalue)
    retvalue->reference(); //The function does not do a ref for us.
  return retvalue;
}

auto Root::get_display() const -> Glib::RefPtr<const Gdk::Display>
{
  return const_cast<Root*>(this)->get_display();
}

auto Root::set_focus (Widget &focus) -> void
{
  gtk_root_set_focus(gobj(), focus.gobj());
}

auto Root::get_focus() -> Widget*
{
  return Glib::wrap(gtk_root_get_focus(gobj()));
}

auto Root::get_focus() const -> const Widget*
{
  return const_cast<Root*>(this)->get_focus();
}


} // namespace Gtk

