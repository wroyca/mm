// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GIOMM_INETSOCKETADDRESS_H
#define _GIOMM_INETSOCKETADDRESS_H

#include <libmm/glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm/gio/enums.hxx>
#include <libmm/gio/inetaddress.hxx>
#include <libmm/gio/socketaddress.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GInetSocketAddress = struct _GInetSocketAddress;
using GInetSocketAddressClass = struct _GInetSocketAddressClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace gio
{
  class LIBMM_GIO_SYMEXPORT InetSocketAddress_Class;
}
#endif

namespace gio
{

  class LIBMM_GIO_SYMEXPORT InetSocketAddress : public SocketAddress
  {
#ifndef DOXYGEN_SHOULD_SKIP_THIS

  public:
    using CppObjectType = InetSocketAddress;
    using CppClassType = InetSocketAddress_Class;
    using BaseObjectType = GInetSocketAddress;
    using BaseClassType = GInetSocketAddressClass;

    InetSocketAddress (const InetSocketAddress&) = delete;
    auto
    operator= (const InetSocketAddress&) -> InetSocketAddress& = delete;

  private:
    friend class InetSocketAddress_Class;
    static CppClassType inetsocketaddress_class_;

  protected:
    explicit InetSocketAddress (const glib::ConstructParams& construct_params);
    explicit InetSocketAddress (GInetSocketAddress* castitem);

#endif

  public:
    InetSocketAddress (InetSocketAddress&& src) noexcept;
    auto
    operator= (InetSocketAddress&& src) noexcept -> InetSocketAddress&;

    ~InetSocketAddress () noexcept override;

    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GInetSocketAddress*
    {
      return reinterpret_cast<GInetSocketAddress*> (gobject_);
    }

    auto
    gobj () const -> const GInetSocketAddress*
    {
      return reinterpret_cast<GInetSocketAddress*> (gobject_);
    }

    auto
    gobj_copy () -> GInetSocketAddress*;

  private:
  protected:
    explicit InetSocketAddress (const glib::RefPtr<InetAddress>& address,
                                guint16 port);

  public:
    static auto
    create (const glib::RefPtr<InetAddress>& address, guint16 port)
        -> glib::RefPtr<InetSocketAddress>;

    auto
    get_address () -> glib::RefPtr<InetAddress>;

    auto
    get_address () const -> glib::RefPtr<const InetAddress>;

    auto
    get_port () const -> guint16;

    auto
    get_flowinfo () const -> guint32;

    auto
    get_scope_id () const -> guint32;

    auto
    property_address () const
        -> glib::PropertyProxy_ReadOnly<glib::RefPtr<InetAddress>>;

    auto
    property_port () const -> glib::PropertyProxy_ReadOnly<guint>;

    auto
    property_flowinfo () const -> glib::PropertyProxy_ReadOnly<guint>;

    auto
    property_scope_id () const -> glib::PropertyProxy_ReadOnly<guint>;

  public:
  public:
  protected:
  };

} // namespace gio

namespace glib
{

  LIBMM_GIO_SYMEXPORT
  auto
  wrap (GInetSocketAddress* object, bool take_copy = false) -> glib::RefPtr<gio::InetSocketAddress>;
} // namespace glib

#endif
