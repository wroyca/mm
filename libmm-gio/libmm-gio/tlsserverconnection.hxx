
#ifndef _GIOMM_TLSSERVERCONNECTION_H
#define _GIOMM_TLSSERVERCONNECTION_H

#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm-gio/enums.hxx>
#include <libmm-gio/iostream.hxx>
#include <libmm-gio/tlscertificate.hxx>
#include <libmm-glib/interface.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
typedef struct _GTlsServerConnectionInterface GTlsServerConnectionInterface;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GTlsServerConnection = struct _GTlsServerConnection;
using GTlsServerConnectionClass = struct _GTlsServerConnectionClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gio
{
  class GIOMM_API TlsServerConnection_Class;
}
#endif

namespace Gio
{

  class GIOMM_API TlsServerConnectionImpl;

  class GIOMM_API TlsServerConnection : public Glib::Interface
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

    explicit TlsServerConnection (const Glib::Interface_Class& interface_class);

  public:
    explicit TlsServerConnection (GTlsServerConnection* castitem);

  protected:
#endif

  public:
    TlsServerConnection (TlsServerConnection&& src) noexcept;
    auto
    operator= (TlsServerConnection&& src) noexcept -> TlsServerConnection&;

    ~TlsServerConnection () noexcept override;

    static void
    add_interface (GType gtype_implementer);

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
    create (const Glib::RefPtr<IOStream>& base_io_stream,
            const Glib::RefPtr<TlsCertificate>& certificate)
        -> Glib::RefPtr<TlsServerConnectionImpl>;

    auto
    property_authentication_mode ()
        -> Glib::PropertyProxy<TlsAuthenticationMode>;

    auto
    property_authentication_mode () const
        -> Glib::PropertyProxy_ReadOnly<TlsAuthenticationMode>;

  public:
  public:
  protected:
  };

} // namespace Gio

namespace Glib
{

  GIOMM_API
  auto
  wrap (GTlsServerConnection* object, bool take_copy = false) -> Glib::RefPtr<Gio::TlsServerConnection>;

} // namespace Glib

#endif
