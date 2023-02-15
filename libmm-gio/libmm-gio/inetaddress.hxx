// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GIOMM_INETADDRESS_H
#define _GIOMM_INETADDRESS_H

#include <libmm-gio/gioconfig.hxx>

#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm-gio/enums.hxx>
#include <libmm-glib/object.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GInetAddress = struct _GInetAddress;
using GInetAddressClass = struct _GInetAddressClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gio
{
  class GIOMM_API InetAddress_Class;
}
#endif

namespace Gio
{

  class GIOMM_API InetAddress : public Glib::Object
  {
#ifndef DOXYGEN_SHOULD_SKIP_THIS

  public:
    using CppObjectType = InetAddress;
    using CppClassType = InetAddress_Class;
    using BaseObjectType = GInetAddress;
    using BaseClassType = GInetAddressClass;

    InetAddress (const InetAddress&) = delete;
    auto
    operator= (const InetAddress&) -> InetAddress& = delete;

  private:
    friend class InetAddress_Class;
    static CppClassType inetaddress_class_;

  protected:
    explicit InetAddress (const Glib::ConstructParams& construct_params);
    explicit InetAddress (GInetAddress* castitem);

#endif

  public:
    InetAddress (InetAddress&& src) noexcept;
    auto
    operator= (InetAddress&& src) noexcept -> InetAddress&;

    ~InetAddress () noexcept override;

    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GInetAddress*
    {
      return reinterpret_cast<GInetAddress*> (gobject_);
    }

    auto
    gobj () const -> const GInetAddress*
    {
      return reinterpret_cast<GInetAddress*> (gobject_);
    }

    auto
    gobj_copy () -> GInetAddress*;

  private:
  protected:
    explicit InetAddress (const guint8* bytes, SocketFamily family);

  public:
    static auto
    create (const Glib::ustring& string) -> Glib::RefPtr<InetAddress>;

    static auto
    create (const guint8* bytes, SocketFamily family)
        -> Glib::RefPtr<InetAddress>;

    static auto
    create_any (SocketFamily family) -> Glib::RefPtr<InetAddress>;
    static auto
    create_loopback (SocketFamily family) -> Glib::RefPtr<InetAddress>;

    auto
    address_equal (const Glib::RefPtr<const InetAddress>& other_address) const
        -> bool;

    auto
    to_bytes () const -> const guint8*;

    auto
    to_string () const -> Glib::ustring;

    auto
    get_family () const -> SocketFamily;

    auto
    get_is_any () const -> bool;

    auto
    get_is_link_local () const -> bool;

    auto
    get_is_loopback () const -> bool;

    auto
    get_is_mc_global () const -> bool;

    auto
    get_is_mc_link_local () const -> bool;

    auto
    get_is_mc_node_local () const -> bool;

    auto
    get_is_mc_org_local () const -> bool;

    auto
    get_is_mc_site_local () const -> bool;

    auto
    get_is_multicast () const -> bool;

    auto
    get_is_site_local () const -> bool;

    auto
    get_native_size () const -> gsize;

    auto
    property_bytes () const -> Glib::PropertyProxy_ReadOnly<void*>;

    auto
    property_family () const -> Glib::PropertyProxy_ReadOnly<SocketFamily>;

    auto
    property_is_any () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_is_link_local () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_is_loopback () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_is_mc_global () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_is_mc_link_local () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_is_mc_node_local () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_is_mc_org_local () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_is_mc_site_local () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_is_multicast () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_is_site_local () const -> Glib::PropertyProxy_ReadOnly<bool>;

  public:
  public:
  protected:
  };

} // namespace Gio

namespace Glib
{

  GIOMM_API
  auto
  wrap (GInetAddress* object, bool take_copy = false) -> Glib::RefPtr<Gio::InetAddress>;
} // namespace Glib

#endif
