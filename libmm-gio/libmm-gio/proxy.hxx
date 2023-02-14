
#ifndef _GIOMM_PROXY_H
#define _GIOMM_PROXY_H

#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm-gio/asyncresult.hxx>
#include <libmm-gio/cancellable.hxx>
#include <libmm-gio/iostream.hxx>
#include <libmm-gio/proxyaddress.hxx>
#include <libmm-glib/error.hxx>
#include <libmm-glib/interface.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
typedef struct _GProxyInterface GProxyInterface;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GProxy = struct _GProxy;
using GProxyClass = struct _GProxyClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gio
{
  class GIOMM_API Proxy_Class;
}
#endif

namespace Gio
{

  class GIOMM_API Proxy : public Glib::Interface
  {
#ifndef DOXYGEN_SHOULD_SKIP_THIS

  public:
    using CppObjectType = Proxy;
    using CppClassType = Proxy_Class;
    using BaseObjectType = GProxy;
    using BaseClassType = GProxyInterface;

    Proxy (const Proxy&) = delete;
    auto
    operator= (const Proxy&) -> Proxy& = delete;

  private:
    friend class Proxy_Class;
    static CppClassType proxy_class_;

#endif
  protected:
    Proxy ();

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    explicit Proxy (const Glib::Interface_Class& interface_class);

  public:
    explicit Proxy (GProxy* castitem);

  protected:
#endif

  public:
    Proxy (Proxy&& src) noexcept;
    auto
    operator= (Proxy&& src) noexcept -> Proxy&;

    ~Proxy () noexcept override;

    static void
    add_interface (GType gtype_implementer);

    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS
    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GProxy*
    {
      return reinterpret_cast<GProxy*> (gobject_);
    }

    auto
    gobj () const -> const GProxy*
    {
      return reinterpret_cast<GProxy*> (gobject_);
    }

  private:
  public:
    static auto
    get_default_for_protocol (const Glib::ustring& protocol)
        -> Glib::RefPtr<Proxy>;

    auto
    connect (const Glib::RefPtr<IOStream>& connection,
             const Glib::RefPtr<const ProxyAddress>& proxy_address,
             const Glib::RefPtr<Cancellable>& cancellable)
        -> Glib::RefPtr<IOStream>;

    void
    connect_async (const Glib::RefPtr<IOStream>& connection,
                   const Glib::RefPtr<const ProxyAddress>& proxy_address,
                   const SlotAsyncReady& slot,
                   const Glib::RefPtr<Cancellable>& cancellable);

    void
    connect_async (const Glib::RefPtr<IOStream>& connection,
                   const Glib::RefPtr<const ProxyAddress>& proxy_address,
                   const SlotAsyncReady& slot);

    auto
    connect_finish (const Glib::RefPtr<AsyncResult>& result)
        -> Glib::RefPtr<IOStream>;

    auto
    supports_hostname () const -> bool;

  public:
  public:
  protected:
  };

} // namespace Gio

namespace Glib
{

  GIOMM_API
  auto
  wrap (GProxy* object, bool take_copy = false) -> Glib::RefPtr<Gio::Proxy>;

} // namespace Glib

#endif
