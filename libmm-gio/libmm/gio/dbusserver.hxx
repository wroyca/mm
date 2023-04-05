// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GIOMM_DBUSSERVER_H
#define _GIOMM_DBUSSERVER_H

#include <libmm/glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm/gio/dbusauthobserver.hxx>
#include <libmm/gio/dbusconnection.hxx>
#include <libmm/gio/initable.hxx>
#include <libmm/glib/object.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GDBusServer = struct _GDBusServer;
using GDBusServerClass = struct _GDBusServerClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace gio::DBus
{
  class LIBMM_GIO_SYMEXPORT Server_Class;
}
#endif

namespace gio::DBus
{

  class LIBMM_GIO_SYMEXPORT Server : public glib::Object,
                           public Initable
  {
#ifndef DOXYGEN_SHOULD_SKIP_THIS

  public:
    using CppObjectType = Server;
    using CppClassType = Server_Class;
    using BaseObjectType = GDBusServer;
    using BaseClassType = GDBusServerClass;

    Server (const Server&) = delete;
    auto
    operator= (const Server&) -> Server& = delete;

  private:
    friend class Server_Class;
    static CppClassType server_class_;

  protected:
    explicit Server (const glib::ConstructParams& construct_params);
    explicit Server (GDBusServer* castitem);

#endif

  public:
    Server (Server&& src) noexcept;
    auto
    operator= (Server&& src) noexcept -> Server&;

    ~Server () noexcept override;

    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GDBusServer*
    {
      return reinterpret_cast<GDBusServer*> (gobject_);
    }

    auto
    gobj () const -> const GDBusServer*
    {
      return reinterpret_cast<GDBusServer*> (gobject_);
    }

    auto
    gobj_copy () -> GDBusServer*;

  private:
  public:
    enum class Flags
    {
      NONE = 0x0,
      RUN_IN_THREAD = (1 << 0),
      AUTHENTICATION_ALLOW_ANONYMOUS = (1 << 1),
      AUTHENTICATION_REQUIRE_SAME_USER = (1 << 2)
    };

  protected:
    Server (const std::string& address,
            const std::string& guid,
            const glib::RefPtr<AuthObserver>& observer,
            const glib::RefPtr<Cancellable>& cancellable,
            Flags flags);

    Server (const std::string& address,
            const std::string& guid,
            const glib::RefPtr<Cancellable>& cancellable,
            Flags flags);

    Server (const std::string& address,
            const std::string& guid,
            const glib::RefPtr<AuthObserver>& observer,
            Flags flags);

    Server (const std::string& address, const std::string& guid, Flags flags);

  public:
    static auto
    create_sync (const std::string& address,
                 const std::string& guid,
                 const glib::RefPtr<AuthObserver>& observer,
                 const glib::RefPtr<Cancellable>& cancellable,
                 Flags flags = gio::DBus::Server::Flags::NONE)
        -> glib::RefPtr<Server>;

    static auto
    create_sync (const std::string& address,
                 const std::string& guid,
                 const glib::RefPtr<Cancellable>& cancellable,
                 Flags flags = gio::DBus::Server::Flags::NONE)
        -> glib::RefPtr<Server>;

    static auto
    create_sync (const std::string& address,
                 const std::string& guid,
                 const glib::RefPtr<AuthObserver>& observer,
                 Flags flags = gio::DBus::Server::Flags::NONE)
        -> glib::RefPtr<Server>;

    static auto
    create_sync (const std::string& address,
                 const std::string& guid,
                 Flags flags = gio::DBus::Server::Flags::NONE)
        -> glib::RefPtr<Server>;

    auto
    start () -> void;

    auto
    stop () -> void;

    auto
    is_active () const -> bool;

    auto
    get_guid () const -> std::string;

    auto
    get_flags () const -> Flags;

    auto
    get_client_address () const -> std::string;

    auto
    property_active () const -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_address () const -> glib::PropertyProxy_ReadOnly<std::string>;

    auto
    property_authentication_observer () const
        -> glib::PropertyProxy_ReadOnly<glib::RefPtr<AuthObserver>>;

    auto
    property_client_address () const
        -> glib::PropertyProxy_ReadOnly<std::string>;

    auto
    property_flags () const -> glib::PropertyProxy_ReadOnly<Flags>;

    auto
    property_guid () const -> glib::PropertyProxy_ReadOnly<std::string>;

    auto
    signal_new_connection ()
        -> glib::SignalProxy<bool (const glib::RefPtr<Connection>&)>;

  public:
  public:
  protected:
  };

} // namespace gio::DBus

namespace gio::DBus
{

  inline auto
  operator| (Server::Flags lhs, Server::Flags rhs) -> Server::Flags
  {
    return static_cast<Server::Flags> (static_cast<unsigned> (lhs) |
                                       static_cast<unsigned> (rhs));
  }

  inline auto
  operator& (Server::Flags lhs, Server::Flags rhs) -> Server::Flags
  {
    return static_cast<Server::Flags> (static_cast<unsigned> (lhs) &
                                       static_cast<unsigned> (rhs));
  }

  inline auto
  operator^ (Server::Flags lhs, Server::Flags rhs) -> Server::Flags
  {
    return static_cast<Server::Flags> (static_cast<unsigned> (lhs) ^
                                       static_cast<unsigned> (rhs));
  }

  inline auto
  operator~(Server::Flags flags) -> Server::Flags
  {
    return static_cast<Server::Flags> (~static_cast<unsigned> (flags));
  }

  inline auto
  operator|= (Server::Flags& lhs, Server::Flags rhs) -> Server::Flags&
  {
    return (lhs = static_cast<Server::Flags> (static_cast<unsigned> (lhs) |
                                              static_cast<unsigned> (rhs)));
  }

  inline auto
  operator&= (Server::Flags& lhs, Server::Flags rhs) -> Server::Flags&
  {
    return (lhs = static_cast<Server::Flags> (static_cast<unsigned> (lhs) &
                                              static_cast<unsigned> (rhs)));
  }

  inline auto
  operator^= (Server::Flags& lhs, Server::Flags rhs) -> Server::Flags&
  {
    return (lhs = static_cast<Server::Flags> (static_cast<unsigned> (lhs) ^
                                              static_cast<unsigned> (rhs)));
  }
} // namespace gio::DBus

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace glib
{

  template <>
  class LIBMM_GIO_SYMEXPORT Value<gio::DBus::Server::Flags>
    : public glib::Value_Flags<gio::DBus::Server::Flags>
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
  wrap (GDBusServer* object, bool take_copy = false) -> glib::RefPtr<gio::DBus::Server>;
} // namespace glib

#endif
