// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GIOMM_PROXY_H
#define _GIOMM_PROXY_H

#include <libmm/glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm/gio/asyncresult.hxx>
#include <libmm/gio/cancellable.hxx>
#include <libmm/gio/iostream.hxx>
#include <libmm/gio/proxyaddress.hxx>
#include <libmm/glib/error.hxx>
#include <libmm/glib/interface.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
typedef struct _GProxyInterface GProxyInterface;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GProxy = struct _GProxy;
using GProxyClass = struct _GProxyClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace gio
{
  class LIBMM_GIO_SYMEXPORT Proxy_Class;
}
#endif

namespace gio
{

  class LIBMM_GIO_SYMEXPORT Proxy : public glib::Interface
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

    explicit Proxy (const glib::Interface_Class& interface_class);

  public:
    explicit Proxy (GProxy* castitem);

  protected:
#endif

  public:
    Proxy (Proxy&& src) noexcept;
    auto
    operator= (Proxy&& src) noexcept -> Proxy&;

    ~Proxy () noexcept override;

    static auto
    add_interface (GType gtype_implementer) -> void;

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
    get_default_for_protocol (const glib::ustring& protocol)
        -> glib::RefPtr<Proxy>;

    auto
    connect (const glib::RefPtr<IOStream>& connection,
             const glib::RefPtr<const ProxyAddress>& proxy_address,
             const glib::RefPtr<Cancellable>& cancellable)
        -> glib::RefPtr<IOStream>;

    auto
    connect_async (const glib::RefPtr<IOStream>& connection,
                   const glib::RefPtr<const ProxyAddress>& proxy_address,
                   const SlotAsyncReady& slot,
                   const glib::RefPtr<Cancellable>& cancellable) -> void;

    auto
    connect_async (const glib::RefPtr<IOStream>& connection,
                   const glib::RefPtr<const ProxyAddress>& proxy_address,
                   const SlotAsyncReady& slot) -> void;

    auto
    connect_finish (const glib::RefPtr<AsyncResult>& result)
        -> glib::RefPtr<IOStream>;

    auto
    supports_hostname () const -> bool;

  public:
  public:
  protected:
  };

} // namespace gio

namespace glib
{

  LIBMM_GIO_SYMEXPORT
  auto
  wrap (GProxy* object, bool take_copy = false) -> glib::RefPtr<gio::Proxy>;

} // namespace glib

#endif
