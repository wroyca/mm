
#ifndef _GIOMM_TCPCONNECTION_H
#define _GIOMM_TCPCONNECTION_H

#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm-gio/socketconnection.hxx>
#include <libmm-glib/object.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GTcpConnection = struct _GTcpConnection;
using GTcpConnectionClass = struct _GTcpConnectionClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gio
{
  class GIOMM_API TcpConnection_Class;
}
#endif

namespace Gio
{

  class GIOMM_API TcpConnection : public Gio::SocketConnection
  {
#ifndef DOXYGEN_SHOULD_SKIP_THIS

  public:
    using CppObjectType = TcpConnection;
    using CppClassType = TcpConnection_Class;
    using BaseObjectType = GTcpConnection;
    using BaseClassType = GTcpConnectionClass;

    TcpConnection (const TcpConnection&) = delete;
    auto
    operator= (const TcpConnection&) -> TcpConnection& = delete;

  private:
    friend class TcpConnection_Class;
    static CppClassType tcpconnection_class_;

  protected:
    explicit TcpConnection (const Glib::ConstructParams& construct_params);
    explicit TcpConnection (GTcpConnection* castitem);

#endif

  public:
    TcpConnection (TcpConnection&& src) noexcept;
    auto
    operator= (TcpConnection&& src) noexcept -> TcpConnection&;

    ~TcpConnection () noexcept override;

    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GTcpConnection*
    {
      return reinterpret_cast<GTcpConnection*> (gobject_);
    }

    auto
    gobj () const -> const GTcpConnection*
    {
      return reinterpret_cast<GTcpConnection*> (gobject_);
    }

    auto
    gobj_copy () -> GTcpConnection*;

  private:
  public:
    void
    set_graceful_disconnect (bool graceful_disconnect);

    auto
    get_graceful_disconnect () const -> bool;

    auto
    property_graceful_disconnect () -> Glib::PropertyProxy<bool>;

    auto
    property_graceful_disconnect () const -> Glib::PropertyProxy_ReadOnly<bool>;

  public:
  public:
  protected:
  };

} // namespace Gio

namespace Glib
{

  GIOMM_API
  auto
  wrap (GTcpConnection* object, bool take_copy = false) -> Glib::RefPtr<Gio::TcpConnection>;
} // namespace Glib

#endif
