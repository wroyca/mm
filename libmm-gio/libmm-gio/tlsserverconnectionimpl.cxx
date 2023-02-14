

#include <libmm-gio/tlsserverconnectionimpl.hxx>
#include <utility>

namespace Gio
{
  TlsServerConnectionImpl::TlsServerConnectionImpl (GTlsConnection* castitem)
    : ObjectBase (nullptr),
      TlsConnection (castitem)
  {
  }

  TlsServerConnectionImpl::TlsServerConnectionImpl (
      TlsServerConnectionImpl&& src) noexcept
    : TlsServerConnection (std::move (src)),
      TlsConnection (std::move (src))
  {
  }

  auto
  TlsServerConnectionImpl::operator= (TlsServerConnectionImpl&& src) noexcept -> TlsServerConnectionImpl&
  {
    TlsServerConnection::operator= (std::move (src));
    TlsConnection::operator= (std::move (src));
    return *this;
  }

  TlsServerConnectionImpl::~TlsServerConnectionImpl () noexcept = default;
} // namespace Gio
