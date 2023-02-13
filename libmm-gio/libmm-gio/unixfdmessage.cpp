


#include <libmm-glib/mm-glib.hpp>

#include <libmm-gio/unixfdmessage.hpp>
#include <libmm-gio/unixfdmessage_p.hpp>


/* Copyright (C) 2010 The giomm Development Team
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

#include <gio/gunixfdmessage.h>
#include <libmm-glib/error.hpp>
#include <libmm-gio/unixfdlist.hpp>

namespace Gio
{

auto
UnixFDMessage::steal_fds() -> std::vector<int>
{
  int length = 0;
  const auto fds = g_unix_fd_message_steal_fds(gobj(), &length);
  // The array is terminated with a -1, but that terminating element is
  // not included in the length that g_unix_fd_message_steal_fds() returns.
  return Glib::ArrayHandler<int>::array_to_vector(fds, length, Glib::OWNERSHIP_DEEP);
}

} // namespace Gio

namespace
{
} // anonymous namespace


namespace Glib
{

auto wrap(GUnixFDMessage* object, bool take_copy) -> Glib::RefPtr<Gio::UnixFDMessage>
{
  return Glib::make_refptr_for_instance<Gio::UnixFDMessage>( dynamic_cast<Gio::UnixFDMessage*> (Glib::wrap_auto ((GObject*)(object), take_copy)) );
  //We use dynamic_cast<> in case of multiple inheritance.
}

} /* namespace Glib */


namespace Gio
{


/* The *_Class implementation: */

auto UnixFDMessage_Class::init() -> const Glib::Class&
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Class has to know the class init function to clone custom types.
    class_init_func_ = &UnixFDMessage_Class::class_init_function;

    // This is actually just optimized away, apparently with no harm.
    // Make sure that the parent type has been created.
    //CppClassParent::CppObjectType::get_type();

    // Create the wrapper type, with the same class/instance size as the base type.
    register_derived_type(g_unix_fd_message_get_type());

    // Add derived versions of interfaces, if the C type implements any interfaces:

  }

  return *this;
}


void UnixFDMessage_Class::class_init_function(void* g_class, void* class_data)
{
  const auto klass = static_cast<BaseClassType*>(g_class);
  CppClassParent::class_init_function(klass, class_data);


}


auto UnixFDMessage_Class::wrap_new(GObject* object) -> Glib::ObjectBase*
{
  return new UnixFDMessage((GUnixFDMessage*)object);
}


/* The implementation: */

auto UnixFDMessage::gobj_copy() -> GUnixFDMessage*
{
  reference();
  return gobj();
}

UnixFDMessage::UnixFDMessage(const Glib::ConstructParams& construct_params)
:
  Gio::SocketControlMessage(construct_params)
{

}

UnixFDMessage::UnixFDMessage(GUnixFDMessage* castitem)
:
  Gio::SocketControlMessage((GSocketControlMessage*)(castitem))
{}


UnixFDMessage::UnixFDMessage(UnixFDMessage&& src) noexcept
: Gio::SocketControlMessage(std::move(src))
{}

auto UnixFDMessage::operator=(UnixFDMessage&& src) noexcept -> UnixFDMessage&
{
  Gio::SocketControlMessage::operator=(std::move(src));
  return *this;
}


UnixFDMessage::~UnixFDMessage() noexcept
{}


UnixFDMessage::CppClassType UnixFDMessage::unixfdmessage_class_; // initialize static member

auto UnixFDMessage::get_type() -> GType
{
  return unixfdmessage_class_.init().get_type();
}


auto UnixFDMessage::get_base_type() -> GType
{
  return g_unix_fd_message_get_type();
}


UnixFDMessage::UnixFDMessage()
:
  // Mark this class as non-derived to allow C++ vfuncs to be skipped.
  Glib::ObjectBase(nullptr),
  Gio::SocketControlMessage(Glib::ConstructParams(unixfdmessage_class_.init()))
{


}

UnixFDMessage::UnixFDMessage(const Glib::RefPtr<UnixFDList>& fd_list)
:
  // Mark this class as non-derived to allow C++ vfuncs to be skipped.
  Glib::ObjectBase(nullptr),
  Gio::SocketControlMessage(Glib::ConstructParams(unixfdmessage_class_.init(), "fd_list", Glib::unwrap(fd_list), nullptr))
{


}

auto UnixFDMessage::create() -> Glib::RefPtr<UnixFDMessage>
{
  return Glib::make_refptr_for_instance<UnixFDMessage>( new UnixFDMessage() );
}

auto UnixFDMessage::create(const Glib::RefPtr<UnixFDList>& fd_list) -> Glib::RefPtr<UnixFDMessage>
{
  return Glib::make_refptr_for_instance<UnixFDMessage>( new UnixFDMessage(fd_list) );
}

auto UnixFDMessage::get_fd_list() -> Glib::RefPtr<UnixFDList>
{
  auto retvalue = Glib::wrap(g_unix_fd_message_get_fd_list(gobj()));
  if(retvalue)
    retvalue->reference(); //The function does not do a ref for us.
  return retvalue;
}

auto UnixFDMessage::get_fd_list() const -> Glib::RefPtr<const UnixFDList>
{
  return const_cast<UnixFDMessage*>(this)->get_fd_list();
}

auto UnixFDMessage::append_fd(int fd) -> bool
{
  GError* gerror = nullptr;
  auto retvalue = g_unix_fd_message_append_fd(gobj(), fd, &(gerror));
  if(gerror)
    ::Glib::Error::throw_exception(gerror);
  return retvalue;
}


static_assert(Glib::Traits::ValueCompatibleWithWrapProperty<Glib::RefPtr<UnixFDList>>::value,
  "Type Glib::RefPtr<UnixFDList> cannot be used in _WRAP_PROPERTY. "
  "There is no suitable template specialization of Glib::Value<>.");

auto UnixFDMessage::property_fd_list() const -> Glib::PropertyProxy_ReadOnly< Glib::RefPtr<UnixFDList> >
{
  return Glib::PropertyProxy_ReadOnly< Glib::RefPtr<UnixFDList> >(this, "fd-list");
}


} // namespace Gio

#endif // _WIN32
