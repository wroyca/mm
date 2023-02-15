// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GIOMM_DBUSSERVER_H
#define _GIOMM_DBUSSERVER_H

#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm-gio/dbusauthobserver.hxx>
#include <libmm-gio/dbusconnection.hxx>
#include <libmm-gio/initable.hxx>
#include <libmm-glib/object.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GDBusServer = struct _GDBusServer;
using GDBusServerClass = struct _GDBusServerClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gio::DBus
{
  class LIBMM_GIO_SYMEXPORT Server_Class;
}
#endif

namespace Gio::DBus
{

  class LIBMM_GIO_SYMEXPORT Server : public Glib::Object,
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
    explicit Server (const Glib::ConstructParams& construct_params);
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
            const Glib::RefPtr<AuthObserver>& observer,
            const Glib::RefPtr<Cancellable>& cancellable,
            Flags flags);

    Server (const std::string& address,
            const std::string& guid,
            const Glib::RefPtr<Cancellable>& cancellable,
            Flags flags);

    Server (const std::string& address,
            const std::string& guid,
            const Glib::RefPtr<AuthObserver>& observer,
            Flags flags);

    Server (const std::string& address, const std::string& guid, Flags flags);

  public:
    static auto
    create_sync (const std::string& address,
                 const std::string& guid,
                 const Glib::RefPtr<AuthObserver>& observer,
                 const Glib::RefPtr<Cancellable>& cancellable,
                 Flags flags = Gio::DBus::Server::Flags::NONE)
        -> Glib::RefPtr<Server>;

    static auto
    create_sync (const std::string& address,
                 const std::string& guid,
                 const Glib::RefPtr<Cancellable>& cancellable,
                 Flags flags = Gio::DBus::Server::Flags::NONE)
        -> Glib::RefPtr<Server>;

    static auto
    create_sync (const std::string& address,
                 const std::string& guid,
                 const Glib::RefPtr<AuthObserver>& observer,
                 Flags flags = Gio::DBus::Server::Flags::NONE)
        -> Glib::RefPtr<Server>;

    static auto
    create_sync (const std::string& address,
                 const std::string& guid,
                 Flags flags = Gio::DBus::Server::Flags::NONE)
        -> Glib::RefPtr<Server>;

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
    property_active () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_address () const -> Glib::PropertyProxy_ReadOnly<std::string>;

    auto
    property_authentication_observer () const
        -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<AuthObserver>>;

    auto
    property_client_address () const
        -> Glib::PropertyProxy_ReadOnly<std::string>;

    auto
    property_flags () const -> Glib::PropertyProxy_ReadOnly<Flags>;

    auto
    property_guid () const -> Glib::PropertyProxy_ReadOnly<std::string>;

    auto
    signal_new_connection ()
        -> Glib::SignalProxy<bool (const Glib::RefPtr<Connection>&)>;

  public:
  public:
  protected:
  };

} // namespace Gio::DBus

namespace Gio::DBus
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
} // namespace Gio::DBus

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

  template <>
  class LIBMM_GIO_SYMEXPORT Value<Gio::DBus::Server::Flags>
    : public Glib::Value_Flags<Gio::DBus::Server::Flags>
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
  wrap (GDBusServer* object, bool take_copy = false) -> Glib::RefPtr<Gio::DBus::Server>;
} // namespace Glib

#endif
