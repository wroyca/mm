/* Copyright (C) 2007 The gtkmm Development Team
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

#ifndef _WIN32

#include <mm/glib/mm-glib.h>

#include <mm/gio/unixoutputstream.h>
#include <mm/gio/private/unixoutputstream_p.h>

#include <gio/gio.h>
#include <gio/gunixoutputstream.h>

namespace
{
} // anonymous namespace


namespace Glib
{

auto wrap(GUnixOutputStream* object, bool take_copy) -> Glib::RefPtr<Gio::UnixOutputStream>
{
  return Glib::make_refptr_for_instance<Gio::UnixOutputStream>( dynamic_cast<Gio::UnixOutputStream*> (Glib::wrap_auto ((GObject*)(object), take_copy)) );
  //We use dynamic_cast<> in case of multiple inheritance.
}

} /* namespace Glib */


namespace Gio
{


/* The *_Class implementation: */

auto UnixOutputStream_Class::init() -> const Glib::Class&
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Class has to know the class init function to clone custom types.
    class_init_func_ = &UnixOutputStream_Class::class_init_function;

    // This is actually just optimized away, apparently with no harm.
    // Make sure that the parent type has been created.
    //CppClassParent::CppObjectType::get_type();

    // Create the wrapper type, with the same class/instance size as the base type.
    register_derived_type(g_unix_output_stream_get_type());

    // Add derived versions of interfaces, if the C type implements any interfaces:
  PollableOutputStream::add_interface(get_type());
  FileDescriptorBased::add_interface(get_type());

  }

  return *this;
}


void UnixOutputStream_Class::class_init_function(void* g_class, void* class_data)
{
  const auto klass = static_cast<BaseClassType*>(g_class);
  CppClassParent::class_init_function(klass, class_data);


}


auto UnixOutputStream_Class::wrap_new(GObject* object) -> Glib::ObjectBase*
{
  return new UnixOutputStream((GUnixOutputStream*)object);
}


/* The implementation: */

auto UnixOutputStream::gobj_copy() -> GUnixOutputStream*
{
  reference();
  return gobj();
}

UnixOutputStream::UnixOutputStream(const Glib::ConstructParams& construct_params)
:
  Gio::OutputStream(construct_params)
{

}

UnixOutputStream::UnixOutputStream(GUnixOutputStream* castitem)
:
  Gio::OutputStream((GOutputStream*)(castitem))
{}


UnixOutputStream::UnixOutputStream(UnixOutputStream&& src) noexcept
: Gio::OutputStream(std::move(src))
  , PollableOutputStream(std::move(src))
  , FileDescriptorBased(std::move(src))
{}

auto UnixOutputStream::operator=(UnixOutputStream&& src) noexcept -> UnixOutputStream&
{
  Gio::OutputStream::operator=(std::move(src));
  PollableOutputStream::operator=(std::move(src));
  FileDescriptorBased::operator=(std::move(src));
  return *this;
}


UnixOutputStream::~UnixOutputStream() noexcept
{}


UnixOutputStream::CppClassType UnixOutputStream::unixoutputstream_class_; // initialize static member

auto UnixOutputStream::get_type() -> GType
{
  return unixoutputstream_class_.init().get_type();
}


auto UnixOutputStream::get_base_type() -> GType
{
  return g_unix_output_stream_get_type();
}


UnixOutputStream::UnixOutputStream(int fd, bool close_fd)
:
  // Mark this class as non-derived to allow C++ vfuncs to be skipped.
  Glib::ObjectBase(nullptr),
  Gio::OutputStream(Glib::ConstructParams(unixoutputstream_class_.init(), "fd", fd, "close_fd", static_cast<int>(close_fd), nullptr))
{


}

auto UnixOutputStream::create(int fd, bool close_fd) -> Glib::RefPtr<UnixOutputStream>
{
  return Glib::make_refptr_for_instance<UnixOutputStream>( new UnixOutputStream(fd, close_fd) );
}

void UnixOutputStream::set_close_fd(bool close_fd)
{
  g_unix_output_stream_set_close_fd(gobj(), static_cast<int>(close_fd));
}

auto UnixOutputStream::get_close_fd() const -> bool
{
  return g_unix_output_stream_get_close_fd(const_cast<GUnixOutputStream*>(gobj()));
}

auto UnixOutputStream::get_fd() const -> int
{
  return g_unix_output_stream_get_fd(const_cast<GUnixOutputStream*>(gobj()));
}


auto UnixOutputStream::property_fd() const -> Glib::PropertyProxy_ReadOnly< int >
{
  return Glib::PropertyProxy_ReadOnly< int >(this, "fd");
}

auto UnixOutputStream::property_close_fd() -> Glib::PropertyProxy< bool >
{
  return Glib::PropertyProxy< bool >(this, "close-fd");
}

auto UnixOutputStream::property_close_fd() const -> Glib::PropertyProxy_ReadOnly< bool >
{
  return Glib::PropertyProxy_ReadOnly< bool >(this, "close-fd");
}


} // namespace Gio

#endif // _WIN32
