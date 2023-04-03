// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GIOMM_DBUSPROXY_H
#define _GIOMM_DBUSPROXY_H

#include <libmm/glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm/gio/asyncinitable.hxx>
#include <libmm/gio/asyncresult.hxx>
#include <libmm/gio/dbusconnection.hxx>
#include <libmm/gio/dbusinterface.hxx>
#include <libmm/gio/dbusintrospection.hxx>
#include <libmm/gio/initable.hxx>
#include <libmm/glib/object.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GDBusProxy = struct _GDBusProxy;
using GDBusProxyClass = struct _GDBusProxyClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gio::DBus
{
  class LIBMM_GIO_SYMEXPORT Proxy_Class;
}
#endif

namespace Gio::DBus
{

  enum class ProxyFlags
  {
    NONE = 0x0,
    DO_NOT_LOAD_PROPERTIES = (1 << 0),
    DO_NOT_CONNECT_SIGNALS = (1 << 1),
    DO_NOT_AUTO_START = (1 << 2),
    GET_INVALIDATED_PROPERTIES = (1 << 3),
    DO_NOT_AUTO_START_AT_CONSTRUCTION = (1 << 4),
    NO_MATCH_RULE = (1 << 5)
  };

  inline auto
  operator| (ProxyFlags lhs, ProxyFlags rhs) -> ProxyFlags
  {
    return static_cast<ProxyFlags> (static_cast<unsigned> (lhs) |
                                    static_cast<unsigned> (rhs));
  }

  inline auto
  operator& (ProxyFlags lhs, ProxyFlags rhs) -> ProxyFlags
  {
    return static_cast<ProxyFlags> (static_cast<unsigned> (lhs) &
                                    static_cast<unsigned> (rhs));
  }

  inline auto
  operator^ (ProxyFlags lhs, ProxyFlags rhs) -> ProxyFlags
  {
    return static_cast<ProxyFlags> (static_cast<unsigned> (lhs) ^
                                    static_cast<unsigned> (rhs));
  }

  inline auto
  operator~(ProxyFlags flags) -> ProxyFlags
  {
    return static_cast<ProxyFlags> (~static_cast<unsigned> (flags));
  }

  inline auto
  operator|= (ProxyFlags& lhs, ProxyFlags rhs) -> ProxyFlags&
  {
    return (lhs = static_cast<ProxyFlags> (static_cast<unsigned> (lhs) |
                                           static_cast<unsigned> (rhs)));
  }

  inline auto
  operator&= (ProxyFlags& lhs, ProxyFlags rhs) -> ProxyFlags&
  {
    return (lhs = static_cast<ProxyFlags> (static_cast<unsigned> (lhs) &
                                           static_cast<unsigned> (rhs)));
  }

  inline auto
  operator^= (ProxyFlags& lhs, ProxyFlags rhs) -> ProxyFlags&
  {
    return (lhs = static_cast<ProxyFlags> (static_cast<unsigned> (lhs) ^
                                           static_cast<unsigned> (rhs)));
  }

} // namespace Gio::DBus

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

  template <>
  class LIBMM_GIO_SYMEXPORT Value<Gio::DBus::ProxyFlags>
    : public Glib::Value_Flags<Gio::DBus::ProxyFlags>
  {
  public:
    static auto
    value_type () -> GType G_GNUC_CONST;
  };

} // namespace Glib
#endif

namespace Gio::DBus
{

  class LIBMM_GIO_SYMEXPORT Proxy : public Glib::Object,
                          public Initable,
                          public AsyncInitable,
                          public Interface
  {
#ifndef DOXYGEN_SHOULD_SKIP_THIS

  public:
    using CppObjectType = Proxy;
    using CppClassType = Proxy_Class;
    using BaseObjectType = GDBusProxy;
    using BaseClassType = GDBusProxyClass;

    Proxy (const Proxy&) = delete;
    auto
    operator= (const Proxy&) -> Proxy& = delete;

  private:
    friend class Proxy_Class;
    static CppClassType proxy_class_;

  protected:
    explicit Proxy (const Glib::ConstructParams& construct_params);
    explicit Proxy (GDBusProxy* castitem);

#endif

  public:
    Proxy (Proxy&& src) noexcept;
    auto
    operator= (Proxy&& src) noexcept -> Proxy&;

    ~Proxy () noexcept override;

    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GDBusProxy*
    {
      return reinterpret_cast<GDBusProxy*> (gobject_);
    }

    auto
    gobj () const -> const GDBusProxy*
    {
      return reinterpret_cast<GDBusProxy*> (gobject_);
    }

    auto
    gobj_copy () -> GDBusProxy*;

  private:
  protected:
    Proxy (const Glib::RefPtr<Connection>& connection,
           const Glib::ustring& name,
           const Glib::ustring& object_path,
           const Glib::ustring& interface_name,
           const SlotAsyncReady& slot,
           const Glib::RefPtr<Cancellable>& cancellable,
           const Glib::RefPtr<InterfaceInfo>& info = {},
           ProxyFlags flags = ProxyFlags::NONE);

    Proxy (const Glib::RefPtr<Connection>& connection,
           const Glib::ustring& name,
           const Glib::ustring& object_path,
           const Glib::ustring& interface_name,
           const SlotAsyncReady& slot,
           const Glib::RefPtr<InterfaceInfo>& info = {},
           ProxyFlags flags = ProxyFlags::NONE);

    Proxy (const Glib::RefPtr<Connection>& connection,
           const Glib::ustring& name,
           const Glib::ustring& object_path,
           const Glib::ustring& interface_name,
           const Glib::RefPtr<Cancellable>& cancellable,
           const Glib::RefPtr<InterfaceInfo>& info = {},
           ProxyFlags flags = ProxyFlags::NONE);

    Proxy (const Glib::RefPtr<Connection>& connection,
           const Glib::ustring& name,
           const Glib::ustring& object_path,
           const Glib::ustring& interface_name,
           const Glib::RefPtr<InterfaceInfo>& info = {},
           ProxyFlags flags = ProxyFlags::NONE);

    Proxy (BusType bus_type,
           const Glib::ustring& name,
           const Glib::ustring& object_path,
           const Glib::ustring& interface_name,
           const SlotAsyncReady& slot,
           const Glib::RefPtr<Cancellable>& cancellable,
           const Glib::RefPtr<InterfaceInfo>& info = {},
           ProxyFlags flags = ProxyFlags::NONE);

    Proxy (BusType bus_type,
           const Glib::ustring& name,
           const Glib::ustring& object_path,
           const Glib::ustring& interface_name,
           const SlotAsyncReady& slot,
           const Glib::RefPtr<InterfaceInfo>& info = {},
           ProxyFlags flags = ProxyFlags::NONE);

    Proxy (BusType bus_type,
           const Glib::ustring& name,
           const Glib::ustring& object_path,
           const Glib::ustring& interface_name,
           const Glib::RefPtr<Cancellable>& cancellable,
           const Glib::RefPtr<InterfaceInfo>& info = {},
           ProxyFlags flags = ProxyFlags::NONE);

    Proxy (BusType bus_type,
           const Glib::ustring& name,
           const Glib::ustring& object_path,
           const Glib::ustring& interface_name,
           const Glib::RefPtr<InterfaceInfo>& info = {},
           ProxyFlags flags = ProxyFlags::NONE);

  public:
    static auto
    create (const Glib::RefPtr<Connection>& connection,
            const Glib::ustring& name,
            const Glib::ustring& object_path,
            const Glib::ustring& interface_name,
            const SlotAsyncReady& slot,
            const Glib::RefPtr<Cancellable>& cancellable,
            const Glib::RefPtr<InterfaceInfo>& info = {},
            ProxyFlags flags = ProxyFlags::NONE) -> void;

    static auto
    create (const Glib::RefPtr<Connection>& connection,
            const Glib::ustring& name,
            const Glib::ustring& object_path,
            const Glib::ustring& interface_name,
            const SlotAsyncReady& slot,
            const Glib::RefPtr<InterfaceInfo>& info = {},
            ProxyFlags flags = ProxyFlags::NONE) -> void;

    static auto
    create_finish (const Glib::RefPtr<AsyncResult>& res)
        -> Glib::RefPtr<Gio::DBus::Proxy>;

    static auto
    create_sync (const Glib::RefPtr<Connection>& connection,
                 const Glib::ustring& name,
                 const Glib::ustring& object_path,
                 const Glib::ustring& interface_name,
                 const Glib::RefPtr<Cancellable>& cancellable,
                 const Glib::RefPtr<InterfaceInfo>& info = {},
                 ProxyFlags flags = ProxyFlags::NONE) -> Glib::RefPtr<Proxy>;

    static auto
    create_sync (const Glib::RefPtr<Connection>& connection,
                 const Glib::ustring& name,
                 const Glib::ustring& object_path,
                 const Glib::ustring& interface_name,
                 const Glib::RefPtr<InterfaceInfo>& info = {},
                 ProxyFlags flags = ProxyFlags::NONE) -> Glib::RefPtr<Proxy>;

    static auto
    create_for_bus (BusType bus_type,
                    const Glib::ustring& name,
                    const Glib::ustring& object_path,
                    const Glib::ustring& interface_name,
                    const SlotAsyncReady& slot,
                    const Glib::RefPtr<Cancellable>& cancellable,
                    const Glib::RefPtr<InterfaceInfo>& info = {},
                    ProxyFlags flags = ProxyFlags::NONE) -> void;

    static auto
    create_for_bus (BusType bus_type,
                    const Glib::ustring& name,
                    const Glib::ustring& object_path,
                    const Glib::ustring& interface_name,
                    const SlotAsyncReady& slot,
                    const Glib::RefPtr<InterfaceInfo>& info = {},
                    ProxyFlags flags = ProxyFlags::NONE) -> void;

    static auto
    create_for_bus_finish (const Glib::RefPtr<AsyncResult>& res)
        -> Glib::RefPtr<Gio::DBus::Proxy>;

    static auto
    create_for_bus_sync (BusType bus_type,
                         const Glib::ustring& name,
                         const Glib::ustring& object_path,
                         const Glib::ustring& interface_name,
                         const Glib::RefPtr<Cancellable>& cancellable,
                         const Glib::RefPtr<InterfaceInfo>& info = {},
                         ProxyFlags flags = ProxyFlags::NONE)
        -> Glib::RefPtr<Proxy>;

    static auto
    create_for_bus_sync (BusType bus_type,
                         const Glib::ustring& name,
                         const Glib::ustring& object_path,
                         const Glib::ustring& interface_name,
                         const Glib::RefPtr<InterfaceInfo>& info = {},
                         ProxyFlags flags = ProxyFlags::NONE)
        -> Glib::RefPtr<Proxy>;

    auto
    get_flags () const -> ProxyFlags;

    auto
    get_connection () -> Glib::RefPtr<Connection>;

    auto
    get_connection () const -> Glib::RefPtr<const Connection>;

    auto
    get_name () const -> Glib::ustring;

    auto
    get_name_owner () const -> Glib::ustring;

    auto
    get_object_path () const -> Glib::ustring;

    auto
    get_interface_name () const -> Glib::ustring;

    auto
    get_default_timeout () const -> int;

    auto
    set_default_timeout (int timeout_msec = -1) -> void;

    auto
    get_cached_property (Glib::VariantBase& property,
                         const Glib::ustring& property_name) const -> void;

    auto
    set_cached_property (const Glib::ustring& property_name,
                         const Glib::VariantBase& value) -> void;

    auto
    get_cached_property_names () const -> std::vector<Glib::ustring>;

    auto
    set_interface_info (const Glib::RefPtr<InterfaceInfo>& info) -> void;

    auto
    get_interface_info () -> Glib::RefPtr<InterfaceInfo>;

    auto
    get_interface_info () const -> Glib::RefPtr<const InterfaceInfo>;

    auto
    call (const Glib::ustring& method_name,
          const SlotAsyncReady& slot,
          const Glib::RefPtr<Cancellable>& cancellable,
          const Glib::VariantContainerBase& parameters = {},
          int timeout_msec = -1,
          CallFlags flags = Gio::DBus::CallFlags::NONE) -> void;

    auto
    call (const Glib::ustring& method_name,
          const SlotAsyncReady& slot,
          const Glib::VariantContainerBase& parameters = {},
          int timeout_msec = -1,
          CallFlags flags = Gio::DBus::CallFlags::NONE) -> void;

    auto
    call (const Glib::ustring& method_name,
          const Glib::RefPtr<Cancellable>& cancellable,
          const Glib::VariantContainerBase& parameters = {},
          int timeout_msec = -1,
          CallFlags flags = Gio::DBus::CallFlags::NONE) -> void;

    auto
    call (const Glib::ustring& method_name,
          const Glib::VariantContainerBase& parameters = {},
          int timeout_msec = -1,
          CallFlags flags = Gio::DBus::CallFlags::NONE) -> void;

    auto
    call_finish (const Glib::RefPtr<AsyncResult>& res)
        -> Glib::VariantContainerBase;

    auto
    call_sync (const Glib::ustring& method_name,
               const Glib::RefPtr<Cancellable>& cancellable,
               const Glib::VariantContainerBase& parameters = {},
               int timeout_msec = -1,
               CallFlags flags = Gio::DBus::CallFlags::NONE)
        -> Glib::VariantContainerBase;

    auto
    call_sync (const Glib::ustring& method_name,
               const Glib::VariantContainerBase& parameters = {},
               int timeout_msec = -1,
               CallFlags flags = Gio::DBus::CallFlags::NONE)
        -> Glib::VariantContainerBase;

#ifdef G_OS_UNIX

    void
    call (const Glib::ustring& method_name,
          const Glib::VariantContainerBase& parameters,
          const SlotAsyncReady& slot,
          const Glib::RefPtr<Cancellable>& cancellable,
          const Glib::RefPtr<UnixFDList>& fd_list,
          int timeout_msec = -1,
          CallFlags flags = Gio::DBus::CallFlags::NONE);
#endif

#ifdef G_OS_UNIX

    void
    call (const Glib::ustring& method_name,
          const Glib::VariantContainerBase& parameters,
          const SlotAsyncReady& slot,
          const Glib::RefPtr<UnixFDList>& fd_list,
          int timeout_msec = -1,
          CallFlags flags = Gio::DBus::CallFlags::NONE);
#endif

#ifdef G_OS_UNIX

    void
    call (const Glib::ustring& method_name,
          const Glib::VariantContainerBase& parameters,
          const Glib::RefPtr<Cancellable>& cancellable,
          const Glib::RefPtr<UnixFDList>& fd_list,
          int timeout_msec = -1,
          CallFlags flags = Gio::DBus::CallFlags::NONE);
#endif

#ifdef G_OS_UNIX

    void
    call (const Glib::ustring& method_name,
          const Glib::VariantContainerBase& parameters,
          const Glib::RefPtr<UnixFDList>& fd_list,
          int timeout_msec = -1,
          CallFlags flags = Gio::DBus::CallFlags::NONE);
#endif

#ifdef G_OS_UNIX

    auto
    call_finish (const Glib::RefPtr<AsyncResult>& res,
                 Glib::RefPtr<UnixFDList>& out_fd_list)
        -> Glib::VariantContainerBase;
#endif

#ifdef G_OS_UNIX

    auto
    call_sync (const Glib::ustring& method_name,
               const Glib::VariantContainerBase& parameters,
               const Glib::RefPtr<Cancellable>& cancellable,
               const Glib::RefPtr<UnixFDList>& fd_list,
               Glib::RefPtr<UnixFDList>& out_fd_list,
               int timeout_msec = -1,
               CallFlags flags = Gio::DBus::CallFlags::NONE)
        -> Glib::VariantContainerBase;
#endif

#ifdef G_OS_UNIX

    auto
    call_sync (const Glib::ustring& method_name,
               const Glib::VariantContainerBase& parameters,
               const Glib::RefPtr<UnixFDList>& fd_list,
               Glib::RefPtr<UnixFDList>& out_fd_list,
               int timeout_msec = -1,
               CallFlags flags = Gio::DBus::CallFlags::NONE)
        -> Glib::VariantContainerBase;
#endif

    auto
    property_g_connection () const
        -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<Connection>>;

    auto
    property_g_default_timeout () -> Glib::PropertyProxy<int>;

    auto
    property_g_default_timeout () const -> Glib::PropertyProxy_ReadOnly<int>;

    auto
    property_g_flags () const -> Glib::PropertyProxy_ReadOnly<ProxyFlags>;

    auto
    property_g_interface_info ()
        -> Glib::PropertyProxy<Glib::RefPtr<InterfaceInfo>>;

    auto
    property_g_interface_info () const
        -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<InterfaceInfo>>;

    auto
    property_g_interface_name () const
        -> Glib::PropertyProxy_ReadOnly<Glib::ustring>;

    auto
    property_g_name () const -> Glib::PropertyProxy_ReadOnly<Glib::ustring>;

    auto
    property_g_name_owner () const
        -> Glib::PropertyProxy_ReadOnly<Glib::ustring>;

    auto
    property_g_object_path () const
        -> Glib::PropertyProxy_ReadOnly<Glib::ustring>;

    using MapChangedProperties = std::map<Glib::ustring, Glib::VariantBase>;

    auto
    signal_properties_changed ()
        -> Glib::SignalProxy<void (const MapChangedProperties&,
                                   const std::vector<Glib::ustring>&)>;

    auto
    signal_signal ()
        -> Glib::SignalProxy<void (const Glib::ustring&,
                                   const Glib::ustring&,
                                   const Glib::VariantContainerBase&)>;

    auto
    signal_signal (const Glib::ustring& signal_name)
        -> Glib::SignalProxyDetailed<void (const Glib::ustring&,
                                           const Glib::ustring&,
                                           const Glib::VariantContainerBase&)>;

  public:
  public:
  protected:
    virtual auto
    on_properties_changed (
        const MapChangedProperties& changed_properties,
        const std::vector<Glib::ustring>& invalidated_properties) -> void;

    virtual auto
    on_signal (const Glib::ustring& sender_name,
               const Glib::ustring& signal_name,
               const Glib::VariantContainerBase& parameters) -> void;
  };

} // namespace Gio::DBus

namespace Glib
{

  LIBMM_GIO_SYMEXPORT
  auto
  wrap (GDBusProxy* object, bool take_copy = false) -> Glib::RefPtr<Gio::DBus::Proxy>;
} // namespace Glib

#endif
