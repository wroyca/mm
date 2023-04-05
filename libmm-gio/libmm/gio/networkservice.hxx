// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GIOMM_NETWORKSERVICE_H
#define _GIOMM_NETWORKSERVICE_H

#include <libmm/glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm/gio/socketconnectable.hxx>
#include <libmm/glib/object.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GNetworkService = struct _GNetworkService;
using GNetworkServiceClass = struct _GNetworkServiceClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace gio
{
  class LIBMM_GIO_SYMEXPORT NetworkService_Class;
}
#endif

namespace gio
{

  class LIBMM_GIO_SYMEXPORT NetworkService : public glib::Object,
                                   public SocketConnectable
  {
#ifndef DOXYGEN_SHOULD_SKIP_THIS

  public:
    using CppObjectType = NetworkService;
    using CppClassType = NetworkService_Class;
    using BaseObjectType = GNetworkService;
    using BaseClassType = GNetworkServiceClass;

    NetworkService (const NetworkService&) = delete;
    auto
    operator= (const NetworkService&) -> NetworkService& = delete;

  private:
    friend class NetworkService_Class;
    static CppClassType networkservice_class_;

  protected:
    explicit NetworkService (const glib::ConstructParams& construct_params);
    explicit NetworkService (GNetworkService* castitem);

#endif

  public:
    NetworkService (NetworkService&& src) noexcept;
    auto
    operator= (NetworkService&& src) noexcept -> NetworkService&;

    ~NetworkService () noexcept override;

    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GNetworkService*
    {
      return reinterpret_cast<GNetworkService*> (gobject_);
    }

    auto
    gobj () const -> const GNetworkService*
    {
      return reinterpret_cast<GNetworkService*> (gobject_);
    }

    auto
    gobj_copy () -> GNetworkService*;

  private:
    explicit NetworkService (const glib::ustring& service,
                             const glib::ustring& protocol,
                             const glib::ustring& domain);

  public:
    static auto
    create (const glib::ustring& service,
            const glib::ustring& protocol,
            const glib::ustring& domain) -> glib::RefPtr<NetworkService>;

    auto
    get_service () const -> glib::ustring;

    auto
    get_protocol () const -> glib::ustring;

    auto
    get_domain () const -> glib::ustring;

    auto
    get_scheme () const -> glib::ustring;

    auto
    set_scheme (const glib::ustring& scheme) -> void;

    auto
    property_domain () const -> glib::PropertyProxy_ReadOnly<glib::ustring>;

    auto
    property_protocol () const -> glib::PropertyProxy_ReadOnly<glib::ustring>;

    auto
    property_scheme () -> glib::PropertyProxy<glib::ustring>;

    auto
    property_scheme () const -> glib::PropertyProxy_ReadOnly<glib::ustring>;

    auto
    property_service () const -> glib::PropertyProxy_ReadOnly<glib::ustring>;

  public:
  public:
  protected:
  };

} // namespace gio

namespace glib
{

  LIBMM_GIO_SYMEXPORT
  auto
  wrap (GNetworkService* object, bool take_copy = false) -> glib::RefPtr<gio::NetworkService>;
} // namespace glib

#endif
