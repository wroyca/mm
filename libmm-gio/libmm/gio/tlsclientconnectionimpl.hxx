// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GIOMM_TLSCLIENTCONNECTIONIMPL_H
#define _GIOMM_TLSCLIENTCONNECTIONIMPL_H

#include <libmm/gio/mm-gioconfig.hxx>
#include <libmm/gio/tlsclientconnection.hxx>
#include <libmm/gio/tlsconnection.hxx>

namespace gio
{

  class LIBMM_GIO_SYMEXPORT TlsClientConnectionImpl : public TlsClientConnection,
                                            public TlsConnection
  {
  private:
    TlsClientConnectionImpl (const TlsClientConnectionImpl&) = delete;
    auto
    operator= (const TlsClientConnectionImpl&)
        -> TlsClientConnectionImpl& = delete;

    friend class TlsConnection_Class;

  protected:
    explicit TlsClientConnectionImpl (GTlsConnection* castitem);

  public:
    TlsClientConnectionImpl (TlsClientConnectionImpl&& src) noexcept;
    auto
    operator= (TlsClientConnectionImpl&& src) noexcept
        -> TlsClientConnectionImpl&;

    ~TlsClientConnectionImpl () noexcept override;
  };

} // namespace gio

#endif
