// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GIOMM_NETWORKMONITOR_H
#define _GIOMM_NETWORKMONITOR_H

#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <gio/gio.h>
#include <libmm-gio/asyncresult.hxx>
#include <libmm-gio/cancellable.hxx>
#include <libmm-gio/socketconnectable.hxx>
#include <libmm-glib/interface.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
typedef struct _GNetworkMonitorInterface GNetworkMonitorInterface;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GNetworkMonitor = struct _GNetworkMonitor;
using GNetworkMonitorClass = struct _GNetworkMonitorClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gio
{
  class GIOMM_API NetworkMonitor_Class;
}
#endif

namespace Gio
{

  enum class NetworkConnectivity
  {
    LOCAL = 1,
    LIMITED,
    PORTAL,
    FULL
  };

} // namespace Gio

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

  template <>
  class GIOMM_API Value<Gio::NetworkConnectivity>
    : public Glib::Value_Enum<Gio::NetworkConnectivity>
  {
  public:
    static auto
    value_type () -> GType G_GNUC_CONST;
  };

} // namespace Glib
#endif

namespace Gio
{

  class GIOMM_API NetworkMonitor : public Glib::Interface
  {
#ifndef DOXYGEN_SHOULD_SKIP_THIS

  public:
    using CppObjectType = NetworkMonitor;
    using CppClassType = NetworkMonitor_Class;
    using BaseObjectType = GNetworkMonitor;
    using BaseClassType = GNetworkMonitorInterface;

    NetworkMonitor (const NetworkMonitor&) = delete;
    auto
    operator= (const NetworkMonitor&) -> NetworkMonitor& = delete;

  private:
    friend class NetworkMonitor_Class;
    static CppClassType networkmonitor_class_;

#endif
  protected:
    NetworkMonitor ();

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    explicit NetworkMonitor (const Glib::Interface_Class& interface_class);

  public:
    explicit NetworkMonitor (GNetworkMonitor* castitem);

  protected:
#endif

  public:
    NetworkMonitor (NetworkMonitor&& src) noexcept;
    auto
    operator= (NetworkMonitor&& src) noexcept -> NetworkMonitor&;

    ~NetworkMonitor () noexcept override;

    static auto
    add_interface (GType gtype_implementer) -> void;

    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS
    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GNetworkMonitor*
    {
      return reinterpret_cast<GNetworkMonitor*> (gobject_);
    }

    auto
    gobj () const -> const GNetworkMonitor*
    {
      return reinterpret_cast<GNetworkMonitor*> (gobject_);
    }

  private:
  public:
    static auto
    get_default () -> Glib::RefPtr<NetworkMonitor>;

    auto
    get_network_available () const -> bool;

    auto
    get_network_metered () const -> bool;

    auto
    get_connectivity () const -> NetworkConnectivity;

    auto
    can_reach (const Glib::RefPtr<SocketConnectable>& connectable,
               const Glib::RefPtr<Cancellable>& cancellable) -> bool;

    auto
    can_reach (const Glib::RefPtr<SocketConnectable>& connectable) -> bool;

    auto
    can_reach_async (const Glib::RefPtr<SocketConnectable>& connectable,
                     const SlotAsyncReady& slot,
                     const Glib::RefPtr<Cancellable>& cancellable) -> void;

    auto
    can_reach_finish (const Glib::RefPtr<AsyncResult>& result) -> bool;

    auto
    signal_network_changed () -> Glib::SignalProxy<void (bool)>;

    auto
    property_network_available () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_connectivity () const
        -> Glib::PropertyProxy_ReadOnly<NetworkConnectivity>;

    auto
    property_network_metered () const -> Glib::PropertyProxy_ReadOnly<bool>;

  public:
  public:
  protected:
    virtual auto
    on_network_changed (bool available) -> void;
  };

} // namespace Gio

namespace Glib
{

  GIOMM_API
  auto
  wrap (GNetworkMonitor* object, bool take_copy = false) -> Glib::RefPtr<Gio::NetworkMonitor>;

} // namespace Glib

#endif
