


#include <libmm-glib/mm-glib.hxx>

#include <libmm-gio/proxyresolver.hxx>
#include <libmm-gio/proxyresolver_p.hxx>


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
 * License along with this library.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <gio/gio.h>
#include <utility>
#include <libmm-glib/error.hxx>
#include <libmm-glib/exceptionhandler.hxx>
#include <libmm-glib/vectorutils.hxx>
#include <libmm-gio/slot_async.hxx>

namespace Gio
{

auto
ProxyResolver::lookup(const Glib::ustring& uri) -> std::vector<Glib::ustring>
{
  GError* gerror = nullptr;
  auto retvalue = Glib::ArrayHandler<Glib::ustring>::array_to_vector(
    g_proxy_resolver_lookup(gobj(), uri.c_str(), nullptr, &gerror), Glib::OWNERSHIP_DEEP);
  if (gerror)
    Glib::Error::throw_exception(gerror);

  return retvalue;
}

auto ProxyResolver::lookup_async (
  const Glib::ustring &uri, const SlotAsyncReady &slot,
  const Glib::RefPtr <Cancellable> &cancellable) -> void
{
  // Create a copy of the slot.
  // A pointer to it will be passed through the callback's data parameter
  // and deleted in the callback.
  const auto slot_copy = new SlotAsyncReady(slot);

  g_proxy_resolver_lookup_async(
    gobj(), uri.c_str(), Glib::unwrap(cancellable), &SignalProxy_async_callback, slot_copy);
}

auto ProxyResolver::lookup_async (const Glib::ustring &uri, const SlotAsyncReady &slot) -> void
{
  // Create a copy of the slot.
  // A pointer to it will be passed through the callback's data parameter
  // and deleted in the callback.
  const auto slot_copy = new SlotAsyncReady(slot);

  g_proxy_resolver_lookup_async(
    gobj(), uri.c_str(), nullptr, &SignalProxy_async_callback, slot_copy);
}

} // namespace Gio

namespace
{
} // anonymous namespace


namespace Glib
{

auto wrap(GProxyResolver* object, const bool take_copy) -> RefPtr<Gio::ProxyResolver>
{
  return Glib::make_refptr_for_instance<Gio::ProxyResolver>( Glib::wrap_auto_interface<Gio::ProxyResolver> ((GObject*)object, take_copy) );
  //We use dynamic_cast<> in case of multiple inheritance.
}

} // namespace Glib


namespace Gio
{


/* The *_Class implementation: */

auto ProxyResolver_Class::init() -> const Interface_Class&
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Interface_Class has to know the interface init function
    // in order to add interfaces to implementing types.
    class_init_func_ = &ProxyResolver_Class::iface_init_function;

    // We can not derive from another interface, and it is not necessary anyway.
    gtype_ = g_proxy_resolver_get_type();
  }

  return *this;
}

auto ProxyResolver_Class::iface_init_function (void *g_iface, void *) -> void
{
  const auto klass = static_cast<BaseClassType*>(g_iface);

  //This is just to avoid an "unused variable" warning when there are no vfuncs or signal handlers to connect.
  //This is a temporary fix until I find out why I can not seem to derive a GtkFileChooser interface. murrayc
  g_assert(klass != nullptr);


}


auto ProxyResolver_Class::wrap_new(GObject* object) -> Glib::ObjectBase*
{
  return new ProxyResolver((GProxyResolver*)object);
}


/* The implementation: */

ProxyResolver::ProxyResolver()
: Interface(proxyresolver_class_.init())
{}

ProxyResolver::ProxyResolver(GProxyResolver* castitem)
: Interface((GObject*)castitem)
{}

ProxyResolver::ProxyResolver(const Glib::Interface_Class& interface_class)
: Interface(interface_class)
{
}

ProxyResolver::ProxyResolver(ProxyResolver&& src) noexcept
: Interface(std::move(src))
{}

auto ProxyResolver::operator=(ProxyResolver&& src) noexcept -> ProxyResolver&
{
  Interface::operator=(std::move(src));
  return *this;
}

ProxyResolver::~ProxyResolver() noexcept = default;

// static
auto ProxyResolver::add_interface (
  const GType gtype_implementer) -> void
{
  proxyresolver_class_.init().add_interface(gtype_implementer);
}

ProxyResolver::CppClassType ProxyResolver::proxyresolver_class_; // initialize static member

auto ProxyResolver::get_type() -> GType
{
  return proxyresolver_class_.init().get_type();
}


auto ProxyResolver::get_base_type() -> GType
{
  return g_proxy_resolver_get_type();
}


auto ProxyResolver::get_default() -> Glib::RefPtr<ProxyResolver>
{
  return Glib::wrap(g_proxy_resolver_get_default());
}

auto ProxyResolver::is_supported() const -> bool
{
  return g_proxy_resolver_is_supported(const_cast<GProxyResolver*>(gobj()));
}

auto ProxyResolver::lookup(const Glib::ustring& uri, const Glib::RefPtr<Cancellable>& cancellable) -> std::vector<Glib::ustring>
{
  GError* gerror = nullptr;
  auto retvalue = Glib::ArrayHandler<Glib::ustring>::array_to_vector(g_proxy_resolver_lookup(gobj(), uri.c_str(), Glib::unwrap(cancellable), &gerror), Glib::OWNERSHIP_DEEP);
  if(gerror)
    Glib::Error::throw_exception(gerror);
  return retvalue;
}

auto ProxyResolver::lookup_finish(const Glib::RefPtr<AsyncResult>& result) -> std::vector<Glib::ustring>
{
  GError* gerror = nullptr;
  auto retvalue = Glib::ArrayHandler<Glib::ustring>::array_to_vector(g_proxy_resolver_lookup_finish(gobj(), Glib::unwrap(result), &gerror), Glib::OWNERSHIP_DEEP);
  if(gerror)
    Glib::Error::throw_exception(gerror);
  return retvalue;
}


} // namespace Gio


