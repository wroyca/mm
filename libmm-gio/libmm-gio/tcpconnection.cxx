

#include <libmm-glib/mm-glib.hxx>

#include <libmm-gio/tcpconnection.hxx>
#include <libmm-gio/tcpconnection_p.hxx>

#include <gio/gio.h>

namespace Gio
{
}

namespace
{
}

namespace Glib
{

  auto
  wrap (GTcpConnection* object, const bool take_copy) -> RefPtr<Gio::TcpConnection>
  {
    return Glib::make_refptr_for_instance<Gio::TcpConnection> (
        dynamic_cast<Gio::TcpConnection*> (
            wrap_auto ((GObject*) object, take_copy)));
  }

} // namespace Glib

namespace Gio
{

  auto
  TcpConnection_Class::init () -> const Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &TcpConnection_Class::class_init_function;

      register_derived_type (g_tcp_connection_get_type ());
    }

    return *this;
  }

  auto
  TcpConnection_Class::class_init_function (void* g_class, void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);
  }

  auto
  TcpConnection_Class::wrap_new (GObject* object) -> Glib::ObjectBase*
  {
    return new TcpConnection ((GTcpConnection*) object);
  }

  auto
  TcpConnection::gobj_copy () -> GTcpConnection*
  {
    reference ();
    return gobj ();
  }

  TcpConnection::TcpConnection (const Glib::ConstructParams& construct_params)
    : SocketConnection (construct_params)
  {
  }

  TcpConnection::TcpConnection (GTcpConnection* castitem)
    : SocketConnection ((GSocketConnection*) castitem)
  {
  }

  TcpConnection::TcpConnection (TcpConnection&& src) noexcept
    : SocketConnection (std::move (src))
  {
  }

  auto
  TcpConnection::operator= (TcpConnection&& src) noexcept -> TcpConnection&
  {
    SocketConnection::operator= (std::move (src));
    return *this;
  }

  TcpConnection::~TcpConnection () noexcept = default;

  TcpConnection::CppClassType TcpConnection::tcpconnection_class_;

  auto
  TcpConnection::get_type () -> GType
  {
    return tcpconnection_class_.init ().get_type ();
  }

  auto
  TcpConnection::get_base_type () -> GType
  {
    return g_tcp_connection_get_type ();
  }

  auto
  TcpConnection::set_graceful_disconnect (const bool graceful_disconnect) -> void
  {
    g_tcp_connection_set_graceful_disconnect (gobj (), graceful_disconnect);
  }

  auto
  TcpConnection::get_graceful_disconnect () const -> bool
  {
    return g_tcp_connection_get_graceful_disconnect (
        const_cast<GTcpConnection*> (gobj ()));
  }

  auto
  TcpConnection::property_graceful_disconnect () -> Glib::PropertyProxy<bool>
  {
    return {this, "graceful-disconnect"};
  }

  auto
  TcpConnection::property_graceful_disconnect () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return {this, "graceful-disconnect"};
  }

} // namespace Gio
