// Generated by gmmproc 2.74.0 -- DO NOT MODIFY!


#include <glibmm.h>

#include <giomm/unixconnection.h>
#include <giomm/private/unixconnection_p.h>


/* Copyright (C) 2010 Jonathon Jongsma
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
#include <gio/gunixconnection.h>
#include <giomm/slot_async.h>

namespace Gio
{

void
UnixConnection::receive_credentials_async(
  const SlotAsyncReady& slot, const Glib::RefPtr<Cancellable>& cancellable)
{
  auto slot_copy = new SlotAsyncReady(slot);

  g_unix_connection_receive_credentials_async(
    gobj(), Glib::unwrap(cancellable), &SignalProxy_async_callback, slot_copy);
}

void
UnixConnection::receive_credentials_async(const SlotAsyncReady& slot)
{
  auto slot_copy = new SlotAsyncReady(slot);

  g_unix_connection_receive_credentials_async(
    gobj(), nullptr, &SignalProxy_async_callback, slot_copy);
}

void
UnixConnection::send_credentials_async(
  const SlotAsyncReady& slot, const Glib::RefPtr<Cancellable>& cancellable)
{
  auto slot_copy = new SlotAsyncReady(slot);

  g_unix_connection_send_credentials_async(
    gobj(), Glib::unwrap(cancellable), &SignalProxy_async_callback, slot_copy);
}

void
UnixConnection::send_credentials_async(const SlotAsyncReady& slot)

{
  auto slot_copy = new SlotAsyncReady(slot);

  g_unix_connection_send_credentials_async(gobj(), nullptr, &SignalProxy_async_callback, slot_copy);
}

} // namespace Gio

namespace
{
} // anonymous namespace


namespace Glib
{

Glib::RefPtr<Gio::UnixConnection> wrap(GUnixConnection* object, bool take_copy)
{
  return Glib::make_refptr_for_instance<Gio::UnixConnection>( dynamic_cast<Gio::UnixConnection*> (Glib::wrap_auto ((GObject*)(object), take_copy)) );
  //We use dynamic_cast<> in case of multiple inheritance.
}

} /* namespace Glib */


namespace Gio
{


/* The *_Class implementation: */

const Glib::Class& UnixConnection_Class::init()
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Class has to know the class init function to clone custom types.
    class_init_func_ = &UnixConnection_Class::class_init_function;

    // This is actually just optimized away, apparently with no harm.
    // Make sure that the parent type has been created.
    //CppClassParent::CppObjectType::get_type();

    // Create the wrapper type, with the same class/instance size as the base type.
    register_derived_type(g_unix_connection_get_type());

    // Add derived versions of interfaces, if the C type implements any interfaces:

  }

  return *this;
}


void UnixConnection_Class::class_init_function(void* g_class, void* class_data)
{
  const auto klass = static_cast<BaseClassType*>(g_class);
  CppClassParent::class_init_function(klass, class_data);


}


Glib::ObjectBase* UnixConnection_Class::wrap_new(GObject* object)
{
  return new UnixConnection((GUnixConnection*)object);
}


/* The implementation: */

GUnixConnection* UnixConnection::gobj_copy()
{
  reference();
  return gobj();
}

UnixConnection::UnixConnection(const Glib::ConstructParams& construct_params)
:
  Gio::SocketConnection(construct_params)
{

}

UnixConnection::UnixConnection(GUnixConnection* castitem)
:
  Gio::SocketConnection((GSocketConnection*)(castitem))
{}


UnixConnection::UnixConnection(UnixConnection&& src) noexcept
: Gio::SocketConnection(std::move(src))
{}

UnixConnection& UnixConnection::operator=(UnixConnection&& src) noexcept
{
  Gio::SocketConnection::operator=(std::move(src));
  return *this;
}


UnixConnection::~UnixConnection() noexcept
{}


UnixConnection::CppClassType UnixConnection::unixconnection_class_; // initialize static member

GType UnixConnection::get_type()
{
  return unixconnection_class_.init().get_type();
}


GType UnixConnection::get_base_type()
{
  return g_unix_connection_get_type();
}


bool UnixConnection::send_fd(int fd, const Glib::RefPtr<Cancellable>& cancellable)
{
  GError* gerror = nullptr;
  auto retvalue = g_unix_connection_send_fd(gobj(), fd, const_cast<GCancellable*>(Glib::unwrap(cancellable)), &(gerror));
  if(gerror)
    ::Glib::Error::throw_exception(gerror);
  return retvalue;
}

bool UnixConnection::send_fd(int fd)
{
  GError* gerror = nullptr;
  auto retvalue = g_unix_connection_send_fd(gobj(), fd, nullptr, &(gerror));
  if(gerror)
    ::Glib::Error::throw_exception(gerror);
  return retvalue;
}

int UnixConnection::receive_fd(const Glib::RefPtr<Cancellable>& cancellable)
{
  GError* gerror = nullptr;
  auto retvalue = g_unix_connection_receive_fd(gobj(), const_cast<GCancellable*>(Glib::unwrap(cancellable)), &(gerror));
  if(gerror)
    ::Glib::Error::throw_exception(gerror);
  return retvalue;
}

int UnixConnection::receive_fd()
{
  GError* gerror = nullptr;
  auto retvalue = g_unix_connection_receive_fd(gobj(), nullptr, &(gerror));
  if(gerror)
    ::Glib::Error::throw_exception(gerror);
  return retvalue;
}

Glib::RefPtr<Credentials> UnixConnection::receive_credentials(const Glib::RefPtr<Cancellable>& cancellable)
{
  GError* gerror = nullptr;
  auto retvalue = Glib::wrap(g_unix_connection_receive_credentials(gobj(), const_cast<GCancellable*>(Glib::unwrap(cancellable)), &(gerror)));
  if(gerror)
    ::Glib::Error::throw_exception(gerror);
  return retvalue;
}

Glib::RefPtr<Credentials> UnixConnection::receive_credentials()
{
  GError* gerror = nullptr;
  auto retvalue = Glib::wrap(g_unix_connection_receive_credentials(gobj(), nullptr, &(gerror)));
  if(gerror)
    ::Glib::Error::throw_exception(gerror);
  return retvalue;
}

Glib::RefPtr<const Credentials> UnixConnection::receive_credentials(const Glib::RefPtr<Cancellable>& cancellable) const
{
  return const_cast<UnixConnection*>(this)->receive_credentials(cancellable);
}

Glib::RefPtr<const Credentials> UnixConnection::receive_credentials() const
{
  return const_cast<UnixConnection*>(this)->receive_credentials();
}

Glib::RefPtr<Credentials> UnixConnection::receive_credentials_finish(const Glib::RefPtr<AsyncResult>& result)
{
  GError* gerror = nullptr;
  auto retvalue = Glib::wrap(g_unix_connection_receive_credentials_finish(gobj(), Glib::unwrap(result), &(gerror)));
  if(gerror)
    ::Glib::Error::throw_exception(gerror);
  return retvalue;
}

bool UnixConnection::send_credentials(const Glib::RefPtr<Cancellable>& cancellable)
{
  GError* gerror = nullptr;
  auto retvalue = g_unix_connection_send_credentials(gobj(), const_cast<GCancellable*>(Glib::unwrap(cancellable)), &(gerror));
  if(gerror)
    ::Glib::Error::throw_exception(gerror);
  return retvalue;
}

bool UnixConnection::send_credentials()
{
  GError* gerror = nullptr;
  auto retvalue = g_unix_connection_send_credentials(gobj(), nullptr, &(gerror));
  if(gerror)
    ::Glib::Error::throw_exception(gerror);
  return retvalue;
}

bool UnixConnection::send_credentials_finish(const Glib::RefPtr<AsyncResult>& result)
{
  GError* gerror = nullptr;
  auto retvalue = g_unix_connection_send_credentials_finish(gobj(), Glib::unwrap(result), &(gerror));
  if(gerror)
    ::Glib::Error::throw_exception(gerror);
  return retvalue;
}


} // namespace Gio


