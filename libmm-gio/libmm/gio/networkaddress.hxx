// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GIOMM_NETWORKADDRESS_H
#define _GIOMM_NETWORKADDRESS_H

#include <libmm/glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm/gio/socketconnectable.hxx>
#include <libmm/glib/object.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GNetworkAddress = struct _GNetworkAddress;
using GNetworkAddressClass = struct _GNetworkAddressClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace gio
{
  class LIBMM_GIO_SYMEXPORT NetworkAddress_Class;
}
#endif

namespace gio
{

  class LIBMM_GIO_SYMEXPORT NetworkAddress : public glib::Object,
                                   public SocketConnectable
  {
#ifndef DOXYGEN_SHOULD_SKIP_THIS

  public:
    using CppObjectType = NetworkAddress;
    using CppClassType = NetworkAddress_Class;
    using BaseObjectType = GNetworkAddress;
    using BaseClassType = GNetworkAddressClass;

    NetworkAddress (const NetworkAddress&) = delete;
    auto
    operator= (const NetworkAddress&) -> NetworkAddress& = delete;

  private:
    friend class NetworkAddress_Class;
    static CppClassType networkaddress_class_;

  protected:
    explicit NetworkAddress (const glib::ConstructParams& construct_params);
    explicit NetworkAddress (GNetworkAddress* castitem);

#endif

  public:
    NetworkAddress (NetworkAddress&& src) noexcept;
    auto
    operator= (NetworkAddress&& src) noexcept -> NetworkAddress&;

    ~NetworkAddress () noexcept override;

    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GNetworkAddress*
    {
      return reinterpret_cast<GNetworkAddress*> (gobject_);
    }

    auto
    gobj () const -> const GNetworkAddress*
    {
      return reinterpret_cast<GNetworkAddress*> (gobject_);
    }

    auto
    gobj_copy () -> GNetworkAddress*;

  private:
    explicit NetworkAddress (const std::string& hostname, guint16 port);

  public:
    static auto
    create (const std::string& hostname, guint16 port)
        -> glib::RefPtr<NetworkAddress>;

    auto
    get_hostname () const -> std::string;

    auto
    get_port () const -> guint16;

    auto
    get_scheme () const -> std::string;

    static auto
    parse (const std::string& host_and_port, guint16 default_port)
        -> glib::RefPtr<NetworkAddress>;

    auto
    property_hostname () const -> glib::PropertyProxy_ReadOnly<std::string>;

    auto
    property_port () const -> glib::PropertyProxy_ReadOnly<guint>;

    auto
    property_scheme () const -> glib::PropertyProxy_ReadOnly<std::string>;

  public:
  public:
  protected:
  };

} // namespace gio

namespace glib
{

  LIBMM_GIO_SYMEXPORT
  auto
  wrap (GNetworkAddress* object, bool take_copy = false) -> glib::RefPtr<gio::NetworkAddress>;
} // namespace glib

#endif
