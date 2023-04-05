// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GIOMM_TLSSERVERCONNECTION_H
#define _GIOMM_TLSSERVERCONNECTION_H

#include <libmm/glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm/gio/enums.hxx>
#include <libmm/gio/iostream.hxx>
#include <libmm/gio/tlscertificate.hxx>
#include <libmm/glib/interface.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
typedef struct _GTlsServerConnectionInterface GTlsServerConnectionInterface;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GTlsServerConnection = struct _GTlsServerConnection;
using GTlsServerConnectionClass = struct _GTlsServerConnectionClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace gio
{
  class LIBMM_GIO_SYMEXPORT TlsServerConnection_Class;
}
#endif

namespace gio
{

  class LIBMM_GIO_SYMEXPORT TlsServerConnectionImpl;

  class LIBMM_GIO_SYMEXPORT TlsServerConnection : public glib::Interface
  {
#ifndef DOXYGEN_SHOULD_SKIP_THIS

  public:
    using CppObjectType = TlsServerConnection;
    using CppClassType = TlsServerConnection_Class;
    using BaseObjectType = GTlsServerConnection;
    using BaseClassType = GTlsServerConnectionInterface;

    TlsServerConnection (const TlsServerConnection&) = delete;
    auto
    operator= (const TlsServerConnection&) -> TlsServerConnection& = delete;

  private:
    friend class TlsServerConnection_Class;
    static CppClassType tlsserverconnection_class_;

#endif
  protected:
    TlsServerConnection ();

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    explicit TlsServerConnection (const glib::Interface_Class& interface_class);

  public:
    explicit TlsServerConnection (GTlsServerConnection* castitem);

  protected:
#endif

  public:
    TlsServerConnection (TlsServerConnection&& src) noexcept;
    auto
    operator= (TlsServerConnection&& src) noexcept -> TlsServerConnection&;

    ~TlsServerConnection () noexcept override;

    static auto
    add_interface (GType gtype_implementer) -> void;

    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS
    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GTlsServerConnection*
    {
      return reinterpret_cast<GTlsServerConnection*> (gobject_);
    }

    auto
    gobj () const -> const GTlsServerConnection*
    {
      return reinterpret_cast<GTlsServerConnection*> (gobject_);
    }

  private:
  public:
    static auto
    create (const glib::RefPtr<IOStream>& base_io_stream,
            const glib::RefPtr<TlsCertificate>& certificate)
        -> glib::RefPtr<TlsServerConnectionImpl>;

    auto
    property_authentication_mode ()
        -> glib::PropertyProxy<TlsAuthenticationMode>;

    auto
    property_authentication_mode () const
        -> glib::PropertyProxy_ReadOnly<TlsAuthenticationMode>;

  public:
  public:
  protected:
  };

} // namespace gio

namespace glib
{

  LIBMM_GIO_SYMEXPORT
  auto
  wrap (GTlsServerConnection* object, bool take_copy = false) -> glib::RefPtr<gio::TlsServerConnection>;

} // namespace glib

#endif
