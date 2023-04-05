// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/gio/proxyresolver.hxx>
#include <libmm/gio/proxyresolver_p.hxx>

#include <gio/gio.h>
#include <libmm/gio/slot_async.hxx>
#include <libmm/glib/error.hxx>
#include <libmm/glib/exceptionhandler.hxx>
#include <libmm/glib/vectorutils.hxx>
#include <utility>

namespace gio
{

  auto
  ProxyResolver::lookup (const glib::ustring& uri) -> std::vector<glib::ustring>
  {
    GError* gerror = nullptr;
    auto retvalue = glib::ArrayHandler<glib::ustring>::array_to_vector (
        g_proxy_resolver_lookup (gobj (), uri.c_str (), nullptr, &gerror),
        glib::OWNERSHIP_DEEP);
    if (gerror)
      glib::Error::throw_exception (gerror);

    return retvalue;
  }

  auto
  ProxyResolver::lookup_async (const glib::ustring& uri,
                               const SlotAsyncReady& slot,
                               const glib::RefPtr<Cancellable>& cancellable) -> void
  {
    const auto slot_copy = new SlotAsyncReady (slot);

    g_proxy_resolver_lookup_async (gobj (),
                                   uri.c_str (),
                                   glib::unwrap (cancellable),
                                   &SignalProxy_async_callback,
                                   slot_copy);
  }

  auto
  ProxyResolver::lookup_async (const glib::ustring& uri,
                               const SlotAsyncReady& slot) -> void
  {
    const auto slot_copy = new SlotAsyncReady (slot);

    g_proxy_resolver_lookup_async (gobj (),
                                   uri.c_str (),
                                   nullptr,
                                   &SignalProxy_async_callback,
                                   slot_copy);
  }

} // namespace gio

namespace
{
}

namespace glib
{

  auto
  wrap (GProxyResolver* object, const bool take_copy) -> RefPtr<gio::ProxyResolver>
  {
    return glib::make_refptr_for_instance<gio::ProxyResolver> (
        glib::wrap_auto_interface<gio::ProxyResolver> ((GObject*) object,
                                                       take_copy));
  }

} // namespace glib

namespace gio
{

  auto
  ProxyResolver_Class::init () -> const Interface_Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &ProxyResolver_Class::iface_init_function;

      gtype_ = g_proxy_resolver_get_type ();
    }

    return *this;
  }

  auto
  ProxyResolver_Class::iface_init_function (void* g_iface, void*) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_iface);

    g_assert (klass != nullptr);
  }

  auto
  ProxyResolver_Class::wrap_new (GObject* object) -> glib::ObjectBase*
  {
    return new ProxyResolver ((GProxyResolver*) object);
  }

  ProxyResolver::ProxyResolver ()
    : Interface (proxyresolver_class_.init ())
  {
  }

  ProxyResolver::ProxyResolver (GProxyResolver* castitem)
    : Interface ((GObject*) castitem)
  {
  }

  ProxyResolver::ProxyResolver (const glib::Interface_Class& interface_class)
    : Interface (interface_class)
  {
  }

  ProxyResolver::ProxyResolver (ProxyResolver&& src) noexcept
    : Interface (std::move (src))
  {
  }

  auto
  ProxyResolver::operator= (ProxyResolver&& src) noexcept -> ProxyResolver&
  {
    Interface::operator= (std::move (src));
    return *this;
  }

  ProxyResolver::~ProxyResolver () noexcept = default;

  auto
  ProxyResolver::add_interface (const GType gtype_implementer) -> void
  {
    proxyresolver_class_.init ().add_interface (gtype_implementer);
  }

  ProxyResolver::CppClassType ProxyResolver::proxyresolver_class_;

  auto
  ProxyResolver::get_type () -> GType
  {
    return proxyresolver_class_.init ().get_type ();
  }

  auto
  ProxyResolver::get_base_type () -> GType
  {
    return g_proxy_resolver_get_type ();
  }

  auto
  ProxyResolver::get_default () -> glib::RefPtr<ProxyResolver>
  {
    return glib::wrap (g_proxy_resolver_get_default ());
  }

  auto
  ProxyResolver::is_supported () const -> bool
  {
    return g_proxy_resolver_is_supported (
        const_cast<GProxyResolver*> (gobj ()));
  }

  auto
  ProxyResolver::lookup (const glib::ustring& uri,
                         const glib::RefPtr<Cancellable>& cancellable) -> std::vector<glib::ustring>
  {
    GError* gerror = nullptr;
    auto retvalue = glib::ArrayHandler<glib::ustring>::array_to_vector (
        g_proxy_resolver_lookup (gobj (),
                                 uri.c_str (),
                                 glib::unwrap (cancellable),
                                 &gerror),
        glib::OWNERSHIP_DEEP);
    if (gerror)
      glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  ProxyResolver::lookup_finish (const glib::RefPtr<AsyncResult>& result) -> std::vector<glib::ustring>
  {
    GError* gerror = nullptr;
    auto retvalue = glib::ArrayHandler<glib::ustring>::array_to_vector (
        g_proxy_resolver_lookup_finish (gobj (),
                                        glib::unwrap (result),
                                        &gerror),
        glib::OWNERSHIP_DEEP);
    if (gerror)
      glib::Error::throw_exception (gerror);
    return retvalue;
  }

} // namespace gio
