// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GIOMM_PROXYADDRESS_H
#define _GIOMM_PROXYADDRESS_H

#include <libmm/glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm/gio/inetsocketaddress.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GProxyAddress = struct _GProxyAddress;
using GProxyAddressClass = struct _GProxyAddressClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace gio
{
  class LIBMM_GIO_SYMEXPORT ProxyAddress_Class;
}
#endif

namespace gio
{

  class LIBMM_GIO_SYMEXPORT ProxyAddress : public InetSocketAddress
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
    explicit ProxyAddress (const glib::ConstructParams& construct_params);
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
    explicit ProxyAddress (const glib::RefPtr<InetAddress>& address,
                           guint16 port,
                           const glib::ustring& protocol,
                           const glib::ustring& destination_hostname,
                           guint16 destination_port,
                           const glib::ustring& username = {},
                           const glib::ustring& password = {});

  public:
    static auto
    create (const glib::RefPtr<InetAddress>& address,
            guint16 port,
            const glib::ustring& protocol,
            const glib::ustring& destination_hostname,
            guint16 destination_port,
            const glib::ustring& username = {},
            const glib::ustring& password = {}) -> glib::RefPtr<ProxyAddress>;

    auto
    get_protocol () const -> glib::ustring;

    auto
    get_destination_protocol () const -> glib::ustring;

    auto
    get_destination_hostname () const -> glib::ustring;

    auto
    get_destination_port () const -> guint16;

    auto
    get_username () const -> glib::ustring;

    auto
    get_password () const -> glib::ustring;

    auto
    get_uri () const -> glib::ustring;

    auto
    property_protocol () const -> glib::PropertyProxy_ReadOnly<glib::ustring>;

    auto
    property_destination_protocol () const
        -> glib::PropertyProxy_ReadOnly<glib::ustring>;

    auto
    property_destination_hostname () const
        -> glib::PropertyProxy_ReadOnly<glib::ustring>;

    auto
    property_destination_port () const -> glib::PropertyProxy_ReadOnly<guint>;

    auto
    property_username () const -> glib::PropertyProxy_ReadOnly<glib::ustring>;

    auto
    property_password () const -> glib::PropertyProxy_ReadOnly<glib::ustring>;

    auto
    property_uri () const -> glib::PropertyProxy_ReadOnly<glib::ustring>;

  public:
  public:
  protected:
  };

} // namespace gio

namespace glib
{

  LIBMM_GIO_SYMEXPORT
  auto
  wrap (GProxyAddress* object, bool take_copy = false) -> glib::RefPtr<gio::ProxyAddress>;
} // namespace glib

#endif
