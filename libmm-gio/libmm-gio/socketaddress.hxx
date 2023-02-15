// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GIOMM_SOCKETADDRESS_H
#define _GIOMM_SOCKETADDRESS_H

#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm-glib/object.hxx>

#include <libmm-gio/asyncresult.hxx>
#include <libmm-gio/cancellable.hxx>
#include <libmm-gio/enums.hxx>
#include <libmm-gio/socketconnectable.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GSocketAddress = struct _GSocketAddress;
using GSocketAddressClass = struct _GSocketAddressClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gio
{
  class LIBMM_GIO_SYMEXPORT SocketAddress_Class;
}
#endif

namespace Gio
{

  class LIBMM_GIO_SYMEXPORT SocketAddress : public Glib::Object,
                                  public SocketConnectable
  {
#ifndef DOXYGEN_SHOULD_SKIP_THIS

  public:
    using CppObjectType = SocketAddress;
    using CppClassType = SocketAddress_Class;
    using BaseObjectType = GSocketAddress;
    using BaseClassType = GSocketAddressClass;

    SocketAddress (const SocketAddress&) = delete;
    auto
    operator= (const SocketAddress&) -> SocketAddress& = delete;

  private:
    friend class SocketAddress_Class;
    static CppClassType socketaddress_class_;

  protected:
    explicit SocketAddress (const Glib::ConstructParams& construct_params);
    explicit SocketAddress (GSocketAddress* castitem);

#endif

  public:
    SocketAddress (SocketAddress&& src) noexcept;
    auto
    operator= (SocketAddress&& src) noexcept -> SocketAddress&;

    ~SocketAddress () noexcept override;

    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GSocketAddress*
    {
      return reinterpret_cast<GSocketAddress*> (gobject_);
    }

    auto
    gobj () const -> const GSocketAddress*
    {
      return reinterpret_cast<GSocketAddress*> (gobject_);
    }

    auto
    gobj_copy () -> GSocketAddress*;

  private:
  public:
    static auto
    create (gpointer native, gsize len) -> Glib::RefPtr<SocketAddress>;

    auto
    get_family () const -> SocketFamily;

    auto
    to_native (gpointer dest, gsize destlen) -> bool;

    auto
    get_native_size () const -> gssize;

    auto
    property_family () const -> Glib::PropertyProxy_ReadOnly<SocketFamily>;

  public:
  public:
  protected:
  };

} // namespace Gio

namespace Glib
{

  LIBMM_GIO_SYMEXPORT
  auto
  wrap (GSocketAddress* object, bool take_copy = false) -> Glib::RefPtr<Gio::SocketAddress>;
} // namespace Glib

#endif
