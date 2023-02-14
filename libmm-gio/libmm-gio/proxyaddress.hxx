
#ifndef _GIOMM_PROXYADDRESS_H
#define _GIOMM_PROXYADDRESS_H

#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm-gio/inetsocketaddress.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GProxyAddress = struct _GProxyAddress;
using GProxyAddressClass = struct _GProxyAddressClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gio
{
  class GIOMM_API ProxyAddress_Class;
}
#endif

namespace Gio
{

  class GIOMM_API ProxyAddress : public InetSocketAddress
  {
#ifndef DOXYGEN_SHOULD_SKIP_THIS

  public:
    using CppObjectType = ProxyAddress;
    using CppClassType = ProxyAddress_Class;
    using BaseObjectType = GProxyAddress;
    using BaseClassType = GProxyAddressClass;

    ProxyAddress (const ProxyAddress&) = delete;
    auto
    operator= (const ProxyAddress&) -> ProxyAddress& = delete;

  private:
    friend class ProxyAddress_Class;
    static CppClassType proxyaddress_class_;

  protected:
    explicit ProxyAddress (const Glib::ConstructParams& construct_params);
    explicit ProxyAddress (GProxyAddress* castitem);

#endif

  public:
    ProxyAddress (ProxyAddress&& src) noexcept;
    auto
    operator= (ProxyAddress&& src) noexcept -> ProxyAddress&;

    ~ProxyAddress () noexcept override;

    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GProxyAddress*
    {
      return reinterpret_cast<GProxyAddress*> (gobject_);
    }

    auto
    gobj () const -> const GProxyAddress*
    {
      return reinterpret_cast<GProxyAddress*> (gobject_);
    }

    auto
    gobj_copy () -> GProxyAddress*;

  private:
  protected:
    explicit ProxyAddress (const Glib::RefPtr<InetAddress>& address,
                           guint16 port,
                           const Glib::ustring& protocol,
                           const Glib::ustring& destination_hostname,
                           guint16 destination_port,
                           const Glib::ustring& username = {},
                           const Glib::ustring& password = {});

  public:
    static auto
    create (const Glib::RefPtr<InetAddress>& address,
            guint16 port,
            const Glib::ustring& protocol,
            const Glib::ustring& destination_hostname,
            guint16 destination_port,
            const Glib::ustring& username = {},
            const Glib::ustring& password = {}) -> Glib::RefPtr<ProxyAddress>;

    auto
    get_protocol () const -> Glib::ustring;

    auto
    get_destination_protocol () const -> Glib::ustring;

    auto
    get_destination_hostname () const -> Glib::ustring;

    auto
    get_destination_port () const -> guint16;

    auto
    get_username () const -> Glib::ustring;

    auto
    get_password () const -> Glib::ustring;

    auto
    get_uri () const -> Glib::ustring;

    auto
    property_protocol () const -> Glib::PropertyProxy_ReadOnly<Glib::ustring>;

    auto
    property_destination_protocol () const
        -> Glib::PropertyProxy_ReadOnly<Glib::ustring>;

    auto
    property_destination_hostname () const
        -> Glib::PropertyProxy_ReadOnly<Glib::ustring>;

    auto
    property_destination_port () const -> Glib::PropertyProxy_ReadOnly<guint>;

    auto
    property_username () const -> Glib::PropertyProxy_ReadOnly<Glib::ustring>;

    auto
    property_password () const -> Glib::PropertyProxy_ReadOnly<Glib::ustring>;

    auto
    property_uri () const -> Glib::PropertyProxy_ReadOnly<Glib::ustring>;

  public:
  public:
  protected:
  };

} // namespace Gio

namespace Glib
{

  GIOMM_API
  auto
  wrap (GProxyAddress* object, bool take_copy = false) -> Glib::RefPtr<Gio::ProxyAddress>;
} // namespace Glib

#endif
