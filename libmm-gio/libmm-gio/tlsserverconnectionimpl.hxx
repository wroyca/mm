// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GIOMM_TLSSERVERCONNECTIONIMPL_H
#define _GIOMM_TLSSERVERCONNECTIONIMPL_H

#include <libmm-gio/gioconfig.hxx>
#include <libmm-gio/tlsconnection.hxx>
#include <libmm-gio/tlsserverconnection.hxx>

namespace Gio
{

  class GIOMM_API TlsServerConnectionImpl : public TlsServerConnection,
                                            public TlsConnection
  {
  private:
    TlsServerConnectionImpl (const TlsServerConnectionImpl&) = delete;
    auto
    operator= (const TlsServerConnectionImpl&)
        -> TlsServerConnectionImpl& = delete;

    friend class TlsConnection_Class;

  protected:
    explicit TlsServerConnectionImpl (GTlsConnection* castitem);

  public:
    TlsServerConnectionImpl (TlsServerConnectionImpl&& src) noexcept;
    auto
    operator= (TlsServerConnectionImpl&& src) noexcept
        -> TlsServerConnectionImpl&;

    ~TlsServerConnectionImpl () noexcept override;
  };

} // namespace Gio

#endif
