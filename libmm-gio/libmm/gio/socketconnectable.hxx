// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GIOMM_SOCKETCONNECTABLE_H
#define _GIOMM_SOCKETCONNECTABLE_H

#include <libmm/glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm/gio/socketaddressenumerator.hxx>
#include <libmm/glib/interface.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
typedef struct _GSocketConnectableIface GSocketConnectableIface;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GSocketConnectable = struct _GSocketConnectable;
using GSocketConnectableClass = struct _GSocketConnectableClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace gio
{
  class LIBMM_GIO_SYMEXPORT SocketConnectable_Class;
}
#endif

namespace gio
{

  class LIBMM_GIO_SYMEXPORT SocketConnectable : public glib::Interface
  {
#ifndef DOXYGEN_SHOULD_SKIP_THIS

  public:
    using CppObjectType = SocketConnectable;
    using CppClassType = SocketConnectable_Class;
    using BaseObjectType = GSocketConnectable;
    using BaseClassType = GSocketConnectableIface;

    SocketConnectable (const SocketConnectable&) = delete;
    auto
    operator= (const SocketConnectable&) -> SocketConnectable& = delete;

  private:
    friend class SocketConnectable_Class;
    static CppClassType socketconnectable_class_;

#endif
  protected:
    SocketConnectable ();

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    explicit SocketConnectable (const glib::Interface_Class& interface_class);

  public:
    explicit SocketConnectable (GSocketConnectable* castitem);

  protected:
#endif

  public:
    SocketConnectable (SocketConnectable&& src) noexcept;
    auto
    operator= (SocketConnectable&& src) noexcept -> SocketConnectable&;

    ~SocketConnectable () noexcept override;

    static auto
    add_interface (GType gtype_implementer) -> void;

    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS
    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GSocketConnectable*
    {
      return reinterpret_cast<GSocketConnectable*> (gobject_);
    }

    auto
    gobj () const -> const GSocketConnectable*
    {
      return reinterpret_cast<GSocketConnectable*> (gobject_);
    }

  private:
  public:
    auto
    enumerate () -> glib::RefPtr<SocketAddressEnumerator>;

    auto
    enumerate () const -> glib::RefPtr<const SocketAddressEnumerator>;

    auto
    proxy_enumerate () -> glib::RefPtr<SocketAddressEnumerator>;

    auto
    proxy_enumerate () const -> glib::RefPtr<const SocketAddressEnumerator>;

    auto
    to_string () const -> glib::ustring;

  public:
  public:
  protected:
  };

} // namespace gio

namespace glib
{

  LIBMM_GIO_SYMEXPORT
  auto
  wrap (GSocketConnectable* object, bool take_copy = false) -> glib::RefPtr<gio::SocketConnectable>;

} // namespace glib

#endif
