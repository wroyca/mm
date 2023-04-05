// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/gio/tcpwrapperconnection.hxx>
#include <libmm/gio/tcpwrapperconnection_p.hxx>

#include <gio/gio.h>

namespace gio
{
}

namespace
{
}

namespace glib
{

  auto
  wrap (GTcpWrapperConnection* object, const bool take_copy) -> RefPtr<gio::TcpWrapperConnection>
  {
    return glib::make_refptr_for_instance<gio::TcpWrapperConnection> (
        dynamic_cast<gio::TcpWrapperConnection*> (
            wrap_auto ((GObject*) object, take_copy)));
  }

} // namespace glib

namespace gio
{

  auto
  TcpWrapperConnection_Class::init () -> const Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &TcpWrapperConnection_Class::class_init_function;

      register_derived_type (g_tcp_wrapper_connection_get_type ());
    }

    return *this;
  }

  auto
  TcpWrapperConnection_Class::class_init_function (void* g_class,
                                                   void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);
  }

  auto
  TcpWrapperConnection_Class::wrap_new (GObject* object) -> glib::ObjectBase*
  {
    return new TcpWrapperConnection ((GTcpWrapperConnection*) object);
  }

  auto
  TcpWrapperConnection::gobj_copy () -> GTcpWrapperConnection*
  {
    reference ();
    return gobj ();
  }

  TcpWrapperConnection::TcpWrapperConnection (
      const glib::ConstructParams& construct_params)
    : TcpConnection (construct_params)
  {
  }

  TcpWrapperConnection::TcpWrapperConnection (GTcpWrapperConnection* castitem)
    : TcpConnection ((GTcpConnection*) castitem)
  {
  }

  TcpWrapperConnection::TcpWrapperConnection (
      TcpWrapperConnection&& src) noexcept
    : TcpConnection (std::move (src))
  {
  }

  auto
  TcpWrapperConnection::operator= (TcpWrapperConnection&& src) noexcept -> TcpWrapperConnection&
  {
    TcpConnection::operator= (std::move (src));
    return *this;
  }

  TcpWrapperConnection::~TcpWrapperConnection () noexcept = default;

  TcpWrapperConnection::CppClassType
      TcpWrapperConnection::tcpwrapperconnection_class_;

  auto
  TcpWrapperConnection::get_type () -> GType
  {
    return tcpwrapperconnection_class_.init ().get_type ();
  }

  auto
  TcpWrapperConnection::get_base_type () -> GType
  {
    return g_tcp_wrapper_connection_get_type ();
  }

  TcpWrapperConnection::TcpWrapperConnection (
      const glib::RefPtr<IOStream>& base_io_stream,
      const glib::RefPtr<Socket>& socket)
    : ObjectBase (nullptr),
      TcpConnection (glib::ConstructParams (tcpwrapperconnection_class_.init (),
                                            "base_io_stream",
                                            glib::unwrap (base_io_stream),
                                            "socket",
                                            glib::unwrap (socket),
                                            nullptr))
  {
  }

  auto
  TcpWrapperConnection::get_base_io_stream () -> glib::RefPtr<IOStream>
  {
    auto retvalue =
        glib::wrap (g_tcp_wrapper_connection_get_base_io_stream (gobj ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  TcpWrapperConnection::get_base_io_stream () const -> glib::RefPtr<const IOStream>
  {
    return const_cast<TcpWrapperConnection*> (this)->get_base_io_stream ();
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<
          glib::RefPtr<IOStream>>::value,
      "Type glib::RefPtr<IOStream> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  TcpWrapperConnection::property_base_io_stream () const -> glib::PropertyProxy_ReadOnly<glib::RefPtr<IOStream>>
  {
    return {this, "base-io-stream"};
  }

} // namespace gio
