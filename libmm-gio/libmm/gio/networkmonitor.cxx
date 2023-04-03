// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/gio/networkmonitor.hxx>
#include <libmm/gio/networkmonitor_p.hxx>

#include <gio/gio.h>
#include <libmm/gio/slot_async.hxx>
#include <libmm/glib/exceptionhandler.hxx>

namespace Gio
{

  auto
  NetworkMonitor::can_reach_async (
      const Glib::RefPtr<SocketConnectable>& connectable,
      const SlotAsyncReady& slot,
      const Glib::RefPtr<Cancellable>& cancellable) -> void
  {
    const auto slot_copy = new SlotAsyncReady (slot);

    g_network_monitor_can_reach_async (gobj (),
                                       Glib::unwrap (connectable),
                                       Glib::unwrap (cancellable),
                                       &SignalProxy_async_callback,
                                       slot_copy);
  }

} // namespace Gio

namespace
{

  auto
  NetworkMonitor_signal_network_changed_callback (GNetworkMonitor* self,
                                                  const gboolean p0,
                                                  void* data) -> void
  {
    using namespace Gio;
    using SlotType = sigc::slot<void (bool)>;

    const auto obj = dynamic_cast<NetworkMonitor*> (
        Glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj)
    {
      try
      {
        if (const auto slot = Glib::SignalProxyNormal::data_to_slot (data))
          (*static_cast<SlotType*> (slot)) (p0);
      }
      catch (...)
      {
        Glib::exception_handlers_invoke ();
      }
    }
  }

  const Glib::SignalProxyInfo NetworkMonitor_signal_network_changed_info = {
      "network-changed",
      (GCallback) &NetworkMonitor_signal_network_changed_callback,
      (GCallback) &NetworkMonitor_signal_network_changed_callback};

} // namespace

auto
Glib::Value<Gio::NetworkConnectivity>::value_type () -> GType
{
  return g_network_connectivity_get_type ();
}

namespace Glib
{

  auto
  wrap (GNetworkMonitor* object, const bool take_copy) -> RefPtr<Gio::NetworkMonitor>
  {
    return Glib::make_refptr_for_instance<Gio::NetworkMonitor> (
        Glib::wrap_auto_interface<Gio::NetworkMonitor> ((GObject*) object,
                                                        take_copy));
  }

} // namespace Glib

namespace Gio
{

  auto
  NetworkMonitor_Class::init () -> const Interface_Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &NetworkMonitor_Class::iface_init_function;

      gtype_ = g_network_monitor_get_type ();
    }

    return *this;
  }

  auto
  NetworkMonitor_Class::iface_init_function (void* g_iface, void*) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_iface);

    g_assert (klass != nullptr);

    klass->network_changed = &network_changed_callback;
  }

  auto
  NetworkMonitor_Class::network_changed_callback (GNetworkMonitor* self,
                                                  const gboolean p0) -> void
  {
    const auto obj_base =
        Glib::ObjectBase::_get_current_wrapper ((GObject*) self);

    if (obj_base && obj_base->is_derived_ ())
    {
      const auto obj = dynamic_cast<CppObjectType* const> (obj_base);
      if (obj)
      {
        try
        {
          obj->on_network_changed (p0);
          return;
        }
        catch (...)
        {
          Glib::exception_handlers_invoke ();
        }
      }
    }

    const auto base =
        static_cast<BaseClassType*> (g_type_interface_peek_parent (
            g_type_interface_peek (G_OBJECT_GET_CLASS (self),
                                   CppObjectType::get_type ())));

    if (base && base->network_changed)
      (*base->network_changed) (self, p0);
  }

  auto
  NetworkMonitor_Class::wrap_new (GObject* object) -> Glib::ObjectBase*
  {
    return new NetworkMonitor ((GNetworkMonitor*) object);
  }

  NetworkMonitor::NetworkMonitor ()
    : Interface (networkmonitor_class_.init ())
  {
  }

  NetworkMonitor::NetworkMonitor (GNetworkMonitor* castitem)
    : Interface ((GObject*) castitem)
  {
  }

  NetworkMonitor::NetworkMonitor (const Glib::Interface_Class& interface_class)
    : Interface (interface_class)
  {
  }

  NetworkMonitor::NetworkMonitor (NetworkMonitor&& src) noexcept
    : Interface (std::move (src))
  {
  }

  auto
  NetworkMonitor::operator= (NetworkMonitor&& src) noexcept -> NetworkMonitor&
  {
    Interface::operator= (std::move (src));
    return *this;
  }

  NetworkMonitor::~NetworkMonitor () noexcept = default;

  auto
  NetworkMonitor::add_interface (const GType gtype_implementer) -> void
  {
    networkmonitor_class_.init ().add_interface (gtype_implementer);
  }

  NetworkMonitor::CppClassType NetworkMonitor::networkmonitor_class_;

  auto
  NetworkMonitor::get_type () -> GType
  {
    return networkmonitor_class_.init ().get_type ();
  }

  auto
  NetworkMonitor::get_base_type () -> GType
  {
    return g_network_monitor_get_type ();
  }

  auto
  NetworkMonitor::get_default () -> Glib::RefPtr<NetworkMonitor>
  {
    return Glib::wrap (g_network_monitor_get_default ());
  }

  auto
  NetworkMonitor::get_network_available () const -> bool
  {
    return g_network_monitor_get_network_available (
        const_cast<GNetworkMonitor*> (gobj ()));
  }

  auto
  NetworkMonitor::get_network_metered () const -> bool
  {
    return g_network_monitor_get_network_metered (
        const_cast<GNetworkMonitor*> (gobj ()));
  }

  auto
  NetworkMonitor::get_connectivity () const -> NetworkConnectivity
  {
    return static_cast<NetworkConnectivity> (
        g_network_monitor_get_connectivity (
            const_cast<GNetworkMonitor*> (gobj ())));
  }

  auto
  NetworkMonitor::can_reach (const Glib::RefPtr<SocketConnectable>& connectable,
                             const Glib::RefPtr<Cancellable>& cancellable) -> bool
  {
    GError* gerror = nullptr;
    const auto retvalue = g_network_monitor_can_reach (
        gobj (),
        Glib::unwrap (connectable),
        Glib::unwrap (cancellable),
        &gerror);
    if (gerror)
      Glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  NetworkMonitor::can_reach (const Glib::RefPtr<SocketConnectable>& connectable) -> bool
  {
    GError* gerror = nullptr;
    const auto retvalue = g_network_monitor_can_reach (
        gobj (),
        Glib::unwrap (connectable),
        nullptr,
        &gerror);
    if (gerror)
      Glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  NetworkMonitor::can_reach_finish (const Glib::RefPtr<AsyncResult>& result) -> bool
  {
    GError* gerror = nullptr;
    const auto retvalue = g_network_monitor_can_reach_finish (
        gobj (),
        Glib::unwrap (result),
        &gerror);
    if (gerror)
      Glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  NetworkMonitor::signal_network_changed () -> Glib::SignalProxy<void (bool)>
  {
    return {this, &NetworkMonitor_signal_network_changed_info};
  }

  auto
  NetworkMonitor::property_network_available () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return {this, "network-available"};
  }

  static_assert (
      Glib::Traits::ValueCompatibleWithWrapProperty<NetworkConnectivity>::value,
      "Type NetworkConnectivity cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  auto
  NetworkMonitor::property_connectivity () const -> Glib::PropertyProxy_ReadOnly<NetworkConnectivity>
  {
    return {this, "connectivity"};
  }

  auto
  NetworkMonitor::property_network_metered () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return {this, "network-metered"};
  }

  auto
  NetworkMonitor::on_network_changed (const bool available) -> void
  {
    const auto base =
        static_cast<BaseClassType*> (g_type_interface_peek_parent (
            g_type_interface_peek (G_OBJECT_GET_CLASS (gobject_),
                                   get_type ())));

    if (base && base->network_changed)
      (*base->network_changed) (gobj (), static_cast<int> (available));
  }

} // namespace Gio
