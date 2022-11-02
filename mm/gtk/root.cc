// Generated by gmmproc 2.74.0 -- DO NOT MODIFY!


#include <mm/glib/mm-glib.h>

#include <mm/gtk/root.h>
#include <mm/gtk/private/root_p.h>


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
#include <mm/gdk/display.h>
#include <mm/gdk/surface.h>
#include <mm/gtk/widget.h>

namespace Gtk
{
void Root::unset_focus()
{
  gtk_root_set_focus(gobj(), nullptr);
}

} // namespace Gtk

namespace
{
} // anonymous namespace


namespace Glib
{

auto wrap(GtkRoot* object, bool take_copy) -> Glib::RefPtr<Gtk::Root>
{
  return Glib::make_refptr_for_instance<Gtk::Root>( dynamic_cast<Gtk::Root*> (Glib::wrap_auto_interface<Gtk::Root> ((GObject*)(object), take_copy)) );
  //We use dynamic_cast<> in case of multiple inheritance.
}

} // namespace Glib


namespace Gtk
{


/* The *_Class implementation: */

auto Root_Class::init() -> const Glib::Interface_Class&
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

void Root_Class::iface_init_function(void* g_iface, void*)
{
  const auto klass = static_cast<BaseClassType*>(g_iface);

  //This is just to avoid an "unused variable" warning when there are no vfuncs or signal handlers to connect.
  //This is a temporary fix until I find out why I can not seem to derive a GtkFileChooser interface. murrayc
  g_assert(klass != nullptr);


}


auto Root_Class::wrap_new(GObject* object) -> Glib::ObjectBase*
{
  return new Root((GtkRoot*)(object));
}


/* The implementation: */

Root::Root()
:
  Glib::Interface(root_class_.init())
{}

Root::Root(GtkRoot* castitem)
:
  Glib::Interface((GObject*)(castitem))
{}

Root::Root(const Glib::Interface_Class& interface_class)
: Glib::Interface(interface_class)
{
}

Root::Root(Root&& src) noexcept
: Glib::Interface(std::move(src))
{}

auto Root::operator=(Root&& src) noexcept -> Root&
{
  Glib::Interface::operator=(std::move(src));
  return *this;
}

Root::~Root() noexcept
{}

// static
void Root::add_interface(GType gtype_implementer)
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

void Root::set_focus(Widget& focus)
{
  gtk_root_set_focus(gobj(), (focus).gobj());
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

