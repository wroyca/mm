

#include <libmm-glib/mm-glib.hxx>

#include <libmm-gio/proxy.hxx>
#include <libmm-gio/proxy_p.hxx>

#include <gio/gio.h>
#include <libmm-gio/slot_async.hxx>
#include <libmm-glib/error.hxx>
#include <libmm-glib/exceptionhandler.hxx>
#include <utility>

namespace Gio
{

  auto
  Proxy::connect_async (const Glib::RefPtr<IOStream>& connection,
                        const Glib::RefPtr<const ProxyAddress>& proxy_address,
                        const SlotAsyncReady& slot,
                        const Glib::RefPtr<Cancellable>& cancellable) -> void
  {
    const auto slot_copy = new SlotAsyncReady (slot);

    g_proxy_connect_async (
        gobj (),
        Glib::unwrap (connection),
        const_cast<GProxyAddress*> (Glib::unwrap (proxy_address)),
        Glib::unwrap (cancellable),
        &SignalProxy_async_callback,
        slot_copy);
  }

  auto
  Proxy::connect_async (const Glib::RefPtr<IOStream>& connection,
                        const Glib::RefPtr<const ProxyAddress>& proxy_address,
                        const SlotAsyncReady& slot) -> void
  {
    const auto slot_copy = new SlotAsyncReady (slot);

    g_proxy_connect_async (
        gobj (),
        Glib::unwrap (connection),
        const_cast<GProxyAddress*> (Glib::unwrap (proxy_address)),
        nullptr,
        &SignalProxy_async_callback,
        slot_copy);
  }

} // namespace Gio

namespace
{
}

namespace Glib
{

  auto
  wrap (GProxy* object, const bool take_copy) -> RefPtr<Gio::Proxy>
  {
    return Glib::make_refptr_for_instance<Gio::Proxy> (
        Glib::wrap_auto_interface<Gio::Proxy> ((GObject*) object, take_copy));
  }

} // namespace Glib

namespace Gio
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
  Proxy_Class::wrap_new (GObject* object) -> Glib::ObjectBase*
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

  Proxy::Proxy (const Glib::Interface_Class& interface_class)
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
  Proxy::get_default_for_protocol (const Glib::ustring& protocol) -> Glib::RefPtr<Proxy>
  {
    return Glib::wrap (g_proxy_get_default_for_protocol (protocol.c_str ()));
  }

  auto
  Proxy::connect (const Glib::RefPtr<IOStream>& connection,
                  const Glib::RefPtr<const ProxyAddress>& proxy_address,
                  const Glib::RefPtr<Cancellable>& cancellable) -> Glib::RefPtr<IOStream>
  {
    GError* gerror = nullptr;
    auto retvalue = Glib::wrap (g_proxy_connect (
        gobj (),
        Glib::unwrap (connection),
        const_cast<GProxyAddress*> (Glib::unwrap (proxy_address)),
        Glib::unwrap (cancellable),
        &gerror));
    if (gerror)
      Glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  Proxy::connect_finish (const Glib::RefPtr<AsyncResult>& result) -> Glib::RefPtr<IOStream>
  {
    GError* gerror = nullptr;
    auto retvalue = Glib::wrap (
        g_proxy_connect_finish (gobj (), Glib::unwrap (result), &gerror));
    if (gerror)
      Glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  Proxy::supports_hostname () const -> bool
  {
    return g_proxy_supports_hostname (const_cast<GProxy*> (gobj ()));
  }

} // namespace Gio
