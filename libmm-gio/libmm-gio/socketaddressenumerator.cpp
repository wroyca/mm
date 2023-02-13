


#include <libmm-glib/mm-glib.hpp>

#include <libmm-gio/socketaddressenumerator.hpp>
#include <libmm-gio/socketaddressenumerator_p.hpp>


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
#include <libmm-glib/error.hpp>
#include <libmm-gio/socketaddress.hpp>
#include <libmm-gio/slot_async.hpp>

namespace Gio
{

auto SocketAddressEnumerator::next_async (
  const Glib::RefPtr <Cancellable> &cancellable, const SlotAsyncReady &slot) -> void
{
  // Create a copy of the slot.
  // A pointer to it will be passed through the callback's data parameter
  // and deleted in the callback.
  const auto slot_copy = new SlotAsyncReady(slot);

  g_socket_address_enumerator_next_async(
    gobj(), Glib::unwrap(cancellable), &SignalProxy_async_callback, slot_copy);
}

} // namespace Gio

namespace
{
} // anonymous namespace


namespace Glib
{

auto wrap(GSocketAddressEnumerator* object, const bool take_copy) -> RefPtr<Gio::SocketAddressEnumerator>
{
  return Glib::make_refptr_for_instance<Gio::SocketAddressEnumerator>( dynamic_cast<Gio::SocketAddressEnumerator*> (wrap_auto((GObject*)object, take_copy)) );
  //We use dynamic_cast<> in case of multiple inheritance.
}

} /* namespace Glib */


namespace Gio
{


/* The *_Class implementation: */

auto SocketAddressEnumerator_Class::init() -> const Class&
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Class has to know the class init function to clone custom types.
    class_init_func_ = &SocketAddressEnumerator_Class::class_init_function;

    // This is actually just optimized away, apparently with no harm.
    // Make sure that the parent type has been created.
    //CppClassParent::CppObjectType::get_type();

    // Create the wrapper type, with the same class/instance size as the base type.
    register_derived_type(g_socket_address_enumerator_get_type());

    // Add derived versions of interfaces, if the C type implements any interfaces:

  }

  return *this;
}


auto SocketAddressEnumerator_Class::class_init_function (void *g_class, void *class_data) -> void
{
  const auto klass = static_cast<BaseClassType*>(g_class);
  CppClassParent::class_init_function(klass, class_data);


}


auto SocketAddressEnumerator_Class::wrap_new(GObject* object) -> Glib::ObjectBase*
{
  return new SocketAddressEnumerator((GSocketAddressEnumerator*)object);
}


/* The implementation: */

auto SocketAddressEnumerator::gobj_copy() -> GSocketAddressEnumerator*
{
  reference();
  return gobj();
}

SocketAddressEnumerator::SocketAddressEnumerator(const Glib::ConstructParams& construct_params)
: Object(construct_params)
{

}

SocketAddressEnumerator::SocketAddressEnumerator(GSocketAddressEnumerator* castitem)
: Object((GObject*)castitem)
{}


SocketAddressEnumerator::SocketAddressEnumerator(SocketAddressEnumerator&& src) noexcept
: Object(std::move(src))
{}

auto SocketAddressEnumerator::operator=(SocketAddressEnumerator&& src) noexcept -> SocketAddressEnumerator&
{
  Object::operator=(std::move(src));
  return *this;
}


SocketAddressEnumerator::~SocketAddressEnumerator() noexcept = default;

SocketAddressEnumerator::CppClassType SocketAddressEnumerator::socketaddressenumerator_class_; // initialize static member

auto SocketAddressEnumerator::get_type() -> GType
{
  return socketaddressenumerator_class_.init().get_type();
}


auto SocketAddressEnumerator::get_base_type() -> GType
{
  return g_socket_address_enumerator_get_type();
}


auto SocketAddressEnumerator::next(const Glib::RefPtr<Cancellable>& cancellable) -> Glib::RefPtr<SocketAddress>
{
  GError* gerror = nullptr;
  auto retvalue = Glib::wrap(g_socket_address_enumerator_next(gobj(), Glib::unwrap(cancellable), &gerror));
  if(gerror)
    Glib::Error::throw_exception(gerror);
  return retvalue;
}

auto SocketAddressEnumerator::next() -> Glib::RefPtr<SocketAddress>
{
  GError* gerror = nullptr;
  auto retvalue = Glib::wrap(g_socket_address_enumerator_next(gobj(), nullptr, &gerror));
  if(gerror)
    Glib::Error::throw_exception(gerror);
  return retvalue;
}

auto SocketAddressEnumerator::next_finish(const Glib::RefPtr<AsyncResult>& result) -> Glib::RefPtr<SocketAddress>
{
  GError* gerror = nullptr;
  auto retvalue = Glib::wrap(g_socket_address_enumerator_next_finish(gobj(), Glib::unwrap(result), &gerror));
  if(gerror)
    Glib::Error::throw_exception(gerror);
  return retvalue;
}


} // namespace Gio


