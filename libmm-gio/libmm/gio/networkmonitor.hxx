// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GIOMM_NETWORKMONITOR_H
#define _GIOMM_NETWORKMONITOR_H

#include <libmm/glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <gio/gio.h>
#include <libmm/gio/asyncresult.hxx>
#include <libmm/gio/cancellable.hxx>
#include <libmm/gio/socketconnectable.hxx>
#include <libmm/glib/interface.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
typedef struct _GNetworkMonitorInterface GNetworkMonitorInterface;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GNetworkMonitor = struct _GNetworkMonitor;
using GNetworkMonitorClass = struct _GNetworkMonitorClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace gio
{
  class LIBMM_GIO_SYMEXPORT NetworkMonitor_Class;
}
#endif

namespace gio
{

  enum class NetworkConnectivity
  {
    LOCAL = 1,
    LIMITED,
    PORTAL,
    FULL
  };

} // namespace gio

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace glib
{

  template <>
  class LIBMM_GIO_SYMEXPORT Value<gio::NetworkConnectivity>
    : public glib::Value_Enum<gio::NetworkConnectivity>
  {
  public:
    static auto
    value_type () -> GType G_GNUC_CONST;
  };

} // namespace glib
#endif

namespace gio
{

  class LIBMM_GIO_SYMEXPORT NetworkMonitor : public glib::Interface
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

    explicit NetworkMonitor (const glib::Interface_Class& interface_class);

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
    get_default () -> glib::RefPtr<NetworkMonitor>;

    auto
    get_network_available () const -> bool;

    auto
    get_network_metered () const -> bool;

    auto
    get_connectivity () const -> NetworkConnectivity;

    auto
    can_reach (const glib::RefPtr<SocketConnectable>& connectable,
               const glib::RefPtr<Cancellable>& cancellable) -> bool;

    auto
    can_reach (const glib::RefPtr<SocketConnectable>& connectable) -> bool;

    auto
    can_reach_async (const glib::RefPtr<SocketConnectable>& connectable,
                     const SlotAsyncReady& slot,
                     const glib::RefPtr<Cancellable>& cancellable) -> void;

    auto
    can_reach_finish (const glib::RefPtr<AsyncResult>& result) -> bool;

    auto
    signal_network_changed () -> glib::SignalProxy<void (bool)>;

    auto
    property_network_available () const -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_connectivity () const
        -> glib::PropertyProxy_ReadOnly<NetworkConnectivity>;

    auto
    property_network_metered () const -> glib::PropertyProxy_ReadOnly<bool>;

  public:
  public:
  protected:
    virtual auto
    on_network_changed (bool available) -> void;
  };

} // namespace gio

namespace glib
{

  LIBMM_GIO_SYMEXPORT
  auto
  wrap (GNetworkMonitor* object, bool take_copy = false) -> glib::RefPtr<gio::NetworkMonitor>;

} // namespace glib

#endif
