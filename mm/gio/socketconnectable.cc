// Generated by gmmproc 2.74.0 -- DO NOT MODIFY!


#include <mm/glib/mm-glib.h>

#include <mm/gio/socketconnectable.h>
#include <mm/gio/private/socketconnectable_p.h>


/* Copyright (C) 2009 The giomm Development Team
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
 * License along with this library.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <gio/gio.h>

namespace Gio
{
} // namespace Gio

namespace
{
} // anonymous namespace


namespace Glib
{

auto wrap(GSocketConnectable* object, bool take_copy) -> Glib::RefPtr<Gio::SocketConnectable>
{
  return Glib::make_refptr_for_instance<Gio::SocketConnectable>( dynamic_cast<Gio::SocketConnectable*> (Glib::wrap_auto_interface<Gio::SocketConnectable> ((GObject*)(object), take_copy)) );
  //We use dynamic_cast<> in case of multiple inheritance.
}

} // namespace Glib


namespace Gio
{


/* The *_Class implementation: */

auto SocketConnectable_Class::init() -> const Glib::Interface_Class&
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Interface_Class has to know the interface init function
    // in order to add interfaces to implementing types.
    class_init_func_ = &SocketConnectable_Class::iface_init_function;

    // We can not derive from another interface, and it is not necessary anyway.
    gtype_ = g_socket_connectable_get_type();
  }

  return *this;
}

void SocketConnectable_Class::iface_init_function(void* g_iface, void*)
{
  const auto klass = static_cast<BaseClassType*>(g_iface);

  //This is just to avoid an "unused variable" warning when there are no vfuncs or signal handlers to connect.
  //This is a temporary fix until I find out why I can not seem to derive a GtkFileChooser interface. murrayc
  g_assert(klass != nullptr);


}


auto SocketConnectable_Class::wrap_new(GObject* object) -> Glib::ObjectBase*
{
  return new SocketConnectable((GSocketConnectable*)(object));
}


/* The implementation: */

SocketConnectable::SocketConnectable()
:
  Glib::Interface(socketconnectable_class_.init())
{}

SocketConnectable::SocketConnectable(GSocketConnectable* castitem)
:
  Glib::Interface((GObject*)(castitem))
{}

SocketConnectable::SocketConnectable(const Glib::Interface_Class& interface_class)
: Glib::Interface(interface_class)
{
}

SocketConnectable::SocketConnectable(SocketConnectable&& src) noexcept
: Glib::Interface(std::move(src))
{}

auto SocketConnectable::operator=(SocketConnectable&& src) noexcept -> SocketConnectable&
{
  Glib::Interface::operator=(std::move(src));
  return *this;
}

SocketConnectable::~SocketConnectable() noexcept
{}

// static
void SocketConnectable::add_interface(GType gtype_implementer)
{
  socketconnectable_class_.init().add_interface(gtype_implementer);
}

SocketConnectable::CppClassType SocketConnectable::socketconnectable_class_; // initialize static member

auto SocketConnectable::get_type() -> GType
{
  return socketconnectable_class_.init().get_type();
}


auto SocketConnectable::get_base_type() -> GType
{
  return g_socket_connectable_get_type();
}


auto SocketConnectable::enumerate() -> Glib::RefPtr<SocketAddressEnumerator>
{
  return Glib::wrap(g_socket_connectable_enumerate(gobj()));
}

auto SocketConnectable::enumerate() const -> Glib::RefPtr<const SocketAddressEnumerator>
{
  return const_cast<SocketConnectable*>(this)->enumerate();
}

auto SocketConnectable::proxy_enumerate() -> Glib::RefPtr<SocketAddressEnumerator>
{
  return Glib::wrap(g_socket_connectable_proxy_enumerate(gobj()));
}

auto SocketConnectable::proxy_enumerate() const -> Glib::RefPtr<const SocketAddressEnumerator>
{
  return const_cast<SocketConnectable*>(this)->proxy_enumerate();
}

auto SocketConnectable::to_string() const -> Glib::ustring
{
  return Glib::convert_return_gchar_ptr_to_ustring(g_socket_connectable_to_string(const_cast<GSocketConnectable*>(gobj())));
}


} // namespace Gio

