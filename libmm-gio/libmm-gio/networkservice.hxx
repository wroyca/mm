
#ifndef _GIOMM_NETWORKSERVICE_H
#define _GIOMM_NETWORKSERVICE_H

#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm-gio/socketconnectable.hxx>
#include <libmm-glib/object.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GNetworkService = struct _GNetworkService;
using GNetworkServiceClass = struct _GNetworkServiceClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gio
{
  class GIOMM_API NetworkService_Class;
}
#endif

namespace Gio
{

  class GIOMM_API NetworkService : public Glib::Object,
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
    explicit NetworkService (const Glib::ConstructParams& construct_params);
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
    explicit NetworkService (const Glib::ustring& service,
                             const Glib::ustring& protocol,
                             const Glib::ustring& domain);

  public:
    static auto
    create (const Glib::ustring& service,
            const Glib::ustring& protocol,
            const Glib::ustring& domain) -> Glib::RefPtr<NetworkService>;

    auto
    get_service () const -> Glib::ustring;

    auto
    get_protocol () const -> Glib::ustring;

    auto
    get_domain () const -> Glib::ustring;

    auto
    get_scheme () const -> Glib::ustring;

    void
    set_scheme (const Glib::ustring& scheme);

    auto
    property_domain () const -> Glib::PropertyProxy_ReadOnly<Glib::ustring>;

    auto
    property_protocol () const -> Glib::PropertyProxy_ReadOnly<Glib::ustring>;

    auto
    property_scheme () -> Glib::PropertyProxy<Glib::ustring>;

    auto
    property_scheme () const -> Glib::PropertyProxy_ReadOnly<Glib::ustring>;

    auto
    property_service () const -> Glib::PropertyProxy_ReadOnly<Glib::ustring>;

  public:
  public:
  protected:
  };

} // namespace Gio

namespace Glib
{

  GIOMM_API
  auto
  wrap (GNetworkService* object, bool take_copy = false) -> Glib::RefPtr<Gio::NetworkService>;
} // namespace Glib

#endif
