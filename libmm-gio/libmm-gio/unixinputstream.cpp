#ifndef _WIN32

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

#include <mm/glib/mm-glib.hpp>

#include <mm/gio/unixinputstream.hpp>
#include <mm/gio/private/unixinputstream_p.hpp>

#include <gio/gio.h>
#include <gio/gunixinputstream.h>

namespace
{
} // anonymous namespace

namespace Glib
{

auto wrap(GUnixInputStream* object, bool take_copy) -> Glib::RefPtr<Gio::UnixInputStream>
{
  return Glib::make_refptr_for_instance<Gio::UnixInputStream>( dynamic_cast<Gio::UnixInputStream*> (Glib::wrap_auto ((GObject*)(object), take_copy)) );
  //We use dynamic_cast<> in case of multiple inheritance.
}

} /* namespace Glib */


namespace Gio
{


/* The *_Class implementation: */

auto UnixInputStream_Class::init() -> const Glib::Class&
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Class has to know the class init function to clone custom types.
    class_init_func_ = &UnixInputStream_Class::class_init_function;

    // This is actually just optimized away, apparently with no harm.
    // Make sure that the parent type has been created.
    //CppClassParent::CppObjectType::get_type();

    // Create the wrapper type, with the same class/instance size as the base type.
    register_derived_type(g_unix_input_stream_get_type());

    // Add derived versions of interfaces, if the C type implements any interfaces:
  PollableInputStream::add_interface(get_type());
  FileDescriptorBased::add_interface(get_type());

  }

  return *this;
}


void UnixInputStream_Class::class_init_function(void* g_class, void* class_data)
{
  const auto klass = static_cast<BaseClassType*>(g_class);
  CppClassParent::class_init_function(klass, class_data);


}


auto UnixInputStream_Class::wrap_new(GObject* object) -> Glib::ObjectBase*
{
  return new UnixInputStream((GUnixInputStream*)object);
}


/* The implementation: */

auto UnixInputStream::gobj_copy() -> GUnixInputStream*
{
  reference();
  return gobj();
}

UnixInputStream::UnixInputStream(const Glib::ConstructParams& construct_params)
:
  Gio::InputStream(construct_params)
{

}

UnixInputStream::UnixInputStream(GUnixInputStream* castitem)
:
  Gio::InputStream((GInputStream*)(castitem))
{}


UnixInputStream::UnixInputStream(UnixInputStream&& src) noexcept
: Gio::InputStream(std::move(src))
  , PollableInputStream(std::move(src))
  , FileDescriptorBased(std::move(src))
{}

auto UnixInputStream::operator=(UnixInputStream&& src) noexcept -> UnixInputStream&
{
  Gio::InputStream::operator=(std::move(src));
  PollableInputStream::operator=(std::move(src));
  FileDescriptorBased::operator=(std::move(src));
  return *this;
}


UnixInputStream::~UnixInputStream() noexcept
{}


UnixInputStream::CppClassType UnixInputStream::unixinputstream_class_; // initialize static member

auto UnixInputStream::get_type() -> GType
{
  return unixinputstream_class_.init().get_type();
}


auto UnixInputStream::get_base_type() -> GType
{
  return g_unix_input_stream_get_type();
}


UnixInputStream::UnixInputStream(int fd, bool close_fd)
:
  // Mark this class as non-derived to allow C++ vfuncs to be skipped.
  Glib::ObjectBase(nullptr),
  Gio::InputStream(Glib::ConstructParams(unixinputstream_class_.init(), "fd", fd, "close_fd", static_cast<int>(close_fd), nullptr))
{


}

auto UnixInputStream::create(int fd, bool close_fd) -> Glib::RefPtr<UnixInputStream>
{
  return Glib::make_refptr_for_instance<UnixInputStream>( new UnixInputStream(fd, close_fd) );
}

void UnixInputStream::set_close_fd(bool close_fd)
{
  g_unix_input_stream_set_close_fd(gobj(), static_cast<int>(close_fd));
}

auto UnixInputStream::get_close_fd() const -> bool
{
  return g_unix_input_stream_get_close_fd(const_cast<GUnixInputStream*>(gobj()));
}

auto UnixInputStream::get_fd() const -> int
{
  return g_unix_input_stream_get_fd(const_cast<GUnixInputStream*>(gobj()));
}


auto UnixInputStream::property_fd() const -> Glib::PropertyProxy_ReadOnly< int >
{
  return Glib::PropertyProxy_ReadOnly< int >(this, "fd");
}

auto UnixInputStream::property_close_fd() -> Glib::PropertyProxy< bool >
{
  return Glib::PropertyProxy< bool >(this, "close-fd");
}

auto UnixInputStream::property_close_fd() const -> Glib::PropertyProxy_ReadOnly< bool >
{
  return Glib::PropertyProxy_ReadOnly< bool >(this, "close-fd");
}


} // namespace Gio

#endif // _WIN32
