// Generated by gmmproc 2.74.0 -- DO NOT MODIFY!


#include <glibmm.h>

#include <giomm/networkmonitor.h>
#include <giomm/private/networkmonitor_p.h>


/* Copyright (C) 2014 The gtkmm Development Team
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

#include <glibmm/exceptionhandler.h>
#include <gio/gio.h>
#include <giomm/slot_async.h>

namespace Gio
{

void
NetworkMonitor::can_reach_async(const Glib::RefPtr<SocketConnectable>& connectable,
  const SlotAsyncReady& slot, const Glib::RefPtr<Cancellable>& cancellable)
{
  // Create a copy of the slot.
  // A pointer to it will be passed through the callback's data parameter
  // and deleted in the callback.
  auto slot_copy = new SlotAsyncReady(slot);

  g_network_monitor_can_reach_async(gobj(), Glib::unwrap(connectable), Glib::unwrap(cancellable),
    &SignalProxy_async_callback, slot_copy);
}

} // namespace Gio

namespace
{


static void NetworkMonitor_signal_network_changed_callback(GNetworkMonitor* self, gboolean p0,void* data)
{
  using namespace Gio;
  using SlotType = sigc::slot<void(bool)>;

  auto obj = dynamic_cast<NetworkMonitor*>(Glib::ObjectBase::_get_current_wrapper((GObject*) self));
  // Do not try to call a signal on a disassociated wrapper.
  if(obj)
  {
    try
    {
      if(const auto slot = Glib::SignalProxyNormal::data_to_slot(data))
        (*static_cast<SlotType*>(slot))(p0
);
    }
    catch(...)
    {
       Glib::exception_handlers_invoke();
    }
  }
}

static const Glib::SignalProxyInfo NetworkMonitor_signal_network_changed_info =
{
  "network-changed",
  (GCallback) &NetworkMonitor_signal_network_changed_callback,
  (GCallback) &NetworkMonitor_signal_network_changed_callback
};


} // anonymous namespace

// static
GType Glib::Value<Gio::NetworkConnectivity>::value_type()
{
  return g_network_connectivity_get_type();
}


namespace Glib
{

Glib::RefPtr<Gio::NetworkMonitor> wrap(GNetworkMonitor* object, bool take_copy)
{
  return Glib::make_refptr_for_instance<Gio::NetworkMonitor>( dynamic_cast<Gio::NetworkMonitor*> (Glib::wrap_auto_interface<Gio::NetworkMonitor> ((GObject*)(object), take_copy)) );
  //We use dynamic_cast<> in case of multiple inheritance.
}

} // namespace Glib


namespace Gio
{


/* The *_Class implementation: */

const Glib::Interface_Class& NetworkMonitor_Class::init()
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Interface_Class has to know the interface init function
    // in order to add interfaces to implementing types.
    class_init_func_ = &NetworkMonitor_Class::iface_init_function;

    // We can not derive from another interface, and it is not necessary anyway.
    gtype_ = g_network_monitor_get_type();
  }

  return *this;
}

void NetworkMonitor_Class::iface_init_function(void* g_iface, void*)
{
  const auto klass = static_cast<BaseClassType*>(g_iface);

  //This is just to avoid an "unused variable" warning when there are no vfuncs or signal handlers to connect.
  //This is a temporary fix until I find out why I can not seem to derive a GtkFileChooser interface. murrayc
  g_assert(klass != nullptr);


  klass->network_changed = &network_changed_callback;
}


void NetworkMonitor_Class::network_changed_callback(GNetworkMonitor* self, gboolean p0)
{
  const auto obj_base = static_cast<Glib::ObjectBase*>(
      Glib::ObjectBase::_get_current_wrapper((GObject*)self));

  // Non-gtkmmproc-generated custom classes implicitly call the default
  // Glib::ObjectBase constructor, which sets is_derived_. But gtkmmproc-
  // generated classes can use this optimisation, which avoids the unnecessary
  // parameter conversions if there is no possibility of the virtual function
  // being overridden:
  if(obj_base && obj_base->is_derived_())
  {
    const auto obj = dynamic_cast<CppObjectType* const>(obj_base);
    if(obj) // This can be NULL during destruction.
    {
      try // Trap C++ exceptions which would normally be lost because this is a C callback.
      {
        // Call the virtual member method, which derived classes might override.
        obj->on_network_changed(p0
);
        return;
      }
      catch(...)
      {
        Glib::exception_handlers_invoke();
      }
    }
  }

  const auto base = static_cast<BaseClassType*>(
        g_type_interface_peek_parent( // Get the parent interface of the interface (The original underlying C interface).
g_type_interface_peek(G_OBJECT_GET_CLASS(self), CppObjectType::get_type()) // Get the interface.
)    );

  // Call the original underlying C function:
  if(base && base->network_changed)
    (*base->network_changed)(self, p0);
}


Glib::ObjectBase* NetworkMonitor_Class::wrap_new(GObject* object)
{
  return new NetworkMonitor((GNetworkMonitor*)(object));
}


/* The implementation: */

NetworkMonitor::NetworkMonitor()
:
  Glib::Interface(networkmonitor_class_.init())
{}

NetworkMonitor::NetworkMonitor(GNetworkMonitor* castitem)
:
  Glib::Interface((GObject*)(castitem))
{}

NetworkMonitor::NetworkMonitor(const Glib::Interface_Class& interface_class)
: Glib::Interface(interface_class)
{
}

NetworkMonitor::NetworkMonitor(NetworkMonitor&& src) noexcept
: Glib::Interface(std::move(src))
{}

NetworkMonitor& NetworkMonitor::operator=(NetworkMonitor&& src) noexcept
{
  Glib::Interface::operator=(std::move(src));
  return *this;
}

NetworkMonitor::~NetworkMonitor() noexcept
{}

// static
void NetworkMonitor::add_interface(GType gtype_implementer)
{
  networkmonitor_class_.init().add_interface(gtype_implementer);
}

NetworkMonitor::CppClassType NetworkMonitor::networkmonitor_class_; // initialize static member

GType NetworkMonitor::get_type()
{
  return networkmonitor_class_.init().get_type();
}


GType NetworkMonitor::get_base_type()
{
  return g_network_monitor_get_type();
}


Glib::RefPtr<NetworkMonitor> NetworkMonitor::get_default()
{
  return Glib::wrap(g_network_monitor_get_default());
}

bool NetworkMonitor::get_network_available() const
{
  return g_network_monitor_get_network_available(const_cast<GNetworkMonitor*>(gobj()));
}

bool NetworkMonitor::get_network_metered() const
{
  return g_network_monitor_get_network_metered(const_cast<GNetworkMonitor*>(gobj()));
}

NetworkConnectivity NetworkMonitor::get_connectivity() const
{
  return static_cast<NetworkConnectivity>(g_network_monitor_get_connectivity(const_cast<GNetworkMonitor*>(gobj())));
}

bool NetworkMonitor::can_reach(const Glib::RefPtr<SocketConnectable>& connectable, const Glib::RefPtr<Cancellable>& cancellable)
{
  GError* gerror = nullptr;
  auto retvalue = g_network_monitor_can_reach(gobj(), const_cast<GSocketConnectable*>(Glib::unwrap(connectable)), const_cast<GCancellable*>(Glib::unwrap(cancellable)), &(gerror));
  if(gerror)
    ::Glib::Error::throw_exception(gerror);
  return retvalue;
}

bool NetworkMonitor::can_reach(const Glib::RefPtr<SocketConnectable>& connectable)
{
  GError* gerror = nullptr;
  auto retvalue = g_network_monitor_can_reach(gobj(), const_cast<GSocketConnectable*>(Glib::unwrap(connectable)), nullptr, &(gerror));
  if(gerror)
    ::Glib::Error::throw_exception(gerror);
  return retvalue;
}

bool NetworkMonitor::can_reach_finish(const Glib::RefPtr<AsyncResult>& result)
{
  GError* gerror = nullptr;
  auto retvalue = g_network_monitor_can_reach_finish(gobj(), Glib::unwrap(result), &(gerror));
  if(gerror)
    ::Glib::Error::throw_exception(gerror);
  return retvalue;
}


Glib::SignalProxy<void(bool)> NetworkMonitor::signal_network_changed()
{
  return Glib::SignalProxy<void(bool) >(this, &NetworkMonitor_signal_network_changed_info);
}


Glib::PropertyProxy_ReadOnly< bool > NetworkMonitor::property_network_available() const
{
  return Glib::PropertyProxy_ReadOnly< bool >(this, "network-available");
}

static_assert(Glib::Traits::ValueCompatibleWithWrapProperty<NetworkConnectivity>::value,
  "Type NetworkConnectivity cannot be used in _WRAP_PROPERTY. "
  "There is no suitable template specialization of Glib::Value<>.");

Glib::PropertyProxy_ReadOnly< NetworkConnectivity > NetworkMonitor::property_connectivity() const
{
  return Glib::PropertyProxy_ReadOnly< NetworkConnectivity >(this, "connectivity");
}

Glib::PropertyProxy_ReadOnly< bool > NetworkMonitor::property_network_metered() const
{
  return Glib::PropertyProxy_ReadOnly< bool >(this, "network-metered");
}


void Gio::NetworkMonitor::on_network_changed(bool available)
{
  const auto base = static_cast<BaseClassType*>(
      g_type_interface_peek_parent( // Get the parent interface of the interface (The original underlying C interface).
g_type_interface_peek(G_OBJECT_GET_CLASS(gobject_), CppObjectType::get_type()) // Get the interface.
)  );

  if(base && base->network_changed)
    (*base->network_changed)(gobj(),static_cast<int>(available));
}


} // namespace Gio


