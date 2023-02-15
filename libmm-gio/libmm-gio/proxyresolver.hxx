// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GIOMM_PROXYRESOLVER_H
#define _GIOMM_PROXYRESOLVER_H

#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm-gio/asyncresult.hxx>
#include <libmm-gio/cancellable.hxx>
#include <libmm-glib/error.hxx>
#include <libmm-glib/interface.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
typedef struct _GProxyResolverInterface GProxyResolverInterface;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GProxyResolver = struct _GProxyResolver;
using GProxyResolverClass = struct _GProxyResolverClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gio
{
  class LIBMM_GIO_SYMEXPORT ProxyResolver_Class;
}
#endif

namespace Gio
{

  class LIBMM_GIO_SYMEXPORT ProxyResolver : public Glib::Interface
  {
#ifndef DOXYGEN_SHOULD_SKIP_THIS

  public:
    using CppObjectType = ProxyResolver;
    using CppClassType = ProxyResolver_Class;
    using BaseObjectType = GProxyResolver;
    using BaseClassType = GProxyResolverInterface;

    ProxyResolver (const ProxyResolver&) = delete;
    auto
    operator= (const ProxyResolver&) -> ProxyResolver& = delete;

  private:
    friend class ProxyResolver_Class;
    static CppClassType proxyresolver_class_;

#endif
  protected:
    ProxyResolver ();

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    explicit ProxyResolver (const Glib::Interface_Class& interface_class);

  public:
    explicit ProxyResolver (GProxyResolver* castitem);

  protected:
#endif

  public:
    ProxyResolver (ProxyResolver&& src) noexcept;
    auto
    operator= (ProxyResolver&& src) noexcept -> ProxyResolver&;

    ~ProxyResolver () noexcept override;

    static auto
    add_interface (GType gtype_implementer) -> void;

    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS
    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GProxyResolver*
    {
      return reinterpret_cast<GProxyResolver*> (gobject_);
    }

    auto
    gobj () const -> const GProxyResolver*
    {
      return reinterpret_cast<GProxyResolver*> (gobject_);
    }

  private:
  public:
    static auto
    get_default () -> Glib::RefPtr<ProxyResolver>;

    auto
    is_supported () const -> bool;

    auto
    lookup (const Glib::ustring& uri,
            const Glib::RefPtr<Cancellable>& cancellable)
        -> std::vector<Glib::ustring>;

    auto
    lookup (const Glib::ustring& uri) -> std::vector<Glib::ustring>;

    auto
    lookup_async (const Glib::ustring& uri,
                  const SlotAsyncReady& slot,
                  const Glib::RefPtr<Cancellable>& cancellable) -> void;

    auto
    lookup_async (const Glib::ustring& uri, const SlotAsyncReady& slot) -> void;

    auto
    lookup_finish (const Glib::RefPtr<AsyncResult>& result)
        -> std::vector<Glib::ustring>;

  public:
  public:
  protected:
  };

} // namespace Gio

namespace Glib
{

  LIBMM_GIO_SYMEXPORT
  auto
  wrap (GProxyResolver* object, bool take_copy = false) -> Glib::RefPtr<Gio::ProxyResolver>;

} // namespace Glib

#endif
