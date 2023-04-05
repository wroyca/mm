// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/gio/tlsserverconnectionimpl.hxx>
#include <utility>

namespace gio
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
} // namespace gio
