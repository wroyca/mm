// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/gio/proxy.hxx>
#include <libmm/gio/proxy_p.hxx>

#include <gio/gio.h>
#include <libmm/gio/slot_async.hxx>
#include <libmm/glib/error.hxx>
#include <libmm/glib/exceptionhandler.hxx>
#include <utility>

namespace gio
{

  auto
  Proxy::connect_async (const glib::RefPtr<IOStream>& connection,
                        const glib::RefPtr<const ProxyAddress>& proxy_address,
                        const SlotAsyncReady& slot,
                        const glib::RefPtr<Cancellable>& cancellable) -> void
  {
    const auto slot_copy = new SlotAsyncReady (slot);

    g_proxy_connect_async (
        gobj (),
        glib::unwrap (connection),
        const_cast<GProxyAddress*> (glib::unwrap (proxy_address)),
        glib::unwrap (cancellable),
        &SignalProxy_async_callback,
        slot_copy);
  }

  auto
  Proxy::connect_async (const glib::RefPtr<IOStream>& connection,
                        const glib::RefPtr<const ProxyAddress>& proxy_address,
                        const SlotAsyncReady& slot) -> void
  {
    const auto slot_copy = new SlotAsyncReady (slot);

    g_proxy_connect_async (
        gobj (),
        glib::unwrap (connection),
        const_cast<GProxyAddress*> (glib::unwrap (proxy_address)),
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
  wrap (GProxy* object, const bool take_copy) -> RefPtr<gio::Proxy>
  {
    return glib::make_refptr_for_instance<gio::Proxy> (
        glib::wrap_auto_interface<gio::Proxy> ((GObject*) object, take_copy));
  }

} // namespace glib

namespace gio
{

  auto
  Proxy_Class::init () -> const Interface_Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &Proxy_Class::iface_init_function;

      gtype_ = g_proxy_get_type ();
    }

    return *this;
  }

  auto
  Proxy_Class::iface_init_function (void* g_iface, void*) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_iface);

    g_assert (klass != nullptr);
  }

  auto
  Proxy_Class::wrap_new (GObject* object) -> glib::ObjectBase*
  {
    return new Proxy ((GProxy*) object);
  }

  Proxy::Proxy ()
    : Interface (proxy_class_.init ())
  {
  }

  Proxy::Proxy (GProxy* castitem)
    : Interface ((GObject*) castitem)
  {
  }

  Proxy::Proxy (const glib::Interface_Class& interface_class)
    : Interface (interface_class)
  {
  }

  Proxy::Proxy (Proxy&& src) noexcept
    : Interface (std::move (src))
  {
  }

  auto
  Proxy::operator= (Proxy&& src) noexcept -> Proxy&
  {
    Interface::operator= (std::move (src));
    return *this;
  }

  Proxy::~Proxy () noexcept = default;

  auto
  Proxy::add_interface (const GType gtype_implementer) -> void
  {
    proxy_class_.init ().add_interface (gtype_implementer);
  }

  Proxy::CppClassType Proxy::proxy_class_;

  auto
  Proxy::get_type () -> GType
  {
    return proxy_class_.init ().get_type ();
  }

  auto
  Proxy::get_base_type () -> GType
  {
    return g_proxy_get_type ();
  }

  auto
  Proxy::get_default_for_protocol (const glib::ustring& protocol) -> glib::RefPtr<Proxy>
  {
    return glib::wrap (g_proxy_get_default_for_protocol (protocol.c_str ()));
  }

  auto
  Proxy::connect (const glib::RefPtr<IOStream>& connection,
                  const glib::RefPtr<const ProxyAddress>& proxy_address,
                  const glib::RefPtr<Cancellable>& cancellable) -> glib::RefPtr<IOStream>
  {
    GError* gerror = nullptr;
    auto retvalue = glib::wrap (g_proxy_connect (
        gobj (),
        glib::unwrap (connection),
        const_cast<GProxyAddress*> (glib::unwrap (proxy_address)),
        glib::unwrap (cancellable),
        &gerror));
    if (gerror)
      glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  Proxy::connect_finish (const glib::RefPtr<AsyncResult>& result) -> glib::RefPtr<IOStream>
  {
    GError* gerror = nullptr;
    auto retvalue = glib::wrap (
        g_proxy_connect_finish (gobj (), glib::unwrap (result), &gerror));
    if (gerror)
      glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  Proxy::supports_hostname () const -> bool
  {
    return g_proxy_supports_hostname (const_cast<GProxy*> (gobj ()));
  }

} // namespace gio
