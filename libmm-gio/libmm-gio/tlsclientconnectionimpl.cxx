

#include <libmm-gio/tlsclientconnectionimpl.hxx>
#include <utility>

namespace Gio
{
  TlsClientConnectionImpl::TlsClientConnectionImpl (GTlsConnection* castitem)
    : ObjectBase (nullptr),
      TlsConnection (castitem)
  {
  }

  TlsClientConnectionImpl::TlsClientConnectionImpl (
      TlsClientConnectionImpl&& src) noexcept
    : TlsClientConnection (std::move (src)),
      TlsConnection (std::move (src))
  {
  }

  auto
  TlsClientConnectionImpl::operator= (TlsClientConnectionImpl&& src) noexcept -> TlsClientConnectionImpl&
  {
    TlsClientConnection::operator= (std::move (src));
    TlsConnection::operator= (std::move (src));
    return *this;
  }

  TlsClientConnectionImpl::~TlsClientConnectionImpl () noexcept = default;
} // namespace Gio
