// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GIOMM_DBUSOBJECTMANAGERCLIENT_H
#define _GIOMM_DBUSOBJECTMANAGERCLIENT_H

#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm-gio/asyncinitable.hxx>
#include <libmm-gio/asyncresult.hxx>
#include <libmm-gio/dbusconnection.hxx>
#include <libmm-gio/dbusobjectmanager.hxx>
#include <libmm-gio/dbusobjectproxy.hxx>
#include <libmm-gio/dbusproxy.hxx>
#include <libmm-gio/initable.hxx>
#include <libmm-glib/object.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GDBusObjectManagerClient = struct _GDBusObjectManagerClient;
using GDBusObjectManagerClientClass = struct _GDBusObjectManagerClientClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gio::DBus
{
  class LIBMM_GIO_SYMEXPORT ObjectManagerClient_Class;
}
#endif

namespace Gio::DBus
{

  class LIBMM_GIO_SYMEXPORT ObjectManagerClient : public Glib::Object,
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
        const Glib::ConstructParams& construct_params);
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
        sigc::slot<GType (const Glib::RefPtr<Gio::DBus::ObjectManagerClient>&,
                          const Glib::ustring&,
                          const Glib::ustring&)>;

  protected:
    ObjectManagerClient (const Glib::RefPtr<Connection>& connection,
                         const Glib::ustring& name,
                         const Glib::ustring& object_path,
                         const SlotAsyncReady& slot_async_ready,
                         const Glib::RefPtr<Cancellable>& cancellable,
                         const SlotProxyType& slot_proxy_type,
                         Flags flags);

    ObjectManagerClient (BusType bus_type,
                         const Glib::ustring& name,
                         const Glib::ustring& object_path,
                         const SlotAsyncReady& slot_async_ready,
                         const Glib::RefPtr<Cancellable>& cancellable,
                         const SlotProxyType& slot_proxy_type,
                         Flags flags);

  public:
    static auto
    create (const Glib::RefPtr<Connection>& connection,
            const Glib::ustring& name,
            const Glib::ustring& object_path,
            const SlotAsyncReady& slot_async_ready,
            const Glib::RefPtr<Cancellable>& cancellable = {},
            const SlotProxyType& slot_proxy_type = {},
            Flags flags = Flags::NONE) -> void;

    static auto
    create_finish (const Glib::RefPtr<AsyncResult>& res)
        -> Glib::RefPtr<Gio::DBus::ObjectManagerClient>;

    static auto
    create_sync (const Glib::RefPtr<Connection>& connection,
                 const Glib::ustring& name,
                 const Glib::ustring& object_path,
                 const Glib::RefPtr<Cancellable>& cancellable = {},
                 const SlotProxyType& slot_proxy_type = {},
                 Flags flags = Flags::NONE)
        -> Glib::RefPtr<Gio::DBus::ObjectManagerClient>;

    static auto
    create_for_bus (BusType bus_type,
                    const Glib::ustring& name,
                    const Glib::ustring& object_path,
                    const SlotAsyncReady& slot_async_ready,
                    const Glib::RefPtr<Cancellable>& cancellable = {},
                    const SlotProxyType& slot_proxy_type = {},
                    Flags flags = Flags::NONE) -> void;

    static auto
    create_for_bus_finish (const Glib::RefPtr<AsyncResult>& res)
        -> Glib::RefPtr<Gio::DBus::ObjectManagerClient>;

    static auto
    create_for_bus_sync (BusType bus_type,
                         const Glib::ustring& name,
                         const Glib::ustring& object_path,
                         const Glib::RefPtr<Cancellable>& cancellable = {},
                         const SlotProxyType& slot_proxy_type = {},
                         Flags flags = Flags::NONE)
        -> Glib::RefPtr<Gio::DBus::ObjectManagerClient>;

    auto
    get_connection () -> Glib::RefPtr<Connection>;

    auto
    get_connection () const -> Glib::RefPtr<const Connection>;

    auto
    get_flags () const -> Flags;

    auto
    get_name () const -> Glib::ustring;

    auto
    get_name_owner () const -> Glib::ustring;

    auto
    property_connection () const
        -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<Connection>>;

    auto
    property_flags () const -> Glib::PropertyProxy_ReadOnly<Flags>;

    auto
    property_object_path () const
        -> Glib::PropertyProxy_ReadOnly<Glib::ustring>;

    auto
    property_name () const -> Glib::PropertyProxy_ReadOnly<Glib::ustring>;

    auto
    property_name_owner () const -> Glib::PropertyProxy_ReadOnly<Glib::ustring>;

    auto
    signal_interface_proxy_signal ()
        -> Glib::SignalProxy<void (const Glib::RefPtr<Gio::DBus::ObjectProxy>&,
                                   const Glib::RefPtr<Gio::DBus::Proxy>&,
                                   const Glib::ustring&,
                                   const Glib::ustring&,
                                   const Glib::VariantContainerBase&)>;

    using MapChangedProperties = std::map<Glib::ustring, Glib::VariantBase>;

    auto
    signal_interface_proxy_properties_changed ()
        -> Glib::SignalProxy<void (const Glib::RefPtr<Gio::DBus::ObjectProxy>&,
                                   const Glib::RefPtr<Gio::DBus::Proxy>&,
                                   const MapChangedProperties&,
                                   const std::vector<Glib::ustring>&)>;

  public:
  public:
  protected:
    virtual auto
    on_interface_proxy_signal (
        const Glib::RefPtr<Gio::DBus::ObjectProxy>& object_proxy,
        const Glib::RefPtr<Gio::DBus::Proxy>& interface_proxy,
        const Glib::ustring& sender_name,
        const Glib::ustring& signal_name,
        const Glib::VariantContainerBase& parameters) -> void;

    virtual auto
    on_interface_proxy_properties_changed (
        const Glib::RefPtr<Gio::DBus::ObjectProxy>& object_proxy,
        const Glib::RefPtr<Gio::DBus::Proxy>& interface_proxy,
        const MapChangedProperties& changed_properties,
        const std::vector<Glib::ustring>& invalidated_properties) -> void;
  };

} // namespace Gio::DBus

namespace Gio::DBus
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
} // namespace Gio::DBus

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

  template <>
  class LIBMM_GIO_SYMEXPORT Value<Gio::DBus::ObjectManagerClient::Flags>
    : public Glib::Value_Flags<Gio::DBus::ObjectManagerClient::Flags>
  {
  public:
    static auto
    value_type () -> GType G_GNUC_CONST;
  };

} // namespace Glib
#endif

namespace Glib
{

  LIBMM_GIO_SYMEXPORT
  auto
  wrap (GDBusObjectManagerClient* object, bool take_copy = false) -> Glib::RefPtr<Gio::DBus::ObjectManagerClient>;
} // namespace Glib

#endif
