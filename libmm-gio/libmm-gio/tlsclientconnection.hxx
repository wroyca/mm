
#ifndef _GIOMM_TLSCLIENTCONNECTION_H
#define _GIOMM_TLSCLIENTCONNECTION_H

#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm-gio/enums.hxx>
#include <libmm-gio/iostream.hxx>
#include <libmm-glib/interface.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
typedef struct _GTlsClientConnectionInterface GTlsClientConnectionInterface;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GTlsClientConnection = struct _GTlsClientConnection;
using GTlsClientConnectionClass = struct _GTlsClientConnectionClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gio
{
  class GIOMM_API TlsClientConnection_Class;
}
#endif

namespace Glib
{
  class GLIBMM_API ByteArray;
}

namespace Gio
{

  class GIOMM_API SocketConnectable;
  class GIOMM_API TlsClientConnectionImpl;

  class GIOMM_API TlsClientConnection : public Glib::Interface
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

    explicit TlsClientConnection (const Glib::Interface_Class& interface_class);

  public:
    explicit TlsClientConnection (GTlsClientConnection* castitem);

  protected:
#endif

  public:
    TlsClientConnection (TlsClientConnection&& src) noexcept;
    auto
    operator= (TlsClientConnection&& src) noexcept -> TlsClientConnection&;

    ~TlsClientConnection () noexcept override;

    static void
    add_interface (GType gtype_implementer);

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
    create (const Glib::RefPtr<IOStream>& base_io_stream,
            const Glib::RefPtr<const SocketConnectable>& server_identity)
        -> Glib::RefPtr<TlsClientConnectionImpl>;

    static auto
    create (const Glib::RefPtr<IOStream>& base_io_stream)
        -> Glib::RefPtr<TlsClientConnectionImpl>;

    void
    set_server_identity (const Glib::RefPtr<SocketConnectable>& identity);

    auto
    get_server_identity () -> Glib::RefPtr<SocketConnectable>;

    auto
    get_server_identity () const -> Glib::RefPtr<const SocketConnectable>;

#ifndef GIOMM_DISABLE_DEPRECATED

    void
    set_validation_flags (TlsCertificateFlags flags);
#endif

#ifndef GIOMM_DISABLE_DEPRECATED

    auto
    get_validation_flags () const -> TlsCertificateFlags;
#endif

    auto
    get_accepted_cas () -> std::vector<Glib::RefPtr<Glib::ByteArray>>;

    auto
    get_accepted_cas () const
        -> std::vector<Glib::RefPtr<const Glib::ByteArray>>;

    void
    copy_session_state (const Glib::RefPtr<TlsClientConnection>& source);

    auto
    property_server_identity ()
        -> Glib::PropertyProxy<Glib::RefPtr<SocketConnectable>>;

    auto
    property_server_identity () const
        -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<SocketConnectable>>;

#ifndef GIOMM_DISABLE_DEPRECATED

    auto
    property_validation_flags () -> Glib::PropertyProxy<TlsCertificateFlags>;

    auto
    property_validation_flags () const
        -> Glib::PropertyProxy_ReadOnly<TlsCertificateFlags>;

#endif

  public:
  public:
  protected:
  };

} // namespace Gio

namespace Glib
{

  GIOMM_API
  auto
  wrap (GTlsClientConnection* object, bool take_copy = false) -> Glib::RefPtr<Gio::TlsClientConnection>;

} // namespace Glib

#endif
