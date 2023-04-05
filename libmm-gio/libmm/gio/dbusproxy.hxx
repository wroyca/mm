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
namespace gio::DBus
{
  class LIBMM_GIO_SYMEXPORT Proxy_Class;
}
#endif

namespace gio::DBus
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

} // namespace gio::DBus

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace glib
{

  template <>
  class LIBMM_GIO_SYMEXPORT Value<gio::DBus::ProxyFlags>
    : public glib::Value_Flags<gio::DBus::ProxyFlags>
  {
  public:
    static auto
    value_type () -> GType G_GNUC_CONST;
  };

} // namespace glib
#endif

namespace gio::DBus
{

  class LIBMM_GIO_SYMEXPORT Proxy : public glib::Object,
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
    explicit Proxy (const glib::ConstructParams& construct_params);
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
    Proxy (const glib::RefPtr<Connection>& connection,
           const glib::ustring& name,
           const glib::ustring& object_path,
           const glib::ustring& interface_name,
           const SlotAsyncReady& slot,
           const glib::RefPtr<Cancellable>& cancellable,
           const glib::RefPtr<InterfaceInfo>& info = {},
           ProxyFlags flags = ProxyFlags::NONE);

    Proxy (const glib::RefPtr<Connection>& connection,
           const glib::ustring& name,
           const glib::ustring& object_path,
           const glib::ustring& interface_name,
           const SlotAsyncReady& slot,
           const glib::RefPtr<InterfaceInfo>& info = {},
           ProxyFlags flags = ProxyFlags::NONE);

    Proxy (const glib::RefPtr<Connection>& connection,
           const glib::ustring& name,
           const glib::ustring& object_path,
           const glib::ustring& interface_name,
           const glib::RefPtr<Cancellable>& cancellable,
           const glib::RefPtr<InterfaceInfo>& info = {},
           ProxyFlags flags = ProxyFlags::NONE);

    Proxy (const glib::RefPtr<Connection>& connection,
           const glib::ustring& name,
           const glib::ustring& object_path,
           const glib::ustring& interface_name,
           const glib::RefPtr<InterfaceInfo>& info = {},
           ProxyFlags flags = ProxyFlags::NONE);

    Proxy (BusType bus_type,
           const glib::ustring& name,
           const glib::ustring& object_path,
           const glib::ustring& interface_name,
           const SlotAsyncReady& slot,
           const glib::RefPtr<Cancellable>& cancellable,
           const glib::RefPtr<InterfaceInfo>& info = {},
           ProxyFlags flags = ProxyFlags::NONE);

    Proxy (BusType bus_type,
           const glib::ustring& name,
           const glib::ustring& object_path,
           const glib::ustring& interface_name,
           const SlotAsyncReady& slot,
           const glib::RefPtr<InterfaceInfo>& info = {},
           ProxyFlags flags = ProxyFlags::NONE);

    Proxy (BusType bus_type,
           const glib::ustring& name,
           const glib::ustring& object_path,
           const glib::ustring& interface_name,
           const glib::RefPtr<Cancellable>& cancellable,
           const glib::RefPtr<InterfaceInfo>& info = {},
           ProxyFlags flags = ProxyFlags::NONE);

    Proxy (BusType bus_type,
           const glib::ustring& name,
           const glib::ustring& object_path,
           const glib::ustring& interface_name,
           const glib::RefPtr<InterfaceInfo>& info = {},
           ProxyFlags flags = ProxyFlags::NONE);

  public:
    static auto
    create (const glib::RefPtr<Connection>& connection,
            const glib::ustring& name,
            const glib::ustring& object_path,
            const glib::ustring& interface_name,
            const SlotAsyncReady& slot,
            const glib::RefPtr<Cancellable>& cancellable,
            const glib::RefPtr<InterfaceInfo>& info = {},
            ProxyFlags flags = ProxyFlags::NONE) -> void;

    static auto
    create (const glib::RefPtr<Connection>& connection,
            const glib::ustring& name,
            const glib::ustring& object_path,
            const glib::ustring& interface_name,
            const SlotAsyncReady& slot,
            const glib::RefPtr<InterfaceInfo>& info = {},
            ProxyFlags flags = ProxyFlags::NONE) -> void;

    static auto
    create_finish (const glib::RefPtr<AsyncResult>& res)
        -> glib::RefPtr<gio::DBus::Proxy>;

    static auto
    create_sync (const glib::RefPtr<Connection>& connection,
                 const glib::ustring& name,
                 const glib::ustring& object_path,
                 const glib::ustring& interface_name,
                 const glib::RefPtr<Cancellable>& cancellable,
                 const glib::RefPtr<InterfaceInfo>& info = {},
                 ProxyFlags flags = ProxyFlags::NONE) -> glib::RefPtr<Proxy>;

    static auto
    create_sync (const glib::RefPtr<Connection>& connection,
                 const glib::ustring& name,
                 const glib::ustring& object_path,
                 const glib::ustring& interface_name,
                 const glib::RefPtr<InterfaceInfo>& info = {},
                 ProxyFlags flags = ProxyFlags::NONE) -> glib::RefPtr<Proxy>;

    static auto
    create_for_bus (BusType bus_type,
                    const glib::ustring& name,
                    const glib::ustring& object_path,
                    const glib::ustring& interface_name,
                    const SlotAsyncReady& slot,
                    const glib::RefPtr<Cancellable>& cancellable,
                    const glib::RefPtr<InterfaceInfo>& info = {},
                    ProxyFlags flags = ProxyFlags::NONE) -> void;

    static auto
    create_for_bus (BusType bus_type,
                    const glib::ustring& name,
                    const glib::ustring& object_path,
                    const glib::ustring& interface_name,
                    const SlotAsyncReady& slot,
                    const glib::RefPtr<InterfaceInfo>& info = {},
                    ProxyFlags flags = ProxyFlags::NONE) -> void;

    static auto
    create_for_bus_finish (const glib::RefPtr<AsyncResult>& res)
        -> glib::RefPtr<gio::DBus::Proxy>;

    static auto
    create_for_bus_sync (BusType bus_type,
                         const glib::ustring& name,
                         const glib::ustring& object_path,
                         const glib::ustring& interface_name,
                         const glib::RefPtr<Cancellable>& cancellable,
                         const glib::RefPtr<InterfaceInfo>& info = {},
                         ProxyFlags flags = ProxyFlags::NONE)
        -> glib::RefPtr<Proxy>;

    static auto
    create_for_bus_sync (BusType bus_type,
                         const glib::ustring& name,
                         const glib::ustring& object_path,
                         const glib::ustring& interface_name,
                         const glib::RefPtr<InterfaceInfo>& info = {},
                         ProxyFlags flags = ProxyFlags::NONE)
        -> glib::RefPtr<Proxy>;

    auto
    get_flags () const -> ProxyFlags;

    auto
    get_connection () -> glib::RefPtr<Connection>;

    auto
    get_connection () const -> glib::RefPtr<const Connection>;

    auto
    get_name () const -> glib::ustring;

    auto
    get_name_owner () const -> glib::ustring;

    auto
    get_object_path () const -> glib::ustring;

    auto
    get_interface_name () const -> glib::ustring;

    auto
    get_default_timeout () const -> int;

    auto
    set_default_timeout (int timeout_msec = -1) -> void;

    auto
    get_cached_property (glib::VariantBase& property,
                         const glib::ustring& property_name) const -> void;

    auto
    set_cached_property (const glib::ustring& property_name,
                         const glib::VariantBase& value) -> void;

    auto
    get_cached_property_names () const -> std::vector<glib::ustring>;

    auto
    set_interface_info (const glib::RefPtr<InterfaceInfo>& info) -> void;

    auto
    get_interface_info () -> glib::RefPtr<InterfaceInfo>;

    auto
    get_interface_info () const -> glib::RefPtr<const InterfaceInfo>;

    auto
    call (const glib::ustring& method_name,
          const SlotAsyncReady& slot,
          const glib::RefPtr<Cancellable>& cancellable,
          const glib::VariantContainerBase& parameters = {},
          int timeout_msec = -1,
          CallFlags flags = gio::DBus::CallFlags::NONE) -> void;

    auto
    call (const glib::ustring& method_name,
          const SlotAsyncReady& slot,
          const glib::VariantContainerBase& parameters = {},
          int timeout_msec = -1,
          CallFlags flags = gio::DBus::CallFlags::NONE) -> void;

    auto
    call (const glib::ustring& method_name,
          const glib::RefPtr<Cancellable>& cancellable,
          const glib::VariantContainerBase& parameters = {},
          int timeout_msec = -1,
          CallFlags flags = gio::DBus::CallFlags::NONE) -> void;

    auto
    call (const glib::ustring& method_name,
          const glib::VariantContainerBase& parameters = {},
          int timeout_msec = -1,
          CallFlags flags = gio::DBus::CallFlags::NONE) -> void;

    auto
    call_finish (const glib::RefPtr<AsyncResult>& res)
        -> glib::VariantContainerBase;

    auto
    call_sync (const glib::ustring& method_name,
               const glib::RefPtr<Cancellable>& cancellable,
               const glib::VariantContainerBase& parameters = {},
               int timeout_msec = -1,
               CallFlags flags = gio::DBus::CallFlags::NONE)
        -> glib::VariantContainerBase;

    auto
    call_sync (const glib::ustring& method_name,
               const glib::VariantContainerBase& parameters = {},
               int timeout_msec = -1,
               CallFlags flags = gio::DBus::CallFlags::NONE)
        -> glib::VariantContainerBase;

#ifdef G_OS_UNIX

    void
    call (const glib::ustring& method_name,
          const glib::VariantContainerBase& parameters,
          const SlotAsyncReady& slot,
          const glib::RefPtr<Cancellable>& cancellable,
          const glib::RefPtr<UnixFDList>& fd_list,
          int timeout_msec = -1,
          CallFlags flags = gio::DBus::CallFlags::NONE);
#endif

#ifdef G_OS_UNIX

    void
    call (const glib::ustring& method_name,
          const glib::VariantContainerBase& parameters,
          const SlotAsyncReady& slot,
          const glib::RefPtr<UnixFDList>& fd_list,
          int timeout_msec = -1,
          CallFlags flags = gio::DBus::CallFlags::NONE);
#endif

#ifdef G_OS_UNIX

    void
    call (const glib::ustring& method_name,
          const glib::VariantContainerBase& parameters,
          const glib::RefPtr<Cancellable>& cancellable,
          const glib::RefPtr<UnixFDList>& fd_list,
          int timeout_msec = -1,
          CallFlags flags = gio::DBus::CallFlags::NONE);
#endif

#ifdef G_OS_UNIX

    void
    call (const glib::ustring& method_name,
          const glib::VariantContainerBase& parameters,
          const glib::RefPtr<UnixFDList>& fd_list,
          int timeout_msec = -1,
          CallFlags flags = gio::DBus::CallFlags::NONE);
#endif

#ifdef G_OS_UNIX

    auto
    call_finish (const glib::RefPtr<AsyncResult>& res,
                 glib::RefPtr<UnixFDList>& out_fd_list)
        -> glib::VariantContainerBase;
#endif

#ifdef G_OS_UNIX

    auto
    call_sync (const glib::ustring& method_name,
               const glib::VariantContainerBase& parameters,
               const glib::RefPtr<Cancellable>& cancellable,
               const glib::RefPtr<UnixFDList>& fd_list,
               glib::RefPtr<UnixFDList>& out_fd_list,
               int timeout_msec = -1,
               CallFlags flags = gio::DBus::CallFlags::NONE)
        -> glib::VariantContainerBase;
#endif

#ifdef G_OS_UNIX

    auto
    call_sync (const glib::ustring& method_name,
               const glib::VariantContainerBase& parameters,
               const glib::RefPtr<UnixFDList>& fd_list,
               glib::RefPtr<UnixFDList>& out_fd_list,
               int timeout_msec = -1,
               CallFlags flags = gio::DBus::CallFlags::NONE)
        -> glib::VariantContainerBase;
#endif

    auto
    property_g_connection () const
        -> glib::PropertyProxy_ReadOnly<glib::RefPtr<Connection>>;

    auto
    property_g_default_timeout () -> glib::PropertyProxy<int>;

    auto
    property_g_default_timeout () const -> glib::PropertyProxy_ReadOnly<int>;

    auto
    property_g_flags () const -> glib::PropertyProxy_ReadOnly<ProxyFlags>;

    auto
    property_g_interface_info ()
        -> glib::PropertyProxy<glib::RefPtr<InterfaceInfo>>;

    auto
    property_g_interface_info () const
        -> glib::PropertyProxy_ReadOnly<glib::RefPtr<InterfaceInfo>>;

    auto
    property_g_interface_name () const
        -> glib::PropertyProxy_ReadOnly<glib::ustring>;

    auto
    property_g_name () const -> glib::PropertyProxy_ReadOnly<glib::ustring>;

    auto
    property_g_name_owner () const
        -> glib::PropertyProxy_ReadOnly<glib::ustring>;

    auto
    property_g_object_path () const
        -> glib::PropertyProxy_ReadOnly<glib::ustring>;

    using MapChangedProperties = std::map<glib::ustring, glib::VariantBase>;

    auto
    signal_properties_changed ()
        -> glib::SignalProxy<void (const MapChangedProperties&,
                                   const std::vector<glib::ustring>&)>;

    auto
    signal_signal ()
        -> glib::SignalProxy<void (const glib::ustring&,
                                   const glib::ustring&,
                                   const glib::VariantContainerBase&)>;

    auto
    signal_signal (const glib::ustring& signal_name)
        -> glib::SignalProxyDetailed<void (const glib::ustring&,
                                           const glib::ustring&,
                                           const glib::VariantContainerBase&)>;

  public:
  public:
  protected:
    virtual auto
    on_properties_changed (
        const MapChangedProperties& changed_properties,
        const std::vector<glib::ustring>& invalidated_properties) -> void;

    virtual auto
    on_signal (const glib::ustring& sender_name,
               const glib::ustring& signal_name,
               const glib::VariantContainerBase& parameters) -> void;
  };

} // namespace gio::DBus

namespace glib
{

  LIBMM_GIO_SYMEXPORT
  auto
  wrap (GDBusProxy* object, bool take_copy = false) -> glib::RefPtr<gio::DBus::Proxy>;
} // namespace glib

#endif
