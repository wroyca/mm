// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GIOMM_DBUSOBJECTMANAGERCLIENT_H
#define _GIOMM_DBUSOBJECTMANAGERCLIENT_H

#include <libmm/glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm/gio/asyncinitable.hxx>
#include <libmm/gio/asyncresult.hxx>
#include <libmm/gio/dbusconnection.hxx>
#include <libmm/gio/dbusobjectmanager.hxx>
#include <libmm/gio/dbusobjectproxy.hxx>
#include <libmm/gio/dbusproxy.hxx>
#include <libmm/gio/initable.hxx>
#include <libmm/glib/object.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GDBusObjectManagerClient = struct _GDBusObjectManagerClient;
using GDBusObjectManagerClientClass = struct _GDBusObjectManagerClientClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace gio::DBus
{
  class LIBMM_GIO_SYMEXPORT ObjectManagerClient_Class;
}
#endif

namespace gio::DBus
{

  class LIBMM_GIO_SYMEXPORT ObjectManagerClient : public glib::Object,
                                        public Initable,
                                        public AsyncInitable,
                                        public ObjectManager
  {
#ifndef DOXYGEN_SHOULD_SKIP_THIS

  public:
    using CppObjectType = ObjectManagerClient;
    using CppClassType = ObjectManagerClient_Class;
    using BaseObjectType = GDBusObjectManagerClient;
    using BaseClassType = GDBusObjectManagerClientClass;

    ObjectManagerClient (const ObjectManagerClient&) = delete;
    auto
    operator= (const ObjectManagerClient&) -> ObjectManagerClient& = delete;

  private:
    friend class ObjectManagerClient_Class;
    static CppClassType objectmanagerclient_class_;

  protected:
    explicit ObjectManagerClient (
        const glib::ConstructParams& construct_params);
    explicit ObjectManagerClient (GDBusObjectManagerClient* castitem);

#endif

  public:
    ObjectManagerClient (ObjectManagerClient&& src) noexcept;
    auto
    operator= (ObjectManagerClient&& src) noexcept -> ObjectManagerClient&;

    ~ObjectManagerClient () noexcept override;

    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GDBusObjectManagerClient*
    {
      return reinterpret_cast<GDBusObjectManagerClient*> (gobject_);
    }

    auto
    gobj () const -> const GDBusObjectManagerClient*
    {
      return reinterpret_cast<GDBusObjectManagerClient*> (gobject_);
    }

    auto
    gobj_copy () -> GDBusObjectManagerClient*;

  private:
  public:
    enum class Flags
    {
      NONE = 0x0,
      DO_NOT_AUTO_START = (1 << 0)
    };

    using SlotProxyType =
        sigc::slot<GType (const glib::RefPtr<gio::DBus::ObjectManagerClient>&,
                          const glib::ustring&,
                          const glib::ustring&)>;

  protected:
    ObjectManagerClient (const glib::RefPtr<Connection>& connection,
                         const glib::ustring& name,
                         const glib::ustring& object_path,
                         const SlotAsyncReady& slot_async_ready,
                         const glib::RefPtr<Cancellable>& cancellable,
                         const SlotProxyType& slot_proxy_type,
                         Flags flags);

    ObjectManagerClient (BusType bus_type,
                         const glib::ustring& name,
                         const glib::ustring& object_path,
                         const SlotAsyncReady& slot_async_ready,
                         const glib::RefPtr<Cancellable>& cancellable,
                         const SlotProxyType& slot_proxy_type,
                         Flags flags);

  public:
    static auto
    create (const glib::RefPtr<Connection>& connection,
            const glib::ustring& name,
            const glib::ustring& object_path,
            const SlotAsyncReady& slot_async_ready,
            const glib::RefPtr<Cancellable>& cancellable = {},
            const SlotProxyType& slot_proxy_type = {},
            Flags flags = Flags::NONE) -> void;

    static auto
    create_finish (const glib::RefPtr<AsyncResult>& res)
        -> glib::RefPtr<gio::DBus::ObjectManagerClient>;

    static auto
    create_sync (const glib::RefPtr<Connection>& connection,
                 const glib::ustring& name,
                 const glib::ustring& object_path,
                 const glib::RefPtr<Cancellable>& cancellable = {},
                 const SlotProxyType& slot_proxy_type = {},
                 Flags flags = Flags::NONE)
        -> glib::RefPtr<gio::DBus::ObjectManagerClient>;

    static auto
    create_for_bus (BusType bus_type,
                    const glib::ustring& name,
                    const glib::ustring& object_path,
                    const SlotAsyncReady& slot_async_ready,
                    const glib::RefPtr<Cancellable>& cancellable = {},
                    const SlotProxyType& slot_proxy_type = {},
                    Flags flags = Flags::NONE) -> void;

    static auto
    create_for_bus_finish (const glib::RefPtr<AsyncResult>& res)
        -> glib::RefPtr<gio::DBus::ObjectManagerClient>;

    static auto
    create_for_bus_sync (BusType bus_type,
                         const glib::ustring& name,
                         const glib::ustring& object_path,
                         const glib::RefPtr<Cancellable>& cancellable = {},
                         const SlotProxyType& slot_proxy_type = {},
                         Flags flags = Flags::NONE)
        -> glib::RefPtr<gio::DBus::ObjectManagerClient>;

    auto
    get_connection () -> glib::RefPtr<Connection>;

    auto
    get_connection () const -> glib::RefPtr<const Connection>;

    auto
    get_flags () const -> Flags;

    auto
    get_name () const -> glib::ustring;

    auto
    get_name_owner () const -> glib::ustring;

    auto
    property_connection () const
        -> glib::PropertyProxy_ReadOnly<glib::RefPtr<Connection>>;

    auto
    property_flags () const -> glib::PropertyProxy_ReadOnly<Flags>;

    auto
    property_object_path () const
        -> glib::PropertyProxy_ReadOnly<glib::ustring>;

    auto
    property_name () const -> glib::PropertyProxy_ReadOnly<glib::ustring>;

    auto
    property_name_owner () const -> glib::PropertyProxy_ReadOnly<glib::ustring>;

    auto
    signal_interface_proxy_signal ()
        -> glib::SignalProxy<void (const glib::RefPtr<gio::DBus::ObjectProxy>&,
                                   const glib::RefPtr<gio::DBus::Proxy>&,
                                   const glib::ustring&,
                                   const glib::ustring&,
                                   const glib::VariantContainerBase&)>;

    using MapChangedProperties = std::map<glib::ustring, glib::VariantBase>;

    auto
    signal_interface_proxy_properties_changed ()
        -> glib::SignalProxy<void (const glib::RefPtr<gio::DBus::ObjectProxy>&,
                                   const glib::RefPtr<gio::DBus::Proxy>&,
                                   const MapChangedProperties&,
                                   const std::vector<glib::ustring>&)>;

  public:
  public:
  protected:
    virtual auto
    on_interface_proxy_signal (
        const glib::RefPtr<gio::DBus::ObjectProxy>& object_proxy,
        const glib::RefPtr<gio::DBus::Proxy>& interface_proxy,
        const glib::ustring& sender_name,
        const glib::ustring& signal_name,
        const glib::VariantContainerBase& parameters) -> void;

    virtual auto
    on_interface_proxy_properties_changed (
        const glib::RefPtr<gio::DBus::ObjectProxy>& object_proxy,
        const glib::RefPtr<gio::DBus::Proxy>& interface_proxy,
        const MapChangedProperties& changed_properties,
        const std::vector<glib::ustring>& invalidated_properties) -> void;
  };

} // namespace gio::DBus

namespace gio::DBus
{

  inline auto
  operator| (ObjectManagerClient::Flags lhs, ObjectManagerClient::Flags rhs) -> ObjectManagerClient::Flags
  {
    return static_cast<ObjectManagerClient::Flags> (
        static_cast<unsigned> (lhs) | static_cast<unsigned> (rhs));
  }

  inline auto
  operator& (ObjectManagerClient::Flags lhs, ObjectManagerClient::Flags rhs) -> ObjectManagerClient::Flags
  {
    return static_cast<ObjectManagerClient::Flags> (
        static_cast<unsigned> (lhs) & static_cast<unsigned> (rhs));
  }

  inline auto
  operator^ (ObjectManagerClient::Flags lhs, ObjectManagerClient::Flags rhs) -> ObjectManagerClient::Flags
  {
    return static_cast<ObjectManagerClient::Flags> (
        static_cast<unsigned> (lhs) ^ static_cast<unsigned> (rhs));
  }

  inline auto
  operator~(ObjectManagerClient::Flags flags) -> ObjectManagerClient::Flags
  {
    return static_cast<ObjectManagerClient::Flags> (
        ~static_cast<unsigned> (flags));
  }

  inline auto
  operator|= (ObjectManagerClient::Flags& lhs, ObjectManagerClient::Flags rhs) -> ObjectManagerClient::Flags&
  {
    return (lhs = static_cast<ObjectManagerClient::Flags> (
                static_cast<unsigned> (lhs) | static_cast<unsigned> (rhs)));
  }

  inline auto
  operator&= (ObjectManagerClient::Flags& lhs, ObjectManagerClient::Flags rhs) -> ObjectManagerClient::Flags&
  {
    return (lhs = static_cast<ObjectManagerClient::Flags> (
                static_cast<unsigned> (lhs) & static_cast<unsigned> (rhs)));
  }

  inline auto
  operator^= (ObjectManagerClient::Flags& lhs, ObjectManagerClient::Flags rhs) -> ObjectManagerClient::Flags&
  {
    return (lhs = static_cast<ObjectManagerClient::Flags> (
                static_cast<unsigned> (lhs) ^ static_cast<unsigned> (rhs)));
  }
} // namespace gio::DBus

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace glib
{

  template <>
  class LIBMM_GIO_SYMEXPORT Value<gio::DBus::ObjectManagerClient::Flags>
    : public glib::Value_Flags<gio::DBus::ObjectManagerClient::Flags>
  {
  public:
    static auto
    value_type () -> GType G_GNUC_CONST;
  };

} // namespace glib
#endif

namespace glib
{

  LIBMM_GIO_SYMEXPORT
  auto
  wrap (GDBusObjectManagerClient* object, bool take_copy = false) -> glib::RefPtr<gio::DBus::ObjectManagerClient>;
} // namespace glib

#endif
