// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GIOMM_TLSCLIENTCONNECTION_H
#define _GIOMM_TLSCLIENTCONNECTION_H

#include <libmm/glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm/gio/enums.hxx>
#include <libmm/gio/iostream.hxx>
#include <libmm/glib/interface.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
typedef struct _GTlsClientConnectionInterface GTlsClientConnectionInterface;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GTlsClientConnection = struct _GTlsClientConnection;
using GTlsClientConnectionClass = struct _GTlsClientConnectionClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace gio
{
  class LIBMM_GIO_SYMEXPORT TlsClientConnection_Class;
}
#endif

namespace glib
{
  class LIBMM_GLIB_SYMEXPORT ByteArray;
}

namespace gio
{

  class LIBMM_GIO_SYMEXPORT SocketConnectable;
  class LIBMM_GIO_SYMEXPORT TlsClientConnectionImpl;

  class LIBMM_GIO_SYMEXPORT TlsClientConnection : public glib::Interface
  {
#ifndef DOXYGEN_SHOULD_SKIP_THIS

  public:
    using CppObjectType = TlsClientConnection;
    using CppClassType = TlsClientConnection_Class;
    using BaseObjectType = GTlsClientConnection;
    using BaseClassType = GTlsClientConnectionInterface;

    TlsClientConnection (const TlsClientConnection&) = delete;
    auto
    operator= (const TlsClientConnection&) -> TlsClientConnection& = delete;

  private:
    friend class TlsClientConnection_Class;
    static CppClassType tlsclientconnection_class_;

#endif
  protected:
    TlsClientConnection ();

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    explicit TlsClientConnection (const glib::Interface_Class& interface_class);

  public:
    explicit TlsClientConnection (GTlsClientConnection* castitem);

  protected:
#endif

  public:
    TlsClientConnection (TlsClientConnection&& src) noexcept;
    auto
    operator= (TlsClientConnection&& src) noexcept -> TlsClientConnection&;

    ~TlsClientConnection () noexcept override;

    static auto
    add_interface (GType gtype_implementer) -> void;

    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS
    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GTlsClientConnection*
    {
      return reinterpret_cast<GTlsClientConnection*> (gobject_);
    }

    auto
    gobj () const -> const GTlsClientConnection*
    {
      return reinterpret_cast<GTlsClientConnection*> (gobject_);
    }

  private:
  public:
    static auto
    create (const glib::RefPtr<IOStream>& base_io_stream,
            const glib::RefPtr<const SocketConnectable>& server_identity)
        -> glib::RefPtr<TlsClientConnectionImpl>;

    static auto
    create (const glib::RefPtr<IOStream>& base_io_stream)
        -> glib::RefPtr<TlsClientConnectionImpl>;

    auto
    set_server_identity (const glib::RefPtr<SocketConnectable>& identity)
        -> void;

    auto
    get_server_identity () -> glib::RefPtr<SocketConnectable>;

    auto
    get_server_identity () const -> glib::RefPtr<const SocketConnectable>;

#ifndef GIOMM_DISABLE_DEPRECATED

    auto
    set_validation_flags (TlsCertificateFlags flags) -> void;
#endif

#ifndef GIOMM_DISABLE_DEPRECATED

    auto
    get_validation_flags () const -> TlsCertificateFlags;
#endif

    auto
    get_accepted_cas () -> std::vector<glib::RefPtr<glib::ByteArray>>;

    auto
    get_accepted_cas () const
        -> std::vector<glib::RefPtr<const glib::ByteArray>>;

    auto
    copy_session_state (const glib::RefPtr<TlsClientConnection>& source)
        -> void;

    auto
    property_server_identity ()
        -> glib::PropertyProxy<glib::RefPtr<SocketConnectable>>;

    auto
    property_server_identity () const
        -> glib::PropertyProxy_ReadOnly<glib::RefPtr<SocketConnectable>>;

#ifndef GIOMM_DISABLE_DEPRECATED

    auto
    property_validation_flags () -> glib::PropertyProxy<TlsCertificateFlags>;

    auto
    property_validation_flags () const
        -> glib::PropertyProxy_ReadOnly<TlsCertificateFlags>;

#endif

  public:
  public:
  protected:
  };

} // namespace gio

namespace glib
{

  LIBMM_GIO_SYMEXPORT
  auto
  wrap (GTlsClientConnection* object, bool take_copy = false) -> glib::RefPtr<gio::TlsClientConnection>;

} // namespace glib

#endif
